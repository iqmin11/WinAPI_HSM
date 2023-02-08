#include "FemininityStatusWindow.h"
#include <GameEnginePlatform/GameEngineWindow.h>

FemininityStatusWindow::FemininityStatusWindow()
{

}

FemininityStatusWindow::~FemininityStatusWindow()
{

}

void FemininityStatusWindow::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	SetStatusCount(6);
	SetStatusFrameRender(PM2RenderOrder::Menu1_StatusGauge);

	SetPos(float4{ GameEngineWindow::GetScreenSize().x , 0 } + (float4::Left * (GetMenuFrameScale().half())) + float4{ -10,0 } + (float4::Down * GameEngineWindow::GetScreenSize().half()) + float4{ 0, 155 });
}
