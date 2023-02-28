#pragma once
#include <GameEngineCore/GameEngineActor.h>

class ScheduleAnimation;
class ScheduleCalendar;
class PaintingClass;
class SchedulePlayer : public GameEngineActor
{
public:
	// construtor destructor
	SchedulePlayer();
	~SchedulePlayer();

	// delete Function
	SchedulePlayer(const SchedulePlayer& _Other) = delete;
	SchedulePlayer(SchedulePlayer&& _Other) noexcept = delete;
	SchedulePlayer& operator=(const SchedulePlayer& _Other) = delete;
	SchedulePlayer& operator=(SchedulePlayer&& _Other) noexcept = delete;
	void PlayFirstOrderSchedule(float _DeltaTime);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float Time = 0;

	ScheduleAnimation* AcScheduleAnimation = nullptr;
	ScheduleCalendar* AcScheduleCalendar = nullptr;
	PaintingClass* AcPaintingClass = nullptr;
	
};

