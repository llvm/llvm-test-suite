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

  v8i32_op0 = (v8i32){0x00000000, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_result = (v8i32){0x00000000, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
                         0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrecip_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0000ff00, 0x00000000, 0x00000000, 0x00000000,
                      0x000000ff, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
                         0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrecip_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfrecip_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
                         0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrecip_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
                         0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrecip_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xfc00fc00, 0x00000000, 0xfc000000, 0xfc003802,
                      0xfc00fc00, 0x00000000, 0xfc000000, 0xfc003802};
  v8i32_result = (v8i32){0x82fe0bd9, 0x7f800000, 0x83000000, 0x82ff902d,
                         0x82fe0bd9, 0x7f800000, 0x83000000, 0x82ff902d};
  __m256_out = __lasx_xvfrecip_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
                         0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrecip_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
                         0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrecip_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xfd02fd02, 0xfd02fd02, 0xfd02fd02, 0xfd02fd02,
                      0xfd02fd02, 0xfd02fd02, 0xfd02fd02, 0xfd02fd02};
  v8i32_result = (v8i32){0x81fa28e4, 0x81fa28e4, 0x81fa28e4, 0x81fa28e4,
                         0x81fa28e4, 0x81fa28e4, 0x81fa28e4, 0x81fa28e4};
  __m256_out = __lasx_xvfrecip_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0000ffff, 0x00000000, 0x00000000, 0x00000000,
                      0x0000ff80, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x60b5054d, 0x7f800000, 0x7f800000, 0x7f800000,
                         0x60b53246, 0x7f800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0060005a, 0xffffffff, 0xffffffff, 0xffffffff,
                      0x0060005a, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_result = (v8i32){0x5f13ccf5, 0xffffffff, 0xffffffff, 0xffffffff,
                         0x5f13ccf5, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfrsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
                         0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
                         0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
                         0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
                         0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
                         0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000008, 0x00000002, 0x00000000, 0x00000000,
                      0x00000008, 0x00000002, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x64000000, 0x64800000, 0x7f800000, 0x7f800000,
                         0x64000000, 0x64800000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xfef907bc, 0x000000bd, 0x00000000, 0x00000000,
                      0xfef907bc, 0x000000bd, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7fc00000, 0x62d2acee, 0x7f800000, 0x7f800000,
                         0x7fc00000, 0x62d2acee, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfrsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfrsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x132feea9, 0x18181818, 0x04e8296f,
                      0x00000000, 0x132feea9, 0x18181818, 0x04e8296f};
  v8i32_result = (v8i32){0x7f800000, 0x559a674d, 0x53261036, 0x5cbe15f2,
                         0x7f800000, 0x559a674d, 0x53261036, 0x5cbe15f2};
  __m256_out = __lasx_xvfrsqrt_s((__m256)v8i32_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  return 0;
}
