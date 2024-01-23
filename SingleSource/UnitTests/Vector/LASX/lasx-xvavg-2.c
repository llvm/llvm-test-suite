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

  v4u64_op0 = (v4u64){0xe75278c187b20039, 0x61d849f0c0794ced,
                      0x1d1d1d1d1d1d1d1d, 0x1d1d1d1d1d1d1d1d};
  v4u64_op1 = (v4u64){0xfbe0b80c960c96d0, 0x0c0c0c0c0cb60cc0,
                      0x0ca40c0c0c0c0cc0, 0xf90c0c0c00000000};
  __m256i_result = (__m256i){0xf19998668e5f4b84, 0x36722a7e66972cd6,
                             0x146014141414146e, 0x8b1414140e0e0e0e};
  __m256i_out = __lasx_xvavg_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000ff00fff0, 0x000000000000ffff,
                      0x0000000000ffffff, 0x000000000000ffff};
  __m256i_result = (__m256i){0x000000007f007f78, 0x0000000000007f7f,
                             0x00000000007f7f7f, 0x0000000000007f7f};
  __m256i_out = __lasx_xvavg_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff00fefffeff02ff, 0x0000ffffffff0100,
                      0x00000000ffff02ff, 0x0000ffffffffffff};
  v4u64_op1 = (v4u64){0x00030081bd80f90e, 0x0000000000000000,
                      0x00030006fa05f20e, 0x0000000000000000};
  __m256i_result = (__m256i){0x7f017fc0ddbf7d86, 0x00007f7f7f7f0000,
                             0x00010003fc827a86, 0x00007f7f7f7f7f7f};
  __m256i_out = __lasx_xvavg_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0202010202020102, 0x0202010202020102,
                      0x0202010202020102, 0x0202010202020102};
  __m256i_result = (__m256i){0x0101000101010001, 0x0101000101010001,
                             0x0101000101010001, 0x0101000101010001};
  __m256i_out = __lasx_xvavg_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvavg_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0x00ffffffffffffff,
                      0xffffffff00000000, 0x00ffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7f7f7f7f00000000, 0x007f7f7f7f7f7f7f,
                             0x7f7f7f7f00000000, 0x007f7f7f7f7f7f7f};
  __m256i_out = __lasx_xvavg_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000007f00000000, 0x0000007f00000022,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000003f00000000, 0x0000003f00000011,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff7fff7fff7fff, 0x0000000000000000,
                      0x7fff7fff7fff7fff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x3fff3fff3fff3fff, 0x0000000000000000,
                             0x3fff3fff3fff3fff, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7fff7fff7fff7fff, 0x0000000000000000,
                             0x7fff7fff7fff7fff, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffbfffaffff0000, 0xffffffffffff0000,
                      0xfffbfffafffffffe, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x012c002c001c000a, 0x00fe01fc01fe0000,
                      0x012c002c001c0006, 0x00fe01fc01fe01fc};
  __m256i_result = (__m256i){0x80938013800d0005, 0x807e80fd80fe0000,
                             0x80938013800d8002, 0x807e80fd80fe80fd};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0002000200020002, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x8000800080008000, 0x7fff7fff7fff7fff,
                             0x7fff7fff7fff7fff, 0x7fff7fff7fff7fff};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x00000000ffffffff,
                      0x00000000ffffffff, 0x00000000ffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000007fff7fff, 0x000000007fff7fff,
                             0x000000007fff7fff, 0x000000007fff7fff};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ff810011, 0x0000000000000000,
                      0x00000000ff810011, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7fffffffffffffff, 0x7fffffffffffffff,
                      0x7fffffffffffffff, 0x7fffffffffffffff};
  __m256i_result = (__m256i){0x3fff7fffffc08008, 0x3fff7fff7fff7fff,
                             0x3fff7fffffc08008, 0x3fff7fff7fff7fff};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x80000000ff800000, 0x8000000080000000,
                      0x80000000ff800000, 0x8000000080000000};
  v4u64_op1 = (v4u64){0x80000000ff7f0001, 0x800000007fff0001,
                      0x80000000ff7f0001, 0x800000007fff0001};
  __m256i_result = (__m256i){0x80000000ff7f0000, 0x800000007fff0000,
                             0x80000000ff7f0000, 0x800000007fff0000};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffff0000, 0xffc6ffc6003a003a,
                      0xffffffffffff0000, 0xffc6ffc6003a003a};
  __m256i_result = (__m256i){0x7fff7fff7fff0000, 0x7fe37fe3001d001d,
                             0x7fff7fff7fff0000, 0x7fe37fe3001d001d};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000009, 0x0000000000000009,
                      0x0000000000000009, 0x0000000000000009};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000004, 0x0000000000000004,
                             0x0000000000000004, 0x0000000000000004};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfc00000000000000, 0x00000000fc38fc38,
                      0xfc00000000000000, 0x00000000fc38fc38};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7e00000000000000, 0x000000007e1c7e1c,
                             0x7e00000000000000, 0x000000007e1c7e1c};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000fffe00800022,
                      0x00000000ffffffff, 0x0000fffe00800022};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x000000000003ffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000007fff7fff, 0x00007fff00400011,
                             0x000000008001ffff, 0x00007fff00400011};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0a09080706050403,
                      0x0000000000000000, 0x0a09080706050403};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0504840303028201,
                             0x0000000000000000, 0x0504840303028201};
  __m256i_out = __lasx_xvavg_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000200, 0x0000000000000200,
                      0x0000000000000200, 0x0000000000000200};
  v4u64_op1 = (v4u64){0x0000000000000200, 0x0000000000000200,
                      0x0000000000000200, 0x0000000000000200};
  __m256i_result = (__m256i){0x0000000000000200, 0x0000000000000200,
                             0x0000000000000200, 0x0000000000000200};
  __m256i_out = __lasx_xvavg_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000005000000020, 0x0000000000000000,
                      0x0000005000000020, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000002800000010, 0x0000000000000000,
                             0x0000002800000010, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x40efffe000000000,
                      0x0000000000000000, 0x40efffe000000000};
  v4u64_op1 = (v4u64){0xff00fe00feff02ff, 0xff00fe00feff02ff,
                      0xff00fe00feff02ff, 0xff00fe00feff02ff};
  __m256i_result = (__m256i){0x7f807f007f7f817f, 0x9ff87ef07f7f817f,
                             0x7f807f007f7f817f, 0x9ff87ef07f7f817f};
  __m256i_out = __lasx_xvavg_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0fffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x21f6050d955d3f68, 0x111ebb784f9bf1ac,
                      0x1c386546809f3b50, 0x111ebb784f9c4100};
  __m256i_result = (__m256i){0x10fb02864aae9fb4, 0x088f5dbc27cdf8d6,
                             0x161c32a2c04f9da7, 0x088f5dbc27ce2080};
  __m256i_out = __lasx_xvavg_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffe0000fffe0012, 0xfffefffefffeffee,
                      0xfffe0000fffe0012, 0xfffefffefffeffee};
  v4u64_op1 = (v4u64){0xfffe0000fffe0012, 0xfffefffefffeffee,
                      0xfffe0000fffe0012, 0xfffefffefffeffee};
  __m256i_result = (__m256i){0xfffe0000fffe0012, 0xfffefffefffeffee,
                             0xfffe0000fffe0012, 0xfffefffefffeffee};
  __m256i_out = __lasx_xvavg_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000100000001, 0x0000000000000000,
                      0x0000000100000001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7fffffffffffffff, 0x7fffffffffffffff,
                             0x7fffffffffffffff, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvavg_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010001, 0x0001000100010001,
                      0x0001000100010001, 0x0001000100010001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000800080008000, 0x0000800080008000,
                             0x0000800080008000, 0x0000800080008000};
  __m256i_out = __lasx_xvavg_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00007bbb0000f777, 0x0000000000004444,
                      0x00007bbb0000f777, 0x0000000000004444};
  __m256i_result = (__m256i){0x00003ddd80007bbb, 0x0000000000002222,
                             0x00003ddd80007bbb, 0x0000000000002222};
  __m256i_out = __lasx_xvavg_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000000f0f0, 0x0000000000000000,
                      0x000000000000f0f0, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000007878, 0x0000000000000000,
                             0x0000000000007878, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x7fffffffffffffff, 0x7fffffffffffffff,
                             0x7fffffffffffffff, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvavg_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvavg_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000001e00000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000f00000000};
  __m256i_out = __lasx_xvavg_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
