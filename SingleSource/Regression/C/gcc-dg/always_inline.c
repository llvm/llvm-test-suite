/* { dg-do compile } */
/* { dg-options "-O2 -fgnu89-inline" } */
#include <stdarg.h>
inline __attribute__ ((always_inline)) void
e(int t, ...) /* { dg-error "variable argument lists" } */
{
  va_list q;
  va_start (q, t);
}
