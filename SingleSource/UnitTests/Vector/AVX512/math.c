/*
 * Test math instructions: sqrt, reciprocal, floor, ceil, exponent,
 *                          scale, fixup ,roundscale and ternary logic.
 * Here we check for _mm512_[mask|maskz]_[ceil|floor|scalef|sqrt|ternarylogic]
 * intrinsics.
 */
#include "m512_test_util.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

volatile int vol0 = 0;

V512 i32;
V512 i32_squares;
V512 i32_neg;
V512 i64;
V512 i64_squares;
V512 i64_neg;
V512 f32;
V512 f32_squares;
V512 f32_halves;
V512 f64;
V512 f64_squares;
V512 f64_halves;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 16; i++) {
    i32.s32[i] = i;
    i32_squares.s32[i] = i * i;
    i32_neg.s32[i] = -i;
    f32.f32[i] = i;
    f32_squares.f32[i] = i * i;
    f32_halves.f32[i] = i + 0.5f;
  }

  for (i = 0; i < 8; i++) {
    i64.s64[i] = i;
    i64_squares.s64[i] = i * i;
    i64_neg.s64[i] = -i;
    f64.f64[i] = i;
    f64_squares.f64[i] = i * i;
    f64_halves.f64[i] = i + 0.5;
  }
}

void NOINLINE do_rcp14pd() {
  volatile V512 res;
  V512 expected;
  __mmask8 k = 0xc3;

  res.zmmd = _mm512_rcp14_pd(f64.zmmd);

  res.zmmi = _mm512_setzero_epi32();
  res.zmmd = _mm512_mask_rcp14_pd(res.zmmd, k, f64.zmmd);
}

void NOINLINE do_rcp14ps() {
  volatile V512 res;
  V512 expected;
  __mmask16 k = 0x7e95;

  res.zmm = _mm512_rcp14_ps(f32.zmm);

  res.zmmi = _mm512_setzero_epi32();
  res.zmm = _mm512_mask_rcp14_ps(res.zmm, k, f32.zmm);
}

