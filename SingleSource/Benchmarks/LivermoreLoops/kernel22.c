/***********************************************************************
 * gcc kernel22.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 22 -- Planckian distribution                             *
********************************************************************/
double kernel22()
{
  long   k;
  double heuristics=0.0;
  unsigned iter = 0;

  parameters (22);
  start_time();

  expmax = 20.0;
  u[n-1] = 0.99*expmax*v[n-1];
  do
    {
      for ( k=0 ; k<n ; k++ )
        {
          y[k] = u[k] / v[k];
          w[k] = x[k] / ( exp( y[k] ) -1.0 );
        }
    }
  while (iter++ < ITERATIONS);

  for ( k=0; k<n; k++ )
    heuristics += w[k];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel22());
    return 0;
}
