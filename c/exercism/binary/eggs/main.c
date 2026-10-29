#include "eliuds_eggs.h"
#include <stdio.h>

int main(void)
{
    int value = 13;
    printf("Egg count for %d: %d\n", value, egg_count(value));
    return 0;
}