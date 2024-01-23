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
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000ffff, 0x0000000000000000,
                             0x000000000000ffff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffff00000001, 0xffffffffffff8001,
                      0xffffffff00000001, 0xffffffffffff8001};
  __m256i_result = (__m256i){0xfffffff0ffff0000, 0x0000000000000000,
                             0xfffffff0ffff0000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffffffffff, 0x0000000000000000,
                      0x7fffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fffffffffffffff, 0x0000000000000000,
                      0x7fffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000001ffffff, 0x0000000001ffffff,
                             0x0000000001ffffff, 0x0000000001ffffff};
  __m256i_out = __lasx_xvssrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000ffffffff,
                      0x0000000000000000, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000ffff00000000,
                             0x0000000000000000, 0x0000ffff00000000};
  __m256i_out = __lasx_xvssrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000300000005fe, 0x00000000ffffff02,
                      0x00000300000005fe, 0x00000000fffffe02};
  v4u64_op1 = (v4u64){0xff00fe00feff02ff, 0x0000000001fffeff,
                      0x0007fd00000f02ff, 0x0000000000ff00ff};
  __m256i_result = (__m256i){0x000000ffffffff00, 0x0000ffff00000000,
                             0x0000000000ff0000, 0x0000ffff00000000};
  __m256i_out = __lasx_xvssrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000007f007f007f, 0x0000000000000000,
                      0x0000007f007f007f, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000005e80, 0x0af57272788754ab,
                      0x0000000000005e80, 0x0af57272788754ab};
  __m256i_result = (__m256i){0x7f7f7f7f0000007f, 0x00000000000f0f0f,
                             0x7f7f7f7f0000007f, 0x00000000000f0f0f};
  __m256i_out = __lasx_xvssrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000ff80, 0x0000000000000000,
                      0x0000000000000002, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000000ff, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff0000ffff0000, 0x0000000000000000,
                      0xffff0000ffff0000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fffffff7fffffff, 0x0000000000000000,
                      0x7fffffff7fffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000007fff7fff, 0x0000000080008000,
                             0x000000007fff7fff, 0x0000000080008000};
  __m256i_out = __lasx_xvssrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010001, 0x0001000100010001,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0100010001000000, 0x0100010001000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0004000400040004, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0303030303020000, 0x0000000000000000,
                      0x0303030303020000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x000000007fff7fff,
                             0x0000000000000000, 0x000000007fff7fff};
  __m256i_out = __lasx_xvssrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00027fff000080fe, 0x00067fff00047fff,
                      0x00027fff000080fe, 0x00067fff00047fff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x067f047f027f0080,
                             0x0000000000000000, 0x067f047f027f0080};
  __m256i_out = __lasx_xvssrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1010101010101010, 0x0000000000000000,
                      0x1010101010101010, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000040404000, 0x0000000000000000,
                      0x0000000040404000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000404, 0x0000000001010101,
                             0x0000000000000404, 0x0000000001010101};
  __m256i_out = __lasx_xvssrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7efefefe80ffffff, 0x0000000000000000,
                      0x7efefefe80ffffff, 0xffffffffffff8000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x00000000003fffc0,
                             0xffffffffffffffff, 0xffffffff003fffc0};
  __m256i_out = __lasx_xvssrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000004000, 0x7f80780000000000,
                      0x0000000000004000, 0x7f80780000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x00000000f0000000,
                      0x0000000000000000, 0x00000000f0000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x1fe01e0000000000,
                             0x0000000000000000, 0x1fe01e0000000000};
  __m256i_out = __lasx_xvssrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x22);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000001, 0x0000000100000001,
                      0x0000000100000001, 0x0000000100000001};
  v4u64_op1 = (v4u64){0x0000000100000001, 0x0000000100000001,
                      0x0000000100000001, 0x0000000100000001};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000089, 0x0000000000000000,
                      0x000000000154dc84, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000c40086, 0x0000000000010000,
                      0x0000000000c40086, 0x0000000000010000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000002a54290, 0x0000000000000000,
                      0x0000000002a54290, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000ff0000, 0x0000000000000000,
                      0x0000000000ff0000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x39);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x4000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x000000007fffffff,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x32);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x408480007fff0000, 0x3eab77367fff4848,
                      0x408480007fff0000, 0x3eab77367fff4848};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000700000008,
                             0xffffffffffffffff, 0x0000000700000008};
  __m256i_out = __lasx_xvssrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc07f8000c07f8000, 0x0000000000000000,
                      0xc07f8000c07f8000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffffe00000001, 0xfffffffe00000001,
                      0xfffffffe00000001, 0xfffffffe00000001};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x00000000fff01fe0,
                             0xffffffffffffffff, 0x00000000fff01fe0};
  __m256i_out = __lasx_xvssrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000020202000, 0x0000000000000000,
                      0x0000000020202000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000001, 0x0000000000000100,
                      0x0000000000000001, 0x0000000000000100};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8000ffff0000ffff, 0x03fbfffc03fc07fc,
                      0x8000ffff0000ffff, 0x03fbfffc03fc07fc};
  __m256i_result = (__m256i){0x7fffffff80000000, 0x0000000000000000,
                             0x7fffffff80000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000fe, 0xff00000000000000,
                      0x00000000000000fe, 0xff00000000000000};
  v4u64_op1 = (v4u64){0x00007fff7fffffff, 0x0000000000000000,
                      0x00007fff7fffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x8000000000000000,
                             0x0000000000000000, 0x8000000000000000};
  __m256i_out = __lasx_xvssrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x37);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0x000000000000ffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x6300000000000000, 0xce7ffffffffffffe,
                      0x6300000000000000, 0xce7ffffffffffffe};
  __m256i_result = (__m256i){0xffffffff39ffffff, 0x0000000000000000,
                             0xffffffff39ffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xb5308001b72eaf12, 0x01fe000247639d9c,
                      0xb72e8001b72eaf12, 0x01fe8001b72e0001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x7fffffffffffffff,
                             0x0000000000000000, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvssrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x26);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000007f, 0x0000000000000000,
                      0x0000000000000002, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000002000000019, 0x000000200000001e,
                      0x0000002000000019, 0x0000002000000018};
  __m256i_result = (__m256i){0x000400000003c000, 0x0000000000000000,
                             0x0004000000030000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x33);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000004, 0x0000000000000004,
                      0x0000000000000004, 0x0000000000000004};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x2000000000000000,
                             0x0000000000000000, 0x2000000000000000};
  __m256i_out = __lasx_xvssrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fe1ffe0ffe1ffe0, 0x01ff0020ff1f001f,
                      0x7fe1ffe0ffe1ffe0, 0x01ff0020ff1f001f};
  __m256i_result = (__m256i){0x007fc0083fc7c007, 0x0000000000000000,
                             0x007fc0083fc7c007, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x42);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x01ffff4300ffff00, 0x0100010001000100,
                      0x01ffff4300ffff00, 0x0100010001000100};
  v4u64_op1 = (v4u64){0x0000004000000000, 0x0000000040004000,
                      0x0000004000000000, 0x0000000040004000};
  __m256i_result = (__m256i){0x0001000100000000, 0x7fffffffffffffff,
                             0x0001000100000000, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvssrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x6afc01000001ff00, 0x00000000fe96fe95,
                      0x6afc01000001ff00, 0x00000000fe96fe95};
  v4u64_op1 = (v4u64){0x000000010000ff00, 0x0000000000ff0000,
                      0x000000010000ff00, 0x0000000000ff0000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ff78ffc0, 0x00000000ff88ffc0,
                      0x00000000ff78ffc0, 0x00000000ff88ffc0};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000001ff1,
                             0x0000000000000000, 0x0000000000001ff1};
  __m256i_out = __lasx_xvssrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x53);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffc00fffffc00, 0x0000000000000000,
                      0xfffffc00fffffc00, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xff00ff007f007f00, 0xff00ff00ff00ff00,
                      0xff00ff007f007f00, 0xff00ff00ff00ff00};
  __m256i_result = (__m256i){0xc03fc03fc03fc03f, 0x000000000000003f,
                             0xc03fc03fc03fc03f, 0x000000000000003f};
  __m256i_out = __lasx_xvssrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff0000fffd0004, 0x0000ffff0002fffd,
                      0x0000ffff0002fffd, 0xffff0000fffd0004};
  v4u64_op1 = (v4u64){0xffff0000fffd0004, 0x0000ffff0002fffd,
                      0x0000ffff0002fffd, 0xffff0000fffd0004};
  __m256i_result = (__m256i){0x000000000000000f, 0x000000000000000f,
                             0xfffffffffffffff0, 0xfffffffffffffff0};
  __m256i_out = __lasx_xvssrani_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0400040004000400, 0x0400040004000400,
                      0x0400040004000400, 0x0400040004000400};
  v4u64_op1 = (v4u64){0xfffc0000fffc0000, 0xfffc0000fffc0000,
                      0xfffc0000fffc0000, 0xfffc0000fffc0000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrani_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff90000fff9fff9, 0xfff9fff9fff9fff9,
                      0xfff90000fff9fff9, 0xfff9fff9fff9fff9};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x6906e68064f3d78b, 0xd04752cdd5543b56,
                      0x6906e68064f3d78b, 0xd04752cdd5543b56};
  v4u64_op1 = (v4u64){0x0000000004560420, 0x0000000000ff1100,
                      0x0000000004560420, 0x0000000000ff1100};
  __m256i_result = (__m256i){0x00000fff00004542, 0x00ff00ffff00ff00,
                             0x00000fff00004542, 0x00ff00ffff00ff00};
  __m256i_out = __lasx_xvssrani_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000000000ff,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000100000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7f8000007f800000, 0x7f8000007f800000,
                      0x7f8000007f800000, 0x7f8000007f800000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0f000f000f000f00,
                             0x0000000000000000, 0x0f000f000f000f00};
  __m256i_out = __lasx_xvssrani_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0404000004040000, 0x0404000004040000,
                      0x0404000004040000, 0x0404000004040000};
  v4u64_op1 = (v4u64){0x0404000004040000, 0x0404000004040000,
                      0x0404000004040000, 0x0404000004040000};
  __m256i_result = (__m256i){0x4000400040004000, 0x4000400040004000,
                             0x4000400040004000, 0x4000400040004000};
  __m256i_out = __lasx_xvssrani_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000007f433c78, 0x0000000000000000,
                      0x000000007f433c78, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000ffff, 0x0000000000000000,
                             0x000000000000ffff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fff80007fff0000, 0x0000000000000000,
                      0x7fff80007fff0000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7f057f0b7f5b007f, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000007f007f5, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000fb0819280000, 0x0000c475ceb40000,
                      0x00000001fc000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x074132a240000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000000000c9,
                             0x00000000003a0200, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x7fff7fff05407fff,
                      0x0000000000000000, 0x7fff7fff05407fff};
  v4u64_op1 = (v4u64){0x0000000000007fff, 0x7fffffff7fffffff,
                      0x0000000000007fff, 0x7fffffff7fffffff};
  __m256i_result = (__m256i){0xffffffff00001fff, 0xffffffff00000000,
                             0xffffffff00001fff, 0xffffffff00000000};
  __m256i_out = __lasx_xvssrani_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x5b7f00ff5b7f00ff, 0xdf00000052a00000,
                      0x5b7f00ff5b7f00ff, 0xdf00000052a00000};
  v4u64_op1 = (v4u64){0x0040000000000000, 0x0000000000000000,
                      0x00c0000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000040000000, 0x0000ffffffffffff,
                             0x00000000c0000000, 0x0000ffffffffffff};
  __m256i_out = __lasx_xvssrani_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x000400030010000f, 0x0004000f00100003,
                      0x000400030010000f, 0x0004000f00100003};
  __m256i_result = (__m256i){0x0400100004001000, 0x0000000000000000,
                             0x0400100004001000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff0000000000080, 0xfff0000000000000,
                      0xfff0000000000080, 0xfff0000000000000};
  v4u64_op1 = (v4u64){0xffffffff00000000, 0xffffffffffffffff,
                      0xffffffff00000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x31);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8080808080808080, 0x8080808080808080,
                      0x8080808080808080, 0x8080808080808080};
  v4u64_op1 = (v4u64){0x0002000200020002, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x87c1135043408bba, 0x009c3e201e39e7e3,
                      0x87c1135043408bba, 0x009c3e201e39e7e3};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffff00000000,
                             0x0000000000000000, 0xffffffff00000000};
  __m256i_out = __lasx_xvssrani_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7f7f7f5c8f374980, 0x0001b0b1b4b5dd9f,
                      0x7f7f7f5c8f374980, 0x0001b0b1b4b5dd9f};
  v4u64_op1 = (v4u64){0xd0d8eecf383fdf0d, 0x0001000100010001,
                      0xd0d8eecf383fdf0d, 0x0001000100010001};
  __m256i_result = (__m256i){0x0000000100000000, 0x0000000100007f7f,
                             0x0000000100000000, 0x0000000100007f7f};
  __m256i_out = __lasx_xvssrani_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x30);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000b03f, 0x000000000000457d,
                      0x000000000000b03f, 0x000000000000457d};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ff80, 0x0000000000000000,
                      0x0000000000000002, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000002, 0x0000000000000000,
                      0x0000000000000002, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000100000000,
                      0x00000000ffffffff, 0x0000000000000001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x73);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x38f7414938f78830,
                      0x0000000000000000, 0x38f7414938f7882f};
  v4u64_op1 = (v4u64){0x0000801380f300fb, 0x0000000000000000,
                      0x0000801380f380fe, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000008, 0xffffffffffffffff,
                             0x0000000000000008, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrani_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000ffff, 0x000000000000ffff,
                      0x000000000000ffff, 0x000000000000ffff};
  __m256i_result = (__m256i){0x0000000000000007, 0x0000000000000000,
                             0x0000000000000007, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x59);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00817fff00810000, 0x007c7fff00007fff,
                      0x00817fff00810000, 0x007c7fff00007fff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x55);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000000, 0x0000000000000000,
                      0x0000000100000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000010,
                             0x0000000000000000, 0x0000000000000010};
  __m256i_out = __lasx_xvssrani_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000700000000, 0x00000005ffffffff,
                      0x0000000700000000, 0x00000005ffffffff};
  __m256i_result = (__m256i){0x0000000000000005, 0x0000000000000000,
                             0x0000000000000005, 0x0000000000000000};
  __m256i_out = __lasx_xvssrani_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x60);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0004000500040005, 0x0004000500040005,
                      0x0004000500040005, 0x0004000500040005};
  v4u64_op1 = (v4u64){0x0004000500040005, 0x0004000400040004,
                      0x0004000500040005, 0x0004000400040004};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrani_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
