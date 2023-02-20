#pragma once
#include <vector>

#include <GameEngineBase/GameEngineDebug.h>

enum class Week
{
	Null = -1,
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
	static std::vector<Date> GetOneMonthCalendar(unsigned int _YYYY, unsigned  int _MM);
	static bool IsOverMonth(unsigned int _MM);
	static bool IsOverDay(unsigned int _YYYY, unsigned  int _MM, unsigned  int _DD);
	static bool IsLeapYear(unsigned int _YYYY);
	static bool IsBigMonth(unsigned int _MM);
	void SetWeekDay(unsigned int _YYYY, unsigned  int _MM, unsigned  int _DD);
	static unsigned int FindFirstWeekday(unsigned int _YYYY);
	static unsigned int GetMonthLenth(unsigned int _YYYY, unsigned  int _MM);
	static std::vector<unsigned int> GetMonthLenths(unsigned int _YYYY);
	static unsigned int FindMonthFirstWeekday(unsigned int _YYYY, unsigned  int _MM);


	// construtor destructor
	Date();
	Date(int _YYYY, int _MM, int _DD);
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
	bool IsNullDate()
	{
		if (Year  == 0||
			Month == 0||
			Day	  == 0)
		{
			return true;
		}
		return false;

	}

	void SetDate(unsigned int _YYYY, unsigned int _MM, unsigned int _DD)
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

	void SetNullDate()
	{
		Year = 0;
		Month = 0;
		Day = 0;
		WeekDay = Week::Null;
	}
	
	unsigned int GetYear() const
	{
		return Year;
	}
	
	unsigned int GetMonth() const
	{
		return Month;
	}
	
	unsigned int GetDay() const
	{
		return Day;
	}

	Week GetWeekDay() const
	{
		return WeekDay;
	}

	unsigned int FindFirstWeekday();

	bool operator== (const Date& _date)
	{
		return Year == _date.Year && Month == _date.Month && Day == _date.Day;
	}

	bool operator!= (const Date& _date)
	{
		return Year != _date.Year || Month != _date.Month || Day != _date.Day;
	}

	bool operator> (const Date& _date)
	{
		if (Year > _date.Year)
		{
			return true;
		}
		else if (Year < _date.Year)
		{
			return false;
		}
		else
		{
			if (Month > _date.Month)
			{
				return true;
			}
			else if (Month < _date.Month)
			{
				return false;
			}
			else
			{
				if (Day > _date.Day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}

	bool operator< (const Date& _date)
	{
		if (Year < _date.Year)
		{
			return true;
		}
		else if (Year > _date.Year)
		{
			return false;
		}
		else
		{
			if (Month < _date.Month)
			{
				return true;
			}
			else if (Month > _date.Month)
			{
				return false;
			}
			else
			{
				if (Day < _date.Day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}

	bool operator>= (const Date& _date)
	{
		return *this == _date || *this > _date;
	}

	bool operator<= (const Date& _date)
	{
		return *this == _date || *this < _date;
	}

protected:


private:

	unsigned int Year = 0; // 제한 없음
	unsigned int Month = 0; // 1~12
	unsigned int Day = 0; // 1~31
	
	Week WeekDay = Week::Null; // 0~6
	
	void SetYear(unsigned int _YYYY)
	{
		Year = _YYYY;
	}

	void SetMonth(unsigned int _MM)
	{
		Month = _MM;
	}

	void SetDay(unsigned int _DD)
	{
		Day = _DD;
	}
};

