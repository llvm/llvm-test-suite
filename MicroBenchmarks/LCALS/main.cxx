//
// See README-LCALS_license.txt for access and distribution restrictions
//
// This code is under continuing development.  Go to http://codesign.llnl.gov
// to acquire the latest released version.
//

//
// Main program for LCALS suite.
//

#include <cstdlib>

#include<string>
#include<iostream>
#include<algorithm>

#include <unistd.h>

#include "LCALSSuite.hxx"
#include <benchmark/benchmark.h>

int main(int argc, char *argv[])
{

   //
   // Define some variables used to define part of suite execution.
   //
   bool do_fom = true;
   bool run_misc = false;
   bool input_error = false;
   std::string output_dirname;

   //
   // Process command line args and report correct usage if necessary.
   //
   // if (argc == 1) no args to check...
#ifdef TESTSUITE
   if (argc > 1) {
      std::string arg = argv[1];
      if ( arg == "-misc" ) {
         run_misc = true; 
      } else {
         output_dirname = argv[1];
      }
   }

   if (argc > 2) {
      if ( !run_misc ) { 
         input_error = true; 
      } else {
         output_dirname = argv[2];
      }
   }

   if ( argc > 3) {
      input_error = true; 
   } 

   if ( !input_error ) { 

      if ( !output_dirname.empty() && !recursiveMkdir(output_dirname) ) {
        std::cout << "Problem with given output directory name." << std::endl;
        std::cout << "No file output will be generated." << std::endl;
      } 

   } else {
      std::cout << "ERROR RUNNING EXECUTABLE!\n\n";
      std::cout << "CORRECT USAGE:\n";
      std::cout << "\t" << argv[0] 
                << " -misc <output directory name>, both args optional\n\n"
                << "\tIf '-misc' option is given, " 
                << "benchmark variants plus others may be run.\n"
                << "\tActual loop variants to run are set below using the\n"
                << "\tvector 'run_variants'. Note that the compiler switch\n"
                << "\tin the Makefile may be required for full compilation.\n\n"
                << "\tWhen no output directory is provided,\n"
                << "\trun summary will be printed to standard output\n" 
                << "\tIf directory name is provided, execution summary and\n"
                << "\ttext files suitable for importing into MS Excel will\n"
                << "\tbe written there." << std::endl;
      exit(-1);
      return -1;
   }
#endif

   //
   // Define some parameters specifying how suite of loops will execute.
   //
   // See README-LCALS_instructions.txt file for additional description of how 
   // to control compilation and execution of loop suite.
   //
   unsigned num_suite_passes = 1;
#if defined(LCALS_VERIFY_CHECKSUM_ABBREVIATED)
   //
   // When verifying checksums, we only take one pass through the suite of loops
   // as this is sufficient.
   // 
   num_suite_passes = num_checksum_suite_passes;
#endif

   //
   // Specify fraction of pre-defined loop sample counts to use.
   // Smaller value reduces total run time. However, a value too
   // small will result in inaccurate timings.
   //
   double sample_frac = 1.0;

   //
   // Specify multiplication factor used to deviate from pre-defined loop 
   // lengths to use.  For example, setting factor to 'a' will roughly
   // multiply the length of "1D" loops by a and will multiply total number 
   // of iterations of "domain-based" loops by a^N, where N is the 
   // spatial dimension of the domain used by the loop.
   //
   double loop_length_factor = 1.0;

   //
   //  Specify which loops lengths to run by true/false
   //  value in 'run_loop_length' array.
   //
   bool run_loop_length[NUM_LENGTHS];
   run_loop_length[LONG] = true;
   run_loop_length[MEDIUM] = true;
   run_loop_length[SHORT] = true;


   //
   //  Specify loop kernels to run by true/false value in 'run_loop' array.
   //
   //  NOTE: If COMPILE_* macro constant associated with each lernel
   //        is not defined, then those kernels will not be compiled 
   //        and thus will not be run.
   //
   bool run_loop[NUM_LOOP_KERNELS];
   for (unsigned iloop = 0; iloop < NUM_LOOP_KERNELS; ++iloop) {
      run_loop[iloop] = false;
   }


#if defined(LCALS_DO_OMP_ONLY)

   // Loop Subset A: Loops extracted from LLNL app codes.
   run_loop[PRESSURE_CALC ] = true;
   run_loop[PRESSURE_CALC_ALT ] = true;
   run_loop[ENERGY_CALC   ] = true;
   run_loop[ENERGY_CALC_ALT   ] = true;
   run_loop[VOL3D_CALC    ] = true;
   run_loop[DEL_DOT_VEC_2D] = true;
   run_loop[COUPLE        ] = true;
   run_loop[FIR           ] = true;

   // Loop Subset B: "Basic" Loops.
   run_loop[INIT3         ] = true;
   run_loop[MULADDSUB     ] = true;
   run_loop[IF_QUAD       ] = true;
   run_loop[TRAP_INT      ] = true;

   // Loop Subset C: Loops from older Livermore Loops in "C" suite.
   run_loop[PIC_2D        ] = true; 

#else  // else run all loop kernels

   // Loop Subset A: Loops extracted from LLNL app codes.
   run_loop[PRESSURE_CALC ] = true;
   run_loop[ENERGY_CALC   ] = true;
   run_loop[VOL3D_CALC    ] = true;
   run_loop[DEL_DOT_VEC_2D] = true;
   run_loop[COUPLE        ] = true;
   run_loop[FIR           ] = true;

   // Loop Subset B: "Basic" Loops.
   run_loop[INIT3         ] = true;
   run_loop[MULADDSUB     ] = true;
   run_loop[IF_QUAD       ] = true;
   run_loop[TRAP_INT      ] = true;

   // Loop Subset C: Loops from older Livermore Loops in "C" suite.
   run_loop[HYDRO_1D      ] = true;
   run_loop[ICCG          ] = true;
   run_loop[INNER_PROD    ] = true;
   run_loop[BAND_LIN_EQ   ] = true;
   run_loop[TRIDIAG_ELIM  ] = true;
   run_loop[EOS           ] = true;
   run_loop[ADI           ] = true;
   run_loop[INT_PREDICT   ] = true; 
   run_loop[DIFF_PREDICT  ] = true; 
   run_loop[FIRST_SUM     ] = true;
   run_loop[FIRST_DIFF    ] = true;
   run_loop[PIC_2D        ] = true; 
   run_loop[PIC_1D        ] = true;
   run_loop[HYDRO_2D      ] = true;
   run_loop[GEN_LIN_RECUR ] = true;
   run_loop[DISC_ORD      ] = true;
   run_loop[MAT_X_MAT     ] = true;
   run_loop[PLANCKIAN     ] = true;
   run_loop[IMP_HYDRO_2D  ] = true;
   run_loop[FIND_FIRST_MIN] = true;

#endif


   //
   // Specify which loop variants are executed. To run different loop variants,
   // change which enum values are pushed onto the run-variants vector here. 
   //
   // IMPORTANT: The first variant added is used as the reference
   //            variant for reporting relative execution timing data
   //            and checksum comparisons.
   //
   std::vector<LoopVariantID> run_variants;
   if ( !run_misc ) {
      //
      // These variants comprose the LCALS benchmark.
      //

#if defined(LCALS_DO_OMP_ONLY)

      run_variants.push_back(RAW_OMP);
      run_variants.push_back(FORALL_LAMBDA_OMP);

#else  // run other variants in addition to OMP variants

      run_variants.push_back(RAW);
      run_variants.push_back(FORALL_LAMBDA);
      run_variants.push_back(RAW_OMP);
      run_variants.push_back(FORALL_LAMBDA_OMP);

#endif

   } else {
      //
      // These variants are used for miscellaneous studies.
      //

#if defined(LCALS_DO_OMP_ONLY)

      run_variants.push_back(RAW_OMP);
      run_variants.push_back(FORALL_LAMBDA_OMP);
#if defined(LCALS_DO_MISC)
      run_variants.push_back(FORALL_FUNCTOR_OMP);
//    run_variants.push_back(FORALL_LAMBDA_OMP_TYPEFIX);
#endif // if LCALS_DO_MISC


#else  // run other variants in addition to OMP variants

      //
      // Bechmark variants.
      // 
      run_variants.push_back(RAW);
      run_variants.push_back(FORALL_LAMBDA);
//    run_variants.push_back(RAW_OMP);
//    run_variants.push_back(FORALL_LAMBDA_OMP);

      //
      // Other available loop variants.
      // 
#if defined(LCALS_DO_MISC)
//    run_variants.push_back(FORALL_HYBRID_LAMBDA);

//    run_variants.push_back(FORALL_FUNCTOR);
//    run_variants.push_back(FORALL_FUNCTOR_OMP);

//    run_variants.push_back(RAW_FUNC);

//    run_variants.push_back(FORALL_LAMBDA_TYPEFIX);
//    run_variants.push_back(FORALL_LAMBDA_OMP_TYPEFIX);
//    run_variants.push_back(FORALL_HYBRID_LAMBDA_TYPEFIX);
#endif // if LCALS_DO_MISC

#endif

   }


   //
   // Obtain and report hostname.
   // 
   const int host_namelen = 64;
   char host[host_namelen];
   gethostname( host, host_namelen );
   std::string host_name(host);

#ifdef TESTSUITE
   std::cout << "\n Running loop suite on " << host_name << std::endl;
#endif
   //
   // Specify size in bytes of largest data cache level on machine so that 
   // caches can be properly flushed between execution of different loops.
   // 

   CacheIndex_type cache_size = 0;
   if ( host_name.find("rzalastor") != std::string::npos ) {
      cache_size = 12000000;  // 12MB on rzalastor 
   } else if ( host_name.find("rzmerl") != std::string::npos ) {
      cache_size = 20000000;  // 20MB on rzmerl  
   } else if ( host_name.find("dawn") != std::string::npos ) {
      cache_size = 8000000;   // 8MB on dawn/rzdawndev
   } else if ( host_name.find("rzuseq") != std::string::npos ||
               host_name.find("vulcan") != std::string::npos ||
               host_name.find("sequoia") != std::string::npos ) {
      cache_size = 32000000;  // 32MB on BG/Q
   } 
#ifdef TESTSUITE
   else {
      std::cout << "\n WARNING: unknown system cache size. " 
                << "Timing results may be suspect!!" << std::endl;
   }
#endif

 
   //
   // Allocate data for running loops and generating execution timings.
   // Also, set structures that define how loops will be run.
   //
   allocateLoopSuiteRunInfo(host_name,
                            NUM_LOOP_KERNELS,
                            NUM_LENGTHS,
                            num_suite_passes, 
                            run_loop_length,
                            cache_size);

   
   defineLoopSuiteRunInfo( run_variants, run_loop, sample_frac,
                                                   loop_length_factor );

   allocateLoopData();


   if (do_fom) {
      //
      // Compute reference times for figure of merit (FOM) calculation.
      //
      computeReferenceLoopTimes();
   }

   /*************** TEST SUITE ****************
    *                                         *
    *  Using google benchmark as test Runner  *
    *                                         *
    *******************************************/


   ::benchmark::Initialize(&argc, argv);
   if(::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
   ::benchmark::RunSpecifiedBenchmarks();


#ifdef TESTSUITE
   // Run loops, record timings, etc.
   //
   for (unsigned ipass = 0; ipass < num_suite_passes; ++ipass) {
      std::cout << "\n run suite: pass = " << ipass << std::endl;

      for (unsigned ivariant = 0; ivariant < run_variants.size(); ++ivariant) {

         std::string loop_variant_name = 
            getVariantName(run_variants[ivariant]);

         std::cout << "\t run loop variant ---> " 
                   << loop_variant_name << std::endl;

         for (unsigned ilen = 0; ilen < NUM_LENGTHS; ++ilen) {

            if (run_loop_length[ilen]) {

               LoopLength rilen = static_cast<LoopLength>(ilen);

               runLoopVariant(run_variants[ivariant], run_loop, rilen) ;

            }  // if loop length is run

         } // iterate over loop lengths

      }  // iterate over loop variants

   }  // iterate over loop suite passes
#endif

#ifdef TESTSUITE
   //
   //  Generate report(s).
   //
   std::cout << "\n generate reports...." << std::endl;
  
   std::vector<std::string> run_variant_names = getVariantNames(run_variants);

   generateTimingReport(run_variant_names, output_dirname);
   generateChecksumReport(run_variant_names, output_dirname); 
   generateFOMReport(run_variant_names, output_dirname);
#endif

   //
   //  Clean up.
   //
   freeLoopData();
#ifdef TESTSUITE
   std::cout << "\n freeLoopSuiteRunInfo..." << std::endl;
#endif
   freeLoopSuiteRunInfo();
#ifdef TESTSUITE
   std::cout << "\n DONE!!! " << std::endl;
#endif
   return 0 ;
}

