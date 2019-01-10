
/*
 * Test 128 and 256-bit load and store intrinsics,
 * with masked and zero-masked forms, by comparing
 * their output with the corresponding 512-bit intrinsic.
 *
 * This test was created to check the correctness
 * of the following intrinsics support:
 *      _mm512_load_si512()
 *      _mm512_store_si512()
 *      _mm256_storeu_ps()
 *      _mm256_storeu_si256()
 *      _mm_storeu_ps()
 *      _mm_storeu_si128()
 */

#include "m512_test_util.h"
#include <stdio.h>

V512 fsrc1;
V512 fsrc2;
V512 fsrc_non_negative;
V512 fsrc_arr[2];

V512 dsrc1;
V512 dsrc2;
V512 dsrc_non_negative;
V512 dsrc_arr[2];

V512 isrc1;
V512 isrc2;
V512 isrc_arr[2];

static void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 16; i++) {
    fsrc1.f32[i] = (float)(i + 1);
    fsrc2.f32[i] = 4.0f * (float)(i + 1);
    fsrc_non_negative.f32[i] = 2.0f * (float)(i);
    isrc2.s32[i] = (3 * i) - 17;
  }

  fsrc_arr[0] = fsrc2;
  fsrc_arr[1] = fsrc1;

  for (i = 0; i < 64; i++) {
    isrc1.s8[i] = 2 * i + 1;
    if (i % 3) {
      isrc1.s8[i] = -isrc1.s8[i];
    }
  }

  isrc_arr[0] = isrc2;
  isrc_arr[1] = isrc1;

  for (i = 0; i < 8; i++) {
    dsrc1.f64[i] = (double)(-i - 1);
    dsrc2.f64[i] = 3.0 * (double)(-i - 1);
    dsrc_non_negative.f64[i] = 4.0f * (double)(i);
  }

  dsrc_arr[0] = dsrc2;
  dsrc_arr[1] = dsrc1;
}

/*
 * Use "soft update" between tests to make compiler think src was updated.
 * Prevents PRE'ing a load of src, thus allowing ciscization.
 * Also prevents PRE'ing intrinsic operations, ensuring we
 * execute the intended instructions.
 */
volatile int vol0 = 0;
#define soft_v512_update(var) (var).xmmi[vol0] = (var).xmmi[vol0]

void NOINLINE do_load_and_loadu_pd() {
  V512 xmm_res, ymm_res, zmm_res;
  __mmask8 k8 = 0x7e;

  /* Non-masked. */

  soft_v512_update(dsrc1);
  zmm_res.zmmd = _mm512_load_pd(&dsrc1.zmmd);

  soft_v512_update(dsrc_arr[0]);
  zmm_res.zmmd = _mm512_loadu_pd(&dsrc_arr[0].f64[1]);

  /* Masked. */

  zmm_res.zmmd = _mm512_setzero_pd();
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(dsrc1);
  zmm_res.zmmd = _mm512_mask_load_pd(zmm_res.zmmd, k8, &dsrc1.zmmd);

  zmm_res.zmmd = _mm512_setzero_pd();
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(dsrc_arr[0]);
  zmm_res.zmmd = _mm512_mask_loadu_pd(zmm_res.zmmd, k8, &dsrc_arr[0].f64[3]);

  /* Zero-masked. */

  zmm_res.zmmd = _mm512_set1_pd(1.0);
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(dsrc1);
  zmm_res.zmmd = _mm512_maskz_load_pd(k8, &dsrc1.zmmd);
  soft_v512_update(dsrc1);

  zmm_res.zmmd = _mm512_set1_pd(1.0);
  ymm_res = zmm_res;
  xmm_res = zmm_res;
}

