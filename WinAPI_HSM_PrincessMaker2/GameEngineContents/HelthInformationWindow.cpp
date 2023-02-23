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
	interface_Disease->SetText("���� ����", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_Disease->SetPosition(interface_DiseasePos);
	
	interface_Delinquency = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_Delinquency->SetText("�ҷ�ȭ ����", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_Delinquency->SetPosition(interface_DelinquencyPos);
	
	interface_Popularity = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_Popularity->SetText("�θ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
	interface_Popularity->SetPosition(interface_PopularityPos);

	interface_DietState = CreateRender(PM2RenderOrder::Menu1_Display);
	interface_DietState->SetText("�ǰ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
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
		DiseaseStateRender->SetText("�ǰ��մϴ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	case true:
		DiseaseStateRender->SetText("���������Դϴ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	}
	DiseaseStateRender->SetPosition(DiseaseStateRenderPos);
	DelinquentStateRender = CreateRender(PM2RenderOrder::Menu1_Display);
	switch (DelinquentState)
	{
	case false:
		DelinquentStateRender->SetText("�����մϴ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	case true:
		DelinquentStateRender->SetText("�ҷ��մϴ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	}
	DelinquentStateRender->SetPosition(DelinquentStateRenderPos);

	DietStateRender = CreateRender(PM2RenderOrder::Menu1_Display);
	switch (DietState)
	{
	case Diet::Null:
		break;
	case Diet::��������_�ʴ´�:
		DietStateRender->SetText("���������� �ʴ´١�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	case Diet::��·��_ưư�ϰ�:
		DietStateRender->SetText("����·�� ưư�ϰԡ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	case Diet::������_���̷�:
		DietStateRender->SetText("�������� ���̷Ρ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
		break;
	case Diet::���̾�Ʈ_��Ų��:
		DietStateRender->SetText("�����̾�Ʈ ��Ų�١�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
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
			DiseaseStateRender->SetText("�ǰ��մϴ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		case true :
			DiseaseStateRender->SetText("���������Դϴ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		}
	}
	
	if (DelinquentState != Olive::OlivePlayer->IsDelinquentState())
	{
		DelinquentState = Olive::OlivePlayer->IsDelinquentState();
		switch (DelinquentState)
		{
		case false:
			DelinquentStateRender->SetText("�����մϴ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		case true:
			DelinquentStateRender->SetText("�ҷ��մϴ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
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
		case Diet::��������_�ʴ´�:
			DietStateRender->SetText("���������� �ʴ´١�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		case Diet::��·��_ưư�ϰ�:
			DietStateRender->SetText("����·�� ưư�ϰԡ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		case Diet::������_���̷�:
			DietStateRender->SetText("�������� ���̷Ρ�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		case Diet::���̾�Ʈ_��Ų��:
			DietStateRender->SetText("�����̾�Ʈ ��Ų�١�", TextHeight, TextType, TextAlign::Left, TextColor, TextBoxScale1);
			break;
		default:
			break;
		}
	}
	
}
