#include "ScheduleCalendar.h"
#include <GameEngineCore/GameEngineRender.h>
#include "RaisingSimLevel.h"
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
	SetYearNumRender();
	SetMonthRender();
	SetDayNumRender();
	Off();
}

void ScheduleCalendar::Update(float _DeltaTime)
{
	if (Today != dynamic_cast<RaisingSimLevel*>(GetLevel())->GetToday())
	{
		Today = dynamic_cast<RaisingSimLevel*>(GetLevel())->GetToday();
		NextDate = Today.GetNextDate();
		UpdateDayNumRender();
		UpdateYearNumRender();
		UpdateMonthRender();
	}
}

void ScheduleCalendar::SetDayNumRender()
{
	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 7; x++)
		{
			DayNumRender[y][x].SetOwner(this);
			DayNumRender[y][x].SetImage("Num.bmp", DayNumRenderScale_2, static_cast<int>(PM2RenderOrder::Menu1_Display), RGB(255, 0, 255));
			DayNumRender[y][x].SetAlign(Align::Right);
			DayNumRender[y][x].SetRenderPos(FirstDayNumRenderPos_2 + DayNumRenderInterval * float4{ static_cast<float>(x), static_cast<float>(y) });
			DayNumRender[y][x].SetValue(0);
		}
	}
}

void ScheduleCalendar::SetYearNumRender()
{
	YearNumRender.SetOwner(this);
	YearNumRender.SetImage("Num.bmp", YearNumRenderScale, static_cast<int>(PM2RenderOrder::Menu1_Display), RGB(255, 0, 255));
	YearNumRender.SetAlign(Align::Right);
	YearNumRender.SetRenderPos(YearNumRenderPos);
}

void ScheduleCalendar::SetMonthRender()
{
	MonthRender = CreateRender("Num_Month.bmp", PM2RenderOrder::Menu1_Display);
	MonthRender->SetScale(MonthRenderScale);
	MonthRender->SetPosition(MonthRenderPos);
}

void ScheduleCalendar::UpdateDayNumRender()
{
	SetThisMonthCalendar();
	int MonthFirstWeekday = Date::FindMonthFirstWeekday(NextDate.GetYear(), NextDate.GetMonth());
	int DayIndex = 0;
	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 7; x++)
		{
			if (x + (y * 7) < MonthFirstWeekday)
			{
				DayNumRender[y][x].SetImage("Num.bmp", DayNumRenderScale_2, static_cast<int>(PM2RenderOrder::Menu1_Display), RGB(255, 0, 255));
				DayNumRender[y][x].SetRenderPos(FirstDayNumRenderPos_2 + DayNumRenderInterval * float4{ static_cast<float>(x), static_cast<float>(y) });
				DayNumRender[y][x].SetValue(0);
				DayNumRender[y][x].Off();
			}
			else if (x + (y * 7) < MonthFirstWeekday + ThisMonthCalendar.size())
			{
				int SetDay = ThisMonthCalendar[DayIndex].GetDay();

				if (1 == GameEngineMath::GetLenth(SetDay))
				{
					DayNumRender[y][x].SetImage("Num_Age.bmp", DayNumRenderScale_1, static_cast<int>(PM2RenderOrder::Menu1_Display), RGB(255, 0, 255));
					DayNumRender[y][x].SetRenderPos(FirstDayNumRenderPos_1 + DayNumRenderInterval * float4{ static_cast<float>(x), static_cast<float>(y) });
					DayNumRender[y][x].On();
				}
				else if (2 == GameEngineMath::GetLenth(SetDay))
				{
					DayNumRender[y][x].SetImage("Num.bmp", DayNumRenderScale_2, static_cast<int>(PM2RenderOrder::Menu1_Display), RGB(255, 0, 255));
					DayNumRender[y][x].SetRenderPos(FirstDayNumRenderPos_2 + DayNumRenderInterval * float4{ static_cast<float>(x), static_cast<float>(y) });
					DayNumRender[y][x].On();
				}

				DayNumRender[y][x].SetValue(SetDay);
				if (NextDate > ThisMonthCalendar[DayIndex])
				{
					DayNumRender[y][x].Off();
				}
				DayIndex++;
			}
			else
			{
				DayNumRender[y][x].SetImage("Num.bmp", DayNumRenderScale_2, static_cast<int>(PM2RenderOrder::Menu1_Display), RGB(255, 0, 255));
				DayNumRender[y][x].SetRenderPos(FirstDayNumRenderPos_2 + DayNumRenderInterval * float4{ static_cast<float>(x), static_cast<float>(y) });
				DayNumRender[y][x].SetValue(0);
				DayNumRender[y][x].Off();
			}
		}
	}
}

void ScheduleCalendar::UpdateYearNumRender()
{
	YearNumRender.SetValue(NextDate.GetYear());
}

void ScheduleCalendar::UpdateMonthRender()
{
	MonthRender->SetFrame(NextDate.GetMonth() - 1);
}

void ScheduleCalendar::SetThisMonthCalendar()
{
	ThisMonthCalendar = Date::GetOneMonthCalendar(NextDate.GetYear(), NextDate.GetMonth());
}
