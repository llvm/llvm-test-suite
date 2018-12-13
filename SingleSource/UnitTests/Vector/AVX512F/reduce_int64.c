#include "m512_test_util.h"
#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
/*
 * Here we check for _mm512_[mask_]reduce_[add|mul|min|max] intrinsics.
 */
typedef __int64 s64;
typedef unsigned __int64 u64;

typedef float f32;
typedef double f64;

typedef int s32;
typedef unsigned int u32;

int verbose = 0;
#define VERBOSE (verbose > 1)
#define SHOW_OP (verbose > 2)
#define SCALE_TRACE (verbose > 3)

typedef enum {
  REDUCE_ADD,
  REDUCE_MUL,
  REDUCE_MIN,
  REDUCE_MAX,
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

static __int64 NOINLINE mask_s64_reduce_op(OPER op, __mmask16 mask,
                                           __int64 s64op1[8]) {
  int handled = 0;
  __int64 res;

  switch (op) {

  case REDUCE_ADD:
    handled = 1;
    DO_REDUCE_8(res, mask, s64op1, s64, ADDOP, 0);
    break;

  case REDUCE_MUL:
    handled = 1;
    DO_REDUCE_8(res, mask, s64op1, s64, MULOP, 1);
    break;

  case REDUCE_MIN:
    handled = 1;
    DO_REDUCE_8(res, mask, s64op1, s64, IMin, 0x7fffffffffffffff);
    break;

  case REDUCE_MAX:
    handled = 1;
    DO_REDUCE_8(res, mask, s64op1, s64, IMax, 0x8000000000000000);
    break;

  case REDUCE_OR:
    handled = 1;
    DO_REDUCE_8(res, mask, s64op1, s64, OROP, 0);
    break;

  case REDUCE_AND:
    handled = 1;
    DO_REDUCE_8(res, mask, s64op1, s64, ANDOP, 0xffffffffffffffff);
    break;

  default:
    printf("FAIL: mask_s64_reduce_op: bad op\n");
    exit(1);
    break;
  }
  if (!handled) {
    printf("FAIL: mask_s64_reduce_op: unsupported op\n");
  }
  return (res);
}

static __int64 NOINLINE mask_u64_reduce_op(OPER op, __mmask16 mask,
                                           unsigned __int64 u64op1[8]) {
  int handled = 0;
  __int64 res;

  switch (op) {

  case REDUCE_MIN:
    handled = 1;
    DO_REDUCE_8(res, mask, u64op1, u64, IMin, 0xffffffffffffffff);
    break;

  case REDUCE_MAX:
    handled = 1;
    DO_REDUCE_8(res, mask, u64op1, u64, IMax, 0x0000000000000000);
    break;

  default:
    printf("FAIL: mask_u64_reduce_op: bad op\n");
    exit(1);
    break;
  }
  if (!handled) {
    printf("FAIL: mask_u64_reduce_op: unsupported op\n");
  }
  return (res);
}

static void NOINLINE init_s64(__int64 s64out[8], __int64 s64op1[8]) {
  int i = 0;
  for (i = 0; i < 8; i += 1) {
    s64out[i] = s64op1[i];
  }
}

static void NOINLINE print_s64(char *pfx, __int64 var) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  printf("%15lld", var);
  printf("\n");
}

static void NOINLINE print_u64(char *pfx, u64 var) {
  if (pfx) {
    printf("%s: ", pfx);
  }
  printf("%15llu", var);
  printf("\n");
}

static void NOINLINE print_ivec(char *pfx, __int64 ivec[]) {
  char *fmt = "%5ld %5ld %5ld %5ld ";
  if (pfx) {
    printf("%s: ", pfx);
  }
  printf(fmt, ivec[7], ivec[6], ivec[5], ivec[4]);
  printf(fmt, ivec[3], ivec[2], ivec[1], ivec[0]);
  printf("\n");
}

