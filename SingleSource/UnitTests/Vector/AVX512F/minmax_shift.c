/*
 * Test min, max and shift instructions
 * This test was created to check the correctness
 * of the following intrinsics support:
 *      _mm512_[mask|maskz]_[abs|min|max]
 *      _mm512_[mask|maskz]_[sll|slli|srai|srli|sra|srl]_*
 *      _mm512_[mask|maskz]_cvtep*_ep*
 *      _mm256_cvtepi16_epi64
 *      _mm256_sll
 *      _mm_cvtepi16_epi64
 *      _mm_sll
 */
#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

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
volatile int vol0 = 0;
/*
 * Use this between tests to make compiler think src was updated.
 * Prevents PRE'ing of a load of src, thus allowing ciscization.
 */
#define soft_update(src) (src).xmmi[vol0] = (src).xmmi[vol0]

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 64; i++) {
    i8.s8[i] = i;
    i8_mix.s8[i] = (i & 1) ? i : -i;
    i8_big.s8[i] = 1000 * (i + 1);
    if ((i & 1) != 0) {
      i8_big.s8[i] = -i8_big.s8[i];
    }
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

void NOINLINE do_absd() {
  V512 res;
  V512 expected;
  __mmask16 k;

  res.zmmi = _mm512_abs_epi32(i32_mix.zmmi);
  check_equal_nd(&res, &i32, 16, "_mm512_abs_epi32", __LINE__);

  k = 0x1234;
  res.zmmi = _mm512_mask_abs_epi32(_mm512_setzero_epi32(), k, i32_mix.zmmi);
  expected.zmmi = _mm512_mask_mov_epi32(_mm512_setzero_epi32(), k, i32.zmmi);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_abs_epi32", __LINE__);
}

void NOINLINE do_absq() {
  V512 res;
  V512 expected;
  __mmask8 k;

  res.zmmi = _mm512_abs_epi64(i64_mix.zmmi);
  check_equal_nd(&res, &i64, 16, "_mm512_abs_epi64", __LINE__);

  k = 0x73;
  res.zmmi = _mm512_mask_abs_epi64(_mm512_setzero_epi32(), k, i64_mix.zmmi);
  expected.zmmi = _mm512_mask_mov_epi64(_mm512_setzero_epi32(), k, i64.zmmi);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_abs_epi64", __LINE__);
}

void NOINLINE do_movsxwq() {
  V512 xres, yres, zres;
  V512 expected, expected_save;
  volatile int i;
  __mmask8 k8 = 0xe7;

  /* Non-masked. */

  zres.zmmi = _mm512_cvtepi16_epi64(i16_mix.xmmi[0]);
  for (i = 0; i < 8; i++) {
    expected.s64[i] = i16_mix.s16[i];
  }
  expected_save = expected;
  soft_update(i16_mix);
  soft_update(i16_mix);
  check_equal_nd(&zres, &expected, 16, "_mm512_cvtepi16_epi64", __LINE__);
  check_equal_nd(&yres, &expected, 8, "_mm256_cvtepi16_epi64", __LINE__);
  check_equal_nd(&xres, &expected, 4, "_mm_cvtepi16_epi64", __LINE__);

  /* Masked. */

  soft_update(i16_mix);
  zres.zmmi = _mm512_setzero_epi32();
  yres = zres;
  xres = zres;
  zres.zmmi = _mm512_mask_cvtepi16_epi64(zres.zmmi, k8, i16_mix.xmmi[0]);
  expected = expected_save;
  for (i = 0; i < 8; i++) {
    if ((k8 & (1 << i)) == 0) {
      expected.s64[i] = 0;
    }
  }
  soft_update(i16_mix);
  soft_update(i16_mix);
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_cvtepi16_epi64", __LINE__);

  /* Zero-masked. */

  zres = i8_mix;
  yres = zres;
  xres = zres;
  soft_update(i16_mix);
  zres.zmmi = _mm512_maskz_cvtepi16_epi64(k8, i16_mix.xmmi[0]);
  for (i = 0; i < 8; i++) {
    if ((k8 & (1 << i)) == 0) {
      expected.s64[i] = 0;
    }
  }
  soft_update(i16_mix);
  soft_update(i16_mix);
  soft_update(i16_mix);
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_cvtepi16_epi64", __LINE__);
}

void NOINLINE do_movsxdq() {
  V512 xres, yres, zres;
  V512 expected;
  __mmask8 k8 = 0x5d;

  /* Non-masked. */

  zres.zmmi = _mm512_cvtepi32_epi64(i32_mix.ymmi[0]);
  expected.zmmi = _mm512_set_epi64(7, -6, 5, -4, 3, -2, 1, 0);
  check_equal_nd(&zres, &expected, 16, "_mm512_cvtepi32_epi64", __LINE__);

  /* Masked. */

  soft_update(i32_mix);
  zres.zmmi = _mm512_setzero_epi32();
  yres = zres;
  xres = zres;
  zres.zmmi = _mm512_mask_cvtepi32_epi64(zres.zmmi, k8, i32_mix.ymmi[0]);
  expected.zmmi = _mm512_set_epi64(0, -6, 0, -4, 3, -2, 0, 0);
  soft_update(i32_mix);
  soft_update(i32_mix);
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_cvtepi32_epi64", __LINE__);

  /* Zero-masked. */

  k8 = 0x79;
  soft_update(i32_mix);
  zres = i8_mix;
  yres = zres;
  xres = zres;
  zres.zmmi = _mm512_maskz_cvtepi32_epi64(k8, i32_mix.ymmi[0]);
  soft_update(i32_mix);
  soft_update(i32_mix);
  expected.zmmi = _mm512_set_epi64(7, -6, 5, -4, 3, -2, 1, 0);
  expected.zmmi = _mm512_maskz_mov_epi64(k8, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_cvtepi32_epi64", __LINE__);
}

void NOINLINE do_movsxbd() {
  V512 xres, yres, zres;
  V512 expected, expected_save;
  volatile int i;
  __mmask16 k16 = 0xfefe;
  __mmask8 k8 = (__mmask8)k16;

  /* Non-masked. */

  zres.zmmi = _mm512_cvtepi8_epi32(i8_mix.xmmi[0]);
  for (i = 0; i < 16; i++) {
    expected.s32[i] = i8_mix.s8[i];
  }
  expected_save = expected;
  check_equal_nd(&zres, &expected, 16, "_mm512_cvtepi8_epi32", __LINE__);
  soft_update(i8_mix);

  /* Masked. */

  soft_update(i8_mix);
  zres.zmmi = _mm512_setzero_epi32();
  yres = zres;
  xres = zres;
  zres.zmmi = _mm512_mask_cvtepi8_epi32(zres.zmmi, k16, i8_mix.xmmi[0]);
  expected = expected_save;
  for (i = 0; i < 16; i++) {
    if ((k16 & (1 << i)) == 0) {
      expected.s32[i] = 0;
    }
  }
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_cvtepi8_epi32", __LINE__);
  soft_update(i8_mix);

  /* Zero-masked. */

  soft_update(i8_mix);
  k16 <<= 1;
  k8 = (__mmask8)k16;
  zres.zmmi = _mm512_maskz_cvtepi8_epi32(k16, i8_mix.xmmi[0]);
  expected = expected_save;
  for (i = 0; i < 16; i++) {
    if ((k16 & (1 << i)) == 0) {
      expected.s32[i] = 0;
    }
  }
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_cvtepi8_epi32", __LINE__);
  soft_update(i8_mix);
}

void NOINLINE do_movsxbq() {
  V512 xres, yres, zres;
  V512 expected, expected_save;
  volatile int i;
  __mmask8 k8 = 0xfe;

  /* Non-masked. */

  zres.zmmi = _mm512_cvtepi8_epi64(i8_mix.xmmi[0]);
  for (i = 0; i < 8; i++) {
    expected.s64[i] = i8_mix.s8[i];
  }
  expected_save = expected;
  check_equal_nd(&zres, &expected, 16, "_mm512_cvtepi8_epi64", __LINE__);
  soft_update(i8_mix);

  /* Masked. */

  soft_update(i8_mix);
  zres.zmmi = _mm512_setzero_epi32();
  yres = zres;
  xres = zres;
  zres.zmmi = _mm512_mask_cvtepi8_epi64(zres.zmmi, k8, i8_mix.xmmi[0]);
  expected = expected_save;
  for (i = 0; i < 8; i++) {
    if ((k8 & (1 << i)) == 0) {
      expected.s64[i] = 0;
    }
  }
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_cvtepi8_epi64", __LINE__);
  soft_update(i8_mix);

  /* Zero-masked. */

  soft_update(i8_mix);
  k8 <<= 1;
  zres.zmmi = _mm512_maskz_cvtepi8_epi64(k8, i8_mix.xmmi[0]);
  expected = expected_save;
  for (i = 0; i < 8; i++) {
    if ((k8 & (1 << i)) == 0) {
      expected.s64[i] = 0;
    }
  }
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_cvtepi8_epi64", __LINE__);
  soft_update(i8_mix);
}

void NOINLINE do_movzxwd() {
  V512 xres, yres, zres;
  V512 expected;
  __mmask16 k16 = 0xc936;
  __mmask8 k8 = (__mmask8)k16;
  ;

  /* Non-masked. */

  zres.zmmi = _mm512_cvtepu16_epi32(i16_mix.ymmi[0]);
  expected.zmmi =
      _mm512_set_epi32(15, 0xfff2, 13, 0xfff4, 11, 0xfff6, 9, 0xfff8, 7, 0xfffa,
                       5, 0xfffc, 3, 0xfffe, 1, 0);
  check_equal_nd(&zres, &expected, 16, "_mm512_cvtepu16_epi32", __LINE__);

  /* Masked. */

  soft_update(i16_mix);
  zres.zmmi = _mm512_setzero_epi32();
  yres = zres;
  xres = zres;
  zres.zmmi = _mm512_mask_cvtepu16_epi32(zres.zmmi, k16, i16_mix.ymmi[0]);
  expected.zmmi = _mm512_set_epi32(15, 0xfff2, 0, 0, 11, 0, 0, 0xfff8, 0, 0, 5,
                                   0xfffc, 0, 0xfffe, 1, 0);
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_cvtepu16_epi32", __LINE__);

  /* Zero-masked. */

  zres = i8_mix;
  yres = zres;
  xres = zres;
  soft_update(i16_mix);
  zres.zmmi = _mm512_maskz_cvtepu16_epi32(k16, i16_mix.ymmi[0]);
  expected.zmmi =
      _mm512_set_epi32(15, 0xfff2, 13, 0xfff4, 11, 0xfff6, 9, 0xfff8, 7, 0xfffa,
                       5, 0xfffc, 3, 0xfffe, 1, 0);
  expected.zmmi = _mm512_maskz_mov_epi32(k16, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_cvtepu16_epi32", __LINE__);
}

void NOINLINE do_movzxwq() {
  V512 xres, yres, zres;
  V512 expected, expected_save;
  volatile int i;
  __mmask8 k8 = 0xe7;

  /* Non-masked. */

  zres.zmmi = _mm512_cvtepu16_epi64(i16_mix.xmmi[0]);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = i16_mix.u16[i];
  }
  expected_save = expected;
  soft_update(i16_mix);
  check_equal_nd(&zres, &expected, 16, "_mm512_cvtepu16_epi64", __LINE__);

  /* Masked. */

  soft_update(i16_mix);
  zres.zmmi = _mm512_setzero_epi32();
  yres = zres;
  xres = zres;
  zres.zmmi = _mm512_mask_cvtepu16_epi64(zres.zmmi, k8, i16_mix.xmmi[0]);
  expected = expected_save;
  for (i = 0; i < 8; i++) {
    if ((k8 & (1 << i)) == 0) {
      expected.u64[i] = 0;
    }
  }
  soft_update(i16_mix);
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_cvtepu16_epi64", __LINE__);

  /* Zero-masked. */

  zres = i8_mix;
  yres = zres;
  xres = zres;
  soft_update(i16_mix);
  zres.zmmi = _mm512_maskz_cvtepu16_epi64(k8, i16_mix.xmmi[0]);
  for (i = 0; i < 8; i++) {
    if ((k8 & (1 << i)) == 0) {
      expected.u64[i] = 0;
    }
  }
  soft_update(i16_mix);
  soft_update(i16_mix);
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_cvtepu16_epi64", __LINE__);
}

void NOINLINE do_movzxdq() {
  V512 xres, yres, zres;
  V512 expected;
  __mmask8 k8 = 0xeb;

  /* Non-masked. */

  zres.zmmi = _mm512_cvtepu32_epi64(i32_mix.ymmi[0]);
  expected.zmmi = _mm512_set_epi64(7, (unsigned int)-6, 5, (unsigned int)-4, 3,
                                   (unsigned int)-2, 1, 0);
  soft_update(i32_mix);
  check_equal_nd(&zres, &expected, 16, "_mm512_cvtepu32_epi64", __LINE__);

  /* Masked. */

  soft_update(i32_mix);
  zres.zmmi = _mm512_setzero_epi32();
  yres = zres;
  xres = zres;
  zres.zmmi = _mm512_mask_cvtepu32_epi64(zres.zmmi, k8, i32_mix.ymmi[0]);
  expected.zmmi = _mm512_set_epi64(0, -6, 0, -4, 3, -2, 0, 0);
  expected.zmmi = _mm512_set_epi64(7, (unsigned int)-6, 5, 0, 3, 0, 1, 0);
  soft_update(i32_mix);
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_cvtepu32_epi64", __LINE__);

  /* Zero-masked. */

  k8 = 0xe7;
  soft_update(i32_mix);
  zres = i8_mix;
  yres = zres;
  xres = zres;
  zres.zmmi = _mm512_maskz_cvtepu32_epi64(k8, i32_mix.ymmi[0]);
  soft_update(i32_mix);
  expected.zmmi = _mm512_set_epi64(7, (unsigned int)-6, 5, (unsigned int)-4, 3,
                                   (unsigned int)-2, 1, 0);
  expected.zmmi = _mm512_maskz_mov_epi64(k8, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_cvtepu32_epi64", __LINE__);
}

void NOINLINE do_movzxbd() {
  V512 xres, yres, zres;
  V512 expected, expected_save;
  volatile int i;
  __mmask16 k16 = 0xfefe;
  __mmask8 k8 = (__mmask8)k16;

  /* Non-masked. */

  zres.zmmi = _mm512_cvtepu8_epi32(i8_mix.xmmi[0]);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = i8_mix.u8[i];
  }
  expected_save = expected;
  check_equal_nd(&zres, &expected, 16, "_mm512_cvtepu8_epi32", __LINE__);
  soft_update(i8_mix);

  /* Masked. */

  soft_update(i8_mix);
  zres.zmmi = _mm512_setzero_epi32();
  yres = zres;
  xres = zres;
  zres.zmmi = _mm512_mask_cvtepu8_epi32(zres.zmmi, k16, i8_mix.xmmi[0]);
  expected = expected_save;
  for (i = 0; i < 16; i++) {
    if ((k16 & (1 << i)) == 0) {
      expected.u32[i] = 0;
    }
  }
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_cvtepu8_epi32", __LINE__);
  soft_update(i8_mix);

  /* Zero-masked. */

  soft_update(i8_mix);
  k16 <<= 1;
  k8 = (__mmask8)k16;
  zres.zmmi = _mm512_maskz_cvtepu8_epi32(k16, i8_mix.xmmi[0]);
  expected = expected_save;
  for (i = 0; i < 16; i++) {
    if ((k16 & (1 << i)) == 0) {
      expected.u32[i] = 0;
    }
  }
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_cvtepu8_epi32", __LINE__);
  soft_update(i8_mix);
}

void NOINLINE do_movzxbq() {
  V512 xres, yres, zres;
  V512 expected, expected_save;
  volatile int i;
  __mmask8 k8 = 0xfe;

  /* Non-masked. */

  zres.zmmi = _mm512_cvtepu8_epi64(i8_mix.xmmi[0]);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = i8_mix.u8[i];
  }
  expected_save = expected;
  check_equal_nd(&zres, &expected, 16, "_mm512_cvtepu8_epi64", __LINE__);
  soft_update(i8_mix);

  /* Masked. */

  soft_update(i8_mix);
  zres.zmmi = _mm512_setzero_epi32();
  yres = zres;
  xres = zres;
  zres.zmmi = _mm512_mask_cvtepu8_epi64(zres.zmmi, k8, i8_mix.xmmi[0]);
  expected = expected_save;
  for (i = 0; i < 8; i++) {
    if ((k8 & (1 << i)) == 0) {
      expected.u64[i] = 0;
    }
  }
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_cvtepu8_epi64", __LINE__);
  soft_update(i8_mix);

  /* Zero-masked. */

  soft_update(i8_mix);
  k8 <<= 1;
  zres.zmmi = _mm512_maskz_cvtepu8_epi64(k8, i8_mix.xmmi[0]);
  expected = expected_save;
  for (i = 0; i < 8; i++) {
    if ((k8 & (1 << i)) == 0) {
      expected.u64[i] = 0;
    }
  }
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_cvtepu8_epi64", __LINE__);
  soft_update(i8_mix);
}

void NOINLINE do_maxsd() {
  V512 res;
  V512 expected;
  __mmask8 k = 0x5d;

  res.zmmi = _mm512_max_epi32(i32.zmmi, i32_mix.zmmi);
  check_equal_nd(&res, &i32, 16, "_mm512_max_epi32", __LINE__);

  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_max_epi32(res.zmmi, k, i32.zmmi, i32_mix.zmmi);
  expected.zmm = _mm512_mask_mov_ps(_mm512_setzero_ps(), k, i32.zmm);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_max_epi32", __LINE__);
}

void NOINLINE do_maxud() {
  V512 res;
  V512 expected;
  __mmask16 k = 0x5d;

  res.zmmi = _mm512_max_epu32(i32.zmmi, i32_mix.zmmi);
  check_equal_nd(&res, &i32_mix, 16, "_mm512_max_epu32", __LINE__);

  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_max_epu32(res.zmmi, k, i32.zmmi, i32_mix.zmmi);
  expected.zmm = _mm512_mask_mov_ps(_mm512_setzero_ps(), k, i32_mix.zmm);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_max_epu32", __LINE__);
}

void NOINLINE do_minsd() {
  V512 res;
  V512 expected;
  __mmask8 k = 0x5d;

  res.zmmi = _mm512_min_epi32(i32.zmmi, i32_mix.zmmi);
  check_equal_nd(&res, &i32_mix, 16, "_mm512_min_epi32", __LINE__);

  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_min_epi32(res.zmmi, k, i32.zmmi, i32_mix.zmmi);
  expected.zmm = _mm512_mask_mov_ps(_mm512_setzero_ps(), k, i32_mix.zmm);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_min_epi32", __LINE__);
}

void NOINLINE do_minud() {
  V512 res;
  V512 expected;
  __mmask16 k = 0x5d;

  res.zmmi = _mm512_min_epu32(i32.zmmi, i32_mix.zmmi);
  check_equal_nd(&res, &i32, 16, "_mm512_min_epu32", __LINE__);

  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_min_epu32(res.zmmi, k, i32.zmmi, i32_mix.zmmi);
  expected.zmm = _mm512_mask_mov_ps(_mm512_setzero_ps(), k, i32.zmm);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_min_epu32", __LINE__);
}

void NOINLINE do_pslld() {
  V512 res;
  V512 vcount;
  V512 expected;
  volatile int i;
  int count = 7;
  __mmask16 k;
  __mmask8 k8;

  i = 0;
  vcount.zmm = _mm512_setzero_ps();
  vcount.u64[i] = count;

  res.zmmi = _mm512_sll_epi32(i32_big.zmmi, vcount.xmmi[0]);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = (count > 31) ? 0 : (i32_big.u32[i] << count);
  }
  check_equal_nd(&res, &expected, 16, "_mm512_sll_epi32", __LINE__);

  soft_update(vcount);
  res.ymmi[0] = _mm256_sll_epi32(i32_big.ymmi[0], vcount.xmmi[0]);
  check_equal_nd(&res, &expected, 8, "_mm256_sll_epi32", __LINE__);

  soft_update(vcount);
  res.xmmi[0] = _mm_sll_epi32(i32_big.xmmi[0], vcount.xmmi[0]);
  check_equal_nd(&res, &expected, 4, "_mm_sll_epi32", __LINE__);

  k = 0x7fdb;
  k8 = (__mmask8)k;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_sll_epi32(res.zmmi, k, i32_mix.zmmi, vcount.xmmi[0]);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u32[i] = (count > 31) ? 0 : (i32_mix.u32[i] << count);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_sll_epi32", __LINE__);

  soft_update(vcount);
  res.ymmi[0] = _mm256_setzero_si256();

  soft_update(vcount);
  res.xmmi[0] = _mm_setzero_si128();

  res = i8_mix;
  res.zmmi = _mm512_maskz_sll_epi32(k, i32_mix.zmmi, vcount.xmmi[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_sll_epi32", __LINE__);

  soft_update(vcount);
  res = i8_mix;

  soft_update(vcount);
  res = i8_mix;
}

void NOINLINE do_psllq() {
  V512 res;
  V512 vcount;
  V512 expected;
  volatile int i;
  int count = 7;
  __mmask8 k;

  i = 0;
  vcount.zmm = _mm512_setzero_ps();
  vcount.u64[i] = count;

  res.zmmi = _mm512_sll_epi64(i64_big.zmmi, vcount.xmmi[0]);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = (count > 63) ? 0 : (i64_big.u64[i] << count);
  }
  check_equal_nd(&res, &expected, 16, "_mm512_sll_epi64", __LINE__);

  soft_update(vcount);
  res.ymmi[0] = _mm256_sll_epi64(i64_big.ymmi[0], vcount.xmmi[0]);
  check_equal_nd(&res, &expected, 8, "_mm256_sll_epi64", __LINE__);

  soft_update(vcount);
  res.xmmi[0] = _mm_sll_epi64(i64_big.xmmi[0], vcount.xmmi[0]);
  check_equal_nd(&res, &expected, 4, "_mm_sll_epi64", __LINE__);

  k = 0xc3;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_sll_epi64(res.zmmi, k, i64_mix.zmmi, vcount.xmmi[0]);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u64[i] = (count > 63) ? 0 : (i64_mix.u64[i] << count);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_sll_epi64", __LINE__);

  soft_update(vcount);
  res.ymmi[0] = _mm256_setzero_si256();

  soft_update(vcount);
  res.xmmi[0] = _mm_setzero_si128();

  res = i8_mix;
  res.zmmi = _mm512_maskz_sll_epi64(k, i64_mix.zmmi, vcount.xmmi[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_sll_epi64", __LINE__);

  soft_update(vcount);
  res = i8_mix;

  soft_update(vcount);
  res = i8_mix;
}

void NOINLINE do_pslldi(int cnt) {
  V512 res;
  V512 expected;
  __mmask16 k;
  volatile int i;

  res.zmmi = _mm512_slli_epi32(i32_big.zmmi, 3);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = i32_big.u32[i] << 3;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_slli_epi32", __LINE__);

  k = 0x9786;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_slli_epi32(res.zmmi, k, i32_mix.zmmi, 6);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u32[i] = (i32_mix.u32[i] << 6);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_slli_epi32", __LINE__);

  res.zmmi = _mm512_slli_epi32(i32_big.zmmi, cnt);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = i32_big.u32[i] << cnt;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_slli_epi32", __LINE__);

  k = 0x9786;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_slli_epi32(res.zmmi, k, i32_mix.zmmi, cnt);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u32[i] = (i32_mix.u32[i] << cnt);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_slli_epi32", __LINE__);
}

void NOINLINE do_psllqi(int cnt) {
  V512 res;
  V512 expected;
  __mmask8 k;
  volatile int i;

  res.zmmi = _mm512_slli_epi64(i64_big.zmmi, 3);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = i64_big.u64[i] << 3;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_slli_epi64", __LINE__);

  k = 0x97;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_slli_epi64(res.zmmi, k, i64_mix.zmmi, 6);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u64[i] = (i64_mix.u64[i] << 6);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_slli_epi64", __LINE__);

  res.zmmi = _mm512_slli_epi64(i64_big.zmmi, cnt);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = i64_big.u64[i] << cnt;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_slli_epi64", __LINE__);

  k = 0x97;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_slli_epi64(res.zmmi, k, i64_mix.zmmi, cnt);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u64[i] = (i64_mix.u64[i] << cnt);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_slli_epi64", __LINE__);
}

void NOINLINE do_psradi(int cnt) {
  V512 res;
  V512 expected;
  __mmask16 k;
  volatile int i;

  res.zmmi = _mm512_srai_epi32(i32_big.zmmi, 3);
  for (i = 0; i < 16; i++) {
    expected.s32[i] = i32_big.s32[i] >> 3;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_srai_epi32", __LINE__);

  k = 0x9786;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_srai_epi32(res.zmmi, k, i32_mix.zmmi, 6);
  for (i = 0; i < 16; i++) {
    expected.s32[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.s32[i] = (i32_mix.s32[i] >> 6);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srai_epi32", __LINE__);

  res.zmmi = _mm512_srai_epi32(i32_big.zmmi, cnt);
  for (i = 0; i < 16; i++) {
    expected.s32[i] = i32_big.s32[i] >> cnt;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_srai_epi32", __LINE__);

  k = 0x9786;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_srai_epi32(res.zmmi, k, i32_mix.zmmi, cnt);
  for (i = 0; i < 16; i++) {
    expected.s32[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.s32[i] = (i32_mix.s32[i] >> cnt);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srai_epi32", __LINE__);
}

void NOINLINE do_psrldi(int cnt) {
  V512 res;
  V512 expected;
  __mmask16 k;
  volatile int i;

  res.zmmi = _mm512_srli_epi32(i32_big.zmmi, 3);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = i32_big.u32[i] >> 3;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_srli_epi32", __LINE__);

  k = 0x9786;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_srli_epi32(res.zmmi, k, i32_mix.zmmi, 6);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u32[i] = (i32_mix.u32[i] >> 6);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srli_epi32", __LINE__);

  res.zmmi = _mm512_srli_epi32(i32_big.zmmi, cnt);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = i32_big.u32[i] >> cnt;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_srli_epi32", __LINE__);

  k = 0x9786;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_srli_epi32(res.zmmi, k, i32_mix.zmmi, cnt);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u32[i] = (i32_mix.u32[i] >> cnt);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srli_epi32 #2", __LINE__);
}

void NOINLINE do_psraqi(int cnt) {
  V512 res;
  V512 expected;
  __mmask8 k;
  volatile int i;

  res.zmmi = _mm512_srai_epi64(i64_big.zmmi, 3);
  for (i = 0; i < 8; i++) {
    expected.s64[i] = i64_big.s64[i] >> 3;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_srai_epi64", __LINE__);

  k = 0x97;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_srai_epi64(res.zmmi, k, i64_mix.zmmi, 6);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.s64[i] = (i64_mix.s64[i] >> 6);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srai_epi64", __LINE__);

  res.zmmi = _mm512_srai_epi64(i64_big.zmmi, cnt);
  for (i = 0; i < 8; i++) {
    expected.s64[i] = i64_big.s64[i] >> cnt;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_srai_epi64", __LINE__);

  k = 0x97;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_srai_epi64(res.zmmi, k, i64_mix.zmmi, cnt);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.s64[i] = (i64_mix.s64[i] >> cnt);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srai_epi64", __LINE__);
}

void NOINLINE do_psrlqi(int cnt) {
  V512 res;
  V512 expected;
  __mmask8 k;
  volatile int i;

  res.zmmi = _mm512_srli_epi64(i64_big.zmmi, 3);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = i64_big.u64[i] >> 3;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_srli_epi64", __LINE__);

  k = 0x97;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_srli_epi64(res.zmmi, k, i64_mix.zmmi, 6);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u64[i] = (i64_mix.u64[i] >> 6);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srli_epi64", __LINE__);

  res.zmmi = _mm512_srli_epi64(i64_big.zmmi, cnt);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = i64_big.u64[i] >> cnt;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_srli_epi64", __LINE__);

  k = 0x97;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_srli_epi64(res.zmmi, k, i64_mix.zmmi, cnt);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u64[i] = (i64_mix.u64[i] >> cnt);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srli_epi64", __LINE__);
}

void NOINLINE do_psrad() {
  V512 res;
  V512 vcount;
  V512 expected;
  volatile int i;
  int count = 7;
  __mmask16 k;
  __mmask8 k8;

  i = 0;
  vcount.zmm = _mm512_setzero_ps();
  vcount.u64[i] = count;

  res.zmmi = _mm512_sra_epi32(i32_big.zmmi, vcount.xmmi[0]);
  for (i = 0; i < 16; i++) {
    expected.s32[i] = (count > 31) ? 0 : (i32_big.s32[i] >> count);
  }
  check_equal_nd(&res, &expected, 16, "_mm512_sra_epi32", __LINE__);

  k = 0x7fdb;
  k8 = (__mmask8)k;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_sra_epi32(res.zmmi, k, i32_mix.zmmi, vcount.xmmi[0]);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.s32[i] = (count > 31) ? 0 : (i32_mix.s32[i] >> count);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_sra_epi32", __LINE__);

  res = i8_mix;
  res.zmmi = _mm512_maskz_sra_epi32(k, i32_mix.zmmi, vcount.xmmi[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_sra_epi32", __LINE__);
}

void NOINLINE do_psrld() {
  V512 res;
  V512 vcount;
  V512 expected;
  volatile int i;
  int count = 7;
  __mmask16 k;
  __mmask8 k8;

  i = 0;
  vcount.zmm = _mm512_setzero_ps();
  vcount.u64[i] = count;

  res.zmmi = _mm512_srl_epi32(i32_big.zmmi, vcount.xmmi[0]);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = (count > 31) ? 0 : (i32_big.u32[i] >> count);
  }
  check_equal_nd(&res, &expected, 16, "_mm512_srl_epi32", __LINE__);

  k = 0x7fdb;
  k8 = (__mmask8)k;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_srl_epi32(res.zmmi, k, i32_mix.zmmi, vcount.xmmi[0]);
  for (i = 0; i < 16; i++) {
    expected.u32[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u32[i] = (count > 31) ? 0 : (i32_mix.u32[i] >> count);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srl_epi32", __LINE__);

  res = i8_mix;
  res.zmmi = _mm512_maskz_srl_epi32(k, i32_mix.zmmi, vcount.xmmi[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_srl_epi32", __LINE__);
}

void NOINLINE do_psraq() {
  V512 res;
  V512 vcount;
  V512 expected;
  volatile int i;
  int count = 7;
  __mmask8 k;

  i = 0;
  vcount.zmm = _mm512_setzero_ps();
  vcount.u64[i] = count;

  res.zmmi = _mm512_sra_epi64(i64_big.zmmi, vcount.xmmi[0]);
  for (i = 0; i < 8; i++) {
    expected.s64[i] = (count > 63) ? 0 : (i64_big.s64[i] >> count);
  }
  check_equal_nd(&res, &expected, 16, "_mm512_sra_epi64", __LINE__);

  k = 0xc3;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_sra_epi64(res.zmmi, k, i64_mix.zmmi, vcount.xmmi[0]);
  for (i = 0; i < 8; i++) {
    expected.s64[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.s64[i] = (count > 63) ? 0 : (i64_mix.s64[i] >> count);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_sra_epi64", __LINE__);

  res = i8_mix;
  res.zmmi = _mm512_maskz_sra_epi64(k, i64_mix.zmmi, vcount.xmmi[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_sra_epi64", __LINE__);
}

void NOINLINE do_psrlq() {
  V512 res;
  V512 vcount;
  V512 expected;
  volatile int i;
  int count = 7;
  __mmask8 k;

  i = 0;
  vcount.zmm = _mm512_setzero_ps();
  vcount.u64[i] = count;

  res.zmmi = _mm512_srl_epi64(i64_big.zmmi, vcount.xmmi[0]);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = (count > 63) ? 0 : (i64_big.u64[i] >> count);
  }
  check_equal_nd(&res, &expected, 16, "_mm512_srl_epi64", __LINE__);

  k = 0xc3;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_srl_epi64(res.zmmi, k, i64_mix.zmmi, vcount.xmmi[0]);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u64[i] = (count > 63) ? 0 : (i64_mix.u64[i] >> count);
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srl_epi64", __LINE__);

  res.zmmi = _mm512_maskz_srl_epi64(k, i64_mix.zmmi, vcount.xmmi[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_srl_epi64", __LINE__);

  soft_update(vcount);
  res = i8_mix;
}

void NOINLINE do_movsxwd() {
  V512 xres, yres, zres;
  V512 expected;
  __mmask16 k16 = 0x7e5d;
  __mmask8 k8 = (__mmask8)k16;
  ;

  /* Non-masked. */

  zres.zmmi = _mm512_cvtepi16_epi32(i16_mix.ymmi[0]);
  expected.zmmi = _mm512_set_epi32(15, -14, 13, -12, 11, -10, 9, -8, 7, -6, 5,
                                   -4, 3, -2, 1, 0);
  check_equal_nd(&zres, &expected, 16, "_mm512_cvtepi16_epi32", __LINE__);

  /* Masked. */

  soft_update(i16_mix);
  zres.zmmi = _mm512_setzero_epi32();
  yres = zres;
  xres = zres;
  zres.zmmi = _mm512_mask_cvtepi16_epi32(zres.zmmi, k16, i16_mix.ymmi[0]);
  expected.zmmi = _mm512_set_epi32(0, -14, 13, -12, 11, -10, 9, 0, 0, -6, 0, -4,
                                   3, -2, 0, 0);
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_cvtepi16_epi32", __LINE__);

  /* Zero-masked. */

  zres = i8_mix;
  yres = zres;
  xres = zres;
  soft_update(i16_mix);
  zres.zmmi = _mm512_maskz_cvtepi16_epi32(k16, i16_mix.ymmi[0]);
  expected.zmmi = _mm512_set_epi32(15, -14, 13, -12, 11, -10, 9, -8, 7, -6, 5,
                                   -4, 3, -2, 1, 0);
  expected.zmmi = _mm512_maskz_mov_epi32(k16, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_cvtepi16_epi32", __LINE__);
}

int main(int argc, char *argv[]) {
  int cnt;

  init();

  do_absd();
  do_absq();

  do_movsxwd();
  do_movsxdq();
  do_movsxbd();
  do_movsxbq();
  do_movzxwd();
  do_movzxwq();

  do_movzxbd();
  do_movzxbq();

  do_maxsd();
  do_maxud();
  do_minsd();
  do_minud();

  do_pslld();
  do_psllq();

  for (cnt = 0; cnt <= 8; cnt++) {
    do_pslldi(cnt);
    do_psradi(cnt);
    do_psrldi(cnt);

    do_psllqi(cnt);
    do_psraqi(cnt);
    do_psrlqi(cnt);
  }

  do_psrlq();
  do_psraq();
  do_psrld();
  do_psrad();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
