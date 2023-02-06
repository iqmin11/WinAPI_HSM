#include "Date.h"
#include <GameEngineBase/GameEngineDebug.h>


std::vector<Date> Date::GetOneMonthCalendar(int _YYYY, int _MM)
{
    std::vector<Date> Result = std::vector<Date>();

    if (IsOverMonth(_MM))
    {
        MsgAssert("입력 가능한 Month의 범위를 벗어났습니다")
    }
    if (IsBigMonth(_MM))
    {
        Result.resize(31);
    }
    else if (2 == _MM)
    {
        if (IsLeapYear(_YYYY))
        {
            Result.resize(29);
        }
        else
        {
            Result.resize(28);
        }
    }
    else
    {
        Result.resize(30);
    }


    for (int i = 0; i < Result.size(); i++)
    {
        Result[i].SetDate(_YYYY, _MM, i + 1);
    }

    return Result;
}

Date::Date()
{

}

Date::~Date()
{

}

bool Date::IsOverMonth()
{
    if (0 < Month && 13 > Month)
    {
        return false;
    }
    return true;
}

bool Date::IsOverMonth(int _MM)
{
    if (0 < _MM && 13 > _MM)
    {
        return false;
    }
    return true;
}

bool Date::IsOverDay()
{
    if (1 == Month ||
        3 == Month || 
        5 == Month || 
        7 == Month || 
        8 == Month || 
        10 == Month || 
        12 == Month )
    {
        if (0 < Day && 32 > Day)
        {
            return false;
        }
        return true;
    }
    else if (4 == Month ||
        6 == Month || 
        9 == Month || 
        11 == Month) 
    {
        if (0 < Day && 31 > Day)
        {
            return false;
        }
        return true;
    }
    else
    {
        if (IsLeapYear())
        {
            if (0 < Day && 30 > Day)
            {
                return false;
            }
            return true;
        }
        else
        {
            if (0 < Day && 29 > Day)
            {
                return false;
            }
            return true;
        }
    }

    return false;
}

bool Date::IsOverDay(int _YYYY, int _MM, int _DD)
{
    if (1 == _MM ||
        3 == _MM ||
        5 == _MM ||
        7 == _MM ||
        8 == _MM ||
        10 == _MM ||
        12 == _MM)
    {
        if (0 < _DD && 32 > _DD)
        {
            return false;
        }
        return true;
    }
    else if (4 == _MM ||
        6 == _MM ||
        9 == _MM ||
        11 == _MM)
    {
        if (0 < _DD && 31 > _DD)
        {
            return false;
        }
        return true;
    }
    else
    {
        if (IsLeapYear(_YYYY))
        {
            if (0 < _DD && 30 > _DD)
            {
                return false;
            }
            return true;
        }
        else
        {
            if (0 < _DD && 29 > _DD)
            {
                return false;
            }
            return true;
        }
    }

    return false;;
}



bool Date::IsOverWeekDay()
{
    if (0 <= Month && 7 > Month)
    {
        return false;
    }
    return true;
}

bool Date::IsLeapYear() // 윤년이니?
{
    if ((0 == (Year % 4) && 0 != (Year % 100)) || 0 == (Year % 400))
    {
        return true;
    }
    return false;
}

bool Date::IsLeapYear(int _YYYY)
{
    if ((0 == (_YYYY % 4) && 0 != (_YYYY % 100)) || 0 == (_YYYY % 400))
    {
        return true;
    }
    return false;
}

bool Date::IsBigMonth(int _MM)
{
    if (1 == _MM ||
    3  == _MM ||
    5  == _MM ||
    7  == _MM ||
    8  == _MM ||
    10 == _MM ||
    12 == _MM)
    {
        return true;
    }
    return false;
}

void Date::SetWeekDay(int _YYYY, int _MM, int _DD)
{
    int WholeDay = 0;
    for (int MM = 1; MM <= _MM; MM++)
    {
        if (MM == _MM)
        {
            for (int DD = 1; DD < _DD; DD++)
            {
                WholeDay++;
            }
            WeekDay = static_cast<Week>((WholeDay + FindFirstWeekday(_YYYY)) % 7);
            return;
        }
        else
        {
            for (int DD = 1; !IsOverDay(_YYYY, MM, DD); DD++)
            {
                WholeDay++;
            }
        }
    }
}

int Date::FindFirstWeekday(int _YYYY)
{
    int PrevYear = _YYYY - 1;
    return (PrevYear + ((PrevYear / 4) - (PrevYear / 100) + (PrevYear / 400)) + 1) % 7;
}

int Date::GetMonthLenth(int _YYYY, int _MM)
{
    if (IsOverMonth(_MM))
    {
        MsgAssert("입력 가능한 Month의 범위를 벗어났습니다")
    }

    if (IsBigMonth(_MM))
    {
        return 31;
    }
    else if (2 == _MM)
    {
        if (IsLeapYear(_YYYY))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else
    {
        return 30;
    }
}

std::vector<int> Date::GetMonthLenths(int _YYYY)
{
    std::vector<int> Result = std::vector<int>();
    Result.resize(12);
    for (int i = 0; i < Result.size(); i++)
    {
        Result[i] = GetMonthLenth(_YYYY, i + 1);
    }
    return Result;
}



int Date::FindFirstWeekday()
{
    int PrevYear = Year - 1;
    return (PrevYear + ((PrevYear / 4) - (PrevYear / 100) + (PrevYear / 400)) + 1) % 7;
}

