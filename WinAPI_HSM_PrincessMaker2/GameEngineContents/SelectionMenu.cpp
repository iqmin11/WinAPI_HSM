#include "SelectionMenu.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>


SelectionMenu::SelectionMenu()
{

}

SelectionMenu::~SelectionMenu()
{

}

void SelectionMenu::SetSelectionMenu(int _Count, float4 _Pos, float _xScale, int _ActorOrder, int _RenderOrder) // 이순간 세로크기는 정해지게
{
	CountButton = _Count;
	SetMenuFrameScale({ _xScale, (static_cast<float>(CountButton) * 24.0f) + 40.0f });
	SetPos(_Pos);
	SelectButtons.resize(CountButton);
	GameEngineLevel* Level = GetLevel();
	for (size_t i = 0; i < SelectButtons.size(); i++)
	{
		SelectButtons[i] = Level->CreateActor<Button>(_ActorOrder);
		SelectButtons[i]->SetPos(float4{ _Pos.x, _Pos.y - 13.0f * (SelectButtons.size() - 1) } + float4{ 0, 26.0f * static_cast<float>(i) });
		SelectButtons[i]->SetReleaseImage("SelectButton_Release.bmp");
		SelectButtons[i]->SetHoverImage("SelectButton_Hover.bmp");
		SelectButtons[i]->SetPressImage("SelectButton_Hover.bmp");
		SelectButtons[i]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
		SelectButtons[i]->SetScale({ _xScale - 10, 26.0f });
		SelectButtons[i]->SetRenderOrder(_RenderOrder);
	}
}

void SelectionMenu::SetSelectionMenu(int _Count, float4 _Pos, float _xScale, PM2ActorOrder _ButtonActorOrder, PM2RenderOrder _ButtonRenderOrder)
{
	SetSelectionMenu(_Count, _Pos, _xScale, static_cast<int>(_ButtonActorOrder), static_cast<int>(_ButtonRenderOrder));
}

void SelectionMenu::Start()
{
	//사용법 예시
	//InitMenuFrameRender(PM2RenderOrder::Menu0, 0);
	//SetSelectionMenu(3, GameEngineWindow::GetScreenSize().half(), 230.0f, PM2ActorOrder::Menu0_Button, PM2RenderOrder::Menu0_Button);
}

void SelectionMenu::Update(float _Deltatime)
{
	
}

void SelectionMenu::Render(float _Time)
{

}

