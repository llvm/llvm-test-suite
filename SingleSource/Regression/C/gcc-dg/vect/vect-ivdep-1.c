/* { dg-do compile } */
/* { dg-require-effective-target vect_int } */
/* { dg-additional-options "-O3 -fopt-info-vec-optimized" } */

/* PR other/33426 */
/* Testing whether #pragma ivdep is working.  */

void foo(int n, int *a, int *b, int *c, int *d, int *e) {
  int i, j;
#pragma GCC ivdep
  for (i = 0; i < n; ++i) {
    a[i] = b[i] + c[i];
  }
}

/* { dg-message "loop vectorized" "" { target *-*-* } 0 } */
/* { dg-bogus " version\[^\n\r]* alias" "" { target *-*-* } 0 } */
/* { dg-prune-output " version\[^\n\r]* alignment" } */
