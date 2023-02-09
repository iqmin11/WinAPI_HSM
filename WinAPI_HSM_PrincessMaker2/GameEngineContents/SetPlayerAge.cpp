#include "SetPlayerAge.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

SetPlayerAge::SetPlayerAge()
{

}

SetPlayerAge::~SetPlayerAge()
{

}

void SetPlayerAge::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	BackgroundRender = CreateRender("SetPlayerBackground.BMP", PM2RenderOrder::BackGround);
	BackgroundRender->SetScaleToImage();
	Off();
}

void SetPlayerAge::Update(float _DeltaTime)
{
}

void SetPlayerAge::Render(float _DeltaTime)
{
}
