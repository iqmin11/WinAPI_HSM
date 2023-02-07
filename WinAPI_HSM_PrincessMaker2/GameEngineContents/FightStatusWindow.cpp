#include "FightStatusWindow.h"
#include <GameEnginePlatform/GameEngineWindow.h>

FightStatusWindow::FightStatusWindow()
{

}

FightStatusWindow::~FightStatusWindow()
{

}

void FightStatusWindow::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	SetStatusCount(6);
	SetStatusFrameRender(PM2RenderOrder::Menu1_StatusGauge);
	SetPos((float4::Down * GameEngineWindow::GetScreenSize().half()) + float4{ 0, 155 } + (float4::Right * GetMenuFrameScale().half()) + float4{ 10, 0 });
}
