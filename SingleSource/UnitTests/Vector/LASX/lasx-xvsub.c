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

  v4u64_op0 = (v4u64){0x0000000000000009, 0x0000000000000009,
                      0x0000000000000009, 0x0000000000000009};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000009, 0x0000000000000009,
                             0x0000000000000009, 0x0000000000000009};
  __m256i_out = __lasx_xvsub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0xffffffffffffffff,
                      0x00000000ffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000ffffffffffff, 0xffffffffffffffff,
                      0x0000ffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000010100000000, 0x0000000000000000,
                             0x0000010100000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000c409ed87, 0x000000010bb83239,
                      0x000000001cc7ee87, 0x00000000ffbe20fc};
  v4u64_op1 = (v4u64){0xff00fe00feff02ff, 0xff00fe00feff02ff,
                      0xff00fe00feff02ff, 0xff00fe00feff02ff};
  __m256i_result = (__m256i){0x01000200c60aeb88, 0x010002010db9303a,
                             0x010002001ec8ec88, 0x0100020001bf1efd};
  __m256i_out = __lasx_xvsub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010101,
                             0x0101010101010101, 0x0101010101010101};
  __m256i_out = __lasx_xvsub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010200000000, 0x0101010101010101,
                      0x0101010200000000, 0x0101010101010101};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010200000000, 0x0101010101010101,
                             0x0101010200000000, 0x0101010101010101};
  __m256i_out = __lasx_xvsub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7e00000000000000, 0x000000007e1c7e1c,
                      0x7e00000000000000, 0x000000007e1c7e1c};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7e00000000000000, 0x000000007e1c7e1c,
                             0x7e00000000000000, 0x000000007e1c7e1c};
  __m256i_out = __lasx_xvsub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000004000000000, 0x0000000040004000,
                      0x0000004000000000, 0x0000000040004000};
  v4u64_op1 = (v4u64){0x01ffff4300ffff00, 0x0100010001000100,
                      0x01ffff4300ffff00, 0x0100010001000100};
  __m256i_result = (__m256i){0xff0101fd00010100, 0xff00ff003f003f00,
                             0xff0101fd00010100, 0xff00ff003f003f00};
  __m256i_out = __lasx_xvsub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsub_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010001, 0x0001000100010001,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000007, 0x00ff00ff00000007,
                      0x00000000000000e7, 0x00ff00ff00000007};
  __m256i_result = (__m256i){0x000100010001fffa, 0xff02ff020001fffa,
                             0x000000000000ff19, 0xff01ff010000fff9};
  __m256i_out = __lasx_xvsub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x43e019c657c7d050, 0x43d03bfff827e9f9,
                      0x43dac1f2a3804ff0, 0x43d03bfff827ea21};
  __m256i_result = (__m256i){0xbc20e63aa8392fb0, 0xbc30c40107d91607,
                             0xbc263e0e5c80b010, 0xbc30c40107d915df};
  __m256i_out = __lasx_xvsub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff21c241ff21c241, 0xff21c241ff21c241,
                      0xff21c241ff21c241, 0xff21c241ff21c241};
  v4u64_op1 = (v4u64){0x0000000000000009, 0x0000000000000000,
                      0x0000000000000009, 0x0000000000000000};
  __m256i_result = (__m256i){0xff21c241ff21c238, 0xff21c241ff21c241,
                             0xff21c241ff21c238, 0xff21c241ff21c241};
  __m256i_out = __lasx_xvsub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0808080808080808,
                      0x0000000000000000, 0x0808080808080808};
  __m256i_result = (__m256i){0x0000000000000000, 0xf7f8f7f8f7f8f7f8,
                             0x0000000000000000, 0xf7f8f7f8f7f8f7f8};
  __m256i_out = __lasx_xvsub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000e0000000d, 0x0000000e000e000e,
                      0x0000000e0000000d, 0x0000000e000e000e};
  v4u64_op1 = (v4u64){0x0000000e0000000d, 0x0000000e000e000e,
                      0x0000000e0000000d, 0x0000000e000e000e};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x7f7f7f7f7f7f7f7f, 0x00000000207f2000,
                      0x7f7f7f7f7f7f7f7f, 0x207f207f207f2000};
  __m256i_result = (__m256i){0x8080808080808080, 0xffffffffdf80dfff,
                             0x8080808080808080, 0xdf80df80df80dfff};
  __m256i_out = __lasx_xvsub_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x45c5c5c545c5c5c5, 0xc5c5c5c4c5c5c5c4,
                      0x45c5c5c545c5c5c5, 0xc5c5c5c4c5c5c5c4};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x45c5c5c645c5c5c6, 0xc5c5c5c5c5c5c5c5,
                             0x45c5c5c645c5c5c6, 0xc5c5c5c5c5c5c5c5};
  __m256i_out = __lasx_xvsub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7ff8000000000000, 0x1f0fdf7f3e3b31d4,
                      0x7ff8000000000000, 0x1f0fdf7f3e3b31d4};
  __m256i_result = (__m256i){0x8008000000000000, 0xe0f02081c1c4ce2c,
                             0x8008000000000000, 0xe0f02081c1c4ce2c};
  __m256i_out = __lasx_xvsub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xff3eff3eff3eff3e,
                      0xffffffffffffffff, 0xff3eff3eff3eff3e};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xff3eff3eff3eff3e,
                             0xffffffffffffffff, 0xff3eff3eff3eff3e};
  __m256i_out = __lasx_xvsub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fffffffffffffff, 0x00000000001c9880,
                      0x7fffffffffffffff, 0x00000000001c9880};
  __m256i_result = (__m256i){0x8000000100000001, 0x00000000ffe36780,
                             0x8000000100000001, 0x00000000ffe36780};
  __m256i_out = __lasx_xvsub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00e9a80014ff0000, 0x00b213171dff0606,
                      0x00e9a80014ff0000, 0x00b213171dff0606};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x00e9a80114ff0001, 0x00b213181dff0607,
                             0x00e9a80114ff0001, 0x00b213181dff0607};
  __m256i_out = __lasx_xvsub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000fdfdfe, 0x7fffffffffffffff,
                      0x7fffffffffffffff, 0x7fffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0001fffe00010000, 0x0001fffe0001fffe};
  __m256i_result = (__m256i){0x0000000000fdfdfe, 0x7fffffffffffffff,
                             0x7ffe0001fffeffff, 0x7ffe0001fffe0001};
  __m256i_out = __lasx_xvsub_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffffffffff, 0x0000000000000000,
                      0x7fffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffff90ffffff80, 0x0000000000000000,
                      0xffffff90ffffff80, 0x0000000000000000};
  __m256i_result = (__m256i){0x8000006f0000007f, 0x0000000000000000,
                             0x8000006f0000007f, 0x0000000000000000};
  __m256i_out = __lasx_xvsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x7f7f7f7f7f7f7f7f,
                      0x7f7f7f7f7f7f7f7f, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x8080808080808081,
                             0x8080808080808081, 0x0000000000000000};
  __m256i_out = __lasx_xvsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff017e01fe, 0x017e00ff017e00ff,
                      0x00ff00ff017e01fe, 0x00ff00ff00ff00ff};
  v4u64_op1 = (v4u64){0xe1616161e1614e60, 0xe1616161e1614e60,
                      0xe1616161e1614e60, 0xe1616161e1614e60};
  __m256i_result = (__m256i){0x1f9d9f9d201cb39e, 0x201c9f9d201cb29f,
                             0x1f9d9f9d201cb39e, 0x1f9d9f9d1f9db29f};
  __m256i_out = __lasx_xvsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffeffebfb7afb62, 0x0000000000000000,
                      0xfffeffebfb7afb62, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xc192181230000000, 0xbff0000000000000,
                      0xc192181230000000, 0xbff0000000000000};
  __m256i_result = (__m256i){0x3e6ce7d9cb7afb62, 0x4010000000000000,
                             0x3e6ce7d9cb7afb62, 0x4010000000000000};
  __m256i_out = __lasx_xvsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff00000000, 0x0000ffff0000ffff,
                      0x0000ffff00000000, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff00000000, 0x0000ffff0000ffff,
                             0x0000ffff00000000, 0x0000ffff0000ffff};
  __m256i_out = __lasx_xvsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000013, 0x0000000000000013,
                      0x0000000000000013, 0x0000000000000013};
  __m256i_result = (__m256i){0xffffffffffffffed, 0xffffffffffffffed,
                             0xffffffffffffffed, 0xffffffffffffffed};
  __m256i_out = __lasx_xvsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0fffffff0fffffff, 0x0000000000000000,
                      0x0fffffff0fffffff, 0x0fffffff0fffffff};
  v4u64_op1 = (v4u64){0x000000007fff7fff, 0x0000000000000000,
                      0x7fff7fff7fff7fff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0ffffffe90008000, 0x0000000000000000,
                             0x90007fff90008000, 0x0fffffff0fffffff};
  __m256i_out = __lasx_xvsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000001, 0x0000000000000001,
                      0x0000000000000001, 0x0000000000000001};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8000000080000000, 0x8000000080000000,
                      0x8000000080000000, 0x8000000080000000};
  __m256i_result = (__m256i){0x7fffffff80000000, 0x7fffffff80000000,
                             0x7fffffff80000000, 0x7fffffff80000000};
  __m256i_out = __lasx_xvsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x05ea05ea05ea05ec, 0x0000000000000001,
                      0x05ea05ea05ea05ec, 0x0000000000000001};
  __m256i_result = (__m256i){0xfa15fa15fa15fa14, 0xffffffffffffffff,
                             0xfa15fa15fa15fa14, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsub_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsub_q((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0504070804040404, 0x0505070804040404,
                      0x0504070804040404, 0x0505070804040404};
  v4u64_op1 = (v4u64){0x000000ff000000ff, 0x0000ff000000ffff,
                      0x000000ff000000ff, 0x0000ff000000ffff};
  __m256i_result = (__m256i){0x0504060904040305, 0x0504080804030405,
                             0x0504060904040305, 0x0504080804030405};
  __m256i_out = __lasx_xvsub_q((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ff00fff8ffc0, 0x00000000fff8fff8,
                      0x0000ff00fff8ffc0, 0x00000000fff8fff8};
  v4u64_op1 = (v4u64){0x0000ff0100090040, 0x00000000fff8ff40,
                      0x0000ff0100090040, 0x00000000fff8ff40};
  __m256i_result = (__m256i){0xffffffffffefff80, 0x00000000000000b7,
                             0xffffffffffefff80, 0x00000000000000b7};
  __m256i_out = __lasx_xvsub_q((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
