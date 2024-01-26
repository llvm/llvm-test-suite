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

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0xffff00000000ffff, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0xffffffffbe8b470f, 0x7ffffffffffff7ff,
                      0xffffffffe06df0d7, 0x7ffffffffffff7ff};
  v4u64_result = (v4u64){0xffffffffbe8b470f, 0x7ffffffffffff7ff,
                         0xffff00000000ffff, 0x7ffffffffffff7ff};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x41d6600000000000,
                      0x0000000000000000, 0x41d6600000000000};
  v4u64_op1 = (v4u64){0x7fffffffffffffff, 0x0000000000000000,
                      0x7fffffffffffffff, 0x0000000000000000};
  v4u64_result = (v4u64){0x7fffffffffffffff, 0x41d6600000000000,
                         0x7fffffffffffffff, 0x41d6600000000000};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_result = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                         0xffffffffffffffff, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00007fff00007fff, 0x00007fff00007fff,
                      0x00007fff00007fff, 0x00007fff00007fff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x00007fff00007fff, 0x00007fff00007fff,
                         0x00007fff00007fff, 0x00007fff00007fff};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffa2beb040, 0x0000000022beb03f,
                      0x7fffffffa2beb040, 0x0000000022beb03f};
  v4u64_op1 = (v4u64){0x000f000000000000, 0x0000000000000000,
                      0x000f000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7fffffffa2beb040, 0x0000000022beb03f,
                         0x7fffffffa2beb040, 0x0000000022beb03f};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff7fff7fff7fff, 0x000001c000000134,
                      0x7fff7fff7fff7fff, 0x000001c000000134};
  v4u64_op1 = (v4u64){0x7fff7fff7fff7fff, 0x000001c000000134,
                      0x7fff7fff7fff7fff, 0x000001c000000134};
  v4u64_result = (v4u64){0x7fff7fff7fff7fff, 0x0000038000000268,
                         0x7fff7fff7fff7fff, 0x0000038000000268};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000405, 0x0000000001010100,
                      0x0000000000000405, 0x0000000001010100};
  v4u64_result = (v4u64){0x0000000000000405, 0x0000000001010100,
                         0x0000000000000405, 0x0000000001010100};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000040, 0x0000000000000040,
                      0x0000000000000040, 0x0000000000000040};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000040, 0x0000000000000040,
                         0x0000000000000040, 0x0000000000000040};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000040, 0x0000000000000040,
                      0x0000000000000040, 0x0000000000000040};
  v4u64_op1 = (v4u64){0x00000000ff78ffc0, 0x00000000ff88ffc0,
                      0x00000000ff78ffc0, 0x00000000ff88ffc0};
  v4u64_result = (v4u64){0x00000000ff790000, 0x00000000ff890000,
                         0x00000000ff790000, 0x00000000ff890000};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000010006d, 0x000000000000006d,
                      0x000000000010006d, 0x000000000000006d};
  v4u64_op1 = (v4u64){0x0000000000080040, 0x0000000000000040,
                      0x0000000000080040, 0x0000000000000040};
  v4u64_result = (v4u64){0x00000000001800ad, 0x00000000000000ad,
                         0x00000000001800ad, 0x00000000000000ad};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffffffffff, 0x0000000000000000,
                      0x7fffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x2020000000000000, 0x001fffffffe00000,
                      0x2020000000000000, 0x001fffffffe00000};
  v4u64_result = (v4u64){0x7fffffffffffffff, 0x001fffffffe00000,
                         0x7fffffffffffffff, 0x001fffffffe00000};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000001,
                      0x0000000000000001, 0x0000000000000001};
  v4u64_op1 = (v4u64){0xffffffffffff8000, 0x0000000000000000,
                      0xffffffffffff8000, 0x0000000000000000};
  v4u64_result = (v4u64){0xffffffffffff8000, 0x0000000000000001,
                         0xffffffffffff8000, 0x0000000000000001};
  __m256d_out = __lasx_xvfadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x00007ffe81fdfe03,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x80007ffe81fdfe03,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000001,
                      0x0000000000000001, 0x0000000000000001};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_result = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                         0xffffffffffffffff, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x41d8585858400000, 0xc1be9e9e9f000000,
                      0x41d8585858400000, 0xc1be9e9e9f000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_result = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                         0xffffffffffffffff, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xff00ffffff00ffff, 0xff00d5007f00ffff,
                      0xff00ffffff00ffff, 0xff00d5007f00ffff};
  v4u64_result = (v4u64){0x7f00ffffff00ffff, 0x7f00d5007f00ffff,
                         0x7f00ffffff00ffff, 0x7f00d5007f00ffff};
  __m256d_out = __lasx_xvfsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000002, 0xffffffffffffffff,
                      0xffffffff00000002, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xffffffff00000002, 0xffffffffffffffff,
                         0xffffffff00000002, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00fe00ff00fe, 0x0000ffff0000ffff,
                      0x00ff00fe00ff00fe, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x00ff00fe00ff00fe, 0x0000ffff0000ffff,
                         0x00ff00fe00ff00fe, 0x0000ffff0000ffff};
  __m256d_out = __lasx_xvfsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmul_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000100000001, 0x0000000400000001,
                      0x0000000100000001, 0x0000000400000001};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmul_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_result = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                         0xffffffffffffffff, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfmul_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000010100000000, 0x0000000000000000,
                      0x0000010100000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00390015003529c1, 0x00008000003f0000,
                      0x00390015003529c1, 0x00008000003f0000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmul_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfe00000000000000, 0x0000000001ffffff,
                      0xfe00000000000000, 0x0000000001ffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x8000000000000000, 0x0000000000000000,
                         0x8000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfmul_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x55555555aaaaaaac, 0x0000005536aaaaac,
                      0x55555555aaaaaaac, 0x0000005536aaaaac};
  v4u64_op1 = (v4u64){0x0002555400000000, 0x0006000000040000,
                      0x0002555400000000, 0x0006000000040000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x3f2c678e38d1104c,
                         0x7ff0000000000000, 0x3f2c678e38d1104c};
  __m256d_out = __lasx_xvfdiv_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffc3aaa8d58f43c8,
                      0x4f90000000000000, 0xffe367cc82f8989a};
  v4u64_op1 = (v4u64){0x7ff8000000000000, 0x1f0fdf7f3e3b31d4,
                      0x7ff8000000000000, 0x1f0fdf7f3e3b31d4};
  v4u64_result = (v4u64){0x7ff8000000000000, 0xfff0000000000000,
                         0x7ff8000000000000, 0xfff0000000000000};
  __m256d_out = __lasx_xvfdiv_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0010000000100000, 0x0010000000100000,
                      0x0010000000100000, 0x0010000000100000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000483800,
                      0x0000000000000000, 0x0000000000483800};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x41cc5bb8a95fd1eb,
                         0x7ff0000000000000, 0x41cc5bb8a95fd1eb};
  __m256d_out = __lasx_xvfdiv_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff8000000000000, 0x7ff8000000000000,
                         0x7ff8000000000000, 0x7ff8000000000000};
  __m256d_out = __lasx_xvfdiv_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff8000000000000, 0x7ff8000000000000,
                         0x7ff8000000000000, 0x7ff8000000000000};
  __m256d_out = __lasx_xvfdiv_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff8000000000000, 0x7ff8000000000000,
                         0x7ff8000000000000, 0x7ff8000000000000};
  __m256d_out = __lasx_xvfdiv_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff8000000000000, 0x7ff8000000000000,
                         0x7ff8000000000000, 0x7ff8000000000000};
  __m256d_out = __lasx_xvfdiv_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  return 0;
}
