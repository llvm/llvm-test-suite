//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Source file containing LCALS "C" subset raw loops using the google
// benchmark library.
//

#include <benchmark/benchmark.h>
#include "../LCALSSuite.hxx"

static void BM_HYDRO_1D_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 1 -- hydro fragment
    *******************************************************************
    *       DO 1 L = 1,Loop
    *       DO 1 k = 1,n
    *  1       X(k)= Q + Y(k)*(R*ZX(k+10) + T*ZX(k+11))
    */

   LoopData& loop_data = getLoopData();

   loopInit(HYDRO_1D);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];
   Real_ptr z = loop_data.array_1D_Real[2];

   const Real_type q = loop_data.scalar_Real[0];
   const Real_type r = loop_data.scalar_Real[1];
   const Real_type t = loop_data.scalar_Real[2];

   for (auto _ : state) {

      for (Index_type k=0 ; k< state.range(0) ; k++ ) {
         x[k] = q + y[k]*( r*z[k+10] + t*z[k+11] );
      }

   }
}

BENCHMARK(BM_HYDRO_1D_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);


static void BM_ICCG_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 2 -- ICCG excerpt (Incomplete Cholesky Conj. Gradient)
    *******************************************************************
    *    DO 200  L= 1,Loop
    *        II= n
    *     IPNTP= 0
    *222   IPNT= IPNTP
    *     IPNTP= IPNTP+II
    *        II= II/2
    *         i= IPNTP+1
    CDIR$ IVDEP
    *    DO 2 k= IPNT+2,IPNTP,2
    *         i= i+1
    *  2   X(i)= X(k) - V(k)*X(k-1) - V(k+1)*X(k+1)
    *        IF( II.GT.1) GO TO 222
    *200 CONTINUE
    */

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
         for (Index_type k=ipnt+1 ; k<ipntp ; k=k+2 ) {
            i++;
            x[i] = x[k] - v[k  ]*x[k-1] - v[k+1]*x[k+1];
         }
      } while ( ii>0 );

   }
}

BENCHMARK(BM_ICCG_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_INNER_PROD_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 3 -- inner product
    *******************************************************************
    *    DO 3 L= 1,Loop
    *         Q= 0.0
    *    DO 3 k= 1,n
    *  3      Q= Q + Z(k)*X(k)
    */

   LoopData& loop_data = getLoopData();

   loopInit(INNER_PROD);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr z = loop_data.array_1D_Real[1];

   Real_type q = 0.0;
   Real_type val = 0.0;

   for (auto _ : state) {

      q = 0.0;
      for (Index_type k=0 ; k< state.range(0); k++ ) {
         benchmark::DoNotOptimize(q += z[k]*x[k]);
      }

   }
}

BENCHMARK(BM_INNER_PROD_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_BAND_LIN_EQ_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 4 -- banded linear equations
    *******************************************************************
    *            m= (1001-7)/2
    *    DO 444  L= 1,Loop
    *    DO 444  k= 7,1001,m
    *           lw= k-6
    *         temp= X(k-1)
    CDIR$ IVDEP
    *    DO   4  j= 5,n,5
    *       temp  = temp   - XZ(lw)*Y(j)
    *  4        lw= lw+1
    *       X(k-1)= Y(5)*temp
    *444 CONTINUE
    */

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
         for (Index_type j=4 ; j< state.range(0) ; j=j+5 ) {
            temp -= x[lw]*y[j];
            lw++;
         }
         x[k-1] = y[4]*temp;
      }

   }
}

BENCHMARK(BM_BAND_LIN_EQ_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_TRIDIAG_ELIM_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 5 -- tri-diagonal elimination, below diagonal
    *******************************************************************
    *    DO 5 L = 1,Loop
    *    DO 5 i = 2,n
    *  5    X(i)= Z(i)*(Y(i) - X(i-1))
    */

   LoopData& loop_data = getLoopData();

   loopInit(TRIDIAG_ELIM);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];
   Real_ptr z = loop_data.array_1D_Real[2];

   for (auto _ : state) {

      for ( Index_type i=1 ; i< state.range(0) ; i++ ) {
         x[i] = z[i]*( y[i] - x[i-1] );
      }

   }
}

