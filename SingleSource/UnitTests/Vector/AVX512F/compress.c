
/*
 * Test the compress family of intrinsics.
 * This test was created to check the correctness
 * of the following intrinsics support:
 *      _mm512_mask_compress_epi32()
 *      _mm512_mask_compress_epi64()
 *      _mm512_mask_compress_ps()
 *      _mm512_mask_compress_pd()
 *      _mm512_mask_compressstoreu_epi32()
 *      _mm512_mask_compressstoreu_epi64()
 *      _mm512_mask_compressstoreu_ps()
 *      _mm512_mask_compressstoreu_pd()
 */

#include "m512_test_util.h"
#include <stdio.h>

V512 i32;
V512 i64;
V512 f32;
V512 f64;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 16; i++) {
    i32.s32[i] = i;
    f32.f32[i] = i;
  }

  for (i = 0; i < 8; i++) {
    i64.s64[i] = i;
    f64.f64[i] = i;
  }
}

/*
 * Check that the low N 32-bit elements of "got" and "expected" are the same.
 */
void NOINLINE check_equal_n(void *got, void *expected, int n_elems,
                            char *banner) {
  int i;
  V512 *v1 = (V512 *)got;
  V512 *v2 = (V512 *)expected;

  for (i = 0; i < n_elems; i++) {
    if (v1->u32[i] != v2->u32[i]) {
      printf("ERROR: %s failed at %d'th element:  0x%0.8x != 0x%0.8x\n",
             banner ? banner : "", i, v1->u32[i], v2->u32[i]);
      n_errs++;
      break;
    }
  }
}

void NOINLINE do_512_compress_epi32() {
  V512 res;
  V512 expected;
  volatile int i, j;
  __mmask16 k = 0x7923;

  res.zmmi = _mm512_mask_compress_epi32(i32.zmmi, k, i32.zmmi);
  for (i = 0, j = 0; i < 16; i++) {
    if (k & (1 << i)) {
      expected.s32[j++] = i32.s32[i];
    }
  }
  for (i = j; i < 16; i++) {
    expected.s32[i] = i32.s32[i];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_compress_epi32", __LINE__);
}

void NOINLINE do_512_compress_epi64() {
  V512 res;
  V512 expected;
  volatile int i, j;
  __mmask8 k = 0xbd;

  res.zmmi = _mm512_mask_compress_epi64(i64.zmmi, k, i64.zmmi);
  for (i = 0, j = 0; i < 8; i++) {
    if (k & (1 << i)) {
      expected.s64[j++] = i64.s64[i];
    }
  }
  for (i = j; i < 8; i++) {
    expected.s64[i] = i64.s64[i];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_compress_epi64", __LINE__);
}

void NOINLINE do_512_compress_ps() {
  V512 res;
  V512 expected;
  volatile int i, j;
  __mmask16 k = 0xabcd;

  res.zmm = _mm512_mask_compress_ps(f32.zmm, k, f32.zmm);
  for (i = 0, j = 0; i < 16; i++) {
    if (k & (1 << i)) {
      expected.f32[j++] = f32.f32[i];
    }
  }
  for (i = j; i < 16; i++) {
    expected.f32[i] = f32.f32[i];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_compress_ps", __LINE__);
}

void NOINLINE do_512_compress_pd() {
  V512 res;
  V512 expected;
  volatile int i, j;
  __mmask8 k = 0x57;

  res.zmmd = _mm512_mask_compress_pd(f64.zmmd, k, f64.zmmd);
  for (i = 0, j = 0; i < 8; i++) {
    if (k & (1 << i)) {
      expected.f64[j++] = f64.f64[i];
    }
  }
  for (i = j; i < 8; i++) {
    expected.f64[i] = f64.f64[i];
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_compress_pd", __LINE__);
}

void NOINLINE do_512_compressstore_epi32() {
  V512 res;
  V512 expected;
  volatile int i, j;
  __mmask16 k = 0x3297;

  for (i = 0; i < 16; i++) {
    res.s32[i] = -13;
  }

  _mm512_mask_compressstoreu_epi32(&res, k, i32.zmmi);
  for (i = 0, j = 0; i < 16; i++) {
    if (k & (1 << i)) {
      expected.s32[j++] = i32.s32[i];
    }
  }
  for (i = j; i < 16; i++) {
    expected.s32[i] = -13;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_compressstoreu_epi32",
                 __LINE__);
}

void NOINLINE do_512_compressstore_epi64() {
  V512 res;
  V512 expected;
  volatile int i, j;
  __mmask8 k = 0x9c;

  for (i = 0; i < 8; i++) {
    res.s64[i] = -72;
  }

  _mm512_mask_compressstoreu_epi64(&res, k, i64.zmmi);
  for (i = 0, j = 0; i < 8; i++) {
    if (k & (1 << i)) {
      expected.s64[j++] = i64.s64[i];
    }
  }
  for (i = j; i < 8; i++) {
    expected.s64[i] = -72;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_compressstoreu_epi64",
                 __LINE__);
}

void NOINLINE do_512_compressstore_ps() {
  V512 res;
  V512 expected;
  volatile int i, j;
  __mmask16 k = 0xdcf3;

  for (i = 0; i < 16; i++) {
    res.f32[i] = -100.0f;
  }

  _mm512_mask_compressstoreu_ps(&res, k, f32.zmm);
  for (i = 0, j = 0; i < 16; i++) {
    if (k & (1 << i)) {
      expected.f32[j++] = f32.f32[i];
    }
  }
  for (i = j; i < 16; i++) {
    expected.f32[i] = -100.0f;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_compressstoreu_ps",
                 __LINE__);
}

void NOINLINE do_512_compressstore_pd() {
  V512 res;
  V512 expected;
  volatile int i, j;
  __mmask8 k = 0xf5;

  for (i = 0; i < 8; i++) {
    res.f64[i] = -99.0;
  }

  _mm512_mask_compressstoreu_pd(&res, k, f64.zmmd);
  for (i = 0, j = 0; i < 8; i++) {
    if (k & (1 << i)) {
      expected.f64[j++] = f64.f64[i];
    }
  }
  for (i = j; i < 8; i++) {
    expected.f64[i] = -99.0;
  }
  check_equal_nd(&res, &expected, 16, "_mm512_mask_compressstoreu_pd",
                 __LINE__);
}

int main(int argc, char *argv[]) {
  init();

  do_512_compress_epi32();
  do_512_compress_epi64();
  do_512_compress_ps();
  do_512_compress_pd();

  do_512_compressstore_epi32();
  do_512_compressstore_epi64();
  do_512_compressstore_ps();
  do_512_compressstore_pd();

  if (n_errs) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
