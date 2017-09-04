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

/*----------------------------------------------------------------------
Description:
  Inverse of the Hilbert Space-Filling Curve Map from a 2D or 3D
domain to the 1D domain.  Two different 2D and 3D domains are
supported.

For the routines 'hsfc2d' and 'hsfc3d' the 2D and 3D domains are
defined as follows.
Note that
  *     0   is the minimum value of an unsigned integer
  *   ~(0u) is the maximum value of an unsigned integer - all bits set
thus the 2D and 3D domains are
  *   [0,~(0u)] x [0,~(0u)]
  *   [0,~(0u)] x [0,~(0u)] x [0,~(0u)]
respectively.

For the routines 'fhsfc2d' and 'fhsfc3d' the 2D and 3D domains are
defines as:
  *   [0.0,1.0] x [0.0,1.0]
  *   [0.0,1.0] x [0.0,1.0] x [0.0,1.0]
respectively.

The 1D domain is a multiword (array of unsigned integers) key.
This key is essentially an unsigned integer of an arbitrary
number of bits.  The most significant bit is the leading bit
of the first (0th) word of the key.  The least significant
bit is the trailing bit of the last word.

----------------------------------------------------------------------*/

#ifndef __HILBERT_SPACE_FILLING_CURVE_MAPPING__
#define __HILBERT_SPACE_FILLING_CURVE_MAPPING__

#ifdef __cplusplus
extern "C" {
#endif

extern void hsfc2d(
  unsigned   coord[] , /* IN: Normalized integer 2D coordinate */
  unsigned   nkey ,    /* IN: Word length of key */
  unsigned   key[] );  /* OUT: space-filling curve key */

extern void hsfc3d(
  unsigned   coord[] , /* IN: Normalized integer 3D coordinate */
  unsigned   nkey ,    /* IN: Word length of 'key' */
  unsigned   key[] );  /* OUT: space-filling curve key */

extern void fhsfc2d(
  double     coord[] , /* IN: Normalized floating point 2D coordinate */
  unsigned   nkey ,    /* IN: Word length of key */
  unsigned   key[] );  /* OUT: space-filling curve key */

extern void fhsfc3d(
  double     coord[] , /* IN: Normalized floating point 3D coordinate */
  unsigned   nkey ,    /* IN: Word length of key */
  unsigned   key[] );  /* OUT: space-filling curve key */

#ifdef __cplusplus
}
#endif

#endif

