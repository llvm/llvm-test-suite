
/*
 * Test 128 and 256-bit two operand integer intrinsics,
 * with masked and zero-masked forms, by comparing
 * their output with the corresponding 512-bit intrinsic.
 * Here we check for _mm512_[mask|maskz]_[and|andnot|or|xor|add|max|min|mul|sub]
 * intrinsics
 */

#include "m512_test_util.h"
#include <stdio.h>

V512 i8_src1;
V512 i8_src2;
V512 i16_src1;
V512 i16_src2;
V512 i32_src1;
V512 i32_src2;
V512 i64_src1;
V512 i64_src2;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 64; i++) {
    i8_src1.s8[i] = i;
    i8_src2.s8[i] = (i & 1) ? i : -i;
  }

  for (i = 0; i < 32; i++) {
    i16_src1.s16[i] = i;
    i16_src2.s16[i] = (i & 1) ? i : -i;
  }

  for (i = 0; i < 16; i++) {
    i32_src1.s32[i] = i;
    i32_src2.s32[i] = (i & 1) ? i : -i;
  }

  for (i = 0; i < 8; i++) {
    i64_src1.s64[i] = i;
    i64_src2.s64[i] = (i & 1) ? i : -i;
  }
}

/*
 * Use "soft update" between tests to make compiler think src was updated.
 * Prevents PRE'ing a load of src, thus allowing ciscization.
 * Also prevents PRE'ing intrinsic operations, ensuring we
 * execute the intended instructions.
 */
volatile int vol0 = 0;
#define soft_v512_update(var) (var).xmmi[vol0] = (var).xmmi[vol0]

/*
 * Generate a function that tests a packed int64 intrinsic
 * by implementing the XMM, YMM and ZMM versions, and comparing
 * the XMM and YMM results with the low part of the ZMM result.
 *
 * We test regular, masked and zero masked forms.
 *
 * Use GEN_I64_UNIFORM when the core intrinsic name is the same
 * for all vector lengths, e.g. "add_epi64".  Otherwise use
 * GEN_I64 to list the different names, e.g. "and_si128" and "and_si256".
 */

#define GEN_I64_UNIFORM(oper) GEN_I64(oper, oper, oper, oper, oper)

#define GEN_I64(test_name, oper_epi64, oper_xmm, oper_ymm, oper_zmm)           \
  void NOINLINE do_##test_name() {                                             \
    V512 xmm_res, ymm_res, zmm_res;                                            \
    __mmask8 k8 = 0x5a;                                                        \
                                                                               \
    /* Non-masked. */                                                          \
                                                                               \
    soft_v512_update(i64_src2);                                                \
    zmm_res.zmmi = _mm512_##oper_zmm(i64_src1.zmmi, i64_src2.zmmi);            \
                                                                               \
    /* Masked. */                                                              \
                                                                               \
    zmm_res.zmmi = _mm512_setzero_epi32();                                     \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i64_src2);                                                \
    zmm_res.zmmi = _mm512_mask_##oper_epi64(zmm_res.zmmi, k8, i64_src1.zmmi,   \
                                            i64_src2.zmmi);                    \
                                                                               \
    /* Zero-masked. */                                                         \
                                                                               \
    zmm_res.zmmi = _mm512_set1_epi64(1);                                       \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i64_src2);                                                \
    zmm_res.zmmi =                                                             \
        _mm512_maskz_##oper_epi64(k8, i64_src1.zmmi, i64_src2.zmmi);           \
  }

#define GEN_I32_UNIFORM(oper) GEN_I32(oper, oper, oper, oper, oper)

#define GEN_I32(test_name, oper_epi32, oper_xmm, oper_ymm, oper_zmm)           \
  void NOINLINE do_##test_name() {                                             \
    V512 xmm_res, ymm_res, zmm_res;                                            \
    __mmask16 k16 = 0x7feb;                                                    \
    __mmask8 k8 = (__mmask8)k16;                                               \
                                                                               \
    /* Non-masked. */                                                          \
                                                                               \
    soft_v512_update(i32_src2);                                                \
    zmm_res.zmmi = _mm512_##oper_zmm(i32_src1.zmmi, i32_src2.zmmi);            \
                                                                               \
    /* Masked. */                                                              \
                                                                               \
    zmm_res.zmmi = _mm512_setzero_epi32();                                     \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i32_src2);                                                \
    zmm_res.zmmi = _mm512_mask_##oper_epi32(zmm_res.zmmi, k16, i32_src1.zmmi,  \
                                            i32_src2.zmmi);                    \
                                                                               \
    /* Zero-masked. */                                                         \
                                                                               \
    zmm_res.zmmi = _mm512_set1_epi32(1.0);                                     \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i32_src2);                                                \
    zmm_res.zmmi =                                                             \
        _mm512_maskz_##oper_epi32(k16, i32_src1.zmmi, i32_src2.zmmi);          \
  }

#define GEN_I16_UNIFORM(oper) GEN_I16(oper, oper, oper, oper, oper)

