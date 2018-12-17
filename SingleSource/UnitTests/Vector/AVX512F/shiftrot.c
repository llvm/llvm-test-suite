/*
 * Test shifts and rotates.
 * This test was created to check the correctness
 * of the following intrinsics support:
 *      _mm512_[maskz_]sllv_epi*()
 *      _mm512_[maskz_]srav_epi*()
 *      _mm512_[maskz_]srlv_epi*()
 *      _mm512_[maskz_]slli_epi*()
 *      _mm512_[maskz_]srai_epi*()
 *      _mm512_[maskz_]srli_epi*()
 *      _mm512_[maskz_]rol_epi*()
 *      _mm512_[maskz_]ror_epi*()
 *      _mm512_[maskz_]rolv_epi*()
 *      _mm512_[maskz_]rorv_epi*()
 */

#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

V512 counts16, counts32, counts64, src, passthru, counts32_imm, counts64_imm;
__mmask8 k8 = 0xf9;
__mmask16 k16 = 0x9ffe;

volatile int vol0;

/*
 * Use this between tests to make compiler think src was updated.
 * Prevents PRE'ing of a load of src.
 */
#define soft_update(v512) (v512).xmmi[vol0] = (v512).xmmi[vol0]
#define soft_src_update() soft_update(src)
#define soft_counts16_update() soft_update(counts16)
#define soft_counts32_update() soft_update(counts32)
#define soft_counts64_update() soft_update(counts64)

#define IMMCNT 3

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 16; i++) {
    counts32.s32[i] = ((i & 0x3) == 0) ? (-3 * i) : (3 * i);
    counts32_imm.s32[i] = IMMCNT;
    src.s32[i] = -27 * i * i + 300 * i - 82;
    if (i & 0x1) {
      src.s32[i] *= -1;
    }
    passthru.s32[i] = 48 * i * i + 100 * i - 9;
  }

  for (i = 0; i < 8; i++) {
    counts64.s64[i] = ((i & 0x3) == 0) ? (-9 * i) : (9 * i);
    counts64_imm.s64[i] = IMMCNT;
  }

  for (i = 0; i < 32; i++) {
    counts16.s16[i] = ((i & 0x3) == 0) ? (3 - i) : i;
  }
}

typedef enum { OP_ROL, OP_ROR, OP_SLL, OP_SRA, OP_SRL } Operation;

V512 dummy;

#define emulate16_m128(oper, res, src1, src2)                                  \
  emulate16((oper), (res), dummy, (__mmask32)-1, (src1), (src2), 8, 0)

#define emulate16_mask_m128(oper, res, orig, k, src1, src2)                    \
  emulate16((oper), (res), (orig), (k), (src1), (src2), 8, 0)

#define emulate16_maskz_m128(oper, res, k, src1, src2)                         \
  emulate16((oper), (res), dummy, (k), (src1), (src2), 8, 1)

#define emulate16_m256(oper, res, src1, src2)                                  \
  emulate16((oper), (res), dummy, (__mmask32)-1, (src1), (src2), 16, 0)

#define emulate16_mask_m256(oper, res, orig, k, src1, src2)                    \
  emulate16((oper), (res), (orig), (k), (src1), (src2), 16, 0)

#define emulate16_maskz_m256(oper, res, k, src1, src2)                         \
  emulate16((oper), (res), dummy, (k), (src1), (src2), 16, 1)

#define emulate16_m512(oper, res, src1, src2)                                  \
  emulate16((oper), (res), dummy, (__mmask32)-1, (src1), (src2), 32, 0)

#define emulate16_mask_m512(oper, res, orig, k, src1, src2)                    \
  emulate16((oper), (res), (orig), (k), (src1), (src2), 32, 0)

#define emulate16_maskz_m512(oper, res, k, src1, src2)                         \
  emulate16((oper), (res), dummy, (k), (src1), (src2), 32, 1)

