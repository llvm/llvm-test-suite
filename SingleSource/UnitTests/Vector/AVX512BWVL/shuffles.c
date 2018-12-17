/*
 * Test shifts and rotates.
 *
 * This test was created to check the correctness
 * of the following intrinsics support:
 *      _mm_shuffle_epi32()
 *      _mm_shufflehi_epi16()
 *      _mm_shufflelo_epi16()
 *      _mm256_shuffle_epi32()
 *      _mm256_shufflehi_epi16()
 *      _mm256_shufflelo_epi16()
 *      _mm512_shuffle_epi32()
 *      _mm512_shufflehi_epi16()
 *      _mm512_shufflelo_epi16()
 */

#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

V512 counts16, counts32, counts64, src, passthru, zeros;
__mmask8 k8 = 0xf9;
__mmask16 k16 = 0x9ffe;

volatile int vol0;

/*
 * Use this between tests to make compiler think src was updated.
 * Prevents PRE'ing of a load of src.
 */
#define soft_src_update() src.xmmi[vol0] = src.xmmi[vol0]
#define soft_counts16_update() counts16.xmmi[vol0] = counts16.xmmi[vol0]
#define soft_counts32_update() counts32.xmmi[vol0] = counts32.xmmi[vol0]
#define soft_counts64_update() counts64.xmmi[vol0] = counts64.xmmi[vol0]

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 16; i++) {
    counts32.s32[i] = 3;
    zeros.u32[i] = 0;
    src.s32[i] = -27 * i * i + 300 * i - 82;
    if (i & 0x1) {
      src.s32[i] *= -1;
    }
    passthru.s32[i] = 48 * i * i + 100 * i - 9;
  }

  for (i = 0; i < 8; i++) {
    counts64.s64[i] = 9;
  }

  for (i = 0; i < 32; i++) {
    counts16.s16[i] = 4;
  }
}


void NOINLINE emulate_shuffle(void *presult, const void *p, 
const void *mask_src, int size, int control, int mask) {
  int i;
  V512 *result = (V512 *)presult;
  V512 *v = (V512 *)p;
  V512 *src = (V512 *)mask_src;
  for (i = 0; i < size; i++) {
    if (((1 << i) & mask) == 0) 
        result->u32[i] = src->u32[i];
      else
        result->u32[i] = v->u32[4 * (i / 4) + ((control >> (2 * (i % 4))) & 3)];
  }
}


void NOINLINE emulate_shuffle16(void *presult, const void *p, 
const void *mask_src, int size, int control, int mask, int order) {
  int i;
  V512 *result = (V512 *)presult;
  V512 *v = (V512 *)p;
  V512 *src = (V512 *)mask_src;
  for (i = 0; i < size; i++) {
    if (((1 << i) & mask) == 0) {
      result->u16[i] = src->u16[i];
    } else {
      if ((i / 4) % 2 == order) {
        result->u16[i] = v->u16[i];
      } else {
        result->u16[i] = v->u16[4 * (i / 4) + ((control >> (2 * (i % 4))) & 3)];
      }
    }
  }
}


