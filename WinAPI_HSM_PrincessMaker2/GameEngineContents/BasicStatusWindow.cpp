#include "BasicStatusWindow.h"
#include "Olive.h"

BasicStatusWindow::BasicStatusWindow()
{

}

BasicStatusWindow::~BasicStatusWindow()
{

}

void BasicStatusWindow::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	ConstitutionRender = InsertStatus("ü��", Max, Style);
	StrengthRender = InsertStatus("�ٷ�", Max, Style);
	IntelligenceRender = InsertStatus("����", Max, Style);
	RefinementRender = InsertStatus("��ǰ", Max, Style);
	CharismaRender = InsertStatus("����", Max, Style);
	MoralityRender = InsertStatus("������", Max, Style);
	FaithRender = InsertStatus("�ž�", Max, Style);
	SinRender = InsertStatus("����", Max, Style);
	SensitivityRender = InsertStatus("������", Max, Style);
	StressRender = InsertStatus("��Ʈ����", Max, Style);
	SetPos(ActorPos);
}

void BasicStatusWindow::Update(float _DeltaTime)
{
	if (Constitution != Olive::OlivePlayer->GetStatue().Constitution)
	{
		Constitution = Olive::OlivePlayer->GetStatue().Constitution;
		ConstitutionRender->UpdateValue(Constitution);
	}

	if (Strength != Olive::OlivePlayer->GetStatue().Strength)
	{
		Strength = Olive::OlivePlayer->GetStatue().Strength;
		StrengthRender->UpdateValue(Strength);
	}

	if (Intelligence != Olive::OlivePlayer->GetStatue().Intelligence)
	{
		Intelligence = Olive::OlivePlayer->GetStatue().Intelligence;
		IntelligenceRender->UpdateValue(Intelligence);
	}

	if (Refinement != Olive::OlivePlayer->GetStatue().Refinement)
	{
		Refinement = Olive::OlivePlayer->GetStatue().Refinement;
		RefinementRender->UpdateValue(Refinement);
	}

	if (Charisma != Olive::OlivePlayer->GetStatue().Charisma)
	{
		Charisma = Olive::OlivePlayer->GetStatue().Charisma;
		CharismaRender->UpdateValue(Charisma);
	}

	if (Morality != Olive::OlivePlayer->GetStatue().Morality)
	{
		Morality = Olive::OlivePlayer->GetStatue().Morality;
		MoralityRender->UpdateValue(Morality);
	}

	if (Faith != Olive::OlivePlayer->GetStatue().Faith)
	{
		Faith = Olive::OlivePlayer->GetStatue().Faith;
		FaithRender->UpdateValue(Faith);
	}

	if (Sin != Olive::OlivePlayer->GetStatue().Sin)
	{
		Sin = Olive::OlivePlayer->GetStatue().Sin;
		SinRender->UpdateValue(Sin);
	}

	if (Sensitivity != Olive::OlivePlayer->GetStatue().Sensitivity)
	{
		Sensitivity = Olive::OlivePlayer->GetStatue().Sensitivity;
		SensitivityRender->UpdateValue(Sensitivity);
	}

	if (Stress != Olive::OlivePlayer->GetStatue().Stress)
	{
		Stress = Olive::OlivePlayer->GetStatue().Stress;
		StressRender->UpdateValue(Stress);
	}

}
