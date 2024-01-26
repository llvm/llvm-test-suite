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
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001fffe0001fffe, 0x0001fffe0001fffe,
                      0x0001fffe0001fffe, 0x0001fffe0001fffe};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x00ff01fffffffeff, 0x00ff01fffffffeff,
                             0x00ff01fffffffeff, 0x00ff01fffffffeff};
  __m256i_out = __lasx_xvilvl_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000005, 0x0000000000000005,
                      0x0000000000000005, 0x0000000000000005};
  __m256i_result = (__m256i){0x0000000000000005, 0x0000000000000000,
                             0x0000000000000005, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfff3fff3fff3fff3, 0xfff3fff3fff3fff3,
                      0xfff3fff3fff3fff3, 0xfff3fff3fff3fff3};
  __m256i_result = (__m256i){0x00ff00f300ff00f3, 0x00ff00f300ff00f3,
                             0x00ff00f300ff00f3, 0x00ff00f300ff00f3};
  __m256i_out = __lasx_xvilvl_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000001d001d, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000001d0000001d, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xe0e0e0e0e0e0e0e0, 0x00000000e0e0e0e0,
                      0xe0e0e0e0e0e0e0e0, 0xe0e0e0e0e0e0e0e0};
  v4u64_op1 = (v4u64){0x7000700070007000, 0x0000000070007000,
                      0x7000700070007000, 0x7000700070007000};
  __m256i_result = (__m256i){0xe070e000e070e000, 0xe070e000e070e000,
                             0xe070e000e070e000, 0xe070e000e070e000};
  __m256i_out = __lasx_xvilvl_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x003f003f003f0040, 0x0000000000000000,
                      0x003f003f003f0040, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x003f003f003f0040, 0x0000000000000000,
                      0x003f003f003f0040, 0x0000000000000000};
  __m256i_result = (__m256i){0x00003f3f00004040, 0x00003f3f00003f3f,
                             0x00003f3f00004040, 0x00003f3f00003f3f};
  __m256i_out = __lasx_xvilvl_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000100, 0x0000000000000000,
                             0x0000000000000100, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000a800b000a800b, 0x0003800400038004,
                      0x000a800b000a800b, 0x0003800400038004};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000a0080000b00, 0x00000a0080000b00,
                             0x00000a0080000b00, 0x00000a0080000b00};
  __m256i_out = __lasx_xvilvl_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000003fc03fc0, 0xfe01fe01fd02fd02,
                      0x000000003fc03fc0, 0xfe01fe01fd02fd02};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x3f00c0003f00c000, 0x0000000000000000,
                             0x3f00c0003f00c000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x00000000ffffffff,
                      0x00000000ffffffff, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0xf000f010f000f010, 0xf000f000f000f000,
                      0xf000f010f000f010, 0xf000f000f000f000};
  __m256i_result = (__m256i){0xfff0ff00fff0ff10, 0x00f0000000f00010,
                             0xfff0ff00fff0ff10, 0x00f0000000f00010};
  __m256i_out = __lasx_xvilvl_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000900000000, 0x0000001a00000001,
                      0x0000000900000000, 0x0000001a00000001};
  __m256i_result = (__m256i){0xffff0000ffff0000, 0x0000000000000009,
                             0xffff0000ffff0000, 0x0000000000000009};
  __m256i_out = __lasx_xvilvl_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffefffffefc, 0xfffffffffffffffe};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffff0000fffe0000, 0xffff0000ffff0000,
                             0xffff0000fefc0000, 0xffff0000fffe0000};
  __m256i_out = __lasx_xvilvl_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000007f007f78, 0x0000000000007f7f,
                      0x00000000007f7f7f, 0x0000000000007f7f};
  v4u64_op1 = (v4u64){0xfffffffffffbfffc, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7f00fffb7f78fffc, 0x0000ffff0000ffff,
                             0x007f00007f7f0000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x8080808080808081,
                      0x8080808080808081, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000808000008081, 0x0000808000008080};
  __m256i_out = __lasx_xvilvl_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x000000000000ffff, 0x0000000000000000,
                             0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_out = __lasx_xvilvl_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00fe00ff00fe, 0x0000ffff0000ffff,
                      0x00ff00fe00ff00fe, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0x00ff00fe00ff00fe, 0x0000ffff0000ffff,
                      0x00ff00fe00ff00fe, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x00ff00ff00fe00fe, 0x00ff00ff00fe00fe,
                             0x00ff00ff00fe00fe, 0x00ff00ff00fe00fe};
  __m256i_out = __lasx_xvilvl_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007c000000810081, 0x0000000000ff0102,
                      0x007c000000810081, 0x0000000000ff0102};
  v4u64_op1 = (v4u64){0x7fff7fff7fff0000, 0x7fe37fe3001d001d,
                      0x7fff7fff7fff0000, 0x7fe37fe3001d001d};
  __m256i_result = (__m256i){0x00817fff00810000, 0x007c7fff00007fff,
                             0x00817fff00810000, 0x007c7fff00007fff};
  __m256i_out = __lasx_xvilvl_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0101010101010101,
                      0xfffffffffffffefd, 0x0101010101010101};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0101010101010101,
                      0xfffffffffffffefd, 0x0101010101010101};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xfffffefdfffffefd, 0xffffffffffffffff};
  __m256i_out = __lasx_xvilvl_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000064, 0xfffffffffffffe98,
                      0x0000000000000064, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000064, 0x0000000000000000,
                             0x0000000000000064, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000e000e000e000e, 0x0000000000000000,
                      0x000e000e000e000e, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000e000e, 0x00000000000e000e,
                             0x00000000000e000e, 0x00000000000e000e};
  __m256i_out = __lasx_xvilvl_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x00000000ffffffff,
                             0x00000000ffffffff, 0x00000000ffffffff};
  __m256i_out = __lasx_xvilvl_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffed, 0xffffffffffffffed,
                      0xffffffffffffffed, 0xffffffffffffffed};
  __m256i_result = (__m256i){0x00000000ffffffed, 0x00000000ffffffff,
                             0x00000000ffffffed, 0x00000000ffffffff};
  __m256i_out = __lasx_xvilvl_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x7ff0000000000000,
                             0x0000000000000000, 0x7ff0000000000000};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x07efefefefefefee, 0x07efefefefefefee,
                      0x07efefefefefefee, 0x07efefefefefefee};
  __m256i_result = (__m256i){0x07efefefefefefee, 0x0000000000000000,
                             0x07efefefefefefee, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000000000000, 0x7fffffffffffffff,
                      0x0000000000000000, 0x8000000000000000};
  v4u64_op1 = (v4u64){0x0000ffffffffffff, 0xffffffffffffffff,
                      0x0000ffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000ffffffffffff, 0x8000000000000000,
                             0x0000ffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00ff00ff00040000, 0x00ff00ff00ff00ff,
                      0x00ff00ff000c0000, 0x00ff00ff00ff00ff};
  __m256i_result = (__m256i){0x00ff00ff00040000, 0x0000000000000000,
                             0x00ff00ff000c0000, 0x0000000000000000};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000e000e, 0x00000000000e000e,
                      0x00000000000e000e, 0x00000000000e000e};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000000e000e,
                             0x0000000000000000, 0x00000000000e000e};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000001fffffff9, 0x00000001fffffff9,
                      0x00000001fffffff9, 0x00000001fffffff9};
  v4u64_op1 = (v4u64){0x4980008068400000, 0x498000804843ffe0,
                      0x4980008068400000, 0x498000804843ffe0};
  __m256i_result = (__m256i){0x4980008068400000, 0x00000001fffffff9,
                             0x4980008068400000, 0x00000001fffffff9};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010101010101, 0x0101010101010101,
                      0x0101010101010101, 0x0101010101010101};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0101010101010101,
                             0x0000000000000000, 0x0101010101010101};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvilvl_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
