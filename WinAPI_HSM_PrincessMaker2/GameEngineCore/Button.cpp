#include "Button.h"
#include <GameEnginePlatform/GameEngineInput.h>

Button::Button()
{
	State = ButtonState::Release;
}

Button::~Button()
{
}


void Button::SetTargetCollisionGroup(int _PointTargetGroup)
{
	PointTargetGroup = _PointTargetGroup;
	if (nullptr == ButtonCollision)
	{
		ButtonCollision = CreateCollision(PointTargetGroup);
	}
}


void Button::Start()
{
	ButtonRender = CreateRender();
	ButtonCollision = CreateCollision();
}

void Button::SetRenderOrder(int _Value)
{
	ButtonRender->SetOrder(_Value);
}

void Button::SetScale(float4 _Scale)
{
	Scale = _Scale;
	ButtonCollision->SetScale(Scale);
}

void Button::SetCollisionOrder(int _Order)
{
	ButtonCollision->SetOrder(_Order);
}


GameEngineCollision* CurCollision;


void Button::Off()
{
	GameEngineActor::Off();

	if (CurCollision == ButtonCollision)
	{
		CurCollision = nullptr;
	}
}

void Button::Update(float _DeltaTime)
{
	State = ButtonState::Release;

	if (true == ButtonCollision->Collision({ .TargetGroup = PointTargetGroup, .TargetColType = CollisionType::CT_Point, .ThisColType = ButtonCollisionType }))
	{
		if (true == GameEngineInput::IsPress("EngineMouseLeft") && nullptr != CurCollision)
		{
			State = ButtonState::Press;
		}
		else if (true == GameEngineInput::IsUp("EngineMouseLeft") && nullptr != ClickPtr && ButtonCollision == CurCollision)
		{
			CurCollision = nullptr;
			ClickPtr(this);
		}
		else if (true == GameEngineInput::IsFree("EngineMouseLeft") && nullptr == CurCollision || ButtonCollision == CurCollision)
		{
			CurCollision = ButtonCollision;
			State = ButtonState::Hover;
		}
	}
	else 
	{
		if (CurCollision == ButtonCollision)
		{
			CurCollision = nullptr;
		}
	}

	switch (State)
	{
	case ButtonState::Release:
		CurImageName = ReleaseImageName;
		ButtonRender->SetImage(ReleaseImageName);
		if (-1 != ReleaseIndex)
		{
			ButtonRender->SetFrame(ReleaseIndex);
		}
		ButtonRender->SetScale(Scale);
		break;
	case ButtonState::Press:
		CurImageName = PressImageName;
		ButtonRender->SetImage(PressImageName);
		if (-1 != PressIndex)
		{
			ButtonRender->SetFrame(PressIndex);
		}
		ButtonRender->SetScale(Scale);
		break;
	case ButtonState::Hover:
		CurImageName = HoverImageName;
		ButtonRender->SetImage(HoverImageName);
		if (-1 != HoverIndex)
		{
			ButtonRender->SetFrame(HoverIndex);
		}
		ButtonRender->SetScale(Scale);
		break;
	default:
		break;
	}
}

void Button::LevelChangeEnd(GameEngineLevel* _Level)
{
}