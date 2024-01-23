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

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v2u64_op0 = (v2u64){0xfffcfffcfffcfffc, 0xfffcfffcfffcfffc};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x6664666466646664, 0x6664666466646664};
  __m128i_out = __lsx_vbitseli_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x66);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffff7, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffff0000010000, 0xffffffff00000001};
  __m128i_result = (__m128i){0x5d5d5d5d5d5d5d55, 0xffffffff00000001};
  __m128i_out = __lsx_vbitseli_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x5d);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000004, 0x0000000000000004};
  __m128i_result = (__m128i){0x5959595959595959, 0x5959595959595959};
  __m128i_out = __lsx_vbitseli_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x59);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xfffd000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0xfffd000000000000};
  __m128i_out = __lsx_vbitseli_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x3a);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vbitseli_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xaa);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0b4c600000000002, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0808080808080808, 0x0808080808080808};
  __m128i_result = (__m128i){0x0004280808080808, 0x0808080808080808};
  __m128i_out = __lsx_vbitseli_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0xa4);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00007770ffff9411, 0x0000004000000040};
  v2u64_op1 = (v2u64){0x00007770ffff941d, 0x000000400000004c};
  __m128i_result = (__m128i){0x000047404f4f040d, 0x000000400000004c};
  __m128i_out = __lsx_vbitseli_b((__m128)v2u64_op0, (__m128)v2u64_op1, 0x4f);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
