/*
 * This test was created to check the correctness
 * of the following intrinsics support:
 *      _mm_getexp_round_*()
 *      _mm_mask_getexp_round_*()
 *      _mm_maskz_getexp_round_*()
 *      _mm512_getexp_*()
 *      _mm512_getexp_round_*()
 *      _mm512_mask_getexp_*()
 *      _mm512_mask_getexp_round_*()
 *      _mm512_maskz_getexp_*()
 *      _mm512_maskz_getexp_round_*()
 */

#include "m512_test_util.h"
#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

int show_op = 0;

static int NOINLINE check_ps(float val1[], float good[], int mask, int num_elem,
                             int zmask) {
  int i;
  int res = 1;

  for (i = 0; i < num_elem; i += 1) {
    if ((1 << i) & mask) {
      if (val1[i] != good[i]) {
        res = 0;
        printf("FAIL(%d): %f != %f\n", i, val1[i], good[i]);
      }
    } else if (zmask == 1) {
      if (val1[i] != 0) {
        res = 0;
        printf("FAIL(%d): %f != 0\n", i, val1[i]);
      }
    }
  }
  return (res);
}

static int NOINLINE check_ss(float val1[], float good[], float op2[], int mask,
                             int num_elem, int zmask) {
  int i = 0;
  int res = 1;

  // check first element
  if (0x1 & mask) {
    if (val1[i] != good[i]) {
      res = 0;
      printf("FAIL(%d): %f != %f\n", i, val1[i], good[i]);
    }
  } else if (zmask == 1) {
    if (val1[i] != 0) {
      res = 0;
      printf("FAIL(%d): %f != 0\n", i, val1[i]);
    }
  }

  // check other elements
  for (i = 1; i < num_elem; i += 1) {
    if (val1[i] != op2[i]) {
      res = 0;
      printf("FAIL(%d): %f != %f\n", i, val1[i], op2[i]);
    }
  }
  return (res);
}

static void NOINLINE print_f32_vec(char *pfx, float ivec[], int short_form) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  if (!short_form) {
    printf("%10.4f %10.4f %10.4f %10.4f ", ivec[15], ivec[14], ivec[13],
           ivec[12]);
    printf("%10.4f %10.4f %10.4f %10.4f ", ivec[11], ivec[10], ivec[9],
           ivec[8]);
    printf("%10.4f %10.4f %10.4f %10.4f ", ivec[7], ivec[6], ivec[5], ivec[4]);
  }
  printf("%10.4f %10.4f %10.4f %10.4f\n", ivec[3], ivec[2], ivec[1], ivec[0]);
}

static void NOINLINE init_exp_f32(float ivalout[16], float ivalexp[16],
                                  float source[16]) {
  int i;
  float expected[] = {10.0, 7.0,  24.0, 5.0,  9.0, 2.0,  22.0, 6.0,
                      0.0,  21.0, 1.0,  18.0, 2.0, 22.0, 2.0,  16.0};

#pragma clang loop vectorize(disable)
  for (i = 0; i < 16; i += 1) {
    ivalout[i] = source[i];
    ivalexp[i] = floorf(log2(fabs((source[i]))));
    ivalexp[i] = expected[i];
  }
}

static int NOINLINE check_pd(double val1[], double good[], int mask,
                             int num_elem, int zmask) {
  int i;
  int res = 1;

  for (i = 0; i < num_elem; i += 1) {
    if ((1 << i) & mask) {
      if (val1[i] != good[i]) {
        res = 0;
        printf("FAIL(%d): %f != %f\n", i, val1[i], good[i]);
      }
    } else if (zmask == 1) {
      if (val1[i] != 0) {
        res = 0;
        printf("FAIL(%d): %f != 0\n", i, val1[i]);
      }
    }
  }
  return (res);
}

static int NOINLINE check_sd(double val1[], double good[], double op2[],
                             int mask, int num_elem, int zmask) {
  int i = 0;
  int res = 1;

  // check first element
  if (0x1 & mask) {
    if (val1[i] != good[i]) {
      res = 0;
      printf("FAIL(%d): %f != %f\n", i, val1[i], good[i]);
    }
  } else if (zmask == 1) {
    if (val1[i] != 0) {
      res = 0;
      printf("FAIL(%d): %f != 0\n", i, val1[i]);
    }
  }

  // check other elements
  for (i = 1; i < num_elem; i += 1) {
    if (val1[i] != op2[i]) {
      res = 0;
      printf("FAIL(%d): %f != %f\n", i, val1[i], op2[i]);
    }
  }
  return (res);
}

