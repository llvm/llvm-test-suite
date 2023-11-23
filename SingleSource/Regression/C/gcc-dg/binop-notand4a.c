/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-optimized" } */

int
foo (unsigned char a, _Bool b)
{
  return (!a & a) | (b & !b);
}

/* As long as comparisons aren't boolified and casts from boolean-types
   aren't preserved, the folding of  X & !X to zero fails.  */
/* { dg-final { scan-tree-dump-times "return 0" 1 "optimized" { xfail *-*-* } } } */
