//
// See README-LCALS_license.txt for access and distribution restrictions
//

//
// Header file with macros and constants for data types, execution,
// timing options, etc. used in LCALS
//

#ifndef LCALSParams_HXX
#define LCALSParams_HXX


////////////////////////////////////////////////////////////////////////////////
//
// This file contains various parameters that control compilation and some
// aspects of execution of the loop suite.  The macro constants and typedefs in
// this file provide the ability to make changes that will propagate 
// throughout the LCALS code when compiled.  Parameters in this file specify:
//
// o Timing and checksum output options
// o Scalar data types and pointer types (e.g., restrict & alignment properties)
// o Loop variants that can be built by each compiler 
// o Loop execution policies for traversal templates (used with loop bodies
//   represented as lambda expressions or functors)
//
//
// IMPORTANT: MANY OF THE MACROS CONTROLLING THESE OPTIONS
//            ARE SET IN THE LCALS_rules.mk FILE.
//
////////////////////////////////////////////////////////////////////////////////

#if defined(LCALS_VERIFY_CHECKSUM_ABBREVIATED)
static const int num_checksum_suite_passes = 1;
static const int num_checksum_samples = 3;
#endif



////////////////////////////////////////////////////////////////////////////////
//
// Define/undefine macro constants and other paramters used to control data
// type definitions.
// 
////////////////////////////////////////////////////////////////////////////////

//
//  Parameterized scalar data types.
//

typedef int     Index_type;

#if defined(LCALS_USE_DOUBLE)
///
typedef double  Real_type;

#elif defined(LCALS_USE_FLOAT)
///
typedef float  Real_type;


#else
#error LCALS Real_type is undefined!

#endif

#include<complex>
typedef std::complex<Real_type> Complex_type;

//
// Use volatile keyword on loop variable for sampling loops to prevent 
// compilers from potentially optimizing out loops where result is
// identical for each sample iteration.
// 
typedef volatile int SampIndex_type;
//
// Use unsigned long for loop variable used in loops to flush cache to
// allow for large caches with size possibly bigger than what int can adderss.
// 
typedef unsigned long CacheIndex_type;

//
//  Floating point array data alignmnent value.  Typically, same as
//  SIMD vector width.
//
const int LCALS_DATA_ALIGN = 32;


//
//  Compiler-specific definitions for inline directives, data alignment
//  intrinsics, and SIMD vector pragmas
//
//  Variables for compiler instrinsics, directives, typedefs
//
//     LCALS_INLINE - macro to enforce method inlining
//
//     LCALS_ALIGN_DATA(<variable>) - macro to express alignment of data,
//                              loop bounds, etc.
//
//     LCALS_SIMD - macro to express SIMD vectorization pragma to force
//                 loop vectorization
//

#if defined(LCALS_COMPILER_ICC)
//
// Configuration options for Intel compilers
//

#define LCALS_INLINE inline  __attribute__((always_inline))

#if __ICC < 1300  // use alignment intrinsic
#define LCALS_ALIGN_DATA(d) __assume_aligned(d, LCALS_DATA_ALIGN)
#else
#define LCALS_ALIGN_DATA(d)  // TODO: Define this...
#endif

#define LCALS_SIMD  // TODO: Define this...


#elif defined(LCALS_COMPILER_GNU)
//
// Configuration options for GNU compilers
//

#define LCALS_INLINE inline  __attribute__((always_inline))

#define LCALS_ALIGN_DATA(d) __builtin_assume_aligned(d, LCALS_DATA_ALIGN)

#define LCALS_SIMD  // TODO: Define this...


#elif defined(LCALS_COMPILER_XLC12)
//
// Configuration options for xlc v12 compiler (i.e., bgq/sequoia).
//

#define LCALS_INLINE inline  __attribute__((always_inline))

#define LCALS_ALIGN_DATA(d) __alignx(LCALS_DATA_ALIGN, d)

//#define LCALS_SIMD  _Pragma("simd_level(10)")
#define LCALS_SIMD   // TODO: Define this...


#elif defined(LCALS_COMPILER_CLANG)
//
// Configuration options for clang compilers
//

#define LCALS_INLINE inline  __attribute__((always_inline))

#define LCALS_ALIGN_DATA(d) // TODO: Define this...

#define LCALS_SIMD  // TODO: Define this...


#else
#error LCALS compiler is undefined!

#endif


