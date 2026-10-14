// Swap combined with aliasing: `C(b, a, a)`. Slot 0 takes the second
// incoming (`b`); slots 1 and 2 both take the first incoming (`a`).
// A two-phase emit that handles aliasing for a pure repeat `C(a, a, a)`
// can still fail this case if the swap-phase ordering leaves slot 2's
// read clobbered by slot 0's write to slot 1's incoming pointer.
//
// REQUIRES: clang (for __attribute__((musttail))).

#include "musttail-common.h"

static const bigint kA = {{0xA1A1A1A1A1A1A1A1ULL, 0xA2A2A2A2A2A2A2A2ULL,
                           0xA3A3A3A3A3A3A3A3ULL, 0xA4A4A4A4A4A4A4A4ULL}};

static const bigint kB = {{0xB1B1B1B1B1B1B1B1ULL, 0xB2B2B2B2B2B2B2B2ULL,
                           0xB3B3B3B3B3B3B3B3ULL, 0xB4B4B4B4B4B4B4B4ULL}};

#define POISON 0xDEADBEEFCAFEBABEULL

__attribute__((noinline)) static int callee(bigint x, bigint y, bigint z) {
  // Slot 0 should hold kB; slots 1 and 2 should both hold kA.
  // Address-distinctness via write-then-read probe.
  x.parts[0] = POISON;
  volatile unsigned long long *vy = (volatile unsigned long long *)&y;
  volatile unsigned long long *vz = (volatile unsigned long long *)&z;
  unsigned long long via_y = vy[0];
  unsigned long long via_z = vz[0];
  if (via_y == POISON)
    return 1;
  if (via_z == POISON)
    return 2;
  if (via_y != kA.parts[0])
    return 3;
  if (via_z != kA.parts[0])
    return 4;
  // Sanity: x's other parts should still be kB.
  if (x.parts[1] != kB.parts[1] || x.parts[2] != kB.parts[2] ||
      x.parts[3] != kB.parts[3])
    return 5;
  return 0;
}

__attribute__((noinline)) static int caller(bigint a, bigint b, bigint c) {
  (void)c;
  __attribute__((musttail)) return callee(b, a, a);
}

int main(void) {
  bigint zero = {{0, 0, 0, 0}};
  int r = caller(kA, kB, zero);
  switch (r) {
  case 1:
    fprintf(stderr, "swap-alias: write to x changed y (slot 0/1 alias)\n");
    break;
  case 2:
    fprintf(stderr, "swap-alias: write to x changed z (slot 0/2 alias)\n");
    break;
  case 3:
    fprintf(stderr, "swap-alias: y is not kA\n");
    break;
  case 4:
    fprintf(stderr, "swap-alias: z is not kA\n");
    break;
  case 5:
    fprintf(stderr, "swap-alias: x (kB) corrupted\n");
    break;
  }
  return r;
}
