#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>
#include "Date.h"
#include "OnedaySchedule.h"
#include "ContentsEnums.h"

class GameEngineRender;
class ScheduleCalendar : public GameEngineActor
{
public:
	// construtor destructor
	ScheduleCalendar();
	~ScheduleCalendar();

	// delete Function
	ScheduleCalendar(const ScheduleCalendar& _Other) = delete;
	ScheduleCalendar(ScheduleCalendar&& _Other) noexcept = delete;
	ScheduleCalendar& operator=(const ScheduleCalendar& _Other) = delete;
	ScheduleCalendar& operator=(ScheduleCalendar&& _Other) noexcept = delete;

	void On() override;
	void Off() override;

	void ScheduleSetting(ScheduleLabel _Schedule);
	void CancelSchedule();
	void Reset();
	std::vector<std::vector<OnedaySchedule*>>& GetThisMonthSchedule()
	{
		return ThisMonthSchedule;
	}

	bool FirstScheduleSet = false;
	bool SecondScheduleSet = false;
	bool ThirdScheduleSet = false;
	bool ScheduleSetEnd = false;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 ActorPos = {160,263};
	Date Today = Date(1000,10,10);
	Date NextDate = Date(1000, 10, 11);
	std::vector<std::vector<OnedaySchedule*>> ThisMonthSchedule = std::vector<std::vector<OnedaySchedule*>>();
	void UpdateMonthCalendar();
	void SetThisMonthSchedule();
	
	GameEngineRender* CalendarFrame = nullptr;
	
	float4 FirstScheduleActorPos = { 40, 183 };
	float4 ScheduleActorInterval = { 40,40 };

	NumberRenderObject YearNumRender = {};
	float4 YearNumRenderScale = { 10,20 };
	float4 YearNumRenderPos = { -25,-130 };

	GameEngineRender* MonthRender = nullptr;
	float4 MonthRenderScale = { 60,20 };
	float4 MonthRenderPos = { 30,-130 };

	GameEngineRender* IconRender[6][7] = {};
	float4 IconScale = { 34,34 };
	float4 FirstIconPos = { -120,-80 }; // 280, 220

	

	void SetYearNumRender();
	void SetMonthRender();

	void UpdateDayNumRender();
	void UpdateYearNumRender();
	void UpdateMonthRender();
};

