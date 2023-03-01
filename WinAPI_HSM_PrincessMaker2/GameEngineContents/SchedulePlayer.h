#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Date.h"
#include "ContentsEnums.h"

struct ScheduleSave
{
	int Order = 0;
	Date DateSave = Date();
	ScheduleLabel ScheduleSave;
};

class ScheduleAnimationPlayer;
class ScheduleCalendar;
class PaintingClass;
class RaisingSimLevel;
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
	void PlaySecondOrderSchedule(float _DeltaTime);
	void PlayThirdOrderSchedule(float _DeltaTime);

	void On() override;
	void Off() override;


protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float Time = 0;
	ScheduleSave Save[6][7] = {};
	bool FirstUpdateCheck = false;
	bool ScheduleEnd = true;

	RaisingSimLevel* ParentLevel = nullptr;

	ScheduleAnimationPlayer* AcScheduleAnimationPlayer = nullptr;
	ScheduleCalendar* AcScheduleCalendar = nullptr;
	PaintingClass* AcPaintingClass = nullptr;

	void PlayOneDaySchedule();
	
	void PlayerStart();
	void PlayerUpdate(float _DeltaTime);
	//void PlayerEnd();
};

