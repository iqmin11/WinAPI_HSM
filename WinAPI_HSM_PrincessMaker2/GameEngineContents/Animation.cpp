#include "Animation.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>

Animation::Animation()
{

}

Animation::~Animation()
{

}

void Animation::Start()
{
	SetPos({0,0});
}

void Animation::Update()
{
	//SetMove(float4::Left * 0.01f);
}

void Animation::Render()
{
	float4 ImagePos = GetPos();
	GameEngineImage* Image = GameEngineResources::GetInst().ImageFind("PartTimeJobAnimation.bmp");
	GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, ImagePos + float4{ 0,0 }, Image->GetImageScale(), { 0,0 }, Image->GetImageScale());

}
