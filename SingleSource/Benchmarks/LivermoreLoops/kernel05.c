/***********************************************************************
 * gcc kernel05.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 5 -- tri-diagonal elimination, below diagonal            *
********************************************************************/
double kernel05()
{
  long   i;
  unsigned iter = 0;
  double heuristics=0.0;

  parameters (5);
  do
    {
      for ( i=1 ; i<n ; i++ )
        {
          x[i] = z[i]*( y[i] - x[i-1] );
        }
    }
  while (iter++ < ITERATIONS);

  for ( i=0; i<n; i++ )
    heuristics += x[i];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel05());
    return 0;
}
