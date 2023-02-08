#include "StatusWindow.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

#include "GaugeRenderObject.h"


StatusWindow::StatusWindow()
{

}

StatusWindow::~StatusWindow()
{
	for (auto i : Gauges)
	{
		delete i;
	}
}

void StatusWindow::InsertStatus(StatusName _StatusName, int _Max)
{
	++StatusCount;
	SetMenuFrameScale({ 220.0f + 20.0f,(static_cast<float>(StatusCount) * 20.0f) + 20.0f });
	GaugeRenderObject* InsertGaugePtr = new GaugeRenderObject; 
	InsertGaugePtr->SetOwner(this);
	InsertGaugePtr->SetGaugeRender(GetFrameRenderOrder() + 1, _StatusName, _Max);
	Gauges.push_back(InsertGaugePtr);
	for (int i = 0; i < Gauges.size(); ++i)
	{
		Gauges[i]->SetPosition(((float4::Up * 10 * static_cast<float>(Gauges.size() - 1)) + (float4::Down * 20 * static_cast<float>(i))));
	}
	//(float4::Up * (StatusGaugeFrameRender_Layer1[i]->GetScale().half()) * static_cast<float>(StatusGaugeFrameRender_Layer1.size() - 1) + float4::Down * (StatusGaugeFrameRender_Layer1[i]->GetScale()) * static_cast<float>(i));
}

//void StatusWindow::SetStatusFrameRender(int _Order)
//{
//	SetMenuFrameScale({220.0f + 20.0f,(static_cast<float>(StatusCount)*20.0f)+20.0f});
//	
//	//for (int i = 0; i < StatusGaugeFrameRender_Layer1.size(); i++)
//	//{
//	//	StatusGaugeFrameRender_Layer1[i] = CreateRender("StatusGaugeFrame_Layer1.bmp", _Order);
//	//	StatusGaugeFrameRender_Layer1[i]->SetPosition(float4::Up * (StatusGaugeFrameRender_Layer1[i]->GetScale().half()) * static_cast<float>(StatusGaugeFrameRender_Layer1.size() - 1) + float4::Down * (StatusGaugeFrameRender_Layer1[i]->GetScale()) * static_cast<float>(i));
//	//}
//	//
//	//StatusGaugeRender.resize(StatusCount);
//	//for (size_t i = 0; i < StatusGaugeRender.size(); i++)
//	//{
//	//	StatusGaugeRender[i] = CreateRender("StatusGauge.bmp", _Order + 2);
//	//	StatusGaugeRender[i]->SetScale({ 110, 14 });
//	//	StatusGaugeRender[i]->SetFrame(0);
//	//	StatusGaugeRender[i]->SetPosition(StatusGaugeFrameRender_Layer1[i]->GetPosition() + float4{ -55.0f, -1.0 });
//	//}
//	//
//	//StatusGaugeEmptyRender.resize(StatusCount);
//	//for (size_t i = 0; i < StatusGaugeEmptyRender.size(); i++)
//	//{
//	//	StatusGaugeEmptyRender[i] = CreateRender("StatusGauge.bmp", _Order + 1);
//	//	StatusGaugeEmptyRender[i]->SetScale({ 110, 14 });
//	//	StatusGaugeEmptyRender[i]->SetFrame(1);
//	//	StatusGaugeEmptyRender[i]->SetPosition(StatusGaugeFrameRender_Layer1[i]->GetPosition() + float4{ 55.0f, -1.0 });
//	//}
//	//
//	//StatusGaugeFrameRender_Layer2.resize(StatusCount);
//	//for (int i = 0; i < StatusGaugeFrameRender_Layer2.size(); i++)
//	//{
//	//	StatusGaugeFrameRender_Layer2[i] = CreateRender("StatusGaugeFrame_Layer2.bmp", _Order + 3);
//	//	StatusGaugeFrameRender_Layer2[i]->SetPosition(float4::Up * (StatusGaugeFrameRender_Layer2[i]->GetScale().half()) * static_cast<float>(StatusGaugeFrameRender_Layer2.size() - 1) + float4::Down * (StatusGaugeFrameRender_Layer2[i]->GetScale()) * static_cast<float>(i));
//	//}
//}
//
//void StatusWindow::SetStatusFrameRender(PM2RenderOrder _Order)
//{
//	SetStatusFrameRender(static_cast<int>(_Order));
//}

void StatusWindow::Start()
{
	//사용법 예시
	// 
	//InitMenuFrameRender(PM2RenderOrder::Menu1);
	//InsertStatus(이름, 능력치 맥스 수치)
	//InsertStatus(이름, 능력치 맥스 수치)
	//InsertStatus(이름, 능력치 맥스 수치) 넣고싶은만큼 넣고
	//SetPos();

}

void StatusWindow::Update(float _DeltaTime)
{

}
