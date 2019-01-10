/*
 * Test intrinsics related to integer down-converting instructions
 * like vpmovdb, where the source values are in an __m128i value.
 *
 * This test was created to check the correctness
 * of the following AVX512 intrinsics support:
 *_mm_cvtepi*
 *_mm_cvtsepi*
 *_mm_cvtusepi*
 *_mm_mask_cvtepi*
 *_mm_mask_cvtsepi*
 *_mm_mask_cvtusepi*
 *_mm_maskz_cvtepi*
 *_mm_maskz_cvtsepi*
 *_mm_maskz_cvtusepi*
 */

#include "m512_test_util.h"
#include <limits.h>

volatile int vol0 = 0;

#define soft_src_update(var) var.xmmi[vol0] = var.xmmi[vol0]

V512 i8;
V512 i16;
V512 i16_mix;
V512 i16_big;
V512 i32;
V512 i32_mix;
V512 i32_big;
V512 i64;
V512 i64_mix;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 64; i++) {
    i8.s8[i] = i;
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
  }
}

/* Saturation utility functions for emulation. */

static signed char NOINLINE sat16_8(short s) {
  return (s < -128) ? -128 : ((s > 127) ? 127 : s);
}

static unsigned char NOINLINE usat16_8(unsigned short s) {
  return (s > 255) ? 255 : s;
}

static signed char NOINLINE sat32_8(int s) {
  return (s < -128) ? -128 : ((s > 127) ? 127 : s);
}

static unsigned char usat32_8(unsigned int s) { return (s > 255) ? 255 : s; }

static short NOINLINE sat32_16(int s) {
  return (s < (int)0xffff8000) ? (int)0xffff8000
                               : ((s > (int)0x7fff) ? (int)0x7fff : s);
}

static unsigned short NOINLINE usat32_16(unsigned int s) {
  return (s > (unsigned int)0xffff) ? (unsigned int)0xffff : s;
}

static signed char NOINLINE sat64_8(__int64 s) {
  return (s < -128) ? -128 : ((s > 127) ? 127 : s);
}

static unsigned char NOINLINE usat64_8(unsigned __int64 s) {
  return (s > 255) ? 255 : s;
}

static short NOINLINE sat64_16(__int64 s) {
  return (s < SHRT_MIN) ? SHRT_MIN : ((s > SHRT_MAX) ? SHRT_MAX : s);
}

static unsigned short NOINLINE usat64_16(unsigned __int64 s) {
  return (s > USHRT_MAX) ? USHRT_MAX : s;
}

static int NOINLINE sat64_32(__int64 s) {
  return (s < INT_MIN) ? INT_MIN : ((s > INT_MAX) ? INT_MAX : s);
}

static unsigned int NOINLINE usat64_32(unsigned __int64 s) {
  return (s > UINT_MAX) ? UINT_MAX : s;
}

void NOINLINE do_pmovwb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xdb;

  res.xmmi[0] = _mm_cvtepi16_epi8(i16.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 8; i++) {
    expected.s8[i] = i16.s16[i];
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtepi16_epi8", __LINE__);

  soft_src_update(i16);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtepi16_epi8(res.xmmi[1], k, i16.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i16.s16[i];
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtepi16_epi8", __LINE__);

  soft_src_update(i16);
  res.xmmi[0] = _mm_maskz_cvtepi16_epi8(k, i16.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i16.s16[i];
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtepi16_epi8", __LINE__);

  soft_src_update(i16);
  res.xmmi[vol0] = i16_big.xmmi[0];
  _mm_mask_cvtepi16_storeu_epi8(&res.xmmi[0], k, i16.xmmi[0]);
  expected.xmmi[0] = i16_big.xmmi[0];
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i16.s16[i];
    }
  }

  check_equal_nd(&res, &expected, 2, "_mm_mask_cvtepi16_storeu_epi8", __LINE__);
}

