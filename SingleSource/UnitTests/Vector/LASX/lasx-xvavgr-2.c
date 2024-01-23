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

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x8080808080808080, 0x8080808080808080,
                             0x8080808080808080, 0x8080808080808080};
  __m256i_out = __lasx_xvavgr_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x8080808080808080, 0x8080808080808080,
                             0x8080808080808080, 0x8080808080808080};
  __m256i_out = __lasx_xvavgr_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000018803100188, 0x0000000000000000,
                      0x0000018803100188, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000014402080144, 0x0000000000000000,
                             0x0000014402080144, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000403e00004040, 0x000086fe0000403e,
                      0x0000403e00004040, 0x000086fe0000403e};
  __m256i_result = (__m256i){0x0000201f00002020, 0x0000437f0000201f,
                             0x0000201f00002020, 0x0000437f0000201f};
  __m256i_out = __lasx_xvavgr_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0ffffffe90008000, 0x0000000000000000,
                      0x90007fff90008000, 0x0fffffff0fffffff};
  __m256i_result = (__m256i){0x87ffffffc880c080, 0x8080808080808080,
                             0xc880bfffc880c080, 0x87ffffff87ffffff};
  __m256i_out = __lasx_xvavgr_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000c40086, 0x00fe01f000010000,
                      0x0000000000c40086, 0x00fe01f000010000};
  v4u64_op1 = (v4u64){0x0000000002a54287, 0x0000000082a54290,
                      0x00000000028aa700, 0x0000000082a54290};
  __m256i_result = (__m256i){0x0000000001b52187, 0x007f00f841532148,
                             0x0000000001a753c3, 0x007f00f841532148};
  __m256i_out = __lasx_xvavgr_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00007bbb0000f777, 0x0000000000004444,
                      0x00007bbb0000f777, 0x0000000000004444};
  __m256i_result = (__m256i){0x00003dde00007bbc, 0x0000000000002222,
                             0x00003dde00007bbc, 0x0000000000002222};
  __m256i_out = __lasx_xvavgr_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7f807f007f7f817f, 0x9ff87ef07f7f817f,
                      0x7f807f007f7f817f, 0x9ff87ef07f7f817f};
  __m256i_result = (__m256i){0x3fc03f803fc040c0, 0x4ffc3f783fc040c0,
                             0x3fc03f803fc040c0, 0x4ffc3f783fc040c0};
  __m256i_out = __lasx_xvavgr_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0504070804040404, 0x0505070804040404,
                      0x0504070804040404, 0x0505070804040404};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0282038402020202, 0x0283038402020202,
                             0x0282038402020202, 0x0283038402020202};
  __m256i_out = __lasx_xvavgr_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000ff000000ff, 0x101010100000000e,
                      0x000000ff000000ff, 0x1010101010001000};
  v4u64_op1 = (v4u64){0x0101010101010101, 0x0101010101010101,
                      0x0101010101010101, 0x0101010101010101};
  __m256i_result = (__m256i){0x0081010000810100, 0x0889088900810088,
                             0x0081010000810100, 0x0889088908810881};
  __m256i_out = __lasx_xvavgr_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7c00000880008000, 0x00000000ffffffff,
                      0x7c00000880008000, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x00000000001d001d, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x3e000004400f400f, 0x0000000080008000,
                             0x3e00000440004000, 0x0000000080008000};
  __m256i_out = __lasx_xvavgr_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0100000001000100, 0x00000000ffffffff,
                      0x0100000001000100, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x7575757575757575,
                      0x0000000000000000, 0x7575757575757575};
  __m256i_result = (__m256i){0x0080000000800080, 0x3abb3abbbabababa,
                             0x0080000000800080, 0x3abb3abbbabababa};
  __m256i_out = __lasx_xvavgr_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x00000000000000ff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000080, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8000000080000000, 0x0000000000000000,
                      0x8000000080000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xc0008000c0008000, 0x0000000000000000,
                             0xc0008000c0008000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000fffffffffffe, 0x0001000100020001,
                      0x0000ffff00010000, 0xfffe000000000000};
  v4u64_op1 = (v4u64){0xe3aebaf4df958004, 0x36722a7e66972cd6,
                      0x00d6c1c830160048, 0x8b1414140e0e0e0e};
  __m256i_result = (__m256i){0x71d7dd7aefcac001, 0x1b399540334c966c,
                             0x006be0e4180b8024, 0xc5890a0a07070707};
  __m256i_out = __lasx_xvavgr_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000808080, 0x0000000000000000};
  __m256i_result = (__m256i){0x8000000080000000, 0x8000000080000000,
                             0x8000000080404040, 0x8000000080000000};
  __m256i_out = __lasx_xvavgr_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0007000700070007, 0x0007000700070007,
                      0x0007000700070007, 0x0007000700070007};
  v4u64_op1 = (v4u64){0x000e000e000e000e, 0x0000000000000000,
                      0x000e000e000e000e, 0x0000000000000000};
  __m256i_result = (__m256i){0x000a800b000a800b, 0x0003800400038004,
                             0x000a800b000a800b, 0x0003800400038004};
  __m256i_out = __lasx_xvavgr_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00f9f9f900000002, 0x0000000000000000,
                      0x00f9f9f900000002, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x007cfcfd80000001, 0x0000000000000000,
                             0x007cfcfd80000001, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffff8001ffff8001, 0xffff000000000000,
                      0xffff8001ffff8001, 0xffff000000000000};
  __m256i_result = (__m256i){0x7fffc0017fffc001, 0x7fff800000000000,
                             0x7fffc0017fffc001, 0x7fff800000000000};
  __m256i_out = __lasx_xvavgr_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0080000000000000,
                      0x0000000000000000, 0x0080000000000000};
  v4u64_op1 = (v4u64){0x000000000000000a, 0x0000000000000000,
                      0x000000000000000a, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000005, 0x0040000000000000,
                             0x0000000000000005, 0x0040000000000000};
  __m256i_out = __lasx_xvavgr_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0658f2dc0eb21e3c, 0x31730b5beb7c99f5,
                      0xc5c085372cfabfba, 0x372e9d75e8aab100};
  v4u64_op1 = (v4u64){0x00000001890b7a39, 0x0000000001020f22,
                      0x0000000109973de7, 0x000000000501e99b};
  __m256i_result = (__m256i){0x032c796ecbdecc3b, 0x18b985adf63f548c,
                             0x62e0429c1b48fed1, 0x1b974ebaf6d64d4e};
  __m256i_out = __lasx_xvavgr_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xc600000000000000,
                      0x0000000000000000, 0xc600000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x6300000000000000,
                             0x0000000000000000, 0x6300000000000000};
  __m256i_out = __lasx_xvavgr_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x3a2a3a2a3aaa45aa, 0x3a553f7f7a2a3a2a,
                      0x3a2a3a2a3aaa45aa, 0x3a2a3a2a3a2a3a2a};
  v4u64_op1 = (v4u64){0x00ff00ff017e01fe, 0x017e00ff017e00ff,
                      0x00ff00ff017e01fe, 0x00ff00ff00ff00ff};
  __m256i_result = (__m256i){0x1d949d949e1423d4, 0x1de9a03f3dd41d95,
                             0x1d949d949e1423d4, 0x1d949d949d949d95};
  __m256i_out = __lasx_xvavgr_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010100005400, 0x00000000ffffffff,
                      0x0000000083f95466, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x011f011f0244420e, 0x001e001ea1bfa1bf,
                      0x001e001e83e5422e, 0x001e001ea1bfa1bf};
  __m256i_result = (__m256i){0x0110011001224b07, 0x000f000fd0dfd0df,
                             0x000f000f83ef4b4a, 0x000f000fd0dfd0df};
  __m256i_out = __lasx_xvavgr_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000003, 0x0000000000000003,
                      0x0000000000000003, 0x0000000000000003};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000030000,
                      0x0000000000000000, 0x0000000000030000};
  __m256i_result = (__m256i){0x0000000000000002, 0x0000000000018002,
                             0x0000000000000002, 0x0000000000018002};
  __m256i_out = __lasx_xvavgr_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x43ec0a1b2aba7ed0, 0x223d76f09f37e357,
                      0x3870ca8d013e76a0, 0x223d76f09f3881ff};
  __m256i_result = (__m256i){0x21f6050d955d3f68, 0x111ebb784f9bf1ac,
                             0x1c386546809f3b50, 0x111ebb784f9c4100};
  __m256i_out = __lasx_xvavgr_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xbffebffec0fe0000, 0x0000840100000000,
                      0xbffebffec0fe0000, 0x0000840100000000};
  __m256i_result = (__m256i){0x5fff5fff607f0000, 0x0000420080000000,
                             0x5fff5fff607f0000, 0x0000420080000000};
  __m256i_out = __lasx_xvavgr_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000000,
                             0x0000000000000001, 0x0000000000000000};
  __m256i_out = __lasx_xvavgr_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff457d607f, 0x00000000457d607d,
                      0xffffffff457d607f, 0x00000000457d607d};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7fffffffa2beb040, 0x0000000022beb03f,
                             0x7fffffffa2beb040, 0x0000000022beb03f};
  __m256i_out = __lasx_xvavgr_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
