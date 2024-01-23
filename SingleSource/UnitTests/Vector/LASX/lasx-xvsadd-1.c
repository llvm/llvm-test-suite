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

  v4u64_op0 = (v4u64){0x00000000403f3fff, 0x3fff3fff3fff4000,
                      0x000000003fff3fff, 0x3fff3fff3fff3fff};
  v4u64_op1 = (v4u64){0x00000000403f3fff, 0x3fff3fff3fff4000,
                      0x000000003fff3fff, 0x3fff3fff3fff3fff};
  __m256i_result = (__m256i){0x00000000807e7ffe, 0x7ffe7ffe7ffe8000,
                             0x000000007ffe7ffe, 0x7ffe7ffe7ffe7ffe};
  __m256i_out = __lasx_xvadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x6161616161616161, 0x6161616161616161,
                      0x6161616161616161, 0x6161616161616161};
  v4u64_op1 = (v4u64){0x6161616161616161, 0x6161616161616161,
                      0x6161616161616161, 0x6161616161616161};
  __m256i_result = (__m256i){0xc2c2c2c2c2c2c2c2, 0xc2c2c2c2c2c2c2c2,
                             0xc2c2c2c2c2c2c2c2, 0xc2c2c2c2c2c2c2c2};
  __m256i_out = __lasx_xvadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7f807f007f7f817f, 0x9ff87ef07f7f817f,
                      0x7f807f007f7f817f, 0x9ff87ef07f7f817f};
  __m256i_result = (__m256i){0x7f807f007f7f817f, 0x9ff87ef07f7f817f,
                             0x7f807f007f7f817f, 0x9ff87ef07f7f817f};
  __m256i_out = __lasx_xvadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffff0020001d001f,
                      0x0000000000000000, 0xffff0020001d001f};
  __m256i_result = (__m256i){0x0000000000000000, 0xffff0020001d001f,
                             0x0000000000000000, 0xffff0020001d001f};
  __m256i_out = __lasx_xvadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000800200028, 0x0000000800200027,
                      0x0000000800200028, 0x0000000800200027};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x000000006040190d,
                      0x0000000000000000, 0x000000006040190d};
  __m256i_result = (__m256i){0x0000000800200028, 0x0000000860601934,
                             0x0000000800200028, 0x0000000860601934};
  __m256i_out = __lasx_xvadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000010001, 0x0000000000000000,
                      0x0000000000010001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000ffff0000000d,
                      0x0000000000000000, 0x0000ffff0000000d};
  __m256i_result = (__m256i){0x0000000000010001, 0x0000ffff0000000d,
                             0x0000000000010001, 0x0000ffff0000000d};
  __m256i_out = __lasx_xvadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvadd_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsadd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x003f003f003f003f,
                      0x0000000000000000, 0x003f003f003f003f};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xff3eff3eff3eff3e,
                             0xffffffffffffffff, 0xff3eff3eff3eff3e};
  __m256i_out = __lasx_xvsadd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xa020202020206431, 0xa020202020202020,
                      0xa020202020206431, 0xa020202020202020};
  __m256i_result = (__m256i){0xa020202020206431, 0xa020202020202020,
                             0xa020202020206431, 0xa020202020202020};
  __m256i_out = __lasx_xvsadd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffa80000ff31, 0x0000fff90000ff78,
                      0x0000ff050000ff3c, 0x0000ffee0000ff4c};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffa80000ff31, 0x0000fff90000ff78,
                             0x0000ff050000ff3c, 0x0000ffee0000ff4c};
  __m256i_out = __lasx_xvsadd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ff810011, 0x0000000000000000,
                      0x00000000ff810011, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ff810011, 0x0000000000000000,
                             0x00000000ff810011, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff00000000000000, 0xffffff00ffffff00,
                      0xff00000000000000, 0xffffff00ffffff00};
  v4u64_op1 = (v4u64){0x0000000200000008, 0x0000000000000000,
                      0x0000000200000008, 0x0000000000000000};
  __m256i_result = (__m256i){0xff00000200000008, 0xffffff00ffffff00,
                             0xff00000200000008, 0xffffff00ffffff00};
  __m256i_out = __lasx_xvsadd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0xffffffffffff8000};
  v4u64_op1 = (v4u64){0x7fffffff80000000, 0x0000000000000000,
                      0x7fffffff80000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7efefefe80ffffff, 0x0000000000000000,
                             0x7efefefe80ffffff, 0xffffffffffff8000};
  __m256i_out = __lasx_xvsadd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsadd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00007fe000007fe0, 0x00007fde00007fd4,
                      0x00007fe000007fe0, 0x00007fde00007fd4};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffff7edfffff7edf, 0xffff7eddffff7ed3,
                             0xffff7edfffff7edf, 0xffff7eddffff7ed3};
  __m256i_out = __lasx_xvsadd_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xe032c739adcc6bbd, 0x280ac9da313863f4,
                      0x000000003a0a9512, 0xffffffffffc81aca};
  v4u64_op1 = (v4u64){0x0000fffffffffffe, 0x0001000100020001,
                      0x0000ffff00010000, 0xfffe000000000000};
  __m256i_result = (__m256i){0xe032c738adcb6bbb, 0x280bc9db313a63f5,
                             0x0000ffff3a0b9512, 0xfffdffffffc81aca};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000000000000,
                             0x00000000ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000001, 0x0000000100000001,
                      0x0000000100000001, 0x0000000100000001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x1fe01e0000000000,
                      0x0000000000000000, 0x1fe01e0000000000};
  __m256i_result = (__m256i){0x0000000100000001, 0x1fe01e0100000001,
                             0x0000000100000001, 0x1fe01e0100000001};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000fffffffa, 0x0000000000000000,
                      0x00000000fffffffa, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000fffffffa, 0x0000000000000000,
                             0x00000000fffffffa, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000383fffffdf0d, 0xf800d0d8ffffeecf,
                      0x0000383fffffdf0d, 0xf800d0d8ffffeecf};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xf000f000ffffffff,
                      0xffffffffffffffff, 0xf000f000ffffffff};
  __m256i_result = (__m256i){0xffff383efffedf0c, 0xe800c0d8fffeeece,
                             0xffff383efffedf0c, 0xe800c0d8fffeeece};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff0000ffff0001, 0xffffffffffffffff,
                      0xffff0000ffff0001, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffff0000ffff0001, 0xffffffffffffffff,
                      0xffff0000ffff0001, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xfffe0000fffe0002, 0xfffefffefffefffe,
                             0xfffe0000fffe0002, 0xfffefffefffefffe};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7575757575757575, 0x7575757575757575,
                      0x7575757575757575, 0x7575757575757575};
  __m256i_result = (__m256i){0x7575757575757575, 0x7575757575757575,
                             0x7575757575757575, 0x7575757575757575};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000000,
                             0x0000000000000001, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000fc00fc00, 0xfc003802fc000000,
                      0x00000000fc00fc00, 0xfc003802fc000000};
  __m256i_result = (__m256i){0x00000000fc00fc00, 0xfc003802fc000000,
                             0x00000000fc00fc00, 0xfc003802fc000000};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000004, 0x0000000000000004,
                      0x0000000000000004, 0x0000000000000004};
  v4u64_op1 = (v4u64){0x0000000000000004, 0x0000000000000004,
                      0x0000000000000004, 0x0000000000000004};
  __m256i_result = (__m256i){0x0000000000000008, 0x0000000000000008,
                             0x0000000000000008, 0x0000000000000008};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000007b00f9007e, 0x0000000000000000,
                      0x0000007b00f9007e, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000007b00f9007e, 0x0000000000000000,
                      0x0000007b00f9007e, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000f601f200fc, 0x0000000000000000,
                             0x000000f601f200fc, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000007f00000000, 0x0000007f00000022,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000007f00000000, 0x0000007f00000022,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsadd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19,
                      0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19,
                             0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19};
  __m256i_out = __lasx_xvsadd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffb5ff80ffd0ffd8, 0x00010000002fff9e,
                      0xffb7ff80ffd0ffd8, 0x0002ff80ffb70000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffb5ff80ffd0ffd8, 0x00010000002fff9e,
                             0xffb7ff80ffd0ffd8, 0x0002ff80ffb70000};
  __m256i_out = __lasx_xvsadd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff800000000000, 0xffff800000000000,
                      0xffff800000000000, 0xffff800000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffff800000000000, 0xffff800000000000,
                             0xffff800000000000, 0xffff800000000000};
  __m256i_out = __lasx_xvsadd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000008, 0x0000000000000008,
                      0x0000000000000008, 0x0000000000000008};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000008, 0x0000000000000008,
                             0x0000000000000008, 0x0000000000000008};
  __m256i_out = __lasx_xvsadd_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
