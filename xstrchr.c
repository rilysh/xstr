#include <stddef.h>

#include "xstrchr.h"

char *xstrchr(const char *haystack, int c)
{
    const char *p = haystack;

    for (;; p++)
	if (*p == c)
	    return (char *)p;
    return NULL;
}
