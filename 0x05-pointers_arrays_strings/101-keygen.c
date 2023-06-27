#include <stdio.h>
#include <stdint.h>

int64_t checksum(char **arg1)
{
    char **var_18h;
    int64_t var_8h;

    var_8h = 0;
    for (var_18h = arg1; *(char *)var_18h != '\0'; var_18h = (char **)((int64_t)var_18h + 1)) {
        var_8h = var_8h + *(char *)var_18h;
    }
    return var_8h;
}
