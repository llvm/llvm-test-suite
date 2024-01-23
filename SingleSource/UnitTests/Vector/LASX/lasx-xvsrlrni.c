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

  v4u64_op0 = (v4u64){0x0100010001000000, 0x0100010001000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0001000100010001, 0x0001000100010001,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff0000000000000, 0xfff0000000000000,
                      0xfff0000000000000, 0xfff0000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xf0000000f0000000,
                             0x0000000000000000, 0xf0000000f0000000};
  __m256i_out = __lasx_xvsrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0404040404040404,
                             0x0000000000000000, 0x0404040404040404};
  __m256i_out = __lasx_xvsrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000ffff0000ffff,
                      0xffffffffffffffff, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0x000000000000ffff, 0x000000000000ffff,
                      0x000000000000ffff, 0x000000000000ffff};
  __m256i_result = (__m256i){0x0000000400000004, 0x0004000400000000,
                             0x0000000400000004, 0x0004000404040404};
  __m256i_out = __lasx_xvsrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x80208020c22080a7,
                      0x0000000000000000, 0x80208020c22080a7};
  v4u64_op1 = (v4u64){0xdfc2ff20df80ffa7, 0xdf80ff20df80ff20,
                      0xdfc2ff20df80ffa7, 0xdf80ff20df80ff20};
  __m256i_result = (__m256i){0xbffebffec0febfff, 0x0000840100000000,
                             0xbffebffec0febfff, 0x0000840100000000};
  __m256i_out = __lasx_xvsrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000001200000012, 0x0000001200000012,
                      0x0000001200000012, 0x0000001200000012};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000812000008120, 0x000081220000812c,
                      0x0000812000008120, 0x000081220000812c};
  v4u64_op1 = (v4u64){0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f,
                      0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f};
  __m256i_result = (__m256i){0xfefefefefefefefe, 0x0005000500050005,
                             0xfefefefefefefefe, 0x0005000500050005};
  __m256i_out = __lasx_xvsrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x7fffffff80000000, 0x7fffffff80000000,
                      0x7fffffff80000000, 0x7fffffff80000000};
  __m256i_result = (__m256i){0xffff0000ffff0000, 0xffffffffffffffff,
                             0xffff0000ffff0000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0020002000200020,
                             0x0000000000000000, 0x0020002000200020};
  __m256i_out = __lasx_xvsrlrni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x817f11ed81800ff0, 0x00000000000000fe,
                      0x817f11ed81800ff0, 0x00000000000000fe};
  v4u64_op1 = (v4u64){0x817f11ed81800ff0, 0x00000000000000fe,
                      0x817f11ed81800ff0, 0x00000000000000fe};
  __m256i_result = (__m256i){0x00000004fc480040, 0x00000004fc480040,
                             0x00000004fc480040, 0x00000004fc480040};
  __m256i_out = __lasx_xvsrlrni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlrni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff0fff0fff0fc00, 0x0000000000000000,
                      0xfff0fff0fff0fc00, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffff000000, 0x0000000000000000,
                      0xffffffffff000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000008000, 0x00000000f880f87e,
                             0x0000000000008000, 0x00000000f880f87e};
  __m256i_out = __lasx_xvsrlrni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001ffffffffffff, 0x00000003ffffffff,
                      0x0001ffffffffffff, 0x00000003ffffffff};
  v4u64_op1 = (v4u64){0x000000010000005e, 0x0000000000000000,
                      0x000000010000005e, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlrni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffff00000000,
                      0x0000000000000000, 0xffffffff00000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffffffff00000000,
                      0x0000000000000000, 0xffffffff00000000};
  __m256i_result = (__m256i){0x0040000000000000, 0x0040000000000000,
                             0x0040000000000000, 0x0040000000000000};
  __m256i_out = __lasx_xvsrlrni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000020,
                             0x0000000000000000, 0x0000000000000020};
  __m256i_out = __lasx_xvsrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000808000008081, 0x0000808000008080};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000081};
  __m256i_out = __lasx_xvsrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x68);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000002a5429, 0x0000000000000000,
                      0x00000000002a5429, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x30);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000801380f300fb, 0x0000000000000000,
                      0x0000801380f380fe, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000007f3a40, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x42);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x56);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffc0c0ffffbfc0, 0xffffffffffffffff,
                      0xffffc0c0ffffbfc0, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x00003f3f0000400d, 0x0000000000000000,
                      0x00003f3f0000400d, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x1000000000000000,
                             0x0000000000000000, 0x1000000000000000};
  __m256i_out = __lasx_xvsrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x44);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000ffffffff,
                      0x0000000000000000, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x1000000000000000,
                      0x0000000000000000, 0x1000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffe00000000000,
                             0x0000000000000000, 0xffffe00000000000};
  __m256i_out = __lasx_xvsrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfc00000000000048, 0x3ff0000000000000,
                      0xfc00000000000048, 0x3ff0000000000000};
  v4u64_op1 = (v4u64){0xbfffa004fffd8000, 0x0000000000000000,
                      0xbfffa004fffd8000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00002fffe8013fff, 0x00003f0000000000,
                             0x00002fffe8013fff, 0x00003f0000000000};
  __m256i_out = __lasx_xvsrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000080800000808,
                      0x0000000000000000, 0x0000080800000808};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000101000000000,
                             0x0000000000000000, 0x0000101000000000};
  __m256i_out = __lasx_xvsrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff00010001000100, 0x0100010001000100,
                      0xff00010001000100, 0x0100010001000100};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000004000000000, 0x0000000040004000,
                             0x0000004000000000, 0x0000000040004000};
  __m256i_out = __lasx_xvsrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x028da7fe15020000, 0x00b2fe28e4420609,
                      0x028da7fe15020000, 0x00b2fe28e4420609};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000598,
                             0x0000000000000000, 0x0000000000000598};
  __m256i_out = __lasx_xvsrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000800000010, 0x0000000000000000,
                      0x0000000800000010, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000002000000, 0x0000000000000000,
                             0x0000000002000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
