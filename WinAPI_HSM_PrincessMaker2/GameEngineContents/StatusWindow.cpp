#include "StatusWindow.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineRender.h>

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

void StatusWindow::InsertStatus(StatusName _StatusName, int _Max, GaugeFrameStyle _Style)
{
	++StatusCount;
	SetMenuFrameScale({ 220.0f + 20.0f,(static_cast<float>(StatusCount) * 20.0f) + 20.0f });
	GaugeRenderObject* InsertGaugePtr = new GaugeRenderObject; 
	InsertGaugePtr->SetOwner(this);
	InsertGaugePtr->SetGaugeRender(GetFrameRenderOrder() + 1, _StatusName, _Max, _Style);
	Gauges.push_back(InsertGaugePtr);
	for (int i = 0; i < Gauges.size(); ++i)
	{
		Gauges[i]->SetPosition(((float4::Up * 10 * static_cast<float>(Gauges.size() - 1)) + (float4::Down * 20 * static_cast<float>(i))));
	}
}

void StatusWindow::Start()
{
	//���� ����
	//St = GaugeFrameStyle::Nomal;
	//InitMenuFrameRender(PM2RenderOrder::Menu1);
	//InsertStatus(�̸�, �ɷ�ġ �ƽ� ��ġ)
	//InsertStatus(�̸�, �ɷ�ġ �ƽ� ��ġ)
	//InsertStatus(�̸�, �ɷ�ġ �ƽ� ��ġ) �ְ������ŭ �ְ�
	//SetPos();

}

void StatusWindow::Update(float _DeltaTime)
{

}
