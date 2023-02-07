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
	SetMenuFrameScale({220.0f + 20.0f,(static_cast<float>(StatusCount)*20.0f)+20.0f});
	StatusGaugeFrameRender_Layer1.resize(StatusCount);
	for (int i = 0; i < StatusGaugeFrameRender_Layer1.size(); i++)
	{
		StatusGaugeFrameRender_Layer1[i] = CreateRender("StatusGaugeFrame_Layer1.bmp", _Order);
		StatusGaugeFrameRender_Layer1[i]->SetPosition(float4::Up * (StatusGaugeFrameRender_Layer1[i]->GetScale().half()) * static_cast<float>(StatusGaugeFrameRender_Layer1.size() - 1) + float4::Down * (StatusGaugeFrameRender_Layer1[i]->GetScale()) * static_cast<float>(i));
	}

	StatusGaugeRender.resize(StatusCount);
	for (size_t i = 0; i < StatusGaugeRender.size(); i++)
	{
		StatusGaugeRender[i] = CreateRender("StatusGauge.bmp", _Order + 2);
		StatusGaugeRender[i]->SetScale({ 110, 14 });
		StatusGaugeRender[i]->SetFrame(0);
		StatusGaugeRender[i]->SetPosition(StatusGaugeFrameRender_Layer1[i]->GetPosition() + float4{ -55.0f, -1.0 });
	}

	StatusGaugeEmptyRender.resize(StatusCount);
	for (size_t i = 0; i < StatusGaugeEmptyRender.size(); i++)
	{
		StatusGaugeEmptyRender[i] = CreateRender("StatusGauge.bmp", _Order + 1);
		StatusGaugeEmptyRender[i]->SetScale({ 110, 14 });
		StatusGaugeEmptyRender[i]->SetFrame(1);
		StatusGaugeEmptyRender[i]->SetPosition(StatusGaugeFrameRender_Layer1[i]->GetPosition() + float4{ 55.0f, -1.0 });
	}

	StatusGaugeFrameRender_Layer2.resize(StatusCount);
	for (int i = 0; i < StatusGaugeFrameRender_Layer2.size(); i++)
	{
		StatusGaugeFrameRender_Layer2[i] = CreateRender("StatusGaugeFrame_Layer2.bmp", _Order + 3);
		StatusGaugeFrameRender_Layer2[i]->SetPosition(float4::Up * (StatusGaugeFrameRender_Layer2[i]->GetScale().half()) * static_cast<float>(StatusGaugeFrameRender_Layer2.size() - 1) + float4::Down * (StatusGaugeFrameRender_Layer2[i]->GetScale()) * static_cast<float>(i));
	}
}

void StatusWindow::SetStatusFrameRender(PM2RenderOrder _Order)
{
	SetStatusFrameRender(static_cast<int>(_Order));
}

void StatusWindow::Start()
{
	//사용법 예시
	//SetPos(GameEngineWindow::GetScreenSize().half());
	//InitMenuFrameRender(PM2RenderOrder::Menu1);
	//SetStatusCount(3);
	//SetStatusFrameRender(PM2RenderOrder::Menu1_StatusGauge); 
}

void StatusWindow::Update(float _DeltaTime)
{

}
