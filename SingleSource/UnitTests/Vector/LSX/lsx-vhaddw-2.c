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

  v2u64_op0 = (v2u64){0x00000000fff80000, 0x00000000fff8fff8};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000ff0000, 0x0000000000ff00ff};
  __m128i_out = __lsx_vhaddw_hu_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xff80000000000000, 0xff80000000000000};
  __m128i_result = (__m128i){0x0080000000000000, 0x0080000000000000};
  __m128i_out = __lsx_vhaddw_hu_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_hu_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x5252525252525252, 0x5252525252525252};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0052005200520052, 0x0052005200520052};
  __m128i_out = __lsx_vhaddw_hu_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_hu_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000fffd, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffff00000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x00ff00ff000000ff, 0x00ff00ff00ff00ff};
  __m128i_out = __lsx_vhaddw_hu_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000049ffffffaa, 0x00060012000e002b};
  v2u64_op1 = (v2u64){0x000000127fffffea, 0x000000060000000e};
  __m128i_result = (__m128i){0x0000001201fe01e9, 0x000000060000000e};
  __m128i_out = __lsx_vhaddw_hu_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x5d7f5d807fea807f};
  __m128i_result = (__m128i){0x00ff00ff00ff00ff, 0x007f008000ea007f};
  __m128i_out = __lsx_vhaddw_hu_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_hu_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_wu_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x4f804f804f804f80, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x4f804f804f804f80, 0x0000000000000000};
  __m128i_result = (__m128i){0x00009f0000009f00, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_wu_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000bd3d00000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000bd3d00000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000bd3d00000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_wu_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_wu_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000001f, 0x000000000000001f};
  v2u64_op1 = (v2u64){0xffff007f00000000, 0xffff007f00000000};
  __m128i_result = (__m128i){0x0000007f00000000, 0x0000007f00000000};
  __m128i_out = __lsx_vhaddw_wu_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x28bf0351ec69b5f2, 0x7ef400ad21fc7081};
  __m128i_result = (__m128i){0x000003510000b5f2, 0x000000ad00007081};
  __m128i_out = __lsx_vhaddw_wu_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xadad52525252adad, 0x5252adadadadadad};
  __m128i_result = (__m128i){0x000052520000adad, 0x0000adad0000adad};
  __m128i_out = __lsx_vhaddw_wu_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ff8000010f78, 0x0000ffff0000ffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x002a001a001a000b};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000001a0000000b};
  __m128i_out = __lsx_vhaddw_wu_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00feff8000ff80ff, 0x7500000075007500};
  v2u64_op1 = (v2u64){0x00007d1800007c99, 0xffff800000000000};
  __m128i_result = (__m128i){0x00007e1600007d98, 0x0000f50000007500};
  __m128i_out = __lsx_vhaddw_wu_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xc1fc7941bc7e00ff, 0xffff760386bdae46};
  v2u64_op1 = (v2u64){0x0802080408060803, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000ca000000c481, 0x0000ffff000086bd};
  __m128i_out = __lsx_vhaddw_wu_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000007fff9, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x5efeb3165bd7653d, 0xffff2356fe165486};
  __m128i_result = (__m128i){0x0000b31600006544, 0x0000235600005486};
  __m128i_out = __lsx_vhaddw_wu_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xdd3b8b02563b2d7b, 0x9c83e21a22001818};
  v2u64_op1 = (v2u64){0x4f4f4f4f4f4f4f4f, 0x4f4f4f4f4f4f4f4f};
  __m128i_result = (__m128i){0x00012c8a0000a58a, 0x0000ebd20000714f};
  __m128i_out = __lsx_vhaddw_wu_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000003, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0024d8f6a494006a, 0xa8beed87bc3f2be1};
  v2u64_op1 = (v2u64){0xfeffffffffffffff, 0xfeffffffffffffff};
  __m128i_result = (__m128i){0x000000010024d8f5, 0x00000001a8beed86};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000001, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000078c00000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x6a57a30ff0000000, 0x0000000000000001};
  __m128i_result = (__m128i){0x00000000f0000000, 0x0000000000000001};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000040d, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000001};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x00000001fffffffe, 0x00000001fffffffe};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x8000000083ff0be0, 0x80000000b57ec564};
  __m128i_result = (__m128i){0x0000000183ff0bdf, 0x00000001b57ec563};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffff00000000};
  __m128i_result = (__m128i){0x00000000ffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000000000000, 0x8000e2e3ffffd1d3};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000080000000, 0x000000008000e2e3};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000200000002, 0x0000000200010002};
  v2u64_op1 = (v2u64){0x0000000200000002, 0x0000000200010002};
  __m128i_result = (__m128i){0x0000000000000004, 0x0000000000010004};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffffffff, 0x00000000ffffffff};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x00000001fffffffe};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000001000000000, 0x0000001000000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000001};
  __m128i_out = __lsx_vhaddw_du_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff00000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x870968c1f56bb3cd, 0x4ee85545ffffffff};
  __m128i_result = (__m128i){0x870968c1f56bb3cd, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_qu_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000013d, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0006000200000000, 0x0010001000030000};
  __m128i_result = (__m128i){0x0006000200000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_qu_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffff01ff01, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xfffffffffffffffe, 0x0000000000000001};
  __m128i_out = __lsx_vhaddw_qu_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_qu_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000001b, 0x000000000000001b};
  v2u64_op1 = (v2u64){0x00000000001b0000, 0x00000000001b0000};
  __m128i_result = (__m128i){0x00000000001b001b, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_qu_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000004870ba0, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000004870ba0, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_qu_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000010000000, 0x0000000010000000};
  v2u64_op1 = (v2u64){0xff800000ff800000, 0xff800000ff800000};
  __m128i_result = (__m128i){0xff8000010f800000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_qu_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00007fff7fff8000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_qu_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0x00000000000003e2};
  __m128i_result = (__m128i){0xffffffffffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_qu_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vhaddw_qu_du((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
