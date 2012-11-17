/***********************************************************************
 * gcc kernel08.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 8 -- ADI integration                                     *
********************************************************************/
double kernel08()
{
  long   nl1, nl2;
  long   kx, ky;
  unsigned iter = 0;
  double heuristics=0.0;

  nl1 = 0;
  nl2 = 1;

  parameters (8);
  do
    {
      for ( kx=1 ; kx<3 ; kx++ )
        {

          for ( ky=1 ; ky<n ; ky++ )
            {
              du1[ky] = u1[nl1][ky+1][kx] - u1[nl1][ky-1][kx];
              du2[ky] = u2[nl1][ky+1][kx] - u2[nl1][ky-1][kx];
              du3[ky] = u3[nl1][ky+1][kx] - u3[nl1][ky-1][kx];
              u1[nl2][ky][kx]=
                u1[nl1][ky][kx]+a11*du1[ky]+a12*du2[ky]+a13*du3[ky] + sig*
                (u1[nl1][ky][kx+1]-2.0*u1[nl1][ky][kx]+u1[nl1][ky][kx-1]);
              u2[nl2][ky][kx]=
                u2[nl1][ky][kx]+a21*du1[ky]+a22*du2[ky]+a23*du3[ky] + sig*
                (u2[nl1][ky][kx+1]-2.0*u2[nl1][ky][kx]+u2[nl1][ky][kx-1]);
              u3[nl2][ky][kx]=
                u3[nl1][ky][kx]+a31*du1[ky]+a32*du2[ky]+a33*du3[ky] + sig*
                (u3[nl1][ky][kx+1]-2.0*u3[nl1][ky][kx]+u3[nl1][ky][kx-1]);
            }
        }
    }
  while (iter++ < ITERATIONS);

  for ( kx=0; kx<3; kx++ )
    for ( ky=0; ky<n; ky++ )
      heuristics += u3[nl2][ky][kx];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel08());
    return 0;
}
