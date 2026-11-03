// Same argument forwarded to three call slots: `C(a, a, a)`.
// Generalizes alias-distinct-addresses to three slots: the callee
// writes through one and observes the others via volatile reads.
// Two of the three observations must remain unaffected for the C ABI
// rule (distinct storage per by-value param) to hold.
//
// REQUIRES: clang (for __attribute__((musttail))).

#include "musttail-common.h"

static const bigint kA = {{0x1A1A1A1A1A1A1A1AULL, 0x2A2A2A2A2A2A2A2AULL,
                           0x3A3A3A3A3A3A3A3AULL, 0x4A4A4A4A4A4A4A4AULL}};

#define POISON 0xDEADBEEFCAFEBABEULL

__attribute__((noinline)) static int callee(bigint x, bigint y, bigint z) {
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
  return 0;
}

__attribute__((noinline)) static int caller(bigint a, bigint b, bigint c) {
  (void)b;
  (void)c;
  __attribute__((musttail)) return callee(a, a, a);
}

int main(void) {
  bigint zero = {{0, 0, 0, 0}};
  int r = caller(kA, zero, zero);
  switch (r) {
  case 1:
    fprintf(stderr, "triple-alias: writing to x changed y (slot 0-1 alias)\n");
    break;
  case 2:
    fprintf(stderr, "triple-alias: writing to x changed z (slot 0-2 alias)\n");
    break;
  case 3:
    fprintf(stderr, "triple-alias: y corrupted\n");
    break;
  case 4:
    fprintf(stderr, "triple-alias: z corrupted\n");
    break;
  }
  return r;
}
