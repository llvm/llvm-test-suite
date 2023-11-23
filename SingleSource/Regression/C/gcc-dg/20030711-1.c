/* Test whether strncmp has not been "optimized" into memcmp
   nor any code with memcmp semantics.  */
/* { dg-do run { target mmap } } */
/* { dg-options "-O2" } */
#include <stddef.h>
#include <stdio.h>
#include <sys/mman.h>
#ifndef MAP_ANONYMOUS
#define MAP_ANONYMOUS MAP_ANON
#endif
#ifndef MAP_ANON
#define MAP_ANON 0
#endif
#ifndef MAP_FAILED
#define MAP_FAILED ((void *)-1)
#endif
#include <stdlib.h>

void __attribute__((noinline)) test (const char *p)
{
  if (__builtin_strncmp (p, "abcdefghijklmnopq", 17) == 0)
    abort ();
}

int main (void)
{
  char *p = mmap (NULL, 131072, PROT_READ | PROT_WRITE,
                  MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  if (p == MAP_FAILED)
    return 0;
  if (munmap (p + 65536, 65536) < 0)
    return 0;
  __builtin_memcpy (p + 65536 - 5, "abcd", 5);
  test (p + 65536 - 5);
  return 0;
}
