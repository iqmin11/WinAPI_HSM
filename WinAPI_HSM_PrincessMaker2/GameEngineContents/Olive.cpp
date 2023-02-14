#include "Olive.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

Olive* Olive::OlivePlayer;

Olive::Olive()
{

}

Olive::~Olive()
{

}

void Olive::Start()
{
	OlivePlayer = this;

	SetPos(GameEngineWindow::GetScreenSize().half());
	BodyRender = CreateRender("body_10_nomal.BMP", PM2RenderOrder::Player); 
	BodyRender->SetScaleToImage();
	SetMove(float4::Down * ((GameEngineWindow::GetScreenSize().half()) - (BodyRender->GetImage()->GetImageScale().half())));
	HeadRender = CreateRender("head_10_nomal.BMP", PM2RenderOrder::Player);
	HeadRender->SetScaleToImage();
	HeadRender->SetPosition(float4::Up * ((BodyRender->GetImage()->GetImageScale().half()) + (HeadRender->GetImage()->GetImageScale().half())));

	Off();
}

void Olive::Update(float _DeltaTime)
{
	/*if (true == GameEngineInput::IsPress("LeftMove"))
	{
		SetMove(float4::Left * MoveSpeed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("RightMove"))
	{
		SetMove(float4::Right * MoveSpeed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("UpMove"))
	{
		SetMove(float4::Up * MoveSpeed * _DeltaTime);
	}

	if (true == GameEngineInput::IsPress("DownMove"))
	{
		SetMove(float4::Down * MoveSpeed * _DeltaTime);
	}*/
}

void Olive::Render(float _Time)
{
	/*HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos();

	Rectangle(DoubleDC,
		ActorPos.ix() - 5,
		ActorPos.iy() - 5,
		ActorPos.ix() + 5,
		ActorPos.iy() + 5
	);*/ // µð¹ö±ë¿ë
}
