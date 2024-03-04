#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>
#include <GameEngineCore/NumberRenderObject.h>

#include "Button_Date.h"
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
	
	static bool FirstUpdate;

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

	float4 EcahMonthCalendarInterval = { 250 , 105 };

	Button_Date* DateButton[4][3][6][7] = {};
	float4 DateButtonScale = { 20,14 };
	float4 FirstDaySetPos = { -330, -177 };
	float4 EachDayNumInterval = { 30,15 };

	GameEngineRender* WeekRender[4][3] = {};
	float4 WeekRenderScale = { 210,10 };
	float4 FirstWeekSetPos = { -235, -192 };

	GameEngineRender* YearRender[4][3][4] = {}; 
	float4 YearRenderScale = { 8,12 };
	float4 FirstYearSetPos = { -370, -182 };

	GameEngineRender* MonthRender[4][3] = {};
	float4 MonthRenderScale = { 20,16 };
	float4 FirstMonthSetPos = { -360, -165 };

	GameEngineRender* BackgroundRender = nullptr;

	GameEngineRender* ExplainRender1 = nullptr;
	GameEngineRender* ExplainRender2 = nullptr;
	GameEngineRender* ExplainRenderShadow = nullptr;
	float4 ExplainTextBoxScale = { 300,18 };

	int LetterRenderHeight = 18;
	std::string TextType = "±¼¸²";
	COLORREF TextColor = RGB(0, 0, 0);
	COLORREF TextShadowColor = RGB(192, 120, 178);

	NumberRenderObject HoverButtonDateRender_Year = NumberRenderObject();
	float4 Pos_HoverButtonDateRender_Year = { -335, -221 };
	NumberRenderObject HoverButtonDateRender_Month = NumberRenderObject();
	float4 Pos_HoverButtonDateRender_Month = { -305, -221 };
	NumberRenderObject HoverButtonDateRender_Day = NumberRenderObject();
	float4 Pos_HoverButtonDateRender_Day = { -275, -221 };

	float4 WichButtonNotRelease();

	void SetDateNumButton();
	void SetYearRender();
	void SetWeekdayRender();
	void SetMonthRender();

	void SetExplainRender();
	
	static void SetOliveBirthDay(Button* _Btn);
};

