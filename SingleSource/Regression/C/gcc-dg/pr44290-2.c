/* { dg-do compile } */
/* { dg-require-effective-target naked_functions } */
/* { dg-options "-O2 -fdump-tree-optimized" } */

static unsigned long __attribute__((naked))
foo (unsigned long base)
{
  asm volatile ("dummy");
}
unsigned long
bar (void)
{
  static int start, set;

  if (!set)
    {
      set = 1;
      start = foo (0);
    }

  return foo (start);
}

/* { dg-final { scan-tree-dump "foo \\\(long unsigned int base\\\)" "optimized" } } */
