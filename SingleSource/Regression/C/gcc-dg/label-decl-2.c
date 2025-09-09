/* Test diagnostics for label declarations.  Test with -pedantic.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-options "-pedantic" } */

typedef int b;

void
f (void)
{
  __label__ a, b, c, d; /* { dg-warning "ISO C forbids label declarations" "label decls" } */
  __extension__ (void)&&d; /* { dg-error "label 'd' used but not defined" } */
  goto c; /* { dg-error "label 'c' used but not defined" } */
 a: (void)0;
 b: (void)0;
}
