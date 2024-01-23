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

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000000ff000000ff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x00ff00ff00000000};
  __m128i_out = __lsx_vsrlni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x171f0a1f6376441f, 0x6363797c63990099};
  v2u64_op1 = (v2u64){0x171f0a1f6376441f, 0x6363797c63990099};
  __m128i_result = (__m128i){0x181e180005021811, 0x181e180005021811};
  __m128i_out = __lsx_vsrlni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x000000ff000000ff};
  __m128i_result = (__m128i){0x00ff00ff00000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000002050320, 0x0000000002050320};
  v2u64_op1 = (v2u64){0x010101017f010101, 0x0101010101010101};
  __m128i_result = (__m128i){0x020202020202fe02, 0x0000040600000406};
  __m128i_out = __lsx_vsrlni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xb1b1b1b1b16f0670, 0x000000000042ab41};
  v2u64_op1 = (v2u64){0x0000000044470000, 0x00000000084d12ce};
  __m128i_result = (__m128i){0x0000000000000100, 0x0000000202020200};
  __m128i_out = __lsx_vsrlni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_b_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000fe00fd, 0xc39fffff007fffff};
  v2u64_op1 = (v2u64){0x78c00000ff000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000003c607f80, 0x61cf003f0000007f};
  __m128i_out = __lsx_vsrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff7f01ff01, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffff7f01ff01, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffffffffffffe03, 0xfffffffffffffe03};
  __m128i_out = __lsx_vsrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000ffffffffffff, 0x0000ffffffffffff};
  __m128i_result = (__m128i){0x00003fff00003fff, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x12);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000a00028004000, 0xf0fd800080000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffff00000000};
  __m128i_result = (__m128i){0x000f000000000000, 0x000f000800000002};
  __m128i_out = __lsx_vsrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vsrlni_h_w((__m128)v2u64_op0, (__m128)v2u64_op1, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x1e801ffc7fc00000, 0x7fc000007fc00000};
  __m128i_result = (__m128i){0x00003fe00ffe3fe0, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x11);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000008, 0x0000000000000008};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xaeaeaeaeaeaeae35, 0xaeaeaeaeaeaeae35};
  v2u64_op1 = (v2u64){0xaeaeaeaeaeaeae35, 0xaeaeaeaeaeaeae35};
  __m128i_result = (__m128i){0x0000000200000002, 0x0000000200000002};
  __m128i_out = __lsx_vsrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3e);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000008140c80, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000008140c80, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000002050320, 0x0000000002050320};
  __m128i_out = __lsx_vsrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xe364525335ede000, 0xffffe000ffffe000};
  __m128i_result = (__m128i){0x00000fff00000e36, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x34);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_w_d((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x000000000000001f, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffff8001ffff8001};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x7fff7fff7fff7fff};
  __m128i_result = (__m128i){0x000fffefffefffef, 0x001ffff0003ffff0};
  __m128i_out = __lsx_vsrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4b);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x601fbfbeffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfff8000000000000, 0xfffb00fdfdf7ffff};
  __m128i_out = __lsx_vsrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0xd);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000455555555, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000008, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7c7c000000007176, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000f3040705, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000001f1f};
  __m128i_out = __lsx_vsrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x32);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000001};
  v2u64_op1 = (v2u64){0x0000000000040001, 0x00000000000bffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc001a1867fffa207, 0xe4c8b96e2560afe9};
  v2u64_op1 = (v2u64){0xc001a1867fffa207, 0xe4c8b96e2560afe9};
  __m128i_result = (__m128i){0xe2560afe9c001a18, 0xe2560afe9c001a18};
  __m128i_out = __lsx_vsrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x24);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x020310edc003023d};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x000000080c43b700};
  __m128i_out = __lsx_vsrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x56);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x020310edc003023d, 0x30eb022002101b20};
  v2u64_op1 = (v2u64){0x020310edc003023d, 0x30eb022002101b20};
  __m128i_result = (__m128i){0x022002101b200203, 0x022002101b200203};
  __m128i_out = __lsx_vsrlni_d_q((__m128)v2u64_op0, (__m128)v2u64_op1, 0x30);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
