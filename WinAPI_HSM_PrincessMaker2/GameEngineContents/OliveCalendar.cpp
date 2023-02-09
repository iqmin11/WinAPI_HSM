#include "OliveCalendar.h"
#include <vector>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnums.h"


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

	BackgroundRender = CreateRender("SetOliveBirth.BMP", PM2RenderOrder::BackGround);
	BackgroundRender ->SetScaleToImage();
	DateNumRender();
	MonthNumRender();
	YearNumRender();
	WeekdayRender();
	Off();
}

void OliveCalendar::Update(float _DeltaTime)
{

}

void OliveCalendar::Render(float _DeltaTime)
{
	
}


int OliveCalendar::FindFirstWeekday()
{
	int PrevYear = CalendarYear - 1;
	return (PrevYear + ((PrevYear / 4) - (PrevYear / 100) + (PrevYear / 400)) + 1) % 7;
}

void OliveCalendar::DateNumRender()
{
	int FirstWeekday = FindFirstWeekday(); // 1월 1일 요일 찾기 공식
	int MonthLen_Leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 윤년 각 달의 날짜수
	int MonthLen_NonLeap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 평년 각 달의 날짜수
	int MonthFirstWeekday = FirstWeekday; 
	
	for (int w = 0; w < 4; w++)
	{
		for (int z = 0; z < 3; z++)
		{
			int i = 1;
			int Month = (z + 1) + (w * 3);
			for (int y = 0; y < 6; y++) // 한달
			{
				for (int x = 0; x < 7; x++) // 일주일
				{
					float fx = static_cast<float>(x);
					float fy = static_cast<float>(y);
					float fz = static_cast<float>(z);
					float fw = static_cast<float>(w);
					DateRender[w][z][y][x] = CreateRender("OliveCalendarNum.BMP", PM2RenderOrder::Contents);
					DateRender[w][z][y][x]->SetScale({20,14}); //default {20,15}
					DateRender[w][z][y][x]->SetPosition(-float4{ 315 + 15, 192 - (15 * 1) } + float4{ (30 * fx) + ((210 + (10 * 4)) * fz), (15 * fy) + ((15 * 6 + 15) * fw) });
					if (IsLeapYear())
					{
						if (x + (y * 7) < MonthFirstWeekday)
						{
							DateRender[w][z][y][x]->SetFrame(0);
						}
						else if (x + (y * 7) < MonthFirstWeekday + MonthLen_Leap[Month - 1])
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
					else
					{
						if (x + (y * 7) < MonthFirstWeekday)
						{
							DateRender[w][z][y][x]->SetFrame(0);
						}
						else if (x + (y * 7) < MonthFirstWeekday + MonthLen_NonLeap[Month - 1])
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

void OliveCalendar::YearNumRender()
{
	int Year1000 = CalendarYear / 1000;
	int Year100 = (CalendarYear - (Year1000*1000)) / 100;
	int Year10 = (CalendarYear - (Year1000*1000) - (Year100*100)) / 10;
	int Year1 = CalendarYear - (Year1000 * 1000) - (Year100 * 100) - (Year10 * 10);
	
	for (int z = 0; z < 4; z++)
	{
		for (int y = 0; y < 3; y++)
		{
			int CurYear = CalendarYear;
			
			for (int x = 0; x < 4; x++)
			{
				float fx = static_cast<float>(x);
				float fy = static_cast<float>(y);
				float fz = static_cast<float>(z);
				YearRender[z][y][x] = CreateRender("OliveYearNum.BMP", PM2RenderOrder::Contents); // 인덱스상 3이 1,  5가 2 (인덱스 -1 / 2가 원래 숫자임)
				YearRender[z][y][x]->SetScale({ 8,12 }); //default {10,15} -> 8*6짜리 숫자가 년도로 들어가야함
				YearRender[z][y][x]->SetPosition(-float4{ 315 + 40 + 15, 192 - (15 * 1) + 5 } + float4{ (8 * fx) + ((210 + (10 * 4)) * fy), (15 * 6 + 15) * fz });
				//CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 192 - (15 * 1) } + float4{ (30 * fx) + (242 * fz), (15 * fy) + ((15 * 6 + 15) * fw) });
			}
			
			YearRender[z][y][0]->SetFrame(Year1000);
			YearRender[z][y][1]->SetFrame(Year100);
			YearRender[z][y][2]->SetFrame(Year10);
			YearRender[z][y][3]->SetFrame(Year1);
		
		}
	}
}

void OliveCalendar::WeekdayRender()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			float fx = static_cast<float>(x);
			float fy = static_cast<float>(y);
			WeekRender[y][x] = CreateRender("OliveWeek.BMP", PM2RenderOrder::Contents);
			WeekRender[y][x]->SetScale({ 210,10 }); //default {10,15} -> 8*6짜리 숫자가 년도로 들어가야함
			WeekRender[y][x]->SetPosition(-float4{ 315-95 + 15, 192 + 15 - (15 * 1) } + float4{ ((210 + (10 * 4)) * fx), (15 * 6 + 15) * fy });
			//CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 192 - (15 * 1) } + float4{ (30 * fx) + (242 * fz), (15 * fy) + ((15 * 6 + 15) * fw) });

		}
	}
}

void OliveCalendar::MonthNumRender()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			float fx = static_cast<float>(x);
			float fy = static_cast<float>(y);
			MonthRender[y][x] = CreateRender("OliveCalendarNum.BMP", PM2RenderOrder::Contents);
			MonthRender[y][x]->SetFrame(x + 1 + (y*3)); 
			MonthRender[y][x]->SetScale({ 20,16 });
			MonthRender[y][x]->SetPosition(-float4{ 315 + 30 + 15, 192 - (15 * 1) - 12 } + float4{ ((210 + (10*4)) * fx), (15 * 6 + 15) * fy });
			//CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 192 - (15 * 1) } + float4{ (30 * fx) + (242 * fz), (15 * fy) + ((15 * 6 + 15) * fw) });
		}
	}
}



bool OliveCalendar::IsLeapYear() // 윤년이니?
{
	if ((0 == (CalendarYear % 4) && 0 != (CalendarYear % 100)) || 0 == (CalendarYear % 400))
	{
		return true;
	}
	return false;
}