void NOINLINE do_sqrtps() {
  V512 res;
  V512 expected;
  __mmask16 k;
  volatile int i;

  res.zmm = _mm512_sqrt_ps(f32_squares.zmm);
  for (i = 0; i < 16; i++) {
    expected.f32[i] = i;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_sqrt_ps", __LINE__);

  f32_squares.xmm[vol0] = f32_squares.xmm[vol0]; /* No-op. */

  k = 0xbcdf;
  res.zmm = _mm512_setzero_ps();
  res.zmm = _mm512_mask_sqrt_ps(res.zmm, k, f32_squares.zmm);
  expected.zmm = _mm512_setzero_ps();
  for (i = 0; i < 16; i++) {
    if (k & (1 << i)) {
      expected.f32[i] = i;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_sqrt_ps", __LINE__);
}

void NOINLINE do_sqrtpd() {
  V512 res;
  V512 expected;
  __mmask8 k;
  volatile int i;

  res.zmmd = _mm512_sqrt_pd(f64_squares.zmmd);
  for (i = 0; i < 8; i++) {
    expected.f64[i] = i;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_sqrt_pd", __LINE__);

  f64_squares.xmmd[vol0] = f64_squares.xmmd[vol0]; /* No-op. */

  k = 0xe9;
  res.zmmd = _mm512_setzero_pd();
  res.zmmd = _mm512_mask_sqrt_pd(res.zmmd, k, f64_squares.zmmd);
  expected.zmmd = _mm512_setzero_pd();
  for (i = 0; i < 8; i++) {
    if (k & (1 << i)) {
      expected.f64[i] = i;
    }
  }

  check_equal_nd(&res, &expected, 16, "_mm512_mask_sqrt_pd", __LINE__);
}

void NOINLINE do_floorps() {
  V512 res;
  V512 expected;
  __mmask16 k;
  volatile int i;

  res.zmm = _mm512_floor_ps(f32_halves.zmm);
  for (i = 0; i < 16; i++) {
    expected.f32[i] = i;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_floor_ps", __LINE__);

  f32_halves.xmm[vol0] = f32_halves.xmm[vol0]; /* No-op. */

  k = 0xbcdf;
  res.zmm = _mm512_setzero_ps();
  res.zmm = _mm512_mask_floor_ps(res.zmm, k, f32_halves.zmm);
  expected.zmm = _mm512_setzero_ps();
  for (i = 0; i < 16; i++) {
    if (k & (1 << i)) {
      expected.f32[i] = i;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_floor_ps", __LINE__);
}

void NOINLINE do_floorpd() {
  V512 res;
  V512 expected;
  __mmask8 k;
  volatile int i;

  res.zmmd = _mm512_floor_pd(f64_halves.zmmd);
  for (i = 0; i < 8; i++) {
    expected.f64[i] = i;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_floor_pd", __LINE__);

  f64_halves.xmmd[vol0] = f64_halves.xmmd[vol0]; /* No-op. */

  k = 0x7b;
  res.zmmd = _mm512_setzero_pd();
  res.zmmd = _mm512_mask_floor_pd(res.zmmd, k, f64_halves.zmmd);
  expected.zmmd = _mm512_setzero_pd();
  for (i = 0; i < 8; i++) {
    if (k & (1 << i)) {
      expected.f64[i] = i;
    }
  }

  check_equal_nd(&res, &expected, 16, "_mm512_mask_floor_pd", __LINE__);
}

void NOINLINE do_ceilps() {
  V512 res;
  V512 expected;
  __mmask16 k;
  volatile int i;

  res.zmm = _mm512_ceil_ps(f32_halves.zmm);
  for (i = 0; i < 16; i++) {
    expected.f32[i] = i + 1;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_ceil_ps", __LINE__);

  f32_halves.xmm[vol0] = f32_halves.xmm[vol0]; /* No-op. */

  k = 0xbcdf;
  res.zmm = _mm512_setzero_ps();
  res.zmm = _mm512_mask_ceil_ps(res.zmm, k, f32_halves.zmm);
  expected.zmm = _mm512_setzero_ps();
  for (i = 0; i < 16; i++) {
    if (k & (1 << i)) {
      expected.f32[i] = i + 1;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_ceil_ps", __LINE__);
}

void NOINLINE do_ceilpd() {
  V512 res;
  V512 expected;
  __mmask8 k;
  volatile int i;

  res.zmmd = _mm512_ceil_pd(f64_halves.zmmd);
  for (i = 0; i < 8; i++) {
    expected.f64[i] = i + 1;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_ceil_pd", __LINE__);

  f64_halves.xmmd[vol0] = f64_halves.xmmd[vol0]; /* No-op. */

  k = 0x7b;
  res.zmmd = _mm512_setzero_pd();
  res.zmmd = _mm512_mask_ceil_pd(res.zmmd, k, f64_halves.zmmd);
  expected.zmmd = _mm512_setzero_pd();
  for (i = 0; i < 8; i++) {
    if (k & (1 << i)) {
      expected.f64[i] = i + 1;
    }
  }

  check_equal_nd(&res, &expected, 16, "_mm512_mask_ceil_pd", __LINE__);
}

void NOINLINE do_getexpsd() {
  __mmask8 k8 = 0x2;
  volatile __m128d res;
  volatile __m128d v1 = _mm_set_pd(8.0, 32.0);
  volatile __m128d v2 = _mm_set_pd(16.0, 64.0);

  __m128d res_exp_nomask = _mm_set_pd(8.0, 6.0);
  __m128d res_exp_mask = _mm_set_pd(8.0, 32.0);
  __m128d res_exp_maskz = _mm_set_pd(8.0, 0.0);

  res = _mm_setzero_pd();
  res = _mm_getexp_sd(v1, v2);

  check_equal_ndf((void *)&res, (void *)&res_exp_nomask, 2, "_mm_getexp_sd",
                  __LINE__);

  res = _mm_setzero_pd();
  res = _mm_mask_getexp_sd(v1, k8, v1, v2);
  check_equal_ndf((void *)&res, (void *)&res_exp_mask, 2, "_mm_mask_getexp_sd",
                  __LINE__);

  res = _mm_setzero_pd();
  res = _mm_maskz_getexp_sd(k8, v1, v2);
  check_equal_ndf((void *)&res, (void *)&res_exp_maskz, 2,
                  "_mm_maskz_getexp_sd", __LINE__);
}

void NOINLINE do_getexpss() {
  __mmask8 k8 = 0xe;
  volatile __m128 res;
  volatile __m128 v1 = _mm_set_ps(16.0f, 32.0f, 64.0f, 128.0f);
  volatile __m128 v2 = _mm_set_ps(128.0f, 256.0f, 512.0f, 1024.0f);

  volatile __m128 res_exp_nomask = _mm_set_ps(16.0f, 32.0f, 64.0f, 10.0f);
  volatile __m128 res_exp_mask = _mm_set_ps(16.0f, 32.0f, 64.0f, 128.0f);
  volatile __m128 res_exp_maskz = _mm_set_ps(16.0f, 32.0f, 64.0f, 0.0f);

  res = _mm_setzero_ps();
  res = _mm_getexp_ss(v1, v2);
  check_equal_nsf((void *)&res, (void *)&res_exp_nomask, 4, "_mm_getexp_ss",
                  __LINE__);

  res = _mm_setzero_ps();
  res = _mm_mask_getexp_ss(v1, k8, v1, v2);
  check_equal_nsf((void *)&res, (void *)&res_exp_mask, 2, "_mm_mask_getexp_ss",
                  __LINE__);

  res = _mm_setzero_ps();
  res = _mm_maskz_getexp_ss(k8, v1, v2);
  check_equal_nsf((void *)&res, (void *)&res_exp_maskz, 4,
                  "_mm_maskz_getexp_ss", __LINE__);
}

void NOINLINE do_getmantpd() {
  volatile V512 res;
  V512 expected;
  __mmask8 k = 0x75;

  res.zmmd =
      _mm512_getmant_pd(f64.zmmd, _MM_MANT_NORM_p5_1, _MM_MANT_SIGN_zero);

  res.zmmi = _mm512_setzero_epi32();
  res.zmmd = _mm512_mask_getmant_pd(res.zmmd, k, f64.zmmd, _MM_MANT_NORM_p5_2,
                                    _MM_MANT_SIGN_zero);
}

void NOINLINE do_getmantps() {
  volatile V512 res;
  V512 expected;
  __mmask16 k = 0x7e95;

  res.zmm = _mm512_getmant_ps(f32.zmm, _MM_MANT_NORM_p5_1, _MM_MANT_SIGN_zero);

  res.zmmi = _mm512_setzero_epi32();
  res.zmm = _mm512_mask_getmant_ps(res.zmm, k, f32.zmm, _MM_MANT_NORM_p5_2,
                                   _MM_MANT_SIGN_zero);
}

#define CHECK_SCALEFPD(n_elems, dest, mask, zeroing, name)                     \
  {                                                                            \
    volatile int i;                                                            \
    for (i = 0; i < n_elems; i++) {                                            \
      expected.f64[i] = f64.f64[i] * (pow(2.0, floor(f64_squares.f64[i])));    \
      if ((mask & (1 << i)) == 0) {                                            \
        if (zeroing) {                                                         \
          expected.f64[i] = 0.0;                                               \
        } else {                                                               \
          expected.f64[i] = dest.f64[i];                                       \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_elems * 2, name, __LINE__);              \
    f64.xmmd[vol0] = f64.xmmd[vol0];                                           \
  }

void NOINLINE do_scalefpd() {
  V512 res;
  V512 expected;
  __mmask8 k = 0xFF;

  res.zmmd = _mm512_scalef_round_pd(f64.zmmd, f64_squares.zmmd,
                                    _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
  CHECK_SCALEFPD(8, f64_halves, k, 0, "_mm512_scalef_round_pd");

  res.zmmd = _mm512_scalef_pd(f64.zmmd, f64_squares.zmmd);
  CHECK_SCALEFPD(8, f64_halves, k, 0, "_mm512_scalef_pd");

  k = 0x75;

  res.zmmd = _mm512_mask_scalef_round_pd(
      f64_halves.zmmd, k, f64.zmmd, f64_squares.zmmd,
      _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
  CHECK_SCALEFPD(8, f64_halves, k, 0, "_mm512_mask_scalef_round_pd");

  res.zmmd =
      _mm512_mask_scalef_pd(f64_halves.zmmd, k, f64.zmmd, f64_squares.zmmd);
  CHECK_SCALEFPD(8, f64_halves, k, 0, "_mm512_mask_scalef_pd");

  k = 0x57;

  res.zmmd = _mm512_maskz_scalef_round_pd(
      k, f64.zmmd, f64_squares.zmmd, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
  CHECK_SCALEFPD(8, f64_halves, k, 1, "_mm512_maskz_scalef_round_pd");

  res.zmmd = _mm512_maskz_scalef_pd(k, f64.zmmd, f64_squares.zmmd);
  CHECK_SCALEFPD(8, f64_halves, k, 1, "_mm512_maskz_scalef_pd");
}

#define CHECK_SCALEFPS(n_elems, dest, mask, zeroing, name)                     \
  {                                                                            \
    volatile int i;                                                            \
    for (i = 0; i < n_elems; i++) {                                            \
      expected.f32[i] = f32.f32[i] * (powf(2.0F, floorf(f32_squares.f32[i]))); \
      if ((mask & (1 << i)) == 0) {                                            \
        if (zeroing) {                                                         \
          expected.f32[i] = 0.0F;                                              \
        } else {                                                               \
          expected.f32[i] = dest.f32[i];                                       \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_elems, name, __LINE__);                  \
    f32.xmm[vol0] = f32.xmm[vol0];                                             \
  }

void NOINLINE do_scalefps() {
  V512 res;
  V512 expected;
  __mmask16 k = 0xFFFF;

  res.zmm = _mm512_scalef_round_ps(f32.zmm, f32_squares.zmm,
                                   _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
  CHECK_SCALEFPS(16, f32_halves, k, 0, "_mm512_scalef_round_ps");

  res.zmm = _mm512_scalef_ps(f32.zmm, f32_squares.zmm);
  CHECK_SCALEFPS(16, f32_halves, k, 0, "_mm512_scalef_ps");

  k = 0x0bcd;

  res.zmm =
      _mm512_mask_scalef_round_ps(f32_halves.zmm, k, f32.zmm, f32_squares.zmm,
                                  _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
  CHECK_SCALEFPS(16, f32_halves, k, 0, "_mm512_mask_scalef_round_ps");

  res.zmm = _mm512_mask_scalef_ps(f32_halves.zmm, k, f32.zmm, f32_squares.zmm);
  CHECK_SCALEFPS(16, f32_halves, k, 0, "_mm512_mask_scalef_ps");

  k = 0x0dcb;

  res.zmm = _mm512_maskz_scalef_round_ps(
      k, f32.zmm, f32_squares.zmm, _MM_FROUND_TO_NEG_INF | _MM_FROUND_NO_EXC);
  CHECK_SCALEFPS(16, f32_halves, k, 1, "_mm512_maskz_scalef_round_ps");

  res.zmm = _mm512_maskz_scalef_ps(k, f32.zmm, f32_squares.zmm);
  CHECK_SCALEFPS(16, f32_halves, k, 1, "_mm512_maskz_scalef_ps");
}

#define SOME_ROUND (_MM_FROUND_CUR_DIRECTION)

void NOINLINE do_fixupimmpd() {
  volatile V512 res;
  V512 expected;
  __mmask8 k = 0x75;

  res.zmmd = _mm512_fixupimm_pd(f64.zmmd, f64_squares.zmmd, i32.zmmi, 0x97);

  res.zmmi = _mm512_setzero_epi32();
  res.zmmd = _mm512_mask_fixupimm_pd(res.zmmd, k, f64.zmmd, i32.zmmi, 0xfe);

  res.zmmi = _mm512_setzero_epi32();
  res.zmmd = _mm512_maskz_fixupimm_pd(k, res.zmmd, f64.zmmd, i32.zmmi, 0xfe);

  res.zmmd = _mm512_fixupimm_round_pd(f64.zmmd, f64_squares.zmmd, i32.zmmi,
                                      0x97, SOME_ROUND);

  res.zmmi = _mm512_setzero_epi32();
  res.zmmd = _mm512_mask_fixupimm_round_pd(res.zmmd, k, f64.zmmd, i32.zmmi,
                                           0xfe, SOME_ROUND);

  res.zmmi = _mm512_setzero_epi32();
  res.zmmd = _mm512_maskz_fixupimm_round_pd(k, res.zmmd, f64.zmmd, i32.zmmi,
                                            0xfe, SOME_ROUND);
}

void NOINLINE do_fixupimmps() {
  volatile V512 res;
  V512 expected;
  __mmask16 k = 0x75;

  res.zmm = _mm512_fixupimm_ps(f32.zmm, f32_squares.zmm, i32.zmmi, 0x97);

  res.zmmi = _mm512_setzero_epi32();
  res.zmm = _mm512_mask_fixupimm_ps(res.zmm, k, f32.zmm, i32.zmmi, 0xfe);

  res.zmmi = _mm512_setzero_epi32();
  res.zmm = _mm512_maskz_fixupimm_ps(k, res.zmm, f32.zmm, i32.zmmi, 0xfe);

  res.zmm = _mm512_fixupimm_round_ps(f32.zmm, f32_squares.zmm, i32.zmmi, 0x97,
                                     SOME_ROUND);

  res.zmmi = _mm512_setzero_epi32();
  res.zmm = _mm512_mask_fixupimm_round_ps(res.zmm, k, f32.zmm, i32.zmmi, 0xfe,
                                          SOME_ROUND);

  res.zmmi = _mm512_setzero_epi32();
  res.zmm = _mm512_maskz_fixupimm_round_ps(k, res.zmm, f32.zmm, i32.zmmi, 0xfe,
                                           SOME_ROUND);
}

void NOINLINE do_fixupimmsd() {
  volatile V512 res;
  V512 expected;

  __mmask8 k = 0x75;

  res.xmmd[0] =
      _mm_fixupimm_sd(f64.xmmd[0], f64_squares.xmmd[0], i32.xmmi[0], 0x97);

  res.xmmi[0] = _mm_setzero_si128();
  res.xmmd[0] =
      _mm_mask_fixupimm_sd(res.xmmd[0], k, f64.xmmd[0], i32.xmmi[0], 0xfe);

  res.xmmi[0] = _mm_setzero_si128();
  res.xmmd[0] =
      _mm_maskz_fixupimm_sd(k, res.xmmd[0], f64.xmmd[0], i32.xmmi[0], 0xfe);

  res.xmmd[0] = _mm_fixupimm_round_sd(f64.xmmd[0], f64_squares.xmmd[0],
                                      i32.xmmi[0], 0x97, SOME_ROUND);

  res.xmmi[0] = _mm_setzero_si128();
  res.xmmd[0] = _mm_mask_fixupimm_round_sd(res.xmmd[0], k, f64.xmmd[0],
                                           i32.xmmi[0], 0xfe, SOME_ROUND);

  res.xmmi[0] = _mm_setzero_si128();
  res.xmmd[0] = _mm_maskz_fixupimm_round_sd(k, res.xmmd[0], f64.xmmd[0],
                                            i32.xmmi[0], 0xfe, SOME_ROUND);
}

void NOINLINE do_fixupimmss() {
  volatile V512 res;
  V512 expected;
  __mmask8 k = 0x75;

  res.xmm[0] =
      _mm_fixupimm_ss(f32.xmm[0], f32_squares.xmm[0], i32.xmmi[0], 0x97);

  res.xmmi[0] = _mm_setzero_si128();
  res.xmm[0] =
      _mm_mask_fixupimm_ss(res.xmm[0], k, f32.xmm[0], i32.xmmi[0], 0xfe);

  res.xmmi[0] = _mm_setzero_si128();
  res.xmm[0] =
      _mm_maskz_fixupimm_ss(k, res.xmm[0], f32.xmm[0], i32.xmmi[0], 0xfe);

  res.xmm[0] = _mm_fixupimm_round_ss(f64.xmm[0], f64_squares.xmm[0],
                                     i32.xmmi[0], 0x97, SOME_ROUND);

  res.xmmi[0] = _mm_setzero_si128();
  res.xmm[0] = _mm_mask_fixupimm_round_ss(res.xmm[0], k, f64.xmm[0],
                                          i32.xmmi[0], 0xfe, SOME_ROUND);

  res.xmmi[0] = _mm_setzero_si128();
  res.xmm[0] = _mm_maskz_fixupimm_round_ss(k, res.xmm[0], f64.xmm[0],
                                           i32.xmmi[0], 0xfe, SOME_ROUND);
}

void NOINLINE do_roundscalepd() {
  volatile V512 res;
  V512 expected;
  __mmask16 k = 0x3d;

  res.zmmd = _mm512_roundscale_pd(f64.zmmd, 0xff);

  res.zmmi = _mm512_setzero_epi32();
  res.zmmd = _mm512_mask_roundscale_pd(res.zmmd, k, f64.zmmd, 0x36);
}

void NOINLINE do_roundscaleps() {
  volatile V512 res;
  V512 expected;
  __mmask16 k = 0x74cb;

  res.zmm = _mm512_roundscale_ps(f32.zmm, 0xf7);

  res.zmmi = _mm512_setzero_epi32();
  res.zmm = _mm512_mask_roundscale_ps(res.zmm, k, f32.zmm, 0x36);
}

static int NOINLINE emulate_ternarylogicd(int a, int b, int c, int imm) {
  int i, index, res = 0;

  for (i = 0; i < 32; i++) {
    index = ((a & 1) << 2) | ((b & 1) << 1) | (c & 1);
    res |= ((imm & (1 << index)) ? 1 : 0) << i;
    a >>= 1;
    b >>= 1;
    c >>= 1;
  }

  return res;
}

void NOINLINE do_pternlogq() {
  volatile int i;
  V512 res, resx, resy;
  V512 expected;
  __mmask8 k8 = 0x75;

  res.zmmi =
      _mm512_ternarylogic_epi64(i64.zmmi, i64_squares.zmmi, i64.zmmi, 0x79);
  for (i = 0; i < 16; i++) {
    expected.s32[i] =
        emulate_ternarylogicd(i64.s32[i], i64_squares.s32[i], i64.s32[i], 0x79);
  }
  check_equal_nd(&res, &expected, 16, "_mm512_ternarylogic_epi64", __LINE__);

  i64.xmm[vol0] = i64.xmm[vol0]; /* No-op. */

  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_ternarylogic_epi64(res.zmmi, k8, i64_neg.zmmi,
                                            i64.zmmi, 0xca);
  for (i = 0; i < 16; i += 2) {
    if (k8 & (1 << (i / 2))) {
      expected.s32[i] =
          emulate_ternarylogicd(0, i64_neg.s32[i], i64.s32[i], 0xca);
      expected.s32[i + 1] =
          emulate_ternarylogicd(0, i64_neg.s32[i + 1], i64.s32[i + 1], 0xca);
    } else {
      expected.s32[i] = 0;
      expected.s32[i + 1] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_ternarylogic_epi64",
                 __LINE__);

  i64.xmm[vol0] = i64.xmm[vol0]; /* No-op. */

  res.zmmi = _mm512_maskz_ternarylogic_epi64(k8, i64_squares.zmmi,
                                             i64_squares.zmmi, i64.zmmi, 0x3b);
  for (i = 0; i < 16; i += 2) {
    if (k8 & (1 << (i / 2))) {
      expected.s32[i] = emulate_ternarylogicd(
          i64_squares.s32[i], i64_squares.s32[i], i64.s32[i], 0x3b);
      expected.s32[i + 1] = emulate_ternarylogicd(
          i64_squares.s32[i + 1], i64_squares.s32[i + 1], i64.s32[i], 0x3b);
    } else {
      expected.s32[i] = 0;
      expected.s32[i + 1] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_ternarylogic_epi64",
                 __LINE__);
}

void NOINLINE do_pternlogd() {
  volatile int i;
  V512 res, resx, resy;
  V512 expected;
  __mmask16 k = 0x23bc;
  __mmask8 k8 = (__mmask8)k;

  res.zmmi =
      _mm512_ternarylogic_epi32(i32.zmmi, i32_squares.zmmi, i32.zmmi, 0x97);
  for (i = 0; i < 16; i++) {
    expected.s32[i] =
        emulate_ternarylogicd(i32.s32[i], i32_squares.s32[i], i32.s32[i], 0x97);
  }
  check_equal_nd(&res, &expected, 16, "_mm512_ternarylogic_epi32", __LINE__);

  i32.xmm[vol0] = i32.xmm[vol0]; /* No-op. */

  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_ternarylogic_epi32(res.zmmi, k, i32_squares.zmmi,
                                            i32.zmmi, 0xfe);
  for (i = 0; i < 16; i++) {
    if (k & (1 << i)) {
      expected.s32[i] =
          emulate_ternarylogicd(0, i32_squares.s32[i], i32.s32[i], 0xfe);
    } else {
      expected.s32[i] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_ternarylogic_epi32",
                 __LINE__);

  i32.xmm[vol0] = i32.xmm[vol0]; /* No-op. */

  k = 0xabcd;
  k8 = (__mmask8)k;
  res.zmmi = _mm512_maskz_ternarylogic_epi32(k, i32_squares.zmmi, i32_neg.zmmi,
                                             i32.zmmi, 0x3b);
  for (i = 0; i < 16; i++) {
    if (k & (1 << i)) {
      expected.s32[i] = emulate_ternarylogicd(i32_squares.s32[i],
                                              i32_neg.s32[i], i32.s32[i], 0x3b);
    } else {
      expected.s32[i] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_ternarylogic_epi32",
                 __LINE__);
}

int main(int argc, char *argv[]) {
  init();

  do_rcp14pd();
  do_rcp14ps();

  do_sqrtps();
  do_sqrtpd();

  do_floorps();
  do_floorpd();

  do_ceilps();
  do_ceilpd();

  do_getexpsd();
  do_getexpss();

  do_getmantpd();
  do_getmantps();

  do_scalefpd();
  do_scalefps();

  do_fixupimmpd();
  do_fixupimmps();

  do_fixupimmsd();
  do_fixupimmss();

  do_roundscalepd();
  do_roundscaleps();

  do_pternlogq();
  do_pternlogd();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
