//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Header file with enums, macros, routines and structures used to
// compile and run loops in LCALS suite and to generate execution
// statistics.
//

#ifndef LCALSSuite_HXX
#define LCALSSuite_HXX

#include "LCALSParams.hxx" 
#include "LCALSStats.hxx"

#include <vector>
#include <string>


//
// Enumeration defining unique id for each loop KERNEL in suite.
//
// IMPORTANT: Generally, this should not need modification unless
//            new loops (i.e., kernels) are added to the suite.
//
// Note: To keep output understandable, keep this consistent with
//       routine defineLoopSuiteRunInfo().
//
enum LoopKernelID {

   // Keep this one first and don't comment out (!!)
   // This insures loop ids start at zero so all array indexing
   // or data structures is correct.  Also, this loop is not
   // executed the same way the others are. 
   REF_LOOP = 0,

   //
   // Loop Subset A: Loops extracted from LLNL app codes.
   // They are implemented in runA<variant>Loops.cxx files.
   //
   PRESSURE_CALC,
   PRESSURE_CALC_ALT,
   ENERGY_CALC,
   ENERGY_CALC_ALT,
   VOL3D_CALC,
   DEL_DOT_VEC_2D,
   COUPLE,
   FIR,

   //
   // Loop Subset B: "Basic" Loops.
   // They are implemented in runB<variant>Loops.cxx files.
   //
   INIT3,
   MULADDSUB,
   IF_QUAD,
   TRAP_INT,

   //
   // Loop Subset C: Loops from older Livermore Loops in "C" suite.
   // They are implemented in runC<variant>Loops.cxx files.
   //
   HYDRO_1D,
   ICCG,
   INNER_PROD,
   BAND_LIN_EQ,
   TRIDIAG_ELIM,
   EOS,
   ADI,
   INT_PREDICT,
   DIFF_PREDICT,
   FIRST_SUM,
   FIRST_DIFF,
   PIC_2D,
   PIC_1D,
   HYDRO_2D,
   GEN_LIN_RECUR,
   DISC_ORD,
   MAT_X_MAT,
   PLANCKIAN,
   IMP_HYDRO_2D,
   FIND_FIRST_MIN,

   NUM_LOOP_KERNELS // Keep this one last and NEVER comment out (!!)

};


//
// Enumeration defining unique id for each loop VARIANT in suite.
//
// IMPORTANT: Generally, this should not need modification unless
//            new loop variants are added to the suite.
//
enum LoopVariantID {
   //
   // These variants define LCALS benchmark
   //
   RAW,
   RAW_OMP,
   FORALL_LAMBDA,
   FORALL_LAMBDA_OMP,

#if defined(LCALS_DO_MISC)

   //
   // These variants are used in miscellaneous LCALS studies
   //
   FORALL_HYBRID_LAMBDA,
#if 0  // THESE ARE NOT AVAILABLE YET!!!
   FORALL_HYBRID_LAMBDA_OMP,
#endif
   FORALL_FUNCTOR,
   FORALL_FUNCTOR_OMP,
#if 0  // THESE ARE NOT AVAILABLE YET!!!
   FORALL_HYBRID_FUNCTOR,
   FORALL_HYBRID_FUNCTOR_OMP,
#endif
   RAW_FUNC,
   FORALL_LAMBDA_TYPEFIX,
   FORALL_LAMBDA_OMP_TYPEFIX,
   FORALL_HYBRID_LAMBDA_TYPEFIX,

#endif // if LCALS_DO_MISC 

};


//
// Enumeration defining possible loop lengths to run.
//
enum LoopLength {

   LONG = 0,
   MEDIUM,
   SHORT,

   NUM_LENGTHS // Keep this one last (!!)

};


////////////////////////////////////////////////////////////////////////////////
//
// The following macro constants define which loop VARIANTS can be compiled 
// (and potentially) run for a given compiler.
//
// NOTE: The Makefile sets the LCALS_COMPILER_* macro constant.
//
//  --> IMPORTANT: Actual selection of which loop variants are run is done
//                 in main.cxx via the vector 'run_variants'.
//
////////////////////////////////////////////////////////////////////////////////

#if defined(LCALS_COMPILER_ICC)
//
// Configuration options for Intel compilers
//

#define COMPILE_RAW_VARIANTS
#define COMPILE_LAMBDA_VARIANTS
#define COMPILE_FUNCTOR_VARIANTS
#define COMPILE_OMP_VARIANTS


#elif defined(LCALS_COMPILER_GNU)
//
// Configuration options for GNU compilers
//

#define COMPILE_RAW_VARIANTS
#define COMPILE_LAMBDA_VARIANTS
#define COMPILE_FUNCTOR_VARIANTS
#define COMPILE_OMP_VARIANTS


