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
  v4u64_op1 = (v4u64){0xbf28b0686066be60, 0xffffffff0000ffff,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x40d74f979f99419f, 0x00000000ffff0000,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffefffffefc, 0xfffffffffffffffe};
  v4u64_op1 = (v4u64){0x00000000ffdcff64, 0x0000000000000000,
                      0x01480000052801a2, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xfffffffffffffefd, 0xffffffffffffffff};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0002555500000000, 0x0006000000040000,
                      0x0002555500000000, 0x0006000000040000};
  __m256i_result = (__m256i){0xfffdaaaaffffffff, 0xfff9fffffffbffff,
                             0xfffdaaaaffffffff, 0xfff9fffffffbffff};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000022, 0x0000000000000000,
                      0x0000000000000022, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000175e0000490d, 0x0000236200005111,
                      0x0000175e0000490d, 0x0000236200005111};
  v4u64_op1 = (v4u64){0x00220021004a007e, 0x0002000000020000,
                      0x00220021004a007e, 0x0002000000020000};
  __m256i_result = (__m256i){0xffddffdeffb5ff8d, 0xfffdfffffffdffff,
                             0xffddffdeffb5ff8d, 0xfffdfffffffdffff};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000040, 0x0000000000000000,
                      0x0000000000000040, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x01fe01ae00ff00ff, 0x00ff010000ff017e,
                      0x01fe01ae00ff00ff, 0x00ff010000ff017e};
  __m256i_result = (__m256i){0xfe01fe51ff00ff40, 0xff00feffff00fe81,
                             0xfe01fe51ff00ff40, 0xff00feffff00fe81};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffe0df9f8e, 0xffffffffffffffff,
                      0xffffffffe0df9f8e, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xe07de0801f20607a, 0xffffffffffffffff,
                      0xe07de0801f20607a, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffe0df9f8f, 0xffffffffffffffff,
                             0xffffffffe0df9f8f, 0xffffffffffffffff};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x800000ff800000ff, 0x8000800080008000,
                      0x800000ff800000ff, 0x8000800080008000};
  v4u64_op1 = (v4u64){0x8000800080008000, 0x0000000000000000,
                      0x8000800080008000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffff7fffffff7fff, 0xffffffffffffffff,
                             0xffff7fffffff7fff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000001, 0x0000000000000000,
                      0x0000000000000001, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000000,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x8080808080808080, 0xffffffffdf80dfff,
                      0x8080808080808080, 0xdf80df80df80dfff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x4981008168410001, 0x498100814843ffe1,
                      0x4981008168410001, 0x498100814843ffe1};
  v4u64_op1 = (v4u64){0x7ff8000000000000, 0x40f69fe73c26f4ee,
                      0x7ff8000000000000, 0x40f69fe73c26f4ee};
  __m256i_result = (__m256i){0xc987ffffffffffff, 0xff896099cbdbfff1,
                             0xc987ffffffffffff, 0xff896099cbdbfff1};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffdf5b000041b0, 0xfffffffeffff97a1,
                      0xffffdf5b000041b0, 0xfffffffeffff97a1};
  __m256i_result = (__m256i){0x000020a4ffffbe4f, 0x000000010000685e,
                             0x000020a4ffffbe4f, 0x000000010000685e};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000070002000a, 0x0000000600000006,
                      0x000000070002000a, 0x0000000600000006};
  v4u64_op1 = (v4u64){0x0000000000000007, 0x0040000000000003,
                      0x0000000000000007, 0x0040000000000003};
  __m256i_result = (__m256i){0xfffffffffffffffa, 0xffbffffffffffffe,
                             0xfffffffffffffffa, 0xffbffffffffffffe};
  __m256i_out = __lasx_xvorn_v((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
