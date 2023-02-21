#include "FighterAndMagicalStatusWindow.h"
#include "Olive.h"

FighterAndMagicalStatusWindow::FighterAndMagicalStatusWindow()
{

}

FighterAndMagicalStatusWindow::~FighterAndMagicalStatusWindow()
{

}

void FighterAndMagicalStatusWindow::Start()
{
	InitMenuFrameRender(PM2RenderOrder::Menu1);
	CombatSkillRender = InsertStatus("�������", Max, Style);
	CombatAttackRender = InsertStatus("���ݷ�", Max, Style);
	CombatDefenseRender = InsertStatus("����", Max, Style);

	MagicSkillRender = InsertStatus("�������", Max, Style);
	MagicAttackRender = InsertStatus("����", Max, Style);
	MagicDefenseRender = InsertStatus("�׸���", Max, Style);

	SetPos(ActorPos);
	Off();
}

void FighterAndMagicalStatusWindow::Update(float _DeltaTime)
{
	if (CombatSkill != Olive::OlivePlayer->GetStatue().CombatSkill)
	{
		CombatSkill = Olive::OlivePlayer->GetStatue().CombatSkill;
		CombatSkillRender->UpdateValue(CombatSkill);
	}
	if (CombatAttack != Olive::OlivePlayer->GetStatue().CombatAttack)
	{
		CombatAttack = Olive::OlivePlayer->GetStatue().CombatAttack;
		CombatAttackRender->UpdateValue(CombatAttack);
	}
	if (CombatDefense != Olive::OlivePlayer->GetStatue().CombatDefense)
	{
		CombatDefense = Olive::OlivePlayer->GetStatue().CombatDefense;
		CombatDefenseRender->UpdateValue(CombatDefense);
	}
	if (MagicSkill != Olive::OlivePlayer->GetStatue().MagicSkill)
	{
		MagicSkill = Olive::OlivePlayer->GetStatue().MagicSkill;
		MagicSkillRender->UpdateValue(MagicSkill);
	}
	if (MagicAttack != Olive::OlivePlayer->GetStatue().MagicAttack)
	{
		MagicAttack = Olive::OlivePlayer->GetStatue().MagicAttack;
		MagicAttackRender->UpdateValue(MagicAttack);
	}
	if (MagicDefense != Olive::OlivePlayer->GetStatue().MagicDefense)
	{
		MagicDefense = Olive::OlivePlayer->GetStatue().MagicDefense;
		MagicDefenseRender->UpdateValue(MagicDefense);
	}
}
