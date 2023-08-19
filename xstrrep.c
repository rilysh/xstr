#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xstrstr.h"
#include "xmemcpy.h"

char *rstrstr(const char *haystack, const char *needle)
{
    char *occr, *buf;
    size_t idx;

    occr = strstr(haystack, needle);
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

char *xstrrep(char *src, const char *needle, const char *replace)
{
    size_t sz;
    char *str, *buf, *nbuf;

    str = xstrstr(src, needle);
    if (str == NULL)
	goto out_failed;

    sz = strlen(str) + strlen(replace) + 1UL;
    buf = calloc(sz, sizeof(char));
    if (buf == NULL)
        goto out_failed;

    strcat(buf, replace);
    sz = strlen(needle);
    /* we consume sz */
    for (; sz; sz--)
	str++;

    strcat(buf, str);
    str = rstrstr(src, needle);
    sz = strlen(str) + strlen(buf);
    nbuf = calloc(sz + 1UL, sizeof(char));
    if (nbuf == NULL) {
	free(str);
	goto out_failed;
    }

    snprintf(nbuf, sz, "%s%s", str, buf);
    free(str);
    free(buf);
    return nbuf;

out_failed:
    return strdup("calloc");
}

