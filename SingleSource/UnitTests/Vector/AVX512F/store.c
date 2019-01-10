/*
 * Test store instructions.
 * This test was created to check the correctness
 * of the following intrinsics support:
 *      _mm512_store_ps()
 *      _mm512_mask_store_ps()
 *      _mm512_store_epi32()
 *      _mm512_mask_store_epi32()
 *      _mm512_store_epi64()
 *      _mm512_mask_store_epi64()
 *      _mm512_store_pd()
 *      _mm512_mask_store_pd()
 */

#include "m512_test_util.h"
#include <stdio.h>

__m512 v1;
__m512i i1;
__m512d d1;
V512 tval;
int ALIGNTO(64) dest_memory[16];
unsigned int et_memory[16];
void *pdst = (void *)&dest_memory;

unsigned int initial = 0;
void NOINLINE set_nonzero(void *vp, int c) {
  int i;
  V512 *v = (V512 *)vp;

  for (i = 0; i < 16; i++) {
    v->u32[i] = 10 * i * i - 3 * i + c;
    if (v->u32[i] == 0) {
      v->u32[i] = 1234;
    }
    et_memory[i] = initial;
    dest_memory[i] = initial;
  }
}

void NOINLINE set_generic32_result(void *vp1, int mask, int subset) {
  int i, max;
  V512 *v1 = (V512 *)vp1;

  max = (subset == 1 ? 1 : (subset == 2 ? 4 : 16));
  for (i = 0; i < max; i++) {
    if ((mask & 0x1) != 0) {
      et_memory[i] = v1->u32[i];
    }
    mask >>= 1;
  }
}

void NOINLINE set_generic64_result(void *vp1, int mask, int subset) {
  int i, max;
  V512 *v1 = (V512 *)vp1;

  max = (subset == 1 ? 1 : (subset == 2 ? 4 : 8));
  for (i = 0; i < max; i++) {
    if ((mask & 0x1) != 0) {
      ((U64 *)&et_memory)[i] = v1->u64[i];
    }
    mask >>= 1;
  }
}

void NOINLINE do_store_ps() {
  /* full vector */
  set_nonzero(&v1, 11);
  set_generic32_result(&v1, 0xffff, 0);
  _mm512_store_ps(pdst, v1);
  check_equal_nd(pdst, &et_memory, 16, "_mm512_store_ps - full vector",
                 __LINE__);

  /* vector with write mask */
  set_nonzero(&v1, 5);
  set_generic32_result(&v1, 0xf00f, 0);
  _mm512_mask_store_ps(pdst, 0xf00f, v1);
  check_equal_nd(pdst, &et_memory, 16, "_mm512_mask_store_ps - full vector",
                 __LINE__);
}

void NOINLINE do_store_epi32() {
  /* full vector */
  set_nonzero(&i1, 11);
  set_generic32_result(&i1, 0xffff, 0);
  _mm512_store_epi32(pdst, i1);
  check_equal_nd(pdst, &et_memory, 16, "_mm512_store_epi32 - full vector",
                 __LINE__);

  /* vector with write mask */
  set_nonzero(&i1, 5);
  set_generic32_result(&i1, 0xf00f, 0);
  _mm512_mask_store_epi32(pdst, 0xf00f, i1);
  check_equal_nd(pdst, &et_memory, 16, "_mm512_mask_store_epi32 - full vector",
                 __LINE__);
}

void NOINLINE do_store_epi64() {
  /* full vector */
  set_nonzero(&i1, 11);
  set_generic64_result(&i1, 0xff, 0);
  _mm512_store_epi64(pdst, i1);
  check_equal_nq(pdst, &et_memory, 8, "_mm512_store_epi64 - full vector",
                 __LINE__);

  /* vector with write mask */
  set_nonzero(&i1, 5);
  set_generic64_result(&i1, 0x60, 0);
  _mm512_mask_store_epi64(pdst, 0x60, i1);
  check_equal_nq(pdst, &et_memory, 8, "_mm512_mask_store_epi64 - full vector",
                 __LINE__);
}

void NOINLINE do_store_pd() {
  /* full vector */
  set_nonzero(&d1, 11);
  set_generic64_result(&d1, 0xff, 0);
  _mm512_store_pd(pdst, d1);
  check_equal_nq(pdst, &et_memory, 8, "_mm512_store_pd - full vector",
                 __LINE__);

  /* vector with write mask */
  set_nonzero(&d1, 5);
  set_generic64_result(&d1, 0xf1, 0);
  _mm512_mask_store_pd(pdst, 0xf1, d1);
  check_equal_nq(pdst, &et_memory, 8, "_mm512_mask_store_pd - full vector",
                 __LINE__);
}

int main() {
  do_store_ps();
  do_store_epi32();
  do_store_epi64();
  do_store_pd();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
