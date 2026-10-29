#include "eliuds_eggs_v2.h"

int egg_count_v2(int value)
{
    int count = 0;

    while (value > 0)
    {
        if (value % 2 != 0) count++;
        value /= 2;
    }
    return count;
}