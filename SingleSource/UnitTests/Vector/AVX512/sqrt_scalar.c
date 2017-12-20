#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

/*
 * Here we check for _mm_[mask|mmaskz]sqrt_[round]_[ss|sd] intrinsics, but
 * _mm_sqrt_ss,_mm_sqrt_sd intrinsics that belong to
 * earlier versions of ISA.
 */

void __declspec(noinline) do_sqrt_sd() {
  __mmask8 k8;
  volatile __m128d v1 = _mm_set_pd(2.0, (15.0));
  volatile __m128d v2 = _mm_set_pd(4.0, (0.25));
  volatile __m128d undef = _mm_set_pd(333.0, 111.0);
  __m128d exp = _mm_set_pd(2.0, (0.5));
  __m128d expm1 = _mm_set_pd(2.0, (0.5));
  __m128d expm0 = _mm_set_pd(2.0, 111.0);
  __m128d expzm1 = _mm_set_pd(2.0, (0.5));
  __m128d expzm0 = _mm_set_pd(2.0, 0.0);
  volatile __m128d r;
  k8 = 1;
  r = _mm_mask_sqrt_sd(undef, k8, v1, v2);
  check_equal_ndf(&r, &expm1, 2,
                  "_mm_mask_"
                  "sqrt"
                  "_sd{1}",
                  __LINE__);
  k8 = 0;
  r = _mm_mask_sqrt_sd(undef, k8, v1, v2);
  check_equal_ndf(&r, &expm0, 2,
                  "_mm_mask_"
                  "sqrt"
                  "_sd{0}",
                  __LINE__);
  k8 = 1;
  r = _mm_maskz_sqrt_sd(k8, v1, v2);
  check_equal_ndf(&r, &expzm1, 2,
                  "_mm_maskz_"
                  "sqrt"
                  "_sd{1}",
                  __LINE__);
  k8 = 0;
  r = _mm_maskz_sqrt_sd(k8, v1, v2);
  check_equal_ndf(&r, &expzm0, 2,
                  "_mm_maskz_"
                  "sqrt"
                  "_sd{0}",
                  __LINE__);

  r = _mm_sqrt_round_sd(v1, v2, (_MM_FROUND_CUR_DIRECTION));
  check_equal_ndf(&r, &exp, 2,
                  "_mm_"
                  "sqrt"
                  "_round_sd",
                  __LINE__);
  k8 = 1;
  r = _mm_mask_sqrt_round_sd(undef, k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
  check_equal_ndf(&r, &expm1, 2,
                  "_mm_mask_"
                  "sqrt"
                  "_round_sd{1}",
                  __LINE__);
  k8 = 0;
  r = _mm_mask_sqrt_round_sd(undef, k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
  check_equal_ndf(&r, &expm0, 2,
                  "_mm_mask_"
                  "sqrt"
                  "_round_sd{0}",
                  __LINE__);
  k8 = 1;
  r = _mm_maskz_sqrt_round_sd(k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
  check_equal_ndf(&r, &expzm1, 2,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_sd{1}",
                  __LINE__);
  k8 = 0;
  r = _mm_maskz_sqrt_round_sd(k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
  check_equal_ndf(&r, &expzm0, 2,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_sd{0}",
                  __LINE__);

  r = _mm_sqrt_round_sd(v1, v2, ((_MM_FROUND_NO_EXC)));
  check_equal_ndf(&r, &exp, 2,
                  "_mm_"
                  "sqrt"
                  "_round_sd",
                  __LINE__);
  k8 = 1;
  r = _mm_mask_sqrt_round_sd(undef, k8, v1, v2, ((_MM_FROUND_NO_EXC)));
  check_equal_ndf(&r, &expm1, 2,
                  "_mm_mask_"
                  "sqrt"
                  "_round_sd{1}",
                  __LINE__);
  k8 = 0;
  r = _mm_mask_sqrt_round_sd(undef, k8, v1, v2, ((_MM_FROUND_NO_EXC)));
  check_equal_ndf(&r, &expm0, 2,
                  "_mm_mask_"
                  "sqrt"
                  "_round_sd{0}",
                  __LINE__);
  k8 = 1;
  r = _mm_maskz_sqrt_round_sd(k8, v1, v2, ((_MM_FROUND_NO_EXC)));
  check_equal_ndf(&r, &expzm1, 2,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_sd{1}",
                  __LINE__);
  k8 = 0;
  r = _mm_maskz_sqrt_round_sd(k8, v1, v2, ((_MM_FROUND_NO_EXC)));
  check_equal_ndf(&r, &expzm0, 2,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_sd{0}",
                  __LINE__);

  r = _mm_sqrt_round_sd(v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
  check_equal_ndf(&r, &exp, 2,
                  "_mm_"
                  "sqrt"
                  "_round_sd",
                  __LINE__);
  k8 = 1;
  r = _mm_mask_sqrt_round_sd(undef, k8, v1, v2,
                             ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
  check_equal_ndf(&r, &expm1, 2,
                  "_mm_mask_"
                  "sqrt"
                  "_round_sd{1}",
                  __LINE__);
  k8 = 0;
  r = _mm_mask_sqrt_round_sd(undef, k8, v1, v2,
                             ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
  check_equal_ndf(&r, &expm0, 2,
                  "_mm_mask_"
                  "sqrt"
                  "_round_sd{0}",
                  __LINE__);
  k8 = 1;
  r = _mm_maskz_sqrt_round_sd(k8, v1, v2,
                              ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
  check_equal_ndf(&r, &expzm1, 2,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_sd{1}",
                  __LINE__);
  k8 = 0;
  r = _mm_maskz_sqrt_round_sd(k8, v1, v2,
                              ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
  check_equal_ndf(&r, &expzm0, 2,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_sd{0}",
                  __LINE__);

  r = _mm_sqrt_round_sd(v1, v2,
                        ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
  check_equal_ndf(&r, &exp, 2,
                  "_mm_"
                  "sqrt"
                  "_round_sd",
                  __LINE__);
  k8 = 1;
  r = _mm_mask_sqrt_round_sd(undef, k8, v1, v2,
                             ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
  check_equal_ndf(&r, &expm1, 2,
                  "_mm_mask_"
                  "sqrt"
                  "_round_sd{1}",
                  __LINE__);
  k8 = 0;
  r = _mm_mask_sqrt_round_sd(undef, k8, v1, v2,
                             ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
  check_equal_ndf(&r, &expm0, 2,
                  "_mm_mask_"
                  "sqrt"
                  "_round_sd{0}",
                  __LINE__);
  k8 = 1;
  r = _mm_maskz_sqrt_round_sd(
      k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
  check_equal_ndf(&r, &expzm1, 2,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_sd{1}",
                  __LINE__);
  k8 = 0;
  r = _mm_maskz_sqrt_round_sd(
      k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
  check_equal_ndf(&r, &expzm0, 2,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_sd{0}",
                  __LINE__);

  r = _mm_sqrt_round_sd(v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
  check_equal_ndf(&r, &exp, 2,
                  "_mm_"
                  "sqrt"
                  "_round_sd",
                  __LINE__);
  k8 = 1;
  r = _mm_mask_sqrt_round_sd(undef, k8, v1, v2,
                             ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
  check_equal_ndf(&r, &expm1, 2,
                  "_mm_mask_"
                  "sqrt"
                  "_round_sd{1}",
                  __LINE__);
  k8 = 0;
  r = _mm_mask_sqrt_round_sd(undef, k8, v1, v2,
                             ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
  check_equal_ndf(&r, &expm0, 2,
                  "_mm_mask_"
                  "sqrt"
                  "_round_sd{0}",
                  __LINE__);
  k8 = 1;
  r = _mm_maskz_sqrt_round_sd(k8, v1, v2,
                              ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
  check_equal_ndf(&r, &expzm1, 2,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_sd{1}",
                  __LINE__);
  k8 = 0;
  r = _mm_maskz_sqrt_round_sd(k8, v1, v2,
                              ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
  check_equal_ndf(&r, &expzm0, 2,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_sd{0}",
                  __LINE__);
}
void __declspec(noinline) do_sqrt_ss() {
  __mmask8 k8;
  volatile __m128 v1 = _mm_set_ps(4.0f, 3.0f, 2.0f, (17.0f));
  volatile __m128 v2 = _mm_set_ps(8.0f, 7.0f, 6.0f, (0.16f));
  volatile __m128 undef = _mm_set_ps(777.0f, 555.0f, 333.0f, 111.0f);
  __m128 exp = _mm_set_ps(4.0f, 3.0f, 2.0f, (0.4f));
  __m128 expm1 = _mm_set_ps(4.0f, 3.0f, 2.0f, (0.4f));
  __m128 expm0 = _mm_set_ps(4.0f, 3.0f, 2.0f, 111.0f);
  __m128 expzm1 = _mm_set_ps(4.0f, 3.0f, 2.0f, (0.4f));
  __m128 expzm0 = _mm_set_ps(4.0f, 3.0f, 2.0f, 0.0f);
  volatile __m128 r;
  k8 = 1;
  r = _mm_mask_sqrt_ss(undef, k8, v1, v2);
  check_equal_nsf(&r, &expm1, 4,
                  "_mm_mask_"
                  "sqrt"
                  "_ss",
                  __LINE__);
  k8 = 0;
  r = _mm_mask_sqrt_ss(undef, k8, v1, v2);
  check_equal_nsf(&r, &expm0, 4,
                  "_mm_mask_"
                  "sqrt"
                  "_ss",
                  __LINE__);
  k8 = 1;
  r = _mm_maskz_sqrt_ss(k8, v1, v2);
  check_equal_nsf(&r, &expzm1, 4,
                  "_mm_maskz_"
                  "sqrt"
                  "_ss",
                  __LINE__);
  k8 = 0;
  r = _mm_maskz_sqrt_ss(k8, v1, v2);
  check_equal_nsf(&r, &expzm0, 4,
                  "_mm_maskz_"
                  "sqrt"
                  "_ss",
                  __LINE__);

  r = _mm_sqrt_round_ss(v1, v2, (_MM_FROUND_CUR_DIRECTION));
  check_equal_nsf(&r, &exp, 4,
                  "_mm_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 1;
  r = _mm_mask_sqrt_round_ss(undef, k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
  check_equal_nsf(&r, &expm1, 4,
                  "_mm_mask_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 0;
  r = _mm_mask_sqrt_round_ss(undef, k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
  check_equal_nsf(&r, &expm0, 4,
                  "_mm_mask_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 1;
  r = _mm_maskz_sqrt_round_ss(k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
  check_equal_nsf(&r, &expzm1, 4,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 0;
  r = _mm_maskz_sqrt_round_ss(k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
  check_equal_nsf(&r, &expzm0, 4,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);

  r = _mm_sqrt_round_ss(v1, v2, ((_MM_FROUND_NO_EXC)));
  check_equal_nsf(&r, &exp, 4,
                  "_mm_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 1;
  r = _mm_mask_sqrt_round_ss(undef, k8, v1, v2, ((_MM_FROUND_NO_EXC)));
  check_equal_nsf(&r, &expm1, 4,
                  "_mm_mask_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 0;
  r = _mm_mask_sqrt_round_ss(undef, k8, v1, v2, ((_MM_FROUND_NO_EXC)));
  check_equal_nsf(&r, &expm0, 4,
                  "_mm_mask_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 1;
  r = _mm_maskz_sqrt_round_ss(k8, v1, v2, ((_MM_FROUND_NO_EXC)));
  check_equal_nsf(&r, &expzm1, 4,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 0;
  r = _mm_maskz_sqrt_round_ss(k8, v1, v2, ((_MM_FROUND_NO_EXC)));
  check_equal_nsf(&r, &expzm0, 4,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);

  r = _mm_sqrt_round_ss(v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
  check_equal_nsf(&r, &exp, 4,
                  "_mm_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 1;
  r = _mm_mask_sqrt_round_ss(undef, k8, v1, v2,
                             ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
  check_equal_nsf(&r, &expm1, 4,
                  "_mm_mask_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 0;
  r = _mm_mask_sqrt_round_ss(undef, k8, v1, v2,
                             ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
  check_equal_nsf(&r, &expm0, 4,
                  "_mm_mask_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 1;
  r = _mm_maskz_sqrt_round_ss(k8, v1, v2,
                              ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
  check_equal_nsf(&r, &expzm1, 4,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 0;
  r = _mm_maskz_sqrt_round_ss(k8, v1, v2,
                              ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
  check_equal_nsf(&r, &expzm0, 4,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);

  r = _mm_sqrt_round_ss(v1, v2,
                        ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
  check_equal_nsf(&r, &exp, 4,
                  "_mm_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 1;
  r = _mm_mask_sqrt_round_ss(undef, k8, v1, v2,
                             ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
  check_equal_nsf(&r, &expm1, 4,
                  "_mm_mask_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 0;
  r = _mm_mask_sqrt_round_ss(undef, k8, v1, v2,
                             ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
  check_equal_nsf(&r, &expm0, 4,
                  "_mm_mask_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 1;
  r = _mm_maskz_sqrt_round_ss(
      k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
  check_equal_nsf(&r, &expzm1, 4,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 0;
  r = _mm_maskz_sqrt_round_ss(
      k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
  check_equal_nsf(&r, &expzm0, 4,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);

  r = _mm_sqrt_round_ss(v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
  check_equal_nsf(&r, &exp, 4,
                  "_mm_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 1;
  r = _mm_mask_sqrt_round_ss(undef, k8, v1, v2,
                             ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
  check_equal_nsf(&r, &expm1, 4,
                  "_mm_mask_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 0;
  r = _mm_mask_sqrt_round_ss(undef, k8, v1, v2,
                             ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
  check_equal_nsf(&r, &expm0, 4,
                  "_mm_mask_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 1;
  r = _mm_maskz_sqrt_round_ss(k8, v1, v2,
                              ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
  check_equal_nsf(&r, &expzm1, 4,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
  k8 = 0;
  r = _mm_maskz_sqrt_round_ss(k8, v1, v2,
                              ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
  check_equal_nsf(&r, &expzm0, 4,
                  "_mm_maskz_"
                  "sqrt"
                  "_round_ss",
                  __LINE__);
}

int main(int argc, char *argv[]) {
  do_sqrt_sd();
  do_sqrt_ss();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }
  printf("PASSED\n");
  return 0;
}
