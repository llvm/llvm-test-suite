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

  v4u64_op0 = (v4u64){0x0000040400000104, 0x0000000000000004,
                      0x0000441000000004, 0xffffd10000006459};
  __m256i_result = (__m256i){0x0f0f0f0f0f0f0f0f, 0x0f0f0f0f0f0f0f0f,
                             0x0f0f44100f0f0f0f, 0x0f0f0f0f0f0f6459};
  __m256i_out = __lasx_xvmaxi_b((__m256)v4u64_op0, 15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x80808081808080fb, 0x8080808180808093,
                      0x80808081808080fe, 0x8080808180808093};
  __m256i_result = (__m256i){0xf5f5f5f5f5f5f5fb, 0xf5f5f5f5f5f5f5f5,
                             0xf5f5f5f5f5f5f5fe, 0xf5f5f5f5f5f5f5f5};
  __m256i_out = __lasx_xvmaxi_b((__m256)v4u64_op0, -11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0909090909090909, 0x0909090909090909,
                             0x0909090909090909, 0x0909090909090909};
  __m256i_out = __lasx_xvmaxi_b((__m256)v4u64_op0, 9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_b((__m256)v4u64_op0, -4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0002000200020002, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0d0d0d0d0d0d0d0d, 0x0d0d0d0d0d0d0d0d,
                             0x0d0d0d0d0d0d0d0d, 0x0d0d0d0d0d0d0d0d};
  __m256i_out = __lasx_xvmaxi_b((__m256)v4u64_op0, 13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000007fffffff, 0x000000007fffffff,
                      0x000000007fffffff, 0x000000007fffffff};
  __m256i_result = (__m256i){0x0a0a0a0a7f0a0a0a, 0x0a0a0a0a7f0a0a0a,
                             0x0a0a0a0a7f0a0a0a, 0x0a0a0a0a7f0a0a0a};
  __m256i_out = __lasx_xvmaxi_b((__m256)v4u64_op0, 10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0707070707070707, 0x0707070707070707,
                             0x0707070707070707, 0x0707070707070707};
  __m256i_out = __lasx_xvmaxi_b((__m256)v4u64_op0, 7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0d0d0d0d0d0d0d0d, 0x0d0d0d0d0d0d0d0d,
                             0x0d0d0d0d0d0d0d0d, 0x0d0d0d0d0d0d0d0d};
  __m256i_out = __lasx_xvmaxi_b((__m256)v4u64_op0, 13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x2a2a2a2a2a2a2a2a, 0x2a2a2a2a2a2a2a2a,
                      0x2a2a2a2a2a2a2a2a, 0x2a2a2a2a2a2a2a2a};
  __m256i_result = (__m256i){0x2a2a2a2a2a2a2a2a, 0x2a2a2a2a2a2a2a2a,
                             0x2a2a2a2a2a2a2a2a, 0x2a2a2a2a2a2a2a2a};
  __m256i_out = __lasx_xvmaxi_b((__m256)v4u64_op0, -14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_b((__m256)v4u64_op0, 0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0c0c0c0c0c0c0c0c, 0x0c0c0c0c0c0c0c0c,
                             0x0c0c0c0c0c0c0c0c, 0x0c0c0c0c0c0c0c0c};
  __m256i_out = __lasx_xvmaxi_b((__m256)v4u64_op0, 12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0005000500050005, 0x0005000500050005,
                             0x0005000500050005, 0x0005000500050005};
  __m256i_out = __lasx_xvmaxi_h((__m256)v4u64_op0, 5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010001, 0x0001000100010001,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0001000100010001, 0x0001000100010001,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_h((__m256)v4u64_op0, -11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffc00000ffc0ffc0, 0xffc0ffc0ffc0ffc0,
                      0xffc00000ffc0ffc0, 0xffc0ffc0ffc0ffc0};
  __m256i_result = (__m256i){0xfff90000fff9fff9, 0xfff9fff9fff9fff9,
                             0xfff90000fff9fff9, 0xfff9fff9fff9fff9};
  __m256i_out = __lasx_xvmaxi_h((__m256)v4u64_op0, -7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaxi_h((__m256)v4u64_op0, -13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00040000, 0x00ff00ff00ff00ff,
                      0x00ff00ff000c0000, 0x00ff00ff00ff00ff};
  __m256i_result = (__m256i){0x00ff00ff00040000, 0x00ff00ff00ff00ff,
                             0x00ff00ff000c0000, 0x00ff00ff00ff00ff};
  __m256i_out = __lasx_xvmaxi_h((__m256)v4u64_op0, -2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffe0000000000, 0x00000000000001ff,
                      0xfffffe0000000000, 0x00000000000001ff};
  __m256i_result = (__m256i){0x0008000800080008, 0x00080008000801ff,
                             0x0008000800080008, 0x00080008000801ff};
  __m256i_out = __lasx_xvmaxi_h((__m256)v4u64_op0, 8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_h((__m256)v4u64_op0, 0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000c9, 0x0000000000000000,
                      0x00000000000000c9, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000000c9, 0x0000000000000000,
                             0x00000000000000c9, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_h((__m256)v4u64_op0, -15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000008000165a, 0x0000ffff8000ffa3,
                      0x000000008000165a, 0x0000ffff8000ffa3};
  __m256i_result = (__m256i){0x000900090009165a, 0x0009000900090009,
                             0x000900090009165a, 0x0009000900090009};
  __m256i_out = __lasx_xvmaxi_h((__m256)v4u64_op0, 9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_h((__m256)v4u64_op0, 0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfd12fd12fd12fd12, 0xfd12fd12fd12fd12,
                      0xfd12fd12fd12fd12, 0xfd12fd12fd12fd12};
  __m256i_result = (__m256i){0x000a000a000a000a, 0x000a000a000a000a,
                             0x000a000a000a000a, 0x000a000a000a000a};
  __m256i_out = __lasx_xvmaxi_h((__m256)v4u64_op0, 10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000001000000, 0x0000000001000000,
                      0x0000000001000000, 0x0000000001000000};
  __m256i_result = (__m256i){0x0000000401000000, 0x0000000401000000,
                             0x0000000401000000, 0x0000000401000000};
  __m256i_out = __lasx_xvmaxi_w((__m256)v4u64_op0, 4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_w((__m256)v4u64_op0, -16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0110000000000080, 0x0110000000000000,
                      0x0110000000000080, 0x0110000000000000};
  __m256i_result = (__m256i){0x0110000000000080, 0x0110000000000004,
                             0x0110000000000080, 0x0110000000000004};
  __m256i_out = __lasx_xvmaxi_w((__m256)v4u64_op0, 4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_w((__m256)v4u64_op0, -11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000200000002, 0x0000000200000002,
                             0x0000000200000002, 0x0000000200000002};
  __m256i_out = __lasx_xvmaxi_w((__m256)v4u64_op0, 2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000e0000000e, 0x0000000e0000000e,
                             0x0000000e0000000e, 0x0000000e0000000e};
  __m256i_out = __lasx_xvmaxi_w((__m256)v4u64_op0, 14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffff040000000000,
                      0x0000000000000000, 0xffff040000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xfffffff400000000,
                             0x0000000000000000, 0xfffffff400000000};
  __m256i_out = __lasx_xvmaxi_w((__m256)v4u64_op0, -12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000ffffffff,
                      0x0000000000000000, 0x00000000ffffffff};
  __m256i_result = (__m256i){0x0000000900000009, 0x0000000900000009,
                             0x0000000900000009, 0x0000000900000009};
  __m256i_out = __lasx_xvmaxi_w((__m256)v4u64_op0, 9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xe07de0801f20607a, 0xffffffffffffffff,
                      0xe07de0801f20607a, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x000000081f20607a, 0x0000000800000008,
                             0x000000081f20607a, 0x0000000800000008};
  __m256i_out = __lasx_xvmaxi_w((__m256)v4u64_op0, 8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000000000000,
                             0x00000000ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_w((__m256)v4u64_op0, -2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0x000000000000ff80, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000ffff, 0x0000000000000000,
                             0x000000000000ff80, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_d((__m256)v4u64_op0, -16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000009, 0x0000000000000009,
                             0x0000000000000009, 0x0000000000000009};
  __m256i_out = __lasx_xvmaxi_d((__m256)v4u64_op0, 9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_d((__m256)v4u64_op0, -2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000004560420, 0x0000000000ff1100,
                      0x0000000004560420, 0x0000000000ff1100};
  __m256i_result = (__m256i){0x0000000004560420, 0x0000000000ff1100,
                             0x0000000004560420, 0x0000000000ff1100};
  __m256i_out = __lasx_xvmaxi_d((__m256)v4u64_op0, -14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaxi_d((__m256)v4u64_op0, -1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7e00000000000000, 0x000000007e1c7e1c,
                      0x7e00000000000000, 0x000000007e1c7e1c};
  __m256i_result = (__m256i){0x7e00000000000000, 0x000000007e1c7e1c,
                             0x7e00000000000000, 0x000000007e1c7e1c};
  __m256i_out = __lasx_xvmaxi_d((__m256)v4u64_op0, -9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0xffffffff00000000,
                      0xffffffff00000000, 0xffffffff00000000};
  __m256i_result = (__m256i){0xfffffffffffffff5, 0xfffffffffffffff5,
                             0xfffffffffffffff5, 0xfffffffffffffff5};
  __m256i_out = __lasx_xvmaxi_d((__m256)v4u64_op0, -11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000007, 0x0000000000000007,
                             0x0000000000000007, 0x0000000000000007};
  __m256i_out = __lasx_xvmaxi_d((__m256)v4u64_op0, 7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000007b007e, 0x0000000000000000,
                      0x00000000007b007e, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000007b007e, 0x0000000000000002,
                             0x00000000007b007e, 0x0000000000000002};
  __m256i_out = __lasx_xvmaxi_d((__m256)v4u64_op0, 2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
