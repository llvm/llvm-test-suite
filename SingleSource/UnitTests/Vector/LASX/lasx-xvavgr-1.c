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

  v4u64_op0 = (v4u64){0x55555555aaaaaaac, 0x5555555536aaaaac,
                      0x55555555aaaaaaac, 0x5555555536aaaaac};
  v4u64_op1 = (v4u64){0xffffffff39ffffff, 0x0000000000000000,
                      0xffffffff39ffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x2a2a2a2af2d5d5d6, 0x2b2b2b2b1bd5d5d6,
                             0x2a2a2a2af2d5d5d6, 0x2b2b2b2b1bd5d5d6};
  __m256i_out = __lasx_xvavgr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000080, 0x0000000000000080,
                      0x0000000000000080, 0x0000000000000080};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000000c0, 0x00000000000000c0,
                             0x00000000000000c0, 0x00000000000000c0};
  __m256i_out = __lasx_xvavgr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0020002000400040, 0x0020002000400040,
                      0x0020002000400040, 0x0020002000400040};
  __m256i_result = (__m256i){0x0010001000200020, 0x0010001000200020,
                             0x0010001000200020, 0x0010001000200020};
  __m256i_out = __lasx_xvavgr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000003, 0x0000000000000000,
                      0x0000000000000003, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffffffffffffe, 0x0000000000000001,
                      0xfffffffffffffffe, 0x0000000000000001};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvavgr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fe363637fe36363, 0x7fe36364661af18f,
                      0x7fe363637fe36363, 0x7fe36364661af18f};
  __m256i_result = (__m256i){0x40f2323240f23232, 0x40f23232330df9c8,
                             0x40f2323240f23232, 0x40f23232330df9c8};
  __m256i_out = __lasx_xvavgr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0001000100800000, 0x0001000100010001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0001000100c00000, 0x0001000100010001};
  __m256i_out = __lasx_xvavgr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000f00f000000000, 0xfff0ff000000000f,
                      0x000f00f000000000, 0xfff0ff000000000f};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000800f800000000, 0x00f8000000000008,
                             0x000800f800000000, 0x00f8000000000008};
  __m256i_out = __lasx_xvavgr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000000d6d6d, 0x0000000000000000,
                      0x00000000090b0906, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000073737, 0x0000000000000000,
                             0x0000000005060503, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xbff0000000000000, 0xbff0000000000000,
                      0xbff0000000000000, 0xbff0000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xdff8000000000000, 0xdff8000000000000,
                             0xdff8000000000000, 0xdff8000000000000};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffefefffffefe, 0x0000000000000000,
                      0xfffffefefffffefe, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ff7f0000ff7f, 0x0000000000000000,
                             0x0000ff7f0000ff7f, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffffffffff, 0x0000000000000000,
                      0x7fffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x4000000000000000, 0x0000000000000000,
                             0x4000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000fd0000, 0x0000000000000000,
                      0x0000000000fd0000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000007f0000, 0x0000000000000000,
                             0x00000000007f0000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xbf84bf00bf00bf0e, 0xbf00bf00bf00bf00,
                      0xbf84bf00bf00bf0e, 0xbf00bf00bf00bf00};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xdfc2df80df80df87, 0xdf80df80df80df80,
                             0xdfc2df80df80df87, 0xdf80df80df80df80};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xbf84bf00bf00bf0e, 0xbf00bf00bf00bf00,
                      0xbf84bf00bf00bf0e, 0xbf00bf00bf00bf00};
  v4u64_op1 = (v4u64){0x00003f3f00004040, 0x00003f3f00003f3f,
                      0x00003f3f00004040, 0x00003f3f00003f3f};
  __m256i_result = (__m256i){0xdfc2ff20df80ffa7, 0xdf80ff20df80ff20,
                             0xdfc2ff20df80ffa7, 0xdf80ff20df80ff20};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x43ef878780000009, 0x0000000080000009,
                      0x43ef878780000009, 0x0000000080000009};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x21f8c3c4c0000005, 0x00000000c0000005,
                             0x21f8c3c4c0000005, 0x00000000c0000005};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x9090909090909090, 0x9090909090909090,
                      0x9090909090909090, 0x9090909090909090};
  v4u64_op1 = (v4u64){0x8000000000000000, 0x0000000000000000,
                      0x8000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x8848c848c848c848, 0xc848c848c848c848,
                             0x8848c848c848c848, 0xc848c848c848c848};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffff0000, 0x0000000000000000,
                      0xffffffffffff0000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000008000, 0x7fff80007fff0000,
                      0x0000000000008000, 0x7fff80007fff0000};
  v4u64_op1 = (v4u64){0x000000ff800000ff, 0x000000ff800000ff,
                      0x000000ff800000ff, 0x000000ff800000ff};
  __m256i_result = (__m256i){0x00000080c000c080, 0x4000c08000000080,
                             0x00000080c000c080, 0x4000c08000000080};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffff7fffffff, 0x0000000000000000,
                      0x7fffffff7fffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffff8000, 0x0000000000000000,
                      0xffffffffffff8000, 0x0000000000000000};
  __m256i_result = (__m256i){0x3fffffff3fffc000, 0x0000000000000000,
                             0x3fffffff3fffc000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x007fffffffffffff,
                      0xffffffffffffffff, 0x007fffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x003fffffffffffff,
                             0xffffffffffffffff, 0x003fffffffffffff};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x003fffffffffffff,
                      0xffffffffffffffff, 0x003fffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x001fffffffffffff,
                             0xffffffffffffffff, 0x001fffffffffffff};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000007ffffffce, 0x00000005ffffffff,
                      0x00000007ffffffce, 0x00000005ffffffff};
  v4u64_op1 = (v4u64){0x00000007ffffffce, 0x00000005ffffffff,
                      0x00000007ffffffce, 0x00000005ffffffff};
  __m256i_result = (__m256i){0x00000007ffffffce, 0x00000005ffffffff,
                             0x00000007ffffffce, 0x00000005ffffffff};
  __m256i_out = __lasx_xvavgr_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000001010101, 0x0000000001010101,
                      0x0000000001010101, 0x0000000001010101};
  __m256i_result = (__m256i){0x0000000000808081, 0x0000000000808081,
                             0x0000000000808081, 0x0000000000808081};
  __m256i_out = __lasx_xvavgr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000f18080010000,
                      0x0000000000000000, 0x0000f18080010000};
  __m256i_result = (__m256i){0x0000000000000000, 0x000078c0c0008000,
                             0x0000000000000000, 0x000078c0c0008000};
  __m256i_out = __lasx_xvavgr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfebdff3eff3dff52, 0xfebdff3eff3dff52,
                      0xfebdff3eff3dff52, 0xfebdff3eff3dff52};
  v4u64_op1 = (v4u64){0x160fe9f000000000, 0x1086658a18ba3594,
                      0x160fe9f000000000, 0x1086658a18ba3594};
  __m256i_result = (__m256i){0x0a66f497ff9effa9, 0x07a232640bfc1a73,
                             0x0a66f497ff9effa9, 0x07a232640bfc1a73};
  __m256i_out = __lasx_xvavgr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffff295329, 0xfffffffffefefeff,
                      0xffffffffff295329, 0xfffffffffefefeff};
  v4u64_op1 = (v4u64){0x0000000000c40086, 0x00fe01f000010000,
                      0x0000000000c40086, 0x00fe01f000010000};
  __m256i_result = (__m256i){0x00000000fff6a9d8, 0x007f00f8ff7fff80,
                             0x00000000fff6a9d8, 0x007f00f8ff7fff80};
  __m256i_out = __lasx_xvavgr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000807e7ffe, 0x7ffe7ffe7ffe8000,
                      0x000000007ffe7ffe, 0x7ffe7ffe7ffe7ffe};
  v4u64_op1 = (v4u64){0x00000000807e7ffe, 0x7ffe7ffe7ffe8000,
                      0x000000007ffe7ffe, 0x7ffe7ffe7ffe7ffe};
  __m256i_result = (__m256i){0x00000000807e7ffe, 0x7ffe7ffe7ffe8000,
                             0x000000007ffe7ffe, 0x7ffe7ffe7ffe7ffe};
  __m256i_out = __lasx_xvavgr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00fe00fe, 0x00ff00ff00fe00fe,
                      0x00ff00ff00fe00fe, 0x00ff00ff00fe00fe};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x007f8080007f007f, 0x007f8080007f007f,
                             0x007f8080007f007f, 0x007f8080007f007f};
  __m256i_out = __lasx_xvavgr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffff0000, 0xffc6ffc6003a003a,
                      0xffffffffffff0000, 0xffc6ffc6003a003a};
  __m256i_result = (__m256i){0x00000000ffff8000, 0xffe37fe3001d001d,
                             0x00000000ffff8000, 0xffe37fe3001d001d};
  __m256i_out = __lasx_xvavgr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000f00000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000700000000};
  __m256i_out = __lasx_xvavgr_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000101, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000081, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000004a0000002a, 0x0000004a00000040,
                      0x0000004a0000002a, 0x0000004a00000040};
  v4u64_op1 = (v4u64){0x0000fffffffefffe, 0xff7fffffffffffff,
                      0x0000fffffffefffe, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x00008024ffff8014, 0xffc0002500000020,
                             0x00008024ffff8014, 0x0000002500000020};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000001a00, 0x0000000000000000,
                      0x0000000000001a00, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000001a00, 0x0000000000000000,
                      0x0000000000001a00, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000001a00, 0x0000000000000000,
                             0x0000000000001a00, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000179e0000951d, 0x000023a20000a121,
                      0x0000179e0000951d, 0x000023a20000a121};
  v4u64_op1 = (v4u64){0x0000010000000100, 0x0000010000000100,
                      0x0000010000000100, 0x0000010000000100};
  __m256i_result = (__m256i){0x00000c4f00004b0f, 0x0000125100005111,
                             0x00000c4f00004b0f, 0x0000125100005111};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000100010001, 0x0001000000000000,
                      0x0000000100010001, 0x0001000000000000};
  __m256i_result = (__m256i){0x0000000080008001, 0x0000800000000000,
                             0x0000000080008001, 0x0000800000000000};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff457d607f, 0x00000000457d607d,
                      0xffffffff457d607f, 0x00000000457d607d};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffa2beb040, 0x0000000022beb03f,
                             0xffffffffa2beb040, 0x0000000022beb03f};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000005858585a, 0x000000005858585a,
                      0x000000005858585a, 0x000000005858585a};
  v4u64_op1 = (v4u64){0x000023a300003fef, 0x000023a300003fff,
                      0x000023a300003fef, 0x000023a300003fff};
  __m256i_result = (__m256i){0x000011d1ac2c4c25, 0x000011d1ac2c4c2d,
                             0x000011d1ac2c4c25, 0x000011d1ac2c4c2d};
  __m256i_out = __lasx_xvavgr_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
