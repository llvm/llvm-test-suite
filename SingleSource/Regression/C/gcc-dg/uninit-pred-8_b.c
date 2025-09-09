/* { dg-do compile } */
/* ???  Jump threading makes a mess of the logical-op-non-short-circuit=0 case
   so force it our way.  */
/* { dg-options "-Wuninitialized -O2 --param logical-op-non-short-circuit=1" } */

int g;
void bar();
void blah(int);

int foo (int n, int l, int m, int r)
{
  int v;

  if (n < 10 || m > 100 || r < 20 || l)
    v = r;

  if (m) g++;
  else   bar();

  if ( n < 10 ||  m > 100 || r < 20 )
      blah(v); /* { dg-bogus "uninitialized" "bogus warning" } */

  if ( n < 10 ||  m > 100 || r < 10 )
      blah(v); /* { dg-bogus "uninitialized" "bogus warning" } */

  return 0;
}

int foo_2 (int n, int l, int m, int r)
{
  int v;

  if (n < 10 || m > 100 || r < 20 || l)
    v = r;

  if (m) g++;
  else   bar();

  if ( n < 10 ||  m > 100 || r < 20 )
      blah(v); /* { dg-bogus "uninitialized" "bogus warning" } */

  if ( n < 10 ||  m > 100 || r < 30 )
      blah(v); /* { dg-warning "uninitialized" "warning" } */

  return 0;
}
