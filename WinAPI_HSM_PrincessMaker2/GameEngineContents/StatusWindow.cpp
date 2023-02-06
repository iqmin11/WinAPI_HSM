#include "StatusWindow.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

StatusWindow::StatusWindow()
{

}

StatusWindow::~StatusWindow()
{

}

void StatusWindow::SetStatusCount(int _Count)
{
	StatusCount = _Count;
}

void StatusWindow::SetStatusFrameRender(int _Order)
{
	StatusGaugeFrameRender.resize(StatusCount);
	SetMenuFrameScale({220.0f + 20.0f,(static_cast<float>(StatusCount)*20.0f)+20.0f});
	for (size_t i = 0; i < StatusGaugeFrameRender.size(); i++)
	{
		StatusGaugeFrameRender[i] = CreateRender("StatusGaugeFrame.bmp", _Order);
		StatusGaugeFrameRender[i]->SetPosition(float4::Up * (StatusGaugeFrameRender[i]->GetScale().half())*static_cast<float>(StatusGaugeFrameRender.size() - 1) + float4::Down * (StatusGaugeFrameRender[i]->GetScale()) * static_cast<float>(i));
	}

	StatusGaugeRender.resize(StatusCount);
	for (size_t i = 0; i < StatusGaugeRender.size(); i++)
	{
		StatusGaugeRender[i] = CreateRender("StatusGauge.bmp", _Order);
		StatusGaugeRender[i]->SetPosition(StatusGaugeFrameRender[i]->GetPosition() + float4{-1.0, -1.0});
	}
}

void StatusWindow::SetStatusFrameRender(PM2RenderOrder _Order)
{
	SetStatusFrameRender(static_cast<int>(_Order));
}

void StatusWindow::Start()
{
	//사용법 예시
	SetPos(GameEngineWindow::GetScreenSize().half());
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	SetStatusCount(3);
	SetStatusFrameRender(PM2RenderOrder::Menu1_StatusGauge); // 이단계에서 이미지 편집이 필요
	StatusGaugeRender[1]->Off();
}
