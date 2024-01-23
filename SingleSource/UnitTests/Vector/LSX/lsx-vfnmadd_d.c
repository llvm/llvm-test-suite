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

  v2u64_op0 = (v2u64){0x9f9e7e3e9ea3ff41, 0xef0179a47c793879};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x1e801ffc7fc00000, 0x7fc000007fc00000};
  v2u64_result = (v2u64){0x9e801ffc7fc00000, 0xffc000007fc00000};
  __m128d_out = __lsx_vfnmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x3f8000003f800000};
  v2u64_op2 = (v2u64){0x0000ffff00000000, 0x0000ffff00000000};
  v2u64_result = (v2u64){0x8000ffff00000000, 0x8000ffff00000000};
  __m128d_out = __lsx_vfnmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffbfffffffbf, 0xffffffbfffffffbf};
  v2u64_op1 = (v2u64){0xffffffff00000001, 0x0000000008800022};
  v2u64_op2 = (v2u64){0x6477d042343cce24, 0xb8ec43befe38e64b};
  v2u64_result = (v2u64){0xffffffbfffffffbf, 0xffffffbfffffffbf};
  __m128d_out = __lsx_vfnmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffff000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000060000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0xfffffffffffff000, 0x8000000000000000};
  __m128d_out = __lsx_vfnmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffafffffffa, 0xfffffffafffffffa};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_result = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128d_out = __lsx_vfnmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xf8f8f8f8f8f8f8f8, 0xf8f8f8f8f8f8f8f8};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x8000000000000000, 0x8000000000000000};
  __m128d_out = __lsx_vfnmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x8000000000000000, 0x8000000000000000};
  __m128d_out = __lsx_vfnmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000008000000080, 0x0000008000000080};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x8000000000000000, 0x8000000000000000};
  __m128d_out = __lsx_vfnmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff76ffd8ffe6ffaa, 0xff80ffa2fff0ff74};
  v2u64_op1 = (v2u64){0xff76ffd8ffe6ffaa, 0xff80ffa2fff0ff74};
  v2u64_op2 = (v2u64){0x0303030303030303, 0x0303030303030303};
  v2u64_result = (v2u64){0xfff0000000000000, 0xfff0000000000000};
  __m128d_out = __lsx_vfnmadd_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffff00000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffff00000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x8000000000000000, 0xffffffff00000000};
  __m128d_out = __lsx_vfnmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000ffff0000ffff};
  v2u64_op1 = (v2u64){0x0001ffff0001ffff, 0x0001ffff00000000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x8000000000000000, 0x8000000000000000};
  __m128d_out = __lsx_vfnmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffffe, 0x0000000000000001};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xff800000ff800000};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0xfffffffffffffffe, 0x3c600000ff800000};
  __m128d_out = __lsx_vfnmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000000d, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000000000000d, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x00000000b5207f80, 0x0000000000000000};
  v2u64_result = (v2u64){0x00000000b5207f80, 0x8000000000000000};
  __m128d_out = __lsx_vfnmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op2 = (v2u64){0xffffffffffffffff, 0x0000000000000000};
  v2u64_result = (v2u64){0xffffffffffffffff, 0x8000000000000000};
  __m128d_out = __lsx_vfnmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000009000900, 0x0000000009000900};
  v2u64_op2 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_result = (v2u64){0x8000000000000000, 0x8000000000000000};
  __m128d_out = __lsx_vfnmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00a975be00accf03, 0x00c2758000bccf42};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  v2u64_op2 = (v2u64){0x00000000ffffffff, 0x0000000000000000};
  v2u64_result = (v2u64){0x00000000ffffffff, 0x8000000000000000};
  __m128d_out = __lsx_vfnmsub_d((__m128)v2u64_op0, (__m128)v2u64_op1, (__m128)v2u64_op2);
  check_lsx_out(&v2u64_result, &__m128d_out, sizeof(__m128d_out), __FILE__, __LINE__);

  return 0;
}