void NOINLINE emulate16(Operation oper, V512 *res, V512 orig, __mmask16 k,
                        V512 src1, V512 src2, int length, int zero_mask) {
  int i;
  short op1, op2, r;

  for (i = 0; i < length; i++) {
    if (((1 << i) & k) == 0) {
      r = zero_mask ? 0 : orig.s16[i];
    } else {
      op1 = src1.s16[i];
      op2 = src2.s16[i];

      switch (oper) {
      case OP_ROL:
        op2 &= 0xf;
        r = (op1 << op2);
        if (op2 != 0) {
          r |= ((unsigned short)op1 >> (16 - op2));
        }
        break;
      case OP_ROR:
        op2 &= 0xf;
        r = ((unsigned short)op1 >> op2);
        if (op2 != 0) {
          r |= (op1 << (16 - op2));
        }
        break;
      case OP_SLL:
        r = (op2 & ~0xf) ? 0 : (op1 << op2);
        break;
      case OP_SRA:
        r = (op2 & ~0xf) ? (op1 < 0 ? -1 : 0) : (op1 >> op2);
        break;
      case OP_SRL:
        r = (op2 & ~0xf) ? 0 : ((unsigned short)op1 >> op2);
        break;
      default:
        printf("ERROR -- unexpected 16-bit operation\n");
        n_errs++;
        return;
      }
    }

    res->s16[i] = r;
  }
}

#define emulate32_m128(oper, res, src1, src2)                                  \
  emulate32((oper), (res), dummy, (__mmask16)-1, (src1), (src2), 4, 0)

#define emulate32_mask_m128(oper, res, orig, k, src1, src2)                    \
  emulate32((oper), (res), (orig), (k), (src1), (src2), 4, 0)

#define emulate32_maskz_m128(oper, res, k, src1, src2)                         \
  emulate32((oper), (res), dummy, (k), (src1), (src2), 4, 1)

#define emulate32_m256(oper, res, src1, src2)                                  \
  emulate32((oper), (res), dummy, (__mmask16)-1, (src1), (src2), 8, 0)

#define emulate32_mask_m256(oper, res, orig, k, src1, src2)                    \
  emulate32((oper), (res), (orig), (k), (src1), (src2), 8, 0)

#define emulate32_maskz_m256(oper, res, k, src1, src2)                         \
  emulate32((oper), (res), dummy, (k), (src1), (src2), 8, 1)

#define emulate32_m512(oper, res, src1, src2)                                  \
  emulate32((oper), (res), dummy, (__mmask16)-1, (src1), (src2), 16, 0)

#define emulate32_mask_m512(oper, res, orig, k, src1, src2)                    \
  emulate32((oper), (res), (orig), (k), (src1), (src2), 16, 0)

#define emulate32_maskz_m512(oper, res, k, src1, src2)                         \
  emulate32((oper), (res), dummy, (k), (src1), (src2), 16, 1)

#define emulate32_m256(oper, res, src1, src2)                                  \
  emulate32((oper), (res), dummy, (__mmask16)-1, (src1), (src2), 8, 0)

#define emulate32_mask_m256(oper, res, orig, k, src1, src2)                    \
  emulate32((oper), (res), (orig), (k), (src1), (src2), 8, 0)

#define emulate32_maskz_m256(oper, res, k, src1, src2)                         \
  emulate32((oper), (res), dummy, (k), (src1), (src2), 8, 1)

#define emulate32_m128(oper, res, src1, src2)                                  \
  emulate32((oper), (res), dummy, (__mmask16)-1, (src1), (src2), 4, 0)

#define emulate32_mask_m128(oper, res, orig, k, src1, src2)                    \
  emulate32((oper), (res), (orig), (k), (src1), (src2), 4, 0)

#define emulate32_maskz_m128(oper, res, k, src1, src2)                         \
  emulate32((oper), (res), dummy, (k), (src1), (src2), 4, 1)

void NOINLINE emulate32(Operation oper, V512 *res, V512 orig, __mmask16 k,
                        V512 src1, V512 src2, int length, int zero_mask) {
  int i, op1, op2, r;

  for (i = 0; i < length; i++) {
    if (((1 << i) & k) == 0) {
      r = zero_mask ? 0 : orig.s32[i];
    } else {
      op1 = src1.s32[i];
      op2 = src2.s32[i];

      switch (oper) {
      case OP_ROL:
        op2 &= 0x1f;
        r = (op1 << op2);
        if (op2 != 0) {
          r |= ((unsigned int)op1 >> (32 - op2));
        }
        break;
      case OP_ROR:
        op2 &= 0x1f;
        r = ((unsigned int)op1 >> op2);
        if (op2 != 0) {
          r |= (op1 << (32 - op2));
        }
        break;
      case OP_SLL:
        r = (op2 & ~0x1f) ? 0 : (op1 << op2);
        break;
      case OP_SRA:
        r = (op2 & ~0x1f) ? (op1 < 0 ? -1 : 0) : (op1 >> op2);
        break;
      case OP_SRL:
        r = (op2 & ~0x1f) ? 0 : ((unsigned int)op1 >> op2);
        break;
      default:
        printf("ERROR -- unexpected 32-bit operation\n");
        n_errs++;
        return;
      }
    }

    res->s32[i] = r;
  }
}

