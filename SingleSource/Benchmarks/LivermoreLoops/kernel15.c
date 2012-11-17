/***********************************************************************
 * gcc kernel15.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 15 -- Casual Fortran.  Development version               *
********************************************************************/
double kernel15()
{
  double ar, br;
  long   j, k;
  long   ng, nz;
  unsigned iter = 0;
  double heuristics=0.0;

  parameters (15);
  do
    {
      ng = 7;
      nz = n;
      ar = 0.053;
      br = 0.073;
      for ( j=1 ; j<ng ; j++ )
        {
          for ( k=1 ; k<nz ; k++ )
            {
              if ( (j+1) >= ng )
                {
                  vy[j][k] = 0.0;
                  continue;
                }
              if ( vh[j+1][k] > vh[j][k] )
                {
                  t = ar;
                }
              else
                {
                  t = br;
                }
              if ( vf[j][k] < vf[j][k-1] )
                {
                  if ( vh[j][k-1] > vh[j+1][k-1] )
                    r = vh[j][k-1];
                  else
                    r = vh[j+1][k-1];
                  s = vf[j][k-1];
                }
              else
                {
                  if ( vh[j][k] > vh[j+1][k] )
                    r = vh[j][k];
                  else
                    r = vh[j+1][k];
                  s = vf[j][k];
                }
              vy[j][k] = sqrt( vg[j][k]*vg[j][k] + r*r )* t/s;
              if ( (k+1) >= nz )
                {
                  vs[j][k] = 0.0;
                  continue;
                }
              if ( vf[j][k] < vf[j-1][k] )
                {
                  if ( vg[j-1][k] > vg[j-1][k+1] )
                    r = vg[j-1][k];
                  else
                    r = vg[j-1][k+1];
                  s = vf[j-1][k];
                  t = br;
                }
              else
                {
                  if ( vg[j][k] > vg[j][k+1] )
                    r = vg[j][k];
                  else
                    r = vg[j][k+1];
                  s = vf[j][k];
                  t = ar;
                }
              vs[j][k] = sqrt( vh[j][k]*vh[j][k] + r*r )* t / s;
            }
        }
    }
  while (iter++ < ITERATIONS);

  for ( j=0; j<ng; j++ )
    for ( k=0; k<nz; k++ )
      heuristics += vs[j][k];;

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel15());
    return 0;
}
