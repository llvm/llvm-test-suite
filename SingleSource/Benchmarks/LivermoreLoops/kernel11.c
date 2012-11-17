/***********************************************************************
 * gcc kernel11.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 11 -- first sum                                          *
********************************************************************/
double kernel11()
{
  long   k;
  unsigned iter = 0;
  double heuristics=0.0;

  parameters (11);
  do
    {
      x[0] = y[0];
      for ( k=1 ; k<n ; k++ )
        {
          x[k] = x[k-1] + y[k];
        }
    }
  while (iter++ < ITERATIONS);

  for ( k=0; k<n; k++ )
    heuristics += x[k];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel11());
    return 0;
}
