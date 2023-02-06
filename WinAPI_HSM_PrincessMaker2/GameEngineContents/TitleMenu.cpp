#include "TitleMenu.h"
#include <GameEnginePlatform/GameEngineWindow.h>

TitleMenu::TitleMenu()
{

}

TitleMenu::~TitleMenu()
{

}

void TitleMenu::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu0, 0);
	SetMenuFrameScale({ 230,112 });
	SetPos({ GameEngineWindow::GetScreenSize().half() });
	SetButton(3, PM2RenderOrder::Menu0_Button);
}

