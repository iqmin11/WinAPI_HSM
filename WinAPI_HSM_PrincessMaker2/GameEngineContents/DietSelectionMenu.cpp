#include "DietSelectionMenu.h"
#include <GameEngineCore/Button.h>
#include "Olive.h"

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

	Off();
}

void DietSelectionMenu::Click0(Button* _Button)
{
	Olive::OlivePlayer->SetOliveDiet(Diet::무리하지_않는다);
}

void DietSelectionMenu::Click1(Button* _Button)
{
	Olive::OlivePlayer->SetOliveDiet(Diet::어쨌든_튼튼하게);
}

void DietSelectionMenu::Click2(Button* _Button)
{
	Olive::OlivePlayer->SetOliveDiet(Diet::얌전한_아이로);
}

void DietSelectionMenu::Click3(Button* _Button)
{
	Olive::OlivePlayer->SetOliveDiet(Diet::다이어트_시킨다);
}
