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
	St = GaugeFrameStyle::Nomal;
	InsertStatus(StatusName::체력, 999, St);
	InsertStatus(StatusName::근력, 100, St);
	InsertStatus(StatusName::지능, 100, St);
	InsertStatus(StatusName::기품, 100, St);
	InsertStatus(StatusName::색기, 100, St);
	InsertStatus(StatusName::도덕성, 100, St);
	InsertStatus(StatusName::신앙, 100, St);
	InsertStatus(StatusName::업보, 100, St);
	InsertStatus(StatusName::감수성, 100, St);
	InsertStatus(StatusName::스트레스, 100, St);
	SetPos((float4::Down * GameEngineWindow::GetScreenSize().half()) + float4{0,-40} + (float4::Right * GetMenuFrameScale().half()) + float4{ 10, 0 });

	Off();
}
