#include "MenuManager.h"
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

#include "CubeDialog.h"

MainMenu* MenuManager::AcMainMenu = nullptr;
StatusWindowManager* MenuManager::AcStatusWindowManager = nullptr;

ConverstionSelectionMenu* MenuManager::AcConverstionSelectionMenu = nullptr;

Diet MenuManager::DietSetConfirm = Diet::Null;
DietSelectionMenu* MenuManager::AcDietSelectionMenu = nullptr;
DietFinalConfirmSelectionMenu* MenuManager::AcDietFinalConfirmSelectionMenu = nullptr;

PersonalInformationWindow* MenuManager::AcPersonalInformationWindow = nullptr;
HelthInformationWindow* MenuManager::AcHelthInformationWindow = nullptr;
PhysicalStatusWindow* MenuManager::AcPhysicalStatusWindow = nullptr;

ScheduleCalendar* MenuManager::AcScheduleCalendar = nullptr;
ScheduleSelectionMenu* MenuManager::AcScheduleSelectionMenu = nullptr;
ClassSelectWindow* MenuManager::AcClassSelectWindow = nullptr;

CubeDialog* MenuManager::AcCubeDialog = nullptr;

MenuManager::MenuManager()
{

}

MenuManager::~MenuManager()
{

}

void MenuManager::Start()
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

	AcCubeDialog = dynamic_cast<RaisingSimLevel*>(Level)->GetAcCubeDialog();

	SetButtonAndKey();
}

void MenuManager::Update(float _DeltaTime)
{
	SetEngineRightClick();
}

void MenuManager::SetButtonAndKey()
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

void MenuManager::SetEngineRightClick()
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
			AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 1 ��° )");
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

void MenuManager::ClickMainMenu_00(Button* _Button)
{
	AcMainMenu->Off();
	AcStatusWindowManager->On();
}

void MenuManager::ClickMainMenu_01(Button* _Button)
{
	AcMainMenu->Off();
	AcConverstionSelectionMenu->On();
}

void MenuManager::ClickMainMenu_02(Button* _Button)
{
	AcMainMenu->Off();
	AcDietSelectionMenu->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�����δ�, �ư����� �ǰ�������\n� ��ħ���� �Ͻðڽ��ϱ�?��");
}

void MenuManager::ClickMainMenu_02_0(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n30G ���ϴ�. ���� ���� ��\n��Ȱ�� ���� �� �ֽ��ϴ١�");
	AcDietFinalConfirmSelectionMenu->On();
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::��������_�ʴ´�;
}

void MenuManager::ClickMainMenu_02_1(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n80G ���ϴ�. ü���� �ö�\n���ҡ�");
	AcDietFinalConfirmSelectionMenu->On();
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::��·��_ưư�ϰ�;
}

void MenuManager::ClickMainMenu_02_2(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n10G ���ϴ�. �ణ �ǰ��� ��\n���� ������ �𸨴ϴ١�");
	AcDietFinalConfirmSelectionMenu->On();
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::������_���̷�;
}

void MenuManager::ClickMainMenu_02_3(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n5G �ۿ� ���� �ʽ��ϴ�. �ư�����\n�����Ը� ���̰� �ʹٸ�, �� ��\nħ���� ������. ��, ü���� ��\n���� �Ҹ��ϹǷ� �����Ͻñ� ��\n���ϴ١�");
	AcDietFinalConfirmSelectionMenu->On();
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::���̾�Ʈ_��Ų��;
}

void MenuManager::ClickMainMenu_02_0_0(Button* _Button)
{
	switch (DietSetConfirm)
	{
	case Diet::��������_�ʴ´�:
		Olive::OlivePlayer->SetOliveDiet(Diet::��������_�ʴ´�);
		break;
	case Diet::��·��_ưư�ϰ�:
		Olive::OlivePlayer->SetOliveDiet(Diet::��·��_ưư�ϰ�);
		break;
	case Diet::������_���̷�:
		Olive::OlivePlayer->SetOliveDiet(Diet::������_���̷�);
		break;
	case Diet::���̾�Ʈ_��Ų��:
		Olive::OlivePlayer->SetOliveDiet(Diet::���̾�Ʈ_��Ų��);
		break;
	default:
		break;
	}
	AcMainMenu->On();
	AcDietFinalConfirmSelectionMenu->Off();
	AcCubeDialog->Off();
}

void MenuManager::ClickMainMenu_02_0_1(Button* _Button)
{
	AcMainMenu->On();
	AcDietFinalConfirmSelectionMenu->Off();
	AcCubeDialog->Off();
}

void MenuManager::ClickMainMenu_03(Button* _Button)
{
	AcMainMenu->Off();
	AcPersonalInformationWindow->On();
	AcHelthInformationWindow->On();
	AcPhysicalStatusWindow->On();
}

void MenuManager::ClickMainMenu_S(Button* _Button)
{
	AcMainMenu->Off();
	AcScheduleCalendar->On();
	AcScheduleSelectionMenu->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 1 ��° )");
}

void MenuManager::ClickMainMenu_S_0(Button* _Button)
{
	AcScheduleSelectionMenu->Off();
	AcClassSelectWindow->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "������ ������ ����ġ�ðڽ��ϱ�?");
}
