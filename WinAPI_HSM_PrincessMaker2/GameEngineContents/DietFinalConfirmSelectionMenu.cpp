#include "DietFinalConfirmSelectionMenu.h"

DietFinalConfirmSelectionMenu::DietFinalConfirmSelectionMenu()
{

}

DietFinalConfirmSelectionMenu::~DietFinalConfirmSelectionMenu()
{

}

void DietFinalConfirmSelectionMenu::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu2, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(2, ActorPos, Xscale, PM2ActorOrder::Menu2_Button, PM2RenderOrder::Menu2_Button);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 0, "이 방침으로");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu2_Display), 1, "지금까지대로");
	Off();
}