#define emulate64_m128(oper, res, src1, src2)                                  \
  emulate64((oper), (res), dummy, (__mmask8)-1, (src1), (src2), 2, 0)

#define emulate64_mask_m128(oper, res, orig, k, src1, src2)                    \
  emulate64((oper), (res), (orig), (k), (src1), (src2), 2, 0)

#define emulate64_maskz_m128(oper, res, k, src1, src2)                         \
  emulate64((oper), (res), dummy, (k), (src1), (src2), 2, 1)

#define emulate64_m256(oper, res, src1, src2)                                  \
  emulate64((oper), (res), dummy, (__mmask8)-1, (src1), (src2), 4, 0)

#define emulate64_mask_m256(oper, res, orig, k, src1, src2)                    \
  emulate64((oper), (res), (orig), (k), (src1), (src2), 4, 0)

#define emulate64_maskz_m256(oper, res, k, src1, src2)                         \
  emulate64((oper), (res), dummy, (k), (src1), (src2), 4, 1)

#define emulate64_m512(oper, res, src1, src2)                                  \
  emulate64((oper), (res), dummy, (__mmask8)-1, (src1), (src2), 8, 0)

#define emulate64_mask_m512(oper, res, orig, k, src1, src2)                    \
  emulate64((oper), (res), (orig), (k), (src1), (src2), 8, 0)

#define emulate64_maskz_m512(oper, res, k, src1, src2)                         \
  emulate64((oper), (res), dummy, (k), (src1), (src2), 8, 1)

#define emulate64_m256(oper, res, src1, src2)                                  \
  emulate64((oper), (res), dummy, (__mmask8)-1, (src1), (src2), 4, 0)

#define emulate64_mask_m256(oper, res, orig, k, src1, src2)                    \
  emulate64((oper), (res), (orig), (k), (src1), (src2), 4, 0)

#define emulate64_maskz_m256(oper, res, k, src1, src2)                         \
  emulate64((oper), (res), dummy, (k), (src1), (src2), 4, 1)

#define emulate64_m128(oper, res, src1, src2)                                  \
  emulate64((oper), (res), dummy, (__mmask8)-1, (src1), (src2), 2, 0)

#define emulate64_mask_m128(oper, res, orig, k, src1, src2)                    \
  emulate64((oper), (res), (orig), (k), (src1), (src2), 2, 0)

#define emulate64_maskz_m128(oper, res, k, src1, src2)                         \
  emulate64((oper), (res), dummy, (k), (src1), (src2), 2, 1)

void NOINLINE emulate64(Operation oper, V512 *res, V512 orig, __mmask8 k,
                        V512 src1, V512 src2, int length, int zero_mask) {
  int i;
  I64 op1, op2, r;

  for (i = 0; i < length; i++) {
    if (((1 << i) & k) == 0) {
      r = zero_mask ? 0 : orig.s64[i];
    } else {
      op1 = src1.s64[i];
      op2 = src2.s64[i];

      switch (oper) {
      case OP_ROL:
        op2 &= 0x3f;
        r = (op1 << op2);
        if (op2 != 0) {
          r |= ((U64)op1 >> (64 - op2));
        }
        break;
      case OP_ROR:
        op2 &= 0x3f;
        r = ((U64)op1 >> op2);
        if (op2 != 0) {
          r |= (op1 << (64 - op2));
        }
        break;
      case OP_SLL:
        r = (op2 & ~0x3f) ? 0 : (op1 << op2);
        break;
      case OP_SRA:
        r = (op2 & ~0x3f) ? (op1 < 0 ? -1 : 0) : (op1 >> op2);
        break;
      case OP_SRL:
        r = (op2 & ~0x3f) ? 0 : ((U64)op1 >> op2);
        break;
      default:
        printf("ERROR -- unexpected 64-bit operation\n");
        n_errs++;
        return;
      }
    }

    res->s64[i] = r;
  }
}

