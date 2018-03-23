//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Source file containing LCALS "A" subset raw loops using the google
// benchmark library
//

#include <benchmark/benchmark.h>
#include "../LCALSSuite.hxx"
#include "../SubsetDataA.hxx"

static void BM_PRESSURE_CALC_RAW(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(PRESSURE_CALC);

   Real_ptr compression = loop_data.array_1D_Real[0];
   Real_ptr bvc = loop_data.array_1D_Real[1];
   Real_ptr p_new = loop_data.array_1D_Real[2];
   Real_ptr e_old = loop_data.array_1D_Real[3];
   Real_ptr vnewc = loop_data.array_1D_Real[4];

   const Real_type cls = loop_data.scalar_Real[0];
   const Real_type p_cut = loop_data.scalar_Real[1];
   const Real_type pmin = loop_data.scalar_Real[2];
   const Real_type eosvmax = loop_data.scalar_Real[3];
   
   for( auto _ : state) {

      for (Index_type i=0 ; i<state.range(0) ; i++ ) {
         bvc[i] = cls * (compression[i] + 1.0);
      }

      for (Index_type i=0 ; i<state.range(0) ; i++ ) {
         p_new[i] = bvc[i] * e_old[i] ;

         if ( fabs(p_new[i]) <  p_cut ) p_new[i] = 0.0 ;

         if ( vnewc[i] >= eosvmax ) p_new[i] = 0.0 ;

         if ( p_new[i]  <  pmin ) p_new[i]   = pmin ;
      }

   }
}

BENCHMARK(BM_PRESSURE_CALC_RAW)->Arg(171)->Arg(5001)->
                                 Arg(44217)->Unit(benchmark::kMicrosecond);


static void BM_ENERGY_CALC_RAW(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(ENERGY_CALC);

   Real_ptr e_new = loop_data.array_1D_Real[0];
   Real_ptr e_old = loop_data.array_1D_Real[1];
   Real_ptr delvc = loop_data.array_1D_Real[2];
   Real_ptr p_new = loop_data.array_1D_Real[3];
   Real_ptr p_old = loop_data.array_1D_Real[4];
   Real_ptr q_new = loop_data.array_1D_Real[5];
   Real_ptr q_old = loop_data.array_1D_Real[6];
   Real_ptr work = loop_data.array_1D_Real[7];
   Real_ptr compHalfStep = loop_data.array_1D_Real[8];
   Real_ptr pHalfStep = loop_data.array_1D_Real[9];
   Real_ptr bvc = loop_data.array_1D_Real[10];
   Real_ptr pbvc = loop_data.array_1D_Real[11];
   Real_ptr ql_old = loop_data.array_1D_Real[12];
   Real_ptr qq_old = loop_data.array_1D_Real[13];
   Real_ptr vnewc = loop_data.array_1D_Real[14];

   const Real_type rho0 = loop_data.scalar_Real[0];
   const Real_type e_cut = loop_data.scalar_Real[1];
   const Real_type emin = loop_data.scalar_Real[2];
   const Real_type q_cut = loop_data.scalar_Real[3];

   for( auto _ : state) {

      for (Index_type i=0 ; i< state.range(0) ; i++ ) {
         e_new[i] = e_old[i] - 0.5 * delvc[i] *
                    (p_old[i] + q_old[i]) + 0.5 * work[i];
      }

      for (Index_type i=0 ; i< state.range(0) ; i++ ) {
         if ( delvc[i] > 0.0 ) {
                    q_new[i] = 0.0 ;
         }
         else {
            Real_type vhalf = 1.0 / (1.0 + compHalfStep[i]) ;
            Real_type ssc = ( pbvc[i] * e_new[i]
               + vhalf * vhalf * bvc[i] * pHalfStep[i] ) / rho0 ;

            if ( ssc <= 0.1111111e-36 ) {
               ssc = 0.3333333e-18 ;
            } else {
               ssc = sqrt(ssc) ;
            }

            q_new[i] = (ssc*ql_old[i] + qq_old[i]) ;
         }
      }
      for (Index_type i=0 ; i< state.range(0) ; i++ ) {
         e_new[i] = e_new[i] + 0.5 * delvc[i]
            * ( 3.0*(p_old[i] + q_old[i])
               - 4.0*(pHalfStep[i] + q_new[i])) ;
      }

      for (Index_type i=0 ; i< state.range(0) ; i++ ) {
         e_new[i] += 0.5 * work[i];

         if ( fabs(e_new[i]) < e_cut ) { e_new[i] = 0.0  ; }

            if ( e_new[i]  < emin ) { e_new[i] = emin ; }
      }

      for (Index_type i=0 ; i< state.range(0) ; i++ ) {
         Real_type q_tilde ;

         if (delvc[i] > 0.0) {
            q_tilde = 0. ;
         }
         else {
            Real_type ssc = ( pbvc[i] * e_new[i]
               + vnewc[i] * vnewc[i] * bvc[i] * p_new[i] ) / rho0 ;

            if ( ssc <= 0.1111111e-36 ) {
               ssc = 0.3333333e-18 ;
            } else {
               ssc = sqrt(ssc) ;
            }

            q_tilde = (ssc*ql_old[i] + qq_old[i]) ;
         }

         e_new[i] = e_new[i] - ( 7.0*(p_old[i] + q_old[i])
                                - 8.0*(pHalfStep[i] + q_new[i])
                                + (p_new[i] + q_tilde)) * delvc[i] / 6.0 ;

         if ( fabs(e_new[i]) < e_cut ) {
            e_new[i] = 0.0  ;
         }
         if ( e_new[i]  < emin ) {
            e_new[i] = emin ;
         }
      }

      for (Index_type i=0 ; i< state.range(0) ; i++ ) {
         if ( delvc[i] <= 0.0 ) {
            Real_type ssc = ( pbvc[i] * e_new[i]
               + vnewc[i] * vnewc[i] * bvc[i] * p_new[i] ) / rho0 ;

            if ( ssc <= 0.1111111e-36 ) {
               ssc = 0.3333333e-18 ;
            } else {
               ssc = sqrt(ssc) ;
            }

            q_new[i] = (ssc*ql_old[i] + qq_old[i]) ;

            if (fabs(q_new[i]) < q_cut) q_new[i] = 0.0 ;
         }
      }

   }
}

