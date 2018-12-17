/*
 * Test MOVZEXT family intrinsics.
 * This test was created to check the correctness
 * of the following intrinsics support:
 * _mm256_zextps128_ps256()
 * _mm256_zextpd128_pd256()
 * _mm256_zextsi128_si256()
 * _mm512_zextps128_ps512()
 * _mm512_zextpd128_pd512()
 * _mm512_zextsi128_si512()
 * _mm512_zextps256_ps512()
 * _mm512_zextpd256_pd512()
 * _mm512_zextsi256_si512()
 */

#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

V512 src1;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 16; i++) {
    src1.s32[i] = (i + 1) * 1111111;
  }
}

void NOINLINE emulate_zext(V512 *res, V512 src1, int length) {
  int j;

  for (j = 0; j < 16; j++) {
    res->s32[j] = 0;
  }

  for (j = 0; j < length; j++) {
    res->s32[j] = src1.s32[j];
  }
}

void NOINLINE do_zext() {
  V512 res;
  V512 expected;

  emulate_zext(&expected, src1, 4);
  res.ymm[0] = _mm256_zextps128_ps256(src1.xmm[0]);
  check_equal_nd(&res, &expected, 8, "_mm256_zextps128_ps256", __LINE__);

  emulate_zext(&expected, src1, 4);
  res.ymmd[0] = _mm256_zextpd128_pd256(src1.xmmd[0]);
  check_equal_nd(&res, &expected, 8, "_mm256_zextpd128_pd256", __LINE__);

  emulate_zext(&expected, src1, 4);
  res.ymmi[0] = _mm256_zextsi128_si256(src1.xmmi[0]);
  check_equal_nd(&res, &expected, 8, "_mm256_zextsi128_si256", __LINE__);

  emulate_zext(&expected, src1, 4);
  res.zmm = _mm512_zextps128_ps512(src1.xmm[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_zextps128_ps512", __LINE__);

  emulate_zext(&expected, src1, 4);
  res.zmmd = _mm512_zextpd128_pd512(src1.xmmd[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_zextpd128_pd512", __LINE__);

  emulate_zext(&expected, src1, 4);
  res.zmmi = _mm512_zextsi128_si512(src1.xmmi[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_zextsi128_si512", __LINE__);

  emulate_zext(&expected, src1, 8);
  res.zmm = _mm512_zextps256_ps512(src1.ymm[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_zextps256_ps512", __LINE__);

  emulate_zext(&expected, src1, 8);
  res.zmmd = _mm512_zextpd256_pd512(src1.ymmd[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_zextpd256_pd512", __LINE__);

  emulate_zext(&expected, src1, 8);
  res.zmmi = _mm512_zextsi256_si512(src1.ymmi[0]);
  check_equal_nd(&res, &expected, 16, "_mm512_zextsi256_si512", __LINE__);
}

int main(int argc, char *argv[]) {
  init();

  do_zext();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }
  printf("PASSED\n");
  return 0;
}