BENCHMARK(BM_TRIDIAG_ELIM_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_EOS_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 7 -- equation of state fragment
    *******************************************************************
    *    DO 7 L= 1,Loop
    *    DO 7 k= 1,n
    *      X(k)=     U(k  ) + R*( Z(k  ) + R*Y(k  )) +
    *   .        T*( U(k+3) + R*( U(k+2) + R*U(k+1)) +
    *   .        T*( U(k+6) + Q*( U(k+5) + Q*U(k+4))))
    *  7 CONTINUE
    */

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

      for ( Index_type k=0 ; k< state.range(0) ; k++ ) {
         x[k] = u[k] + r*( z[k] + r*y[k] ) +
                t*( u[k+3] + r*( u[k+2] + r*u[k+1] ) +
                  t*( u[k+6] + q*( u[k+5] + q*u[k+4] ) ) );
      }

   }
}

BENCHMARK(BM_EOS_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_ADI_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 8 -- ADI integration
    *******************************************************************
    *    DO  8      L = 1,Loop
    *             nl1 = 1
    *             nl2 = 2
    *    DO  8     kx = 2,3
    CDIR$ IVDEP
    *    DO  8     ky = 2,n
    *          DU1(ky)=U1(kx,ky+1,nl1)  -  U1(kx,ky-1,nl1)
    *          DU2(ky)=U2(kx,ky+1,nl1)  -  U2(kx,ky-1,nl1)
    *          DU3(ky)=U3(kx,ky+1,nl1)  -  U3(kx,ky-1,nl1)
    *    U1(kx,ky,nl2)=U1(kx,ky,nl1) +A11*DU1(ky) +A12*DU2(ky) +A13*DU3(ky)
    *   .       + SIG*(U1(kx+1,ky,nl1) -2.*U1(kx,ky,nl1) +U1(kx-1,ky,nl1))
    *    U2(kx,ky,nl2)=U2(kx,ky,nl1) +A21*DU1(ky) +A22*DU2(ky) +A23*DU3(ky)
    *   .       + SIG*(U2(kx+1,ky,nl1) -2.*U2(kx,ky,nl1) +U2(kx-1,ky,nl1))
    *    U3(kx,ky,nl2)=U3(kx,ky,nl1) +A31*DU1(ky) +A32*DU2(ky) +A33*DU3(ky)
    *   .       + SIG*(U3(kx+1,ky,nl1) -2.*U3(kx,ky,nl1) +U3(kx-1,ky,nl1))
    *  8 CONTINUE
    */

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
         for (Index_type ky=1 ; ky< state.range(0) ; ky++ ) {
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
}

BENCHMARK(BM_ADI_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_INT_PREDICT_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 9 -- integrate predictors
    *******************************************************************
    *    DO 9  L = 1,Loop
    *    DO 9  i = 1,n
    *    PX( 1,i)= DM28*PX(13,i) + DM27*PX(12,i) + DM26*PX(11,i) +
    *   .          DM25*PX(10,i) + DM24*PX( 9,i) + DM23*PX( 8,i) +
    *   .          DM22*PX( 7,i) +  C0*(PX( 5,i) +      PX( 6,i))+ PX( 3,i)
    *  9 CONTINUE
    */

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

      for (Index_type i=0 ; i< state.range(0) ; i++ ) {
         px[i][0] = dm28*px[i][12] + dm27*px[i][11] + dm26*px[i][10] +
              dm25*px[i][ 9] + dm24*px[i][ 8] + dm23*px[i][ 7] +
              dm22*px[i][ 6] + c0*( px[i][ 4] + px[i][ 5]) + px[i][ 2];
      }

   }
}

