#include "ConverstionSelectionMenu.h"
#include <GameEnginePlatform/GameEngineWindow.h>

ConverstionSelectionMenu::ConverstionSelectionMenu()
{

}

ConverstionSelectionMenu::~ConverstionSelectionMenu()
{

}

void ConverstionSelectionMenu::Start()
{
	//사용법 예시
	InitMenuFrameRender(PM2RenderOrder::Menu0, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(3, { 685,354 }, 170.0f, PM2ActorOrder::Menu0_Button, PM2RenderOrder::Menu0_Button);
	//GetSelectButtons()[0]->SetClickCallBack(LevelChangeToFirstSet);
	//GetSelectButtons()[1]->SetClickCallBack(LevelChangeToOpening);
	//GetSelectButtons()[2]->SetClickCallBack(LevelChangeToRaisingSim);
	//함수는 private static으로 구현
}
