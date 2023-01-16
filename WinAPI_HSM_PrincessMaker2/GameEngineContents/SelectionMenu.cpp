#include "SelectionMenu.h"
#include <vector>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

SelectionMenu::SelectionMenu()
{

}

SelectionMenu::~SelectionMenu()
{

}

void SelectionMenu::Start()
{
	CreateMenuFrame(GameEngineWindow::GetScreenSize().half(), { 13,8 }, 0);
	MenuFrameRender(1);
}

void SelectionMenu::Update(float _Deltatime)
{
}

void SelectionMenu::Render(float _Time)
{
}
