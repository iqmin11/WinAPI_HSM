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
	TextRender->SetText("�ĺ�", TextHeight, TextType, TextAlign::Left, TextColor, {80, 21}); // 175, 103
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
	case Diet::��������_�ʴ´�:
		SetUpdateText("�ĺ� 30G �ʿ��մϴ�");
		FoodCostNumRender.SetValue(30);
		break;
	case Diet::��·��_ưư�ϰ�:
		SetUpdateText("�ĺ� 80G �ʿ��մϴ�");
		FoodCostNumRender.SetValue(80);
		break;
	case Diet::������_���̷�:
		SetUpdateText("�ĺ� 10G �ʿ��մϴ�");
		FoodCostNumRender.SetValue(10);
		break;
	case Diet::���̾�Ʈ_��Ų��:
		SetUpdateText("�ĺ� 5G �ʿ��մϴ�");
		FoodCostNumRender.SetValue(5);
		break;
	default:
		break;
	}
}
