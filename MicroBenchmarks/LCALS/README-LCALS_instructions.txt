//
// See README-LCALS_license.txt for access and distribution restrictions
//
================================================================================
================================================================================
LCALS: Livermore Compiler Analysis Loop Suite
 by Rich Hornung (hornung1@llnl.gov), 
    Center for Applied Scientific Computing,
    Lawrence Livermore National Laboratory 
================================================================================
================================================================================

 o This code is under continuing development.  Go to http://codesign.llnl.gov
   to acquire the latest released version.

 o This loop suite is designed to measure performance for a variety of loops
   using different compilers and platforms.  In particular, the suite 
   helps to understand compiler optimization, run-time performance issues,
   and platform capabilities.  The suite is also useful as a source of
   example code snippets for interactions with compiler developers.

 o The loops in the suite are partitioned into three subsets based on their 
   origins (and also to avoid having them all in a single source file).  Each 
   loop is implemented using multiple software constructs (i.e., referred 
   to herein as "variants").  The three loop subsets are:

   -  Subset A: Loops representative of those found in application codes.
      They are implemented in source files named runA<variant>Loops.cxx.  

   -  Subset B: Basic loops that help to illustrate compiler optimization 
      issues. They are implemented in source files named runB<variant>Loops.cxx

   -  Subset C: Loops extracted from "Livermore Loops coded in C" developed by 
      Steve Langer, which were derived from the Fortran version by Frank 
      McMahon.  They are implemented in source files runC<variant>Loops.cxx 

   Please see the contents of the loop source files to understand the 
   differences among the variants.

 o New loops may be added to the suite by inserting them into appropriate 
   loop source files and modifying a few other files that control suite 
   execution and parametrization.  Details are provided below.

 o Various parameters can be adjusted to control how loops are defined and run.
 
   -- Each loop may be run with different loop lengths (currently up to three
      lengths for each loop) and will be sampled some number of times to 
      generate execution timing data.  Loop length and sampling parameters 
      may be modified to evaluate different platform performance 
      characteristics.  Details are provided below.

 o Various run time statistics can be generated for analysis.  Currently,
   these include: min run time, max run time, average run time, 
   standard deviation across run times, and average execution time relative 
   to a reference loop variant.  Here, run time is the time required to 
   execute the loop for one "sampling" pass through the suite.  See below.


--------------------------------------------------------------------------------
Loop kernels and variants:

 o Each loop in the suite is defined by its traditional C/C++ for-loop 
   "kernel".  Then, each loop appears in multiple variants that use different
   programming and execution constructs.

 o Loops that emply traditional C/C++ for-loop syntax are referred to as 
   "Raw" variants.  The "Raw" variant of each loop represents the version 
   obtained from its original source, plus minor modifications necessary 
   to plug into the loop suite framework.  For example, the loops in the 
   runCRawLoops.cxx file are essentially verbatim from the Livermore Loops 
   Coded in C" suite mentioned above.  Typically, the "Raw" loops serve as 
   reference implemenation for runtime comparisons.  

 o Other variants use loop traversal C++ template methods and represent the 
   loop body as a lambda function or functor class.  One of the main goals 
   of the suite is to assess how SIMD vectorization, OpenMP multithreading, 
   etc. work with these different loop implementation choices.

   Note that only a subset of the loops in the suite appear in the OpenMP
   variants since many of the loops do not benefit from thread parallelism
   due to OpenMP overheads.  OpenMP loops are implmented in source files
   named runOMP<variant>Loops.cxx; in particular, they are not broken out
   into separate source files based on the subsets described above.

 o Although all loop bodies contain only C-syntax, the loop framework 
   uses C++ classes and templates. So a C++ compiler is required to compile 
   the code.  All C++ compilers should be able to compile the framework
   code and "Raw" loop variants.  

 o Not all compilers implement the OpenMP standard. Thus, those loop variants
   may not be compiled and run depending on the compiler being used.

 o The intent of the C++ lambda and functor loop variants is to evaluate 
   compilers in the context of C++ abstraction layers using template methods. 
   Not all compilers support standard C++ lambda expressions at this time.  
   Thus, the lambda variants of the loops may not be compiled and run 
   depending on the compiler being used.


