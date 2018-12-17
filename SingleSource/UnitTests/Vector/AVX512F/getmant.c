/*
 * Here we check for _mm512_[mask|maskz]_getmant_[round]_[pd|ps|ss|sd]
 * intrinsics.
 */

#include "m512_test_util.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

volatile int vol0 = 0;

V512 zeros;
V512 f64;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 16; i++) {
    zeros.s32[i] = 0;
  }

  for (i = 0; i < 8; i++) {
    f64.f64[i] = i;
  }
}

float getmant_ps(float src, int interval, int sc) {
  union {
    struct {
      unsigned int fraction : 23;
      unsigned int exp : 8;
      unsigned int sign : 1;
    } st;
    float value;
  } dst;
  dst.value = src;
  // Get sign bit
  dst.st.sign = (sc == _MM_MANT_SIGN_zero) ? 0 : dst.st.sign;

  int isZero = (dst.st.exp == 0) && (dst.st.fraction == 0);

  int isDenorm = (dst.st.exp == 0) && (dst.st.fraction != 0);

  int isInfinite = (dst.st.exp == 0x0FF) && (dst.st.fraction == 0);

  int isNaN = (dst.st.exp == 0x0FF) && (dst.st.fraction != 0);

  // Check for NAN operand

  if (isNaN) {
    return NAN;
  }

  // Check for Zero and Infinite operands
  if ((isZero) || (isInfinite)) {
    dst.st.exp = 0x07F;
    return dst.value;
  }

  // Check for negative operand (including -0.0)
  if ((dst.st.sign == 1) && sc == _MM_MANT_SIGN_nan) {
    return NAN;
  }

  // Checking for denormal operands
  if (isDenorm) {
    if (_MM_GET_FLUSH_ZERO_MODE() == _MM_FLUSH_ZERO_ON)
      dst.st.fraction = 0;
    else {
      int j = 0;
      dst.st.exp = 0x07F;

      while (j == 0) {
        // normalize mantissa
        j = (dst.st.fraction >> 22) & 0x1;
        // Start normalizing the mantissa
        dst.st.fraction = (dst.st.fraction << 1);

        // Adjust the exponent
        dst.st.exp--;
      }
    }
  }

  // fraction is normalized.

  // Checking for exponent response
  int isUnbiased = dst.st.exp - 0x07F;

  // subtract the bias from exponent

  int isOddExp = isUnbiased & 0x1;

  // recognized unbiased ODD exponent

  int SignalingBit = (dst.st.fraction >> 22) & 0x1;

  switch (interval) {
  case _MM_MANT_NORM_1_2:
    dst.st.exp = 0x07F;
    break;
  case _MM_MANT_NORM_p5_2:
    dst.st.exp = (isOddExp) ? 0x07E : 0x07F;
    break;
  case _MM_MANT_NORM_p5_1:
    dst.st.exp = 0x07E;
    break;
  case _MM_MANT_NORM_p75_1p5:
    dst.st.exp = (SignalingBit) ? 0x07E : 0x07F;
    break;
  }
  return dst.value;
}

double getmant_pd(double src, int interval, int sc) {
  union {
    struct {
      unsigned long int fraction : 52;
      unsigned int exp : 11;
      unsigned int sign : 1;
    } st;
    double value;
  } dst;
  dst.value = src;
  // Get sign bit
  dst.st.sign = (sc == _MM_MANT_SIGN_zero) ? 0 : dst.st.sign;

  int isZero = (dst.st.exp == 0) && (dst.st.fraction == 0);

  int isDenorm = (dst.st.exp == 0) && (dst.st.fraction != 0);

  int isInfinite = (dst.st.exp == 0x7FF) && (dst.st.fraction == 0);

  int isNaN = (dst.st.exp == 0x7FF) && (dst.st.fraction != 0);

  // Check for NAN operand

  if (isNaN) {
    return NAN;
  }

  // Check for Zero and Infinite operands
  if ((isZero) || (isInfinite)) {
    dst.st.exp = 0x03FF;
    return dst.value;
  }

  // Check for negative operand (including -0.0)
  if ((dst.st.sign == 1) && sc == _MM_MANT_SIGN_nan) {
    return NAN;
  }

  // Checking for denormal operands
  if (isDenorm) {
    if (_MM_GET_FLUSH_ZERO_MODE() == _MM_FLUSH_ZERO_ON)
      dst.st.fraction = 0;
    else {
      int j = 0;
      dst.st.exp = 0x03FF;

      while (j == 0) {
        // normalize mantissa
        j = (dst.st.fraction >> 51) & 0x1;
        // Start normalizing the mantissa
        dst.st.fraction = (dst.st.fraction << 1);

        // Adjust the exponent
        dst.st.exp--;
      }
    }
  }

  // fraction is normalized.

  // Checking for exponent response
  int isUnbiased = dst.st.exp - 0x03FF;

  // subtract the bias from exponent

  int isOddExp = isUnbiased & 0x1;

  // recognized unbiased ODD exponent

  int SignalingBit = (dst.st.fraction >> 51) & 0x1;

  switch (interval) {
  case _MM_MANT_NORM_1_2:
    dst.st.exp = 0x3FF;
    break;
  case _MM_MANT_NORM_p5_2:
    dst.st.exp = (isOddExp) ? 0x3FE : 0x3FF;
    break;
  case _MM_MANT_NORM_p5_1:
    dst.st.exp = 0x3FE;
    break;
  case _MM_MANT_NORM_p75_1p5:
    dst.st.exp = (SignalingBit) ? 0x3FE : 0x3FF;
    break;
  }
  return dst.value;
}

