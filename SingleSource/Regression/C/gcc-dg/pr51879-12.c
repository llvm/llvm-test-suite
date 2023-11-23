/* { dg-do compile } */
/* { dg-options "-O2 -ftree-tail-merge -fdump-tree-pre -fno-code-hoisting" } */

__attribute__((pure)) int bar (int);
__attribute__((pure)) int bar2 (int);
void baz (int);

int x, z;

void
foo (int y)
{
  int a = 0;
  if (y == 6)
    {
      a += bar (7);
      a += bar2 (6);
    }
  else
    {
      a += bar2 (6);
      a += bar (7);
    }
  baz (a);
}

/* { dg-final { scan-tree-dump-times "bar \\(" 1 "pre" { xfail *-*-* } } } */
/* { dg-final { scan-tree-dump-times "bar2 \\(" 1 "pre" { xfail *-*-* } } } */
