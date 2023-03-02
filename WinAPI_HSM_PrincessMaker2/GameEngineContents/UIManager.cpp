#include "UIManager.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "RaisingSimLevel.h"
#include "Olive.h"

#include "MainMenu.h"
#include "CubeDialog.h"

RaisingSimLevel* UIManager::ParentLevel = nullptr;
MainMenu* UIManager::AcMainMenu = nullptr;
CubeDialog* UIManager::AcCubeDialog = nullptr;

UIManager::UIManager()
{

}

UIManager::~UIManager()
{

}

void UIManager::Start()
{
	ParentLevel = dynamic_cast<RaisingSimLevel*>(GetLevel());
	AcMainMenu = ParentLevel->CreateActor<MainMenu>(PM2ActorOrder::Menu0);
	AcCubeDialog = ParentLevel->GetAcCubeDialog();

	AcCubeDialog->SetUpdateText("「주인님, 안녕하십니까. 집사 \n큐브 입니다.」");
}

void UIManager::Update(float _DeltaTime)
{
	SetEngineRightClick();
}

void UIManager::SetEngineRightClick()
{
	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		if (AcCubeDialog->IsUpdate())
		{
			if (AcCubeDialog->GetUpdateText() == "「주인님, 안녕하십니까. 집사 \n큐브 입니다.」")
			{
				AcCubeDialog->SetUpdateText("「아가씨는 오늘도 건강하십니\n다. 그럼 속히 아가씨의 이번 \n달 스케줄을 결정해 주십시오」");
			}
			else if (AcCubeDialog->GetUpdateText() == "「아가씨는 오늘도 건강하십니\n다. 그럼 속히 아가씨의 이번 \n달 스케줄을 결정해 주십시오」")
			{
				AcCubeDialog->Off();
				AcMainMenu->On();
			}
			else if (AcCubeDialog->GetUpdateText() == "예, 알겠습니다. 다음달부터 그\n렇게 하겠습니다")
			{
				AcCubeDialog->Off();
				AcMainMenu->On();
			}
		}
	}
}

//void UIManager::SetEngineRightClick()
//{
//	if (GameEngineInput::IsUp("EngineMouseRight"))
//	{
//		if (true/*AcStatusWindowManager->IsUpdate()*/)
//		{
//			AcMainMenu->On();
//			//AcStatusWindowManager->Off();
//		}
//		else if (AcConverstionSelectionMenu->IsUpdate())
//		{
//			AcMainMenu->On();
//			AcConverstionSelectionMenu->Off();
//		}
//		else if (AcDietSelectionMenu->IsUpdate())
//		{
//			AcMainMenu->On();
//			AcDietSelectionMenu->Off();
//			AcCubeDialog->Off();
//		}
//		else if (AcScheduleSelectionMenu->IsUpdate()) // 스케줄 종류 선택(수업, 알바, 휴식 등)의 상황에서 오른쪽마우스 클릭하는 상황
//		{
//			if (!AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcMainMenu->On();
//				AcScheduleCalendar->Off();
//				AcScheduleSelectionMenu->Off();
//				AcCubeDialog->Off();
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcScheduleCalendar->CancelSchedule();
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 1 번째 )");
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcScheduleCalendar->CancelSchedule();
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 2 번째 )");
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcScheduleCalendar->CancelSchedule();
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 3 번째 )");
//			}
//		}
//		else if (AcClassSelectWindow->IsUpdate()) // 과목 선택하는 창에서 오른쪽 마우스 클릭하는 상황
//		{
//			AcClassSelectWindow->Off();
//			AcScheduleCalendar->On();
//			AcScheduleSelectionMenu->On();
//			if (!AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 1 번째 )");
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 2 번째 )");
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 3 번째 )");
//			}
//		}
//		else if (AcSchedulingConfirmSelectionMenu->IsUpdate())
//		{
//			AcSchedulingConfirmSelectionMenu->Off();
//			AcScheduleSelectionMenu->On();
//			if (!AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 1 번째 )");
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 2 번째 )");
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 3 번째 )");
//			}
//		}
//		else if (AcScheduleFinalConfirm->IsUpdate())
//		{
//			AcScheduleFinalConfirm->Off();
//			AcScheduleCalendar->Reset();
//			AcScheduleSelectionMenu->On();
//			AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 1 번째 )");
//		}
//		else if (AcPersonalInformationWindow->IsUpdate())
//		{
//			AcMainMenu->On();
//			AcPersonalInformationWindow->Off();
//			AcHelthInformationWindow->Off();
//			AcPhysicalStatusWindow->Off();
//		}
//		else if (AcCubeDialog->GetUpdateText() == "「주인님, 안녕하십니까. 집사 \n큐브 입니다.」")
//		{
//			AcCubeDialog->SetUpdateText("「아가씨는 오늘도 건강하십니\n다. 그럼 속히 아가씨의 이번 \n달 스케줄을 결정해 주십시오」");
//		}
//		else if (AcCubeDialog->GetUpdateText() == "「아가씨는 오늘도 건강하십니\n다. 그럼 속히 아가씨의 이번 \n달 스케줄을 결정해 주십시오」")
//		{
//			AcMainMenu->On();
//			AcCubeDialog->Off();
//		}
//		else if (AcCubeDialog->GetUpdateText() == "예, 알겠습니다. 다음달부터 그\n렇게 하겠습니다")
//		{
//			AcMainMenu->On();	
//			AcSelectDialog->Off();
//			AcCubeDialog->Off();
//		}
//		else if (AcCubeDialog->GetUpdateText() == "스케줄을 실행합니다" && AcCubeDialog->IsUpdate())
//		{
//			AcCubeDialog->Off();
//			AcScheduleCalendar->Off();
//			AcFoodCostDialog->On();
//		}
//		else if (AcFoodCostDialog->IsUpdate())
//		{
//			AcFoodCostDialog->Off();
//			//여기서 식비를 깎아야함
//			switch (Olive::OlivePlayer->GetOliveDiet())
//			{
//			case Diet::무리하지_않는다:
//				Olive::OlivePlayer->GetGold() -= 30;
//				break;
//			case Diet::어쨌든_튼튼하게:
//				Olive::OlivePlayer->GetGold() -= 80;
//				break;
//			case Diet::얌전한_아이로:
//				Olive::OlivePlayer->GetGold() -= 10;
//				break;
//			case Diet::다이어트_시킨다:
//				Olive::OlivePlayer->GetGold() -= 5;
//				break;
//			default:
//				break;
//			}
//			AcScheduleDialog->UpdateScheduleDialog(ScheduleLabel::미술, "왕궁화가 필킨스\n「내가 왕궁화가인 필킨스다.\n그림을 통해서 예술의 심오함을\n 가르쳐 주도록 하지.」");
//		}
//		else if (AcScheduleDialog->GetUpdateText() == "왕궁화가 필킨스\n「내가 왕궁화가인 필킨스다.\n그림을 통해서 예술의 심오함을\n 가르쳐 주도록 하지.」")
//		{
//			AcScheduleDialog->Off();
//			AcScheduleCalendar->Off();
//			AcSchedulePlayer->On();
//		}
//	}
//}

