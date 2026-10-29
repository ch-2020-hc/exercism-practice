#include "hamming.h"
#include <stdio.h>

int main(void)
{
    const char *lhs = "GTC";
    const char *rhs = "CT";
    printf("%d\n", sizeof(rhs));
    printf("%d\n", compute(lhs, rhs));
    return 0;
}