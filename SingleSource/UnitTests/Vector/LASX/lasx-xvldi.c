#include "lasx_test_util.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_out, __m256i_result;
  __m256 __m256_out, __m256_result;
  __m256d __m256d_out, __m256d_result;
  v4u64 v4u64_op0, v4u64_op1, v4u64_op2;
  v8i32 v8i32_op0, v8i32_op1, v8i32_op2;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  __m256i_result = (__m256i){0x0000001000000010, 0x0000001000000010,
                             0x0000001000000010, 0x0000001000000010};
  __m256i_out = __lasx_xvldi(-4080);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  __m256i_result = (__m256i){0xfebcfebcfebcfebc, 0xfebcfebcfebcfebc,
                             0xfebcfebcfebcfebc, 0xfebcfebcfebcfebc};
  __m256i_out = __lasx_xvldi(1724);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  __m256i_result = (__m256i){0x3fd1000000000000, 0x3fd1000000000000,
                             0x3fd1000000000000, 0x3fd1000000000000};
  __m256i_out = __lasx_xvldi(-943);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  __m256i_result = (__m256i){0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c,
                             0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c};
  __m256i_out = __lasx_xvldi(1820);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  __m256i_result = (__m256i){0x7200000072000000, 0x7200000072000000,
                             0x7200000072000000, 0x7200000072000000};
  __m256i_out = __lasx_xvldi(-3214);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  __m256i_result = (__m256i){0xffffff1dffffff1d, 0xffffff1dffffff1d,
                             0xffffff1dffffff1d, 0xffffff1dffffff1d};
  __m256i_out = __lasx_xvldi(2845);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  __m256i_result = (__m256i){0x0000001000000010, 0x0000001000000010,
                             0x0000001000000010, 0x0000001000000010};
  __m256i_out = __lasx_xvldi(-4080);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  __m256i_result = (__m256i){0x3fd1000000000000, 0x3fd1000000000000,
                             0x3fd1000000000000, 0x3fd1000000000000};
  __m256i_out = __lasx_xvldi(-943);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  __m256i_result = (__m256i){0x7200000072000000, 0x7200000072000000,
                             0x7200000072000000, 0x7200000072000000};
  __m256i_out = __lasx_xvldi(-3214);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