static void NOINLINE print_f64_vec(char *pfx, double ivec[], int short_form) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  if (!short_form) {
    printf("%10.4f %10.4f %10.4f %10.4f ", ivec[7], ivec[6], ivec[5], ivec[4]);
  }
  printf("%10.4f %10.4f %10.4f %10.4f\n", ivec[3], ivec[2], ivec[1], ivec[0]);
}

static void NOINLINE init_exp_f64(double ivalout[8], double ivalexp[8],
                                  double source[8]) {
  int i;
  double expected[] = {10.0, 7.0, 24.0, 5.0, 9.0, 2.0, 22.0, 19.0};

#pragma clang loop vectorize(disable)
  for (i = 0; i < 8; i += 1) {
    ivalout[i] = source[i];

    //  MS does not support log2() therefore we will use pre-calculated values.
    //        ivalexp[i] = floor(log2(fabs((source[i]))));
    ivalexp[i] = expected[i];
  }
}

#define CHECK_RESULT_PS(FUNC, RES, GOOD, OP, MMASK, NUMB, ZEROM)               \
  {                                                                            \
    int passed = 0;                                                            \
    passed = check_ps(RES.f32, GOOD.f32, MMASK, NUMB, ZEROM);                  \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_f32_vec("Opand1", OP.f32, 0);                                      \
      print_f32_vec("Scalar", GOOD.f32, 0);                                    \
      print_f32_vec("Vector", RES.f32, 0);                                     \
    }                                                                          \
  }

#define CHECK_RESULT_SS(FUNC, RES, GOOD, OP1, OP2, MMASK, NUMB, ZEROM)         \
  {                                                                            \
    int passed = 0;                                                            \
    passed = check_ss(RES.f32, GOOD.f32, OP2.f32, MMASK, NUMB, ZEROM);         \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_f32_vec("Opand1", OP1.f32, 1);                                     \
      print_f32_vec("Opand2", OP2.f32, 1);                                     \
      print_f32_vec("Scalar", GOOD.f32, 1);                                    \
      print_f32_vec("Vector", RES.f32, 1);                                     \
    }                                                                          \
  }

#define CHECK_RESULT_PD(FUNC, RES, GOOD, OP, MMASK, NUMB, ZEROM)               \
  {                                                                            \
    int passed = 0;                                                            \
    passed = check_pd(RES.f64, GOOD.f64, MMASK, NUMB, ZEROM);                  \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_f64_vec("Opand1", OP.f64, 0);                                      \
      print_f64_vec("Scalar", GOOD.f64, 0);                                    \
      print_f64_vec("Vector", RES.f64, 0);                                     \
    }                                                                          \
  }

#define CHECK_RESULT_SD(FUNC, RES, GOOD, OP1, OP2, MMASK, NUMB, ZEROM)         \
  {                                                                            \
    int passed = 0;                                                            \
    passed = check_sd(RES.f64, GOOD.f64, OP2.f64, MMASK, NUMB, ZEROM);         \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_f64_vec("Opand1", OP1.f64, 1);                                     \
      print_f64_vec("Opand2", OP2.f64, 1);                                     \
      print_f64_vec("Scalar", GOOD.f64, 1);                                    \
      print_f64_vec("Vector", RES.f64, 1);                                     \
    }                                                                          \
  }

