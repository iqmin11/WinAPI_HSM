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
	SetPos(GameEngineWindow::GetScreenSize().half());
}

void Background::Update(float _Deltatime)
{

}

void Background::Render(float _Time)
{
	float4 PlayerPos = GetPos();
	GameEngineImage* Image = GameEngineResources::GetInst().ImageFind("background.bmp");
	GameEngineWindow::GetDoubleBufferImage()->BitCopy(Image, PlayerPos, Image->GetImageScale()/*{ 800, 600 }*/);
}