#elif defined(LCALS_COMPILER_XLC12)
//
// Configuration options for IBM xlC compilers
//

//
// xlC compilers DO NOT support lambda functions currently!!
//
#define COMPILE_RAW_VARIANTS
#undef COMPILE_LAMBDA_VARIANTS
#define COMPILE_FUNCTOR_VARIANTS
#define COMPILE_OMP_VARIANTS


#elif defined(LCALS_COMPILER_CLANG)
//
// Configuration options for clang compilers
//

//
// Clang compilers DO NOT support OpenMP currently!!
//
#define COMPILE_RAW_VARIANTS
#define COMPILE_LAMBDA_VARIANTS
#define COMPILE_FUNCTOR_VARIANTS
#undef COMPILE_OMP_VARIANTS


#else
#error LCALS compiler is undefined!

#endif


//
// The following macro constants are used to turn on/off compilation of
// individual loop KERNELS in suite.  Names are consistent with LoopID 
// enum above.
//

#if defined (LCALS_DO_OMP_ONLY)
//
// Only these loops have OpenMP implementations.  The imlementations are
// found in runOMP<variant>Loops.cxx files.
//

// Loop Subset A: Loops extracted from LLNL app codes.
#define COMPILE_PRESSURE_CALC
#define COMPILE_PRESSURE_CALC_ALT
#define COMPILE_ENERGY_CALC
#define COMPILE_ENERGY_CALC_ALT
#define COMPILE_VOL3D_CALC
#define COMPILE_DEL_DOT_VEC_2D
#define COMPILE_COUPLE
#define COMPILE_FIR

// Loop Subset B: "Basic" Loops.
#define COMPILE_INIT3
#define COMPILE_MULADDSUB
#define COMPILE_IF_QUAD
#define COMPILE_TRAP_INT

// Loop Subset C: Loops from older Livermore Loops in "C" suite.
#define COMPILE_PIC_2D

#else // compile all loop kernels
//
// Loop Subset A: Loops extracted from LLNL app codes.
// They are implemented in runA<variant>Loops.cxx files.
//
#define COMPILE_PRESSURE_CALC
#define COMPILE_PRESSURE_CALC_ALT
#define COMPILE_ENERGY_CALC
#define COMPILE_ENERGY_CALC_ALT
#define COMPILE_VOL3D_CALC
#define COMPILE_DEL_DOT_VEC_2D
#define COMPILE_COUPLE
#define COMPILE_FIR

//
// Loop Subset B: "Basic" Loops.
// They are implemented in runB<variant>Loops.cxx files.
//
#define COMPILE_INIT3
#define COMPILE_MULADDSUB
#define COMPILE_IF_QUAD
#define COMPILE_TRAP_INT

//
// Loop Subset C: Loops from older Livermore Loops in "C" suite.
// They are implemented in runLCK<variant>Loops.cxx files.
//
#define COMPILE_HYDRO_1D
#define COMPILE_ICCG
#define COMPILE_INNER_PROD
#define COMPILE_BAND_LIN_EQ
#define COMPILE_TRIDIAG_ELIM
#define COMPILE_EOS
#define COMPILE_ADI
#define COMPILE_INT_PREDICT
#define COMPILE_DIFF_PREDICT
#define COMPILE_FIRST_SUM
#define COMPILE_FIRST_DIFF
#define COMPILE_PIC_2D
#define COMPILE_PIC_1D
#define COMPILE_HYDRO_2D
#define COMPILE_GEN_LIN_RECUR
#define COMPILE_DISC_ORD
#define COMPILE_MAT_X_MAT
#define COMPILE_PLANCKIAN
#define COMPILE_IMP_HYDRO_2D
#define COMPILE_FIND_FIRST_MIN

#endif



//////////////////////////////////////////////////////////////////
//
//  Structure holding double arrays and scalars used in loops.
//
//  Note: These are initialized in allocateLoopData().
//
///////////////////////////////////////////////////////////////////

struct LoopData
{

   //
   // Structures to hold data for easy reinitialization
   // (useful for verifying result checksums, etc.)
   //  
   struct RealArray 
   {
      int id;
      Real_ptr data; 
      Index_type len;
   };

   struct IndxArray
   {
      int id;
      Index_type* data;
      Index_type  len;
   };

   struct ComplexArray
   {
      int id;
      Complex_ptr data;
      Index_type  len;
   };


   Index_type max_loop_length;

