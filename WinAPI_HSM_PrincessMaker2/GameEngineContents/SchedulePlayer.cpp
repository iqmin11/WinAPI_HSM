#include "SchedulePlayer.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include "ScheduleCalendar.h"
#include "RaisingSimLevel.h"
#include "ScheduleAnimationPlayer.h"
#include "PaintingClass.h"
#include "Olive.h"
#include "FoodCostDialog.h"
#include "ScheduleDialog.h"

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

void SchedulePlayer::Off()
{
	GameEngineObject::Off();
	AcScheduleAnimationPlayer->Off();
	AcFoodCostDialog->Off();
}

void SchedulePlayer::Start()
{
	ParentLevel = dynamic_cast<RaisingSimLevel*>(GetLevel());
	AcScheduleAnimationPlayer = ParentLevel->CreateActor<ScheduleAnimationPlayer>(PM2ActorOrder::Menu2);
	AcScheduleCalendar = ScheduleCalendar::GetAcScheduleCalendar();
	AcPaintingClass = ParentLevel->AcPaintingClass;
	AcFoodCostDialog = ParentLevel->CreateActor<FoodCostDialog>(PM2ActorOrder::Menu2);
	AcScheduleDialog = ParentLevel->GetAcScheduleDialog();
	Off();
}

void SchedulePlayer::Update(float _DeltaTime)
{
	//if (BackRenderer->IsUpdate())
	//{

	//}

	//if (true == BackRenderer->IsAnimationEnd())
	//{
	//	// �̰� ����ϰ� ������ �Ű�.
	//	if (0 != AnimationName.size())
	//	{
	//		BackRenderer->ChangeAnimation(AnimationName.front());
	//		AnimationName.pop_front();
	//	}

	//	// �������� �ִ�. ������ �Ŷ��
	//	std::list<std::string>::iterator Start = AnimationName.begin();
	//	std::list<std::string>::iterator Next = ++AnimationName.begin();

	//	std::string CurName = *Start;
	//	std::string NextName = *Next;

	//	if (CurName != NextName)
	//	{
	//		BackRenderer->Off();
	//	}
	//}
	

	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		if (AcFoodCostDialog->IsUpdate())
		{
			AcFoodCostDialog->Off();
		}
	}

	if (FirstUpdateCheck == false)
	{
		FirstUpdateCheck = true;
		ScheduleEnd = false;
		SchedulePlayerStart();
	}
	else if(!AcFoodCostDialog->IsUpdate() && ScheduleEnd == false)
	{
		SchedulePlayerUpdate(_DeltaTime);
	}
	//else
	//{
	//	FirstUpdateCheck = false;
	//	ScheduleEnd = true;
	//	Off();
	//}
}

void SchedulePlayer::PlayOneDaySchedule()
{
	AcScheduleAnimationPlayer->On();
	AcPaintingClass->On();
	Olive::OlivePlayer->OliveStatus += AcPaintingClass->GetStatusVariance();
	ParentLevel->GoToNextDay();
}

