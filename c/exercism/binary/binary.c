#include "binary.h"

int convert(const char *input)
{
    int len = 0;
    int dec = 0;
    int power=1;
    while (input[len] != '\0') len++;

    for (int i = 0; i < len; i++)
    {
        if (input[i] != '0' && input[i] != '1') 
        {
            printf("Invalid input: %c\n", input[i]);
            return INVALID;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (input[i] == '0') i++;
        else
        {
            for (int j = len-i-1; j > 0; j--)
            {
                power *=2;
            }
            dec += power;
            power = 1;
        }
    }
    return dec;
}
