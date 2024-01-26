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
  v4u64_op1 = (v4u64){0x7fffffff7fffffff, 0x0000000000000000,
                      0x7fffffff7fffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x7f0000007f000000, 0x0000000000000000,
                             0x7f0000007f000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffe0000000, 0xffffffffe0000000,
                      0xffffffffe0000000, 0xffffffffe0000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffff000000, 0xffffffffff000000,
                             0xffffffffff000000, 0xffffffffff000000};
  __m256i_out = __lasx_xvmax_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff0000000000000, 0xffffffffffffffff,
                      0x7ff0000000000000, 0x7ff0000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x7fff000000000000, 0x0000000000000000,
                             0x7fff000000000000, 0x7f00000000000000};
  __m256i_out = __lasx_xvmax_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0004000400040004, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0004000400040004, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x5980000000000000, 0x0000000000000000,
                      0x5980000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x5900000000000000, 0x0000000000000000,
                             0x5900000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00ffce20, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ffce20, 0x00ff00ff00ff00ff};
  v4u64_op1 = (v4u64){0x0000000004560408, 0x0000000000ee1100,
                      0x0000000004560408, 0x0000000000ee1100};
  __m256i_result = (__m256i){0x0000000004560420, 0x0000000000ff1100,
                             0x0000000004560420, 0x0000000000ff1100};
  __m256i_out = __lasx_xvmax_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000001ffffffff, 0x00000001ffffffff,
                      0x00000001ffffffff, 0x00000001ffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000100000000, 0x0000000100000000,
                             0x0000000100000000, 0x0000000100000000};
  __m256i_out = __lasx_xvmax_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000100, 0x0000000000000200,
                      0x0000000000000100, 0x0000000000000200};
  v4u64_op1 = (v4u64){0x0000000000000100, 0x0000000000000200,
                      0x0000000000000100, 0x0000000000000200};
  __m256i_result = (__m256i){0x0000000000000100, 0x0000000000000200,
                             0x0000000000000100, 0x0000000000000200};
  __m256i_out = __lasx_xvmax_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000007f433c78, 0x0000000000000000,
                      0x000000007f433c78, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000007f433c78, 0x0000000000000000,
                             0x000000007f433c78, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff01ff01ff01ff01, 0xff01ff01ff01ff01,
                      0xff01ff01ff01ff01, 0xff01ff01ff01ff01};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0001000100010001, 0x0001000100010001,
                             0x0001000100010001, 0x0001000100010001};
  __m256i_out = __lasx_xvmax_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000000000000, 0x0000000000000000,
                      0x8000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffce, 0x0000000000000000,
                      0x00000000ffffffce, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7ff0000000000000, 0x7ff0000000000000,
                             0x7ff0000000000000, 0x7ff0000000000000};
  __m256i_out = __lasx_xvmax_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                             0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  __m256i_out = __lasx_xvmax_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x4000000000000000, 0x4000000000000000,
                      0x4000000000000000, 0x4000000000000000};
  __m256i_result = (__m256i){0x4000000000000000, 0x4000000000000000,
                             0x4000000000000000, 0x4000000000000000};
  __m256i_out = __lasx_xvmax_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffff800080000000, 0xffff800000000000,
                      0xffff800080000000, 0xffff800000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000e0000000e, 0x0000000e0000000e,
                      0x0000000e0000000e, 0x0000000e0000000e};
  v4u64_op1 = (v4u64){0x0001000400010004, 0x0001000100010001,
                      0x0001000400010004, 0x0001000100010001};
  __m256i_result = (__m256i){0x0001000e0001000e, 0x0001000e0001000e,
                             0x0001000e0001000e, 0x0001000e0001000e};
  __m256i_out = __lasx_xvmax_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000ffff, 0x0080000000000002,
                      0x000000000000ffff, 0x0080000000000002};
  __m256i_result = (__m256i){0x0000000000000000, 0x0080000000000002,
                             0x0000000000000000, 0x0080000000000002};
  __m256i_out = __lasx_xvmax_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x1090918800000000,
                      0x0000000000000000, 0x1090918800000000};
  v4u64_op1 = (v4u64){0x0000000000004000, 0x1c80780000000000,
                      0x0000000000004000, 0x1c80780000000000};
  __m256i_result = (__m256i){0x0000000000004000, 0x1c80780000000000,
                             0x0000000000004000, 0x1c80780000000000};
  __m256i_out = __lasx_xvmax_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7,
                      0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0101010101010101, 0x0101010101010101,
                      0x0101010101010101, 0x0101010101010101};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010101,
                             0x0101010101010101, 0x0101010101010101};
  __m256i_out = __lasx_xvmax_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmax_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7f807f007f7f817f, 0x9ff87ef07f7f817f,
                      0x7f807f007f7f817f, 0x9ff87ef07f7f817f};
  __m256i_result = (__m256i){0x7f807f007f7f817f, 0x000000007f7f817f,
                             0x7f807f007f7f817f, 0x000000007f7f817f};
  __m256i_out = __lasx_xvmax_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x7fefffffffffffff,
                      0x0000000000000000, 0x7fefffffffffffff};
  v4u64_op1 = (v4u64){0xfffffebeeaaeeeeb, 0xfffffebeeaaefafb,
                      0xfffffebeeaaeeeeb, 0xfffffebeeaaefafb};
  __m256i_result = (__m256i){0x0000000000000000, 0x7fefffffffffffff,
                             0x0000000000000000, 0x7fefffffffffffff};
  __m256i_out = __lasx_xvmax_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xebebebebebebebeb, 0xebebebebebebebeb,
                      0xebebebebebebebeb, 0xebebebebebebebeb};
  v4u64_op1 = (v4u64){0x000000000000ff00, 0x0000000000000000,
                      0x000000000000ff00, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000ff00, 0x0000000000000000,
                             0x000000000000ff00, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fff00007fff0000, 0x0000000038ea4d4a,
                      0x7fff00007fff0000, 0x0000000038ea4d4a};
  __m256i_result = (__m256i){0x7fff00007fff0000, 0x0000000038ea4d4a,
                             0x7fff00007fff0000, 0x0000000038ea4d4a};
  __m256i_out = __lasx_xvmax_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffff97a2, 0x0000000000000000,
                      0x00000000ffff97a2, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmax_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffffbfffc, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000001000000010, 0x0000000000000000,
                      0x0000001000000010, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000001000000010, 0x0000000000000000,
                             0x0000001000000010, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0xffffffffffffffff,
                      0x00000000ffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x556caad9aabbaa88, 0x0000004a557baac4,
                      0x556caad9aabbaa88, 0x0000004a557baac4};
  __m256i_result = (__m256i){0x556caad9aabbaa88, 0x0000004a557baac4,
                             0x556caad9aabbaa88, 0x0000004a557baac4};
  __m256i_out = __lasx_xvmax_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000020006, 0x0000000000020006,
                      0x0000000000020006, 0x0000000000020006};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000020006, 0x0000000000020006,
                             0x0000000000020006, 0x0000000000020006};
  __m256i_out = __lasx_xvmax_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffff0000000d, 0xffffffff0000000f,
                      0xffffffff0000000d, 0xffffffff0000000f};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmax_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000080000000, 0x8000000080000000,
                      0x8000000080000000, 0x8000000080000000};
  v4u64_op1 = (v4u64){0xfffe97c020010001, 0xfffeb6839ffffd80,
                      0xfffe97c020010001, 0xfffeb6839ffffd80};
  __m256i_result = (__m256i){0xfffe97c020010001, 0xfffeb6839ffffd80,
                             0xfffe97c020010001, 0xfffeb6839ffffd80};
  __m256i_out = __lasx_xvmax_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
