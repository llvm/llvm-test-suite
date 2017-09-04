/* ---------------------------------------------------------------------
Author:     H. Carter Edwards 
            hcedwar@sandia.gov

Copyright:  Copyright (C) 1997   H. Carter Edwards
            Graduate Student
            University of Texas

Re-release: Copyright (C) 2011-2012   H. Carter Edwards

Purpose:    Domain paritioning based upon Hilbert Space-Filling Curve
            ordering.

License:    Re-release under the less-restrictive CLAMR software terms.
            Permitted by email with H. Carter Edwards on 9/13/2011

Disclaimer:

    These routines comes with ABSOLUTELY NO WARRANTY;
    This is free software, and you are welcome to redistribute it
    under certain conditions. See License terms in file 'LICENSE'.
--------------------------------------------------------------------- */

#include <limits.h>
#include <stdlib.h>

#include "hsfc.h"

/*--------------------------------------------------------------------*/
/* Make it callable from FORTRAN:
 *   Interface types: INTEGER and REAL*8
 */

void hsfc2sort(
               const int      N ,     /* IN: Number of points */
               const double * X ,     /* IN: array of X-Coordinates */
               const double * Y ,     /* IN: array of Y-Coordinates */
               const int      ibase,  /* 0 for C and 1 for Fortran */
               int          * Info ,  /* OUT: (1 <= LDInfo) [ HSFC ordering ]
                                 (2 <= LDInfo) [ HSFC index, #1 ]
                                 (3 <= LDInfo) [ HSFC index, #2 ] */
               int            LDInfo /* IN:  Leading dimension of Info */
               );

/*--------------------------------------------------------------------*/

#define MaxBits ( sizeof(unsigned) * CHAR_BIT )

#define NBITC     (32)  /* 32 Bits per coordinate, resolve data at 2^31 */
#define NKEY(ND)  ((NBITC * ND + MaxBits - 1) / MaxBits)

/*--------------------------------------------------------------------*/

static int ui1comp( const void * const I1 , const void * const I2 )
{
  return (
    ( ((const unsigned *)I1)[0] != ((const unsigned *)I2)[0] ) ? (
    ( ((const unsigned *)I1)[0] <  ((const unsigned *)I2)[0] ) ? -1 : 1 ) : (
       0 ));
}

static int ui2comp( const void * const I1 , const void * const I2 )
{
  return (
    ( ((const unsigned *)I1)[0] != ((const unsigned *)I2)[0] ) ? (
    ( ((const unsigned *)I1)[0] <  ((const unsigned *)I2)[0] ) ? -1 : 1 ) : (
    ( ((const unsigned *)I1)[1] != ((const unsigned *)I2)[1] ) ? (
    ( ((const unsigned *)I1)[1] <  ((const unsigned *)I2)[1] ) ? -1 : 1 ) : (
       0 )));
}

/*--------------------------------------------------------------------*/

static int ui3comp( const void * const I1 , const void * const I2 )
{
  return (
    ( ((const unsigned *)I1)[0] != ((const unsigned *)I2)[0] ) ? (
    ( ((const unsigned *)I1)[0] <  ((const unsigned *)I2)[0] ) ? -1 : 1 ) : (
    ( ((const unsigned *)I1)[1] != ((const unsigned *)I2)[1] ) ? (
    ( ((const unsigned *)I1)[1] <  ((const unsigned *)I2)[1] ) ? -1 : 1 ) : (
    ( ((const unsigned *)I1)[2] != ((const unsigned *)I2)[2] ) ? (
    ( ((const unsigned *)I1)[2] <  ((const unsigned *)I2)[2] ) ? -1 : 1 ) : (
       0 ))));
}

static int N_uiNcomp = 0 ;

static int uiNcomp( const void * const I1 , const void * const I2 )
{
  const int N = N_uiNcomp ;
  register int i ;

  for ( i = 0 ; i < N &&
    ((const unsigned *)I1)[i] != ((const unsigned *)I2)[i] ; ++i );

  return ( i < N ) ? (
    ( ((const unsigned *)I1)[i] < ((const unsigned *)I2)[i] ) ? -1 : 1 ) : 0 ;
}

/*--------------------------------------------------------------------*/

