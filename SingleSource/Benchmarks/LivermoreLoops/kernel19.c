/***********************************************************************
 * gcc kernel19.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 19 -- general linear recurrence equations                *
********************************************************************/
double kernel19()
{
  long   i, k;
  long   kb5i;
  double heuristics=0.0;
  unsigned iter = 0;

  parameters (19);
  kb5i = 0;
  do
    {
      for ( k=0 ; k<n ; k++ )
        {
          b5[k+kb5i] = sa[k] + stb5*sb[k];
          stb5 = b5[k+kb5i] - stb5;
        }
      for ( i=1 ; i<=n ; i++ )
        {
          k = n - i;
          b5[k+kb5i] = sa[k] + stb5*sb[k];
          stb5 = b5[k+kb5i] - stb5;
        }
    }
  while (iter++ < ITERATIONS);

  for ( k=0; k<n; k++ )
    heuristics += b5[k];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel19());
    return 0;
}
