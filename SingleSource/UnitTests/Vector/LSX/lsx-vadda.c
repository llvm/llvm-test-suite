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

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadda_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0x00000001fffc001f};
  __m128i_result = (__m128i){0x0101010102020202, 0x0101010202050120};
  __m128i_out = __lsx_vadda_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0101010101010101, 0x0101010101010101};
  __m128i_out = __lsx_vadda_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000100000001};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000100000001};
  __m128i_out = __lsx_vadda_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadda_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000092444, 0x00000000006a9a5c};
  v2u64_op1 = (v2u64){0x0000000000092444, 0x00000000006a9a5c};
  __m128i_result = (__m128i){0x0000000000124888, 0x0000000000d4ccb8};
  __m128i_out = __lsx_vadda_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000008140c80, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000008140c80, 0x0000000000000000};
  __m128i_out = __lsx_vadda_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffff000000b9, 0x0000fffe0000ff45};
  v2u64_op1 = (v2u64){0x343d8dc6b0ed5a08, 0xffd5002affffffff};
  __m128i_result = (__m128i){0x353e743b50135a4f, 0x012b012c01010246};
  __m128i_out = __lsx_vadda_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000008};
  __m128i_result = (__m128i){0x0101010101010101, 0x0101010101010109};
  __m128i_out = __lsx_vadda_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000004442403e4, 0x0000000005452505};
  v2u64_op1 = (v2u64){0x00000000ffffffe0, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000044525043c, 0x0000000005452505};
  __m128i_out = __lsx_vadda_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000208000002080, 0x0000208000002080};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000208000002080, 0x0000208000002080};
  __m128i_out = __lsx_vadda_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000800000008000, 0x0000800000008000};
  __m128i_result = (__m128i){0x0000800000008000, 0x0000800000008000};
  __m128i_out = __lsx_vadda_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x63635c9e63692363, 0x5c9c9c9ce3636363};
  v2u64_op1 = (v2u64){0x0000a00028004000, 0xf0fd800080000000};
  __m128i_result = (__m128i){0x6363bc9e8b696363, 0x6b9fe3649c9d6363};
  __m128i_out = __lsx_vadda_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fff00007fff0000, 0x7fff00007fff0000};
  v2u64_op1 = (v2u64){0x003f0000003f0000, 0x003f0000003f0000};
  __m128i_result = (__m128i){0x803e0000803e0000, 0x803e0000803e0000};
  __m128i_out = __lsx_vadda_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000008};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000008};
  __m128i_out = __lsx_vadda_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000024170000, 0x00000000084d12ce};
  v2u64_op1 = (v2u64){0x0000000020300000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000044470000, 0x00000000084d12ce};
  __m128i_out = __lsx_vadda_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x52527d7d52527d7d, 0x52527d7d52527d7d};
  __m128i_result = (__m128i){0x52527d7d52527d7d, 0x52527d7d52527d7d};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0003000700020005, 0x0003000300030003};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0003000700020005, 0x0003000300030003};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x4f8000004f800000, 0x4f8000004f800000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x4f8000004f800000, 0x4f8000004f800000};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1111111111111111, 0x1111111111111111};
  v2u64_op1 = (v2u64){0x0000002000000020, 0x0000002000000020};
  __m128i_result = (__m128i){0x1111113111111131, 0x1111113111111131};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x1f5533a694f902c0, 0xfffffacdb6dbecac};
  v2u64_op1 = (v2u64){0xa36aca4435b8b8e1, 0x5a6f5c53ebed3faa};
  __m128i_result = (__m128i){0x7bea6962a0bfb621, 0x5a6f61865d36d3aa};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000000000000, 0x8000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x8000000000000000, 0x8000000000000000};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001400000000, 0x0000001400000014};
  v2u64_op1 = (v2u64){0xfffc000400000000, 0xfff9000000000000};
  __m128i_result = (__m128i){0x0004001000000000, 0x0007001400000014};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8080808080808080, 0x8080808080808080};
  v2u64_op1 = (v2u64){0x8080808080808080, 0x8080808080808080};
  __m128i_result = (__m128i){0xfefeff00fefeff00, 0xfefeff00fefeff00};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6363636363636363, 0x6363636363636363};
  v2u64_op1 = (v2u64){0xff01ff01ac465ca1, 0xff01ff01ac025c87};
  __m128i_result = (__m128i){0x64616462b71d06c2, 0x64616462b76106dc};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffaeffaeffaeffae, 0xffaeffaeffaeffae};
  __m128i_result = (__m128i){0x0051005200510052, 0x0051005200510052};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3bc000003a800000, 0x3a8000003a800000};
  v2u64_op1 = (v2u64){0x0a0000000a000000, 0x0a0000000a000000};
  __m128i_result = (__m128i){0x45c0000044800000, 0x4480000044800000};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6363636363636363, 0x6363636363636363};
  v2u64_op1 = (v2u64){0xffffffff00000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x6363636463636363, 0x6363636363636363};
  __m128i_out = __lsx_vadda_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadda_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vadda_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfffcfffcfffcfffc, 0xfffcfffcfffcfffc};
  __m128i_result = (__m128i){0x0003000300030004, 0x0003000300030004};
  __m128i_out = __lsx_vadda_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x76f424887fffffff, 0x0000000000000001};
  v2u64_op1 = (v2u64){0x003f000000000000, 0xfff082f000000000};
  __m128i_result = (__m128i){0x773324887fffffff, 0x000f7d1000000001};
  __m128i_out = __lsx_vadda_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0003c853c843c87e, 0x0003c853c843c87e};
  __m128i_result = (__m128i){0x0003c853c843c87e, 0x0003c853c843c87e};
  __m128i_out = __lsx_vadda_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000200000002000};
  v2u64_op1 = (v2u64){0xffffffffe000ffdf, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x000000001fff0021, 0x0000200000002001};
  __m128i_out = __lsx_vadda_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x5d7f5d807fea807f};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x5d7f5d807fea807f};
  __m128i_result = (__m128i){0x0000000000000000, 0xbafebb00ffd500fe};
  __m128i_out = __lsx_vadda_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