BENCHMARK(BM_INT_PREDICT_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_DIFF_PREDICT_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 10 -- difference predictors
    *******************************************************************
    *    DO 10  L= 1,Loop
    *    DO 10  i= 1,n
    *    AR      =      CX(5,i)
    *    BR      = AR - PX(5,i)
    *    PX(5,i) = AR
    *    CR      = BR - PX(6,i)
    *    PX(6,i) = BR
    *    AR      = CR - PX(7,i)
    *    PX(7,i) = CR
    *    BR      = AR - PX(8,i)
    *    PX(8,i) = AR
    *    CR      = BR - PX(9,i)
    *    PX(9,i) = BR
    *    AR      = CR - PX(10,i)
    *    PX(10,i)= CR
    *    BR      = AR - PX(11,i)
    *    PX(11,i)= AR
    *    CR      = BR - PX(12,i)
    *    PX(12,i)= BR
    *    PX(14,i)= CR - PX(13,i)
    *    PX(13,i)= CR
    * 10 CONTINUE
    */

   LoopData& loop_data = getLoopData();

   loopInit(DIFF_PREDICT);

   Real_ptr* px = loop_data.array_2D_Nx25_Real[0];
   Real_ptr* cx = loop_data.array_2D_Nx25_Real[1];

   for (auto _ : state) {

      for (Index_type i=0 ; i< state.range(0) ; i++ ) {
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
      }

   }
}

BENCHMARK(BM_DIFF_PREDICT_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_FIRST_SUM_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 11 -- first sum
    *******************************************************************
    *    DO 11 L = 1,Loop
    *        X(1)= Y(1)
    *    DO 11 k = 2,n
    * 11     X(k)= X(k-1) + Y(k)
    */

   LoopData& loop_data = getLoopData();

   loopInit(FIRST_SUM);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];

   for (auto _ :state) {

      x[0] = y[0];
      for (Index_type k=1 ; k< state.range(0) ; k++ ) {
         x[k] = x[k-1] + y[k];
      }

   }
}

BENCHMARK(BM_FIRST_SUM_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_FIRST_DIFF_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 12 -- first difference
    *******************************************************************
    *    DO 12 L = 1,Loop
    *    DO 12 k = 1,n
    * 12     X(k)= Y(k+1) - Y(k)
    */

   LoopData& loop_data = getLoopData();

   loopInit(FIRST_DIFF);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];

   for (auto _ : state) {

      for (Index_type k=0 ; k< state.range(0) ; k++ ) {
         x[k] = y[k+1] - y[k];
      }

   }
}

BENCHMARK(BM_FIRST_DIFF_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_PIC_2D_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 13 -- 2-D PIC (Particle In Cell)
    *******************************************************************
    *    DO  13     L= 1,Loop
    *    DO  13    ip= 1,n
    *              i1= P(1,ip)
    *              j1= P(2,ip)
    *              i1=        1 + MOD2N(i1,64)
    *              j1=        1 + MOD2N(j1,64)
    *         P(3,ip)= P(3,ip)  + B(i1,j1)
    *         P(4,ip)= P(4,ip)  + C(i1,j1)
    *         P(1,ip)= P(1,ip)  + P(3,ip)
    *         P(2,ip)= P(2,ip)  + P(4,ip)
    *              i2= P(1,ip)
    *              j2= P(2,ip)
    *              i2=            MOD2N(i2,64)
    *              j2=            MOD2N(j2,64)
    *         P(1,ip)= P(1,ip)  + Y(i2+32)
    *         P(2,ip)= P(2,ip)  + Z(j2+32)
    *              i2= i2       + E(i2+32)
    *              j2= j2       + F(j2+32)
    *        H(i2,j2)= H(i2,j2) + 1.0
    * 13 CONTINUE
    */

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

      for (Index_type ip=0 ; ip< state.range(0) ; ip++ ) {
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
      }

   }
}

