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

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfefefefefefefefe, 0xfefefefefefefefe,
                             0xfefefefefefefefe, 0xfefefefefefefefe};
  __m256i_out = __lasx_xvbitrev_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19,
                      0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x9c9b9a999c9b9a99, 0x1d1a1b181d1a1b18,
                             0x9c9b9a999c9b9a99, 0x1d1a1b181d1a1b18};
  __m256i_out = __lasx_xvbitrev_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000001010101,
                      0x0000000000000000, 0x0000000001010101};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010100000000,
                             0x0101010101010101, 0x0101010100000000};
  __m256i_out = __lasx_xvbitrev_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010101,
                             0x0101010101010101, 0x0101010101010101};
  __m256i_out = __lasx_xvbitrev_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfff8fff8fff8fff8, 0x0000000000000000,
                      0xfff8fff8fff8fff8, 0x0000000000000000};
  __m256i_result = (__m256i){0x8001800180018001, 0x0101010101010101,
                             0x8001800180018001, 0x0101010101010101};
  __m256i_out = __lasx_xvbitrev_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x7fefffffffffffff,
                      0x0000000000000000, 0x7fefffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x7eeefefefefefefe,
                             0x0101010101010101, 0x7eeefefefefefefe};
  __m256i_out = __lasx_xvbitrev_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0xffffffffffffffff,
                      0xffffffff00000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfefefefe01010101, 0xfefefefefefefefe,
                             0xfefefefe01010101, 0xfefefefefefefefe};
  __m256i_out = __lasx_xvbitrev_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000400008, 0x000000000000006d,
                      0x0000000000400008, 0x000000000000006d};
  v4u64_op1 = (v4u64){0x000000000010006d, 0x0000000000080040,
                      0x000000000010006d, 0x0000000000080040};
  __m256i_result = (__m256i){0x0101010101410128, 0x010101010101016c,
                             0x0101010101410128, 0x010101010101016c};
  __m256i_out = __lasx_xvbitrev_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000027, 0x0000000000000040,
                      0x0000000000000027, 0x0000000000000040};
  __m256i_result = (__m256i){0xfefefefefefefe7f, 0xfefefefefefefefe,
                             0xfefefefefefefe7f, 0xfefefefefefefefe};
  __m256i_out = __lasx_xvbitrev_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010101,
                             0x0101010101010101, 0x0101010101010101};
  __m256i_out = __lasx_xvbitrev_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x000000000000000c,
                      0x0000000000000000, 0x000000000000000c};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010110,
                             0x0101010101010101, 0x0101010101010110};
  __m256i_out = __lasx_xvbitrev_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff4ff4e11410b40, 0x010200023b8e4174,
                      0xffd5020738b43ddb, 0x0501030102141923};
  v4u64_op1 = (v4u64){0x008102c2008a029f, 0x024c01f901950261,
                      0x030d03aa0079029b, 0x01fa022a01a401e5};
  __m256i_result = (__m256i){0xfff6ff4a15418b40, 0x110202023bae4176,
                             0xdfd506073ab435db, 0x0101070102041903};
  __m256i_out = __lasx_xvbitrev_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000002e2100, 0x0000000000000000,
                      0x0000000033e87ef1, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fff7fff7fff7fff, 0x0000000000000000,
                      0x7fff7fff7fff7fff, 0x0000000000000000};
  __m256i_result = (__m256i){0x80008000802ea100, 0x0001000100010001,
                             0x80008000b3e8fef1, 0x0001000100010001};
  __m256i_out = __lasx_xvbitrev_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x8000800080008000, 0x8000800080008000,
                             0x8000800080008000, 0x8000800080008000};
  __m256i_out = __lasx_xvbitrev_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8000000080000000, 0x8000000080000000,
                      0x8000000080000000, 0x8000000080000000};
  __m256i_result = (__m256i){0x0001000100010001, 0x0001000100010001,
                             0x0001000100010001, 0x0001000100010001};
  __m256i_out = __lasx_xvbitrev_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000040, 0x0000000000000040,
                      0x0000000000000040, 0x0000000000000040};
  __m256i_result = (__m256i){0x0001000100010001, 0x0001000100010001,
                             0x0001000100010001, 0x0001000100010001};
  __m256i_out = __lasx_xvbitrev_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0x000000000000ffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x000100010001fffe, 0x8000800080008000,
                             0x000100010001fffe, 0x8000800080008000};
  __m256i_out = __lasx_xvbitrev_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000008000, 0x7fff80007fff0000,
                      0x0000000000008000, 0x7fff80007fff0000};
  v4u64_op1 = (v4u64){0xfffffffe00000001, 0xfffffffe00000001,
                      0xfffffffe00000001, 0xfffffffe00000001};
  __m256i_result = (__m256i){0x8000400000018002, 0xffffc0007ffe0002,
                             0x8000400000018002, 0xffffc0007ffe0002};
  __m256i_out = __lasx_xvbitrev_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff97c120000000, 0xffffb6811fffff80,
                      0xffff97c120000000, 0xffffb6811fffff80};
  v4u64_op1 = (v4u64){0x4980008068400000, 0x00000001fffffff9,
                      0x4980008068400000, 0x00000001fffffff9};
  __m256i_result = (__m256i){0xfffe97c020010001, 0xfffeb6839ffffd80,
                             0xfffe97c020010001, 0xfffeb6839ffffd80};
  __m256i_out = __lasx_xvbitrev_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000080, 0x0000000000000002,
                      0x0000000000000080, 0x0000000000000002};
  v4u64_op1 = (v4u64){0x00000000000000ff, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0001000100018080, 0x0001000100010003,
                             0x0001000100010081, 0x0001000100010003};
  __m256i_out = __lasx_xvbitrev_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0001000100010001, 0x0001000100010001,
                             0x0001000100010001, 0x0001000100010001};
  __m256i_out = __lasx_xvbitrev_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000001e18, 0x000000000000ffe0,
                      0x0000000000001e18, 0x000000000000ffe0};
  v4u64_op1 = (v4u64){0x0000000000001e18, 0x000000000000ffe0,
                      0x0000000000001e18, 0x000000000000ffe0};
  __m256i_result = (__m256i){0x0000000101001e18, 0x000000010000ffe1,
                             0x0000000101001e18, 0x000000010000ffe1};
  __m256i_out = __lasx_xvbitrev_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000004000, 0x1c80780000000000,
                      0x0000000000004000, 0x1c80780000000000};
  __m256i_result = (__m256i){0x0000000100000001, 0x0000000100000001,
                             0x0000000100000001, 0x0000000100000001};
  __m256i_out = __lasx_xvbitrev_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x2c27000000000000, 0x0200000200000000,
                      0x2c27000000000000, 0x0200000200000000};
  __m256i_result = (__m256i){0x0000000100000001, 0x0000000400000001,
                             0x0000000100000001, 0x0000000400000001};
  __m256i_out = __lasx_xvbitrev_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000100000001, 0x0000000100000001,
                             0x0000000100000001, 0x0000000100000001};
  __m256i_out = __lasx_xvbitrev_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xff00000000ff00ff, 0xffffffffff00ffff,
                      0xff000000ff00ff00, 0xffff00ff00ffff00};
  __m256i_result = (__m256i){0x0000000180000000, 0x8000000080000000,
                             0x0000000100000001, 0x8000000000000001};
  __m256i_out = __lasx_xvbitrev_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x000000007fffffff,
                      0x0000000000000000, 0x000000007fffffff};
  v4u64_op1 = (v4u64){0x8000000000000000, 0x7fffffffffffffff,
                      0x8000000000000000, 0x7fffffffffffffff};
  __m256i_result = (__m256i){0x0000000100000001, 0x80000000ffffffff,
                             0x0000000100000001, 0x80000000ffffffff};
  __m256i_out = __lasx_xvbitrev_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000100000001, 0x0000000100000001,
                             0x0000000100000001, 0x0000000100000001};
  __m256i_out = __lasx_xvbitrev_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000100000001, 0x0000000100000001,
                             0x0000000100000001, 0x0000000100000001};
  __m256i_out = __lasx_xvbitrev_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7,
                      0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7};
  v4u64_op1 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  __m256i_result = (__m256i){0xf7f7f7f6f7f7f7f6, 0xf7f7f7f6f7f7f7f6,
                             0xf7f7f7f6f7f7f7f6, 0xf7f7f7f6f7f7f7f6};
  __m256i_out = __lasx_xvbitrev_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x000000000000ffff,
                      0x000000000000ffff, 0x000000000000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000010000fffe, 0x000000010000fffe,
                             0x000000010000fffe, 0x000000010000fffe};
  __m256i_out = __lasx_xvbitrev_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00003fe000000000, 0x0000000000000000,
                      0x00003fe000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000100000001, 0x0000000100000001,
                             0x0000000100000001, 0x0000000100000001};
  __m256i_out = __lasx_xvbitrev_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffbe8bc70f, 0xffffffffffffffff,
                      0xffffffffe0edf8d7, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffbe8bc70f, 0xffffffffffffffff,
                      0xffffffffe0edf8d7, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffbe8b470f, 0x7fffffffffffffff,
                             0xffffffffe06df8d7, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvbitrev_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x8000000000000000, 0x8000000000000000,
                             0x8000000000000000, 0x8000000000000000};
  __m256i_out = __lasx_xvbitrev_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff00010003, 0x0080000200000002,
                      0x0000ffff00010003, 0x0000000200000002};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff00010002, 0x0080000200000003,
                             0x0000ffff00010002, 0x0000000200000003};
  __m256i_out = __lasx_xvbitrev_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x8000000000000000, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvbitrev_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvbitrev_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000200000002, 0x0000000200000002,
                      0x0000000200000002, 0x0000000200000002};
  __m256i_result = (__m256i){0x0000000000000004, 0x0000000000000004,
                             0x0000000000000004, 0x0000000000000004};
  __m256i_out = __lasx_xvbitrev_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000000b, 0x000000000008000b,
                      0x000000000000000b, 0x000000000008000b};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000000a, 0x000000000008000a,
                             0x000000000000000a, 0x000000000008000a};
  __m256i_out = __lasx_xvbitrev_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000001,
                      0x0000000000000000, 0x0000000000000001};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000002,
                             0x0000000000000001, 0x0000000000000002};
  __m256i_out = __lasx_xvbitrev_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00fe00fe00fe00fe, 0x00fe00fe00fe00fe,
                      0x00fe00fe00fe00fe, 0x00fe00fe00fe00fe};
  v4u64_op1 = (v4u64){0x00fe00fe00fe00fe, 0x00fe00fe00fe00fe,
                      0x00fe00fe00fe00fe, 0x00fe00fe00fe00fe};
  __m256i_result = (__m256i){0x40fe00fe00fe00fe, 0x40fe00fe00fe00fe,
                             0x40fe00fe00fe00fe, 0x40fe00fe00fe00fe};
  __m256i_out = __lasx_xvbitrev_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000ff000000ff, 0x0000000000000000,
                      0x000000ff000000ff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fffffffffffffff, 0x7fffffff80000000,
                      0x7fffffffffffffff, 0x7fffffff80000000};
  __m256i_result = (__m256i){0x800000ff000000ff, 0x0000000000000001,
                             0x800000ff000000ff, 0x0000000000000001};
  __m256i_out = __lasx_xvbitrev_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
