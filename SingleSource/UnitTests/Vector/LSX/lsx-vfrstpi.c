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

  v2u64_op0 = (v2u64){0x0000007f00000004, 0x0000000100000001};
  v2u64_op1 = (v2u64){0x0001000100000004, 0x0000000401000001};
  __m128i_result = (__m128i){0x0000007f00000004, 0x0000000110000001};
  __m128i_out = __lsx_vfrstpi_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xeef8227b4f8017b1, 0x75b043c4d17db125};
  v2u64_op1 = (v2u64){0x027c027c000027c0, 0x0000000000000000};
  __m128i_result = (__m128i){0xeef8227b4f8017b1, 0x75b043c4007db125};
  __m128i_out = __lsx_vfrstpi_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ff000000ff00, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x03c0038000000380, 0x03c0000000000000};
  __m128i_result = (__m128i){0x0000ff000000ff00, 0x0000000000000000};
  __m128i_out = __lsx_vfrstpi_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x0);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x5b35342c979955da, 0x0000000000000009};
  v2u64_op1 = (v2u64){0xffffffff00000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x5b35342c970455da, 0x0000000000000009};
  __m128i_out = __lsx_vfrstpi_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0010000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfrstpi_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001002affca0070, 0x00d3012b015700bb};
  v2u64_op1 = (v2u64){0x0000000100013fa0, 0x00000001ca02f854};
  __m128i_result = (__m128i){0x00010000ffca0070, 0x00d3012b015700bb};
  __m128i_out = __lsx_vfrstpi_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000001b, 0x000000000000001b};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x000000000000001b, 0x000000000000001b};
  __m128i_out = __lsx_vfrstpi_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x379674c000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000fffffffe, 0xffffff7ffffffffe};
  __m128i_result = (__m128i){0x379674c000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfrstpi_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x8);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x02f3030303030303, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x004d004d004d004d, 0x004d004d004d004d};
  __m128i_result = (__m128i){0x02f3030303100303, 0x0000000000000000};
  __m128i_out = __lsx_vfrstpi_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7f4300177f7a7f59, 0x0027002a00030018};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x7f4300177f7a7f59, 0x0027002a00080018};
  __m128i_out = __lsx_vfrstpi_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000800000000, 0x0000000000000000};
  __m128i_out = __lsx_vfrstpi_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x2);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000010a000b, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00ffff000000ff00, 0x00ffff0000000000};
  __m128i_result = (__m128i){0x00000000010a000b, 0x0000000000000000};
  __m128i_out = __lsx_vfrstpi_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0101010101010101, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0101010101010101, 0x0008000000000000};
  __m128i_out = __lsx_vfrstpi_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fffe0001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000000002bb, 0x00000000000000bf};
  __m128i_result = (__m128i){0x00080000fffe0001, 0x0000000000000000};
  __m128i_out = __lsx_vfrstpi_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff81a800003bea, 0x0000545cffffab1d};
  v2u64_op1 = (v2u64){0x545cab1d81a83bea, 0x13f9c5b60028a415};
  __m128i_result = (__m128i){0xffff81a800003bea, 0x0000545cffff0001};
  __m128i_out = __lsx_vfrstpi_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0008000000000000};
  __m128i_out = __lsx_vfrstpi_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x7);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000800000000};
  __m128i_out = __lsx_vfrstpi_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0008000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vfrstpi_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000800000000};
  __m128i_out = __lsx_vfrstpi_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x6);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x001a001a001a000b, 0x001a001a001a000b};
  v2u64_op1 = (v2u64){0x001a001a001a000b, 0x001a001a001a000b};
  __m128i_result = (__m128i){0x001a001a001a000b, 0x001a001a001a0008};
  __m128i_out = __lsx_vfrstpi_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00007770ffff941d, 0x000000400000004c};
  v2u64_op1 = (v2u64){0x00007770ffff941d, 0x000000400000004c};
  __m128i_result = (__m128i){0x00007770ffff941d, 0x000000400000004c};
  __m128i_out = __lsx_vfrstpi_h((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
