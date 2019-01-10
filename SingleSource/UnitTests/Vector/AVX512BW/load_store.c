/*
 * Test load and store instructions.
 * Here we check for _mm512_[mask|maskz]_[loadu|storeu] intrinsics.
 */
#include "m512_test_util.h"

V512 src_vals[2];
V512 all_ones;
volatile int vol0 = 0;

void NOINLINE init() {
  volatile int i;
  int j;

  for (i = 0; i < sizeof(src_vals) / sizeof(src_vals[0]); i++) {
    for (j = 0; j < 16; j++) {
      src_vals[i].s32[j] = 16 * i + j;
    }
  }

  for (i = 0; i < 16; i++) {
    all_ones.s32[i] = -1;
  }
}

void NOINLINE do_loadu() {
  V512 res;
  V512 expected;
  __mmask64 k64 = 0xfbde79feffeeffee;
  __mmask32 k32 = 0xbfde79fe;
  __mmask16 k16 = 0xbfde;
  __mmask8 k8 = 0xaf;
  volatile int i;
  signed char *p8 = &src_vals[0].s8[0];
  short *p16 = &src_vals[0].s16[0];
  int *p = &src_vals[0].s32[0];
  __int64 *p64 = &src_vals[0].s64[0];

  res.zmm = _mm512_loadu_ps(&src_vals[0].s32[1]);
  for (i = 0; i < 16; i++) {
    expected.s32[i] = p[i + 1];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_loadu_ps", __LINE__);

  res.zmmd = _mm512_loadu_pd(&src_vals[0].s32[2]);
  for (i = 0; i < 16; i++) {
    expected.s32[i] = p[i + 2];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_loadu_pd", __LINE__);

  res.zmmi = _mm512_loadu_si512(&src_vals[0].s32[3]);
  for (i = 0; i < 16; i++) {
    expected.s32[i] = p[i + 3];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_loadu_si512", __LINE__);

  /* Now the write-masked versions. */

  res = all_ones;
  expected = all_ones;
  res.zmm = _mm512_mask_loadu_ps(res.zmm, k16, &src_vals[0].s32[5]);
  for (i = 0; i < 16; i++) {
    if ((1 << i) & k16) {
      expected.s32[i] = p[i + 5];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_loadu_ps", __LINE__);

  k64 += vol0;
  res = all_ones;
  expected = all_ones;
  res.zmmi = _mm512_mask_loadu_epi8(res.zmmi, k64, &src_vals[0].s8[7]);
  for (i = 0; i < 64; i++) {
    if (((__mmask64)1 << i) & k64) {
      expected.s8[i] = p8[i + 7];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_loadu_epi8", __LINE__);

  k64 += vol0;
  res = all_ones;
  expected.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_maskz_loadu_epi8(k64, &src_vals[0].s8[9]);
  for (i = 0; i < 64; i++) {
    if (((__mmask64)1 << i) & k64) {
      expected.s8[i] = p8[i + 9];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_loadu_epi8", __LINE__);

  k32 += vol0;
  res = all_ones;
  expected = all_ones;
  res.zmmi = _mm512_mask_loadu_epi16(res.zmmi, k32, &src_vals[0].s16[5]);
  for (i = 0; i < 32; i++) {
    if ((1 << i) & k32) {
      expected.s16[i] = p16[i + 5];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_loadu_epi16", __LINE__);

  k32 += vol0;
  res = all_ones;
  expected.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_maskz_loadu_epi16(k32, &src_vals[0].s16[3]);
  for (i = 0; i < 32; i++) {
    if ((1 << i) & k32) {
      expected.s16[i] = p16[i + 3];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_loadu_epi16", __LINE__);

  k16 = 0xabcd + vol0;
  res = all_ones;
  expected = all_ones;
  res.zmmi = _mm512_mask_loadu_epi32(res.zmmi, k16, &src_vals[0].s32[7]);
  for (i = 0; i < 16; i++) {
    if ((1 << i) & k16) {
      expected.s32[i] = p[i + 7];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_loadu_epi32", __LINE__);

  res = all_ones;
  expected = all_ones;
  res.zmmd = _mm512_mask_loadu_pd(res.zmmd, k8, &src_vals[0].s64[2]);
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k8) {
      expected.s64[i] = p64[i + 2];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_loadu_pd", __LINE__);

  k8 = 0x79 + vol0;
  res = all_ones;
  expected = all_ones;
  res.zmmi = _mm512_mask_loadu_epi64(res.zmmi, k8, &src_vals[0].s64[3]);
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k8) {
      expected.s64[i] = p64[i + 3];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_loadu_epi64", __LINE__);
}

void NOINLINE do_storeu() {
  V512 src;
  V512 expected;
  volatile int i;
  static V512 dst_vals[2];
  __mmask64 k64 = 0xabcdffffffffeebd;
  __mmask32 k32 = 0xfefebdbd;
  __mmask16 k16 = 0x79ab;
  __mmask8 k8 = 0xea;

  src.zmmi = src_vals[0].zmmi;

  dst_vals[0].zmm = _mm512_setzero_ps();
  dst_vals[1].zmm = _mm512_setzero_ps();
  _mm512_storeu_si512(&dst_vals[0].s32[1], src.zmmi);
  check_equal_nd(&dst_vals[0].s32[1], &src_vals, 16, "_mm512_storeu_si512",
                 __LINE__);

  dst_vals[0].zmm = _mm512_setzero_ps();
  dst_vals[1].zmm = _mm512_setzero_ps();
  _mm512_storeu_ps(&dst_vals[0].s32[2], src.zmm);
  check_equal_nd(&dst_vals[0].s32[2], &src_vals, 16, "_mm512_storeu_pd",
                 __LINE__);

  dst_vals[0].zmm = _mm512_setzero_ps();
  dst_vals[1].zmm = _mm512_setzero_ps();
  _mm512_storeu_pd(&dst_vals[0].s32[4], src.zmmd);
  check_equal_nd(&dst_vals[0].s32[4], &src_vals, 16, "_mm512_storeu_pd",
                 __LINE__);

  /* Now the write-masked versions. */

  dst_vals[0] = all_ones;
  dst_vals[1] = all_ones;
  _mm512_mask_storeu_epi8(&dst_vals[0].s8[3], k64, src.zmmi);
  expected = all_ones;
  for (i = 0; i < 64; i++) {
    if (((__mmask64)1 << i) & k64) {
      expected.s8[i] = src.s8[i];
    }
  }
  check_equal_nd(&dst_vals[0].s8[3], &expected, 16, "_mm512_mask_storeu_epi8",
                 __LINE__);

  dst_vals[0] = all_ones;
  dst_vals[1] = all_ones;
  _mm512_mask_storeu_epi16(&dst_vals[0].s16[3], k32, src.zmmi);
  expected = all_ones;
  for (i = 0; i < 32; i++) {
    if (((__mmask32)1 << i) & k32) {
      expected.s16[i] = src.s16[i];
    }
  }
  check_equal_nd(&dst_vals[0].s16[3], &expected, 16, "_mm512_mask_storeu_epi16",
                 __LINE__);

  dst_vals[0] = all_ones;
  dst_vals[1] = all_ones;
  _mm512_mask_storeu_epi32(&dst_vals[0].s32[1], k16, src.zmmi);
  expected = all_ones;
  for (i = 0; i < 16; i++) {
    if ((1 << i) & k16) {
      expected.s32[i] = src.s32[i];
    }
  }
  check_equal_nd(&dst_vals[0].s32[1], &expected, 16, "_mm512_mask_storeu_epi32",
                 __LINE__);

  k16 = 0xdcba + vol0;
  dst_vals[0] = all_ones;
  dst_vals[1] = all_ones;
  _mm512_mask_storeu_ps(&dst_vals[0].s32[3], k16, src.zmm);
  expected = all_ones;
  for (i = 0; i < 16; i++) {
    if ((1 << i) & k16) {
      expected.s32[i] = src.s32[i];
    }
  }
  check_equal_nd(&dst_vals[0].s32[3], &expected, 16, "_mm512_mask_storeu_ps",
                 __LINE__);

  k8 = 0xbc;
  dst_vals[0] = all_ones;
  dst_vals[1] = all_ones;
  _mm512_mask_storeu_pd(&dst_vals[0].s64[3], k8, src.zmmd);
  expected = all_ones;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k8) {
      expected.s64[i] = src.s64[i];
    }
  }
  check_equal_nd(&dst_vals[0].s64[3], &expected, 16, "_mm512_mask_storeu_pd",
                 __LINE__);

  k8 = 0xcb + vol0;
  dst_vals[0] = all_ones;
  dst_vals[1] = all_ones;
  _mm512_mask_storeu_epi64(&dst_vals[0].s64[1], k8, src.zmmi);
  expected = all_ones;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k8) {
      expected.s64[i] = src.s64[i];
    }
  }
  check_equal_nd(&dst_vals[0].s64[1], &expected, 16, "_mm512_mask_storeu_epi64",
                 __LINE__);
}

int main(int argc, char *argv[]) {
  init();

  do_loadu();
  do_storeu();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
