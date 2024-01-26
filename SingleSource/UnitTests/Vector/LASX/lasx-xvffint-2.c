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

  v4u64_op0 = (v4u64){0xffffe651ffffbfff, 0xffffffffffffffff,
                      0xffffbf7f00007fff, 0xffffffffffffffff};
  v8i32_result = (v8i32){0x4f7fffc0, 0x4f7fffe6, 0x4f800000, 0x4f800000,
                         0x46fffe00, 0x4f7fffbf, 0x4f800000, 0x4f800000};
  __m256_out = __lasx_xvffint_s_wu((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0101010101010101,
                      0xfffffffffffffefd, 0x0101010101010101};
  v8i32_result = (v8i32){0x4f800000, 0x4f800000, 0x4b808080, 0x4b808080,
                         0x4f7fffff, 0x4f800000, 0x4b808080, 0x4b808080};
  __m256_out = __lasx_xvffint_s_wu((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvffint_s_wu((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvffint_s_wu((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000008, 0x0000000000000008,
                      0x0000000000000008, 0x0000000000000008};
  v8i32_result = (v8i32){0x41000000, 0x00000000, 0x41000000, 0x00000000,
                         0x41000000, 0x00000000, 0x41000000, 0x00000000};
  __m256_out = __lasx_xvffint_s_wu((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000020, 0x0000000000000040,
                      0x0000000000000020, 0x0000000000000040};
  v8i32_result = (v8i32){0x42000000, 0x00000000, 0x42800000, 0x00000000,
                         0x42000000, 0x00000000, 0x42800000, 0x00000000};
  __m256_out = __lasx_xvffint_s_wu((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvffint_s_wu((__m256)v4u64_op0);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101000000000000, 0x0000000000000000,
                      0x0101000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x4370100000000000, 0x0000000000000000,
                         0x4370100000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_lu((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_lu((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_lu((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x2020202020206431, 0x2020202020202020,
                      0x2020202020206431, 0x2020202020202020};
  v4u64_result = (v4u64){0x43c0101010101032, 0x43c0101010101010,
                         0x43c0101010101032, 0x43c0101010101010};
  __m256d_out = __lasx_xvffint_d_lu((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x80ce32be3e827f00, 0x40efffe09fa7e358,
                      0x6b07ca8e013fbf01, 0x40efffe09fa88260};
  v4u64_result = (v4u64){0x43e019c657c7d050, 0x43d03bfff827e9f9,
                         0x43dac1f2a3804ff0, 0x43d03bfff827ea21};
  __m256d_out = __lasx_xvffint_d_lu((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_result = (v4u64){0x43f0000000000000, 0x43f0000000000000,
                         0x43f0000000000000, 0x43f0000000000000};
  __m256d_out = __lasx_xvffint_d_lu((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000000, 0x0000000100000000,
                      0x0000000100000000, 0x0000000100000000};
  v4u64_result = (v4u64){0x41f0000000000000, 0x41f0000000000000,
                         0x41f0000000000000, 0x41f0000000000000};
  __m256d_out = __lasx_xvffint_d_lu((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_lu((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0202010202020102, 0x0202010202020102,
                      0x0202010202020102, 0x0202010202020102};
  v4u64_result = (v4u64){0x4380100810101008, 0x4380100810101008,
                         0x4380100810101008, 0x4380100810101008};
  __m256d_out = __lasx_xvffint_d_lu((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_lu((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x41f0000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvffint_d_lu((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  return 0;
}
