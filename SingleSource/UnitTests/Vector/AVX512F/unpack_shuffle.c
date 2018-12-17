
/*
 * Test the unpack{hi,lo} and shuffle intrinsics.
 * This test was created to check the correctness
 * of the following intrinsics support:
 * _mm512_mask_blend_*()
 * _mm512_shuffle_*()
 * _mm512_mask_shuffle_*()
 * _mm_unpack*()
 * _mm256_unpack*()
 * _mm512_unpack*()
 * _mm512_mask_unpack*()
 * _mm512_maskz_unpack*()
 */

#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

volatile int vol0 = 0;
/*
 * Use this between tests to make compiler think src was updated.
 * Prevents PRE'ing of a load of src.
 */
#define soft_update(src) (src).xmmi[vol0] = (src).xmmi[vol0]

V512 in8;
V512 in8_neg;
V512 in32;
V512 in32_neg;
V512 in32_mix;
V512 in64;
V512 in64_neg;
V512 in64_mix;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 64; i++) {
    in8.s8[i] = i;
    in8_neg.s8[i] = -i;
  }


  for (i = 0; i < 16; i++) {
    in32.s32[i] = i;
    in32_neg.s32[i] = -i;
    in32_mix.s32[i] = ((i % 3) == 0) ? -i : i;
  }

  for (i = 0; i < 8; i++) {
    in64.s64[i] = i;
    in64_neg.s64[i] = -i;
    in64_mix.s64[i] = ((i % 3) == 0) ? -i : i;
  }
}

