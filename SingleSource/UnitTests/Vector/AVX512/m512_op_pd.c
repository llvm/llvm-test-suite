#include "m512_test_util.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * This test was created to check the correctness
 * of the following intrinsics support:
 *      _mm512_add_pd()
 *      _mm512_max_pd()
 *      _mm512_min_pd()
 *      _mm512_mask_max_pd()
 *      _mm512_mask_min_pd()
 *      _mm512_mask_mul_pd()
 *      _mm512_mask_abs_pd()
 *      _mm512_add_round_pd()
 *      _mm512_sub_round_pd()
 */

int show_op = 0;

typedef enum { ASSIGN, ABS, ADD, MAX, MIN, MUL, SUB } OPER;

static void NOINLINE intop(OPER op, double ivalout[8], double ivalop1[8],
                           double ivalop2[8]) {
  int i;
  int handled = 0;

  memset(ivalout, 0, sizeof(ivalout));
  for (i = 0; i < 8; i += 1) {
    switch (op) {
    case ASSIGN:
      handled = 1;
      ivalout[i] = ivalop1[i];
      break;
    case ABS:
      handled = 1;
      ivalout[i] = ivalop1[i] >= 0 ? ivalop1[i] : -ivalop1[i];
      break;
    case ADD:
      handled = 1;
      ivalout[i] = ivalop1[i] + ivalop2[i];
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

static int NOINLINE check(double val1[], double good[]) {
  int i;
  int res = 1;
  for (i = 0; i < 8; i += 1) {
    if (val1[i] != good[i]) {
      res = 0;
      printf("FAIL: %f != %f\n", val1[i], good[i]);
    }
  }
  return (res);
}

static int NOINLINE check_mask(double val1[], double good[], int mask) {
  int i;
  int res = 1;
  for (i = 0; i < 8; i += 1) {
    if ((1 << i) & mask) {
      if (val1[i] != good[i]) {
        res = 0;
        printf("FAIL: %f != %f\n", val1[i], good[i]);
      }
    }
  }
  return (res);
}

static void NOINLINE print_vec(char *pfx, double ivec[]) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  printf("%10.4f %10.4f %10.4f %10.4f ", ivec[7], ivec[6], ivec[5], ivec[4]);
  printf("%10.4f %10.4f %10.4f %10.4f\n", ivec[3], ivec[2], ivec[1], ivec[0]);
}

#define DOONE(OP, FUNC)                                                        \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f64, v1.f64, v2.f64);                                       \
    vvv.zmmd = FUNC(v1.zmmd, v2.zmmd);                                         \
    passed = check(vvv.f64, good.f64);                                         \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_vec("Opand1", v1.f64);                                             \
      print_vec("Opand2", v2.f64);                                             \
      print_vec("Scalar", good.f64);                                           \
      print_vec("Vector", vvv.f64);                                            \
    }                                                                          \
  }

#define DOONE_WITH_MASK(OP, FUNC, MMASK)                                       \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f64, v1.f64, v2.f64);                                       \
    vvv.zmmd = FUNC(vvv.zmmd, MMASK, v1.zmmd, v2.zmmd);                        \
    passed = check_mask(vvv.f64, good.f64, MMASK);                             \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_vec("Opand1", v1.f64);                                             \
      print_vec("Opand2", v2.f64);                                             \
      print_vec("Scalar", good.f64);                                           \
      print_vec("Vector", vvv.f64);                                            \
    }                                                                          \
  }

#define DOONE_WITH_MASK_1OP(OP, FUNC, MMASK)                                   \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f64, v1.f64, v2.f64);                                       \
    vvv.zmmd = FUNC(vvv.zmmd, MMASK, v1.zmmd);                                 \
    passed = check_mask(vvv.f64, good.f64, MMASK);                             \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_vec("Opand1", v1.f64);                                             \
      print_vec("Opand2", v2.f64);                                             \
      print_vec("Scalar", good.f64);                                           \
      print_vec("Vector", vvv.f64);                                            \
    }                                                                          \
  }

#define DOONE_ROUND(OP, FUNC, ROUND)                                           \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f64, v1.f64, v2.f64);                                       \
    vvv.zmmd = FUNC(v1.zmmd, v2.zmmd, ROUND);                                  \
    passed = check(vvv.f64, good.f64);                                         \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_vec("Opand1", v1.f64);                                             \
      print_vec("Opand2", v2.f64);                                             \
      print_vec("Scalar", good.f64);                                           \
      print_vec("Vector", vvv.f64);                                            \
    }                                                                          \
  }

#define DOONE_WITH_MASK_ROUND(OP, FUNC, MMASK, ROUND)                          \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f64, v1.f64, v2.f64);                                       \
    vvv.zmmd = FUNC(vvv.zmmd, MMASK, v1.zmmd, v2.zmmd, ROUND);                 \
    passed = check_mask(vvv.f64, good.f64, MMASK);                             \
    if (!passed) {                                                             \
      printf("FAIL " #FUNC "\n");                                              \
      n_errs++;                                                                \
    }                                                                          \
    if (!passed || show_op) {                                                  \
      print_vec("Opand1", v1.f64);                                             \
      print_vec("Opand2", v2.f64);                                             \
      print_vec("Scalar", good.f64);                                           \
      print_vec("Vector", vvv.f64);                                            \
    }                                                                          \
  }

int main() {
  double init1[] = {1, 2, -3, 4, 5, -6, 7, 8};
  double init2[] = {11, 12, 23, 24, 35, 36, 17, 38};

  V512 v1;
  V512 v2;
  V512 good;
  V512 vvv;

  intop(ASSIGN, v1.f64, init1, 0);
  intop(ASSIGN, v2.f64, init2, 0);

  // simple intrinsics
  DOONE(ADD, _mm512_add_pd);
  DOONE(MAX, _mm512_max_pd);
  DOONE(MIN, _mm512_min_pd);
  DOONE(MUL, _mm512_mul_pd);
  DOONE(SUB, _mm512_sub_pd);

  DOONE_WITH_MASK(ADD, _mm512_mask_add_pd, 0x07);
  DOONE_WITH_MASK(MAX, _mm512_mask_max_pd, 0x01);
  DOONE_WITH_MASK(MIN, _mm512_mask_min_pd, 0x03);
  DOONE_WITH_MASK(MUL, _mm512_mask_mul_pd, 0xf0);
  DOONE_WITH_MASK(SUB, _mm512_mask_sub_pd, 0x9f);

  DOONE_WITH_MASK_1OP(ABS, _mm512_mask_abs_pd, 0xf4);

  // intrinsics with rounding mode
  DOONE_ROUND(ADD, _mm512_add_round_pd,
              _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);
  DOONE_ROUND(SUB, _mm512_sub_round_pd,
              _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);

  DOONE_WITH_MASK_ROUND(ADD, _mm512_mask_add_round_pd, 0x07,
                        _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_WITH_MASK_ROUND(SUB, _mm512_mask_sub_round_pd, 0xf0,
                        _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
