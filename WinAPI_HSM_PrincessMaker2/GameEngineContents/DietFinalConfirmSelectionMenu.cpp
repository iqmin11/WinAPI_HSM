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
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 0, "이 방침으로");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 1, "지금까지대로");
	SetButtonClick();
	Off();
}

void DietFinalConfirmSelectionMenu::Update(float _DeltaTime)
{
	switch (DietState)
	{
	case Diet::Null:
		break;
	case Diet::무리하지_않는다:
		AcSelectDialog->SetUpdateText("무리하지 않는다");
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n30G 들어갑니다. 무리 없는 식\n생활을 보낼 수 있습니다」");
		break;
	case Diet::어쨌든_튼튼하게:
		AcSelectDialog->SetUpdateText("어쨌든 튼튼하게");
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n80G 들어갑니다. 체력이 올라가\n겠죠」");
		break;
	case Diet::얌전한_아이로:
		AcSelectDialog->SetUpdateText("얌전한 아이로");
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n10G 들어갑니다. 약간 건강에 부\n담이 갈지도 모릅니다」");
		break;
	case Diet::다이어트_시킨다:
		AcSelectDialog->SetUpdateText("다이어트 시킨다");
		AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n5G 밖에 들지 않습니다. 아가씨의\n몸무게를 줄이고 싶다면, 이 방\n침으로 가시죠. 단, 체력을 상\n당히 소모하므로 주의하시기 바\n랍니다」");
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
	AcCubeDialog->UpdateCubeDialog(CubeFace::Proud, "예, 알겠습니다. 다음달부터 그\n렇게 하겠습니다");
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
