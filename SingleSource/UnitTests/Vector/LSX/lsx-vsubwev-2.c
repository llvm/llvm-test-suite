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
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000004, 0x00ff00ff00000083};
  __m128i_result = (__m128i){0x000000000000fffc, 0xff01ff010000ff7d};
  __m128i_out = __lsx_vsubwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1000100010001000, 0x1000100010001000};
  v2u64_op1 = (v2u64){0xffff00fc0000ff02, 0x0000000000000001};
  __m128i_result = (__m128i){0xff01ff040000fffe, 0x000000000000ffff};
  __m128i_out = __lsx_vsubwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1f5533a694f902c0, 0xfffffacdb6dbecac};
  v2u64_op1 = (v2u64){0xff39ff37ff35ff33, 0x21011f3f193d173b};
  __m128i_result = (__m128i){0x001c006f00c4008d, 0x00fe008e009e0071};
  __m128i_out = __lsx_vsubwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xd1b09480f2123460, 0x9c9ca19d509ae734};
  v2u64_op1 = (v2u64){0x9c9c9c9c9c9c9c9c, 0x9c9c9c9c9c9c9c9c};
  __m128i_result = (__m128i){0x0014ffe4ff76ffc4, 0x00000001fffeff98};
  __m128i_out = __lsx_vsubwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xee297a731e5c5f86, 0x34947b4b11684f92};
  __m128i_result = (__m128i){0xffd7ff8dffa4ff7a, 0xff6cffb5ff98ff6e};
  __m128i_out = __lsx_vsubwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_h_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff01018888, 0xfffffffff8f8dada};
  v2u64_op1 = (v2u64){0xfffefffe3f6fb04d, 0xffffffff3ea5016b};
  __m128i_result = (__m128i){0x00000001ffffd83b, 0x000000000000d96f};
  __m128i_out = __lsx_vsubwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000016fff9d3d, 0x00000000f0009d3c};
  v2u64_op1 = (v2u64){0x00000000000007f0, 0x0000000000000bd0};
  __m128i_result = (__m128i){0x000000010000954d, 0x000000000000916c};
  __m128i_out = __lsx_vsubwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000100010000fe01, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000500000005, 0x000000050000007b};
  __m128i_result = (__m128i){0xfffffffc0000fdfc, 0xfffffffbffffff85};
  __m128i_out = __lsx_vsubwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000032, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000032, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffff80df00000000};
  v2u64_op1 = (v2u64){0x2a569f8081c3bbe9, 0xa5c4c774856ba837};
  __m128i_result = (__m128i){0xffff6080ffff4417, 0xffffb96bffff57c9};
  __m128i_out = __lsx_vsubwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffaa076aeb, 0x0000000063b2ac27};
  __m128i_result = (__m128i){0xffff0001ffff9515, 0x00000000ffff53d9};
  __m128i_out = __lsx_vsubwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m128i_out = __lsx_vsubwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00020fbf00000fbf, 0x00060fbf00040fbf};
  v2u64_op1 = (v2u64){0x6363636363636363, 0x6363636363636363};
  __m128i_result = (__m128i){0xffffac5cffffac5c, 0xffffac5cffffac5c};
  __m128i_out = __lsx_vsubwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000ffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffaefffbffaefffb, 0xffaefffbffaefffb};
  __m128i_result = (__m128i){0xffff000500000004, 0xffff0005ffff0005};
  __m128i_out = __lsx_vsubwev_w_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000000a1630000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x00000000a1630000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x00000001fffffffe, 0x00000001fffffffe};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000001};
  __m128i_out = __lsx_vsubwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000001fd0, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000001fd0, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xf77edf9cffffffff, 0xff7ffffef77fffdd};
  __m128i_result = (__m128i){0xffffffff00000001, 0x0000000008800022};
  __m128i_out = __lsx_vsubwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffe3d7, 0xffffffffffffda6f};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x0000000000000001};
  __m128i_result = (__m128i){0x00000000ffffe3d6, 0x00000000ffffda6e};
  __m128i_out = __lsx_vsubwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x003fffff00000000, 0x003fffff00000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x80006b0080808080, 0x8000807f00000000};
  v2u64_op1 = (v2u64){0xc0000002b0995850, 0xffff00011cf0c569};
  __m128i_result = (__m128i){0xffffffffcfe72830, 0xffffffffe30f3a97};
  __m128i_out = __lsx_vsubwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x58fa6b4000000000, 0x00000000ff9f5c25};
  v2u64_op1 = (v2u64){0x58fa6b4000000000, 0x00000000ff9f5c25};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8080808080808080, 0x8080808080808080};
  v2u64_op1 = (v2u64){0xcda585aebbb2836a, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffc4cdfd16, 0x0000000080808080};
  __m128i_out = __lsx_vsubwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x77eb15638eeb5fc2, 0x801dd5cb0004e058};
  v2u64_op1 = (v2u64){0x0000002000000000, 0x000000200000001b};
  __m128i_result = (__m128i){0x000000008eeb5fc2, 0x000000000004e03d};
  __m128i_out = __lsx_vsubwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_d_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000001, 0xffffffffffffffff};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000c7fff000c, 0x0000000c0000bd49};
  v2u64_op1 = (v2u64){0xfffff00010000fff, 0x0000000000000001};
  __m128i_result = (__m128i){0x0000100c6ffef00d, 0xffffffffffffffff};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000c00000000000, 0x0000006f00000000};
  v2u64_op1 = (v2u64){0x0000000000001f0a, 0x000000000000006f};
  __m128i_result = (__m128i){0x0000bfffffffe0f6, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffcfffdfffcfffd, 0xfffcfffcfffcfffd};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffcfffdfffcfffd, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffff7e00000081};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0a0a0a0a0a0a0a0a, 0x0a0a0a0a0a0a0a0a};
  v2u64_op1 = (v2u64){0xffff6080ffff4417, 0xffffb96bffff57c9};
  __m128i_result = (__m128i){0x0a0aa9890a0ac5f3, 0xffffffffffffffff};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x370bdfecffecffec, 0x370bdfecffecffec};
  v2u64_op1 = (v2u64){0x0010001000100010, 0x0010001000100010};
  __m128i_result = (__m128i){0x36fbdfdcffdcffdc, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000100000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000100000000, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0001000100010001, 0x0001000100010001};
  __m128i_result = (__m128i){0xfffefffefffeffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff000000000000, 0xffffffff00000000};
  v2u64_op1 = (v2u64){0x0a753500a9fa0d06, 0x000000000a752a55};
  __m128i_result = (__m128i){0xf589caff5605f2fa, 0x0000000000000000};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000087c, 0x087c000000000000};
  v2u64_op1 = (v2u64){0x00000001000010f8, 0x10f8000100000001};
  __m128i_result = (__m128i){0xfffffffefffff784, 0xffffffffffffffff};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffff000000000000, 0xffff000000000000};
  __m128i_result = (__m128i){0x0001000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vsubwev_q_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
