//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Source file containing LCALS "C" subset forall lambda loops using 
// the google benchmark library.
//

#include <benchmark/benchmark.h>
#include "../LCALSSuite.hxx"
#include "../LCALSTraversalMethods.hxx"

static void BM_HYDRO_1D_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(HYDRO_1D);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];
   Real_ptr z = loop_data.array_1D_Real[2];

   const Real_type q = loop_data.scalar_Real[0];
   const Real_type r = loop_data.scalar_Real[1];
   const Real_type t = loop_data.scalar_Real[2];

   for (auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type k)  {
         x[k] = q + y[k]*( r*z[k+10] + t*z[k+11] );
      } );

   }
}

BENCHMARK(BM_HYDRO_1D_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);


static void BM_ICCG_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(ICCG);

   Real_ptr x = loop_data.array_1D_Nx4_Real[0];
   Real_ptr v = loop_data.array_1D_Nx4_Real[1];

   Index_type ii, ipnt, ipntp, i;

  for (auto _ : state) {

      ii = state.range(0);
      ipntp = 0;
      do {
         ipnt = ipntp;
         ipntp += ii;
         ii /= 2;
         i = ipntp ;
         forall<exec_policy>(ipnt+1, ipntp, 2,
         [&] (Index_type k) {
            i++;
            x[i] = x[k] - v[k  ]*x[k-1] - v[k+1]*x[k+1];
         } );
      } while ( ii>0 );

   }
}

BENCHMARK(BM_ICCG_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_INNER_PROD_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(INNER_PROD);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr z = loop_data.array_1D_Real[1];

   Real_type q = 0.0;
   Real_type val = 0.0;

   for (auto _ : state) {

      q = 0.0;
      forall<exec_policy>(0, state.range(0),
      [&] (Index_type k) {
         benchmark::DoNotOptimize(q += z[k]*x[k]);
      } );

   }
}

BENCHMARK(BM_INNER_PROD_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_BAND_LIN_EQ_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(BAND_LIN_EQ);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];

   Index_type lw;
   Real_type temp;

   for (auto _ : state) {

      Index_type m = ( 1001-7 )/2;
      for ( Index_type k=6 ; k<1001 ; k=k+m ) {
         lw = k - 6;
         temp = x[k-1];
         forall<exec_policy>(4, state.range(0), 5,
         [&] (Index_type j) {
            temp -= x[lw]*y[j];
            lw++;
         } );
         x[k-1] = y[4]*temp;
      }

   }
}

BENCHMARK(BM_BAND_LIN_EQ_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_TRIDIAG_ELIM_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(TRIDIAG_ELIM);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];
   Real_ptr z = loop_data.array_1D_Real[2];

   for (auto _ : state) {

      forall<exec_policy>(1, state.range(0),
      [&] (Index_type i) {
         x[i] = z[i]*( y[i] - x[i-1] );
      } );

   }
}

BENCHMARK(BM_TRIDIAG_ELIM_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_EOS_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(EOS);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];
   Real_ptr z = loop_data.array_1D_Real[2];
   Real_ptr u = loop_data.array_1D_Real[3];

   const Real_type q = loop_data.scalar_Real[0];
   const Real_type r = loop_data.scalar_Real[1];
   const Real_type t = loop_data.scalar_Real[2];

   for (auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type k) {
         x[k] = u[k] + r*( z[k] + r*y[k] ) +
               t*( u[k+3] + r*( u[k+2] + r*u[k+1] ) +
                  t*( u[k+6] + q*( u[k+5] + q*u[k+4] ) ) );
      } );

   }
}

BENCHMARK(BM_EOS_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_ADI_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(ADI);

   Real_ptr du1 = loop_data.array_1D_Real[0];
   Real_ptr du2 = loop_data.array_1D_Real[1];
   Real_ptr du3 = loop_data.array_1D_Real[2];

   Real_ptr** u1 = loop_data.array_3D_2xNx4_Real[0];
   Real_ptr** u2 = loop_data.array_3D_2xNx4_Real[1];
   Real_ptr** u3 = loop_data.array_3D_2xNx4_Real[2];

   const Real_type sig = loop_data.scalar_Real[0];
   const Real_type a11 = loop_data.scalar_Real[1];
   const Real_type a12 = loop_data.scalar_Real[2];
   const Real_type a13 = loop_data.scalar_Real[3];
   const Real_type a21 = loop_data.scalar_Real[4];
   const Real_type a22 = loop_data.scalar_Real[5];
   const Real_type a23 = loop_data.scalar_Real[6];
   const Real_type a31 = loop_data.scalar_Real[7];
   const Real_type a32 = loop_data.scalar_Real[8];
   const Real_type a33 = loop_data.scalar_Real[9];

   Index_type nl1 = 0;
   Index_type nl2 = 1;
   Index_type kx;

   for (auto _ : state) {

      for ( kx=1 ; kx<3 ; kx++ ) {
         forall<exec_policy>(1, state.range(0),
         [&] (Index_type ky) {
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
         } );
      }

   }
}

