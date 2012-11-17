/***********************************************************************
 * gcc kernel18.c -m64 -lrt -lc -lm
 * L. L. N. L.  " C "  K E R N E L S:  M F L O P S  P C  V E R S I O N
 */

#include "lloops.h"

/********************************************************************
*   Kernel 18 - 2-D explicit hydrodynamics fragment                 *
********************************************************************/
double kernel18()
{
  long   j, k;
  long   jn, kn;
  double heuristics=0.0;
  unsigned iter = 0;

  parameters (18);
  do
    {
      t = 0.0037;
      s = 0.0041;
      kn = 6;
      jn = n;
      for ( k=1 ; k<kn ; k++ )
        {

          for ( j=1 ; j<jn ; j++ )
            {
              za[k][j] = ( zp[k+1][j-1] +zq[k+1][j-1] -zp[k][j-1] -zq[k][j-1] )*
                ( zr[k][j] +zr[k][j-1] ) / ( zm[k][j-1] +zm[k+1][j-1]);
              zb[k][j] = ( zp[k][j-1] +zq[k][j-1] -zp[k][j] -zq[k][j] ) *
                ( zr[k][j] +zr[k-1][j] ) / ( zm[k][j] +zm[k][j-1]);
            }
        }
      for ( k=1 ; k<kn ; k++ )
        {

          for ( j=1 ; j<jn ; j++ )
            {
              zu[k][j] += s*( za[k][j]   *( zz[k][j] - zz[k][j+1] ) -
                              za[k][j-1] *( zz[k][j] - zz[k][j-1] ) -
                              zb[k][j]   *( zz[k][j] - zz[k-1][j] ) +
                              zb[k+1][j] *( zz[k][j] - zz[k+1][j] ) );
              zv[k][j] += s*( za[k][j]   *( zr[k][j] - zr[k][j+1] ) -
                              za[k][j-1] *( zr[k][j] - zr[k][j-1] ) -
                              zb[k][j]   *( zr[k][j] - zr[k-1][j] ) +
                              zb[k+1][j] *( zr[k][j] - zr[k+1][j] ) );
            }
        }
      for ( k=1 ; k<kn ; k++ )
        {

          for ( j=1 ; j<jn ; j++ )
            {
              zr[k][j] = zr[k][j] + t*zu[k][j];
              zz[k][j] = zz[k][j] + t*zv[k][j];
            }
        }
    }
  while (iter++ < ITERATIONS);

  for ( k=0; k<6; k++ )
    for ( j=0; j<jn; j++ )
      heuristics += (zu[k][j]*zv[k][j])+(zr[k][j]*zz[k][j]);

  return heuristics;
}

int main(int argc, char *argv[])
{
    printf("%f\n", kernel18());
    return 0;
}
