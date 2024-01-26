#include "lsx_test_util.h"
#include <lsxintrin.h>

int
main ()
{
  __m128i __m128i_out, __m128i_result;
  __m128  __m128_out, __m128_result;
  __m128d __m128d_out, __m128d_result;
  v2u64 v2u64_op0, v2u64_op1, v2u64_op2;
  v4i32 v4i32_op0, v4i32_op1, v4i32_op2;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  __m128i_result = (__m128i){0x00a300a300a300a3, 0x00a300a300a300a3};
  __m128i_out = __lsx_vldi(1187);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  __m128i_result = (__m128i){0xfffffffffffffe15, 0xfffffffffffffe15};
  __m128i_out = __lsx_vldi(3605);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  __m128i_result = (__m128i){0xecececececececec, 0xecececececececec};
  __m128i_out = __lsx_vldi(1004);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  __m128i_result = (__m128i){0x00ffff00ff00ff00, 0x00ffff00ff00ff00};
  __m128i_out = __lsx_vldi(-1686);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  __m128i_result = (__m128i){0x004d004d004d004d, 0x004d004d004d004d};
  __m128i_out = __lsx_vldi(1101);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  __m128i_result = (__m128i){0x0a0000000a000000, 0x0a0000000a000000};
  __m128i_out = __lsx_vldi(-3318);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  __m128i_result = (__m128i){0x00ffff00ff00ff00, 0x00ffff00ff00ff00};
  __m128i_out = __lsx_vldi(-1686);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  __m128i_result = (__m128i){0x0a0000000a000000, 0x0a0000000a000000};
  __m128i_out = __lsx_vldi(-3318);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
