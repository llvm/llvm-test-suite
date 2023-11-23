/* PR middle-end/11151 */
/* Originator: Andrew Church <gcczilla@achurch.org> */
/* { dg-do run } */
/* { dg-xfail-run-if "PR36571 untyped return is char register" { "avr-*-*" } } */
/* { dg-require-effective-target untyped_assembly } */
/* This used to fail on SPARC because the (undefined) return
   value of 'bar' was overwriting that of 'foo'.  */

extern void abort(void);

int foo(int n)
{
  return n+1;
}

int bar(int n)
{
  __builtin_return(__builtin_apply((void (*)(void))foo, __builtin_apply_args(), 64));
}

char *g;

int main(void)
{
  /* Allocate 64 bytes on the stack to make sure that __builtin_apply
     can read at least 64 bytes above the return address.  */
  char dummy[64];

  g = dummy;

  if (bar(1) != 2)
    abort();

  return 0;
}