void SchedulePlayer::SetScheduleDialog(ScheduleLabel _Mug)
{
	switch (_Mug)
	{
	case ScheduleLabel::Null:
		break;
	case ScheduleLabel::�ڿ�����:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "���ݼ��� ��ũ����\n �������� ��� ���� ���а� ��\n���� ������ �� ����. �ź�����\n�� �ΰ��� ������ ���� ��\n��. �����̳� ������ ������ ��\n�� ������ �ʾ�.��");
		break;
	case ScheduleLabel::����:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "�ý��� ����\n ��������, ���� ��ȸ�� ���ŵ�\n�� �����Դϴ�.��");
		break;
	case ScheduleLabel::������:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "ũ��� �屺\n ������. ���� �ٷ� �ձ��� ����\n��, ������屺�� �̶� �Ҹ���� \n���� ���ϳ׽� ���̰�ũ��Ŵ�\n.��");
		break;
	case ScheduleLabel::�˼�:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "�˻� ������\n ������, ���� �� ������ ���.\n���� ��, �̸��� ����Ʈ��. ��\n�����̶� �ҷ���. �� ������ ��\n�� ��ĥ���� �������̶� ������\n�ɰŴ�.��");
		break;
	case ScheduleLabel::������:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "������ Į ����\n ���ο��� ���� ���ΰ� �ƴϴ�.\n���⿡ �������� �ʴ� �������� \n���Ǵ� ������ �Ѱ���� ���ϴ�\nü���� ���濡 ����.��");
		break;
	case ScheduleLabel::����:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "������ ��Ʈ��\n ���ȳ��ϼ���. ���� ���������� �����Դϴ�. �����а� �Բ� �ǿ븶���� ��쵵�� ���ҡ�");
		break;
	case ScheduleLabel::�ù���:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "��� ��Ʈ�罺\n ���ô� ����� ������ ǳ��Ӱ�\n���ݴϴ�. �� ������� �ô� ��\n���鿡�� ������ ����, â����\n�̷��� ����� ����. ��, �Բ�\n�����սô�. ������ �յ�����");
		break;
	case ScheduleLabel::����:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "��� ��Ʈ�罺\n ���� �Դ�. �� �����̴� ���κ�\n�� ���� �������� ���߿�����\n���ǹ����� ����ġ�� ���������");
		break;
	case ScheduleLabel::����:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "���� ���� Ʈ��\n ���米�� ���߸� ��ǥ�ϴ� ����\n���� �־�, ���� �Ƿ��� Ŀ�ٶ� \n���Ⱑ �˴ϴ�. ������ ������\n��. �ڽ��� ���ؼ���");
		break;
	case ScheduleLabel::�̼�:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "�ձ�ȭ�� ��Ų��\n ������ �ձ�ȭ���� ��Ų����. \n�׸��� ���ؼ� ������ �ɿ����� \n������ �ֵ��� ����.��");
		break;
	default:
		break;
	}
	AcScheduleDialog->Off();
}

void SchedulePlayer::SetFirstScheduleDialog()
{
	ScheduleLabel Value = ScheduleLabel::Null;
	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 7; x++)
		{
			if (Save[y][x].DateSave == AcScheduleCalendar->GetFirstScheduleEndDate())
			{
				Value = Save[y][x].ScheduleSave;
			}
		}
	}
	SetScheduleDialog(Value);
}

void SchedulePlayer::SetSecondScheduleDialog()
{
	ScheduleLabel Value = ScheduleLabel::Null;
	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 7; x++)
		{
			if (Save[y][x].DateSave == AcScheduleCalendar->GetSecondScheduleEndDate())
			{
				Value = Save[y][x].ScheduleSave;
			}
		}
	}
	SetScheduleDialog(Value);
}

void SchedulePlayer::SetThirdScheduleDialog()
{
	ScheduleLabel Value = ScheduleLabel::Null;
	for (size_t y = 0; y < 6; y++)
	{
		for (size_t x = 0; x < 7; x++)
		{
			if (Save[y][x].DateSave == AcScheduleCalendar->GetSecondScheduleEndDate())
			{
				Value = Save[y][x].ScheduleSave;
			}
		}
	}
	SetScheduleDialog(Value);
}


void SchedulePlayer::SchedulePlayerStart()
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
	AcFoodCostDialog->On();
	SetFirstScheduleDialog();
}

void SchedulePlayer::SchedulePlayerUpdate(float _DeltaTime)
{
	if (AcScheduleCalendar->FirstScheduleSet)
	{
		//���⵵ ��ŸƮ ������Ʈ ���� ������ ������ �������ҰͰ���.
		//PlayFirstOrderSchedule(_DeltaTime);
	}
	//else if (AcScheduleCalendar->SecondScheduleSet)
	//{
	//	PlaySecondOrderSchedule(_DeltaTime);
	//}
	//else if (AcScheduleCalendar->ThirdScheduleSet)
	//{
	//	PlayThirdOrderSchedule(_DeltaTime);
	//}
}
