#include "Dialog.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include "ContentsEnums.h"

Dialog::Dialog()
{

}

Dialog::~Dialog()
{

}

void Dialog::Start()
{
	CreateMenuFrame(GameEngineWindow::GetScreenSize().half(), { 27,9 });
	MenuFrameRender(PM2RenderOrder::Menu);
}

void Dialog::Update(float _DeltaTime)
{

}

void Dialog::Render(float _Time)
{

}
