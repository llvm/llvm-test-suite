/*
 * Test intrinsics for vptestm[bdqw] and vptestnm[bdqw].
 * Here we check for _mm512_test_[epi32|epi64]_mask intrinsics.
 */

#include "m512_test_util.h"
#include <stdio.h>

volatile int ten = 10;

#define TEST(base_intrin, mask_intrin, r1, r2, correct_res)                    \
  {                                                                            \
    __int64 _i, _mask;                                                         \
    __int64 _cres = (correct_res);                                             \
    __int64 _res = base_intrin((r1), (r2));                                    \
    if (_res != _cres) {                                                       \
      printf(#base_intrin "(" #r1 ", " #r2 ") failed\n");                      \
      printf("Expected 0x%08x%08x; got 0x%08x%08x\n", (int)(_cres >> 32),      \
             (int)_cres, (int)(_res >> 32), (int)_res);                        \
      n_errs++;                                                                \
    }                                                                          \
    for (_i = 0; _i < ten; _i++) {                                             \
      _mask = ((__int64)rand() << 32) | rand();                                \
      _res = mask_intrin(_mask, (r1), (r2));                                   \
      _cres = (correct_res)&_mask;                                             \
      if (_res != _cres) {                                                     \
        printf(#mask_intrin "(0x%08x%08x, " #r1 ", " #r2 ") "                  \
                            "failed\n",                                        \
               (int)(_mask >> 32), (int)_mask);                                \
        printf("Expected 0x%08x%08x; got 0x%08x%08x\n", (int)(_cres >> 32),    \
               (int)_cres, (int)(_res >> 32), (int)_res);                      \
        n_errs++;                                                              \
      }                                                                        \
    }                                                                          \
  }

V512 i8;
V512 mix8;
V512 i16;
V512 mix16;

V512 i32;
V512 mix32;

V512 i64;
V512 mix64;

volatile int vol0 = 0;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 64; i++) {
    i8.s8[i] = -1;
    mix8.s8[i] = (i & 1) ? 0 : -1;
  }

  for (i = 0; i < 32; i++) {
    i16.s16[i] = -1;
    mix16.s16[i] = (i & 1) ? 0 : -1;
  }

  for (i = 0; i < 16; i++) {
    i32.s32[i] = -1;
    mix32.s32[i] = (i & 1) ? 0 : -1;
  }

  for (i = 0; i < 8; i++) {
    i64.s64[i] = -1;
    mix64.s64[i] = (i & 1) ? 0 : -1;
  }
}

void NOINLINE do_ptestmb() {
  TEST(_mm_test_epi8_mask, _mm_mask_test_epi8_mask, mix8.xmmi[0], i8.xmmi[0],
       0x5555);

  i8.xmmi[vol0] = i8.xmmi[vol0]; /* No-op. */

  TEST(_mm256_test_epi8_mask, _mm256_mask_test_epi8_mask, mix8.ymmi[0],
       i8.ymmi[0], 0x55555555);

  i8.xmmi[vol0] = i8.xmmi[vol0]; /* No-op. */

  TEST(_mm512_test_epi8_mask, _mm512_mask_test_epi8_mask, mix8.zmmi, i8.zmmi,
       0x5555555555555555);
}

void NOINLINE do_ptestmw() {
  TEST(_mm_test_epi16_mask, _mm_mask_test_epi16_mask, mix16.xmmi[0],
       i16.xmmi[0], 0x55);

  i16.xmmi[vol0] = i16.xmmi[vol0]; /* No-op. */

  TEST(_mm256_test_epi16_mask, _mm256_mask_test_epi16_mask, mix16.ymmi[0],
       i16.ymmi[0], 0x5555);

  i16.xmmi[vol0] = i16.xmmi[vol0]; /* No-op. */

  TEST(_mm512_test_epi16_mask, _mm512_mask_test_epi16_mask, mix16.zmmi,
       i16.zmmi, 0x55555555);
}

void NOINLINE do_ptestmd() {
  TEST(_mm_test_epi32_mask, _mm_mask_test_epi32_mask, mix32.xmmi[0],
       i32.xmmi[0], 0x5);

  i32.xmmi[vol0] = i32.xmmi[vol0]; /* No-op. */

  TEST(_mm256_test_epi32_mask, _mm256_mask_test_epi32_mask, mix32.ymmi[0],
       i32.ymmi[0], 0x55);

  i32.xmmi[vol0] = i32.xmmi[vol0]; /* No-op. */

  TEST(_mm512_test_epi32_mask, _mm512_mask_test_epi32_mask, mix32.zmmi,
       i32.zmmi, 0x5555);
}

