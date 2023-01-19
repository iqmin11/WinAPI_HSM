#pragma once
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
	bool IsOverDay();
	bool IsOverDay(int _YYYY, int _MM, int _DD);
	bool IsOverWeekDay();
	bool IsLeapYear();
	bool IsLeapYear(int _YYYY);

	void SetDate(int _YYYY, int _MM, int _DD)
	{
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

	int GetWeekDay() const
	{
		return WeekDay;
	}

	int FindFirstWeekday();

protected:


private:

	int Year = 0; // 제한 없음
	int Month = 0; // 1~12
	int Day = 0; // 1~31
	int WeekDay = 0; // 0~6
	int FindFirstWeekday(int _YYYY);

};

