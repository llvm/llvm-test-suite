/* Some incompatible external linkage declarations were not diagnosed.
   Bug 21342.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-options "" } */

extern int a[];
void f(void) { extern int a[]; extern int a[10]; } /* { dg-message "note: previous declaration of 'a'" "note" } */
extern int a[5]; /* { dg-error "conflicting types for 'a'" } */
