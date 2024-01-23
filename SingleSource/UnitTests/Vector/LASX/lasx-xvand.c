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
  v4u64_op1 = (v4u64){0x0010001000100010, 0x0010001000100010,
                      0x0010001000100010, 0x0010001000100010};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvand_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvand_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvand_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x2020202020202020, 0x2020202020202020,
                      0x2020202020202020, 0x2020202020202020};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvand_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0x000000000000ffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvand_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvand_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xfefee00000000000,
                      0x0000000000000000, 0xfefee00000000000};
  v4u64_op1 = (v4u64){0xfffffffe00000001, 0xfffffffe00000001,
                      0xfffffffe00000001, 0xfffffffe00000001};
  __m256i_result = (__m256i){0x0000000000000000, 0xfefee00000000000,
                             0x0000000000000000, 0xfefee00000000000};
  __m256i_out = __lasx_xvand_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000080000000, 0x00000004843ffdff,
                      0x8000000080000000, 0x00000004843ffdff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvand_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000ff, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c,
                      0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c};
  __m256i_result = (__m256i){0x000000000000001c, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvand_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
