#include "Date.h"

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

bool Date::IsLeapYear() // ¿±≥‚¿Ã¥œ?
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

int Date::FindFirstWeekday()
{
    int PrevYear = Year - 1;
    return (PrevYear + ((PrevYear / 4) - (PrevYear / 100) + (PrevYear / 400)) + 1) % 7;
}

