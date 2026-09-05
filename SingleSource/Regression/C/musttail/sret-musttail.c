// sret + musttail: caller returns a 256-bit struct, which is too large to
// return in registers on RISC-V and AArch64. Both caller and callee get an
// implicit sret pointer; the pointer is forwarded unchanged through the
// musttail. Confirms that the sret bypass in
// isEligibleForTailCallOptimization (added in LLVM PR #185094) is correct.

#include "musttail-common.h"

static const bigint kExpected = {{0xDEADBEEF00000001ULL, 0xDEADBEEF00000002ULL,
                                  0xDEADBEEF00000003ULL,
                                  0xDEADBEEF00000004ULL}};

__attribute__((noinline)) static bigint callee(void) { return kExpected; }

__attribute__((noinline)) static bigint caller(void) {
  __attribute__((musttail)) return callee();
}

int main(void) {
  bigint got = caller();
  if (!bigint_eq(&got, &kExpected)) {
    fprintf(stderr, "sret-musttail: returned bigint corrupted\n");
    return 1;
  }
  return 0;
}
