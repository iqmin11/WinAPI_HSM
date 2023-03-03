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
	case ScheduleLabel::�ڿ�����:
		Render1->SetNameRender("����");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxIntelligence);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Intelligence);

		Render2->SetNameRender("�žӽ�");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxFaith);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Faith);
		break;
	case ScheduleLabel::����:
		Render1->SetNameRender("����");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxIntelligence);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Intelligence);

		Render2->SetNameRender("�žӽ�");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxFaith);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Faith);
		break;
	case ScheduleLabel::������:
		Render1->SetNameRender("����");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxIntelligence);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Intelligence);

		Render2->SetNameRender("������");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxSensitivity);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Sensitivity);
		break;
	case ScheduleLabel::�˼�:
		Render1->SetNameRender("�������");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxCombatSkill);
		Status1 = &(Olive::OlivePlayer->OliveStatus.CombatSkill);

		Render2->SetNameRender("������");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxCombatAttack);
		Status2 = &(Olive::OlivePlayer->OliveStatus.CombatAttack);
		break;
	case ScheduleLabel::������:
		Render1->SetNameRender("�������");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxCombatSkill);
		Status1 = &(Olive::OlivePlayer->OliveStatus.CombatSkill);

		Render2->SetNameRender("����");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxCombatDefense);
		Status2 = &(Olive::OlivePlayer->OliveStatus.CombatDefense);
		break;
	case ScheduleLabel::����:
		Render1->SetNameRender("�������");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxMagicSkill);
		Status1 = &(Olive::OlivePlayer->OliveStatus.MagicSkill);

		Render2->SetNameRender("����");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxMagicAttack);
		Status2 = &(Olive::OlivePlayer->OliveStatus.MagicAttack);
		break;
	case ScheduleLabel::�ù���:
		Render1->SetNameRender("����");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxIntelligence);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Intelligence);

		Render2->SetNameRender("��ǰ");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxRefinement);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Refinement);
		break;
	case ScheduleLabel::����:
		Render1->SetNameRender("��ǰ");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxRefinement);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Refinement);

		Render2->SetNameRender("���ǹ���");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxDecorum);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Decorum);
		break;
	case ScheduleLabel::����:
		Render1->SetNameRender("ü��");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxConstitution);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Constitution);

		Render2->SetNameRender("����");
		Render2->SetMax(Olive::OlivePlayer->OliveStatus.MaxCharisma);
		Status2 = &(Olive::OlivePlayer->OliveStatus.Charisma);
		break;
	case ScheduleLabel::�̼�:
		Render1->SetNameRender("����");
		Render1->SetMax(Olive::OlivePlayer->OliveStatus.MaxArt);
		Status1 = &(Olive::OlivePlayer->OliveStatus.Art);

		Render2->SetNameRender("������");
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