BENCHMARK(BM_ENERGY_CALC_RAW)->Arg(171)->Arg(5001)->
                               Arg(44217)->Unit(benchmark::kMicrosecond);

static void BM_VOL3D_CALC_RAW(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(VOL3D_CALC);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];
   Real_ptr z = loop_data.array_1D_Real[2];
   Real_ptr vol = loop_data.array_1D_Real[3];

   ADomain domain(state.range(0), /* ndims = */ 3);

   UnalignedReal_ptr x0,x1,x2,x3,x4,x5,x6,x7 ;
   UnalignedReal_ptr y0,y1,y2,y3,y4,y5,y6,y7 ;
   UnalignedReal_ptr z0,z1,z2,z3,z4,z5,z6,z7 ;

   NDPTRSET(x,x0,x1,x2,x3,x4,x5,x6,x7) ;
   NDPTRSET(y,y0,y1,y2,y3,y4,y5,y6,y7) ;
   NDPTRSET(z,z0,z1,z2,z3,z4,z5,z6,z7) ;

   const Real_type vnormq = 0.083333333333333333; /* vnormq = 1/12 */

   for (auto _ : state) {

      for (Index_type i = domain.fpz ; i <= domain.lpz ; i++ ) {

         Real_type x71 = x7[i] - x1[i] ;
         Real_type x72 = x7[i] - x2[i] ;
         Real_type x74 = x7[i] - x4[i] ;
         Real_type x30 = x3[i] - x0[i] ;
         Real_type x50 = x5[i] - x0[i] ;
         Real_type x60 = x6[i] - x0[i] ;

         Real_type y71 = y7[i] - y1[i] ;
         Real_type y72 = y7[i] - y2[i] ;
         Real_type y74 = y7[i] - y4[i] ;
         Real_type y30 = y3[i] - y0[i] ;
         Real_type y50 = y5[i] - y0[i] ;
         Real_type y60 = y6[i] - y0[i] ;

         Real_type z71 = z7[i] - z1[i] ;
         Real_type z72 = z7[i] - z2[i] ;
         Real_type z74 = z7[i] - z4[i] ;
         Real_type z30 = z3[i] - z0[i] ;
         Real_type z50 = z5[i] - z0[i] ;
         Real_type z60 = z6[i] - z0[i] ;

         Real_type xps = x71 + x60 ;
         Real_type yps = y71 + y60 ;
         Real_type zps = z71 + z60 ;

         Real_type cyz = y72 * z30 - z72 * y30 ;
         Real_type czx = z72 * x30 - x72 * z30 ;
         Real_type cxy = x72 * y30 - y72 * x30 ;
         vol[i] = xps * cyz + yps * czx + zps * cxy ;

         xps = x72 + x50 ;
         yps = y72 + y50 ;
         zps = z72 + z50 ;

         cyz = y74 * z60 - z74 * y60 ;
         czx = z74 * x60 - x74 * z60 ;
         cxy = x74 * y60 - y74 * x60 ;
         vol[i] += xps * cyz + yps * czx + zps * cxy ;

         xps = x74 + x30 ;
         yps = y74 + y30 ;
         zps = z74 + z30 ;

         cyz = y71 * z50 - z71 * y50 ;
         czx = z71 * x50 - x71 * z50 ;
         cxy = x71 * y50 - y71 * x50 ;
         vol[i] += xps * cyz + yps * czx + zps * cxy ;

         vol[i] *= vnormq ;

      }

   }
}