#define CHECK_UNPCKHBW(n_lanes, dest, mask, zeroing, name)                     \
  {                                                                            \
    volatile int i, j, lane;                                                   \
    for (lane = 0; lane < n_lanes; lane++) {                                   \
      for (i = 0, j = 0; i < 16; i += 2, j++) {                                \
        expected.s8[16 * lane + i] = in8.s8[16 * lane + 8 + j];                \
        expected.s8[16 * lane + i + 1] = in8_neg.s8[16 * lane + 8 + j];          \
      }                                                                        \
    }                                                                          \
    for (i = 0; i < n_lanes * 16; i++) {                                       \
      if ((mask & (1LL << i)) == 0) {                                          \
        if (zeroing) {                                                         \
          expected.s8[i] = 0;                                                  \
        } else {                                                               \
          expected.s8[i] = dest.s8[i];                                         \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_lanes * 4, name, __LINE__);              \
    in8_neg.ymmi[vol0] = in8_neg.ymmi[vol0];                                       \
  }

#define CHECK_UNPCKH32(n_lanes, dest, mask, zeroing, name)                     \
  {                                                                            \
    volatile int i, j, lane;                                                   \
    for (lane = 0; lane < n_lanes; lane++) {                                   \
      for (i = 0, j = 0; i < 4; i += 2, j++) {                                 \
        expected.s32[4 * lane + i] = in32.s32[4 * lane + 2 + j];               \
        expected.s32[4 * lane + i + 1] = in32_neg.s32[4 * lane + 2 + j];         \
      }                                                                        \
    }                                                                          \
    for (i = 0; i < n_lanes * 4; i++) {                                        \
      if ((mask & (1LL << i)) == 0) {                                          \
        if (zeroing) {                                                         \
          expected.s32[i] = 0;                                                 \
        } else {                                                               \
          expected.s32[i] = dest.s32[i];                                       \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_lanes * 4, name, __LINE__);              \
    in32_neg.ymmi[vol0] = in32_neg.ymmi[vol0];                                     \
  }

#define CHECK_UNPCKH64(n_lanes, dest, mask, zeroing, name)                     \
  {                                                                            \
    volatile int i, j, lane;                                                   \
    for (lane = 0; lane < n_lanes; lane++) {                                   \
      for (i = 0, j = 0; i < 2; i += 2, j++) {                                 \
        expected.s64[2 * lane + i] = in64.s64[2 * lane + 1 + j];               \
        expected.s64[2 * lane + i + 1] = in64_neg.s64[2 * lane + 1 + j];         \
      }                                                                        \
    }                                                                          \
    for (i = 0; i < n_lanes * 2; i++) {                                        \
      if ((mask & (1LL << i)) == 0) {                                          \
        if (zeroing) {                                                         \
          expected.s64[i] = 0;                                                 \
        } else {                                                               \
          expected.s64[i] = dest.s64[i];                                       \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_lanes * 4, name, __LINE__);              \
    in64_neg.ymmi[vol0] = in64_neg.ymmi[vol0];                                     \
  }

#define CHECK_UNPCKL32(n_lanes, dest, mask, zeroing, name)                     \
  {                                                                            \
    volatile int i, j, lane;                                                   \
    for (lane = 0; lane < n_lanes; lane++) {                                   \
      for (i = 0, j = 0; i < 4; i += 2, j++) {                                 \
        expected.s32[4 * lane + i] = in32.s32[4 * lane + j];                   \
        expected.s32[4 * lane + i + 1] = in32_neg.s32[4 * lane + j];             \
      }                                                                        \
    }                                                                          \
    for (i = 0; i < n_lanes * 4; i++) {                                        \
      if ((mask & (1LL << i)) == 0) {                                          \
        if (zeroing) {                                                         \
          expected.s32[i] = 0;                                                 \
        } else {                                                               \
          expected.s32[i] = dest.s32[i];                                       \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_lanes * 4, name, __LINE__);              \
    in32_neg.ymmi[vol0] = in32_neg.ymmi[vol0];                                     \
  }

#define CHECK_UNPCKL64(n_lanes, dest, mask, zeroing, name)                     \
  {                                                                            \
    volatile int i, j, lane;                                                   \
    for (lane = 0; lane < n_lanes; lane++) {                                   \
      for (i = 0, j = 0; i < 2; i += 2, j++) {                                 \
        expected.s64[2 * lane + i] = in64.s64[2 * lane + j];                   \
        expected.s64[2 * lane + i + 1] = in64_neg.s64[2 * lane + j];             \
      }                                                                        \
    }                                                                          \
    for (i = 0; i < n_lanes * 2; i++) {                                        \
      if ((mask & (1LL << i)) == 0) {                                          \
        if (zeroing) {                                                         \
          expected.s64[i] = 0;                                                 \
        } else {                                                               \
          expected.s64[i] = dest.s64[i];                                       \
        }                                                                      \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, n_lanes * 4, name, __LINE__);              \
    in64_neg.ymmi[vol0] = in64_neg.ymmi[vol0];                                     \
  }

void NOINLINE do_unpckps_lo() {
  V512 res;
  V512 expected;
  __mmask16 k = 0xFFFF;

  res.zmm = _mm512_unpacklo_ps(in32.zmm, in32_neg.zmm);
  CHECK_UNPCKL32(4, in32_mix, k, 0, "_mm512_unpacklo_ps");

  k = 0xA4A4;
  res.zmm = _mm512_mask_unpacklo_ps(in32_mix.zmm, k, in32.zmm, in32_neg.zmm);
  CHECK_UNPCKL32(4, in32_mix, k, 0, "_mm512_mask_unpacklo_ps");

  res.zmm = _mm512_maskz_unpacklo_ps(k, in32.zmm, in32_neg.zmm);
  CHECK_UNPCKL32(4, in32_mix, k, 1, "_mm512_maskz_unpacklo_ps");
}

void NOINLINE do_unpckps_hi() {
  V512 res;
  V512 expected;
  __mmask16 k = 0xFFFF;

  res.xmm[vol0] = _mm_unpackhi_ps(in32.xmm[vol0], in32_neg.xmm[vol0]);
  CHECK_UNPCKH32(1, in32_mix, k, 0, "_mm_unpackhi_ps");
  res.ymm[vol0] = _mm256_unpackhi_ps(in32.ymm[vol0], in32_neg.ymm[vol0]);
  CHECK_UNPCKH32(2, in32_mix, k, 0, "_mm256_unpackhi_ps");
  res.zmm = _mm512_unpackhi_ps(in32.zmm, in32_neg.zmm);
  CHECK_UNPCKH32(4, in32_mix, k, 0, "_mm512_unpackhi_ps");

  k = 0xA4A4;
  res.zmm = _mm512_mask_unpackhi_ps(in32_mix.zmm, k, in32.zmm, in32_neg.zmm);
  CHECK_UNPCKH32(4, in32_mix, k, 0, "_mm512_mask_unpackhi_ps");

  res.zmm = _mm512_maskz_unpackhi_ps(k, in32.zmm, in32_neg.zmm);
  CHECK_UNPCKH32(4, in32_mix, k, 1, "_mm512_maskz_unpackhi_ps");
}

void NOINLINE do_unpckdq_lo() {
  V512 res;
  V512 expected;
  __mmask16 k = 0xFFFF;

  res.xmmi[vol0] = _mm_unpacklo_epi32(in32.xmmi[vol0], in32_neg.xmmi[vol0]);
  CHECK_UNPCKL32(1, in32_mix, k, 0, "_mm_unpacklo_epi32");
  res.ymmi[vol0] = _mm256_unpacklo_epi32(in32.ymmi[vol0], in32_neg.ymmi[vol0]);
  CHECK_UNPCKL32(2, in32_mix, k, 0, "_mm256_unpacklo_epi32");
  res.zmmi = _mm512_unpacklo_epi32(in32.zmmi, in32_neg.zmmi);
  CHECK_UNPCKL32(4, in32_mix, k, 0, "_mm512_unpacklo_epi32");

  k = 0xA4A4;
  res.zmmi = _mm512_mask_unpacklo_epi32(in32_mix.zmmi, k, in32.zmmi, in32_neg.zmmi);
  CHECK_UNPCKL32(4, in32_mix, k, 0, "_mm512_mask_unpacklo_epi32");

  res.zmmi = _mm512_maskz_unpacklo_epi32(k, in32.zmmi, in32_neg.zmmi);
  CHECK_UNPCKL32(4, in32_mix, k, 1, "_mm512_maskz_unpacklo_epi32");
}

void NOINLINE do_unpckqdq_lo() {
  V512 res;
  V512 expected;
  __mmask8 k8 = 0xFF;

  res.zmmi = _mm512_unpacklo_epi64(in64.zmmi, in64_neg.zmmi);
  CHECK_UNPCKL64(4, in64_mix, k8, 0, "_mm512_unpacklo_epi64");

  k8 = 0x4A;
  res.zmmi =
      _mm512_mask_unpacklo_epi64(in64_mix.zmmi, k8, in64.zmmi, in64_neg.zmmi);
  CHECK_UNPCKL64(4, in64_mix, k8, 0, "_mm512_mask_unpacklo_epi64");

  res.zmmi = _mm512_maskz_unpacklo_epi64(k8, in64.zmmi, in64_neg.zmmi);
  CHECK_UNPCKL64(4, in64_mix, k8, 1, "_mm512_maskz_unpacklo_epi64");
}

void NOINLINE do_unpckpd_lo() {
  V512 res;
  V512 expected;
  __mmask8 k8 = 0xFF;

  res.zmmd = _mm512_unpacklo_pd(in64.zmmd, in64_neg.zmmd);
  CHECK_UNPCKL64(4, in64_mix, k8, 0, "_mm512_unpacklo_pd");

  k8 = 0x4A;
  res.zmmd = _mm512_mask_unpacklo_pd(in64_mix.zmmd, k8, in64.zmmd, in64_neg.zmmd);
  CHECK_UNPCKL64(4, in64_mix, k8, 0, "_mm512_mask_unpacklo_pd");

  res.zmmd = _mm512_maskz_unpacklo_pd(k8, in64.zmmd, in64_neg.zmmd);
  CHECK_UNPCKL64(4, in64_mix, k8, 1, "_mm512_maskz_unpacklo_pd");
}

#define CHECK_BLENDM(n_elems, width, type, mask, src1, src2, name)             \
  {                                                                            \
    volatile int i;                                                            \
    for (i = 0; i < n_elems; ++i) {                                            \
      if ((mask & (1LL << i)) == 0) {                                          \
        expected.type[i] = src1.type[i];                                       \
      } else {                                                                 \
        expected.type[i] = src2.type[i];                                       \
      }                                                                        \
    }                                                                          \
    check_equal_nd(&res, &expected, (n_elems * width) / 4, name, __LINE__);    \
    src2.ymmi[vol0] = src2.ymmi[vol0];                                         \
  }

void NOINLINE do_blendmd() {
  V512 res;
  V512 expected;
  __mmask16 k = 0xA44A;

  res.zmmi = _mm512_mask_blend_epi32(k, in32.zmmi, in32_neg.zmmi);
  CHECK_BLENDM(16, 4, s32, k, in32, in32_neg, "_mm512_mask_blend_epi32");
  res.zmmi = _mm512_mask_mov_epi32(in32.zmmi, k, in32_neg.zmmi);
  CHECK_BLENDM(16, 4, s32, k, in32, in32_neg, "_mm512_mask_mov_epi32");
}

void NOINLINE do_blendmq() {
  V512 res;
  V512 expected;
  __mmask8 k = 0xA4;

  res.zmmi = _mm512_mask_blend_epi64(k, in64.zmmi, in64_neg.zmmi);
  CHECK_BLENDM(8, 8, s64, k, in64, in64_neg, "_mm512_mask_blend_epi64");
  res.zmmi = _mm512_mask_mov_epi64(in64.zmmi, k, in64_neg.zmmi);
  CHECK_BLENDM(8, 8, s64, k, in64, in64_neg, "_mm512_mask_mov_epi64");
}

void NOINLINE do_unpckqdq_hi() {
  V512 res;
  V512 expected;
  __mmask8 k8 = 0xFF;

  res.zmmi = _mm512_unpackhi_epi64(in64.zmmi, in64_neg.zmmi);
  CHECK_UNPCKH64(4, in64_mix, k8, 0, "_mm512_unpackhi_epi64");

  k8 = 0x4A;
  res.zmmi =
      _mm512_mask_unpackhi_epi64(in64_mix.zmmi, k8, in64.zmmi, in64_neg.zmmi);
  CHECK_UNPCKH64(4, in64_mix, k8, 0, "_mm512_mask_unpackhi_epi64");

  res.zmmi = _mm512_maskz_unpackhi_epi64(k8, in64.zmmi, in64_neg.zmmi);
  CHECK_UNPCKH64(4, in64_mix, k8, 1, "_mm512_maskz_unpackhi_epi64");
}

void NOINLINE do_unpckpd_hi() {
  V512 res;
  V512 expected;
  __mmask8 k8 = 0xFF;

  res.xmmd[vol0] = _mm_unpackhi_pd(in64.xmmd[vol0], in64_neg.xmmd[vol0]);
  CHECK_UNPCKH64(1, in64_mix, k8, 0, "_mm_unpackhi_pd");
  res.ymmd[vol0] = _mm256_unpackhi_pd(in64.ymmd[vol0], in64_neg.ymmd[vol0]);
  CHECK_UNPCKH64(2, in64_mix, k8, 0, "_mm256_unpackhi_pd");
  res.zmmd = _mm512_unpackhi_pd(in64.zmmd, in64_neg.zmmd);
  CHECK_UNPCKH64(4, in64_mix, k8, 0, "_mm512_unpackhi_pd");

  k8 = 0x4A;
  res.zmmd = _mm512_mask_unpackhi_pd(in64_mix.zmmd, k8, in64.zmmd, in64_neg.zmmd);
  CHECK_UNPCKH64(4, in64_mix, k8, 0, "_mm512_mask_unpackhi_pd");

  res.zmmd = _mm512_maskz_unpackhi_pd(k8, in64.zmmd, in64_neg.zmmd);
  CHECK_UNPCKH64(4, in64_mix, k8, 1, "_mm512_maskz_unpackhi_pd");
}

void NOINLINE do_shuf_ps() {
  V512 res;
  V512 expected;
  volatile int i, lane;
  __mmask16 k = 0x7e95;
#define PS_IMM 0x5c

  res.zmm = _mm512_shuffle_ps(in32.zmm, in32_neg.zmm, PS_IMM);

  for (lane = 0; lane < 4; lane++) {
    for (i = 0; i < 1; i++) {
      expected.s32[4 * lane + i] = in32.s32[4 * lane + (PS_IMM & 3)];
      expected.s32[4 * lane + i + 1] = in32.s32[4 * lane + ((PS_IMM >> 2) & 3)];
      expected.s32[4 * lane + 2 + i] =
          in32_neg.s32[4 * lane + ((PS_IMM >> 4) & 3)];
      expected.s32[4 * lane + 2 + i + 1] =
          in32_neg.s32[4 * lane + ((PS_IMM >> 6) & 3)];
    }
  }

  check_equal_nd(&res, &expected, 16, "_mm512_shuffle_ps", __LINE__);

  res.zmmi = _mm512_setzero_epi32();
  res.zmm = _mm512_mask_shuffle_ps(res.zmm, k, in32.zmm, in32_neg.zmm, PS_IMM);

  expected.zmmi = _mm512_setzero_epi32();
  for (lane = 0; lane < 4; lane++) {
    for (i = 0; i < 1; i++) {
      int m = 4 * lane;
      if ((1 << (m + i)) & k) {
        expected.s32[m + i] = in32.s32[m + (PS_IMM & 3)];
      }
      if ((1 << (m + i + 1)) & k) {
        expected.s32[m + i + 1] = in32.s32[m + ((PS_IMM >> 2) & 3)];
      }
      if ((1 << (m + 2 + i)) & k) {
        expected.s32[m + 2 + i] = in32_neg.s32[m + ((PS_IMM >> 4) & 3)];
      }
      if ((1 << (m + 2 + i + 1)) & k) {
        expected.s32[m + 2 + i + 1] = in32_neg.s32[m + ((PS_IMM >> 6) & 3)];
      }
    }
  }

  check_equal_nd(&res, &expected, 16, "_mm512_mask_shuffle_ps", __LINE__);
}

void NOINLINE do_unpckdq_hi() {
  V512 res;
  V512 expected;
  __mmask16 k = 0xFFFF;

  res.zmmi = _mm512_unpackhi_epi32(in32.zmmi, in32_neg.zmmi);
  CHECK_UNPCKH32(4, in32_mix, k, 0, "_mm512_unpackhi_epi32");

  k = 0xA4A4;
  res.zmmi = _mm512_mask_unpackhi_epi32(in32_mix.zmmi, k, in32.zmmi, in32_neg.zmmi);
  CHECK_UNPCKH32(4, in32_mix, k, 0, "_mm512_mask_unpackhi_epi32");

  res.zmmi = _mm512_maskz_unpackhi_epi32(k, in32.zmmi, in32_neg.zmmi);
  CHECK_UNPCKH32(4, in32_mix, k, 1, "_mm512_maskz_unpackhi_epi32");
}

void NOINLINE do_shuf_pd() {
  V512 res;
  V512 expected;
  volatile int i, lane;
  __mmask8 k = 0xba;
#define PD_IMM 0x7b

  res.zmmd = _mm512_shuffle_pd(in64.zmmd, in64_neg.zmmd, PD_IMM);

  for (lane = 0; lane < 4; lane++) {
    int m = 2 * lane;
    for (i = 0; i < 1; i++) {
      expected.s64[m + i] = in64.s64[m + ((PD_IMM >> m) & 1)];
      expected.s64[m + i + 1] = in64_neg.s64[m + ((PD_IMM >> (m + 1)) & 1)];
    }
  }

  check_equal_nd(&res, &expected, 16, "_mm512_shuffle_pd", __LINE__);

  res.zmmi = _mm512_setzero_epi32();
  res.zmmd =
      _mm512_mask_shuffle_pd(res.zmmd, k, in64.zmmd, in64_neg.zmmd, PD_IMM);

  expected.zmmi = _mm512_setzero_epi32();
  for (lane = 0; lane < 4; lane++) {
    int m = 2 * lane;
    for (i = 0; i < 1; i++) {
      if ((1 << (m + i)) & k) {
        expected.s64[m + i] = in64.s64[m + ((PD_IMM >> m) & 1)];
      }
      if ((1 << (m + i + 1)) & k) {
        expected.s64[m + i + 1] = in64_neg.s64[m + ((PD_IMM >> (m + 1)) & 1)];
      }
    }
  }

  check_equal_nd(&res, &expected, 16, "_mm512_mask_shuffle_pd", __LINE__);
}

void NOINLINE do_shuf_f32x4() {
  V512 res;
  V512 expected;
  V512 tmp;
  volatile int i, j, lane;
  __mmask16 k = 0x7e95;
#define F32X4_IMM 0x5c

  res.zmm = _mm512_shuffle_f32x4(in32.zmm, in32_neg.zmm, F32X4_IMM);

  // This code was copied from shuffle_ps, need to update for f32x4.
  for (lane = 0; lane < 4; lane++) {
    j = ((F32X4_IMM >> 2 * lane) & 0x3);
    if (lane < 2) {
      expected.xmmi[lane] = in32.xmmi[j];
    } else {
      expected.xmmi[lane] = in32_neg.xmmi[j];
    }
  }

  check_equal_nd(&res, &expected, 16, "_mm512_shuffle_f32x4", __LINE__);

  res.zmmi = _mm512_setzero_epi32();
  res.zmm =
      _mm512_mask_shuffle_f32x4(res.zmm, k, in32.zmm, in32_neg.zmm, F32X4_IMM);

  expected.zmmi = _mm512_setzero_epi32();
  for (lane = 0; lane < 4; lane++) {
    int m = 4 * lane;
    j = ((F32X4_IMM >> 2 * lane) & 0x3);
    if (lane < 2) {
      tmp.xmmi[lane] = in32.xmmi[j];
    } else {
      tmp.xmmi[lane] = in32_neg.xmmi[j];
    }

    for (i = 0; i < 4; i++) {
      if ((1 << (m + i)) & k) {
        expected.s32[m + i] = tmp.s32[m + i];
      }
    }
  }

  check_equal_nd(&res, &expected, 16, "_mm512_mask_shuffle_f32x4", __LINE__);
}

void NOINLINE do_blendmpd() {
  V512 res;
  V512 expected;
  __mmask8 k = 0x4A;

  soft_update(in64_neg);
  res.zmmd = _mm512_mask_blend_pd(k, in64.zmmd, in64_neg.zmmd);
  CHECK_BLENDM(8, 8, s64, k, in64, in64_neg, "_mm512_mask_blend_pd");
  res.zmmd = _mm512_mask_mov_pd(in64.zmmd, k, in64_neg.zmmd);
  CHECK_BLENDM(8, 8, s64, k, in64, in64_neg, "_mm512_mask_blend_pd");
}

void NOINLINE do_blendmps() {
  V512 res;
  V512 expected;
  __mmask16 k = 0xA44A;

  res.zmm = _mm512_mask_blend_ps(k, in32.zmm, in32_neg.zmm);
  CHECK_BLENDM(16, 4, s32, k, in32, in32_neg, "_mm512_mask_blend_ps");
  res.zmm = _mm512_mask_mov_ps(in32.zmm, k, in32_neg.zmm);
  CHECK_BLENDM(16, 4, s32, k, in32, in32_neg, "_mm512_mask_mov_ps");
}

int main(int argc, char *argv[]) {
  init();

  do_shuf_f32x4();
  do_shuf_pd();
  do_shuf_ps();

  do_unpckdq_hi();

  do_unpckps_lo();
  do_unpckps_hi();

  do_unpckdq_lo();
  do_unpckqdq_lo();

  do_unpckpd_lo();
  do_unpckpd_hi();

  do_unpckqdq_hi();

  do_blendmd();
  do_blendmq();
  do_blendmpd();
  do_blendmps();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
