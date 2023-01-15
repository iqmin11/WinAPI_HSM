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
}

void TitleBackground::Update(float _Deltatime)
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	GameEngineRender* Render = CreateRender("titlebackground.BMP", 0);
}

void TitleBackground::Render(float _Time)
{
}
