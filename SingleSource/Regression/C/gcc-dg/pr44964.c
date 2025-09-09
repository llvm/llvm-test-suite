/* { dg-do compile } */
/* { dg-options "-fkeep-inline-functions -O" } */

static inline __attribute__ ((const))
int baz (int i)
{
  return i;
}

static __attribute__ ((always_inline))
inline __attribute__ ((flatten))
void bar (void)
{
  baz (0);
}

void
foo (void)
{
  bar ();
}

