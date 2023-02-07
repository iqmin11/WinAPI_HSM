#include "Button.h"
#include <GameEnginePlatform/GameEngineInput.h>

Button::Button()
{
}

Button::~Button()
{
}

void Button::SetImage(const std::string_view& _IdleImage, const std::string_view& _CollisionImage, int _RenderOrder)
{
	Render_State_Idle->SetImage(_IdleImage);
	Render_State_Idle->SetOrder(_RenderOrder);
	Render_State_Collision->SetImage(_IdleImage);
	Render_State_Collision->SetOrder(_RenderOrder);
	Render_State_Collision->Off();
}

void Button::SetScale(const float4& _Scale)
{
	Render_State_Idle->SetScale(_Scale);
	Render_State_Collision->SetScale(_Scale);
	ButtonCollision->SetScale(_Scale);
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
	Render_State_Idle = CreateRender();
	Render_State_Collision = CreateRender();
}

//void Button::SetFunction()
//{
//	//int TargetGroup = -342367842;
//	//CollisionType TargetColType = CollisionType::CT_CirCle;
//	//CollisionType ThisColType = CollisionType::CT_CirCle;
//
//	if (true == ButtonCollision->Collision({ .TargetGroup = PointTargetGroup, .TargetColType = CollisionType::CT_Point, .ThisColType = ButtonCollisionType }))
//	{
//		if (true == GameEngineInput::IsDown("EngineMouseLeft") && nullptr != ClickPtr)
//		{
//			ClickPtr();
//		}
//	}
//}