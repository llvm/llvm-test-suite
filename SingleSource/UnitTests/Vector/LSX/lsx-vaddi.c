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

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000001};
  __m128i_result = (__m128i){0x1414141414141415, 0x1414141414141415};
  __m128i_out = __lsx_vaddi_bu((__m128)v2u64_op0, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0505050504040404, 0x0505050505050505};
  __m128i_out = __lsx_vaddi_bu((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000008140c80, 0x0000000000000000};
  __m128i_result = (__m128i){0x1f1f1f1f27332b9f, 0x1f1f1f1f1f1f1f1f};
  __m128i_out = __lsx_vaddi_bu((__m128)v2u64_op0, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000000};
  __m128i_result = (__m128i){0x0303030303030304, 0x0303030303030303};
  __m128i_out = __lsx_vaddi_bu((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8080808080808080, 0x8080808080808080};
  __m128i_result = (__m128i){0x8f8f8f8f8f8f8f8f, 0x8f8f8f8f8f8f8f8f};
  __m128i_out = __lsx_vaddi_bu((__m128)v2u64_op0, 0xf);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0018001800180018, 0x0018001800180018};
  __m128i_out = __lsx_vaddi_hu((__m128)v2u64_op0, 0x18);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000080000000000, 0x0000080000000000};
  __m128i_result = (__m128i){0x0019081900190019, 0x0019081900190019};
  __m128i_out = __lsx_vaddi_hu((__m128)v2u64_op0, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000a000a000a000a, 0x000a000a000a000a};
  __m128i_out = __lsx_vaddi_hu((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000ff0000, 0xffc1000000000000};
  __m128i_result = (__m128i){0x000b000b010a000b, 0xffcc000b000b000b};
  __m128i_out = __lsx_vaddi_hu((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x001f001f001f001f, 0x001f001f001f001f};
  __m128i_out = __lsx_vaddi_hu((__m128)v2u64_op0, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x001c001c001c001c, 0x001c001c001c001c};
  __m128i_out = __lsx_vaddi_hu((__m128)v2u64_op0, 0x1c);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc8847ef6ed3f2000, 0x67eb85afb2ebb000};
  __m128i_result = (__m128i){0xc89d7f0fed582019, 0x680485c8b304b019};
  __m128i_out = __lsx_vaddi_hu((__m128)v2u64_op0, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000a0000000a, 0x0000000a0000000a};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0xa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffe000ffff1fff, 0x0000000001000001};
  __m128i_result = (__m128i){0xffffe009ffff2008, 0x000000090100000a};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000300000003, 0x0000000200000002};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0x3);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfe00fcfffe01fd01, 0xfc01fcfefc02fdf7};
  __m128i_result = (__m128i){0xfe00fd14fe01fd16, 0xfc01fd13fc02fe0c};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0x15);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000001300000013, 0x0000001300000013};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0x13);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000007fff0000, 0x000000000000bd3d};
  __m128i_result = (__m128i){0x0000000c7fff000c, 0x0000000c0000bd49};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000fffe0001, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000005fffe0006, 0x0000000500000005};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0x5);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000000fffffeff};
  __m128i_result = (__m128i){0x0000000900000009, 0x00000009ffffff08};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xaa55555655aaaaa8, 0x55aa55aa55aa55ab};
  __m128i_result = (__m128i){0xaa55556f55aaaac1, 0x55aa55c355aa55c4};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0x19);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000040, 0x0000000000000020};
  __m128i_result = (__m128i){0x0000000e0000004e, 0x0000000e0000002e};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0xe);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000400000004, 0x0000000400000004};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x003f0000ffffffff, 0x003f0000ffffffff};
  __m128i_result = (__m128i){0x003f000400000003, 0x003f000400000003};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0x4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff8000010f800000, 0x0000000000000000};
  __m128i_result = (__m128i){0xff80000a0f800009, 0x0000000900000009};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0x9);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x020310d0c0030220, 0x30eb020302101b03};
  __m128i_result = (__m128i){0x020310edc003023d, 0x30eb022002101b20};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0x1d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x59f7fd7059f7fd70, 0x0000000000000000};
  __m128i_result = (__m128i){0x59f7fd8759f7fd87, 0x0000001700000017};
  __m128i_out = __lsx_vaddi_wu((__m128)v2u64_op0, 0x17);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x20c4e0c4e0da647a, 0x6420e0208400c4c4};
  __m128i_result = (__m128i){0x20c4e0c4e0da6499, 0x6420e0208400c4e3};
  __m128i_out = __lsx_vaddi_du((__m128)v2u64_op0, 0x1f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1918171615141312, 0x21201f1e1d001b1a};
  __m128i_result = (__m128i){0x191817161514131d, 0x21201f1e1d001b25};
  __m128i_out = __lsx_vaddi_du((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000014, 0x0000000000000014};
  __m128i_out = __lsx_vaddi_du((__m128)v2u64_op0, 0x14);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00007770ffff9411, 0x0000004000000040};
  __m128i_result = (__m128i){0x00007770ffff941d, 0x000000400000004c};
  __m128i_out = __lsx_vaddi_du((__m128)v2u64_op0, 0xc);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000016, 0x0000000000000016};
  __m128i_out = __lsx_vaddi_du((__m128)v2u64_op0, 0x16);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000800000000};
  __m128i_result = (__m128i){0x000000000000000b, 0x000000080000000b};
  __m128i_out = __lsx_vaddi_du((__m128)v2u64_op0, 0xb);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
