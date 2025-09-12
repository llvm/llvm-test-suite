/* { dg-do compile } */
/* { dg-options "-fstrict-overflow -O2 -fdump-tree-optimized" } */

/* Source: Ian Lance Taylor.  Dual of no-strict-overflow-7.c.  */

/* We can only simplify the conditional when using strict overflow
   semantics.  */

int
foo (char* p)
{
  return p + 1000 < p;
}

/* { dg-final { scan-tree-dump-not "\[+\]\[ \]*1000" "optimized" } } */
