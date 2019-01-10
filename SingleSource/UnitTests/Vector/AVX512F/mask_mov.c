/*
 * Test mask_mov and maskz_mov intructions
 */

#include "m512_test_util.h"
#include <stdio.h>

__m512i i1;
__m512i i2;
__m512i i3;
__m512i i4;

__m512 f1;
__m512 f2;
__m512 f3;
__m512 f4;

__m512d d1;
__m512d d2;
__m512d d3;
__m512d d4;

volatile int vol = 0; /* To prevent optimizations */

void NOINLINE set_nonzero(void *vp, int c) {
  int i;
  V512 *v = (V512 *)vp;

  for (i = 0; i < 16; i++) {
    v->u32[i] = 10 * i * i - 3 * i + c + vol;
    if (v->u32[i] == 0) {
      v->u32[i] = 1234;
    }
  }
}

void NOINLINE check_equal32(void *vgot, void *vexpected, void *vexpected_orig,
                            int mask, char *banner) {
  int i;
  V512 *got = (V512 *)vgot;
  V512 *expected = (V512 *)vexpected;
  V512 *orig = (V512 *)vexpected_orig;

  for (i = 0; i < 16; i++) {
    int ans = (mask & (1 << i)) ? expected->s32[i] : orig->s32[i];
    if (got->s32[i] != ans) {
      printf("ERROR: %s failed -- 0x%0.8x != 0x%0.8x at element [%d]\n",
             banner ? banner : "", got->s32[i], ans, i);
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
    __int64 ans = (mask & (1 << i)) ? expected->s64[i] : orig->s64[i];
    if (got->s64[i] != ans) {
      printf("ERROR: %s failed -- %0.16" PRIx64 " != %0.16" PRIx64
             " at element [%d]\n",
             banner ? banner : "", got->s64[i], ans, i);
      n_errs++;
      break;
    }
  }
}

void NOINLINE do_mask_mov_32() {
  int k = 0xf2f3;
  __m512i zeroi = _mm512_setzero_epi32();

  set_nonzero(&i1, -97);
  set_nonzero(&i2, 22);
  set_nonzero(&i3, 22);

  i3 = _mm512_mask_mov_epi32(i1, k, i2);
  check_equal32(&i3, &i2, &i1, k, "_mm512_mask_mov_epi32");

  i4 = _mm512_maskz_mov_epi32(k, i1);
  check_equal32(&i4, &i1, &zeroi, k, "_mm512_maskz_mov_epi32");

  set_nonzero(&f1, -96);
  set_nonzero(&f2, 21);
  set_nonzero(&f3, 1400);

  f3 = _mm512_mask_mov_ps(f1, k, f2);
  check_equal32(&f3, &f2, &f1, k, "_mm512_mask_mov_ps");

  f4 = _mm512_maskz_mov_ps(k, f1);
  check_equal32(&f4, &f1, &zeroi, k, "_mm512_maskz_mov_ps");
}

void NOINLINE do_mask_mov_64() {
  __mmask8 k = 0x59;
  __m512i zeroi = _mm512_setzero_epi32();

  set_nonzero(&i1, -97);
  set_nonzero(&i2, 22);
  set_nonzero(&i3, 22);

  i3 = _mm512_mask_mov_epi64(i1, k, i2);
  check_equal64(&i3, &i2, &i1, k, "_mm512_mask_mov_epi64");

  i4 = _mm512_maskz_mov_epi64(k, i1);
  check_equal64(&i4, &i1, &zeroi, k, "_mm512_maskz_mov_epi64");

  set_nonzero(&d1, -96);
  set_nonzero(&d2, 21);
  set_nonzero(&d3, 1400);

  d3 = _mm512_mask_mov_pd(d1, k, d2);
  check_equal64(&d3, &d2, &d1, k, "_mm512_mask_mov_pd");

  d4 = _mm512_maskz_mov_pd(k, d1);
  check_equal64(&d4, &d1, &zeroi, k, "_mm512_maskz_mov_pd");
}

int main() {
  do_mask_mov_32();
  do_mask_mov_64();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
