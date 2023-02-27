#include "UIManager.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>

#include "RaisingSimLevel.h"
#include "Olive.h"

#include "MainMenu.h"
#include "StatusWindowManager.h"

#include "ConverstionSelectionMenu.h"

#include "DietSelectionMenu.h"
#include "SelectDialog.h"
#include "DietFinalConfirmSelectionMenu.h"

#include "PersonalInformationWindow.h"
#include "HelthInformationWindow.h"
#include "PhysicalStatusWindow.h"

#include "ScheduleCalendar.h"
#include "ScheduleSelectionMenu.h"
#include "ClassSelectWindow.h"
#include "ScheduleAnimationPlayer.h"
#include "IconButton.h"
#include "SchedulingConfirmSelectionMenu.h"

#include "CubeDialog.h"

RaisingSimLevel* UIManager::ParentLevel = nullptr;

//���θ޴�
MainMenu* UIManager::AcMainMenu = nullptr;

//����â
StatusWindowManager* UIManager::AcStatusWindowManager = nullptr;

//������ ��ȭ
ConverstionSelectionMenu* UIManager::AcConverstionSelectionMenu = nullptr;

//�Ĵ�
Diet UIManager::DietSetConfirm = Diet::Null;
DietSelectionMenu* UIManager::AcDietSelectionMenu = nullptr;
SelectDialog* UIManager::AcSelectDialog = nullptr;
DietFinalConfirmSelectionMenu* UIManager::AcDietFinalConfirmSelectionMenu = nullptr;

//�������� �� ��ü����
PersonalInformationWindow* UIManager::AcPersonalInformationWindow = nullptr;
HelthInformationWindow* UIManager::AcHelthInformationWindow = nullptr;
PhysicalStatusWindow* UIManager::AcPhysicalStatusWindow = nullptr;

//������â
ScheduleCalendar* UIManager::AcScheduleCalendar = nullptr;
ScheduleSelectionMenu* UIManager::AcScheduleSelectionMenu = nullptr;
ClassSelectWindow* UIManager::AcClassSelectWindow = nullptr;
ScheduleAnimationPlayer* UIManager::AcScheduleAnimationPlayer = nullptr;
SchedulingConfirmSelectionMenu* UIManager::AcSchedulingConfirmSelectionMenu = nullptr;

