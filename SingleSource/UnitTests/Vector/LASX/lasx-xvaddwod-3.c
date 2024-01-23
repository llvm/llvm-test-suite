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

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwod_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000002e2100, 0x0000000000000000,
                      0x0000000033e87ef1, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000021, 0x0000000000000000,
                             0x000000000033007e, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x2020202020202020, 0x2020202020202020,
                      0x2020202020202020, 0x2020202020202020};
  v4u64_op1 = (v4u64){0x0000000020202020, 0x0000000020202020,
                      0x0000000020202020, 0x0000000020202020};
  __m256i_result = (__m256i){0x0020002000400040, 0x0020002000400040,
                             0x0020002000400040, 0x0020002000400040};
  __m256i_out = __lasx_xvaddwod_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000f000000000000, 0x0000000000000000,
                      0x000f000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x007fc0083fc7c007, 0x0000000000000000,
                      0x007fc0083fc7c007, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffc0003fffc0, 0x0000000000000000,
                             0x0000ffc0003fffc0, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffb8579f, 0x00000000ffdbbbcf,
                      0x00000000ffb8579f, 0x00000000ffdbbbcf};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000ff0057, 0x0000000000ff00bb,
                             0x0000000000ff0057, 0x0000000000ff00bb};
  __m256i_out = __lasx_xvaddwod_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                             0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  __m256i_out = __lasx_xvaddwod_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000073737, 0x0000000000000000,
                      0x0000000005060503, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000200, 0x0000000000000200,
                      0x0000000000000200, 0x0000000000000200};
  __m256i_result = (__m256i){0x0000000000000039, 0x0000000000000002,
                             0x0000000000050007, 0x0000000000000002};
  __m256i_out = __lasx_xvaddwod_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000f3280000dfff, 0x0000ffff0000ffff,
                      0x0000468600007f79, 0x0000ffff0000ff80};
  v4u64_op1 = (v4u64){0x0703020000000000, 0x0000000000020100,
                      0x0102040000000000, 0x0000000007070707};
  __m256i_result = (__m256i){0x0000070300000000, 0x0000000000000002,
                             0x0000010200000000, 0x0000000000000707};
  __m256i_out = __lasx_xvaddwod_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x7fffffffffffffff,
                      0x0000000000000000, 0x7fffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x00007fffffffffff,
                             0x0000000000000000, 0x00007fffffffffff};
  __m256i_out = __lasx_xvaddwod_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8000000000000000, 0x8000000000000000,
                      0x8000000000000000, 0x8000000000000000};
  __m256i_result = (__m256i){0xffff800000000000, 0xffff800000000000,
                             0xffff800000000000, 0xffff800000000000};
  __m256i_out = __lasx_xvaddwod_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7c007c007c007c00, 0x7c007c007c007c00,
                      0x7c007c007c007c00, 0x7c007c007c007c00};
  v4u64_op1 = (v4u64){0x000100640000ff92, 0x0001000000010000,
                      0x000100640000ff92, 0x0001000000010000};
  __m256i_result = (__m256i){0x00007c0100007c00, 0x00007c0100007c01,
                             0x00007c0100007c00, 0x00007c0100007c01};
  __m256i_out = __lasx_xvaddwod_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfe00000000000000, 0x0000000001ffffff,
                      0xfe00000000000000, 0x0000000001ffffff};
  __m256i_result = (__m256i){0xfffffe0000000000, 0x00000000000001ff,
                             0xfffffe0000000000, 0x00000000000001ff};
  __m256i_out = __lasx_xvaddwod_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000ffff0000ffff, 0x0000ffffffffffff,
                      0x0000ffff0000ffff, 0x0000ffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000ffffffff,
                             0x0000000000000000, 0x00000000ffffffff};
  __m256i_out = __lasx_xvaddwod_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwod_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000007d, 0x0000000000000048,
                      0x000000000000007d, 0x0000000000000048};
  v4u64_op1 = (v4u64){0x000800400010006d, 0x0000000000000000,
                      0x000800400010006d, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000800000010, 0x0000000000000000,
                             0x0000000800000010, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffe97c020010001, 0xfffeb6839ffffd80,
                      0xfffe97c020010001, 0xfffeb6839ffffd80};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000fffe00002001, 0x0000fffe00009fff,
                             0x0000fffe00002001, 0x0000fffe00009fff};
  __m256i_out = __lasx_xvaddwod_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000027, 0x0000000000000040,
                      0x0000000000000027, 0x0000000000000040};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0001000100010080, 0x0000000000000000,
                      0x0001000100010080, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwod_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x07fffc670800f086, 0xffffd84900000849,
                      0x7fff7ffe7fffeffe, 0x0000000000007f00};
  v4u64_op1 = (v4u64){0x344ade20fe00fd01, 0x311d9b643ec1fe01,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x311d73ad3ec2064a, 0x0000000000000001,
                             0x0000000000007f00, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000700000002, 0xffffffa4fffffffd,
                      0x0000081500000104, 0xffff80cbfffffdf8};
  __m256i_result = (__m256i){0xffffffa4fffffffd, 0xffffffffffffffff,
                             0xffff80cbfffffdf8, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwod_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0100000100000001, 0x0000000008050501,
                      0x0100000100000001, 0x0000000008050501};
  __m256i_result = (__m256i){0x0000000008050501, 0x0000000000000000,
                             0x0000000008050501, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x019d00a2003a0000, 0x01fe007a01c40110,
                      0x019d00a20039fff9, 0x01fe007a01c40110};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x000000000003ffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x01fe007a01c40110, 0x0000000000000000,
                             0x01fe007a01c40110, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x001ffffe00200000, 0x0000000000000000,
                      0x001ffffe00200000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffff0020001d001f,
                      0x0000000000000000, 0xffff0020001d001f};
  __m256i_result = (__m256i){0xffff0020001d001f, 0xffffffffffffffff,
                             0xffff0020001d001f, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwod_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000000fef0ff0, 0x0000000000000000,
                      0x000000000fef0ff0, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000800080008000, 0x0000000000000000,
                      0x8000800080008000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8000000080ff0080, 0x8000400080ffc080,
                      0x8000000080ff0080, 0x8000400080ffc080};
  __m256i_result = (__m256i){0x8000400080ffc080, 0xffffffffffffffff,
                             0x8000400080ffc080, 0xffffffffffffffff};
  __m256i_out = __lasx_xvaddwod_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8000000000000000, 0x0000000000000000,
                      0x8000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x007f010000000100, 0x0000000000000000,
                      0x007f010000000100, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwod_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
