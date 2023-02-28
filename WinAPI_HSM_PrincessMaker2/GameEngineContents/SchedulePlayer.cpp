#include "SchedulePlayer.h"
#include "ScheduleCalendar.h"
#include "RaisingSimLevel.h"

SchedulePlayer::SchedulePlayer()
{

}

SchedulePlayer::~SchedulePlayer()
{

}

void SchedulePlayer::PlayFirstOrderSchedule(float _DeltaTime)
{
	Time += _DeltaTime;
	if (Time >= 1)
	{
		Time = 0;
		for (size_t y = 0; y < AcScheduleCalendar->GetThisMonthSchedule().size(); y++)
		{
			for (size_t x = 0; x < AcScheduleCalendar->GetThisMonthSchedule()[y].size(); x++)
			{
				if (AcScheduleCalendar->GetThisMonthSchedule()[y][x]->GetScheduleOrder() == 1 && dynamic_cast<RaisingSimLevel*>(GetLevel())->GetToday() == AcScheduleCalendar->GetThisMonthSchedule()[y][x]->DateValue && AcScheduleCalendar->GetThisMonthSchedule()[y][x]->IsSchedulePrepare() == true)
				{
					//PlayOneDaySchedule();
					return;
				}
			}
		}
	}
	//AcScheduleCalendar->FirstScheduleSet = false;
	//AcScheduleCalendar->ScheduleSetEnd = false;
}

void SchedulePlayer::Start()
{
}

void SchedulePlayer::Update(float _DeltaTime)
{
}
