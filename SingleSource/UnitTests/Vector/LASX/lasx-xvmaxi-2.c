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

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_bu((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000102};
  __m256i_result = (__m256i){0x0a0a0a0a0a0a0a0a, 0x0a0a0a0a0a0a0a0a,
                             0x0a0a0a0a0a0a0a0a, 0x0a0a0a0a0a0a0a0a};
  __m256i_out = __lasx_xvmaxi_bu((__m256)v4u64_op0, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x1717171717171717, 0x1717171717171717,
                             0x1717171717171717, 0x1717171717171717};
  __m256i_out = __lasx_xvmaxi_bu((__m256)v4u64_op0, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000007fffffff, 0x7ffe00007f000000,
                      0x000000007fffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x161616167fffffff, 0x7ffe16167f161616,
                             0x161616167fffffff, 0x1616161616161616};
  __m256i_out = __lasx_xvmaxi_bu((__m256)v4u64_op0, 0x16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000feb60000c7eb, 0x0000feb60000b7d0,
                      0x0000feb60000c7eb, 0x0000feb60000b7d0};
  __m256i_result = (__m256i){0x0707feb60707c7eb, 0x0707feb60707b7d0,
                             0x0707feb60707c7eb, 0x0707feb60707b7d0};
  __m256i_out = __lasx_xvmaxi_bu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x1111111111111111, 0x1111111111111111,
                             0x1111111111111111, 0x1111111111111111};
  __m256i_out = __lasx_xvmaxi_bu((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010101,
                             0x0101010101010101, 0x0101010101010101};
  __m256i_out = __lasx_xvmaxi_bu((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000165a, 0x0000ffff0000ffa3,
                      0x000000000000165a, 0x0000ffff0000ffa3};
  __m256i_result = (__m256i){0x181818181818185a, 0x1818ffff1818ffa3,
                             0x181818181818185a, 0x1818ffff1818ffa3};
  __m256i_out = __lasx_xvmaxi_bu((__m256)v4u64_op0, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x1c1c1c1c1c1c1c1c, 0x1c1c1c1c1c1c1c1c,
                             0x1c1c1c1c1c1c1c1c, 0x1c1c1c1c1c1c1c1c};
  __m256i_out = __lasx_xvmaxi_bu((__m256)v4u64_op0, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaxi_hu((__m256)v4u64_op0, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf064c6098d214127, 0xeffc000000000000,
                      0xf064c6098d214127, 0xeffc000000000000};
  __m256i_result = (__m256i){0xf064c6098d214127, 0xeffc001800180018,
                             0xf064c6098d214127, 0xeffc001800180018};
  __m256i_out = __lasx_xvmaxi_hu((__m256)v4u64_op0, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000010001, 0x0000000000000003,
                      0x0000000000010001, 0x0000000000000003};
  __m256i_result = (__m256i){0x0001000100010001, 0x0001000100010003,
                             0x0001000100010001, 0x0001000100010003};
  __m256i_out = __lasx_xvmaxi_hu((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0007000700070007, 0x0007000700070007,
                             0x0007000700070007, 0x0007000700070007};
  __m256i_out = __lasx_xvmaxi_hu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0018001800180018, 0x0018001800180018,
                             0x0018001800180018, 0x0018001800180018};
  __m256i_out = __lasx_xvmaxi_hu((__m256)v4u64_op0, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000d6d6d, 0x00000000000d6d6d,
                      0x00000000000d6d6d, 0x00000000000d6d6d};
  __m256i_result = (__m256i){0x0017001700176d6d, 0x0017001700176d6d,
                             0x0017001700176d6d, 0x0017001700176d6d};
  __m256i_out = __lasx_xvmaxi_hu((__m256)v4u64_op0, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffffffffff, 0x001fffffffe00000,
                      0x7fffffffffffffff, 0x001fffffffe00000};
  __m256i_result = (__m256i){0x7fffffffffffffff, 0x001fffffffe00011,
                             0x7fffffffffffffff, 0x001fffffffe00011};
  __m256i_out = __lasx_xvmaxi_hu((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000001400000014, 0x0000001400000014,
                             0x0000001400000014, 0x0000001400000014};
  __m256i_out = __lasx_xvmaxi_wu((__m256)v4u64_op0, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000080, 0x0000000000000080,
                      0x0000000000000080, 0x0000000000000080};
  __m256i_result = (__m256i){0x0000000e00000080, 0x0000000e00000080,
                             0x0000000e00000080, 0x0000000e00000080};
  __m256i_out = __lasx_xvmaxi_wu((__m256)v4u64_op0, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000fd0000, 0x0000000000000000,
                      0x0000000000fd0000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000001b00fd0000, 0x0000001b0000001b,
                             0x0000001b00fd0000, 0x0000001b0000001b};
  __m256i_out = __lasx_xvmaxi_wu((__m256)v4u64_op0, 0x1b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffd017d00, 0x000000007aff7c00,
                      0xfffffffffd017d00, 0x000000007aff7c00};
  __m256i_result = (__m256i){0xfffffffffd017d00, 0x0000000c7aff7c00,
                             0xfffffffffd017d00, 0x0000000c7aff7c00};
  __m256i_out = __lasx_xvmaxi_wu((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x0000001f0000ffff, 0x0000001f0000001f,
                             0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_out = __lasx_xvmaxi_wu((__m256)v4u64_op0, 0x1f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000300000003, 0x0000000300000003,
                             0x0000000300000003, 0x0000000300000003};
  __m256i_out = __lasx_xvmaxi_wu((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000ff000000ff, 0x1010101000000000,
                      0x000000ff000000ff, 0x1010101010001000};
  __m256i_result = (__m256i){0x000000ff000000ff, 0x101010100000000e,
                             0x000000ff000000ff, 0x1010101010001000};
  __m256i_out = __lasx_xvmaxi_wu((__m256)v4u64_op0, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000007ffff, 0x000000000007ffff,
                      0x000000000007ffff, 0x000000000007ffff};
  __m256i_result = (__m256i){0x0000001e0007ffff, 0x0000001e0007ffff,
                             0x0000001e0007ffff, 0x0000001e0007ffff};
  __m256i_out = __lasx_xvmaxi_wu((__m256)v4u64_op0, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000002, 0x00000000000000fe,
                      0x00000000000000fd, 0x0000000000000001};
  __m256i_result = (__m256i){0x0000000400000004, 0x00000004000000fe,
                             0x00000004000000fd, 0x0000000400000004};
  __m256i_out = __lasx_xvmaxi_wu((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000001f, 0x0000000000000000,
                      0x000000000000001f, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000001f, 0x0000000000000000,
                             0x000000000000001f, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_wu((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000010, 0x0000000000000000,
                      0x0000000000000010, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000001700000017, 0x0000001700000017,
                             0x0000001700000017, 0x0000001700000017};
  __m256i_out = __lasx_xvmaxi_wu((__m256)v4u64_op0, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x07fed3c8f7ad28d0, 0x07fee332883f86b0,
                      0x07fed3c8f7ad28d0, 0x07fee332883f86b0};
  __m256i_result = (__m256i){0x07fed3c8f7ad28d0, 0x07fee332883f86b0,
                             0x07fed3c8f7ad28d0, 0x07fee332883f86b0};
  __m256i_out = __lasx_xvmaxi_wu((__m256)v4u64_op0, 0x10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffff00000000,
                      0x0000000000000000, 0xffffffff00000000};
  __m256i_result = (__m256i){0x000000000000001e, 0xffffffff00000000,
                             0x000000000000001e, 0xffffffff00000000};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19,
                      0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19};
  __m256i_result = (__m256i){0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19,
                             0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000003f, 0x000000000000003f,
                      0x000000000000003f, 0x000000000000003f};
  __m256i_result = (__m256i){0x000000000000003f, 0x000000000000003f,
                             0x000000000000003f, 0x000000000000003f};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0xffffffffffffffff,
                      0x00000000ffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x00000000ffffffff, 0xffffffffffffffff,
                             0x00000000ffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000001c, 0x000000000000001c,
                             0x000000000000001c, 0x000000000000001c};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000005, 0x0000000000000005,
                             0x0000000000000005, 0x0000000000000005};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000600000006, 0x0000000600000006,
                      0x0000000600000006, 0x0000000600000006};
  __m256i_result = (__m256i){0x0000000600000006, 0x0000000600000006,
                             0x0000000600000006, 0x0000000600000006};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffffffffffe, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0xfffffffffffffffe, 0xfffffffffffffffe,
                             0xfffffffffffffffe, 0xfffffffffffffffe};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000040, 0x0000000000000000,
                      0x0000000000000040, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000040, 0x0000000000000012,
                             0x0000000000000040, 0x0000000000000012};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffffffffff, 0x7fffffffffffffff,
                      0x7fffffffffffffff, 0x7fffffffffffffff};
  __m256i_result = (__m256i){0x7fffffffffffffff, 0x7fffffffffffffff,
                             0x7fffffffffffffff, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000007, 0x0000000000000007,
                             0x0000000000000007, 0x0000000000000007};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000000b, 0x000000000000000b,
                             0x000000000000000b, 0x000000000000000b};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000013, 0x0000000000000013,
                             0x0000000000000013, 0x0000000000000013};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000014, 0x0000000000000014,
                             0x0000000000000014, 0x0000000000000014};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000014, 0x0000000000000014,
                             0x0000000000000014, 0x0000000000000014};
  __m256i_out = __lasx_xvmaxi_du((__m256)v4u64_op0, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
