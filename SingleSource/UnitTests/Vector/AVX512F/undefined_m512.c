#include "m512_test_util.h"
#include <stdio.h>

/* This test was created to check support
 * of the following intrinsics:
 * _mm512_undefined()
 * _mm512_undefined_epi32()
 * _mm512_undefined_pd()
 * _mm512_undefined_ps()
 */

__m512 NOINLINE do_undef() {
  __m512 v1 = _mm512_undefined();
  __m512i v2 = _mm512_undefined_epi32();
  __m512d v3 = _mm512_undefined_pd();
  __m512 v4 = _mm512_undefined_ps();

  return v4;
}

int main(int argc, char *argv[]) {
  /*
   * These tests don't execute meaningfully, so don't call them.
   * argc is typically 1 but the compiler doesn't known that.
   * We're really just ensuring that they get succesfully compiled,
   * And that, if executed by an sde, they are successfully decoded.
   */
  if (argc > 10) {
    do_undef();
  }

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
