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
	SetStatusCount(10);
	SetStatusFrameRender(PM2RenderOrder::Menu1_StatusGauge);
	SetPos((float4::Down * GameEngineWindow::GetScreenSize().half()) + float4{0,-40} + (float4::Right * GetMenuFrameScale().half()) + float4{ 10, 0 });
}
