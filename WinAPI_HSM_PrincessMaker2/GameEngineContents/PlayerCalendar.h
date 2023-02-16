#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>
#include <GameEngineCore/NumberRenderObject.h>

#include "Button_Date.h"
#include "Date.h"


class PlayerCalendar : public GameEngineActor
{
public:
	// construtor destructor
	PlayerCalendar();
	~PlayerCalendar();

	// delete Function
	PlayerCalendar(const PlayerCalendar& _Other) = delete;
	PlayerCalendar(PlayerCalendar&& _Other) noexcept = delete;
	PlayerCalendar& operator=(const PlayerCalendar& _Other) = delete;
	PlayerCalendar& operator=(PlayerCalendar&& _Other) noexcept = delete;

	void SetOliveBirth(int _YYYY, int _MM, int _DD); // 임시
	void SetCalendarYear(int _YYYY);// 임시

	void On() override;
	void Off() override;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;


private:
	Date OliveBirth = Date();
	int CalendarYear = 0;
	Date PlayerBirth = Date();

	float4 EcahMonthCalendarInterval = { 250 , 105 };

	Button_Date* DateButton[4][3][6][7] = {}; //달력 열, 행, 날짜 열, 행
	float4 DateButtonScale = { 20,14 };
	float4 FirstDaySetPos = { -330, -177 };
	float4 EachDayNumInterval = { 30,15 };
	
	GameEngineRender* WeekRender[4][3] = {}; //달력 열, 행, 날짜 열, 행
	float4 WeekRenderScale = { 210,10 };
	float4 FirstWeekSetPos = { -235, -192 };

	GameEngineRender* YearRender[4][3][4] = {}; // 달력 열, 행, 년도 네글자
	float4 YearRenderScale = { 8,12 };
	float4 FirstYearSetPos = { -370, -182 };

	GameEngineRender* MonthRender[4][3] = {}; // 달력 열, 행 
	float4 MonthRenderScale = { 20,16 };
	float4 FirstMonthSetPos = { -360, -165};
	
	
	GameEngineRender* BackgroundRender = nullptr;

	GameEngineRender* ExplainRender1 = nullptr;
	GameEngineRender* ExplainRender2 = nullptr;
	GameEngineRender* ExplainRenderShadow = nullptr;
	int LetterRenderHeight = 18;
	std::string TextType = "굴림";
	COLORREF TextColor = RGB(0, 0, 0);
	COLORREF TextShadowColor = RGB(106, 170, 126);
	
	NumberRenderObject HoverButtonDateRender_Year = NumberRenderObject();
	float4 Pos_HoverButtonDateRender_Year = {-335, -221};
	NumberRenderObject HoverButtonDateRender_Month = NumberRenderObject();
	float4 Pos_HoverButtonDateRender_Month = {-305, -221};
	NumberRenderObject HoverButtonDateRender_Day = NumberRenderObject();
	float4 Pos_HoverButtonDateRender_Day = {-275, -221};

	bool FirstUpdate = false;

	float4 WichButtonNotRelease();

	void SetDateNumButton();
	void UpdateDateNumButton();

	void SetYearRender();
	void UpdateYearRender();

	void SetWeekdayRender();
	
	void SetMonthRender();
	void UpdateMonthRender();

	void SetExplainRender();

	static void SetPlayerBirthDay(Button* _Btn);
};

