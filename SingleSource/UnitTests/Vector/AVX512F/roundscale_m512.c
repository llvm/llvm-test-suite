#include "m512_test_util.h"
#include <stdio.h>

/*
 * Here we check for _mm512_[mask|mmaskz]roundscale[_round]_[ss|sd] intrinsics.
 */

void __declspec(noinline) do_roundscale_pd() {
  __mmask8 k8;
  volatile __m512d v1 = _mm512_set1_pd((1.6));
  volatile __m512d undef = _mm512_set1_pd(3.0);
  __m512d exp = _mm512_set1_pd((2.0));
  __m512d exp1 = _mm512_set1_pd((1.0));
  __m512d expm = _mm512_set_pd((2.0), 3.0, (2.0), 3.0, (2.0), 3.0, (2.0), 3.0);
  __m512d expzm = _mm512_set_pd((1.0), 0, (1.0), 0, (1.0), 0, (1.0), 0);

  {
    volatile __m512d r = _mm512_roundscale_pd(v1, 0x8);
    check_equal_ndf(&r, &exp, 8, "_mm512_roundscale_pd{0x8}", __LINE__);
    r = _mm512_roundscale_pd(v1, 0x9);
    check_equal_ndf(&r, &exp1, 8, "_mm512_roundscale_pd{0x9}", __LINE__);
    k8 = 0xAA;
    r = _mm512_mask_roundscale_pd(undef, k8, v1, 0xA);
    check_equal_ndf(&r, &expm, 8, "_mm512_mask_roundscale_pd{1}{0xA}",
                    __LINE__);
    r = _mm512_maskz_roundscale_pd(k8, v1, 0xB);
    check_equal_ndf(&r, &expzm, 8, "_mm512_maskz_roundscale_pd{0}{0xB}",
                    __LINE__);
  }

  {
    volatile __m512d r =
        _mm512_roundscale_round_pd(v1, 0x8, (_MM_FROUND_CUR_DIRECTION));
    check_equal_ndf(&r, &exp, 8, "_mm512_roundscale_round_pd{0x8}", __LINE__);
    r = _mm512_roundscale_round_pd(v1, 0x9, (_MM_FROUND_CUR_DIRECTION));
    check_equal_ndf(&r, &exp1, 8, "_mm512_roundscale_round_pd{0x9}", __LINE__);
    k8 = 0xAA;
    r = _mm512_mask_roundscale_round_pd(undef, k8, v1, 0xA,
                                        (_MM_FROUND_CUR_DIRECTION));
    check_equal_ndf(&r, &expm, 8, "_mm512_mask_roundscale_round_pd{1}{0xA}",
                    __LINE__);
    r = _mm512_maskz_roundscale_round_pd(k8, v1, 0xB,
                                         (_MM_FROUND_CUR_DIRECTION));
    check_equal_ndf(&r, &expzm, 8, "_mm512_maskz_roundscale_round_pd{0}{0xB}",
                    __LINE__);
  }

  {
    volatile __m512d r =
        _mm512_roundscale_round_pd(v1, 0x8, ((_MM_FROUND_NO_EXC)));
    check_equal_ndf(&r, &exp, 8, "_mm512_roundscale_round_pd{0x8}", __LINE__);
    r = _mm512_roundscale_round_pd(v1, 0x9, ((_MM_FROUND_NO_EXC)));
    check_equal_ndf(&r, &exp1, 8, "_mm512_roundscale_round_pd{0x9}", __LINE__);
    k8 = 0xAA;
    r = _mm512_mask_roundscale_round_pd(undef, k8, v1, 0xA,
                                        ((_MM_FROUND_NO_EXC)));
    check_equal_ndf(&r, &expm, 8, "_mm512_mask_roundscale_round_pd{1}{0xA}",
                    __LINE__);
    r = _mm512_maskz_roundscale_round_pd(k8, v1, 0xB, ((_MM_FROUND_NO_EXC)));
    check_equal_ndf(&r, &expzm, 8, "_mm512_maskz_roundscale_round_pd{0}{0xB}",
                    __LINE__);
  }
}
void __declspec(noinline) do_roundscale_ps() {
  __mmask16 k8;
  volatile __m512 v1 = _mm512_set1_ps((-1.6f));
  volatile __m512 undef = _mm512_set1_ps(3.0);
  __m512 exp = _mm512_set1_ps((-2.0f));
  __m512 exp1 = _mm512_set1_ps((-2.0f));
  __m512 expm =
      _mm512_set_ps((-1.0f), 3.0, (-1.0f), 3.0, (-1.0f), 3.0, (-1.0f), 3.0,
                    (-1.0f), 3.0, (-1.0f), 3.0, (-1.0f), 3.0, (-1.0f), 3.0);
  __m512 expzm = _mm512_set_ps((-1.0f), 0, (-1.0f), 0, (-1.0f), 0, (-1.0f), 0,
                               (-1.0f), 0, (-1.0f), 0, (-1.0f), 0, (-1.0f), 0);

  {
    volatile __m512 r = _mm512_roundscale_ps(v1, 0x8);
    check_equal_nsf(&r, &exp, 16, "_mm512_roundscale_{0x8}", __LINE__);
    r = _mm512_roundscale_ps(v1, 0x9);
    check_equal_nsf(&r, &exp, 16, "_mm512_roundscale_{0x9}", __LINE__);
    k8 = 0xAAAA;
    r = _mm512_mask_roundscale_ps(undef, k8, v1, 0xA);
    check_equal_nsf(&r, &expm, 16, "_mm512_mask_roundscale_{1}{A}", __LINE__);
    r = _mm512_maskz_roundscale_ps(k8, v1, 0xB);
    check_equal_nsf(&r, &expzm, 16, "_mm512_maskz_roundscale_{0}{B}", __LINE__);
  }

  {
    volatile __m512 r =
        _mm512_roundscale_round_ps(v1, 0x8, (_MM_FROUND_CUR_DIRECTION));
    check_equal_nsf(&r, &exp, 16, "_mm512_roundscale_round_ps", __LINE__);
    r = _mm512_roundscale_round_ps(v1, 0x9, (_MM_FROUND_CUR_DIRECTION));
    check_equal_nsf(&r, &exp1, 16, "_mm512_roundscale_round_ps", __LINE__);
    k8 = 0xAAAA;
    r = _mm512_mask_roundscale_round_ps(undef, k8, v1, 0xA,
                                        (_MM_FROUND_CUR_DIRECTION));
    check_equal_nsf(&r, &expm, 16, "_mm512_mask_roundscale_round_{1}{A}",
                    __LINE__);
    r = _mm512_maskz_roundscale_round_ps(k8, v1, 0xB,
                                         (_MM_FROUND_CUR_DIRECTION));
    check_equal_nsf(&r, &expzm, 16, "_mm512_maskz_roundscale_round_{0}{B}",
                    __LINE__);
  }

  {
    volatile __m512 r =
        _mm512_roundscale_round_ps(v1, 0x8, ((_MM_FROUND_NO_EXC)));
    check_equal_nsf(&r, &exp, 16, "_mm512_roundscale_round_ps", __LINE__);
    r = _mm512_roundscale_round_ps(v1, 0x9, ((_MM_FROUND_NO_EXC)));
    check_equal_nsf(&r, &exp1, 16, "_mm512_roundscale_round_ps", __LINE__);
    k8 = 0xAAAA;
    r = _mm512_mask_roundscale_round_ps(undef, k8, v1, 0xA,
                                        ((_MM_FROUND_NO_EXC)));
    check_equal_nsf(&r, &expm, 16, "_mm512_mask_roundscale_round_{1}{A}",
                    __LINE__);
    r = _mm512_maskz_roundscale_round_ps(k8, v1, 0xB, ((_MM_FROUND_NO_EXC)));
    check_equal_nsf(&r, &expzm, 16, "_mm512_maskz_roundscale_round_{0}{B}",
                    __LINE__);
  }
}

int main(int argc, char *argv[]) {
  do_roundscale_pd();
  do_roundscale_ps();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
