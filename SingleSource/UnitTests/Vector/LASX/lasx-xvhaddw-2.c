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

  v4u64_op0 = (v4u64){0x151196b58fd1114d, 0x000033ff01020e23,
                      0x028e509508b16ee9, 0x0000015d050192cb};
  v4u64_op1 = (v4u64){0x0000228200001680, 0x0001ffe80001fe9c,
                      0x0000716800007bb6, 0x0001ffaa0000040e};
  __m256i_result = (__m256i){0x00150118008f0091, 0x0001011b000200aa,
                             0x000200b800080124, 0x000100ab000500a0};
  __m256i_out = __lasx_xvhaddw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000001000310000, 0x0000000000000000,
                      0x00000001341c4000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00007f7f00007fff, 0x0000000000000000,
                      0x00007f7f00000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000007f000000ff, 0x0000000000000000,
                             0x0000007f00340040, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffafaf80000000, 0x8000000180007f7f,
                      0xffffafaf80000000, 0x8000000180007f7f};
  __m256i_result = (__m256i){0x01fe01ae00ff00ff, 0x00ff010000ff017e,
                             0x01fe01ae00ff00ff, 0x00ff010000ff017e};
  __m256i_out = __lasx_xvhaddw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7c00000880008000, 0x00000000ffffffff,
                      0x7c00000880008000, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x0000000000010001, 0x0000000000000003,
                      0x0000000000010001, 0x0000000000000003};
  __m256i_result = (__m256i){0x007c000000810081, 0x0000000000ff0102,
                             0x007c000000810081, 0x0000000000ff0102};
  __m256i_out = __lasx_xvhaddw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffc0003fffc0, 0x0000000000000000,
                      0x0000ffc0003fffc0, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x007fc0083fc7c007, 0x0000000000000000,
                      0x007fc0083fc7c007, 0x0000000000000000};
  __m256i_result = (__m256i){0x007f010700c70106, 0x0000000000000000,
                             0x007f010700c70106, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000e0010000e,
                      0x0000000000000000, 0x0000000e0010000e};
  v4u64_op1 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0x000000000000ffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000000ff, 0x0000000000000000,
                             0x00000000000000ff, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101000101010001, 0x0000000000000000,
                      0x0101000101010001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0001000000010000, 0x0000000000000000,
                             0x0001000000010000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_hu_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000ffff, 0x0000000000000000,
                             0x000000000000ffff, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000002a54290, 0x0000000000000000,
                      0x0000000002a54290, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000002a5, 0x0000000000000000,
                             0x00000000000002a5, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff0000ffff, 0x0000000000000000,
                             0x0000ffff0000ffff, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000e0e0e0e0e0e,
                      0x0000000000000000, 0x0e0e0e0e0e0e0e0e};
  v4u64_op1 = (v4u64){0xffffffff8fff9000, 0x0000000000000000,
                      0xffffffff8fff9000, 0xffffffff8fff9000};
  __m256i_result = (__m256i){0x0000ffff00009000, 0x0000000000000e0e,
                             0x0000ffff00009000, 0x00010e0d00009e0e};
  __m256i_out = __lasx_xvhaddw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000e0000000e, 0x0000000e0000000e,
                      0x0000000e0000000e, 0x0000000e0000000e};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0004000500040005, 0x0004000400040004,
                      0x0004000500040005, 0x0004000400040004};
  v4u64_op1 = (v4u64){0x7fffffff80000000, 0x7fffffff80000000,
                      0x7fffffff80000000, 0x7fffffff80000000};
  __m256i_result = (__m256i){0x0001000300000004, 0x0001000300000004,
                             0x0001000300000004, 0x0001000300000004};
  __m256i_out = __lasx_xvhaddw_wu_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff4ff4e11410b40, 0x010200023b8e4174,
                      0xffd5020738b43ddb, 0x0501030102141923};
  v4u64_op1 = (v4u64){0x6d3c2d3a89167aeb, 0x0000883a00000f20,
                      0xf259905a09c23be0, 0x000019410000e69a};
  __m256i_result = (__m256i){0x00000001890b7a39, 0x0000000001020f22,
                             0x0000000109973de7, 0x000000000501e99b};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff000000000000, 0x0000000000000000,
                      0x7fff000000000000, 0x7f00000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000007fff0000, 0x0000000000000000,
                             0x000000007fff0000, 0x000000007f000000};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xfff90000fff9fff9, 0xfff9fff9fff9fff9,
                      0xfff90000fff9fff9, 0xfff9fff9fff9fff9};
  __m256i_result = (__m256i){0x00000001fff9fff8, 0x00000001fff9fff8,
                             0x00000001fff9fff8, 0x00000001fff9fff8};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffb4ffcec0f1, 0x00000000000018de,
                      0x00003f6ee0570b4e, 0xffffff81ffffeb2f};
  v4u64_op1 = (v4u64){0xffffffb4ffcec0f1, 0x00000000000018de,
                      0x00003f6ee0570b4e, 0xffffff81ffffeb2f};
  __m256i_result = (__m256i){0x00000001ffcec0a5, 0x00000000000018de,
                             0x00000000e0574abc, 0x00000001ffffeab0};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffc3aaa8d58f43c8,
                      0x4f90000000000000, 0xffe367cc82f8989a};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000d58f43c8,
                             0x0000000000000000, 0x0000000082f8989a};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000001700170017, 0x0000000000000017,
                      0x0000001700170017, 0x0000000000000017};
  __m256i_result = (__m256i){0x0000000000170017, 0x0000000000000017,
                             0x0000000000170017, 0x0000000000000017};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000004411, 0x0000000000000000,
                      0x0000000000004411, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000004411, 0x0000000000000000,
                             0x0000000000004411, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000175e0000490d, 0x0000236200005111,
                      0x0000175e0000490d, 0x0000236200005111};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000010000175d, 0x0000000000002362,
                             0x000000010000175d, 0x0000000000002362};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x00000000ffffffff,
                      0xffffffffffffffff, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x000000000000ff01, 0x0000ff0100ff0000,
                      0x000000000000ff01, 0x0000ff0100ff0000};
  __m256i_result = (__m256i){0x000000010000ff00, 0x0000000000ff0000,
                             0x000000010000ff00, 0x0000000000ff0000};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003fff00003fff, 0x00003fff00003fff,
                      0x00003fff00003fff, 0x00003fff00003fff};
  v4u64_op1 = (v4u64){0x00000007ffffffce, 0x00000005ffffffff,
                      0x00000007ffffffce, 0x00000005ffffffff};
  __m256i_result = (__m256i){0x0000000100003fcd, 0x0000000100003ffe,
                             0x0000000100003fcd, 0x0000000100003ffe};
  __m256i_out = __lasx_xvhaddw_du_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000080000000, 0xfffffefefffffefe,
                      0xfffffefefffffcfa, 0xfffffefefffffefe};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffefefffffefe, 0x0000000000000000,
                             0xfffffefefffffefe, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000040, 0x0000000000000000,
                      0x0000000000000040, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000003f, 0x0000000000000000,
                      0x000000000000003f, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000003f, 0x0000000000000000,
                             0x000000000000003f, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x9090909090909090, 0x9090909090909090,
                      0x9090909090909090, 0x9090909090909090};
  __m256i_result = (__m256i){0x9090909090909090, 0x0000000000000000,
                             0x9090909090909090, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000000f, 0x0000000000000000,
                      0x000000000000000f, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000000f, 0x0000000000000000,
                             0x000000000000000f, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf3f3f3f3f3f3f3f3, 0xf3f3f3f3f3f3f3f3,
                      0xf3f3f3f3f3f3f3f3, 0xf3f3f3f3f3f3f3f3};
  v4u64_op1 = (v4u64){0x0000000000000100, 0x0000000000000200,
                      0x0000000000000100, 0x0000000000000200};
  __m256i_result = (__m256i){0xf3f3f3f3f3f3f4f3, 0x0000000000000000,
                             0xf3f3f3f3f3f3f4f3, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x800000ff800000ff, 0x8000800080008000,
                      0x800000ff800000ff, 0x8000800080008000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0080000000000002,
                      0x0000000000000000, 0x0080000000000002};
  __m256i_result = (__m256i){0x8000800080008000, 0x0000000000000000,
                             0x8000800080008000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000001ce, 0x00000000000001fe,
                      0x00000000000001ce, 0x00000000000001fe};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000005,
                      0xffffffffffffffff, 0x0000000000000005};
  __m256i_result = (__m256i){0x00000000000001fd, 0x0000000000000001,
                             0x00000000000001fd, 0x0000000000000001};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfd12fd12fd12fd12, 0xfd12fd12fd12fd12,
                      0xfd12fd12fd12fd12, 0xfd12fd12fd12fd12};
  v4u64_op1 = (v4u64){0xfd02fd02fd02fd02, 0xfd02fd02fd02fd02,
                      0xfd02fd02fd02fd02, 0xfd02fd02fd02fd02};
  __m256i_result = (__m256i){0xfa15fa15fa15fa14, 0x0000000000000001,
                             0xfa15fa15fa15fa14, 0x0000000000000001};
  __m256i_out = __lasx_xvhaddw_qu_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
