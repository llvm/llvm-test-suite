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

  v4u64_op0 = (v4u64){0x1e18000000000000, 0x1e1800001e180000,
                      0x1e18000000000000, 0x1e1800001e180000};
  v4u64_result = (v4u64){0x2f03988e1409212e, 0x2f03988e2052463e,
                         0x2f03988e1409212e, 0x2f03988e2052463e};
  __m256d_out = __lasx_xvfsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff874dc687870000, 0x00000000003f7e3f,
                      0xffc6cc05c64d960e, 0x00000000003f7e3f};
  v4u64_result = (v4u64){0x7ff8000000000000, 0x1f0fdf7f3e3b31d4,
                         0x7ff8000000000000, 0x1f0fdf7f3e3b31d4};
  __m256d_out = __lasx_xvfsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000018, 0x0000000000000000,
                      0x0000000100000018, 0x0000000000000000};
  v4u64_result = (v4u64){0x1f60000000c00000, 0x0000000000000000,
                         0x1f60000000c00000, 0x0000000000000000};
  __m256d_out = __lasx_xvfsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0003030300000100, 0x0003030300000100,
                      0x0003030300000300, 0x0003030300000300};
  v4u64_result = (v4u64){0x1febc46085090567, 0x1febc46085090567,
                         0x1febc46085090ea0, 0x1febc46085090ea0};
  __m256d_out = __lasx_xvfsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_result = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                         0x0000000000000000, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000007f007f007f, 0x0000000000000000,
                      0x0000007f007f007f, 0x0000000000000000};
  v4u64_result = (v4u64){0x1f9689fdb16cabbd, 0x0000000000000000,
                         0x1f9689fdb16cabbd, 0x0000000000000000};
  __m256d_out = __lasx_xvfsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffff0000, 0x0000000000000000,
                      0xffffffffffff0000, 0x0000000000000000};
  v4u64_result = (v4u64){0xffffffffffff0000, 0x0000000000000000,
                         0xffffffffffff0000, 0x0000000000000000};
  __m256d_out = __lasx_xvfsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x0000000000000000, 0x0000000000000000,
                         0x0000000000000000, 0x0000000000000000};
  __m256d_out = __lasx_xvfsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000010000000100, 0x0000000000000000,
                      0x0000010000000100, 0x0000000000000000};
  v4u64_result = (v4u64){0x1fa0000000080000, 0x0000000000000000,
                         0x1fa0000000080000, 0x0000000000000000};
  __m256d_out = __lasx_xvfsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffff8000, 0x0000000000000000,
                      0xffffffffffff8000, 0x0000000000000000};
  v4u64_result = (v4u64){0xffffffffffff8000, 0x0000000000000000,
                         0xffffffffffff8000, 0x0000000000000000};
  __m256d_out = __lasx_xvfsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x03fc03fc03f803f8,
                      0x03fc03fc03f803f8, 0x03fc03fc03f803f8};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7be2468acf15f39c,
                         0x7be2468acf15f39c, 0x7be2468acf15f39c};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000089, 0x0000000002a54290,
                      0x000000000154dc84, 0x0000000002a54290};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xd0d8eecf383fdf0d, 0x0001000100010001,
                      0xd0d8eecf383fdf0d, 0x0001000100010001};
  v4u64_result = (v4u64){0xaf0489001bd4c0c3, 0x7ff0000000000000,
                         0xaf0489001bd4c0c3, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000fffff614, 0x0000000a00000000,
                      0x00000000fffff614, 0x0000000a00000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000001e0000001e, 0x0000001e0000001e,
                      0x0000001e0000001e, 0x0000001e0000001e};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff80000000000000, 0x0000000000000000,
                      0xff80000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x8060000000000000, 0x7ff0000000000000,
                         0x8060000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_result = (v4u64){0xffffffffffffffff, 0x7ff0000000000000,
                         0xffffffffffffffff, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_result = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                         0xffffffffffffffff, 0xffffffffffffffff};
  __m256d_out = __lasx_xvfrecip_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0xffffffffffffffff,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0xffffffff00000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0003fffc00060000, 0x0000000000000000,
                      0x0209fefb08140000, 0x000000000000ffff};
  v4u64_result = (v4u64){0x5ff00007fff9fff3, 0x7ff0000000000000,
                         0x5ee1c073b800c916, 0x6100000800060005};
  __m256d_out = __lasx_xvfrsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x555555553f800000, 0x0000000000000000,
                      0x555555553f800000, 0x0000000000000000};
  v4u64_result = (v4u64){0x353bb67af686ad9b, 0x7ff0000000000000,
                         0x353bb67af686ad9b, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000001f0000ffff, 0x0000001f0000001f,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  v4u64_result = (v4u64){0x6056fd4e1a4616c4, 0x6056fd4e7926d5c0,
                         0x60000007fffe0001, 0x60000007fffe0001};
  __m256d_out = __lasx_xvfrsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_result = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                         0x7ff0000000000000, 0x7ff0000000000000};
  __m256d_out = __lasx_xvfrsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000f900004040, 0x00001bfa000000f9,
                      0x000000f900004040, 0x00001bfa000000f9};
  v4u64_result = (v4u64){0x6040392cdaf9b3ff, 0x60183329ceb52cf0,
                         0x6040392cdaf9b3ff, 0x60183329ceb52cf0};
  __m256d_out = __lasx_xvfrsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xbffffffe80000000, 0x3de00103153ff5fb,
                      0xbffffffe80000000, 0x3de00103153ff5fb};
  v4u64_result = (v4u64){0x7ff8000000000000, 0x40f69fe73c26f4ee,
                         0x7ff8000000000000, 0x40f69fe73c26f4ee};
  __m256d_out = __lasx_xvfrsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000007ffffffce, 0x00000005ffffffff,
                      0x00000007ffffffce, 0x00000005ffffffff};
  v4u64_result = (v4u64){0x6066a09e66c5f1bb, 0x606a20bd700e59a3,
                         0x6066a09e66c5f1bb, 0x606a20bd700e59a3};
  __m256d_out = __lasx_xvfrsqrt_d((__m256)v4u64_op0);
  check_lasx_out(&v4u64_result, &__m256d_out, sizeof(__m256d_out), __FILE__, __LINE__);

  return 0;
}
