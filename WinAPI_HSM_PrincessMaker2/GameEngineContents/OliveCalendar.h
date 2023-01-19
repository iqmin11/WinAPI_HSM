#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Date.h"
enum Week
{
	Sun,
	Mon,
	Tue,
	Wed,
	Thu,
	Fri,
	Sat
};

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
	

};

