#include "ScheduleCalendar.h"
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

ScheduleCalendar::ScheduleCalendar()
{

}

ScheduleCalendar::~ScheduleCalendar()
{

}

void ScheduleCalendar::Start()
{
	SetPos(ActorPos);
	CalendarFrame = CreateRender("Calendar.bmp", PM2RenderOrder::Menu1);
	CalendarFrame->SetScaleToImage();
	SetThisMonthCalendar();
	SetDayNumRender();
}

void ScheduleCalendar::SetDayNumRender()
{
	int MonthFirstWeekday = Date::FindMonthFirstWeekday(Today.GetYear(), Today.GetMonth());
	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 7; x++)
		{
			if (x + (y * 7) < MonthFirstWeekday)
			{
				DayNumRender[y][x].SetOwner(this);
				DayNumRender[y][x].SetImage("Num.bmp", DayNumRenderScale, static_cast<int>(PM2RenderOrder::Menu1_Display), RGB(255, 0, 255));
				DayNumRender[y][x].SetAlign(Align::Right);
				DayNumRender[y][x].SetRenderPos(FirstDayNumRenderPos + DayNumRenderInterval * float4{ static_cast<float>(x), static_cast<float>(y) });
				DayNumRender[y][x].SetValue(0);
			}
			else
			{
				DayNumRender[y][x].SetOwner(this);
				DayNumRender[y][x].SetImage("Num.bmp", DayNumRenderScale, static_cast<int>(PM2RenderOrder::Menu1_Display), RGB(255, 0, 255));
				DayNumRender[y][x].SetAlign(Align::Right);
				DayNumRender[y][x].SetRenderPos(FirstDayNumRenderPos + DayNumRenderInterval * float4{ static_cast<float>(x), static_cast<float>(y) });
				DayNumRender[y][x].SetValue(10);
			}
		}
	}
}

void ScheduleCalendar::SetThisMonthCalendar()
{
	ThisMonthCalendar = Date::GetOneMonthCalendar(Today.GetYear(), Today.GetMonth());
}
