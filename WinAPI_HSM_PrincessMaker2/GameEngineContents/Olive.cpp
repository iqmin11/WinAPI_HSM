#include "Olive.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>

Olive::Olive()
{

}

Olive::~Olive()
{

}

void Olive::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	GameEngineRender* BodyRender = CreateRender("body_10_nomal.BMP", 1); // 나중에 문제가 있을수도 있음 생각하기(첫 랜더때 이미지가 엉뚱한 위치에 있을 수 있음)
	SetMove(float4::Down * ((GameEngineWindow::GetScreenSize().half()) - (BodyRender->GetImage()->GetImageScale().half())));
	GameEngineRender* HeadRender = CreateRender("head_10_nomal.BMP", 2);
	HeadRender->SetPosition(float4::Up * ((BodyRender->GetImage()->GetImageScale().half()) + (HeadRender->GetImage()->GetImageScale().half())));
	
}

void Olive::Update(float _Deltatime)
{
	//SetMove(float4::Left * 0.01f);
}

void Olive::Render(float _Time)
{
	//float4 BodyPos = GetPos();
	//GameEngineImage* BodyImage = GameEngineResources::GetInst().ImageFind("body_10_nomal.bmp");
	//GameEngineImage* HeadImage = GameEngineResources::GetInst().ImageFind("head_10_nomal.bmp");
	//float4 HeadPos = GetPos() - float4{0,BodyImage->GetImageScale().y};
	//GameEngineWindow::GetDoubleBufferImage()->TransCopy(HeadImage, HeadPos + float4{ 0,-14 }, HeadImage->GetImageScale(), { 0,0 }, HeadImage->GetImageScale());
	//GameEngineWindow::GetDoubleBufferImage()->TransCopy(BodyImage, BodyPos + float4{ 0,0 }, BodyImage->GetImageScale(), { 0,0 }, BodyImage->GetImageScale());

}