static void NOINLINE print_uvec(char *pfx, unsigned __int64 ivec[]) {
  char *fmt = "%5lu %5lu %5lu %5lu ";
  if (pfx) {
    printf("%s: ", pfx);
  }
  printf(fmt, ivec[7], ivec[6], ivec[5], ivec[4]);
  printf(fmt, ivec[3], ivec[2], ivec[1], ivec[0]);
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

#define CHECK_REDUCE_S64(FUNC)                                                 \
  {                                                                            \
    int passed = (result == mresult);                                          \
    CHECK_PRINT(passed, FUNC);                                                 \
    if (!passed || SHOW_OP) {                                                  \
      print_ivec("Opand1", v1.s64);                                            \
      print_s64("Scalar", result);                                             \
      print_s64("Vector", mresult);                                            \
    }                                                                          \
  }

#define CHECK_REDUCE_U64(FUNC)                                                 \
  {                                                                            \
    int passed = (result == mresult);                                          \
    CHECK_PRINT(passed, FUNC);                                                 \
    if (!passed || SHOW_OP) {                                                  \
      print_uvec("Opand1", v1.u64);                                            \
      print_u64("Scalar", result);                                             \
      print_u64("Vector", mresult);                                            \
    }                                                                          \
  }

#define CHECK_MASK_REDUCE_S64(FUNC)                                            \
  {                                                                            \
    int passed = (result == mresult);                                          \
    CHECK_PRINT(passed, FUNC);                                                 \
    if (!passed || SHOW_OP) {                                                  \
      print_ivec("Opand1", v1.s64);                                            \
      PRINT_MASK(8, 5, "  Mask", mask);                                        \
      print_s64("Scalar", result);                                             \
      print_s64("Vector", mresult);                                            \
    }                                                                          \
  }

#define CHECK_MASK_REDUCE_U64(FUNC)                                            \
  {                                                                            \
    int passed = (result == mresult);                                          \
    CHECK_PRINT(passed, FUNC);                                                 \
    if (!passed || SHOW_OP) {                                                  \
      print_uvec("Opand1", v1.u64);                                            \
      PRINT_MASK(8, 5, "  Mask", mask);                                        \
      print_u64("Scalar", result);                                             \
      print_u64("Vector", mresult);                                            \
    }                                                                          \
  }

#define DOONE_REDUCE_S64(OP, FUNC)                                             \
  {                                                                            \
    __int64 result;                                                            \
    __int64 mresult;                                                           \
    result = mask_s64_reduce_op(OP, mask_true, v1.s64);                        \
    mresult = FUNC(v1.zmmi);                                                   \
    CHECK_REDUCE_S64(FUNC);                                                    \
  }

#define DOONE_MASK_REDUCE_S64(OP, mask, FUNC)                                  \
  {                                                                            \
    __int64 result;                                                            \
    __int64 mresult;                                                           \
    result = mask_s64_reduce_op(OP, mask, v1.s64);                             \
    mresult = FUNC(mask, v1.zmmi);                                             \
    CHECK_MASK_REDUCE_S64(FUNC);                                               \
  }

#define DOONE_REDUCE_U64(OP, FUNC)                                             \
  {                                                                            \
    unsigned __int64 result;                                                   \
    unsigned __int64 mresult;                                                  \
    result = mask_u64_reduce_op(OP, mask_true, v1.u64);                        \
    mresult = FUNC(v1.zmmi);                                                   \
    CHECK_REDUCE_U64(FUNC);                                                    \
  }

#define DOONE_MASK_REDUCE_U64(OP, mask, FUNC)                                  \
  {                                                                            \
    unsigned __int64 result;                                                   \
    unsigned __int64 mresult;                                                  \
    result = mask_u64_reduce_op(OP, mask, v1.u64);                             \
    mresult = FUNC(mask, v1.zmmi);                                             \
    CHECK_MASK_REDUCE_U64(FUNC);                                               \
  }

__mmask16 mvals[] = {0, 0x82a5};
__int64 init1[8] = {7, 1, 11, 3, 1, 1, 2, 3};

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 8; i++) {
    init1[i] = init1[i]; /* No change, but compiler does not know this. */
  }
}

