#pragma once
#include "MenuFrame.h"

class DanceClass;
class FencingClass;
class FightingClass;
class MagicClass;
class PaintingClass;
class PoetryClass;
class ProtocolClass;
class ScienceClass;
class StrategyClass;
class TheologyClass;

enum class AnimationState
{
	Null = -1,
	Dance,
	Fencing,
	Fighting,
	Magic,
	Painting,
	Poetry,
	Protocol,
	Science,
	Strategy,
	Theology,
};

class ScheduleAnimationPlayer : public MenuFrame
{
public:
	// construtor destructor
	ScheduleAnimationPlayer();
	~ScheduleAnimationPlayer();

	// delete Function
	ScheduleAnimationPlayer(const ScheduleAnimationPlayer& _Other) = delete;
	ScheduleAnimationPlayer(ScheduleAnimationPlayer&& _Other) noexcept = delete;
	ScheduleAnimationPlayer& operator=(const ScheduleAnimationPlayer& _Other) = delete;
	ScheduleAnimationPlayer& operator=(ScheduleAnimationPlayer&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 ActorPos = {240, 380};
	float4 BoxScale = {420, 180};

	AnimationState StateValue = AnimationState::Null;

	DanceClass* AcDanceClass = nullptr;
	FencingClass* AcFencingClass = nullptr;
	FightingClass* AcFightingClass = nullptr;
	MagicClass* AcMagicClass = nullptr;
	PaintingClass* AcPaintingClass = nullptr;
	PoetryClass* AcPoetryClass = nullptr;
	ProtocolClass* AcProtocolClass = nullptr;
	ScienceClass* AcScienceClass = nullptr;
	StrategyClass* AcStrategyClass = nullptr;
	TheologyClass* AcTheologyClass = nullptr;
};

