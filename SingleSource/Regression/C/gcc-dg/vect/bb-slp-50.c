/* { dg-do compile } */
/* { dg-require-effective-target vect_double } */

double a[2];
double b[2];
double c[2];
double d[2];
double e[2];
void foo(double x)
{
  double tembc0 = b[1] + c[1];
  double tembc1 = b[0] + c[0];
  double temde0 = d[0] + e[1];
  double temde1 = d[1] + e[0];
  a[0] = tembc0 + temde0;
  a[1] = tembc1 + temde1;
}

/* We should common the permutation on the tembc{0,1} operands.  */
/* { dg-final { scan-tree-dump-times "add new stmt: \[^\\n\\r\]* = VEC_PERM_EXPR" 2 "slp2" } } */
