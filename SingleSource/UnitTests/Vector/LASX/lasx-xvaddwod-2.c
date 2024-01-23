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

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0006000000040000,
                      0x0000000000000000, 0x0006000000040000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000007fffffff, 0x7ffe00007f000000,
                      0x000000007fffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x00ff00ff017e01fe, 0x017e00ff017e00ff,
                             0x00ff00ff017e01fe, 0x00ff00ff00ff00ff};
  __m256i_out = __lasx_xvaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xb71c413b199d04b5, 0x000000fefe02fffe,
                      0xb7146213fc1e0049, 0xb70036db12c4007e};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00b7004100190004, 0x0000000000fe00ff,
                             0x00b7006200fc0000, 0x00b7003600120000};
  __m256i_out = __lasx_xvaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffd017d00, 0x000000007aff7c00,
                      0xfffffffffd017d00, 0x000000007aff7c00};
  v4u64_op1 = (v4u64){0x0000000067751500, 0x00000000008e7c00,
                      0x0000000067751500, 0x00000000008e7c00};
  __m256i_result = (__m256i){0x00ff00ff01640092, 0x00000000007a00f8,
                             0x00ff00ff01640092, 0x00000000007a00f8};
  __m256i_out = __lasx_xvaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffa0078fffa0074, 0xfffefffefffefffe,
                      0xfffa0078fffa0074, 0xfffefffefffefffe};
  __m256i_result = (__m256i){0x00ff000000ff0000, 0x00ff00ff00ff00ff,
                             0x00ff000000ff0000, 0x00ff00ff00ff00ff};
  __m256i_out = __lasx_xvaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00ff00ff00ff00ff, 0x0000000000000000,
                             0x00ff00ff00ff00ff, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffff800000000000, 0xffff800000000000,
                      0xffff800000000000, 0xffff800000000000};
  __m256i_result = (__m256i){0x00ff008000000000, 0x00ff008000000000,
                             0x00ff008000000000, 0x00ff008000000000};
  __m256i_out = __lasx_xvaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff8001ffff0001, 0x00000000ffff0020,
                      0xffff8001ffff0001, 0x00000000ffff0020};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00ff008000ff0000, 0x0000000000ff0000,
                             0x00ff008000ff0000, 0x0000000000ff0000};
  __m256i_out = __lasx_xvaddwod_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffff000000000000, 0x0000000000000000,
                      0xffff000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff00000000, 0x0000000000000000,
                             0x0000ffff00000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00007fff0000ffff, 0x00017fff0000ffff,
                      0x0000804000004141, 0x0000800000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000100000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7bbbbbbbf7777778, 0x0000000044444443,
                      0x7bbbbbbbf7777778, 0x0000000044444443};
  __m256i_result = (__m256i){0x00007bbb0000f777, 0x0000000000004444,
                             0x00007bbb0000f777, 0x0000000000004444};
  __m256i_out = __lasx_xvaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x3e6ce7d9cb7afb62, 0x4010000000000000,
                      0x3e6ce7d9cb7afb62, 0x4010000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00003e6c0000cb7a, 0x0000401000000000,
                             0x00003e6c0000cb7a, 0x0000401000000000};
  __m256i_out = __lasx_xvaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x3abac5447fffca89, 0x3aadec4f6c7975b1,
                      0x3abac5447fffca89, 0x3aadec4f6c7975b1};
  v4u64_op1 = (v4u64){0x3abac5447fffca89, 0x3aadec4f6c7975b1,
                      0x3abac5447fffca89, 0x3aadec4f6c7975b1};
  __m256i_result = (__m256i){0x000075740000fffe, 0x0000755a0000d8f2,
                             0x000075740000fffe, 0x0000755a0000d8f2};
  __m256i_out = __lasx_xvaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000002000000020, 0x0000002000000020,
                      0x0000002000000020, 0x0000002000000020};
  v4u64_op1 = (v4u64){0xffffffffffee00ba, 0x0000000000000000,
                      0xffffffffffee00ba, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff0000ffee, 0x0000000000000000,
                             0x0000ffff0000ffee, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffff9fffffff9, 0x9ffffd8020010001,
                      0xfffffff9fffffff9, 0x9ffffd8020010001};
  __m256i_result = (__m256i){0x0000ffff0000ffff, 0x00009fff00002001,
                             0x0000ffff0000ffff, 0x00009fff00002001};
  __m256i_out = __lasx_xvaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000010001, 0x0000000000010001,
                      0x0000000000010001, 0x0000000000010001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvaddwod_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000900000000, 0x0000001a00000001,
                      0x0000000900000000, 0x0000001a00000001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000009, 0x000000000000001a,
                             0x0000000000000009, 0x000000000000001a};
  __m256i_out = __lasx_xvaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000800000000000, 0x8000800000000000,
                      0x8000800000000000, 0x8000800000000000};
  v4u64_op1 = (v4u64){0x8000800000000000, 0x8000800000000000,
                      0x8000800000000000, 0x8000800000000000};
  __m256i_result = (__m256i){0x0000000100010000, 0x0000000100010000,
                             0x0000000100010000, 0x0000000100010000};
  __m256i_out = __lasx_xvaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0x00000000ffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffff00000000, 0x00000000ffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x00000000fffffffe, 0x0000000000000000,
                             0x00000000fffffffe, 0x00000000fffffffe};
  __m256i_out = __lasx_xvaddwod_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffee, 0xffffffffffffffee,
                      0xffffffffffffffee, 0xffffffffffffffee};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x00000000ffffffff,
                             0x00000000ffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000030007, 0x00000000003f0000,
                      0x0000000000030007, 0x00000000003f0000};
  v4u64_op1 = (v4u64){0xff15c1ea95ea02ff, 0x0000ffffffff0100,
                      0x00153f1594ea02ff, 0x0000ffffffffffff};
  __m256i_result = (__m256i){0x00000000ff15c1ea, 0x000000000000ffff,
                             0x0000000000153f15, 0x000000000000ffff};
  __m256i_out = __lasx_xvaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffff040000000000,
                      0x0000000000000000, 0xffff040000000000};
  v4u64_op1 = (v4u64){0x00ff00ff00fe00fe, 0x00ff00ff00fe00fe,
                      0x00ff00ff00fe00fe, 0x00ff00ff00fe00fe};
  __m256i_result = (__m256i){0x0000000000ff00ff, 0x0000000100fe04ff,
                             0x0000000000ff00ff, 0x0000000100fe04ff};
  __m256i_out = __lasx_xvaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x000000000000ffff, 0x000000000000ffff,
                             0x000000000000ffff, 0x000000000000ffff};
  __m256i_out = __lasx_xvaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff00000000, 0x0000ffff0000ffff,
                      0x0000ffff00000000, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x000000000003ffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000ffff, 0x000000000000ffff,
                             0x000000000000ffff, 0x000000000000ffff};
  __m256i_out = __lasx_xvaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00f9f9f900000002, 0x0000000000000000,
                      0x00f9f9f900000002, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xf9f9f9f9f9f9f9f9, 0xf9f9f9f9f9f9f9f9,
                      0xf9f9f9f9f9f9f9f9, 0xf9f9f9f9f9f9f9f9};
  __m256i_result = (__m256i){0x00000000faf3f3f2, 0x00000000f9f9f9f9,
                             0x00000000faf3f3f2, 0x00000000f9f9f9f9};
  __m256i_out = __lasx_xvaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000029170, 0x0000000001fff000,
                      0x0000000000029170, 0x0000000001fff000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffff7fffffff, 0x7fffffff7fffffff,
                      0x7fffffff7fffffff, 0x7fffffff7fffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7fffffff7fffffff, 0x0000000000000000,
                             0x7fffffff7fffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc3f0c3f0c3f0c3f0, 0xc3f0c3f0c3f0c3f0,
                      0xc3f0c3f0c3f0c3f0, 0xc3f0c3f0c3f0c3f0};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xc3f0c3f0c3f0c3f0, 0x0000000000000000,
                             0xc3f0c3f0c3f0c3f0, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff00ff00ff00ef32, 0xff00ff00ff00ef32,
                      0xff00ff00ff00ef32, 0xff00ff00ff00ef32};
  v4u64_op1 = (v4u64){0xe7e7e7e7e7e7e7e7, 0xe7e7e7e7e7e7e7e7,
                      0xe7e7e7e7e7e7e7e7, 0xe7e7e7e7e7e7e7e7};
  __m256i_result = (__m256i){0xe6e8e6e8e6e8d719, 0x0000000000000001,
                             0xe6e8e6e8e6e8d719, 0x0000000000000001};
  __m256i_out = __lasx_xvaddwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000800400010006d, 0x0000000000000000,
                      0x000800400010006d, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000800400010006d, 0x0000000000000000,
                      0x000800400010006d, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000003fffff, 0xffffffffffffffff,
                      0x00000000003fffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
