#include "EstimateStatusWindow.h"
#include "Olive.h"
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
	
	FighterRender = InsertStatus("������", Max, Style);
	MagicalRender = InsertStatus("������", Max, Style);
	SocialRender = InsertStatus("�米��", Max, Style);
	HouseWorkRender = InsertStatus("������", Max, Style);
	
	SetPos(float4{ GameEngineWindow::GetScreenSize().x , GameEngineWindow::GetScreenSize().hy() } + (float4::Left * (GetMenuFrameScale().half())) + float4{ -10,0 } + float4{ 0,20 });
	Off();
}

void EstimateStatusWindow::Update(float _DeltaTime)
{
	if (Fighter != Olive::OlivePlayer->GetStatue().Fighter)
	{
		Fighter = Olive::OlivePlayer->GetStatue().Fighter;
		FighterRender->UpdateValue(Fighter);
	}
	if (Magical != Olive::OlivePlayer->GetStatue().Magical)
	{
		Magical = Olive::OlivePlayer->GetStatue().Magical;
		MagicalRender->UpdateValue(Magical);
	}
	if (Social != Olive::OlivePlayer->GetStatue().Social)
	{
		Social = Olive::OlivePlayer->GetStatue().Social;
		SocialRender->UpdateValue(Social);
	}
	if (HouseWork != Olive::OlivePlayer->GetStatue().HouseWork)
	{
		HouseWork = Olive::OlivePlayer->GetStatue().HouseWork;
		HouseWorkRender->UpdateValue(HouseWork);
	}
}
