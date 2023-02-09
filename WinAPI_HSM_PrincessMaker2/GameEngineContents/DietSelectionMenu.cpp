#include "DietSelectionMenu.h"

DietSelectionMenu::DietSelectionMenu()
{

}

DietSelectionMenu::~DietSelectionMenu()
{

}

void DietSelectionMenu::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu0, 0);
	SetSelectionMenu(4, { 685,366 }, 170.0f, PM2ActorOrder::Menu0_Button, PM2RenderOrder::Menu0_Button);
}
