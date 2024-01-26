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

  v4u64_op0 = (v4u64){0xc70000020000c000, 0xc9d8080067f50020,
                      0x0000800080000000, 0x8000800000000000};
  __m256i_result = (__m256i){0xf00000020000f000, 0xf0f008000ff5000f,
                             0x0000f000f0000000, 0xf000f00000000000};
  __m256i_out = __lasx_xvsat_b((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x0000ffff0000ffff,
                      0x000000000000ff80, 0x000000000000ffff};
  __m256i_result = (__m256i){0x000000000000ffff, 0x0000ffff0000ffff,
                             0x000000000000fff8, 0x000000000000ffff};
  __m256i_out = __lasx_xvsat_b((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_b((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000e000e000e000e, 0x0000000000000000,
                      0x000e000e000e000e, 0x0000000000000000};
  __m256i_result = (__m256i){0x000e000e000e000e, 0x0000000000000000,
                             0x000e000e000e000e, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_b((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x00000000ffffffff,
                      0xffffffffffffffff, 0x00000000ffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x00000000ffffffff,
                             0xffffffffffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvsat_b((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_b((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_b((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003fe50001c013, 0x00003fea00013fec,
                      0x00003fe50001c013, 0x00003fea00013fec};
  __m256i_result = (__m256i){0x000000ff0000ff00, 0x000000ff000000ff,
                             0x000000ff0000ff00, 0x000000ff000000ff};
  __m256i_out = __lasx_xvsat_b((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000399400003994, 0x0000399400003994,
                      0x0000399400003994, 0x0000399400003994};
  __m256i_result = (__m256i){0x00000fff00000fff, 0x00000fff00000fff,
                             0x00000fff00000fff, 0x00000fff00000fff};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfebdff3eff3dff52, 0xfebdff3eff3dff52,
                      0xfebdff3eff3dff52, 0xfebdff3eff3dff52};
  __m256i_result = (__m256i){0xffc0ffc0ffc0ffc0, 0xffc0ffc0ffc0ffc0,
                             0xffc0ffc0ffc0ffc0, 0xffc0ffc0ffc0ffc0};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffe05ffffe911, 0x00002df900001700,
                      0xfffffe05ffffe911, 0x00002df900001700};
  __m256i_result = (__m256i){0xfffffffcfffffffc, 0x0000000300000003,
                             0xfffffffcfffffffc, 0x0000000300000003};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffdd97dc4, 0xffffffffffff0001,
                      0xfffffffffdd97dc4, 0xffffffffffff0001};
  __m256i_result = (__m256i){0xfffffffffdd97dc4, 0xffffffffffff0001,
                             0xfffffffffdd97dc4, 0xffffffffffff0001};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000014402080144, 0x0000000000000000,
                      0x0000014402080144, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000007f007f007f, 0x0000000000000000,
                             0x0000007f007f007f, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000ffffff, 0xffffffffffffffff,
                      0x0000000000ffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x00000000003fffff, 0xffffffffffffffff,
                             0x00000000003fffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsat_h((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0049004200000000, 0x0002000200000022,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000007f00000000, 0x0000007f00000022,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xfffffffefffffefd, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xfffffffefffffefd, 0xfffffffffffffffe};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00c200c200c200bb, 0x00c200c200c200c2,
                      0x00c200c200c200bb, 0x00c200c200c200c2};
  __m256i_result = (__m256i){0x007fffff007fffff, 0x007fffff007fffff,
                             0x007fffff007fffff, 0x007fffff007fffff};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0020002000200020, 0x0000000000000000,
                      0x0020002000200020, 0x0000000000000000};
  __m256i_result = (__m256i){0x0001ffff0001ffff, 0x0000000000000000,
                             0x0001ffff0001ffff, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000080000000800, 0x0000080000001000,
                      0x0000080000000800, 0x0000080000001000};
  __m256i_result = (__m256i){0x0000000f0000000f, 0x0000000f0000000f,
                             0x0000000f0000000f, 0x0000000f0000000f};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000b8f81b8c840e4, 0x000050504c4c2362,
                      0x000b8f81b8c840e4, 0x000050504c4c2362};
  __m256i_result = (__m256i){0x000007fffffff800, 0x000007ff000007ff,
                             0x000007fffffff800, 0x000007ff000007ff};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0x12);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0x10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0x13);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_w((__m256)v4u64_op0, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x97541c5897541c58, 0x97541c5897541c58,
                      0x97541c5897541c58, 0x97541c5897541c58};
  __m256i_result = (__m256i){0xfffffffc00000000, 0xfffffffc00000000,
                             0xfffffffc00000000, 0xfffffffc00000000};
  __m256i_out = __lasx_xvsat_d((__m256)v4u64_op0, 0x22);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffff605a, 0xffffffffffff5f5c,
                      0xffffffffffff605a, 0xffffffffffff5f5c};
  __m256i_result = (__m256i){0xffffffffffff605a, 0xffffffffffff5f5c,
                             0xffffffffffff605a, 0xffffffffffff5f5c};
  __m256i_out = __lasx_xvsat_d((__m256)v4u64_op0, 0x2d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffff8d9ffa7103d, 0x0000000000000000,
                      0xff8f0842ff29211e, 0x001175f10e4330e8};
  __m256i_result = (__m256i){0xfffff8d9ffa7103d, 0x0000000000000000,
                             0xff8f0842ff29211e, 0x001175f10e4330e8};
  __m256i_out = __lasx_xvsat_d((__m256)v4u64_op0, 0x39);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0xfffffffffffffffe,
                      0x0000000000000001, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0x0000000000000001, 0xfffffffffffffffe,
                             0x0000000000000001, 0xfffffffffffffffe};
  __m256i_out = __lasx_xvsat_d((__m256)v4u64_op0, 0x21);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc2c2c2c2c2c2c2c2, 0xc2c2c2c2c2c2c2c2,
                      0xc2c2c2c2c2c2c2c2, 0xc2c2c2c2c2c2c2c2};
  __m256i_result = (__m256i){0xfffe000000000000, 0xfffe000000000000,
                             0xfffe000000000000, 0xfffe000000000000};
  __m256i_out = __lasx_xvsat_d((__m256)v4u64_op0, 0x31);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  __m256i_result = (__m256i){0x00000001ffffffff, 0x00000001ffffffff,
                             0x00000001ffffffff, 0x00000001ffffffff};
  __m256i_out = __lasx_xvsat_d((__m256)v4u64_op0, 0x21);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_d((__m256)v4u64_op0, 0x3d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_d((__m256)v4u64_op0, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x4980008068400000, 0x498000804843ffe0,
                      0x4980008068400000, 0x498000804843ffe0};
  __m256i_result = (__m256i){0x0fffffffffffffff, 0x0fffffffffffffff,
                             0x0fffffffffffffff, 0x0fffffffffffffff};
  __m256i_out = __lasx_xvsat_d((__m256)v4u64_op0, 0x3c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffe97c020010001, 0xfffeb6839ffffd80,
                      0xfffe97c020010001, 0xfffeb6839ffffd80};
  __m256i_result = (__m256i){0xfffffffffffffff8, 0xfffffffffffffff8,
                             0xfffffffffffffff8, 0xfffffffffffffff8};
  __m256i_out = __lasx_xvsat_d((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc0000000c0000000, 0x00000002c21ffeff,
                      0xc0000000c0000000, 0x00000002c21ffeff};
  __m256i_result = (__m256i){0xfffffffffffffff8, 0x0000000000000007,
                             0xfffffffffffffff8, 0x0000000000000007};
  __m256i_out = __lasx_xvsat_d((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_d((__m256)v4u64_op0, 0x32);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
