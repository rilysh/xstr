#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "xmemcpy.h"
#include "xstrdup.h"
#include "xstrchr.h"

static char *rchrchr(const char *haystack, const char needle)
{
    char *occr, *buf;
    size_t idx;

    occr = xstrchr(haystack, needle);
    if (occr == NULL)
        goto out_haystack;

    idx = (size_t)(occr - haystack);
    buf = calloc(idx + 1UL, sizeof(char));
    if (buf == NULL)
	goto out_haystack;

    xmemcpy(buf, haystack, idx);
    return buf;

out_haystack:
    return strdup(haystack);
}

char *xchrrep(char *src, const char needle, const char replace)
{
    size_t sz;
    char *str, *rstr, *nstr;

    str = xstrchr(src, needle);
    if (str == NULL)
	goto out_failed;

    str++;
    rstr = rchrchr(src, needle);
    sz = strlen(str) + strlen(rstr) + 1UL;
    nstr = calloc(sz + 1, sizeof(char));

    sprintf(nstr, "%s%c%s", rstr, replace, str);
    free(rstr);
    return nstr;

out_failed:
    return xstrdup("calloc");
}