BENCHMARK(BM_ADI_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_INT_PREDICT_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(INT_PREDICT);

   Real_ptr* px = loop_data.array_2D_Nx25_Real[0];

   const Real_type dm22 = loop_data.scalar_Real[0];
   const Real_type dm23 = loop_data.scalar_Real[1];
   const Real_type dm24 = loop_data.scalar_Real[2];
   const Real_type dm25 = loop_data.scalar_Real[3];
   const Real_type dm26 = loop_data.scalar_Real[4];
   const Real_type dm27 = loop_data.scalar_Real[5];
   const Real_type dm28 = loop_data.scalar_Real[6];
   const Real_type c0 = loop_data.scalar_Real[7];

   for (auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type i) {
         px[i][0] = dm28*px[i][12] + dm27*px[i][11] + dm26*px[i][10] +
              dm25*px[i][ 9] + dm24*px[i][ 8] + dm23*px[i][ 7] +
              dm22*px[i][ 6] + c0*( px[i][ 4] + px[i][ 5]) + px[i][ 2];
      } );

   }
}

BENCHMARK(BM_INT_PREDICT_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_DIFF_PREDICT_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(DIFF_PREDICT);

   Real_ptr* px = loop_data.array_2D_Nx25_Real[0];
   Real_ptr* cx = loop_data.array_2D_Nx25_Real[1];

   for (auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type i) {
         Real_type ar, br, cr;
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
      } );

   }
}

BENCHMARK(BM_DIFF_PREDICT_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_FIRST_SUM_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(FIRST_SUM);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];

   for (auto _ :state) {

      x[0] = y[0];
      forall<exec_policy>(1, state.range(0),
      [&] (Index_type k) {
         x[k] = x[k-1] + y[k];
      } );

   }
}

BENCHMARK(BM_FIRST_SUM_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_FIRST_DIFF_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(FIRST_DIFF);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];

   for (auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type k) {
         x[k] = y[k+1] - y[k];
      } );

   }
}

BENCHMARK(BM_FIRST_DIFF_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_PIC_2D_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(PIC_2D);

   Real_ptr* p = loop_data.array_2D_Nx25_Real[0];
   Real_ptr* b = loop_data.array_2D_Nx25_Real[1];
   Real_ptr* c = loop_data.array_2D_Nx25_Real[2];

   Real_ptr y = loop_data.array_1D_Real[0];
   Real_ptr z = loop_data.array_1D_Real[1];

   Index_type* e = loop_data.array_1D_Indx[0];
   Index_type* f = loop_data.array_1D_Indx[1];

   Real_ptr* h = loop_data.array_2D_64x64_Real[0];

   for (auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type ip) {
         Index_type i1, j1, i2, j2;
         i1 = (Index_type) p[ip][0];
         j1 = (Index_type) p[ip][1];
         i1 &= 64-1;
         j1 &= 64-1;
         p[ip][2] += b[j1][i1];
         p[ip][3] += c[j1][i1];
         p[ip][0] += p[ip][2];
         p[ip][1] += p[ip][3];
         i2 = (Index_type) p[ip][0];
         j2 = (Index_type) p[ip][1];
         i2 = ( i2 & 64-1 ) ;
         j2 = ( j2 & 64-1 ) ;
         p[ip][0] += y[i2+32];
         p[ip][1] += z[j2+32];
         i2 += e[i2+32];
         j2 += f[j2+32];
         h[j2][i2] += 1.0;
      } );

   }
}

