#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Date.h"
#include "ContentsEnums.h"

struct ScheduleSave
{
	ScheduleSave(int _Order, Date _Date, ScheduleLabel _Schedule)
		: Order(_Order),
		DateSave(_Date),
		Schedule(_Schedule) {}

	int Order = 0;
	Date DateSave = Date();
	ScheduleLabel Schedule = ScheduleLabel::Null;
};

class ScheduleAnimationPlayer;
class ScheduleCalendar;

class PaintingClass;
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

class RaisingSimLevel;
class FoodCostDialog;
class ScheduleDialog;
class SchedulePlayerGuage;
class ScheduleMessageBox;
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
	//void PlayFirstOrderSchedule(float _DeltaTime);
	//void PlaySecondOrderSchedule(float _DeltaTime);
	//void PlayThirdOrderSchedule(float _DeltaTime);

	static SchedulePlayer* GetAcSchedulePlayer()
	{
		return AcSchedulePlayer;
	}

	std::list<ScheduleSave>& GetSave()
	{
		return Save;
	}

	void Off() override;
	static bool IsPartOfScheduleEnd;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	static SchedulePlayer* AcSchedulePlayer;

	float Time = 1;
	std::list<ScheduleSave> Save = std::list<ScheduleSave>();
	bool FirstUpdateCheck = false;

	RaisingSimLevel* ParentLevel = nullptr;

	ScheduleAnimationPlayer* AcScheduleAnimationPlayer = nullptr;
	ScheduleCalendar* AcScheduleCalendar = nullptr;
	SchedulePlayerGuage* AcSchedulePlayerGuage = nullptr;
	ScheduleMessageBox* AcScheduleMessageBox = nullptr;

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

	FoodCostDialog* AcFoodCostDialog = nullptr;
	ScheduleDialog* AcScheduleDialog = nullptr;
	
	bool FirstScheduleUpdateCheck = false;

	int DayCount = 0;

	void PlayOneDaySchedule();
	void AnimationOff();
	
	void AnimationPlay();
	void AnimationStop();
	
	void PayDiet();
};

