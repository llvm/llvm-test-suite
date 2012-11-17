/***********************************************************************
 * gcc kernel20.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/*************************************************************************
* Kernel 20 - Discrete ordinates transport, conditional recurrence on xx *
*************************************************************************/
double kernel20()
{
  long   k;
  double di, dn;
  double heuristics=0.0;
  unsigned iter = 0;

  parameters (20);
  do
    {
      for ( k=0 ; k<n ; k++ )
        {
          di = y[k] - g[k] / ( xx[k] + dk );
          dn = 0.2;

          if ( di )
            {
              dn = z[k]/di ;
              if ( t < dn ) dn = t;
              if ( s > dn ) dn = s;
            }
          x[k] = ( ( w[k] + v[k]*dn )* xx[k] + u[k] ) / ( vx[k] + v[k]*dn );
          xx[k+1] = ( x[k] - xx[k] )* dn + xx[k];
        }
    }
  while (iter++ < ITERATIONS);

  for ( k=0; k<n; k++ )
    heuristics += x[k] + xx[k];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel20());
    return 0;
}
