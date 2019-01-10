/*
 * Test movedup and moveldup instructions.
 * Here we check for _mm512_[mask|maskz]move[l|h]dup intrinsics
 */

#include "m512_test_util.h"
#include <stdio.h>

int verbose = 0;

__m512 f1;
__m512 f2;
__m512 f3;
__m512 f4;

__m512d d1;
__m512d d2;
__m512d d3;
__m512d d4;

volatile int vol = 0; /* To prevent optimizations */

void NOINLINE init() {
  int i;
  V512 *pf1 = (V512 *)&f1;
  V512 *pf2 = (V512 *)&f2;
  V512 *pd1 = (V512 *)&d1;
  V512 *pd2 = (V512 *)&d2;

  for (i = 0; i < 16; i++) {
    pf1->f32[i] = 17 + ((i & 1) ? 1 : -1) * i + vol;
    pf2->f32[i] = -(100 + ((i & 3) == 3 ? 1 : -1) * i + vol);
  }

  for (i = 0; i < 8; i++) {
    pd1->f64[i] = pf1->f32[i];
    pd2->f64[i] = -pf2->f32[i];
  }
}

void NOINLINE check_equal32(void *vgot, void *vexpected, void *vexpected_orig,
                            int mask, char *banner) {
  int i;
  V512 *got = (V512 *)vgot;
  V512 *expected = (V512 *)vexpected;
  V512 *orig = (V512 *)vexpected_orig;

  for (i = 0; i < 16; i++) {
    int ans = (mask & (1 << i)) ? expected->u32[i] : orig->u32[i];
    if (got->u32[i] != ans) {
      printf("ERROR: %s failed -- 0x%0.8x != 0x%0.8x at element [%d]\n",
             banner ? banner : "", got->u32[i], ans, i);
      n_errs++;
      break;
    }
  }
}

void NOINLINE check_equal64(void *vgot, void *vexpected, void *vexpected_orig,
                            int mask, char *banner) {
  int i;
  V512 *got = (V512 *)vgot;
  V512 *expected = (V512 *)vexpected;
  V512 *orig = (V512 *)vexpected_orig;

  for (i = 0; i < 8; i++) {
    __int64 ans = (mask & (1 << i)) ? expected->u64[i] : orig->u64[i];
    if (got->u64[i] != ans) {
      printf("ERROR: %s failed -- %0.16" PRIx64 " != %0.16" PRIx64
             " at element [%d]\n",
             banner ? banner : "", got->u64[i], ans, i);
      n_errs++;
      break;
    }
  }
}

void NOINLINE emulate_movedup_pd(void *presult, const void *p1, int mask,
                                 const void *p2, int zero_masking) {
  int i;
  V512 *result = (V512 *)presult;
  V512 *v1 = (V512 *)p1;
  V512 *v2 = (V512 *)p2;

  for (i = 0; i < 8; i++) {

    if (((1 << i) & mask) == 0) {
      result->u64[i] = zero_masking ? 0 : v1->u64[i];
    } else {
      int src_index = i & 0xfe; // even index
      result->u64[i] = v2->u64[src_index];
    }
  }
}

void NOINLINE emulate_moveldup_ps(void *presult, const void *p1, int mask,
                                  const void *p2, int zero_masking) {
  int i;
  V512 *result = (V512 *)presult;
  V512 *v1 = (V512 *)p1;
  V512 *v2 = (V512 *)p2;

  for (i = 0; i < 16; i++) {

    if (((1 << i) & mask) == 0) {
      result->u32[i] = zero_masking ? 0 : v1->u32[i];
    } else {
      int src_index = i & 0xfe; // even index
      result->u32[i] = v2->u32[src_index];
    }
  }
}

void NOINLINE emulate_movehdup_ps(void *presult, const void *p1, int mask,
                                  const void *p2, int zero_masking) {
  int i;
  V512 *result = (V512 *)presult;
  V512 *v1 = (V512 *)p1;
  V512 *v2 = (V512 *)p2;

  for (i = 0; i < 16; i++) {

    if (((1 << i) & mask) == 0) {
      result->u32[i] = zero_masking ? 0 : v1->u32[i];
    } else {
      int src_index = (i & 0xfe) + 1; // odd index
      result->u32[i] = v2->u32[src_index];
    }
  }
}

void NOINLINE do_movedup_pd() {
  if (verbose) {
    printf("BEGIN do_movedup_pd\n");
  }

  d3 = _mm512_movedup_pd(d2);
  emulate_movedup_pd(&d4, (void *)0, 0xff, &d2, 0);
  check_equal64(&d3, &d4, (void *)0, 0xff, "_mm512_movedup_pd");

  d3 = _mm512_maskz_movedup_pd(0xc5, d2);
  emulate_movedup_pd(&d4, (void *)0, 0xc5, &d2, 1);
  check_equal64(&d3, &d4, (void *)0, 0xff, "_mm512_maskz_movedup_pd");

  d3 = _mm512_mask_movedup_pd(d1, 0xda, d2);
  emulate_movedup_pd(&d4, &d1, 0xda, &d2, 0);
  check_equal64(&d3, &d4, (void *)0, 0xff, "_mm512_mask_movedup_pd");

  if (verbose) {
    printf("DONE\n");
  }
}

void NOINLINE do_moveldup_ps() {
  if (verbose) {
    printf("BEGIN do_moveldup_ps\n");
  }

  f3 = _mm512_moveldup_ps(f2);
  emulate_moveldup_ps(&f4, (void *)0, 0xffff, &f2, 0);
  check_equal32(&f3, &f4, (void *)0, 0xffff, "_mm512_moveldup_ps");

  f3 = _mm512_maskz_moveldup_ps(0x79fa, f2);
  emulate_moveldup_ps(&f4, (void *)0, 0x79fa, &f2, 1);
  check_equal32(&f3, &f4, (void *)0, 0xffff, "_mm512_maskz_moveldup_ps");

  f3 = _mm512_mask_moveldup_ps(f1, 0x53da, f2);
  emulate_moveldup_ps(&f4, &f1, 0x53da, &f2, 0);
  check_equal32(&f3, &f4, (void *)0, 0xffff, "_mm512_mask_moveldup_ps");

  if (verbose) {
    printf("DONE\n");
  }
}

void NOINLINE do_movehdup_ps() {
  if (verbose) {
    printf("BEGIN do_movehdup_ps\n");
  }

  f3 = _mm512_movehdup_ps(f2);
  emulate_movehdup_ps(&f4, (void *)0, 0xffff, &f2, 0);
  check_equal32(&f3, &f4, (void *)0, 0xffff, "_mm512_movehdup_ps");

  f3 = _mm512_maskz_movehdup_ps(0x79fa, f2);
  emulate_movehdup_ps(&f4, (void *)0, 0x79fa, &f2, 1);
  check_equal32(&f3, &f4, (void *)0, 0xffff, "_mm512_maskz_movehdup_ps");

  f3 = _mm512_mask_movehdup_ps(f1, 0x79fa, f2);
  emulate_movehdup_ps(&f4, &f1, 0x79fa, &f2, 0);
  check_equal32(&f3, &f4, (void *)0, 0xffff, "_mm512_mask_movehdup_ps");

  if (verbose) {
    printf("DONE\n");
  }
}

int main(int argc, char *argv[]) {
  init();

  do_movedup_pd();

  do_moveldup_ps();
  do_movehdup_ps();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
