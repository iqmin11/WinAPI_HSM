#include "ConverstionSelectionMenu.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "MainMenu.h"

ConverstionSelectionMenu::ConverstionSelectionMenu()
{

}

ConverstionSelectionMenu::~ConverstionSelectionMenu()
{

}

void ConverstionSelectionMenu::Start()
{
	AcMainMenu = MainMenu::GetAcMainMenu();
	
	InitMenuFrameRender(PM2RenderOrder::Menu0, MenuFrameStyleEnum::Gold);
	SetSelectionMenu(3, ActorPos, Xscale, PM2ActorOrder::Menu1_Button, PM2RenderOrder::Menu0_Button);
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 0, "�γణ�� �̾߱�");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 1, "�뵷");
	SetButtonString(static_cast<int>(PM2RenderOrder::Menu1_Display), 2, "����");
	Off();
}

void ConverstionSelectionMenu::Update(float _DeltaTime)
{
	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		Off();
		AcMainMenu->On();
	}
}