BENCHMARK(BM_PIC_2D_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_PIC_1D_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(PIC_1D);

   Real_ptr vx = loop_data.array_1D_Real[0];
   Real_ptr xx = loop_data.array_1D_Real[1];
   Real_ptr xi = loop_data.array_1D_Real[2];
   Real_ptr ex = loop_data.array_1D_Real[3];
   Real_ptr ex1 = loop_data.array_1D_Real[4];
   Real_ptr dex = loop_data.array_1D_Real[5];
   Real_ptr dex1 = loop_data.array_1D_Real[6];
   Real_ptr rh = loop_data.array_1D_Real[7];
   Real_ptr rx = loop_data.array_1D_Real[8];

   const Real_type flx = loop_data.scalar_Real[0];

   Index_type* ix = loop_data.array_1D_Indx[2];
   Index_type* ir = loop_data.array_1D_Indx[3];
   Index_type* grd = loop_data.array_1D_Indx[4];


   for (auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type k) {
         vx[k] = 0.0;
         xx[k] = 0.0;
         ix[k] = (Index_type) grd[k];
         xi[k] = (Real_type) ix[k];
         ex1[k] = ex[ ix[k] - 1 ];
         dex1[k] = dex[ ix[k] - 1 ];
      } );

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type k) {
         vx[k] = vx[k] + ex1[k] + ( xx[k] - xi[k] )*dex1[k];
         xx[k] = xx[k] + vx[k]  + flx;
         ir[k] = (Index_type) xx[k];
         rx[k] = xx[k] - ir[k];
         ir[k] = ( ir[k] & (2048-1) ) + 1;
         xx[k] = rx[k] + ir[k];
      } );

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type k) {
         rh[ ir[k]-1 ] += 1.0 - rx[k];
         rh[ ir[k]   ] += rx[k];
      } );

   }
}

BENCHMARK(BM_PIC_1D_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_HYDRO_2D_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(HYDRO_2D);

   Real_ptr* za = loop_data.array_2D_7xN_Real[0];
   Real_ptr* zb = loop_data.array_2D_7xN_Real[1]; 
   Real_ptr* zm = loop_data.array_2D_7xN_Real[2];
   Real_ptr* zp = loop_data.array_2D_7xN_Real[3];
   Real_ptr* zq = loop_data.array_2D_7xN_Real[4];
   Real_ptr* zr = loop_data.array_2D_7xN_Real[5];
   Real_ptr* zu = loop_data.array_2D_7xN_Real[6];
   Real_ptr* zv = loop_data.array_2D_7xN_Real[7];
   Real_ptr* zz = loop_data.array_2D_7xN_Real[8];

   Real_ptr* zrout = loop_data.array_2D_7xN_Real[9];
   Real_ptr* zzout = loop_data.array_2D_7xN_Real[10];

   const Real_type t = 0.0037;
   const Real_type s = 0.0041;

   Index_type kn = 6;
   Index_type jn = state.range(0);
   Index_type k;

   for (auto _ : state) {

      for ( k=1 ; k<kn ; k++ ) {
         forall<exec_policy>(1, jn,
         [&] (Index_type j) {
            za[k][j] = ( zp[k+1][j-1] +zq[k+1][j-1] -zp[k][j-1] -zq[k][j-1] )*
                       ( zr[k][j] +zr[k][j-1] ) / ( zm[k][j-1] +zm[k+1][j-1]);
            zb[k][j] = ( zp[k][j-1] +zq[k][j-1] -zp[k][j] -zq[k][j] ) *
                       ( zr[k][j] +zr[k-1][j] ) / ( zm[k][j] +zm[k][j-1]);
         } );
      }

      for ( k=1 ; k<kn ; k++ ) {
         forall<exec_policy>(1, jn,
         [&] (Index_type j) {
            zu[k][j] += s*( za[k][j]   *( zz[k][j] - zz[k][j+1] ) -
                            za[k][j-1] *( zz[k][j] - zz[k][j-1] ) -
                            zb[k][j]   *( zz[k][j] - zz[k-1][j] ) +
                            zb[k+1][j] *( zz[k][j] - zz[k+1][j] ) );
            zv[k][j] += s*( za[k][j]   *( zr[k][j] - zr[k][j+1] ) -
                            za[k][j-1] *( zr[k][j] - zr[k][j-1] ) -
                            zb[k][j]   *( zr[k][j] - zr[k-1][j] ) +
                            zb[k+1][j] *( zr[k][j] - zr[k+1][j] ) );
         } );
      }

      for ( k=1 ; k<kn ; k++ ) {
         forall<exec_policy>(1, jn,
         [&] (Index_type j) {
            zrout[k][j] = zr[k][j] + t*zu[k][j];
            zzout[k][j] = zz[k][j] + t*zv[k][j];
         } );
      }

   }
}

BENCHMARK(BM_HYDRO_2D_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_GEN_LIN_RECUR_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(GEN_LIN_RECUR);

   Real_ptr b5 = loop_data.array_1D_Real[0];
   Real_ptr sa = loop_data.array_1D_Real[1];
   Real_ptr sb = loop_data.array_1D_Real[2];

   Real_type stb5 = loop_data.scalar_Real[0];

   Index_type kb5i = 0;

   for (auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type k) {
         b5[k+kb5i] = sa[k] + stb5*sb[k];
         stb5 = b5[k+kb5i] - stb5;
      } );

      forall<exec_policy>(1, state.range(0) + 1,
      [&] (Index_type i) {
         Index_type k = state.range(0) - i ;
         b5[k+kb5i] = sa[k] + stb5*sb[k];
         stb5 = b5[k+kb5i] - stb5;
      } );

   }
}

