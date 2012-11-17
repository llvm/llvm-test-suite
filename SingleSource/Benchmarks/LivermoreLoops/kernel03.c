/***********************************************************************
 * gcc kernel03.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 3 -- inner product                                       *
********************************************************************/
double kernel03()
{
  long k;
  unsigned iter = 0;
  double heuristics=0.0;

  parameters (3);
  do
    {
      q = 0.0;
      for ( k=0 ; k<n ; k++ )
        {
          q += z[k]*x[k];
        }
      heuristics += q;
    }
  while (iter++ < ITERATIONS);

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel03());
    return 0;
}
