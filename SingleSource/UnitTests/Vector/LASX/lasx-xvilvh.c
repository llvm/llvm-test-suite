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

  v4u64_op0 = (v4u64){0x7fffff90ffffff81, 0x0000000000000000,
                      0x7fffff90ffffff81, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf5f5f5f5f5f5f5f5, 0xffffffffffffffff,
                      0xf5f5f5f5f5f5f5f5, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000004000000,
                      0x0000000000000000, 0x0000000004000000};
  __m256i_result = (__m256i){0xff04ff00ff00ff00, 0xff00ff00ff00ff00,
                             0xff04ff00ff00ff00, 0xff00ff00ff00ff00};
  __m256i_out = __lasx_xvilvh_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010101010101, 0x7eeefefefefefefe,
                      0x0101010101010101, 0x7eeefefefefefefe};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfe00fe00fe00fe00, 0x7e00ee00fe00fe00,
                             0xfe00fe00fe00fe00, 0x7e00ee00fe00fe00};
  __m256i_out = __lasx_xvilvh_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x4040404040404040, 0x4040404040404040,
                      0x4040404040404040, 0x4040404040404040};
  v4u64_op1 = (v4u64){0xffffffff80007fe9, 0xffffffff7bfffff1,
                      0xffffffff80007fe9, 0xffffffff7bfffff1};
  __m256i_result = (__m256i){0x407b40ff40ff40f1, 0x40ff40ff40ff40ff,
                             0x407b40ff40ff40f1, 0x40ff40ff40ff40ff};
  __m256i_out = __lasx_xvilvh_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001fffe00018069, 0x0001fffe0001fffa,
                      0x0001fffe00018069, 0x0001fffe0001fffa};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x00ff01fffffffaff, 0x00ff01fffffffeff,
                             0x00ff01fffffffaff, 0x00ff01fffffffeff};
  __m256i_out = __lasx_xvilvh_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xbff0000000000000, 0xbff0000000000000,
                      0xbff0000000000000, 0xbff0000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x8000000000000000,
                      0xffffffffffffffff, 0x8000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xbff0800000000000,
                             0x0000000000000000, 0xbff0800000000000};
  __m256i_out = __lasx_xvilvh_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010101010101, 0x0008010101010101,
                      0x2020202020200008, 0x2020202020202020};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101000001010000, 0x0008000001010000,
                             0x2020000020200000, 0x2020000020200000};
  __m256i_out = __lasx_xvilvh_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8015003f0006001f, 0x0000003f00390035,
                      0x8015003f0006001f, 0x0000003f00390035};
  v4u64_op1 = (v4u64){0x80007073cadc3779, 0x80000000001529c1,
                      0x80007073cadc3779, 0x80000000001529c1};
  __m256i_result = (__m256i){0x00390015003529c1, 0x00008000003f0000,
                             0x00390015003529c1, 0x00008000003f0000};
  __m256i_out = __lasx_xvilvh_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x00000000ffffffff,
                      0x00000000ffffffff, 0x00000000ffffffff};
  __m256i_result = (__m256i){0x0000ffff0000ffff, 0x0000000000000000,
                             0x0000ffff0000ffff, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000002c, 0x000000000000002c,
                      0x000000000000002c, 0x000000000000002c};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000002c0000, 0x0000000000000000,
                             0x00000000002c0000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffff1fffffff1, 0x0000000000000000,
                      0xfffffff1fffffff1, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x800080ff800080ff, 0x800080ff800080ff,
                      0x800080ff800080ff, 0x800080ff800080ff};
  v4u64_op1 = (v4u64){0x00000080c000c080, 0x4000c08000000080,
                      0x00000080c000c080, 0x4000c08000000080};
  __m256i_result = (__m256i){0x8000000080ff0080, 0x8000400080ffc080,
                             0x8000000080ff0080, 0x8000400080ffc080};
  __m256i_out = __lasx_xvilvh_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffffffffff, 0x001fffffffe00000,
                      0x7fffffffffffffff, 0x001fffffffe00000};
  v4u64_op1 = (v4u64){0x7fffffffffffffff, 0x001fffffffe00000,
                      0x7fffffffffffffff, 0x001fffffffe00000};
  __m256i_result = (__m256i){0xffe0ffe000000000, 0x001f001fffffffff,
                             0xffe0ffe000000000, 0x001f001fffffffff};
  __m256i_out = __lasx_xvilvh_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000003f, 0x000000000000003f,
                      0x000000000000003f, 0x000000000000003f};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000003f00000000, 0x0000000000000000,
                             0x0000003f00000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x000000000000ffff, 0x000000000000ffff,
                             0x000000000000ffff, 0x000000000000ffff};
  __m256i_out = __lasx_xvilvh_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00001ff8d8d90000, 0x00001ff8d8d8c000,
                      0x00001ff8d8d90000, 0x00001ff8d8d8c000};
  v4u64_op1 = (v4u64){0x0200000202000002, 0x0000000000000000,
                      0x0200000202000002, 0x0000000000000000};
  __m256i_result = (__m256i){0xd8d8c00000000000, 0x00001ff800000000,
                             0xd8d8c00000000000, 0x00001ff800000000};
  __m256i_out = __lasx_xvilvh_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000100, 0x0000000000000000,
                      0x0000000000000100, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000000203ff, 0x0000000001ff03ff,
                      0x00000000000203ff, 0x0000000001ff03ff};
  __m256i_result = (__m256i){0x0000000001ff03ff, 0x0000000000000000,
                             0x0000000001ff03ff, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffff8000, 0x0000000000000000,
                      0xffffffffffff8000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffff8000, 0x0000000000000000,
                      0xffffffffffff8000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000101, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x000307fffe72e800, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000001fffe, 0x0000000000000000,
                      0x000000000001fffe, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x5555555580000000, 0x555555553f800000,
                      0x5555555580000000, 0x555555553f800000};
  __m256i_result = (__m256i){0x555555553f800000, 0x0000000000000000,
                             0x555555553f800000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x419cd5b11c3c5654, 0x6580668200fe0002,
                      0x2475cef801f0ffdd, 0x247fe49409620040};
  v4u64_op1 = (v4u64){0x419cd5b11c3c5654, 0x6580668200fe0002,
                      0x2475cef801f0ffdd, 0x247fe49409620040};
  __m256i_result = (__m256i){0x6580668200fe0002, 0x6580668200fe0002,
                             0x247fe49409620040, 0x247fe49409620040};
  __m256i_out = __lasx_xvilvh_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0020002000200020,
                      0x0000000000000000, 0x0020002000200020};
  __m256i_result = (__m256i){0x0020002000200020, 0x0000000000000000,
                             0x0020002000200020, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000080000000, 0x8000000080000000,
                      0x8000000080000000, 0x8000000080000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x8000000080000000,
                             0xffffffffffffffff, 0x8000000080000000};
  __m256i_out = __lasx_xvilvh_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000000000ff, 0x00000000ffffffff,
                      0x00000000000000ff, 0x00000000ffffffff};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000000000000,
                             0x00000000ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xaad5555500000000, 0x0000000000000000,
                      0xaad5555500000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x00001fff200007ef,
                      0x0000000000000000, 0x1f001f00000007ef};
  __m256i_result = (__m256i){0x00001fff200007ef, 0x0000000000000000,
                             0x1f001f00000007ef, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff02000000, 0x0000000000000000,
                      0x0000ffff02000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000002, 0x0000000000000100,
                      0x0000000000000002, 0x0000000000000100};
  __m256i_result = (__m256i){0x0000000000000100, 0x0000000000000000,
                             0x0000000000000100, 0x0000000000000000};
  __m256i_out = __lasx_xvilvh_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffe97c020010001, 0xfffeb6839ffffd80,
                      0xfffe97c020010001, 0xfffeb6839ffffd80};
  v4u64_op1 = (v4u64){0x000000011ffd97c3, 0x000000019ffdf403,
                      0x000000011ffd97c3, 0x000000019ffdf403};
  __m256i_result = (__m256i){0x000000019ffdf403, 0xfffeb6839ffffd80,
                             0x000000019ffdf403, 0xfffeb6839ffffd80};
  __m256i_out = __lasx_xvilvh_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
