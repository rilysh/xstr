#include <string.h>
#include <stdlib.h>

#include "xmemcpy.h"

char *xstrdup(const char *src)
{
    size_t len = strlen(src);
    char *p = calloc(len, sizeof(char));

    xmemcpy(p, src, len);
    return p;
}
