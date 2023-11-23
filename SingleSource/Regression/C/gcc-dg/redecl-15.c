/* Test for ICE with redeclaration in inner scope which is accepted
   despite incompatible type.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-options "-std=gnu89" } */

void
f (void)
{
  g(); /* { dg-message "note: previous implicit declaration of 'g'" } */
  {
    void g(); /* { dg-warning "conflicting types for 'g'" } */
  }
}
