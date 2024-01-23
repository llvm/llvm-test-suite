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

  v4u64_op0 = (v4u64){0xffff000000000000, 0x0000000000000000,
                      0xffff000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffff605a, 0xffffffffffff5f5c,
                      0xffffffffffff605a, 0xffffffffffff5f5c};
  __m256i_result = (__m256i){0x0101000000000000, 0x0000000000000000,
                             0x0101000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0x0202810102020202, 0x0202020202020202,
                      0x0202810102020202, 0x0202020202020202};
  __m256i_result = (__m256i){0x00007fff0000fefe, 0x0000fefe0000fefe,
                             0x00007fff0000fefe, 0x0000fefe0000fefe};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000017547fffffff, 0x0000000000000000,
                      0x000017547fffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x80938013800d0005, 0x807e80fd80fe0000,
                      0x80938013800d8002, 0x807e80fd80fe80fd};
  __m256i_result = (__m256i){0x0000801380f300fb, 0x0000000000000000,
                             0x0000801380f380fe, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000fffd5a98, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x00000000ffffffff,
                      0x00000000ffffffff, 0x00000000ffffffff};
  __m256i_result = (__m256i){0x000000000101ff01, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000003, 0x0000000000000000,
                      0x0000000000000003, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000000fd, 0x0000000000000000,
                             0x00000000000000fd, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0057ffa800ceff31, 0x80f900f980780078,
                      0x00faff0500c3ff3c, 0x8011ffee804c004c};
  v4u64_op1 = (v4u64){0xffff0000ffff0000, 0x0000000000000000,
                      0xffff0000ffff0000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00ff000000010000, 0x0000000000000000,
                             0x0001000000010000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000000000ff,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x000000007fffffff,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x000000000000004e, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000003fff, 0x0000000000003fff,
                      0x0000000000003fff, 0x0000000000003fff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0xffffffff00000000,
                      0xffffffff00000000, 0xffffffff00000000};
  v4u64_op1 = (v4u64){0x6c2905ae7c14c561, 0x00000001faf19b60,
                      0x6c2905ae7c14c561, 0x00000001faf19b60};
  __m256i_result = (__m256i){0x94d7fb5200000000, 0x000000ff00000000,
                             0x94d7fb5200000000, 0x000000ff00000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffe97a1df5b41b0, 0xfffeb664007ffd61,
                      0xfffe97a1df5b41b0, 0xfffeb664007ffd61};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000ff80, 0x0000000000000000,
                      0x0000000000000002, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000180, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffe0000fffe0012, 0xfffefffefffeffee,
                      0xfffe0000fffe0012, 0xfffefffefffeffee};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000001ffff, 0x0000000000000000,
                             0x000000000001ffff, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xdfc2df80df80df87, 0xdf80df80df80df80,
                      0xdfc2df80df80df87, 0xdf80df80df80df80};
  v4u64_op1 = (v4u64){0xdfc2df80df80df87, 0xdf80df80df80df80,
                      0xdfc2df80df80df87, 0xdf80df80df80df80};
  __m256i_result = (__m256i){0x203e208020802079, 0x2080208020802080,
                             0x203e208020802079, 0x2080208020802080};
  __m256i_out = __lasx_xvsigncov_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003f3f00004040, 0x0000000000000000,
                      0x00003f3f00004040, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffffffffe05f8102,
                      0x0000000000000000, 0xffffffffe05f8102};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000104000000000, 0xffffffa30000165a,
                      0x0000104000000000, 0xffffffa30000165a};
  v4u64_op1 = (v4u64){0xc1d75053f0000000, 0x41dfffffffc00000,
                      0xc1d75053f0000000, 0x41dfffffffc00000};
  __m256i_result = (__m256i){0x0000505300000000, 0xbe21000100000000,
                             0x0000505300000000, 0xbe21000100000000};
  __m256i_out = __lasx_xvsigncov_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfefefefefefefefe, 0xfefefefefefefefe,
                      0xfefefefefefefefe, 0xfefefefefefefefe};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf000000000000000, 0xf000000000000000,
                      0xf000000000000000, 0xf000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000080, 0x0000000000000000,
                      0x0000000000000080, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff39ffffff, 0x0000000000000000,
                      0xffffffff39ffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000000010000, 0x0000000000000000,
                      0x0001000000010000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0002000000000000, 0x0006000000040000,
                      0x0002000000000000, 0x0006000000040000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x80be0000ffffffff, 0x0000000000000080,
                      0x80be0000ffffffff, 0x0000000000000080};
  v4u64_op1 = (v4u64){0x8000000100000000, 0x0000000000000000,
                      0x8000000100000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7fffffff00000000, 0x0000000000000000,
                             0x7fffffff00000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000001880310877e, 0x0000000000000000,
                      0x000001880310877e, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000f788f788, 0x8000000000000000,
                      0x00000000f788f788, 0x8000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x97541c5897541c58, 0x97541c5897541c58,
                      0x97541c5897541c58, 0x97541c5897541c58};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x00000000ffffffff,
                      0xffffffffffffffff, 0x00000000ffffffff};
  __m256i_result = (__m256i){0x0000000000000001, 0xffffffff00000001,
                             0x0000000000000001, 0xffffffff00000001};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffee, 0xffffffffffffffee,
                      0xffffffffffffffee, 0xffffffffffffffee};
  v4u64_op1 = (v4u64){0x007f00ff007f00ff, 0x0000000000000000,
                      0x007f00ff007f00ff, 0x0000000000000000};
  __m256i_result = (__m256i){0xff80ff00ff80ff01, 0x0000000000000000,
                             0xff80ff00ff80ff01, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x3901000039010000, 0x3880800037800000,
                      0x3901000039010000, 0x3880800037800000};
  v4u64_op1 = (v4u64){0x00003fc00000428a, 0xffffc040ffffc09d,
                      0x00003fc00000428a, 0xffffc040ffffc09d};
  __m256i_result = (__m256i){0x00003fc00000428a, 0xffffc040ffffc09d,
                             0x00003fc00000428a, 0xffffc040ffffc09d};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffa2beb040, 0x0000000022beb03f,
                      0x7fffffffa2beb040, 0x0000000022beb03f};
  v4u64_op1 = (v4u64){0xffffba8300004fc2, 0xffffba8300004fc2,
                      0xffffba8300004fc2, 0xffffba8300004fc2};
  __m256i_result = (__m256i){0xffffba8300004fc2, 0xffffba8300004fc2,
                             0xffffba8300004fc2, 0xffffba8300004fc2};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00c000000000, 0x004100df00ff00ff,
                      0x00ff00c000000000, 0x004100df00ff00ff};
  v4u64_op1 = (v4u64){0xc1d75053f0000000, 0x41dfffffffc00000,
                      0xc1d75053f0000000, 0x41dfffffffc00000};
  __m256i_result = (__m256i){0xc1d75053f0000000, 0x41dfffffffc00000,
                             0xc1d75053f0000000, 0x41dfffffffc00000};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ff78ffc0, 0x00000000ff88ffc0,
                      0x00000000ff78ffc0, 0x00000000ff88ffc0};
  v4u64_op1 = (v4u64){0x0000002000000020, 0x00000000ff78ffc0,
                      0x0000002000000020, 0x0000002000000020};
  __m256i_result = (__m256i){0x0000002000000020, 0x00000000ff78ffc0,
                             0x0000002000000020, 0x0000002000000020};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x4d0a902890b800dc, 0xffffffffffff6361,
                      0x4d0a902890b800dc, 0xffffffffffff6361};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000ff0000, 0x0000000000ff0000,
                      0x0000000000ff0000, 0x0000000000ff0000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8768876887688769, 0x8282828282828282,
                      0x8768876887688769, 0x8282828282828282};
  v4u64_op1 = (v4u64){0x00000000003fffc0, 0x0000000000000000,
                      0x00000000003fffc0, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffc00040, 0x0000000000000000,
                             0xffffffffffc00040, 0x0000000000000000};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffafffe80004fff1, 0xffdbff980038ffaf,
                      0xffafffe80004fff1, 0xffdbff980038ffaf};
  v4u64_op1 = (v4u64){0xffff0000fffd0003, 0x0000ffff0002fffc,
                      0xffff0000fffd0003, 0x0000ffff0002fffc};
  __m256i_result = (__m256i){0x0000ffff0002fffd, 0xffff0000fffd0004,
                             0x0000ffff0002fffd, 0xffff0000fffd0004};
  __m256i_out = __lasx_xvsigncov_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