////////////////////////////////////////////////////////////////////////////////
//
// The following items include some setup items for pointer type definitions 
// that follow.
// 
////////////////////////////////////////////////////////////////////////////////

#if defined(LCALS_COMPILER_ICC)
//
// alignment attribute supported for versions > 12
//
#if __ICC >= 1300
typedef Real_type* __restrict__ __attribute__((align_value(LCALS_DATA_ALIGN))) TDRAReal_ptr;

typedef const Real_type* __restrict__ __attribute__((align_value(LCALS_DATA_ALIGN))) const_TDRAReal_ptr;
#endif


#elif defined(LCALS_COMPILER_GNU)
//
// Nothing here for now because alignment attribute is not working...
//


#elif defined(LCALS_COMPILER_XLC12)
extern
#ifdef __cplusplus
"builtin"
#endif
void __alignx(int n, const void* addr);


#elif defined(LCALS_COMPILER_CLANG)
typedef Real_type aligned_real_type __attribute__((aligned (LCALS_DATA_ALIGN)));
typedef aligned_real_type* __restrict__ TDRAReal_ptr;

typedef const aligned_real_type* __restrict__ const_TDRAReal_ptr;

#else
#error LCALS compiler is undefined!

#endif


#if defined(LCALS_USE_PTR_CLASS)
/*!
 ******************************************************************************
 *
 * \brief Class representing a restricted Real_type const pointer.
 *
 ******************************************************************************
 */
class ConstRestrictRealPtr
{
public:

   ///
   /// Ctors and assignment op.
   ///

   ConstRestrictRealPtr() : dptr(0) { ; }

   ConstRestrictRealPtr(const Real_type* d) : dptr(d) { ; }

   ConstRestrictRealPtr& operator=(const Real_type* d) {
      ConstRestrictRealPtr copy(d);
      std::swap(dptr, copy.dptr);
      return *this;
   }

   ///
   /// NOTE: Using compiler-generated copy ctor, dtor, and copy assignment op.
   ///

   ///
   ///  Implicit conversion operator to bare const pointer.
   ///
   operator const Real_type*() { return dptr; }

   ///
   ///  "Explicit conversion operator" to bare const pointer,
   ///  consistent with boost shared ptr.
   ///
   const Real_type* get() const { return dptr; }

   ///
   /// Bracket operator.
   ///
   const Real_type& operator [] (Index_type i) const
   {
      return( (const Real_type* __restrict__) dptr)[i];
   }

   ///
   /// + operator for pointer arithmetic.
   ///
   const Real_type* operator+ (Index_type i) const { return dptr+i; }

private:
   const Real_type* dptr;
};


/*!
 ******************************************************************************
 *
 * \brief Class representing a restricted Real_type (non-const) pointer.
 *
 ******************************************************************************
 */
class RestrictRealPtr
{
public:

   ///
   /// Ctors and assignment op.
   ///

   RestrictRealPtr() : dptr(0) { ; }

   RestrictRealPtr(Real_type* d) : dptr(d) { ; }

   RestrictRealPtr& operator=(Real_type* d) { 
      RestrictRealPtr copy(d);
      std::swap(dptr, copy.dptr);
      return *this; 
   }

   ///
   /// NOTE: Using compiler-generated copy ctor, dtor, and copy assignment op.
   ///

   ///
   ///  Implicit conversion operator to (non-const) bare pointer.
   ///
   operator Real_type*() { return dptr; }

   ///
   ///  Implicit conversion operator to const bare pointer.
   ///
   operator const Real_type*() const { return dptr; }

   ///
   ///  "Explicit conversion operator" to (non-const) bare pointer,
   ///  consistent with boost shared ptr.
   ///
   Real_type* get() { return dptr; }

   ///
   ///  "Explicit conversion operator" to const bare pointer,
   ///  consistent with boost shared ptr.
   ///
   const Real_type* get() const { return dptr; }

   ///
   ///  Operator that enables implicit conversion from RestrictRealPtr to
   ///  RestrictRealConstPtr.
   ///
   operator ConstRestrictRealPtr ()
      { return ConstRestrictRealPtr(dptr); }


   ///
   /// Bracket operator.
   ///
   Real_type& operator [] (Index_type i)
   {
      return( (Real_type* __restrict__) dptr)[i];
   }

   ///
   /// + operator for (non-const) pointer arithmetic.
   ///
   Real_type* operator+ (Index_type i) { return dptr+i; }

   ///
   /// + operator for const pointer arithmetic.
   ///
   const Real_type* operator+ (Index_type i) const { return dptr+i; }

private:
   Real_type* dptr;
};


