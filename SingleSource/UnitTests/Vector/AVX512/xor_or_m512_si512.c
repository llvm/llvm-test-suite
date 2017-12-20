#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>
/* This test was created to check the correctness
 * of the following intrinsics support:
 * _mm512_or_si512()
 * _mm512_xor_si512()
 */
void __declspec(noinline) do_or_() {
  volatile __m512i v1 = _mm512_set1_epi32((10));
  volatile __m512i v2 = _mm512_set1_epi32((3));
  volatile __m512i exp1 = _mm512_set1_epi32((11));
  volatile __m512i r = _mm512_or_si512(v1, v2);
  check_equal_nd(&r, &exp1, 16, "_mm512_or_si512", __LINE__);
}

void __declspec(noinline) do_xor_() {
  volatile __m512i v1 = _mm512_set1_epi32((10));
  volatile __m512i v2 = _mm512_set1_epi32((3));
  volatile __m512i exp1 = _mm512_set1_epi32((9));
  volatile __m512i r = _mm512_xor_si512(v1, v2);
  check_equal_nd(&r, &exp1, 16, "_mm512_xor_si512", __LINE__);
}

int main(int argc, char *argv[]) {
  do_or_();
  do_xor_();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
