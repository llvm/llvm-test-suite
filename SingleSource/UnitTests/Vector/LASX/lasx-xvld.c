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
  __m256i_result = (__m256i){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                             0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_out = __lasx_xvld((unsigned long *)&v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                      0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_result = (__m256i){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                             0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_out = __lasx_xvldx((unsigned long *)&v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                      0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_result = (__m256i){0xebebebebebebebeb, 0xebebebebebebebeb,
                             0xebebebebebebebeb, 0xebebebebebebebeb};
  __m256i_out = __lasx_xvldrepl_b((unsigned long *)&v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                      0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_result = (__m256i){0xfeebfeebfeebfeeb, 0xfeebfeebfeebfeeb,
                             0xfeebfeebfeebfeeb, 0xfeebfeebfeebfeeb};
  __m256i_out = __lasx_xvldrepl_h((unsigned long *)&v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                      0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_result = (__m256i){0xad72feebad72feeb, 0xad72feebad72feeb,
                             0xad72feebad72feeb, 0xad72feebad72feeb};
  __m256i_out = __lasx_xvldrepl_w((unsigned long *)&v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0ad152a5ad72feeb, 0xa98d4f7a77c308ee,
                      0x58569d7be9179100, 0x042f0500cfea969a};
  __m256i_result = (__m256i){0x0ad152a5ad72feeb, 0x0ad152a5ad72feeb,
                             0x0ad152a5ad72feeb, 0x0ad152a5ad72feeb};
  __m256i_out = __lasx_xvldrepl_d((unsigned long *)&v4u64_op0, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
