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
	static std::vector<Date> GetOneMonthCalendar(int _YYYY, int _MM);
	static bool IsOverMonth(int _MM);
	static bool IsOverDay(int _YYYY,  int _MM,  int _DD);
	static bool IsLeapYear(int _YYYY);
	static bool IsBigMonth(int _MM);
	static int FindFirstWeekday(int _YYYY);
	static int GetMonthLenth(int _YYYY,  int _MM);
	static std::vector<int> GetMonthLenths(int _YYYY);
	static int FindMonthFirstWeekday(int _YYYY,  int _MM);
	static Week GetWeekDay(int _YYYY, int _MM, int _DD);
	static Date GetMonthLastDate(const Date& _Date);
	

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

	void SetWeekDay();

	void SetDate(const Date& _Date)
	{
		SetDate(_Date.Year, _Date.Month, _Date.Day);
	}

	void SetDate(int _YYYY, int _MM, int _DD)
	{
		if (IsOverMonth(_MM) ||
			IsOverDay(_YYYY, _MM, _DD))
		{
			MsgAssert("입력가능한 날짜를 벗어났습니다")
		}
		Year = _YYYY;
		Month = _MM;
		Day = _DD;
		SetWeekDay();
	}

	void SetNullDate()
	{
		Year = 0;
		Month = 0;
		Day = 0;
		WeekDay = Week::Null;
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

	Date GetNextDate() const
	{
		Date CopyValue = *this;
		return ++CopyValue;
	}

	int FindFirstWeekday();

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

	Date& operator ++ ()
	{
		++Day;
		if (IsOverDay())
		{
			++Month;
			Day = 1;
			if (IsOverMonth())
			{
				++Year;
				Month = 1;
			}
		}
		SetWeekDay();

		if (IsOverDay() || IsOverMonth())
		{
			MsgAssert("입력가능한 날짜를 벗어났습니다")
		}
		return *this;
	}

	Date operator + (int _Value)
	{
		Date Result = *this;
		for (size_t i = 0; i < _Value; i++)
		{
			++Result;
		}
		/*Date Result = *this;
		if (28 < _Value)
		{
			MsgAssert("28보다 큰숫자 넣기 금지")
		}

		Result.Day += _Value;
		if (IsOverDay())
		{
			++Result.Month;
			Result.Day = 1;
			if (IsOverMonth())
			{
				++Result.Year;
				Result.Month = 1;
			}
		}
		SetWeekDay();*/
		
		return Result;
	}

protected:


private:

	int Year = 0; // 제한 없음
	int Month = 0; // 1~12
	int Day = 0; // 1~31
	
	Week WeekDay = Week::Null; // 0~6
	
	
};