void emulate_getmant_ps(void *presult, const void *p, int size, int mask,
                        int zeromask, int interval, int sc) {
  int i;
  V512 *result = (V512 *)presult;
  V512 *v = (V512 *)p;
  for (i = 0; i < size; i++) {

    if (((1 << i) & mask) == 0) {
      if (zeromask)
        result->f32[i] = 0;
      else
        result->f32[i] = result->f32[i];
      continue;
    }
    result->f32[i] = getmant_ps(v->f32[i], interval, sc);
  }
}

void emulate_getmant_pd(void *presult, const void *p, int size, int mask,
                        int zeromask, int interval, int sc) {
  int i;
  V512 *result = (V512 *)presult;
  V512 *v = (V512 *)p;
  for (i = 0; i < size; i++) {

    if (((1 << i) & mask) == 0) {
      if (zeromask)
        result->f64[i] = 0;
      else
        result->f64[i] = result->f64[i];
      continue;
    }
    result->f64[i] = getmant_pd(v->f64[i], interval, sc);
  }
}

void NOINLINE do_getmantpd() {
  volatile __m512d zres, zmm;
  volatile __m512d zexpected;
  __mmask8 k = 0x75;

  zmm = f64.zmmd;
  zres = _mm512_getmant_pd(zmm, _MM_MANT_NORM_p5_1, _MM_MANT_SIGN_zero);
  emulate_getmant_pd(&zexpected, &zmm, 8, 0xffff, 0, _MM_MANT_NORM_p5_1,
                     _MM_MANT_SIGN_zero);
  check_equal_ndf(&zres, &zexpected, 8, "_mm512_getmant_pd", __LINE__);

  zres = _mm512_mask_getmant_pd(zres, k, zmm, _MM_MANT_NORM_p5_2,
                                _MM_MANT_SIGN_zero);
  emulate_getmant_pd(&zexpected, &zmm, 8, k, 0, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_ndf(&zres, &zexpected, 8, "_mm512_mask_getmant_pd", __LINE__);

  zres =
      _mm512_maskz_getmant_pd(k, zmm, _MM_MANT_NORM_p5_2, _MM_MANT_SIGN_zero);
  emulate_getmant_pd(&zexpected, &zmm, 8, k, 1, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_ndf(&zres, &zexpected, 8, "_mm512_maksz_getmant_pd", __LINE__);

  zres = _mm512_getmant_round_pd(zmm, _MM_MANT_NORM_p5_2, _MM_MANT_SIGN_zero,
                                 _MM_FROUND_CUR_DIRECTION);
  emulate_getmant_pd(&zexpected, &zmm, 8, 0xffff, 0, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_ndf(&zres, &zexpected, 8, "_mm512_getmant_round_pd", __LINE__);
  zres = _mm512_mask_getmant_round_pd(zres, k, zmm, _MM_MANT_NORM_p5_2,
                                      _MM_MANT_SIGN_zero,
                                      _MM_FROUND_CUR_DIRECTION);
  emulate_getmant_pd(&zexpected, &zmm, 8, k, 0, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_ndf(&zres, &zexpected, 8, "_mm512_mask_getmant_round_pd",
                  __LINE__);
  zres = _mm512_maskz_getmant_round_pd(
      k, zmm, _MM_MANT_NORM_p5_2, _MM_MANT_SIGN_zero, _MM_FROUND_CUR_DIRECTION);
  emulate_getmant_pd(&zexpected, &zmm, 8, k, 1, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_ndf(&zres, &zexpected, 8, "_mm512_maskz_getmant_round_pd",
                  __LINE__);
}

void NOINLINE do_getmantps() {
  volatile __m512 zres, zmm;
  volatile __m512 zexpected;
  __mmask16 k = 0x75;

  zmm = f64.zmm;
  zres = _mm512_getmant_ps(zmm, _MM_MANT_NORM_p5_1, _MM_MANT_SIGN_zero);
  emulate_getmant_ps(&zexpected, &zmm, 16, 0xffff, 0, _MM_MANT_NORM_p5_1,
                     _MM_MANT_SIGN_zero);
  check_equal_nsf(&zres, &zexpected, 16, "_mm512_getmant_ps", __LINE__);

  zres = _mm512_mask_getmant_ps(zres, k, zmm, _MM_MANT_NORM_p5_2,
                                _MM_MANT_SIGN_zero);
  emulate_getmant_ps(&zexpected, &zmm, 16, k, 0, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_nsf(&zres, &zexpected, 16, "_mm512_mask_getmant_ps", __LINE__);

  zres =
      _mm512_maskz_getmant_ps(k, zmm, _MM_MANT_NORM_p5_2, _MM_MANT_SIGN_zero);
  emulate_getmant_ps(&zexpected, &zmm, 16, k, 1, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_nsf(&zres, &zexpected, 16, "_mm512_maskz_getmant_ps", __LINE__);

  zres = _mm512_getmant_round_ps(zmm, _MM_MANT_NORM_p5_2, _MM_MANT_SIGN_zero,
                                 _MM_FROUND_CUR_DIRECTION);
  emulate_getmant_ps(&zexpected, &zmm, 16, 0xffff, 0, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_nsf(&zres, &zexpected, 16, "_mm512_getmant_round_ps", __LINE__);
  zres = _mm512_mask_getmant_round_ps(zres, k, zmm, _MM_MANT_NORM_p5_2,
                                      _MM_MANT_SIGN_zero,
                                      _MM_FROUND_CUR_DIRECTION);
  emulate_getmant_ps(&zexpected, &zmm, 16, k, 0, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_nsf(&zres, &zexpected, 16, "_mm512_mask_getmant_round_pd",
                  __LINE__);

  zres = _mm512_maskz_getmant_round_ps(
      k, zmm, _MM_MANT_NORM_p5_2, _MM_MANT_SIGN_zero, _MM_FROUND_CUR_DIRECTION);
  emulate_getmant_ps(&zexpected, &zmm, 16, k, 1, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_nsf(&zres, &zexpected, 16, "_mm512_maskz_getmant_round_pd",
                  __LINE__);
}

void NOINLINE do_getmantss() {
  volatile __m128 xres, xmm, xmm2;
  volatile __m128 xexpected;
  __mmask8 k = 0x75;
  xmm2 = zeros.xmm[0];
  xmm = f64.xmm[0];
  xres = _mm_getmant_ss(xmm2, xmm, _MM_MANT_NORM_p5_1, _MM_MANT_SIGN_zero);
  emulate_getmant_ps(&xexpected, &xmm, 4, 0x1, 1, _MM_MANT_NORM_p5_1,
                     _MM_MANT_SIGN_zero);
  check_equal_nsf(&xres, &xexpected, 4, "_mm_getmant_ss", __LINE__);

  xres = _mm_mask_getmant_ss(xres, k, xmm2, xmm, _MM_MANT_NORM_p5_2,
                             _MM_MANT_SIGN_zero);
  emulate_getmant_ps(&xexpected, &xmm, 4, 0x1 & k, 1, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_nsf(&xres, &xexpected, 4, "_mm_mask_getmant_ss", __LINE__);

  xres = _mm_maskz_getmant_ss(k, xmm2, xmm, _MM_MANT_NORM_p5_2,
                              _MM_MANT_SIGN_zero);
  emulate_getmant_ps(&xexpected, &xmm, 4, 0x1 & k, 1, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_nsf(&xres, &xexpected, 4, "_mm_maskz_getmant_ss", __LINE__);

  xres = _mm_getmant_round_ss(xmm2, xmm, _MM_MANT_NORM_p5_1, _MM_MANT_SIGN_zero,
                              _MM_FROUND_CUR_DIRECTION);
  emulate_getmant_ps(&xexpected, &xmm, 4, 0x1, 1, _MM_MANT_NORM_p5_1,
                     _MM_MANT_SIGN_zero);
  check_equal_nsf(&xres, &xexpected, 4, "_mm_getmant_round_ss", __LINE__);

  xres =
      _mm_mask_getmant_round_ss(xres, k, xmm2, xmm, _MM_MANT_NORM_p5_2,
                                _MM_MANT_SIGN_zero, _MM_FROUND_CUR_DIRECTION);
  emulate_getmant_ps(&xexpected, &xmm, 4, 0x1 & k, 1, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_nsf(&xres, &xexpected, 4, "_mm_mask_getmant_round_ss", __LINE__);

  xres =
      _mm_maskz_getmant_round_ss(k, xmm2, xmm, _MM_MANT_NORM_p5_2,
                                 _MM_MANT_SIGN_zero, _MM_FROUND_CUR_DIRECTION);
  emulate_getmant_ps(&xexpected, &xmm, 4, 0x1 & k, 1, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_nsf(&xres, &xexpected, 4, "_mm_maskz_getmant_round_ss", __LINE__);
}

void NOINLINE do_getmantsd() {
  volatile __m128d xres, xmm, xmm2;
  volatile __m128d xexpected;
  __mmask8 k = 0x75;
  xmm2 = zeros.xmmd[0];
  xmm = f64.xmmd[0];
  xres = _mm_getmant_sd(xmm2, xmm, _MM_MANT_NORM_p5_1, _MM_MANT_SIGN_zero);
  emulate_getmant_pd(&xexpected, &xmm, 2, 0x1, 1, _MM_MANT_NORM_p5_1,
                     _MM_MANT_SIGN_zero);
  check_equal_ndf(&xres, &xexpected, 2, "_mm_getmant_sd", __LINE__);
  
  xres = _mm_mask_getmant_sd(xres, k, xmm2, xmm, _MM_MANT_NORM_p5_2,
                             _MM_MANT_SIGN_zero);
  emulate_getmant_pd(&xexpected, &xmm, 2, 0x1 & k, 1, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_ndf(&xres, &xexpected, 2, "_mm_mask_getmant_sd", __LINE__);

  xres = _mm_maskz_getmant_sd(k, xmm2, xmm, _MM_MANT_NORM_p5_2,
                              _MM_MANT_SIGN_zero);
  emulate_getmant_pd(&xexpected, &xmm, 2, 0x1 & k, 1, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_ndf(&xres, &xexpected, 2, "_mm_maskz_getmant_sd", __LINE__);

  xres = _mm_getmant_round_sd(xmm2, xmm, _MM_MANT_NORM_p5_1, _MM_MANT_SIGN_zero,
                              _MM_FROUND_CUR_DIRECTION);
  emulate_getmant_pd(&xexpected, &xmm, 2, 0x1, 1, _MM_MANT_NORM_p5_1,
                     _MM_MANT_SIGN_zero);
  check_equal_ndf(&xres, &xexpected, 2, "_mm_getmant_round_sd", __LINE__);
  
  xres =
      _mm_mask_getmant_round_sd(xres, k, xmm2, xmm, _MM_MANT_NORM_p5_2,
                                _MM_MANT_SIGN_zero, _MM_FROUND_CUR_DIRECTION);
  emulate_getmant_pd(&xexpected, &xmm, 2, 0x1 & k, 1, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_ndf(&xres, &xexpected, 2, "_mm_mask_getmant_round_sd", __LINE__);

  xres =
      _mm_maskz_getmant_round_sd(k, xmm2, xmm, _MM_MANT_NORM_p5_2,
                                 _MM_MANT_SIGN_zero, _MM_FROUND_CUR_DIRECTION);
  emulate_getmant_pd(&xexpected, &xmm, 2, 0x1 & k, 1, _MM_MANT_NORM_p5_2,
                     _MM_MANT_SIGN_zero);
  check_equal_ndf(&xres, &xexpected, 2, "_mm_maskz_getmant_round_sd", __LINE__);
}

int main(int argc, char *argv[]) {
  init();

  do_getmantpd();
  do_getmantps();
  do_getmantsd();
  do_getmantss();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
