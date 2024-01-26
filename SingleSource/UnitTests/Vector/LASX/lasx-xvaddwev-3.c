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

  v4u64_op0 = (v4u64){0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19,
                      0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19};
  v4u64_op1 = (v4u64){0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19,
                      0x1c1b1a191c1b1a19, 0x1c1b1a191c1b1a19};
  __m256i_result = (__m256i){0x0036003200360032, 0x0036003200360032,
                             0x0036003200360032, 0x0036003200360032};
  __m256i_out = __lasx_xvaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x8000000000000000,
                      0x8000000000000000, 0x8000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000170017, 0x0000000000000017,
                      0x0000000000170017, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000170017, 0x0000000000000017,
                             0x0000000000170017, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001fffe00010001, 0x0001fffe0000ffff,
                      0x0001fffe00010001, 0x0001fffe0000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000100fe00010001, 0x000100fe000000ff,
                             0x000100fe00010001, 0x000100fe000000ff};
  __m256i_out = __lasx_xvaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xfffffe20001dfe1f,
                      0x0000000000000000, 0xfffffe20001dfe1f};
  __m256i_result = (__m256i){0x0000000000000000, 0xffff0020001d001f,
                             0x0000000000000000, 0xffff0020001d001f};
  __m256i_out = __lasx_xvaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x5ff00007fff9fff3, 0x7ff0000000000000,
                      0x5ee1c073b800c916, 0x6100000800060005};
  v4u64_op1 = (v4u64){0x0003fffc00060000, 0x0000000000000000,
                      0x0209fefb08140000, 0x000000000000ffff};
  __m256i_result = (__m256i){0x000000030000fff3, 0x0000000000000000,
                             0x0000bf6e0000c916, 0x0000000800000004};
  __m256i_out = __lasx_xvaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8020004a0011002a, 0x000b004a00440040,
                      0x8020004a0011002a, 0x000b004a00440040};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000004a0000002a, 0x0000004a00000040,
                             0x0000004a0000002a, 0x0000004a00000040};
  __m256i_out = __lasx_xvaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00001fff00001fff, 0x00001fff00001fff,
                      0x00001fff00001fff, 0x00001fff00001fff};
  __m256i_result = (__m256i){0x00001fff00001fff, 0x00001fff00001fff,
                             0x00001fff00001fff, 0x00001fff00001fff};
  __m256i_out = __lasx_xvaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0808080808080808,
                      0x0000000000000000, 0x0808080808080808};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000080800000808,
                             0x0000000000000000, 0x0000080800000808};
  __m256i_out = __lasx_xvaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x001a001a002a009a, 0x001a001a001a009a,
                      0x001a001a002a009a, 0x001a001a001a009a};
  v4u64_op1 = (v4u64){0x0000000000000040, 0x0000000000000040,
                      0x0000000000000040, 0x0000000000000040};
  __m256i_result = (__m256i){0x0000001a000000da, 0x0000001a000000da,
                             0x0000001a000000da, 0x0000001a000000da};
  __m256i_out = __lasx_xvaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                             0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_out = __lasx_xvaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000007ffffffce, 0x00000005ffffffff,
                      0x00000007ffffffce, 0x00000005ffffffff};
  __m256i_result = (__m256i){0x00000007ffffffce, 0x00000005ffffffff,
                             0x00000007ffffffce, 0x00000005ffffffff};
  __m256i_out = __lasx_xvaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000e7, 0x00000000000000ff,
                      0x00000000000000e7, 0x00000000000000ff};
  v4u64_op1 = (v4u64){0x00000000000000e7, 0x00000000000000ff,
                      0x00000000000000e7, 0x00000000000000ff};
  __m256i_result = (__m256i){0x00000000000001ce, 0x00000000000001fe,
                             0x00000000000001ce, 0x00000000000001fe};
  __m256i_out = __lasx_xvaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000ff0000, 0x0000000000000000,
                      0x0000000000ff0000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000ff0000, 0x0000000000000000,
                             0x0000000000ff0000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fffffff7fffffff, 0x7fffffff7fffffff,
                      0x7fffffff7fffffff, 0x7fffffff7fffffff};
  __m256i_result = (__m256i){0x000000007fffffff, 0x000000007fffffff,
                             0x000000007fffffff, 0x000000007fffffff};
  __m256i_out = __lasx_xvaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000010000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000010000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff000000010000, 0x0000000000000000,
                      0x0001000000010000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0017ffa8008eff31, 0x80b900b980380038,
                      0x00baff050083ff3c, 0x8011ffae800c000c};
  __m256i_result = (__m256i){0x00000000008fff31, 0xffffffff80380038,
                             0x000000000084ff3c, 0xffffffff800c000c};
  __m256i_out = __lasx_xvaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x001f001f001f001f, 0x0000000000000000,
                      0x001f001f001f001f, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000001001f001e, 0x00000000ffffffff,
                             0x00000001001f001e, 0x00000000ffffffff};
  __m256i_out = __lasx_xvaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00ff00ff, 0x0000000000000000,
                      0x00ff00ff00ff00ff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000ff00ff, 0x0000000000000000,
                             0x0000000000ff00ff, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff10000fff10000, 0x0000000000000000,
                      0xfff10000fff10000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  __m256i_result = (__m256i){0x0000000100f000ff, 0x0000000000ff00ff,
                             0x0000000100f000ff, 0x0000000000ff00ff};
  __m256i_out = __lasx_xvaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff88ff88ff880000, 0xff88ff88ff880000,
                      0xff88ff88ff880000, 0xff88ff88ff880000};
  v4u64_op1 = (v4u64){0x00000000fff0ffc0, 0x000000000000ffc0,
                      0x00000000fff0ffc0, 0x000000000000ffc0};
  __m256i_result = (__m256i){0x00000000ff78ffc0, 0x00000000ff88ffc0,
                             0x00000000ff78ffc0, 0x00000000ff88ffc0};
  __m256i_out = __lasx_xvaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000016e00, 0x0000000000000000,
                      0x0000000000016e00, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000016e00, 0x0000000000000000,
                             0x0000000000016e00, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c,
                      0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c};
  __m256i_result = (__m256i){0xffffffffff1cff1c, 0xffffffffff1cff1c,
                             0xffffffffff1cff1c, 0xffffffffff1cff1c};
  __m256i_out = __lasx_xvaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffffffeff, 0xffffffffffffff1f,
                      0xfffffffffffffeff, 0xffffffffffffff1f};
  v4u64_op1 = (v4u64){0xfff1ffca0011ffcb, 0x0010ffc80010ff52,
                      0xfff1ffca0011ffcb, 0x0010ffc80010ff52};
  __m256i_result = (__m256i){0xfff1ffca0011feca, 0x0000000000000000,
                             0xfff1ffca0011feca, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x00000000ffffffff, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0xffffffff00000002, 0xffffffffffffffff,
                      0xffffffff00000002, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffff00000002, 0xffffffffffffffff,
                             0x0000000000000001, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000008000, 0x000000007fff0000,
                      0x0000000000008000, 0x000000007fff0000};
  v4u64_op1 = (v4u64){0x000000000000ffff, 0x0000ffff00000000,
                      0x000000000000ffff, 0x0000ffff00000000};
  __m256i_result = (__m256i){0x0000000000017fff, 0x0000000000000000,
                             0x0000000000017fff, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000004000000040, 0x0000000000000000,
                      0x0000004000000040, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000004000000040, 0x0000000000000000,
                             0x0000004000000040, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
