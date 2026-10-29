#include "clock.h"
#include "string.h"
#include "stdlib.h"


clock_t clock_create(int hour, int minute)
{
    clock_t clock;
    char t[MAX_STR_LEN];
    
    hour += minute / 60;
    minute = minute % 60;

    if (hour >= 24)
    {
        hour = hour % 24;
    }
    while (hour < 0) hour += 24;

    while (minute < 0) 
    {
        minute += 60;
        hour -= 1;
    }
    
    int quo_h = hour / 10;
    int rem_h = hour % 10;
    t[0] = quo_h + '0';
    t[1] = rem_h + '0';
    t[2] = ':';
    int quo_m = minute / 10;
    int rem_m = minute % 10;
    t[3] = quo_m + '0';
    t[4] = rem_m + '0';

    strcpy(clock.text, t);
    return clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
    char t[MAX_STR_LEN];
    strcpy(t, clock.text);

    int hour = 0;
    int min = 0;

    hour = (t[0]-'0') * 10 + (t[1]-'0');
    min = (t[3]-'0') *10 + (t[4]-'0');

    min += minute_add;

    hour += min /60;
    min = min % 60;

    return clock_create(hour, min);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    char t[MAX_STR_LEN];
    strcpy(t, clock.text);

    int hour = 0;
    int min = 0;

    hour = (t[0]-'0') * 10 + (t[1]-'0');
    min = (t[3]-'0') *10 + (t[4]-'0');

    min -= minute_subtract;
    while (min < 0)
    {
        min += 60;
        hour -= 1;
    }

    return clock_create(hour, min);
}
bool clock_is_equal(clock_t a, clock_t b)
{
    bool isEqual = true;
    for (size_t i = 0; i < MAX_STR_LEN; ++i)
    {
        if (a.text[i] != b.text[i])
        {
            isEqual = false;
            break;
        }
    }
    return isEqual;
}

