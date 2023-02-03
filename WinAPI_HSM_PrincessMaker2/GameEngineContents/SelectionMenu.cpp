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

void SelectionMenu::SetSelectionMenu(const float4& _pos, const float4& _Size, const int _style, int _Count)
{
	SetMenuFrame(_pos, _Size, _style);
	CountSelection = _Count;
}

void SelectionMenu::CreateSelectionMenu(int _Order)
{
	MenuFrameRender(_Order);
	CreateSelectionRender(_Order + 1);
	CreateSelectionCollision();
	
}

void SelectionMenu::CreateSelectionMenu(PM2RenderOrder _Order)
{
	CreateSelectionMenu(static_cast<int>(_Order));
}



void SelectionMenu::Start()
{
	
}

void SelectionMenu::Update(float _Deltatime)
{
	std::vector<GameEngineCollision*> Collision;
	for (size_t i = 0; i < CountSelection; i++)
	{
		if (nullptr != SelectionCollision[i])
		{
			if (true == SelectionCollision[i]->Collision({ .TargetGroup = static_cast<int>(PM2CollisionOrder::MousePoint), .TargetColType = CT_Point, .ThisColType = CT_Rect }, Collision))
			{
				HilightSelection[i]->On();
			}
			else
			{
				HilightSelection[i]->Off();
			}
		}
	}
	
}

void SelectionMenu::Render(float _Time)
{
	//HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	//float4 ActorPos = GetPos();

	//Rectangle(DoubleDC,
	//	ActorPos.ix() - 8,
	//	ActorPos.iy() - 8,
	//	ActorPos.ix() + 8,
	//	ActorPos.iy() + 8
	//); // µð¹ö±ë¿ë
}

void SelectionMenu::CreateSelectionRender(int _Order)
{
	HilightSelection.resize(CountSelection);

	for (int i = 0; i < HilightSelection.size(); i++)
	{
		HilightSelection[i] = CreateRender("SelectionHilight.bmp", _Order);
		HilightSelection[i]->SetScale(float4{ GetMenuFrameSize().x - 10, 25.0f});
		HilightSelection[i]->SetMove((float4::Up * GetMenuFrameSize().half() + float4{0, 30.0f}));
		HilightSelection[i]->SetMove(float4{ 0, 25.0f * static_cast<float>(i) });
		HilightSelection[i]->Off();
	}
}

void SelectionMenu::CreateSelectionCollision()
{
	SelectionCollision.resize(CountSelection);

	for (int i = 0; i < SelectionCollision.size(); i++)
	{
		SelectionCollision[i] = CreateCollision(PM2CollisionOrder::Selection);
		SelectionCollision[i]->SetScale(float4{ GetMenuFrameSize().x - 10, 25.0f });
		SelectionCollision[i]->SetMove((float4::Up * GetMenuFrameSize().half() + float4{ 0, 30.0f }));
		SelectionCollision[i]->SetMove(float4{ 0, 25.0f * static_cast<float>(i) });
	}
}


