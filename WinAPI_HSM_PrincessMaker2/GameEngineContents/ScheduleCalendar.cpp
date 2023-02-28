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

void ScheduleCalendar::On()
{
	GameEngineObject::On();
	for (size_t y = 0; y < ThisMonthSchedule.size(); y++)
	{
		for (size_t x = 0; x < ThisMonthSchedule[y].size(); x++)
		{
			ThisMonthSchedule[y][x]->On();
		}
	}

}

void ScheduleCalendar::Off()
{
	GameEngineObject::Off();
	for (size_t y = 0; y < ThisMonthSchedule.size(); y++)
	{
		for (size_t x = 0; x < ThisMonthSchedule[y].size(); x++)
		{
			ThisMonthSchedule[y][x]->Off();
		}
	}
}

void ScheduleCalendar::ScheduleSetting(ScheduleLabel _Schedule)
{
	Date StartDate = NextDate;
	Date LastDate = Date::GetMonthLastDate(NextDate);
	if (!FirstScheduleSet && !SecondScheduleSet && !ThirdScheduleSet)
	{
		FirstScheduleSet = true;
		for (size_t y = 0; y < ThisMonthSchedule.size(); y++)
		{
			for (size_t x = 0; x < ThisMonthSchedule[y].size(); x++)
			{
				if (ThisMonthSchedule[y][x]->DateValue < StartDate)
				{
					continue;
				}
				else if (ThisMonthSchedule[y][x]->DateValue >= StartDate && ThisMonthSchedule[y][x]->DateValue < (StartDate + 10))
				{
					ThisMonthSchedule[y][x]->ScheduleValue = _Schedule;
					ThisMonthSchedule[y][x]->SetScheduleOrder(1);
					ThisMonthSchedule[y][x]->SchedulePrepare();
					if (ThisMonthSchedule[y][x]->DateValue == LastDate)
					{
						ThisMonthSchedule[y][x]->ScheduleValue = _Schedule;
						ThisMonthSchedule[y][x]->SetScheduleOrder(1);
						ThisMonthSchedule[y][x]->SchedulePrepare();
						ScheduleSetEnd = true;
						return;
					}
				}
			}
		}
	}
	else if (FirstScheduleSet && !SecondScheduleSet && !ThirdScheduleSet)
	{
		SecondScheduleSet = true;
		for (size_t y = 0; y < ThisMonthSchedule.size(); y++)
		{
			for (size_t x = 0; x < ThisMonthSchedule[y].size(); x++)
			{
				if (ThisMonthSchedule[y][x]->DateValue < StartDate + 10)
				{
					continue;
				}
				else if (ThisMonthSchedule[y][x]->DateValue >= (StartDate + 10) && ThisMonthSchedule[y][x]->DateValue < (StartDate + 20))
				{
					ThisMonthSchedule[y][x]->ScheduleValue = _Schedule;
					ThisMonthSchedule[y][x]->SetScheduleOrder(2);
					ThisMonthSchedule[y][x]->SchedulePrepare();
					if (ThisMonthSchedule[y][x]->DateValue == LastDate)
					{
						ThisMonthSchedule[y][x]->ScheduleValue = _Schedule;
						ThisMonthSchedule[y][x]->SetScheduleOrder(2);
						ThisMonthSchedule[y][x]->SchedulePrepare();
						ScheduleSetEnd = true;
						return; 
					}
				}
			}
		}
	}
	else if (FirstScheduleSet && SecondScheduleSet && !ThirdScheduleSet)
	{
		ThirdScheduleSet = true;
		for (size_t y = 0; y < ThisMonthSchedule.size(); y++)
		{
			for (size_t x = 0; x < ThisMonthSchedule[y].size(); x++)
			{
				if (ThisMonthSchedule[y][x]->DateValue < StartDate + 20)
				{
					continue;
				}
				else if (ThisMonthSchedule[y][x]->DateValue >= (StartDate + 20) && ThisMonthSchedule[y][x]->DateValue <= LastDate)
				{
					ThisMonthSchedule[y][x]->ScheduleValue = _Schedule;
					ThisMonthSchedule[y][x]->SetScheduleOrder(3);
					ThisMonthSchedule[y][x]->SchedulePrepare();
				}
					ScheduleSetEnd = true;
			}
		}
	}
	else
	{
		MsgAssert("순서 제대로 셋팅 안해줬습니다");
	}
	
}

