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

  v4u64_op0 = (v4u64){0x000000003fff3fff, 0x3fff3fff3fff3fff,
                      0x000000003fff3fff, 0x3fff3fff3fff3fff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000000000000,
                             0x00000000ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000030007, 0x00000000003f0000,
                      0x0000000000030007, 0x00000000003f0000};
  v4u64_op1 = (v4u64){0x0000000000030007, 0x00000000003f0000,
                      0x0000000000030007, 0x00000000003f0000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffff47b4ffff5879, 0x0000504fffff3271,
                      0xffff47b4ffff5879, 0x0000504fffff3271};
  __m256i_result = (__m256i){0x0001004c0001ff87, 0x0000ffb10001ff8f,
                             0x0001004c0001ff87, 0x0000ffb10001ff8f};
  __m256i_out = __lasx_xvsubwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000008, 0x0000000000000000,
                      0x0000000000000008, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffffffffffff7, 0xffffffffffffffff,
                             0xfffffffffffffff7, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsubwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000ff02ff80fede,
                      0x0000000000000000, 0x0000ff02ff80fede};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000fffe00800022,
                             0x00000000ffffffff, 0x0000fffe00800022};
  __m256i_out = __lasx_xvsubwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0001000100010001, 0x0001000100010001,
                             0x0001000100010001, 0x0001000100010001};
  __m256i_out = __lasx_xvsubwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x8000000000000000,
                      0x0000000000000000, 0x8000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000100040, 0x0000000000000040,
                      0x0000000000100040, 0x0000000000000040};
  __m256i_result = (__m256i){0x00000000fff0ffc0, 0x000000000000ffc0,
                             0x00000000fff0ffc0, 0x000000000000ffc0};
  __m256i_out = __lasx_xvsubwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000001010000, 0x0000000000000000,
                      0x0000000001010000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffff0000, 0x0000000000000000,
                             0x00000000ffff0000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff00017fff0000, 0x7fff00017fff0000,
                      0x7fff00017fff0000, 0x7fff00017fff0000};
  v4u64_op1 = (v4u64){0xffffffe4ffffffe4, 0xffffffe4ffffffe4,
                      0xffffffe4ffffffe4, 0xffffffe4ffffffe4};
  __m256i_result = (__m256i){0x0000001d0000001c, 0x0000001d0000001c,
                             0x0000001d0000001c, 0x0000001d0000001c};
  __m256i_out = __lasx_xvsubwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffff000000, 0xffffffffff000000,
                      0xffffffffff000000, 0xffffffffff000000};
  v4u64_op1 = (v4u64){0x0000010000000000, 0x0000000000000000,
                      0x0000010000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffeff00000000, 0xffffffff00000000,
                             0xfffffeff00000000, 0xffffffff00000000};
  __m256i_out = __lasx_xvsubwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xfffffffffffffefd, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0101010101010101, 0x0101010101010101,
                      0x0101010101010203, 0x0101010101010101};
  __m256i_result = (__m256i){0xfffffefefffffefe, 0xfffffefefffffefe,
                             0xfffffefefffffcfa, 0xfffffefefffffefe};
  __m256i_out = __lasx_xvsubwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000600000006, 0x0000000600000006,
                      0x0000000600000006, 0x0000000600000006};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000600000006, 0x0000000600000006,
                             0x0000000600000006, 0x0000000600000006};
  __m256i_out = __lasx_xvsubwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xbff0000000000000, 0xbff0000000000000,
                      0xbff0000000000000, 0xbff0000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x000000fffffffefe, 0x0000000000000102};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0x0000000000000101, 0xfffffffffffffefd};
  __m256i_out = __lasx_xvsubwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000003f, 0x000000000000003f,
                      0x000000000000003f, 0x000000000000003f};
  v4u64_op1 = (v4u64){0x000000000000003f, 0x000000000000003f,
                      0x000000000000003f, 0x000000000000003f};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7,
                      0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7};
  __m256i_result = (__m256i){0x0000000008080809, 0x0000000008080809,
                             0x0000000008080809, 0x0000000008080809};
  __m256i_out = __lasx_xvsubwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000300000003, 0x0000000300000003,
                      0x0000000300000003, 0x0000000300000003};
  __m256i_result = (__m256i){0xfffffffffffffffd, 0xfffffffffffffffd,
                             0xfffffffffffffffd, 0xfffffffffffffffd};
  __m256i_out = __lasx_xvsubwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c,
                      0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c};
  v4u64_op1 = (v4u64){0x0000000400000004, 0x0000000000000000,
                      0x0000000400000004, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffff1cff18, 0xffffffffff1cff1c,
                             0xffffffffff1cff18, 0xffffffffff1cff1c};
  __m256i_out = __lasx_xvsubwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvsubwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000003c01ff9, 0x0000000000000000,
                      0x0000000003c01ff9, 0x0000000000001400};
  __m256i_result = (__m256i){0xfffffffffc3fe007, 0x0000000000000000,
                             0xfffffffffc3fe007, 0xffffffffffffec00};
  __m256i_out = __lasx_xvsubwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffff0000ffff0000, 0x0000000000000000,
                      0xffff0000ffff0000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff00010000, 0x0000000000000000,
                             0x0000ffff00010000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffefefffffefe, 0x0000000000000000,
                      0xfffffefefffffefe, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000010100000102, 0x0000000000000000,
                             0x0000010100000102, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007fffff007fffff, 0x007fffff0000ffff,
                      0x007fffff007fffff, 0x007fffff0000ffff};
  v4u64_op1 = (v4u64){0x00c200c200c200bb, 0x00c200c200c200c2,
                      0x00c200c200c200bb, 0x00c200c200c200c2};
  __m256i_result = (__m256i){0xffbdff3cffbdff44, 0xffffffffffffffff,
                             0xffbdff3cffbdff44, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsubwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
