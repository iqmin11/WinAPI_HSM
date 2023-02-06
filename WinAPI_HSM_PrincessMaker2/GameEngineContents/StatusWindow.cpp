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
	for (int i = 0; i < StatusGaugeRender.size(); i++)
	{
		StatusGaugeRender[i].resize(2);
	}
	
	for (int i = 0; i < StatusGaugeRender.size(); i++)
	{
		for (int j = 0; j < StatusGaugeRender[i].size(); j++)
		{
			StatusGaugeRender[i][j] = CreateRender("StatusGauge.bmp", _Order + 2 - j);
			StatusGaugeRender[i][j]->SetScale({110, 14});
			StatusGaugeRender[i][j]->SetFrame(j);
			StatusGaugeRender[i][j]->SetPosition(StatusGaugeFrameRender_Layer1[i]->GetPosition() + float4{-55.0f + 110.0f*static_cast<float>(j), -1.0});
		}
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
	SetPos(GameEngineWindow::GetScreenSize().half());
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	SetStatusCount(3);
	SetStatusFrameRender(PM2RenderOrder::Menu1_StatusGauge); // 이단계에서 이미지 편집이 필요
}

void StatusWindow::Update(float _DeltaTime)
{
	StatusGaugeRender[0][0]->SetMove(float4::Right * 10 * _DeltaTime);
}
