#include "lasx_test_util.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_out, __m256i_result;
  __m256 __m256_out, __m256_result;
  __m256d __m256d_out, __m256d_result;
  v4u64 v4u64_op0, v4u64_op1, v4u64_op2, v4u64_result;
  v8i32 v8i32_op0, v8i32_op1, v8i32_op2, v8i32_result;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0101010101010101,
                      0xfffffffffffffefd, 0x0101010101010101};
  v4u64_result = (v4u64){0xffffffffffffffff, 0xc08f780000000000,
                         0xfffffffffffffefd, 0xc08f780000000000};
  __m256d_out = __lasx_xvflogb_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xfff0000000000000, 0xfff0000000000000,
                         0xfff0000000000000, 0xfff0000000000000};
  __m256d_out = __lasx_xvflogb_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xfff0000000000000, 0xfff0000000000000,
                         0xfff0000000000000, 0xfff0000000000000};
  __m256d_out = __lasx_xvflogb_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xfff0000000000000, 0xfff0000000000000,
                         0xfff0000000000000, 0xfff0000000000000};
  __m256d_out = __lasx_xvflogb_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xfff0000000000000, 0xfff0000000000000,
                         0xfff0000000000000, 0xfff0000000000000};
  __m256d_out = __lasx_xvflogb_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xfff0000000000000, 0xfff0000000000000,
                         0xfff0000000000000, 0xfff0000000000000};
  __m256d_out = __lasx_xvflogb_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  return 0;
}
