#include "UIManager.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "RaisingSimLevel.h"
#include "Olive.h"

#include "MainMenu.h"
#include "StatusWindowManager.h"

#include "ConverstionSelectionMenu.h"
#include "DietSelectionMenu.h"
#include "DietFinalConfirmSelectionMenu.h"

#include "PersonalInformationWindow.h"
#include "HelthInformationWindow.h"
#include "PhysicalStatusWindow.h"

#include "ScheduleCalendar.h"
#include "ScheduleSelectionMenu.h"
#include "ClassSelectWindow.h"
#include "ScheduleAnimationPlayer.h"

#include "CubeDialog.h"

MainMenu* UIManager::AcMainMenu = nullptr;
StatusWindowManager* UIManager::AcStatusWindowManager = nullptr;

ConverstionSelectionMenu* UIManager::AcConverstionSelectionMenu = nullptr;

Diet UIManager::DietSetConfirm = Diet::Null;
DietSelectionMenu* UIManager::AcDietSelectionMenu = nullptr;
DietFinalConfirmSelectionMenu* UIManager::AcDietFinalConfirmSelectionMenu = nullptr;

PersonalInformationWindow* UIManager::AcPersonalInformationWindow = nullptr;
HelthInformationWindow* UIManager::AcHelthInformationWindow = nullptr;
PhysicalStatusWindow* UIManager::AcPhysicalStatusWindow = nullptr;

ScheduleCalendar* UIManager::AcScheduleCalendar = nullptr;
ScheduleSelectionMenu* UIManager::AcScheduleSelectionMenu = nullptr;
ClassSelectWindow* UIManager::AcClassSelectWindow = nullptr;
ScheduleAnimationPlayer* UIManager::AcScheduleAnimationPlayer = nullptr;

CubeDialog* UIManager::AcCubeDialog = nullptr;

UIManager::UIManager()
{

}

UIManager::~UIManager()
{

}

void UIManager::Start()
{
	GameEngineLevel* Level = GetLevel();
	AcMainMenu = Level->CreateActor<MainMenu>(PM2ActorOrder::Menu0);

	AcStatusWindowManager = Level->CreateActor<StatusWindowManager>(PM2ActorOrder::Menu1);
	
	AcConverstionSelectionMenu = Level->CreateActor<ConverstionSelectionMenu>(PM2ActorOrder::Menu1);
	
	AcDietSelectionMenu = Level->CreateActor<DietSelectionMenu>(PM2ActorOrder::Menu1);
	AcDietFinalConfirmSelectionMenu = Level->CreateActor<DietFinalConfirmSelectionMenu>(PM2ActorOrder::Menu2);

	AcPersonalInformationWindow = Level->CreateActor<PersonalInformationWindow>(PM2ActorOrder::Menu1);
	AcHelthInformationWindow = Level->CreateActor<HelthInformationWindow>(PM2ActorOrder::Menu1);
	AcPhysicalStatusWindow = Level->CreateActor<PhysicalStatusWindow>(PM2ActorOrder::Menu1);
	
	AcScheduleCalendar = Level->CreateActor<ScheduleCalendar>(PM2ActorOrder::Menu1);
	AcScheduleSelectionMenu = Level->CreateActor<ScheduleSelectionMenu>(PM2ActorOrder::Menu1);
	AcClassSelectWindow = Level->CreateActor<ClassSelectWindow>(PM2ActorOrder::Menu2);
	AcScheduleAnimationPlayer = Level->CreateActor<ScheduleAnimationPlayer>(PM2ActorOrder::Menu2);

	AcCubeDialog = dynamic_cast<RaisingSimLevel*>(Level)->GetAcCubeDialog();

	SetButtonAndKey();
}

void UIManager::Update(float _DeltaTime)
{
	SetEngineRightClick();
}

void UIManager::SetButtonAndKey()
{
	AcMainMenu->GetMainMenuButton()[0][0]->SetClickCallBack(ClickMainMenu_00);
	AcMainMenu->GetMainMenuButton()[0][1]->SetClickCallBack(ClickMainMenu_01);
	AcMainMenu->GetMainMenuButton()[0][2]->SetClickCallBack(ClickMainMenu_02);
	AcMainMenu->GetMainMenuButton()[0][3]->SetClickCallBack(ClickMainMenu_03);
	//AcMainMenu->GetMainMenuButton()[1][0]->SetClickCallBack(ClickMainMenu_10);
	//AcMainMenu->GetMainMenuButton()[1][1]->SetClickCallBack(ClickMainMenu_11);
	//AcMainMenu->GetMainMenuButton()[1][2]->SetClickCallBack(ClickMainMenu_12);
	//AcMainMenu->GetMainMenuButton()[1][3]->SetClickCallBack(ClickMainMenu_13);
	AcMainMenu->GetScheduleButton()->SetClickCallBack(ClickMainMenu_S);

	//AcConverstionSelectionMenu->GetSelectButtons()[0]->SetClickCallBack(ClickMainMenu_01_0);
	//AcConverstionSelectionMenu->GetSelectButtons()[1]->SetClickCallBack(ClickMainMenu_01_1);
	//AcConverstionSelectionMenu->GetSelectButtons()[2]->SetClickCallBack(ClickMainMenu_01_2);

	AcDietSelectionMenu->GetSelectButtons()[0]->SetClickCallBack(ClickMainMenu_02_0);
	AcDietSelectionMenu->GetSelectButtons()[1]->SetClickCallBack(ClickMainMenu_02_1);
	AcDietSelectionMenu->GetSelectButtons()[2]->SetClickCallBack(ClickMainMenu_02_2);
	AcDietSelectionMenu->GetSelectButtons()[3]->SetClickCallBack(ClickMainMenu_02_3);
	
	AcDietFinalConfirmSelectionMenu->GetSelectButtons()[0]->SetClickCallBack(ClickMainMenu_02_0_0);
	AcDietFinalConfirmSelectionMenu->GetSelectButtons()[1]->SetClickCallBack(ClickMainMenu_02_0_1);

	AcScheduleSelectionMenu->GetSelectButtons()[0]->SetClickCallBack(ClickMainMenu_S_0);
	//AcScheduleSelectionMenu->GetSelectButtons()[1]->SetClickCallBack(ClickMainMenu_S_1);
	//AcScheduleSelectionMenu->GetSelectButtons()[2]->SetClickCallBack(ClickMainMenu_S_2);
	//AcScheduleSelectionMenu->GetSelectButtons()[3]->SetClickCallBack(ClickMainMenu_S_3);
}

