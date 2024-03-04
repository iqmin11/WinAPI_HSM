#include "SchedulePlayer.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "ScheduleCalendar.h"
#include "RaisingSimLevel.h"
#include "ScheduleAnimationPlayer.h"
#include "Olive.h"
#include "FoodCostDialog.h"
#include "ScheduleDialog.h"
#include "MainMenu.h"

#include "SchedulePlayerGuage.h"
#include "ScheduleMessageBox.h"

#include "PaintingClass.h"
#include "DanceClass.h"
#include "FencingClass.h"
#include "FightingClass.h"
#include "MagicClass.h"
#include "PaintingClass.h"
#include "PoetryClass.h"
#include "ProtocolClass.h"
#include "ScienceClass.h"
#include "StrategyClass.h"
#include "TheologyClass.h"

SchedulePlayer* SchedulePlayer::AcSchedulePlayer = nullptr;
bool SchedulePlayer::IsPartOfScheduleEnd = false;

SchedulePlayer::SchedulePlayer()
{
	AcSchedulePlayer = this;
}

SchedulePlayer::~SchedulePlayer()
{

}

void SchedulePlayer::Off()
{
	GameEngineObject::Off();
	AcScheduleAnimationPlayer->Off();
	AcFoodCostDialog->Off();
	AcPaintingClass->Off();
}

void SchedulePlayer::Start()
{
	ParentLevel = dynamic_cast<RaisingSimLevel*>(GetLevel());
	AcScheduleAnimationPlayer = ParentLevel->CreateActor<ScheduleAnimationPlayer>(PM2ActorOrder::Menu2);
	AcScheduleCalendar = ScheduleCalendar::GetAcScheduleCalendar();
	
	AcDanceClass = ParentLevel->AcDanceClass;
	AcFencingClass = ParentLevel->AcFencingClass;
	AcFightingClass = ParentLevel->AcFightingClass;
	AcMagicClass = ParentLevel->AcMagicClass;
	AcPaintingClass = ParentLevel->AcPaintingClass;
	AcPoetryClass = ParentLevel->AcPoetryClass;
	AcProtocolClass = ParentLevel->AcProtocolClass;
	AcScienceClass = ParentLevel->AcScienceClass;
	AcStrategyClass = ParentLevel->AcStrategyClass;
	AcTheologyClass = ParentLevel->AcTheologyClass;
	
	AcFoodCostDialog = ParentLevel->CreateActor<FoodCostDialog>(PM2ActorOrder::Menu2);
	AcScheduleDialog = ParentLevel->GetAcScheduleDialog();
	AcSchedulePlayerGuage = ParentLevel->CreateActor<SchedulePlayerGuage>(PM2ActorOrder::Menu2);
	AcScheduleMessageBox = ParentLevel->CreateActor<ScheduleMessageBox>(PM2ActorOrder::Menu2);

	BGMPlayer = ParentLevel->GetBGMPlayer();
	
	Off();
}

void SchedulePlayer::Update(float _DeltaTime)
{
	if (!FirstUpdateCheck)
	{
		FirstUpdateCheck = true;
		PayDiet();
		AcFoodCostDialog->On();
		BGMPlayer->Stop();
		*BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("13_Training.mp3");
	}
	else if(!AcFoodCostDialog->IsUpdate())
	{
		if (!FirstScheduleUpdateCheck)
		{
			IsPartOfScheduleEnd = false;
			FirstScheduleUpdateCheck = true;
			AcScheduleDialog->UpdateScheduleDialog(Save.begin()->Schedule, ScheduleSituation::ScheduleStart);
		}
		else if (!AcScheduleDialog->IsUpdate())
		{
			ScheduleSave Prev = *(Save.begin());

			Time += _DeltaTime;
			if (Time >= 1)
			{
				IsPartOfScheduleEnd = false;
				Time = 0;
				AnimationPlay();
				PlayOneDaySchedule();
				Save.pop_front();
			}

			if (Save.size() == 0)
			{
				IsPartOfScheduleEnd = true;
				AnimationOff();
				AcScheduleDialog->UpdateScheduleDialog(Prev.Schedule, ScheduleSituation::ScheduleEnd);
				FirstUpdateCheck = false;
				FirstScheduleUpdateCheck = false;
				MainMenu::GetAcMainMenu()->On();
				AcScheduleCalendar->Reset();
				Off();
				BGMPlayer->Stop();
				switch (ParentLevel->GetTodaySeason())
				{
				case Season::Spring:
					*BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("04_Main_screen_(Spring).mp3");
					break;
				case Season::Summer:
					*BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("05_Main_screen_(Summer).mp3");
					break;
				case Season::Fall:
					*BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("06_Main_screen_(Autumn).mp3");
					break;
				case Season::Winter:
					*BGMPlayer = GameEngineResources::GetInst().SoundPlayToControl("07_Main_screen_(Winter).mp3");
					break;
				default:
					break;
				}
				return;
			}

			ScheduleSave Next = *(Save.begin());

			if (Prev.Order != Next.Order)
			{
				IsPartOfScheduleEnd = true;
				AnimationOff();
				AcScheduleDialog->UpdateScheduleDialog(Prev.Schedule, ScheduleSituation::ScheduleEnd);
			}

			if (!AcScheduleDialog->IsUpdate() && IsPartOfScheduleEnd)
			{
				FirstScheduleUpdateCheck = false;
			}
		}
	}
}

