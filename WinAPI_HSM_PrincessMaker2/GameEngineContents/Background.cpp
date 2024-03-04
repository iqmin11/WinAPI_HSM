#include "Background.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

Background::Background()
{

}

Background::~Background()
{

}

void Background::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	BackgroundRender = CreateRender("background.BMP", 0);
	BackgroundRender->SetScaleToImage();
}

void Background::Update(float _DeltaTime)
{

}

void Background::Render(float _Time)
{
}
