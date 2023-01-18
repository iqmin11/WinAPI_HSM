#include "RPGOlive.h"
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEnginePlatform/GameEngineWindow.h>

RPGOlive* RPGOlive::MainPlayer;

RPGOlive::RPGOlive()
{

}

RPGOlive::~RPGOlive()
{

}

void RPGOlive::Start()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
	MainPlayer = this;
	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove", 'W');
	}

	AnimationRender = CreateRender(1);
	AnimationRender->SetScale({ 40,60 });

	AnimationRender->CreateAnimation({ .AnimationName = "Down_Move",  .ImageName = "Olive.bmp", .Start = 0, .End = 1, .InterTime = 0.2f });
	AnimationRender->CreateAnimation({ .AnimationName = "Down_Idle",  .ImageName = "Olive.bmp", .Start = 0, .End = 0, .InterTime = 0.2f });

	AnimationRender->CreateAnimation({ .AnimationName = "Up_Move",  .ImageName = "Olive.bmp", .Start = 2, .End = 3, .InterTime = 0.2f });
	AnimationRender->CreateAnimation({ .AnimationName = "Up_Idle",  .ImageName = "Olive.bmp", .Start = 2, .End = 2, .InterTime = 0.2f });

	AnimationRender->CreateAnimation({ .AnimationName = "Left_Move",  .ImageName = "Olive.bmp", .Start = 4, .End = 5, .InterTime = 0.2f });
	AnimationRender->CreateAnimation({ .AnimationName = "Left_Idle",  .ImageName = "Olive.bmp", .Start = 4, .End = 4, .InterTime = 0.2f });

	AnimationRender->CreateAnimation({ .AnimationName = "Right_Move",  .ImageName = "Olive.bmp", .Start = 6, .End = 7, .InterTime = 0.2f });
	AnimationRender->CreateAnimation({ .AnimationName = "Right_Idle",  .ImageName = "Olive.bmp", .Start = 6, .End = 6, .InterTime = 0.2f });

	ChangeState(PlayerState::IDLE);
}

void RPGOlive::Update(float _DeltaTime)
{
	DirCheck();
	UpdateState(_DeltaTime);

}

void RPGOlive::Render(float _Time)
{
}




void RPGOlive::DirCheck()
{
	if (GameEngineInput::IsPress("LeftMove"))
	{
		DirString = "Left_";
	}
	else if (GameEngineInput::IsPress("RightMove"))
	{
		DirString = "Right_";
	}
	else if (GameEngineInput::IsPress("UpMove"))
	{
		DirString = "Up_";
	}
	else if (GameEngineInput::IsPress("DownMove"))
	{
		DirString = "Down_";
	}
}

void RPGOlive::ChangeState(PlayerState _State)
{
	PlayerState NextState = _State;
	PlayerState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case PlayerState::IDLE:
		IdleStart();
		break;

	case PlayerState::MOVE:
		MoveStart();
		break;
	
	default:
		break;
	}
}

void RPGOlive::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case PlayerState::IDLE:
		IdleUpdate(_Time);
		break;

	case PlayerState::MOVE:
		MoveUpdate(_Time);
		break;

	default:
		break;
	}
}

void RPGOlive::IdleStart()
{
	AnimationRender->ChangeAnimation(DirString + "Idle");
}

void RPGOlive::IdleUpdate(float _DeltaTime)
{
	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove") || GameEngineInput::IsPress("UpMove") || GameEngineInput::IsPress("DownMove"))
	{
		ChangeState(PlayerState::MOVE);
		return;
	}
}

void RPGOlive::IdleEnd()
{
}

void RPGOlive::MoveStart()
{
	AnimationRender->ChangeAnimation(DirString + "Move");
}

void RPGOlive::MoveUpdate(float _DeltaTime)
{
	if (false == GameEngineInput::IsPress("LeftMove") &&
		false == GameEngineInput::IsPress("RightMove")&&
		false == GameEngineInput::IsPress("UpMove")&&
		false == GameEngineInput::IsPress("DownMove"))
	{
		ChangeState(PlayerState::IDLE);
		return;
	}

	if (GameEngineInput::IsPress("LeftMove"))
	{
		SetMove(float4::Left * MoveSpeed * _DeltaTime);
	}
	if (GameEngineInput::IsPress("RightMove"))
	{
		SetMove(float4::Right * MoveSpeed * _DeltaTime);
	}
	if (GameEngineInput::IsPress("UpMove"))
	{
		SetMove(float4::Up * MoveSpeed * _DeltaTime);
	}
	if (GameEngineInput::IsPress("DownMove"))
	{
		SetMove(float4::Down * MoveSpeed * _DeltaTime);
	}
}

void RPGOlive::MoveEnd()
{
}
