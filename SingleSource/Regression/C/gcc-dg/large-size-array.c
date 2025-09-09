/* { dg-do compile } */
#include <limits.h>

#if defined(__LP64__) || defined(_WIN64)
#define DIM UINT_MAX>>1
#else
#define DIM USHRT_MAX>>1
#endif

int
sub (int *a)
{
  return a[0];
}

int
main (void)
{
  int a[DIM][DIM];  /* { dg-error "exceeds maximum object size" } */
  return sub (&a[0][0]);
}
