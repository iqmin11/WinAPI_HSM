#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Date.h"
#include <GameEngineCore/NumberRenderObject.h>
#include "ContentsEnums.h"

class GameEngineRender;
class OnedaySchedule : public GameEngineActor
{
public:
	// construtor destructor
	OnedaySchedule();
	~OnedaySchedule();

	// delete Function
	OnedaySchedule(const OnedaySchedule& _Other) = delete;
	OnedaySchedule(OnedaySchedule&& _Other) noexcept = delete;
	OnedaySchedule& operator=(const OnedaySchedule& _Other) = delete;
	OnedaySchedule& operator=(OnedaySchedule&& _Other) noexcept = delete;

	Date DateValue = Date();
	ScheduleLabel ScheduleValue = ScheduleLabel::Null;

	void UpdateDayNumRender();
	int GetScheduleOrder()
	{
		return ScheduleOrder;
	}

	void SetScheduleOrder(int _Order)
	{
		ScheduleOrder = _Order;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	Date Today = Date();
	Date NextDate = Date();
	int ScheduleOrder = 0;
	
	NumberRenderObject DayNumRender = NumberRenderObject();
	float4 DayNumRenderScale_1 = { 20,20 };
	float4 DayNumRenderScale_2 = { 10,20 };
	float4 DayNumRenderPos_1 = { 10,10 };
	float4 DayNumRenderPos_2 = { 15,10 };
	

	GameEngineRender* IconRender = nullptr;
	float4 IconRenderScale = { 40,40 };

	void SetDayNumRender();

};

