// musttail behind a branch: the SDValue-lifetime regression in LLVM PR
// #185094 review. LowerFormalArguments runs in the entry BB and the
// musttail lives in a successor BB. Storing the indirect-arg pointer as
// an SDValue across the BB boundary was invalidated by CurDAG->clear();
// the vreg-based fix keeps the pointer alive across BBs.

#include "musttail-common.h"

static const bigint kInput = {{0xC0DEC0DEC0DEC0DEULL, 0xDEADBEEFDEADBEEFULL,
                               0xFEEDFACEFEEDFACEULL, 0xCAFEBABECAFEBABEULL}};

__attribute__((noinline)) static int callee(bigint a, int cond) {
  (void)cond;
  return bigint_eq(&a, &kInput) ? 0 : 1;
}

static volatile int gCond = 1;

__attribute__((noinline)) static int caller(bigint a, int cond) {
  if (cond) {
    __attribute__((musttail)) return callee(a, cond);
  }
  return 99;
}

static volatile int gFalse = 0;

int main(void) {
  int r = caller(kInput, gCond);
  if (r != 0) {
    fprintf(stderr, "cross-bb-musttail: forwarded ptr corrupted across BBs\n");
    return r;
  }
  // Exercise the false branch too so the entry-block CopyToReg is not the
  // only path validated.
  int s = caller(kInput, gFalse);
  if (s != 99) {
    fprintf(stderr, "cross-bb-musttail: false branch returned %d, expected 99\n", s);
    return 2;
  }
  return 0;
}
