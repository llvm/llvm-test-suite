// Computed indirect arg: caller modifies the bigint then musttails. This
// is the case folkertdev caught during LLVM PR #185094 review -- before
// the fix, the RISC-V backend silently dropped the modified value because
// it forwarded the original incoming pointer instead of storing the new
// value into it.

#include "musttail-common.h"

static const bigint kInput = {{0x0101010101010101ULL, 0x0202020202020202ULL,
                               0x0303030303030303ULL, 0x0404040404040404ULL}};

static const bigint kExpected = {{0x0101010101010102ULL, 0x0202020202020203ULL,
                                  0x0303030303030304ULL,
                                  0x0404040404040405ULL}};

__attribute__((noinline)) static int callee(bigint a) {
  return bigint_eq(&a, &kExpected) ? 0 : 1;
}

__attribute__((noinline)) static int caller(bigint a) {
  bigint b;
  b.parts[0] = a.parts[0] + 1;
  b.parts[1] = a.parts[1] + 1;
  b.parts[2] = a.parts[2] + 1;
  b.parts[3] = a.parts[3] + 1;
  __attribute__((musttail)) return callee(b);
}

int main(void) {
  int r = caller(kInput);
  if (r != 0)
    fprintf(stderr, "computed-indirect: computed value lost or wrong\n");
  return r;
}
