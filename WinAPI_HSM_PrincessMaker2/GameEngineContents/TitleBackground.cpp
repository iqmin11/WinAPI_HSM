#include "TitleBackground.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

TitleBackground::TitleBackground()
{

}

TitleBackground::~TitleBackground()
{

}

void TitleBackground::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	Render = CreateRender("blackbackground.BMP", 0);
	Render->SetScaleToImage();
}

