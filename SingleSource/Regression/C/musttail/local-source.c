// musttail with a local-variable source: `C(local)`. The value lives
// in the caller's frame, which the tail call deallocates. The frontend
// must route the value through the incoming-parameter storage (which
// survives) rather than forwarding a pointer to the local.
//
// The local is computed at runtime from a `volatile` seed so the
// optimizer cannot fold it into a constant and skip the byval-temp
// pattern this test is designed to expose.
//
// REQUIRES: clang (for __attribute__((musttail))).

#include "musttail-common.h"

static volatile unsigned long long gSeed = 0x4242424242424242ULL;

__attribute__((noinline)) static int callee(bigint a) {
  unsigned long long seed = gSeed;
  if (a.parts[0] != seed)
    return 1;
  if (a.parts[1] != (seed ^ 0xFFULL))
    return 2;
  if (a.parts[2] != (seed + 1))
    return 3;
  if (a.parts[3] != ~seed)
    return 4;
  return 0;
}

__attribute__((noinline)) static int caller(bigint incoming) {
  (void)incoming;
  unsigned long long seed = gSeed;
  bigint local;
  local.parts[0] = seed;
  local.parts[1] = seed ^ 0xFFULL;
  local.parts[2] = seed + 1;
  local.parts[3] = ~seed;
  __attribute__((musttail)) return callee(local);
}

int main(void) {
  bigint dummy = {{0, 0, 0, 0}};
  int r = caller(dummy);
  switch (r) {
  case 1:
    fprintf(stderr, "local-source: parts[0] corrupted\n");
    break;
  case 2:
    fprintf(stderr, "local-source: parts[1] corrupted\n");
    break;
  case 3:
    fprintf(stderr, "local-source: parts[2] corrupted\n");
    break;
  case 4:
    fprintf(stderr, "local-source: parts[3] corrupted\n");
    break;
  }
  return r;
}