void hsfc2sort(
  const int      N ,     /* IN: Number of points */
  const double * X ,     /* IN: array of X-Coordinates */
  const double * Y ,     /* IN: array of Y-Coordinates */
  const int      ibase,  /* 0 for C and 1 for Fortran */
        int    * Info ,  /* OUT: (1 <= LDInfo) [ HSFC ordering ]
                                   (2 <= LDInfo) [ HSFC index, #1 ]
                                   (3 <= LDInfo) [ HSFC index, #2 ] */
        int      LDInfo )/* IN:  Leading dimension of Info */
{
  /*------------------------------------------------------------------*/

  const double imax = ((double) ~(0u)) ;

  const unsigned ldinfo = LDInfo ;
  const unsigned long long npt    = N ;
  const unsigned nkey   = NKEY(2) ;
  const unsigned ldT    = nkey + 1 ;

  unsigned * const T = (unsigned *) malloc( sizeof(unsigned) * ldT * npt );

  int i , ix , iy , ii , it ;

  /* Fill SFC table */

  for ( i = it = ix = iy = 0 ; (unsigned long long)i < npt ;
        ++i , ix++ , iy++ , it += ldT ) {
    double xy[2] ;
    unsigned coord[2] ;

    xy[0] = X[ix] ;
    xy[1] = Y[iy] ;

    coord[0] = xy[0] * imax ;
    coord[1] = xy[1] * imax ;

    hsfc2d( coord , nkey , T + it );
    T[it+nkey] = i ;
  }

  /* SFC Key output */
  
  if ( 2 < ldinfo && 1 < nkey ) {
    for ( ii = 1, it = 0, i = 0 ; (unsigned long long)i < npt ; ++i, ii += ldinfo, it += ldT ) {
      Info[ii]   = T[it];
      Info[ii+1] = T[it+1];
    }
  }
  else if ( 1 < ldinfo ) {
    for ( ii = 1, it = 0 ,i = 0 ; (unsigned long long)i < npt ; ++i, ii += ldinfo, it += ldT ) {
      Info[ii] = T[it] ;
    }
  }

  /* Sort */

  switch ( nkey ) {
  case 0: break ;
  case 1: qsort( T , npt , sizeof(unsigned) * ldT , ui1comp ); break ;
  case 2: qsort( T , npt , sizeof(unsigned) * ldT , ui2comp ); break ;
  case 3: qsort( T , npt , sizeof(unsigned) * ldT , ui3comp ); break ;
  default:
    N_uiNcomp = nkey ;
    qsort( T , npt , sizeof(unsigned) * ldT , uiNcomp );
    N_uiNcomp = 0 ;
    break ;
  }

  for (ii = 0, i = 0, it = nkey ; (unsigned long long)i < npt ; ++i, ii += ldinfo, it += ldT) {
    Info[ii] = T[it] + ibase; /* 1 -- FORTRAN convention, 0 -- C */
  }

  free( (void *) T );

  return ;
}

/*--------------------------------------------------------------------*/

void hsfc3sort(
  const int      N ,     /* IN: Number of points */
  const double * X ,     /* IN: array of X-Coordinates */
  const double * Y ,     /* IN: array of Y-Coordinates */
  const double * Z ,     /* IN: array of Y-Coordinates */
  const int      ibase ,    /* IN: Stride for Y array */
        int    * Info ,  /* OUT: (1 <= LDInfo) [ HSFC ordering ]
                                   (2 <= LDInfo) [ HSFC index, #1 ]
                                   (3 <= LDInfo) [ HSFC index, #2 ]
                                   (4 <= LDInfo) [ HSFC index, #3 ] */
        int      LDInfo )/* IN:  Leading dimension of Info */
{
  /*------------------------------------------------------------------*/

  const double imax = ((double) ~(0u)) ;

  const unsigned ldinfo = LDInfo ;
  const unsigned long long npt    = N ;
  const unsigned nkey   = NKEY(3) ;
  const unsigned ldT    = nkey + 1 ;

  unsigned * const T = (unsigned *) malloc( sizeof(unsigned) * ldT * npt );

  int i , ix , iy , iz , ii , it ;

  /* Fill SFC table */

  for ( i = it = ix = iy = iz = 0 ; (unsigned long long)i < npt ;
        ++i , ix++ , iy++ , iz++ , it += ldT ) {
    double xyz[3] ;
    unsigned coord[3] ;

    xyz[0] = X[ix] ;
    xyz[1] = Y[iy] ;
    xyz[2] = Z[iz] ;

    coord[0] = xyz[0] * imax ;
    coord[1] = xyz[1] * imax ;
    coord[2] = xyz[2] * imax ;

    hsfc3d( coord , nkey , T + it );
    T[it+nkey] = i ;
  }

  /* SFC Key output */
  
  if ( 3 < ldinfo && 2 < nkey ) {
    for ( ii = 1, it = 0, i = 0 ; (unsigned long long)i < npt ; ++i, ii += ldinfo, it += ldT ) {
      Info[ii]   = T[it];
      Info[ii+1] = T[it+1];
      Info[ii+2] = T[it+2];
    }
  }
  else if ( 2 < ldinfo && 1 < nkey ) {
    for ( ii = 1, it = 0, i = 0 ; (unsigned long long)i < npt ; ++i, ii += ldinfo, it += ldT ) {
      Info[ii]   = T[it];
      Info[ii+1] = T[it+1];
    }
  }
  else if ( 1 < ldinfo ) {
    for ( ii = 1, it = 0 ,i = 0 ; (unsigned long long)i < npt ; ++i, ii += ldinfo, it += ldT ) {
      Info[ii] = T[it] ;
    }
  }

  /* Sort */

  switch ( nkey ) {
  case 0: break ;
  case 1: qsort( T , npt , sizeof(unsigned) * ldT , ui1comp ); break ;
  case 2: qsort( T , npt , sizeof(unsigned) * ldT , ui2comp ); break ;
  case 3: qsort( T , npt , sizeof(unsigned) * ldT , ui3comp ); break ;
  default:
    N_uiNcomp = nkey ;
    qsort( T , npt , sizeof(unsigned) * ldT , uiNcomp );
    N_uiNcomp = 0 ;
    break ;
  }

  for (ii = 0, i = 0, it = nkey ; (unsigned long long)i < npt ; ++i, ii += ldinfo, it += ldT) {
    Info[ii] = T[it] + ibase ; /* FORTRAN convention */
  }

  free( (void *) T );

  return ;
}