void NOINLINE do_shiftv32() {
  V512 res;
  V512 expected;

  /* sll 32 */

  soft_counts32_update();
  res.zmmi = _mm512_sllv_epi32(src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_m512(OP_SLL, &expected, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_sllv_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi =
      _mm512_mask_sllv_epi32(passthru.zmmi, k16, src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_mask_m512(OP_SLL, &expected, passthru, k16, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_sllv_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi = _mm512_maskz_sllv_epi32(k16, src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_maskz_m512(OP_SLL, &expected, k16, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_sllv_epi32", __LINE__);

  /* sra 32 */

  soft_counts32_update();
  res.zmmi = _mm512_srav_epi32(src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_m512(OP_SRA, &expected, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_srav_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi =
      _mm512_mask_srav_epi32(passthru.zmmi, k16, src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_mask_m512(OP_SRA, &expected, passthru, k16, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srav_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi = _mm512_maskz_srav_epi32(k16, src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_maskz_m512(OP_SRA, &expected, k16, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_srav_epi32", __LINE__);

  /* srl 32 */

  soft_counts32_update();
  res.zmmi = _mm512_srlv_epi32(src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_m512(OP_SRL, &expected, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_srlv_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi =
      _mm512_mask_srlv_epi32(passthru.zmmi, k16, src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_mask_m512(OP_SRL, &expected, passthru, k16, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srlv_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi = _mm512_maskz_srlv_epi32(k16, src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_maskz_m512(OP_SRL, &expected, k16, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_srlv_epi32", __LINE__);
}

void NOINLINE do_shiftv64() {
  V512 res;
  V512 expected;

  /* sll 64 */

  soft_counts64_update();
  res.zmmi = _mm512_sllv_epi64(src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_m512(OP_SLL, &expected, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_sllv_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_mask_sllv_epi64(passthru.zmmi, k8, src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_mask_m512(OP_SLL, &expected, passthru, k8, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_sllv_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_maskz_sllv_epi64(k8, src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_maskz_m512(OP_SLL, &expected, k8, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_sllv_epi64", __LINE__);

  /* sra 64 */

  soft_counts64_update();
  res.zmmi = _mm512_srav_epi64(src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_m512(OP_SRA, &expected, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_srav_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_mask_srav_epi64(passthru.zmmi, k8, src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_mask_m512(OP_SRA, &expected, passthru, k8, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srav_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_maskz_srav_epi64(k8, src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_maskz_m512(OP_SRA, &expected, k8, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_srav_epi64", __LINE__);

  /* srl 64 */

  soft_counts64_update();
  res.zmmi = _mm512_srlv_epi64(src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_m512(OP_SRL, &expected, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_srlv_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_mask_srlv_epi64(passthru.zmmi, k8, src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_mask_m512(OP_SRL, &expected, passthru, k8, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_srlv_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_maskz_srlv_epi64(k8, src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_maskz_m512(OP_SRL, &expected, k8, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_srlv_epi64", __LINE__);
}

void NOINLINE do_rotate32() {
  V512 res;
  V512 expected;

  /* rotate left 32 */

  soft_counts32_update();
  res.zmmi = _mm512_rolv_epi32(src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_m512(OP_ROL, &expected, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_rolv_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi =
      _mm512_mask_rolv_epi32(passthru.zmmi, k16, src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_mask_m512(OP_ROL, &expected, passthru, k16, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_rolv_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi = _mm512_maskz_rolv_epi32(k16, src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_maskz_m512(OP_ROL, &expected, k16, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_rolv_epi32", __LINE__);

  /* rotate left 32 imm form 512 */

  soft_counts32_update();
  res.zmmi = _mm512_rol_epi32(src.zmmi, IMMCNT);
  soft_counts32_update();
  emulate32_m512(OP_ROL, &expected, src, counts32_imm);
  check_equal_nd(&res, &expected, 16, "_mm512_rol_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi = _mm512_mask_rol_epi32(passthru.zmmi, k16, src.zmmi, IMMCNT);
  soft_counts32_update();
  emulate32_mask_m512(OP_ROL, &expected, passthru, k16, src, counts32_imm);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_rol_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi = _mm512_maskz_rol_epi32(k16, src.zmmi, IMMCNT);
  soft_counts32_update();
  emulate32_maskz_m512(OP_ROL, &expected, k16, src, counts32_imm);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_rol_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi = _mm512_rorv_epi32(src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_m512(OP_ROR, &expected, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_rorv_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi =
      _mm512_mask_rorv_epi32(passthru.zmmi, k16, src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_mask_m512(OP_ROR, &expected, passthru, k16, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_rorv_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi = _mm512_maskz_rorv_epi32(k16, src.zmmi, counts32.zmmi);
  soft_counts32_update();
  emulate32_maskz_m512(OP_ROR, &expected, k16, src, counts32);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_rorv_epi32", __LINE__);

  /* rotate right 32 imm form */
  soft_counts32_update();
  res.zmmi = _mm512_ror_epi32(src.zmmi, IMMCNT);
  soft_counts32_update();
  emulate32_m512(OP_ROR, &expected, src, counts32_imm);
  check_equal_nd(&res, &expected, 16, "_mm512_ror_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi = _mm512_mask_ror_epi32(passthru.zmmi, k16, src.zmmi, IMMCNT);
  soft_counts32_update();
  emulate32_mask_m512(OP_ROR, &expected, passthru, k16, src, counts32_imm);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_ror_epi32", __LINE__);

  soft_counts32_update();
  res.zmmi = _mm512_maskz_ror_epi32(k16, src.zmmi, IMMCNT);
  soft_counts32_update();
  emulate32_maskz_m512(OP_ROR, &expected, k16, src, counts32_imm);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_ror_epi32", __LINE__);
}

void NOINLINE do_rotate64() {
  V512 res;
  V512 expected;

  /* rotate left 64 */

  soft_counts64_update();
  res.zmmi = _mm512_rolv_epi64(src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_m512(OP_ROL, &expected, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_rolv_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_mask_rolv_epi64(passthru.zmmi, k8, src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_mask_m512(OP_ROL, &expected, passthru, k8, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_rolv_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_maskz_rolv_epi64(k8, src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_maskz_m512(OP_ROL, &expected, k8, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_rolv_epi64", __LINE__);

  /* rotate left 64 imm form 512 */

  soft_counts64_update();
  res.zmmi = _mm512_rol_epi64(src.zmmi, IMMCNT);
  soft_counts64_update();
  emulate64_m512(OP_ROL, &expected, src, counts64_imm);
  check_equal_nd(&res, &expected, 16, "_mm512_rol_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_mask_rol_epi64(passthru.zmmi, k8, src.zmmi, IMMCNT);
  soft_counts64_update();
  emulate64_mask_m512(OP_ROL, &expected, passthru, k8, src, counts64_imm);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_rol_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_maskz_rol_epi64(k8, src.zmmi, IMMCNT);
  soft_counts64_update();
  emulate64_maskz_m512(OP_ROL, &expected, k8, src, counts64_imm);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_rol_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_rorv_epi64(src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_m512(OP_ROR, &expected, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_rorv_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_mask_rorv_epi64(passthru.zmmi, k8, src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_mask_m512(OP_ROR, &expected, passthru, k8, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_rorv_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_maskz_rorv_epi64(k8, src.zmmi, counts64.zmmi);
  soft_counts64_update();
  emulate64_maskz_m512(OP_ROR, &expected, k8, src, counts64);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_rorv_epi64", __LINE__);

  /* rotate right 64 imm form */
  soft_counts64_update();
  res.zmmi = _mm512_ror_epi64(src.zmmi, IMMCNT);
  soft_counts64_update();
  emulate64_m512(OP_ROR, &expected, src, counts64_imm);
  check_equal_nd(&res, &expected, 16, "_mm512_ror_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_mask_ror_epi64(passthru.zmmi, k8, src.zmmi, IMMCNT);
  soft_counts64_update();
  emulate64_mask_m512(OP_ROR, &expected, passthru, k8, src, counts64_imm);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_ror_epi64", __LINE__);

  soft_counts64_update();
  res.zmmi = _mm512_maskz_ror_epi64(k8, src.zmmi, IMMCNT);
  soft_counts64_update();
  emulate64_maskz_m512(OP_ROR, &expected, k8, src, counts64_imm);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_ror_epi64", __LINE__);
}

void NOINLINE do_shifti32() {
  V512 xres, zres;
  V512 expected;
  __mmask16 myk16 = 0x7f7f;

  /* slli, non-masked */

  soft_update(src);
  zres.zmmi = _mm512_slli_epi32(src.zmmi, IMMCNT);
  emulate32_m512(OP_SLL, &expected, src, counts32_imm);
  check_equal_nd(&zres, &expected, 16, "_mm512_slli_epi32", __LINE__);

  soft_update(src);
  zres.zmmi = _mm512_slli_epi32(src.zmmi, 0);
  check_equal_nd(&zres, &src, 16, "_mm512_slli_epi32 0", __LINE__);

  soft_update(src);
  zres.zmmi = _mm512_slli_epi32(src.zmmi, 33);
  xres.zmmi = _mm512_setzero_epi32();
  check_equal_nd(&zres, &xres, 16, "_mm512_slli_epi32 33", __LINE__);

  /* slli, masked.  Reuses "expected" from above. */

  soft_update(src);
  zres.zmmi = _mm512_mask_slli_epi32(passthru.zmmi, myk16, src.zmmi, IMMCNT);
  expected.zmmi = _mm512_mask_mov_epi32(passthru.zmmi, myk16, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_slli_epi32", __LINE__);

  /* slli, zero-masked.  Reuses "expected" from above. */

  soft_update(src);
  zres.zmmi = _mm512_maskz_slli_epi32(myk16, src.zmmi, IMMCNT);
  expected.zmmi = _mm512_maskz_mov_epi32(myk16, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_slli_epi32", __LINE__);

  /* srai, non-masked */

  soft_update(src);
  zres.zmmi = _mm512_srai_epi32(src.zmmi, IMMCNT);
  emulate32_m512(OP_SRA, &expected, src, counts32_imm);
  check_equal_nd(&zres, &expected, 16, "_mm512_srai_epi32", __LINE__);

  soft_update(src);
  zres.zmmi = _mm512_srai_epi32(src.zmmi, 0);
  check_equal_nd(&zres, &src, 16, "_mm512_srai_epi32 0", __LINE__);

  /* srai, masked.  Reuses "expected" from above. */

  soft_update(src);
  zres.zmmi = _mm512_mask_srai_epi32(passthru.zmmi, myk16, src.zmmi, IMMCNT);
  expected.zmmi = _mm512_mask_mov_epi32(passthru.zmmi, myk16, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_srai_epi32", __LINE__);

  /* srai, zero-masked.  Reuses "expected" from above. */

  soft_update(src);
  zres.zmmi = _mm512_maskz_srai_epi32(myk16, src.zmmi, IMMCNT);
  expected.zmmi = _mm512_maskz_mov_epi32(myk16, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_srai_epi32", __LINE__);

  /* srli, non-masked */

  soft_update(src);
  zres.zmmi = _mm512_srli_epi32(src.zmmi, IMMCNT);
  emulate32_m512(OP_SRL, &expected, src, counts32_imm);
  check_equal_nd(&zres, &expected, 16, "_mm512_srli_epi32", __LINE__);

  soft_update(src);
  zres.zmmi = _mm512_srli_epi32(src.zmmi, 0);
  check_equal_nd(&zres, &src, 16, "_mm512_srli_epi32 0", __LINE__);

  soft_update(src);
  zres.zmmi = _mm512_srli_epi32(src.zmmi, 33);
  xres.zmmi = _mm512_setzero_epi32();
  check_equal_nd(&zres, &xres, 16, "_mm512_srli_epi32 33", __LINE__);

  /* srli, masked.  Reuses "expected" from above. */

  soft_update(src);
  zres.zmmi = _mm512_mask_srli_epi32(passthru.zmmi, myk16, src.zmmi, IMMCNT);
  expected.zmmi = _mm512_mask_mov_epi32(passthru.zmmi, myk16, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_srli_epi32", __LINE__);

  /* srli, zero-masked.  Reuses "expected" from above. */

  soft_update(src);
  zres.zmmi = _mm512_maskz_srli_epi32(myk16, src.zmmi, IMMCNT);
  expected.zmmi = _mm512_maskz_mov_epi32(myk16, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_srli_epi32", __LINE__);
}

void NOINLINE do_shifti64() {
  V512 xres, zres;
  V512 expected;
  __mmask8 myk8 = 0xee;

  /* slli, non-masked */

  soft_update(src);
  zres.zmmi = _mm512_slli_epi64(src.zmmi, IMMCNT);
  emulate64_m512(OP_SLL, &expected, src, counts64_imm);
  check_equal_nd(&zres, &expected, 16, "_mm512_slli_epi64", __LINE__);

  soft_update(src);
  zres.zmmi = _mm512_slli_epi64(src.zmmi, 0);
  check_equal_nd(&zres, &src, 16, "_mm512_slli_epi64 0", __LINE__);

  soft_update(src);
  zres.zmmi = _mm512_slli_epi64(src.zmmi, 67);
  xres.zmmi = _mm512_setzero_epi32();
  check_equal_nd(&zres, &xres, 16, "_mm512_slli_epi64 67", __LINE__);

  /* slli, masked.  Reuses "expected" from above. */

  soft_update(src);
  zres.zmmi = _mm512_mask_slli_epi64(passthru.zmmi, myk8, src.zmmi, IMMCNT);
  expected.zmmi = _mm512_mask_mov_epi64(passthru.zmmi, myk8, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_slli_epi64", __LINE__);

  /* slli, zero-masked.  Reuses "expected" from above. */

  soft_update(src);
  zres.zmmi = _mm512_maskz_slli_epi64(myk8, src.zmmi, IMMCNT);
  expected.zmmi = _mm512_maskz_mov_epi64(myk8, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_slli_epi64", __LINE__);

  /* srai, non-masked */

  soft_update(src);
  zres.zmmi = _mm512_srai_epi64(src.zmmi, IMMCNT);
  emulate64_m512(OP_SRA, &expected, src, counts64_imm);
  check_equal_nd(&zres, &expected, 16, "_mm512_srai_epi64", __LINE__);

  soft_update(src);
  zres.zmmi = _mm512_srai_epi64(src.zmmi, 0);
  check_equal_nd(&zres, &src, 16, "_mm512_srai_epi64 0", __LINE__);

  /* srai, masked.  Reuses "expected" from above. */

  soft_update(src);
  zres.zmmi = _mm512_mask_srai_epi64(passthru.zmmi, myk8, src.zmmi, IMMCNT);
  expected.zmmi = _mm512_mask_mov_epi64(passthru.zmmi, myk8, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_srai_epi64", __LINE__);

  /* srai, zero-masked.  Reuses "expected" from above. */

  soft_update(src);
  zres.zmmi = _mm512_maskz_srai_epi64(myk8, src.zmmi, IMMCNT);
  expected.zmmi = _mm512_maskz_mov_epi64(myk8, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_srai_epi64", __LINE__);

  /* srli, non-masked */

  soft_update(src);
  zres.zmmi = _mm512_srli_epi64(src.zmmi, IMMCNT);
  emulate64_m512(OP_SRL, &expected, src, counts64_imm);
  check_equal_nd(&zres, &expected, 16, "_mm512_srli_epi64", __LINE__);

  soft_update(src);
  zres.zmmi = _mm512_srli_epi64(src.zmmi, 0);
  check_equal_nd(&zres, &src, 16, "_mm512_srli_epi64 0", __LINE__);

  soft_update(src);
  zres.zmmi = _mm512_srli_epi64(src.zmmi, 67);
  xres.zmmi = _mm512_setzero_epi32();
  check_equal_nd(&zres, &xres, 16, "_mm512_srli_epi64 67", __LINE__);

  /* srli, masked.  Reuses "expected" from above. */

  soft_update(src);
  zres.zmmi = _mm512_mask_srli_epi64(passthru.zmmi, myk8, src.zmmi, IMMCNT);
  expected.zmmi = _mm512_mask_mov_epi64(passthru.zmmi, myk8, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_mask_srli_epi64", __LINE__);

  /* srli, zero-masked.  Reuses "expected" from above. */

  soft_update(src);
  zres.zmmi = _mm512_maskz_srli_epi64(myk8, src.zmmi, IMMCNT);
  expected.zmmi = _mm512_maskz_mov_epi64(myk8, expected.zmmi);
  check_equal_nd(&zres, &expected, 16, "_mm512_maskz_srli_epi64", __LINE__);
}

int main(int argc, char *argv[]) {
  init();

  do_shifti32();
  do_shifti64();
  do_shiftv32();
  do_shiftv64();

  do_rotate32();
  do_rotate64();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
