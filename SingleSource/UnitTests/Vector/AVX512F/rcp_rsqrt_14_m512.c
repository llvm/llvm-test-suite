#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>
/*
 * Here we check for _mm512_[mask|maskz]_[rsqrt14|rcp14] intrinsics.
 */
#define CHECK_PD(op)                                                           \
  {                                                                            \
    volatile __m512d r = _mm512_##op##_pd(v1);                                 \
    check_equal_ndf(&r, &exp, 8, "_mm512_" #op "_pd", __LINE__);               \
    k8 = 0xAA;                                                                 \
    r = _mm512_mask_##op##_pd(undef, k8, v1);                                  \
    check_equal_ndf(&r, &expm, 8, "_mm512_mask_" #op "_pd{1}", __LINE__);      \
    r = _mm512_maskz_##op##_pd(k8, v1);                                        \
    check_equal_ndf(&r, &expzm, 8, "_mm512_maskz_" #op "_pd{0}", __LINE__);    \
  }

#define DECL_PD(op, srcv, expv)                                                \
  void NOINLINE do_##op##_pd() {                                               \
    __mmask8 k8;                                                               \
    volatile __m512d v1 = _mm512_set1_pd((srcv));                              \
                                                                               \
    volatile __m512d undef = _mm512_set1_pd(3.0);                              \
    __m512d exp = _mm512_set1_pd(expv);                                        \
    __m512d expm =                                                             \
        _mm512_set_pd((expv), 3.0, (expv), 3.0, (expv), 3.0, (expv), 3.0);     \
    __m512d expzm = _mm512_set_pd((expv), 0, (expv), 0, (expv), 0, (expv), 0); \
                                                                               \
    CHECK_PD(op);                                                              \
  }

#define TEST_PD(op) do_##op##_pd()

// PS version starts here.

#define CHECK_PS(op)                                                           \
  {                                                                            \
    volatile __m512 r = _mm512_##op##_ps(v1);                                  \
    check_equal_nsf(&r, &exp, 16, "_mm512_" #op "_ps", __LINE__);              \
    k8 = 0xAAAA;                                                               \
    r = _mm512_mask_##op##_ps(undef, k8, v1);                                  \
    check_equal_nsf(&r, &expm, 16, "_mm512_mask_" #op "_ps{1}", __LINE__);     \
    r = _mm512_maskz_##op##_ps(k8, v1);                                        \
    check_equal_nsf(&r, &expzm, 16, "_mm512_maskz_" #op "_ps{0}", __LINE__);   \
  }

#define DECL_PS(op, srcv, expv)                                                \
  void NOINLINE do_##op##_ps() {                                               \
    __mmask16 k8;                                                              \
    volatile __m512 v1 = _mm512_set1_ps((srcv));                               \
                                                                               \
    volatile __m512 undef = _mm512_set1_ps(3.0);                               \
    __m512 exp = _mm512_set1_ps(expv);                                         \
    __m512 expm =                                                              \
        _mm512_set_ps((expv), 3.0, (expv), 3.0, (expv), 3.0, (expv), 3.0,      \
                      (expv), 3.0, (expv), 3.0, (expv), 3.0, (expv), 3.0);     \
    __m512 expzm = _mm512_set_ps((expv), 0, (expv), 0, (expv), 0, (expv), 0,   \
                                 (expv), 0, (expv), 0, (expv), 0, (expv), 0);  \
                                                                               \
    CHECK_PS(op);                                                              \
  }

#define TEST_PS(op) do_##op##_ps()

DECL_PD(rsqrt14, 0.25, 2.0)
DECL_PS(rsqrt14, 0.16f, 2.5f)
DECL_PD(rcp14, 0.5, 2.0)
DECL_PS(rcp14, 0.4f, 2.5f)

int main(int argc, char *argv[]) {
  TEST_PD(rcp14);
  TEST_PS(rcp14);
  TEST_PD(rsqrt14);
  TEST_PS(rsqrt14);

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
