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
	InitMenuFrameRender(PM2RenderOrder::Menu0, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(3, { 400,250 }, 230.0f, PM2ActorOrder::Menu0_Button, PM2RenderOrder::Menu0_Button);
	GetSelectButtons()[0]->SetClickCallBack(LevelChangeToFirstSet);
	GetSelectButtons()[1]->SetClickCallBack(LevelChangeToOpening);
	GetSelectButtons()[2]->SetClickCallBack(LevelChangeToRaisingSim);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 0, "FirstSet으로");		     //Test
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 1, "Opening으로");			//Test
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 2, "RaisingSim으로");	     //Test
	//SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 0, "처음부터 시작");
	//SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 1, "처음부터 (오프닝 스킵)");
	//SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 2, "시간을 되돌린다");
}