static void NOINLINE getexp_float() {
  V512 v0, v1, v2, v3, v4;

  float init[] = {1111.11, -222.22,    33333333.33, -44.44,
                  555.55,  -6.66,      7777777.77,  -86.88,
                  -1.11,   2222222.22, -3.33,       444444.44,
                  -5.55,   6666666.66, -7.77,       88888.88};

  init_exp_f32(v1.f32, v2.f32, init);
  v4.zmm = _mm512_set1_ps(1.0);
  v0.zmm = _mm512_setzero_ps();

  v3.zmm = _mm512_getexp_ps(v1.zmm);
  CHECK_RESULT_PS(_mm512_getexp_ps, v3, v2, v1, 0xffff, 16, 0);

  v3.zmm = _mm512_mask_getexp_ps(v0.zmm, 0x1ff8, v1.zmm);
  CHECK_RESULT_PS(_mm512_mask_getexp_ps, v3, v2, v1, 0x1ff8, 16, 0);

  v3.zmm = _mm512_maskz_getexp_ps(0xf18f, v1.zmm);
  CHECK_RESULT_PS(_mm512_maskz_getexp_ps, v3, v2, v1, 0xf18f, 16, 1);

  v3.zmm = _mm512_getexp_round_ps(v1.zmm, _MM_FROUND_TO_NEAREST_INT |
                                              _MM_FROUND_NO_EXC);
  CHECK_RESULT_PS(_mm512_getexp_round_ps, v3, v2, v1, 0xffff, 16, 0);

  v3.zmm = _mm512_mask_getexp_round_ps(
      v0.zmm, 0x1ff8, v1.zmm, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  CHECK_RESULT_PS(_mm512_mask_getexp_round_ps, v3, v2, v1, 0x1ff8, 16, 0);

  v3.zmm = _mm512_maskz_getexp_round_ps(
      0xf18f, v1.zmm, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  CHECK_RESULT_PS(_mm512_maskz_getexp_round_ps, v3, v2, v1, 0xf18f, 16, 1);

  v3.xmm[0] = _mm_getexp_round_ss(
      v4.xmm[0], v1.xmm[0], _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  CHECK_RESULT_SS(_mm_getexp_round_ss, v3, v2, v1, v4, 0x1, 4, 0);

  v3.xmm[0] =
      _mm_mask_getexp_round_ss(v0.xmm[0], 0x1, v4.xmm[0], v1.xmm[0],
                               _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  CHECK_RESULT_SS(_mm_mask_getexp_round_ss, v3, v2, v1, v4, 0x1, 4, 0);

  v3.xmm[0] = _mm_maskz_getexp_round_ss(
      0x0, v4.xmm[0], v1.xmm[0], _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  CHECK_RESULT_SS(_mm_maskz_getexp_round_ss, v3, v2, v1, v4, 0x0, 4, 1);
}

static void NOINLINE getexp_double() {
  V512 v0, v1, v2, v3, v4;

  double init[] = {1111.11, -222.22, 33333333.33, -44.44,
                   555.55,  -6.66,   7777777.77,  -888888.88};

  init_exp_f64(v1.f64, v2.f64, init);
  v4.zmmd = _mm512_set1_pd(1.0);
  v0.zmmd = _mm512_setzero_pd();

  v3.zmmd = _mm512_getexp_pd(v1.zmmd);
  CHECK_RESULT_PD(_mm512_getexp_pd, v3, v2, v1, 0xffff, 8, 0);

  v3.zmmd = _mm512_mask_getexp_pd(v0.zmmd, 0xf8, v1.zmmd);
  CHECK_RESULT_PD(_mm512_mask_getexp_pd, v3, v2, v1, 0xf8, 8, 0);

  v3.zmmd = _mm512_maskz_getexp_pd(0x8f, v1.zmmd);
  CHECK_RESULT_PD(_mm512_maskz_getexp_pd, v3, v2, v1, 0x8f, 8, 1);

  v3.zmmd = _mm512_getexp_round_pd(v1.zmmd, _MM_FROUND_TO_NEAREST_INT |
                                                _MM_FROUND_NO_EXC);
  CHECK_RESULT_PD(_mm512_getexp_round_pd, v3, v2, v1, 0xffff, 8, 0);

  v3.zmmd = _mm512_mask_getexp_round_pd(
      v0.zmmd, 0x1f, v1.zmmd, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  CHECK_RESULT_PD(_mm512_mask_getexp_round_pd, v3, v2, v1, 0x1f, 8, 0);

  v3.zmmd = _mm512_maskz_getexp_round_pd(
      0xf1, v1.zmmd, _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  CHECK_RESULT_PD(_mm512_maskz_getexp_round_pd, v3, v2, v1, 0xf1, 8, 1);

  v3.xmmd[0] = _mm_getexp_round_sd(
      v4.xmmd[0], v1.xmmd[0], _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  CHECK_RESULT_SD(_mm_getexp_round_sd, v3, v2, v1, v4, 0x1, 2, 0);

  v3.xmmd[0] =
      _mm_mask_getexp_round_sd(v0.xmmd[0], 0x1, v4.xmmd[0], v1.xmmd[0],
                               _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  CHECK_RESULT_SD(_mm_mask_getexp_round_sd, v3, v2, v1, v4, 0x1, 2, 0);

  v3.xmmd[0] =
      _mm_maskz_getexp_round_sd(0x0, v4.xmmd[0], v1.xmmd[0],
                                _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  CHECK_RESULT_SD(_mm_maskz_getexp_round_sd, v3, v2, v1, v4, 0x0, 2, 1);
}

int main() {
  getexp_float();
  getexp_double();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
