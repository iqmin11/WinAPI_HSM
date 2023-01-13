#include "Olive.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>

Olive::Olive()
{

}

Olive::~Olive()
{

}

void Olive::Start()
{
	//SetPos({145, 307});
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
