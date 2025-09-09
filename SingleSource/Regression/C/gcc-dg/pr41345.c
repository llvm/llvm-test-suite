/* PR bootstrap/41345 */
/* { dg-do compile } */
/* { dg-options "-O2 -g -fcompare-debug" } */
/* { dg-xfail-if "AIX compare debug" { powerpc-ibm-aix* } } */

void
foo (int *x)
{
  int a;
  for (a = 0; a < 2; a++)
    if (x[a])
      goto lab;
  __builtin_unreachable ();
lab:;
}
