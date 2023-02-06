#include "Calendar.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>


Calendar::Calendar()
{

}

Calendar::~Calendar()
{

}

//void Calendar::SetCalendarData(int _YYYY, int _MM)
//{
//	int a = 0;
//	for (int y = 0; y < CalendarData.size(); y++)
//	{
//		for (int x = 0; x < CalendarData[y].size(); x++)
//		{
//			while (x + a == static_cast<int>(Date::GetOneMonthCalendar(_YYYY, _MM)[6 * y + x].GetWeekDay()))
//			{
//				++a;
//			}
//			CalendarData[y][x + a] = Date::GetOneMonthCalendar(_YYYY, _MM)[6 * y + x];
//		}
//	}
//}

void Calendar::Start()
{
	//SetPos(GameEngineWindow::GetScreenSize().half());
	//Today.SetDate(1211,2,16);
	//CalendarData.resize(6);
	//for (size_t y = 0; y < CalendarData.size(); y++)
	//{
	//	CalendarData[y].resize(7);
	//}
	//SetCalendarData(Today.GetYear(), Today.GetMonth());
	//CalendarNumRender.resize(6);
	//for (size_t y = 0; y < CalendarNumRender.size(); y++)
	//{
	//	CalendarNumRender[y].resize(7);
	//}
	//CalendarFrameRender = CreateRender("Calendar.bmp", PM2RenderOrder::Menu1);
	//CalendarNumRender.resize(CalendarData.size());
	//for (size_t y = 0; y < 6; y++)
	//{
	//	for (size_t x = 0; x < 7; x++)
	//	{
	//		CalendarNumRender[y*6 + x] = CreateRender("Num.bmp", PM2RenderOrder::Menu1_Display);
	//		CalendarNumRender[y*6 + x]->SetFrame(CalendarData[6 * y + x] % 10);
	//		CalendarNumRender[y*6 + x]->SetScale({10,20});
	//		CalendarNumRender[y*6 + x]->SetPosition({10.0f* static_cast<float>(x), 20.0f * static_cast<float>(y) });
	//	}
	//}
}

void Calendar::Update(float _DeltaTime)
{
}

void Calendar::Render(float _Time)
{
}
