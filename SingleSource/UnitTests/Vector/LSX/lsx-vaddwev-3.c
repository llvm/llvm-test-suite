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

  v2u64_op0 = (v2u64){0x837cd5db43fc55d4, 0x0403cfcf01c1595e};
  v2u64_op1 = (v2u64){0x0404038383838404, 0x0404038383838404};
  __m128i_result = (__m128i){0x0080005e007f00d8, 0x0007005200440062};
  __m128i_out = __lsx_vaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000000000a0, 0xffffffffcafff8ff};
  v2u64_op1 = (v2u64){0xe5017c2ac9ca9fd0, 0xe6d4572c8a5835bc};
  __m128i_result = (__m128i){0x0001002affca0070, 0x00d3012b015700bb};
  __m128i_out = __lsx_vaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x00000fea0000fffe};
  v2u64_op1 = (v2u64){0x636363ec6363636c, 0x6363771163631745};
  __m128i_result = (__m128i){0x0063ffec0063006c, 0x006300fb00630143};
  __m128i_out = __lsx_vaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x000000000000ffff};
  __m128i_result = (__m128i){0x0000000000000000, 0x000000000000ffff};
  __m128i_out = __lsx_vaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x6363636363636363, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x9c9c9c9c9c9c9c9d, 0x0000000000000000};
  __m128i_result = (__m128i){0xffffffffffff0000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00008080ffffffff, 0x8080ffffffff8080};
  __m128i_result = (__m128i){0x0000ff80ffffffff, 0xff80ffffffffff80};
  __m128i_out = __lsx_vaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x01009aa4a301084b, 0x00197f26cb658837};
  v2u64_op1 = (v2u64){0x001effae001effae, 0x001effae001effae};
  __m128i_result = (__m128i){0x001e0052001ffff9, 0x0037ffd40083ffe5};
  __m128i_out = __lsx_vaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff0000ffff0000, 0xffff00ffffff00ff};
  v2u64_op1 = (v2u64){0x0000090900000998, 0x0000f50000000900};
  __m128i_result = (__m128i){0x00ff000900ffff98, 0x00ff00ff00ff00ff};
  __m128i_out = __lsx_vaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ff800000, 0x10f881a20ffd02b0};
  __m128i_result = (__m128i){0x00000000ff800000, 0xfff8ffa2fffdffb0};
  __m128i_out = __lsx_vaddwev_h_bu_b((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x7fff7fff7fff7fff};
  __m128i_result = (__m128i){0x0000000000000000, 0x00007fff00007fff};
  __m128i_out = __lsx_vaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x000000000000007b};
  __m128i_result = (__m128i){0x0000000000000001, 0x000000000000007b};
  __m128i_out = __lsx_vaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x1e0200001e020000};
  v2u64_op1 = (v2u64){0xfffcfffdfffcfffd, 0xfffcfffcfffcfffd};
  __m128i_result = (__m128i){0xfffffffdfffffffd, 0xfffffffcfffffffd};
  __m128i_out = __lsx_vaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xff00ff00ff00ff00, 0xff00ff00ff00ff00};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000ff000000ff00, 0x0000ff000000ff00};
  __m128i_out = __lsx_vaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000005, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000005, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0101010101010101, 0x0101010101010101};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000010100000101, 0x0000010100000101};
  __m128i_out = __lsx_vaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000400000004, 0x0000000400000004};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000400000004, 0x0000000400000004};
  __m128i_out = __lsx_vaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xa2f54a1ea2f54a1e, 0x8000000080000008};
  __m128i_result = (__m128i){0x00004a1e00004a1e, 0x0000000000000008};
  __m128i_out = __lsx_vaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000868686868686, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000000000ff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000868600008785, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x41f8e880ffffffff, 0x63636b6afe486741};
  v2u64_op1 = (v2u64){0x41f8e08016161198, 0xe363636363abdf16};
  __m128i_result = (__m128i){0x0000c90000011197, 0x0000cecd00004657};
  __m128i_out = __lsx_vaddwev_w_hu_h((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000fff1000ffffe, 0x00000001000f000e};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000000ffffe, 0x00000000000f000e};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x3430af9effffffff, 0x0c07e181ffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffffffff, 0x00000000ffffffff};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000fe00ff, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000fe00ff, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000049ffffffaa, 0x00060012000e002b};
  __m128i_result = (__m128i){0xffffffffffffffaa, 0x00000000000e002b};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000958affff995d, 0x0000006f00001f0a};
  v2u64_op1 = (v2u64){0x0000bfffffffe0f6, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000000ffff7a53, 0x0000000000001f0a};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffff7f80ffff7f80, 0xffff7f80ffff7f80};
  v2u64_op1 = (v2u64){0xffff7f80ffff7f80, 0xffff7f80ffff7f80};
  __m128i_result = (__m128i){0x00000000fffeff00, 0x00000000fffeff00};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0008000000000000};
  v2u64_op1 = (v2u64){0x00000000003dffc2, 0x00000000003dffc2};
  __m128i_result = (__m128i){0x00000000003dffc2, 0x00000000003dffc2};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0080006b0000000b, 0x0080008000800080};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x000000000000000b, 0x0000000000800080};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  __m128i_result = (__m128i){0x0000000000ff00ff, 0x0000000000ff00ff};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000455555555, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000055555555, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x000400530050ffa6, 0xff7f810100001000};
  v2u64_op1 = (v2u64){0x000400530050ffa6, 0xffff007fff810001};
  __m128i_result = (__m128i){0x0000000000a1ff4c, 0xffffffffff811001};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000001f0000001f, 0x0000002000000020};
  v2u64_op1 = (v2u64){0x7fffffff7fffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x000000008000001e, 0x000000000000001f};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xf9796558e39953fd, 0xd3259a2984048c23};
  v2u64_op1 = (v2u64){0x9611c3985b3159f5, 0x86dd8341b164f12b};
  __m128i_result = (__m128i){0x000000013ecaadf2, 0x0000000035697d4e};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00ff00ff00ff010f, 0x00ff00ef00ff010f};
  v2u64_op1 = (v2u64){0xc1f03e1042208410, 0x0001000100010001};
  __m128i_result = (__m128i){0x00000000431f851f, 0x0000000001000110};
  __m128i_out = __lsx_vaddwev_d_wu_w((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x000000030000003f, 0x7fff7fff7fff7fff};
  __m128i_result = (__m128i){0x000000030000003f, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xfffffffffffffffe};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0xffffffbfffffffbf, 0xffffffbfffffffbf};
  __m128i_result = (__m128i){0xffffffbfffffffbe, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8312f5424ca4a07f, 0x06b1213ef1efa299};
  v2u64_op1 = (v2u64){0x1f1f1f27332b9f00, 0x1f1f1f1f1f1f1f00};
  __m128i_result = (__m128i){0xa23214697fd03f7f, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x7fffffff80000000, 0x80000000ffffd860};
  __m128i_result = (__m128i){0x7fffffff80000000, 0x0000000000000000};
  __m128i_out = __lsx_vaddwev_q_du_d((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
