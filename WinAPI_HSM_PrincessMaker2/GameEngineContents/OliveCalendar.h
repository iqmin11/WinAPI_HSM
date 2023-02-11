#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>
#include <GameEngineCore/NumberRenderObject.h>
#include "Date.h"

class OliveCalendar : public GameEngineActor
{
public:
	// construtor destructor
	OliveCalendar();
	~OliveCalendar();

	// delete Function
	OliveCalendar(const OliveCalendar& _Other) = delete;
	OliveCalendar(OliveCalendar&& _Other) noexcept = delete;
	OliveCalendar& operator=(const OliveCalendar& _Other) = delete;
	OliveCalendar& operator=(OliveCalendar&& _Other) noexcept = delete;



	void SetDateNumButton();
	void SetYearRender();
	void SetWeekdayRender();
	void SetMonthRender();
	
	void SetStartDate(int _YYYY, int _MM, int _DD)
	{
		StartDate.SetDate(_YYYY, _MM, _DD);
	}

	void On() override;
	void Off() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;


private:
	Date StartDate = Date();

	Button* DateButton[4][3][6][7] = {}; //달력 열, 행, 날짜 열, 행
	Date EachButtonDate[4][3][6][7] = {}; //달력 열, 행, 날짜 열, 행
	GameEngineRender* WeekRender[4][3] = {}; //달력 열, 행, 날짜 열, 행
	GameEngineRender* YearRender[4][3][4] = {}; // 달력 열, 행, 년도 네글자
	GameEngineRender* MonthRender[4][3] = {}; // 달력 열, 행 
	GameEngineRender* BackgroundRender = nullptr;

	NumberRenderObject HoverButtonDateRender_Year = NumberRenderObject();
	float4 Pos_HoverButtonDateRender_Year = { -335, -221 };
	NumberRenderObject HoverButtonDateRender_Month = NumberRenderObject();
	float4 Pos_HoverButtonDateRender_Month = { -305, -221 };
	NumberRenderObject HoverButtonDateRender_Day = NumberRenderObject();
	float4 Pos_HoverButtonDateRender_Day = { -275, -221 };

	float4 WichButtonNotRelease();
	void SetEachButtonDate();

};

