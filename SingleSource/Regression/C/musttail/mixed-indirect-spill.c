// Indirect bigint + 9 i32 args on the same musttail call. Exercises both
// the indirect-arg forwarding path (LLVM PR #185094) and the stack-spill
// bypass on the same call site.

#include "musttail-common.h"

static const bigint kBig = {{0x1234567890ABCDEFULL, 0xFEDCBA0987654321ULL,
                             0xAAAAAAAAAAAAAAAAULL, 0x5555555555555555ULL}};

__attribute__((noinline)) static int callee(bigint big, int a, int b, int c,
                                            int d, int e, int f, int g, int h,
                                            int i) {
  if (!bigint_eq(&big, &kBig))
    return 100;
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
  return 0;
}

__attribute__((noinline)) static int caller(bigint big, int a, int b, int c,
                                            int d, int e, int f, int g, int h,
                                            int i) {
  __attribute__((musttail)) return callee(big, a, b, c, d, e, f, g, h, i);
}

int main(void) {
  int r = caller(kBig, 1, 2, 3, 4, 5, 6, 7, 8, 9);
  if (r != 0)
    fprintf(stderr, "mixed-indirect-spill: arg corrupted across musttail (got %d)\n", r);
  return r;
}
