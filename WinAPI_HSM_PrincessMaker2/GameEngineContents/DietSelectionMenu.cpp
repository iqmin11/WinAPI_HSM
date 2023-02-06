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
	SetMenuFrameScale({ 170,138 });
	SetButton(4, PM2RenderOrder::Menu0_Button);
	SetPos({ 685, 366 });
}
