#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

/*
 * Here we check for _mm_[mask|maskz]roundscale_[ss|sd] intrinsics.
 */

void __declspec(noinline) do_roundscale_sd() {
  __mmask8 k8;
  volatile __m128d v1 = _mm_set_pd(2.0, (15.0));
  volatile __m128d v2 = _mm_set_pd(4.0, (1.6));
  volatile __m128d undef = _mm_set_pd(333.0, 111.0);
  __m128d exp = _mm_set_pd(2.0, (2.0));
  __m128d exp1 = _mm_set_pd(2.0, (1.0));
  __m128d expm1 = _mm_set_pd(2.0, (2.0));
  __m128d expm0 = _mm_set_pd(2.0, 111.0);
  __m128d expzm1 = _mm_set_pd(2.0, (1.0));
  __m128d expzm0 = _mm_set_pd(2.0, 0.0);

  {
    volatile __m128d r = _mm_roundscale_sd(v1, v2, 0x8);
    check_equal_ndf(&r, &exp, 2,
                    "_mm_"
                    "roundscale_sd{imm=0x8}",
                    __LINE__);
    r = _mm_roundscale_sd(v1, v2, 0x9);
    check_equal_ndf(&r, &exp1, 2,
                    "_mm_"
                    "roundscale_sd{imm=0x9}",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_roundscale_sd(undef, k8, v1, v2, 0xA);
    check_equal_ndf(&r, &expm1, 2, "_mm_mask_roundscale_sd{1}{imm=0xA}",
                    __LINE__);
    k8 = 0;
    r = _mm_mask_roundscale_sd(undef, k8, v1, v2, 0x8);
    check_equal_ndf(&r, &expm0, 2, "_mm_mask_roundscale_sd{0}", __LINE__);
    k8 = 1;
    r = _mm_maskz_roundscale_sd(k8, v1, v2, 0xB);
    check_equal_ndf(&r, &expzm1, 2, "_mm_maskz_roundscale_sd{1}{imm=0xB}",
                    __LINE__);
    k8 = 0;
    r = _mm_maskz_roundscale_sd(k8, v1, v2, 0x8);
    check_equal_ndf(&r, &expzm0, 2, "_mm_maskz_roundscale_sd{0}", __LINE__);
  }
}
void __declspec(noinline) do_roundscale_ss() {
  __mmask8 k8;
  volatile __m128 v1 = _mm_set_ps(4.0f, 3.0f, 2.0f, (17.0f));
  volatile __m128 v2 = _mm_set_ps(8.0f, 7.0f, 6.0f, (-1.6f));
  volatile __m128 undef = _mm_set_ps(777.0f, 555.0f, 333.0f, 111.0f);
  __m128 exp = _mm_set_ps(4.0f, 3.0f, 2.0f, (-2.0f));
  __m128 exp1 = _mm_set_ps(4.0f, 3.0f, 2.0f, (-2.0f));
  __m128 expm1 = _mm_set_ps(4.0f, 3.0f, 2.0f, (-1.0f));
  __m128 expm0 = _mm_set_ps(4.0f, 3.0f, 2.0f, 111.0f);
  __m128 expzm1 = _mm_set_ps(4.0f, 3.0f, 2.0f, (-1.0f));
  __m128 expzm0 = _mm_set_ps(4.0f, 3.0f, 2.0f, 0.0f);

  {
    volatile __m128 r = _mm_roundscale_ss(v1, v2, 0x8);
    check_equal_nsf(&r, &exp, 4,
                    "_mm_"
                    "roundscale_ss{imm=0x8}",
                    __LINE__);
    r = _mm_roundscale_ss(v1, v2, 0x9);
    check_equal_nsf(&r, &exp1, 4,
                    "_mm_"
                    "roundscale_ss{imm=0x9}",
                    __LINE__);
    k8 = 1;
    r = _mm_mask_roundscale_ss(undef, k8, v1, v2, 0xA);
    check_equal_nsf(&r, &expm1, 4, "_mm_mask_roundscale_ss{imm=0xA}", __LINE__);
    k8 = 0;
    r = _mm_mask_roundscale_ss(undef, k8, v1, v2, 0x8);
    check_equal_nsf(&r, &expm0, 4, "_mm_mask_roundscale_ss", __LINE__);
    k8 = 1;
    r = _mm_maskz_roundscale_ss(k8, v1, v2, 0xB);
    check_equal_nsf(&r, &expzm1, 4, "_mm_maskz_roundscale_ss{imm=0xB}",
                    __LINE__);
    k8 = 0;
    r = _mm_maskz_roundscale_ss(k8, v1, v2, 0x8);
    check_equal_nsf(&r, &expzm0, 4, "_mm_maskz_roundscale_ss", __LINE__);
  }
}

int main(int argc, char *argv[]) {
  do_roundscale_sd();
  do_roundscale_ss();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
