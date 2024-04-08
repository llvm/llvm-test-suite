/* { dg-do compile { target vect_int } } */
/* { dg-additional-options "-std=c99 -fopt-info-vec -O3" } */

void
vadd (int *dst, int *op1, int *op2, int count)
{
/* { dg-prune-output " version\[^\n\r]* alignment" } */
/* { dg-optimized "21: loop vectorized" "" { target *-*-* } .+2 } */
/* { dg-optimized "21: loop versioned for vectorization because of possible aliasing" "" { target *-*-* } .+1 } */
  for (int i = 0; i < count; ++i)
    dst[i] = op1[i] + op2[i];
}