void UIManager::SetEngineRightClick()
{
	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		if (AcStatusWindowManager->IsUpdate())
		{
			AcMainMenu->On();
			AcStatusWindowManager->Off();
		}
		else if (AcConverstionSelectionMenu->IsUpdate())
		{
			AcMainMenu->On();
			AcConverstionSelectionMenu->Off();
		}
		else if (AcDietSelectionMenu->IsUpdate())
		{
			AcMainMenu->On();
			AcDietSelectionMenu->Off();
			AcCubeDialog->Off();
		}
		else if (AcScheduleSelectionMenu->IsUpdate())
		{
			AcMainMenu->On();
			AcScheduleCalendar->Off();
			AcScheduleSelectionMenu->Off();
			AcCubeDialog->Off();
		}
		else if (AcClassSelectWindow->IsUpdate())
		{
			AcClassSelectWindow->Off();
			AcScheduleCalendar->On();
			AcScheduleSelectionMenu->On();
			//AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 1 번째 )");
		}
		else if (AcPersonalInformationWindow->IsUpdate())
		{
			AcMainMenu->On();
			AcPersonalInformationWindow->Off();
			AcHelthInformationWindow->Off();
			AcPhysicalStatusWindow->Off();
		}
	}
}

void UIManager::ClickMainMenu_00(Button* _Button)
{
	AcMainMenu->Off();
	AcStatusWindowManager->On();
}

void UIManager::ClickMainMenu_01(Button* _Button)
{
	AcMainMenu->Off();
	AcConverstionSelectionMenu->On();
}

void UIManager::ClickMainMenu_02(Button* _Button)
{
	AcMainMenu->Off();
	AcDietSelectionMenu->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「주인님, 아가씨의 건강관리는\n어떤 방침으로 하시겠습니까?」");
}

void UIManager::ClickMainMenu_02_0(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n30G 들어갑니다. 무리 없는 식\n생활을 보낼 수 있습니다」");
	AcDietFinalConfirmSelectionMenu->On();
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::무리하지_않는다;
}

void UIManager::ClickMainMenu_02_1(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n80G 들어갑니다. 체력이 올라가\n겠죠」");
	AcDietFinalConfirmSelectionMenu->On();
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::어쨌든_튼튼하게;
}

void UIManager::ClickMainMenu_02_2(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n10G 들어갑니다. 약간 건강에 부\n담이 갈지도 모릅니다」");
	AcDietFinalConfirmSelectionMenu->On();
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::얌전한_아이로;
}

void UIManager::ClickMainMenu_02_3(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n5G 밖에 들지 않습니다. 아가씨의\n몸무게를 줄이고 싶다면, 이 방\n침으로 가시죠. 단, 체력을 상\n당히 소모하므로 주의하시기 바\n랍니다」");
	AcDietFinalConfirmSelectionMenu->On();
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::다이어트_시킨다;
}

void UIManager::ClickMainMenu_02_0_0(Button* _Button)
{
	switch (DietSetConfirm)
	{
	case Diet::무리하지_않는다:
		Olive::OlivePlayer->SetOliveDiet(Diet::무리하지_않는다);
		break;
	case Diet::어쨌든_튼튼하게:
		Olive::OlivePlayer->SetOliveDiet(Diet::어쨌든_튼튼하게);
		break;
	case Diet::얌전한_아이로:
		Olive::OlivePlayer->SetOliveDiet(Diet::얌전한_아이로);
		break;
	case Diet::다이어트_시킨다:
		Olive::OlivePlayer->SetOliveDiet(Diet::다이어트_시킨다);
		break;
	default:
		break;
	}
	AcMainMenu->On();
	AcDietFinalConfirmSelectionMenu->Off();
	AcCubeDialog->Off();
}

void UIManager::ClickMainMenu_02_0_1(Button* _Button)
{
	AcMainMenu->On();
	AcDietFinalConfirmSelectionMenu->Off();
	AcCubeDialog->Off();
}

void UIManager::ClickMainMenu_03(Button* _Button)
{
	AcMainMenu->Off();
	AcPersonalInformationWindow->On();
	AcHelthInformationWindow->On();
	AcPhysicalStatusWindow->On();
}

void UIManager::ClickMainMenu_S(Button* _Button)
{
	AcMainMenu->Off();
	AcScheduleCalendar->On();
	AcScheduleSelectionMenu->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "이번 달 딸의 예정은? ( 1 번째 )");
}

void UIManager::ClickMainMenu_S_0(Button* _Button)
{
	AcScheduleSelectionMenu->Off();
	AcClassSelectWindow->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "딸에게 무엇을 가르치시겠습니까?");
}
