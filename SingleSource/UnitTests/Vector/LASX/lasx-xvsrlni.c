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
  __m256i_out = __lasx_xvsrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000100000001,
                      0xffffffffffffffff, 0x0000000100000001};
  v4u64_op1 = (v4u64){0x7fff000000000000, 0x0000000000000000,
                      0x7fff000000000000, 0x7f00000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000001010101,
                             0x0000000000000000, 0x0000000001010101};
  __m256i_out = __lasx_xvsrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000200000034, 0x0000000000000000,
                      0xfffffc500000002d, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x5ff1f90ffffbf30f, 0xdf91f111808007fb,
                      0x1729c173836edfbe, 0xbfa3e127c147721f};
  __m256i_result = (__m256i){0xc88840fdf887fd87, 0x000000000001001a,
                             0xd193a30f94b9b7df, 0x00000000ff280016};
  __m256i_out = __lasx_xvsrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffc5556aaa8, 0x0000000000000000,
                      0xfffffffc5556aaa8, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x555555553f800000, 0x0000000000000000,
                      0x555555553f800000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000002020100, 0x0000000007070205,
                             0x0000000002020100, 0x0000000007070205};
  __m256i_out = __lasx_xvsrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00ff00ff, 0x0000000000000000,
                      0x00ff00ff00ff00ff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00ff00fe00ff00fe, 0x0000ffff0000ffff,
                      0x00ff00fe00ff00fe, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x00ff00ff07070707, 0x0000000007070707,
                             0x00ff00ff07070707, 0x0000000007070707};
  __m256i_out = __lasx_xvsrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x5980000000000000, 0x0000000000000000,
                      0x5980000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff00ffffff00ffff, 0xffffffffffffffff,
                      0xff00ffffff00ffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xff00ffffff00ffff, 0xffffffffffffffff,
                      0xff00ffffff00ffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffe01fe01f, 0xffffffffe01fe01f,
                             0xffffffffe01fe01f, 0xffffffffe01fe01f};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000fe01020b0001, 0xffffffffffffffff,
                      0x0000fe01020b0001, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0fff0fff00000020, 0x0000000000000000,
                             0x0fff0fff00000020, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x003f003f003f003f,
                             0x0000000000000000, 0x003f003f003f003f};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffa0078fffa0074, 0xfffefffefffefffe,
                      0xfffa0078fffa0074, 0xfffefffefffefffe};
  v4u64_op1 = (v4u64){0xfffa2078fffa2074, 0xfffefffefffefffe,
                      0xfffa2078fffa2074, 0xfffefffefffefffe};
  __m256i_result = (__m256i){0x01ff01ff01ff01ff, 0x01ff01ff01ff01ff,
                             0x01ff01ff01ff01ff, 0x01ff01ff01ff01ff};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00ef0120, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ef0120, 0x00ff00ff00ff00ff};
  v4u64_op1 = (v4u64){0x00000000e9ece9ec, 0x00000000e9ece9ec,
                      0x00000000e9ece9ec, 0x00000000e9ece9ec};
  __m256i_result = (__m256i){0x0000e9ec0000e9ec, 0x00ff00ff00ff0120,
                             0x0000e9ec0000e9ec, 0x00ff00ff00ff0120};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffdd001dffe00031, 0xffdd001dffe00020,
                      0xffdd001dffe00031, 0xffdd001dffe00020};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x3ff73ff83ff73ff8,
                             0x0000000000000000, 0x3ff73ff83ff73ff8};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003fff00003fff, 0x00003fff00003fff,
                      0x00003fff00003fff, 0x00003fff00003fff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0003000300030003,
                             0x0000000000000000, 0x0003000300030003};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0003000300030003,
                      0x0000000000000000, 0x0003000300030003};
  v4u64_op1 = (v4u64){0x0000000000000003, 0x0000000000000000,
                      0x0000000000000003, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0600060000000000,
                             0x0000000000000000, 0x0600060000000000};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x7fef0000ffff0000,
                      0x0000000000000000, 0x7fef0000ffff0000};
  v4u64_op1 = (v4u64){0x0000000000ff00ff, 0x0000000000ff00ff,
                      0x0000000000ff00ff, 0x0000000000ff00ff};
  __m256i_result = (__m256i){0x0000fe010000fe01, 0xde00fe0000000000,
                             0x0000fe010000fe01, 0xde00fe0000000000};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff0000ffff0000, 0xffff000000000000,
                      0xffff0000ffff0000, 0xffff000000000000};
  v4u64_op1 = (v4u64){0x0000000000000002, 0xffffffff00000001,
                      0x0000000000000002, 0xffffffff00000001};
  __m256i_result = (__m256i){0x03ff000000000000, 0x03ff000003ff03ff,
                             0x03ff000000000000, 0x03ff000003ff03ff};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000e000e, 0x00000000000e000e,
                      0x00000000000e000e, 0x00000000000e000e};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x00000e0000000e00,
                             0xffffffffffffffff, 0x00000e0000000e00};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000feff0001ffb8, 0x000000000001fff0,
                      0x0000feff0001ffb8, 0x000000000001fff0};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffff00, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000000f, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffefe00000000, 0xffffffffffffffff,
                      0xfffffefefffffefe, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x000003ff000003ff,
                             0x0000000000000000, 0x000003ff000003ff};
  __m256i_out = __lasx_xvsrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x36);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc8eab25698f97e90, 0xd207e90001fb16ef,
                      0xc8eab25698f97e90, 0xd207e90001fb16ef};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x01fb16ef98f97e90,
                             0x0000000000000000, 0x01fb16ef98f97e90};
  __m256i_out = __lasx_xvsrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003e6c0000cb7a, 0x0000401000000000,
                      0x00003e6c0000cb7a, 0x0000401000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x40000000b000032d,
                             0x0000000000000000, 0x40000000b000032d};
  __m256i_out = __lasx_xvsrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff00000000, 0x0000ffff00000000,
                      0x0000ffff00000000, 0x0000ffff00000000};
  v4u64_op1 = (v4u64){0xffffffff00000000, 0xffffffff00000000,
                      0xffffffff00000000, 0xffffffff00000000};
  __m256i_result = (__m256i){0x0007ffff0007ffff, 0x0000000700000007,
                             0x0007ffff0007ffff, 0x0000000700000007};
  __m256i_out = __lasx_xvsrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xfc003802fc000000,
                      0x0000000000000000, 0xfc003802fc000000};
  __m256i_result = (__m256i){0x03802fc000000000, 0x0000000000000000,
                             0x03802fc000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000004000, 0x0000200000000000,
                      0x0000000000004000, 0x0000200000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x39);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x73);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x007f00ff007f00ff, 0x007f00ff007f00ff,
                      0x007f00ff007f00ff, 0x007f00ff007f00ff};
  __m256i_result = (__m256i){0x01fc03fc01fc03fc, 0xfffffffffffffffc,
                             0x01fc03fc01fc03fc, 0xfffffffffffffffc};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001fffe00010001, 0x0001fffe0000ffff,
                      0x0001fffe00010001, 0x0001fffe0000ffff};
  v4u64_op1 = (v4u64){0x0000ffff0000ffff, 0x0000000000000000,
                      0x0000ffff0000ffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000007fff8, 0x0007fff8000ffff0,
                             0x000000000007fff8, 0x0007fff8000ffff0};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0010000f0000000f, 0x0020000f0000000f,
                      0x0010000f0000000f, 0x0020000f0000000f};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x1e0000001e002000,
                             0x0000000000000000, 0x1e0000001e002000};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x27);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffff3225, 0x0000000000000000,
                      0x00000000ffff3225, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x1a19181716151413, 0x2221201f1e1d1c1b,
                      0x1a19181716151413, 0x2221201f1e1d1c1b};
  __m256i_result = (__m256i){0x0000000004442403, 0x0000000000000000,
                             0x0000000004442403, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x63);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x66);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0808080008280820, 0x080808000828082f,
                      0x0808080008280820, 0x080808000828082f};
  v4u64_op1 = (v4u64){0x132feea900000000, 0x04e8296f18181818,
                      0x132feea900000000, 0x04e8296f18181818};
  __m256i_result = (__m256i){0xf18181818132feea, 0x00828082f0808080,
                             0xf18181818132feea, 0x00828082f0808080};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x24);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x43);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000003fc03bbc, 0xfe01fe01fc01fc01,
                      0x000000003fc03bbc, 0xfe01fe01fc01fc01};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xfc01000000003fc0,
                             0x0000000000000000, 0xfc01000000003fc0};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x2555205ea7bc4020, 0x0000000126000200,
                      0x2555205ea7bc4020, 0x0000000126000200};
  v4u64_op1 = (v4u64){0x10ffffff10000006, 0x0fffffff10000006,
                      0x10ffffff10000006, 0x0fffffff10000006};
  __m256i_result = (__m256i){0x003ffffffc400000, 0x0000000004980008,
                             0x003ffffffc400000, 0x0000000004980008};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x46);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff0ff00fff0ff10, 0x00f0000000f00010,
                      0xfff0ff00fff0ff10, 0x00f0000000f00010};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0087ff87f807ff87,
                             0x0000000000000000, 0x0087ff87f807ff87};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x68);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x000000000000ffff, 0x000000000000ffff,
                      0x000000000000ffff, 0x000000000000ffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000ffffffffffff,
                             0x0000000000000000, 0x0000ffffffffffff};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x50);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfefefefefefefefe, 0x0000000000050005,
                      0xfefefefefefefefe, 0x0005000500050005};
  v4u64_op1 = (v4u64){0xf08aff01f07cc291, 0xf007fe76f008fe19,
                      0xf08aff01f07cc291, 0xf007fe76f008fe19};
  __m256i_result = (__m256i){0x0000000003c01ff9, 0x0000000000000000,
                             0x0000000003c01ff9, 0x0000000000001400};
  __m256i_out = __lasx_xvsrlni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x66);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
