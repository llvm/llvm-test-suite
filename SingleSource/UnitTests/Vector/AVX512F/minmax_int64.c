/*
 * Test the min/max int64 family of intrinsics.
 * Here we check for _mm512_[mask|maskz]_[min|max]_ep[i|u]64 intrinsics.
 */

#include "m512_test_util.h"
#include <stdio.h>

V512 i64, i64_2;

void NOINLINE init() {
  volatile int i;
  for (i = 0; i < 8; i++) {
    if (i % 2) {
      i64.s64[i] = (i + 1) * 10000;
      i64_2.s64[i] = -(i + 1) * 1000;
    } else {
      i64.s64[i] = -(i + 1) * 1000;
      i64_2.s64[i] = (i + 1) * 10000;
    }
  }
}

void NOINLINE do_512_max_epi64() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xdb; /* 11011011 */

  /* scalar calculation */
  for (i = 0; i < 8; i++) {
    expected.s64[i] = (i64.s64[i] > i64_2.s64[i]) ? i64.s64[i] : i64_2.s64[i];
  }
  /* intrinsic calculation */
  res.zmmi = _mm512_max_epi64(i64.zmmi, i64_2.zmmi);
  check_equal_nq(&res, &expected, 8, "_mm512_max_epi64", __LINE__);

  /* scalar mask */
  expected.s64[2] = 0;
  expected.s64[5] = 0;

  /* masked intrinsic calculation */
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_max_epi64(res.zmmi, k, i64.zmmi, i64_2.zmmi);
  check_equal_nq(&res, &expected, 8, "_mm512_mask_max_epi64", __LINE__);
}

void NOINLINE do_512_max_epu64() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xdb; /* 11011011 */

  /* scalar calculation */
  for (i = 0; i < 8; i++) {
    expected.u64[i] = (i64.u64[i] > i64_2.u64[i]) ? i64.u64[i] : i64_2.u64[i];
  }
  /* intrinsic calculation */
  res.zmmi = _mm512_max_epu64(i64.zmmi, i64_2.zmmi);
  check_equal_nq(&res, &expected, 8, "_mm512_max_epu64", __LINE__);

  /* scalar mask */
  expected.u64[2] = 0;
  expected.u64[5] = 0;

  /* masked intrinsic calculation */
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_max_epu64(res.zmmi, k, i64.zmmi, i64_2.zmmi);
  check_equal_nq(&res, &expected, 8, "_mm512_mask_max_epu64", __LINE__);
}

void NOINLINE do_512_min_epi64() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xdb; /* 11011011 */

  /* scalar calculation */
  for (i = 0; i < 8; i++) {
    expected.s64[i] = (i64.s64[i] < i64_2.s64[i]) ? i64.s64[i] : i64_2.s64[i];
  }
  /* intrinsic calculation */
  res.zmmi = _mm512_min_epi64(i64.zmmi, i64_2.zmmi);
  check_equal_nq(&res, &expected, 8, "_mm512_min_epi64", __LINE__);

  /* scalar mask */
  expected.s64[2] = 0;
  expected.s64[5] = 0;

  /* masked intrinsic calculation */
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_min_epi64(res.zmmi, k, i64.zmmi, i64_2.zmmi);
  check_equal_nq(&res, &expected, 8, "_mm512_mask_min_epi64", __LINE__);
}

void NOINLINE do_512_min_epu64() {
  V512 res;
  V512 expected;
  volatile int i;
  __mmask8 k = 0xdb; /* 11011011 */

  /* scalar calculation */
  for (i = 0; i < 8; i++) {
    expected.u64[i] = (i64.u64[i] < i64_2.u64[i]) ? i64.u64[i] : i64_2.u64[i];
  }
  /* intrinsic calculation */
  res.zmmi = _mm512_min_epu64(i64.zmmi, i64_2.zmmi);
  check_equal_nq(&res, &expected, 8, "_mm512_min_epu64", __LINE__);

  /* scalar mask */
  expected.u64[2] = 0;
  expected.u64[5] = 0;

  /* masked intrinsic calculation */
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_min_epu64(res.zmmi, k, i64.zmmi, i64_2.zmmi);
  check_equal_nq(&res, &expected, 8, "_mm512_mask_min_epu64", __LINE__);
}

int main(int argc, char *argv[]) {
  init();

  do_512_max_epi64();
  do_512_max_epu64();
  do_512_min_epi64();
  do_512_min_epu64();

  if (n_errs) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
