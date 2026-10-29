#include "eliuds_eggs.h"

int egg_count(int value)
{
    // char *egg[] = (char*)malloc(sizeof(char)*length);
    int count = 0;
    int power = 0;
    int x = 1;

    while (value != 0)
    {
        if (value % 2 != 0)
        {
            value = value -1;
            count += 1;
        }
        else
        {
            int temp = value;
            while (temp != 0)
            {
                while (temp % 2 == 0)
                {
                    temp /= 2;
                    power += 1;
                }
                if (power > 0) count += 1;
    
                while (power >0)
                {
                    x = x*2;
                    power--;  
                }
                value = value - x;
                x =1;
                temp = value;
            }
        }
    }
    return count;
}

