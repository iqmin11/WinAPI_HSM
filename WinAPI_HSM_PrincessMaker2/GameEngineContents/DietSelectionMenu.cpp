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
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 0, "무리하지 않는다");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 1, "어쨌든 튼튼하게");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 2, "얌전한 아이로");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 3, "다이어트 시킨다");
	
	SetButton();

	Off();
}

void DietSelectionMenu::Update(float _DeltaTime)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「주인님, 아가씨의 건강관리는\n어떤 방침으로 하시겠습니까?」");
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
	AcDietFinalConfirmSelectionMenu->SetDietState(Diet::무리하지_않는다);
}

void DietSelectionMenu::Click1(Button* _Button)
{
	AcDietSelectionMenu->Off();
	AcDietFinalConfirmSelectionMenu->On();
	AcDietFinalConfirmSelectionMenu->SetDietState(Diet::어쨌든_튼튼하게);
}

void DietSelectionMenu::Click2(Button* _Button)
{
	AcDietSelectionMenu->Off();
	AcDietFinalConfirmSelectionMenu->On();
	AcDietFinalConfirmSelectionMenu->SetDietState(Diet::얌전한_아이로);
}

void DietSelectionMenu::Click3(Button* _Button)
{
	AcDietSelectionMenu->Off();
	AcDietFinalConfirmSelectionMenu->On();
	AcDietFinalConfirmSelectionMenu->SetDietState(Diet::다이어트_시킨다);
}

