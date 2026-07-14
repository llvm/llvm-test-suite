// Same argument forwarded to two call slots: `C(a, a)`. The C ABI
// gives each by-value parameter its own storage; the callee can observe
// aliasing by writing through one slot and reading the other.
//
// `&x == &y` would also expose the bug but the optimizer folds that
// check at -O1+ (it treats indirect params as noalias by ABI). The
// write-then-read-via-volatile probe survives optimization.
//
// Before llvm/llvm-project#199351, fork-clang's forwarding path passed
// the same incoming pointer to both slots for non-restrict struct args.
// Writing to `x` then reading `y` exposed the alias.
//
// REQUIRES: clang (for __attribute__((musttail))).

#include "musttail-common.h"

static const bigint kA = {{0xA1A1A1A1A1A1A1A1ULL, 0xA2A2A2A2A2A2A2A2ULL,
                           0xA3A3A3A3A3A3A3A3ULL, 0xA4A4A4A4A4A4A4A4ULL}};

#define POISON 0xDEADBEEFCAFEBABEULL

__attribute__((noinline)) static int callee(bigint x, bigint y) {
  // Write a known poison value through x.parts[0]. Read y.parts[0]
  // via a volatile pointer so the optimizer cannot reuse x's prior
  // value or assume the load is independent.
  x.parts[0] = POISON;
  volatile unsigned long long *vy = (volatile unsigned long long *)&y;
  unsigned long long via_y = vy[0];
  if (via_y == POISON)
    return 1;
  if (via_y != kA.parts[0])
    return 2;
  if (x.parts[1] != kA.parts[1] || x.parts[2] != kA.parts[2] ||
      x.parts[3] != kA.parts[3])
    return 3;
  return 0;
}

__attribute__((noinline)) static int caller(bigint a, bigint b) {
  (void)b;
  __attribute__((musttail)) return callee(a, a);
}

int main(void) {
  bigint b = {{0, 0, 0, 0}};
  int r = caller(kA, b);
  switch (r) {
  case 1:
    fprintf(stderr, "alias-distinct-addresses: writing to x changed y "
                    "(ABI violation)\n");
    break;
  case 2:
    fprintf(stderr, "alias-distinct-addresses: y corrupted\n");
    break;
  case 3:
    fprintf(stderr, "alias-distinct-addresses: x corrupted\n");
    break;
  }
  return r;
}