void NOINLINE do_store_and_storeu_pd() {
  V512 xmm_res[2], ymm_res[2], zmm_res[2];
  __mmask8 k8 = 0xef;

  /* Non-masked. */

  zmm_res[0].zmmd = _mm512_set1_pd(1.0);
  zmm_res[1] = zmm_res[0];
  ymm_res[0] = zmm_res[0];
  ymm_res[1] = zmm_res[0];
  xmm_res[0] = zmm_res[0];
  xmm_res[1] = zmm_res[0];

  soft_v512_update(dsrc1);
  _mm512_store_pd(&zmm_res[0].zmmd, dsrc1.zmmd);

  soft_v512_update(dsrc1);
  _mm512_storeu_pd(&zmm_res[0].f64[1], dsrc1.zmmd);

  /* Masked. */

  zmm_res[0].zmmd = _mm512_set1_pd(1.0);
  zmm_res[1] = zmm_res[0];
  ymm_res[0] = zmm_res[0];
  ymm_res[1] = zmm_res[0];
  xmm_res[0] = zmm_res[0];
  xmm_res[1] = zmm_res[0];

  soft_v512_update(dsrc1);
  _mm512_mask_store_pd(&zmm_res[0].zmmd, k8, dsrc1.zmmd);

  zmm_res[0].zmmd = _mm512_set1_pd(1.0);
  zmm_res[1] = zmm_res[0];
  ymm_res[0] = zmm_res[0];
  ymm_res[1] = zmm_res[0];
  xmm_res[0] = zmm_res[0];
  xmm_res[1] = zmm_res[0];

  soft_v512_update(dsrc1);
  _mm512_mask_storeu_pd(&zmm_res[0].f64[1], k8, dsrc1.zmmd);
}

void NOINLINE do_load_and_loadu_ps() {
  V512 xmm_res, ymm_res, zmm_res;
  __mmask16 k16 = 0xff7e;
  __mmask8 k8 = (__mmask8)k16;

  /* Non-masked. */

  soft_v512_update(fsrc1);
  zmm_res.zmm = _mm512_load_ps(&fsrc1.zmm);

  soft_v512_update(fsrc_arr[0]);
  zmm_res.zmm = _mm512_loadu_ps(&fsrc_arr[0].f32[3]);

  /* Masked. */

  zmm_res.zmm = _mm512_setzero_ps();
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(fsrc1);
  zmm_res.zmm = _mm512_mask_load_ps(zmm_res.zmm, k16, &fsrc1.zmm);

  zmm_res.zmm = _mm512_setzero_ps();
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(fsrc_arr[0]);
  zmm_res.zmm = _mm512_mask_loadu_ps(zmm_res.zmm, k16, &fsrc_arr[0].f32[5]);

  /* Zero-masked. */

  zmm_res.zmm = _mm512_set1_ps(1.0f);
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(fsrc1);
  zmm_res.zmm = _mm512_maskz_load_ps(k16, &fsrc1.zmm);

  zmm_res.zmm = _mm512_set1_ps(1.0f);
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(fsrc_arr[0]);
  zmm_res.zmm = _mm512_maskz_loadu_ps(k16, &fsrc_arr[0].f32[5]);
}

void NOINLINE do_store_and_storeu_ps() {
  V512 xmm_res[2], ymm_res[2], zmm_res[2];
  __mmask16 k16 = 0xffef;
  __mmask8 k8 = (__mmask8)k16;

  /* Non-masked. */

  zmm_res[0].zmm = _mm512_set1_ps(1.0f);
  zmm_res[1] = zmm_res[0];
  ymm_res[0] = zmm_res[0];
  ymm_res[1] = zmm_res[0];
  xmm_res[0] = zmm_res[0];
  xmm_res[1] = zmm_res[0];

  soft_v512_update(fsrc1);
  _mm512_store_ps(&zmm_res[0].zmm, fsrc1.zmm);

  soft_v512_update(fsrc1);
  _mm512_storeu_ps(&zmm_res[0].f32[1], fsrc1.zmm);
  soft_v512_update(fsrc1);
  _mm256_storeu_ps(&ymm_res[0].f32[1], fsrc1.ymm[0]);
  soft_v512_update(fsrc1);
  _mm_storeu_ps(&xmm_res[0].f32[1], fsrc1.xmm[0]);

  check_equal_nsf(&ymm_res[0].f32[1], &zmm_res[0].f32[1], 8, "_mm256_storeu_ps",
                  __LINE__);
  check_equal_nsf(&xmm_res[0].f32[1], &zmm_res[0].f32[1], 4, "_mm_storeu_ps",
                  __LINE__);

  /* Masked. */

  zmm_res[0].zmm = _mm512_set1_ps(1.0f);
  zmm_res[1] = zmm_res[0];
  ymm_res[0] = zmm_res[0];
  ymm_res[1] = zmm_res[0];
  xmm_res[0] = zmm_res[0];
  xmm_res[1] = zmm_res[0];

  soft_v512_update(fsrc1);
  _mm512_mask_store_ps(&zmm_res[0].zmm, k8, fsrc1.zmm);

  zmm_res[0].zmm = _mm512_set1_ps(1.0f);
  zmm_res[1] = zmm_res[0];
  ymm_res[0] = zmm_res[0];
  ymm_res[1] = zmm_res[0];
  xmm_res[0] = zmm_res[0];
  xmm_res[1] = zmm_res[0];

  soft_v512_update(fsrc1);
  _mm512_mask_storeu_ps(&zmm_res[0].f32[1], k8, fsrc1.zmm);
}