//ť���� ��ȭâ
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
	AllMenu.push_back(AcMainMenu);

	AcStatusWindowManager = ParentLevel->CreateActor<StatusWindowManager>(PM2ActorOrder::Menu1);
	AllMenu.push_back(AcStatusWindowManager);

	AcConverstionSelectionMenu = ParentLevel->CreateActor<ConverstionSelectionMenu>(PM2ActorOrder::Menu1);
	AllMenu.push_back(AcConverstionSelectionMenu);

	AcDietSelectionMenu = ParentLevel->CreateActor<DietSelectionMenu>(PM2ActorOrder::Menu1);
	AllMenu.push_back(AcDietSelectionMenu);
	AcSelectDialog = ParentLevel->CreateActor<SelectDialog>(PM2ActorOrder::Menu1);
	AllMenu.push_back(AcSelectDialog);
	AcDietFinalConfirmSelectionMenu = ParentLevel->CreateActor<DietFinalConfirmSelectionMenu>(PM2ActorOrder::Menu2);
	AllMenu.push_back(AcDietFinalConfirmSelectionMenu);

	AcPersonalInformationWindow = ParentLevel->CreateActor<PersonalInformationWindow>(PM2ActorOrder::Menu1);
	AllMenu.push_back(AcPersonalInformationWindow);
	AcHelthInformationWindow = ParentLevel->CreateActor<HelthInformationWindow>(PM2ActorOrder::Menu1);
	AllMenu.push_back(AcHelthInformationWindow);
	AcPhysicalStatusWindow = ParentLevel->CreateActor<PhysicalStatusWindow>(PM2ActorOrder::Menu1);
	AllMenu.push_back(AcPhysicalStatusWindow);

	AcScheduleCalendar = ParentLevel->CreateActor<ScheduleCalendar>(PM2ActorOrder::Menu1);
	AllMenu.push_back(AcScheduleCalendar);
	AcScheduleSelectionMenu = ParentLevel->CreateActor<ScheduleSelectionMenu>(PM2ActorOrder::Menu1);
	AllMenu.push_back(AcScheduleSelectionMenu);
	AcClassSelectWindow = ParentLevel->CreateActor<ClassSelectWindow>(PM2ActorOrder::Menu2);
	AllMenu.push_back(AcClassSelectWindow);
	AcScheduleAnimationPlayer = ParentLevel->CreateActor<ScheduleAnimationPlayer>(PM2ActorOrder::Menu2);
	AllMenu.push_back(AcScheduleAnimationPlayer);
	AcSchedulingConfirmSelectionMenu = ParentLevel->CreateActor<SchedulingConfirmSelectionMenu>(PM2ActorOrder::Menu2);
	AllMenu.push_back(AcSchedulingConfirmSelectionMenu);

	AcCubeDialog = ParentLevel->GetAcCubeDialog();

	AcCubeDialog->SetUpdateText("�����δ�, �ȳ��Ͻʴϱ�. ���� \nť�� �Դϴ�.��");

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

	AcSchedulingConfirmSelectionMenu->GetSelectButtons()[0]->SetClickCallBack(ClickMainMenu_S_0_0_0);
	AcSchedulingConfirmSelectionMenu->GetSelectButtons()[1]->SetClickCallBack(ClickMainMenu_S_0_0_1);

	AcClassSelectWindow->GetPaintingButton()->SetClickCallBack(ClickMainMenu_S_0_0);
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
			AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 1 ��° )");
		}
		else if (AcSchedulingConfirmSelectionMenu->IsUpdate())
		{
			AcSchedulingConfirmSelectionMenu->Off();
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
		else if (AcCubeDialog->GetUpdateText() == "�����δ�, �ȳ��Ͻʴϱ�. ���� \nť�� �Դϴ�.��")
		{
			AcCubeDialog->SetUpdateText("���ư����� ���õ� �ǰ��Ͻʴ�\n��. �׷� ���� �ư����� �̹� \n�� �������� ������ �ֽʽÿ���");
		}
		else if (AcCubeDialog->GetUpdateText() == "���ư����� ���õ� �ǰ��Ͻʴ�\n��. �׷� ���� �ư����� �̹� \n�� �������� ������ �ֽʽÿ���")
		{
			AcMainMenu->On();
			AcCubeDialog->Off();
		}
		else if (AcCubeDialog->GetUpdateText() == "��, �˰ڽ��ϴ�. �����޺��� ��\n���� �ϰڽ��ϴ�")
		{
			AcMainMenu->On();	
			AcSelectDialog->Off();
			AcCubeDialog->Off();
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
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�����δ�, �ư����� �ǰ�������\n� ��ħ���� �Ͻðڽ��ϱ�?��");
}

void UIManager::ClickMainMenu_02_0(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n30G ���ϴ�. ���� ���� ��\n��Ȱ�� ���� �� �ֽ��ϴ١�");
	AcDietFinalConfirmSelectionMenu->On();
	AcSelectDialog->On();
	AcSelectDialog->SetUpdateText("�������� �ʴ´�");
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::��������_�ʴ´�;
}

void UIManager::ClickMainMenu_02_1(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n80G ���ϴ�. ü���� �ö�\n���ҡ�");
	AcDietFinalConfirmSelectionMenu->On();
	AcSelectDialog->On();
	AcSelectDialog->SetUpdateText("��·�� ưư�ϰ�");
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::��·��_ưư�ϰ�;
}

void UIManager::ClickMainMenu_02_2(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n10G ���ϴ�. �ణ �ǰ��� ��\n���� ������ �𸨴ϴ١�");
	AcDietFinalConfirmSelectionMenu->On();
	AcSelectDialog->On();
	AcSelectDialog->SetUpdateText("������ ���̷�");
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::������_���̷�;
}

void UIManager::ClickMainMenu_02_3(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n5G �ۿ� ���� �ʽ��ϴ�. �ư�����\n�����Ը� ���̰� �ʹٸ�, �� ��\nħ���� ������. ��, ü���� ��\n���� �Ҹ��ϹǷ� �����Ͻñ� ��\n���ϴ١�");
	AcDietFinalConfirmSelectionMenu->On();
	AcSelectDialog->On();
	AcSelectDialog->SetUpdateText("���̾�Ʈ ��Ų��");
	AcDietSelectionMenu->Off();
	DietSetConfirm = Diet::���̾�Ʈ_��Ų��;
}

void UIManager::ClickMainMenu_02_0_0(Button* _Button)
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
	AcDietFinalConfirmSelectionMenu->Off();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Proud, "��, �˰ڽ��ϴ�. �����޺��� ��\n���� �ϰڽ��ϴ�");
	
	//AcMainMenu->On();
	//AcCubeDialog->Off();
}

void UIManager::ClickMainMenu_02_0_1(Button* _Button)
{
	AcMainMenu->On();
	AcDietFinalConfirmSelectionMenu->Off();
	AcSelectDialog->Off();
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
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 1 ��° )");
}

void UIManager::ClickMainMenu_S_0(Button* _Button)
{
	AcScheduleSelectionMenu->Off();
	AcClassSelectWindow->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "������ ������ ����ġ�ðڽ��ϱ�?");
}

void UIManager::ClickMainMenu_S_0_0(Button* _Button)
{
	AcClassSelectWindow->Off();
	AcSchedulingConfirmSelectionMenu->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̼�. \n�׸��� �׷� �������� ������\n���� �۴´�");
}

void UIManager::ClickMainMenu_S_0_0_0(Button* _Button)
{
	AcSchedulingConfirmSelectionMenu->Off();
	AcScheduleSelectionMenu->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 2 ��° )");
}

void UIManager::ClickMainMenu_S_0_0_1(Button* _Button)
{
	AcSchedulingConfirmSelectionMenu->Off();
	AcScheduleSelectionMenu->On();
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 1 ��° )");
}

bool UIManager::IsAnyMenuUpdate()
{
	for (auto i : AllMenu)
	{
		if (i->IsUpdate())
		{
			return true;
		}
	}
	return false;
}
