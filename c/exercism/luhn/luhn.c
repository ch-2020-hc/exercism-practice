#include "luhn.h"
#include <ctype.h>
#include <stdlib.h>


bool luhn(const char *num)
{
    int size = 0;
    int sum = 0;
    int count = 0; // count of spaces
    int str;
    int j= 0;

    if (!*num) return false;

    while(num[size] != '\0') 
    {
        if(isspace(num[size])) 
        {
            count++;
            size++;
        }
        
        if (!isdigit(num[size]))
        {
            return false;
        }
        size++;
    }
    
    for(int i = 0; i < size ; ++i)
    {
        if(isspace(num[i])) 
        {
            j++;
            i++;
        }
        if ((size - count) % 2 == 0) // total chars without space are even
        {
            if ((i-j) % 2 == 0) // xth of element without spaces
            {
                str = (num[i] - '0') * 2;
                if (str > 9)
                {
                    str = str - 9; 
                }
            }
            else
            {
                str = num[i] - '0';
            }
        }
        else
        {
            if ((i-j+1) % 2 == 0) // xth of element, when total chars is odd
            {
                str = (num[i] - '0') * 2;
                if (str > 9)
                {
                    str = str - 9; 
                }
            }
            else
            {
                str = num[i] - '0';
            }
        }
            
        sum = sum + str;  
    }

    if ((size-count) == 1 && sum == 0) return false;
    else if(sum%10 == 0) return true;
    else return false;    
}

