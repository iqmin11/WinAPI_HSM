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
	CreateMenuFrame(GameEngineWindow::GetScreenSize().half(), { 14,7 }, 0);
	MenuFrameRender(1);
}

void SelectionMenu::Update(float _Deltatime)
{
}

void SelectionMenu::Render(float _Time)
{
	HDC DoubleDC = GameEngineWindow::GetDoubleBufferImage()->GetImageDC();
	float4 ActorPos = GetPos();

	Rectangle(DoubleDC,
		ActorPos.ix() - 8,
		ActorPos.iy() - 8,
		ActorPos.ix() + 8,
		ActorPos.iy() + 8
	); // µð¹ö±ë¿ë
}
