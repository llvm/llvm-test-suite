/***********************************************************************
 * gcc kernel06.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 6 -- general linear recurrence equations                 *
********************************************************************/
double kernel06()
{
  long i, k;
  unsigned iter = 0;
  double heuristics=0.0; 

  parameters (6);
  do
    {
      for ( i=1 ; i<n ; i++ )
        {
          w[i] = 0.01;
          for ( k=0 ; k<i ; k++ )
            {
              w[i] += b[k][i] * w[(i-k)-1];
            }
        }
    }
  while (iter++ < ITERATIONS);

  for ( i=0; i<n; i++ )
    heuristics += w[i];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel06());
    return 0;
}
