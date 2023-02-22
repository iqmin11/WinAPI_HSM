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

GameEngineCollision* TestCollision = nullptr;
float DelayTime = 0.0f;

void Button::Update(float _DeltaTime)
{

	if (0.0f < DelayTime)
	{
		TestCollision = nullptr;
		DelayTime -= _DeltaTime;
		return;
	}

	if (nullptr != TestCollision && ButtonCollision != TestCollision)
	{
		return;
	}

	State = ButtonState::Release;

	if (true == ButtonCollision->Collision({ .TargetGroup = PointTargetGroup, .TargetColType = CollisionType::CT_Point, .ThisColType = ButtonCollisionType }))
	{
		if (true == GameEngineInput::IsUp("EngineMouseLeft") && nullptr != ClickPtr)
		{
			DelayTime = 0.1f;
			ClickPtr(this);
		}
		else if (true == GameEngineInput::IsFree("EngineMouseLeft"))
		{
			State = ButtonState::Hover;
		}
		else if (true == GameEngineInput::IsPress("EngineMouseLeft"))
		{
			TestCollision = ButtonCollision;
			State = ButtonState::Press;
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