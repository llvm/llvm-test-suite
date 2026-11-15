// 10 x i32 args. RISC-V and AArch64 pass the first 8 in registers and
// spill the rest to the caller's outgoing stack region. musttail reuses
// that incoming layout. This exercises the getStackSize() != 0 bypass
// in isEligibleForTailCallOptimization that LLVM PR #185094 reworked
// (the bypass already existed in some form on these backends; this
// test guards against future regressions of musttail with stack-passed
// args independently of the indirect-arg fix).

#include "musttail-common.h"

__attribute__((noinline)) static int callee(int a, int b, int c, int d, int e,
                                            int f, int g, int h, int i,
                                            int j) {
  if (a != 1)
    return 1;
  if (b != 2)
    return 2;
  if (c != 3)
    return 3;
  if (d != 4)
    return 4;
  if (e != 5)
    return 5;
  if (f != 6)
    return 6;
  if (g != 7)
    return 7;
  if (h != 8)
    return 8;
  if (i != 9)
    return 9;
  if (j != 10)
    return 10;
  return 0;
}

__attribute__((noinline)) static int caller(int a, int b, int c, int d, int e,
                                            int f, int g, int h, int i,
                                            int j) {
  __attribute__((musttail)) return callee(a, b, c, d, e, f, g, h, i, j);
}

int main(void) {
  int r = caller(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  if (r != 0)
    fprintf(stderr, "stack-spill-10-i32: arg slot mismatch (got %d)\n", r);
  return r;
}