BENCHMARK(BM_VOL3D_CALC_RAW)->Arg(SHORT)->Arg(MEDIUM)->
                              Arg(LONG)->Unit(benchmark::kMicrosecond);

static void BM_DEL_DOT_VEC_2D_RAW(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(DEL_DOT_VEC_2D);

   Real_ptr x = loop_data.array_1D_Real[0];
   Real_ptr y = loop_data.array_1D_Real[1];
   Real_ptr xdot = loop_data.array_1D_Real[2];
   Real_ptr ydot = loop_data.array_1D_Real[3];
   Real_ptr div = loop_data.array_1D_Real[4];

   ADomain domain(state.range(0), /* ndims = */ 2);

   UnalignedReal_ptr x1,x2,x3,x4 ;
   UnalignedReal_ptr y1,y2,y3,y4 ;
   UnalignedReal_ptr fx1,fx2,fx3,fx4 ;
   UnalignedReal_ptr fy1,fy2,fy3,fy4 ;

   NDSET2D(x,x1,x2,x3,x4) ;
   NDSET2D(y,y1,y2,y3,y4) ;
   NDSET2D(xdot,fx1,fx2,fx3,fx4) ;
   NDSET2D(ydot,fy1,fy2,fy3,fy4) ;

   const Real_type ptiny = 1.0e-20;
   const Real_type half  = 0.5;

   for ( auto _ : state ) {

      for (Index_type ii = 0 ; ii < domain.n_real_zones ; ii++ ) {

         Index_type i  = domain.real_zones[ii] ;

         Real_type xi  = half * ( x1[i]  + x2[i]  - x3[i]  - x4[i]  ) ;
         Real_type xj  = half * ( x2[i]  + x3[i]  - x4[i]  - x1[i]  ) ;

         Real_type yi  = half * ( y1[i]  + y2[i]  - y3[i]  - y4[i]  ) ;
         Real_type yj  = half * ( y2[i]  + y3[i]  - y4[i]  - y1[i]  ) ;

         Real_type fxi = half * ( fx1[i] + fx2[i] - fx3[i] - fx4[i] ) ;
         Real_type fxj = half * ( fx2[i] + fx3[i] - fx4[i] - fx1[i] ) ;

         Real_type fyi = half * ( fy1[i] + fy2[i] - fy3[i] - fy4[i] ) ;
         Real_type fyj = half * ( fy2[i] + fy3[i] - fy4[i] - fy1[i] ) ;

         Real_type rarea  = 1.0 / ( xi * yj - xj * yi + ptiny ) ;

         Real_type dfxdx  = rarea * ( fxi * yj - fxj * yi ) ;

         Real_type dfydy  = rarea * ( fyj * xi - fyi * xj ) ;

         Real_type affine = ( fy1[i] + fy2[i] + fy3[i] + fy4[i] ) /
                            ( y1[i]  + y2[i]  + y3[i]  + y4[i]  ) ;

         div[i] = dfxdx + dfydy + affine ;
      }

   }
}

BENCHMARK(BM_DEL_DOT_VEC_2D_RAW)->Arg(SHORT)->Arg(MEDIUM)->
                                  Arg(LONG)->Unit(benchmark::kMicrosecond);

