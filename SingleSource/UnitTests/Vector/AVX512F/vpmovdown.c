/*
 * Test intrinsics related to integer down-converting instructions
 * like vpmovdb.
 * This test was created to check the correctness
 * of the following intrinsics support:
 * _mm512_cvtepi*_epi*()
 * _mm512_mask_cvtepi*_epi*()
 * _mm512_maskz_cvtepi*_epi*()
 * _mm512_mask_cvtepi*_storeu_epi*()
 * _mm512_cvtsepi*_epi*()
 * _mm512_mask_cvtsepi*_epi*()
 * _mm512_maskz_cvtsepi*_epi*()
 * _mm512_mask_cvtsepi*_storeu_epi*()
 * _mm512_cvtusepi*_epi*()
 * _mm512_mask_cvtusepi*_epi*()
 * _mm512_maskz_cvtusepi*_epi*()
 * _mm512_mask_cvtusepi*_storeu_epi*()
 */

#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

volatile int vol0 = 0;

#define soft_src_update(var) var.xmmi[vol0] = var.xmmi[vol0]

V512 i8;
V512 i16;
V512 i32;
V512 i32_mix;
V512 i64;
V512 i64_mix;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 64; i++) {
    i8.s8[i] = i;
  }

  for (i = 0; i < 32; i++) {
    i16.s16[i] = i;
  }

  for (i = 0; i < 16; i++) {
    i32.s32[i] = i;
    i32_mix.s32[i] = (i & 1) ? i : -i;
  }

  for (i = 0; i < 8; i++) {
    i64.s64[i] = i;
    i64_mix.s64[i] = (i & 1) ? i : -i;
  }
}

