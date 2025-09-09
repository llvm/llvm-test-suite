/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized" } */

void f (void*);

void g (char *a)
{
  __builtin_memset (a, 0, 8);
  __builtin_memset (a, 0, 8);

  f (a);
}

void h (char *a)
{
  __builtin_memset (a, 0, 8);
  __builtin_memset (a, 0, 7);

  f (a);
}

/* { dg-final { scan-tree-dump-times "__builtin_memset" 2 "optimized" } } */
