#pragma once
#include <vector>

#include <GameEngineBase/GameEngineDebug.h>

enum class Week
{
	SUN,
	MON,
	TUE,
	WED,
	THU,
	FRI,
	SAT
};

class Date
{
public:
	static std::vector<Date> GetOneMonthCalendar(int _YYYY, int _MM);
	static bool IsOverMonth(int _MM);
	static bool IsOverDay(int _YYYY, int _MM, int _DD);
	static bool IsLeapYear(int _YYYY);
	static bool IsBigMonth(int _MM);
	void SetWeekDay(int _YYYY, int _MM, int _DD);
	static int FindFirstWeekday(int _YYYY);
	static int GetMonthLenth(int _YYYY, int _MM);
	static std::vector<int> GetMonthLenths(int _YYYY);
	static int FindMonthFirstWeekday(int _YYYY, int _MM);

	// construtor destructor
	Date();
	~Date();

	// delete Function
	//Date(const Date& _Other) = delete;
	//Date(Date&& _Other) noexcept = delete;
	//Date& operator=(const Date& _Other) = delete;
	//Date& operator=(Date&& _Other) noexcept = delete;
	
	bool IsOverMonth();
	bool IsOverDay();
	bool IsOverWeekDay();
	bool IsLeapYear();
	void SetDate(int _YYYY, int _MM, int _DD)
	{
		if (IsOverMonth(_MM) ||
			IsOverDay(_YYYY, _MM, _DD))
		{
			MsgAssert("입력가능한 날짜를 벗어났습니다")
		}
		SetYear(_YYYY);
		SetMonth(_MM);
		SetDay(_DD);
		SetWeekDay(_YYYY, _MM, _DD);
	}
	
	int GetYear() const
	{
		return Year;
	}
	
	int GetMonth() const
	{
		return Month;
	}
	
	int GetDay() const
	{
		return Day;
	}

	Week GetWeekDay() const
	{
		return WeekDay;
	}

	int FindFirstWeekday();

protected:


private:

	unsigned int Year = 0; // 제한 없음
	unsigned int Month = 0; // 1~12
	unsigned int Day = 0; // 1~31
	Week WeekDay = Week::SUN; // 0~6
	
	void SetYear(int _YYYY)
	{
		Year = _YYYY;
	}

	void SetMonth(int _MM)
	{
		Month = _MM;
	}

	void SetDay(int _DD)
	{
		Day = _DD;
	}
};

