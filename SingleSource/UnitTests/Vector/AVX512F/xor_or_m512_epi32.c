#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>
/* This test was created to check the correctness
 * of the following intrinsics support:
 * _mm512_or_epi32()
 * _mm512_mask_or_epi32()
 * _mm512_xor_epi32()
 * _mm512_mask_xor_epi32()
 */
void __declspec(noinline)
    check_equal_epi32(__m512i vres, __m512i vexp, char *banner, int line) {
  int i;

  __declspec(align(64)) int res[16];
  __declspec(align(64)) int exp[16];

  _mm512_store_epi32(res, vres);
  _mm512_store_epi32(exp, vexp);

  for (i = 0; i < 16; i++) {
    if (res[i] != exp[i]) {
      printf("ERROR: %s failed at line %d with result (%d) != "
             "(%d)  element %d\n",
             banner, line, res[i], exp[i], i);
      ++n_errs;
    }
  }
}

void __declspec(noinline) do_or_() {
  __mmask16 k8 = 0xAAAA;
  volatile __m512i undef = _mm512_set1_epi32(3);
  volatile __m512i v1 = _mm512_set1_epi32((10));
  volatile __m512i v2 = _mm512_set1_epi32((3));
  volatile __m512i exp1 = _mm512_set1_epi32((11));
  volatile __m512i exp2 = _mm512_set_epi32((11), 3, (11), 3, (11), 3, (11), 3,
                                           (11), 3, (11), 3, (11), 3, (11), 3);
  volatile __m512i r = _mm512_or_epi32(v1, v2);
  check_equal_nd(&r, &exp1, 16, "_mm512_or_epi32", __LINE__);
  r = _mm512_mask_or_epi32(undef, k8, v1, v2);
  check_equal_nd(&r, &exp2, 16, "_mm512_mask_or_epi32", __LINE__);
}

void __declspec(noinline) do_xor_() {
  __mmask16 k8 = 0xAAAA;
  volatile __m512i undef = _mm512_set1_epi32(3);
  volatile __m512i v1 = _mm512_set1_epi32((10));
  volatile __m512i v2 = _mm512_set1_epi32((3));
  volatile __m512i exp1 = _mm512_set1_epi32((9));
  volatile __m512i exp2 = _mm512_set_epi32((9), 3, (9), 3, (9), 3, (9), 3, (9),
                                           3, (9), 3, (9), 3, (9), 3);
  volatile __m512i r = _mm512_xor_epi32(v1, v2);
  check_equal_nd(&r, &exp1, 16, "_mm512_xor_epi32", __LINE__);
  r = _mm512_mask_xor_epi32(undef, k8, v1, v2);
  check_equal_nd(&r, &exp2, 16, "_mm512_mask_xor_epi32", __LINE__);
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
