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

  v4i32_op0 = (v4i32){0x05050000, 0x00000000, 0x05050505, 0x05050505};
  v4i32_op1 = (v4i32){0xe496cbc9, 0x03574e38, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xe496cbc9, 0x03574e38, 0x05050505, 0x05050505};
  __m128_out = __lsx_vfadd_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfadd_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfadd_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x0000000f, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00077f88, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00077f97, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfadd_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x000000ff, 0x000000ff, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0xffecffec, 0x370bdfec, 0xffecffec, 0x370bdfec};
  v4i32_result = (v4i32){0xffecffec, 0x370bdfec, 0xffecffec, 0x370bdfec};
  __m128_out = __lsx_vfadd_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v4i32_op1 = (v4i32){0x00ff0000, 0x0000ff00, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m128_out = __lsx_vfadd_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0xffff0000, 0xffff0000};
  v4i32_op1 = (v4i32){0x80200110, 0x40408010, 0x80040110, 0x40088040};
  v4i32_result = (v4i32){0x80200110, 0x40408010, 0xffff0000, 0xffff0000};
  __m128_out = __lsx_vfadd_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0xfffffffc, 0xffffffff, 0xfffffffc, 0xffffffff};
  v4i32_result = (v4i32){0xfffffffc, 0xffffffff, 0xfffffffc, 0xffffffff};
  __m128_out = __lsx_vfadd_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x0000001b, 0x0000001b, 0x0000001b, 0x0000001b};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x0000001b, 0x0000001b, 0x0000001b, 0x0000001b};
  __m128_out = __lsx_vfadd_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfsub_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x81010102, 0x7fffffff, 0x81010102, 0x7fff0101};
  v4i32_op1 = (v4i32){0x20204000, 0x00001020, 0xffffe000, 0x00000fff};
  v4i32_result = (v4i32){0xa0204000, 0x7fffffff, 0xffffe000, 0x7fff0101};
  __m128_out = __lsx_vfsub_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xffffffff, 0x00000000, 0xffffffff, 0x00000000};
  v4i32_op1 = (v4i32){0x20204000, 0x00001020, 0xffffe000, 0x00000fff};
  v4i32_result = (v4i32){0xffffffff, 0x80001020, 0xffffffff, 0x80000fff};
  __m128_out = __lsx_vfsub_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfsub_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xa494006b, 0x0124d8f6, 0x43c0d41e, 0x56411278};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0xffffffff};
  v4i32_result = (v4i32){0x80000000, 0x00000000, 0x00000000, 0xffffffff};
  __m128_out = __lsx_vfmul_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x0501050c, 0x05010501, 0x05010501, 0x05010501};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmul_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x2cbd0357, 0x407c2ca3, 0x5b7a02c8, 0x21f32eaf};
  v4i32_op1 = (v4i32){0x00010400, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmul_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xfffe0001, 0xfffe0001, 0xfffe0001, 0xfffe0001};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xfffe0001, 0xfffe0001, 0xfffe0001, 0xfffe0001};
  __m128_out = __lsx_vfmul_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00002ebf, 0x00000000};
  v4i32_op1 = (v4i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xffffffff, 0xffffffff, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmul_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x01000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmul_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x1f1f1f1f, 0x1f1f1f1f, 0x1f1f1f1f, 0x00081f1f};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmul_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x21030a49, 0x030298a6, 0x49678a35, 0x021b7d24};
  v4i32_op1 = (v4i32){0x00000002, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmul_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfmul_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xb8145f50, 0x27b169bb, 0x47e59090, 0xf6548a17};
  v4i32_op1 = (v4i32){0x00be00a0, 0xff700028, 0x00d2ff76, 0x004eff62};
  v4i32_result = (v4i32){0x800001b8, 0xe7a6533b, 0x093d35ab, 0xb7032c34};
  __m128_out = __lsx_vfmul_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xa494afcb, 0x8064d8f6, 0xbc3f2be1, 0x54feed87};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xff800000, 0xff800000, 0xff800000, 0x7f800000};
  __m128_out = __lsx_vfdiv_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x7f678077, 0xd8248069, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x7f678077, 0xd8248069, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x3f800000, 0x3f800000, 0x7fc00000, 0x7fc00000};
  __m128_out = __lsx_vfdiv_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7fc00000, 0x7fc00000, 0x7fc00000, 0x7fc00000};
  __m128_out = __lsx_vfdiv_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00010000, 0x00030000, 0x00040000, 0x00070000};
  v4i32_op1 = (v4i32){0x00010000, 0x00030000, 0x00040000, 0x00070000};
  v4i32_result = (v4i32){0x3f800000, 0x3f800000, 0x3f800000, 0x3f800000};
  __m128_out = __lsx_vfdiv_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00010001, 0x00010001, 0x0001007c, 0x00010001};
  v4i32_result = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m128_out = __lsx_vfdiv_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0xfffffffc, 0x00000003, 0x00001fff, 0x00001fff};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0xfffffffc, 0x7f800000, 0x7f800000, 0x7f800000};
  __m128_out = __lsx_vfdiv_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  v4i32_op0 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_op1 = (v4i32){0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v4i32_result = (v4i32){0x7fc00000, 0x7fc00000, 0x7fc00000, 0x7fc00000};
  __m128_out = __lsx_vfdiv_s((__m128)v4i32_op0, (__m128)v4i32_op1);
  check_lsx_out(&v4i32_result, &__m128_out, sizeof(__m128_out), __FILE__, __LINE__);

  return 0;
}
