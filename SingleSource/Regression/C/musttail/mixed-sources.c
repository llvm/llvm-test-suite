// musttail with one local source and one forwarded-incoming source:
// `C(local, a)`. The two slots take different code paths inside the
// frontend's two-phase emit: slot 0 copies the runtime-computed local
// into the i=0 incoming pointer; slot 1 forwards the incoming arg.
//
// The callee receives two values; slot 0 holds the local, slot 1 holds
// the original incoming. The local is computed from a volatile seed to
// defeat constant folding.
//
// REQUIRES: clang (for __attribute__((musttail))).

#include "musttail-common.h"

static volatile unsigned long long gSeed = 0x1234567812345678ULL;

static const bigint kIncoming = {{0xC0FFEEC0FFEEC0FFULL, 0xEEC0FFEEC0FFEEC0ULL,
                                  0xFFEEC0FFEEC0FFEEULL, 0xC0FFEEC0FFEEC0FFULL}};

__attribute__((noinline)) static int callee(bigint x, bigint y) {
  unsigned long long seed = gSeed;
  if (x.parts[0] != seed)
    return 1;
  if (x.parts[1] != (seed + 1))
    return 2;
  if (!bigint_eq(&y, &kIncoming))
    return 3;
  return 0;
}

__attribute__((noinline)) static int caller(bigint a, bigint b) {
  (void)b;
  unsigned long long seed = gSeed;
  bigint local;
  local.parts[0] = seed;
  local.parts[1] = seed + 1;
  local.parts[2] = seed + 2;
  local.parts[3] = seed + 3;
  __attribute__((musttail)) return callee(local, a);
}

int main(void) {
  bigint b = {{0, 0, 0, 0}};
  int r = caller(kIncoming, b);
  switch (r) {
  case 1:
    fprintf(stderr, "mixed-sources: local slot parts[0] corrupted\n");
    break;
  case 2:
    fprintf(stderr, "mixed-sources: local slot parts[1] corrupted\n");
    break;
  case 3:
    fprintf(stderr, "mixed-sources: incoming slot corrupted\n");
    break;
  }
  return r;
}
