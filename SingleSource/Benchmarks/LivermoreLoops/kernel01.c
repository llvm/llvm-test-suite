/***********************************************************************
 * gcc kernel01.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 1 -- hydro fragment                                      *
********************************************************************/
double kernel01()
{
  unsigned iter = 0;
  long k;
  double heuristics=0.0;

  parameters (1);
  do
    {
      for ( k=0 ; k<n ; k++ )
        {
          x[k] = q + y[k]*( r*z[k+10] + t*z[k+11] );
        }
      
    }
  while (iter++ < ITERATIONS);

  for ( k=0; k<n; k++ )
    heuristics += x[k];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel01());
    return 0;
}
