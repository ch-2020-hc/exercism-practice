#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
    int len_l = sizeof(lhs);
    int len_r = sizeof(rhs)/sizeof(rhs[0]);
    int dist= 0;

    if (len_l == len_r)
    {
        for(int i = 0 ; i < len_l; i++)
        {
           if(lhs[i] == rhs[i])
           {
               dist = dist;
           }
            else
            {
                dist++; 
            }
        }
    }
    else dist =-1;
    return dist;
}

