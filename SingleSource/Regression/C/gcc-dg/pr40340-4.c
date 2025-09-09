/* PR middle-end/40340 */
/* { dg-do compile } */
/* { dg-options "-O2 -Wall -Wno-array-bounds -Wno-system-headers -g" } */

#define TEST3
#include "pr40340.h"

int
main (void)
{
  char buf[4];
  test3 (buf);
  return 0;
}

/* { dg-bogus "overflow" "" { target *-*-* } 10 } */
