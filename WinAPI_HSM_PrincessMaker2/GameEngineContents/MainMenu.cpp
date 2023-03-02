#include "MainMenu.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>

#include "GlobalButton.h"
#include "ContentsEnums.h"

#include "StatusWindowManager.h"
#include "RaisingSimLevel.h"
#include "UIManager.h"
#include "ConverstionSelectionMenu.h"
#include "DietSelectionMenu.h"
#include "InformationWindowManager.h"

#include "ScheduleCalendar.h"
#include "ScheduleSelectionMenu.h"

MainMenu* MainMenu::AcMainMenu = nullptr;
StatusWindowManager* MainMenu::AcStatusWindowManager = nullptr;
ConverstionSelectionMenu* MainMenu::AcConverstionSelectionMenu = nullptr;
DietSelectionMenu* MainMenu::AcDietSelectionMenu = nullptr;
InformationWindowManager* MainMenu::AcInformationWindowManager = nullptr;

ScheduleCalendar* MainMenu::AcScheduleCalendar = nullptr;
ScheduleSelectionMenu* MainMenu::AcScheduleSelectionMenu = nullptr;

MainMenu::MainMenu()
{
	AcMainMenu = this;
}

MainMenu::~MainMenu()
{

}
std::vector<std::vector<GlobalButton*>> MainMenu::GetMainMenuButton()
{
	return MainMenuButtons;
}

void MainMenu::On()
{
	GameEngineObject::On();
	for (size_t y = 0; y < MainMenuButtons.size(); y++)
	{
		for (size_t x = 0; x < MainMenuButtons[y].size(); x++)
		{
			MainMenuButtons[y][x]->On();
		}
	}
	ScheduleButton->On();
}

void MainMenu::Off()
{
	GameEngineObject::Off();
	for (size_t y = 0; y < MainMenuButtons.size(); y++)
	{
		for (size_t x = 0; x < MainMenuButtons[y].size(); x++)
		{
			MainMenuButtons[y][x]->Off();
		}
	}
	ScheduleButton->Off();
}

void MainMenu::Start()
{
	GameEngineLevel* Level = GetLevel();
	SetPos(ActorPos);
	MainMenuRender = CreateRender("MainMenu.bmp", PM2RenderOrder::Menu0);
	MainMenuRender->SetScaleToImage();
	SetMainMenuButtons();

	AcStatusWindowManager = Level->CreateActor<StatusWindowManager>(PM2ActorOrder::Menu1);
	AcConverstionSelectionMenu = Level->CreateActor<ConverstionSelectionMenu>(PM2ActorOrder::Menu1);
	AcDietSelectionMenu = Level->CreateActor<DietSelectionMenu>(PM2ActorOrder::Menu1);
	AcInformationWindowManager = Level->CreateActor<InformationWindowManager>(PM2ActorOrder::Menu1);
	
	AcScheduleCalendar = Level->CreateActor<ScheduleCalendar>(PM2ActorOrder::Menu1);
	AcScheduleSelectionMenu = Level->CreateActor<ScheduleSelectionMenu>(PM2ActorOrder::Menu1);
	SetClickButton();
}

void MainMenu::Update(float _DeltaTime)
{
	
}

void MainMenu::Render(float _Time)
{
}

void MainMenu::SetMainMenuButtons()
{
	GameEngineLevel* Level = GetLevel();
	MainMenuButtons.resize(2);
	for (size_t x = 0; x < MainMenuButtons.size(); x++)
	{
		MainMenuButtons[x].resize(4);
	}


	for (size_t y = 0; y < MainMenuButtons.size(); y++)
	{
		for (size_t x = 0; x < MainMenuButtons[y].size(); x++)
		{
			MainMenuButtons[y][x] = Level->CreateActor<GlobalButton>(PM2ActorOrder::Menu0_Button);
			MainMenuButtons[y][x]->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
			MainMenuButtons[y][x]->SetScale(MainMenuButtonScale);
			MainMenuButtons[y][x]->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
			MainMenuButtons[y][x]->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
			MainMenuButtons[y][x]->SetReleaseImage("SelectButton_Release.bmp");
			MainMenuButtons[y][x]->SetHoverImage("MainMenu_Buttons.bmp", static_cast<int>(x + 4 * y));
			MainMenuButtons[y][x]->SetPressImage("MainMenu_Buttons.bmp", static_cast<int>(x + 4 * y));
			MainMenuButtons[y][x]->SetPos(ActorPos + (FirstButtonSetPos + MainMenuButtonScale * float4{ static_cast<float>(x),static_cast<float>(y) }));
		}
	}

	ScheduleButton = Level->CreateActor<GlobalButton>(PM2ActorOrder::Menu0_Button);
	ScheduleButton->SetTargetCollisionGroup(static_cast<int>(PM2CollisionOrder::MousePoint));
	ScheduleButton->SetScale(ScheduleButtonScale);
	ScheduleButton->SetRenderOrder(static_cast<int>(PM2RenderOrder::Menu0_Button));
	ScheduleButton->SetCollisionOrder(static_cast<int>(PM2ActorOrder::Menu0_Button));
	ScheduleButton->SetReleaseImage("SelectButton_Release.bmp");
	ScheduleButton->SetHoverImage("MainMenu_Schedule.bmp");
	ScheduleButton->SetPressImage("MainMenu_Schedule.bmp");
	ScheduleButton->SetPos(ActorPos + ScheduleButtonPos);
}

void MainMenu::SetClickButton()
{
	MainMenuButtons[0][0]->SetClickCallBack(ClickMainMenu_00);
	MainMenuButtons[0][1]->SetClickCallBack(ClickMainMenu_01);
	MainMenuButtons[0][2]->SetClickCallBack(ClickMainMenu_02);
	MainMenuButtons[0][3]->SetClickCallBack(ClickMainMenu_03);

	ScheduleButton->SetClickCallBack(ClickMainMenu_S);
}

void MainMenu::ClickMainMenu_00(Button* _Btn)
{
	AcStatusWindowManager->On();
	AcMainMenu->Off();
}

void MainMenu::ClickMainMenu_01(Button* _Btn)
{
	AcConverstionSelectionMenu->On();
	AcMainMenu->Off();
}

void MainMenu::ClickMainMenu_02(Button* _Btn)
{
	AcDietSelectionMenu->On();
	AcMainMenu->Off();
}

void MainMenu::ClickMainMenu_03(Button* _Btn)
{
	AcInformationWindowManager->On();
	AcMainMenu->Off();
}

void MainMenu::ClickMainMenu_S(Button* _Btn)
{
	AcScheduleCalendar->On();
	AcScheduleSelectionMenu->On();
	AcMainMenu->Off();
}



