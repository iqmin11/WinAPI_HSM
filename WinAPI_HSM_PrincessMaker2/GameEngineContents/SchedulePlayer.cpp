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
	Off();
}

void SchedulePlayer::Update(float _DeltaTime)
{
	if (!FirstUpdateCheck) // 한달의 스케줄 시작
	{
		FirstUpdateCheck = true;
		PayDiet();
		AcFoodCostDialog->On();
	}
	else if(!AcFoodCostDialog->IsUpdate())
	{
		if (!FirstScheduleUpdateCheck)// 한주의 스케줄 시작
		{
			FirstScheduleUpdateCheck = true;
			AcScheduleDialog->UpdateScheduleDialog(Save.begin()->Schedule, ScheduleSituation::ScheduleStart);
		}
		else if (!AcScheduleDialog->IsUpdate())
		{
			int Prev = Save.begin()->Order;

			Time += _DeltaTime;
			if (Time >= 1) // 스케줄이 진행되는 부분
			{
				Time = 0;
				AcSchedulePlayerGuage->SetSchedule(Save.begin()->Schedule);
				PlayOneDaySchedule();
				Save.pop_front();
			}

			if (Save.size() == 0) // 모든 스케줄이 끝나는 부분
			{
				FirstUpdateCheck = false;
				FirstScheduleUpdateCheck = false;
				MainMenu::GetAcMainMenu()->On();
				AcScheduleCalendar->Reset();
				AnimationOff();
				Off();
				return;
			}

			int Next = Save.begin()->Order;

			if (Prev != Next) // 한주의 스케줄이 끝나는 부분
			{
				AnimationOff();
				FirstScheduleUpdateCheck = false;
			}
		}
	}
}

void SchedulePlayer::PlayOneDaySchedule()
{
	AcScheduleAnimationPlayer->On(); // 애니메이션 창을 띄운다
	AcSchedulePlayerGuage->On();
	switch (Save.begin()->Schedule)
	{
	case ScheduleLabel::무용:
		AcDanceClass->On(); // 애니메이션을 띄운다
		Olive::OlivePlayer->OliveStatus += AcDanceClass->GetStatusVariance(); // 능력치를 올린다
		break;
	case ScheduleLabel::검술:
		AcFencingClass->On(); // 애니메이션을 띄운다
		Olive::OlivePlayer->OliveStatus += AcFencingClass->GetStatusVariance(); // 능력치를 올린다
		break;
	case ScheduleLabel::격투술:
		AcFightingClass->On(); // 애니메이션을 띄운다
		Olive::OlivePlayer->OliveStatus += AcFightingClass->GetStatusVariance(); // 능력치를 올린다
		break;
	case ScheduleLabel::마법:
		AcMagicClass->On(); // 애니메이션을 띄운다
		Olive::OlivePlayer->OliveStatus += AcMagicClass->GetStatusVariance(); // 능력치를 올린다
		break;
	case ScheduleLabel::미술:
		AcPaintingClass->On(); // 애니메이션을 띄운다
		Olive::OlivePlayer->OliveStatus += AcPaintingClass->GetStatusVariance(); // 능력치를 올린다
		break;
	case ScheduleLabel::시문학:
		AcPoetryClass->On(); // 애니메이션을 띄운다
		Olive::OlivePlayer->OliveStatus += AcPoetryClass->GetStatusVariance(); // 능력치를 올린다
		break;
	case ScheduleLabel::예법:
		AcProtocolClass->On(); // 애니메이션을 띄운다
		Olive::OlivePlayer->OliveStatus += AcProtocolClass->GetStatusVariance(); // 능력치를 올린다
		break;
	case ScheduleLabel::자연과학:
		AcScienceClass->On(); // 애니메이션을 띄운다
		Olive::OlivePlayer->OliveStatus += AcScienceClass->GetStatusVariance(); // 능력치를 올린다
		break;
	case ScheduleLabel::군사학:
		AcStrategyClass->On(); // 애니메이션을 띄운다
		Olive::OlivePlayer->OliveStatus += AcStrategyClass->GetStatusVariance(); // 능력치를 올린다
		break;
	case ScheduleLabel::신학:
		AcTheologyClass->On(); // 애니메이션을 띄운다
		Olive::OlivePlayer->OliveStatus += AcTheologyClass->GetStatusVariance(); // 능력치를 올린다
		break;
	default:
		break;
	}
	
	ParentLevel->GoToNextDay(); // 다음날로 간다
}

void SchedulePlayer::AnimationOff()
{
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

