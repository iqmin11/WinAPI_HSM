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

private:
	float4 ActorPos = {160,263};
	Date Today = Date(1200,9,10);
	std::vector<Date> ThisMonthCalendar = std::vector<Date>();

	GameEngineRender* CalendarFrame = nullptr;
	
	NumberRenderObject DayNumRender[6][7] = {};
	float4 DayNumRenderScale = { 10,20 };
	float4 FirstDayNumRenderPos = { -105,-70 };
	float4 DayNumRenderInterval = { 40,40 };


	void SetDayNumRender();
	void SetThisMonthCalendar();
};