void NOINLINE do_load_and_loadu_epi32() {
  V512 xmm_res, ymm_res, zmm_res;
  __mmask16 k16 = 0xffef;
  __mmask8 k8 = (__mmask8)k16;

  /* Non-masked. */

  soft_v512_update(isrc1);
  zmm_res.zmmi = _mm512_load_epi32(&isrc1.zmmi);

  soft_v512_update(isrc1);
  ymm_res.zmmi = _mm512_load_si512(&isrc1.zmmi);
  check_equal_nd(&ymm_res, &zmm_res, 16, "_mm512_load_si512", __LINE__);

  soft_v512_update(isrc_arr[0]);
  zmm_res.zmmi = _mm512_loadu_si512(&isrc_arr[0].s32[1]);

  /* Masked. */

  zmm_res.zmmi = _mm512_setzero_epi32();
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(isrc1);
  zmm_res.zmmi = _mm512_mask_load_epi32(zmm_res.zmmi, k16, &isrc1.zmmi);

  zmm_res.zmmi = _mm512_setzero_epi32();
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(isrc_arr[0]);
  zmm_res.zmmi =
      _mm512_mask_loadu_epi32(zmm_res.zmmi, k16, &isrc_arr[0].s32[3]);

  /* Zero-masked. */

  zmm_res.zmmi = _mm512_set1_epi32(-7);
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(isrc1);
  zmm_res.zmmi = _mm512_maskz_load_epi32(k16, &isrc1.zmmi);

  zmm_res.zmmi = _mm512_set1_epi32(11);
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(isrc_arr[0]);
  zmm_res.zmmi = _mm512_maskz_loadu_epi32(k16, &isrc_arr[0].s32[1]);
}

void NOINLINE do_store_and_storeu_epi32() {
  V512 xmm_res[2], ymm_res[2], zmm_res[2];
  __mmask16 k16 = 0xfeff;
  __mmask8 k8 = (__mmask8)k16;

  /* Non-masked. */

  zmm_res[0].zmmi = _mm512_set1_epi32(-101);
  zmm_res[1] = zmm_res[0];
  ymm_res[0] = zmm_res[0];
  ymm_res[1] = zmm_res[0];
  xmm_res[0] = zmm_res[0];
  xmm_res[1] = zmm_res[0];

  soft_v512_update(isrc1);
  _mm512_store_epi32(&zmm_res[0].zmmi, isrc1.zmmi);
  soft_v512_update(isrc1);
  _mm256_store_si256((__m256i *)&ymm_res[0].s32[0], isrc1.ymmi[0]);
  soft_v512_update(isrc1);
  _mm_store_si128((__m128i *)&xmm_res[0].s32[0], isrc1.xmmi[0]);

  check_equal_nd(&ymm_res, &zmm_res, 8, "_mm256_store_epi32", __LINE__);
  check_equal_nd(&xmm_res, &zmm_res, 4, "_mm_store_epi32", __LINE__);

  soft_v512_update(isrc1);
  ymm_res[0].zmmi = _mm512_setzero_si512();
  _mm512_store_si512(&ymm_res[0].zmmi, isrc1.zmmi);
  check_equal_nd(&ymm_res, &zmm_res, 16, "_mm512_store_si512", __LINE__);

  soft_v512_update(isrc1);
  _mm512_storeu_si512(&zmm_res[0].s32[1], isrc1.zmmi);
  soft_v512_update(isrc1);
  _mm256_storeu_si256((__m256i *)&ymm_res[0].s32[1], isrc1.ymmi[0]);
  soft_v512_update(isrc1);
  _mm_storeu_si128((__m128i *)&xmm_res[0].s32[1], isrc1.xmmi[0]);

  check_equal_nd(&ymm_res[0].s32[1], &zmm_res[0].s32[1], 8,
                 "_mm256_storeu_si256", __LINE__);
  check_equal_nd(&xmm_res[0].s32[1], &zmm_res[0].s32[1], 4, "_mm_storeu_si128",
                 __LINE__);

  /* Masked. */

  zmm_res[0].zmmi = _mm512_set1_epi32(999);
  zmm_res[1] = zmm_res[0];
  ymm_res[0] = zmm_res[0];
  ymm_res[1] = zmm_res[0];
  xmm_res[0] = zmm_res[0];
  xmm_res[1] = zmm_res[0];

  soft_v512_update(isrc1);
  _mm512_mask_store_epi32(&zmm_res[0].zmmi, k16, isrc1.zmmi);

  zmm_res[0].zmmi = _mm512_set1_epi32(-3);
  zmm_res[1] = zmm_res[0];
  ymm_res[0] = zmm_res[0];
  ymm_res[1] = zmm_res[0];
  xmm_res[0] = zmm_res[0];
  xmm_res[1] = zmm_res[0];

  soft_v512_update(isrc1);
  _mm512_mask_storeu_epi32(&zmm_res[0].s32[1], k16, isrc1.zmmi);
}