void NOINLINE do_ptestmq() {
  TEST(_mm_test_epi64_mask, _mm_mask_test_epi64_mask, mix64.xmmi[0],
       i64.xmmi[0], 0x1);

  i64.xmmi[vol0] = i64.xmmi[vol0]; /* No-op. */

  TEST(_mm256_test_epi64_mask, _mm256_mask_test_epi64_mask, mix64.ymmi[0],
       i64.ymmi[0], 0x5);

  i64.xmmi[vol0] = i64.xmmi[vol0]; /* No-op. */

  TEST(_mm512_test_epi64_mask, _mm512_mask_test_epi64_mask, mix64.zmmi,
       i64.zmmi, 0x55);
}

void NOINLINE do_ptestnmb() {
  TEST(_mm_testn_epi8_mask, _mm_mask_testn_epi8_mask, mix8.xmmi[0], i8.xmmi[0],
       0xaaaa);

  i8.xmmi[vol0] = i8.xmmi[vol0]; /* No-op. */

  TEST(_mm256_testn_epi8_mask, _mm256_mask_testn_epi8_mask, mix8.ymmi[0],
       i8.ymmi[0], 0xaaaaaaaa);

  i8.xmmi[vol0] = i8.xmmi[vol0]; /* No-op. */

  TEST(_mm512_testn_epi8_mask, _mm512_mask_testn_epi8_mask, mix8.zmmi, i8.zmmi,
       0xaaaaaaaaaaaaaaaa);
}

void NOINLINE do_ptestnmw() {
  TEST(_mm_testn_epi16_mask, _mm_mask_testn_epi16_mask, mix16.xmmi[0],
       i16.xmmi[0], 0xaa);

  i16.xmmi[vol0] = i16.xmmi[vol0]; /* No-op. */

  TEST(_mm256_testn_epi16_mask, _mm256_mask_testn_epi16_mask, mix16.ymmi[0],
       i16.ymmi[0], 0xaaaa);

  i16.xmmi[vol0] = i16.xmmi[vol0]; /* No-op. */

  TEST(_mm512_testn_epi16_mask, _mm512_mask_testn_epi16_mask, mix16.zmmi,
       i16.zmmi, 0xaaaaaaaa);
}

void NOINLINE do_ptestnmd() {
  TEST(_mm_testn_epi32_mask, _mm_mask_testn_epi32_mask, mix32.xmmi[0],
       i32.xmmi[0], 0xa);

  i32.xmmi[vol0] = i32.xmmi[vol0]; /* No-op. */

  TEST(_mm256_testn_epi32_mask, _mm256_mask_testn_epi32_mask, mix32.ymmi[0],
       i32.ymmi[0], 0xaa);

  i32.xmmi[vol0] = i32.xmmi[vol0]; /* No-op. */

  TEST(_mm512_testn_epi32_mask, _mm512_mask_testn_epi32_mask, mix32.zmmi,
       i32.zmmi, 0xaaaa);
}

void NOINLINE do_ptestnmq() {
  TEST(_mm_testn_epi64_mask, _mm_mask_testn_epi64_mask, mix64.xmmi[0],
       i64.xmmi[0], 0x2);

  i64.xmmi[vol0] = i64.xmmi[vol0]; /* No-op. */

  TEST(_mm256_testn_epi64_mask, _mm256_mask_testn_epi64_mask, mix64.ymmi[0],
       i64.ymmi[0], 0xa);

  i64.xmmi[vol0] = i64.xmmi[vol0]; /* No-op. */

  TEST(_mm512_testn_epi64_mask, _mm512_mask_testn_epi64_mask, mix64.zmmi,
       i64.zmmi, 0xaa);
}

int main(int argc, char *argv[]) {
  init();

  do_ptestmb();
  do_ptestmw();
  do_ptestmd();
  do_ptestmq();

  do_ptestnmb();
  do_ptestnmw();
  do_ptestnmd();
  do_ptestnmq();

  if (n_errs) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
