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
  v4u64_op1 = (v4u64){0xfff6fff6fff6fff6, 0xfff6fff6fff6fff6,
                      0xfff6fff6fff6fff6, 0xfff6fff6fff6fff6};
  __m256i_result = (__m256i){0xff01ff01ff01ff01, 0xff01ff01ff01ff01,
                             0xff01ff01ff01ff01, 0xff01ff01ff01ff01};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000020001, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000007dfdff4b, 0xffffcc8000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ff83ff01, 0xff01ff3400000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000080, 0x0000000000000080,
                      0x0000000000000080, 0x0000000000000080};
  v4u64_op1 = (v4u64){0x0000004000000040, 0x0000004000000040,
                      0x0000004000000040, 0x0000004000000040};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x0000ff010000ff01, 0x0000ff010000ff01,
                             0x0000ff010000ff01, 0x0000ff010000ff01};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xefdfefdfefdfefdf, 0xefdfefdf00000000,
                      0xefdfefdfefdfefdf, 0xefdfefdf00000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xfff0fff0fff0fff0, 0xfff0fff0ff01ff01,
                             0xfff0fff0fff0fff0, 0xfff0fff0ff01ff01};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff0000ffff, 0x0000ffffffffffff,
                      0x0000ffff0000ffff, 0x0000ffffffffffff};
  v4u64_op1 = (v4u64){0x0001fffe0001fffe, 0x0001fffe0001fffe,
                      0x0001fffe0001fffe, 0x0001fffe0001fffe};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000ff0000,
                             0x0000000000000000, 0x0000000000ff0000};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xdfc2df80df80df87, 0xdf80df80df80df80,
                      0xdfc2df80df80df87, 0xdf80df80df80df80};
  __m256i_result = (__m256i){0xff21ff21ff21ff21, 0xff21ff21ff21ff21,
                             0xff21ff21ff21ff21, 0xff21ff21ff21ff21};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007ffcfcfd020202, 0x0000000000000000,
                      0x4079808280057efe, 0x0000000000000002};
  v4u64_op1 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000fc00fd0002, 0x0000000000000000,
                             0x004000800080007e, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffffe00000001, 0xffffffff00000000,
                      0xffffffff00000000, 0xffffffff00000000};
  __m256i_result = (__m256i){0xff01ff0100000000, 0xff01ff0100000000,
                             0xff01ff0100000000, 0xff01ff0100000000};
  __m256i_out = __lasx_xvsubwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000007fffffff, 0x7ffe00007f000000,
                      0x000000007fffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffff0000ffff, 0xffffffff00000000,
                      0x000000000000ffff, 0xffffffff00000000};
  __m256i_result = (__m256i){0xffff000100007fff, 0xffff7fff00007f00,
                             0x0000000000007fff, 0xffff000100000000};
  __m256i_out = __lasx_xvsubwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000b8f81b8c840e4, 0x000050504c4c2362,
                      0x000b8f81b8c840e4, 0x000050504c4c2362};
  __m256i_result = (__m256i){0xfffffff5ffff4738, 0x00000000ffffb3b4,
                             0xfffffff5ffff4738, 0x00000000ffffb3b4};
  __m256i_out = __lasx_xvsubwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff20010001, 0x00009fff9ffffd80,
                      0x0000ffff20010001, 0x00009fff9ffffd80};
  v4u64_op1 = (v4u64){0x00002080df5b41cf, 0x0000000000000000,
                      0x00002080df5b41cf, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffff40a6, 0x0000000000009fff,
                             0x00000000ffff40a6, 0x0000000000009fff};
  __m256i_out = __lasx_xvsubwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x00007fffffffffff,
                      0xffffffffffffffff, 0x00007fffffffffff};
  __m256i_result = (__m256i){0xffffffff00000001, 0xffffffffffff8001,
                             0xffffffff00000001, 0xffffffffffff8001};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0003fffc00060000, 0x0000000000000001,
                      0x020afefb08140000, 0x0001000100010000};
  v4u64_op1 = (v4u64){0x000000ff00000000, 0x0000000000000000,
                      0xffffffffff000000, 0xffff00ffffffffff};
  __m256i_result = (__m256i){0x000000000003fefd, 0x0000000000000000,
                             0xffffffff020afefc, 0xffffffff0001ff02};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff00ff00ff00ef32, 0xff00ff00ff00ef32,
                      0xff00ff00ff00ef32, 0xff00ff00ff00ef32};
  v4u64_op1 = (v4u64){0x151415141514e335, 0x1514151415141514,
                      0x151415141514e335, 0x1514151415141514};
  __m256i_result = (__m256i){0x00000000e9ece9ec, 0x00000000e9ece9ec,
                             0x00000000e9ece9ec, 0x00000000e9ece9ec};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0004005600040020, 0x0000000000000000,
                      0x000c005e000c0029, 0x0008000800080008};
  v4u64_op1 = (v4u64){0x0000000300000002, 0x0002000000020000,
                      0x0000000300000002, 0x0002000000020000};
  __m256i_result = (__m256i){0x0000000000040053, 0xfffffffffffe0000,
                             0x00000000000c005b, 0x0000000000060008};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x00000000ffffffff,
                             0x00000000ffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x00000000ffffffff,
                             0x00000000ffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003f784000ff80, 0xf7f8f7f84000fff9,
                      0x00003f784000ff80, 0xf7f8f7f8f800f800};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000003f78, 0x00000000f7f8f7f8,
                             0x0000000000003f78, 0x00000000f7f8f7f8};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7000700070007000, 0x0000000070007000,
                      0x7000700070007000, 0x7000700070007000};
  __m256i_result = (__m256i){0xffffffff8fff9000, 0x0000000000000000,
                             0xffffffff8fff9000, 0xffffffff8fff9000};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8848c848c848c848, 0xc848c848c848c848,
                      0x8848c848c848c848, 0xc848c848c848c848};
  __m256i_result = (__m256i){0xffffffff77b737b8, 0xffffffff37b737b8,
                             0xffffffff77b737b8, 0xffffffff37b737b8};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x457db03e45a87310, 0x457db03e457db03e,
                      0x457db03e45a87310, 0x457db03e457db03e};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffff457db03f, 0x00000000457db03e,
                             0xffffffff457db03f, 0x00000000457db03e};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x00000000ffffffff,
                             0x00000000ffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvsubwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010001, 0x0001000100010001,
                      0x0001000100010001, 0x0001000100010001};
  v4u64_op1 = (v4u64){0x8000000080000000, 0x0000000000000000,
                      0x8000000080000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0001000100010001, 0x0000000000000000,
                             0x0001000100010001, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x00000000ffffffff,
                      0x0000000000000000, 0x00000000ffffffff};
  __m256i_result = (__m256i){0xffffffff00000001, 0xffffffffffffffff,
                             0xffffffff00000001, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsubwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffffffffff, 0x0000000000000000,
                      0x7fffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000ffff0000ffff, 0x0000000000000000,
                      0x0000ffff0000ffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff00ff00ff00ff00, 0xffffffffffffffff,
                      0xff00ff00ff00ff00, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x000b2673a90896a4, 0x000050504c4c2362,
                      0x000b2673a90896a4, 0x000050504c4c2362};
  __m256i_result = (__m256i){0xffffafafb3b3dc9d, 0x0000000000000000,
                             0xffffafafb3b3dc9d, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0100000100000001, 0x0000000008050501,
                      0x0100000100000001, 0x0000000008050501};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000008050501, 0x0000000000000000,
                             0x0000000008050501, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000029170, 0x0000000001fff000,
                      0x0000000000029170, 0x0000000001fff000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000001fff000, 0x0000000000000000,
                             0x0000000001fff000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000d6d6d, 0x0000000000000000,
                      0x00000000090b0906, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffff8000, 0x0000000000000000,
                      0xffffffffffff8000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsubwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
