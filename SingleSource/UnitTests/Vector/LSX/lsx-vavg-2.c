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
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000100000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavg_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f};
  __m128i_out = __lsx_vavg_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xfffffffffffffffe};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x7f7f7f7f7f7f7f7f, 0xfffffffffffffffe};
  __m128i_out = __lsx_vavg_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f};
  __m128i_out = __lsx_vavg_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x37b951002d81a921, 0x0000100000001000};
  v2u64_op1 = (v2u64){0x000047404f4f040d, 0x000000400000004c};
  __m128i_result = (__m128i){0x1b5c4c203e685617, 0x0000082000000826};
  __m128i_out = __lsx_vavg_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00a975be00accf03, 0x00c2758000bccf42};
  v2u64_op1 = (v2u64){0x00a975be00accf03, 0x00c2758000bccf42};
  __m128i_result = (__m128i){0x00a975be00accf03, 0x00c2758000bccf42};
  __m128i_out = __lsx_vavg_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0100010000000000, 0x0100000001000100};
  v2u64_op1 = (v2u64){0xffffffffffff732a, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x807f807f7fff3995, 0x807f7fff807f807f};
  __m128i_out = __lsx_vavg_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x000000007f7f7f7f};
  v2u64_op1 = (v2u64){0xfffffffffffffff0, 0x0000000000000000};
  __m128i_result = (__m128i){0x7fff7fff7fff7ff8, 0x000000003fbf3fbf};
  __m128i_out = __lsx_vavg_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x353c8cc4b1ec5b09, 0x0101010101010101};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffff00000000ffff};
  __m128i_result = (__m128i){0x1a9e466258f62d84, 0x8080008000808080};
  __m128i_out = __lsx_vavg_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavg_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavg_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000158, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000000000ac, 0x0000000000000000};
  __m128i_out = __lsx_vavg_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000020, 0x9c9c9c9c00000000};
  __m128i_result = (__m128i){0x0000000000000010, 0x4e4e4e4e00000000};
  __m128i_out = __lsx_vavg_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000868686868686, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x1e1e1e1e1e1e1e1e, 0x1e1e1e1e1e1e1e1e};
  __m128i_result = (__m128i){0x0f0f525252525252, 0x0f0f0f0f0f0f0f0f};
  __m128i_out = __lsx_vavg_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x14eb6a002a406a00, 0x0000000014eb54ab};
  v2u64_op1 = (v2u64){0x00000000ffdfdc0d, 0x0000000000000000};
  __m128i_result = (__m128i){0x0a753500950fa306, 0x000000000a752a55};
  __m128i_out = __lsx_vavg_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffff00010000fff, 0xfffff00010000fff};
  v2u64_op1 = (v2u64){0xfffff00010000fff, 0xfffff00010000fff};
  __m128i_result = (__m128i){0xfffff00010000fff, 0xfffff00010000fff};
  __m128i_out = __lsx_vavg_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000002ffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000017fffffff, 0x0000000000000000};
  __m128i_out = __lsx_vavg_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0101030100010001, 0x0101000100010001};
  __m128i_result = (__m128i){0x0080818000008000, 0x0080800000008000};
  __m128i_out = __lsx_vavg_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000400000004, 0x0000000400000004};
  __m128i_result = (__m128i){0x0000000200000002, 0x0000000200000002};
  __m128i_out = __lsx_vavg_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavg_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavg_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavg_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ed001a00580070, 0x0017004800c400f9};
  v2u64_op1 = (v2u64){0x00000000fffffffe, 0xffffff7ffffffffe};
  __m128i_result = (__m128i){0x0076800d802c0037, 0x800b7fe38062007b};
  __m128i_out = __lsx_vavg_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff76ffd8ffe6ffaa, 0xff80ffa2fff0ff74};
  v2u64_op1 = (v2u64){0xbbc8ecc5f3ced5f3, 0xc0b4d1a5f8babad3};
  __m128i_result = (__m128i){0xdd9ff64ef9daeace, 0xe01ae8a3fc55dd23};
  __m128i_out = __lsx_vavg_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000007fffffff, 0x0000000000000000};
  __m128i_out = __lsx_vavg_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3f80000000000000, 0x3f80000000000000};
  v2u64_op1 = (v2u64){0x0000ff000000ff00, 0x0000000000000000};
  __m128i_result = (__m128i){0x1fc07f8000007f80, 0x1fc0000000000000};
  __m128i_out = __lsx_vavg_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavg_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavg_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000001};
  v2u64_op1 = (v2u64){0x0000e31d4cae8636, 0x0000000043cf26c7};
  __m128i_result = (__m128i){0x0000718ea657431b, 0x0000000021e79364};
  __m128i_out = __lsx_vavg_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfff0000000000000, 0xfff0000000000000};
  __m128i_result = (__m128i){0x7ff8000000000000, 0x7ff8000000000000};
  __m128i_out = __lsx_vavg_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vavg_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00feff8000ff80ff, 0xffffff80ffff7e02};
  v2u64_op1 = (v2u64){0xf931fd04f832fe02, 0x0000ffff0000ffff};
  __m128i_result = (__m128i){0x7d187e427c993f80, 0x80007fc000003f00};
  __m128i_out = __lsx_vavg_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
