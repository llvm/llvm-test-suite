#include "m512_test_util.h"
#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Test reduce instructions.
 * Here we check for _mm512_[mask_]reduce_[add|mul|min|max|and|or] intrinsics.
 */

typedef long long s64;
typedef unsigned long long u64;

typedef float f32;
typedef double f64;

typedef int s32;
typedef unsigned int u32;

int verbose = 0;
#define VERBOSE (verbose > 1)
#define SHOW_OP (verbose > 2)

typedef enum {
  ASSIGN,
  ADD,
  REDUCE_ADD,
  REDUCE_MUL,
  REDUCE_MIN,
  REDUCE_MAX,
  REDUCE_GMIN,
  REDUCE_GMAX,
  REDUCE_OR,
  REDUCE_AND
} OPER;

__mmask16 mask_true = 0xffff;

#define MASK(mask, n) ((mask & (0x1 << n)) != 0)

#define IMin(i, j) (((i) <= (j)) ? (i) : (j))
#define IMax(i, j) (((i) >= (j)) ? (i) : (j))

#define MULOP(a, b) (a * b)
#define ADDOP(a, b) (a + b)
#define OROP(a, b) (a | b)
#define ANDOP(a, b) (a & b)
#define GMINOP(a, b) fmin(a, b)
#define GMAXOP(a, b) fmax(a, b)

#define DO_MASK_COPY(len, output, mask, input, def)                            \
  {                                                                            \
    int n;                                                                     \
                                                                               \
    for (n = 0; n < len; n += 1) {                                             \
      if (MASK(mask, n)) {                                                     \
        output[n] = input[n];                                                  \
      } else {                                                                 \
        output[n] = def;                                                       \
      }                                                                        \
    }                                                                          \
  }

