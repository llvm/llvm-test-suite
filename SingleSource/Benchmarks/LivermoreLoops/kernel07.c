/***********************************************************************
 * gcc kernel07.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 7 -- equation of state fragment                          *
********************************************************************/
double kernel07()
{
  long k;
  unsigned iter = 0;
  double heuristics=0.0;

  parameters (7);
  do
    {
      for ( k=0 ; k<n ; k++ )
        {
          x[k] = u[k] + r*( z[k] + r*y[k] ) +
            t*( u[k+3] + r*( u[k+2] + r*u[k+1] ) +
                t*( u[k+6] + q*( u[k+5] + q*u[k+4] ) ) );
        }
    }
  while (iter++ < ITERATIONS);

  for ( k=0; k<n; k++ )
    heuristics += x[k];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel07());
    return 0;
}
