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
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000001,
                      0x0000000000000001, 0x0000000000000001};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvmaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffff800000000000, 0xffff800000000000,
                      0xffff800000000000, 0xffff800000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000007f7f7f80, 0x0000000000000000,
                      0x000000007f7f7f80, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000007f7f7f80, 0x0000000000000000,
                             0x000000007f7f7f80, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000002000000, 0x0200000002000000,
                      0x0000000002000000, 0x0200000002000000};
  v4u64_op1 = (v4u64){0xf2b180c9fc1fefdc, 0xffffffff01fb0408,
                      0xf2b180c9fc1fefdc, 0xffffffff01fb0408};
  v4u64_op2 = (v4u64){0x00003cfc0000006f, 0x0000008000000080,
                      0x00003cfc0000006f, 0x0000008000000080};
  __m256i_result = (__m256i){0x0000c5dc02005f64, 0x02007f8002000400,
                             0x0000c5dc02005f64, 0x02007f8002000400};
  __m256i_out = __lasx_xvmaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000700020004, 0x0000000600000006,
                      0x0000000700020004, 0x0000000600000006};
  v4u64_op1 = (v4u64){0x0000000000000002, 0x0000000000000000,
                      0x0000000000000002, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000003, 0x0040000000000003,
                      0x0000000000000003, 0x0040000000000003};
  __m256i_result = (__m256i){0x000000070002000a, 0x0000000600000006,
                             0x000000070002000a, 0x0000000600000006};
  __m256i_out = __lasx_xvmaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff874dc687870000, 0x00000000003f7e3f,
                      0xffc6cc05c64d960e, 0x00000000003f7e3f};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x41dfffdfffc00000,
                      0x0000000000000000, 0x41dfffc000000000};
  v4u64_op2 = (v4u64){0x5b409c0000000000, 0x0001fbf9fbe29f52,
                      0x5b409c0000000000, 0x0001fbf9fbe29f52};
  __m256i_result = (__m256i){0xff874dc687870000, 0xfbd884e7003f7e3f,
                             0xffc6cc05c64d960e, 0xfbba01c0003f7e3f};
  __m256i_out = __lasx_xvmaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000003fff3fff, 0x3fff3fff3fff3fff,
                      0x000000003fff3fff, 0x3fff3fff3fff3fff};
  v4u64_op1 = (v4u64){0x0000000000000800, 0x0000000000000001,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000800, 0x0000000000000001,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000403f3fff, 0x3fff3fff3fff4000,
                             0x000000003fff3fff, 0x3fff3fff3fff3fff};
  __m256i_out = __lasx_xvmaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x40effc0000000000,
                      0x0000000000000000, 0x40effc0000000000};
  v4u64_op1 = (v4u64){0x7f017fc0ddbf7d86, 0x00007f7f7f7f0000,
                      0x00010003fc827a86, 0x00007f7f7f7f7f7f};
  v4u64_op2 = (v4u64){0xff15c1ea95ea02ff, 0x0000ffffffff0100,
                      0x00153f1594ea02ff, 0x0000ffffffffffff};
  __m256i_result = (__m256i){0x60c485800178147a, 0xc06e7c8100000000,
                             0x0000bd3f016f177a, 0xc06e7c817f7e8081};
  __m256i_out = __lasx_xvmaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000165a, 0x0000000000000000,
                      0x000000000000165a, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000011f, 0x0000000000000000,
                      0x000000000000011f, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x000000000000165a, 0x0000ffff0000ffa3,
                      0x000000000000165a, 0x0000ffff0000ffa3};
  __m256i_result = (__m256i){0x0000000000192540, 0x0000000000000000,
                             0x0000000000192540, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ff88ff88, 0x8000000000000000,
                      0x00000000ff88ff88, 0x8000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x8000000000000000,
                      0x0000000000000000, 0x8000000000000000};
  __m256i_result = (__m256i){0x00000000ff88ff88, 0x8000000000000000,
                             0x00000000ff88ff88, 0x8000000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffdf5b000041b0, 0xfffffffeffff97a1,
                      0xffffdf5b000041b0, 0xfffffffeffff97a1};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x07fed3c8f7ad28d0, 0x07fee332883f86b0,
                      0x07fed3c8f7ad28d0, 0x07fee332883f86b0};
  __m256i_result = (__m256i){0xffffdf5b000041b0, 0xfffffffeffff97a1,
                             0xffffdf5b000041b0, 0xfffffffeffff97a1};
  __m256i_out = __lasx_xvmaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000fb8000000000,
                      0x0000000000000000, 0x0000fb8000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000001c0, 0xc03fc03f000001c0,
                      0x0000000000007380, 0x807f807f00000380};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0004000400040004, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000001c0, 0xc03fc03f000001c0,
                             0x0000000000007380, 0x807f807f00000380};
  __m256i_out = __lasx_xvmaddwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff80ff00ff80ff01, 0x0000000000000000,
                      0xff80ff00ff80ff01, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xf711ee11f711ee11, 0x007f00ff007f00ff,
                      0xf711ee11f711ee91, 0x007f00ff007f00fe};
  __m256i_result = (__m256i){0xff80ff00ff80ff01, 0x0000000000000000,
                             0xff80ff00ff80ff01, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000080000000, 0xffffffffffffffff,
                      0x8000000080000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x4980008068400000, 0x498000804843ffe0,
                      0x4980008068400000, 0x498000804843ffe0};
  v4u64_op2 = (v4u64){0xffff800300000000, 0xffff801000000010,
                      0xffff800300000000, 0xffff801000000010};
  __m256i_result = (__m256i){0x8000000080000000, 0x00000004843ffdff,
                             0x8000000080000000, 0x00000004843ffdff};
  __m256i_out = __lasx_xvmaddwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x01fe01fe00000000, 0x01fe01fe01fe01fe,
                      0x01fe01fe01fe01fe, 0x01fe01fe01fe01fe};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000010000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000001fffc0001, 0x00000001fffc0001,
                      0x00000001fffc0001, 0x00000001fffc0001};
  v4u64_op1 = (v4u64){0x00000001fffc0001, 0x00000001fffc0001,
                      0x00000001fffc0001, 0x00000001fffc0001};
  v4u64_op2 = (v4u64){0x0000000000000022, 0x0000000000000000,
                      0x0000000000000022, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000045ff740023, 0x00000001fffc0001,
                             0x00000045ff740023, 0x00000001fffc0001};
  __m256i_out = __lasx_xvmaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x0000fffe00800022,
                      0x00000000ffffffff, 0x0000fffe00800022};
  v4u64_op2 = (v4u64){0xffffffff00000000, 0xffffffffffffffff,
                      0xffffffff00000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000100000000, 0x00000000fffffffe,
                             0x0000000100000001, 0x00000000fffffffe};
  __m256i_out = __lasx_xvmaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x7fffffff7fffffff,
                      0x0000000000000000, 0x7fffffff7fffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000016e00, 0x0000000000000000,
                      0x0000000000016e00, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000b70000, 0x0000000000000000,
                      0x000000000155b200, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000016e00, 0x0000000000000000,
                             0x0000000000016e00, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x000001e001e001e0,
                      0x0000000000000000, 0x000001e001e001e0};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