static void BM_COUPLE_RAW(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(COUPLE);

   Complex_ptr t0 = loop_data.array_1D_Complex[0];
   Complex_ptr t1 = loop_data.array_1D_Complex[1];
   Complex_ptr t2 = loop_data.array_1D_Complex[2];
   Complex_ptr denac = loop_data.array_1D_Complex[3];
   Complex_ptr denlw = loop_data.array_1D_Complex[4];


   ADomain domain(state.range(0), /* ndims = */ 3);

   Index_type imin = domain.imin;
   Index_type imax = domain.imax;
   Index_type jmin = domain.jmin;
   Index_type jmax = domain.jmax;
   Index_type kmin = domain.kmin;
   Index_type kmax = domain.kmax;

   const Real_type clight=3.e+10;
   const Real_type csound=3.09e+7;
   const Real_type omega0= 0.9;
   const Real_type omegar= 0.9;
   const Real_type dt= 0.208;
   const Real_type c10 = 0.25 * (clight / csound);
   const Real_type fratio = sqrt(omegar / omega0);
   const Real_type r_fratio = 1.0/fratio;
   const Real_type c20 = 0.25 * (clight / csound) * r_fratio;
   const Complex_type ireal(0.0, 1.0);

   for ( auto _ : state ) {

      for (Index_type k = kmin; k < kmax; k++) {

         for (Index_type j = jmin; j < jmax; j++) {

            Index_type it0=    ((k)*(jmax+1) + (j))*(imax+1) ;
            Index_type idenac= ((k)*(jmax+2) + (j))*(imax+2) ;

            for (Index_type i = imin; i < imax; i++) {

               Complex_type c1 = c10 * denac[idenac+i];
               Complex_type c2 = c20 * denlw[it0+i];

               /* promote to doubles to avoid possible divide by zero
                  errors later on. */
               Real_type c1re = real(c1);  Real_type c1im = imag(c1);
               Real_type c2re = real(c2);  Real_type c2im = imag(c2);

               /* compute lamda = sqrt(|c1|^2 + |c2|^2) using doubles
                  to avoid underflow. */
               Real_type zlam = c1re*c1re + c1im*c1im +
                                c2re*c2re + c2im*c2im + 1.0e-34;
               zlam = sqrt(zlam);
               Real_type snlamt = sin(zlam * dt * 0.5);
               Real_type cslamt = cos(zlam * dt * 0.5);

               Complex_type a0t = t0[it0+i];
               Complex_type a1t = t1[it0+i];
               Complex_type a2t = t2[it0+i] * fratio;

               Real_type r_zlam= 1.0/zlam;
               c1 *= r_zlam;
               c2 *= r_zlam;
               Real_type zac1 = zabs2(c1);
               Real_type zac2 = zabs2(c2);

               /* compute new A0 */
               Complex_type z3 = ( c1 * a1t + c2 * a2t ) * snlamt ;
               t0[it0+i] = a0t * cslamt -  ireal * z3;

               /* compute new A1  */
               Real_type r = zac1 * cslamt + zac2;
               Complex_type z5 = c2 * a2t;
               Complex_type z4 = conj(c1) * z5 * (cslamt-1);
               z3 = conj(c1) * a0t * snlamt;
               t1[it0+i] = a1t * r + z4 - ireal * z3;

               /* compute new A2  */
               r = zac1 + zac2 * cslamt;
               z5 = c1 * a1t;
               z4 = conj(c2) * z5 * (cslamt-1);
               z3 = conj(c2) * a0t * snlamt;
               t2[it0+i] = ( a2t * r + z4 - ireal * z3 ) * r_fratio;

            }  // i loop

         }  // j loop

      }  // k loop

   } // benchmark loop
}

BENCHMARK(BM_COUPLE_RAW)->Arg(SHORT)->Arg(MEDIUM)->
                          Arg(LONG)->Unit(benchmark::kMicrosecond);

static void BM_FIR_RAW(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(FIR);

   Real_ptr out = loop_data.array_1D_Real[0];
   Real_ptr in = loop_data.array_1D_Real[1];

   const Index_type coefflen = 16;
   Real_type coeff[coefflen] = { 3.0, -1.0, -1.0, -1.0,
                                -1.0, 3.0, -1.0, -1.0,
                                -1.0, -1.0, 3.0, -1.0,
                                -1.0, -1.0, -1.0, 3.0 };
   const Index_type len_minus_coeff = state.range(0) - coefflen;

   Index_type val = 0;

   for ( auto _ : state ) {

      for (Index_type i = 0 ; i < len_minus_coeff ; i++ ) {
         Real_type sum = 0.0;

         for (Index_type j = 0; j < coefflen; ++j ) {
            sum += coeff[j]*in[i+j];
         }
         out[i] = sum;
      }

   }
}

BENCHMARK(BM_FIR_RAW)->Arg(171)->Arg(5001)->
                       Arg(44217)->Unit(benchmark::kMicrosecond);
