#pragma once
#include <vector>

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
	// construtor destructor
	Date();
	~Date();

	// delete Function
	Date(const Date& _Other) = delete;
	Date(Date&& _Other) noexcept = delete;
	Date& operator=(const Date& _Other) = delete;
	Date& operator=(Date&& _Other) noexcept = delete;
	
	bool IsOverMonth();
	bool IsOverMonth(int _MM);
	bool IsOverDay();
	bool IsOverDay(int _YYYY, int _MM, int _DD);
	bool IsOverWeekDay();
	bool IsLeapYear();
	bool IsLeapYear(int _YYYY);

	void SetDate(int _YYYY, int _MM, int _DD)
	{
		IsOverMonth(_MM);
		IsOverDay(_YYYY, _MM, _DD);
		SetYear(_YYYY);
		SetMonth(_MM);
		SetDay(_DD);
		SetWeekDay(_YYYY, _MM, _DD);
	}

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

	void SetWeekDay(int _YYYY, int _MM, int _DD);
	
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
	int FindFirstWeekday(int _YYYY);

};

