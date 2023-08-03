#include <stdio.h>
#include "main.h"

int get_endianness(void)
{
    int value = 0x01;
    char *byte = (char *)&value;
    return (*byte == 0x01) ? 1 : 0;
}
