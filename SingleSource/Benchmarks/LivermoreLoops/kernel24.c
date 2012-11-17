/***********************************************************************
 * gcc kernel24.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 24 -- find location of first minimum in array            *
********************************************************************/
double kernel24()
{
  long   k;
  unsigned iter = 0;
  double heuristics=0.0;

  parameters (24);
  x[n/2] = -1.0e+10;
  do
    {
      m24 = 0;
      for ( k=1 ; k<n ; k++ )
        {
          if ( x[k] < x[m24] ) m24 = k;
        }
      heuristics += m24;
    }
  while (iter++ < ITERATIONS);

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel24());
    return 0;
}
