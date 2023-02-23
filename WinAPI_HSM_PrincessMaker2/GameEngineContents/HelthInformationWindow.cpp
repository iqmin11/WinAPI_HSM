#include "HelthInformationWindow.h"
#include <GameEngineCore/GameEngineRender.h>
#include "Olive.h"

HelthInformationWindow::HelthInformationWindow()
{

}

HelthInformationWindow::~HelthInformationWindow()
{

}

void HelthInformationWindow::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1, MenuFrameStyleEnum::Nomal);
	SetMenuFrameScale(Scale);
	SetPos(ActorPos);

	interface_Disease = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_Disease->SetText("질병 지수", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_Disease->SetPosition(interface_DiseasePos);
	
	interface_Delinquency = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_Delinquency->SetText("불량화 지수", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_Delinquency->SetPosition(interface_DelinquencyPos);
	
	interface_Popularity = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_Popularity->SetText("인맥", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_Popularity->SetPosition(interface_PopularityPos);

	interface_DietState = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_DietState->SetText("건강", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_DietState->SetPosition(interface_DietStatePos);

	DiseaseRender = CreateRender(PM2RenderOrder::Menu1_Display);
	DiseaseRender->SetText(std::to_string(static_cast<int>(DiseaseIndex)) + std::string(" %"), TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
	DiseaseRender->SetPosition(DiseaseRenderPos);
	DelinquencyRender = CreateRender(PM2RenderOrder::Menu1_Display);
	DelinquencyRender->SetText(std::to_string(static_cast<int>(Delinquency)) + std::string(" %"), TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
	DelinquencyRender->SetPosition(DelinquencyRenderPos);
	PopularityRender = CreateRender(PM2RenderOrder::Menu1_Display);
	PopularityRender->SetText(std::to_string(static_cast<int>(Popularity)), TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
	PopularityRender->SetPosition(PopularityRenderPos);
	DiseaseStateRender = CreateRender(PM2RenderOrder::Menu1_Display);
	DiseaseState = Olive::OlivePlayer->IsDiseaseState();
	switch (DiseaseState)
	{
	case false:
		DiseaseStateRender->SetText("건강합니다", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	case true:
		DiseaseStateRender->SetText("질병상태입니다", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	}
	DiseaseStateRender->SetPosition(DiseaseStateRenderPos);
	DelinquentStateRender = CreateRender(PM2RenderOrder::Menu1_Display);
	switch (DelinquentState)
	{
	case false:
		DelinquentStateRender->SetText("솔직합니다", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	case true:
		DelinquentStateRender->SetText("불량합니다", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	}
	DelinquentStateRender->SetPosition(DelinquentStateRenderPos);

	DietStateRender = CreateRender(PM2RenderOrder::Menu1_Display);
	switch (DietState)
	{
	case Diet::Null:
		break;
	case Diet::무리하지_않는다:
		DietStateRender->SetText("「무리하지 않는다」", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	case Diet::어쨌든_튼튼하게:
		DietStateRender->SetText("「어쨌든 튼튼하게」", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	case Diet::얌전한_아이로:
		DietStateRender->SetText("「얌전한 아이로」", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	case Diet::다이어트_시킨다:
		DietStateRender->SetText("「다이어트 시킨다」", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	default:
		break;
	}
	DietStateRender->SetPosition(DietStateRenderPos);

	Off();
}

void HelthInformationWindow::Update(float _DeltaTime)
{
	UpdateHelthInformationWindow();
}

void HelthInformationWindow::UpdateHelthInformationWindow()
{
	if (DiseaseIndex != Olive::OlivePlayer->GetDiseaseIndex())
	{
		DiseaseIndex = Olive::OlivePlayer->GetDiseaseIndex();
		DiseaseRender->SetText(std::to_string(static_cast<int>(DiseaseIndex)) + std::string(" %"), TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
	}

	if (Delinquency != Olive::OlivePlayer->GetDelinquency())
	{
		Delinquency = Olive::OlivePlayer->GetDelinquency();
		DelinquencyRender->SetText(std::to_string(static_cast<int>(Delinquency)) + std::string(" %"), TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
	}

	if (Popularity != Olive::OlivePlayer->GetPopularity())
	{
		Popularity = Olive::OlivePlayer->GetPopularity();
		PopularityRender->SetText(std::to_string(static_cast<int>(Popularity)), TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale2);
	}

	if (DiseaseState != Olive::OlivePlayer->IsDiseaseState())
	{
		DiseaseState = Olive::OlivePlayer->IsDiseaseState();
		switch (DiseaseState)
		{
		case false :
			DiseaseStateRender->SetText("건강합니다", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		case true :
			DiseaseStateRender->SetText("질병상태입니다", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		}
	}
	
	if (DelinquentState != Olive::OlivePlayer->IsDelinquentState())
	{
		DelinquentState = Olive::OlivePlayer->IsDelinquentState();
		switch (DelinquentState)
		{
		case false:
			DelinquentStateRender->SetText("솔직합니다", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		case true:
			DelinquentStateRender->SetText("불량합니다", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		}
	}

	if (DietState != Olive::OlivePlayer->GetOliveDiet())
	{
		DietState = Olive::OlivePlayer->GetOliveDiet();
		switch (DietState)
		{
		case Diet::Null:
			break;
		case Diet::무리하지_않는다:
			DietStateRender->SetText("「무리하지 않는다」", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		case Diet::어쨌든_튼튼하게:
			DietStateRender->SetText("「어쨌든 튼튼하게」", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		case Diet::얌전한_아이로:
			DietStateRender->SetText("「얌전한 아이로」", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		case Diet::다이어트_시킨다:
			DietStateRender->SetText("「다이어트 시킨다」", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		default:
			break;
		}
	}
	
}
