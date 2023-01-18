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
	//AnimationRender->CreateAnimation({ .AnimationName = "Success_clean", .ImageName = "PartTimeJobAnimation.bmp", .Start = 0, .End = 3 });
	//AnimationRender->CreateAnimation({ .AnimationName = "Fail_clean", .ImageName = "PartTimeJobAnimation.bmp", .Start = 4, .End = 5 });
	//AnimationRender->CreateAnimation({ .AnimationName = "Success_HouseKeeping", .ImageName = "PartTimeJobAnimation.bmp", .Start = 7, .End = 9 });
	//AnimationRender->CreateAnimation({ .AnimationName = "Fail_HouseKeeping", .ImageName = "PartTimeJobAnimation.bmp", .Start = 10, .End = 14 });
}

void Animation::Update(float _DeltaTime)
{
	//SetMove(float4::Left * 0.01f);
}

void Animation::Render(float _Time)
{
	//float4 ImagePos = GetPos();
	//GameEngineImage* Image = GameEngineResources::GetInst().ImageFind("PartTimeJobAnimation.bmp");
	//GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, ImagePos + float4{ 0,0 }, Image->GetImageScale(), { 0,0 }, Image->GetImageScale());
	//GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, ImagePos + float4{ 0,0 }, { 50, 100 }, { 50,0 }, {50,100}/*좌표가 아니라 시작위치부터 사이즈*/, RGB(0, 204, 0));
	//GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, 13, ImagePos, { 50, 100 }/*좌표가 아니라 시작위치부터 사이즈*/, RGB(0, 204, 0));
}
