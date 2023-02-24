#pragma once
#include "MenuFrame.h"

class ScienceClass;
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

	ScienceClass* AcScienceClass = nullptr;
};

