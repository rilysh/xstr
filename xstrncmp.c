#include "xstrncmp.h"

/* Based on musl implementation */
int xstrncmp(const char *s1, const char *s2, size_t n)
{
    if (!n--)
	return 0;

    for (; *s1 && *s2 && n && *s1 == *s2; s1++, s2++, n--);
    return *s1 - *s2;
}
