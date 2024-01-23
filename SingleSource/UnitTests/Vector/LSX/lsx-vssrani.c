#include "lsx_test_util.h"
#include <lsxintrin.h>

int
main ()
{
  __m128i __m128i_out, __m128i_result;
  __m128  __m128_out, __m128_result;
  __m128d __m128d_out, __m128d_result;
  v2u64 v2u64_op0, v2u64_op1, v2u64_op2;
  v4i32 v4i32_op0, v4i32_op1, v4i32_op2;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00001802041b0013, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000007f7f02, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffefffefffffffc, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x00000000ffffffff};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ff0000000000000, 0x7ff0000000000000};
  v2u64_op1 = (v2u64){0xfe00fd1400010000, 0xfc01fd1300000001};
  __m128i_result = (__m128i){0x8080000180800100, 0x7f0000007f000000};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fefefe6a, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x000000000000fbf9};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000100010001};
  v2u64_op1 = (v2u64){0x007b01ec007b3a9e, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff39ff37ff35ff33, 0x21011f3f193d173b};
  v2u64_op1 = (v2u64){0x000000000000e41b, 0x0000000015d926c7};
  __m128i_result = (__m128i){0x00000000000000ff, 0x00000000ffffffff};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0101010101010101, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x000000007f7f7f7f};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ffffffe0, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000fff0, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000005, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000004, 0xffc0ff80ff800000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffff0000000000};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x9c7c266e3faa293c, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000000f3040705};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x084d1a0907151a3d};
  v2u64_op1 = (v2u64){0x000007d07fffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000000000ff, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000010000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000007fff};
  __m128i_out = __lsx_vssrani_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000040, 0x0000000000000040};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000004000000040};
  __m128i_out = __lsx_vssrani_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff1aff6d48ce567f, 0xff1afffefec0ec85};
  v2u64_op1 = (v2u64){0xffff80c1ffffe8de, 0xffff80c400000148};
  __m128i_result = (__m128i){0xffff0000ffffffff, 0xffe3ffd8ffe30919};
  __m128i_out = __lsx_vssrani_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7f0000fd7f0000fd, 0x7f7f7f7f00107f04};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x7fffffff7fffffff};
  __m128i_out = __lsx_vssrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000fe00fd, 0xc39fffff007fffff};
  __m128i_result = (__m128i){0xfffff0e700000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x32);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000001ffffff29, 0x00000000000000c0};
  __m128i_result = (__m128i){0x000000183fffffe5, 0x0000000020000000};
  __m128i_out = __lsx_vssrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0f000d200e000c20, 0x11000f2010000e20};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x7fffffff7fffffff};
  __m128i_out = __lsx_vssrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000c0c0c0c0, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x0014000100000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x35);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x28);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00005e96ffffb402, 0x0000000000005e94};
  v2u64_op1 = (v2u64){0x7fff7fff7fff7fff, 0x00fe000100cf005f};
  __m128i_result = (__m128i){0x0001fc0000fffeff, 0x00000000000000bd};
  __m128i_out = __lsx_vssrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x27);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000014, 0x0002000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000ffff00000000};
  __m128i_result = (__m128i){0x0007fff800000000, 0x0010000000000000};
  __m128i_out = __lsx_vssrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x9611c3985b3159f5, 0x86dd8341b164f12b};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xff86dd83ff9611c3};
  __m128i_out = __lsx_vssrani_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x28);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff7fffffffffffff, 0xff7fffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xfffffffffff7ffff};
  __m128i_out = __lsx_vssrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x64);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x47);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fff7fc01, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xc72df14afbfafdf9, 0x82c539ffffffffff};
  __m128i_result = (__m128i){0x8000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x23);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffff0000000000};
  __m128i_out = __lsx_vssrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x18);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0a000a000a000a00, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffff46, 0xfffffffffffffffe};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffff7777ffff7777, 0x0000777777777777};
  __m128i_result = (__m128i){0x000003bbbbbbbbbb, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x45);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x377b810912c0e000, 0x98147a504d145000};
  v2u64_op1 = (v2u64){0x377b810912c0e000, 0x98147a504d145000};
  __m128i_result = (__m128i){0x8000000000000000, 0x8000000000000000};
  __m128i_out = __lsx_vssrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x14eb6a002a406a00, 0x0000000014eb54ab};
  __m128i_result = (__m128i){0x7fffffffffffffff, 0xe0001fffffffffff};
  __m128i_out = __lsx_vssrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000080000000, 0x8000000080000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffff80000000};
  __m128i_out = __lsx_vssrani_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x60);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000301de01fe01fe, 0x00cf01fe01fe01fe};
  v2u64_op1 = (v2u64){0xfffc002000000000, 0x3ff0000000000000};
  __m128i_result = (__m128i){0x0f00000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000080000000000, 0x0000080000000000};
  __m128i_result = (__m128i){0x00ff000000ff0000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000080000068, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000040033, 0x0000000000038003};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff913bb9951901, 0x00680486ffffffda};
  v2u64_op1 = (v2u64){0x387c7e0a133f2000, 0x67157b5100005000};
  __m128i_result = (__m128i){0x0c0f000a070f0204, 0x0000000000000003};
  __m128i_out = __lsx_vssrani_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x3b2c8aefd44be966, 0x2e2b34ca59fa4c88};
  __m128i_result = (__m128i){0x2e34594c3b000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff000000000000, 0xffff000000000000};
  v2u64_op1 = (v2u64){0xffff000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_bu_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0xffffffff00000000};
  v2u64_op1 = (v2u64){0xffffff0000010000, 0xffffffff00000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x7f007f007f007f00};
  v2u64_op1 = (v2u64){0x000000030000003f, 0x7fff7fff7fff7fff};
  __m128i_result = (__m128i){0xffffffff0003003f, 0xffffffff00000000};
  __m128i_out = __lsx_vssrani_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x17483c07141b5971, 0x6a5d5b056f2f4978};
  __m128i_result = (__m128i){0xd4bade5e2e902836, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0010001000100010, 0x0010001000000010};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x1000000010001000};
  __m128i_out = __lsx_vssrani_hu_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0004007c00fc0000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00003f80000000ff, 0x00000000000000ff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000000ffffffff};
  __m128i_out = __lsx_vssrani_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffee00000004, 0xffffffff00000001};
  v2u64_op1 = (v2u64){0x3a3a00003a3a0000, 0x3a3a3a3b3a3a3a3a};
  __m128i_result = (__m128i){0x0000003a0000003a, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x38);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xfffffffffffffffe};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xf9796558e39953fd, 0xd3259a2984048c23};
  v2u64_op1 = (v2u64){0x4040000041410101, 0x1010111105050000};
  __m128i_result = (__m128i){0x0000808000020200, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1313131313131313, 0x1313131313131313};
  v2u64_op1 = (v2u64){0xd73691661e5b68b4, 0x34947b4b11684f92};
  __m128i_result = (__m128i){0xffffffff00000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vssrani_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000f8a40000f310, 0xfffaf1500000fffa};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000000000003e2};
  __m128i_out = __lsx_vssrani_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x26);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x27b1b106b8145f50, 0xf654ad7447e59090};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_wu_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe31c86e90cda86f7, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000000000000e3};
  __m128i_out = __lsx_vssrani_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x38);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ff00ff00ff00ff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000000000007f8};
  __m128i_out = __lsx_vssrani_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000001fff9fffa, 0x00000001fff9fff9};
  __m128i_result = (__m128i){0x007ffe7ffe400000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc485edbcc0000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000001};
  __m128i_result = (__m128i){0x0000000000010000, 0x000000000000c485};
  __m128i_out = __lsx_vssrani_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x30);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00001fff00001fff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000007ffc000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7fff7fff7fff7fff, 0x00fe000100cf005f};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000010000fffb, 0x00000002fffffffb};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000000bffffffe};
  __m128i_out = __lsx_vssrani_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x42);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000158, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x79);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x30);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ff800000, 0xfff8ffa2fffdffb0};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vssrani_du_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x50);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