/*!
 ******************************************************************************
 *
 * \brief Class representing a restricted aligned Real_type const pointer.
 *
 ******************************************************************************
 */
class ConstRestrictAlignedRealPtr
{
public:

   ///
   /// Ctors and assignment op.
   ///

   ConstRestrictAlignedRealPtr() : dptr(0) { ; }

   ConstRestrictAlignedRealPtr(const Real_type* d) : dptr(d) { ; }

   ConstRestrictAlignedRealPtr& operator=(const Real_type* d) {
      ConstRestrictAlignedRealPtr copy(d);
      std::swap(dptr, copy.dptr);
      return *this;
   }

   ///
   /// NOTE: Using compiler-generated copy ctor, dtor, and copy assignment op.
   ///

   ///
   ///  Implicit conversion operator to bare const pointer.
   ///
   operator const Real_type*() { return dptr; }

   ///
   ///  "Explicit conversion operator" to bare const pointer,
   ///  consistent with boost shared ptr.
   ///
   const Real_type* get() const { return dptr; }

   ///
   /// Compiler-specific bracket operators.
   ///
#if defined(LCALS_COMPILER_ICC)
   ///
   const Real_type& operator [] (Index_type i) const
   {
#if __ICC < 1300 // use alignment intrinsic
      LCALS_ALIGN_DATA(dptr);
      return( (const Real_type* __restrict__) dptr)[i];
#else // use alignment attribute
      return( (const_TDRAReal_ptr) dptr)[i];
#endif
   }


#elif defined(LCALS_COMPILER_GNU)
   ///
   const Real_type& operator [] (Index_type i) const
   {
#if 1 // NOTE: alignment instrinsic not available for older GNU compilers
      return( (const Real_type* __restrict__) LCALS_ALIGN_DATA(dptr) )[i];
#else
      return( (const Real_type* __restrict__) dptr)[i];
#endif
   }


#elif defined(LCALS_COMPILER_XLC12)
   const Real_type& operator [] (Index_type i) const
   {
      LCALS_ALIGN_DATA(dptr);
      return( (const Real_type* __restrict__) dptr)[i];
   }


#elif defined(LCALS_COMPILER_CLANG)
   const Real_type& operator [] (Index_type i) const
   {
      return( (const_TDRAReal_ptr) dptr)[i];
   }


#else
#error LCALS compiler macro is undefined!

#endif

   ///
   /// + operator for pointer arithmetic.
   ///
   const Real_type* operator+ (Index_type i) const { return dptr+i; }

private:
   const Real_type* dptr;
};


/*!
 ******************************************************************************
 *
 * \brief Class representing a restricted aligned Real_type (non-const) pointer.
 *
 ******************************************************************************
 */
class RestrictAlignedRealPtr
{
public:

   ///
   /// Ctors and assignment op.
   ///

   RestrictAlignedRealPtr() : dptr(0) { ; }

   RestrictAlignedRealPtr(Real_type* d) : dptr(d) { ; }

   RestrictAlignedRealPtr& operator=(Real_type* d) { RestrictAlignedRealPtr copy(d);
                                                   std::swap(dptr, copy.dptr);
                                                   return *this; }

   ///
   /// NOTE: Using compiler-generated copy ctor, dtor, and copy assignment op.
   ///

   ///
   ///  Implicit conversion operator to (non-const) bare pointer.
   ///
   operator Real_type*() { return dptr; }

   ///
   ///  Implicit conversion operator to const bare pointer.
   ///
   operator const Real_type*() const { return dptr; }

   ///
   ///  "Explicit conversion operator" to (non-const) bare pointer,
   ///  consistent with boost shared ptr.
   ///
   Real_type* get() { return dptr; }

   ///
   ///  "Explicit conversion operator" to const bare pointer,
   ///  consistent with boost shared ptr.
   ///
   const Real_type* get() const { return dptr; }

   ///
   ///  Operator that enables implicit conversion from RestrictAlignedRealPtr to
   ///  RestrictAlignedRealConstPtr.
   ///
   operator ConstRestrictAlignedRealPtr ()
      { return ConstRestrictAlignedRealPtr(dptr); }


   ///
   /// Compiler-specific bracket operators.
   ///

#if defined(LCALS_COMPILER_ICC)
   ///
   Real_type& operator [] (Index_type i)
   {
#if __ICC < 1300 // use alignment intrinsic
      LCALS_ALIGN_DATA(dptr);
      return( (Real_type* __restrict__) dptr)[i];
#else // use alignment attribute
      return( (TDRAReal_ptr) dptr)[i];
#endif
   }

