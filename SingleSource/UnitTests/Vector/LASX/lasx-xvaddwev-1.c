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

  v4u64_op0 = (v4u64){0x98111cca98111cca, 0x98111cca98111cca,
                      0x98111cca98111cca, 0x98111cca98111cca};
  v4u64_op1 = (v4u64){0x61e0000000000001, 0xfffffffeffffff88,
                      0x61e0000000000001, 0xfffffffeffffff88};
  __m256i_result = (__m256i){0xfff1ffca0011ffcb, 0x0010ffc80010ff52,
                             0xfff1ffca0011ffcb, 0x0010ffc80010ff52};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffe90ffffff80, 0x0000000000000000,
                      0xfffffe90ffffff80, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffff90ffffff80, 0x0000000000000000,
                             0xffffff90ffffff80, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000005, 0x0000000000000000,
                      0x0000000000000005, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000005, 0x0000000000000000,
                             0x0000000000000005, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xfffefffefffefffe, 0xfffefffefffefffe,
                             0xfffefffefffefffe, 0xfffefffefffefffe};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000023, 0x0000000000000000,
                      0x0000000000000023, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000023, 0x0000000000000000,
                             0x0000000000000023, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x01c601c6fe3afe3a,
                      0x0000000000000000, 0x01c601c6fe3afe3a};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffc6ffc6003a003a,
                             0xffffffffffffffff, 0xffc6ffc6003a003a};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000008, 0x0000000000000000,
                      0x0000000000000008, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000009, 0x0000000000000009,
                      0x0000000000000009, 0x0000000000000009};
  __m256i_result = (__m256i){0x0000000000000011, 0x0000000000000009,
                             0x0000000000000011, 0x0000000000000009};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x457db03e45a87310, 0x457db03e457db03e,
                      0x457db03e45a87310, 0x457db03e457db03e};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x007d003effa80010, 0x007d003e007d003e,
                             0x007d003effa80010, 0x007d003e007d003e};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffff00000000, 0xffffffffffffffff,
                      0xffffffff00000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffff00000000, 0xffffffffffffffff,
                             0xffffffff00000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x386000003df80000,
                      0x0000000000000000, 0x386000003df80000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0c6a240000000000,
                      0x0000000000000000, 0x0c6a240000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00ca0000fff80000,
                             0x0000000000000000, 0x00ca0000fff80000};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_h_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0d8264202b8ea3f0, 0x31730b5beb7c99f5,
                      0x5464fbfc416b9f71, 0x372e9d75e8aab100};
  v4u64_op1 = (v4u64){0xe072db2bb9d4cd40, 0x26aa68b274dc1322,
                      0x84bd087966d4ace0, 0x80c72fcd40fb3bc0};
  __m256i_result = (__m256i){0x00003f4bffff7130, 0x0000740dffffad17,
                             0x00000475ffff4c51, 0xffffcd42ffffecc0};
  __m256i_out = __lasx_xvaddwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000f3280000dfff, 0xffffffff0000ffff,
                      0x0000468600007f79, 0x0000ffff0000ff80};
  v4u64_op1 = (v4u64){0x0000000000000022, 0x0000000000000000,
                      0x00000000000000ff, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffff328ffffe021, 0xffffffffffffffff,
                             0x0000468600008078, 0xffffffffffffff80};
  __m256i_out = __lasx_xvaddwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x98111cca98111cca, 0x98111cca98111cca,
                      0x98111cca98111cca, 0x98111cca98111cca};
  v4u64_op1 = (v4u64){0x98111cca98111cca, 0x98111cca98111cca,
                      0x98111cca98111cca, 0x98111cca98111cca};
  __m256i_result = (__m256i){0x0000399400003994, 0x0000399400003994,
                             0x0000399400003994, 0x0000399400003994};
  __m256i_out = __lasx_xvaddwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xe161616161614f61, 0xe161616161614f61,
                      0xe161616161614f61, 0xe161616161614f61};
  __m256i_result = (__m256i){0x0000616100004f61, 0x0000616100004f61,
                             0x0000616100004f61, 0x0000616100004f61};
  __m256i_out = __lasx_xvaddwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0x000000000000ffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000000000000,
                             0x00000000ffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x000b8f81b8c840e4, 0x000050504c4c2362,
                      0x000b8f81b8c840e4, 0x000050504c4c2362};
  __m256i_result = (__m256i){0xffff8f81000040e4, 0x0000504f00002361,
                             0xffff8f81000040e4, 0x0000504f00002361};
  __m256i_out = __lasx_xvaddwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000009, 0x0000000000000009,
                      0x0000000000000009, 0x0000000000000009};
  v4u64_op1 = (v4u64){0x0000000000000009, 0x0000000000000009,
                      0x0000000000000009, 0x0000000000000009};
  __m256i_result = (__m256i){0x0000000000000012, 0x0000000000000012,
                             0x0000000000000012, 0x0000000000000012};
  __m256i_out = __lasx_xvaddwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000165a, 0x0000ffff0000ffa3,
                      0x000000000000165a, 0x0000ffff0000ffa3};
  v4u64_op1 = (v4u64){0x7fff7fff5d425d42, 0x40b240b330313031,
                      0x7fff7fff5d425d42, 0x40b240b330313031};
  __m256i_result = (__m256i){0x00007fff0000739c, 0x000040b200002fd4,
                             0x00007fff0000739c, 0x000040b200002fd4};
  __m256i_out = __lasx_xvaddwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00003ff000003ff0, 0x00003fef00003fea,
                      0x00003ff000003ff0, 0x00003fef00003fea};
  v4u64_op1 = (v4u64){0x00003ff000003ff0, 0x00003fef00003fea,
                      0x00003ff000003ff0, 0x00003fef00003fea};
  __m256i_result = (__m256i){0x00007fe000007fe0, 0x00007fde00007fd4,
                             0x00007fe000007fe0, 0x00007fde00007fd4};
  __m256i_out = __lasx_xvaddwev_w_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000100000000,
                      0x0000000000000000, 0x0000000100000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000002e2100, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000001000010, 0x0000000000000001,
                      0x0000000000000001, 0x0000000000000001};
  __m256i_result = (__m256i){0x00000000012e2110, 0x0000000000000001,
                             0x0000000000000002, 0x0000000000000001};
  __m256i_out = __lasx_xvaddwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0010000000100000, 0x0010000000100000,
                      0x0010000000100000, 0x0010000000100000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000483800,
                      0x0000000000000000, 0x0000000000483800};
  __m256i_result = (__m256i){0x0000000000100000, 0x0000000000583800,
                             0x0000000000100000, 0x0000000000583800};
  __m256i_out = __lasx_xvaddwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7bbbbbbbf7777778, 0x0000000044444443,
                      0x7bbbbbbbf7777778, 0x0000000044444443};
  v4u64_op1 = (v4u64){0x000000007bbbbbbb, 0x0000000000000000,
                      0x000000007bbbbbbb, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000073333333, 0x0000000044444443,
                             0x0000000073333333, 0x0000000044444443};
  __m256i_out = __lasx_xvaddwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000010000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000010000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007f807f007e806f, 0x007f807f007e8080,
                      0x007f807f007e806f, 0x007f807f007e8080};
  v4u64_op1 = (v4u64){0x0000000000000023, 0x0000000000000000,
                      0x0000000000000023, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000007e8092, 0x00000000007e8080,
                             0x00000000007e8092, 0x00000000007e8080};
  __m256i_out = __lasx_xvaddwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x00000000000062d4, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000064, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000006338, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0010000100000000, 0x0010000100000000,
                      0x0010000100000000, 0x0010000100000000};
  v4u64_op1 = (v4u64){0xffff800080000000, 0xffff800000000000,
                      0xffff800080000000, 0xffff800000000000};
  __m256i_result = (__m256i){0xffffffff80000000, 0x0000000000000000,
                             0xffffffff80000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000003fc03bbc, 0xfe01fe01fc01fc01,
                      0x000000003fc03bbc, 0xfe01fe01fc01fc01};
  __m256i_result = (__m256i){0x000000003fc03bbc, 0xfffffffffc01fc01,
                             0x000000003fc03bbc, 0xfffffffffc01fc01};
  __m256i_out = __lasx_xvaddwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fffffffffffffff, 0x7fffffffffffffff,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xe5fb66c81da8e5bb, 0x18b988e64facb558,
                      0xe37affb42fc05f69, 0x1b9763952fc4c101};
  __m256i_result = (__m256i){0x65fb66c81da8e5ba, 0x0000000000000000,
                             0xe37affb42fc05f69, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x00000000ffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x1111111111111113, 0x1010101010101093,
                      0x1010101010101012, 0x1010101010101012};
  __m256i_result = (__m256i){0x1111111211111112, 0x0000000000000000,
                             0x1010101110101011, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x5980000000000000, 0x0000000000000000,
                      0x5980000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x5980000000000000, 0x0000000000000000,
                             0x5980000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffefe00000000, 0xffffffffffffffff,
                      0xfffffefefffffefe, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xfffffefe00000000, 0xffffffffffffffff,
                             0xfffffefefffffefe, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000002800000010, 0x0000000000000000,
                      0x0000002800000010, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00ff00ff00040000, 0x00ff00ff00ff00ff,
                      0x00ff00ff000c0000, 0x00ff00ff00ff00ff};
  __m256i_result = (__m256i){0x00ff012700040010, 0x0000000000000000,
                             0x00ff0127000c0010, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc0008000c0008000, 0x0000000000000000,
                      0xc0008000c0008000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xc0008000c0008000, 0x0000000000000000,
                      0xc0008000c0008000, 0x0000000000000000};
  __m256i_result = (__m256i){0x8001000180010000, 0xffffffffffffffff,
                             0x8001000180010000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000200000002, 0x0000000200000002,
                      0x0000000200000002, 0x0000000200000002};
  v4u64_op1 = (v4u64){0xffff800000000000, 0xffff800000000000,
                      0xffff800000000000, 0xffff800000000000};
  __m256i_result = (__m256i){0xffff800200000002, 0xffffffffffffffff,
                             0xffff800200000002, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000020000000200, 0x0000020000000200,
                      0x0000020000000200, 0x0000020000000200};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000020000000200, 0x0000000000000000,
                             0x0000020000000200, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffe97c020010001, 0xfffeb6839ffffd80,
                      0xfffe97c020010001, 0xfffeb6839ffffd80};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffe97c020010001, 0xffffffffffffffff,
                             0xfffe97c020010001, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x000001e001e001e0,
                      0x0000000000000000, 0x000001e001e001e0};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