void NOINLINE do_pmovdb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask16 k = 0x79ab;

  res.xmmi[0] = _mm512_cvtepi32_epi8(i32.zmmi);

  for (i = 0; i < 16; i++) {
    expected.s8[i] = i32.s32[i];
  }

  check_equal_nd(&res, &expected, 4, "_mm512_cvtepi32_epi8", __LINE__);

  soft_src_update(i32);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm512_mask_cvtepi32_epi8(res.xmmi[1], k, i32.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i32.s32[i];
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtepi32_epi8", __LINE__);

  soft_src_update(i32);
  res.xmmi[0] = _mm512_maskz_cvtepi32_epi8(k, i32.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i32.s32[i];
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_maskz_cvtepi32_epi8", __LINE__);

  soft_src_update(i32);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = res.xmmi[1];

  _mm512_mask_cvtepi32_storeu_epi8(&(res.xmmi[0]), k, i32.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i32.s32[i];
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtepi32_storeu_epi8",
                 __LINE__);
}

void NOINLINE do_pmovsdb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask16 k = 0xbadc;

  res.xmmi[0] = _mm512_cvtsepi32_epi8(i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    expected.s8[i] = (i32_mix.s32[i] < -128)
                         ? -128
                         : ((i32_mix.s32[i] > 127) ? 127 : i32_mix.s32[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm512_cvtsepi32_epi8", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm512_mask_cvtsepi32_epi8(res.xmmi[1], k, i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = (i32_mix.s32[i] < -128)
                           ? -128
                           : ((i32_mix.s32[i] > 127) ? 127 : i32_mix.s32[i]);
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtsepi32_epi8", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[0] = _mm512_maskz_cvtsepi32_epi8(k, i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = (i32_mix.s32[i] < -128)
                           ? -128
                           : ((i32_mix.s32[i] > 127) ? 127 : i32_mix.s32[i]);
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_maskz_cvtsepi32_epi8", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = res.xmmi[1];
  _mm512_mask_cvtsepi32_storeu_epi8(&(res.xmmi[0]), k, i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = (i32_mix.s32[i] < -128)
                           ? -128
                           : ((i32_mix.s32[i] > 127) ? 127 : i32_mix.s32[i]);
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtsepi32_storeu_epi8",
                 __LINE__);
}

void NOINLINE do_pmovusdb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask16 k = 0x57fd;

  res.xmmi[0] = _mm512_cvtusepi32_epi8(i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    expected.u8[i] = ((i32_mix.u32[i] > 255) ? 255 : i32_mix.u32[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm512_cvtusepi32_epi8", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm512_mask_cvtusepi32_epi8(res.xmmi[1], k, i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.u8[i] = ((i32_mix.u32[i] > 255) ? 255 : i32_mix.u32[i]);
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtusepi32_epi8", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[0] = _mm512_maskz_cvtusepi32_epi8(k, i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.u8[i] = ((i32_mix.u32[i] > 255) ? 255 : i32_mix.u32[i]);
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_maskz_cvtusepi32_epi8", __LINE__);

  soft_src_update(i32_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = res.xmmi[1];
  _mm512_mask_cvtusepi32_storeu_epi8(&(res.xmmi[0]), k, i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.u8[i] = ((i32_mix.u32[i] > 255) ? 255 : i32_mix.u32[i]);
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtusepi32_storeu_epi8",
                 __LINE__);
}

void NOINLINE do_pmovdw() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask16 k = 0x97cd;

  res.ymmi[0] = _mm512_cvtepi32_epi16(i32.zmmi);

  for (i = 0; i < 16; i++) {
    expected.s16[i] = i32.s32[i];
  }

  check_equal_nd(&res, &expected, 8, "_mm512_cvtepi32_epi16", __LINE__);

  soft_src_update(i32);
  res.ymmi[1] = i8.ymmi[0];
  res.ymmi[0] = i8.ymmi[1];
  res.ymmi[0] = _mm512_mask_cvtepi32_epi16(res.ymmi[1], k, i32.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = i32.s32[i];
    } else {
      expected.s16[i] = res.s16[16 + i]; // From res.ymmi[1].
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_mask_cvtepi32_epi16", __LINE__);

  soft_src_update(i32);
  res.ymmi[0] = _mm512_maskz_cvtepi32_epi16(k, i32.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = i32.s32[i];
    } else {
      expected.s16[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_maskz_cvtepi32_epi16", __LINE__);

  soft_src_update(i32);
  res.ymmi[1] = i8.ymmi[0];
  res.ymmi[0] = res.ymmi[1];
  _mm512_mask_cvtepi32_storeu_epi16(&(res.ymmi[0]), k, i32.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = i32.s32[i];
    } else {
      expected.s16[i] = res.s16[16 + i]; // From res.ymmi[1].
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_mask_cvtepi32_storeu_epi16",
                 __LINE__);
}

void NOINLINE do_pmovsdw() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask16 k = 0x63fe;

  res.ymmi[0] = _mm512_cvtsepi32_epi16(i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    expected.s16[i] =
        (i32_mix.s32[i] < (int)0xffff8000)
            ? (int)0xffff8000
            : ((i32_mix.s32[i] > (int)0x7fff) ? (int)0x7fff : i32_mix.s32[i]);
  }

  check_equal_nd(&res, &expected, 8, "_mm512_cvtsepi32_epi16", __LINE__);

  soft_src_update(i32_mix);
  res.ymmi[1] = i16.ymmi[0];
  res.ymmi[0] = i16.ymmi[1];
  res.ymmi[0] = _mm512_mask_cvtsepi32_epi16(res.ymmi[1], k, i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.s16[i] =
          (i32_mix.s32[i] < (int)0xffff8000)
              ? (int)0xffff8000
              : ((i32_mix.s32[i] > (int)0x7fff) ? (int)0x7fff : i32_mix.s32[i]);
    } else {
      expected.s16[i] = res.s16[16 + i]; // From res.ymmi[1].
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_mask_cvtsepi32_epi16", __LINE__);

  soft_src_update(i32_mix);
  res.ymmi[0] = _mm512_maskz_cvtsepi32_epi16(k, i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.s16[i] =
          (i32_mix.s32[i] < (int)0xffff8000)
              ? (int)0xffff8000
              : ((i32_mix.s32[i] > (int)0x7fff) ? (int)0x7fff : i32_mix.s32[i]);
    } else {
      expected.s16[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_maskz_cvtsepi32_epi16", __LINE__);

  soft_src_update(i32_mix);
  res.ymmi[1] = i16.ymmi[0];
  res.ymmi[0] = res.ymmi[1];
  _mm512_mask_cvtsepi32_storeu_epi16(&(res.ymmi[0]), k, i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.s16[i] =
          (i32_mix.s32[i] < (int)0xffff8000)
              ? (int)0xffff8000
              : ((i32_mix.s32[i] > (int)0x7fff) ? (int)0x7fff : i32_mix.s32[i]);
    } else {
      expected.s16[i] = res.s16[16 + i]; // From res.ymmi[1].
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_mask_cvtsepi32_storeu_epi16",
                 __LINE__);
}

void NOINLINE do_pmovusdw() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask16 k = 0x63fe;

  res.ymmi[0] = _mm512_cvtusepi32_epi16(i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    expected.u16[i] =
        (i32_mix.u32[i] > (int)0xffff) ? (int)0xffff : i32_mix.u32[i];
  }

  check_equal_nd(&res, &expected, 8, "_mm512_cvtusepi32_epi16", __LINE__);

  soft_src_update(i32_mix);
  res.ymmi[1] = i16.ymmi[0];
  res.ymmi[0] = i16.ymmi[1];
  res.ymmi[0] = _mm512_mask_cvtusepi32_epi16(res.ymmi[1], k, i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.u16[i] =
          (i32_mix.u32[i] > (int)0xffff) ? (int)0xffff : i32_mix.u32[i];
    } else {
      expected.u16[i] = res.u16[16 + i]; // From res.ymmi[1].
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_mask_cvtusepi32_epi16", __LINE__);

  soft_src_update(i32_mix);
  res.ymmi[0] = _mm512_maskz_cvtusepi32_epi16(k, i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.u16[i] =
          (i32_mix.u32[i] > (int)0xffff) ? (int)0xffff : i32_mix.u32[i];
    } else {
      expected.u16[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_maskz_cvtusepi32_epi16", __LINE__);

  soft_src_update(i32_mix);
  res.ymmi[1] = i16.ymmi[0];
  res.ymmi[0] = res.ymmi[1];
  _mm512_mask_cvtusepi32_storeu_epi16(&(res.ymmi[0]), k, i32_mix.zmmi);

  for (i = 0; i < 16; i++) {
    if ((1 << i) & k) {
      expected.u16[i] =
          (i32_mix.u32[i] > (int)0xffff) ? (int)0xffff : i32_mix.u32[i];
    } else {
      expected.u16[i] = res.u16[16 + i]; // From res.ymmi[1].
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_mask_cvtusepi32_storeu_epi16",
                 __LINE__);
}

void NOINLINE do_pmovqb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0x76;

  res.xmmi[0] = _mm512_cvtepi64_epi8(i64.zmmi);

  expected.u64[1] = 0;
  for (i = 0; i < 8; i++) {
    expected.s8[i] = i64.s64[i];
  }

  check_equal_nd(&res, &expected, 4, "_mm512_cvtepi64_epi8", __LINE__);

  /*
   * Exercise mix with store.
   */

  _mm_store_sd(&res.f64[2], _mm_castsi128_pd(_mm512_cvtepi64_epi8(i64.zmmi)));
  check_equal_nd(&res.f64[2], &expected, 2, "_mm512_cvtepi64_epi8 mix with store",
                 __LINE__);

  soft_src_update(i64);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm512_mask_cvtepi64_epi8(res.xmmi[1], k, i64.zmmi);

  expected.u64[1] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i64.s64[i];
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtepi64_epi8", __LINE__);

  soft_src_update(i64);
  res.xmmi[0] = _mm512_maskz_cvtepi64_epi8(k, i64.zmmi);

  expected.u64[1] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i64.s64[i];
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_maskz_cvtepi64_epi8", __LINE__);

  soft_src_update(i64);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = res.xmmi[1];
  _mm512_mask_cvtepi64_storeu_epi8(&(res.xmmi[0]), k, i64.zmmi);

  expected.u64[1] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = i64.s64[i];
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  // Memory-form instruction does not zero high half of result.
  check_equal_nd(&res, &expected, 2, "_mm512_mask_cvtepi64_storeu_epi8",
                 __LINE__);
}

void NOINLINE do_pmovsqb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0x67;

  res.xmmi[0] = _mm512_cvtsepi64_epi8(i64_mix.zmmi);

  expected.u64[1] = 0;
  for (i = 0; i < 8; i++) {
    expected.s8[i] = (i64_mix.s64[i] < -128)
                         ? -128
                         : ((i64_mix.s64[i] > 127) ? 127 : i64_mix.s64[i]);
  }

  check_equal_nd(&res, &expected, 4, "_mm512_cvtsepi64_epi8", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm512_mask_cvtsepi64_epi8(res.xmmi[1], k, i64_mix.zmmi);

  expected.u64[1] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = (i64_mix.s64[i] < -128)
                           ? -128
                           : ((i64_mix.s64[i] > 127) ? 127 : i64_mix.s64[i]);
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtsepi64_epi8", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[0] = _mm512_maskz_cvtsepi64_epi8(k, i64_mix.zmmi);

  expected.u64[1] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = (i64_mix.s64[i] < -128)
                           ? -128
                           : ((i64_mix.s64[i] > 127) ? 127 : i64_mix.s64[i]);
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_maskz_cvtsepi64_epi8", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = res.xmmi[1];
  _mm512_mask_cvtsepi64_storeu_epi8(&(res.xmmi[0]), k, i64_mix.zmmi);

  expected.u64[1] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s8[i] = (i64_mix.s64[i] < -128)
                           ? -128
                           : ((i64_mix.s64[i] > 127) ? 127 : i64_mix.s64[i]);
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  // Memory-form instruction does not zero high half of result.
  check_equal_nd(&res, &expected, 2, "_mm512_mask_cvtsepi64_storeu_epi8",
                 __LINE__);
}

void NOINLINE do_pmovusqb() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0x67;

  res.xmmi[0] = _mm512_cvtusepi64_epi8(i64_mix.zmmi);

  expected.u64[1] = 0;
  for (i = 0; i < 8; i++) {
    expected.u8[i] = (i64_mix.u64[i] > 255) ? 255 : i64_mix.u64[i];
  }

  check_equal_nd(&res, &expected, 4, "_mm512_cvtusepi64_epi8", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm512_mask_cvtusepi64_epi8(res.xmmi[1], k, i64_mix.zmmi);

  expected.u64[1] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.u8[i] = (i64_mix.u64[i] > 255) ? 255 : i64_mix.u64[i];
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtusepi64_epi8", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[0] = _mm512_maskz_cvtusepi64_epi8(k, i64_mix.zmmi);

  expected.u64[1] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.u8[i] = (i64_mix.u64[i] > 255) ? 255 : i64_mix.u64[i];
    } else {
      expected.s8[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_maskz_cvtusepi64_epi8", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i16.xmmi[0];
  res.xmmi[0] = res.xmmi[1];
  _mm512_mask_cvtusepi64_storeu_epi8(&(res.xmmi[0]), k, i64_mix.zmmi);

  expected.u64[1] = 0;
  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.u8[i] = (i64_mix.u64[i] > 255) ? 255 : i64_mix.u64[i];
    } else {
      expected.s8[i] = res.s8[16 + i]; // From res.xmmi[1].
    }
  }
  // Memory-form instruction does not zero high half of result.
  check_equal_nd(&res, &expected, 2, "_mm512_mask_cvtusepi64_storeu_epi8",
                 __LINE__);
}

void NOINLINE do_pmovqw() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xe9;

  res.xmmi[0] = _mm512_cvtepi64_epi16(i64.zmmi);

  for (i = 0; i < 8; i++) {
    expected.s16[i] = i64.s64[i];
  }

  check_equal_nd(&res, &expected, 4, "_mm512_cvtepi64_epi16", __LINE__);

  soft_src_update(i64);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm512_mask_cvtepi64_epi16(res.xmmi[1], k, i64.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = i64.s64[i];
    } else {
      expected.s16[i] = res.s16[8 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtepi64_epi16", __LINE__);

  soft_src_update(i64);
  res.xmmi[0] = _mm512_maskz_cvtepi64_epi16(k, i64.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = i64.s64[i];
    } else {
      expected.s16[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtepi64_epi16", __LINE__);

  soft_src_update(i64);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = res.xmmi[1];
  _mm512_mask_cvtepi64_storeu_epi16(&(res.xmmi[0]), k, i64.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s16[i] = i64.s64[i];
    } else {
      expected.s16[i] = res.s16[8 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtepi64_storeu_epi16",
                 __LINE__);
}

void NOINLINE do_pmovsqw() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xe9;
  __int64 r;

  res.xmmi[0] = _mm512_cvtsepi64_epi16(i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    r = i64_mix.s64[i];
    if (r < (int)0xffff8000) {
      r = (int)0xffff8000;
    } else if (r > (int)0x7fff) {
      r = (int)0x7fff;
    }
    expected.s16[i] = r;
  }

  check_equal_nd(&res, &expected, 4, "_mm512_cvtsepi64_epi16", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm512_mask_cvtsepi64_epi16(res.xmmi[1], k, i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      r = i64_mix.s64[i];
      if (r < (int)0xffff8000) {
        r = (int)0xffff8000;
      } else if (r > (int)0x7fff) {
        r = (int)0x7fff;
      }
      expected.s16[i] = r;
    } else {
      expected.s16[i] = res.s16[8 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtsepi64_epi16", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[0] = _mm512_maskz_cvtsepi64_epi16(k, i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      r = i64_mix.s64[i];
      if (r < (int)0xffff8000) {
        r = (int)0xffff8000;
      } else if (r > (int)0x7fff) {
        r = (int)0x7fff;
      }
      expected.s16[i] = r;
    } else {
      expected.s16[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_maskz_cvtsepi64_epi16", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = res.xmmi[1];
  _mm512_mask_cvtsepi64_storeu_epi16(&(res.xmmi[0]), k, i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      r = i64_mix.s64[i];
      if (r < (int)0xffff8000) {
        r = (int)0xffff8000;
      } else if (r > (int)0x7fff) {
        r = (int)0x7fff;
      }
      expected.s16[i] = r;
    } else {
      expected.s16[i] = res.s16[8 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtsepi64_storeu_epi16",
                 __LINE__);
}

void NOINLINE do_pmovusqw() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xe9;
  unsigned __int64 r;

  res.xmmi[0] = _mm512_cvtusepi64_epi16(i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    r = i64_mix.u64[i];
    if (r > 0xffff) {
      r = 0xffff;
    }
    expected.s16[i] = r;
  }

  check_equal_nd(&res, &expected, 4, "_mm512_cvtusepi64_epi16", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = i16.xmmi[1];
  res.xmmi[0] = _mm512_mask_cvtusepi64_epi16(res.xmmi[1], k, i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      r = i64_mix.u64[i];
      if (r > 0xffff) {
        r = 0xffff;
      }
      expected.s16[i] = r;
    } else {
      expected.s16[i] = res.s16[8 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtusepi64_epi16", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[0] = _mm512_maskz_cvtusepi64_epi16(k, i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      r = i64_mix.u64[i];
      if (r > 0xffff) {
        r = 0xffff;
      }
      expected.s16[i] = r;
    } else {
      expected.s16[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtusepi64_epi16", __LINE__);

  soft_src_update(i64_mix);
  res.xmmi[1] = i8.xmmi[0];
  res.xmmi[0] = res.xmmi[1];
  _mm512_mask_cvtusepi64_storeu_epi16(&(res.xmmi[0]), k, i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      r = i64_mix.u64[i];
      if (r > 0xffff) {
        r = 0xffff;
      }
      expected.s16[i] = r;
    } else {
      expected.s16[i] = res.s16[8 + i]; // From res.xmmi[1].
    }
  }

  check_equal_nd(&res, &expected, 4, "_mm512_mask_cvtusepi64_storeu_epi16",
                 __LINE__);
}

void NOINLINE do_pmovqd() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xcf;

  res.ymmi[0] = _mm512_cvtepi64_epi32(i64.zmmi);

  for (i = 0; i < 8; i++) {
    expected.s32[i] = i64.s64[i];
  }

  check_equal_nd(&res, &expected, 8, "_mm512_cvtepi64_epi32", __LINE__);

  soft_src_update(i64);
  res.ymmi[1] = i8.ymmi[0];
  res.ymmi[0] = i8.ymmi[1];
  res.ymmi[0] = _mm512_mask_cvtepi64_epi32(res.ymmi[1], k, i64.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s32[i] = i64.s64[i];
    } else {
      expected.s32[i] = res.s32[8 + i]; // From res.ymmi[1].
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_mask_cvtepi64_epi32", __LINE__);

  soft_src_update(i64);
  res.ymmi[0] = _mm512_maskz_cvtepi64_epi32(k, i64.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s32[i] = i64.s64[i];
    } else {
      expected.s32[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_maskz_cvtepi64_epi32", __LINE__);

  soft_src_update(i64);
  res.ymmi[1] = i8.ymmi[0];
  res.ymmi[0] = res.ymmi[1];
  _mm512_mask_cvtepi64_storeu_epi32(&(res.ymmi[0]), k, i64.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      expected.s32[i] = i64.s64[i];
    } else {
      expected.s32[i] = res.s32[8 + i]; // From res.ymmi[1].
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_mask_cvtepi64_storeu_epi32",
                 __LINE__);
}

void NOINLINE do_pmovsqd() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xcf;
  __int64 r;

  res.ymmi[0] = _mm512_cvtsepi64_epi32(i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    r = i64_mix.s64[i];
    if (r < (int)0x80000000) {
      r = (int)0x80000000;
    } else if (r > (int)0x7fffffff) {
      r = (int)0x7fffffff;
    }
    expected.s32[i] = r;
  }

  check_equal_nd(&res, &expected, 8, "_mm512_cvtsepi64_epi32", __LINE__);

  soft_src_update(i64_mix);
  res.ymmi[1] = i8.ymmi[0];
  res.ymmi[0] = i8.ymmi[1];
  res.ymmi[0] = _mm512_mask_cvtsepi64_epi32(res.ymmi[1], k, i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      r = i64_mix.s64[i];
      if (r < (int)0x80000000) {
        r = (int)0x80000000;
      } else if (r > (int)0x7fffffff) {
        r = (int)0x7fffffff;
      }
      expected.s32[i] = r;
    } else {
      expected.s32[i] = res.s32[8 + i]; // From res.ymmi[1].
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_mask_cvtsepi64_epi32", __LINE__);

  soft_src_update(i64_mix);
  res.ymmi[0] = _mm512_maskz_cvtsepi64_epi32(k, i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      r = i64_mix.s64[i];
      if (r < (int)0x80000000) {
        r = (int)0x80000000;
      } else if (r > (int)0x7fffffff) {
        r = (int)0x7fffffff;
      }
      expected.s32[i] = r;
    } else {
      expected.s32[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_maskz_cvtsepi64_epi32", __LINE__);

  soft_src_update(i64_mix);
  res.ymmi[1] = i8.ymmi[0];
  res.ymmi[0] = res.ymmi[1];
  _mm512_mask_cvtsepi64_storeu_epi32(&(res.ymmi[0]), k, i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      r = i64_mix.s64[i];
      if (r < (int)0x80000000) {
        r = (int)0x80000000;
      } else if (r > (int)0x7fffffff) {
        r = (int)0x7fffffff;
      }
      expected.s32[i] = r;
    } else {
      expected.s32[i] = res.s32[8 + i]; // From res.ymmi[1].
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_mask_cvtsepi64_storeu_epi32",
                 __LINE__);
}

void NOINLINE do_pmovusqd() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xcf;
  unsigned __int64 r;

  res.ymmi[0] = _mm512_cvtusepi64_epi32(i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    r = i64_mix.u64[i];
    if (r > (unsigned int)0xffffffff) {
      r = (unsigned int)0xffffffff;
    }
    expected.u32[i] = r;
  }

  check_equal_nd(&res, &expected, 8, "_mm512_cvtusepi64_epi32", __LINE__);

  soft_src_update(i64_mix);
  res.ymmi[1] = i8.ymmi[0];
  res.ymmi[0] = i8.ymmi[1];
  res.ymmi[0] = _mm512_mask_cvtusepi64_epi32(res.ymmi[1], k, i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      r = i64_mix.u64[i];
      if (r > (unsigned int)0xffffffff) {
        r = (unsigned int)0xffffffff;
      }
      expected.u32[i] = r;
    } else {
      expected.s32[i] = res.s32[8 + i]; // From res.ymmi[1].
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_mask_cvtusepi64_epi32", __LINE__);

  soft_src_update(i64_mix);
  res.ymmi[0] = _mm512_maskz_cvtusepi64_epi32(k, i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      r = i64_mix.u64[i];
      if (r > (unsigned int)0xffffffff) {
        r = (unsigned int)0xffffffff;
      }
      expected.u32[i] = r;
    } else {
      expected.s32[i] = 0;
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_maskz_cvtusepi64_epi32", __LINE__);

  soft_src_update(i64_mix);
  res.ymmi[1] = i8.ymmi[0];
  res.ymmi[0] = res.ymmi[1];
  _mm512_mask_cvtusepi64_storeu_epi32(&(res.ymmi[0]), k, i64_mix.zmmi);

  for (i = 0; i < 8; i++) {
    if ((1 << i) & k) {
      r = i64_mix.u64[i];
      if (r > (unsigned int)0xffffffff) {
        r = (unsigned int)0xffffffff;
      }
      expected.u32[i] = r;
    } else {
      expected.s32[i] = res.s32[8 + i]; // From res.ymmi[1].
    }
  }

  check_equal_nd(&res, &expected, 8, "_mm512_mask_cvtusepi64_storeu_epi32",
                 __LINE__);
}

int main(int argc, char *argv[]) {
  init();

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
