#include "SchedulePlayerStatusGauge1_1.h"
#include "Olive.h"

SchedulePlayerStatusGauge1_1::SchedulePlayerStatusGauge1_1()
{

}

SchedulePlayerStatusGauge1_1::~SchedulePlayerStatusGauge1_1()
{

}

void SchedulePlayerStatusGauge1_1::SetSchedule(ScheduleLabel _Schedule)
{
	switch (_Schedule)
	{
	case ScheduleLabel::Null:
		break;
	case ScheduleLabel::자연과학:
		Render1->SetNameRender("지능");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxIntelligence);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Intelligence);

		Render2->SetNameRender("신앙심");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxFaith);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Faith);
		break;
	case ScheduleLabel::신학:
		Render1->SetNameRender("지능");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxIntelligence);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Intelligence);

		Render2->SetNameRender("신앙심");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxFaith);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Faith);
		break;
	case ScheduleLabel::군사학:
		Render1->SetNameRender("지능");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxIntelligence);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Intelligence);

		Render2->SetNameRender("감수성");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxSensitivity);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Sensitivity);
		break;
	case ScheduleLabel::검술:
		Render1->SetNameRender("전투기술");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxCombatSkill);
		Status1 = &(Olive::OlivePlayer->OliveStatus.CombatSkill);

		Render2->SetNameRender("감수성");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxCombatAttack);
		Status2 = &(Olive::OlivePlayer->OliveStatus.CombatAttack);
		break;
	case ScheduleLabel::격투술:
		Render1->SetNameRender("전투기술");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxCombatSkill);
		Status1 = &(Olive::OlivePlayer->OliveStatus.CombatSkill);

		Render2->SetNameRender("방어력");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxCombatDefense);
		Status2 = &(Olive::OlivePlayer->OliveStatus.CombatDefense);
		break;
	case ScheduleLabel::마법:
		Render1->SetNameRender("마법기술");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxMagicSkill);
		Status1 = &(Olive::OlivePlayer->OliveStatus.MagicSkill);

		Render2->SetNameRender("마력");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxMagicAttack);
		Status2 = &(Olive::OlivePlayer->OliveStatus.MagicAttack);
		break;
	case ScheduleLabel::시문학:
		Render1->SetNameRender("지능");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxIntelligence);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Intelligence);

		Render2->SetNameRender("기품");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxRefinement);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Refinement);
		break;
	case ScheduleLabel::예법:
		Render1->SetNameRender("기품");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxRefinement);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Refinement);

		Render2->SetNameRender("예의범절");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxDecorum);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Decorum);
		break;
	case ScheduleLabel::무용:
		Render1->SetNameRender("체력");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxConstitution);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Constitution);

		Render2->SetNameRender("색기");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxCharisma);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Charisma);
		break;
	case ScheduleLabel::미술:
		Render1->SetNameRender("예술");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxArt);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Art);

		Render2->SetNameRender("감수성");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxSensitivity);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Sensitivity);
		break;
	default:
		break;
	}
}

void SchedulePlayerStatusGauge1_1::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	Render1 = InsertStatus(" ", 999, Style);
	Render2 = InsertStatus(" ", 999, Style);
	SetPos({ 160,505 });
	Off();
}

void SchedulePlayerStatusGauge1_1::Update(float _DeltaTime)
{
	if (Status1 != nullptr)
	{
		Render1->UpdateValue(*Status1);
	}

	if (Status2 != nullptr)
	{
		Render2->UpdateValue(*Status2);
	}
}
