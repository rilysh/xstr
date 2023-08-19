#include "xstrcmp.h"

int xstrcmp(const char *s1, const char *s2)
{
    do {
	if (*s1 < *s2)
	    return -1;
        if (*s1 > *s2)
	    return 1;
    } while (*s1++ && *s2++);

    return 0;
}