#define GEN_I16(test_name, oper_epi16, oper_xmm, oper_ymm, oper_zmm)           \
  void NOINLINE do_##test_name() {                                             \
    V512 xmm_res, ymm_res, zmm_res;                                            \
    __mmask32 k32 = 0x7febeb7f;                                                \
    __mmask16 k16 = (__mmask16)k32;                                            \
    __mmask8 k8 = (__mmask8)k16;                                               \
                                                                               \
    /* Non-masked. */                                                          \
                                                                               \
    soft_v512_update(i16_src2);                                                \
    zmm_res.zmmi = _mm512_##oper_zmm(i16_src1.zmmi, i16_src2.zmmi);            \
                                                                               \
    /* Masked. */                                                              \
                                                                               \
    zmm_res.zmmi = _mm512_setzero_epi32();                                     \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i16_src2);                                                \
    zmm_res.zmmi = _mm512_mask_##oper_epi16(zmm_res.zmmi, k32, i16_src1.zmmi,  \
                                            i16_src2.zmmi);                    \
                                                                               \
    /* Zero-masked. */                                                         \
                                                                               \
    zmm_res.zmmi = _mm512_set1_epi32(1.0);                                     \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i16_src2);                                                \
    zmm_res.zmmi =                                                             \
        _mm512_maskz_##oper_epi16(k32, i16_src1.zmmi, i16_src2.zmmi);          \
  }

#define GEN_I8_UNIFORM(oper) GEN_I8(oper, oper, oper, oper, oper)

#define GEN_I8(test_name, oper_epi8, oper_xmm, oper_ymm, oper_zmm)             \
  void NOINLINE do_##test_name() {                                             \
    V512 xmm_res, ymm_res, zmm_res;                                            \
    __mmask64 k64 = 0xa55a7febeb7f5aa5U;                                       \
    __mmask32 k32 = (__mmask32)k64;                                            \
    __mmask16 k16 = (__mmask16)k32;                                            \
                                                                               \
    /* Non-masked. */                                                          \
                                                                               \
    soft_v512_update(i8_src2);                                                 \
    zmm_res.zmmi = _mm512_##oper_zmm(i8_src1.zmmi, i8_src2.zmmi);              \
                                                                               \
    /* Masked. */                                                              \
                                                                               \
    zmm_res.zmmi = _mm512_setzero_epi32();                                     \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i8_src2);                                                 \
    zmm_res.zmmi = _mm512_mask_##oper_epi8(zmm_res.zmmi, k64, i8_src1.zmmi,    \
                                           i8_src2.zmmi);                      \
                                                                               \
    /* Zero-masked. */                                                         \
                                                                               \
    zmm_res.zmmi = _mm512_set1_epi32(1.0);                                     \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i8_src2);                                                 \
    zmm_res.zmmi = _mm512_maskz_##oper_epi8(k64, i8_src1.zmmi, i8_src2.zmmi);  \
  }

GEN_I32(and_si512, and_epi32, and_si128, and_si256, and_si512)
GEN_I32(andnot_si512, andnot_epi32, andnot_si128, andnot_si256, andnot_si512)
GEN_I32(or_si512, or_epi32, or_si128, or_si256, or_si512)
GEN_I32(xor_si512, xor_epi32, xor_si128, xor_si256, xor_si512)

GEN_I64(and_epi64, and_epi64, and_si128, and_si256, and_epi64)
GEN_I64(andnot_epi64, andnot_epi64, andnot_si128, andnot_si256, andnot_epi64)
GEN_I64(or_epi64, or_epi64, or_si128, or_si256, or_epi64)
GEN_I64(xor_epi64, xor_epi64, xor_si128, xor_si256, xor_epi64)

GEN_I64_UNIFORM(add_epi64)
GEN_I64_UNIFORM(max_epi64)
GEN_I64_UNIFORM(max_epu64)
GEN_I64_UNIFORM(min_epi64)
GEN_I64_UNIFORM(min_epu64)
GEN_I64_UNIFORM(mul_epi32) /* Yes, these are really I64 vector elements. */
GEN_I64_UNIFORM(mul_epu32) /* Yes, these are really I64 vector elements. */

GEN_I32(and_epi32, and_epi32, and_si128, and_si256, and_epi32)
GEN_I32(andnot_epi32, andnot_epi32, andnot_si128, andnot_si256, andnot_epi32)
GEN_I32(or_epi32, or_epi32, or_si128, or_si256, or_epi32)
GEN_I32(xor_epi32, xor_epi32, xor_si128, xor_si256, xor_epi32)

GEN_I32_UNIFORM(add_epi32)
GEN_I32_UNIFORM(max_epi32)
GEN_I32_UNIFORM(max_epu32)
GEN_I32_UNIFORM(min_epi32)
GEN_I32_UNIFORM(min_epu32)
GEN_I32_UNIFORM(sub_epi32)

int main() {
  init();

  do_and_si512();
  do_andnot_si512();
  do_or_si512();
  do_xor_si512();

  do_and_epi64();
  do_andnot_epi64();
  do_or_epi64();
  do_xor_epi64();

  do_add_epi64();
  do_max_epi64();
  do_max_epu64();
  do_min_epi64();
  do_min_epu64();
  do_mul_epi32();
  do_mul_epu32();

  do_and_epi32();
  do_andnot_epi32();
  do_or_epi32();
  do_xor_epi32();

  do_add_epi32();
  do_max_epi32();
  do_max_epu32();
  do_min_epi32();
  do_min_epu32();
  do_sub_epi32();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