int main(int argc, char *argv[]) {
  int i;
  int err = 0;

  V512 v1;
  __mmask16 mask = 0;

  verbose = argc;

  init();

  /* zmmi/s64 tests ---------------------------------------- */
  /* _mm512_reduce_add_epi64 */
  init_s64(v1.s64, init1);
  DOONE_REDUCE_S64(REDUCE_ADD, _mm512_reduce_add_epi64);

  /* _mm512_reduce_mul_epi64 */
  init_s64(v1.s64, init1);
  DOONE_REDUCE_S64(REDUCE_MUL, _mm512_reduce_mul_epi64);

  /* _mm512_reduce_min_epi64 */
  init_s64(v1.s64, init1);
  DOONE_REDUCE_S64(REDUCE_MIN, _mm512_reduce_min_epi64);

  /* _mm512_reduce_max_epi64 */
  init_s64(v1.s64, init1);
  DOONE_REDUCE_S64(REDUCE_MAX, _mm512_reduce_max_epi64);

  /* _mm512_reduce_and_epi64 */
  init_s64(v1.s64, init1);
  DOONE_REDUCE_S64(REDUCE_AND, _mm512_reduce_and_epi64);

  /* _mm512_reduce_or_epi64 */
  init_s64(v1.s64, init1);
  DOONE_REDUCE_S64(REDUCE_OR, _mm512_reduce_or_epi64);

  /* _mm512_reduce_min_epu64 */
  init_s64(v1.s64, init1);
  DOONE_REDUCE_U64(REDUCE_MIN, _mm512_reduce_min_epu64);

  /* _mm512_reduce_max_epu64 */
  init_s64(v1.s64, init1);
  DOONE_REDUCE_U64(REDUCE_MAX, _mm512_reduce_max_epu64);

  for (i = 0; i < 2; i += 1) {
    mask = mvals[i];
    /* _mm512_mask_reduce_min_epu64 */
    init_s64(v1.s64, init1);
    DOONE_MASK_REDUCE_U64(REDUCE_MIN, mask, _mm512_mask_reduce_min_epu64);

    /* _mm512_mask_reduce_max_epu64 */
    init_s64(v1.s64, init1);
    DOONE_MASK_REDUCE_U64(REDUCE_MAX, mask, _mm512_mask_reduce_max_epu64);
  }

  for (i = 0; i < 2; i += 1) {
    mask = mvals[i];
    /* _mm512_mask_reduce_add_epi64 */
    init_s64(v1.s64, init1);
    DOONE_MASK_REDUCE_S64(REDUCE_ADD, mask, _mm512_mask_reduce_add_epi64);

    /* _mm512_mask_reduce_mul_epi64 */
    init_s64(v1.s64, init1);
    DOONE_MASK_REDUCE_S64(REDUCE_MUL, mask, _mm512_mask_reduce_mul_epi64);

    /* _mm512_mask_reduce_min_epi64 */
    init_s64(v1.s64, init1);
    DOONE_MASK_REDUCE_S64(REDUCE_MIN, mask, _mm512_mask_reduce_min_epi64);

    /* _mm512_mask_reduce_max_epi64 */
    init_s64(v1.s64, init1);
    DOONE_MASK_REDUCE_S64(REDUCE_MAX, mask, _mm512_mask_reduce_max_epi64);

    /* _mm512_mask_reduce_and_epi64 */
    init_s64(v1.s64, init1);
    DOONE_MASK_REDUCE_S64(REDUCE_AND, mask, _mm512_mask_reduce_and_epi64);

    /* _mm512_mask_reduce_or_epi64 */
    init_s64(v1.s64, init1);
    DOONE_MASK_REDUCE_S64(REDUCE_OR, mask, _mm512_mask_reduce_or_epi64);
  }

  if (err) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
