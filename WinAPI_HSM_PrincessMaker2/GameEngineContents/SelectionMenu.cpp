#include "SelectionMenu.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEngineCore/GameEngineCollision.h>

SelectionMenu::SelectionMenu()
{

}

SelectionMenu::~SelectionMenu()
{

}

void SelectionMenu::SetButton(int _Count, int _Order)
{
	CountButton = _Count;
	HilightButton.resize(_Count);

	for (int i = 0; i < HilightButton.size(); i++)
	{
		HilightButton[i] = CreateRender("SelectionHilight.bmp", _Order);
		HilightButton[i]->SetScale(float4{ GetMenuFrameSize().x - 10, 25.0f });
		HilightButton[i]->SetMove((float4::Up * GetMenuFrameSize().half() + float4{ 0, 30.0f }));
		HilightButton[i]->SetMove(float4{ 0, 25.0f * static_cast<float>(i) });
		HilightButton[i]->Off();
	}

	ButtonCollisions.resize(_Count);

	for (int i = 0; i < ButtonCollisions.size(); i++)
	{
		ButtonCollisions[i] = CreateCollision(_Order + 1);
		ButtonCollisions[i]->SetScale(float4{ GetMenuFrameSize().x - 10, 25.0f });
		ButtonCollisions[i]->SetMove((float4::Up * GetMenuFrameSize().half() + float4{ 0, 30.0f }));
		ButtonCollisions[i]->SetMove(float4{ 0, 25.0f * static_cast<float>(i) });
	}

	IsMouseCollisions.resize(_Count);
}

void SelectionMenu::SetButton(int _Count, PM2RenderOrder _Order)
{
	SetButton(_Count, static_cast<int>(_Order));
}

void SelectionMenu::Start()
{
	//사용법 예시
	//InitMenuFrameRender(0, PM2RenderOrder::Menu0);
	//SetMenuFrameScale({ 230,112 });
	//SetPos({ GameEngineWindow::GetScreenSize().half() });
	//SetButton(3,PM2RenderOrder::Menu0_Button);
}

void SelectionMenu::Update(float _Deltatime)
{
	for (size_t i = 0; i < ButtonCollisions.size(); i++)
	{
		if (true == ButtonCollisions[i]->Collision({ .TargetGroup = static_cast<int>(PM2CollisionOrder::MousePoint), .TargetColType = CT_Point, .ThisColType = CT_Rect }))
		{
			HilightButton[i]->On();
			IsMouseCollisions[i] = true;
		}
		else
		{
			HilightButton[i]->Off();
			IsMouseCollisions[i] = false;
		}
	}
}

void SelectionMenu::Render(float _Time)
{

}

