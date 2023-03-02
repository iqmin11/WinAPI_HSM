#include "DietSelectionMenu.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/Button.h>
#include "Olive.h"
#include "MainMenu.h"
#include "RaisingSimLevel.h"
#include "CubeDialog.h"
#include "DietFinalConfirmSelectionMenu.h"

DietSelectionMenu* DietSelectionMenu::AcDietSelectionMenu = nullptr;
CubeDialog* DietSelectionMenu::AcCubeDialog = nullptr; 
DietFinalConfirmSelectionMenu* DietSelectionMenu::AcDietFinalConfirmSelectionMenu = nullptr;

DietSelectionMenu::DietSelectionMenu()
{
	AcDietSelectionMenu = this;
}

DietSelectionMenu::~DietSelectionMenu()
{

}

void DietSelectionMenu::Start()
{
	AcMainMenu = MainMenu::GetAcMainMenu();
	AcCubeDialog = dynamic_cast<RaisingSimLevel*>(GetLevel())->GetAcCubeDialog();
	AcDietFinalConfirmSelectionMenu = GetLevel()->CreateActor<DietFinalConfirmSelectionMenu>(PM2ActorOrder::Menu2);

	InitMenuFrameRender(PM2RenderOrder::Menu0, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(4, ActorPos, Xscale, PM2ActorOrder::Menu0_Button, PM2RenderOrder::Menu0_Button);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 0, "�������� �ʴ´�");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 1, "��·�� ưư�ϰ�");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 2, "������ ���̷�");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 3, "���̾�Ʈ ��Ų��");
	
	SetButton();

	Off();
}

void DietSelectionMenu::Update(float _DeltaTime)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "�����δ�, �ư����� �ǰ�������\n� ��ħ���� �Ͻðڽ��ϱ�?��");
	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		Off();
		AcCubeDialog->Off();
		AcMainMenu->On();
	}
}

void DietSelectionMenu::SetButton()
{
	GetSelectButtons()[0]->SetClickCallBack(Click0);
	GetSelectButtons()[1]->SetClickCallBack(Click1);
	GetSelectButtons()[2]->SetClickCallBack(Click2);
	GetSelectButtons()[3]->SetClickCallBack(Click3);
}

void DietSelectionMenu::Click0(Button* _Button)
{
	AcDietSelectionMenu->Off();
	AcDietFinalConfirmSelectionMenu->On();
	AcDietFinalConfirmSelectionMenu->SetDietState(Diet::��������_�ʴ´�);
}

void DietSelectionMenu::Click1(Button* _Button)
{
	AcDietSelectionMenu->Off();
	AcDietFinalConfirmSelectionMenu->On();
	AcDietFinalConfirmSelectionMenu->SetDietState(Diet::��·��_ưư�ϰ�);
}

void DietSelectionMenu::Click2(Button* _Button)
{
	AcDietSelectionMenu->Off();
	AcDietFinalConfirmSelectionMenu->On();
	AcDietFinalConfirmSelectionMenu->SetDietState(Diet::������_���̷�);
}

void DietSelectionMenu::Click3(Button* _Button)
{
	AcDietSelectionMenu->Off();
	AcDietFinalConfirmSelectionMenu->On();
	AcDietFinalConfirmSelectionMenu->SetDietState(Diet::���̾�Ʈ_��Ų��);
}

