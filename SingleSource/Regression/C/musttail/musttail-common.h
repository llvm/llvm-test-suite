// Helpers shared by the musttail regression tests in this directory.
//
// The 256-bit `bigint` is the smallest type that is passed indirect by the
// RISC-V (RV32 and RV64) and AArch64 (SVE-disabled) ABIs. fp128 and i128
// would also exercise the indirect path on RV32 specifically, but are not
// portable across the three targets we care about (RV, AArch64, x86_64).

#ifndef MUSTTAIL_COMMON_H
#define MUSTTAIL_COMMON_H

#include <stdio.h>

typedef struct {
  unsigned long long parts[4];
} bigint;

static inline int bigint_eq(const bigint *a, const bigint *b) {
  return a->parts[0] == b->parts[0] && a->parts[1] == b->parts[1] &&
         a->parts[2] == b->parts[2] && a->parts[3] == b->parts[3];
}

#endif