//void UIManager::ClickMainMenu_00(Button* _Button)
//{
//	AcMainMenu->Off();
//	AcStatusWindowManager->On();
//}

//void UIManager::ClickMainMenu_01(Button* _Button)
//{
//	AcMainMenu->Off();
//	AcConverstionSelectionMenu->On();
//}

//void UIManager::ClickMainMenu_02(Button* _Button)
//{
//	AcMainMenu->Off();
//	AcDietSelectionMenu->On();
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「주인님, 아가씨의 건강관리는\n어떤 방침으로 하시겠습니까?」");
//}
//
//void UIManager::ClickMainMenu_02_0(Button* _Button)
//{
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n30G 들어갑니다. 무리 없는 식\n생활을 보낼 수 있습니다」");
//	AcDietFinalConfirmSelectionMenu->On();
//	AcSelectDialog->On();
//	AcSelectDialog->SetUpdateText("무리하지 않는다");
//	AcDietSelectionMenu->Off();
//	DietSetConfirm = Diet::무리하지_않는다;
//}
//
//void UIManager::ClickMainMenu_02_1(Button* _Button)
//{
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n80G 들어갑니다. 체력이 올라가\n겠죠」");
//	AcDietFinalConfirmSelectionMenu->On();
//	AcSelectDialog->On();
//	AcSelectDialog->SetUpdateText("어쨌든 튼튼하게");
//	AcDietSelectionMenu->Off();
//	DietSetConfirm = Diet::어쨌든_튼튼하게;
//}
//
//void UIManager::ClickMainMenu_02_2(Button* _Button)
//{
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n10G 들어갑니다. 약간 건강에 부\n담이 갈지도 모릅니다」");
//	AcDietFinalConfirmSelectionMenu->On();
//	AcSelectDialog->On();
//	AcSelectDialog->SetUpdateText("얌전한 아이로");
//	AcDietSelectionMenu->Off();
//	DietSetConfirm = Diet::얌전한_아이로;
//}
//
//void UIManager::ClickMainMenu_02_3(Button* _Button)
//{
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n5G 밖에 들지 않습니다. 아가씨의\n몸무게를 줄이고 싶다면, 이 방\n침으로 가시죠. 단, 체력을 상\n당히 소모하므로 주의하시기 바\n랍니다」");
//	AcDietFinalConfirmSelectionMenu->On();
//	AcSelectDialog->On();
//	AcSelectDialog->SetUpdateText("다이어트 시킨다");
//	AcDietSelectionMenu->Off();
//	DietSetConfirm = Diet::다이어트_시킨다;
//}
//
//void UIManager::ClickMainMenu_02_0_0(Button* _Button)
//{
//	switch (DietSetConfirm)
//	{
//	case Diet::무리하지_않는다:
//		Olive::OlivePlayer->SetOliveDiet(Diet::무리하지_않는다);
//		break;
//	case Diet::어쨌든_튼튼하게:
//		Olive::OlivePlayer->SetOliveDiet(Diet::어쨌든_튼튼하게);
//		break;
//	case Diet::얌전한_아이로:
//		Olive::OlivePlayer->SetOliveDiet(Diet::얌전한_아이로);
//		break;
//	case Diet::다이어트_시킨다:
//		Olive::OlivePlayer->SetOliveDiet(Diet::다이어트_시킨다);
//		break;
//	default:
//		break;
//	}
//	AcDietFinalConfirmSelectionMenu->Off();
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Proud, "예, 알겠습니다. 다음달부터 그\n렇게 하겠습니다");
//	
//	//AcMainMenu->On();
//	//AcCubeDialog->Off();
//}
//
//void UIManager::ClickMainMenu_02_0_1(Button* _Button)
//{
//	AcMainMenu->On();
//	AcDietFinalConfirmSelectionMenu->Off();
//	AcSelectDialog->Off();
//	AcCubeDialog->Off();
//}

