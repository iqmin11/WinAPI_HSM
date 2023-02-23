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
	HeightRender = InsertStatus("Å°", Max, Style);
	WeightRender = InsertStatus("¸ö¹«°Ô", Max, Style);
	BustRender = InsertStatus("°¡½¿", Max, Style);
	WaistRender = InsertStatus("Çã¸®", Max, Style);
	HipRender = InsertStatus("¾ûµ¢ÀÌ", Max, Style);
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
