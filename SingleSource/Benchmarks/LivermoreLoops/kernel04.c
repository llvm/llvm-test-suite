/***********************************************************************
 * gcc kernel04.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 4 -- banded linear equations                             *
********************************************************************/
double kernel04()
{
  long   lw;
  double temp;
  long   j, k, m;
  double heuristics=0.0;
  unsigned iter = 0;

  parameters (4);
  m = ( 1001-7 )/2;
  do
    {
      for ( k=6 ; k<1001 ; k=k+m )
        {
          lw = k - 6;
          temp = x[k-1];

          for ( j=4 ; j<n ; j=j+5 )
            {
              temp -= x[lw]*y[j];
              lw++;
            }
          x[k-1] = y[4]*temp;
        }
    }
  while (iter++ < ITERATIONS);

  for ( k=0; k<n; k++ )
    heuristics += x[k];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel04());
    return 0;
}
