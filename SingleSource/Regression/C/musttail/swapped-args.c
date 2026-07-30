// Swapped indirect args: caller receives (a, b) and musttails callee(b, a).
// Before the OrigArgIndex fix in LLVM PR #185094, the RISC-V backend
// forwarded the wrong incoming pointers because InputArg::OrigArgIndex
// (unfiltered) and OutputArg::OrigArgIndex (filtered into CallBase::args)
// have different semantics, and the LowerCall side keyed off the wrong one.

#include "musttail-common.h"

static const bigint kA = {{0xAAAA000000000001ULL, 0xAAAA000000000002ULL,
                           0xAAAA000000000003ULL, 0xAAAA000000000004ULL}};

static const bigint kB = {{0xBBBB000000000001ULL, 0xBBBB000000000002ULL,
                           0xBBBB000000000003ULL, 0xBBBB000000000004ULL}};

__attribute__((noinline)) static int callee(bigint x, bigint y) {
  if (!bigint_eq(&x, &kB))
    return 1;
  if (!bigint_eq(&y, &kA))
    return 2;
  return 0;
}

__attribute__((noinline)) static int caller(bigint a, bigint b) {
  __attribute__((musttail)) return callee(b, a);
}

int main(void) {
  int r = caller(kA, kB);
  if (r == 1)
    fprintf(stderr, "swapped-args: first arg not swapped\n");
  else if (r == 2)
    fprintf(stderr, "swapped-args: second arg not swapped\n");
  return r;
}