void ScheduleCalendar::CancelSchedule()
{
	Date StartDate = NextDate;
	Date LastDate = Date::GetMonthLastDate(NextDate);
	if (FirstScheduleSet && !SecondScheduleSet && !ThirdScheduleSet)
	{
		FirstScheduleSet = false;
		for (size_t y = 0; y < ThisMonthSchedule.size(); y++)
		{
			for (size_t x = 0; x < ThisMonthSchedule[y].size(); x++)
			{
				if (ThisMonthSchedule[y][x]->DateValue < StartDate)
				{
					continue;
				}
				else if (ThisMonthSchedule[y][x]->DateValue >= StartDate && ThisMonthSchedule[y][x]->DateValue < (StartDate + 10))
				{
					ThisMonthSchedule[y][x]->ScheduleValue = ScheduleLabel::Null;
					ThisMonthSchedule[y][x]->SetScheduleOrder(0);
					ThisMonthSchedule[y][x]->ScheduleEnd();
					ScheduleSetEnd = false;
				}
			}
		}
	}
	else if (FirstScheduleSet && SecondScheduleSet && !ThirdScheduleSet)
	{
		SecondScheduleSet = false;
		for (size_t y = 0; y < ThisMonthSchedule.size(); y++)
		{
			for (size_t x = 0; x < ThisMonthSchedule[y].size(); x++)
			{
				if (ThisMonthSchedule[y][x]->DateValue < StartDate + 10)
				{
					continue;
				}
				else if (ThisMonthSchedule[y][x]->DateValue >= (StartDate + 10) && ThisMonthSchedule[y][x]->DateValue < (StartDate + 20))
				{
					ThisMonthSchedule[y][x]->ScheduleValue = ScheduleLabel::Null;
					ThisMonthSchedule[y][x]->SetScheduleOrder(0);
					ThisMonthSchedule[y][x]->ScheduleEnd();
					ScheduleSetEnd = false;
				}
			}
		}
	}
	else if (FirstScheduleSet && SecondScheduleSet && ThirdScheduleSet)
	{
		ThirdScheduleSet = false;
		for (size_t y = 0; y < ThisMonthSchedule.size(); y++)
		{
			for (size_t x = 0; x < ThisMonthSchedule[y].size(); x++)
			{
				if (ThisMonthSchedule[y][x]->DateValue < StartDate + 20)
				{
					continue;
				}
				else if (ThisMonthSchedule[y][x]->DateValue >= (StartDate + 20) && ThisMonthSchedule[y][x]->DateValue <= LastDate)
				{
					ThisMonthSchedule[y][x]->ScheduleValue = ScheduleLabel::Null;
					ThisMonthSchedule[y][x]->SetScheduleOrder(0);
					ThisMonthSchedule[y][x]->ScheduleEnd();
					ScheduleSetEnd = false;
				}
			}
		}
	}
}

void ScheduleCalendar::Reset()
{
	for (size_t y = 0; y < ThisMonthSchedule.size(); y++)
	{
		for (size_t x = 0; x < ThisMonthSchedule[y].size(); x++)
		{
			ThisMonthSchedule[y][x]->ScheduleValue = ScheduleLabel::Null;
			ThisMonthSchedule[y][x]->SetScheduleOrder(0);
			ThisMonthSchedule[y][x]->ScheduleEnd();
		}
	}
	FirstScheduleSet = false;
	SecondScheduleSet = false;
	ThirdScheduleSet = false;
	ScheduleSetEnd = false;
}

void ScheduleCalendar::Start()
{
	SetPos(ActorPos);
	CalendarFrame = CreateRender("Calendar.bmp", PM2RenderOrder::Menu1);
	CalendarFrame->SetScaleToImage();
	SetThisMonthSchedule();
	SetYearNumRender();
	SetMonthRender();
	Off();
}

void ScheduleCalendar::Update(float _DeltaTime)
{
	if (Today != dynamic_cast<RaisingSimLevel*>(GetLevel())->GetToday())
	{
		Today = dynamic_cast<RaisingSimLevel*>(GetLevel())->GetToday();
		NextDate = Today.GetNextDate();
		UpdateMonthCalendar();
		UpdateYearNumRender();
		UpdateMonthRender();
	}
}

void ScheduleCalendar::SetThisMonthSchedule()
{
	ThisMonthSchedule.resize(6);
	for (size_t y = 0; y < ThisMonthSchedule.size(); y++)
	{
		ThisMonthSchedule[y].resize(7);
	}

	GameEngineLevel* Level = GetLevel();

	for (size_t y = 0; y < ThisMonthSchedule.size(); y++)
	{
		for (size_t x = 0; x < ThisMonthSchedule[y].size(); x++)
		{
			ThisMonthSchedule[y][x] = Level->CreateActor<OnedaySchedule>(PM2ActorOrder::Menu1);
			ThisMonthSchedule[y][x]->SetPos(FirstScheduleActorPos + ScheduleActorInterval *float4{ static_cast<float>(x), static_cast<float>(y) });
		}
	}
}

void ScheduleCalendar::UpdateMonthCalendar()
{
	std::vector<Date> OneMonthCalendar = Date::GetOneMonthCalendar(NextDate.GetYear(), NextDate.GetMonth());

	int MonthFirstWeekday = Date::FindMonthFirstWeekday(NextDate.GetYear(), NextDate.GetMonth());
	int DayIndex = 0;
	for (size_t y = 0; y < ThisMonthSchedule.size(); y++)
	{
		for (size_t x = 0; x < ThisMonthSchedule[y].size(); x++)
		{
			if (x + (y * 7) < MonthFirstWeekday)
			{
				ThisMonthSchedule[y][x]->DateValue.SetNullDate();
				ThisMonthSchedule[y][x]->UpdateDayNumRender();
			}
			else if (x + (y * 7) < MonthFirstWeekday + OneMonthCalendar.size())
			{
				ThisMonthSchedule[y][x]->DateValue.SetDate(OneMonthCalendar[DayIndex++]);
				ThisMonthSchedule[y][x]->UpdateDayNumRender();
			}
			else
			{
				ThisMonthSchedule[y][x]->DateValue.SetNullDate();
				ThisMonthSchedule[y][x]->UpdateDayNumRender();
			}
		}
	}
}

void ScheduleCalendar::UpdateDayNumRender()
{


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

void ScheduleCalendar::UpdateYearNumRender()
{
	YearNumRender.SetValue(NextDate.GetYear());
}

void ScheduleCalendar::UpdateMonthRender()
{
	MonthRender->SetFrame(NextDate.GetMonth() - 1);
}

