#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

/*
 * Here we check for _mm512_[mask_]reduce_[add|mul] intrinsics.
 */

#define CHECK_PD(op)                                                           \
  {                                                                            \
    volatile double r = _mm512_##op##_pd(v1);                                  \
    check_equal_ndf(&r, &exp1, 1, "_mm512_" #op "_pd", __LINE__);              \
    k8 = 0xAA;                                                                 \
    r = _mm512_mask_##op##_pd(k8, v1);                                         \
    check_equal_ndf(&r, &exp2, 1, "_mm512_mask_" #op "_pd{1}", __LINE__);      \
  }

#define DECL_PD(op, srcv, out1, out2)                                          \
  void NOINLINE do_##op##_pd() {                                               \
    __mmask8 k8;                                                               \
    volatile __m512d v1 = _mm512_set1_pd((srcv));                              \
                                                                               \
    double exp1 = (out1);                                                      \
    double exp2 = (out2);                                                      \
                                                                               \
    CHECK_PD(op);                                                              \
  }

#define TEST_PD(op) do_##op##_pd()

// PS version starts here.

#define CHECK_PS(op)                                                           \
  {                                                                            \
    volatile float r = _mm512_##op##_ps(v1);                                   \
    check_equal_nsf(&r, &exp1, 1, "_mm512_" #op "_ps", __LINE__);              \
    k8 = 0xAAAA;                                                               \
    r = _mm512_mask_##op##_ps(k8, v1);                                         \
    check_equal_nsf(&r, &exp2, 1, "_mm512_mask_" #op "_ps{1}", __LINE__);      \
  }

#define DECL_PS(op, srcv, out1, out2)                                          \
  void NOINLINE do_##op##_ps() {                                               \
    __mmask16 k8;                                                              \
    volatile __m512 v1 = _mm512_set1_ps((srcv));                               \
                                                                               \
    float exp1 = (out1);                                                       \
    float exp2 = (out2);                                                       \
                                                                               \
    CHECK_PS(op);                                                              \
  }

#define TEST_PS(op) do_##op##_ps()

DECL_PD(reduce_add, 0.5, 4.0, 2.0)
DECL_PS(reduce_add, 0.4f, 6.4f, 3.2f)
DECL_PD(reduce_mul, 1.1, 2.1435f, 1.4641f)
DECL_PS(reduce_mul, -1.1f, 4.5949f, 2.1435f)

int main(int argc, char *argv[]) {
  TEST_PD(reduce_add);
  TEST_PS(reduce_add);
  TEST_PD(reduce_mul);
  TEST_PS(reduce_mul);

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
