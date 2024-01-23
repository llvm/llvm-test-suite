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
  v2u64_op1 = (v2u64){0x203e16d116de012b, 0x10f917d72d3d01e4};
  __m128i_result = (__m128i){0x203e16d116de012b, 0x10f917d72d3d01e4};
  __m128i_out = __lsx_vsadd_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fff7ffe7fff3506, 0xfffebd06fffe820c};
  v2u64_op1 = (v2u64){0x7fff7ffe7fff3506, 0xfffebd06fffe820c};
  __m128i_result = (__m128i){0xfefffefffeff6a0c, 0xffffff0cffffff18};
  __m128i_out = __lsx_vsadd_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x4f804f804f804f80, 0x4f804f804f804f80};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vsadd_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xfffff790a15db63d, 0xfffff60ca7104649};
  v2u64_op1 = (v2u64){0x0000000000000001, 0x0000000000000001};
  __m128i_result = (__m128i){0xfffff790a15db63e, 0xfffff60ca710464a};
  __m128i_out = __lsx_vsadd_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0xffffffffffffff46, 0xfffffffffffffffe};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vsadd_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fff7fff7fff7fff, 0x00fe000100cf005f};
  v2u64_op1 = (v2u64){0x7fff7fff7fff7fff, 0x5f675e96e29a5a60};
  __m128i_result = (__m128i){0xfefffefffefffeff, 0x5fff5e97e2ff5abf};
  __m128i_out = __lsx_vsadd_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000001000100010};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0001000100010058};
  __m128i_result = (__m128i){0x0000000000000000, 0x0001001100110068};
  __m128i_out = __lsx_vsadd_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x7fffffff7fffffff, 0x7fffffff7fffffff};
  v2u64_op1 = (v2u64){0x7fffffff81010102, 0x7fff010181010102};
  __m128i_result = (__m128i){0xfeffffffffffffff, 0xfeffffffffffffff};
  __m128i_out = __lsx_vsadd_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00012c8a0000a58a, 0x0000ebd20000714f};
  v2u64_op1 = (v2u64){0x0000000d48eaa1a2, 0xffffffffb81a6f70};
  __m128i_result = (__m128i){0x00012c9748eaffff, 0xffffffffb81ae0bf};
  __m128i_out = __lsx_vsadd_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000011ff8bc, 0x0177fff0fffffff0};
  v2u64_op1 = (v2u64){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0xffffffffffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vsadd_bu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000200, 0x0000000000000200};
  __m128i_result = (__m128i){0x0000000000000200, 0x0000000000000200};
  __m128i_out = __lsx_vsadd_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000001, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000001, 0xffffffffffffffff};
  __m128i_out = __lsx_vsadd_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000d0000000d, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x8002000000000007, 0x8006000000040000};
  __m128i_result = (__m128i){0x8002000d00000014, 0x8006000000040000};
  __m128i_out = __lsx_vsadd_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000014, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000014, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x0000000000000000, 0xffffffffffffffff};
  __m128i_out = __lsx_vsadd_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x0000000000000000, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000008ffffa209, 0x0000000600007fff};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x00000008ffffa209, 0x0000000600007fff};
  __m128i_out = __lsx_vsadd_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x41f8e080f1ef4eaa, 0x636363633f3e47c1};
  v2u64_op1 = (v2u64){0x00000800ecedee68, 0x00000807bf0a1f80};
  __m128i_result = (__m128i){0x41f8e880ffffffff, 0x63636b6afe486741};
  __m128i_out = __lsx_vsadd_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00012c8a0000a58a, 0x0000ebd20000714f};
  v2u64_op1 = (v2u64){0x00012c8a0000a58a, 0x0000ebd20000714f};
  __m128i_result = (__m128i){0x000259140000ffff, 0x0000ffff0000e29e};
  __m128i_out = __lsx_vsadd_hu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xfffffffeffffffff, 0x0000000000000000};
  __m128i_result = (__m128i){0xfffffffeffffffff, 0x0000000000000000};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x342caf9be55700b5, 0x0c03e17edd781b11};
  v2u64_op1 = (v2u64){0x00040003ff4dffca, 0x00040003ff83ff84};
  __m128i_result = (__m128i){0x3430af9effffffff, 0x0c07e181ffffffff};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000ffffffabff99, 0x00000000ffa8ff9f};
  v2u64_op1 = (v2u64){0x0001000000020001, 0x000100000002007d};
  __m128i_result = (__m128i){0x0001ffffffadff9a, 0x00010000ffab001c};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x0800080008000800, 0x0800080008000800};
  __m128i_result = (__m128i){0x0800080008000800, 0x0800080008000800};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x76f424887fffffff, 0x0000000000000001};
  v2u64_op1 = (v2u64){0xc00d060000000000, 0xc110000000000000};
  __m128i_result = (__m128i){0xffffffff7fffffff, 0xc110000000000001};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000029, 0x000000000000002f};
  v2u64_op1 = (v2u64){0xfbfb47fbfbfb0404, 0xfbfbfb17fbfb38ea};
  __m128i_result = (__m128i){0xfbfb47fbfbfb042d, 0xfbfbfb17fbfb3919};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x8080808080808081, 0x0000000000000000};
  v2u64_op1 = (v2u64){0x00000000ffffffff, 0xffffffffffffffff};
  __m128i_result = (__m128i){0x80808080ffffffff, 0xffffffffffffffff};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0012001200120012, 0x00123fff00120012};
  v2u64_op1 = (v2u64){0x000000000005003a, 0x0000000000000000};
  __m128i_result = (__m128i){0x001200120017004c, 0x00123fff00120012};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xc5c534920000c4ed, 0xbfd10d0d7b6b6b73};
  __m128i_result = (__m128i){0xc5c534920000c4ed, 0xbfd10d0d7b6b6b73};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000000084d12ce, 0x000aa822a79308f6};
  v2u64_op1 = (v2u64){0x03aa558e1d37b5a1, 0x000aa822a79308f6};
  __m128i_result = (__m128i){0x03aa558e2584c86f, 0x00155044ffffffff};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x030298a6a1030a49, 0x021b7d24c9678a35};
  v2u64_op1 = (v2u64){0x0000000000000000, 0x0000000000000000};
  __m128i_result = (__m128i){0x030298a6a1030a49, 0x021b7d24c9678a35};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x00000485000004cc, 0x00007a8000000480};
  v2u64_op1 = (v2u64){0x00000485000004cc, 0x00007a8000000480};
  __m128i_result = (__m128i){0x0000090a00000998, 0x0000f50000000900};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  v2u64_op0 = (v2u64){0x0000000000000000, 0x0000000000000000};
  v2u64_op1 = (v2u64){0xff70002800be00a0, 0x004eff6200d2ff76};
  __m128i_result = (__m128i){0xff70002800be00a0, 0x004eff6200d2ff76};
  __m128i_out = __lsx_vsadd_wu((__m128)v2u64_op0, (__m128)v2u64_op1);
  check_lsx_out(&__m128i_result, &__m128i_out, sizeof(__m128i_out), __FILE__, __LINE__);

  return 0;
}
