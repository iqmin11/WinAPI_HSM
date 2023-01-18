#include "OliveCalendar.h"
#include <vector>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>


OliveCalendar::OliveCalendar()
{

}

OliveCalendar::~OliveCalendar()
{

}

void OliveCalendar::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	//GameEngineRender* WeekRender = CreateRender("OliveWeek.BMP");

	GameEngineRender* Background = CreateRender("SetOliveBirth.BMP", 0);
	
	CalendarNumRender();



	/*for (int y = 0; y < CalendarNum.size(); y++)
	{
		for (int x = 0; x < CalendarNum[y].size(); x++)
		{
			float fx = static_cast<float>(x);
			float fy = static_cast<float>(y);
			CalendarNum[y][x] = CreateRender("OliveCalendarNum.BMP", 1);
			if (31 < (x + 1) + (y * 7))
			{
				break;
			}
			CalendarNum[y][x]->SetFrame((x+1) + (y*7));
			CalendarNum[y][x]->SetScale({ 20,15 });
			CalendarNum[y][x]->SetPosition(float4{ -105,-51 } + float4{ 30 * (fx), 20 * fy });
		}
	}
	GameEngineRender* Week = CreateRender("OliveWeek.BMP", 2);
	Week->SetScale({ 210,10 });
	Week->SetPosition(float4{ -10,-66 });*/


}

void OliveCalendar::Update(float _DeltaTime)
{
}

void OliveCalendar::Render(float _DeltaTime)
{
	
}


int OliveCalendar::FindFirstWeekday()
{
	int PrevYear = YearValue - 1;
	return (PrevYear + ((PrevYear / 4) - (PrevYear / 100) + (PrevYear / 400)) + 1) % 7;
}

void OliveCalendar::CalendarNumRender()
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
	int MonthLen_Leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 윤년 각 달의 날짜수
	int MonthLen_NonLeap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 평년 각 달의 날짜수
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
					CalendarNum[w][z][y][x] = CreateRender("OliveCalendarNum.BMP", 1);
					CalendarNum[w][z][y][x]->SetScale({ 20,15 });
					CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 240 } + float4{ (30 * fx) + (210 * fz), (20 * fy) + (120 * fw) });
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

bool OliveCalendar::IsLeapYear() // 윤년이니?
{
	if ((0 == (YearValue % 4) && 0 != (YearValue % 100)) || 0 == (YearValue % 400))
	{
		return true;
	}
	return false;
}
