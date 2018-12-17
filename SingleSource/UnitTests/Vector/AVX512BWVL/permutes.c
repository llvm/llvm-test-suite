/*
 * Test pertumes and shuffle intrinsics.
 * This test was created to check the correctness
 * of the following intrinsics support:
 * _mm*_permute*_pd()
 * _mm*_shuffle_epi8()
 */

#include "m512_test_util.h"

volatile int vol0 = 0;

V512 i8;
V512 i8_mix;
V512 i8_big;
V512 i16;
V512 i16_mix;
V512 i16_big;
V512 i32;
V512 i32_mix;
V512 i32_big;
V512 i64;
V512 i64_mix;
V512 i64_big;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 64; i++) {
    i8.s8[i] = i;
    i8_mix.s8[i] = (i & 1) ? i : -i;
    i8_big.s8[i] = 1000 * (i + 1);
  }

  for (i = 0; i < 32; i++) {
    i16.s16[i] = i;
    i16_mix.s16[i] = (i & 1) ? i : -i;
    i16_big.s16[i] = 1000 * (i + 1);
    if ((i & 1) != 0) {
      i16_big.s16[i] = -i16_big.s16[i];
    }
  }

  for (i = 0; i < 16; i++) {
    i32.s32[i] = i;
    i32_mix.s32[i] = (i & 1) ? i : -i;
    i32_big.s32[i] = 1000 * (i + 1);
    if ((i & 1) != 0) {
      i32_big.s32[i] = -i32_big.s32[i];
    }
  }

  for (i = 0; i < 8; i++) {
    i64.s64[i] = i;
    i64_mix.s64[i] = (i & 1) ? i : -i;
    i64_big.s64[i] = 1000 * (i + 1);
    if ((i & 1) != 0) {
      i64_big.s64[i] = -i64_big.s64[i];
    }
  }
}

