/* PR target/78582. */
/* { dg-options "-fprofile-generate" } */
/* { dg-do compile } */
/* { dg-require-effective-target nonlocal_goto } */

#include <setjmp.h>

void reader_loop () {}

int
main (int argc, char argv, char env)
{
  int a;
  setjmp (0);
  argc = a = argc;
  reader_loop ();

  return 0;
}
