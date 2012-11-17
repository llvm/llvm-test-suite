/***********************************************************************
 * gcc kernel14.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 14 -- 1-D PIC (Particle In Cell)                         *
********************************************************************/
double kernel14()
{
  long   k;
  unsigned iter = 0;
  double heuristics=0.0;

  parameters (14);
  do
    {
      for ( k=0 ; k<n ; k++ )
        {
          vx[k] = 0.0;
          xx[k] = 0.0;
          ix[k] = (long) grd[k];
          xi[k] = (double) ix[k];
          ex1[k] = ex[ ix[k] - 1 ];
          dex1[k] = dex[ ix[k] - 1 ];
        }
      for ( k=0 ; k<n ; k++ )
        {
          vx[k] = vx[k] + ex1[k] + ( xx[k] - xi[k] )*dex1[k];
          xx[k] = xx[k] + vx[k]  + flx;
          ir[k] = (long)xx[k];
          rx[k] = xx[k] - ir[k];
          ir[k] = ( ir[k] & (2048-1) ) + 1;
          xx[k] = rx[k] + ir[k];
        }
      for ( k=0 ; k<n ; k++ )
        {
          rh[ ir[k]-1 ] += 1.0 - rx[k];
          rh[ ir[k]   ] += rx[k];
        }
    }
  while (iter++ < ITERATIONS);

  for ( k=0; k<n; k++ )
    heuristics += xx[k]+rh[ir[k]];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel14());
    return 0;
}
