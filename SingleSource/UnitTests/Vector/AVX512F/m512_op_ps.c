#include "m512_test_util.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * This test was created to check the correctness
 * of the following intrinsics support:
 *      _mm512_add_ps()
 *      _mm512_max_ps()
 *      _mm512_min_ps()
 *      _mm512_mask_max_ps()
 *      _mm512_mask_min_ps()
 *      _mm512_mask_mul_ps()
 *      _mm512_mask_abs_ps()
 *      _mm512_add_round_ps()
 *      _mm512_sub_round_ps()
 */


int show_op = 0;

typedef enum { ASSIGN, ABS, ADD, MAX, MIN, MUL, SUB } OPER;

static void NOINLINE intop(OPER op, float ivalout[16], float ivalop1[16],
                           float ivalop2[16]) {
  int i;
  int handled = 0;

  memset(ivalout, 0, sizeof(ivalout));
  for (i = 0; i < 16; i += 1) {
    switch (op) {
    case ASSIGN:
      handled = 1;
      ivalout[i] = ivalop1[i];
      break;
    case ADD:
      handled = 1;
      ivalout[i] = ivalop1[i] + ivalop2[i];
      break;
    case ABS:
      handled = 1;
      ivalout[i] = ivalop1[i] >= 0 ? ivalop1[i] : -ivalop1[i];
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
  for (i = 0; i < 16; i += 1) {
    if (val1[i] != good[i]) {
      res = 0;
      printf("FAIL: %f != %f\n", val1[i], good[i]);
    }
  }
  return (res);
}

static int NOINLINE check_mask(float val1[], float good[], int mask) {
  int i;
  int res = 1;
  for (i = 0; i < 16; i += 1) {
    if ((1 << i) & mask) {
      if (val1[i] != good[i]) {
        res = 0;
        printf("FAIL: %f != %f\n", val1[i], good[i]);
      }
    }
  }
  return (res);
}

static void NOINLINE print_vec(char *pfx, float ivec[]) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  printf("%10.4f %10.4f %10.4f %10.4f ", ivec[15], ivec[14], ivec[13],
         ivec[12]);
  printf("%10.4f %10.4f %10.4f %10.4f ", ivec[11], ivec[10], ivec[9], ivec[8]);
  printf("%10.4f %10.4f %10.4f %10.4f ", ivec[7], ivec[6], ivec[5], ivec[4]);
  printf("%10.4f %10.4f %10.4f %10.4f\n", ivec[3], ivec[2], ivec[1], ivec[0]);
}

#define DOONE(OP, FUNC)                                                        \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f32, v1.f32, v2.f32);                                       \
    vvv.zmm = FUNC(v1.zmm, v2.zmm);                                            \
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
    vvv.zmm = FUNC(vvv.zmm, MMASK, v1.zmm, v2.zmm);                            \
    passed = check_mask(vvv.f32, good.f32, MMASK);                             \
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

#define DOONE_WITH_MASK_1OP(OP, FUNC, MMASK)                                   \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f32, v1.f32, v2.f32);                                       \
    vvv.zmm = FUNC(vvv.zmm, MMASK, v1.zmm);                                    \
    passed = check_mask(vvv.f32, good.f32, MMASK);                             \
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
    vvv.zmm = FUNC(v1.zmm, v2.zmm, ROUND);                                     \
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

#define DOONE_WITH_MASK_ROUND(OP, FUNC, MMASK, ROUND)                          \
  {                                                                            \
    int passed = 0;                                                            \
    intop(OP, good.f32, v1.f32, v2.f32);                                       \
    vvv.zmm = FUNC(vvv.zmm, MMASK, v1.zmm, v2.zmm, ROUND);                     \
    passed = check_mask(vvv.f32, good.f32, MMASK);                             \
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
  float init1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, 12, 13, 14, 15, 16};
  float init2[] = {11, 12, 23, 24, -35, 36, 17, 38,
                   42, -1, 33, 7,  8,   10, 11, 12};

  V512 v1;
  V512 v2;
  V512 good;
  V512 vvv;

  intop(ASSIGN, v1.f32, init1, 0);
  intop(ASSIGN, v2.f32, init2, 0);

  // simple intrinsics
  DOONE(ADD, _mm512_add_ps);
  DOONE(MAX, _mm512_max_ps);
  DOONE(MIN, _mm512_min_ps);

  DOONE_WITH_MASK(MAX, _mm512_mask_max_ps, 0xf01);
  DOONE_WITH_MASK(MIN, _mm512_mask_min_ps, 0xf03);
  DOONE_WITH_MASK(MUL, _mm512_mask_mul_ps, 0xff0);

  DOONE_WITH_MASK_1OP(ABS, _mm512_mask_abs_ps, 0xcf1);

  // intrinsics with rounding mode round
  DOONE_ROUND(ADD, _mm512_add_round_ps,
              _MM_FROUND_TO_NEAREST_INT | _MM_FROUND_NO_EXC);
  DOONE_ROUND(SUB, _mm512_sub_round_ps,
              _MM_FROUND_TO_POS_INF | _MM_FROUND_NO_EXC);

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
