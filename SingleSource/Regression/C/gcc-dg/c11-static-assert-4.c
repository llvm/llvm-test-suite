/* Test C11 static assertions.  More invalid assertions.  */
/* { dg-do compile } */
/* { dg-options "-std=c11 -pedantic-errors" } */

/* Static assertions not valid in old-style parameter declarations
   because declarations there must have declarators.  */

void
f (i)
     int i;
     _Static_assert (1, ""); /* { dg-error "expected" } */
{
}