#define DO_REDUCE_16(res, mask, input, dtype, oper, initval)                   \
  {                                                                            \
    dtype dtype##tmp[4];                                                       \
    V512 vtmp;                                                                 \
    DO_MASK_COPY(16, vtmp.dtype, mask, input, initval);                        \
                                                                               \
    dtype##tmp[0] = oper(vtmp.dtype[0], vtmp.dtype[4]);                        \
    dtype##tmp[1] = oper(vtmp.dtype[1], vtmp.dtype[5]);                        \
    dtype##tmp[2] = oper(vtmp.dtype[2], vtmp.dtype[6]);                        \
    dtype##tmp[3] = oper(vtmp.dtype[3], vtmp.dtype[7]);                        \
                                                                               \
    dtype##tmp[0] = oper(dtype##tmp[0], vtmp.dtype[8]);                        \
    dtype##tmp[1] = oper(dtype##tmp[1], vtmp.dtype[9]);                        \
    dtype##tmp[2] = oper(dtype##tmp[2], vtmp.dtype[10]);                       \
    dtype##tmp[3] = oper(dtype##tmp[3], vtmp.dtype[11]);                       \
                                                                               \
    dtype##tmp[0] = oper(dtype##tmp[0], vtmp.dtype[12]);                       \
    dtype##tmp[1] = oper(dtype##tmp[1], vtmp.dtype[13]);                       \
    dtype##tmp[2] = oper(dtype##tmp[2], vtmp.dtype[14]);                       \
    dtype##tmp[3] = oper(dtype##tmp[3], vtmp.dtype[15]);                       \
                                                                               \
    dtype##tmp[0] = oper(dtype##tmp[0], dtype##tmp[1]);                        \
    dtype##tmp[2] = oper(dtype##tmp[2], dtype##tmp[3]);                        \
                                                                               \
    res = oper(dtype##tmp[0], dtype##tmp[2]);                                  \
  }

#define DO_REDUCE_8(res, mask, input, dtype, oper, initval)                    \
  {                                                                            \
    dtype dtype##tmp[4];                                                       \
    V512 vtmp;                                                                 \
    DO_MASK_COPY(8, vtmp.dtype, mask, input, initval);                         \
                                                                               \
    dtype##tmp[0] = oper(vtmp.dtype[0], vtmp.dtype[4]);                        \
    dtype##tmp[1] = oper(vtmp.dtype[1], vtmp.dtype[5]);                        \
    dtype##tmp[2] = oper(vtmp.dtype[2], vtmp.dtype[6]);                        \
    dtype##tmp[3] = oper(vtmp.dtype[3], vtmp.dtype[7]);                        \
                                                                               \
    dtype##tmp[0] = oper(dtype##tmp[0], dtype##tmp[1]);                        \
    dtype##tmp[2] = oper(dtype##tmp[2], dtype##tmp[3]);                        \
                                                                               \
    res = oper(dtype##tmp[0], dtype##tmp[2]);                                  \
  }

static int NOINLINE mask_s32_reduce_op(OPER op, __mmask16 mask,
                                       int s32op1[16]) {
  int handled = 0;
  int res;

  switch (op) {

  case REDUCE_ADD:
    handled = 1;
    DO_REDUCE_16(res, mask, s32op1, s32, ADDOP, 0);
    break;

  case REDUCE_MUL:
    handled = 1;
    DO_REDUCE_16(res, mask, s32op1, s32, MULOP, 1);
    break;

  case REDUCE_MIN:
    handled = 1;
    DO_REDUCE_16(res, mask, s32op1, s32, IMin, 0x7fffffff);
    break;

  case REDUCE_MAX:
    handled = 1;
    DO_REDUCE_16(res, mask, s32op1, s32, IMax, 0x80000000);
    break;

  case REDUCE_OR:
    handled = 1;
    DO_REDUCE_16(res, mask, s32op1, s32, OROP, 0);
    break;

  case REDUCE_AND:
    handled = 1;
    DO_REDUCE_16(res, mask, s32op1, s32, ANDOP, 0xffffffff);
    break;

  default:
    printf("FAIL: mask_s32_reduce_op: bad op\n");
    exit(1);
    break;
  }
  if (!handled) {
    printf("FAIL: mask_s32_reduce_op: unsupported op\n");
  }
  return (res);
}

static int NOINLINE mask_u32_reduce_op(OPER op, __mmask16 mask,
                                       u32 u32op1[16]) {
  int handled = 0;
  int res;

  switch (op) {

  case REDUCE_MIN:
    handled = 1;
    DO_REDUCE_16(res, mask, u32op1, u32, IMin, 0xffffffff);
    break;

  case REDUCE_MAX:
    handled = 1;
    DO_REDUCE_16(res, mask, u32op1, u32, IMax, 0x00000000);
    break;

  default:
    printf("FAIL: mask_u32_reduce_op: bad op\n");
    exit(1);
    break;
  }
  if (!handled) {
    printf("FAIL: mask_u32_reduce_op: unsupported op\n");
  }
  return (res);
}

static void NOINLINE init_s32(int s32out[16], int s32op1[16]) {
  int i = 0;
  for (i = 0; i < 16; i++) {
    s32out[i] = s32op1[i];
  }
}

static void NOINLINE init_f32(float f32out[16], float f32op1[16]) {
  int i = 0;
  for (i = 0; i < 16; i++) {
    f32out[i] = f32op1[i];
  }
}

static float NOINLINE mask_f32_reduce_op(OPER op, __mmask16 mask,
                                         float valop1[16]) {
  int handled = 0;
  float res;
  union {
    float f32init;
    int s32init;
  } init;

  switch (op) {

  case REDUCE_ADD:
    handled = 1;
    DO_REDUCE_16(res, mask, valop1, f32, ADDOP, 0.0);
    break;

  case REDUCE_MUL:
    handled = 1;
    DO_REDUCE_16(res, mask, valop1, f32, MULOP, 1.0);
    break;

  case REDUCE_GMIN:
    handled = 1;
    init.s32init = 0x7f800000; /* +inf */
    DO_REDUCE_16(res, mask, valop1, f32, GMINOP, init.f32init);
    break;

  case REDUCE_GMAX:
    handled = 1;
    init.s32init = 0xff800000; /* -inf */
    DO_REDUCE_16(res, mask, valop1, f32, GMAXOP, init.f32init);
    break;

  default:
    printf("FAIL: mask_f32_reduce_op: bad op\n");
    exit(1);
    break;
  }
  if (!handled) {
    printf("FAIL: mask_f32_reduce_op: unsupported op\n");
  }
  return (res);
}

static void NOINLINE init_f64(double f64out[8], double f64op1[8]) {
  int i = 0;
  for (i = 0; i < 8; i++) {
    f64out[i] = f64op1[i];
  }
}

static double NOINLINE mask_f64_reduce_op(OPER op, __mmask16 mask,
                                          double valop1[8]) {
  int handled = 0;
  double res;
  union {
    double f64init;
    int s32init[2];
  } init;

  switch (op) {

  case REDUCE_ADD:
    handled = 1;
    DO_REDUCE_8(res, mask, valop1, f64, ADDOP, 0.0);
    break;

  case REDUCE_MUL:
    handled = 1;
    DO_REDUCE_8(res, mask, valop1, f64, MULOP, 1.0);
    break;

  case REDUCE_GMIN:
    handled = 1;
    init.s32init[0] = 0x00000000; /* +inf */
    init.s32init[1] = 0x7ff00000; /* +inf */
    DO_REDUCE_8(res, mask, valop1, f64, GMINOP, init.f64init);
    break;

  case REDUCE_GMAX:
    handled = 1;
    init.s32init[0] = 0x00000000; /* -inf */
    init.s32init[1] = 0xfff00000; /* -inf */
    DO_REDUCE_8(res, mask, valop1, f64, GMAXOP, init.f64init);
    break;

  default:
    printf("FAIL: mask_f64_reduce_op: bad op\n");
    exit(1);
    break;
  }
  if (!handled) {
    printf("FAIL: mask_f64_reduce_op: unsupported op\n");
  }
  return (res);
}

static void NOINLINE print_s32(char *pfx, int var) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  printf("%5d", var);
  printf("\n");
}

static void NOINLINE print_u32(char *pfx, u32 var) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  printf("%5u", var);
  printf("\n");
}

