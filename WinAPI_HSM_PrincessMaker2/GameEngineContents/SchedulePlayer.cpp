#include "SchedulePlayer.h"
#include "ScheduleCalendar.h"
#include "RaisingSimLevel.h"
#include "ScheduleAnimationPlayer.h"
#include "PaintingClass.h"
#include "Olive.h"
#include "UIManager.h"

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
		for (size_t y = 0; y < 6; y++)
		{
			for (size_t x = 0; x < 7; x++)
			{
				if (Save[y][x].Order == 1 && ParentLevel->GetToday().GetNextDate() == Save[y][x].DateSave)
				{
					PlayOneDaySchedule();
					if (Save[y][x].DateSave == AcScheduleCalendar->GetFirstScheduleEndDate())
					{
						AcScheduleCalendar->FirstScheduleSet = false;
						if (Save[y][x].DateSave == Date::GetMonthLastDate(Save[y][x].DateSave))
						{
							ScheduleEnd = true;
						}
					}
					return;
				}
			}
		}
	}
}

void SchedulePlayer::PlaySecondOrderSchedule(float _DeltaTime)
{
	Time += _DeltaTime;
	if (Time >= 1)
	{
		Time = 0;
		for (size_t y = 0; y < 6; y++)
		{
			for (size_t x = 0; x < 7; x++)
			{
				if (Save[y][x].Order == 2 && ParentLevel->GetToday().GetNextDate() == Save[y][x].DateSave)
				{
					PlayOneDaySchedule();
					if (Save[y][x].DateSave == AcScheduleCalendar->GetSecondScheduleEndDate())
					{
						AcScheduleCalendar->SecondScheduleSet = false;
						if (Save[y][x].DateSave == Date::GetMonthLastDate(Save[y][x].DateSave))
						{
							ScheduleEnd = true;
						}
					}
					return;
				}
			}
		}
	}
}

void SchedulePlayer::PlayThirdOrderSchedule(float _DeltaTime)
{
	Time += _DeltaTime;
	if (Time >= 1)
	{
		Time = 0;
		for (size_t y = 0; y < 6; y++)
		{
			for (size_t x = 0; x < 7; x++)
			{
				if (Save[y][x].Order == 3 && ParentLevel->GetToday().GetNextDate() == Save[y][x].DateSave)
				{
					PlayOneDaySchedule();
					if (Save[y][x].DateSave == AcScheduleCalendar->GetThirdScheduleEndDate())
					{
						AcScheduleCalendar->FirstScheduleSet = false;
						ScheduleEnd = true;
					}
					return;
				}
			}
		}
	}
}

void SchedulePlayer::On()
{
	GameEngineObject::On();
	AcScheduleAnimationPlayer->On();
	AcPaintingClass->On();
}

void SchedulePlayer::Off()
{
	GameEngineObject::Off();
	AcScheduleAnimationPlayer->Off();
	AcPaintingClass->Off();
}

void SchedulePlayer::Start()
{
	ParentLevel = dynamic_cast<RaisingSimLevel*>(GetLevel());
	AcScheduleAnimationPlayer = ParentLevel->CreateActor<ScheduleAnimationPlayer>(PM2ActorOrder::Menu2);
	AcScheduleCalendar = ParentLevel->GetUIManager()->GetScheduleCalendar();
	AcPaintingClass = ParentLevel->AcPaintingClass;
	Off();
}

void SchedulePlayer::Update(float _DeltaTime)
{
	if (FirstUpdateCheck == false)
	{
		FirstUpdateCheck = true;
		ScheduleEnd = false;
		PlayerStart();
	}
	else if(ScheduleEnd == false)
	{
		PlayerUpdate(_DeltaTime);
	}
	else
	{
		FirstUpdateCheck = false;
		ScheduleEnd = true;
		Off();
	}
}

void SchedulePlayer::PlayOneDaySchedule()
{
	AcScheduleAnimationPlayer->On();
	AcPaintingClass->On();
	Olive::OlivePlayer->OliveStatus += AcPaintingClass->GetStatusVariance();
	ParentLevel->GoToNextDay();
}

void SchedulePlayer::PlayerStart()
{
	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 7; x++)
		{
			Save[y][x].Order = AcScheduleCalendar->GetThisMonthSchedule()[y][x]->GetScheduleOrder();
			Save[y][x].DateSave = AcScheduleCalendar->GetThisMonthSchedule()[y][x]->DateValue;
			Save[y][x].ScheduleSave = AcScheduleCalendar->GetThisMonthSchedule()[y][x]->ScheduleValue;
		}
	}
}

void SchedulePlayer::PlayerUpdate(float _DeltaTime)
{
	if (AcScheduleCalendar->FirstScheduleSet)
	{
		PlayFirstOrderSchedule(_DeltaTime);
	}
	else if (AcScheduleCalendar->SecondScheduleSet)
	{
		PlaySecondOrderSchedule(_DeltaTime);
	}
	else if (AcScheduleCalendar->ThirdScheduleSet)
	{
		PlayThirdOrderSchedule(_DeltaTime);
	}
}
