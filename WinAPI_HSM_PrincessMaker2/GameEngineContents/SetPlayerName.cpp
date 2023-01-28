#include "SetPlayerName.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "ContentsEnums.h"

SetPlayerName::SetPlayerName()
{

}

SetPlayerName::~SetPlayerName()
{

}

void SetPlayerName::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	BackgroundRender = CreateRender("SetPlayerBackground.BMP", PM2RenderOrder::BackGround);
	Off();
}

void SetPlayerName::Update(float _DeltaTime)
{
}

void SetPlayerName::Render(float _DeltaTime)
{
}
