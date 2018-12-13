#include "m512_test_util.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Here we check for _mm_[mask|maskz]_[add|div|max|min|mul|sub]_[round]_ss
 * intrinsics.
 */

int show_op =
#ifdef SHOW_OP
    1
#else
    0
#endif
    ;

typedef enum { ASSIGN, ADD, DIV, MAX, MIN, MUL, SUB } OPER;

static void NOINLINE intop(OPER op, float ivalout[4], float ivalop1[4],
                           float ivalop2[4]) {
  int i;
  int handled = 0;

  memset(ivalout, 0, sizeof(ivalout));
  for (i = 0; i < 4; i += 1) {
    switch (op) {
    case ASSIGN:
      handled = 1;
      ivalout[i] = ivalop1[i];
      break;
    case ADD:
      handled = 1;
      ivalout[i] = ivalop1[i] + ivalop2[i];
      break;
    case DIV:
      handled = 1;
      ivalout[i] = ivalop1[i] / ivalop2[i];
      break;
    case MAX:
      handled = 1;
      ivalout[i] = (ivalop1[i] > ivalop2[i]) ? ivalop1[i] : ivalop2[i];
      break;
    case MIN:
      handled = 1;
      ivalout[i] = (ivalop1[i] < ivalop2[i]) ? ivalop1[i] : ivalop2[i];
      break;
    case MUL:
      handled = 1;
      ivalout[i] = ivalop2[i] * ivalop1[i];
      break;
    case SUB:
      handled = 1;
      ivalout[i] = ivalop1[i] - ivalop2[i];
      break;
    default:
      printf("FAIL: bad op\n");
      break;
    }
  }
  if (!handled) {
    printf("FAIL: unsupported op\n");
    n_errs++;
  }
}

static int NOINLINE check(float val1[], float good[]) {
  int i;
  int res = 1;
  for (i = 0; i < 4; i += 1) {
    if (val1[i] != good[i]) {
      res = 0;
      printf("FAIL: %f != %f\n", val1[i], good[i]);
    }
  }
  return (res);
}

static int NOINLINE check_mask(float dest[], float val1[], float good[],
                               int mask, int zeroing) {
  int i, j;
  int res = 1;

  // elements number to check dest vector
  j = 1;

  if (mask == 1) {
    if (val1[0] != good[0]) {
      res = 0;
      printf("FAIL: %f != %f\n", val1[0], dest[0]);
    }
  } else if (mask == 0) {
    if (zeroing == 1) {
      if (val1[0] != 0) {
        res = 0;
        printf("FAIL: %f != %f\n", val1[0], dest[0]);
      }
    } else {
      j = 0;
    }
  }

  // check other elements of dest vector
  for (i = j; i < 4; i += 1) {
    if (val1[i] != dest[i]) {
      res = 0;
      printf("FAIL: %f != %f\n", val1[i], dest[i]);
    }
  }
  return (res);
}

static void NOINLINE print_vec(char *pfx, float ivec[]) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  printf("%10.4f %10.4f %10.4f %10.4f\n", ivec[3], ivec[2], ivec[1], ivec[0]);
}

#define DOONE(OP, FUNC)                                                        \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f32, v1.f32, v2.f32);                                       \
    vvv.xmm[0] = FUNC(v1.xmm[0], v2.xmm[0]);                                   \
    passed = check_mask(vvv.f32, vvv.f32, good.f32, 0x1, 0);                   \
    passed = check(vvv.f32, good.f32);                                         \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_vec("Opand1", v1.f32);                                             \
      print_vec("Opand2", v2.f32);                                             \
      print_vec("Scalar", good.f32);                                           \
      print_vec("Vector", vvv.f32);                                            \
    }                                                                          \
  }

#define DOONE_WITH_MASK(OP, FUNC, MMASK)                                       \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f32, v1.f32, v2.f32);                                       \
    vvv.xmm[0] = FUNC(vvv.xmm[0], MMASK, v1.xmm[0], v2.xmm[0]);                \
    passed = check_mask(vvv.f32, vvv.f32, good.f32, MMASK, 0);                 \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_vec("Opand1", v1.f32);                                             \
      print_vec("Opand2", v2.f32);                                             \
      print_vec("Scalar", good.f32);                                           \
      print_vec("Vector", vvv.f32);                                            \
    }                                                                          \
  }

#define DOONE_WITH_ZMASK(OP, FUNC, MMASK)                                      \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f32, v1.f32, v2.f32);                                       \
    vvv.xmm[0] = FUNC(MMASK, v1.xmm[0], v2.xmm[0]);                            \
    passed = check_mask(vvv.f32, vvv.f32, good.f32, MMASK, 1);                 \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_vec("Opand1", v1.f32);                                             \
      print_vec("Opand2", v2.f32);                                             \
      print_vec("Scalar", good.f32);                                           \
      print_vec("Vector", vvv.f32);                                            \
    }                                                                          \
  }

