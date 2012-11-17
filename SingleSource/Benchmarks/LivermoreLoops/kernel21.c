/***********************************************************************
 * gcc kernel21.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 21 -- matrix*matrix product                              *
********************************************************************/
double kernel21()
{
  long   i, j, k;
  double heuristics=0.0;
  unsigned iter = 0;

  parameters (21);
  do
    {
      for ( k=0 ; k<25 ; k++ )
        {
          for ( i=0 ; i<25 ; i++ )
            {
              for ( j=0 ; j<n ; j++ )
                {
                  px[j][i] += vy[k][i] * cx[j][k];
                }
            }
        }
    }
  while (iter++ < ITERATIONS/10); /* this one takes a while! */

  /* Inverse order iteration on purpose */
  for ( j=0; j<n; j++ )
    for ( k=0; k<25; k++ )
      heuristics += px[j][k];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel21());
    return 0;
}