   ///
   const Real_type& operator [] (Index_type i) const
   {
#if __ICC < 1300 // use alignment intrinsic
      LCALS_ALIGN_DATA(dptr);
      return( (Real_type* __restrict__) dptr)[i];
#else // use alignment attribute
      return( (TDRAReal_ptr) dptr)[i];
#endif
   }

#elif defined(LCALS_COMPILER_GNU)
   ///
   Real_type& operator [] (Index_type i)
   {
#if 1 // NOTE: alignment instrinsic not available for older GNU compilers
      return( (Real_type* __restrict__) LCALS_ALIGN_DATA(dptr) )[i];
#else
      return( (Real_type* __restrict__) dptr)[i];
#endif
   }

   ///
   const Real_type& operator [] (Index_type i) const
   {
#if 1 // NOTE: alignment instrinsic not available for older GNU compilers
      return( (Real_type* __restrict__) LCALS_ALIGN_DATA(dptr) )[i];
#else
      return( (Real_type* __restrict__) dptr)[i];
#endif
   }


#elif defined(LCALS_COMPILER_XLC12)
   ///
   Real_type& operator [] (Index_type i)
   {
      LCALS_ALIGN_DATA(dptr);
      return( (Real_type* __restrict__) dptr)[i];
   }

   ///
   const Real_type& operator [] (Index_type i) const
   {
      LCALS_ALIGN_DATA(dptr);
      return( (Real_type* __restrict__) dptr)[i];
   }


#elif defined(LCALS_COMPILER_CLANG)
   ///
   Real_type& operator [] (Index_type i)
   {
      return( (TDRAReal_ptr) dptr)[i];
   }

   ///
   const Real_type& operator [] (Index_type i) const
   {
      return( (TDRAReal_ptr) dptr)[i];
   }


#else
#error LCALS compiler macro is undefined!

#endif

   ///
   /// + operator for (non-const) pointer arithmetic.
   ///
   Real_type* operator+ (Index_type i) { return dptr+i; }

   ///
   /// + operator for const pointer arithmetic.
   ///
   const Real_type* operator+ (Index_type i) const { return dptr+i; }

private:
   Real_type* dptr;
};


/*!
 ******************************************************************************
 *
 * \brief Class representing a restricted Complex_type const pointer.
 *
 ******************************************************************************
 */
class ConstRestrictComplexPtr
{
public:

   ///
   /// Ctors and assignment op.
   ///

   ConstRestrictComplexPtr() : dptr(0) { ; }

   ConstRestrictComplexPtr(const Complex_type* d) : dptr(d) { ; }

   ConstRestrictComplexPtr& operator=(const Complex_type* d) {
      ConstRestrictComplexPtr copy(d);
      std::swap(dptr, copy.dptr);
      return *this;
   }

   ///
   /// NOTE: Using compiler-generated copy ctor, dtor, and copy assignment op.
   ///

   ///
   ///  Implicit conversion operator to bare const pointer.
   ///
   operator const Complex_type*() const { return dptr; }

   ///
   ///  "Explicit conversion operator" to bare const pointer,
   ///  consistent with boost shared ptr.
   ///
   const Complex_type* get() const { return dptr; }

   ///
   ///  Bracket operator.
   ///
   const Complex_type& operator [] (Index_type i) const
   {
      return( (const Complex_type* __restrict__) dptr)[i];
   }

   ///
   /// + operator for pointer arithmetic.
   ///
   const Complex_type* operator+ (Index_type i) const { return dptr+i; }

private:
   const Complex_type* dptr;
};


/*!
 ******************************************************************************
 *
 * \brief Class representing a restricted Complex_type (non-const) pointer.
 *
 ******************************************************************************
 */
class RestrictComplexPtr
{
public:

   ///
   /// Ctors and assignment op.
   ///

   RestrictComplexPtr() : dptr(0) { ; }

   RestrictComplexPtr(Complex_type* d) : dptr(d) { ; }

   RestrictComplexPtr& operator=(Complex_type* d) { RestrictComplexPtr copy(d);
                                                    std::swap(dptr, copy.dptr);
                                                    return *this; }

   ///
   /// NOTE: Using compiler-generated copy ctor, dtor, and copy assignment op.
   ///

