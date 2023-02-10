#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/Button.h>
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


	void DateNumButtonSet();
	void YearNumRender();
	void WeekdayRender();
	void MonthNumRender();



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
	Date PlayerBirth = Date();
	int CalendarYear = 2023;

	Button* DateButton[4][3][6][7] = {}; //달력 열, 행, 날짜 열, 행
	GameEngineRender* WeekRender[4][3] = {}; //달력 열, 행, 날짜 열, 행
	GameEngineRender* YearRender[4][3][4] = {}; // 달력 열, 행, 년도 네글자
	GameEngineRender* MonthRender[4][3] = {}; // 달력 열, 행 
	GameEngineRender* BackgroundRender = nullptr;
};

