#include "Olive.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineBase/GameEnginePath.h>
#include <GameEngineCore/GameEngineResources.h>
#include <GameEngineCore/GameEngineRender.h>

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

	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove", 'W');
	}

	SetPos(GameEngineWindow::GetScreenSize().half());
	GameEngineRender* BodyRender = CreateRender("body_10_nomal.BMP", 1); 
	SetMove(float4::Down * ((GameEngineWindow::GetScreenSize().half()) - (BodyRender->GetImage()->GetImageScale().half())));
	GameEngineRender* HeadRender = CreateRender("head_10_nomal.BMP", 1);
	HeadRender->SetPosition(float4::Up * ((BodyRender->GetImage()->GetImageScale().half()) + (HeadRender->GetImage()->GetImageScale().half())));
	
}

void Olive::Update(float _DeltaTime)
{
	if (true == GameEngineInput::IsPress("LeftMove"))
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
	}
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
