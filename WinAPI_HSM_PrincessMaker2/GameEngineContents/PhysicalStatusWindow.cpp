#include "PhysicalStatusWindow.h"
#include "Olive.h"


PhysicalStatusWindow::PhysicalStatusWindow()
{

}

PhysicalStatusWindow::~PhysicalStatusWindow()
{

}

void PhysicalStatusWindow::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	HeightRender = InsertStatus("Ű", Max, Style);
	WeightRender = InsertStatus("������", Max, Style);
	BustRender = InsertStatus("����", Max, Style);
	WaistRender = InsertStatus("�㸮", Max, Style);
	HipRender = InsertStatus("������", Max, Style);
	SetPos(ActorPos);
	Off();
}

void PhysicalStatusWindow::Update(float _DeltaTime)
{
	UpdatePhysicalStatusWindow();
}

void PhysicalStatusWindow::UpdatePhysicalStatusWindow()
{
	if (Height != Olive::OlivePlayer->GetHeight())
	{
		Height = Olive::OlivePlayer->GetHeight();
		HeightRender->UpdateValue(Height);
	}

	if (Weight != Olive::OlivePlayer->GetWeight())
	{
		Weight = Olive::OlivePlayer->GetWeight();
		WeightRender->UpdateValue(Weight);
	}

	if (Bust != Olive::OlivePlayer->GetBust())
	{
		Bust = Olive::OlivePlayer->GetBust();
		BustRender->UpdateValue(Bust);
	}

	if (Waist != Olive::OlivePlayer->GetWaist())
	{
		Waist = Olive::OlivePlayer->GetWaist();
		WaistRender->UpdateValue(Waist);
	}

	if (Hip != Olive::OlivePlayer->GetHip())
	{
		Hip = Olive::OlivePlayer->GetHip();
		HipRender->UpdateValue(Hip);
	}
}
