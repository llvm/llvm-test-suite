/* { dg-do compile { target { ! { *-*-darwin* hppa*-*-* amdgcn*-*-* } } } } */
/* { dg-require-effective-target fpic } */
/* { dg-options "-fpic" } */

#if __PIC__ != 1
# error __PIC__ is not 1!
#endif

#ifdef __PIE__
# error __PIE__ is defined!
#endif
