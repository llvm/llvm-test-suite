/*
 * Test 512 and 256-bit insert intrinsics taking 2 simd operands
 * and an immediate, with masked and zero-masked forms.
 * Here we check for _mm512_[mask|maskz]_insert[f|i] intrinsics.
 */

#include "m512_test_util.h"
#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

#define CHECK_INSERT(opcode, res_bit_size, dtype, is_masked, mask,             \
                     is_zero_mask, imm, op2_bit_size, elem_bit_size)           \
  {                                                                            \
    int fail = 0;                                                              \
    /* Compute the expected result. */                                         \
    expect.zmmi = compute_insert(&expect, mask, is_zero_mask, imm,             \
                                 &dtype##op1.zmmi, &dtype##op2.zmmi,           \
                                 res_bit_size, op2_bit_size, elem_bit_size);   \
                                                                               \
    /* Compare the obtained and expected results. */                           \
    fail =                                                                     \
        check_equal_n##dtype(&res, &expect, res_bit_size / elem_bit_size,      \
                             is_masked ? (is_zero_mask ? opcode " zero mask"   \
                                                       : opcode " blend mask") \
                                       : opcode " no mask",                    \
                             __LINE__);                                        \
    if (fail) {                                                                \
      printf("\n\nMASK: %x, IMM: %d\n\n", mask, imm);                          \
      printf("\n");                                                            \
      display_p##dtype(&dtype##op1, "op1:", res_bit_size / elem_bit_size);     \
      printf("\n");                                                            \
      display_p##dtype(&dtype##op2, "op2:", op2_bit_size / elem_bit_size);     \
      printf("\n");                                                            \
      display_p##dtype(&dtype##res_orig,                                       \
                       "old:", res_bit_size / elem_bit_size);                  \
      printf("\n================================================\n\n");        \
    }                                                                          \
  }

