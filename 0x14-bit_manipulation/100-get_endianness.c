#include <stdio.h>
#include "main.h"

int get_endianness(void) {
    int value;
    char *byte;

    value = 0x01;
    byte = (char *)&value;

    return (*byte == 0x01) ? 1 : 0;
}
