/***********************************************************************
 * gcc kernel23.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 23 -- 2-D implicit hydrodynamics fragment                *
********************************************************************/
double kernel23()
{
  long   j, k;
  double qa;
  double heuristics=0.0;
  unsigned iter = 0;
     
  parameters (23);
  do
    {
      for ( j=1 ; j<6 ; j++ )
        {
          for ( k=1 ; k<n ; k++ )
            {
              qa = za[j+1][k]*zr[j][k] + za[j-1][k]*zb[j][k] +
                za[j][k+1]*zu[j][k] + za[j][k-1]*zv[j][k] + zz[j][k];
              za[j][k] += 0.175*( qa - za[j][k] );
            }
        }
    }
  while (iter++ < ITERATIONS);

  for ( j=0; j<6; j++ )
    for ( k=0; k<n; k++ )
      heuristics += za[j][k];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel23());
    return 0;
}
