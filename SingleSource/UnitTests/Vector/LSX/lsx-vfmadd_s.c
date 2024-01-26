#include "lsx_test_util.h"
#include <lsxintrin.h>

int
main ()
{
  __m128i __m128i_out, __m128i_result;
  __m128  __m128_out, __m128_result;
  __m128d __m128d_out, __m128d_result;
  v2u64 v2u64_op0, v2u64_op1, v2u64_op2, v2u64_result;
  v4i32 v4i32_op0, v4i32_op1, v4i32_op2, v4i32_result;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000002, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000002, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00010001, 0x01000041, 0xa000a041, 0x0028e0a1};
  v4i32_op1 = (v4i32){0x00000000, 0x00010001, 0x01000001, 0x00000000};
  v4i32_op2 = (v4i32){0xffff1fff, 0xffffe000, 0x01000001, 0x00000000};
  v4i32_result = (v4i32){0xffff1fff, 0xffffe000, 0x01000001, 0x00000000};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  v4i32_op1 = (v4i32){0x00000003, 0x00000003, 0x00000002, 0x00000002};
  v4i32_op2 = (v4i32){0x3fc00000, 0x3fc00000, 0x3fc00000, 0x3fc00000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x7f020000, 0x7f020000, 0x7f040000, 0x7f400000};
  v4i32_op1 = (v4i32){0x003b0013, 0xfffefffe, 0x0014002c, 0xffffffff};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x3f6fb04d, 0xfffefffe, 0x3ea5016b, 0xffffffff};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x004f0080, 0x004f0080, 0x004f0080, 0x004f0080};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x7fff7fff, 0x7fff7fff};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x7fff7fff, 0x7fff7fff};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x3d3d3d3d, 0x3d3d3d3d, 0x3d3d3d3d, 0x3d3d3d3d};
  v4i32_op1 = (v4i32){0x00000000, 0x00100000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x0000bd3d, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00050005, 0x00050005, 0x00050005, 0x00050005};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xc48004c5, 0xe5c1a185, 0xc000c005, 0xe500c085};
  v4i32_op1 = (v4i32){0xffffc005, 0xffffc000, 0xffffffff, 0xffffffff};
  v4i32_op2 = (v4i32){0x005cffca, 0x00590013, 0x002a004b, 0xff550025};
  v4i32_result = (v4i32){0xffffc005, 0xffffc000, 0xffffffff, 0xffffffff};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x7fff7f00, 0x7fff7fff, 0x00cf005f, 0x00fe0001};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x7f6a007f, 0x5d7f5d00};
  v4i32_result = (v4i32){0x7fff7f00, 0x7fff7fff, 0x7f6a007f, 0x5d7f5d00};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xb9951901, 0xffff913b, 0xffffffda, 0x00680486};
  v4i32_op1 = (v4i32){0x01030103, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00200060, 0x00200060, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x001fed4d, 0xffff913b, 0xffffffda, 0x00000000};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x001a000b, 0x001a001a, 0x001a0008, 0x001a001a};
  v4i32_op1 = (v4i32){0x0f800000, 0xff800001, 0xffffffff, 0xffffffff};
  v4i32_op2 = (v4i32){0xff800000, 0xff800000, 0xff800000, 0xff800000};
  v4i32_result = (v4i32){0xff800000, 0xffc00001, 0xffffffff, 0xffffffff};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xfe01fa21, 0xfe03fe3f, 0xfe3bfe01, 0xfe3bfb01};
  v4i32_op1 = (v4i32){0xfe01fa21, 0xfe03fe3f, 0xfe3bfe01, 0xfe3bfb01};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7f800000, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfmadd_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmsub_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffe001, 0xffffe001, 0xffffe001, 0xffffe001};
  v4i32_op1 = (v4i32){0x01ffe200, 0xffffe000, 0xffffffff, 0xffffffff};
  v4i32_op2 = (v4i32){0x83838404, 0x04040383, 0x83838404, 0x04040383};
  v4i32_result = (v4i32){0xffffe001, 0xffffe001, 0xffffe001, 0xffffe001};
  __m128_out = __lsx_vfmsub_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x151d3756, 0x16151413, 0x17161514, 0x18171615};
  v4i32_op1 = (v4i32){0x80000000, 0x39412488, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x40f3fa00, 0x00000000, 0x3ff00000};
  v4i32_result = (v4i32){0x80000000, 0xc0f3fa00, 0x00000000, 0xbff00000};
  __m128_out = __lsx_vfmsub_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000005, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmsub_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x3ddc5dac, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0xffffffff, 0xffffffff};
  v4i32_op2 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0xffffffff, 0xffffffff};
  __m128_out = __lsx_vfmsub_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0x41f8e880, 0xfe486741, 0x63636b6a};
  v4i32_op1 = (v4i32){0x16161198, 0x41f8e080, 0x63abdf16, 0xe3636363};
  v4i32_op2 = (v4i32){0x00accf03, 0x00a975be, 0x00bccf42, 0x00c27580};
  v4i32_result = (v4i32){0xffffffff, 0x4471fb84, 0xff800000, 0xff800000};
  __m128_out = __lsx_vfmsub_s((__m128)v4i32_op0, (__m128)v4i32_op1, (__m128)v4i32_op2);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  return 0;
}
