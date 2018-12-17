/*
 * Test shift instructions.
 * This test was created to check the correctness
 * of the following intrinsics support:
 *      _mm512_sllv_epi32()
 *      _mm512_srav_epi32()
 *      _mm512_srlv_epi32()
 */

#include "m512_test_util.h"
#include <stdio.h>

__m512i i1;
__m512i i2;
__m512i i3;
__m512i i4;

volatile int vol = 0; /* To prevent optimizations */

void NOINLINE init() {
  /* Set shift counts in i1. */

  int i;
  V512 *v = (V512 *)&i1;

  for (i = 0; i < 16; i++) {
    if ((i & 0x3) == 0) {
      v->u32[i] = i + vol;
    } else if ((i & 0x3) == 1) {
      v->u32[i] = -(i + 1 + vol);
    } else if ((i & 0x3) == 2) {
      v->u32[i] = i + 31 + vol;
    } else {
      v->u32[i] = -(i + 31 + vol);
    }
  }

  /* Set random values in i2. */

  v = (V512 *)&i2;

  for (i = 0; i < 64; i++) {
    v->u8[i] = i * i - 3 * i + i + vol;
  }
}

void NOINLINE check_equal32(void *vgot, void *vexpected, void *vexpected_orig,
                            int mask, char *banner) {
  int i;
  V512 *got = (V512 *)vgot;
  V512 *expected = (V512 *)vexpected;
  V512 *orig = (V512 *)vexpected_orig;

  for (i = 0; i < 16; i++) {
    int ans = (mask & (1 << i)) ? expected->s32[i] : orig->s32[i];
    if (got->s32[i] != ans) {
      printf("ERROR: %s failed -- 0x%0.8x != 0x%0.8x at element [%d]\n",
             banner ? banner : "", got->s32[i], ans, i);
      n_errs++;
      break;
    }
  }
}

typedef enum {
  SLLV,   /* Shift count can exceed 31. */
  SRAV,   /* Shift count can exceed 31. */
  SRLV,   /* Shift count can exceed 31. */
  SLLV31, /* Shift count is anded with 31. */
  SRAV31, /* Shift count is anded with 31. */
  SRLV31  /* Shift count is anded with 31. */
} SHIFT_TYPE;

void NOINLINE emulate_shift(void *presult, void *pv_old, int mask, void *psrc,
                            void *pcounts, SHIFT_TYPE type) {
  V512 *result = (V512 *)presult;
  V512 *v_old = (V512 *)pv_old;
  V512 *src = (V512 *)psrc;
  V512 *counts = (V512 *)pcounts;
  int i, imm;

  for (i = 0; i < 16; i++) {
    if ((mask & (1 << i)) == 0) {
      result->u32[i] = v_old->u32[i];
    } else {
      imm = counts->u32[i];
      if (type == SLLV31 || type == SRAV31 || type == SRLV31) {
        imm &= 0x1f;
      }

      if ((unsigned int)imm > 31) {
        if (type == SRAV && src->s32[i] < 0) {
          result->u32[i] = -1;
        } else {
          result->u32[i] = 0;
        }
      } else if (type == SLLV || type == SLLV31) {
        result->u32[i] = src->u32[i] << imm;
      } else if (type == SRLV || type == SRLV31) {
        result->u32[i] = src->u32[i] >> imm;
      } else { /* (type == SRAV || type == SRAV31) */
        result->u32[i] = src->s32[i] >> imm;
      }
    }
  }
}

void NOINLINE do_shifts() {
  int k;

  k = 0xffff;
  i3 = _mm512_sllv_epi32(i2, i1);
  emulate_shift(&i4, &i2, k, &i2, &i1, SLLV);
  check_equal32(&i3, &i4, &i2, k, "_mm512_sllv_epi32");

  k = 0x97d5;
  i3 = _mm512_mask_sllv_epi32(i2, k, i2, i1);
  emulate_shift(&i4, &i2, k, &i2, &i1, SLLV);
  check_equal32(&i3, &i4, &i2, k, "_mm512_sllv_epi32");

  k = 0xffff;
  i3 = _mm512_srav_epi32(i2, i1);
  emulate_shift(&i4, &i2, k, &i2, &i1, SRAV);
  check_equal32(&i3, &i4, &i2, k, "_mm512_srav_epi32");

  k = 0x97d5;
  i3 = _mm512_mask_srav_epi32(i2, k, i2, i1);
  emulate_shift(&i4, &i2, k, &i2, &i1, SRAV);
  check_equal32(&i3, &i4, &i2, k, "_mm512_srav_epi32");

  k = 0xffff;
  i3 = _mm512_srlv_epi32(i2, i1);
  emulate_shift(&i4, &i2, k, &i2, &i1, SRLV);
  check_equal32(&i3, &i4, &i2, k, "_mm512_srlv_epi32");

  k = 0x97d5;
  i3 = _mm512_mask_srlv_epi32(i2, k, i2, i1);
  emulate_shift(&i4, &i2, k, &i2, &i1, SRLV);
  check_equal32(&i3, &i4, &i2, k, "_mm512_srlv_epi32");
}

int main() {
  init();
  do_shifts();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
