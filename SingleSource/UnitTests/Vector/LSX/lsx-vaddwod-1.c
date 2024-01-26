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

  v2u64_op0 = (v2u64){0x00000000ca354688, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0404038383838404, 0x0404038383838404};
  __m128i_result = (__m128i){0x00040003ff4dffca, 0x00040003ff83ff84};
  __m128i_out = __lsx_vaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000000040d, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000004, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00001f5400000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000014, 0x0000000000000014};
  __m128i_result = (__m128i){0x0000001f00000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000f80007, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x003fffff00000000, 0x003fffff00000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000ffff00000000, 0x0000ffff00000000};
  __m128i_out = __lsx_vaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffff0100ff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffefffefffeffff, 0xfffefffefffefffe};
  __m128i_out = __lsx_vaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x00000000ffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000000ffffffff};
  __m128i_out = __lsx_vaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6b769e690fa1e119, 0x478b478b38031779};
  v2u64_op1 = (v2u64){0x0000000001030103, 0x0000000000000000};
  __m128i_result = (__m128i){0x006bff9e0010ffe2, 0x0047004700380017};
  __m128i_out = __lsx_vaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xbbc8ecc5f3ced5f3, 0xc0b4d1a5f8babad3};
  v2u64_op1 = (v2u64){0xbbc8ecc5f3ced5f3, 0xc0b4d1a5f8babad3};
  __m128i_result = (__m128i){0xff76ffd8ffe6ffaa, 0xff80ffa2fff0ff74};
  __m128i_out = __lsx_vaddwod_h_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000800};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000800000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x1f54e0ab00000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00001f5400000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000000000f, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000208000002080, 0x0000208000002080};
  v2u64_op1 = (v2u64){0xa352bfac9269e0aa, 0xd70b30c96ea9f4e8};
  __m128i_result = (__m128i){0xffffa352ffff9269, 0xffffd70b00006ea9};
  __m128i_out = __lsx_vaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000208000002080, 0x0000208000002080};
  v2u64_op1 = (v2u64){0xa352bfac9269e0aa, 0xd70b30c96ea9f4e8};
  __m128i_result = (__m128i){0xffffa352ffff9269, 0xffffd70b00006ea9};
  __m128i_out = __lsx_vaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe593c8c4e593c8c4, 0xff800000ff800000};
  v2u64_op1 = (v2u64){0x9b2ee1a4034b4e34, 0x8144ffff01c820a4};
  __m128i_result = (__m128i){0xffff80c1ffffe8de, 0xffff80c400000148};
  __m128i_out = __lsx_vaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffffffefffffffe, 0xfffffffefffffffe};
  __m128i_out = __lsx_vaddwod_w_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x58bcc2013ea1cc1e, 0xa486c90f6537b8d7};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000058bcc201, 0xffffffffa486c90f};
  __m128i_out = __lsx_vaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00001802041b0013, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00001802041b0014, 0x0000000000000001};
  __m128i_result = (__m128i){0x0000000000003004, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff02000200, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffe000ffffe000, 0xffffe000ffffe000};
  __m128i_result = (__m128i){0xffffffffffffdfff, 0xffffffffffffdfff};
  __m128i_out = __lsx_vaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fbf83468, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000fbf83468, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x7fffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffc6bb97ac, 0xffffffff82bb9784};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x000000007ffffffe};
  __m128i_out = __lsx_vaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x4f804f804f804f80, 0x4f804f804f804f80};
  v2u64_op1 = (v2u64){0x000000002ff9afef, 0x00000001000fbff9};
  __m128i_result = (__m128i){0x000000004f804f80, 0x000000004f804f81};
  __m128i_out = __lsx_vaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001000000000, 0x0000001000000010};
  v2u64_op1 = (v2u64){0x0000001000000000, 0x0000001000000010};
  __m128i_result = (__m128i){0x0000000000000020, 0x0000000000000020};
  __m128i_out = __lsx_vaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001000000000, 0x0000001000000010};
  v2u64_op1 = (v2u64){0x000000000000fff0, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000010, 0x0000000000000010};
  __m128i_out = __lsx_vaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffe00029f9f6061, 0xffff0000ffff0000};
  v2u64_op1 = (v2u64){0x64e464e464e464e4, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000064e264e6, 0xfffffffffffeffff};
  __m128i_out = __lsx_vaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0301030203020502, 0x0305030203020502};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000003010302, 0x0000000003050302};
  __m128i_out = __lsx_vaddwod_d_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x01fc020000fe0100, 0x0000ff0000ff0000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000ff0000ff0000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00a6ffceffb60052, 0xff84fff4ff84fff4};
  __m128i_result = (__m128i){0xff84fff4ff84fff4, 0xffffffffffffffff};
  __m128i_out = __lsx_vaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000c2bac2c2, 0x00000000fefefe6a};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000fefefe6a, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000002000000020, 0x0000002000000020};
  v2u64_op1 = (v2u64){0x0032000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000002000000020, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffff0000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffff0000, 0xffffffffffffffff};
  __m128i_out = __lsx_vaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6bae051ffed76001, 0x5a57bacbd7e39680};
  v2u64_op1 = (v2u64){0xf7077b934ac0e000, 0xf3e6586b60d7b152};
  __m128i_result = (__m128i){0x4e3e133738bb47d2, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000093d0000187f, 0x0000117d00007f7b};
  v2u64_op1 = (v2u64){0x7e7f7e7f027f032f, 0x7d7f027f7c7f7c79};
  __m128i_result = (__m128i){0x7d7f13fc7c7ffbf4, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwod_q_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
