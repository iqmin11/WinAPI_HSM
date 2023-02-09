#include "PlayerCalendar.h"
#include <vector>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
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
	DateNumRender();
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


int PlayerCalendar::FindFirstWeekday()
{
	int PrevYear = CalendarYear - 1;
	return (PrevYear + ((PrevYear / 4) - (PrevYear / 100) + (PrevYear / 400)) + 1) % 7;
}

int PlayerCalendar::FindFirstWeekday(int _YYYY)
{
	int PrevYear = _YYYY - 1;
	return (PrevYear + ((PrevYear / 4) - (PrevYear / 100) + (PrevYear / 400)) + 1) % 7;
}

int PlayerCalendar::FindMonthFirstWeekday(int _YYYY, int _MM)
{
	if (true == Date::IsOverMonth(_MM))
	{
		MsgAssert("입력가능한 Month의 범위를 벗어났습니다");
		return 0;
	}

	int Year = _YYYY;
	int Month = 1;
	int MonthLen[12] = {};
	for (size_t i = 0; i < 12; i++)
	{
		if (13 == Month)
		{
			Month = 1;
			Year++;
		}

		if (2 == Month)
		{
			if (IsLeapYear(Year))
			{
				MonthLen[i] = 29;
			}
			else
			{
				MonthLen[i] = 28;
			}
		}
		else if (4 == Month ||
			6 == Month ||
			9 == Month ||
			11 == Month)
		{
			MonthLen[i] = 30;
		}
		else
		{
			MonthLen[i] = 31;
		}
		Month++;
	}
	int WholeDay = 0;
	for (size_t i = 0; i < _MM - 1; i++)
	{
		WholeDay += MonthLen[i];
	}
	return (FindFirstWeekday(_YYYY) + WholeDay) % 7;
}


void PlayerCalendar::DateNumRender()
{
	int FirstMonth = OliveBirth.GetMonth();
	int Month = FirstMonth;
	int Year = CalendarYear;
	                //        1200                1201
				    //        8   9   10  11  12  1   2    3   4  5   6   7
	                //        31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31    
	int MonthLen[12] = {}; // 2월이 윤년이면이란 뜻으로 될듯->윤년 각 달의 날짜수
	for (size_t i = 0; i < 12; i++)
	{
		if (13 == Month)
		{
			Month = 1;
			Year++;
		}
		
		if (2 == Month)
		{
			if (IsLeapYear(Year))
			{
				MonthLen[i] = 29;
			}
			else
			{
				MonthLen[i] = 28;
			}
		}
		else if (4 == Month ||
			6 == Month || 
			9 == Month || 
			11 == Month )
		{
			MonthLen[i] = 30;
		}
		else
		{
			MonthLen[i] = 31;
		}
		Month++;
	}
	// MonthLen[12] = {31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31}

	int FirstWeekday = FindMonthFirstWeekday(CalendarYear, OliveBirth.GetMonth()); // 1월 1일 요일 찾기 공식
	int MonthFirstWeekday = FirstWeekday;

	for (int w = 0; w < 4; w++)
	{
		for (int z = 0; z < 3; z++)
		{
			int i = 1;
			int FirstMonth = (z + 1) + (w * 3); // 순서상 첫번쨰 달을 말하는거 8월이 맨 앞에오면 8월이 first
			for (int y = 0; y < 6; y++) // 한달
			{
				for (int x = 0; x < 7; x++) // 일주일
				{
					float fx = static_cast<float>(x);
					float fy = static_cast<float>(y);
					float fz = static_cast<float>(z);
					float fw = static_cast<float>(w);
					DateRender[w][z][y][x] = CreateRender("PlayerCalendarNum.BMP", PM2RenderOrder::Contents);
					DateRender[w][z][y][x]->SetScale({ 20,14 }); //default {20,15}
					DateRender[w][z][y][x]->SetPosition(-float4{ 315 + 15, 192 - (15 * 1) } + float4{ (30 * fx) + ((210 + (10 * 4)) * fz), (15 * fy) + ((15 * 6 + 15) * fw) });
					if (x + (y * 7) < MonthFirstWeekday)
					{
						DateRender[w][z][y][x]->SetFrame(0);
					}
					else if (x + (y * 7) < MonthFirstWeekday + MonthLen[FirstMonth - 1])
					{
						if (0 == x)
						{
							DateRender[w][z][y][x]->SetFrame(32 + (i++));
						}
						else
						{
							DateRender[w][z][y][x]->SetFrame(i++);
						}
					}
					else
					{
						DateRender[w][z][y][x]->SetFrame(0);
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
				Year1000 = Year / 1000;
				Year100 = (Year - (Year1000 * 1000)) / 100;
				Year10 = (Year - (Year1000 * 1000) - (Year100 * 100)) / 10;
				Year1 = Year - (Year1000 * 1000) - (Year100 * 100) - (Year10 * 10);
			}

			for (int x = 0; x < 4; x++)
			{
				float fx = static_cast<float>(x);
				float fy = static_cast<float>(y);
				float fz = static_cast<float>(z);
				YearRender[z][y][x] = CreateRender("PlayerYearNum.BMP", PM2RenderOrder::Contents); // 인덱스상 3이 1,  5가 2 (인덱스 -1 / 2가 원래 숫자임)
				YearRender[z][y][x]->SetScale({ 8,12 }); //default {10,15} -> 8*6짜리 숫자가 년도로 들어가야함
				YearRender[z][y][x]->SetPosition(-float4{ 315 + 40 + 15, 192 - (15 * 1) + 5 } + float4{ (8 * fx) + ((210 + (10 * 4)) * fy), (15 * 6 + 15) * fz });
				//CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 192 - (15 * 1) } + float4{ (30 * fx) + (242 * fz), (15 * fy) + ((15 * 6 + 15) * fw) });
			}

			
			YearRender[z][y][0]->SetFrame(Year1000);
			YearRender[z][y][1]->SetFrame(Year100);
			YearRender[z][y][2]->SetFrame(Year10);
			YearRender[z][y][3]->SetFrame(Year1);

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
			WeekRender[y][x]->SetScale({ 210,10 }); //default {10,15} -> 8*6짜리 숫자가 년도로 들어가야함
			WeekRender[y][x]->SetPosition(-float4{ 315 - 95 + 15, 192 + 15 - (15 * 1) } + float4{ ((210 + (10 * 4)) * fx), (15 * 6 + 15) * fy });
			//CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 192 - (15 * 1) } + float4{ (30 * fx) + (242 * fz), (15 * fy) + ((15 * 6 + 15) * fw) });

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
			//CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 192 - (15 * 1) } + float4{ (30 * fx) + (242 * fz), (15 * fy) + ((15 * 6 + 15) * fw) });
		}
	}
}



bool PlayerCalendar::IsLeapYear() // 윤년이니?
{
	if ((0 == (CalendarYear % 4) && 0 != (CalendarYear % 100)) || 0 == (CalendarYear % 400))
	{
		return true;
	}
	return false;
}

bool PlayerCalendar::IsLeapYear(int _YYYY)
{
	if ((0 == (_YYYY % 4) && 0 != (_YYYY % 100)) || 0 == (_YYYY % 400))
	{
		return true;
	}
	return false;
}

void PlayerCalendar::SetOliveBirth(int _YYYY, int _MM, int _DD)
{
	OliveBirth.SetDate(_YYYY,_MM,_DD);
}

void PlayerCalendar::SetCalendarYear(int _YYYY)
{
	CalendarYear = _YYYY;
}