#define CHECK_PSHUFB(n_elems, dest, mask, zeroing, name)                       \
  {                                                                            \
    int i, lane;                                                               \
    for (i = 0; i < n_elems; i++) {                                            \
      expected.s8[i] = 0;                                                      \
      if (i8_mix.s8[i] >= 0) {                                                 \
        lane = i / 16;                                                         \
        expected.s8[i] = i8.s8[16 * lane + (i8_mix.s8[i] & 0xf)];              \
      }                                                                        \
      if ((mask & (1LL << i)) == 0) {                                          \
        if (zeroing) {                                                         \
          expected.s8[i] = 0;                                                  \
        } else {                                                               \
          expected.s8[i] = dest.s8[i];                                         \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_elems / 4, name, __LINE__);              \
    i8_mix.xmmi[vol0] = i8_mix.xmmi[vol0];                                     \
  }

void NOINLINE do_pshufb() {
  V512 res;
  V512 expected;
  __mmask64 k64 = 0xFFFFFFFFFFFFFFFFLL;

  /* Non-masked versions. */
  res.xmmi[vol0] = _mm_shuffle_epi8(i8.xmmi[vol0], i8_mix.xmmi[vol0]);
  CHECK_PSHUFB(16, i8_big, k64, 0, "_mm_shuffle_epi8");

  res.ymmi[vol0] = _mm256_shuffle_epi8(i8.ymmi[vol0], i8_mix.ymmi[vol0]);
  CHECK_PSHUFB(32, i8_big, k64, 0, "_mm256_shuffle_epi8");

  res.zmmi = _mm512_shuffle_epi8(i8.zmmi, i8_mix.zmmi);
  CHECK_PSHUFB(64, i8_big, k64, 0, "_mm512_shuffle_epi8");

  /* Masked versions. */
  k64 = 0xA4A4A4A4A4A4A4A4LL;
  res.xmmi[vol0] = _mm_mask_shuffle_epi8(i8_big.xmmi[vol0], k64, i8.xmmi[vol0],
                                         i8_mix.xmmi[vol0]);
  CHECK_PSHUFB(16, i8_big, k64, 0, "_mm_mask_shuffle_epi8");

  res.ymmi[vol0] = _mm256_mask_shuffle_epi8(i8_big.ymmi[vol0], k64,
                                            i8.ymmi[vol0], i8_mix.ymmi[vol0]);
  CHECK_PSHUFB(32, i8_big, k64, 0, "_mm256_mask_shuffle_epi8");

  res.zmmi = _mm512_mask_shuffle_epi8(i8_big.zmmi, k64, i8.zmmi, i8_mix.zmmi);
  CHECK_PSHUFB(64, i8_big, k64, 0, "_mm512_mask_shuffle_epi8");

  /* Zero-masked versions. */
  k64 = 0x4A4A4A4A4A4A4A4ALL;
  res.xmmi[vol0] =
      _mm_maskz_shuffle_epi8(k64, i8.xmmi[vol0], i8_mix.xmmi[vol0]);
  CHECK_PSHUFB(16, i8_big, k64, 1, "_mm_maskz_shuffle_epi8");

  res.ymmi[vol0] =
      _mm256_maskz_shuffle_epi8(k64, i8.ymmi[vol0], i8_mix.ymmi[vol0]);
  CHECK_PSHUFB(32, i8_big, k64, 1, "_mm256_maskz_shuffle_epi8");

  res.zmmi = _mm512_maskz_shuffle_epi8(k64, i8.zmmi, i8_mix.zmmi);
  CHECK_PSHUFB(64, i8_big, k64, 1, "_mm512_maskz_shuffle_epi8");
}

void NOINLINE do_perm_epi32() {
  __mmask16 k;

  volatile __m512i v1 =
      _mm512_set_epi32(15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
  volatile __m512i v2 =
      _mm512_set_epi32(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  __m512i z1 = v1;
  __m512i z2 = v2;
  __m512i z3;
  __m512i e1;
  volatile __m256i y1 = _mm256_set_epi32(7, 6, 5, 4, 3, 2, 1, 0);
  volatile __m256i y2 = _mm256_set_epi32(0, 1, 2, 3, 4, 5, 6, 7);
  __m256i y3;
  __m256i e2;

  z3 = _mm512_permutexvar_epi32(z2, z1);
  check_equal_nd(&z3, &z2, 16, "_mm512_permutexvar_epi32", __LINE__);

  k = 0xa97e;

  y3 = y1;
  y3 = _mm256_mask_permutexvar_epi32(y3, k, y2, y1);
  e2 = _mm256_set_epi32(7, 1, 2, 3, 4, 5, 6, 0);
  check_equal_nd(&y3, &e2, 8, "_mm256_mask_permutexvar_epi32", __LINE__);

  z3 = v1;
  z3 = _mm512_mask_permutexvar_epi32(z3, k, z2, z1);
  e1 = _mm512_set_epi32(0, 14, 2, 12, 4, 10, 9, 7, 7, 9, 10, 11, 12, 13, 14, 0);
  check_equal_nd(&z3, &e1, 16, "_mm512_mask_permutexvar_epi32", __LINE__);

  y3 = _mm256_maskz_permutexvar_epi32(k, y2, y1);
  e2 = _mm256_set_epi32(0, 1, 2, 3, 4, 5, 6, 0);
  check_equal_nd(&y3, &e2, 8, "_mm256_maskz_permutexvar_epi32", __LINE__);

  z3 = _mm512_maskz_permutexvar_epi32(k, z2, z1);
  e1 = _mm512_set_epi32(0, 0, 2, 0, 4, 0, 0, 7, 0, 9, 10, 11, 12, 13, 14, 0);
  check_equal_nd(&z3, &e1, 16, "_mm512_maskz_permutexvar_epi32", __LINE__);
}

void NOINLINE do_perm_ps() {
  __mmask16 k;

  volatile __m512i v1 =
      _mm512_set_epi32(15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
  volatile __m512i v2 =
      _mm512_set_epi32(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
  __m512 z1 = _mm512_castsi512_ps(v1);
  __m512i z2 = v2;
  __m512 z3;
  __m512i e1;
  volatile __m256 y1 =
      _mm256_castsi256_ps(_mm256_set_epi32(7, 6, 5, 4, 3, 2, 1, 0));
  volatile __m256i y2 = _mm256_set_epi32(0, 1, 2, 3, 4, 5, 6, 7);
  __m256 y3, e2;

  y3 = _mm256_permutevar8x32_ps(y1, y2);
  e2 = _mm256_castsi256_ps(y2);
  check_equal_nd(&y3, &e2, 8, "_mm256_permutevar8x32_ps", __LINE__);

  y3 = _mm256_permutexvar_ps(y2, y1);
  e2 = _mm256_castsi256_ps(y2);
  check_equal_nd(&y3, &e2, 8, "_mm256_permutexvar_ps", __LINE__);

  z3 = _mm512_permutexvar_ps(z2, z1);
  check_equal_nd(&z3, &z2, 16, "_mm512_permutexvar_ps", __LINE__);

  k = 0xa97e;
  y3 = y1;
  y3 = _mm256_mask_permutexvar_ps(y3, k, y2, y1);
  e2 = _mm256_castsi256_ps(_mm256_set_epi32(7, 1, 2, 3, 4, 5, 6, 0));
  check_equal_nd(&y3, &e2, 8, "_mm256_mask_permutexvar_ps", __LINE__);

  k = 0xa97e;
  z3 = _mm512_castsi512_ps(v1);
  z3 = _mm512_mask_permutexvar_ps(z3, k, z2, z1);
  e1 = _mm512_set_epi32(0, 14, 2, 12, 4, 10, 9, 7, 7, 9, 10, 11, 12, 13, 14, 0);
  check_equal_nd(&z3, &e1, 16, "_mm512_mask_permutexvar_ps", __LINE__);

  k = 0xa97e;
  y3 = y1;
  y3 = _mm256_maskz_permutexvar_ps(k, y2, y1);
  e2 = _mm256_castsi256_ps(_mm256_set_epi32(0, 1, 2, 3, 4, 5, 6, 0));
  check_equal_nd(&y3, &e2, 8, "_mm256_maskz_permutexvar_ps", __LINE__);

  k = 0xa97e;
  z3 = _mm512_castsi512_ps(v1);
  z3 = _mm512_maskz_permutexvar_ps(k, z2, z1);
  e1 = _mm512_set_epi32(0, 0, 2, 0, 4, 0, 0, 7, 0, 9, 10, 11, 12, 13, 14, 0);
  check_equal_nd(&z3, &e1, 16, "_mm512_maskz_permutexvar_ps", __LINE__);
}

#define CHECK_PERMI_PS(n_elems, dest, mask, zeroing, name)                     \
  {                                                                            \
    volatile int i;                                                            \
    for (i = 0; i < n_elems; ++i) {                                            \
      expected.f32[i] = i32.f32[4 * (i / 4) + (i32_mix.s32[i] & 0x3)];         \
      if ((mask & (1LL << i)) == 0) {                                          \
        if (zeroing) {                                                         \
          expected.f32[i] = 0;                                                 \
        } else {                                                               \
          expected.f32[i] = dest.f32[i];                                       \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_elems, name, __LINE__);                  \
    i32_mix.ymmi[vol0] = i32_mix.ymmi[vol0];                                   \
  }

#define CHECK_PERMI_PS_IMM(n_elems, dest, mask, zeroing, name)                 \
  {                                                                            \
    volatile int i;                                                            \
    for (i = 0; i < n_elems; ++i) {                                            \
      expected.f32[i] = i32.f32[4 * (i / 4) + ((imm >> ((i % 4) * 2)) & 0x3)]; \
      if ((mask & (1LL << i)) == 0) {                                          \
        if (zeroing) {                                                         \
          expected.f32[i] = 0;                                                 \
        } else {                                                               \
          expected.f32[i] = dest.f32[i];                                       \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_elems, name, __LINE__);                  \
    i32.ymmi[vol0] = i32.ymmi[vol0];                                           \
  }

void NOINLINE do_permi_ps() {
  V512 res;
  V512 expected;
  __mmask16 k = 0xFFFF;
  char imm;

  res.xmm[vol0] = _mm_permutevar_ps(i32.xmm[vol0], i32_mix.xmmi[vol0]);
  CHECK_PERMI_PS(2, i32_big, k, 0, "_mm_permutevar_ps");
  res.ymm[vol0] = _mm256_permutevar_ps(i32.ymm[vol0], i32_mix.ymmi[vol0]);
  CHECK_PERMI_PS(4, i32_big, k, 0, "_mm256_permutevar_ps");
  res.zmm = _mm512_permutevar_ps(i32.zmm, i32_mix.zmmi);
  CHECK_PERMI_PS(8, i32_big, k, 0, "_mm512_permutevar_ps");

  k = 0xA4;
  res.xmm[vol0] = _mm_mask_permutevar_ps(i32_big.xmm[vol0], k, i32.xmm[vol0],
                                         i32_mix.xmmi[vol0]);
  CHECK_PERMI_PS(2, i32_big, k, 0, "_mm_mask_permutevar_ps");
  res.ymm[vol0] = _mm256_mask_permutevar_ps(i32_big.ymm[vol0], k, i32.ymm[vol0],
                                            i32_mix.ymmi[vol0]);
  CHECK_PERMI_PS(4, i32_big, k, 0, "_mm256_mask_permutevar_ps");
  res.zmm = _mm512_mask_permutevar_ps(i32_big.zmm, k, i32.zmm, i32_mix.zmmi);
  CHECK_PERMI_PS(8, i32_big, k, 0, "_mm512_mask_permutevar_ps");

  k = 0xA4;
  res.xmm[vol0] = _mm_maskz_permutevar_ps(k, i32.xmm[vol0], i32_mix.xmmi[vol0]);
  CHECK_PERMI_PS(2, i32_big, k, 1, "_mm_maskz_permutevar_ps");
  res.ymm[vol0] =
      _mm256_maskz_permutevar_ps(k, i32.ymm[vol0], i32_mix.ymmi[vol0]);
  CHECK_PERMI_PS(4, i32_big, k, 1, "_mm256_maskz_permutevar_ps");
  res.zmm = _mm512_maskz_permutevar_ps(k, i32.zmm, i32_mix.zmmi);
  CHECK_PERMI_PS(8, i32_big, k, 1, "_mm512_maskz_permutevar_ps");

  imm = 0xA4;
  k = 0xFF;
  res.xmm[vol0] = _mm_permute_ps(i32.xmm[vol0], 0xA4);
  CHECK_PERMI_PS_IMM(2, i32_big, k, 0, "_mm_permute_ps");
  res.ymm[vol0] = _mm256_permute_ps(i32.ymm[vol0], 0xA4);
  CHECK_PERMI_PS_IMM(4, i32_big, k, 0, "_mm256_permute_ps");
  res.zmm = _mm512_permute_ps(i32.zmm, 0xA4);
  CHECK_PERMI_PS_IMM(8, i32_big, k, 0, "_mm512_permute_pd");

  k = 0xA4;
  res.xmm[vol0] =
      _mm_mask_permute_ps(i32_big.xmm[vol0], k, i32.xmm[vol0], 0xA4);
  CHECK_PERMI_PS_IMM(2, i32_big, k, 0, "_mm_mask_permute_ps");
  res.ymm[vol0] =
      _mm256_mask_permute_ps(i32_big.ymm[vol0], k, i32.ymm[vol0], 0xA4);
  CHECK_PERMI_PS_IMM(4, i32_big, k, 0, "_mm256_mask_permute_ps");
  res.zmm = _mm512_mask_permute_ps(i32_big.zmm, k, i32.zmm, 0xA4);
  CHECK_PERMI_PS_IMM(8, i32_big, k, 0, "_mm512_mask_permute_ps");

  k = 0xA4;
  res.xmm[vol0] = _mm_maskz_permute_ps(k, i32.xmm[vol0], 0xA4);
  CHECK_PERMI_PS_IMM(2, i32_big, k, 1, "_mm_maskz_permute_ps");
  res.ymm[vol0] = _mm256_maskz_permute_ps(k, i32.ymm[vol0], 0xA4);
  CHECK_PERMI_PS_IMM(4, i32_big, k, 1, "_mm256_maskz_permute_ps");
  res.zmm = _mm512_maskz_permute_ps(k, i32.zmm, 0xA4);
  CHECK_PERMI_PS_IMM(8, i32_big, k, 1, "_mm512_maskz_permute_ps");
}

void NOINLINE do_perm_epi64() {
  __mmask8 k;

  volatile __m512i v1 = _mm512_set_epi64(7, 6, 5, 4, 3, 2, 1, 0);
  volatile __m512i v2 = _mm512_set_epi64(0, 1, 2, 3, 4, 5, 6, 7);
  __m512i z1 = v1;
  __m512i z2 = v2;
  __m512i z3;
  __m512i e1;
  volatile __m256i y1 = _mm256_set_epi64x(3, 2, 1, 0);
  volatile __m256i y2 = _mm256_set_epi64x(0, 1, 2, 3);
  __m256i y3, e2;

  y3 = _mm256_permutexvar_epi64(y2, y1);
  e2 = y2;
  check_equal_nd(&y3, &e2, 8, "_mm256_permutexvar_epi64", __LINE__);

  z3 = _mm512_permutexvar_epi64(z2, z1);
  check_equal_nd(&z3, &z2, 16, "_mm512_permutexvar_epi64", __LINE__);

  k = 0x7e;
  y3 = y1;
  y3 = _mm256_mask_permutexvar_epi64(y3, k, y2, y1);
  e2 = _mm256_set_epi64x(0, 1, 2, 0);
  check_equal_nd(&y3, &e2, 8, "_mm256_mask_permutexvar_epi64", __LINE__);

  k = 0x7e;
  z3 = v1;
  z3 = _mm512_mask_permutexvar_epi64(z3, k, z2, z1);
  e1 = _mm512_set_epi64(7, 1, 2, 3, 4, 5, 6, 0);
  check_equal_nd(&z3, &e1, 16, "_mm512_mask_permutexvar_epi64", __LINE__);

  k = 0x7c;
  y3 = y1;
  y3 = _mm256_maskz_permutexvar_epi64(k, y2, y1);
  e2 = _mm256_set_epi64x(0, 1, 0, 0);
  check_equal_nd(&y3, &e2, 8, "_mm256_maskz_permutexvar_epi64", __LINE__);

  k = 0x7e;
  z3 = v1;
  z3 = _mm512_maskz_permutexvar_epi64(k, z2, z1);
  e1 = _mm512_set_epi64(0, 1, 2, 3, 4, 5, 6, 0);
  check_equal_nd(&z3, &e1, 16, "_mm512_maskz_permutexvar_epi64", __LINE__);
}

void NOINLINE do_perm_pd() {
  __mmask8 k;

  volatile __m512i v1 = _mm512_set_epi64(7, 6, 5, 4, 3, 2, 1, 0);
  volatile __m512i v2 = _mm512_set_epi64(0, 1, 2, 3, 4, 5, 6, 7);
  __m512d z1 = _mm512_castsi512_pd(v1);
  __m512i z2 = v2;
  __m512d z3;
  __m512i e1;
  volatile __m256i yv1;
  volatile __m256i yv2;
  __m256d y1;
  __m256i y2;
  __m256d y3;
  __m256i ye1;

  z3 = _mm512_permutexvar_pd(z2, z1);
  check_equal_nd(&z3, &z2, 16, "_mm512_permutexvar_pd", __LINE__);

  k = 0x7e;
  z3 = _mm512_castsi512_pd(v1);
  z3 = _mm512_mask_permutexvar_pd(z3, k, z2, z1);
  e1 = _mm512_set_epi64(7, 1, 2, 3, 4, 5, 6, 0);
  check_equal_nd(&z3, &e1, 16, "_mm512_mask_permutexvar_pd", __LINE__);

  z3 = _mm512_maskz_permutexvar_pd(k, z2, z1);
  e1 = _mm512_set_epi64(0, 1, 2, 3, 4, 5, 6, 0);
  check_equal_nd(&z3, &e1, 16, "_mm512_maskz_permutexvar_pd", __LINE__);

  /* 256 */
  yv1 = _mm256_set_epi64x(7, 6, 5, 4);
  yv2 = _mm256_set_epi64x(4, 5, 6, 7);
  y1 = _mm256_castsi256_pd(yv1);
  y2 = yv2;

  y3 = _mm256_permutexvar_pd(y2, y1);
  check_equal_nd(&y3, &y2, 8, "_mm256_permutexvar_pd", __LINE__);

  k = 0x6;
  y3 = _mm256_castsi256_pd(yv1);
  y3 = _mm256_mask_permutexvar_pd(y3, k, y2, y1);
  ye1 = _mm256_set_epi64x(7, 5, 6, 4);
  check_equal_nd(&y3, &ye1, 8, "_mm256_mask_permutexvar_pd", __LINE__);

  y3 = _mm256_maskz_permutexvar_pd(k, y2, y1);
  ye1 = _mm256_set_epi64x(0, 5, 6, 0);
  check_equal_nd(&y3, &ye1, 8, "_mm256_maskz_permutexvar_pd", __LINE__);
}

#define CHECK_PERMI_PD(n_elems, dest, mask, zeroing, name)                     \
  {                                                                            \
    volatile int i;                                                            \
    for (i = 0; i < n_elems; ++i) {                                            \
      if ((i64_mix.s64[i] & 0x2) == 0) {                                       \
        expected.f64[i] = i64.f64[2 * (i / 2)];                                \
      } else {                                                                 \
        expected.f64[i] = i64.f64[2 * (i / 2) + 1];                            \
      }                                                                        \
      if ((mask & (1LL << i)) == 0) {                                          \
        if (zeroing) {                                                         \
          expected.f64[i] = 0;                                                 \
        } else {                                                               \
          expected.f64[i] = dest.f64[i];                                       \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_elems * 2, name, __LINE__);              \
    i64_mix.ymmi[vol0] = i64_mix.ymmi[vol0];                                   \
  }

#define CHECK_PERMI_PD_IMM(n_elems, dest, mask, zeroing, name)                 \
  {                                                                            \
    volatile int i;                                                            \
    for (i = 0; i < n_elems; ++i) {                                            \
      if (((imm >> i) & 0x1) == 0) {                                           \
        expected.f64[i] = i64.f64[2 * (i / 2)];                                \
      } else {                                                                 \
        expected.f64[i] = i64.f64[2 * (i / 2) + 1];                            \
      }                                                                        \
      if ((mask & (1LL << i)) == 0) {                                          \
        if (zeroing) {                                                         \
          expected.f64[i] = 0;                                                 \
        } else {                                                               \
          expected.f64[i] = dest.f64[i];                                       \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_elems * 2, name, __LINE__);              \
    i64.ymmi[vol0] = i64.ymmi[vol0];                                           \
  }

void NOINLINE do_permi_pd() {
  V512 res;
  V512 expected;
  __mmask8 k = 0xFF;
  char imm;

  res.xmmd[vol0] = _mm_permutevar_pd(i64.xmmd[vol0], i64_mix.xmmi[vol0]);
  CHECK_PERMI_PD(2, i64_big, k, 0, "_mm_permutevar_pd");
  res.ymmd[vol0] = _mm256_permutevar_pd(i64.ymmd[vol0], i64_mix.ymmi[vol0]);
  CHECK_PERMI_PD(4, i64_big, k, 0, "_mm256_permutevar_pd");
  res.zmmd = _mm512_permutevar_pd(i64.zmmd, i64_mix.zmmi);
  CHECK_PERMI_PD(8, i64_big, k, 0, "_mm512_permutevar_pd");

  k = 0xA4;
  res.xmmd[vol0] = _mm_mask_permutevar_pd(i64_big.xmmd[vol0], k, i64.xmmd[vol0],
                                          i64_mix.xmmi[vol0]);
  CHECK_PERMI_PD(2, i64_big, k, 0, "_mm_mask_permutevar_pd");
  res.ymmd[vol0] = _mm256_mask_permutevar_pd(
      i64_big.ymmd[vol0], k, i64.ymmd[vol0], i64_mix.ymmi[vol0]);
  CHECK_PERMI_PD(4, i64_big, k, 0, "_mm256_mask_permutevar_pd");
  res.zmmd = _mm512_mask_permutevar_pd(i64_big.zmmd, k, i64.zmmd, i64_mix.zmmi);
  CHECK_PERMI_PD(8, i64_big, k, 0, "_mm512_mask_permutevar_pd");

  k = 0xA4;
  res.xmmd[vol0] =
      _mm_maskz_permutevar_pd(k, i64.xmmd[vol0], i64_mix.xmmi[vol0]);
  CHECK_PERMI_PD(2, i64_big, k, 1, "_mm_maskz_permutevar_pd");
  res.ymmd[vol0] =
      _mm256_maskz_permutevar_pd(k, i64.ymmd[vol0], i64_mix.ymmi[vol0]);
  CHECK_PERMI_PD(4, i64_big, k, 1, "_mm256_maskz_permutevar_pd");
  res.zmmd = _mm512_maskz_permutevar_pd(k, i64.zmmd, i64_mix.zmmi);
  CHECK_PERMI_PD(8, i64_big, k, 1, "_mm512_maskz_permutevar_pd");

  imm = 0xA4;
  k = 0xFF;
  res.xmmd[vol0] = _mm_permute_pd(i64.xmmd[vol0], 0xA4 & 0x3);
  CHECK_PERMI_PD_IMM(2, i64_big, k, 0, "_mm_permute_pd");
  res.ymmd[vol0] = _mm256_permute_pd(i64.ymmd[vol0], 0xA4 & 0xf);
  CHECK_PERMI_PD_IMM(4, i64_big, k, 0, "_mm256_permute_pd");
  res.zmmd = _mm512_permute_pd(i64.zmmd, 0xA4);
  CHECK_PERMI_PD_IMM(8, i64_big, k, 0, "_mm512_permute_pd");

  k = 0xA4;
  res.xmmd[vol0] =
      _mm_mask_permute_pd(i64_big.xmmd[vol0], k, i64.xmmd[vol0], 0xA4 & 0x3);
  CHECK_PERMI_PD_IMM(2, i64_big, k, 0, "_mm_mask_permute_pd");
  res.ymmd[vol0] =
      _mm256_mask_permute_pd(i64_big.ymmd[vol0], k, i64.ymmd[vol0], 0xA4 & 0xf);
  CHECK_PERMI_PD_IMM(4, i64_big, k, 0, "_mm256_mask_permute_pd");
  res.zmmd = _mm512_mask_permute_pd(i64_big.zmmd, k, i64.zmmd, 0xA4);
  CHECK_PERMI_PD_IMM(8, i64_big, k, 0, "_mm512_mask_permute_pd");

  k = 0xA4;
  res.xmmd[vol0] = _mm_maskz_permute_pd(k, i64.xmmd[vol0], 0xA4 & 0x3);
  CHECK_PERMI_PD_IMM(2, i64_big, k, 1, "_mm_maskz_permute_pd");
  res.ymmd[vol0] = _mm256_maskz_permute_pd(k, i64.ymmd[vol0], 0xA4 & 0xf);
  CHECK_PERMI_PD_IMM(4, i64_big, k, 1, "_mm256_maskz_permute_pd");
  res.zmmd = _mm512_maskz_permute_pd(k, i64.zmmd, 0xA4);
  CHECK_PERMI_PD_IMM(8, i64_big, k, 1, "_mm512_maskz_permute_pd");
}

void NOINLINE do_perm_epi64_imm() {
  __mmask8 k;

  volatile __m512i v1 = _mm512_set_epi64(7, 6, 5, 4, 3, 2, 1, 0);
  __m512i z1 = v1;
  __m512i z2;
  __m512i e1;
  volatile __m256i y1 = _mm256_set_epi64x(3, 2, 1, 0);
  __m256i y2, e2;

  y2 = y1;
  y2 = _mm256_permutex_epi64(y2, 0x7a);
  e2 = _mm256_set_epi64x(1, 3, 2, 2);
  check_equal_nd(&y2, &e2, 8, "_mm256_permutex_epi64", __LINE__);

  z2 = _mm512_permutex_epi64(z1, 0x7a);
  e1 = _mm512_set_epi64(5, 7, 6, 6, 1, 3, 2, 2);
  check_equal_nd(&z2, &e1, 16, "_mm512_permutex_epi64", __LINE__);

  k = 0x7e;
  y2 = y1;
  y2 = _mm256_mask_permutex_epi64(y2, k, y2, 0x7a);
  e2 = _mm256_set_epi64x(1, 3, 2, 0);
  check_equal_nd(&y2, &e2, 8, "_mm256_mask_permutex_epi64", __LINE__);

  k = 0x7e;
  z2 = v1;
  z2 = _mm512_mask_permutex_epi64(z2, k, z2, 0x7a);
  e1 = _mm512_set_epi64(7, 7, 6, 6, 1, 3, 2, 0);
  check_equal_nd(&z2, &e1, 16, "_mm512_mask_permutex_epi64", __LINE__);

  k = 0x76;
  y2 = y1;
  y2 = _mm256_maskz_permutex_epi64(k, y2, 0x7a);
  e2 = _mm256_set_epi64x(0, 3, 2, 0);
  check_equal_nd(&y2, &e2, 8, "_mm256_maskz_permutex_epi64", __LINE__);

  k = 0x7e;
  z2 = v1;
  z2 = _mm512_maskz_permutex_epi64(k, z2, 0x7a);
  e1 = _mm512_set_epi64(0, 7, 6, 6, 1, 3, 2, 0);
  check_equal_nd(&z2, &e1, 16, "_mm512_maskz_permutex_epi64", __LINE__);
}

void NOINLINE do_perm_pd_imm() {
  __mmask8 k;

  volatile __m512i v1 = _mm512_set_epi64(7, 6, 5, 4, 3, 2, 1, 0);
  __m512d z1 = _mm512_castsi512_pd(v1);
  __m512d z2;
  __m512i e1;
  volatile __m256i yv1;
  __m256d y1;
  __m256d y2;
  __m256i ye1;

  z2 = _mm512_permutex_pd(z1, 0x7a);
  e1 = _mm512_set_epi64(5, 7, 6, 6, 1, 3, 2, 2);
  check_equal_nd(&z2, &e1, 16, "_mm512_permutex_pd", __LINE__);

  k = 0x7e;
  z2 = _mm512_castsi512_pd(v1);
  z2 = _mm512_mask_permutex_pd(z2, k, z2, 0x7a);
  e1 = _mm512_set_epi64(7, 7, 6, 6, 1, 3, 2, 0);
  check_equal_nd(&z2, &e1, 16, "_mm512_mask_permutex_pd", __LINE__);

  z2 = _mm512_castsi512_pd(v1);
  z2 = _mm512_maskz_permutex_pd(k, z2, 0x7a);
  e1 = _mm512_set_epi64(0, 7, 6, 6, 1, 3, 2, 0);
  check_equal_nd(&z2, &e1, 16, "_mm512_maskz_permutex_pd", __LINE__);

  /* 256 */
  yv1 = _mm256_set_epi64x(7, 6, 5, 4);
  y1 = _mm256_castsi256_pd(yv1);

  y2 = _mm256_permutex_pd(y1, 0xa);
  ye1 = _mm256_set_epi64x(4, 4, 6, 6);
  check_equal_nd(&y2, &ye1, 8, "_mm256_permutex_pd", __LINE__);

  k = 0x7e;
  y2 = _mm256_castsi256_pd(yv1);
  y2 = _mm256_mask_permutex_pd(y2, k, y2, 0xa);
  ye1 = _mm256_set_epi64x(4, 4, 6, 4);
  check_equal_nd(&y2, &ye1, 8, "_mm256_mask_permutex_pd", __LINE__);

  y2 = _mm256_castsi256_pd(yv1);
  y2 = _mm256_maskz_permutex_pd(k, y2, 0xa);
  ye1 = _mm256_set_epi64x(4, 4, 6, 0);
  check_equal_nd(&y2, &ye1, 8, "_mm256_maskz_permutex_pd", __LINE__);
}

void NOINLINE do_perm_ti_2w() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask32 k;

  res.zmmi = _mm512_permutex2var_epi16(i16.zmmi, i16_mix.zmmi, i16_big.zmmi);
  for (i = 0; i < 32; i++) {
    int index = i16_mix.s16[i] & 0x1f;
    expected.s16[i] =
        (i16_mix.s16[i] & 0x20) ? i16_big.s16[index] : i16.s16[index];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_permutex2var_epi16", __LINE__);

  i16_big.xmmi[vol0] = i16_big.xmmi[vol0];

  k = 0xabcdffef;
  res.zmmi =
      _mm512_mask_permutex2var_epi16(i16.zmmi, k, i16_mix.zmmi, i16_big.zmmi);
  for (i = 0; i < 32; i++) {
    int index = i16_mix.s16[i] & 0x1f;
    expected.s16[i] =
        (i16_mix.s16[i] & 0x20) ? i16_big.s16[index] : i16.s16[index];
    if ((k & (1 << i)) == 0) {
      expected.s16[i] = i16.s16[i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_permutex2var_epi16",
                 __LINE__);

  i16_big.xmmi[vol0] = i16_big.xmmi[vol0];

  k = 0xabcdffef;
  res.zmmi =
      _mm512_mask2_permutex2var_epi16(i16.zmmi, i16_mix.zmmi, k, i16_big.zmmi);
  for (i = 0; i < 32; i++) {
    int index = i16_mix.s16[i] & 0x1f;
    expected.s16[i] =
        (i16_mix.s16[i] & 0x20) ? i16_big.s16[index] : i16.s16[index];
    if ((k & (1 << i)) == 0) {
      expected.s16[i] = i16_mix.s16[i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask2_permutex2var_epi16",
                 __LINE__);

  i16_big.xmmi[vol0] = i16_big.xmmi[vol0];

  k = 0xabcdffef;
  res.zmmi =
      _mm512_maskz_permutex2var_epi16(k, i16.zmmi, i16_mix.zmmi, i16_big.zmmi);
  for (i = 0; i < 32; i++) {
    int index = i16_mix.s16[i] & 0x1f;
    expected.s16[i] =
        (i16_mix.s16[i] & 0x20) ? i16_big.s16[index] : i16.s16[index];
    if ((k & (1 << i)) == 0) {
      expected.s16[i] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_permutex2var_epi16",
                 __LINE__);
}

void NOINLINE do_perm_ti_2d() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask16 k;

  res.zmmi = _mm512_permutex2var_epi32(i32.zmmi, i32_mix.zmmi, i32_big.zmmi);
  for (i = 0; i < 16; i++) {
    int index = i32_mix.s32[i] & 0xf;
    expected.s32[i] =
        (i32_mix.s32[i] & 0x10) ? i32_big.s32[index] : i32.s32[index];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_permutex2var_epi32", __LINE__);

  i32_big.xmmi[vol0] = i32_big.xmmi[vol0];

  k = 0xabcd;
  res.zmmi =
      _mm512_mask_permutex2var_epi32(i32.zmmi, k, i32_mix.zmmi, i32_big.zmmi);
  for (i = 0; i < 16; i++) {
    int index = i32_mix.s32[i] & 0xf;
    expected.s32[i] =
        (i32_mix.s32[i] & 0x10) ? i32_big.s32[index] : i32.s32[index];
    if ((k & (1 << i)) == 0) {
      expected.s32[i] = i32.s32[i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_permutex2var_epi32",
                 __LINE__);

  i32_big.xmmi[vol0] = i32_big.xmmi[vol0];

  k = 0xdcba;
  res.zmmi =
      _mm512_mask2_permutex2var_epi32(i32.zmmi, i32_mix.zmmi, k, i32_big.zmmi);
  for (i = 0; i < 16; i++) {
    int index = i32_mix.s32[i] & 0xf;
    expected.s32[i] =
        (i32_mix.s32[i] & 0x10) ? i32_big.s32[index] : i32.s32[index];
    if ((k & (1 << i)) == 0) {
      expected.s32[i] = i32_mix.s32[i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask2_permutex2var_epi32",
                 __LINE__);

  i32_big.xmmi[vol0] = i32_big.xmmi[vol0];

  k = 0xabcd;
  res.zmmi =
      _mm512_maskz_permutex2var_epi32(k, i32.zmmi, i32_mix.zmmi, i32_big.zmmi);
  for (i = 0; i < 16; i++) {
    int index = i32_mix.s32[i] & 0xf;
    expected.s32[i] =
        (i32_mix.s32[i] & 0x10) ? i32_big.s32[index] : i32.s32[index];
    if ((k & (1 << i)) == 0) {
      expected.s32[i] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_permutex2var_epi32",
                 __LINE__);
}

void NOINLINE do_perm_ti_2q() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k;

  res.zmmi = _mm512_permutex2var_epi64(i64.zmmi, i64_mix.zmmi, i64_big.zmmi);
  for (i = 0; i < 8; i++) {
    int index = i64_mix.s64[i] & 0x7;
    expected.s64[i] =
        (i64_mix.s64[i] & 0x8) ? i64_big.s64[index] : i64.s64[index];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_permutex2var_epi64", __LINE__);

  i64_big.xmmi[vol0] = i64_big.xmmi[vol0];

  k = 0xf9;
  res.zmmi =
      _mm512_mask_permutex2var_epi64(i64.zmmi, k, i64_mix.zmmi, i64_big.zmmi);
  for (i = 0; i < 8; i++) {
    int index = i64_mix.s64[i] & 0x7;
    expected.s64[i] =
        (i64_mix.s64[i] & 0x8) ? i64_big.s64[index] : i64.s64[index];
    if ((k & (1 << i)) == 0) {
      expected.s64[i] = i64.s64[i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_permutex2var_epi64",
                 __LINE__);

  i64_big.xmmi[vol0] = i64_big.xmmi[vol0];

  k = 0xf9;
  res.zmmi =
      _mm512_mask2_permutex2var_epi64(i64.zmmi, i64_mix.zmmi, k, i64_big.zmmi);
  for (i = 0; i < 8; i++) {
    int index = i64_mix.s64[i] & 0x7;
    expected.s64[i] =
        (i64_mix.s64[i] & 0x8) ? i64_big.s64[index] : i64.s64[index];
    if ((k & (1 << i)) == 0) {
      expected.s64[i] = i64_mix.s64[i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask2_permutex2var_epi64",
                 __LINE__);

  i64_big.xmmi[vol0] = i64_big.xmmi[vol0];

  k = 0xe7;
  res.zmmi =
      _mm512_maskz_permutex2var_epi64(k, i64.zmmi, i64_mix.zmmi, i64_big.zmmi);
  for (i = 0; i < 8; i++) {
    int index = i64_mix.s64[i] & 0x7;
    expected.s64[i] =
        (i64_mix.s64[i] & 0x8) ? i64_big.s64[index] : i64.s64[index];
    if ((k & (1 << i)) == 0) {
      expected.s64[i] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_permutex2var_epi64",
                 __LINE__);
}

void NOINLINE do_perm_ti_2ps() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask16 k;

  res.zmm = _mm512_permutex2var_ps(i32.zmm, i32_mix.zmmi, i32_big.zmm);
  for (i = 0; i < 16; i++) {
    int index = i32_mix.s32[i] & 0xf;
    expected.s32[i] =
        (i32_mix.s32[i] & 0x10) ? i32_big.s32[index] : i32.s32[index];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_permutex2var_ps", __LINE__);

  i32_big.xmmi[vol0] = i32_big.xmmi[vol0];

  k = 0xabcd;
  res.zmm = _mm512_mask_permutex2var_ps(i32.zmm, k, i32_mix.zmmi, i32_big.zmm);
  for (i = 0; i < 16; i++) {
    int index = i32_mix.s32[i] & 0xf;
    expected.s32[i] =
        (i32_mix.s32[i] & 0x10) ? i32_big.s32[index] : i32.s32[index];
    if ((k & (1 << i)) == 0) {
      expected.s32[i] = i32.s32[i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_permutex2var_ps", __LINE__);

  i32_big.xmmi[vol0] = i32_big.xmmi[vol0];

  k = 0xabcd;
  res.zmm = _mm512_mask2_permutex2var_ps(i32.zmm, i32_mix.zmmi, k, i32_big.zmm);
  for (i = 0; i < 16; i++) {
    int index = i32_mix.s32[i] & 0xf;
    expected.s32[i] =
        (i32_mix.s32[i] & 0x10) ? i32_big.s32[index] : i32.s32[index];
    if ((k & (1 << i)) == 0) {
      expected.s32[i] = i32_mix.s32[i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask2_permutex2var_ps", __LINE__);

  i32_big.xmmi[vol0] = i32_big.xmmi[vol0];

  k = 0xabcd;
  res.zmm = _mm512_maskz_permutex2var_ps(k, i32.zmm, i32_mix.zmmi, i32_big.zmm);
  for (i = 0; i < 16; i++) {
    int index = i32_mix.s32[i] & 0xf;
    expected.s32[i] =
        (i32_mix.s32[i] & 0x10) ? i32_big.s32[index] : i32.s32[index];
    if ((k & (1 << i)) == 0) {
      expected.s32[i] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_permutex2var_ps", __LINE__);
}

void NOINLINE do_perm_ti_2pd() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k;

  res.zmmd = _mm512_permutex2var_pd(i64.zmmd, i64_mix.zmmi, i64_big.zmmd);
  for (i = 0; i < 8; i++) {
    int index = i64_mix.s64[i] & 0x7;
    expected.s64[i] =
        (i64_mix.s64[i] & 0x8) ? i64_big.s64[index] : i64.s64[index];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_permutex2var_pd", __LINE__);

  i64_big.xmmi[vol0] = i64_big.xmmi[vol0];

  k = 0xf9;
  res.zmmd =
      _mm512_mask_permutex2var_pd(i64.zmmd, k, i64_mix.zmmi, i64_big.zmmd);
  for (i = 0; i < 8; i++) {
    int index = i64_mix.s64[i] & 0x7;
    expected.s64[i] =
        (i64_mix.s64[i] & 0x8) ? i64_big.s64[index] : i64.s64[index];
    if ((k & (1 << i)) == 0) {
      expected.s64[i] = i64.s64[i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_permutex2var_pd", __LINE__);

  i64_big.xmmi[vol0] = i64_big.xmmi[vol0];

  k = 0xf9;
  res.zmmd =
      _mm512_mask2_permutex2var_pd(i64.zmmd, i64_mix.zmmi, k, i64_big.zmmd);
  for (i = 0; i < 8; i++) {
    int index = i64_mix.s64[i] & 0x7;
    expected.s64[i] =
        (i64_mix.s64[i] & 0x8) ? i64_big.s64[index] : i64.s64[index];
    if ((k & (1 << i)) == 0) {
      expected.s64[i] = i64_mix.s64[i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask2_permutex2var_pd", __LINE__);

  i64_big.xmmi[vol0] = i64_big.xmmi[vol0];

  k = 0xf9;
  res.zmmd =
      _mm512_maskz_permutex2var_pd(k, i64.zmmd, i64_mix.zmmi, i64_big.zmmd);
  for (i = 0; i < 8; i++) {
    int index = i64_mix.s64[i] & 0x7;
    expected.s64[i] =
        (i64_mix.s64[i] & 0x8) ? i64_big.s64[index] : i64.s64[index];
    if ((k & (1 << i)) == 0) {
      expected.s64[i] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_permutex2var_pd", __LINE__);
}

#define CHECK_PERMW(n_elems, dest, mask, zeroing, name)                        \
  {                                                                            \
    volatile int i;                                                            \
    for (i = 0; i < n_elems; i++) {                                            \
      expected.s16[i] = i16_mix.s16[i16.s16[i] & 0x1f];                        \
      if ((mask & (1 << i)) == 0) {                                            \
        if (zeroing) {                                                         \
          expected.s16[i] = 0;                                                 \
        } else {                                                               \
          expected.s16[i] = dest.s16[i];                                       \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_elems / 2, name, __LINE__);              \
    i16.xmmi[vol0] = i16.xmmi[vol0];                                           \
  }

void NOINLINE do_permw() {
  V512 res;
  V512 expected;
  __mmask32 k32 = 0xFFFFFFFF;

  res.xmmi[vol0] = _mm_permutexvar_epi16(i16.xmmi[vol0], i16_mix.xmmi[vol0]);
  CHECK_PERMW(8, i16_big, k32, 0, "_mm_permutexvar_epi16");

  res.ymmi[vol0] = _mm256_permutexvar_epi16(i16.ymmi[vol0], i16_mix.ymmi[vol0]);
  CHECK_PERMW(16, i16_big, k32, 0, "_mm256_permutexvar_epi16");

  res.zmmi = _mm512_permutexvar_epi16(i16.zmmi, i16_mix.zmmi);
  CHECK_PERMW(32, i16_big, k32, 0, "_mm512_permutexvar_epi16");

  k32 = 0xA4A4A4A4;
  res.xmmi[vol0] = _mm_mask_permutexvar_epi16(
      i16_big.xmmi[vol0], k32, i16.xmmi[vol0], i16_mix.xmmi[vol0]);
  CHECK_PERMW(8, i16_big, k32, 0, "_mm_mask_permutexvar_epi16");

  res.ymmi[vol0] = _mm256_mask_permutexvar_epi16(
      i16_big.ymmi[vol0], k32, i16.ymmi[vol0], i16_mix.ymmi[vol0]);
  CHECK_PERMW(16, i16_big, k32, 0, "_mm256_mask_permutexvar_epi16");

  res.zmmi =
      _mm512_mask_permutexvar_epi16(i16_big.zmmi, k32, i16.zmmi, i16_mix.zmmi);
  CHECK_PERMW(32, i16_big, k32, 0, "_mm512_mask_permutexvar_epi16");

  k32 = 0x4A4A4A4A;
  res.xmmi[vol0] =
      _mm_maskz_permutexvar_epi16(k32, i16.xmmi[vol0], i16_mix.xmmi[vol0]);
  CHECK_PERMW(8, i16_big, k32, 1, "_mm_maskz_permutexvar_epi16");

  res.ymmi[vol0] =
      _mm256_maskz_permutexvar_epi16(k32, i16.ymmi[vol0], i16_mix.ymmi[vol0]);
  CHECK_PERMW(16, i16_big, k32, 1, "_mm256_maskz_permutexvar_epi16");

  res.zmmi = _mm512_maskz_permutexvar_epi16(k32, i16.zmmi, i16_mix.zmmi);
  CHECK_PERMW(32, i16_big, k32, 1, "_mm512_maskz_permutexvar_epi16");
}

void NOINLINE do_blendmps() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask16 k = 0x3456;

  res.zmm = _mm512_mask_blend_ps(k, i32.zmm, i32_mix.zmm);
  for (i = 0; i < 16; i++) {
    expected.s32[i] = i32.s32[i];
    if ((k & (1 << i)) != 0) {
      expected.s32[i] = i32_mix.s32[i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_blend_ps", __LINE__);
}

int main(int argc, char *argv[]) {
  init();

  do_pshufb();

  do_perm_epi32();
  do_perm_ps();
  do_permi_ps();

  do_perm_epi64();
  do_perm_pd();
  do_permi_pd();

  do_perm_epi64_imm();
  do_perm_pd_imm();

  do_perm_ti_2w();

  do_perm_ti_2d();
  do_perm_ti_2q();

  do_perm_ti_2ps();
  do_perm_ti_2pd();

  do_permw();

  do_blendmps();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
