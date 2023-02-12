#include "PlayerCalendar.h"
#include <vector>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include "MousePoint.h"
#include "ContentsEnums.h"

PlayerCalendar::PlayerCalendar()
{

}

PlayerCalendar::~PlayerCalendar()
{

}

void PlayerCalendar::Start()
{
	SetOliveBirth(1200, 8, 15);
	SetCalendarYear(2023);
	SetPos(GameEngineWindow::GetScreenSize().half());
	
	HoverButtonDateRender_Year.SetOwner(this);
	HoverButtonDateRender_Year.SetImage("BirthNum.bmp", { 10, 9 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	HoverButtonDateRender_Year.SetAlign(Align::Right);
	HoverButtonDateRender_Year.SetRenderPos(Pos_HoverButtonDateRender_Year);
	
	HoverButtonDateRender_Month.SetOwner(this);
	HoverButtonDateRender_Month.SetImage("BirthNum.bmp", { 10, 9 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	HoverButtonDateRender_Month.SetAlign(Align::Right);
	HoverButtonDateRender_Month.SetRenderPos(Pos_HoverButtonDateRender_Month);
	HoverButtonDateRender_Month.SetNumOfDigits(2);

	HoverButtonDateRender_Day.SetOwner(this);
	HoverButtonDateRender_Day.SetImage("BirthNum.bmp", { 10, 9 }, static_cast<int>(PM2RenderOrder::Menu0_Display), RGB(255, 0, 255));
	HoverButtonDateRender_Day.SetAlign(Align::Right);
	HoverButtonDateRender_Day.SetRenderPos(Pos_HoverButtonDateRender_Day);
	HoverButtonDateRender_Day.SetNumOfDigits(2);
		
	BackgroundRender = CreateRender("SetPlayerBirth.BMP", PM2RenderOrder::BackGround);
	BackgroundRender->SetScaleToImage();
	SetDateNumButton();
	SetMonthRender();
	SetYearRender();
	SetWeekdayRender();
	Off();
}

void PlayerCalendar::Update(float _DeltaTime)
{
	float4 Index = WichButtonNotRelease();
	if (
		0 > Index.x &&
		0 > Index.y &&
		0 > Index.z &&
		0 > Index.w
		)
	{
		HoverButtonDateRender_Year.Off();
		HoverButtonDateRender_Month.Off();
		HoverButtonDateRender_Day.Off();
	}
	else
	{
		HoverButtonDateRender_Year.On();
		HoverButtonDateRender_Month.On();
		HoverButtonDateRender_Day.On();
		
		HoverButtonDateRender_Year.SetValue(EachButtonDate[Index.iw()][Index.iz()][Index.iy()][Index.ix()].GetYear());
		HoverButtonDateRender_Month.SetValue(EachButtonDate[Index.iw()][Index.iz()][Index.iy()][Index.ix()].GetMonth());
		HoverButtonDateRender_Day.SetValue(EachButtonDate[Index.iw()][Index.iz()][Index.iy()][Index.ix()].GetDay());
	}
}

void PlayerCalendar::Render(float _DeltaTime)
{

}

float4 PlayerCalendar::WichButtonNotRelease()
{
	for (size_t w = 0; w < 4; w++)
	{
		for (size_t z = 0; z < 3; z++)
		{
			for (size_t y = 0; y < 6; y++)
			{
				for (size_t x = 0; x < 7; x++)
				{
					if (ButtonState::Release != DateButton[w][z][y][x]->GetState())
					{
						return float4{ static_cast<float>(x), static_cast<float>(y), static_cast<float>(z), static_cast<float>(w) };
					}
				}
			}
		}
	}
	return float4{-1, -1, -1, -1};
}

void PlayerCalendar::SetDateNumButton()
{
	SetEachButtonDate();
	int FirstMonth = OliveBirth.GetMonth();
	int Month = FirstMonth;
	int Year = CalendarYear;
	//        1200                1201
	//        8   9   10  11  12  1   2    3   4  5   6   7
	//        31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31    
	int MonthLen[12] = {}; // 2���� �����̸��̶� ������ �ɵ�->���� �� ���� ��¥��

	for (size_t i = 0; i < 12; i++)
	{
		if (13 == Month)
		{
			Month = 1;
			Year++;
		}

		MonthLen[i] = Date::GetMonthLenth(Year, Month);
		Month++;
	}

	int FirstWeekday = Date::FindMonthFirstWeekday(CalendarYear, FirstMonth); // 1�� 1�� ���� ã�� ����
	int MonthFirstWeekday = FirstWeekday;
	GameEngineLevel* Level = GetLevel();

	for (int w = 0; w < 4; w++)
	{
		for (int z = 0; z < 3; z++)
		{
			int i = 1;
			int FirstMonth = (z + 1) + (w * 3); // ������ ù���� ���� ���ϴ°� 8���� �� �տ����� 8���� first
			for (int y = 0; y < 6; y++) // �Ѵ�
			{
				for (int x = 0; x < 7; x++) // ������
				{
					float fx = static_cast<float>(x);
					float fy = static_cast<float>(y);
					float fz = static_cast<float>(z);
					float fw = static_cast<float>(w);
					DateButton[w][z][y][x] = Level->CreateActor<Button>(PM2ActorOrder::Menu0_Button);
					DateButton[w][z][y][x]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
					DateButton[w][z][y][x]->SetScale(DateButtonScale);
					DateButton[w][z][y][x]->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
					DateButton[w][z][y][x]->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
					DateButton[w][z][y][x]->SetPos(GetPos() + (FirstDaySetPos + (EachDayNumInterval * float4{ fx,fy }) + (EcahMonthCalendarInterval * float4{ fz,fw })));
					if (x + (y * 7) < MonthFirstWeekday)
					{
						DateButton[w][z][y][x]->SetReleaseImage("PlayerCalendarNum.bmp", 0);//
						DateButton[w][z][y][x]->SetHoverImage("PlayerCalendarNum.bmp", 0);	//
						DateButton[w][z][y][x]->SetPressImage("PlayerCalendarNum.bmp", 0);	//���ǵ� ���ټ��ۿ����� ���߿� ����ȭ�Ҷ�� ������� ���ľ��ҵ�
					}
					else if (x + (y * 7) < MonthFirstWeekday + MonthLen[FirstMonth - 1])
					{
						if (0 == x)
						{
							DateButton[w][z][y][x]->SetReleaseImage("PlayerCalendarNum.bmp", 32 + (i++));
							DateButton[w][z][y][x]->SetHoverImage("PlayerCalendarNum.bmp", 63 + i);
							DateButton[w][z][y][x]->SetPressImage("PlayerCalendarNum.bmp", 63 + i);
						}
						else
						{
							DateButton[w][z][y][x]->SetReleaseImage("PlayerCalendarNum.bmp", i++);
							DateButton[w][z][y][x]->SetHoverImage("PlayerCalendarNum.bmp", 63 + i);
							DateButton[w][z][y][x]->SetPressImage("PlayerCalendarNum.bmp", 63 + i);
						}
					}
					else
					{
						DateButton[w][z][y][x]->SetReleaseImage("PlayerCalendarNum.bmp", 0);
						DateButton[w][z][y][x]->SetHoverImage("PlayerCalendarNum.bmp", 0);
						DateButton[w][z][y][x]->SetPressImage("PlayerCalendarNum.bmp", 0);
					}
				}
			}
			MonthFirstWeekday = (MonthFirstWeekday + MonthLen[FirstMonth - 1]) % 7;
		}
	}
}

void PlayerCalendar::SetYearRender()
{
	int Month = OliveBirth.GetMonth();
	int Year = CalendarYear;
	std::vector<unsigned int> YearDigits = GameEngineMath::GetDigits(Year);

	for (int z = 0; z < 4; z++)
	{
		for (int y = 0; y < 3; y++)
		{

			if (Month == 13)
			{
				Month = 1;
				Year++;
				YearDigits = GameEngineMath::GetDigits(Year);
			}

			for (int x = 0; x < 4; x++)
			{
				float fx = static_cast<float>(x);
				float fy = static_cast<float>(y);
				float fz = static_cast<float>(z);
				YearRender[z][y][x] = CreateRender("PlayerYearNum.BMP", PM2RenderOrder::Contents); // �ε����� 3�� 1,  5�� 2 (�ε��� -1 / 2�� ���� ������)
				YearRender[z][y][x]->SetScale(YearRenderScale); //default {10,15} -> 8*6¥�� ���ڰ� �⵵�� ������
				YearRender[z][y][x]->SetPosition(FirstYearSetPos + (EcahMonthCalendarInterval * float4{ fy, fz }) + (float4::Right * fx * YearRenderScale.x));
			}

			YearRender[z][y][0]->SetFrame(YearDigits[0]);
			YearRender[z][y][1]->SetFrame(YearDigits[1]);
			YearRender[z][y][2]->SetFrame(YearDigits[2]);
			YearRender[z][y][3]->SetFrame(YearDigits[3]);

			Month++;
		}
	}
}

void PlayerCalendar::SetWeekdayRender()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			float fx = static_cast<float>(x);
			float fy = static_cast<float>(y);
			WeekRender[y][x] = CreateRender("PlayerWeek.BMP", PM2RenderOrder::Contents);
			WeekRender[y][x]->SetScale(WeekRenderScale); //default {10,15} -> 8*6¥�� ���ڰ� �⵵�� ������
			WeekRender[y][x]->SetPosition(FirstWeekSetPos + (EcahMonthCalendarInterval * float4{ fx, fy }));
		}
	}
}

void PlayerCalendar::SetMonthRender()
{
	int Month = OliveBirth.GetMonth();
	
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			float fx = static_cast<float>(x);
			float fy = static_cast<float>(y);
			MonthRender[y][x] = CreateRender("PlayerCalendarNum.BMP", PM2RenderOrder::Contents);
			if (13 == ((x + (y * 3)) + (Month)))
			{
				Month = -(12 - Month);
			}
			MonthRender[y][x]->SetFrame((x + (y * 3)) + (Month));
			MonthRender[y][x]->SetScale({ 20,16 });
			MonthRender[y][x]->SetPosition(FirstMonthSetPos + (EcahMonthCalendarInterval * float4{fx, fy}));
		}
	}
}