void SchedulePlayer::PlayOneDaySchedule()
{
	AcScheduleAnimationPlayer->On();
	AcSchedulePlayerGuage->On();
	AcScheduleMessageBox->On();
	AcScheduleMessageBox->SetDayCount(++DayCount);
	AcScheduleMessageBox->SetScheduleString(Save.begin()->Schedule);
	AcSchedulePlayerGuage->SetSchedule(Save.begin()->Schedule);
	switch (Save.begin()->Schedule)
	{
	case ScheduleLabel::무용:
		AcDanceClass->On();
		Olive::OlivePlayer->OliveStatus += AcDanceClass->GetStatusVariance();
		Olive::OlivePlayer->GetGold() += AcDanceClass->GetPayGold();
		break;
	case ScheduleLabel::검술:
		AcFencingClass->On();
		Olive::OlivePlayer->OliveStatus += AcFencingClass->GetStatusVariance();
		Olive::OlivePlayer->GetGold() += AcFencingClass->GetPayGold();
		break;
	case ScheduleLabel::격투술:
		AcFightingClass->On();
		Olive::OlivePlayer->OliveStatus += AcFightingClass->GetStatusVariance();
		Olive::OlivePlayer->GetGold() += AcFightingClass->GetPayGold();
		break;
	case ScheduleLabel::마법:
		AcMagicClass->On();
		Olive::OlivePlayer->OliveStatus += AcMagicClass->GetStatusVariance();
		Olive::OlivePlayer->GetGold() += AcMagicClass->GetPayGold();
		break;
	case ScheduleLabel::미술:
		AcPaintingClass->On();
		Olive::OlivePlayer->OliveStatus += AcPaintingClass->GetStatusVariance();
		Olive::OlivePlayer->GetGold() += AcPaintingClass->GetPayGold();
		break;
	case ScheduleLabel::시문학:
		AcPoetryClass->On();
		Olive::OlivePlayer->OliveStatus += AcPoetryClass->GetStatusVariance();
		Olive::OlivePlayer->GetGold() += AcPoetryClass->GetPayGold();
		break;
	case ScheduleLabel::예법:
		AcProtocolClass->On();
		Olive::OlivePlayer->OliveStatus += AcProtocolClass->GetStatusVariance();
		Olive::OlivePlayer->GetGold() += AcProtocolClass->GetPayGold();
		break;
	case ScheduleLabel::자연과학:
		AcScienceClass->On();
		Olive::OlivePlayer->OliveStatus += AcScienceClass->GetStatusVariance();
		Olive::OlivePlayer->GetGold() += AcScienceClass->GetPayGold();
		break;
	case ScheduleLabel::군사학:
		AcStrategyClass->On();
		Olive::OlivePlayer->OliveStatus += AcStrategyClass->GetStatusVariance();
		Olive::OlivePlayer->GetGold() += AcStrategyClass->GetPayGold();
		break;
	case ScheduleLabel::신학:
		AcTheologyClass->On();
		Olive::OlivePlayer->OliveStatus += AcTheologyClass->GetStatusVariance();
		Olive::OlivePlayer->GetGold() += AcTheologyClass->GetPayGold();
		break;
	default:
		break;
	}
	
	ParentLevel->GoToNextDay();
}

void SchedulePlayer::AnimationOff()
{
	DayCount = 0;
	AcScheduleMessageBox->Off();
	AcScheduleAnimationPlayer->Off();
	AcDanceClass->Off();
	AcFencingClass->Off();
	AcFightingClass->Off();
	AcMagicClass->Off();
	AcPaintingClass->Off();
	AcPoetryClass->Off();
	AcProtocolClass->Off();
	AcScienceClass->Off();
	AcStrategyClass->Off();
	AcTheologyClass->Off();

	AcSchedulePlayerGuage->Off();
}

void SchedulePlayer::AnimationPlay()
{
	AcDanceClass->PlayObj();
	AcFencingClass->PlayObj();
	AcFightingClass->PlayObj();
	AcMagicClass->PlayObj();
	AcPaintingClass->PlayObj();
	AcPoetryClass->PlayObj();
	AcProtocolClass->PlayObj();
	AcScienceClass->PlayObj();
	AcStrategyClass->PlayObj();
	AcTheologyClass->PlayObj();
}

void SchedulePlayer::AnimationStop()
{
	AcDanceClass->StopObj();
	AcFencingClass->StopObj();
	AcFightingClass->StopObj();
	AcMagicClass->StopObj();
	AcPaintingClass->StopObj();
	AcPoetryClass->StopObj();
	AcProtocolClass->StopObj();
	AcScienceClass->StopObj();
	AcStrategyClass->StopObj();
	AcTheologyClass->StopObj();
}

void SchedulePlayer::PayDiet()
{
	Diet Value = Olive::OlivePlayer->GetOliveDiet();
	switch (Value)
	{
	case Diet::Null:
		break;
	case Diet::무리하지_않는다:
		Olive::OlivePlayer->GetGold() -= 30;
		break;
	case Diet::어쨌든_튼튼하게:
		Olive::OlivePlayer->GetGold() -= 80;
		break;
	case Diet::얌전한_아이로:
		Olive::OlivePlayer->GetGold() -= 10;
		break;
	case Diet::다이어트_시킨다:
		Olive::OlivePlayer->GetGold() -= 5;
		break;
	default:
		break;
	}
	
}

