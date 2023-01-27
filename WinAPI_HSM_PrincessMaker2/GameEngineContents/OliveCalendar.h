#pragma once
#include <GameEngineCore/GameEngineActor.h>
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

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

	//void CreateCalendar(int _year);

	void DateNumRender();
	void YearNumRender();
	void WeekdayRender();
	void MonthNumRender();
	
	
	bool IsLeapYear();

protected:


private:
	int CalendarYear = 0;
	Date OliveBirth = Date();
	int FindFirstWeekday();

	GameEngineRender* DateRender[4][3][6][7] = {}; //달력 열, 행, 날짜 열, 행
	GameEngineRender* WeekRender[4][3] = {}; //달력 열, 행, 날짜 열, 행
	GameEngineRender* YearRender[4][3][4] = {}; // 달력 열, 행, 년도 네글자
	GameEngineRender* MonthRender[4][3] = {}; // 달력 열, 행 
	GameEngineRender* BackgroundRender = nullptr;
};