void NOINLINE do_shuffle_epi32() {
  volatile V512 res;
  V512 expected;
  
  // checking mm512 shuffle
  soft_counts32_update();
  res.zmmi = _mm512_shuffle_epi32(src.zmmi, 3);
  emulate_shuffle(&expected, &src, &zeros, 16, 3, 0xffff);
  check_equal_nd(&res, &expected, 16, "_mm512_shuffle_epi32", __LINE__);
  soft_counts32_update();

  soft_counts32_update();
  res.zmmi = _mm512_mask_shuffle_epi32(passthru.zmmi, k16, src.zmmi, 3);
  emulate_shuffle(&expected, &src, &passthru, 16, 3, k16);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_shuffle_epi32", __LINE__);
  soft_counts32_update();

  soft_counts32_update();
  res.zmmi = _mm512_maskz_shuffle_epi32(k16, src.zmmi, 3);
  emulate_shuffle(&expected, &src, &zeros, 16, 3, k16);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_shuffle_epi32", __LINE__);
  soft_counts32_update();
  
  // checking mm256 shuffle
  soft_counts32_update();
  res.ymmi[0] = _mm256_shuffle_epi32(src.ymmi[0], 3);
  emulate_shuffle(&expected, &src, &zeros, 8, 3, 0xff);
  check_equal_nd(&res, &expected, 8, "_mm256_shuffle_epi32", __LINE__);
  soft_counts32_update();
  
  soft_counts32_update();
  res.ymmi[0] = _mm256_mask_shuffle_epi32(passthru.ymmi[0], k8, src.ymmi[0], 3);
  emulate_shuffle(&expected, &src, &passthru, 8, 3, k8);
  check_equal_nd(&res, &expected, 8, "_mm256_mask_shuffle_epi32", __LINE__);
  soft_counts32_update();

  soft_counts32_update();
  res.ymmi[0] = _mm256_maskz_shuffle_epi32(k8, src.ymmi[0], 3);
  emulate_shuffle(&expected, &src, &zeros, 8, 3, k8);
  check_equal_nd(&res, &expected, 8, "_mm256_maskz_shuffle_epi32", __LINE__);
  soft_counts32_update();
  
  // checking mm shuffle
  soft_counts32_update();
  res.xmmi[0] = _mm_shuffle_epi32(src.xmmi[0], 3);
  emulate_shuffle(&expected, &src, &zeros, 4, 3, 0xf);
  check_equal_nd(&res, &expected, 4, "_mm_shuffle_epi32", __LINE__);
  soft_counts32_update();
  
  soft_counts32_update();
  res.xmmi[0] = _mm_mask_shuffle_epi32(passthru.xmmi[0], k8, src.xmmi[0], 3);
  emulate_shuffle(&expected, &src, &passthru, 4, 3, k8);
  check_equal_nd(&res, &expected, 4, "_mm_mask_shuffle_epi32", __LINE__);
  soft_counts32_update();
  
  soft_counts32_update();
  res.xmmi[0] = _mm_maskz_shuffle_epi32(k8, src.xmmi[0], 3);
  emulate_shuffle(&expected, &src, &zeros, 4, 3, k8);
  check_equal_nd(&res, &expected, 4, "_mm_maskz_shuffle_epi32", __LINE__);
  soft_counts32_update();
}

void NOINLINE do_shufflehi_epi16() {
  volatile V512 res;
  V512 expected;

  // checking mm512 shufflehi
  soft_counts32_update();
  res.zmmi = _mm512_shufflehi_epi16(src.zmmi, 3);
  emulate_shuffle16(&expected, &src, &src, 32, 3, 0xffffffff, 0);
  check_equal_nd(&res, &expected, 16, "_mm512_shufflehi_epi16", __LINE__);
  soft_counts32_update();
  
  soft_counts32_update();
  res.zmmi = _mm512_mask_shufflehi_epi16(passthru.zmmi, k16, src.zmmi, 3);
  emulate_shuffle16(&expected, &src, &passthru, 32, 3, k16, 0);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_shufflehi_epi16", __LINE__);
  soft_counts32_update();

  soft_counts32_update();
  res.zmmi = _mm512_maskz_shufflehi_epi16(k16, src.zmmi, 3);
  emulate_shuffle16(&expected, &src, &zeros, 32, 3, k16, 0);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_shufflehi_epi16", __LINE__);
  soft_counts32_update(); 

  // checking mm256 shufflehi
  soft_counts32_update();
  res.ymmi[0] = _mm256_shufflehi_epi16(src.ymmi[0], 3);
  emulate_shuffle16(&expected, &src, &zeros, 16, 3, 0xffff, 0);
  check_equal_nd(&res, &expected, 8, "_mm256_shufflehi_epi16", __LINE__);
  soft_counts32_update();
  
  soft_counts32_update();
  res.ymmi[0] = _mm256_mask_shufflehi_epi16(passthru.ymmi[0], k16, src.ymmi[0], 3);
  emulate_shuffle16(&expected, &src, &passthru, 16, 3, k16, 0);
  check_equal_nd(&res, &expected, 8, "_mm256_mask_shufflehi_epi16", __LINE__);
  soft_counts32_update();

  soft_counts32_update();
  res.ymmi[0] = _mm256_maskz_shufflehi_epi16(k16, src.ymmi[0], 3);
  emulate_shuffle16(&expected, &src, &zeros, 16, 3, k16, 0);
  check_equal_nd(&res, &expected, 8, "_mm256_maskz_shufflehi_epi16", __LINE__);
  soft_counts32_update();
  
  // checking mm shufflehi
  soft_counts32_update();
  res.xmmi[0] = _mm_shufflehi_epi16(src.xmmi[0], 3);
  emulate_shuffle16(&expected, &src, &zeros, 8, 3, 0xff, 0);
  check_equal_nd(&res, &expected, 4, "_mm_shufflehi_epi16", __LINE__);
  soft_counts32_update();
  
  soft_counts32_update();
  res.xmmi[0] = _mm_mask_shufflehi_epi16(passthru.xmmi[0], k8, src.xmmi[0], 3);
  emulate_shuffle16(&expected, &src, &passthru, 8, 3, k8, 0);
  check_equal_nd(&res, &expected, 4, "_mm_mask_shufflehi_epi16", __LINE__);
  soft_counts32_update();
  
  soft_counts32_update();
  res.xmmi[0] = _mm_maskz_shufflehi_epi16(k8, src.xmmi[0], 3);
  emulate_shuffle16(&expected, &src, &zeros, 8, 3, k8, 0);
  check_equal_nd(&res, &expected, 4, "_mm_maskz_shufflehi_epi16", __LINE__);
  soft_counts32_update();
}

