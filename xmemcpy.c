#include <stddef.h>

#include "xmemcpy.h"

void *xmemcpy(void *dst, const void *src, size_t len)
{
    const unsigned char *s = src;
    unsigned char *d = dst;

    while (len--)
	*d++ = *s++;

    return (void *)d;
}
