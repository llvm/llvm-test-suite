/* PR c/61162 */
/* { dg-do compile } */
/* { dg-options "-Wc++-compat" } */

enum e { A };
enum e
fn1 (void)
{
  enum e e, q = 0; /* { dg-warning "17:enum conversion from 'int' to 'enum e' in initialization is invalid" } */
  e = 0; /* { dg-warning "5:enum conversion from 'int' to 'enum e' in assignment is invalid" } */
  1; return 0; /* { dg-warning "13:enum conversion from 'int' to 'enum e' in return is invalid" } */
}