BENCHMARK(BM_PIC_2D_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_PIC_1D_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 14 -- 1-D PIC (Particle In Cell)
    *******************************************************************
    *    DO   14   L= 1,Loop
    *    DO   141  k= 1,n
    *          VX(k)= 0.0
    *          XX(k)= 0.0
    *          IX(k)= INT(  GRD(k))
    *          XI(k)= REAL( IX(k))
    *         EX1(k)= EX   ( IX(k))
    *        DEX1(k)= DEX  ( IX(k))
    *41  CONTINUE
    *    DO   142  k= 1,n
    *          VX(k)= VX(k) + EX1(k) + (XX(k) - XI(k))*DEX1(k)
    *          XX(k)= XX(k) + VX(k)  + FLX
    *          IR(k)= XX(k)
    *          RX(k)= XX(k) - IR(k)
    *          IR(k)= MOD2N(  IR(k),2048) + 1
    *          XX(k)= RX(k) + IR(k)
    *42  CONTINUE
    *    DO  14    k= 1,n
    *    RH(IR(k)  )= RH(IR(k)  ) + 1.0 - RX(k)
    *    RH(IR(k)+1)= RH(IR(k)+1) + RX(k)
    *14  CONTINUE
    */

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

      for (Index_type k=0 ; k< state.range(0) ; k++ ) {
         vx[k] = 0.0;
         xx[k] = 0.0;
         ix[k] = (Index_type) grd[k];
         xi[k] = (Real_type) ix[k];
         ex1[k] = ex[ ix[k] - 1 ];
         dex1[k] = dex[ ix[k] - 1 ];
      }

      for (Index_type k=0 ; k< state.range(0) ; k++ ) {
         vx[k] = vx[k] + ex1[k] + ( xx[k] - xi[k] )*dex1[k];
         xx[k] = xx[k] + vx[k]  + flx;
         ir[k] = (Index_type) xx[k];
         rx[k] = xx[k] - ir[k];
         ir[k] = ( ir[k] & (2048-1) ) + 1;
         xx[k] = rx[k] + ir[k];
      }

      for (Index_type k=0 ; k< state.range(0) ; k++ ) {
         rh[ ir[k]-1 ] += 1.0 - rx[k];
         rh[ ir[k]   ] += rx[k];
      }

   }
}

BENCHMARK(BM_PIC_1D_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_HYDRO_2D_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 18 - 2-D explicit hydrodynamics fragment
    *******************************************************************
    *       DO 75  L= 1,Loop
    *              T= 0.0037
    *              S= 0.0041
    *             KN= 6
    *             JN= n
    *       DO 70  k= 2,KN
    *       DO 70  j= 2,JN
    *        ZA(j,k)= (ZP(j-1,k+1)+ZQ(j-1,k+1)-ZP(j-1,k)-ZQ(j-1,k))
    *   .            *(ZR(j,k)+ZR(j-1,k))/(ZM(j-1,k)+ZM(j-1,k+1))
    *        ZB(j,k)= (ZP(j-1,k)+ZQ(j-1,k)-ZP(j,k)-ZQ(j,k))
    *   .            *(ZR(j,k)+ZR(j,k-1))/(ZM(j,k)+ZM(j-1,k))
    * 70    CONTINUE
    *       DO 72  k= 2,KN
    *       DO 72  j= 2,JN
    *        ZU(j,k)= ZU(j,k)+S*(ZA(j,k)*(ZZ(j,k)-ZZ(j+1,k))
    *   .                    -ZA(j-1,k) *(ZZ(j,k)-ZZ(j-1,k))
    *   .                    -ZB(j,k)   *(ZZ(j,k)-ZZ(j,k-1))
    *   .                    +ZB(j,k+1) *(ZZ(j,k)-ZZ(j,k+1)))
    *        ZV(j,k)= ZV(j,k)+S*(ZA(j,k)*(ZR(j,k)-ZR(j+1,k))
    *   .                    -ZA(j-1,k) *(ZR(j,k)-ZR(j-1,k))
    *   .                    -ZB(j,k)   *(ZR(j,k)-ZR(j,k-1))
    *   .                    +ZB(j,k+1) *(ZR(j,k)-ZR(j,k+1)))
    * 72    CONTINUE
    *       DO 75  k= 2,KN
    *       DO 75  j= 2,JN
    *        ZR(j,k)= ZR(j,k)+T*ZU(j,k)
    *        ZZ(j,k)= ZZ(j,k)+T*ZV(j,k)
    * 75    CONTINUE
    */

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
         for (Index_type j=1 ; j<jn ; j++ ) {
            za[k][j] = ( zp[k+1][j-1] +zq[k+1][j-1] -zp[k][j-1] -zq[k][j-1] )*
                       ( zr[k][j] +zr[k][j-1] ) / ( zm[k][j-1] +zm[k+1][j-1]);
            zb[k][j] = ( zp[k][j-1] +zq[k][j-1] -zp[k][j] -zq[k][j] ) *
                       ( zr[k][j] +zr[k-1][j] ) / ( zm[k][j] +zm[k][j-1]);
         }
      }

      for ( k=1 ; k<kn ; k++ ) {
         for (Index_type j=1 ; j<jn ; j++ ) {
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

      for ( k=1 ; k<kn ; k++ ) {
         for (Index_type j=1 ; j<jn ; j++ ) {
            zrout[k][j] = zr[k][j] + t*zu[k][j];
            zzout[k][j] = zz[k][j] + t*zv[k][j];
         }
      }

   }
}

