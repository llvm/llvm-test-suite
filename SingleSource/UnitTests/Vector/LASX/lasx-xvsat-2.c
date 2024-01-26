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

  v4u64_op0 = (v4u64){0xffffffff00000000, 0x00000000ffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x3f3f3f3f00000000, 0x000000003f3f3f3f,
                             0x3f3f3f3f3f3f3f3f, 0x3f3f3f3f3f3f3f3f};
  __m256i_out = __lasx_xvsat_bu((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_bu((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x000000000000ffff, 0x0000000000000000,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvsat_bu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfe00000000000000, 0x0000000001ffffff,
                      0xfe00000000000000, 0x0000000001ffffff};
  __m256i_result = (__m256i){0x7f00000000000000, 0x00000000017f7f7f,
                             0x7f00000000000000, 0x00000000017f7f7f};
  __m256i_out = __lasx_xvsat_bu((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0007ffff0007ffff, 0x0000000700000007,
                      0x0007ffff0007ffff, 0x0000000700000007};
  __m256i_result = (__m256i){0x00071f1f00071f1f, 0x0000000700000007,
                             0x00071f1f00071f1f, 0x0000000700000007};
  __m256i_out = __lasx_xvsat_bu((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000d6d6d, 0x0000000000000000,
                      0x00000000000d6d6d, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000d6d6d, 0x0000000000000000,
                             0x00000000000d6d6d, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_bu((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0xffffffffffffffff,
                      0x00000000ffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x000000003fff3fff, 0x3fff3fff3fff3fff,
                             0x000000003fff3fff, 0x3fff3fff3fff3fff};
  __m256i_out = __lasx_xvsat_hu((__m256)v4u64_op0, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x2020202020206431, 0x2020202020202020,
                      0x2020202020206431, 0x2020202020202020};
  __m256i_result = (__m256i){0x001f001f001f001f, 0x001f001f001f001f,
                             0x001f001f001f001f, 0x001f001f001f001f};
  __m256i_out = __lasx_xvsat_hu((__m256)v4u64_op0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x00001fff00001fff, 0x00001fff00001fff,
                             0x00001fff00001fff, 0x00001fff00001fff};
  __m256i_out = __lasx_xvsat_hu((__m256)v4u64_op0, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_hu((__m256)v4u64_op0, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000007fff7fff, 0x0000000000000000,
                      0x000000007fff7fff, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000003f003f, 0x0000000000000000,
                             0x00000000003f003f, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_hu((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc0090000c0200060, 0x0000000000000000,
                      0xc0090000c0200060, 0x0000000000000000};
  __m256i_result = (__m256i){0x007f0000007f0060, 0x0000000000000000,
                             0x007f0000007f0060, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_hu((__m256)v4u64_op0, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x408480007fff0000, 0x3eab77367fff4848,
                      0x408480007fff0000, 0x3eab77367fff4848};
  __m256i_result = (__m256i){0x0003000300030000, 0x0003000300030003,
                             0x0003000300030000, 0x0003000300030003};
  __m256i_out = __lasx_xvsat_hu((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000029170, 0x0000000001fff000,
                      0x0000000000029170, 0x0000000001fff000};
  __m256i_result = (__m256i){0x00000000000203ff, 0x0000000001ff03ff,
                             0x00000000000203ff, 0x0000000001ff03ff};
  __m256i_out = __lasx_xvsat_hu((__m256)v4u64_op0, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_hu((__m256)v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_hu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_wu((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_wu((__m256)v4u64_op0, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_wu((__m256)v4u64_op0, 0x1b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_wu((__m256)v4u64_op0, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_wu((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_wu((__m256)v4u64_op0, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x457db03e45a87310, 0x457db03e457db03e,
                      0x457db03e45a87310, 0x457db03e457db03e};
  __m256i_result = (__m256i){0x0000000f0000000f, 0x0000000f0000000f,
                             0x0000000f0000000f, 0x0000000f0000000f};
  __m256i_out = __lasx_xvsat_wu((__m256)v4u64_op0, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000077fff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x000000000003ffff, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_wu((__m256)v4u64_op0, 0x11);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003fe000000000, 0x0000000000000000,
                      0x00003fe000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00003fe000000000, 0x0000000000000000,
                             0x00003fe000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_wu((__m256)v4u64_op0, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000fffcfffc, 0x00000000fffcfffc,
                      0x00000000fffcfffc, 0x00000000fffcfffc};
  __m256i_result = (__m256i){0x0000000000003fff, 0x0000000000003fff,
                             0x0000000000003fff, 0x0000000000003fff};
  __m256i_out = __lasx_xvsat_wu((__m256)v4u64_op0, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7efefefe80ffffff, 0x0000000000000000,
                      0x7efefefe80ffffff, 0xffffffffffff8000};
  __m256i_result = (__m256i){0x0fffffff0fffffff, 0x0000000000000000,
                             0x0fffffff0fffffff, 0x0fffffff0fffffff};
  __m256i_out = __lasx_xvsat_wu((__m256)v4u64_op0, 0x1b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffe000ffffffff08, 0xffe000ffffffffff,
                      0xffe000ffffffff08, 0xffe000ffffffffff};
  __m256i_result = (__m256i){0x0fffffff0fffffff, 0x0fffffff0fffffff,
                             0x0fffffff0fffffff, 0x0fffffff0fffffff};
  __m256i_out = __lasx_xvsat_wu((__m256)v4u64_op0, 0x1b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x000003ffffffffff, 0x000003ffffffffff,
                             0x000003ffffffffff, 0x000003ffffffffff};
  __m256i_out = __lasx_xvsat_du((__m256)v4u64_op0, 0x29);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_du((__m256)v4u64_op0, 0x34);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000007, 0x00ff00ff00000007,
                      0x00000000000000e7, 0x00ff00ff00000007};
  __m256i_result = (__m256i){0x0000000000000007, 0x0001ffffffffffff,
                             0x00000000000000e7, 0x0001ffffffffffff};
  __m256i_out = __lasx_xvsat_du((__m256)v4u64_op0, 0x30);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x419cd5b11c3c5654, 0x6580668200fe0002,
                      0x2475cef801f0ffdd, 0x247fe49409620040};
  __m256i_result = (__m256i){0x419cd5b11c3c5654, 0x6580668200fe0002,
                             0x2475cef801f0ffdd, 0x247fe49409620040};
  __m256i_out = __lasx_xvsat_du((__m256)v4u64_op0, 0x3f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_du((__m256)v4u64_op0, 0x22);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffff800000000000, 0xffff800000000000,
                      0xffff800080000000, 0xffff800000000000};
  __m256i_result = (__m256i){0x00000000000001ff, 0x00000000000001ff,
                             0x00000000000001ff, 0x00000000000001ff};
  __m256i_out = __lasx_xvsat_du((__m256)v4u64_op0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1fa0000000080000, 0x0000000000000000,
                      0x1fa0000000080000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000007fffff, 0x0000000000000000,
                             0x00000000007fffff, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_du((__m256)v4u64_op0, 0x16);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00007f7f03030000, 0x0000000000000000,
                      0x0000017f00000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00007f7f03030000, 0x0000000000000000,
                             0x0000017f00000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_du((__m256)v4u64_op0, 0x37);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvsat_du((__m256)v4u64_op0, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
