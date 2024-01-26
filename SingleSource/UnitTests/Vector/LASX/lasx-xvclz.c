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

  v4u64_op0 = (v4u64){0xcf25f0e00f1ff0e0, 0x51258839aeda77c6,
                      0xf2781966e6991966, 0x04481940fbb7e6bf};
  __m256i_result = (__m256i){0x0002000004030000, 0x0102000200000100,
                             0x0001030100000301, 0x0501030100000000};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0808080808080808, 0x0808080808080808,
                             0x0808080808080808, 0x0808080808080808};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0xfffffffffffffffe,
                      0x0000000000000001, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0x0808080808080807, 0x0000000000000000,
                             0x0808080808080807, 0x0000000000000000};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff00ffffff00ffff, 0xffffffffffffffff,
                      0xff00ffffff00ffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0008000000080000, 0x0000000000000000,
                             0x0008000000080000, 0x0000000000000000};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0808080808080808, 0x0808080808080808,
                             0x0808080808080808, 0x0808080808080808};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0b004bc000000000, 0x0b085bfc00000000,
                      0x0b004bc000000000, 0x0b085bfc00000000};
  __m256i_result = (__m256i){0x0408010008080808, 0x0404010008080808,
                             0x0408010008080808, 0x0404010008080808};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0408010008080808, 0x0404010008080808,
                      0x0408010008080808, 0x0404010008080808};
  __m256i_result = (__m256i){0x0504070804040404, 0x0505070804040404,
                             0x0504070804040404, 0x0505070804040404};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0808080808080808,
                             0x0000000000000000, 0x0808080808080808};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000080, 0x0000000000000000,
                      0xffffffff00000080, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000008080800, 0x0808080808080808,
                             0x0000000008080800, 0x0808080808080808};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0808080808080808, 0x0808080808080808,
                             0x0808080808080808, 0x0808080808080808};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0808080808080808, 0x0808080808080808,
                             0x0808080808080808, 0x0808080808080808};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0808080808080808, 0x0808080808080808,
                             0x0808080808080808, 0x0808080808080808};
  __m256i_out = __lasx_xvclz_b((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0010001000100010, 0x0010001000100010,
                             0x0010001000100010, 0x0010001000100010};
  __m256i_out = __lasx_xvclz_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000007fff, 0x7fffffff7fffffff,
                      0x0000000000007fff, 0x7fffffff7fffffff};
  __m256i_result = (__m256i){0x0010001000100001, 0x0001000000010000,
                             0x0010001000100001, 0x0001000000010000};
  __m256i_out = __lasx_xvclz_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0010001000100010, 0x0010001000100010,
                             0x0010001000100010, 0x0010001000100010};
  __m256i_out = __lasx_xvclz_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000003c000000032, 0x0000000000000000,
                      0x0000000000000032, 0x0000000000000000};
  __m256i_result = (__m256i){0x001000060010000a, 0x0010001000100010,
                             0x001000100010000a, 0x0010001000100010};
  __m256i_out = __lasx_xvclz_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0a0a0a0a00000000, 0x0a0a000000000a0a,
                      0x0a0a0a0a00000000, 0x0a0a000000000a0a};
  __m256i_result = (__m256i){0x0004000400100010, 0x0004001000100004,
                             0x0004000400100010, 0x0004001000100004};
  __m256i_out = __lasx_xvclz_h((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010001, 0x0000000000000000,
                      0x0001000100010001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000f0000000f, 0x0000002000000020,
                             0x0000000f0000000f, 0x0000002000000020};
  __m256i_out = __lasx_xvclz_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0045b8ae81bce1d8, 0x0000003868686a20,
                      0x0045b8ae81bce1d8, 0x0000003868686a20};
  __m256i_result = (__m256i){0x0000000900000000, 0x0000001a00000001,
                             0x0000000900000000, 0x0000001a00000001};
  __m256i_out = __lasx_xvclz_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000002000000020,
                             0x0000000000000000, 0x0000002000000020};
  __m256i_out = __lasx_xvclz_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000007f, 0x0000000000000002,
                      0x000000000000007f, 0x00000000000000fe};
  __m256i_result = (__m256i){0x0000002000000019, 0x000000200000001e,
                             0x0000002000000019, 0x0000002000000018};
  __m256i_out = __lasx_xvclz_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000002000000020, 0x0000002000000020,
                             0x0000002000000020, 0x0000002000000020};
  __m256i_out = __lasx_xvclz_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000002000000020, 0x0000002000000020,
                             0x0000002000000020, 0x0000002000000020};
  __m256i_out = __lasx_xvclz_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000002000000020, 0x0000002000000020,
                             0x0000002000000020, 0x0000002000000020};
  __m256i_out = __lasx_xvclz_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff0000ffff, 0x0000ffff0000ffff,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x0000001000000010, 0x0000001000000010,
                             0x0000001000000010, 0x0000001000000010};
  __m256i_out = __lasx_xvclz_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000002000000020, 0x0000002000000020,
                             0x0000002000000020, 0x0000002000000020};
  __m256i_out = __lasx_xvclz_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000002000000020, 0x0000002000000020,
                             0x0000002000000020, 0x0000002000000020};
  __m256i_out = __lasx_xvclz_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000002000000020, 0x0000002000000020,
                             0x0000002000000020, 0x0000002000000020};
  __m256i_out = __lasx_xvclz_w((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000040, 0x0000000000000040,
                             0x0000000000000040, 0x0000000000000040};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000040, 0x0000000000000040,
                             0x0000000000000040, 0x0000000000000040};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003fc00000428a, 0xffffc040ffffc09d,
                      0x00003fc00000428a, 0xffffc040ffffc09d};
  __m256i_result = (__m256i){0x0000000000000012, 0x0000000000000000,
                             0x0000000000000012, 0x0000000000000000};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000040, 0x0000000000000040,
                             0x0000000000000040, 0x0000000000000040};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0002ffff0000ff00, 0x0006ffff0004ffff,
                      0x0002ffff0000ff00, 0x0006ffff0004ffff};
  __m256i_result = (__m256i){0x000000000000000e, 0x000000000000000d,
                             0x000000000000000e, 0x000000000000000d};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000a800b000a800b, 0x0003800400038004,
                      0x000a800b000a800b, 0x0003800400038004};
  __m256i_result = (__m256i){0x000000000000000c, 0x000000000000000e,
                             0x000000000000000c, 0x000000000000000e};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ff88ff88, 0x8000000000000000,
                      0x00000000ff88ff88, 0x8000000000000000};
  __m256i_result = (__m256i){0x0000000000000020, 0x0000000000000000,
                             0x0000000000000020, 0x0000000000000000};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000007f8000, 0x0000000000000000,
                      0x00000000007f8000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000029, 0x0000000000000040,
                             0x0000000000000029, 0x0000000000000040};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000040, 0x0000000000000040,
                             0x0000000000000040, 0x0000000000000040};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0101010101010101, 0x0000000000000000,
                      0x0101010101010101, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000007, 0x0000000000000040,
                             0x0000000000000007, 0x0000000000000040};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000040, 0x0000000000000040,
                             0x0000000000000040, 0x0000000000000040};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000001010000, 0x0000000000000000,
                      0x0000000001010000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000027, 0x0000000000000040,
                             0x0000000000000027, 0x0000000000000040};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000040, 0x0000000000000040,
                             0x0000000000000040, 0x0000000000000040};
  __m256i_out = __lasx_xvclz_d((__m256)v4u64_op0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
