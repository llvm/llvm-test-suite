/*
 * Test addsub and subadd instructions.
 * Here we check for _mm512_[mask|mask3]_[fmaddsub|fmsubadd]_[round]
 * intrinsics.
 */
#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

int verbose = 0;

__m512 f1;
__m512 f2;
__m512 f3;
__m512 f4;
__m512 f5;

__m512d d1;
__m512d d2;
__m512d d3;
__m512d d4;
__m512d d5;

typedef enum {
  FMA_132,
  FMA_231,
  FMA_213,
} Fma_order;

volatile int vol = 0; /* To prevent optimizations */

void NOINLINE init() {
  int i;
  V512 *pf1 = (V512 *)&f1;
  V512 *pf2 = (V512 *)&f2;
  V512 *pf3 = (V512 *)&f3;
  V512 *pd1 = (V512 *)&d1;
  V512 *pd2 = (V512 *)&d2;
  V512 *pd3 = (V512 *)&d3;

  for (i = 0; i < 16; i++) {
    pf1->f32[i] = 17 + ((i & 1) ? 1 : -1) * i + vol;
    pf2->f32[i] = -(100 + ((i & 3) == 3 ? 1 : -1) * i + vol);
    pf3->f32[i] = 400 + ((i & 1) ? -1 : 1) * i + vol;
  }

  for (i = 0; i < 8; i++) {
    pd1->f64[i] = pf1->f32[i];
    pd2->f64[i] = -pf2->f32[i];
    pd3->f64[i] = -pf3->f32[i];
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

void NOINLINE emulate_fmaddsub_ps(void *presult, const void *p1, int mask,
                                  const void *p2, const void *p3,
                                  Fma_order order) {
  int i;
  V512 *result = (V512 *)presult;
  V512 *v1 = (V512 *)p1;
  V512 *v2 = (V512 *)p2;
  V512 *v3 = (V512 *)p3;
  for (i = 0; i < 16; i++) {

    if (((1 << i) & mask) == 0) {
      result->u32[i] = v1->u32[i];
      continue;
    }

    switch (order) {
    case FMA_132:
      result->f32[i] =
          v1->f32[i] * v3->f32[i] + ((i % 2 == 0) ? -v2->f32[i] : v2->f32[i]);
      break;

    case FMA_231:
      result->f32[i] =
          v2->f32[i] * v3->f32[i] + ((i % 2 == 0) ? -v1->f32[i] : v1->f32[i]);
      break;

    case FMA_213:
      result->f32[i] =
          v2->f32[i] * v1->f32[i] + ((i % 2 == 0) ? -v3->f32[i] : v3->f32[i]);
      break;

    default:
      printf("ERROR -- bad fma order %d\n", (int)order);
      n_errs++;
      return;
    }
  }
}

void NOINLINE emulate_fmsubadd_ps(void *presult, const void *p1, int mask,
                                  const void *p2, const void *p3,
                                  Fma_order order) {
  int i;
  V512 *result = (V512 *)presult;
  V512 *v1 = (V512 *)p1;
  V512 *v2 = (V512 *)p2;
  V512 *v3 = (V512 *)p3;

  for (i = 0; i < 16; i++) {

    if (((1 << i) & mask) == 0) {
      result->u32[i] = v1->u32[i];
      continue;
    }

    switch (order) {
    case FMA_132:
      result->f32[i] =
          v1->f32[i] * v3->f32[i] + ((i % 2 == 0) ? v2->f32[i] : -v2->f32[i]);
      break;

    case FMA_231:
      result->f32[i] =
          v2->f32[i] * v3->f32[i] + ((i % 2 == 0) ? v1->f32[i] : -v1->f32[i]);
      break;

    case FMA_213:
      result->f32[i] =
          v2->f32[i] * v1->f32[i] + ((i % 2 == 0) ? v3->f32[i] : -v3->f32[i]);
      break;

    default:
      printf("ERROR -- bad fma order %d\n", (int)order);
      n_errs++;
      return;
    }
  }
}

void NOINLINE emulate_fmaddsub_pd(void *presult, const void *p1, int mask,
                                  const void *p2, const void *p3,
                                  Fma_order order) {
  int i;
  V512 *result = (V512 *)presult;
  V512 *v1 = (V512 *)p1;
  V512 *v2 = (V512 *)p2;
  V512 *v3 = (V512 *)p3;

  for (i = 0; i < 8; i++) {

    if (((1 << i) & mask) == 0) {
      result->u64[i] = v1->u64[i];
      continue;
    }

    switch (order) {
    case FMA_132:
      result->f64[i] =
          v1->f64[i] * v3->f64[i] + ((i % 2 == 0) ? -v2->f64[i] : v2->f64[i]);
      break;

    case FMA_231:
      result->f64[i] =
          v2->f64[i] * v3->f64[i] + ((i % 2 == 0) ? -v1->f64[i] : v1->f64[i]);
      break;

    case FMA_213:
      result->f64[i] =
          v2->f64[i] * v1->f64[i] + ((i % 2 == 0) ? -v3->f64[i] : v3->f64[i]);
      break;

    default:
      printf("ERROR -- bad fma order %d\n", (int)order);
      n_errs++;
      return;
    }
  }
}

void NOINLINE emulate_fmsubadd_pd(void *presult, const void *p1, int mask,
                                  const void *p2, const void *p3,
                                  Fma_order order) {
  int i;
  V512 *result = (V512 *)presult;
  V512 *v1 = (V512 *)p1;
  V512 *v2 = (V512 *)p2;
  V512 *v3 = (V512 *)p3;

  for (i = 0; i < 8; i++) {

    if (((1 << i) & mask) == 0) {
      result->u64[i] = v1->u64[i];
      continue;
    }

    switch (order) {
    case FMA_132:
      result->f64[i] =
          v1->f64[i] * v3->f64[i] + ((i % 2 == 0) ? v2->f64[i] : -v2->f64[i]);
      break;

    case FMA_231:
      result->f64[i] =
          v2->f64[i] * v3->f64[i] + ((i % 2 == 0) ? v1->f64[i] : -v1->f64[i]);
      break;

    case FMA_213:
      result->f64[i] =
          v2->f64[i] * v1->f64[i] + ((i % 2 == 0) ? v3->f64[i] : -v3->f64[i]);
      break;

    default:
      printf("ERROR -- bad fma order %d\n", (int)order);
      n_errs++;
      return;
    }
  }
}

void NOINLINE do_fmaddsub_ps() {
  f4 = _mm512_fmaddsub_ps(f1, f2, f3);
  emulate_fmaddsub_ps(&f5, &f1, 0xffff, &f3, &f2, FMA_132);
  check_equal32(&f4, &f5, (void *)0, 0xffff, "_mm512_fmaddsub_ps");

  f4 = _mm512_mask_fmaddsub_ps(f1, 0x79fa, f2, f3);
  emulate_fmaddsub_ps(&f5, &f1, 0x79fa, &f3, &f2, FMA_132);
  check_equal32(&f4, &f5, &f1, 0x79fa, "_mm512_mask_fmaddsub_ps");

  f4 = _mm512_mask3_fmaddsub_ps(f1, f2, f3, 0x563a);
  emulate_fmaddsub_ps(&f5, &f3, 0x563a, &f1, &f2, FMA_231);
  check_equal32(&f4, &f5, &f3, 0x563a, "_mm512_mask3_fmaddsub_ps");

  /*
   * Employ rounding modes.
   * Our FP inputs are all integer values, so there's no need for any
   * special emulation routine.
   */

  f4 = _mm512_fmaddsub_round_ps(f1, f2, f3,
                                _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  emulate_fmaddsub_ps(&f5, &f1, 0xffff, &f3, &f2, FMA_132);
  check_equal32(&f4, &f5, (void *)0, 0xffff, "_mm512_fmaddsub_round_ps");

  f4 = _mm512_mask_fmaddsub_round_ps(f1, 0x79fa, f2, f3,
                                     _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
  emulate_fmaddsub_ps(&f5, &f1, 0x79fa, &f3, &f2, FMA_132);
  check_equal32(&f4, &f5, &f1, 0x79fa, "_mm512_mask_fmaddsub_round_ps");

  f4 = _mm512_mask3_fmaddsub_round_ps(
      f1, f2, f3, 0x563a, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
  emulate_fmaddsub_ps(&f5, &f3, 0x563a, &f1, &f2, FMA_231);
  check_equal32(&f4, &f5, &f3, 0x563a, "_mm512_mask3_fmaddsub_round_ps");
}

void NOINLINE do_fmaddsub_pd() {
  d4 = _mm512_fmaddsub_pd(d1, d2, d3);
  emulate_fmaddsub_pd(&d5, &d1, 0xffff, &d3, &d2, FMA_132);
  check_equal64(&d4, &d5, (void *)0, 0xffff, "_mm512_fmaddsub_pd");

  d4 = _mm512_mask_fmaddsub_pd(d1, 0xfa, d2, d3);
  emulate_fmaddsub_pd(&d5, &d1, 0xfa, &d3, &d2, FMA_132);
  check_equal64(&d4, &d5, &d1, 0xfa, "_mm512_mask_fmaddsub_pd");

  d4 = _mm512_mask3_fmaddsub_pd(d1, d2, d3, 0x56);
  emulate_fmaddsub_pd(&d5, &d3, 0x56, &d1, &d2, FMA_231);
  check_equal64(&d4, &d5, &d3, 0x56, "_mm512_mask3_fmaddsub_pd");

  /*
   * Employ rounding modes.
   * Our FP inputs are all integer values, so there's no need for any
   * special emulation routine.
   */

  d4 = _mm512_fmaddsub_round_pd(d1, d2, d3,
                                _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  emulate_fmaddsub_pd(&d5, &d1, 0xffff, &d3, &d2, FMA_132);
  check_equal64(&d4, &d5, (void *)0, 0xffff, "_mm512_fmaddsub_round_pd");

  d4 = _mm512_mask_fmaddsub_round_pd(d1, 0x79, d2, d3,
                                     _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
  emulate_fmaddsub_pd(&d5, &d1, 0x79, &d3, &d2, FMA_132);
  check_equal64(&d4, &d5, &d1, 0x79, "_mm512_mask_fmaddsub_round_pd");

  d4 = _mm512_mask3_fmaddsub_round_pd(
      d1, d2, d3, 0x63, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
  emulate_fmaddsub_pd(&d5, &d3, 0x63, &d1, &d2, FMA_231);
  check_equal64(&d4, &d5, &d3, 0x63, "_mm512_mask3_fmaddsub_round_pd");
}

void NOINLINE do_fmsubadd_ps() {
  f4 = _mm512_fmsubadd_ps(f1, f2, f3);
  emulate_fmsubadd_ps(&f5, &f1, 0xffff, &f3, &f2, FMA_132);
  check_equal32(&f4, &f5, (void *)0, 0xffff, "_mm512_fmsubadd_ps");

  f4 = _mm512_mask_fmsubadd_ps(f1, 0x79fa, f2, f3);
  emulate_fmsubadd_ps(&f5, &f1, 0x79fa, &f3, &f2, FMA_132);
  check_equal32(&f4, &f5, &f1, 0x79fa, "_mm512_mask_fmsubadd_ps");

  f4 = _mm512_mask3_fmsubadd_ps(f1, f2, f3, 0x563a);
  emulate_fmsubadd_ps(&f5, &f3, 0x563a, &f1, &f2, FMA_231);
  check_equal32(&f4, &f5, &f3, 0x563a, "_mm512_mask3_fmsubadd_ps");

  /*
   * Employ rounding modes.
   * Our FP inputs are all integer values, so there's no need for any
   * special emulation routine.
   */

  f4 = _mm512_fmsubadd_round_ps(f1, f2, f3,
                                _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  emulate_fmsubadd_ps(&f5, &f1, 0xffff, &f3, &f2, FMA_132);
  check_equal32(&f4, &f5, (void *)0, 0xffff, "_mm512_fmsubadd_round_ps");

  f4 = _mm512_mask_fmsubadd_round_ps(f1, 0x79fa, f2, f3,
                                     _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
  emulate_fmsubadd_ps(&f5, &f1, 0x79fa, &f3, &f2, FMA_132);
  check_equal32(&f4, &f5, &f1, 0x79fa, "_mm512_mask_fmsubadd_round_ps");

  f4 = _mm512_mask3_fmsubadd_round_ps(
      f1, f2, f3, 0x563a, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
  emulate_fmsubadd_ps(&f5, &f3, 0x563a, &f1, &f2, FMA_231);
  check_equal32(&f4, &f5, &f3, 0x563a, "_mm512_mask3_fmsubadd_round_ps");
}

void NOINLINE do_fmsubadd_pd() {
  d4 = _mm512_fmsubadd_pd(d1, d2, d3);
  emulate_fmsubadd_pd(&d5, &d1, 0xffff, &d3, &d2, FMA_132);
  check_equal64(&d4, &d5, (void *)0, 0xffff, "_mm512_fmsubadd_pd");

  d4 = _mm512_mask_fmsubadd_pd(d1, 0xfa, d2, d3);
  emulate_fmsubadd_pd(&d5, &d1, 0xfa, &d3, &d2, FMA_132);
  check_equal64(&d4, &d5, &d1, 0xfa, "_mm512_mask_fmsubadd_pd");

  d4 = _mm512_mask3_fmsubadd_pd(d1, d2, d3, 0x56);
  emulate_fmsubadd_pd(&d5, &d3, 0x56, &d1, &d2, FMA_231);
  check_equal64(&d4, &d5, &d3, 0x56, "_mm512_mask3_fmsubadd_pd");

  /*
   * Employ rounding modes.
   * Our FP inputs are all integer values, so there's no need for any
   * special emulation routine.
   */

  d4 = _mm512_fmsubadd_round_pd(d1, d2, d3,
                                _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  emulate_fmsubadd_pd(&d5, &d1, 0xffff, &d3, &d2, FMA_132);
  check_equal64(&d4, &d5, (void *)0, 0xffff, "_mm512_fmsubadd_round_pd");

  d4 = _mm512_mask_fmsubadd_round_pd(d1, 0x79, d2, d3,
                                     _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
  emulate_fmsubadd_pd(&d5, &d1, 0x79, &d3, &d2, FMA_132);
  check_equal64(&d4, &d5, &d1, 0x79, "_mm512_mask_fmsubadd_round_pd");

  d4 = _mm512_mask3_fmsubadd_round_pd(
      d1, d2, d3, 0x63, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
  emulate_fmsubadd_pd(&d5, &d3, 0x63, &d1, &d2, FMA_231);
  check_equal64(&d4, &d5, &d3, 0x63, "_mm512_mask3_fmsubadd_round_pd");
}

int main(int argc, char *argv[]) {
  if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'v' &&
      argv[1][2] == '\0') {
    verbose = 1;
  }

  init();

  do_fmaddsub_ps();
  do_fmaddsub_pd();

  do_fmsubadd_ps();
  do_fmsubadd_pd();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
