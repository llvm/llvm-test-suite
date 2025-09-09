/* Test __attribute__((deprecated)).  Test merging with multiple
   declarations.  Bug 7425.  */
/* { dg-do compile } */
/* { dg-options "" } */

void func(void);
void func(void) __attribute__((deprecated));

void f(void) {
  func(); /* { dg-warning "'func' is deprecated" } */
}
