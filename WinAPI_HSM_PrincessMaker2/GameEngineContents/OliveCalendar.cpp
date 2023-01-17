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

//void Calendar::CreateCalendar(int _year)
//{
//	// 윤년이야? 31 29 31 30 31 30 31 31 30 31 30 31
//	// 평년이야? 31 28 31 30 31 30 31 31 30 31 30 31
//	if (_month > 0 && _month < 13)
//	{
//		if (2 == _month) //2월이야?
//		{
//			if (0 == _year % 4) // 윤년이야?
//			{
//				//29일까지 채우기
//			}
//			else
//			{
//				//28일까지 채우기
//			}
//		}
//		else if (_month == 4||
//			_month == 6	||
//			_month == 9 || 
//			_month == 11) //작은달이야?
//		{
//			//30일까지 채우기
//		}
//		else // 큰달이야?
//		{
//			//31일까지 채우기
//		}
//	}
//	
//}

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
			for (int y = 0; y < CalendarNum[w][z].size(); y++)
			{
				for (int x = 0; x < CalendarNum[w][z][y].size(); x++)
				{
					float fx = static_cast<float>(x);
					float fy = static_cast<float>(y);
					float fz = static_cast<float>(z);
					float fw = static_cast<float>(w);
					CalendarNum[w][z][y][x] = CreateRender("OliveCalendarNum.BMP", 1);
					if (IsLeapYear())
					{
						if (x + (y * 7) < MonthFirstWeekday)
						{
							CalendarNum[w][z][y][x]->SetFrame(0);
							CalendarNum[w][z][y][x]->SetScale({ 20,15 });
							CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 240 } + float4{ (30 * fx) + (210 * fz), (20 * fy) + (120 * fw) });
						}
						else if (x + (y * 7) < MonthFirstWeekday + MonthLen_Leap[Month - 1])
						{
							CalendarNum[w][z][y][x]->SetFrame(i++);
							CalendarNum[w][z][y][x]->SetScale({ 20,15 });
							CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 240 } + float4{ (30 * fx) + (210 * fz), (20 * fy) + (120 * fw) });
						}
						else
						{
							CalendarNum[w][z][y][x]->SetFrame(0);
							CalendarNum[w][z][y][x]->SetScale({ 20,15 });
							CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 240 } + float4{ (30 * fx) + (210 * fz), (20 * fy) + (120 * fw) });
						}
					}
					else
					{
						if (x + (y * 7) < MonthFirstWeekday)
						{
							CalendarNum[w][z][y][x]->SetFrame(0);
							CalendarNum[w][z][y][x]->SetScale({ 20,15 });
							CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 240 } + float4{ (30 * fx) + (210 * fz), (20 * fy) + (120 * fw) });
						}
						else if (x + (y * 7) < MonthFirstWeekday + MonthLen_NonLeap[Month - 1])
						{
							CalendarNum[w][z][y][x]->SetFrame(i++);
							CalendarNum[w][z][y][x]->SetScale({ 20,15 });
							CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 240 } + float4{ (30 * fx) + (210 * fz), (20 * fy) + (120 * fw) });
						}
						else
						{
							CalendarNum[w][z][y][x]->SetFrame(0);
							CalendarNum[w][z][y][x]->SetScale({ 20,15 });
							CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 240 } + float4{ (30 * fx) + (210 * fz), (20 * fy) + (120 * fw) });
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

	/*for (int w = 0; w < CalendarNum.size(); w++)
	{
		for (int z = 0; z < CalendarNum[w].size(); z++)
		{
			for (int y = 0; y < CalendarNum[w][z].size(); y++)
			{
				for (int x = 0; x < CalendarNum[w][z][y].size(); x++)
				{
					float fx = static_cast<float>(x);
					float fy = static_cast<float>(y);
					float fz = static_cast<float>(z);
					float fw = static_cast<float>(w);
					CalendarNum[w][z][y][x] = CreateRender("OliveCalendarNum.BMP", 1);
					CalendarNum[w][z][y][x]->SetFrame((x + 1) + (y * 7));
					CalendarNum[w][z][y][x]->SetScale({ 20,15 });
					CalendarNum[w][z][y][x]->SetPosition(-float4{ 315, 240 } + float4{ (30 * fx) + (210 * fz), (20 * fy) + (120 * fw) });
				}
			}
		}
	}*/

}

bool OliveCalendar::IsLeapYear()
{
	if ((0 == (YearValue % 4) && 0 != (YearValue % 100)) || 0 == (YearValue % 400))
	{
		return true;
	}
	return false;
}
