#if defined(__i386__) || defined(_M_I86) || defined( __amd64__) || defined(__x86_64__)
#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif
/* For x86-based (Intel, AMD) CPUs */
unsigned long long rdtsc(void)
{
    return __rdtsc();
}
/*
  ARM64 instructions stuff
  Taken from: https://github.com/gabrieleara/librdtsc/tree/master/include/librdtsc/arm

  Note: Instructions vary on CPU varient and vendor.
*/
#elif defined(__arm__) || defined(__thumb__) || defined(_M_ARM) || defined(_M_ARMT)
unsigned long long rdtsc(void)
{
    unsigned int tsc;
    unsigned long long ret;

    __asm__ __volatile__("mrc p15, 0, %0, c9, c13, 0" : "=r" (tsc));
    ret = ((unsigned long long)tsc) << 6;

    return ret;
}
#elif defined(__aarch64__) || defined(_M_ARM64)
unsigned long long rdtsc(void)
{
    unsigned long long tsc;

    __asm__ __volatile__("mrs %0, cntvct_el0" : "=r" (tsc));
    return tsc;
}
#else
#error Error: Please implement rdtsc alternative according to your platform
#endif
