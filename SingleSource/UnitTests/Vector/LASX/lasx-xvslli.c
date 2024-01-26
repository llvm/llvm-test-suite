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

  v4u64_op0 = (v4u64){0x0010100000000000, 0xfff1001100100000,
                      0x0010100000000000, 0xfff1001100100000};
  __m256i_result = (__m256i){0x0040400000000000, 0xfcc4004400400000,
                             0x0040400000000000, 0xfcc4004400400000};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff0000000000000, 0xfff0000000000000,
                      0xfff0000000000000, 0xfff0000000000000};
  __m256i_result = (__m256i){0xf000000000000000, 0xf000000000000000,
                             0xf000000000000000, 0xf000000000000000};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x161616167fffffff, 0x7ffe16167f161616,
                      0x161616167fffffff, 0x1616161616161616};
  __m256i_result = (__m256i){0x2c2c2c2cfefefefe, 0xfefc2c2cfe2c2c2c,
                             0x2c2c2c2cfefefefe, 0x2c2c2c2c2c2c2c2c};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xf8f8f8f8f8f8f8f8, 0xf8f8f8f8f8f8f8f8,
                             0xf8f8f8f8f8f8f8f8, 0xf8f8f8f8f8f8f8f8};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000001, 0x0000000100000001,
                      0x0000000100000001, 0x0000000100000001};
  __m256i_result = (__m256i){0x0000008000000080, 0x0000008000000080,
                             0x0000008000000080, 0x0000008000000080};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x00000000ffffffff,
                      0xffffffffffffffff, 0x00000000ffffffff};
  __m256i_result = (__m256i){0xf0f0f0f0f0f0f0f0, 0x00000000f0f0f0f0,
                             0xf0f0f0f0f0f0f0f0, 0x00000000f0f0f0f0};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xfefefefefefefefe, 0xfefefefefefefefe,
                             0xfefefefefefefefe, 0xfefefefefefefefe};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000001,
                      0x0000000000000000, 0x0000000000000001};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000008,
                             0x0000000000000000, 0x0000000000000008};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000080000000, 0x00000004843ffdff,
                      0x8000000080000000, 0x00000004843ffdff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000c040c0,
                             0x0000000000000000, 0x0000000000c040c0};
  __m256i_out = __lasx_xvslli_b((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffefffffffef, 0xffffffefffffffef,
                      0xffffffef000004ea, 0xffffffefffffffef};
  __m256i_result = (__m256i){0xffffffefffffffef, 0xffffffefffffffef,
                             0xffffffef000004ea, 0xffffffefffffffef};
  __m256i_out = __lasx_xvslli_h((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffffffffc, 0xfffffffffffffffc,
                      0xfffffffffffffbf4, 0xfffffffffffffff8};
  __m256i_result = (__m256i){0xf800f800f800e000, 0xf800f800f800e000,
                             0xf800f800f800a000, 0xf800f800f800c000};
  __m256i_out = __lasx_xvslli_h((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffefefffffefe, 0x0000000000000000,
                      0xfffffefefffffefe, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffefefffffefe, 0x0000000000000000,
                             0xfffffefefffffefe, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_h((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1f60000000c00000, 0x0000000000000000,
                      0x1f60000000c00000, 0x0000000000000000};
  __m256i_result = (__m256i){0x60000000c0000000, 0x0000000000000000,
                             0x60000000c0000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_h((__m256)v4u64_op0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff8fff8fff8fff8, 0x0000000000000000,
                      0xfff8fff8fff8fff8, 0x0000000000000000};
  __m256i_result = (__m256i){0xff80ff80ff80ff80, 0x0000000000000000,
                             0xff80ff80ff80ff80, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_h((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xf800f800f800f800, 0xf800f800f800f800,
                             0xf800f800f800f800, 0xf800f800f800f800};
  __m256i_out = __lasx_xvslli_h((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_h((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_h((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_h((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x008102c2008a029f, 0x024c01f901950261,
                      0x030d03aa0079029b, 0x01fa022a01a401e5};
  __m256i_result = (__m256i){0x840000003e000000, 0xf2000000c2000000,
                             0x5400000036000000, 0x54000000ca000000};
  __m256i_out = __lasx_xvslli_w((__m256)v4u64_op0, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf000000000000000, 0x0000000000000000,
                      0xf000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_w((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_w((__m256)v4u64_op0, 0x12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_w((__m256)v4u64_op0, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_w((__m256)v4u64_op0, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x4040404040404040, 0x4040404040404040,
                      0x4040404040404040, 0x4040404040404040};
  __m256i_result = (__m256i){0x0404000004040000, 0x0404000004040000,
                             0x0404000004040000, 0x0404000004040000};
  __m256i_out = __lasx_xvslli_w((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_d((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010001, 0x0001000100010001,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0100010001000000, 0x0100010001000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_d((__m256)v4u64_op0, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0008000800080008, 0x00080008000801ff,
                      0x0008000800080008, 0x00080008000801ff};
  __m256i_result = (__m256i){0x0000000000000000, 0x8000000000000000,
                             0x0000000000000000, 0x8000000000000000};
  __m256i_out = __lasx_xvslli_d((__m256)v4u64_op0, 0x3f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000003f, 0x0000000000000000,
                      0x000000000000003f, 0x0000000000000000};
  __m256i_result = (__m256i){0x03f0000000000000, 0x0000000000000000,
                             0x03f0000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_d((__m256)v4u64_op0, 0x34);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffffffff80000, 0x0000000000000000,
                             0xfffffffffff80000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_d((__m256)v4u64_op0, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_d((__m256)v4u64_op0, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffff000000, 0x0000000000000000,
                             0xffffffffff000000, 0x0000000000000000};
  __m256i_out = __lasx_xvslli_d((__m256)v4u64_op0, 0x18);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
