/* Test formatting of message for invalid lvalue.  Bug 17730.  */
/* { dg-do compile } */
/* { dg-options "" } */

char *p = &'C'; /* { dg-error "lvalue required as unary '&' operand" } */
