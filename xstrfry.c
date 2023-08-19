#include <string.h>

#include "xstrfry.h"
#include "rdtsc.h"

static unsigned long long xorshift64(unsigned long long seed)
{
    unsigned long long x;

    x = seed;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;

    return x;
}

char *xstrfry(char *str)
{
    char c;
    size_t len, i, j;

    len = strlen(str);
    j = 0;

    for (i = 0; i < len - 1; i++) {
	j = xorshift64(rdtsc()) % (len - i) + i;
	c = str[i];
        str[i] = str[j];
        str[j] = c;
    }

    return str;
}