void NOINLINE do_load_and_loadu_epi64() {
  V512 xmm_res, ymm_res, zmm_res;
  __mmask16 k8 = 0xef;

  /* Non-masked. */

  soft_v512_update(isrc1);
  zmm_res.zmmi = _mm512_load_epi64(&isrc1.zmmi);

  soft_v512_update(isrc_arr[0]);
  zmm_res.zmmi = _mm512_loadu_si512(&isrc_arr[0].s64[1]);

  /* Masked. */

  zmm_res.zmmi = _mm512_setzero_epi32();
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(isrc1);
  zmm_res.zmmi = _mm512_mask_load_epi64(zmm_res.zmmi, k8, &isrc1.zmmi);

  zmm_res.zmmi = _mm512_setzero_epi32();
  ymm_res = zmm_res;
  xmm_res = zmm_res;

  soft_v512_update(isrc_arr[0]);
  zmm_res.zmmi = _mm512_mask_loadu_epi64(zmm_res.zmmi, k8, &isrc_arr[0].s64[3]);

  /* Zero-masked. */

  zmm_res.zmmi = _mm512_set1_epi64(-7);
  ymm_res = zmm_res;
  xmm_res = zmm_res;
}

void NOINLINE do_store_and_storeu_epi64() {
  V512 xmm_res[2], ymm_res[2], zmm_res[2];
  __mmask8 k8 = 0xfe;

  /* Non-masked. */

  zmm_res[0].zmmi = _mm512_set1_epi32(-101);
  zmm_res[1] = zmm_res[0];
  ymm_res[0] = zmm_res[0];
  ymm_res[1] = zmm_res[0];
  xmm_res[0] = zmm_res[0];
  xmm_res[1] = zmm_res[0];

  soft_v512_update(isrc1);
  _mm512_store_epi64(&zmm_res[0].zmmi, isrc1.zmmi);
  soft_v512_update(isrc1);
  _mm256_store_si256((__m256i *)&ymm_res[0].s64[0], isrc1.ymmi[0]);
  soft_v512_update(isrc1);
  _mm_store_si128((__m128i *)&xmm_res[0].s64[0], isrc1.xmmi[0]);

  check_equal_nq(&ymm_res, &zmm_res, 4, "_mm256_store_epi64", __LINE__);
  check_equal_nq(&xmm_res, &zmm_res, 2, "_mm_store_si256", __LINE__);

  soft_v512_update(isrc1);
  _mm512_storeu_si512(&zmm_res[0].s64[1], isrc1.zmmi);

  /* Masked. */

  zmm_res[0].zmmi = _mm512_set1_epi32(999);
  zmm_res[1] = zmm_res[0];
  ymm_res[0] = zmm_res[0];
  ymm_res[1] = zmm_res[0];
  xmm_res[0] = zmm_res[0];
  xmm_res[1] = zmm_res[0];

  soft_v512_update(isrc1);
  _mm512_mask_store_epi64(&zmm_res[0].zmmi, k8, isrc1.zmmi);

  zmm_res[0].zmmi = _mm512_set1_epi32(-3);
  zmm_res[1] = zmm_res[0];
  ymm_res[0] = zmm_res[0];
  ymm_res[1] = zmm_res[0];
  xmm_res[0] = zmm_res[0];
  xmm_res[1] = zmm_res[0];

  soft_v512_update(isrc1);
  _mm512_mask_storeu_epi64(&zmm_res[0].s64[1], k8, isrc1.zmmi);
}

int main() {
  init();

  do_load_and_loadu_pd();
  do_load_and_loadu_ps();
  do_load_and_loadu_epi32();
  do_store_and_storeu_epi32();
  do_load_and_loadu_epi64();

  do_store_and_storeu_pd();
  do_store_and_storeu_ps();

  do_store_and_storeu_epi64();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
