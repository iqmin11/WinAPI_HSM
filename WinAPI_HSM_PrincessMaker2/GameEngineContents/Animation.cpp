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
	SetPos(GameEngineWindow::GetScreenSize().half());
}

void Animation::Update(float _Deltatime)
{
	//SetMove(float4::Left * 0.01f);
}

void Animation::Render(float _Deltatime)
{
	float4 ImagePos = GetPos();
	GameEngineImage* Image = GameEngineResources::GetInst().ImageFind("PartTimeJobAnimation.bmp");
	//GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, ImagePos + float4{ 0,0 }, Image->GetImageScale(), { 0,0 }, Image->GetImageScale());
	//GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, ImagePos + float4{ 0,0 }, { 50, 100 }, { 50,0 }, {50,100}/*좌표가 아니라 시작위치부터 사이즈*/, RGB(0, 204, 0));
	GameEngineWindow::GetDoubleBufferImage()->TransCopy(Image, 13, ImagePos, { 50, 100 }/*좌표가 아니라 시작위치부터 사이즈*/, RGB(0, 204, 0));
}
