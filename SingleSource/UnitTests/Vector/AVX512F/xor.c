/*
 * Test xor intrinsics.
 * This test was created to check the correctness
 * of the following intrinsics support:
 * _mm512_xor_epi32()
 * _mm512_mask_xor_epi32()
 * _mm512_xor_epi64()
 * _mm512_mask_xor_epi64()
 */

#include "m512_test_util.h"
#include <stdio.h>

volatile int vol = 0; /* Inhibit optimization */

__m512 f1, f2, f3, f3_orig;
__m512d d1, d2, d3, d3_orig;
__m512i i1, i2, i3, i3_orig;

void NOINLINE set_nonzero(void *vp, int c) {
  int i;
  V512 *v = (V512 *)vp;

  for (i = 0; i < 16; i++) {
    v->u32[i] = 10 * i * i - 3 * i + c;
    if (v->u32[i] == 0) {
      v->u32[i] = 1234;
    }
  }
}

void NOINLINE check_xor(void *vp1, void *vp2, void *vp3, void *vp_orig,
                        int mask, char *banner) {
  int i;
  V512 *v1 = (V512 *)vp1;
  V512 *v2 = (V512 *)vp2;
  V512 *v3 = (V512 *)vp3;
  V512 *v_orig = (V512 *)vp_orig;

  for (i = 0; i < 16; i++) {
    int actual = v3->u32[i];
    int expected = v_orig->u32[i];
    if (mask & (1 << i)) {
      expected = v1->u32[i] ^ v2->u32[i];
    }
    if (actual + vol != expected - vol) {
      printf("ERROR: %s failed\n", banner ? banner : "");
      n_errs++;
      break;
    }
  }
}

void NOINLINE do_xor() {
  set_nonzero(&i1, 99);
  set_nonzero(&i2, 100);
  set_nonzero(&f1, 33);
  set_nonzero(&f2, -35);
  set_nonzero(&d1, -11);
  set_nonzero(&d2, 14);

  set_nonzero(&i3, 1000);
  i3_orig = i3;
  i3 = _mm512_xor_epi32(i1, i2);
  check_xor(&i1, &i2, &i3, &i3_orig, 0xffff, "_mm512_xor_epi32");

  set_nonzero(&i3, 1500);
  i3_orig = i3;
  i3 = _mm512_mask_xor_epi32(i3_orig, 0x5555, i1, i2);
  check_xor(&i1, &i2, &i3, &i3_orig, 0x5555, "_mm512_mask_xor_epi32");

  set_nonzero(&i3, 2000);
  i3_orig = i3;
  i3 = _mm512_xor_epi64(i1, i2);
  check_xor(&i1, &i2, &i3, &i3_orig, 0xffff, "_mm512_xor_epi64");

  set_nonzero(&i3, 2500);
  i3_orig = i3;
  i3 = _mm512_mask_xor_epi64(i3_orig, 0x55, i1, i2);
  check_xor(&i1, &i2, &i3, &i3_orig, 0x3333, "_mm512_mask_xor_epi64");
}

int main() {
  do_xor();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
