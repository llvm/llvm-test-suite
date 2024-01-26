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
  v4u64_op1 = (v4u64){0x8000000080000000, 0x0000000000000000,
                      0x8000000080000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ff00ff00, 0x0000000000000000,
                             0x00000000ff00ff00, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000001900000019, 0x0000001900000019,
                      0x0000001900000019, 0x0000001900000019};
  v4u64_op1 = (v4u64){0x0000000000007fff, 0x7fffffff7fffffff,
                      0x0000000000007fff, 0x7fffffff7fffffff};
  __m256i_result = (__m256i){0x0408040800000004, 0x0000000000000000,
                             0x0408040800000004, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xff80000000000000, 0xfe7fffecfe7fffec,
                      0xff800000ff800000, 0xfe7fffecfe7fffec};
  __m256i_result = (__m256i){0x0808080808000000, 0x0000000000000000,
                             0x0808080808000800, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xd);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0020002000200020,
                      0x0020000000200000, 0x0020002000200020};
  v4u64_op1 = (v4u64){0x000000000000ffff, 0x000000000000ffff,
                      0x000000000000ffff, 0x000000000000ffff};
  __m256i_result = (__m256i){0x000000ff000000ff, 0x1010101000000000,
                             0x000000ff000000ff, 0x1010101010001000};
  __m256i_out = __lasx_xvssrlrni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000010001, 0x0000000000000465,
                      0x0000000000010001, 0x0000000000000465};
  __m256i_result = (__m256i){0x0000008d00000000, 0x0000000000000000,
                             0x0000008d00000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000e0000000e, 0x0000000e0000000e,
                      0x0000000e0000000e, 0x0000000e0000000e};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0007000700070007,
                             0x00000000ffffffff, 0x0007000700070007};
  __m256i_out = __lasx_xvssrlrni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000008002d, 0x0000000000000000,
                      0x000000000008002d, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x00000000007f0000,
                      0x0000000000000000, 0x00000000007f0000};
  __m256i_result = (__m256i){0x0000010000000000, 0x0000000000000000,
                             0x0000010000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000008000000001, 0x00ff00ff00c00040,
                      0x0000008000000001, 0x00ff00ff00c00040};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_bu_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xf);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xbc20e63aa8b9663f, 0xbc30c40108a4544b,
                      0xbc263e0e5d00e69f, 0xbc30c40108a45423};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x17);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_hu_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x19);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x29d403af367b4545, 0xa432ea5a0913dc8e,
                      0xddf50db3c617a115, 0x3133c6409eecf8b0};
  v4u64_op1 = (v4u64){0x683b8b67e20c8ee5, 0xf41a56e8a20878d7,
                      0x5f6108dc25b8e028, 0x38a966b31be83ee9};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffed95be394b1e, 0x988eb37e000fb33d,
                      0xffffffffe06df0d7, 0x7ffffffffffff7ff};
  v4u64_op1 = (v4u64){0x800080008000b8f1, 0x8000800080008000,
                      0x06f880008000ffff, 0x8000ffff8000ffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x10);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000040100000, 0x0000000040100000,
                      0x0000000040100000, 0x0000000040100000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0080200000802000,
                             0xffffffffffffffff, 0x0080200000802000};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x005c0003fff9ffff, 0x00000000003fffc1,
                      0x7f350104f7ebffff, 0x0000000020afefb1};
  __m256i_result = (__m256i){0x00000000000b8000, 0x2000000020000000,
                             0x000000000fe6a021, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x23);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x25);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0400040004000400, 0x0400040004000400,
                      0x0400040004000400, 0x0400040004000400};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000008000000080,
                             0x0000000000000000, 0x0000008000000080};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x33);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0020000000200000, 0x0000000000000000,
                             0x0020000000200000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2d);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfff10000fff10000, 0x0000000000000000,
                      0xfff10000fff10000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  __m256i_result = (__m256i){0x001fe020001fe020, 0x000000001ffe2000,
                             0x001fe020001fe020, 0x000000001ffe2000};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x23);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x15);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0002000200000000, 0x0000000000000000,
                      0x0002000200000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000020002000,
                             0xffffffffffffffff, 0x0000000020002000};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x14);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffff010100000001, 0xffffffffffffffff,
                      0xffff010100000001, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000008000000080, 0x0000000000000000,
                             0x0000008000000080, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_wu_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x39);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000808080, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000808, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000100000,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrlrni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x2c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrlrni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x29);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x07efefefefefefee, 0x07efefefefefefee,
                      0x07efefefefefefee, 0x07efefefefefefee};
  __m256i_result = (__m256i){0x0000000001fbfbfc, 0x0000000000000000,
                             0x0000000001fbfbfc, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x62);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000fe01020b0001, 0xffffffffffffffff,
                      0x0000fe01020b0001, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrlrni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x2020202020202020, 0x2020202020202020,
                      0x2020202020202020, 0x2020202020202020};
  v4u64_op1 = (v4u64){0x4040404040404040, 0x4040404040404040,
                      0x4040404040404040, 0x4040404040404040};
  __m256i_result = (__m256i){0x0000000000404040, 0x0000000000202020,
                             0x0000000000404040, 0x0000000000202020};
  __m256i_out = __lasx_xvssrlrni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x68);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x7fff800000000000,
                      0x0000000000000000, 0x7fff800000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvssrlrni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x27);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_du_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000020001, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xe);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000200000002, 0x0000000200000002,
                      0x0000000200000002, 0x0000000200000002};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00ff00ff00040000, 0x00ff00ff00ff00ff,
                      0x00ff00ff000c0000, 0x00ff00ff00ff00ff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x1010101010101010, 0x0000000010101010,
                             0x1010101010101010, 0x0000000010101010};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000fe, 0x0000000000000000,
                      0x00000000000000fe, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000008,
                             0x0000000000000000, 0x0000000000000008};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000001, 0x0000000000000001,
                      0x0000000000000001, 0x0000000000000001};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x5);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007f010100000101, 0x0000000100000001,
                      0x007f010100000101, 0x0000000100000001};
  v4u64_op1 = (v4u64){0x0000000000004000, 0x0000200000000000,
                      0x0000000000004000, 0x0000200000000000};
  __m256i_result = (__m256i){0x0008000000000010, 0x0000000000000000,
                             0x0008000000000010, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0xa);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff00000000, 0x0000000000000000,
                      0x0000ffff00000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000080040, 0x0000000000080040,
                      0x0000000000080040, 0x0000000000080040};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000007f0000,
                             0x0000000000000000, 0x00000000007f0000};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x07ffffff08000000, 0x0000000000000000,
                      0x07ffffff08000000, 0x07ffffff07ffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x7f7f7f7f7f7f7f7f, 0x00000000207f2000,
                             0x7f7f7f7f7f7f7f7f, 0x207f207f207f2000};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f,
                             0x7f7f7f7f7f7f7f7f, 0x7f7f7f7f7f7f7f7f};
  __m256i_out = __lasx_xvssrlrni_b_h((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x7f8000007f800000, 0x7f8000007f800000,
                      0x7f8000007f800000, 0x7f8000007f800000};
  __m256i_result = (__m256i){0x7fff7fff7fff7fff, 0x0000000000000000,
                             0x7fff7fff7fff7fff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x8);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x7fff7fff7fff7fff, 0x0000000000000000,
                             0x7fff7fff7fff7fff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x0);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000001fef010, 0x0000000002020000,
                      0x000000000201eff0, 0x0000000002020000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xfffefffefffefffd,
                      0x0000000000000000, 0xfffefffe00000000};
  __m256i_result = (__m256i){0x0010001000000000, 0x0000000000000000,
                             0x0010000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xfffefffefffefffd,
                      0x0000000000000000, 0xfffefffe00000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xfffefffefffefffd,
                      0x0000000000000000, 0xfffefffe00000000};
  __m256i_result = (__m256i){0x7fff7fff00000000, 0x7fff7fff00000000,
                             0x7fff000000000000, 0x7fff000000000000};
  __m256i_out = __lasx_xvssrlrni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x002a0074666a4db9, 0x0e0f1192846ff912,
                      0x002a0074666a4db9, 0x0e0f1192846ff912};
  v4u64_op1 = (v4u64){0x0000000100000018, 0x0000000000000000,
                      0x0000000100000018, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x7fff7fff05407fff,
                             0x0000000000000000, 0x7fff7fff05407fff};
  __m256i_out = __lasx_xvssrlrni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xb);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x003f003f003f003f,
                      0x0000000000000000, 0x003f003f003f003f};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0xc);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfefefefe3f800000, 0x0000000000000000,
                      0xfefefefe3f800000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000007fff7fff, 0x0000000000000000,
                             0x000000007fff7fff, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_h_w((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000f18080010000,
                      0x0000000000000000, 0x0000f18080010000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x28);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xd010101010103218, 0xd010101010101010,
                      0xd010101010103218, 0xd010101010101010};
  v4u64_op1 = (v4u64){0xd010101010103218, 0xd010101010101010,
                      0xd010101010103218, 0xd010101010101010};
  __m256i_result = (__m256i){0x7fffffff7fffffff, 0x7fffffff7fffffff,
                             0x7fffffff7fffffff, 0x7fffffff7fffffff};
  __m256i_out = __lasx_xvssrlrni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffe0000000000, 0x0000000001ff8000,
                      0xfffffe0000000000, 0x0000000001ff8000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000002,
                             0x0000000000000000, 0x0000000000000002};
  __m256i_out = __lasx_xvssrlrni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffffe00000000, 0xffffffffffffffff,
                      0xfffffffe00000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000080000000800, 0x0000000000000000,
                             0x0000080000000800, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x35);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000002000, 0x0000000000000000,
                      0x0000000000002000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x38);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000001000000010, 0x0000000000000000,
                             0x0000001000000010, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_w_d((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x7fffffffffffffff,
                             0x0000000000000000, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvssrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x9);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffefffffefc, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0x0000000000000010, 0x0000000000000000,
                             0x0000000000000010, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7c);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x000000000000ffff,
                      0x0000000000000000, 0x000000000000ffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0020000000000000, 0x0000000000000020,
                             0x0020000000000000, 0x0000000000000020};
  __m256i_out = __lasx_xvssrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x4b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000010486048c, 0x0000000000000000,
                      0x000000010486048c, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x6f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0504060904040305, 0x0504080804030405,
                      0x0504060904040305, 0x0504080804030405};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000141020,
                             0x0000000000000000, 0x0000000000141020};
  __m256i_out = __lasx_xvssrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x66);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000007fe70000, 0x0000ffff8000ffa3,
                      0x000000007fe70000, 0x0000ffff8000ffa3};
  v4u64_op1 = (v4u64){0xc600000000000000, 0xc03ae000ffff6000,
                      0xc600000000000000, 0xc03ae000ffff6000};
  __m256i_result = (__m256i){0x0000000000000003, 0x0000000000000000,
                             0x0000000000000003, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000000000000004, 0x0000000000000004,
                             0x0000000000000004, 0x0000000000000004};
  __m256i_out = __lasx_xvssrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x7e);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x1b);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x3f7f7f7f407fffff, 0xffffffffffffffff,
                      0x3f7f7f7f407fffff, 0x7fffffffffffbfff};
  v4u64_op1 = (v4u64){0x7efefefe80ffffff, 0x0000000000000000,
                      0x7efefefe80ffffff, 0xffffffffffff8000};
  __m256i_result = (__m256i){0x0000000000fdfdfe, 0x7fffffffffffffff,
                             0x7fffffffffffffff, 0x7fffffffffffffff};
  __m256i_out = __lasx_xvssrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x27);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffe97c08000ffff, 0xfffeb68380002001,
                      0xfffe97c08000ffff, 0xfffeb68380002001};
  v4u64_op1 = (v4u64){0xfffe97c020010001, 0xfffeb6839ffffd80,
                      0xfffe97c020010001, 0xfffeb6839ffffd80};
  __m256i_result = (__m256i){0x0000007fff5b41d0, 0x0000007fff5b41c0,
                             0x0000007fff5b41d0, 0x0000007fff5b41c0};
  __m256i_out = __lasx_xvssrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x59);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000ffff97a2, 0x0000000000000000,
                      0x00000000ffff97a2, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000001010000, 0x0000000000000000,
                      0x0000000001010000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvssrlrni_d_q((__m256)v4u64_op0, (__m256)v4u64_op1, 0x3f);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
