#include "DietFinalConfirmSelectionMenu.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "SelectDialog.h"
#include "CubeDialog.h"
#include "RaisingSimLevel.h"
#include "MainMenu.h"
#include "Olive.h"

CubeDialog* DietFinalConfirmSelectionMenu::AcCubeDialog = nullptr;
DietFinalConfirmSelectionMenu* DietFinalConfirmSelectionMenu::AcDietFinalConfirmSelectionMenu = nullptr;
Diet DietFinalConfirmSelectionMenu::DietState = Diet::Null;

DietFinalConfirmSelectionMenu::DietFinalConfirmSelectionMenu()
{
	AcDietFinalConfirmSelectionMenu = this;
}

DietFinalConfirmSelectionMenu::~DietFinalConfirmSelectionMenu()
{

}

void DietFinalConfirmSelectionMenu::Start()
{
	AcSelectDialog = GetLevel()->CreateActor<SelectDialog>(PM2ActorOrder::Menu2);
	AcSelectDialog->SetUpdateText(" ");
	AcCubeDialog = dynamic_cast<RaisingSimLevel*>(GetLevel())->GetAcCubeDialog();

	InitMenuFrameRender(PM2RenderOrder::Menu2, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(2, ActorPos, Xscale, PM2ActorOrder::Menu2_Button, PM2RenderOrder::Menu2_Button);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 0, "�� ��ħ����");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 1, "���ݱ������");
	SetButtonClick();
	Off();
}

void DietFinalConfirmSelectionMenu::Update(float _DeltaTime)
{
	switch (DietState)
	{
	case Diet::Null:
		break;
	case Diet::��������_�ʴ´�:
		AcSelectDialog->SetUpdateText("�������� �ʴ´�");
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n30G ���ϴ�. ���� ���� ��\n��Ȱ�� ���� �� �ֽ��ϴ١�");
		break;
	case Diet::��·��_ưư�ϰ�:
		AcSelectDialog->SetUpdateText("��·�� ưư�ϰ�");
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n80G ���ϴ�. ü���� �ö�\n���ҡ�");
		break;
	case Diet::������_���̷�:
		AcSelectDialog->SetUpdateText("������ ���̷�");
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n10G ���ϴ�. �ణ �ǰ��� ��\n���� ������ �𸨴ϴ١�");
		break;
	case Diet::���̾�Ʈ_��Ų��:
		AcSelectDialog->SetUpdateText("���̾�Ʈ ��Ų��");
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "���� ��ħ�̶�� �Ŵ� �ĺ�\n5G �ۿ� ���� �ʽ��ϴ�. �ư�����\n�����Ը� ���̰� �ʹٸ�, �� ��\nħ���� ������. ��, ü���� ��\n���� �Ҹ��ϹǷ� �����Ͻñ� ��\n���ϴ١�");
		break;
	default:
		break;
	}
}

void DietFinalConfirmSelectionMenu::SetButtonClick()
{
	GetSelectButtons()[0]->SetClickCallBack(Click0);
	GetSelectButtons()[1]->SetClickCallBack(Click1);
}

void DietFinalConfirmSelectionMenu::Click0(Button* _Button)
{
	Olive::OlivePlayer->SetOliveDiet(DietState);
	DietState = Diet::Null;
	AcCubeDialog->UpdateCubeDialog(CubeFace::Proud, "��, �˰ڽ��ϴ�. �����޺��� ��\n���� �ϰڽ��ϴ�");
	AcDietFinalConfirmSelectionMenu->Off();
}

void DietFinalConfirmSelectionMenu::Click1(Button* _Button)
{
	AcDietFinalConfirmSelectionMenu->Off();
	AcCubeDialog->Off();
	MainMenu::GetAcMainMenu()->On();
}

void DietFinalConfirmSelectionMenu::On()
{
	SelectionMenu::On();
	AcSelectDialog->On();
}

void DietFinalConfirmSelectionMenu::Off()
{
	SelectionMenu::Off();
	AcSelectDialog->Off();
}

void DietFinalConfirmSelectionMenu::SetDietState(Diet _State)
{
	DietState = _State;
}
