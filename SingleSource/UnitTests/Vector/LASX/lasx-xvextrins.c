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

  v4u64_op0 = (v4u64){0x00000000000000fe, 0x0000000000000000,
                      0x00000000000000fe, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffff5f5c, 0xffffffffffff5f5c,
                      0xffffffffffff5f5c, 0xffffffffffff5f5c};
  __m256i_result = (__m256i){0x00000000000000fe, 0xff00000000000000,
                             0x00000000000000fe, 0xff00000000000000};
  __m256i_out = __lasx_xvextrins_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0xfe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xe161616161614e60, 0xe161616161616161,
                      0xe161616161614e60, 0xe161616161616161};
  __m256i_result = (__m256i){0x0000000000000061, 0x0000000000000000,
                             0x0000000000000061, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00007f7f00007f7f,
                      0x0000000000000000, 0x00007f7f00007f7f};
  v4u64_op1 = (v4u64){0xfffffff900000800, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00007f7f00007fff,
                             0x0000000000000000, 0x00007f7f00007f00};
  __m256i_out = __lasx_xvextrins_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x87);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000080008001, 0x0000000000000000,
                      0x0000000080008001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000080000000, 0x0000000000000000,
                             0x0000000080000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x33);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0xe7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0100010001000100, 0x0100010001000100,
                      0x0100010001000100, 0x0100010001000100};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xff00010001000100, 0x0100010001000100,
                             0xff00010001000100, 0x0100010001000100};
  __m256i_out = __lasx_xvextrins_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ff00fff8ffc0, 0x00000000fff8ffc0,
                      0x0000ff00fff8ffc0, 0x00000000fff8ffc0};
  v4u64_op1 = (v4u64){0x0000ff00fff8ffc0, 0x00000000fff8ffc0,
                      0x0000ff00fff8ffc0, 0x00000000fff8ffc0};
  __m256i_result = (__m256i){0x0000ff00fff8ffc0, 0x00000000fff8fff8,
                             0x0000ff00fff8ffc0, 0x00000000fff8fff8};
  __m256i_out = __lasx_xvextrins_b((__m256)v4u64_op0, (__m256)v4u64_op1, 0x82);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000fffffffe0, 0x0000000000000000,
                      0x0000000fffffefc0, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffefffffefc, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0x0000000fffffffff, 0x0000000000000000,
                             0x0000000fffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x83);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xda);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000ffff00000000, 0x0000000000000000,
                             0x0000ffff00000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xa5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffc6ffc6003a003a,
                      0xffffffffffffffff, 0xffc6ffc6003a003a};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffff0000, 0xffc6ffc6003a003a,
                             0xffffffffffff0000, 0xffc6ffc6003a003a};
  __m256i_out = __lasx_xvextrins_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvextrins_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ff01, 0x0000ff0100ff0000,
                      0x000000000000ff01, 0x0000ff0100ff0000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000000000ff01, 0x0000000000ff0000,
                             0x000000000000ff01, 0x0000000000ff0000};
  __m256i_out = __lasx_xvextrins_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000600000006, 0x0000000600000006,
                      0x0000000600000006, 0x0000000600000006};
  v4u64_op1 = (v4u64){0x8000000000000405, 0x8000000001010100,
                      0x8000000000000405, 0x8000000001010100};
  __m256i_result = (__m256i){0x0000000600000006, 0x0000000600000006,
                             0x0000000600000006, 0x0000000600000006};
  __m256i_out = __lasx_xvextrins_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000007f8000, 0x0000000000000000,
                      0x00000000007f8000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000002000000, 0x0000000000000000,
                      0x0000000002000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000002000000, 0x0000000000000000,
                      0x0000000002000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000002000000, 0x0000000000000000,
                             0x0000000002000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x43);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000020200, 0x0000000000000000,
                      0x0000000002020202, 0x0000000000020202};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x25);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7bbbbbbbf7777778, 0x0000000044444443,
                      0x7bbbbbbbf7777778, 0x0000000044444443};
  __m256i_result = (__m256i){0x000000007bbbbbbb, 0x0000000000000000,
                             0x000000007bbbbbbb, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x66);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x232221201f1e1d1c, 0x2b2a292827262524,
                      0x232221201f1e1d1c, 0x2b2a292827262524};
  v4u64_op1 = (v4u64){0x0000000000000023, 0x0000000000000000,
                      0x0000000000000023, 0x0000000000000000};
  __m256i_result = (__m256i){0x232221201f1e1d1c, 0x0000000027262524,
                             0x232221201f1e1d1c, 0x0000000027262524};
  __m256i_out = __lasx_xvextrins_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xbd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvextrins_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x54);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000430207f944, 0x0000000000000000,
                      0x000000430207f944, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1a);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffe97c020010001, 0xffffffffffffffff,
                      0xfffe97c020010001, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xfffe97a1df5b41b0, 0xfffeb664007ffd61,
                      0xfffe97a1df5b41b0, 0xfffeb664007ffd61};
  __m256i_result = (__m256i){0xfffe97c020010001, 0xffffffff007ffd61,
                             0xfffe97c020010001, 0xffffffff007ffd61};
  __m256i_out = __lasx_xvextrins_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x62);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff49fe4200000000, 0xfe02fe02fee5fe22,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xbf28b0686066be60, 0xffffffff0000ffff,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xff49fe4200000000, 0xffffffff0000ffff,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xbf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000001, 0x0000000000000001,
                      0x0000000000000001, 0x0000000000000001};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000001,
                             0xffffffffffffffff, 0x0000000000000001};
  __m256i_out = __lasx_xvextrins_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x99);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvextrins_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00003f3f00003f3f,
                      0x0000000000000000, 0x00003f3f00003f3f};
  v4u64_op1 = (v4u64){0xffffffff0000000d, 0xffffffff0000000f,
                      0xffffffff0000000d, 0xffffffff0000000f};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffff0000000d,
                             0x0000000000000000, 0xffffffff0000000d};
  __m256i_out = __lasx_xvextrins_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x56);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001ffff0001ffff, 0x0001ffff0001ffff,
                      0x0001ffff0001ffff, 0x0001ffff0001ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0001ffff0001ffff,
                             0x0000000000000000, 0x0001ffff0001ffff};
  __m256i_out = __lasx_xvextrins_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
