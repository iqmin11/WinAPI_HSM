#include "SchedulePlayer.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "ScheduleCalendar.h"
#include "RaisingSimLevel.h"
#include "ScheduleAnimationPlayer.h"
#include "Olive.h"
#include "FoodCostDialog.h"
#include "ScheduleDialog.h"
#include "MainMenu.h"

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
	Off();
}

void SchedulePlayer::Update(float _DeltaTime)
{
	if (!FirstUpdateCheck)
	{
		FirstUpdateCheck = true;
		AcFoodCostDialog->On();
	}
	else if(!AcFoodCostDialog->IsUpdate() && Save.size() != 0 && !AcScheduleDialog->IsUpdate())
	{
		if (!FirstScheduleUpdateCheck)
		{
			FirstScheduleUpdateCheck = true;
			AcScheduleDialog->UpdateScheduleDialog(Save.begin()->Schedule, ScheduleSituation::ScheduleStart);
		}
		else if (!AcScheduleDialog->IsUpdate())
		{
			int Prev = Save.begin()->Order;

			Time += _DeltaTime;
			if (Time >= 1)
			{
				Time = 0;
				PlayOneDaySchedule();
				Save.pop_front();
			}

			if (Save.size() == 0) // ���⼭ ����
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

			if (Prev != Next)
			{
				AnimationOff();
				FirstScheduleUpdateCheck = false;
			}
		}
	}
}

void SchedulePlayer::PlayOneDaySchedule()
{
	AcScheduleAnimationPlayer->On(); // �ִϸ��̼� â�� ����
	switch (Save.begin()->Schedule)
	{
	case ScheduleLabel::����:
		AcDanceClass->On(); // �ִϸ��̼��� ����
		Olive::OlivePlayer->OliveStatus += AcDanceClass->GetStatusVariance(); // �ɷ�ġ�� �ø���
		break;
	case ScheduleLabel::�˼�:
		AcFencingClass->On(); // �ִϸ��̼��� ����
		Olive::OlivePlayer->OliveStatus += AcFencingClass->GetStatusVariance(); // �ɷ�ġ�� �ø���
		break;
	case ScheduleLabel::������:
		AcFightingClass->On(); // �ִϸ��̼��� ����
		Olive::OlivePlayer->OliveStatus += AcFightingClass->GetStatusVariance(); // �ɷ�ġ�� �ø���
		break;
	case ScheduleLabel::����:
		AcMagicClass->On(); // �ִϸ��̼��� ����
		Olive::OlivePlayer->OliveStatus += AcMagicClass->GetStatusVariance(); // �ɷ�ġ�� �ø���
		break;
	case ScheduleLabel::�̼�:
		AcPaintingClass->On(); // �ִϸ��̼��� ����
		Olive::OlivePlayer->OliveStatus += AcPaintingClass->GetStatusVariance(); // �ɷ�ġ�� �ø���
		break;
	case ScheduleLabel::�ù���:
		AcPoetryClass->On(); // �ִϸ��̼��� ����
		Olive::OlivePlayer->OliveStatus += AcPoetryClass->GetStatusVariance(); // �ɷ�ġ�� �ø���
		break;
	case ScheduleLabel::����:
		AcProtocolClass->On(); // �ִϸ��̼��� ����
		Olive::OlivePlayer->OliveStatus += AcProtocolClass->GetStatusVariance(); // �ɷ�ġ�� �ø���
		break;
	case ScheduleLabel::�ڿ�����:
		AcScienceClass->On(); // �ִϸ��̼��� ����
		Olive::OlivePlayer->OliveStatus += AcScienceClass->GetStatusVariance(); // �ɷ�ġ�� �ø���
		break;
	case ScheduleLabel::������:
		AcStrategyClass->On(); // �ִϸ��̼��� ����
		Olive::OlivePlayer->OliveStatus += AcStrategyClass->GetStatusVariance(); // �ɷ�ġ�� �ø���
		break;
	case ScheduleLabel::����:
		AcTheologyClass->On(); // �ִϸ��̼��� ����
		Olive::OlivePlayer->OliveStatus += AcTheologyClass->GetStatusVariance(); // �ɷ�ġ�� �ø���
		break;
	default:
		break;
	}
	
	ParentLevel->GoToNextDay(); // �������� ����
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
}

