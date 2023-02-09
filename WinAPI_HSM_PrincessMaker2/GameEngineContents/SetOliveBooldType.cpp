#include "SetOliveBooldType.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include "ContentsEnums.h"

SetOliveBooldType::SetOliveBooldType()
{

}

SetOliveBooldType::~SetOliveBooldType()
{

}

void SetOliveBooldType::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	BackgroundRender = CreateRender("SetOliveBackground.BMP", PM2RenderOrder::BackGround);
	BackgroundRender->SetScaleToImage();

	Off();
}

void SetOliveBooldType::Update(float _DeltaTime)
{
}

void SetOliveBooldType::Render(float _DeltaTime)
{
}
