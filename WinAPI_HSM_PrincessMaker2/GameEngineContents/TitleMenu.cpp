#include "TitleMenu.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineCore.h>

TitleMenu::TitleMenu()
{

}

TitleMenu::~TitleMenu()
{

}

void TitleMenu::LevelChangeToFirstSet(Button* _Btn)
{
	GameEngineCore::GetInst()->ChangeLevel("FirstSet");
}

void TitleMenu::LevelChangeToOpening(Button* _Btn)
{
	GameEngineCore::GetInst()->ChangeLevel("Opening");
}

void TitleMenu::LevelChangeToRaisingSim(Button* _Btn)
{
	GameEngineCore::GetInst()->ChangeLevel("RaisingSim");
}

void TitleMenu::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu0, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(3, { 400,250 }, 230.0f, PM2ActorOrder::Menu0_Button, PM2RenderOrder::Menu0_Button);
	GetSelectButtons()[0]->SetClickCallBack(LevelChangeToFirstSet);
	//GetSelectButtons()[1]->SetClickCallBack(LevelChangeToOpening);
	//GetSelectButtons()[2]->SetClickCallBack(LevelChangeToRaisingSim);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 0, "세팅 레벨로");		     //Test
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 1, "(비활성화)오프닝 레벨로");			//Test
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 2, "(비활성화)키우기 레벨로");	     //Test
	//SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 0, "처음부터 시작");
	//SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 1, "처음부터 (오프닝 스킵)");
	//SetButtonString(static_cast<int>(PM2RenderOrder::Menu0_Display), 2, "시간을 되돌린다");
}