void NOINLINE do_shufflelo_epi16() {
  volatile V512 res;
  V512 expected;

  // checking mm512 shufflelo
  soft_counts32_update();
  res.zmmi = _mm512_shufflelo_epi16(src.zmmi, 3);
  emulate_shuffle16(&expected, &src, &src, 32, 3, 0xffffffff, 1);
  check_equal_nd(&res, &expected, 16, "_mm512_shufflelo_epi16", __LINE__);
  soft_counts32_update();
  
  soft_counts32_update();
  res.zmmi = _mm512_mask_shufflelo_epi16(passthru.zmmi, k16, src.zmmi, 3);
  emulate_shuffle16(&expected, &src, &passthru, 32, 3, k16, 1);
  check_equal_nd(&res, &expected, 16, "_mm512_mask_shufflelo_epi16", __LINE__);
  soft_counts32_update();

  soft_counts32_update();
  res.zmmi = _mm512_maskz_shufflelo_epi16(k16, src.zmmi, 3);
  emulate_shuffle16(&expected, &src, &zeros, 32, 3, k16, 1);
  check_equal_nd(&res, &expected, 16, "_mm512_maskz_shufflelo_epi16", __LINE__);
  soft_counts32_update(); 
  
  // checking mm256 shufflelo
  soft_counts32_update();
  res.ymmi[0] = _mm256_shufflelo_epi16(src.ymmi[0], 3);
  emulate_shuffle16(&expected, &src, &zeros, 16, 3, 0xffff, 1);
  check_equal_nd(&res, &expected, 8, "_mm256_shufflelo_epi16", __LINE__);
  soft_counts32_update();
  
  soft_counts32_update();
  res.ymmi[0] = _mm256_mask_shufflelo_epi16(passthru.ymmi[0], k16, src.ymmi[0], 3);
  emulate_shuffle16(&expected, &src, &passthru, 16, 3, k16, 1);
  check_equal_nd(&res, &expected, 8, "_mm256_mask_shufflelo_epi16", __LINE__);
  soft_counts32_update();

  soft_counts32_update();
  res.ymmi[0] = _mm256_maskz_shufflelo_epi16(k16, src.ymmi[0], 3);
  emulate_shuffle16(&expected, &src, &zeros, 16, 3, k16, 1);
  check_equal_nd(&res, &expected, 8, "_mm256_maskz_shufflelo_epi16", __LINE__);
  soft_counts32_update();
  
  // checking mm shufflelo
  soft_counts32_update();
  res.xmmi[0] = _mm_shufflelo_epi16(src.xmmi[0], 3);
  emulate_shuffle16(&expected, &src, &zeros, 8, 3, 0xff, 1);
  check_equal_nd(&res, &expected, 4, "_mm_shufflelo_epi16", __LINE__);
  soft_counts32_update();
  
  soft_counts32_update();
  res.xmmi[0] = _mm_mask_shufflelo_epi16(passthru.xmmi[0], k8, src.xmmi[0], 3);
  emulate_shuffle16(&expected, &src, &passthru, 8, 3, k8, 1);
  check_equal_nd(&res, &expected, 4, "_mm_mask_shufflelo_epi16", __LINE__);
  soft_counts32_update();
  
  soft_counts32_update();
  res.xmmi[0] = _mm_maskz_shufflelo_epi16(k8, src.xmmi[0], 3);
  emulate_shuffle16(&expected, &src, &zeros, 8, 3, k8, 1);
  check_equal_nd(&res, &expected, 4, "_mm_maskz_shufflelo_epi16", __LINE__);
  soft_counts32_update();
}

int main(int argc, char *argv[]) {
  init();

  do_shuffle_epi32();
  do_shufflelo_epi16();
  do_shufflehi_epi16();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
