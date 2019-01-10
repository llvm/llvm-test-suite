
/*
 * Test load, copy and store intrinsics related to integer move instructions.
 */

#include "m512_test_util.h"

V512 i8_src1;
V512 i8_src2;
V512 i16_src1;
V512 i16_src2;

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
}

/*
 * Use "soft update" between tests to make compiler think src was updated.
 * Prevents PRE'ing a load of src, thus allowing ciscization.
 * Also prevents PRE'ing intrinsic operations, ensuring we
 * execute the intended instructions.
 */
volatile int vol0 = 0;
#define soft_v512_update(var) (var).xmmi[vol0] = (var).xmmi[vol0]

#define BLANK

#define GEN_MASK_I8_LOAD(oper) GEN_MASK_I8(oper, &)
#define GEN_MASK_I8_COPY(oper) GEN_MASK_I8(oper, BLANK)

#define GEN_MASK_I8(oper, addr_of)                                             \
  void NOINLINE do_##oper() {                                                  \
    V512 xmm_res, ymm_res, zmm_res;                                            \
    __mmask64 k64 = 0xabcdeffe97febdca;                                        \
    __mmask32 k32 = (__mmask32)k64;                                            \
    __mmask16 k16 = (__mmask16)k64;                                            \
                                                                               \
    /* Masked. */                                                              \
                                                                               \
    zmm_res.zmmi = _mm512_setzero_epi32();                                     \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i8_src2);                                                 \
    zmm_res.zmmi =                                                             \
        _mm512_mask_##oper(i8_src1.zmmi, k64, addr_of i8_src2.zmmi);           \
    soft_v512_update(i8_src2);                                                 \
    ymm_res.ymmi[0] =                                                          \
        _mm256_mask_##oper(i8_src1.ymmi[0], k32, addr_of i8_src2.ymmi[0]);     \
    soft_v512_update(i8_src2);                                                 \
    xmm_res.xmmi[0] =                                                          \
        _mm_mask_##oper(i8_src1.xmmi[0], k16, addr_of i8_src2.xmmi[0]);        \
                                                                               \
    check_equal_nd(&ymm_res, &zmm_res, 8, "_mm256_mask_" #oper, __LINE__);     \
    check_equal_nd(&xmm_res, &zmm_res, 4, "_mm_mask_" #oper, __LINE__);        \
                                                                               \
    /* Zero-masked. */                                                         \
                                                                               \
    zmm_res.zmmi = _mm512_set1_epi32(1.0);                                     \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i8_src1);                                                 \
    zmm_res.zmmi = _mm512_maskz_##oper(k64, addr_of i8_src1.zmmi);             \
    soft_v512_update(i8_src1);                                                 \
    ymm_res.ymmi[0] = _mm256_maskz_##oper(k32, addr_of i8_src1.ymmi[0]);       \
    soft_v512_update(i8_src1);                                                 \
    xmm_res.xmmi[0] = _mm_maskz_##oper(k16, addr_of i8_src1.xmmi[0]);          \
                                                                               \
    check_equal_nd(&ymm_res, &zmm_res, 8, "_mm256_maskz_" #oper, __LINE__);    \
    check_equal_nd(&xmm_res, &zmm_res, 4, "_mm_maskz_" #oper, __LINE__);       \
  }

#define GEN_MASK_I8_STORE(oper)                                                \
  void NOINLINE do_##oper() {                                                  \
    V512 xmm_res, ymm_res, zmm_res;                                            \
    __mmask64 k64 = 0xabcdeffe97febdca;                                        \
    __mmask32 k32 = (__mmask32)k64;                                            \
    __mmask16 k16 = (__mmask16)k64;                                            \
                                                                               \
    /* Masked. */                                                              \
                                                                               \
    zmm_res = i16_src1;                                                        \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i8_src2);                                                 \
    _mm512_mask_##oper(&zmm_res.zmmi, k64, i8_src2.zmmi);                      \
    soft_v512_update(i8_src2);                                                 \
    soft_v512_update(ymm_res);                                                 \
    _mm256_mask_##oper(&ymm_res.ymmi[0], k32, i8_src2.ymmi[0]);                \
    soft_v512_update(i8_src2);                                                 \
    soft_v512_update(xmm_res);                                                 \
    _mm_mask_##oper(&xmm_res.xmmi[0], k16, i8_src2.xmmi[0]);                   \
                                                                               \
    check_equal_nd(&ymm_res, &zmm_res, 8, "_mm256_mask_" #oper, __LINE__);     \
    check_equal_nd(&xmm_res, &zmm_res, 4, "_mm_mask_" #oper, __LINE__);        \
  }

#define GEN_MASK_I16_LOAD(oper) GEN_MASK_I16(oper, &)
#define GEN_MASK_I16_COPY(oper) GEN_MASK_I16(oper, BLANK)

#define GEN_MASK_I16(oper, addr_of)                                            \
  void NOINLINE do_##oper() {                                                  \
    V512 xmm_res, ymm_res, zmm_res;                                            \
    __mmask32 k32 = 0xcfe97dba;                                                \
    __mmask16 k16 = (__mmask16)k32;                                            \
    __mmask8 k8 = (__mmask8)k32;                                               \
                                                                               \
    /* Masked. */                                                              \
                                                                               \
    zmm_res.zmmi = _mm512_setzero_epi32();                                     \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i16_src2);                                                \
    zmm_res.zmmi =                                                             \
        _mm512_mask_##oper(i16_src1.zmmi, k32, addr_of i16_src2.zmmi);         \
    soft_v512_update(i16_src2);                                                \
    ymm_res.ymmi[0] =                                                          \
        _mm256_mask_##oper(i16_src1.ymmi[0], k16, addr_of i16_src2.ymmi[0]);   \
    soft_v512_update(i16_src2);                                                \
    xmm_res.xmmi[0] =                                                          \
        _mm_mask_##oper(i16_src1.xmmi[0], k8, addr_of i16_src2.xmmi[0]);       \
                                                                               \
    check_equal_nd(&ymm_res, &zmm_res, 8, "_mm256_mask_" #oper, __LINE__);     \
    check_equal_nd(&xmm_res, &zmm_res, 4, "_mm_mask_" #oper, __LINE__);        \
                                                                               \
    /* Zero-masked. */                                                         \
                                                                               \
    zmm_res.zmmi = _mm512_set1_epi32(1.0);                                     \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i16_src1);                                                \
    zmm_res.zmmi = _mm512_maskz_##oper(k32, addr_of i16_src1.zmmi);            \
    soft_v512_update(i16_src1);                                                \
    ymm_res.ymmi[0] = _mm256_maskz_##oper(k16, addr_of i16_src1.ymmi[0]);      \
    soft_v512_update(i16_src1);                                                \
    xmm_res.xmmi[0] = _mm_maskz_##oper(k8, addr_of i16_src1.xmmi[0]);          \
                                                                               \
    check_equal_nd(&ymm_res, &zmm_res, 8, "_mm256_maskz_" #oper, __LINE__);    \
    check_equal_nd(&xmm_res, &zmm_res, 4, "_mm_maskz_" #oper, __LINE__);       \
  }

#define GEN_MASK_I16_STORE(oper)                                               \
  void NOINLINE do_##oper() {                                                  \
    V512 xmm_res, ymm_res, zmm_res;                                            \
    __mmask32 k32 = 0xcfe97dba;                                                \
    __mmask16 k16 = (__mmask16)k32;                                            \
    __mmask8 k8 = (__mmask8)k32;                                               \
                                                                               \
    /* Masked. */                                                              \
                                                                               \
    zmm_res.zmmi = _mm512_setzero_epi32();                                     \
    ymm_res = zmm_res;                                                         \
    xmm_res = zmm_res;                                                         \
                                                                               \
    soft_v512_update(i16_src2);                                                \
    _mm512_mask_##oper(&zmm_res.zmmi, k32, i16_src2.zmmi);                     \
    soft_v512_update(i16_src2);                                                \
    soft_v512_update(ymm_res);                                                 \
    _mm256_mask_##oper(&ymm_res.ymmi[0], k16, i16_src2.ymmi[0]);               \
    soft_v512_update(i16_src2);                                                \
    soft_v512_update(xmm_res);                                                 \
    _mm_mask_##oper(&xmm_res.xmmi[0], k8, i16_src2.xmmi[0]);                   \
                                                                               \
    check_equal_nd(&ymm_res, &zmm_res, 8, "_mm256_mask_" #oper, __LINE__);     \
    check_equal_nd(&xmm_res, &zmm_res, 4, "_mm_mask_" #oper, __LINE__);        \
  }

GEN_MASK_I8_LOAD(loadu_epi8)
GEN_MASK_I8_COPY(mov_epi8)
GEN_MASK_I8_STORE(storeu_epi8)

GEN_MASK_I16_LOAD(loadu_epi16)
GEN_MASK_I16_COPY(mov_epi16)
GEN_MASK_I16_STORE(storeu_epi16)

int main() {
  init();

  do_loadu_epi8();
  do_mov_epi8();
  do_storeu_epi8();

  do_loadu_epi16();
  do_mov_epi16();
  do_storeu_epi16();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
