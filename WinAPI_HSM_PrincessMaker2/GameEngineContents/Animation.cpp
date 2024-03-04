#include "Animation.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>


Animation::Animation()
{

}

Animation::~Animation()
{

}

void Animation::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
}

void Animation::Update(float _DeltaTime)
{
}

void Animation::Render(float _Time)
{
}