BENCHMARK(BM_HYDRO_2D_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_GEN_LIN_RECUR_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 19 -- general linear recurrence equations
    *******************************************************************
    *               KB5I= 0
    *           DO 194 L= 1,Loop
    *           DO 191 k= 1,n
    *         B5(k+KB5I)= SA(k) +STB5*SB(k)
    *               STB5= B5(k+KB5I) -STB5
    *191        CONTINUE
    *192        DO 193 i= 1,n
    *                  k= n-i+1
    *         B5(k+KB5I)= SA(k) +STB5*SB(k)
    *               STB5= B5(k+KB5I) -STB5
    *193        CONTINUE
    *194 CONTINUE
    */

   LoopData& loop_data = getLoopData();

   loopInit(GEN_LIN_RECUR);

   Real_ptr b5 = loop_data.array_1D_Real[0];
   Real_ptr sa = loop_data.array_1D_Real[1];
   Real_ptr sb = loop_data.array_1D_Real[2];

   Real_type stb5 = loop_data.scalar_Real[0];

   Index_type kb5i = 0;

   for (auto _ : state) {

      for ( Index_type k=0 ; k< state.range(0) ; k++ ) {
         b5[k+kb5i] = sa[k] + stb5*sb[k];
         stb5 = b5[k+kb5i] - stb5;
      }

      for (Index_type  i=1 ; i<= state.range(0) ; i++ ) {
         Index_type k = state.range(0) - i ;
         b5[k+kb5i] = sa[k] + stb5*sb[k];
         stb5 = b5[k+kb5i] - stb5;
      }

   }
}

BENCHMARK(BM_GEN_LIN_RECUR_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_DISC_ORD_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 20 -- Discrete ordinates transport, cond recurrence on xx
    *******************************************************************
    *    DO 20 L= 1,Loop
    *    DO 20 k= 1,n
    *         DI= Y(k)-G(k)/( XX(k)+DK)
    *         DN= 0.2
    *         IF( DI.NE.0.0) DN= MAX( S,MIN( Z(k)/DI, T))
    *       X(k)= ((W(k)+V(k)*DN)* XX(k)+U(k))/(VX(k)+V(k)*DN)
    *    XX(k+1)= (X(k)- XX(k))*DN+ XX(k)
    * 20 CONTINUE
    */

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

      for (Index_type k=0 ; k< state.range(0) ; k++ ) {
         Real_type di = y[k] - g[k] / ( xx[k] + dk );
         Real_type dn = 0.2;
         if ( di ) {
            dn = z[k]/di ;
            if ( t < dn ) dn = t;
            if ( s > dn ) dn = s;
         }
         x[k] = ( ( w[k] + v[k]*dn )* xx[k] + u[k] ) / ( vx[k] + v[k]*dn );
         xx[k+1] = ( x[k] - xx[k] )* dn + xx[k];
      }

   }
}

