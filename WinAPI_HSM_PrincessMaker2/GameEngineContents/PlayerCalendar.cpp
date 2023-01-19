#include "PlayerCalendar.h"
#include <vector>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>


PlayerCalendar::PlayerCalendar()
{

}

PlayerCalendar::~PlayerCalendar()
{

}

void PlayerCalendar::Start()
{
	SetOliveBirth();

	SetPos(GameEngineWindow::GetScreenSize().half());
	//GameEngineRender* WeekRender = CreateRender("OliveWeek.BMP");


	GameEngineRender* Background = CreateRender("SetPlayerBirth.BMP", 0);
	DateNumRender();
	MonthNumRender();
	YearNumRender();
	WeekdayRender();
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

void PlayerCalendar::DateNumRender()
{
	std::vector<std::vector<std::vector<std::vector<GameEngineRender*>>>> CalendarNum = std::vector<std::vector<std::vector<std::vector<GameEngineRender*>>>>();
	CalendarNum.resize(4); // 인터페이스 세로열
	for (size_t z = 0; z < CalendarNum.size(); z++)
	{
		CalendarNum[z].resize(3); // 인터페이스 가로열
		for (size_t y = 0; y < CalendarNum[z].size(); y++)
		{
			CalendarNum[z][y].resize(6); // 달력 하나의 세로열
			for (size_t x = 0; x < CalendarNum[z][y].size(); x++)
			{
				CalendarNum[z][y][x].resize(7); // 달력 하나의 가로열
			}
		}
	}

	int FirstWeekday = FindFirstWeekday(); // 1월 1일 요일 찾기 공식
	int MonthLen_Leap[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 윤년 각 달의 날짜수
	int MonthLen_NonLeap[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 평년 각 달의 날짜수
	int MonthFirstWeekday = FirstWeekday;

	for (int w = 0; w < CalendarNum.size(); w++)
	{
		for (int z = 0; z < CalendarNum[w].size(); z++)
		{
			int i = 1;
			int Month = (z + 1) + (w * 3);
			for (int y = 0; y < CalendarNum[w][z].size(); y++) // 한달
			{
				for (int x = 0; x < CalendarNum[w][z][y].size(); x++) // 일주일
				{
					float fx = static_cast<float>(x);
					float fy = static_cast<float>(y);
					float fz = static_cast<float>(z);
					float fw = static_cast<float>(w);
					CalendarNum[w][z][y][x] = CreateRender("PlayerCalendarNum.BMP", 1);
					CalendarNum[w][z][y][x]->SetScale({ 20,14 }); //default {20,15}
					CalendarNum[w][z][y][x]->SetPosition(-float4{ 315 + 15, 192 - (15 * 1) } + float4{ (30 * fx) + ((210 + (10 * 4)) * fz), (15 * fy) + ((15 * 6 + 15) * fw) });
					if (IsLeapYear())
					{
						if (x + (y * 7) < MonthFirstWeekday)
						{
							CalendarNum[w][z][y][x]->SetFrame(0);
						}
						else if (x + (y * 7) < MonthFirstWeekday + MonthLen_Leap[Month - 1])
						{
							if (0 == x)
							{
								CalendarNum[w][z][y][x]->SetFrame(32 + (i++));
							}
							else
							{
								CalendarNum[w][z][y][x]->SetFrame(i++);
							}
						}
						else
						{
							CalendarNum[w][z][y][x]->SetFrame(0);
						}
					}
					else
					{
						if (x + (y * 7) < MonthFirstWeekday)
						{
							CalendarNum[w][z][y][x]->SetFrame(0);
						}
						else if (x + (y * 7) < MonthFirstWeekday + MonthLen_NonLeap[Month - 1])
						{
							if (0 == x)
							{
								CalendarNum[w][z][y][x]->SetFrame(32 + (i++));
							}
							else
							{
								CalendarNum[w][z][y][x]->SetFrame(i++);
							}
						}
						else
						{
							CalendarNum[w][z][y][x]->SetFrame(0);
						}
					}
				}
			}
			if (IsLeapYear())
			{
				MonthFirstWeekday = (MonthFirstWeekday + MonthLen_Leap[Month - 1]) % 7;
			}
			else
			{
				MonthFirstWeekday = (MonthFirstWeekday + MonthLen_NonLeap[Month - 1]) % 7;
			}
		}
	}
}

void PlayerCalendar::YearNumRender()
{
	int Year1000 = CalendarYear / 1000;
	int Year100 = (CalendarYear - (Year1000 * 1000)) / 100;
	int Year10 = (CalendarYear - (Year1000 * 1000) - (Year100 * 100)) / 10;
	int Year1 = CalendarYear - (Year1000 * 1000) - (Year100 * 100) - (Year10 * 10);


	std::vector<std::vector<std::vector<GameEngineRender*>>> YearNum = std::vector<std::vector<std::vector<GameEngineRender*>>>();

	YearNum.resize(4);
	for (int y = 0; y < YearNum.size(); y++)
	{
		YearNum[y].resize(3);
		for (int x = 0; x < YearNum[y].size(); x++)
		{
			YearNum[y][x].resize(4);
		}
	}

	for (int z = 0; z < YearNum.size(); z++)
	{
		for (int y = 0; y < YearNum[z].size(); y++)
		{
			int CurYear = CalendarYear;

			for (int x = 0; x < YearNum[z][y].size(); x++)
			{
				float fx = static_cast<float>(x);
				float fy = static_cast<float>(y);
				float fz = static_cast<float>(z);
				YearNum[z][y][x] = CreateRender("PlayerYearNum.BMP", 1); // 인덱스상 3이 1,  5가 2 (인덱스 -1 / 2가 원래 숫자임)
				YearNum[z][y][x]->SetScale({ 8,12 }); //default {10,15} -> 8*6짜리 숫자가 년도로 들어가야함
				YearNum[z][y][x]->SetPosition(-float4{ 315 + 40 + 15, 192 - (15 * 1) + 5 } + float4{ (8 * fx) + ((210 + (10 * 4)) * fy), (15 * 6 + 15) * fz });
				//CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 192 - (15 * 1) } + float4{ (30 * fx) + (242 * fz), (15 * fy) + ((15 * 6 + 15) * fw) });
			}

			YearNum[z][y][0]->SetFrame(Year1000);
			YearNum[z][y][1]->SetFrame(Year100);
			YearNum[z][y][2]->SetFrame(Year10);
			YearNum[z][y][3]->SetFrame(Year1);

		}
	}
}

void PlayerCalendar::WeekdayRender()
{
	std::vector<std::vector<GameEngineRender*>> Weekday = std::vector<std::vector<GameEngineRender*>>();

	Weekday.resize(4);
	for (int y = 0; y < Weekday.size(); y++)
	{
		Weekday[y].resize(3);
	}

	for (int y = 0; y < Weekday.size(); y++)
	{
		for (int x = 0; x < Weekday[y].size(); x++)
		{
			float fx = static_cast<float>(x);
			float fy = static_cast<float>(y);
			Weekday[y][x] = CreateRender("PlayerWeek.BMP", 1);
			Weekday[y][x]->SetScale({ 210,10 }); //default {10,15} -> 8*6짜리 숫자가 년도로 들어가야함
			Weekday[y][x]->SetPosition(-float4{ 315 - 95 + 15, 192 + 15 - (15 * 1) } + float4{ ((210 + (10 * 4)) * fx), (15 * 6 + 15) * fy });
			//CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 192 - (15 * 1) } + float4{ (30 * fx) + (242 * fz), (15 * fy) + ((15 * 6 + 15) * fw) });

		}
	}
}

void PlayerCalendar::MonthNumRender()
{
	std::vector<std::vector<GameEngineRender*>> MonthNum = std::vector<std::vector<GameEngineRender*>>();

	MonthNum.resize(4);
	for (int y = 0; y < MonthNum.size(); y++)
	{
		MonthNum[y].resize(3);
	}

	for (int y = 0; y < MonthNum.size(); y++)
	{
		for (int x = 0; x < MonthNum[y].size(); x++)
		{
			float fx = static_cast<float>(x);
			float fy = static_cast<float>(y);
			MonthNum[y][x] = CreateRender("PlayerCalendarNum.BMP", 1);
			MonthNum[y][x]->SetFrame(x + 1 + (y * 3));
			MonthNum[y][x]->SetScale({ 20,16 });
			MonthNum[y][x]->SetPosition(-float4{ 315 + 30 + 15, 192 - (15 * 1) - 12 } + float4{ ((210 + (10 * 4)) * fx), (15 * 6 + 15) * fy });
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

void PlayerCalendar::SetOliveBirth()
{
	OliveBirth.SetDate(1200,8,15);
}