   //
   // Static values indicating number of data arrays 
   // of various forms used in loop suite.
   //
   // NOTE: These number may need to change to accomodate new loops. 
   //       Also, other arrays may need to be added. 
   //
   static const unsigned s_num_1D_Real_arrays = 16;
   static const unsigned s_num_1D_Nx4_Real_arrays = 2;
   static const unsigned s_num_1D_Indx_arrays = 5;
   static const unsigned s_num_1D_Complex_arrays = 5;

   static const unsigned s_num_2D_Nx25_Real_arrays = 4;
   static const unsigned s_num_2D_7xN_Real_arrays = 11;
   static const unsigned s_num_2D_64x64_Real_arrays = 1;

   static const unsigned s_num_3D_2xNx4_Real_arrays = 3;

   static const unsigned s_num_Real_scalars   = 10;

   //
   // NOTE: To see how the following data structures are related,
   //       please see the routine allocateLoopData() in the 
   //       file LCALSSuite.cxx.
   //
   //       The reason that we hold on to the same data in two 
   //       different ways is two-fold:
   //          1) The first set of arrays below makes it easy to 
   //             access pointers to data based on what is used in 
   //             each loop kernel; e.g., arrays of variaous dimensions.
   //          2) The second set of arrays makes it easy to process
   //             arrays for (re)initialization and checksum 
   //             computation to verify results; e.g., we simply
   //             iterate through 1-dim arrays without having to
   //             know their lengths, if they are really being used 
   //             as 2- or 3-dimensional arrays, for example. 
   //

   //
   // Data arrays and scalars used in loop execution.
   //
   Real_ptr  array_1D_Real[s_num_1D_Real_arrays];
   Real_ptr  array_1D_Nx4_Real[s_num_1D_Nx4_Real_arrays];
   Index_type* array_1D_Indx[s_num_1D_Indx_arrays]; 
   Complex_ptr array_1D_Complex[s_num_1D_Complex_arrays]; 

   Real_ptr* array_2D_Nx25_Real[s_num_2D_Nx25_Real_arrays];
   Real_ptr* array_2D_7xN_Real[s_num_2D_7xN_Real_arrays];
   Real_ptr* array_2D_64x64_Real[s_num_2D_64x64_Real_arrays];

   Real_ptr** array_3D_2xNx4_Real[s_num_3D_2xNx4_Real_arrays];

   Real_type scalar_Real[s_num_Real_scalars];

   //
   // Arrays of structs holding data arrays used for data initialization
   // and checksum verification.
   //
   RealArray RealArray_1D[s_num_1D_Real_arrays];
   RealArray RealArray_1D_Nx4[s_num_1D_Nx4_Real_arrays];
   IndxArray IndxArray_1D[s_num_1D_Indx_arrays];
   ComplexArray ComplexArray_1D[s_num_1D_Complex_arrays];

   RealArray RealArray_2D_Nx25[s_num_2D_Nx25_Real_arrays];
   RealArray RealArray_2D_7xN[s_num_2D_7xN_Real_arrays];
   RealArray RealArray_2D_64x64[s_num_2D_64x64_Real_arrays];

   RealArray RealArray_3D_2xNx4[s_num_3D_2xNx4_Real_arrays];

   RealArray RealArray_scalars;

};

//
// Routine to access data structure that holds data needed to execute loops.
// 
LoopData& getLoopData();


//
//  Routine that generates vector of loop variant names string 
//  from vector of LoopVariantID enum values.
//
std::vector<std::string> getVariantNames(
   const std::vector<LoopVariantID>& lvids);

//
//  Routine that maps LoopVariantID enum value (used in main to help
//  insure correctness) to string (used in loop framework for flexibility).
//
std::string getVariantName(LoopVariantID lvid);


//////////////////////////////////////////////////////////////////
//
//  Routines to define how loop suite will be run and
//  to set up data for loop suite.
//
//////////////////////////////////////////////////////////////////

//
// Routines to define specific details about how to run loop suite.
//
// Note:  Individual loop lengths and sampling parameters 
//        are defined in this routine.
//
void defineLoopSuiteRunInfo(const std::vector<LoopVariantID>& run_variants,
                            bool run_loop[], 
                            double sample_frac,
                            double loop_length_factor );


//
// Routines to allocate and initialize arrays (and scalars) for 
// loops in suite and to free those arrays when done.
//
void allocateLoopData();
void freeLoopData();


//
// Routines to initialize and finalize loop data, statistics, timers, etc.  
//
// Each of these routines must be called before and after the execution
// of each loop.
//
void loopInit(unsigned iloop, LoopStat& stat);
void loopInit(unsigned iloop); //, LoopStat& stat);
//
void loopFinalize(unsigned iloop, LoopStat& stat, LoopLength ilength);


