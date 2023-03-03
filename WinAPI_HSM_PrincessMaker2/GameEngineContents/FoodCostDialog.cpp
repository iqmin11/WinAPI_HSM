#include "FoodCostDialog.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>

FoodCostDialog::FoodCostDialog()
{

}

FoodCostDialog::~FoodCostDialog()
{

}

void FoodCostDialog::Start()
{
	Dialog::Start();
	SetDialogScale(ActorScale);
	SetPos(ActorPos); 

	FoodCostRedner = CreateRender("FoodCost.bmp", PM2RenderOrder::Menu1);
	FoodCostRedner->SetScaleToImage(); 
	FoodCostRedner->SetPosition(FoodCostRednerPos);

	FoodCostNumRender.SetOwner(this);
	FoodCostNumRender.SetImage("Num.bmp", { 10, 19 }, static_cast<int>(PM2RenderOrder::Menu1_Display), RGB(255, 0, 255));
	FoodCostNumRender.SetAlign(Align::Right);
	FoodCostNumRender.SetValue(30);
	FoodCostNumRender.SetRenderPos(FoodCostNumRenderPos);
	
	TextRender = CreateRender(PM2RenderOrder::Menu1_Display);
	TextRender->SetText("식비", TextHeight, TextType, TextAlign::Left, TextColor, {80, 21}); // 175, 103
	TextRender->SetPosition(TextRenderPos);

	Off();
}

void FoodCostDialog::Update(float _DeltaTime)
{
	if (GameEngineInput::IsUp("EngineMouseRight"))
	{
		Off();
	}

	OliveDiet = Olive::OlivePlayer->GetOliveDiet();
	SetRender();
	Dialog::Update(_DeltaTime);
}

void FoodCostDialog::SetRender()
{
	switch (OliveDiet)
	{
	case Diet::Null:
		break;
	case Diet::무리하지_않는다:
		SetUpdateText("식비가 30G 필요합니다");
		FoodCostNumRender.SetValue(30);
		break;
	case Diet::어쨌든_튼튼하게:
		SetUpdateText("식비가 80G 필요합니다");
		FoodCostNumRender.SetValue(80);
		break;
	case Diet::얌전한_아이로:
		SetUpdateText("식비가 10G 필요합니다");
		FoodCostNumRender.SetValue(10);
		break;
	case Diet::다이어트_시킨다:
		SetUpdateText("식비가 5G 필요합니다");
		FoodCostNumRender.SetValue(5);
		break;
	default:
		break;
	}
}
