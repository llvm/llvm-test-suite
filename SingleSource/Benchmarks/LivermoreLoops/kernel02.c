/***********************************************************************
 * gcc kernel02.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/**********************************************************************
*   Kernel 2 -- ICCG excerpt (Incomplete Cholesky Conjugate Gradient) *
**********************************************************************/
double kernel02()
{
  long   ipnt, ipntp, ii;
  long   i, k;
  double heuristics=0.0;
  unsigned iter = 0;

  parameters (2);
  do
    {
      ii = n;
      ipntp = 0;
      do
        {
          ipnt = ipntp;
          ipntp += ii;
          ii /= 2;
          i = ipntp;
          for ( k=ipnt+1 ; k<ipntp ; k=k+2 )
            {
              i++;
              x[i] = x[k] - v[k]*x[k-1] - v[k+1]*x[k+1];
            }
        } while ( ii>0 );
    }
  while (iter++ < ITERATIONS);

  for ( k=0; k<n; k++ )
    heuristics += x[k];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel02());
    return 0;
}
