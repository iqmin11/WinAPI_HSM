#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/NumberRenderObject.h>
#include "Date.h"

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

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 ActorPos = {160,263};
	Date Today = Date(1000,10,10);
	Date NextDate = Date(1000, 10, 11);
	std::vector<Date> ThisMonthCalendar = std::vector<Date>();

	GameEngineRender* CalendarFrame = nullptr;
	
	NumberRenderObject DayNumRender[6][7] = {};
	float4 DayNumRenderScale_1 = { 20,20 };
	float4 DayNumRenderScale_2 = { 10,20 };
	float4 FirstDayNumRenderPos_1 = { -110,-70 };
	float4 FirstDayNumRenderPos_2 = { -105,-70 };
	float4 DayNumRenderInterval = { 40,40 };

	NumberRenderObject YearNumRender = {};
	float4 YearNumRenderScale = { 10,20 };
	float4 YearNumRenderPos = { -25,-130 };

	GameEngineRender* MonthRender = nullptr;
	float4 MonthRenderScale = { 60,20 };
	float4 MonthRenderPos = { 30,-130 };

	GameEngineRender* IconRender[6][7] = {};
	float4 IconScale = { 34,34 };
	float4 FirstIconPos = { -120,-80 };


	void SetThisMonthCalendar();
	void SetDayNumRender();
	void SetYearNumRender();
	void SetMonthRender();
	void SetIconRender();

	void UpdateDayNumRender();
	void UpdateYearNumRender();
	void UpdateMonthRender();
};

