/***********************************************************************
 * gcc kernel10.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 10 -- difference predictors                              *
********************************************************************/
double kernel10()
{
  long   i;
  double ar, br, cr;
  unsigned iter = 0;
  double heuristics=0.0;

  parameters (10);
  do
    {
      for ( i=0 ; i<n ; i++ )
        {
          ar        =      cx[i][ 4];
          br        = ar - px[i][ 4];
          px[i][ 4] = ar;
          cr        = br - px[i][ 5];
          px[i][ 5] = br;
          ar        = cr - px[i][ 6];
          px[i][ 6] = cr;
          br        = ar - px[i][ 7];
          px[i][ 7] = ar;
          cr        = br - px[i][ 8];
          px[i][ 8] = br;
          ar        = cr - px[i][ 9];
          px[i][ 9] = cr;
          br        = ar - px[i][10];
          px[i][10] = ar;
          cr        = br - px[i][11];
          px[i][11] = br;
          px[i][13] = cr - px[i][12];
          px[i][12] = cr;
        }
      heuristics += px[i][11]+px[i][12];
    }
  while (iter++ < ITERATIONS);

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel10());
    return 0;
}
