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

  v4u64_op0 = (v4u64){0x7fff7fff7fff0000, 0x7fe37fe3001d001d,
                      0x7fff7fff7fff0000, 0x7fe37fe3001d001d};
  v4u64_op1 = (v4u64){0x7575757575757575, 0x7575757575757575,
                      0x7575757575757575, 0x7575757575757575};
  __m256i_result = (__m256i){0x7fff7fff7fff0000, 0x7fe37fe3001d001d,
                             0x7fff7fff7fff0000, 0x7fe37fe3001d001d};
  __m256i_out = __lasx_xvpermi_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x22);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  v4u64_op1 = (v4u64){0xffff0000ffff0000, 0xffffffffffffffff,
                      0xffff0000ffff0000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                             0xffff0000ffff0000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvpermi_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000019001c, 0x0000000000000000,
                      0x000000000019001c, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000000001fe, 0x0000000000000000,
                      0x00000000000001fe, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000000001fe, 0x0000000000000000,
                             0x000000000019001c, 0x0000000000000000};
  __m256i_out = __lasx_xvpermi_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x31);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
