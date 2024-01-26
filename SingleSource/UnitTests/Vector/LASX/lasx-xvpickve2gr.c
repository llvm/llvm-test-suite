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

  int int_op0, int_op1, int_result, int_out, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  unsigned_int_result = 0x0000000000000000;
  unsigned_int_out = __lasx_xvpickve2gr_wu((__m256)v4u64_op0, 0x2);
  check_lasx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0002000200020006, 0xfffffffffffffffe,
                      0x0002000400000000, 0xfffffffffffffffe};
  unsigned_int_result = 0x0000000000020006;
  unsigned_int_out = __lasx_xvpickve2gr_wu((__m256)v4u64_op0, 0x0);
  check_lasx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  unsigned_int_result = 0x0000000000000000;
  unsigned_int_out = __lasx_xvpickve2gr_wu((__m256)v4u64_op0, 0x5);
  check_lasx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffff0100000001, 0x0000000000000000,
                      0xffffff0100000001, 0x0000000000000000};
  unsigned_int_result = 0x0000000000000000;
  unsigned_int_out = __lasx_xvpickve2gr_wu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0010001000100010, 0x0000000000100010,
                      0x0010001000100010, 0x0000000000100010};
  unsigned_int_result = 0x0000000000100010;
  unsigned_int_out = __lasx_xvpickve2gr_wu((__m256)v4u64_op0, 0x2);
  check_lasx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  unsigned_int_result = 0x0000000000000000;
  unsigned_int_out = __lasx_xvpickve2gr_wu((__m256)v4u64_op0, 0x3);
  check_lasx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000100040, 0x0000000000000040,
                      0x0000000000100040, 0x0000000000000040};
  unsigned_int_result = 0x0000000000000040;
  unsigned_int_out = __lasx_xvpickve2gr_wu((__m256)v4u64_op0, 0x6);
  check_lasx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  unsigned_int_result = 0x00000000ffffffff;
  unsigned_int_out = __lasx_xvpickve2gr_wu((__m256)v4u64_op0, 0x5);
  check_lasx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  unsigned_int_result = 0x00000000ffffffff;
  unsigned_int_out = __lasx_xvpickve2gr_wu((__m256)v4u64_op0, 0x4);
  check_lasx_out(&unsigned_int_result, &unsigned_int_out, sizeof(unsigned_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff00000000, 0x0000000000000000,
                      0x0000ffff00000000, 0x0000000000000000};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lasx_xvpickve2gr_du((__m256)v4u64_op0, 0x3);
  check_lasx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lasx_xvpickve2gr_du((__m256)v4u64_op0, 0x3);
  check_lasx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  unsigned_long_int_result = 0xffffffffffffffff;
  unsigned_long_int_out = __lasx_xvpickve2gr_du((__m256)v4u64_op0, 0x2);
  check_lasx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lasx_xvpickve2gr_du((__m256)v4u64_op0, 0x3);
  check_lasx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  unsigned_long_int_result = 0x00000000ffffffff;
  unsigned_long_int_out = __lasx_xvpickve2gr_du((__m256)v4u64_op0, 0x0);
  check_lasx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lasx_xvpickve2gr_du((__m256)v4u64_op0, 0x2);
  check_lasx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  unsigned_long_int_result = 0xffffffffffffffff;
  unsigned_long_int_out = __lasx_xvpickve2gr_du((__m256)v4u64_op0, 0x1);
  check_lasx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lasx_xvpickve2gr_du((__m256)v4u64_op0, 0x1);
  check_lasx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lasx_xvpickve2gr_du((__m256)v4u64_op0, 0x2);
  check_lasx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lasx_xvpickve2gr_du((__m256)v4u64_op0, 0x3);
  check_lasx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lasx_xvpickve2gr_du((__m256)v4u64_op0, 0x1);
  check_lasx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  unsigned_long_int_result = 0x0000000000000000;
  unsigned_long_int_out = __lasx_xvpickve2gr_du((__m256)v4u64_op0, 0x3);
  check_lasx_out(&unsigned_long_int_result, &unsigned_long_int_out, sizeof(unsigned_long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xcc9b89f2f6cef440, 0xffffffffffffffff,
                      0x0cc08723ff900001, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x7);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x0000ffff0000ffff,
                      0x000000000000ff80, 0x000000000000ffff};
  int_result = 0x000000000000ffff;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x6);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000007f, 0x00000000ff90ff81,
                      0x000000000000007f, 0x00000000ff90ff81};
  int_result = 0x000000000000007f;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x4);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  int_result = 0xffffffff;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x1);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xfffffefdfffffefd, 0xffffffffffffffff};
  int_result = 0xfffffefd;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x4);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x5555555580000000, 0x555555553f800000,
                      0x5555555580000000, 0x555555553f800000};
  int_result = 0x0000000055555555;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x5);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x0);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x5);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  int_result = 0x000000007ff00000;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x1);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000ff, 0x0000000000000000,
                      0x00000000000000ff, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x6);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffff0008, 0x0000000000000000,
                      0x00000000ffff0008, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x6);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x1);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x6);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x0);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  int_result = 0xffffffff;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x2);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffd880, 0x0000000000000000,
                      0xffffffffffffd880, 0x0000000000000000};
  int_result = 0x0000000000000000;
  int_out = __lasx_xvpickve2gr_w((__m256)v4u64_op0, 0x2);
  check_lasx_out(&int_result, &int_out, sizeof(int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  long_int_result = 0x0000000000000000;
  long_int_out = __lasx_xvpickve2gr_d((__m256)v4u64_op0, 0x2);
  check_lasx_out(&long_int_result, &long_int_out, sizeof(long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  long_int_result = 0x0000000000000000;
  long_int_out = __lasx_xvpickve2gr_d((__m256)v4u64_op0, 0x2);
  check_lasx_out(&long_int_result, &long_int_out, sizeof(long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff8000000000000, 0x1f0fdf7f3e3b31d4,
                      0x7ff8000000000000, 0x1f0fdf7f3e3b31d4};
  long_int_result = 0x1f0fdf7f3e3b31d4;
  long_int_out = __lasx_xvpickve2gr_d((__m256)v4u64_op0, 0x1);
  check_lasx_out(&long_int_result, &long_int_out, sizeof(long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x012c002c001c000a, 0x00fe01fc01fe0000,
                      0x012c002c001c0006, 0x00fe01fc01fe01fc};
  long_int_result = 0x00fe01fc01fe0000;
  long_int_out = __lasx_xvpickve2gr_d((__m256)v4u64_op0, 0x1);
  check_lasx_out(&long_int_result, &long_int_out, sizeof(long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x00000000ffff0100,
                      0x00000000ffffffff, 0x00000000ffffffff};
  long_int_result = 0x00000000ffff0100;
  long_int_out = __lasx_xvpickve2gr_d((__m256)v4u64_op0, 0x1);
  check_lasx_out(&long_int_result, &long_int_out, sizeof(long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  long_int_result = 0x0000000000000000;
  long_int_out = __lasx_xvpickve2gr_d((__m256)v4u64_op0, 0x0);
  check_lasx_out(&long_int_result, &long_int_out, sizeof(long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  long_int_result = 0x0000000000000000;
  long_int_out = __lasx_xvpickve2gr_d((__m256)v4u64_op0, 0x2);
  check_lasx_out(&long_int_result, &long_int_out, sizeof(long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x0000ffff00000000,
                      0x000000000000ffff, 0x0000ffff00000000};
  long_int_result = 0x000000000000ffff;
  long_int_out = __lasx_xvpickve2gr_d((__m256)v4u64_op0, 0x0);
  check_lasx_out(&long_int_result, &long_int_out, sizeof(long_int_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  long_int_result = 0xffffffffffffffff;
  long_int_out = __lasx_xvpickve2gr_d((__m256)v4u64_op0, 0x0);
  check_lasx_out(&long_int_result, &long_int_out, sizeof(long_int_out), __FILE__, __LINE__);

  return 0;
}