void PlayerCalendar::SetOliveBirth(int _YYYY, int _MM, int _DD)
{
	OliveBirth.SetDate(_YYYY,_MM,_DD);
}

void PlayerCalendar::SetCalendarYear(int _YYYY)
{
	CalendarYear = _YYYY;
}

void PlayerCalendar::On()
{
	GameEngineObject::On();
	for (size_t w = 0; w < 4; w++)
	{
		for (size_t z = 0; z < 3; z++)
		{
			for (size_t y = 0; y < 6; y++)
			{
				for (size_t x = 0; x < 7; x++)
				{
					if (0 != DateButton[w][z][y][x]->GetReleaseIndex())
					{
						DateButton[w][z][y][x]->On();
					}
				}
			}
		}
	}
}

void PlayerCalendar::Off()
{
	GameEngineObject::Off();
	for (size_t w = 0; w < 4; w++)
	{
		for (size_t z = 0; z < 3; z++)
		{
			for (size_t y = 0; y < 6; y++)
			{
				for (size_t x = 0; x < 7; x++)
				{
					DateButton[w][z][y][x]->Off();
				}
			}
		}
	}
}

void PlayerCalendar::SetEachButtonDate() //�� ��ư �ε��������� ��¥
{
	int FirstMonth = OliveBirth.GetMonth();
	int Month = FirstMonth;
	int Year = CalendarYear;
	//        1200                1201
	//        8   9   10  11  12  1   2    3   4  5   6   7
	//        31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31    
	int MonthLen[12] = {}; // 2���� �����̸��̶� ������ �ɵ�->���� �� ���� ��¥��

	for (size_t i = 0; i < 12; i++)
	{
		if (13 == Month)
		{
			Month = 1;
			Year++;
		}

		MonthLen[i] = Date::GetMonthLenth(Year, Month);
		Month++;
	}

	int FirstWeekday = Date::FindMonthFirstWeekday(CalendarYear, FirstMonth); // 1�� 1�� ���� ã�� ����

	int MonthFirstWeekday = FirstWeekday;
	int SetMonth = OliveBirth.GetMonth();
	int SetYear = CalendarYear;
	for (int w = 0; w < 4; w++)
	{
		for (int z = 0; z < 3; z++)
		{
			
			if (SetMonth == 13)
			{
				SetMonth = 1;
				SetYear++;
			}
			int SetDay = 1;
			int FirstMonth = (z + 1) + (w * 3); // ������ ù���� ���� ���ϴ°� 8���� �� �տ����� 8���� first
			for (int y = 0; y < 6; y++) // �Ѵ�
			{
				for (int x = 0; x < 7; x++) // ������
				{
					float fx = static_cast<float>(x);
					float fy = static_cast<float>(y);
					float fz = static_cast<float>(z);
					float fw = static_cast<float>(w);
					if (x + (y * 7) < MonthFirstWeekday)
					{
						EachButtonDate[w][z][y][x].SetNullDate();
					}
					else if (x + (y * 7) < MonthFirstWeekday + MonthLen[FirstMonth - 1])
					{
						EachButtonDate[w][z][y][x].SetDate(SetYear, SetMonth, SetDay++);
					}
					else
					{
						EachButtonDate[w][z][y][x].SetNullDate();
					}
				}
			}
			SetMonth++;
			MonthFirstWeekday = (MonthFirstWeekday + MonthLen[FirstMonth - 1]) % 7;
		}
	}
}