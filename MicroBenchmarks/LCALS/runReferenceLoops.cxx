//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Source file with routines to generate reference loop times for
// figure of merit (FOM) calculations.
//

#include "LCALSSuite.hxx"
#include "LCALSStats.hxx"

#include<string>
#include<iostream>

//
// Prototypes for file scope routines containing reference loops
//

namespace {

void runReferenceLoop0(LoopStat& lstat, unsigned ilen);
void runReferenceLoop1(LoopStat& lstat, unsigned ilen);

}  // closing brace for unnamed namespace


//
// Define reference loop information.
//
// Note: That this may need to be tweaked in the future.
//
void defineReferenceLoopRunInfo()
{
   LoopSuiteRunInfo& suite_info = getLoopSuiteRunInfo();

   suite_info.ref_loop_stat = LoopStat(NUM_LENGTHS);
   LoopStat& ref_loop_stat = suite_info.ref_loop_stat;

   ref_loop_stat.loop_length[LONG]   = 24336;
   ref_loop_stat.loop_length[MEDIUM] = 3844;
   ref_loop_stat.loop_length[SHORT]  = 64;
   ref_loop_stat.samples_per_pass[LONG]   = 30000;
   ref_loop_stat.samples_per_pass[MEDIUM] = 300000;
   ref_loop_stat.samples_per_pass[SHORT]  = 50000000;
}


//
// Execute reference loops. The intent is to generate a time for
// fast loops that any compile should be able to optimize well.  
// We run two reference loops and take the min execution time.
// This time is used as a reference against which to compre the 
// execution times of other loops for figure of merit computation.
//
// Note: That this may need to be tweaked in the future.
//
void computeReferenceLoopTimes()
{
#ifdef TESTSUITE
   std::cout << "\n computeReferenceLoopTimes..." << std::endl;
#endif
   LoopSuiteRunInfo& suite_info = getLoopSuiteRunInfo();
   LoopStat& ref_loop_stat = suite_info.ref_loop_stat;


   LoopStat  lstat0(suite_info.num_loop_lengths);
   lstat0 = ref_loop_stat;
   for (unsigned ilen = 0; ilen < NUM_LENGTHS; ++ilen) {
      runReferenceLoop0(lstat0, ilen);
   }

   LoopStat  lstat1(suite_info.num_loop_lengths);
   lstat1 = ref_loop_stat;
   for (unsigned ilen = 0; ilen < NUM_LENGTHS; ++ilen) {
      runReferenceLoop1(lstat1, ilen);
   }

   for (unsigned ilen = 0; ilen < NUM_LENGTHS; ++ilen) {
      ref_loop_stat.loop_run_time[ilen].push_back(
         std::min(lstat0.loop_run_time[ilen][0],
                  lstat1.loop_run_time[ilen][0]) );
#if 0 // Just for checking...
      std::cout << "\t len : " << ilen << " rloop0 time = "
                << lstat0.loop_run_time[ilen][0] << std::endl;
      std::cout << "\t len : " << ilen << " rloop1 time = "
                << lstat1.loop_run_time[ilen][0] << std::endl;
      std::cout << "\t ref len, time = " << ilen << " , "
                << ref_loop_stat.loop_run_time[ilen][0] << std::endl;
#endif
   }
}


//
// Prototypes for file scope reference loop routines
//

namespace {

//
// Element-wise vector product
//
void runReferenceLoop0(LoopStat& lstat, unsigned ilen)
{
   LoopData& loop_data = getLoopData();

   Index_type len = lstat.loop_length[ilen];
   int num_samples = lstat.samples_per_pass[ilen];
   LoopTimer ltimer;

   loopInit(REF_LOOP, lstat);

   Real_ptr a = loop_data.array_1D_Real[0];
   Real_ptr b = loop_data.array_1D_Real[1];
   Real_ptr c = loop_data.array_1D_Real[2];

   TIMER_START(ltimer);
   for (SampIndex_type isamp = 0; isamp < num_samples; ++isamp) {

      for (Index_type i=0 ; i<len ; i++ ) {
         c[i] = a[i] * b[i];
      }

   }
   TIMER_STOP(ltimer);

   copyTimer(lstat, ilen, ltimer);
}


//
// Vector dot product
//
void runReferenceLoop1(LoopStat& lstat, unsigned ilen)
{
   LoopData& loop_data = getLoopData();

   Index_type len = lstat.loop_length[ilen];
   int num_samples = lstat.samples_per_pass[ilen];
   LoopTimer ltimer;

   loopInit(REF_LOOP, lstat);

   Real_ptr a = loop_data.array_1D_Real[0];
   Real_ptr b = loop_data.array_1D_Real[1];
   Real_ptr c = loop_data.array_1D_Real[2];

   Real_type val = 0.0;

   TIMER_START(ltimer);
   for (SampIndex_type isamp = 0; isamp < num_samples; ++isamp) {

      Real_type q = 0.0;
      for (Index_type i=0 ; i<len ; i++ ) {
         c[i] = a[i] * b[i];
      }

      val = q*isamp;
   }
   TIMER_STOP(ltimer);

   //
   // RDH added this. Without it compiler may optimize out
   // outer sampling loop because value of q was not used.
   //
   loop_data.scalar_Real[0] = (val + 0.00123) / (val - 0.00123);

   copyTimer(lstat, ilen, ltimer);
}

}  // closing brace for unnamed namespace
