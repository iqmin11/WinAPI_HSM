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
	CombatSkillRender = InsertStatus("전투기술", Max, Style);
	CombatAttackRender = InsertStatus("공격력", Max, Style);
	CombatDefenseRender = InsertStatus("방어력", Max, Style);

	MagicSkillRender = InsertStatus("마법기술", Max, Style);
	MagicAttackRender = InsertStatus("마력", Max, Style);
	MagicDefenseRender = InsertStatus("항마력", Max, Style);

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
