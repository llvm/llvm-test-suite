/***********************************************************************
 * gcc kernel13.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 13 -- 2-D PIC (Particle In Cell)                         *
********************************************************************/
double kernel13()
{
  long   ip, i1, i2, j1, j2;
  unsigned iter = 0;
  double heuristics=0.0;

  parameters (13);
  do
    {
      for ( ip=0; ip<n; ip++)
        {
          i1 = (long)p[ip][0];
          j1 = (long)p[ip][1];
          i1 &= 64-1;
          j1 &= 64-1;
          p[ip][2] += b[j1][i1];
          p[ip][3] += c[j1][i1];
          p[ip][0] += p[ip][2];
          p[ip][1] += p[ip][3];
          i2 = (long)p[ip][0];
          j2 = (long)p[ip][1];
          i2 = ( i2 & (64-1) ) - 1 ;
          j2 = ( j2 & (64-1) ) - 1 ;
          p[ip][0] += y[i2+32];
          p[ip][1] += z[j2+32];
          i2 += e[i2+32];
          j2 += f[j2+32];
          h[j2][i2] += 1.0;
        }
    }
  while (iter++ < ITERATIONS);

  for ( ip=0; ip<n; ip++ )
    heuristics += p[ip][0]+p[ip][1]+p[ip][2]+p[ip][3];

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel13());
    return 0;
}
