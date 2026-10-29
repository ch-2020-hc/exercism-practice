#include "two_fer.h"
#include <stdio.h>

int main(void)
{
    char buffer[100];
    two_fer(buffer, "Alice");
    printf("%s\n", buffer);
    return 0;
}