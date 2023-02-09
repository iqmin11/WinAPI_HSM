#include "TitleMenu.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCore.h>

TitleMenu::TitleMenu()
{

}

TitleMenu::~TitleMenu()
{

}

void TitleMenu::LevelChangeToFirstSet()
{
	GameEngineCore::GetInst()->ChangeLevel("FirstSet");
}

void TitleMenu::LevelChangeToOpening()
{
	GameEngineCore::GetInst()->ChangeLevel("Opening");
}

void TitleMenu::LevelChangeToRaisingSim()
{
	GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
}

void TitleMenu::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu0, 0);
	SetSelectionMenu(3, GameEngineWindow::GetScreenSize().half(), 230.0f, PM2ActorOrder::Menu0_Button, PM2RenderOrder::Menu0_Button);
	GetSelectButtons()[0]->SetClickCallBack(LevelChangeToFirstSet);
	GetSelectButtons()[1]->SetClickCallBack(LevelChangeToOpening);
	GetSelectButtons()[2]->SetClickCallBack(LevelChangeToRaisingSim);
}


