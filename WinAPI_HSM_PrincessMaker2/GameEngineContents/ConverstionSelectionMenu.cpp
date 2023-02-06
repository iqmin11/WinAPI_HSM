#include "ConverstionSelectionMenu.h"
#include <GameEnginePlatform/GameEngineWindow.h>

ConverstionSelectionMenu::ConverstionSelectionMenu()
{

}

ConverstionSelectionMenu::~ConverstionSelectionMenu()
{

}

void ConverstionSelectionMenu::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu0, 0);
	SetMenuFrameScale({ 170,112 });
	SetButton(3, PM2RenderOrder::Menu0_Button);
	SetPos({685, 354});
}
