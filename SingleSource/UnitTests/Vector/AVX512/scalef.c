#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

/*
 * Here we check for _mm_[mask|maskz]scalef_[round]_[ss|sd] intrinsics.
 */

void __declspec(noinline) do_scalef_sd() {
  __mmask8 k8;
  volatile __m128d v1 = _mm_set_pd(2.0, (2.0));
  volatile __m128d v2 = _mm_set_pd(4.0, (2.5));
  volatile __m128d undef = _mm_set_pd(333.0, 111.0);
  __m128d exp = _mm_set_pd(2.0, (8.0));
  __m128d expm1 = _mm_set_pd(2.0, (8.0));
  __m128d expm0 = _mm_set_pd(2.0, 111.0);
  __m128d expzm1 = _mm_set_pd(2.0, (8.0));
  __m128d expzm0 = _mm_set_pd(2.0, 0.0);

  {
    volatile __m128d r = _mm_scalef_sd(v1, v2);
    check_equal_ndf(&r, &exp, 2,
                    "_mm_"
                    "scalef_sd",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_scalef_sd(undef, k8, v1, v2);
    check_equal_ndf(&r, &expm1, 2, "_mm_mask_scalef_sd{1}", __LINE__);
    k8 = 0;
    r = _mm_mask_scalef_sd(undef, k8, v1, v2);
    check_equal_ndf(&r, &expm0, 2, "_mm_mask_scalef_sd{0}", __LINE__);
    k8 = 1;
    r = _mm_maskz_scalef_sd(k8, v1, v2);
    check_equal_ndf(&r, &expzm1, 2, "_mm_maskz_scalef_sd{1}", __LINE__);
    k8 = 0;
    r = _mm_maskz_scalef_sd(k8, v1, v2);
    check_equal_ndf(&r, &expzm0, 2, "_mm_maskz_scalef_sd{0}", __LINE__);
  }

  {
    volatile __m128d r =
        _mm_scalef_round_sd(v1, v2, (_MM_FROUND_CUR_DIRECTION));
    check_equal_ndf(&r, &exp, 2,
                    "_mm_"
                    "scalef_round_sd",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_scalef_round_sd(undef, k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
    check_equal_ndf(&r, &expm1, 2, "_mm_mask_scalef_round_sd{1}", __LINE__);
    k8 = 0;
    r = _mm_mask_scalef_round_sd(undef, k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
    check_equal_ndf(&r, &expm0, 2, "_mm_mask_scalef_round_sd{0}", __LINE__);
    k8 = 1;
    r = _mm_maskz_scalef_round_sd(k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
    check_equal_ndf(&r, &expzm1, 2, "_mm_maskz_scalef_round_sd{1}", __LINE__);
    k8 = 0;
    r = _mm_maskz_scalef_round_sd(k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
    check_equal_ndf(&r, &expzm0, 2, "_mm_maskz_scalef_round_sd{0}", __LINE__);
  }

  {
    volatile __m128d r = _mm_scalef_round_sd(v1, v2, ((_MM_FROUND_NO_EXC)));
    check_equal_ndf(&r, &exp, 2, "_mm_scalef_round_sd", __LINE__);
    k8 = 1;
    r = _mm_mask_scalef_round_sd(undef, k8, v1, v2, ((_MM_FROUND_NO_EXC)));
    check_equal_ndf(&r, &expm1, 2, "_mm_mask_scalef_round_sd{1}", __LINE__);
    k8 = 0;
    r = _mm_mask_scalef_round_sd(undef, k8, v1, v2, ((_MM_FROUND_NO_EXC)));
    check_equal_ndf(&r, &expm0, 2, "_mm_mask_scalef_round_sd{0}", __LINE__);
    k8 = 1;
    r = _mm_maskz_scalef_round_sd(k8, v1, v2, ((_MM_FROUND_NO_EXC)));
    check_equal_ndf(&r, &expzm1, 2, "_mm_maskz_scalef_round_sd{1}", __LINE__);
    k8 = 0;
    r = _mm_maskz_scalef_round_sd(k8, v1, v2, ((_MM_FROUND_NO_EXC)));
    check_equal_ndf(&r, &expzm0, 2, "_mm_maskz_scalef_round_sd{0}", __LINE__);
  }

  {
    volatile __m128d r =
        _mm_scalef_round_sd(v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
    check_equal_ndf(&r, &exp, 2,
                    "_mm_"
                    "scalef_round_sd",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_scalef_round_sd(undef, k8, v1, v2,
                                 ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
    check_equal_ndf(&r, &expm1, 2, "_mm_mask_scalef_round_sd{1}", __LINE__);
    k8 = 0;
    r = _mm_mask_scalef_round_sd(undef, k8, v1, v2,
                                 ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
    check_equal_ndf(&r, &expm0, 2, "_mm_mask_scalef_round_sd{0}", __LINE__);
    k8 = 1;
    r = _mm_maskz_scalef_round_sd(k8, v1, v2,
                                  ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
    check_equal_ndf(&r, &expzm1, 2, "_mm_maskz_scalef_round_sd{1}", __LINE__);
    k8 = 0;
    r = _mm_maskz_scalef_round_sd(k8, v1, v2,
                                  ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
    check_equal_ndf(&r, &expzm0, 2, "_mm_maskz_scalef_round_sd{0}", __LINE__);
  }

  {
    volatile __m128d r = _mm_scalef_round_sd(
        v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
    check_equal_ndf(&r, &exp, 2,
                    "_mm_"
                    "scalef_round_sd",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_scalef_round_sd(
        undef, k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
    check_equal_ndf(&r, &expm1, 2, "_mm_mask_scalef_round_sd{1}", __LINE__);
    k8 = 0;
    r = _mm_mask_scalef_round_sd(
        undef, k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
    check_equal_ndf(&r, &expm0, 2, "_mm_mask_scalef_round_sd{0}", __LINE__);
    k8 = 1;
    r = _mm_maskz_scalef_round_sd(
        k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
    check_equal_ndf(&r, &expzm1, 2, "_mm_maskz_scalef_round_sd{1}", __LINE__);
    k8 = 0;
    r = _mm_maskz_scalef_round_sd(
        k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
    check_equal_ndf(&r, &expzm0, 2, "_mm_maskz_scalef_round_sd{0}", __LINE__);
  }

  {
    volatile __m128d r = _mm_scalef_round_sd(
        v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
    check_equal_ndf(&r, &exp, 2,
                    "_mm_"
                    "scalef_round_sd",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_scalef_round_sd(undef, k8, v1, v2,
                                 ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
    check_equal_ndf(&r, &expm1, 2, "_mm_mask_scalef_round_sd{1}", __LINE__);
    k8 = 0;
    r = _mm_mask_scalef_round_sd(undef, k8, v1, v2,
                                 ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
    check_equal_ndf(&r, &expm0, 2, "_mm_mask_scalef_round_sd{0}", __LINE__);
    k8 = 1;
    r = _mm_maskz_scalef_round_sd(
        k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
    check_equal_ndf(&r, &expzm1, 2, "_mm_maskz_scalef_round_sd{1}", __LINE__);
    k8 = 0;
    r = _mm_maskz_scalef_round_sd(
        k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
    check_equal_ndf(&r, &expzm0, 2, "_mm_maskz_scalef_round_sd{0}", __LINE__);
  };
}
void __declspec(noinline) do_scalef_ss() {
  __mmask8 k8;
  volatile __m128 v1 = _mm_set_ps(4.0f, 3.0f, 2.0f, (2.0f));
  volatile __m128 v2 = _mm_set_ps(8.0f, 7.0f, 6.0f, (2.5f));
  volatile __m128 undef = _mm_set_ps(777.0f, 555.0f, 333.0f, 111.0f);
  __m128 exp = _mm_set_ps(4.0f, 3.0f, 2.0f, (8.0f));
  __m128 expm1 = _mm_set_ps(4.0f, 3.0f, 2.0f, (8.0f));
  __m128 expm0 = _mm_set_ps(4.0f, 3.0f, 2.0f, 111.0f);
  __m128 expzm1 = _mm_set_ps(4.0f, 3.0f, 2.0f, (8.0f));
  __m128 expzm0 = _mm_set_ps(4.0f, 3.0f, 2.0f, 0.0f);

  {
    volatile __m128 r = _mm_scalef_ss(v1, v2);
    check_equal_nsf(&r, &exp, 4,
                    "_mm_"
                    "scalef_ss",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_scalef_ss(undef, k8, v1, v2);
    check_equal_nsf(&r, &expm1, 4, "_mm_mask_scalef_ss", __LINE__);
    k8 = 0;
    r = _mm_mask_scalef_ss(undef, k8, v1, v2);
    check_equal_nsf(&r, &expm0, 4, "_mm_mask_scalef_ss", __LINE__);
    k8 = 1;
    r = _mm_maskz_scalef_ss(k8, v1, v2);
    check_equal_nsf(&r, &expzm1, 4, "_mm_maskz_scalef_ss", __LINE__);
    k8 = 0;
    r = _mm_maskz_scalef_ss(k8, v1, v2);
    check_equal_nsf(&r, &expzm0, 4, "_mm_maskz_scalef_ss", __LINE__);
  }

  {
    volatile __m128 r = _mm_scalef_round_ss(v1, v2, (_MM_FROUND_CUR_DIRECTION));
    check_equal_nsf(&r, &exp, 4,
                    "_mm_"
                    "scalef_round_ss",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_scalef_round_ss(undef, k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
    check_equal_nsf(&r, &expm1, 4, "_mm_mask_scalef_round_ss", __LINE__);
    k8 = 0;
    r = _mm_mask_scalef_round_ss(undef, k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
    check_equal_nsf(&r, &expm0, 4, "_mm_mask_scalef_round_ss", __LINE__);
    k8 = 1;
    r = _mm_maskz_scalef_round_ss(k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
    check_equal_nsf(&r, &expzm1, 4, "_mm_maskz_scalef_round_ss", __LINE__);
    k8 = 0;
    r = _mm_maskz_scalef_round_ss(k8, v1, v2, (_MM_FROUND_CUR_DIRECTION));
    check_equal_nsf(&r, &expzm0, 4, "_mm_maskz_scalef_round_ss", __LINE__);
  }

  {
    volatile __m128 r = _mm_scalef_round_ss(v1, v2, ((_MM_FROUND_NO_EXC)));
    check_equal_nsf(&r, &exp, 4,
                    "_mm_"
                    "scalef_round_ss",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_scalef_round_ss(undef, k8, v1, v2, ((_MM_FROUND_NO_EXC)));
    check_equal_nsf(&r, &expm1, 4, "_mm_mask_scalef_round_ss", __LINE__);
    k8 = 0;
    r = _mm_mask_scalef_round_ss(undef, k8, v1, v2, ((_MM_FROUND_NO_EXC)));
    check_equal_nsf(&r, &expm0, 4, "_mm_mask_scalef_round_ss", __LINE__);
    k8 = 1;
    r = _mm_maskz_scalef_round_ss(k8, v1, v2, ((_MM_FROUND_NO_EXC)));
    check_equal_nsf(&r, &expzm1, 4, "_mm_maskz_scalef_round_ss", __LINE__);
    k8 = 0;
    r = _mm_maskz_scalef_round_ss(k8, v1, v2, ((_MM_FROUND_NO_EXC)));
    check_equal_nsf(&r, &expzm0, 4, "_mm_maskz_scalef_round_ss", __LINE__);
  }

  {
    volatile __m128 r =
        _mm_scalef_round_ss(v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
    check_equal_nsf(&r, &exp, 4,
                    "_mm_"
                    "scalef_round_ss",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_scalef_round_ss(undef, k8, v1, v2,
                                 ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
    check_equal_nsf(&r, &expm1, 4, "_mm_mask_scalef_round_ss", __LINE__);
    k8 = 0;
    r = _mm_mask_scalef_round_ss(undef, k8, v1, v2,
                                 ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
    check_equal_nsf(&r, &expm0, 4, "_mm_mask_scalef_round_ss", __LINE__);
    k8 = 1;
    r = _mm_maskz_scalef_round_ss(k8, v1, v2,
                                  ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
    check_equal_nsf(&r, &expzm1, 4, "_mm_maskz_scalef_round_ss", __LINE__);
    k8 = 0;
    r = _mm_maskz_scalef_round_ss(k8, v1, v2,
                                  ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO)));
    check_equal_nsf(&r, &expzm0, 4, "_mm_maskz_scalef_round_ss", __LINE__);
  }

  {
    volatile __m128 r = _mm_scalef_round_ss(
        v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
    check_equal_nsf(&r, &exp, 4,
                    "_mm_"
                    "scalef_round_ss",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_scalef_round_ss(
        undef, k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
    check_equal_nsf(&r, &expm1, 4, "_mm_mask_scalef_round_ss", __LINE__);
    k8 = 0;
    r = _mm_mask_scalef_round_ss(
        undef, k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
    check_equal_nsf(&r, &expm0, 4, "_mm_mask_scalef_round_ss", __LINE__);
    k8 = 1;
    r = _mm_maskz_scalef_round_ss(
        k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
    check_equal_nsf(&r, &expzm1, 4, "_mm_maskz_scalef_round_ss", __LINE__);
    k8 = 0;
    r = _mm_maskz_scalef_round_ss(
        k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEAREST_INT)));
    check_equal_nsf(&r, &expzm0, 4, "_mm_maskz_scalef_round_ss", __LINE__);
  }

  {
    volatile __m128 r = _mm_scalef_round_ss(
        v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
    check_equal_nsf(&r, &exp, 4,
                    "_mm_"
                    "scalef_round_ss",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_scalef_round_ss(undef, k8, v1, v2,
                                 ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
    check_equal_nsf(&r, &expm1, 4, "_mm_mask_scalef_round_ss", __LINE__);
    k8 = 0;
    r = _mm_mask_scalef_round_ss(undef, k8, v1, v2,
                                 ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
    check_equal_nsf(&r, &expm0, 4, "_mm_mask_scalef_round_ss", __LINE__);
    k8 = 1;
    r = _mm_maskz_scalef_round_ss(
        k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
    check_equal_nsf(&r, &expzm1, 4, "_mm_maskz_scalef_round_ss", __LINE__);
    k8 = 0;
    r = _mm_maskz_scalef_round_ss(
        k8, v1, v2, ((_MM_FROUND_NO_EXC | _MM_FROUND_TO_NEG_INF)));
    check_equal_nsf(&r, &expzm0, 4, "_mm_maskz_scalef_round_ss", __LINE__);
  }
}

int main(int argc, char *argv[]) {
  do_scalef_sd();
  do_scalef_ss();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
