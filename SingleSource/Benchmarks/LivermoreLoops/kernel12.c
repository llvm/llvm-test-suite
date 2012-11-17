/***********************************************************************
 * gcc kernel12.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 12 -- first difference                                   *
********************************************************************/
double kernel12()
{
  long   k;
  unsigned iter = 0;
  double heuristics=0.0;

  parameters (12);
  do
    {
      for ( k=0 ; k<n ; k++ )
        {
          x[k] = y[k+1] - y[k];
        }
    }
  while (iter++ < ITERATIONS);

  for ( k=0; k<n; k++ )
    heuristics += x[k];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel12());
    return 0;
}
