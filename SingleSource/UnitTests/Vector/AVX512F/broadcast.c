/*
 * Test broadcast instructions.
 * This test was created to check the correctness
 * of the following intrinsics support:
 *      _mm512_broadcast_f32x4()
 *      _mm512_broadcast_f64x4()
 *      _mm512_broadcast_i32x4()
 *      _mm512_broadcastload_i64x4()
 *      _mm512_mask_broadcast_f32x4()
 *      _mm512_mask_broadcast_f64x4()
 *      _mm512_mask_broadcast_i32x4()
 *      _mm512_mask_broadcast_i64x4()
 *      _mm512_maskz_broadcast_f32x4()
 *      _mm512_maskz_broadcast_f64x4()
 *      _mm512_maskz_broadcast_i32x4()
 *      _mm512_maskz_broadcast_i64x4()
 */

#include "m512_test_util.h"

V512 i32;
V512 f32;
V512 i64;
V512 f64;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 16; i++) {
    i32.s32[i] = i;
    f32.f32[i] = (float)i;
  }

  for (i = 0; i < 8; i++) {
    i64.s64[i] = i;
    f64.f64[i] = (double)i;
  }
}

void NOINLINE do_32x4() {
  V512 res;
  V512 expected;
  __mmask16 k;

  /*************************** 512 bit intrinsics ***********************/
  /* Unmasked op */
  res.zmm = _mm512_broadcast_f32x4(f32.xmm[0]);
  expected.zmm = _mm512_setr4_ps(0.0f, 1.0f, 2.0f, 3.0f);
  check_equal_nd(&res, &expected, 16, "_mm512_broadcast_f32x4", __LINE__);

  /* Write mask */
  k = 0x7e9a;
  res.zmm = _mm512_setzero_ps();
  res.zmm = _mm512_mask_broadcast_f32x4(res.zmm, k, f32.xmm[0]);
  expected.zmm = _mm512_setr4_ps(0.0f, 1.0f, 2.0f, 3.0f);
  expected.zmm = _mm512_mask_mov_ps(_mm512_setzero_ps(), k, expected.zmm);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_broadcast_f32x4", __LINE__);

  /* Zero mask */
  res.zmm = _mm512_maskz_broadcast_f32x4(k, f32.xmm[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_broadcast_f32x4", __LINE__);

  /* Unmasked op */
  res.zmmi = _mm512_broadcast_i32x4(i32.xmmi[0]);
  expected.zmmi = _mm512_setr4_epi32(0, 1, 2, 3);
  check_equal_nd(&res, &expected, 16, "_mm512_broadcast_i32x4", __LINE__);

  /* Write mask */
  k = 0x789a;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_broadcast_i32x4(res.zmmi, k, i32.xmmi[0]);
  expected.zmmi = _mm512_setr4_epi32(0, 1, 2, 3);
  expected.zmmi =
      _mm512_mask_mov_epi32(_mm512_setzero_epi32(), k, expected.zmmi);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_broadcast_i32x4", __LINE__);

  /* Zero mask */
  res.zmmi = _mm512_maskz_broadcast_i32x4(k, i32.xmmi[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_broadcast_i32x4", __LINE__);

  /*************************** 256 bit intrinsics ***********************/

  /* Write mask */
  k = 0x7e9a;
  res.zmmi = _mm512_setzero_epi32();
  expected.zmm = _mm512_setr4_ps(0.0f, 1.0f, 2.0f, 3.0f);
  expected.zmm = _mm512_mask_mov_ps(_mm512_setzero_ps(), k, expected.zmm);
}

void NOINLINE do_64x4() {
  V512 res;
  V512 expected;
  __mmask8 k;

  /* Unmasked op */
  res.zmmd = _mm512_broadcast_f64x4(f64.ymmd[0]);
  expected.zmmd = _mm512_set_pd(3.0, 2.0, 1.0, 0.0, 3.0, 2.0, 1.0, 0.0);
  check_equal_nd(&res, &expected, 16, "_mm512_broadcast_f64x4", __LINE__);

  /* Write mask */
  k = 0xe4;
  res.zmmd = _mm512_setzero_pd();
  res.zmmd = _mm512_mask_broadcast_f64x4(res.zmmd, k, f64.ymmd[0]);
  expected.zmmd = _mm512_set_pd(3.0, 2.0, 1.0, 0.0, 3.0, 2.0, 1.0, 0.0);
  expected.zmmd = _mm512_mask_mov_pd(_mm512_setzero_pd(), k, expected.zmmd);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_broadcast_f64x4", __LINE__);

  /* Zero mask */
  res.zmmd = _mm512_maskz_broadcast_f64x4(k, f64.ymmd[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_broadcast_f64x4", __LINE__);

  /* Unmasked op */
  res.zmmi = _mm512_broadcast_i64x4(i64.ymmi[0]);
  expected.zmmi = _mm512_set_epi64(3, 2, 1, 0, 3, 2, 1, 0);
  check_equal_nd(&res, &expected, 16, "_mm512_broadcast_i64x4", __LINE__);

  /* Write mask */
  k = 0xdf;
  res.zmmi = _mm512_setzero_epi32();
  res.zmmi = _mm512_mask_broadcast_i64x4(res.zmmi, k, i64.ymmi[0]);
  expected.zmmi = _mm512_set_epi64(3, 2, 1, 0, 3, 2, 1, 0);
  expected.zmmi =
      _mm512_mask_mov_epi64(_mm512_setzero_epi32(), k, expected.zmmi);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_broadcast_i64x4", __LINE__);

  /* Zero mask */
  res.zmmi = _mm512_maskz_broadcast_i64x4(k, i64.ymmi[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_broadcast_i64x4", __LINE__);
}

int main(int argc, char *argv[]) {
  init();

  do_32x4();
  do_64x4();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
