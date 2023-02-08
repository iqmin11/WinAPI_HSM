#include "EstimateStatusWindow.h"
#include <GameEnginePlatform/GameEngineWindow.h>

EstimateStatusWindow::EstimateStatusWindow()
{

}

EstimateStatusWindow::~EstimateStatusWindow()
{

}

void EstimateStatusWindow::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	SetStatusCount(4);
	SetStatusFrameRender(PM2RenderOrder::Menu1_StatusGauge);
	SetPos(float4{ GameEngineWindow::GetScreenSize().x , GameEngineWindow::GetScreenSize().hy() } + (float4::Left * (GetMenuFrameScale().half())) + float4{ -10,0 } + float4{ 0,20 });
}
