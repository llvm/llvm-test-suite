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

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvflogb_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x11111113, 0x11111111, 0x10101093, 0x10101010,
                      0x10101012, 0x10101010, 0x10101012, 0x10101010};
  v8i32_result = (v8i32){0xc2ba0000, 0xc2ba0000, 0xc2be0000, 0xc2be0000,
                         0xc2be0000, 0xc2be0000, 0xc2be0000, 0xc2be0000};
  __m256_out = __lasx_xvflogb_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xff800000, 0xff800000, 0xff800000, 0xff800000,
                         0xff800000, 0xff800000, 0xff800000, 0xff800000};
  __m256_out = __lasx_xvflogb_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xff800000, 0xff800000, 0xff800000, 0xff800000,
                         0xff800000, 0xff800000, 0xff800000, 0xff800000};
  __m256_out = __lasx_xvflogb_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000087, 0x00000000, 0x00000000,
                      0x00000000, 0x00000087, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xff800000, 0xc30e0000, 0xff800000, 0xff800000,
                         0xff800000, 0xc30e0000, 0xff800000, 0xff800000};
  __m256_out = __lasx_xvflogb_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  return 0;
}
