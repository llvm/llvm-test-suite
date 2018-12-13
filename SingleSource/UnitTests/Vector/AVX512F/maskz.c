
#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>
/*
 * Here we check for _mm512_maskz_[add|sub]_[round]_ps intrinsics.
 */
volatile int vol0 = 0;

V512 i32;
V512 i32_squares;
V512 i64;
V512 i64_squares;
V512 f32;
V512 f32_squares;
V512 f32_halves;
V512 f64;
V512 f64_squares;
V512 f64_halves;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 16; i++) {
    i32.s32[i] = i;
    i32_squares.s32[i] = i * i;
    f32.f32[i] = i;
    f32_squares.f32[i] = i * i;
    f32_halves.f32[i] = i + 0.5f;
  }

  for (i = 0; i < 8; i++) {
    i64.s64[i] = i;
    i64_squares.s64[i] = i * i;
    f64.f64[i] = i;
    f64_squares.f64[i] = i * i;
    f64_halves.f64[i] = i + 0.5;
  }
}

/*
 * Generate function do_"oper"_ps, which tests
 * _mm512_maskz_oper_ps(__mmask16, __m512, __m512) and
 * _mm512_maskz_oper_round_ps(__mmask16, __m512, __m512, int rounding)
 */

#define GEN_PS2_OROUND(oper)                                                   \
  void NOINLINE do_##oper##_ps() {                                             \
    V512 resm, resz;                                                           \
    __mmask16 k;                                                               \
                                                                               \
    k = 0xbcdf;                                                                \
    resm.zmm = _mm512_setzero_ps();                                            \
    resm.zmm =                                                                 \
        _mm512_mask_##oper##_ps(resm.zmm, k, f32_halves.zmm, f32_squares.zmm); \
                                                                               \
    /* Set resz to all 1's, use vol0 to make it stick. */                      \
    resz.zmmi = _mm512_ternarylogic_epi32(i32.zmmi, i32.zmmi, i32.zmmi, 0xff); \
    resz.xmm[vol0] = resz.xmm[vol0]; /* No-op. */                              \
    resz.zmm = _mm512_maskz_##oper##_ps(k, f32_halves.zmm, f32_squares.zmm);   \
    check_equal_nd(&resz, &resm, 16, "_mm512_maskz_" #oper "_ps", __LINE__);   \
                                                                               \
    /* Now with a rounding override. */                                        \
                                                                               \
    f32_squares.xmm[vol0] = f32_squares.xmm[vol0]; /* No-op. */                \
    resm.zmm = _mm512_setzero_ps();                                            \
    resm.zmm = _mm512_mask_##oper##_round_ps(                                  \
        resm.zmm, k, f32_halves.zmm, f32_squares.zmm,                          \
        _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);                            \
    f32_squares.xmm[vol0] = f32_squares.xmm[vol0]; /* No-op. */                \
                                                                               \
    /* Set resz to all 1's, use vol0 to make it stick. */                      \
    resz.zmmi = _mm512_ternarylogic_epi32(i32.zmmi, i32.zmmi, i32.zmmi, 0xff); \
    resz.xmm[vol0] = resz.xmm[vol0]; /* No-op. */                              \
                                                                               \
    resz.zmm = _mm512_maskz_##oper##_round_ps(                                 \
        k, f32_halves.zmm, f32_squares.zmm,                                    \
        _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);                            \
    check_equal_nd(&resz, &resm, 16, "_mm512_maskz_" #oper "_round_ps",        \
                   __LINE__);                                                  \
  }

GEN_PS2_OROUND(sub)
GEN_PS2_OROUND(add)

int main(int argc, char *argv[]) {
  init();

  do_add_ps();
  do_sub_ps();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
