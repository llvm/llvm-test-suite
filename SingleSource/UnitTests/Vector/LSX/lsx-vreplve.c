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

  v2u64_op0 = (v2u64){0x0000000080000000, 0x0000000080000000};
  int_op1 = 0x00000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_b((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_b((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000100000001};
  int_op1 = 0xffffffff;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_b((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x00000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_b((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x00020006;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_b((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffffffffffffff4, 0xfffffffffffffff4};
  int_op1 = 0x000000ff;
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vreplve_b((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8000000080000000, 0x8000000080000000};
  int_op1 = 0x000000ff;
  __m128i_result = (__m128i){0x8080808080808080, 0x8080808080808080};
  __m128i_out = __lsx_vreplve_b((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_b((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x00000000090b0906;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_b((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000ffffffff0001};
  int_op1 = 0x00000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_h((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_h((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x00020006;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_h((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_h((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffd27db010d20fbf, 0x6363636363636363};
  int_op1 = 0x0000000000000040;
  __m128i_result = (__m128i){0x0fbf0fbf0fbf0fbf, 0x0fbf0fbf0fbf0fbf};
  __m128i_out = __lsx_vreplve_h((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffefffe011df03e, 0xfffefffefffefffe};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0xf03ef03ef03ef03e, 0xf03ef03ef03ef03e};
  __m128i_out = __lsx_vreplve_h((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0xeef14fe8;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x78c00000ff000000, 0x0000000000000000};
  int_op1 = 0x00000400;
  __m128i_result = (__m128i){0xff000000ff000000, 0xff000000ff000000};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x00000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xe0404041c0404040, 0x803f800080000000};
  int_op1 = 0x00000001;
  __m128i_result = (__m128i){0xe0404041e0404041, 0xe0404041e0404041};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0001000100010001, 0x0001000100010001};
  int_op1 = 0x3f800000;
  __m128i_result = (__m128i){0x0001000100010001, 0x0001000100010001};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x000000ff;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ffff00ff00ff00, 0x00ffff00ff00ff00};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0xff00ff00ff00ff00, 0xff00ff00ff00ff00};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7ff0000000000000, 0x7ff0000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000000000000001b, 0x000000000000001b};
  int_op1 = 0x89e08000;
  __m128i_result = (__m128i){0x0000001b0000001b, 0x0000001b0000001b};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfefefeeffef7fefe, 0xfefefefdbffefdfe};
  int_op1 = 0x9c0d6112;
  __m128i_result = (__m128i){0xbffefdfebffefdfe, 0xbffefdfebffefdfe};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff800000ff800000, 0xff800000ff800000};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0xff800000ff800000, 0xff800000ff800000};
  __m128i_out = __lsx_vreplve_w((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x000000ac;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_d((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffb4ff, 0xffffffffffffffff};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0xffffffffffffb4ff, 0xffffffffffffb4ff};
  __m128i_out = __lsx_vreplve_d((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x20202020;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_d((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0x7ff00000;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_d((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  int_op1 = 0xffff8a35;
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vreplve_d((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000047fe2f0, 0x05dfffc3ffffffc0};
  int_op1 = 0x0000000000000000;
  __m128i_result = (__m128i){0x00000000047fe2f0, 0x00000000047fe2f0};
  __m128i_out = __lsx_vreplve_d((__m128)v2u64_op0, int_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
