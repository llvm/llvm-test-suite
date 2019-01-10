/*
 * Test the "set" intrinsics.
 *
 * This test was created to check the correctness
 * of the following intrinsics support:
 * _mm_mask_set1_epi*
 * _mm_maskz_set1_epi*
 * _mm256_mask_set1_epi*
 * _mm256_maskz_set1_epi*
 * _mm512_mask_set1_epi*
 * _mm512_maskz_set1_epi*
 * _mm512_set1_epi*
 */

#include "m512_test_util.h"

volatile int vol0 = 0;

/* Some scalars that can be ciscized. */

unsigned char char6 = 6;
unsigned short short7 = 7;
int int11 = 11;
__int64 int64_13 = 13;

void NOINLINE invalidate_scalars() {
  /* Make compiler think these variables could have an arbitrary value. */
  char6 += vol0;
  short7 += vol0;
  int11 += vol0;
  int64_13 += vol0;
}

void NOINLINE do_set1_epi8() {
  V512 res, xres, yres;
  V512 expected;
  __mmask64 k = 0xffeebb97abcdffe9;
  __mmask32 k32 = (__mmask32)k;
  __mmask16 k16 = (__mmask16)k32;
  int i;

  res.zmmi = _mm512_set1_epi8(9);
  expected.zmmi = _mm512_set1_epi32(0x09090909);
  check_equal_nd(&res, &expected, 16, "_mm512_set1_epi8", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_set1_epi8(char6);
  expected.zmmi = _mm512_set1_epi32(0x06060606);
  check_equal_nd(&res, &expected, 16, "_mm512_set1_epi8 unknown", __LINE__);

  invalidate_scalars();

  /* Masked */
  res.zmmi = _mm512_set1_epi32(-1);

  xres.xmmi[0] = _mm_mask_set1_epi8(res.xmmi[0], k16, 14);
  yres.ymmi[0] = _mm256_mask_set1_epi8(res.ymmi[0], k32, 14);
  res.zmmi = _mm512_mask_set1_epi8(res.zmmi, k, 14);

  expected.zmmi = _mm512_set1_epi32(0x0e0e0e0e);
  for (i = 0; i < 64; i++) {
    if ((k & ((__mmask64)1 << i)) == 0) {
      expected.s8[i] = -1;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_set1_epi8", __LINE__);
  check_equal_nd(&yres, &expected, 8, "_mm256_mask_set1_epi8", __LINE__);
  check_equal_nd(&xres, &expected, 4, "_mm_mask_set1_epi8", __LINE__);

  invalidate_scalars();
  /* Zero masked */

  res.zmmi = _mm512_maskz_set1_epi8(k, 19);
  xres.xmmi[0] = _mm_maskz_set1_epi8(k16, 19);
  yres.ymmi[0] = _mm256_maskz_set1_epi8(k32, 19);

  expected.zmmi = _mm512_set1_epi32(0x13131313);
  for (i = 0; i < 64; i++) {
    if ((k & ((__mmask64)1 << i)) == 0) {
      expected.s8[i] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_set1_epi8", __LINE__);
  check_equal_nd(&yres, &expected, 8, "_mm256_maskz_set1_epi8", __LINE__);
  check_equal_nd(&xres, &expected, 4, "_mm_maskz_set1_epi8", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_maskz_set1_epi8(k, char6);
  expected.zmmi = _mm512_set1_epi32(0x06060606);
  for (i = 0; i < 64; i++) {
    if ((k & ((__mmask64)1 << i)) == 0) {
      expected.s8[i] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_set1_epi8 unknown",
                 __LINE__);
}

void NOINLINE do_set1_epi16() {
  V512 res, xres, yres;
  V512 expected;
  __mmask32 k = 0xabcdffe9;
  __mmask16 k16 = (__mmask16)k;
  __mmask8 k8 = (__mmask8)k16;
  int i;

  res.zmmi = _mm512_set1_epi16(9);
  expected.zmmi = _mm512_set1_epi32((9 << 16) | 9);
  check_equal_nd(&res, &expected, 16, "_mm512_set1_epi16", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_set1_epi16(short7);
  expected.zmmi = _mm512_set1_epi32((7 << 16) | 7);
  check_equal_nd(&res, &expected, 16, "_mm512_set1_epi16 unknown", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_set1_epi32(-1);

  xres.xmmi[0] = _mm_mask_set1_epi16(res.xmmi[0], k8, 14);
  yres.ymmi[0] = _mm256_mask_set1_epi16(res.ymmi[0], k16, 14);
  res.zmmi = _mm512_mask_set1_epi16(res.zmmi, k, 14);

  expected.zmmi = _mm512_set1_epi32((14 << 16) | 14);
  for (i = 0; i < 32; i++) {
    if ((k & (1 << i)) == 0) {
      expected.s16[i] = -1;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_set1_epi16", __LINE__);
  check_equal_nd(&yres, &expected, 8, "_mm256_mask_set1_epi16", __LINE__);
  check_equal_nd(&xres, &expected, 4, "_mm_mask_set1_epi16", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_maskz_set1_epi16(k, 19);
  xres.xmmi[0] = _mm_maskz_set1_epi16(k8, 19);
  yres.ymmi[0] = _mm256_maskz_set1_epi16(k16, 19);

  expected.zmmi = _mm512_set1_epi32((19 << 16) | 19);
  for (i = 0; i < 32; i++) {
    if ((k & (1 << i)) == 0) {
      expected.s16[i] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_set1_epi16", __LINE__);
  check_equal_nd(&yres, &expected, 8, "_mm256_maskz_set1_epi16", __LINE__);
  check_equal_nd(&xres, &expected, 4, "_mm_maskz_set1_epi16", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_maskz_set1_epi16(k, short7);
  expected.zmmi = _mm512_set1_epi32((7 << 16) | 7);
  for (i = 0; i < 32; i++) {
    if ((k & (1 << i)) == 0) {
      expected.s16[i] = 0;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_set1_epi16 unknown",
                 __LINE__);
}

void NOINLINE do_set1_epi32() {
  V512 res, xres, yres;
  V512 expected;
  __mmask16 k = 0xf7e6;
  __mmask8 k8 = (__mmask8)k;
  volatile int i;

  res.zmmi = _mm512_set1_epi32(9);
  for (i = 0; i < 16; i++) {
    expected.s32[i] = 9;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_set1_epi32", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_set1_epi32(int11);
  for (i = 0; i < 16; i++) {
    expected.s32[i] = 11;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_set1_epi32 unknown", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_set1_epi32(-1);
  xres.xmmi[0] = _mm_mask_set1_epi32(res.xmmi[0], k8, 14);
  yres.ymmi[0] = _mm256_mask_set1_epi32(res.ymmi[0], k8, 14);
  res.zmmi = _mm512_mask_set1_epi32(res.zmmi, k, 14);

  for (i = 0; i < 16; i++) {
    if ((k & (1 << i)) == 0) {
      expected.s32[i] = -1;
    } else {
      expected.s32[i] = 14;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_set1_epi32", __LINE__);
  check_equal_nd(&yres, &expected, 8, "_mm256_mask_set1_epi32", __LINE__);
  check_equal_nd(&xres, &expected, 4, "_mm_mask_set1_epi32", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_maskz_set1_epi32(k, 19);
  xres.xmmi[0] = _mm_maskz_set1_epi32(k8, 19);
  yres.ymmi[0] = _mm256_maskz_set1_epi32(k8, 19);

  for (i = 0; i < 16; i++) {
    if ((k & (1 << i)) == 0) {
      expected.s32[i] = 0;
    } else {
      expected.s32[i] = 19;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_set1_epi32", __LINE__);
  check_equal_nd(&yres, &expected, 8, "_mm256_maskz_set1_epi32", __LINE__);
  check_equal_nd(&xres, &expected, 4, "_mm_maskz_set1_epi32", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_maskz_set1_epi32(k, int11);
  for (i = 0; i < 16; i++) {
    if ((k & (1 << i)) == 0) {
      expected.s32[i] = 0;
    } else {
      expected.s32[i] = 11;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_set1_epi32 unknown",
                 __LINE__);
}

void NOINLINE do_set1_epi64() {
  V512 res, xres, yres;
  V512 expected;
  __mmask8 k = 0xe7;
  volatile int i;

  res.zmmi = _mm512_set1_epi64(9);
  for (i = 0; i < 8; i++) {
    expected.s64[i] = 9;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_set1_epi64", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_set1_epi64(int64_13);
  for (i = 0; i < 8; i++) {
    expected.s64[i] = 13;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_set1_epi64 unknown", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_set1_epi64(-1);
  xres.xmmi[0] = _mm_mask_set1_epi64(res.xmmi[0], k, 14);
  yres.ymmi[0] = _mm256_mask_set1_epi64(res.ymmi[0], k, 14);
  res.zmmi = _mm512_mask_set1_epi64(res.zmmi, k, 14);
  for (i = 0; i < 8; i++) {
    if ((k & (1 << i)) == 0) {
      expected.s64[i] = -1;
    } else {
      expected.s64[i] = 14;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_set1_epi64", __LINE__);
  check_equal_nd(&yres, &expected, 8, "_mm256_mask_set1_epi64", __LINE__);
  check_equal_nd(&xres, &expected, 4, "_mm_mask_set1_epi64", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_maskz_set1_epi64(k, 19);
  xres.xmmi[0] = _mm_maskz_set1_epi64(k, 19);
  yres.ymmi[0] = _mm256_maskz_set1_epi64(k, 19);
  for (i = 0; i < 8; i++) {
    if ((k & (1 << i)) == 0) {
      expected.s64[i] = 0;
    } else {
      expected.s64[i] = 19;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_set1_epi64", __LINE__);
  check_equal_nd(&yres, &expected, 8, "_mm256_maskz_set1_epi64", __LINE__);
  check_equal_nd(&xres, &expected, 4, "_mm_maskz_set1_epi64", __LINE__);

  invalidate_scalars();

  res.zmmi = _mm512_maskz_set1_epi64(k, int64_13);
  for (i = 0; i < 8; i++) {
    if ((k & (1 << i)) == 0) {
      expected.s64[i] = 0;
    } else {
      expected.s64[i] = 13;
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_set1_epi64 unknown",
                 __LINE__);
}

int main(int argc, char *argv[]) {
  do_set1_epi8();
  do_set1_epi16();
  do_set1_epi32();
  do_set1_epi64();

  if (n_errs) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
