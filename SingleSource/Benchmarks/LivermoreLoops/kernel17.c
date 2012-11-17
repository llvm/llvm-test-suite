/***********************************************************************
 * gcc kernel17.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 17 -- implicit, conditional computation                  *
********************************************************************/
double kernel17()
{
  long   i, j;
  double scale, xnei, xnc, e3,e6;
  long   ink;
  unsigned iter = 0;
  double heuristics=0.0;

  parameters (17);
  do
    {
      i = n-1;
      j = 0;
      ink = -1;
      scale = 5.0 / 3.0;
      xnm = 1.0 / 3.0;
      e6 = 1.03 / 3.07;
      goto l61;
    l60:    e6 = xnm*vsp[i] + vstp[i];
      vxne[i] = e6;
      xnm = e6;
      ve3[i] = e6;
      i += ink;
      if ( i==j ) goto end;
    l61:    e3 = xnm*vlr[i] + vlin[i];
      xnei = vxne[i];
      vxnd[i] = e6;
      xnc = scale*e3;
      if ( xnm > xnc ) goto l60;
      if ( xnei > xnc ) goto l60;
      ve3[i] = e3;
      e6 = e3 + e3 - xnm;
      vxne[i] = e3 + e3 - xnei;
      xnm = e6;
      i += ink;
      if ( i != j ) goto l61;
    end:
      heuristics += xnm + xnc + xnei;
    }
  while (iter++ < ITERATIONS);

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel17());
    return 0;
}
