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

  v4u64_op0 = (v4u64){0x0000000000005e02, 0x0000000000000000,
                      0x0000000000005e02, 0x0000000000000000};
  __m256i_result = (__m256i){0xc2c2c2c2c2c29cc0, 0xc2c2c2c2c2c2c2c2,
                             0xc2c2c2c2c2c29cc0, 0xc2c2c2c2c2c2c2c2};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0xc2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x161616167fffffff, 0x7ffe16167f161616,
                      0x161616167fffffff, 0x1616161616161616};
  __m256i_result = (__m256i){0xc7c7c7c7ae2e2e2e, 0xae2fc7c7aec7c7c7,
                             0xc7c7c7c7ae2e2e2e, 0xc7c7c7c7c7c7c7c7};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0xd1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x5353535353535353, 0x5353535353535353,
                             0x5353535353535353, 0x5353535353535353};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0x53);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x6d6d6d6d6d6d6d6d, 0x6d6d6d6d6d6d6d6d,
                             0x6d6d6d6d6d6d6d6d, 0x6d6d6d6d6d6d6d6d};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0x6d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x8e8e8e8e8e8e8e8e, 0x7171717171717171,
                             0x8e8e8e8e8e8e8e8e, 0x7171717171717171};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0x71);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7575757575757575, 0x7575757575757575,
                             0x7575757575757575, 0x7575757575757575};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0x75);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xa4a4a4a4a4a4a4a4, 0xa4a4a4a4a4a4a4a4,
                             0xa4a4a4a4a4a4a4a4, 0xa4a4a4a4a4a4a4a4};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0xa4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xa1a1a1a15e5e5e5e, 0xa1a1a1a1a1a1a1a1,
                             0xa1a1a1a15e5e5e5e, 0xa1a1a1a1a1a1a1a1};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0xa1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff00000000, 0x0000ffff0000ffff,
                      0x0000ffff00000000, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x8d8d72728d8d8d8d, 0x8d8d72728d8d7272,
                             0x8d8d72728d8d8d8d, 0x8d8d72728d8d7272};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0x8d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xb3b3b3b3b3b3b3b3, 0xb3b3b3b3b3b3b3b3,
                             0xb3b3b3b3b3b3b3b3, 0xb3b3b3b3b3b3b3b3};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0x4c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007f0000ff807f81, 0xffffffffff800000,
                      0x007f0000ff807f81, 0xffffffffff800000};
  __m256i_result = (__m256i){0xa2dda2a25d22dd23, 0x5d5d5d5d5d22a2a2,
                             0xa2dda2a25d22dd23, 0x5d5d5d5d5d22a2a2};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0xa2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xd3d3d3d3d3d3d3d3, 0xd3d3d3d3d3d3d3d3,
                             0xd3d3d3d3d3d3d3d3, 0xd3d3d3d3d3d3d3d3};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0xd3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfa15fa15fa15fa14, 0xffffffffffffffff,
                      0xfa15fa15fa15fa14, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x8768876887688769, 0x8282828282828282,
                             0x8768876887688769, 0x8282828282828282};
  __m256i_out = __lasx_xvxori_b((__m256)v4u64_op0, 0x7d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
