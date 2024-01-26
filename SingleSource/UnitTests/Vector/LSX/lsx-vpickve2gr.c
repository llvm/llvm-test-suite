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

  int int_op0, int_op1, int_result, int_out, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v2u64_op0 = (v2u64){0x000000007d3ac600, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lsx_vpickve2gr_b((__m128)v2u64_op0, 0x7);
  check_lsx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00a6ffceffb60052, 0xff84fff4ff84fff4};
  unsigned_int_result = 0x0000000000000084;
  unsigned_int_out = __lsx_vpickve2gr_bu((__m128)v2u64_op0, 0xa);
  check_lsx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0101010101010101, 0x7fffffff7fffffff};
  int_result = 0xffffffff;
  int_out = __lsx_vpickve2gr_b((__m128)v2u64_op0, 0xc);
  check_lsx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  unsigned_int_result = 0x00000000000000ff;
  unsigned_int_out = __lsx_vpickve2gr_bu((__m128)v2u64_op0, 0x9);
  check_lsx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00009c7c00007176, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lsx_vpickve2gr_b((__m128)v2u64_op0, 0xe);
  check_lsx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000fd1654860000, 0x0000feff23560000};
  unsigned_int_result = 0x00000000000000ff;
  unsigned_int_out = __lsx_vpickve2gr_bu((__m128)v2u64_op0, 0xc);
  check_lsx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0400040004000400, 0x0400040004000400};
  unsigned_int_result = 0x0000000000000400;
  unsigned_int_out = __lsx_vpickve2gr_hu((__m128)v2u64_op0, 0x5);
  check_lsx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  int_result = 0xffffffff;
  int_out = __lsx_vpickve2gr_h((__m128)v2u64_op0, 0x2);
  check_lsx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lsx_vpickve2gr_h((__m128)v2u64_op0, 0x1);
  check_lsx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  unsigned_int_result = 0x0000000000000000;
  unsigned_int_out = __lsx_vpickve2gr_wu((__m128)v2u64_op0, 0x3);
  check_lsx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lsx_vpickve2gr_w((__m128)v2u64_op0, 0x2);
  check_lsx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  unsigned_int_result = 0x00000000ffffffff;
  unsigned_int_out = __lsx_vpickve2gr_wu((__m128)v2u64_op0, 0x2);
  check_lsx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  unsigned_int_result = 0x0000000000000000;
  unsigned_int_out = __lsx_vpickve2gr_wu((__m128)v2u64_op0, 0x3);
  check_lsx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  int_result = 0xffffffff;
  int_out = __lsx_vpickve2gr_w((__m128)v2u64_op0, 0x1);
  check_lsx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0002000200000000, 0x0000000000000000};
  unsigned_int_result = 0x0000000000000000;
  unsigned_int_out = __lsx_vpickve2gr_wu((__m128)v2u64_op0, 0x2);
  check_lsx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000200000002, 0x0000000200000002};
  int_result = 0x0000000000000002;
  int_out = __lsx_vpickve2gr_w((__m128)v2u64_op0, 0x0);
  check_lsx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000fdec000000000, 0x6453f5e01d6e5000};
  int_result = 0x000000001d6e5000;
  int_out = __lsx_vpickve2gr_w((__m128)v2u64_op0, 0x2);
  check_lsx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x39c51f389c0d6112, 0x8d78336c83652b86};
  int_result = 0x9c0d6112;
  int_out = __lsx_vpickve2gr_w((__m128)v2u64_op0, 0x0);
  check_lsx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfdce8003090b0906, 0x0674c8868a74fc80};
  int_result = 0x00000000090b0906;
  int_out = __lsx_vpickve2gr_w((__m128)v2u64_op0, 0x0);
  check_lsx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lsx_vpickve2gr_du((__m128)v2u64_op0, 0x1);
  check_lsx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  long_int_result = 0x0000000000000000;
  long_int_out = __lsx_vpickve2gr_d((__m128)v2u64_op0, 0x1);
  check_lsx_out(&long_int_result, &long_int_out, sizeof(long_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3f8000003f800000, 0x3f8000003f800000};
  unsigned_long_int_result = 0x3f8000003f800000;
  unsigned_long_int_out = __lsx_vpickve2gr_du((__m128)v2u64_op0, 0x0);
  check_lsx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  long_int_result = 0x0000000000000000;
  long_int_out = __lsx_vpickve2gr_d((__m128)v2u64_op0, 0x1);
  check_lsx_out(&long_int_result, &long_int_out, sizeof(long_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lsx_vpickve2gr_du((__m128)v2u64_op0, 0x0);
  check_lsx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000001};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lsx_vpickve2gr_du((__m128)v2u64_op0, 0x0);
  check_lsx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000003ddc5dac, 0x0000000000000000};
  long_int_result = 0x000000003ddc5dac;
  long_int_out = __lsx_vpickve2gr_d((__m128)v2u64_op0, 0x0);
  check_lsx_out(&long_int_result, &long_int_out, sizeof(long_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lsx_vpickve2gr_du((__m128)v2u64_op0, 0x0);
  check_lsx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000e0000000e, 0x000000120000000d};
  unsigned_long_int_result = 0x0000000e0000000e;
  unsigned_long_int_out = __lsx_vpickve2gr_du((__m128)v2u64_op0, 0x0);
  check_lsx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  return 0;
}