static void NOINLINE print_f32(char *pfx, float var) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  printf("%5.2f", var);
  printf("\n");
}

static void NOINLINE print_f64(char *pfx, double var) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  printf("%5.2lf", var);
  printf("\n");
}

static void NOINLINE print_ivec(char *pfx, int ivec[]) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  char *fmt = "%5d %5d %5d %5d ";
  printf(fmt, ivec[15], ivec[14], ivec[13], ivec[12]);
  printf(fmt, ivec[11], ivec[10], ivec[9], ivec[8]);
  printf(fmt, ivec[7], ivec[6], ivec[5], ivec[4]);
  printf(fmt, ivec[3], ivec[2], ivec[1], ivec[0]);
  printf("\n");
}

static void NOINLINE print_uvec(char *pfx, u32 ivec[]) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  char *fmt = "%5u %5u %5u %5u ";
  printf(fmt, ivec[15], ivec[14], ivec[13], ivec[12]);
  printf(fmt, ivec[11], ivec[10], ivec[9], ivec[8]);
  printf(fmt, ivec[7], ivec[6], ivec[5], ivec[4]);
  printf(fmt, ivec[3], ivec[2], ivec[1], ivec[0]);
  printf("\n");
}

static void NOINLINE print_fvec(char *pfx, float fvec[]) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  char *fmt = "%5.2f %5.2f %5.2f %5.2f ";
  printf(fmt, fvec[15], fvec[14], fvec[13], fvec[12]);
  printf(fmt, fvec[11], fvec[10], fvec[9], fvec[8]);
  printf(fmt, fvec[7], fvec[6], fvec[5], fvec[4]);
  printf(fmt, fvec[3], fvec[2], fvec[1], fvec[0]);
  printf("\n");
}

