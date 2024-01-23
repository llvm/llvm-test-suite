#include "lsx_test_util.h"
#include <lsxintrin.h>

int
main ()
{
  __m128i __m128i_out, __m128i_result;
  __m128  __m128_out, __m128_result;
  __m128d __m128d_out, __m128d_result;
  v2u64 v2u64_op0, v2u64_op1, v2u64_op2;
  v4i32 v4i32_op0, v4i32_op1, v4i32_op2;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000008000000080, 0x0000010000000002};
  v2u64_op1 = (v2u64){0x1000100010001000, 0x0000000c7fff000c};
  v2u64_op2 = (v2u64){0xfffff0016fff8d3d, 0xfffff000f0008d3c};
  __m128i_result = (__m128i){0xfff0ff8006f0f950, 0x00000100f8100002};
  __m128i_out = __lsx_vmaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x007ffd0001400840, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x007ffd0001400840, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000002000, 0x0000000000002000};
  v2u64_op1 = (v2u64){0xffff0000ffff0000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x000000ff000000ff};
  __m128i_result = (__m128i){0x0000000000002000, 0x0000000000002000};
  __m128i_out = __lsx_vmaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0001000100010058};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0001000100010058};
  __m128i_out = __lsx_vmaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ffac0a000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000002000000000, 0x000000200000001b};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000ffac0a000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000017fda829, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000017fda829, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000800000000ffff, 0xff8000000000ffff};
  v2u64_op2 = (v2u64){0xd705c77a7025c899, 0x697eba2bedfa9c82};
  __m128i_result = (__m128i){0xfffeb827ffffffff, 0xffcb410000000000};
  __m128i_out = __lsx_vmaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fffffc00, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000200010, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000fffffc00, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000000f, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xaaacac88a3a9a96a, 0x000000c5ac01015b};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000000f, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x28bf02d1ec6a35b2, 0x7ef4002d21fc7001};
  v2u64_op1 = (v2u64){0xffff6080ffff4417, 0xffffb96bffff57c9};
  v2u64_op2 = (v2u64){0xff8000007fc00000, 0xff800000ff800000};
  __m128i_result = (__m128i){0x28bf0351ec69b5f2, 0x7ef400ad21fc7081};
  __m128i_out = __lsx_vmaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0001000100010001, 0x0001200100012001};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100000001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xcf00000000000000, 0xbf8000000000ffff};
  v2u64_op2 = (v2u64){0xcf00000000000000, 0xbf80000000000000};
  __m128i_result = (__m128i){0x0961000100000001, 0x1040400000000000};
  __m128i_out = __lsx_vmaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000001010000, 0x03574e3a62407e03};
  v2u64_op1 = (v2u64){0x00000000ffff0000, 0x7da9b23a624082fd};
  v2u64_op2 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000001010000, 0x03574e39e496cbc9};
  __m128i_out = __lsx_vmaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0400040004000400};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffffff01018888, 0xfffffffff8f8dada};
  __m128i_result = (__m128i){0x0000000000000000, 0x0400040004000400};
  __m128i_out = __lsx_vmaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000030000003f, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000ffc100010001, 0x3f77aab500000000};
  v2u64_op2 = (v2u64){0x0000ffc100010001, 0x3f77aab500000000};
  __m128i_result = (__m128i){0x00000000ff820f81, 0x0fbc1df53c1ae3f9};
  __m128i_out = __lsx_vmaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000020000020, 0x0000000020000020};
  v2u64_op2 = (v2u64){0x0000000000810000, 0x00000000ff801c9e};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0003000000012020, 0x000700000004e000};
  v2u64_op1 = (v2u64){0x003f0000ffffffff, 0x003f0000ffffffff};
  v2u64_op2 = (v2u64){0x000000002023dcdc, 0x00000000e00a18f5};
  __m128i_result = (__m128i){0x0003000000012020, 0x000700000004e000};
  __m128i_out = __lsx_vmaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000e0000000e, 0x000000120000000d};
  v2u64_op2 = (v2u64){0x0000ffffffffffff, 0x0000ffffffffffff};
  __m128i_result = (__m128i){0x00000000000dfff2, 0x000000000011ffee};
  __m128i_out = __lsx_vmaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ff8000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffff8000000000, 0xffffff7fffffffff};
  v2u64_op2 = (v2u64){0xffffff8000000000, 0xffffff7fffffffff};
  __m128i_result = (__m128i){0x7ff8010000000001, 0x0000000000003fff};
  __m128i_out = __lsx_vmaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000ff000000ff00};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x000000ff000000ff};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000ff000000ff00};
  __m128i_result = (__m128i){0x01fc020000fe0100, 0x0000ff0000ff0000};
  __m128i_out = __lsx_vmaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000000fff09, 0x00000000000fff08};
  v2u64_op1 = (v2u64){0xffff80000000ffff, 0xffff80ff0000ffff};
  v2u64_op2 = (v2u64){0xfffefffefffefffe, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x00007f01000eff0a, 0xffff80ff0010ff06};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x9d519ee8d2d84f1d, 0xfefd7f7e7f7f7f7f};
  v2u64_op2 = (v2u64){0x0000ffff0000fffe, 0x8644ffff0000ffff};
  __m128i_result = (__m128i){0xd83c8081ffff8080, 0x85bd6b0e94d89998};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000001fc0000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000040004000100, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000001fc0000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x78c00000ff000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x78c00000ff000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x78c00000ff000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000002010202, 0x0000000007070700};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000002010202, 0x0000000007070700};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000c2bac2c2, 0x00000000fefefe6a};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000c2bac2c2, 0x00000000fefefe6a};
  __m128i_out = __lsx_vmaddwod_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x7fff7fff7fff7fff};
  v2u64_op1 = (v2u64){0x4f804f804f804f80, 0x4f804f804f804f80};
  v2u64_op2 = (v2u64){0x000fffefffefffef, 0x001ffff0003ffff0};
  __m128i_result = (__m128i){0xe009f00ee7fb0800, 0x8009700478185812};
  __m128i_out = __lsx_vmaddwod_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1111113111111131, 0x1111113111111131};
  v2u64_op1 = (v2u64){0x0000000000000010, 0x0000000000000010};
  v2u64_op2 = (v2u64){0xffffffffffff0008, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x1111113111111121, 0x1111113111111141};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfefefefefefefefe, 0xfefefefefefefefe};
  v2u64_op1 = (v2u64){0x1000100010001000, 0x1000100010001000};
  v2u64_op2 = (v2u64){0x1000100012030e02, 0x0000000000000000};
  __m128i_result = (__m128i){0xfefefefefefefefe, 0xfefefefefefefefe};
  __m128i_out = __lsx_vmaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000008130c7f, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x1f1f1f27332b9f00, 0x1f1f1f1f1f1f1f00};
  v2u64_op2 = (v2u64){0x370bdfecffecffec, 0x370bdfecffecffec};
  __m128i_result = (__m128i){0x8312f5424ca4a07f, 0x06b1213ef1efa299};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffb00151727, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffff0015172b, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000004, 0x00010000fffffffc};
  __m128i_result = (__m128i){0xfffffffb00151727, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000080800000808, 0x0000080800000808};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xf8f8fd0180810907, 0x010105017878f8f6};
  __m128i_result = (__m128i){0x0000080800000808, 0x0000080800000808};
  __m128i_out = __lsx_vmaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000080000000800};
  v2u64_op1 = (v2u64){0x0000000200000002, 0x0400400204004002};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000080000000800};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000001, 0xfffffffffffffffe};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000158, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0001000100010058};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000158, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000004, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fffbffda, 0x0080000700000014};
  v2u64_op1 = (v2u64){0x000000000005003a, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xfff0000000000000, 0xfff0000000000000};
  __m128i_result = (__m128i){0x00000000fffbffda, 0x0080000700000014};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000024170000, 0x00000000084d12ce};
  v2u64_op2 = (v2u64){0x0808080808080808, 0x0808080808080808};
  __m128i_result = (__m128i){0xb1b1b1b1b16f0670, 0x000000000042ab41};
  __m128i_out = __lsx_vmaddwod_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xb1b1b1b1b16f0670, 0x000000000042ab41};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xb1b1b1b1b16f0670, 0x000000000042ab41};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3960b1a401811060, 0x328e1080889415a0};
  v2u64_op1 = (v2u64){0x3960b1a401811060, 0x328e1080889415a0};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x020310edc003023d};
  __m128i_result = (__m128i){0x2c9e5069f5d57780, 0x32f3c7a38f9f4b8b};
  __m128i_out = __lsx_vmaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000868686868686, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfdce8003090b0906, 0x0674c8868a74fc80};
  v2u64_op2 = (v2u64){0xfdce8003090b0906, 0x0674c8868a74fc80};
  __m128i_result = (__m128i){0xdbe332365392c686, 0x0029aeaca57d74e6};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffd0ba876d000, 0x000002bf8b062000};
  v2u64_op1 = (v2u64){0x41f8e08016161198, 0xe363636363abdf16};
  v2u64_op2 = (v2u64){0x0005847b00000000, 0x0005840100000005};
  __m128i_result = (__m128i){0xcf1225129ad22b6e, 0x0004e8f09e99b528};
  __m128i_out = __lsx_vmaddwod_q_du((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vmaddwod_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
