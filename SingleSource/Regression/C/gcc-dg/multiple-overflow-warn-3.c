/* PR 30465 : Test for duplicated warnings in a conversion.  */
/* { dg-do compile } */
/* { dg-options "-Woverflow" } */

short int
g (void)
{
  short int wc = ((short int)1 << (8 * __SIZEOF_INT__ - 1)) - 1; /* { dg-bogus "overflow .* overflow" } */
  /* { dg-warning "overflow" "" { target *-*-* } .-1 } */
  return wc;
}


