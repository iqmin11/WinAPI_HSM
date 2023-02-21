#pragma once
#include "StatusWindow.h"

class FighterAndMagicalStatusWindow : public StatusWindow
{
public:
	// construtor destructor
	FighterAndMagicalStatusWindow();
	~FighterAndMagicalStatusWindow();

	// delete Function
	FighterAndMagicalStatusWindow(const FighterAndMagicalStatusWindow& _Other) = delete;
	FighterAndMagicalStatusWindow(FighterAndMagicalStatusWindow&& _Other) noexcept = delete;
	FighterAndMagicalStatusWindow& operator=(const FighterAndMagicalStatusWindow& _Other) = delete;
	FighterAndMagicalStatusWindow& operator=(FighterAndMagicalStatusWindow&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 ActorPos = {130, 455};

	float CombatSkill = 0;
	GaugeRenderObject* CombatSkillRender = nullptr;
	float CombatAttack = 0;
	GaugeRenderObject* CombatAttackRender = nullptr;
	float CombatDefense = 0;
	GaugeRenderObject* CombatDefenseRender = nullptr;

	float MagicSkill = 0;
	GaugeRenderObject* MagicSkillRender = nullptr;
	float MagicAttack = 0;
	GaugeRenderObject* MagicAttackRender = nullptr;
	float MagicDefense = 0;
	GaugeRenderObject* MagicDefenseRender = nullptr;

	float Max = 100;

	GaugeFrameStyle Style = GaugeFrameStyle::Detail;

};

