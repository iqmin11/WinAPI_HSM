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

	AcCubeDialog->SetUpdateText("�����δ�, �ȳ��Ͻʴϱ�. ���� \nť�� �Դϴ�.��");
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
			if (AcCubeDialog->GetUpdateText() == "�����δ�, �ȳ��Ͻʴϱ�. ���� \nť�� �Դϴ�.��")
			{
				AcCubeDialog->SetUpdateText("���ư����� ���õ� �ǰ��Ͻʴ�\n��. �׷� ���� �ư����� �̹� \n�� �������� ������ �ֽʽÿ���");
			}
			else if (AcCubeDialog->GetUpdateText() == "���ư����� ���õ� �ǰ��Ͻʴ�\n��. �׷� ���� �ư����� �̹� \n�� �������� ������ �ֽʽÿ���")
			{
				AcCubeDialog->Off();
				AcMainMenu->On();
			}
			else if (AcCubeDialog->GetUpdateText() == "��, �˰ڽ��ϴ�. �����޺��� ��\n���� �ϰڽ��ϴ�")
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
//		else if (AcScheduleSelectionMenu->IsUpdate()) // ������ ���� ����(����, �˹�, �޽� ��)�� ��Ȳ���� �����ʸ��콺 Ŭ���ϴ� ��Ȳ
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
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 1 ��° )");
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcScheduleCalendar->CancelSchedule();
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 2 ��° )");
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcScheduleCalendar->CancelSchedule();
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 3 ��° )");
//			}
//		}
//		else if (AcClassSelectWindow->IsUpdate()) // ���� �����ϴ� â���� ������ ���콺 Ŭ���ϴ� ��Ȳ
//		{
//			AcClassSelectWindow->Off();
//			AcScheduleCalendar->On();
//			AcScheduleSelectionMenu->On();
//			if (!AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 1 ��° )");
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 2 ��° )");
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 3 ��° )");
//			}
//		}
//		else if (AcSchedulingConfirmSelectionMenu->IsUpdate())
//		{
//			AcSchedulingConfirmSelectionMenu->Off();
//			AcScheduleSelectionMenu->On();
//			if (!AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 1 ��° )");
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 2 ��° )");
//			}
//			else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//			{
//				AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 3 ��° )");
//			}
//		}
//		else if (AcScheduleFinalConfirm->IsUpdate())
//		{
//			AcScheduleFinalConfirm->Off();
//			AcScheduleCalendar->Reset();
//			AcScheduleSelectionMenu->On();
//			AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 1 ��° )");
//		}
//		else if (AcPersonalInformationWindow->IsUpdate())
//		{
//			AcMainMenu->On();
//			AcPersonalInformationWindow->Off();
//			AcHelthInformationWindow->Off();
//			AcPhysicalStatusWindow->Off();
//		}
//		else if (AcCubeDialog->GetUpdateText() == "�����δ�, �ȳ��Ͻʴϱ�. ���� \nť�� �Դϴ�.��")
//		{
//			AcCubeDialog->SetUpdateText("���ư����� ���õ� �ǰ��Ͻʴ�\n��. �׷� ���� �ư����� �̹� \n�� �������� ������ �ֽʽÿ���");
//		}
//		else if (AcCubeDialog->GetUpdateText() == "���ư����� ���õ� �ǰ��Ͻʴ�\n��. �׷� ���� �ư����� �̹� \n�� �������� ������ �ֽʽÿ���")
//		{
//			AcMainMenu->On();
//			AcCubeDialog->Off();
//		}
//		else if (AcCubeDialog->GetUpdateText() == "��, �˰ڽ��ϴ�. �����޺��� ��\n���� �ϰڽ��ϴ�")
//		{
//			AcMainMenu->On();	
//			AcSelectDialog->Off();
//			AcCubeDialog->Off();
//		}
//		else if (AcCubeDialog->GetUpdateText() == "�������� �����մϴ�" && AcCubeDialog->IsUpdate())
//		{
//			AcCubeDialog->Off();
//			AcScheduleCalendar->Off();
//			AcFoodCostDialog->On();
//		}
//		else if (AcFoodCostDialog->IsUpdate())
//		{
//			AcFoodCostDialog->Off();
//			//���⼭ �ĺ� ��ƾ���
//			switch (Olive::OlivePlayer->GetOliveDiet())
//			{
//			case Diet::��������_�ʴ´�:
//				Olive::OlivePlayer->GetGold() -= 30;
//				break;
//			case Diet::��·��_ưư�ϰ�:
//				Olive::OlivePlayer->GetGold() -= 80;
//				break;
//			case Diet::������_���̷�:
//				Olive::OlivePlayer->GetGold() -= 10;
//				break;
//			case Diet::���̾�Ʈ_��Ų��:
//				Olive::OlivePlayer->GetGold() -= 5;
//				break;
//			default:
//				break;
//			}
//			AcScheduleDialog->UpdateScheduleDialog(ScheduleLabel::�̼�, "�ձ�ȭ�� ��Ų��\n������ �ձ�ȭ���� ��Ų����.\n�׸��� ���ؼ� ������ �ɿ�����\n ������ �ֵ��� ����.��");
//		}
//		else if (AcScheduleDialog->GetUpdateText() == "�ձ�ȭ�� ��Ų��\n������ �ձ�ȭ���� ��Ų����.\n�׸��� ���ؼ� ������ �ɿ�����\n ������ �ֵ��� ����.��")
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
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�����δ�, �ư����� �ǰ�������\n� ��ħ���� �Ͻðڽ��ϱ�?��");
//}
//
//void UIManager::ClickMainMenu_02_0(Button* _Button)
//{
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n30G ���ϴ�. ���� ���� ��\n��Ȱ�� ���� �� �ֽ��ϴ١�");
//	AcDietFinalConfirmSelectionMenu->On();
//	AcSelectDialog->On();
//	AcSelectDialog->SetUpdateText("�������� �ʴ´�");
//	AcDietSelectionMenu->Off();
//	DietSetConfirm = Diet::��������_�ʴ´�;
//}
//
//void UIManager::ClickMainMenu_02_1(Button* _Button)
//{
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n80G ���ϴ�. ü���� �ö�\n���ҡ�");
//	AcDietFinalConfirmSelectionMenu->On();
//	AcSelectDialog->On();
//	AcSelectDialog->SetUpdateText("��·�� ưư�ϰ�");
//	AcDietSelectionMenu->Off();
//	DietSetConfirm = Diet::��·��_ưư�ϰ�;
//}
//
//void UIManager::ClickMainMenu_02_2(Button* _Button)
//{
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n10G ���ϴ�. �ణ �ǰ��� ��\n���� ������ �𸨴ϴ١�");
//	AcDietFinalConfirmSelectionMenu->On();
//	AcSelectDialog->On();
//	AcSelectDialog->SetUpdateText("������ ���̷�");
//	AcDietSelectionMenu->Off();
//	DietSetConfirm = Diet::������_���̷�;
//}
//
//void UIManager::ClickMainMenu_02_3(Button* _Button)
//{
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n5G �ۿ� ���� �ʽ��ϴ�. �ư�����\n�����Ը� ���̰� �ʹٸ�, �� ��\nħ���� ������. ��, ü���� ��\n���� �Ҹ��ϹǷ� �����Ͻñ� ��\n���ϴ١�");
//	AcDietFinalConfirmSelectionMenu->On();
//	AcSelectDialog->On();
//	AcSelectDialog->SetUpdateText("���̾�Ʈ ��Ų��");
//	AcDietSelectionMenu->Off();
//	DietSetConfirm = Diet::���̾�Ʈ_��Ų��;
//}
//
//void UIManager::ClickMainMenu_02_0_0(Button* _Button)
//{
//	switch (DietSetConfirm)
//	{
//	case Diet::��������_�ʴ´�:
//		Olive::OlivePlayer->SetOliveDiet(Diet::��������_�ʴ´�);
//		break;
//	case Diet::��·��_ưư�ϰ�:
//		Olive::OlivePlayer->SetOliveDiet(Diet::��·��_ưư�ϰ�);
//		break;
//	case Diet::������_���̷�:
//		Olive::OlivePlayer->SetOliveDiet(Diet::������_���̷�);
//		break;
//	case Diet::���̾�Ʈ_��Ų��:
//		Olive::OlivePlayer->SetOliveDiet(Diet::���̾�Ʈ_��Ų��);
//		break;
//	default:
//		break;
//	}
//	AcDietFinalConfirmSelectionMenu->Off();
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Proud, "��, �˰ڽ��ϴ�. �����޺��� ��\n���� �ϰڽ��ϴ�");
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
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 1 ��° )");
//	}
//	else if (AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 2 ��° )");
//	}
//	else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 3 ��° )");
//	}
//}