static void NOINLINE print_dvec(char *pfx, double dvec[]) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  char *fmt = "%5.2lf %5.2lf %5.2lf %5.2lf ";
  printf(fmt, dvec[7], dvec[6], dvec[5], dvec[4]);
  printf(fmt, dvec[3], dvec[2], dvec[1], dvec[0]);
  printf("\n");
}

#define PRINT_MASK(bits, width, pfx, var)                                      \
  print_mask(bits, "%" #width "d ", pfx, var)

static void NOINLINE print_mask(int bits, char *fmt, char *pfx,
                                __mmask16 mask) {
  int i;
  if (pfx) {
    printf("%s: ", pfx);
  }
  for (i = bits; i >= 1; i -= 1) {
    printf(fmt, MASK(mask, (i - 1)));
  }
  printf("\n");
}

#define CHECK_PRINT(STATUS, FUNC)                                              \
  if (!(STATUS)) {                                                             \
    printf("FAIL " #FUNC "\n");                                                \
    err += 1;                                                                  \
  } else if (VERBOSE) {                                                        \
    printf("PASS " #FUNC "\n");                                                \
  }

#define CHECK_REDUCE_S32(FUNC)                                                 \
  {                                                                            \
    int passed = (result == mresult);                                          \
    CHECK_PRINT(passed, FUNC);                                                 \
    if (!passed || SHOW_OP) {                                                  \
      print_ivec("Opand1", v1.s32);                                            \
      print_s32("Scalar", result);                                             \
      print_s32("Vector", mresult);                                            \
    }                                                                          \
  }

#define CHECK_REDUCE_U32(FUNC)                                                 \
  {                                                                            \
    int passed = (result == mresult);                                          \
    CHECK_PRINT(passed, FUNC);                                                 \
    if (!passed || SHOW_OP) {                                                  \
      print_uvec("Opand1", v1.u32);                                            \
      print_u32("Scalar", result);                                             \
      print_u32("Vector", mresult);                                            \
    }                                                                          \
  }

#define CHECK_MASK_REDUCE_S32(FUNC)                                            \
  {                                                                            \
    int passed = (result == mresult);                                          \
    CHECK_PRINT(passed, FUNC);                                                 \
    if (!passed || SHOW_OP) {                                                  \
      print_ivec("Opand1", v1.s32);                                            \
      PRINT_MASK(16, 5, "  Mask", mask);                                       \
      print_s32("Scalar", result);                                             \
      print_s32("Vector", mresult);                                            \
    }                                                                          \
  }

#define CHECK_MASK_REDUCE_U32(FUNC)                                            \
  {                                                                            \
    int passed = (result == mresult);                                          \
    CHECK_PRINT(passed, FUNC);                                                 \
    if (!passed || SHOW_OP) {                                                  \
      print_uvec("Opand1", v1.u32);                                            \
      PRINT_MASK(16, 5, "  Mask", mask);                                       \
      print_u32("Scalar", result);                                             \
      print_u32("Vector", mresult);                                            \
    }                                                                          \
  }

#define CHECK_REDUCE_F32(FUNC)                                                 \
  {                                                                            \
    int passed = (result == mresult);                                          \
    CHECK_PRINT(passed, FUNC);                                                 \
    if (!passed || SHOW_OP) {                                                  \
      print_fvec("Opand1", v1.f32);                                            \
      print_f32("Scalar", result);                                             \
      print_f32("Vector", mresult);                                            \
    }                                                                          \
  }

#define CHECK_MASK_REDUCE_F32(FUNC)                                            \
  {                                                                            \
    int passed = (result == mresult);                                          \
    CHECK_PRINT(passed, FUNC);                                                 \
    if (!passed || SHOW_OP) {                                                  \
      print_fvec("Opand1", v1.f32);                                            \
      PRINT_MASK(16, 9, "  Mask", mask);                                       \
      print_f32("Scalar", result);                                             \
      print_f32("Vector", mresult);                                            \
    }                                                                          \
  }

#define CHECK_REDUCE_F64(FUNC)                                                 \
  {                                                                            \
    int passed = (result == mresult);                                          \
    CHECK_PRINT(passed, FUNC);                                                 \
    if (!passed || SHOW_OP) {                                                  \
      print_dvec("Opand1", v1.f64);                                            \
      print_f64("Scalar", result);                                             \
      print_f64("Vector", mresult);                                            \
    }                                                                          \
  }

#define CHECK_MASK_REDUCE_F64(FUNC)                                            \
  {                                                                            \
    int passed = (result == mresult);                                          \
    CHECK_PRINT(passed, FUNC);                                                 \
    if (!passed || SHOW_OP) {                                                  \
      print_dvec("Opand1", v1.f64);                                            \
      PRINT_MASK(8, 10, "  Mask", mask);                                       \
      print_f64("Scalar", result);                                             \
      print_f64("Vector", mresult);                                            \
    }                                                                          \
  }

#define DOONE_REDUCE_S32(OP, FUNC)                                             \
  {                                                                            \
    int result;                                                                \
    int mresult;                                                               \
    result = mask_s32_reduce_op(OP, mask_true, v1.s32);                        \
    mresult = FUNC(v1.zmmi);                                                   \
    CHECK_REDUCE_S32(FUNC);                                                    \
  }

#define DOONE_MASK_REDUCE_S32(OP, mask, FUNC)                                  \
  {                                                                            \
    int result;                                                                \
    int mresult;                                                               \
    result = mask_s32_reduce_op(OP, mask, v1.s32);                             \
    mresult = FUNC(mask, v1.zmmi);                                             \
    CHECK_MASK_REDUCE_S32(FUNC);                                               \
  }

#define DOONE_REDUCE_U32(OP, FUNC)                                             \
  {                                                                            \
    u32 result;                                                                \
    u32 mresult;                                                               \
    result = mask_u32_reduce_op(OP, mask_true, v1.u32);                        \
    mresult = FUNC(v1.zmmi);                                                   \
    CHECK_REDUCE_U32(FUNC);                                                    \
  }

#define DOONE_MASK_REDUCE_U32(OP, mask, FUNC)                                  \
  {                                                                            \
    int result;                                                                \
    int mresult;                                                               \
    result = mask_u32_reduce_op(OP, mask, v1.u32);                             \
    mresult = FUNC(mask, v1.zmmi);                                             \
    CHECK_MASK_REDUCE_U32(FUNC);                                               \
  }

#define DOONE_REDUCE_F32(OP, FUNC)                                             \
  {                                                                            \
    float result;                                                              \
    float mresult;                                                             \
    result = mask_f32_reduce_op(OP, mask_true, v1.f32);                        \
    mresult = FUNC(v1.zmm);                                                    \
    CHECK_REDUCE_F32(FUNC);                                                    \
  }

#define DOONE_MASK_REDUCE_F32(OP, mask, FUNC)                                  \
  {                                                                            \
    float result;                                                              \
    float mresult;                                                             \
    result = mask_f32_reduce_op(OP, mask, v1.f32);                             \
    mresult = FUNC(mask, v1.zmm);                                              \
    CHECK_MASK_REDUCE_F32(FUNC);                                               \
  }

#define DOONE_REDUCE_F64(OP, FUNC)                                             \
  {                                                                            \
    double result;                                                             \
    double mresult;                                                            \
    result = mask_f64_reduce_op(OP, mask_true, v1.f64);                        \
    mresult = FUNC(v1.zmmd);                                                   \
    CHECK_REDUCE_F64(FUNC);                                                    \
  }

#define DOONE_MASK_REDUCE_F64(OP, mask, FUNC)                                  \
  {                                                                            \
    double result;                                                             \
    double mresult;                                                            \
    memset(&result, 0, sizeof(result));                                        \
    memset(&mresult, 0, sizeof(mresult));                                      \
    result = mask_f64_reduce_op(OP, mask, v1.f64);                             \
    mresult = FUNC(mask, v1.zmmd);                                             \
    CHECK_MASK_REDUCE_F64(FUNC);                                               \
  }

__mmask16 mvals[] = {0, 0x82a5};

int main(int argc, char *argv[]) {
  int i;
  int err = 0;
  int init1[16] = {7, 1, -3, 3, 1, 1, 2, 3, 1, 3, 2, 3, -5, 1, 11, 3};

  float finit1[16] = {-1.0, -2.0, 3.0,  4.0,   5.0,  6.0,  7.0,  18.0,
                      -9.0, 10.0, 11.0, -12.0, 13.0, 14.0, 15.0, 16.0};

  double dinit1[8] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
  double dinit2[8] = {0.5, 2.0, 3.0, 2.1, 5.0, 5.2, 7.1, 3.1};

  V512 v1;
  __mmask16 mask = 0x82a5;

  verbose = argc;

  /* zmmi/s32 tests ---------------------------------------- */
  /* _mm512_reduce_add_epi32 */
  init_s32(v1.s32, init1);
  DOONE_REDUCE_S32(REDUCE_ADD, _mm512_reduce_add_epi32);

  /* _mm512_reduce_mul_epi32 */
  init_s32(v1.s32, init1);
  DOONE_REDUCE_S32(REDUCE_MUL, _mm512_reduce_mul_epi32);

  /* _mm512_reduce_min_epi32 */
  init_s32(v1.s32, init1);
  DOONE_REDUCE_S32(REDUCE_MIN, _mm512_reduce_min_epi32);

  /* _mm512_reduce_max_epi32 */
  init_s32(v1.s32, init1);
  DOONE_REDUCE_S32(REDUCE_MAX, _mm512_reduce_max_epi32);

  /* _mm512_reduce_and_epi32 */
  init_s32(v1.s32, init1);
  DOONE_REDUCE_S32(REDUCE_AND, _mm512_reduce_and_epi32);

  /* _mm512_reduce_or_epi32 */
  init_s32(v1.s32, init1);
  DOONE_REDUCE_S32(REDUCE_OR, _mm512_reduce_or_epi32);

  /* _mm512_reduce_min_epu32 */
  init_s32(v1.s32, init1);
  DOONE_REDUCE_U32(REDUCE_MIN, _mm512_reduce_min_epu32);

  /* _mm512_reduce_max_epu32 */
  init_s32(v1.s32, init1);
  DOONE_REDUCE_U32(REDUCE_MAX, _mm512_reduce_max_epu32);

  for (i = 0; i < 2; i += 1) {
    mask = mvals[i];
    /* _mm512_mask_reduce_min_epu32 */
    init_s32(v1.s32, init1);
    DOONE_MASK_REDUCE_U32(REDUCE_MIN, mask, _mm512_mask_reduce_min_epu32);

    /* _mm512_mask_reduce_max_epu32 */
    init_s32(v1.s32, init1);
    DOONE_MASK_REDUCE_U32(REDUCE_MAX, mask, _mm512_mask_reduce_max_epu32);
  }

  for (i = 0; i < 2; i += 1) {
    mask = mvals[i];
    /* _mm512_mask_reduce_add_epi32 */
    init_s32(v1.s32, init1);
    DOONE_MASK_REDUCE_S32(REDUCE_ADD, mask, _mm512_mask_reduce_add_epi32);

    /* _mm512_mask_reduce_mul_epi32 */
    init_s32(v1.s32, init1);
    DOONE_MASK_REDUCE_S32(REDUCE_MUL, mask, _mm512_mask_reduce_mul_epi32);

    /* _mm512_mask_reduce_min_epi32 */
    init_s32(v1.s32, init1);
    DOONE_MASK_REDUCE_S32(REDUCE_MIN, mask, _mm512_mask_reduce_min_epi32);

    /* _mm512_mask_reduce_max_epi32 */
    init_s32(v1.s32, init1);
    DOONE_MASK_REDUCE_S32(REDUCE_MAX, mask, _mm512_mask_reduce_max_epi32);

    /* _mm512_mask_reduce_and_epi32 */
    init_s32(v1.s32, init1);
    DOONE_MASK_REDUCE_S32(REDUCE_AND, mask, _mm512_mask_reduce_and_epi32);

    /* _mm512_mask_reduce_or_epi32 */
    init_s32(v1.s32, init1);
    DOONE_MASK_REDUCE_S32(REDUCE_OR, mask, _mm512_mask_reduce_or_epi32);
  }

  /* zmm/f32 tests ---------------------------------------- */
  /* _mm512_reduce_add_ps */
  init_f32(v1.f32, finit1);
  DOONE_REDUCE_F32(REDUCE_ADD, _mm512_reduce_add_ps);

  /* _mm512_reduce_mul_ps */
  init_f32(v1.f32, finit1);
  DOONE_REDUCE_F32(REDUCE_MUL, _mm512_reduce_mul_ps);

  /* _mm512_reduce_gmin_ps */
  init_f32(v1.f32, finit1);
  DOONE_REDUCE_F32(REDUCE_GMIN, _mm512_reduce_min_ps);

  /* _mm512_reduce_gmax_ps */
  init_f32(v1.f32, finit1);
  DOONE_REDUCE_F32(REDUCE_GMAX, _mm512_reduce_max_ps);

  for (i = 0; i < 2; i += 1) {
    mask = mvals[i];
    /* _mm512_reduce_gmax_ps */
    init_f32(v1.f32, finit1);
    DOONE_MASK_REDUCE_F32(REDUCE_GMIN, mask, _mm512_mask_reduce_min_ps);

    /* _mm512_reduce_gmax_ps */
    init_f32(v1.f32, finit1);
    DOONE_MASK_REDUCE_F32(REDUCE_GMAX, mask, _mm512_mask_reduce_max_ps);

    /* _mm512_reduce_mul_ps */
    init_f32(v1.f32, finit1);
    DOONE_MASK_REDUCE_F32(REDUCE_MUL, mask, _mm512_mask_reduce_mul_ps);

    /* _mm512_reduce_add_ps */
    init_f32(v1.f32, finit1);
    DOONE_MASK_REDUCE_F32(REDUCE_ADD, mask, _mm512_mask_reduce_add_ps);
  }

  /* zmmd/f64 tests ---------------------------------------- */
  /* _mm512_reduce_add_pd */
  init_f64(v1.f64, dinit1);
  DOONE_REDUCE_F64(REDUCE_ADD, _mm512_reduce_add_pd);

  /* _mm512_reduce_mul_pd */
  init_f64(v1.f64, dinit1);
  DOONE_REDUCE_F64(REDUCE_MUL, _mm512_reduce_mul_pd);

  /* _mm512_reduce_gmin_pd */
  init_f64(v1.f64, dinit1);
  DOONE_REDUCE_F64(REDUCE_GMIN, _mm512_reduce_min_pd);

  /* _mm512_reduce_gmax_pd */
  init_f64(v1.f64, dinit1);
  DOONE_REDUCE_F64(REDUCE_GMAX, _mm512_reduce_max_pd);

  for (i = 0; i < 2; i += 1) {
    mask = mvals[i];
    /* _mm512_mask_reduce_gmin_ps */
    init_f64(v1.f64, dinit1);
    DOONE_MASK_REDUCE_F64(REDUCE_GMIN, mask, _mm512_mask_reduce_min_pd);

    /* _mm512_mask_reduce_gmax_ps */
    init_f64(v1.f64, dinit2);
    DOONE_MASK_REDUCE_F64(REDUCE_GMAX, mask, _mm512_mask_reduce_max_pd);

    /* _mm512_mask_reduce_mul_ps */
    init_f64(v1.f64, dinit1);
    DOONE_MASK_REDUCE_F64(REDUCE_MUL, mask, _mm512_mask_reduce_mul_pd);

    /* _mm512_mask_reduce_add_ps */
    init_f64(v1.f64, dinit2);
    DOONE_MASK_REDUCE_F64(REDUCE_ADD, mask, _mm512_mask_reduce_add_pd);
  }

  if (err) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
