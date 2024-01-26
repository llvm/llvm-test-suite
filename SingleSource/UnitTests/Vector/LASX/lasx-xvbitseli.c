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
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvbitseli_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x00000000000004fb, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x00000000000004fb, 0x0000000000000000};
  __m256i_out = __lasx_xvbitseli_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0xef);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvbitseli_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0xcd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000040400000104, 0x0000000000000004,
                      0x0000441000000004, 0xffffd10000006459};
  v4u64_op1 = (v4u64){0xdb8e209d0cce025a, 0x0000007fff01ffff,
                      0xdb8a3109fe0f0024, 0xdb801b6d0962003f};
  __m256i_result = (__m256i){0xdb8e20990cce025a, 0x0000007fff01fffb,
                             0xdb8a3109fe0f0020, 0x88888a6d0962002e};
  __m256i_out = __lasx_xvbitseli_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x88);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x000000002b902b3e,
                      0x0000000000000000, 0x000000002b902b3e};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x000000002a102a3a,
                             0x0000000000000000, 0x000000002a102a3a};
  __m256i_out = __lasx_xvbitseli_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvbitseli_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf0f0f0f0f0f0f0f0, 0x00000000f0f0f0f0,
                      0xf0f0f0f0f0f0f0f0, 0x00000000f0f0f0f0};
  v4u64_op1 = (v4u64){0xf0f0f0f0f0f0f0f0, 0x00000000f0f0f0f0,
                      0xf0f0f0f0f0f0f0f0, 0x00000000f0f0f0f0};
  __m256i_result = (__m256i){0x9090909090909090, 0x0000000090909090,
                             0x9090909090909090, 0x0000000090909090};
  __m256i_out = __lasx_xvbitseli_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x95);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x5555555555555555, 0x5555555555555555,
                      0x5555555555555555, 0x5555555555555555};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x4545454545454545, 0x4545454545454545,
                             0x4545454545454545, 0x4545454545454545};
  __m256i_out = __lasx_xvbitseli_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf9f9f9f9f9f9f9f9, 0xf9f9f9f9f9f9f9f9,
                      0xf9f9f9f9f9f9f9f9, 0xf9f9f9f9f9f9f9f9};
  v4u64_op1 = (v4u64){0x01bf481000000000, 0x21bb481000ff0000,
                      0x01bf481000000000, 0x21bb481000ff0000};
  __m256i_result = (__m256i){0xb1b7b1b1b1b1b1b1, 0xb1b3b1b1b1b7b1b1,
                             0xb1b7b1b1b1b1b1b1, 0xb1b3b1b1b1b7b1b1};
  __m256i_out = __lasx_xvbitseli_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc03fc03fc03fc03f, 0x000000000000003f,
                      0xc03fc03fc03fc03f, 0x000000000000003f};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xc02dc02dc02dc02d, 0x000000000000002d,
                             0xc02dc02dc02dc02d, 0x000000000000002d};
  __m256i_out = __lasx_xvbitseli_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0xed);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x00000000ffff0000,
                      0x0000000000000000, 0x00000000ffff0000};
  __m256i_result = (__m256i){0x6060000000000000, 0x60600000ffff0000,
                             0x6060000000000000, 0x60600000ffff0000};
  __m256i_out = __lasx_xvbitseli_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x60);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
