#include "Background.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>

Background::Background()
{

}

Background::~Background()
{

}

void Background::Start()
{
	SetPos({0,0});
}

void Background::Update()
{

}

void Background::Render()
{
	float4 PlayerPos = GetPos();
	GameEngineImage* Image = GameEngineResources::GetInst().ImageFind("808.bmp");
	GameEngineWindow::GetBackBufferImage()->BitCopy(Image, PlayerPos + float4{ 0,0 }, { 800, 600 });
}
