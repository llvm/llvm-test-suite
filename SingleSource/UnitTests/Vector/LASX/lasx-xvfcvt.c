#include "lasx_test_util.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_out, __m256i_result;
  __m256 __m256_out, __m256_result;
  __m256d __m256d_out, __m256d_result;
  v4u64 v4u64_op0, v4u64_op1, v4u64_op2, v4u64_result;
  v8i32 v8i32_op0, v8i32_op1, v8i32_op2, v8i32_result;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000010, 0x00000008, 0x00000000, 0x00000005,
                      0x00000000, 0x00000011, 0x0000000c, 0x00000003};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x6d6d6d6d, 0x6d6d6d6d, 0x6d6d6d6d, 0x6d6d6d6d,
                      0x6d6d6d6d, 0x6d6d6d6d, 0x6d6d6d6d, 0x6d6d6d6d};
  v8i32_op1 = (v8i32){0x6d6d6d6d, 0x6d6d6d6d, 0x6d6d6d6d, 0x6d6d6d6d,
                      0x6d6d6d6d, 0x6d6d6d6d, 0x6d6d6d6d, 0x6d6d6d6d};
  __m256i_result = (__m256i){0x7c007c007c007c00, 0x7c007c007c007c00,
                             0x7c007c007c007c00, 0x7c007c007c007c00};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00010000, 0x00020000, 0x00020000, 0x00020000,
                      0x00010000, 0x00020000, 0x00020000, 0x00020000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000,
                      0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x8f00ffff, 0x8e8e8e8e, 0x71010101, 0x71717171,
                      0x8f00ffff, 0x8e8e8e8e, 0x71010101, 0x71717171};
  __m256i_result = (__m256i){0x7c007c0080008000, 0x00000000ffffffff,
                             0x7c007c0080008000, 0x00000000ffffffff};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xfff10000, 0xfff10000, 0x00000000, 0x00000000,
                      0xfff10000, 0xfff10000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0xfff10000, 0xfff10000, 0x00000000, 0x00000000,
                      0xfff10000, 0xfff10000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x00000000ff88ff88, 0x00000000ff88ff88,
                             0x00000000ff88ff88, 0x00000000ff88ff88};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00040000, 0x00000000, 0x00000000, 0x00000000,
                      0x00040000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00010100, 0xff0101fd, 0x3f003f00, 0xff00ff00,
                      0x00010100, 0xff0101fd, 0x3f003f00, 0xff00ff00};
  v8i32_op1 = (v8i32){0xff000100, 0xfe0000bc, 0x00fffeff, 0x01ffff43,
                      0xff000100, 0xfe0000bc, 0x00fffeff, 0x01ffff43};
  __m256i_result = (__m256i){0x00000000fc00fc00, 0xfc003802fc000000,
                             0x00000000fc00fc00, 0xfc003802fc000000};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvfcvt_h_s((__m256)v8i32_op0, (__m256)v8i32_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xcc9b89f2f6cef440, 0xffffffffffffffff,
                      0x0cc08723ff900001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffff00000000, 0xffffffffffffffff,
                      0xffffffff00000000, 0xffffffffffffffff};
  v8i32_result = (v8i32){0xfffffff8, 0xffffffff, 0xff800000, 0xffffffff,
                         0xfffffff8, 0xffffffff, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvt_s_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvt_s_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000,
                         0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvt_s_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xdbc8000000003fff,
                      0x0000000000000000, 0xdbc8000000003fff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0xff800000,
                         0x00000000, 0x00000000, 0x00000000, 0xff800000};
  __m256_out = __lasx_xvfcvt_s_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xff800000ff800000, 0xff800000ff800000,
                      0xff800000ff800000, 0xff800000ff800000};
  v8i32_result = (v8i32){0xff800000, 0xff800000, 0x00000000, 0x00000000,
                         0xff800000, 0xff800000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvt_s_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000ffff0000ffff,
                      0x0000000000000000, 0x0000ffff0000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvt_s_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00003f784000ff80, 0xf7f8f7f84000fff9,
                      0x00003f784000ff80, 0xf7f8f7f8f800f800};
  v8i32_result = (v8i32){0x00000000, 0xff800000, 0x00000000, 0x00000000,
                         0x00000000, 0xff800000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvt_s_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000555500005555, 0x0000555500005555,
                      0x0000555500005555, 0x0000555500005555};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvt_s_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffb7bc02a0, 0xffffffffb680489b,
                      0xffffffffb7bbdec0, 0xffffffffb6804cb9};
  v8i32_result = (v8i32){0xfffffffd, 0xfffffffd, 0x00000000, 0x00000000,
                         0xfffffffd, 0xfffffffd, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvt_s_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0101010201010102, 0x0101010202020203,
                      0x0101010201010102, 0x0101010202020203};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvt_s_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x3fff3fff3fff3fc4, 0x3fff3fff3fff3fff,
                      0x3fff3fff3fff3fc4, 0x3fff3fff3fff3fff};
  v8i32_result = (v8i32){0x3ff9fffa, 0x3ff9fffa, 0x00000000, 0x00000000,
                         0x3ff9fffa, 0x3ff9fffa, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfcvt_s_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  return 0;
}