void NOINLINE do_pmovswb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xdc;

  res.xmmi[0] = _mm_cvtsepi16_epi8(i16_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 8; i++) {
    expected.s8[i] = sat16_8(i16_mix.s16[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtsepi16_epi8", __LINE__);

  soft_src_update(i16_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtsepi16_epi8(res.xmmi[1], k, i16_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = sat16_8(i16_mix.s16[i]);
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtsepi16_epi8", __LINE__);

  soft_src_update(i16_mix);
  res.xmmi[0] = _mm_maskz_cvtsepi16_epi8(k, i16_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = sat16_8(i16_mix.s16[i]);
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtsepi16_epi8", __LINE__);

  soft_src_update(i16_mix);
  res.xmmi[vol0] = i16_big.xmmi[0];
  _mm_mask_cvtsepi16_storeu_epi8(&res.xmmi[0], k, i16_mix.xmmi[0]);
  expected.xmmi[0] = i16_big.xmmi[0];
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = sat16_8(i16_mix.s16[i]);
    }
  }

  check_equal_nd(&res, &expected, 2, "_mm_mask_cvtsepi16_storeu_epi8",
                 __LINE__);
}

void NOINLINE do_pmovuswb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xfd;

  res.xmmi[0] = _mm_cvtusepi16_epi8(i16_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 8; i++) {
    expected.s8[i] = usat16_8(i16_mix.u16[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtusepi16_epi8", __LINE__);

  soft_src_update(i16_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtusepi16_epi8(res.xmmi[1], k, i16_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = usat16_8(i16_mix.u16[i]);
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtusepi16_epi8", __LINE__);

  soft_src_update(i16_mix);
  res.xmmi[0] = _mm_maskz_cvtusepi16_epi8(k, i16_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = usat16_8(i16_mix.u16[i]);
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtusepi16_epi8", __LINE__);

  soft_src_update(i16_mix);
  res.xmmi[vol0] = i16_big.xmmi[0];
  _mm_mask_cvtusepi16_storeu_epi8(&res.xmmi[0], k, i16_mix.xmmi[0]);
  expected.xmmi[0] = i16_big.xmmi[0];
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = usat16_8(i16_mix.u16[i]);
    }
  }

  check_equal_nd(&res, &expected, 2, "_mm_mask_cvtusepi16_storeu_epi8",
                 __LINE__);
}

void NOINLINE do_pmovdb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xab;

  res.xmmi[0] = _mm_cvtepi32_epi8(i32.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 4; i++) {
    expected.s8[i] = i32.s32[i];
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtepi32_epi8", __LINE__);

  soft_src_update(i32);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtepi32_epi8(res.xmmi[1], k, i32.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i32.s32[i];
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtepi32_epi8", __LINE__);

  soft_src_update(i32);
  res.xmmi[0] = _mm_maskz_cvtepi32_epi8(k, i32.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i32.s32[i];
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtepi32_epi8", __LINE__);

  soft_src_update(i32);
  res.xmmi[vol0] = i32_big.xmmi[0];
  _mm_mask_cvtepi32_storeu_epi8(&res.xmmi[0], k, i32.xmmi[0]);
  expected.xmmi[0] = i32_big.xmmi[0];
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i32.s32[i];
    }
  }

  check_equal_nd(&res, &expected, 1, "_mm_mask_cvtepi32_storeu_epi8", __LINE__);
}

void NOINLINE do_pmovsdb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xdb;

  res.xmmi[0] = _mm_cvtsepi32_epi8(i32_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 4; i++) {
    expected.s8[i] = sat32_8(i32_mix.s32[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtsepi32_epi8", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtsepi32_epi8(res.xmmi[1], k, i32_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = sat32_8(i32_mix.s32[i]);
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtsepi32_epi8", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[0] = _mm_maskz_cvtsepi32_epi8(k, i32_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = sat32_8(i32_mix.s32[i]);
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtsepi32_epi8", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[vol0] = i32_big.xmmi[0];
  _mm_mask_cvtsepi32_storeu_epi8(&res.xmmi[0], k, i32_mix.xmmi[0]);
  expected.xmmi[0] = i32_big.xmmi[0];
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = sat32_8(i32_mix.s32[i]);
    }
  }

  check_equal_nd(&res, &expected, 1, "_mm_mask_cvtsepi32_storeu_epi8",
                 __LINE__);
}

void NOINLINE do_pmovusdb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xfd;

  res.xmmi[0] = _mm_cvtusepi32_epi8(i32_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 4; i++) {
    expected.s8[i] = usat32_8(i32_mix.u32[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtusepi32_epi8", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtusepi32_epi8(res.xmmi[1], k, i32_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = usat32_8(i32_mix.u32[i]);
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtusepi32_epi8", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[0] = _mm_maskz_cvtusepi32_epi8(k, i32_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = usat32_8(i32_mix.u32[i]);
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtusepi32_epi8", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[vol0] = i32_big.xmmi[0];
  _mm_mask_cvtusepi32_storeu_epi8(&res.xmmi[0], k, i32_mix.xmmi[0]);
  expected.xmmi[0] = i32_big.xmmi[0];
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = usat32_8(i32_mix.u32[i]);
    }
  }

  check_equal_nd(&res, &expected, 1, "_mm_mask_cvtusepi32_storeu_epi8",
                 __LINE__);
}

void NOINLINE do_pmovdw() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xcd;

  res.xmmi[0] = _mm_cvtepi32_epi16(i32.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 4; i++) {
    expected.s16[i] = i32.s32[i];
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtepi32_epi16", __LINE__);

  soft_src_update(i32);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = i8.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtepi32_epi16(res.xmmi[1], k, i32.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = i32.s32[i];
    } else {
      expected.s16[i] = res.s16[8 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtepi32_epi16", __LINE__);

  soft_src_update(i32);
  res.xmmi[0] = _mm_maskz_cvtepi32_epi16(k, i32.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = i32.s32[i];
    } else {
      expected.s16[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtepi32_epi16", __LINE__);

  soft_src_update(i32);
  res.xmmi[vol0] = i8.xmmi[0];
  _mm_mask_cvtepi32_storeu_epi16(&res.xmmi[0], k, i32.xmmi[0]);
  expected.xmmi[0] = i8.xmmi[0];
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = i32.s32[i];
    }
  }

  check_equal_nd(&res, &expected, 2, "_mm_mask_cvtepi32_storeu_epi16",
                 __LINE__);
}

void NOINLINE do_pmovsdw() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xfe;

  res.xmmi[0] = _mm_cvtsepi32_epi16(i32_mix.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 4; i++) {
    expected.s16[i] = sat32_16(i32_mix.s32[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtsepi32_epi16", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtsepi32_epi16(res.xmmi[1], k, i32_mix.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = sat32_16(i32_mix.s32[i]);
    } else {
      expected.s16[i] = res.s16[8 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtsepi32_epi16", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[0] = _mm_maskz_cvtsepi32_epi16(k, i32_mix.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = sat32_16(i32_mix.s32[i]);
    } else {
      expected.s16[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtsepi32_epi16", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[vol0] = i8.xmmi[0];
  _mm_mask_cvtsepi32_storeu_epi16(&res.xmmi[0], k, i32_mix.xmmi[0]);
  expected.xmmi[0] = i8.xmmi[0];
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = sat32_16(i32_mix.s32[i]);
    }
  }

  check_equal_nd(&res, &expected, 2, "_mm_mask_cvtsepi32_storeu_epi16",
                 __LINE__);
}

void NOINLINE do_pmovusdw() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xfe;

  res.xmmi[0] = _mm_cvtusepi32_epi16(i32_mix.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 4; i++) {
    expected.u16[i] = usat32_16(i32_mix.u32[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtusepi32_epi16", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtusepi32_epi16(res.xmmi[1], k, i32_mix.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.u16[i] = usat32_16(i32_mix.u32[i]);
    } else {
      expected.u16[i] = res.u16[8 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtusepi32_epi16", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[0] = _mm_maskz_cvtusepi32_epi16(k, i32_mix.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.u16[i] = usat32_16(i32_mix.u32[i]);
    } else {
      expected.u16[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtusepi32_epi16", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[vol0] = i8.xmmi[0];
  _mm_mask_cvtusepi32_storeu_epi16(&res.xmmi[0], k, i32_mix.xmmi[0]);
  expected.xmmi[0] = i8.xmmi[0];
  for (i = 0; i < 4; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = usat32_16(i32_mix.s32[i]);
    }
  }

  check_equal_nd(&res, &expected, 2, "_mm_mask_cvtusepi32_storeu_epi16",
                 __LINE__);
}

void NOINLINE do_pmovqb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0x76;

  res.xmmi[0] = _mm_cvtepi64_epi8(i64.xmmi[0]);

  expected.u64[0] = 0;
  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    expected.s8[i] = i64.s64[i];
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtepi64_epi8", __LINE__);

  /*
   * Exercise ciscization.
   */

  _mm_store_sd(&res.f64[2], _mm_castsi128_pd(_mm_cvtepi64_epi8(i64.xmmi[0])));
  check_equal_nd(&res.f64[2], &expected, 2, "_mm_cvtepi64_epi8 ciscized",
                 __LINE__);

  soft_src_update(i64);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtepi64_epi8(res.xmmi[1], k, i64.xmmi[0]);

  expected.u64[0] = 0;
  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i64.s64[i];
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtepi64_epi8", __LINE__);

  soft_src_update(i64);
  res.xmmi[0] = _mm_maskz_cvtepi64_epi8(k, i64.xmmi[0]);

  expected.u64[0] = 0;
  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i64.s64[i];
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtepi64_epi8", __LINE__);

  soft_src_update(i64);
  res.xmmi[vol0] = i8.xmmi[0];
  _mm_mask_cvtepi64_storeu_epi8(&res.xmmi[0], k, i64.xmmi[0]);
  expected.xmmi[0] = i8.xmmi[0];
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i64.s64[i];
    }
  }

  check_equal_nd(&res, &expected, 1, "_mm_mask_cvtepi64_storeu_epi8", __LINE__);
}

void NOINLINE do_pmovsqb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0x67;

  res.xmmi[0] = _mm_cvtsepi64_epi8(i64_mix.xmmi[0]);

  expected.u64[0] = 0;
  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    expected.s8[i] = sat64_8(i64_mix.s64[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtsepi64_epi8", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtsepi64_epi8(res.xmmi[1], k, i64_mix.xmmi[0]);

  expected.u64[0] = 0;
  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = sat64_8(i64_mix.s64[i]);
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtsepi64_epi8", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[0] = _mm_maskz_cvtsepi64_epi8(k, i64_mix.xmmi[0]);

  expected.u64[0] = 0;
  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = sat64_8(i64_mix.s64[i]);
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtsepi64_epi8", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[vol0] = i8.xmmi[0];
  _mm_mask_cvtsepi64_storeu_epi8(&res.xmmi[0], k, i64_mix.xmmi[0]);
  expected.xmmi[0] = i8.xmmi[0];
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = sat64_8(i64_mix.s64[i]);
    }
  }

  check_equal_nd(&res, &expected, 1, "_mm_mask_cvtsepi64_storeu_epi8",
                 __LINE__);
}

void NOINLINE do_pmovusqb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0x67;

  res.xmmi[0] = _mm_cvtusepi64_epi8(i64_mix.xmmi[0]);

  expected.u64[0] = 0;
  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    expected.u8[i] = (i64_mix.u64[i] > 255) ? 255 : i64_mix.u64[i];
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtusepi64_epi8", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtusepi64_epi8(res.xmmi[1], k, i64_mix.xmmi[0]);

  expected.u64[0] = 0;
  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = usat64_8(i64_mix.u64[i]);
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtusepi64_epi8", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[0] = _mm_maskz_cvtusepi64_epi8(k, i64_mix.xmmi[0]);

  expected.u64[0] = 0;
  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = usat64_8(i64_mix.u64[i]);
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtusepi64_epi8", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[vol0] = i8.xmmi[0];
  _mm_mask_cvtusepi64_storeu_epi8(&res.xmmi[0], k, i64_mix.xmmi[0]);
  expected.xmmi[0] = i8.xmmi[0];
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = usat64_8(i64_mix.u64[i]);
    }
  }

  check_equal_nd(&res, &expected, 1, "_mm_mask_cvtusepi64_storeu_epi8",
                 __LINE__);
}

void NOINLINE do_pmovqw() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xe9;

  res.xmmi[0] = _mm_cvtepi64_epi16(i64.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 2; i++) {
    expected.s16[i] = i64.s64[i];
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtepi64_epi16", __LINE__);

  soft_src_update(i64);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtepi64_epi16(res.xmmi[1], k, i64.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = i64.s64[i];
    } else {
      expected.s16[i] = res.s16[8 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtepi64_epi16", __LINE__);

  soft_src_update(i64);
  res.xmmi[0] = _mm_maskz_cvtepi64_epi16(k, i64.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = i64.s64[i];
    } else {
      expected.s16[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtepi64_epi16", __LINE__);

  soft_src_update(i64);
  res.xmmi[vol0] = i8.xmmi[0];
  _mm_mask_cvtepi64_storeu_epi16(&res.xmmi[0], k, i64.xmmi[0]);
  expected.xmmi[0] = i8.xmmi[0];
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = i64.s64[i];
    }
  }

  check_equal_nd(&res, &expected, 1, "_mm_mask_cvtepi64_storeu_epi16",
                 __LINE__);
}

void NOINLINE do_pmovsqw() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xe9;

  res.xmmi[0] = _mm_cvtsepi64_epi16(i64_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 2; i++) {
    expected.s16[i] = sat64_16(i64_mix.s64[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtsepi64_epi16", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtsepi64_epi16(res.xmmi[1], k, i64_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = sat64_16(i64_mix.s64[i]);
    } else {
      expected.s16[i] = res.s16[8 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtsepi64_epi16", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[0] = _mm_maskz_cvtsepi64_epi16(k, i64_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = sat64_16(i64_mix.s64[i]);
    } else {
      expected.s16[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtsepi64_epi16", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[vol0] = i8.xmmi[0];
  _mm_mask_cvtsepi64_storeu_epi16(&res.xmmi[0], k, i64_mix.xmmi[0]);
  expected.xmmi[0] = i8.xmmi[0];
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = sat64_16(i64_mix.s64[i]);
    }
  }

  check_equal_nd(&res, &expected, 1, "_mm_mask_cvtsepi64_storeu_epi16",
                 __LINE__);
}

void NOINLINE do_pmovusqw() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xe9;
  unsigned __int64 r;

  res.xmmi[0] = _mm_cvtusepi64_epi16(i64_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 2; i++) {
    expected.s16[i] = usat64_16(i64_mix.u64[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtusepi64_epi16", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtusepi64_epi16(res.xmmi[1], k, i64_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = usat64_16(i64_mix.u64[i]);
    } else {
      expected.s16[i] = res.s16[8 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtusepi64_epi16", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[0] = _mm_maskz_cvtusepi64_epi16(k, i64_mix.xmmi[0]);

  expected.u64[1] = 0;
  expected.u64[0] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = usat64_16(i64_mix.u64[i]);
    } else {
      expected.s16[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtusepi64_epi16", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[vol0] = i8.xmmi[0];
  _mm_mask_cvtusepi64_storeu_epi16(&res.xmmi[0], k, i64_mix.xmmi[0]);
  expected.xmmi[0] = i8.xmmi[0];
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = usat64_16(i64_mix.u64[i]);
    }
  }

  check_equal_nd(&res, &expected, 1, "_mm_mask_cvtusepi64_storeu_epi16",
                 __LINE__);
}

void NOINLINE do_pmovqd() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xcf;

  res.xmmi[0] = _mm_cvtepi64_epi32(i64.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    expected.s32[i] = i64.s64[i];
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtepi64_epi32", __LINE__);

  soft_src_update(i64);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = i8.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtepi64_epi32(res.xmmi[1], k, i64.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s32[i] = i64.s64[i];
    } else {
      expected.s32[i] = res.s32[4 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtepi64_epi32", __LINE__);

  soft_src_update(i64);
  res.xmmi[0] = _mm_maskz_cvtepi64_epi32(k, i64.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s32[i] = i64.s64[i];
    } else {
      expected.s32[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtepi64_epi32", __LINE__);

  soft_src_update(i64);
  res.xmmi[vol0] = i8.xmmi[0];
  _mm_mask_cvtepi64_storeu_epi32(&res.xmmi[0], k, i64.xmmi[0]);
  expected.xmmi[0] = i8.xmmi[0];
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s32[i] = i64.s64[i];
    }
  }

  check_equal_nd(&res, &expected, 2, "_mm_mask_cvtepi64_storeu_epi32",
                 __LINE__);
}

void NOINLINE do_pmovsqd() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xcf;

  res.xmmi[0] = _mm_cvtsepi64_epi32(i64_mix.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    expected.s32[i] = sat64_32(i64_mix.s64[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtsepi64_epi32", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = i8.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtsepi64_epi32(res.xmmi[1], k, i64_mix.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s32[i] = sat64_32(i64_mix.s64[i]);
    } else {
      expected.s32[i] = res.s32[4 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtsepi64_epi32", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[0] = _mm_maskz_cvtsepi64_epi32(k, i64_mix.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s32[i] = sat64_32(i64_mix.s64[i]);
    } else {
      expected.s32[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtsepi64_epi32", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[vol0] = i8.xmmi[0];
  _mm_mask_cvtsepi64_storeu_epi32(&res.xmmi[0], k, i64_mix.xmmi[0]);
  expected.xmmi[0] = i8.xmmi[0];
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s32[i] = sat64_32(i64_mix.s64[i]);
    }
  }

  check_equal_nd(&res, &expected, 2, "_mm_mask_cvtsepi64_storeu_epi32",
                 __LINE__);
}

void NOINLINE do_pmovusqd() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xcf;

  res.xmmi[0] = _mm_cvtusepi64_epi32(i64_mix.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    expected.u32[i] = usat64_32(i64_mix.u64[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm_cvtusepi64_epi32", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = i8.xmmi[1];
  res.xmmi[0] = _mm_mask_cvtusepi64_epi32(res.xmmi[1], k, i64_mix.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.u32[i] = usat64_32(i64_mix.u64[i]);
    } else {
      expected.s32[i] = res.s32[4 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_mask_cvtusepi64_epi32", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[0] = _mm_maskz_cvtusepi64_epi32(k, i64_mix.xmmi[0]);

  expected.u64[1] = 0;
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.u32[i] = usat64_32(i64_mix.u64[i]);
    } else {
      expected.s32[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm_maskz_cvtusepi64_epi32", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[vol0] = i8.xmmi[0];
  _mm_mask_cvtusepi64_storeu_epi32(&res.xmmi[0], k, i64_mix.xmmi[0]);
  expected.xmmi[0] = i8.xmmi[0];
  for (i = 0; i < 2; i++) {
    if ((1 << i) & k) {
      expected.s32[i] = usat64_32(i64_mix.u64[i]);
    }
  }

  check_equal_nd(&res, &expected, 2, "_mm_mask_cvtusepi64_storeu_epi32",
                 __LINE__);
}

int main(int argc, char *argv[]) {
  init();

  do_pmovwb();
  do_pmovswb();
  do_pmovuswb();

  do_pmovdb();
  do_pmovsdb();
  do_pmovusdb();

  do_pmovdw();
  do_pmovsdw();
  do_pmovusdw();

  do_pmovqb();
  do_pmovsqb();
  do_pmovusqb();

  do_pmovqw();
  do_pmovsqw();
  do_pmovusqw();

  do_pmovqd();
  do_pmovsqd();
  do_pmovusqd();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
