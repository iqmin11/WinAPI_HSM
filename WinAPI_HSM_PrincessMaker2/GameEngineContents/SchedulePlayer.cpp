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
	//	// 이건 평범하게 돌리는 거고.
	//	if (0 != AnimationName.size())
	//	{
	//		BackRenderer->ChangeAnimation(AnimationName.front());
	//		AnimationName.pop_front();
	//	}

	//	// 터질수도 있다. 마지막 거라면
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
	case ScheduleLabel::자연과학:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "연금술사 버크레오\n 「세상의 모든 일은 수학과 물\n리로 설명할 수 있지. 신비주의\n는 인간의 무지가 만들어낸 산\n물. 기적이나 마법도 과학적 현\n상에 지나지 않아.」");
		break;
	case ScheduleLabel::신학:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "시스터 리이\n 「여러분, 저는 교회의 여신도\n인 리이입니다.」");
		break;
	case ScheduleLabel::군사학:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "크루거 장군\n 「제군. 내가 바로 왕국의 상장\n군, 『백승장군』 이라 불리우는 \n엘윈 요하네스 오이겐크루거다\n.」");
		break;
	case ScheduleLabel::검술:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "검사 레프톨\n 「여어, 내가 이 도장의 사범.\n성은 올, 이름은 레프트다. 레\n프톨이라 불러줘. 내 지도는 조\n금 거칠지만 실전형이라 도움이\n될거다.」");
		break;
	case ScheduleLabel::격투술:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "격투가 칼 폭스\n 「싸움은 검이 전부가 아니다.\n무기에 의존하지 않는 격투술의 \n극의는 공격을 한계까지 피하는\n체술의 습득에 있지.」");
		break;
	case ScheduleLabel::마법:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "마법사 패트남\n 「안녕하세요. 제가 마법교실의 선생입니다. 여러분과 함께 실용마법을 배우도록 하죠」");
		break;
	case ScheduleLabel::시문학:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "노사 바트사스\n 「시는 사람의 마음을 풍요롭게\n해줍니다. 옛 사람들의 시는 우\n리들에게 남겨진 보물, 창작은\n미래에 남기는 유산. 자, 함께\n공부합시다. 문학의 왕도를」");
		break;
	case ScheduleLabel::예법:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "노사 바트사스\n 「잘 왔다. 이 늙은이는 예로부\n터 전해 내려오는 궁중예법과\n예의범절을 가르치는 사람이지」");
		break;
	case ScheduleLabel::무용:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "무용 선생 트베\n 「사교계 데뷔를 목표하는 여성\n에게 있어, 무용 실력은 커다란 \n무기가 됩니다. 열심히 익히세\n요. 자신을 위해서」");
		break;
	case ScheduleLabel::미술:
		AcScheduleDialog->UpdateScheduleDialog(_Mug, "왕궁화가 필킨스\n 「내가 왕궁화가인 필킨스다. \n그림을 통해서 예술의 심오함을 \n가르쳐 주도록 하지.」");
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
		//여기도 스타트 업데이트 엔드 세개로 나눠서 만들어야할것같음.
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
