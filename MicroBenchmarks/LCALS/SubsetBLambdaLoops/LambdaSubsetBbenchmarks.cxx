//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Source file containing LCALS "B" subset forall lambda loops using 
// the google benchmark library.
//

#include <benchmark/benchmark.h>
#include "../LCALSSuite.hxx"
#include "../SubsetDataB.hxx"
#include "../LCALSTraversalMethods.hxx"

static void BM_INIT3_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(INIT3);

   Real_ptr out1 = loop_data.array_1D_Real[0];
   Real_ptr out2 = loop_data.array_1D_Real[1];
   Real_ptr out3 = loop_data.array_1D_Real[2];
   Real_ptr in1 = loop_data.array_1D_Real[3];
   Real_ptr in2 = loop_data.array_1D_Real[4];

   for( auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type i) {
         out1[i] = out2[i] = out3[i] = - in1[i] - in2[i];
      } );

   }
}

BENCHMARK(BM_INIT3_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);


static void BM_MULADDSUB_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(MULADDSUB);

   Real_ptr out1 = loop_data.array_1D_Real[0];
   Real_ptr out2 = loop_data.array_1D_Real[1];
   Real_ptr out3 = loop_data.array_1D_Real[2];
   Real_ptr in1 = loop_data.array_1D_Real[3];
   Real_ptr in2 = loop_data.array_1D_Real[4];

   for ( auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type i) {
         out1[i] = in1[i] * in2[i] ;
         out2[i] = in1[i] + in2[i] ;
         out3[i] = in1[i] - in2[i] ;
      } );

   }
}

BENCHMARK(BM_MULADDSUB_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);


static void BM_IF_QUAD_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(IF_QUAD);

   Real_ptr a = loop_data.array_1D_Real[0];
   Real_ptr b = loop_data.array_1D_Real[1];
   Real_ptr c = loop_data.array_1D_Real[2];
   Real_ptr x1 = loop_data.array_1D_Real[3];
   Real_ptr x2 = loop_data.array_1D_Real[4];

   for ( auto _ : state ) { 

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type i) {
         Real_type s = b[i]*b[i] - 4.0*a[i]*c[i];
         if ( s >= 0 ) {
            s = sqrt(s);
            x2[i] = (-b[i]+s)/(2.0*a[i]);
            x1[i] = (-b[i]-s)/(2.0*a[i]);
         } else {
            x2[i] = 0.0;
            x1[i] = 0.0;
         }
      } );

   }
}

BENCHMARK(BM_IF_QUAD_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);



static void BM_TRAP_INT_LAMBDA(benchmark::State& state) {

   LoopData& loop_data = getLoopData();

   loopInit(TRAP_INT);

   Real_type xn = loop_data.scalar_Real[0];
   Real_type x0 = loop_data.scalar_Real[1];
   Real_type xp = loop_data.scalar_Real[2];
   Real_type y = loop_data.scalar_Real[3];
   Real_type yp = loop_data.scalar_Real[4];

   Index_type nx = loop_data.array_1D_Indx[0][0] + 1;

   const Real_type h = (xn - x0) / nx;
   Real_type sumx = 0.5*( trap_int_func(x0, y, xp, yp) +
                          trap_int_func(xn, y, xp, yp) );

   Real_type val = 0;

   for (auto _ : state) {

      forall<exec_policy>(0, state.range(0),
      [&] (Index_type i) {
         Real_type x = x0 + i*h;
         sumx += trap_int_func(x, y, xp, yp);
      } );
      benchmark::DoNotOptimize(val = sumx * h);

   }
}

BENCHMARK(BM_TRAP_INT_LAMBDA)->Arg(171)->Arg(5001)->
                         Arg(44217)->Unit(benchmark::kMicrosecond);