******************** Test Suite Note ***********************
*                                                          *
*     Below is the original build instructions, the        *
*     test suite replaces this build system with the       *
*     llvm test-suite CMake system.  The control of        *
*     loop suite and timing has been altered to use        *
*     the google benchmark library included in the         *
*     MicroBenchmarks directory of the llvm test-suite.    *
*                                                          *
************************************************************
--------------------------------------------------------------------------------
Compiling and running the loop suite:

 The loop suite is typically compiled by typing 'make' and then executed as

    ./lcals.exe <optional output directory>

 o The executable generated by the Makefile accepts an optional argument
   which is the name of a directory for placing output files that contain 
   detailed timing, checksum, and FOM (when specified) results.  Some of 
   these files provide a summary of loop suite performance.  Othere
   contain subsets of this information in comma-delimited text files that may
   be imported into Microsoft Excel to generate spreadsheets and plots.  
   When no output directory is given, a summary of the results is printed 
   to standard output.  

 o LCALS is highly parametrized to explore many compilation and execution
   options. Exercising the full range of options can be achieved by making
   straightforward modifications in a few files, as describe below:

   -- Makefile: This file contains a simple build system for the code. 
                It has a variety of configurations for current LLNL 
                computing systems. Building for other platforms or changing
                any compiler options can done by modifying this file.

   -- LCALS_rules.mk: This file contains "-D" compilation options that 
                conrol some aspects of LCALS parametrization. The effect of 
                these options is described in the comments in this file.
                It is also helpful to see how they are used in the 
                LCALSParams.hxx file.

   -- main.cxx: The main program determines many of the LCALS execution
                options, such as which loops are run (kernels and variants).

   -- LCALSSuite.cxx: The routine defineLoopSuiteRunInfo() in this file 
                defines loop lengths and sampling parameters for each loop
                in the suite.  It also defines loop weights used in Figure
                of Merit (FOM) calculations. 

   -- LCALSSuite.hxx: This file contains '#define' preprocessor directives
                that can be used to turn on/off compilation of individual
                loop kernels and loop variants in the suite. This can be 
                helpful for generating assembly code in small doses.

 o Details on many of these items are given in the next section.
                

