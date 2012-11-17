/***********************************************************************
 * gcc kernel09.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 9 -- integrate predictors                                *
********************************************************************/
double kernel09()
{
  long   i;
  unsigned iter = 0;
  double heuristics=0.0;

  parameters (9);
  do
    {
      for ( i=0 ; i<n ; i++ )
        {
          px[i][0] = dm28*px[i][12] + dm27*px[i][11] + dm26*px[i][10] +
            dm25*px[i][ 9] + dm24*px[i][ 8] + dm23*px[i][ 7] +
            dm22*px[i][ 6] + c0*( px[i][ 4] + px[i][ 5])
            + px[i][ 2];
        }
    }
  while (iter++ < ITERATIONS);

  for ( i=0; i<n; i++ )
    heuristics += px[i][0];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel09());
    return 0;
}
