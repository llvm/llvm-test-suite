/* { dg-do compile } */
/* { dg-options "-Ofast -fdump-tree-optimized" } */
/* { dg-additional-options "-fcompare-debug" { target { ! powerpc-ibm-aix* } } } */

double
foo (double a)
{
  double tmp = 1.0f / __builtin_sqrt (a);
  return tmp * tmp;
}

/* { dg-final { scan-tree-dump-not "__builtin_sqrt" "optimized" } } */