BENCHMARK(BM_GEN_LIN_RECUR_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_DISC_ORD_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(DISC_ORD);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];
   Real_ptr z = loop_data.array_1D_Real[2];
   Real_ptr u = loop_data.array_1D_Real[3];
   Real_ptr v = loop_data.array_1D_Real[4];
   Real_ptr w = loop_data.array_1D_Real[5];
   Real_ptr g = loop_data.array_1D_Real[6];
   Real_ptr xx = loop_data.array_1D_Real[7];
   Real_ptr vx = loop_data.array_1D_Real[9];
   const Real_type s = loop_data.scalar_Real[0];
   const Real_type t = loop_data.scalar_Real[1];
   const Real_type dk = loop_data.scalar_Real[2];

   for (auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type k) {
         Real_type di = y[k] - g[k] / ( xx[k] + dk );
         Real_type dn = 0.2;
         if ( di ) {
            dn = z[k]/di ;
            if ( t < dn ) dn = t;
            if ( s > dn ) dn = s;
         }
         x[k] = ( ( w[k] + v[k]*dn )* xx[k] + u[k] ) / ( vx[k] + v[k]*dn );
         xx[k+1] = ( x[k] - xx[k] )* dn + xx[k];
      } );

   }
}

BENCHMARK(BM_DISC_ORD_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_MAT_X_MAT_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(MAT_X_MAT);

   Real_ptr* px = loop_data.array_2D_Nx25_Real[0];
   Real_ptr* cx = loop_data.array_2D_Nx25_Real[1];
   Real_ptr* vy = loop_data.array_2D_64x64_Real[0];

   Index_type k, i;

   for (auto _ : state) {

      for ( k=0 ; k<25 ; k++ ) {
         for ( i=0 ; i<25 ; i++ ) {
            forall<exec_policy>(0, state.range(0),
            [&] (Index_type j) {
               px[j][i] += vy[k][i] * cx[j][k];
            } );
         }
      }

   }
}

BENCHMARK(BM_MAT_X_MAT_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_PLANCKIAN_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(PLANCKIAN);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];
   Real_ptr u = loop_data.array_1D_Real[2];
   Real_ptr v = loop_data.array_1D_Real[3];
   Real_ptr w = loop_data.array_1D_Real[4];

   Real_type expmax = 20.0;
   u[state.range(0)-1] = 0.99*expmax*v[state.range(0)-1];

   for (auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type k) {
         y[k] = u[k] / v[k];
         w[k] = x[k] / ( exp( y[k] ) -1.0 );
      } );

   }
}

BENCHMARK(BM_PLANCKIAN_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_IMP_HYDRO_2D_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(IMP_HYDRO_2D);

   Real_ptr* za = loop_data.array_2D_7xN_Real[0];
   Real_ptr* zb = loop_data.array_2D_7xN_Real[1];
   Real_ptr* zr = loop_data.array_2D_7xN_Real[2];
   Real_ptr* zu = loop_data.array_2D_7xN_Real[3];
   Real_ptr* zv = loop_data.array_2D_7xN_Real[4];
   Real_ptr* zz = loop_data.array_2D_7xN_Real[5];

   Index_type j;

   for (auto _ : state) {

      for ( j=1 ; j<6 ; j++ ) {
         forall<exec_policy>(1, state.range(0),
         [&] (Index_type k) {
            Real_type qa = za[j+1][k]*zr[j][k] + za[j-1][k]*zb[j][k] +
                 za[j][k+1]*zu[j][k] + za[j][k-1]*zv[j][k] + zz[j][k];
            za[j][k] += 0.175*( qa - za[j][k] );
         } );
      }

   }
}

BENCHMARK(BM_IMP_HYDRO_2D_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_FIND_FIRST_MIN_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(FIND_FIRST_MIN);

   Real_ptr x = loop_data.array_1D_Real[0];

   Index_type m = 0;
   Index_type val = 0;

   for (auto _ : state) {

      m = 0;
      forall<exec_policy>(1, state.range(0),
      [&] (Index_type k) {
         if ( x[k] < x[m] ) benchmark::DoNotOptimize(m = k);
      } );

   }
}

BENCHMARK(BM_FIND_FIRST_MIN_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);