#define DOONE_ROUND(OP, FUNC, ROUND)                                           \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f32, v1.f32, v2.f32);                                       \
    vvv.xmm[0] = FUNC(v1.xmm[0], v2.xmm[0], ROUND);                            \
    passed = check_mask(vvv.f32, vvv.f32, good.f32, 0x1, 0);                   \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_vec("Opand1", v1.f32);                                             \
      print_vec("Opand2", v2.f32);                                             \
      print_vec("Scalar", good.f32);                                           \
      print_vec("Vector", vvv.f32);                                            \
    }                                                                          \
  }

#define DOONE_WITH_MASK_ROUND(OP, FUNC, MMASK, ROUND)                          \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f32, v1.f32, v2.f32);                                       \
    vvv.xmm[0] = FUNC(vvv.xmm[0], MMASK, v1.xmm[0], v2.xmm[0], ROUND);         \
    passed = check_mask(vvv.f32, vvv.f32, good.f32, MMASK, 0);                 \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_vec("Opand1", v1.f32);                                             \
      print_vec("Opand2", v2.f32);                                             \
      print_vec("Scalar", good.f32);                                           \
      print_vec("Vector", vvv.f32);                                            \
    }                                                                          \
  }

#define DOONE_WITH_ZMASK_ROUND(OP, FUNC, MMASK, ROUND)                         \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f32, v1.f32, v2.f32);                                       \
    vvv.xmm[0] = FUNC(MMASK, v1.xmm[0], v2.xmm[0], ROUND);                     \
    passed = check_mask(vvv.f32, vvv.f32, good.f32, MMASK, 1);                 \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_vec("Opand1", v1.f32);                                             \
      print_vec("Opand2", v2.f32);                                             \
      print_vec("Scalar", good.f32);                                           \
      print_vec("Vector", vvv.f32);                                            \
    }                                                                          \
  }

int main() {
  float init1[] = {1, -2, 3, -4, 5, 6, 7, 8, 9, 10, -11, 12, 13, 14, 15, 16};
  float init2[] = {11, 12, 23, -24, 35, 36, 17, 38,
                   42, -1, 33, 7,   8,  10, 11, 12};

  V512 v1;
  V512 v2;
  V512 good;
  V512 vvv;

  intop(ASSIGN, v1.f32, init1, 0);
  intop(ASSIGN, v2.f32, init2, 0);
  vvv.xmm[0] = _mm_setzero_ps();

  // simple intrinsics
  DOONE_WITH_MASK(ADD, _mm_mask_add_ss, 0x1);
  DOONE_WITH_MASK(MAX, _mm_mask_max_ss, 0x1);
  DOONE_WITH_MASK(MIN, _mm_mask_min_ss, 0x1);
  DOONE_WITH_MASK(MUL, _mm_mask_mul_ss, 0x1);
  DOONE_WITH_MASK(SUB, _mm_mask_sub_ss, 0x1);

  // intrinsics with rounding mode
  DOONE_ROUND(ADD, _mm_add_round_ss,
              _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_ROUND(DIV, _mm_div_round_ss,
              _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_ROUND(MAX, _mm_max_round_ss,
              _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_ROUND(MIN, _mm_min_round_ss,
              _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_ROUND(MUL, _mm_mul_round_ss,
              _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_ROUND(SUB, _mm_sub_round_ss,
              _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);

  DOONE_WITH_MASK_ROUND(ADD, _mm_mask_add_round_ss, 0x1,
                        _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_WITH_MASK_ROUND(DIV, _mm_mask_div_round_ss, 0x0,
                        _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_WITH_MASK_ROUND(MAX, _mm_mask_max_round_ss, 0x1,
                        _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_WITH_MASK_ROUND(MIN, _mm_mask_min_round_ss, 0x1,
                        _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_WITH_MASK_ROUND(MUL, _mm_mask_mul_round_ss, 0x0,
                        _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_WITH_MASK_ROUND(SUB, _mm_mask_sub_round_ss, 0x1,
                        _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);

  // intrinsics with zero mask
  DOONE_WITH_ZMASK(ADD, _mm_maskz_add_ss, 0x0);
  DOONE_WITH_ZMASK(DIV, _mm_maskz_div_ss, 0x1);
  DOONE_WITH_ZMASK(MAX, _mm_maskz_max_ss, 0x1);
  DOONE_WITH_ZMASK(MIN, _mm_maskz_min_ss, 0x1);
  DOONE_WITH_ZMASK(MUL, _mm_maskz_mul_ss, 0x1);
  DOONE_WITH_ZMASK(SUB, _mm_maskz_sub_ss, 0x0);

  DOONE_WITH_ZMASK_ROUND(ADD, _mm_maskz_add_round_ss, 0x0,
                         _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_WITH_ZMASK_ROUND(DIV, _mm_maskz_div_round_ss, 0x1,
                         _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_WITH_ZMASK_ROUND(MAX, _mm_maskz_max_round_ss, 0x0,
                         _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_WITH_ZMASK_ROUND(MIN, _mm_maskz_min_round_ss, 0x1,
                         _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_WITH_ZMASK_ROUND(MUL, _mm_maskz_mul_round_ss, 0x1,
                         _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_WITH_ZMASK_ROUND(SUB, _mm_maskz_sub_round_ss, 0x1,
                         _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
