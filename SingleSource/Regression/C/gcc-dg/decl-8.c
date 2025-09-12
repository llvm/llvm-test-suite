/* Test diagnostics for duplicate typedefs.  Basic diagnostics.  */
/* Origin: Joseph Myers <joseph@codesourcery.com> */
/* { dg-do compile } */
/* { dg-options "-std=gnu89 -pedantic-errors" } */

typedef int I; /* { dg-message "note: previous declaration of 'I'" "note" } */
typedef int I; /* { dg-error "redefinition of typedef 'I'" } */

typedef int I1; /* { dg-message "note: previous declaration of 'I1'" "note" } */
typedef long I1; /* { dg-error "conflicting types for 'I1'" } */
