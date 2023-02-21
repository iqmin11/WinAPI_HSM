#include "MainMenu.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRender.h>

#include "GlobalButton.h"
#include "ContentsEnums.h"

MainMenu::MainMenu()
{

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
	SetPos(ActorPos);
	MainMenuRender = CreateRender("MainMenu.bmp", PM2RenderOrder::Menu0);
	MainMenuRender->SetScaleToImage();
	SetMainMenuButtons();
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