BENCHMARK(BM_DISC_ORD_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_MAT_X_MAT_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 21 -- matrix*matrix product
    *******************************************************************
    *    DO 21 L= 1,Loop
    *    DO 21 k= 1,25
    *    DO 21 i= 1,25
    *    DO 21 j= 1,n
    *    PX(i,j)= PX(i,j) +VY(i,k) * CX(k,j)
    * 21 CONTINUE
    */

   LoopData& loop_data = getLoopData();

   loopInit(MAT_X_MAT);

   Real_ptr* px = loop_data.array_2D_Nx25_Real[0];
   Real_ptr* cx = loop_data.array_2D_Nx25_Real[1];
   Real_ptr* vy = loop_data.array_2D_64x64_Real[0];

   Index_type k, i;

   for (auto _ : state) {

      for ( k=0 ; k<25 ; k++ ) {
         for ( i=0 ; i<25 ; i++ ) {
            for (Index_type j=0 ; j< state.range(0) ; j++ ) {
               px[j][i] += vy[k][i] * cx[j][k];
            }
         }
      }

   }
}

BENCHMARK(BM_MAT_X_MAT_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_PLANCKIAN_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 22 -- Planckian distribution
    *******************************************************************
    *     EXPMAX= 20.0
    *       U(n)= 0.99*EXPMAX*V(n)
    *    DO 22 L= 1,Loop
    *    DO 22 k= 1,n
    *                                          Y(k)= U(k)/V(k)
    *       W(k)= X(k)/( EXP( Y(k)) -1.0)
    * 22 CONTINUE
    */

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

      for (Index_type k=0 ; k< state.range(0) ; k++ ) {
         y[k] = u[k] / v[k];
         w[k] = x[k] / ( exp( y[k] ) -1.0 );
      }

   }
}

BENCHMARK(BM_PLANCKIAN_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_IMP_HYDRO_2D_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 23 -- 2-D implicit hydrodynamics fragment
    *******************************************************************
    *    DO 23  L= 1,Loop
    *    DO 23  j= 2,6
    *    DO 23  k= 2,n
    *          QA= ZA(k,j+1)*ZR(k,j) +ZA(k,j-1)*ZB(k,j) +
    *   .          ZA(k+1,j)*ZU(k,j) +ZA(k-1,j)*ZV(k,j) +ZZ(k,j)
    * 23  ZA(k,j)= ZA(k,j) +.175*(QA -ZA(k,j))
    */

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
         for ( Index_type k=1 ; k< state.range(0) ; k++ ) {
            Real_type qa = za[j+1][k]*zr[j][k] + za[j-1][k]*zb[j][k] +
                 za[j][k+1]*zu[j][k] + za[j][k-1]*zv[j][k] + zz[j][k];
            za[j][k] += 0.175*( qa - za[j][k] );
         }
      }

   }
}

BENCHMARK(BM_IMP_HYDRO_2D_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_FIND_FIRST_MIN_RAW(benchmark::State& state) {

   /*
    *******************************************************************
    *   Kernel 24 -- find location of first minimum in array
    *******************************************************************
    *     X( n/2)= -1.0E+10
    *    DO 24  L= 1,Loop
    *           m= 1
    *    DO 24  k= 2,n
    *          IF( X(k).LT.X(m))  m= k
    * 24 CONTINUE
    */

   LoopData& loop_data = getLoopData();

   loopInit(FIND_FIRST_MIN);

   Real_ptr x = loop_data.array_1D_Real[0];

   Index_type m = 0;
   Index_type val = 0;

   for (auto _ : state) {

      m = 0;
      for (Index_type  k=1 ; k< state.range(0) ; k++ ) {
         if ( x[k] < x[m] ) benchmark::DoNotOptimize(m = k);
      }

   }
}

BENCHMARK(BM_FIND_FIRST_MIN_RAW)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);
