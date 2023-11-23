/* { dg-do run } */
/* { dg-options "-O -ffast-math -fdump-tree-optimized" } */

extern double sqrt (double);
extern double pow (double, double);
extern void abort (void);

int main ()
{
  double x = -1.0;
  if (sqrt (pow (x, 2)) != 1.0)
    abort();
  if (sqrt (x*x) != 1.0)
    abort();
  return 0;
}

/* { dg-final { scan-tree-dump-times "sqrt" 0 "optimized" } } */
/* { dg-final { scan-tree-dump-times "pow" 0 "optimized" } } */
