#include "luhn.h"
#include <ctype.h>
#include <stdio.h>

int main(void)
{
    const char *num = "095 245 88";
    printf("%d", luhn(num));
    return 0;
}