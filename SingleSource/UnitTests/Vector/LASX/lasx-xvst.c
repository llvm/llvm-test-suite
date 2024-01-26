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

  v4u64_op0 = (v4u64){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                      0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_result = (__m256i){0x0, 0x0, 0x0, 0x0};
  __lasx_xvst((__m256)v4u64_op0, (unsigned long *)&__m256i_result, 0x0);
  check_lasx_out(&v4u64_op0, &__m256i_result, sizeof(__m256i_result), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                      0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_result = (__m256i){0x0, 0x0, 0x0, 0x0};
  __lasx_xvstx((__m256)v4u64_op0, (unsigned long *)&__m256i_result, 0x0);
  check_lasx_out(&v4u64_op0, &__m256i_result, sizeof(__m256i_result), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                      0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_result = (__m256i){0x8d, 0x0, 0x0, 0x0};
  __m256i_out = (__m256i){0x0, 0x0, 0x0, 0x0};
  __lasx_xvstelm_b((__m256)v4u64_op0, (unsigned long *)&__m256i_out, 0x0, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                      0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_result = (__m256i){0x9100, 0x0, 0x0, 0x0};
  __m256i_out = (__m256i){0x0, 0x0, 0x0, 0x0};
  __lasx_xvstelm_h((__m256)v4u64_op0, (unsigned long *)&__m256i_out, 0x0, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                      0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_result = (__m256i){0xe9179100, 0x0, 0x0, 0x0};
  __m256i_out = (__m256i){0x0, 0x0, 0x0, 0x0};
  __lasx_xvstelm_w((__m256)v4u64_op0, (unsigned long *)&__m256i_out, 0x0, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                      0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_result = (__m256i){0x58569d7be9179100, 0x0, 0x0, 0x0};
  __m256i_out = (__m256i){0x0, 0x0, 0x0, 0x0};
  __lasx_xvstelm_d((__m256)v4u64_op0, (unsigned long *)&__m256i_out, 0x0, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
