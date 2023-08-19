#include <stdlib.h>

#include "xmemcpy.h"
#include "xrngstr.h"
#include "rdtsc.h"

#define ARRAY_SIZE(x)    (sizeof(x) / sizeof(x[0]))

static const char arr[] = {
    'A', 'B', 'C', 'D', 'E',
    'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y',
    'Z', 'a', 'b', 'c', 'd',
    'e', 'f', 'g', 'h', 'i',
    'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's',
    't', 'u', 'v', 'w', 'x',
    'y', 'z', '0', '1', '2',
    '3', '4', '5', '6', '7',
    '8', '9', '~', '!', '@',
    '#', '$', '%', '^', '&',
    '*', '(', ')', '-', '_',
    '=', '+', '|', '\\', '/',
    ':', ';', '"', '\'', '?',
    ',', '.', '<', '>', '{',
    '}', '[', ']'
};

static unsigned long long xorshift64(unsigned long long seed)
{
    unsigned long long x;

    x = seed;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;

    return x;
}

char *xrngstr(size_t len)
{
    char *buf;
    size_t n = 0;
    unsigned long long rng;

    buf = calloc(len, sizeof(char));
    if (buf == NULL)
	return NULL;

    while (len--) {
	rng = xorshift64(rdtsc()) % ARRAY_SIZE(arr);
        xmemcpy(buf + n++, &arr[rng], 1UL);
    }

    return buf;
}
