/* PR rtl-optimization/63637 */
/* { dg-do compile } */
/* { dg-options "-O2" } */

int
foo (void)
{
  int a, b, c;
  asm ("# Magic instruction" : "=r" (a) : "r" (0) : "memory");
  asm ("# Magic instruction" : "=r" (b) : "r" (0) : "memory");
  asm ("# Magic instruction" : "=r" (c) : "r" (0) : "memory");
  return a + b + c;
}

/* { dg-final { scan-assembler-times "# Magic instruction" 3 } } */
