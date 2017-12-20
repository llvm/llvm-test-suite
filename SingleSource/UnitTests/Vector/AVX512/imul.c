/*
 * Test various integer multiply intrinsics.
 * Here we check for _mm512_[mask]mul_ep[i|u]32 intrinsics.
 */

#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

volatile int vol0 = 0;

V512 i64;
V512 i64_mix;
V512 i64_big;

void NOINLINE init() {
  volatile int i;


  for (i = 0; i < 8; i++) {
    i64.s64[i] = i;
    i64_mix.s64[i] = (i & 1) ? i : -i;
    i64_big.s64[i] = 1000 * (i + 1);
    if ((i & 1) != 0) {
      i64_big.s64[i] = -i64_big.s64[i];
    }
  }
}

void NOINLINE do_muldq() {
  V512 res;
  V512 expected;
  __mmask16 k;
  volatile int i;

  res.zmmi = _mm512_mul_epi32(i64_mix.zmmi, i64_big.zmmi);
  for (i = 0; i < 8; i++) {
    expected.s64[i] = (I64)i64_mix.s32[2 * i] * i64_big.s32[2 * i];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mul_epi32", __LINE__);

  /*
   * No-op to inhibit PRE of i64_big, thus enabling localized ciscization.
   */
  i64_big.xmm[vol0] = i64_big.xmm[vol0];

  k = 0xcd;

  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_mul_epi32(res.zmmi, k, i64.zmmi, i64_big.zmmi);
  for (i = 0; i < 8; i++) {
    expected.s64[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.s64[i] = (I64)i64.s32[2 * i] * i64_big.s32[2 * i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_mul_epi32", __LINE__);
}

void NOINLINE do_muludq() {
  V512 res;
  V512 expected;
  __mmask16 k;
  volatile int i;

  res.zmmi = _mm512_mul_epu32(i64_mix.zmmi, i64_big.zmmi);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = (U64)i64_mix.u32[2 * i] * i64_big.u32[2 * i];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mul_epu32", __LINE__);

  /*
   * No-op to inhibit PRE of i64_big, thus enabling localized ciscization.
   */
  i64_big.xmm[vol0] = i64_big.xmm[vol0];

  k = 0xcd;

  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_mul_epu32(res.zmmi, k, i64.zmmi, i64_big.zmmi);
  for (i = 0; i < 8; i++) {
    expected.u64[i] = 0;
    if ((k & (1 << i)) != 0) {
      expected.u64[i] = (U64)i64.u32[2 * i] * i64_big.u32[2 * i];
    }
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_mul_epu32", __LINE__);
}

int main(int argc, char *argv[]) {
  init();

  do_muldq();
  do_muludq();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
