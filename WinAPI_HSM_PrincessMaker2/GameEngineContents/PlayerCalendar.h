#pragma once
#include <GameEngineCore/GameEngineActor.h>
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

	void Start() override;
	void Update(float _DeltaTime) override;
	void Render(float _DeltaTime) override;

	//void CreateCalendar(int _year);

	void DateNumRender();
	void YearNumRender();
	void WeekdayRender();
	void MonthNumRender();


	bool IsLeapYear();
	bool IsLeapYear(int _YYYY);

	void SetOliveBirth(); // юс╫ц

protected:


private:
	Date OliveBirth = Date();
	Date PlayerBirth = Date();
	int CalendarYear = 2023;
	int FindFirstWeekday();
	int FindFirstWeekday(int _YYYY);
	int FindMonthFirstWeekday(int _YYYY, int _MM);

};

