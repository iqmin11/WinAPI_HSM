#include "SetOliveName.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineRender.h>

#include "FirstSetLevel.h"
#include "ContentsEnums.h"

SetOliveName::SetOliveName()
{

}

SetOliveName::~SetOliveName()
{

}

void SetOliveName::Start() 
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	BackgroundRender = CreateRender("SetOliveBackground.BMP", PM2RenderOrder::BackGround);
	BackgroundRender->SetScaleToImage();
	
	Off();
}

void SetOliveName::Update(float _DeltaTime)
{
}

void SetOliveName::Render(float _DeltaTime)
{
}
