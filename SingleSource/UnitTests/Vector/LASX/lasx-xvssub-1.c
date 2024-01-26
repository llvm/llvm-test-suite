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
  v4u64_op1 = (v4u64){0x00000000000001dc, 0x0000000000000000,
                      0x00000000000001dc, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000ff24, 0x0000000000000000,
                             0x000000000000ff24, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x2020202020202020, 0x2020202020202020,
                      0x2020202020202020, 0x2020202020202020};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x2020202020202020, 0x2020202020202020,
                             0x2020202020202020, 0x2020202020202020};
  __m256i_out = __lasx_xvssub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000430207f944, 0x0000000000000000,
                      0x000000430207f944, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000bdfef907bc, 0x0000000000000000,
                             0x000000bdfef907bc, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101000000010000, 0x0000010101010101,
                      0x0101000000010000, 0x0000010101010101};
  v4u64_op1 = (v4u64){0x0101000000010000, 0x0000010101010101,
                      0x0101000000010000, 0x0000010101010101};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000040, 0x0000000000000000,
                      0x0000000000000080, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000ffc0, 0x0000000000000000,
                             0x000000000000ff80, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x2a2ad4d4f2d8807e, 0x2b2b2b2b1bd68080,
                      0x2a2ad4d4f2d8807e, 0x2b2b2b2b1bd68080};
  __m256i_result = (__m256i){0xd5d62b2c0d287f82, 0xd4d5d4d5e42a7f80,
                             0xd5d62b2c0d287f82, 0xd4d5d4d5e42a7f80};
  __m256i_out = __lasx_xvssub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000080000001, 0x8000000080000001,
                      0x8000000080000001, 0x8000000080000001};
  v4u64_op1 = (v4u64){0x8000000080000001, 0x8000000080000001,
                      0x8000000080000001, 0x8000000080000001};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000b8070000a787, 0xffff07b4ffff0707,
                      0x0000b8070000a787, 0xffff07b4ffff0707};
  v4u64_op1 = (v4u64){0xffff47b4ffff5879, 0x0000504fffff3271,
                      0xffff47b4ffff5879, 0x0000504fffff3271};
  __m256i_result = (__m256i){0x0001800000018000, 0xffffb7650000d496,
                             0x0001800000018000, 0xffffb7650000d496};
  __m256i_out = __lasx_xvssub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff7fff00000000, 0x0000000000000000,
                      0x7fff7fff00000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000fc300000fc40, 0x0000000000000000,
                      0x0000fc300000fc40, 0x0000000000000000};
  __m256i_result = (__m256i){0x7fff7fff000003c0, 0x0000000000000000,
                             0x7fff7fff000003c0, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff81001dff9d003b, 0xff81001dff9dff9e,
                      0xff81001dff9d003b, 0xff81001dff9dff9e};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xff81001dff9d003b, 0xff81001dff9dff9e,
                             0xff81001dff9d003b, 0xff81001dff9dff9e};
  __m256i_out = __lasx_xvssub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  v4u64_op1 = (v4u64){0x000000000001fffe, 0x000000000001fffe,
                      0x000000000001fffe, 0x000000000001fffe};
  __m256i_result = (__m256i){0x00ff00ff00fd0101, 0x00ff00ff00fd0101,
                             0x00ff00ff00fd0101, 0x00ff00ff00fd0101};
  __m256i_out = __lasx_xvssub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000100000001, 0x0000000100000001,
                             0x0000000100000001, 0x0000000100000001};
  __m256i_out = __lasx_xvssub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff8000000000000, 0x40f69fe73c26f4ee,
                      0x7ff8000000000000, 0x40f69fe73c26f4ee};
  v4u64_op1 = (v4u64){0x00000001fffffff9, 0x00000001fffffff9,
                      0x00000001fffffff9, 0x00000001fffffff9};
  __m256i_result = (__m256i){0x7ff7ffff00000007, 0x40f69fe63c26f4f5,
                             0x7ff7ffff00000007, 0x40f69fe63c26f4f5};
  __m256i_out = __lasx_xvssub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffff00ffff8000, 0x0000000000000000,
                      0xffffff00ffff8000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000ff00007fff, 0x0000000000000000,
                             0x000000ff00007fff, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xfc00000000000000,
                      0x0000000000000000, 0xfc00000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xfc00000000000000,
                             0x0000000000000000, 0xfc00000000000000};
  __m256i_out = __lasx_xvssub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000001010800, 0x0000000000000000,
                      0x0000000001010800, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffffffefef800, 0x0000000000000000,
                             0xfffffffffefef800, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007f0000007f0060, 0x0000000000000000,
                      0x007f0000007f0060, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x007f0000007f0060, 0x0000000000000000,
                             0x007f0000007f0060, 0x0000000000000000};
  __m256i_out = __lasx_xvssub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x43b32feea9000000, 0x4393a0a5bc606060,
                      0x43b32feea9000000, 0x4393a0a5bc606060};
  v4u64_op1 = (v4u64){0x408480007fff0000, 0x3eab77367fff4848,
                      0x408480007fff0000, 0x3eab77367fff4848};
  __m256i_result = (__m256i){0x032eafee29010000, 0x04e8296f3c611818,
                             0x032eafee29010000, 0x04e8296f3c611818};
  __m256i_out = __lasx_xvssub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001ff91ff100000, 0x0001000000000000,
                      0x0001ff91ff100000, 0x0001000000000000};
  v4u64_op1 = (v4u64){0x0000000000000202, 0x0000000000800080,
                      0x0000000000000202, 0x0000000000800080};
  __m256i_result = (__m256i){0x0001ff91ff0ffdfe, 0x0000ffffff7fff80,
                             0x0001ff91ff0ffdfe, 0x0000ffffff7fff80};
  __m256i_out = __lasx_xvssub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000ff000000ff, 0x0000000000000000,
                      0x000000ff000000ff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8000000080000000, 0x8000000080000000,
                      0x8000000080000000, 0x8000000080000000};
  __m256i_result = (__m256i){0x7fffffffffffffff, 0x7fffffff80000000,
                             0x7fffffffffffffff, 0x7fffffff80000000};
  __m256i_out = __lasx_xvssub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
