#include "MainMenu.h"
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
}

void MainMenu::Update(float _DeltaTime)
{
}

void MainMenu::Render(float _Time)
{
}
