#include "PlayerCalendar.h"
#include <vector>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
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
	//GameEngineRender* WeekRender = CreateRender("OliveWeek.BMP");


	BackgroundRender = CreateRender("SetPlayerBirth.BMP", PM2RenderOrder::BackGround);
	BackgroundRender->SetScaleToImage();
	DateNumButtonSet();
	MonthNumRender();
	YearNumRender();
	WeekdayRender();
	Off();
}

void PlayerCalendar::Update(float _DeltaTime)
{
	
}

void PlayerCalendar::Render(float _DeltaTime)
{

}

void PlayerCalendar::DateNumButtonSet()
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

	int FirstWeekday = Date::FindMonthFirstWeekday(CalendarYear, OliveBirth.GetMonth()); // 1�� 1�� ���� ã�� ����
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
					DateButton[w][z][y][x] = Level->CreateActor<Button>(PM2ActorOrder::Menu0);
					DateButton[w][z][y][x]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
					DateButton[w][z][y][x]->SetScale({ 20,14 });
					DateButton[w][z][y][x]->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0));
					DateButton[w][z][y][x]->SetPos(GetPos() + (-float4{ 315 + 15, 192 - (15 * 1) } + float4{ (30 * fx) + ((210 + (10 * 4)) * fz), (15 * fy) + ((15 * 6 + 15) * fw) }));
					if (x + (y * 7) < MonthFirstWeekday)
					{
						DateButton[w][z][y][x]->SetReleaseImage("PlayerCalendarNum.bmp", 0);
						DateButton[w][z][y][x]->SetHoverImage("PlayerCalendarNum.bmp", 0);
						DateButton[w][z][y][x]->SetPressImage("PlayerCalendarNum.bmp", 0);
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

void PlayerCalendar::YearNumRender()
{
	int Month = OliveBirth.GetMonth();
	int Year = CalendarYear;
	std::vector<unsigned int> YearDigits = GameEngineMath::GetDigits(Year);
	int Year1000 = Year / 1000;
	int Year100 = (Year - (Year1000 * 1000)) / 100;
	int Year10 = (Year - (Year1000 * 1000) - (Year100 * 100)) / 10;
	int Year1 = Year - (Year1000 * 1000) - (Year100 * 100) - (Year10 * 10);


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
				YearRender[z][y][x]->SetScale({ 8,12 }); //default {10,15} -> 8*6¥�� ���ڰ� �⵵�� ������
				YearRender[z][y][x]->SetPosition(-float4{ 315 + 40 + 15, 192 - (15 * 1) + 5 } + float4{ (8 * fx) + ((210 + (10 * 4)) * fy), (15 * 6 + 15) * fz });
			}


			YearRender[z][y][0]->SetFrame(YearDigits[0]);
			YearRender[z][y][1]->SetFrame(YearDigits[1]);
			YearRender[z][y][2]->SetFrame(YearDigits[2]);
			YearRender[z][y][3]->SetFrame(YearDigits[3]);

			Month++;
		}
	}
}

void PlayerCalendar::WeekdayRender()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			float fx = static_cast<float>(x);
			float fy = static_cast<float>(y);
			WeekRender[y][x] = CreateRender("PlayerWeek.BMP", PM2RenderOrder::Contents);
			WeekRender[y][x]->SetScale({ 210,10 }); //default {10,15} -> 8*6¥�� ���ڰ� �⵵�� ������
			WeekRender[y][x]->SetPosition(-float4{ 315 - 95 + 15, 192 + 15 - (15 * 1) } + float4{ ((210 + (10 * 4)) * fx), (15 * 6 + 15) * fy });
		}
	}
}

void PlayerCalendar::MonthNumRender()
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
			MonthRender[y][x]->SetPosition(-float4{ 315 + 30 + 15, 192 - (15 * 1) - 12 } + float4{ ((210 + (10 * 4)) * fx), (15 * 6 + 15) * fy });
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
					DateButton[w][z][y][x]->On();
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
