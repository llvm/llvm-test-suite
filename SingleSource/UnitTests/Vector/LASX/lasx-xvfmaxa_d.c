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

  v4u64_op0 = (v4u64){0x0000000000000000, 0x000000040000fff8,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x000000040000fff8,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmaxa_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffff8001, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmaxa_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000018,
                      0x0000000000000000, 0x0000000000000018};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000018,
                         0x0000000000000000, 0x0000000000000018};
  __m256d_out = __lasx_xvfmaxa_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0002000000010000, 0x0002000000020000,
                      0x0002000000010000, 0x0002000000020000};
  v4u64_op1 = (v4u64){0xfff0000000000000, 0x8000000000000000,
                      0xfff0000000000000, 0x8000000000000000};
  v4u64_result = (v4u64){0xfff0000000000000, 0x0002000000020000,
                         0xfff0000000000000, 0x0002000000020000};
  __m256d_out = __lasx_xvfmaxa_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmaxa_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000001,
                      0x0000000000000001, 0x0000000000000001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000001, 0x0000000000000001,
                         0x0000000000000001, 0x0000000000000001};
  __m256d_out = __lasx_xvfmaxa_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fffffffffffffff, 0x7fffffffffffffff,
                      0x7fffffffffffffff, 0x7fffffffffffffff};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmaxa_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000008000000080, 0x0000008000000080,
                      0x0000008000000080, 0x0000008000000080};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmina_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfefefefefefefefe, 0xfefefefefefefefe,
                      0xfefefefefefefefe, 0xfefefefefefefefe};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmina_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000100, 0x0000000000000000,
                      0x0000000000000100, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmina_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmina_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffb2f600006f48, 0x0000000100000001,
                      0xffffb2f600006f48, 0x0000000100000001};
  v4u64_op1 = (v4u64){0x00000000000000ff, 0x0000000000000000,
                      0x00000000000000ff, 0x0000000000000000};
  v4u64_result = (v4u64){0x00000000000000ff, 0x0000000000000000,
                         0x00000000000000ff, 0x0000000000000000};
  __m256d_out = __lasx_xvfmina_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7efefefe80ffffff, 0x0000000000000000,
                      0x7efefefe80ffffff, 0xffffffffffff8000};
  v4u64_op1 = (v4u64){0x7efefefe80ffffff, 0x0000000000000000,
                      0x7efefefe80ffffff, 0xffffffffffff8000};
  v4u64_result = (v4u64){0x7efefefe80ffffff, 0x0000000000000000,
                         0x7efefefe80ffffff, 0xffffffffffff8000};
  __m256d_out = __lasx_xvfmina_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0087ff87f807ff87,
                      0x0000000000000000, 0x0087ff87f807ff87};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmina_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  return 0;
}
