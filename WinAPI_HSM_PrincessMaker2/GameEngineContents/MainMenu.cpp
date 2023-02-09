#include "MainMenu.h"
#include <GameEngineCore/GameEngineRender.h>

#include "ContentsEnums.h"

MainMenu::MainMenu()
{

}

MainMenu::~MainMenu()
{

}

void MainMenu::Start()
{
	SetPos({700,278});
	MainMenuRender = CreateRender("MainMenu.bmp", PM2RenderOrder::Menu0);
	MainMenuRender->SetScaleToImage();
}

void MainMenu::Update(float _DeltaTime)
{
}

void MainMenu::Render(float _Time)
{
}
