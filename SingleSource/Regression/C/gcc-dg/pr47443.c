/* PR tree-optimization/47443 */
/* { dg-do compile } */
/* { dg-require-stack-check "generic" } */
/* { dg-options "-O -fstack-check=generic" } */

static inline int bar (char *c, int i)
{
  return c + i > c;
}

int foo ()
{
  char c[100];
  return (bar (c, 1));
}
