#include "BasicStatusWindow.h"
#include <GameEnginePlatform/GameEngineWindow.h>

BasicStatusWindow::BasicStatusWindow()
{

}

BasicStatusWindow::~BasicStatusWindow()
{

}

void BasicStatusWindow::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	InsertStatus(StatusName::체력, 100);
	InsertStatus(StatusName::근력, 100);
	InsertStatus(StatusName::지능, 100);
	InsertStatus(StatusName::기품, 100);
	InsertStatus(StatusName::색기, 100);
	InsertStatus(StatusName::도덕성, 100);
	InsertStatus(StatusName::신앙, 100);
	InsertStatus(StatusName::업보, 100);
	InsertStatus(StatusName::감수성, 100);
	InsertStatus(StatusName::스트레스, 100);
	SetPos((float4::Down * GameEngineWindow::GetScreenSize().half()) + float4{0,-40} + (float4::Right * GetMenuFrameScale().half()) + float4{ 10, 0 });
}