--------------------------------------------------------------------------------
Controlling loop suite execution and timing output:

 o The execution of the loop suite follows the pattern described here:

   Iterate over specified number of passes through the loop suite {

      Iterate over specified loop variants to run {

         Iterate over loop lengths to run (e.g., long, medium, short) {

            Iterate over each loop specified to run {

               TIMER_START()
               Iterate over specified number of samples (for loop and length) {

                  Execute loop variant and length.
 
               }
               TIMER_STOP()

            }  // end iteration over loops to run

         } // end iteration over loop lengths

      } // end iteration over loop variants

   } // end iteration over suite passes

 o The loop suite is parametrized so that its execution may be controlled 
   by editing various items in a small number of source and header files
   as described below:

   -- Set number of passes through the suite by setting the variable
      'num_suite_passes' in main.cxx.

   -- Set loop variants to run by adding the corresponding enumeration
      constants to the vector 'run_variants' in main.cxx.  To prevent a 
      variant from running, simply comment out the line which adds the 
      corresponding enum value to the vector.

      NOTE: The first entry added this array indicates the reference variant
            for relative execution time statistics.

      NOTE: An additional argument may be given to the exectuable to run
            loops outside of the standard LCASL benchmark.  This requires 
            that "BUILD_MISC" is defined in the Makefile. 

   -- Set which loop lengths to run by setting the appropriate entry in
      the array 'run_loop_length' in main.cxx (true/false for each length).

   -- Set which loop kernels will run be setting entries in the array 
      'run_loop' in main.cxx (true/false for each loop).

   -- The lengths and number of samples per pass for each loop are set 
      in the routine defineLoopSuiteRunInfo() in LCALSSuite.cxx.

      NOTE: The "samples per pass" values for each loop were determined 
      manually to give approximately 1 second of execution time for its
      serial raw variant on an Intel ES-2670 node. To reduce or increase the 
      total suite execution time, or change the loop lengths used, change 
      the 'sample_frac' and/or 'loop_length_factor' variables in 
      main.cxx.  All default loop lengths will be multiplied by the 
      loop_length_factor value.  The sample count for each loop will be 
      multiplied by sample_frac/loop_length_factor.

   -- The "LoopKernelID" and "LoopLength" enumeration types in the file 
      LCALSSuite.hxx are used to identify loops and loop lengths
      in the suite.  Macros are also provided in that file to conditionally
      compile each loop in the suite.

      The way in which the loops are compiled can influence execution times.
      For example, some compilers perform optimizations for loops compiled
      individually that they do not perform when the same loop is compiled as
      part of a larger suite.

 o All loop forms use the same data arrays, which are pre-allocated based 
   on the loop lengths.  To help with SIMD vectorization and ensure corretness
   data arrays are allocated to be aligned width SIMD vector unit boundaries. 
   This can be changed by setting the 'LCALS_DATA_ALIGN' constant in the
   file LCALSParams.hxx.

 o To minimize the effects of execution of each loop on the others, 
   data caches are flushed before each loop is run. 

   -- Data cache size is set for some LLNL platforms based on hostname.
      If unknown, a warning message will appear when loop suite is run.
      Please edit main.cxx to set the largest data cache size for other 
      platforms.

 o A simple checksum mechanism is provided to verify that different variants 
   of each loop, and implementation changes made to individual loops, generate
   the same numerical results.  "-D" compiler options are provided in the
   LCALS_rules.mk file to control this behavior.  Note that certain levels 
   and types of compiler optimization will cause slight differences in 
   checksums due to changes in operation order, for example.  Thus, the 
   checksums may only be a qualitative indicator of correct execution.

   -- Note that the routines loopInit() and loopFinalize() in LCALSSuite.cxx
      initialize data and compute result checksums for each loop.  These
      must remain consistent with the data used in each loop for correctness.


 o There are two mechanisms available to generate execution timing data for
   loops in the suite.  The choice is made by defining/undefining the 
   associated "-D" option in the LCALS_rules.mk file.  See that file for 
   more information.


--------------------------------------------------------------------------------
Figures of Merit:

 o The program output includes a Figure of Merit (FOM) value for each loop 
   variant and loop length that is executed.  The intent of the FOM is to 
   complement execution timing data with another measure of performance and 
   compiler optimization.  Using the FOM values and total loop suite execution 
   time information in the Figure of Merit report, one can compare different 
   compilers' abilities to optimize on a given platform, performance of 
   different optimization levels for a given compiler, or potential performance 
   of different architectures, etc. 

 o In the FOM calculation, execution time for each loop is weighted by a 
   factor defined in the loop setup routines.  The loops are partitioned into 
   six classes depending on their structure; e.g., data-parallel, order-
   dependent, etc.  The weight for each loop class indicates its relative 
   importance based on code constructs we want the suite to emphasize 
   and how easy we think it should be for a compiler to optimize.  Each loop 
   in the suite is given a weight, w_i (i is the loop id), based on which 
   class it exists in.  Loop classes and weights are defined in the file 
   LCALSSuite.cxx.

 o The FOM is calculated as follows.

   - Relative FOM (FOM_rel).  The aim of the FOM_rel value is to measure 
     a compiler's ability to optimize different loop constructs.

     -- When the code is executed, a reference loop execution time, t_ref, is
        computed using a loop that any compiler should be able to optimize 
        well and which should run faster than any loop in the suite.  
        To help insure this, two simple loops are run, an element-wise vector 
        product and a vector dot product. Then, t_ref is the minimum execution 
        time between the two.

     -- After the suite is run, FOM_rel is calulated as:

        FOM_rel = W * t_ref / Sum_i [ w_i * t_i ]

        The denominator is a weighted sum of execution times for the loops
        that were run; t_i is the run time for loop i.  W = Sum_i ( w_i ) is
        the sum of loop weights.

     -- Note that FOM_rel is a dimensionless quantity that satisfies 
        0 <= FOM_rel <= 1, and FOM_rel increases as loop execution times 
        decrease.  In the ideal case, where each loop executes as fast as the 
        reference loop (which should be impossible), t_i = t_ref for each i.
        So FOM_rel = 1.
