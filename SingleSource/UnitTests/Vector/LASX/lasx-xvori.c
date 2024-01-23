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

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010101,
                             0x0101010101010101, 0x0101010101010101};
  __m256i_out = __lasx_xvori_b((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x6c6c6c6c6c6c6c6c, 0x6c6c6c6c6c6c6c6c,
                             0x6c6c6c6c6c6c6c6c, 0x6c6c6c6c6c6c6c6c};
  __m256i_out = __lasx_xvori_b((__m256)v4u64_op0, 0x6c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffff00fffffff0, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffff9fffffffff, 0x9f9f9f9f9f9f9f9f,
                             0x9f9f9f9fffffffff, 0x9f9f9f9f9f9f9f9f};
  __m256i_out = __lasx_xvori_b((__m256)v4u64_op0, 0x9f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvori_b((__m256)v4u64_op0, 0x6a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffbdff3cffbdff44, 0xffffffffffffffff,
                      0xffbdff3cffbdff44, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffff7effffff46, 0xffffffffffffffff,
                             0xffffff7effffff46, 0xffffffffffffffff};
  __m256i_out = __lasx_xvori_b((__m256)v4u64_op0, 0x42);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xbfbfbfbfbfbfbfbf, 0xbfbfbfbfbfbfbfbf,
                             0xbfbfbfbfbfbfbfbf, 0xbfbfbfbfbfbfbfbf};
  __m256i_out = __lasx_xvori_b((__m256)v4u64_op0, 0xbf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x2c2c2c2c2c2c2c2c,
                             0xffffffffffffffff, 0x2c2c2c2c2c2c2c2c};
  __m256i_out = __lasx_xvori_b((__m256)v4u64_op0, 0x2c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x5252525252525252, 0x5252525252525252,
                             0x5252525252525252, 0x5252525252525252};
  __m256i_out = __lasx_xvori_b((__m256)v4u64_op0, 0x52);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x3f8000003f800000, 0x3f8000003f800000,
                      0x3f8000003f800000, 0x3f8000003f800000};
  __m256i_result = (__m256i){0x7fe363637fe36363, 0x7fe363637fe36363,
                             0x7fe363637fe36363, 0x7fe363637fe36363};
  __m256i_out = __lasx_xvori_b((__m256)v4u64_op0, 0x63);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfefefefe3f800000, 0x0000000000000000,
                      0xfefefefe3f800000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfefefefeffe0e0e0, 0xe0e0e0e0e0e0e0e0,
                             0xfefefefeffe0e0e0, 0xe0e0e0e0e0e0e0e0};
  __m256i_out = __lasx_xvori_b((__m256)v4u64_op0, 0xe0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x6b6b6b6b6b6b6b6b, 0x6b6b6b6b6b6b6b6b,
                             0x6b6b6b6b6b6b6b6b, 0x6b6b6b6b6b6b6b6b};
  __m256i_out = __lasx_xvori_b((__m256)v4u64_op0, 0x6b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
