#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>
/*
 * Here we check for _mm_[mask|maskz]_[rsqrt14|rcp14] intrinsics.
 */
#define CHECK_SCALAR_SD(op)                                                    \
  {                                                                            \
    volatile __m128d r = _mm_##op##_sd(v1, v2);                                \
    check_equal_ndf(&r, &exp, 2, "_mm_" #op "_sd", __LINE__);                  \
    k8 = 1;                                                                    \
    r = _mm_mask_##op##_sd(undef, k8, v1, v2);                                 \
    check_equal_ndf(&r, &expm1, 2, "_mm_mask_" #op "_sd{1}", __LINE__);        \
    k8 = 0;                                                                    \
    r = _mm_mask_##op##_sd(undef, k8, v1, v2);                                 \
    check_equal_ndf(&r, &expm0, 2, "_mm_mask_" #op "_sd{0}", __LINE__);        \
    k8 = 1;                                                                    \
    r = _mm_maskz_##op##_sd(k8, v1, v2);                                       \
    check_equal_ndf(&r, &expzm1, 2, "_mm_maskz_" #op "_sd{1}", __LINE__);      \
    k8 = 0;                                                                    \
    r = _mm_maskz_##op##_sd(k8, v1, v2);                                       \
    check_equal_ndf(&r, &expzm0, 2, "_mm_maskz_" #op "_sd{0}", __LINE__);      \
  }

#define DECL_SCALAR_SD(op, src1v, src2v, expv)                                 \
  void NOINLINE do_##op##_sd() {                                               \
    __mmask8 k8;                                                               \
    volatile __m128d v1 = _mm_set_pd(2.0 /* upr */, (src1v) /* lwr */);        \
    volatile __m128d v2 = _mm_set_pd(4.0 /* upr */, (src2v) /* lwr */);        \
                                                                               \
    volatile __m128d undef = _mm_set_pd(333.0 /* upr */, 111.0 /* lwr */);     \
    __m128d exp = _mm_set_pd(2.0 /* upr */, (expv) /* lwr */);                 \
    __m128d expm1 = _mm_set_pd(2.0 /* upr */, (expv) /* lwr */);               \
    __m128d expm0 = _mm_set_pd(2.0 /* upr */, 111.0 /* lwr */);                \
    __m128d expzm1 = _mm_set_pd(2.0 /* upr */, (expv) /* lwr */);              \
    __m128d expzm0 = _mm_set_pd(2.0 /* upr */, 0.0 /* lwr */);                 \
                                                                               \
    CHECK_SCALAR_SD(op);                                                       \
  }

#define TEST_SCALAR_SD(op) do_##op##_sd()

#define CHECK_SCALAR_SS(op)                                                    \
  {                                                                            \
    volatile __m128 r = _mm_##op##_ss(v1, v2);                                 \
    check_equal_nsf(&r, &exp, 4, "_mm_" #op "_ss", __LINE__);                  \
    k8 = 1;                                                                    \
    r = _mm_mask_##op##_ss(undef, k8, v1, v2);                                 \
    check_equal_nsf(&r, &expm1, 4, "_mm_mask_" #op "_ss", __LINE__);           \
    k8 = 0;                                                                    \
    r = _mm_mask_##op##_ss(undef, k8, v1, v2);                                 \
    check_equal_nsf(&r, &expm0, 4, "_mm_mask_" #op "_ss", __LINE__);           \
    k8 = 1;                                                                    \
    r = _mm_maskz_##op##_ss(k8, v1, v2);                                       \
    check_equal_nsf(&r, &expzm1, 4, "_mm_maskz_" #op "_ss", __LINE__);         \
    k8 = 0;                                                                    \
    r = _mm_maskz_##op##_ss(k8, v1, v2);                                       \
    check_equal_nsf(&r, &expzm0, 4, "_mm_maskz_" #op "_ss", __LINE__);         \
  }

#define DECL_SCALAR_SS(op, src1v, src2v, expv)                                 \
  void NOINLINE do_##op##_ss() {                                               \
    __mmask8 k8;                                                               \
    volatile __m128 v1 =                                                       \
        _mm_set_ps(4.0f /* upr */, 3.0f, 2.0f, (src1v) /* lwr */);             \
    volatile __m128 v2 =                                                       \
        _mm_set_ps(8.0f /* upr */, 7.0f, 6.0f, (src2v) /* lwr */);             \
                                                                               \
    volatile __m128 undef =                                                    \
        _mm_set_ps(777.0f /* upr */, 555.0f, 333.0f, 111.0f /* lwr */);        \
    __m128 exp = _mm_set_ps(4.0f /* upr */, 3.0f, 2.0f, (expv) /* lwr */);     \
    __m128 expm1 = _mm_set_ps(4.0f /* upr */, 3.0f, 2.0f, (expv) /* lwr */);   \
    __m128 expm0 = _mm_set_ps(4.0f /* upr */, 3.0f, 2.0f, 111.0f /* lwr */);   \
    __m128 expzm1 = _mm_set_ps(4.0f /* upr */, 3.0f, 2.0f, (expv) /* lwr */);  \
    __m128 expzm0 = _mm_set_ps(4.0f /* upr */, 3.0f, 2.0f, 0.0f /* lwr */);    \
                                                                               \
    CHECK_SCALAR_SS(op);                                                       \
  }

#define TEST_SCALAR_SS(op) do_##op##_ss()

DECL_SCALAR_SD(rsqrt14, 17.0, 0.25, 2.0)
DECL_SCALAR_SS(rsqrt14, 17.0f, 0.16f, 2.5f)
DECL_SCALAR_SD(rcp14, 17.0, 0.5, 2.0)
DECL_SCALAR_SS(rcp14, 17.0f, 0.4f, 2.5f)

int main(int argc, char *argv[]) {
  TEST_SCALAR_SD(rcp14);
  TEST_SCALAR_SS(rcp14);
  TEST_SCALAR_SD(rsqrt14);
  TEST_SCALAR_SS(rsqrt14);

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