//
// Routines to run reference loops for figure of merit (FOM) calculations.
//
void defineReferenceLoopRunInfo();
void computeReferenceLoopTimes();

//
// Routine called in main to execute loops corresponding to given 
// variant ID and length.  The run_loop boolean array indicates which 
// loop kernels in suite to execute
//
void runLoopVariant( LoopVariantID lvid,
                     bool run_loop[],
                     LoopLength ilength );
                 

//
// Routines to run specific loop variants for suite.
//
// THESE SHOULD NOT BE CALLED BY ROUTINE ABOVE, NOT DIRECTLY!!! 
//
// loop_stats is vector of LoopStat objects corresponding to loop variant.
// run_loop boolean array indicates which loop kernels in suite to execute.
// ilength indicates which loop length to run (see LoopLength enum).
//
void runARawLoops( std::vector<LoopStat>& loop_stats,
                   bool run_loop[],
                   LoopLength ilength );
void runBRawLoops( std::vector<LoopStat>& loop_stats,
                   bool run_loop[],
                   LoopLength ilength );
void runCRawLoops( std::vector<LoopStat>& loop_stats,
                   bool run_loop[],
                   LoopLength ilength );

void runARawFuncLoops( std::vector<LoopStat>& loop_stats,
                       bool run_loop[],
                       LoopLength ilength );
void runBRawFuncLoops( std::vector<LoopStat>& loop_stats,
                       bool run_loop[],
                       LoopLength ilength );
void runCRawFuncLoops( std::vector<LoopStat>& loop_stats,
                       bool run_loop[],
                       LoopLength ilength );

void runOMPRawLoops( std::vector<LoopStat>& loop_stats,
                     bool run_loop[],
                     LoopLength ilength );


void runAForallLambdaLoops( std::vector<LoopStat>& loop_stats,
                            bool run_loop[],
                            LoopLength ilength );
void runBForallLambdaLoops( std::vector<LoopStat>& loop_stats,
                            bool run_loop[],
                            LoopLength ilength );
void runCForallLambdaLoops( std::vector<LoopStat>& loop_stats,
                            bool run_loop[],
                            LoopLength ilength );
void runOMPForallLambdaLoops( std::vector<LoopStat>& loop_stats,
                              bool run_loop[],
                              LoopLength ilength );

void runAForallLambdaLoops_TYPEFIX( std::vector<LoopStat>& loop_stats,
                                    bool run_loop[],
                                    LoopLength ilength );
void runBForallLambdaLoops_TYPEFIX( std::vector<LoopStat>& loop_stats,
                                    bool run_loop[],
                                    LoopLength ilength );
void runCForallLambdaLoops_TYPEFIX( std::vector<LoopStat>& loop_stats,
                                    bool run_loop[],
                                    LoopLength ilength );
void runOMPForallLambdaLoops_TYPEFIX( std::vector<LoopStat>& loop_stats,
                                      bool run_loop[],
                                      LoopLength ilength );


void runAForallFunctorLoops( std::vector<LoopStat>& loop_stats,
                             bool run_loop[],
                             LoopLength ilength );
void runBForallFunctorLoops( std::vector<LoopStat>& loop_stats,
                             bool run_loop[],
                             LoopLength ilength );
void runCForallFunctorLoops( std::vector<LoopStat>& loop_stats,
                             bool run_loop[],
                             LoopLength ilength );
void runOMPForallFunctorLoops( std::vector<LoopStat>& loop_stats,
                               bool run_loop[],
                               LoopLength ilength );

void runAForallHybridLambdaLoops( std::vector<LoopStat>& loop_stats,
                                  bool run_loop[],
                                  LoopLength ilength );
void runBForallHybridLambdaLoops( std::vector<LoopStat>& loop_stats,
                                  bool run_loop[],
                                  LoopLength ilength );
void runCForallHybridLambdaLoops( std::vector<LoopStat>& loop_stats,
                                  bool run_loop[],
                                  LoopLength ilength );

void runAForallHybridLambdaLoops_TYPEFIX( std::vector<LoopStat>& loop_stats,
                                          bool run_loop[],
                                          LoopLength ilength );
void runBForallHybridLambdaLoops_TYPEFIX( std::vector<LoopStat>& loop_stats,
                                          bool run_loop[],
                                          LoopLength ilength );
void runCForallHybridLambdaLoops_TYPEFIX( std::vector<LoopStat>& loop_stats,
                                          bool run_loop[],
                                          LoopLength ilength );

//
// Recursively construct directories based on a relative or
// absolute path name.  Return true if directory created
// successfully, else false.
// 
bool recursiveMkdir(const std::string& path);




#endif  // closing endif for header file include guard