//void UIManager::ClickMainMenu_S_0(Button* _Button)
//{
//	AcScheduleSelectionMenu->Off();
//	AcClassSelectWindow->On();
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "������ ������ ����ġ�ðڽ��ϱ�?");
//}

//void UIManager::ClickMainMenu_S_0_0(Button* _Button)
//{
//	AcClassSelectWindow->Off();
//	ScheduleSetConfirm = ScheduleLabel::�̼�;
//	AcSchedulingConfirmSelectionMenu->On();
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̼�. \n�׸��� �׷� �������� ������\n���� �۴´�");
//}

//void UIManager::ClickMainMenu_S_0_0_0(Button* _Button) // �����ٿ� ���Ѵ�
//{
//	AcScheduleCalendar->ScheduleSetting(ScheduleSetConfirm);
//	if (AcScheduleCalendar->ScheduleSetEnd)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "����, �����ٿ� ���ϰڽ��ϴ١�\n�̹����� �� �����ٷ�\n�����ϱ�?");
//		AcScheduleFinalConfirm->On();
//		AcSchedulingConfirmSelectionMenu->Off();
//	}
//	else if (AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 2 ��° )");
//		AcSchedulingConfirmSelectionMenu->Off();
//		AcScheduleSelectionMenu->On();
//	}
//	else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 3 ��° )");
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
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 1 ��° )");
//	}
//	else if (AcScheduleCalendar->FirstScheduleSet && !AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 2 ��° )");
//	}
//	else if (AcScheduleCalendar->FirstScheduleSet && AcScheduleCalendar->SecondScheduleSet && !AcScheduleCalendar->ThirdScheduleSet)
//	{
//		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 3 ��° )");
//	}
//}

//void UIManager::ClickMainMenu_S_0_0_0_0(Button* _Button)
//{
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�������� �����մϴ�");
//	AcScheduleFinalConfirm->Off();
//}

//void UIManager::ClickMainMenu_S_0_0_0_1(Button* _Button)
//{
//	AcScheduleFinalConfirm->Off();
//	AcScheduleCalendar->Reset();
//	AcScheduleSelectionMenu->On();
//	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�̹� �� ���� ������? ( 1 ��° )");
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
