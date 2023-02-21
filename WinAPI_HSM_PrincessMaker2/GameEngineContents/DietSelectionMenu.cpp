#include "DietSelectionMenu.h"
#include <GameEngineCore/Button.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "RaisingSimLevel.h"
#include "CubeDialog.h"
#include "Olive.h"

CubeDialog* DietSelectionMenu::AcCubeDialog = nullptr;

DietSelectionMenu::DietSelectionMenu()
{

}

DietSelectionMenu::~DietSelectionMenu()
{

}

void DietSelectionMenu::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu0, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(4, ActorPos, Xscale, PM2ActorOrder::Menu0_Button, PM2RenderOrder::Menu0_Button);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 0, "무리하지 않는다");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 1, "어쨌든 튼튼하게");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 2, "얌전한 아이로");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 3, "다이어트 시킨다");
	
	GetSelectButtons()[0]->SetClickCallBack(Click0);
	GetSelectButtons()[1]->SetClickCallBack(Click1);
	GetSelectButtons()[2]->SetClickCallBack(Click2);
	GetSelectButtons()[3]->SetClickCallBack(Click3);

	AcCubeDialog = dynamic_cast<RaisingSimLevel*>(GetLevel())->AcCubeDialog;

	Off();
}

void DietSelectionMenu::Click0(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n30G 들어갑니다. 무리 없는 식\n생활을 보낼 수 있습니다」");
	Olive::OlivePlayer->SetOliveDiet(Diet::무리하지_않는다);
}

void DietSelectionMenu::Click1(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n80G 들어갑니다. 체력이 올라가\n겠죠」");
	Olive::OlivePlayer->SetOliveDiet(Diet::어쨌든_튼튼하게);
}

void DietSelectionMenu::Click2(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n10G 들어갑니다. 약간 건강에 부\n담이 갈지도 모릅니다」");
	Olive::OlivePlayer->SetOliveDiet(Diet::얌전한_아이로);
}

void DietSelectionMenu::Click3(Button* _Button)
{
	AcCubeDialog->UpdateCubeDialog(CubeFace::Nomal, "「그 방침이라면 매달 식비가\n5G 밖에 들지 않습니다. 아가씨의\n몸무게를 줄이고 싶다면, 이 방\n침으로 가시죠. 단, 체력을 상\n당히 소모하므로 주의하시기 바\n랍니다」");
	Olive::OlivePlayer->SetOliveDiet(Diet::다이어트_시킨다);
}
