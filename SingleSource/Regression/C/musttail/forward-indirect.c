// Forwarded indirect arg: caller receives a 256-bit bigint and musttails
// to a callee that takes the same value. The arg is passed indirect by
// the RISC-V and AArch64 ABIs (struct > 2*XLEN). Before LLVM PR #185094,
// the RISC-V backend allocated a fresh stack temporary in the caller and
// passed a pointer that became dangling after the tail call deallocated
// the caller's frame.
//
// REQUIRES: clang (for __attribute__((musttail))).

#include "musttail-common.h"

static const bigint kInput = {{0x1111111111111111ULL, 0x2222222222222222ULL,
                               0x3333333333333333ULL, 0x4444444444444444ULL}};

__attribute__((noinline)) static int callee(bigint a) {
  return bigint_eq(&a, &kInput) ? 0 : 1;
}

__attribute__((noinline)) static int caller(bigint a) {
  __attribute__((musttail)) return callee(a);
}

int main(void) {
  int r = caller(kInput);
  if (r != 0)
    fprintf(stderr, "forward-indirect: arg corrupted across musttail\n");
  return r;
}
