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

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000,
                      0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000,
                         0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfadd_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000002, 0x00000000, 0x00000001, 0xffffffff,
                      0x00000002, 0x00000000, 0x00000001, 0xffffffff};
  v8i32_result = (v8i32){0x00000002, 0x00000000, 0x00000001, 0xffffffff,
                         0x00000002, 0x00000000, 0x00000001, 0xffffffff};
  __m256_out = __lasx_xvfadd_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfadd_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000,
                      0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000,
                      0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000,
                         0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfadd_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x50005000, 0x30313031, 0x40b2bf4d,
                      0x00000000, 0x50005000, 0x30313031, 0x40b2bf4d};
  v8i32_op1 = (v8i32){0xa2bea2be, 0x7fff7fff, 0x22be22be, 0x00000000,
                      0xa2bea2be, 0x7fff7fff, 0x22be22be, 0x00000000};
  v8i32_result = (v8i32){0xa2bea2be, 0x7fff7fff, 0x30313031, 0x40b2bf4d,
                         0xa2bea2be, 0x7fff7fff, 0x30313031, 0x40b2bf4d};
  __m256_out = __lasx_xvfadd_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0xffffffff, 0x00ff0000, 0x00000000, 0x00000000,
                      0xffffffff, 0x00ff0000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0x00ff0000, 0x00000000, 0x00000000,
                         0xffffffff, 0x00ff0000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfadd_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x0000008c, 0x00000000, 0x00000000, 0x00000000,
                      0x0000008c, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x0000008c, 0x00000000, 0x00000000, 0x00000000,
                      0x0000008c, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000118, 0x00000000, 0x00000000, 0x00000000,
                         0x00000118, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfadd_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffff8000, 0xffffffff, 0x00000000, 0x00000000,
                      0xffff8000, 0xffffffff, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffff8000, 0xffffffff, 0x00000000, 0x00000000,
                         0xffff8000, 0xffffffff, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfadd_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000001, 0xffff0101, 0x00000000, 0x00000000,
                      0x00000001, 0xffff0101, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000001, 0xffff0101, 0x00000000, 0x00000000,
                         0x00000001, 0xffff0101, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfadd_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x007fe268, 0x00000000, 0xffff001f, 0x00000000,
                      0x007fe268, 0x00000000, 0xffff001f, 0x00000000};
  v8i32_op1 = (v8i32){0x007fe268, 0x00000000, 0xffff001f, 0x00000000,
                      0x007fe268, 0x00000000, 0xffff001f, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0xffff001f, 0x00000000,
                         0x00000000, 0x00000000, 0xffff001f, 0x00000000};
  __m256_out = __lasx_xvfsub_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0xffffffff, 0xffffffff,
                      0x00000000, 0x00000000, 0xffffffff, 0xffffffff};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0xffffffff, 0xffffffff,
                         0x00000000, 0x00000000, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfsub_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000,
                      0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  v8i32_result = (v8i32){0xff800000, 0xff800000, 0xff800000, 0xff800000,
                         0xff800000, 0xff800000, 0xff800000, 0xff800000};
  __m256_out = __lasx_xvfsub_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x02a54290, 0x00000000, 0x00000000, 0x00000000,
                      0x02a54290, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000089, 0x00000000, 0x02a54290, 0x00000000,
                      0x0154dc84, 0x00000000, 0x02a54290, 0x00000000};
  v8i32_result = (v8i32){0x02a54287, 0x00000000, 0x82a54290, 0x00000000,
                         0x028aa700, 0x00000000, 0x82a54290, 0x00000000};
  __m256_out = __lasx_xvfsub_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfsub_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x607f0000, 0x5fff5fff, 0x80000000, 0x00004200,
                      0x607f0000, 0x5fff5fff, 0x80000000, 0x00004200};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x607f0000, 0x5fff5fff, 0x80000000, 0x00004200,
                         0x607f0000, 0x5fff5fff, 0x80000000, 0x00004200};
  __m256_out = __lasx_xvfsub_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfsub_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfsub_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfsub_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000202, 0x00000000, 0x00800080, 0x00000000,
                      0x00000202, 0x00000000, 0x00800080, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000202, 0x00000000, 0x00800080, 0x00000000,
                         0x00000202, 0x00000000, 0x00800080, 0x00000000};
  __m256_out = __lasx_xvfsub_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xfffefffe, 0xfffefffe, 0xfffefffe, 0xfffefffe,
                      0xfffefffe, 0xfffefffe, 0xfffefffe, 0xfffefffe};
  v8i32_op1 = (v8i32){0x00003fef, 0x000023a3, 0x00003fff, 0x000023a3,
                      0x00003fef, 0x000023a3, 0x00003fff, 0x000023a3};
  v8i32_result = (v8i32){0xfffefffe, 0xfffefffe, 0xfffefffe, 0xfffefffe,
                         0xfffefffe, 0xfffefffe, 0xfffefffe, 0xfffefffe};
  __m256_out = __lasx_xvfsub_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfmul_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmul_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x11111112, 0x11111112, 0x00000000, 0x00000000,
                      0x10101011, 0x10101011, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmul_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00020000, 0x00040000, 0x00060000,
                      0x00000000, 0x00020000, 0x00040000, 0x00060000};
  v8i32_op1 = (v8i32){0x00000000, 0x00020000, 0x00040000, 0x00060000,
                      0x00000000, 0x00020000, 0x00040000, 0x00060000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmul_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmul_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0xffffffff,
                      0xffffffff, 0xffffffff, 0x00000000, 0xffffffff};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0xffffffff,
                         0xffffffff, 0xffffffff, 0x00000000, 0xffffffff};
  __m256_out = __lasx_xvfmul_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x000000ff, 0x000000ff, 0x00000000, 0x00000000,
                      0x000000ff, 0x000000ff, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000101, 0x00000101, 0x00000000, 0x00000000,
                      0x00000101, 0x00000101, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmul_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0x002a542a, 0x00000000, 0x00000000, 0x00000000,
                      0x002a542a, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfdiv_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000001, 0x00000001,
                      0x00000000, 0x00000000, 0x00000001, 0x00000001};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7fc00000, 0x7fc00000, 0x7f800000, 0x7f800000,
                         0x7fc00000, 0x7fc00000, 0x7f800000, 0x7f800000};
  __m256_out = __lasx_xvfdiv_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00fe00fe, 0x00fe00fe, 0x00fe00fe, 0x00fe00fe,
                      0x00fe00fe, 0x00fe00fe, 0x00fe00fe, 0x00fe00fe};
  v8i32_op1 = (v8i32){0x00fe00fe, 0x00fe00fe, 0x00fe00fe, 0x00fe00fe,
                      0x00fe00fe, 0x00fe00fe, 0x00fe00fe, 0x00fe00fe};
  v8i32_result = (v8i32){0x3f800000, 0x3f800000, 0x3f800000, 0x3f800000,
                         0x3f800000, 0x3f800000, 0x3f800000, 0x3f800000};
  __m256_out = __lasx_xvfdiv_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7fc00000, 0x7fc00000, 0x7fc00000, 0x7fc00000,
                         0x7fc00000, 0x7fc00000, 0x7fc00000, 0x7fc00000};
  __m256_out = __lasx_xvfdiv_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x1f636003, 0x803f6004, 0x00000000, 0x00000000,
                      0x1f636003, 0x803f6004, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00c70106, 0x007f0107, 0x00000000, 0x00000000,
                      0x00c70106, 0x007f0107, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x5e123f94, 0xbeff7cfd, 0x7fc00000, 0x7fc00000,
                         0x5e123f94, 0xbeff7cfd, 0x7fc00000, 0x7fc00000};
  __m256_out = __lasx_xvfdiv_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00200028, 0x00000008, 0x60601934, 0x00000008,
                      0x00200028, 0x00000008, 0x60601934, 0x00000008};
  v8i32_op1 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfdiv_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  return 0;
}
