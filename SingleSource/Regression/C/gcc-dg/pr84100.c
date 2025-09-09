/* PR c/84100 */
/* { dg-do compile } */
/* { dg-options "-O2" } */
/* { dg-skip-if "no code alignment > 2" { "pdp11-*-*" } } */

void bar (void);

__attribute__((optimize ("align-loops=16", "align-jumps=16",
			 "align-labels=16", "align-functions=16")))
void
foo (void)
{			/* { dg-bogus "bad option" } */
  for (int i = 0; i < 1024; ++i)
    bar ();
}