#define ZINSERT(opcode, res_bit_size, intrin, dtype, op2_xy, vtype_suffix,     \
                is_masked, mask, is_zero_mask, imm, op2_bit_size,              \
                elem_bit_size)                                                 \
  {                                                                            \
    if (is_masked) {                                                           \
      if (is_zero_mask) {                                                      \
        /* Zero masking */                                                     \
        memset(&res, 0xFF, sizeof(res));                                       \
        res.zmm##vtype_suffix = _mm512_maskz_##intrin(                         \
            mask, dtype##op1.zmm##vtype_suffix,                                \
            dtype##op2.op2_xy##mm##vtype_suffix[0], imm);                      \
      } else {                                                                 \
        /* Blend masking */                                                    \
        memcpy(&res, &dtype##res_orig, sizeof(res));                           \
        res.zmm##vtype_suffix = _mm512_mask_##intrin(                          \
            res.zmm##vtype_suffix, mask, dtype##op1.zmm##vtype_suffix,         \
            dtype##op2.op2_xy##mm##vtype_suffix[0], imm);                      \
      }                                                                        \
    } else {                                                                   \
      /* No masking */                                                         \
      memset(&res, 0x0, sizeof(res));                                          \
      res.zmm##vtype_suffix =                                                  \
          _mm512_##intrin(dtype##op1.zmm##vtype_suffix,                        \
                          dtype##op2.op2_xy##mm##vtype_suffix[0], imm);        \
    }                                                                          \
    CHECK_INSERT(opcode, res_bit_size, dtype, is_masked, mask, is_zero_mask,   \
                 imm, op2_bit_size, elem_bit_size)                             \
  }

volatile int vol0 = 0;

V512 dop1, dop2, dres_orig;
V512 qop1, qop2, qres_orig;
V512 res, expect;

volatile unsigned int dres_orig_arr[16] = {
    0x12345678, 0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555,
    0x66666666, 0x77777777, 0x88888888, 0x99999999, 0xaaaaaaaa, 0xbbbbbbbb,
    0xcccccccc, 0xdddddddd, 0xeeeeeeee, 0xffffffff};

volatile U64 qres_orig_arr[8] = {0x1234567890abcdef, 0x1111111111111111,
                                 0x2222222222222222, 0x3333333333333333,
                                 0x4444444444444444, 0x5555555555555555,
                                 0x6666666666666666, 0x7777777777777777};

static void NOINLINE init() {
  int i;

  // Operand vectors
  for (i = 0; i < 16; i++) {
    dop1.u32[i] = 0x11000000 + i;
  }
  for (i = 0; i < 16; i++) {
    dop2.u32[i] = 0xFF000000 + i;
  }

  for (i = 0; i < 8; i++) {
    qop1.u64[i] = 0x1111000000000000 + i;
  }
  for (i = 0; i < 8; i++) {
    qop2.u64[i] = 0xFFFF000000000000 + i;
  }

  // Destructed operand vectors
  memcpy((void *)&dres_orig, (void *)dres_orig_arr, 64);
  memcpy((void *)&qres_orig, (void *)qres_orig_arr, 64);
}

//
// Emulate the insert operation.
//
__m512i NOINLINE compute_insert(void *res, unsigned int mask, bool zero_mask,
                                int imm, const void *op1, const void *op2,
                                int res_bit_size, int op2_bit_size,
                                int elem_bit_size) {
  V512 *vres = (V512 *)res;
  V512 *vop1 = (V512 *)op1;
  V512 *vop2 = (V512 *)op2;

  int res_idx, elem_mask;
  int num_elems = res_bit_size / elem_bit_size;

  // Merge op1 and op2 into dest; we will do masking later.
  //
  if (res_bit_size == 512) {
    // zmm dest.
    memcpy((void *)&vres->zmmi, (void *)&vop1->zmmi, 64);

    if (op2_bit_size == 128) {
      // xmm op2
      memcpy((void *)&vres->xmmi[imm], (void *)&vop2->xmmi[0], 16);
    } else {
      // ymm op2
      memcpy((void *)&vres->ymmi[imm], (void *)&vop2->ymmi[0], 32);
    }
  } else {
    // ymm dest.
    memcpy((void *)&vres->ymmi[0], (void *)&vop1->ymmi[0], 32);

    // xmm op2
    memcpy((void *)&vres->xmmi[imm], (void *)&vop2->xmmi[0], 16);
  }

  // Apply masking.
  //
  res_idx = 0;
  for (res_idx = 0; res_idx < num_elems; res_idx++) {

    elem_mask = mask & (1 << res_idx);

    // The merge above has taken care of the elem_mask == 1 case.
    if (elem_mask == 0) {
      if (zero_mask) {
        // Zeroing behavior.
        if (elem_bit_size == 32) {
          vres->s32[res_idx] = 0;
        } else {
          vres->s64[res_idx] = 0;
        }
      } else {
        // Blending behavior
        if (elem_bit_size == 32) {
          vres->s32[res_idx] = dres_orig.s32[res_idx];
        } else {
          vres->s64[res_idx] = qres_orig.s64[res_idx];
        }
      }
    }
  }

  return vres->zmmi;
}

#define KMASK_NONE ((__mmask8)0xff)
#define K16MASK_NONE ((__mmask16)0xffff)

#define K8MASK_32x16 ((__mmask16)0xaaaa)

#define K8MASK_64x8 ((__mmask8)0xaa)

// FLOAT operations
// ================

void NOINLINE do_zinsertf32x4() {
  // zinsertf32x4
  //
  ZINSERT("ZINSERTF32x4", 512, insertf32x4, d, x, , false, K16MASK_NONE, false,
          0, 128, 32);

  ZINSERT("ZINSERTF32x4", 512, insertf32x4, d, x, , true, K8MASK_32x16, false,
          0, 128, 32);

  ZINSERT("ZINSERTF32x4", 512, insertf32x4, d, x, , true, K8MASK_32x16, true, 0,
          128, 32);

  ZINSERT("ZINSERTF32x4", 512, insertf32x4, d, x, , true, K8MASK_32x16, true, 1,
          128, 32);

  ZINSERT("ZINSERTF32x4", 512, insertf32x4, d, x, , true, K8MASK_32x16, true, 2,
          128, 32);

  /*
   * No-op to inhibit PRE of loads to exercise mixing operations.
   */
  dop2.s32[vol0] = dop2.s32[vol0];

  ZINSERT("ZINSERTF32x4", 512, insertf32x4, d, x, , true, K8MASK_32x16, true, 3,
          128, 32);
}

void NOINLINE do_zinsertf64x4() {
  // zinsertf64x4
  //
  ZINSERT("ZINSERTF64x4", 512, insertf64x4, q, y, d, false, KMASK_NONE, false,
          0, 256, 64);

  ZINSERT("ZINSERTF64x4", 512, insertf64x4, q, y, d, true, K8MASK_64x8, false,
          0, 256, 64);

  ZINSERT("ZINSERTF64x4", 512, insertf64x4, q, y, d, true, K8MASK_64x8, true, 0,
          256, 64);

  /*
   * No-op to inhibit PRE of loads to exercise mixing operations.
   */
  dop2.s64[vol0] = dop2.s64[vol0];

  ZINSERT("ZINSERTF64x4", 512, insertf64x4, q, y, d, true, K8MASK_64x8, true, 1,
          256, 64);
}

// INT operations
// ==============

void NOINLINE do_zinserti32x4() {
  // zinserti32x4
  //
  ZINSERT("ZINSERTI32x4", 512, inserti32x4, d, x, i, false, K16MASK_NONE, false,
          0, 128, 32);

  ZINSERT("ZINSERTI32x4", 512, inserti32x4, d, x, i, true, K8MASK_32x16, false,
          1, 128, 32);

  ZINSERT("ZINSERTI32x4", 512, inserti32x4, d, x, i, true, K8MASK_32x16, true,
          2, 128, 32);

  /*
   * No-op to inhibit PRE of loads to exercise mixing operations.
   */
  dop2.s32[vol0] = dop2.s32[vol0];

  ZINSERT("ZINSERTI32x4", 512, inserti32x4, d, x, i, true, K8MASK_32x16, true,
          3, 128, 32);
}

void NOINLINE do_zinserti64x4() {
  // zinserti64x4
  //

  ZINSERT("ZINSERTI64x4", 512, inserti64x4, q, y, i, false, KMASK_NONE, false,
          0, 256, 64);

  ZINSERT("ZINSERTI64x4", 512, inserti64x4, q, y, i, true, K8MASK_64x8, false,
          0, 256, 64);

  ZINSERT("ZINSERTI64x4", 512, inserti64x4, q, y, i, true, K8MASK_64x8, true, 0,
          256, 64);

  /*
   * No-op to inhibit PRE of loads to exercise mixing operations.
   */
  dop2.s64[vol0] = dop2.s64[vol0];

  ZINSERT("ZINSERTI64x4", 512, inserti64x4, q, y, i, true, K8MASK_64x8, true, 1,
          256, 64);
}

int main() {
  init();

  // FLOAT
  do_zinsertf32x4();
  do_zinsertf64x4();

  // INT
  do_zinserti32x4();
  do_zinserti64x4();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
