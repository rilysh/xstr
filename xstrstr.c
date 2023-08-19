#include <string.h>

#include "xstrncmp.h"
#include "xstrchr.h"

char *xstrstr(const char *haystack, const char *needle)
{
    const char *p;
    size_t li;

    p = haystack;
    li = strlen(needle);

    for (; (p = xstrchr(p, *needle)); p++)
	if (xstrncmp(p, needle, li) == 0)
	    return p;
}
