/* { dg-do compile } */
/* { dg-options "-fstrict-overflow -O2 -Wstrict-overflow=2" } */

/* Source: Ian Lance Taylor.  Based on strict-overflow-1.c.  */

/* We can only simplify the conditional when using strict overflow
   semantics.  */

int
foo (int i)
{
  return i - 5 < 10;
}