//void UIManager::ClickMainMenu_03(Button* _Button)
//{
//	AcMainMenu->Off();
//	AcPersonalInformationWindow->On();
//	AcHelthInformationWindow->On();
//	AcPhysicalStatusWindow->On();
//}

//void UIManager::ClickMainMenu_S(Button* _Button)
//{
//	AcMainMenu->Off();
//	AcScheduleCalendar->On();
//	AcScheduleSelectionMenu->On();
//	if (!AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 1 번째 )");
//	}
//	else if (AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 2 번째 )");
//	}
//	else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 3 번째 )");
//	}
//}

//void UIManager::ClickMainMenu_S_0(Button* _Button)
//{
//	AcScheduleSelectionMenu->Off();
//	AcClassSelectWindow->On();
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "딸에게 무엇을 가르치시겠습니까?");
//}

//void UIManager::ClickMainMenu_S_0_0(Button* _Button)
//{
//	AcClassSelectWindow->Off();
//	ScheduleSetConfirm = ScheduleLabel::미술;
//	AcSchedulingConfirmSelectionMenu->On();
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "미술. \n그림을 그려 예술적인 센스를\n갈고 닦는다");
//}

//void UIManager::ClickMainMenu_S_0_0_0(Button* _Button) // 스케줄에 편성한다
//{
//	AcScheduleCalendar->ScheduleSetting(ScheduleSetConfirm);
//	if (AcScheduleCalendar->ScheduleSetEnd)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「예, 스케줄에 편성하겠습니다」\n이번달은 이 스케줄로\n좋습니까?");
//		AcScheduleFinalConfirm->On();
//		AcSchedulingConfirmSelectionMenu->Off();
//	}
//	else if (AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 2 번째 )");
//		AcSchedulingConfirmSelectionMenu->Off();
//		AcScheduleSelectionMenu->On();
//	}
//	else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 3 번째 )");
//		AcSchedulingConfirmSelectionMenu->Off();
//		AcScheduleSelectionMenu->On();
//	}
//
//}

//void UIManager::ClickMainMenu_S_0_0_1(Button* _Button)
//{
//	AcSchedulingConfirmSelectionMenu->Off();
//	AcScheduleSelectionMenu->On();
//	if (!AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 1 번째 )");
//	}
//	else if (AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 2 번째 )");
//	}
//	else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 3 번째 )");
//	}
//}

//void UIManager::ClickMainMenu_S_0_0_0_0(Button* _Button)
//{
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "스케줄을 실행합니다");
//	AcScheduleFinalConfirm->Off();
//}

//void UIManager::ClickMainMenu_S_0_0_0_1(Button* _Button)
//{
//	AcScheduleFinalConfirm->Off();
//	AcScheduleCalendar->Reset();
//	AcScheduleSelectionMenu->On();
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 1 번째 )");
//}

//bool UIManager::IsAnyMenuUpdate()
//{
//	for (auto i : AllMenu)
//	{
//		if (i->IsUpdate())
//		{
//			return true;
//		}
//	}
//	return false;
//}
