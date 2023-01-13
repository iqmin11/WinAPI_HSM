#include "Background.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
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
	GameEngineRender* Render = CreateRender("background.BMP", 0);
	Render->SetScale({ 800,600 });

}

void Background::Update(float _Deltatime)
{

}

void Background::Render(float _Time)
{
	//float4 PlayerPos = GetPos();
	//GameEngineImage* Image = GameEngineResources::GetInst().ImageFind("background.bmp");
	//GameEngineWindow::GetDoubleBufferImage()->BitCopy(Image, PlayerPos, Image->GetImageScale()/*{ 800, 600 }*/);
}