   ///
   ///  Implicit conversion operator to (non-const) bare pointer.
   ///
   operator Complex_type*() { return dptr; }

   ///
   ///  Implicit conversion operator to const bare pointer.
   ///
   operator const Complex_type*() const { return dptr; }

   ///
   ///  "Explicit conversion operator" to (non-const) bare pointer,
   ///  consistent with boost shared ptr.
   ///
   Complex_type* get() { return dptr; }

   ///
   ///  "Explicit conversion operator" to const bare pointer,
   ///  consistent with boost shared ptr.
   ///
   const Complex_type* get() const { return dptr; }

   ///
   ///  Operator that enables implicit conversion from RestrictComplexPtr to
   ///  RestrictComplexConstPtr.
   ///
   operator ConstRestrictComplexPtr ()
      { return ConstRestrictComplexPtr(dptr); }

   ///
   ///  (Non-const) bracket operator.
   ///
   Complex_type& operator [] (Index_type i)
   {
      return( (Complex_type* __restrict__) dptr)[i];
   }

   ///
   ///  Const bracket operator.
   ///
   const Complex_type& operator [] (Index_type i) const
   {
      return( (Complex_type* __restrict__) dptr)[i];
   }

   ///
   /// + operator for (non-const) pointer arithmetic.
   ///
   Complex_type* operator+ (Index_type i) { return dptr+i; }

   ///
   /// + operator for const pointer arithmetic.
   ///
   const Complex_type* operator+ (Index_type i) const { return dptr+i; }

private:
   Complex_type* dptr;
};
#endif  // defined(LCALS_USE_PTR_CLASS)


/*
 ******************************************************************************
 *
 * Finally, we define data pointer types based on definitions above and
 * -D value given at compile time.
 *
 ******************************************************************************
 */
#if defined(LCALS_USE_BARE_PTR)
typedef Real_type* Real_ptr;
typedef const Real_type* const_Real_ptr;
typedef Complex_type* Complex_ptr;
typedef const Complex_type* const_Complex_ptr;

typedef Real_type* UnalignedReal_ptr;
typedef const Real_type* const_UnalignedReal_ptr;


#elif defined(LCALS_USE_RESTRICT_PTR)
typedef Real_type* __restrict__ Real_ptr;
typedef const Real_type* __restrict__ const_Real_ptr;
typedef Complex_type* __restrict__ Complex_ptr;
typedef const Complex_type* __restrict__ const_Complex_ptr;

typedef Real_type* __restrict__ UnalignedReal_ptr;
typedef const Real_type* __restrict__ const_UnalignedReal_ptr;


#elif defined(LCALS_USE_RESTRICT_ALIGNED_PTR)
typedef TDRAReal_ptr Real_ptr;
typedef const_TDRAReal_ptr const_Real_ptr;
typedef Complex_type* __restrict__ Complex_ptr;
typedef const Complex_type* __restrict__ const_Complex_ptr;

typedef Real_type* __restrict__ UnalignedReal_ptr;
typedef const Real_type* __restrict__ const_UnalignedReal_ptr;


#elif defined(LCALS_USE_PTR_CLASS)
typedef RestrictAlignedRealPtr Real_ptr;
typedef ConstRestrictAlignedRealPtr const_Real_ptr;
typedef RestrictComplexPtr Complex_ptr;
typedef ConstRestrictComplexPtr const_Complex_ptr;

typedef RestrictRealPtr UnalignedReal_ptr;
typedef ConstRestrictRealPtr const_UnalignedReal_ptr;


#else
#error LCALS pointer type is undefined!

#endif


//
// By default, all loop variants defined as supported in the
// compiler-specific sections above are turned on here (for
// both compilation and execution).
//
// Loop variants can be turned off via the #define/#undef macros below.
// It's a bit cheesy, but it's simple and it works!
//
// Execution of individual loop variants can also be controlled
// by modifying the strings that get added to the run_loop_variants
// vector in main.cxx
//


//
//  Execution policies applicable to "forall" loop variants.  
//  Traversal method templates are defined in LCALSTraversalMethods.hxx 
//  header files.
//

// Tag struct types define available forall method execution policies
struct seq_exec {};
struct simd_exec {};
struct omp_parallel_for_exec {};
struct omp_for_nowait_exec {};

// 
// Execution policy used in (non-OpenMP) "forall" loop variants.  
// To use another policy in all such loops, change this typedef.
//
typedef simd_exec exec_policy;



#endif  // closing endif for header file include guard
