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

  v4u64_op0 = (v4u64){0x0003ffd00003fd38, 0x0000000000000000,
                      0x0003ff540000081c, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000228200001680, 0x0001ffe80001fe9c,
                      0x0000716800007bb6, 0x0001ffaa0000040e};
  v4u64_op2 = (v4u64){0x0658f2dc0eb21e3c, 0x31730b5beb7c99f5,
                      0xc5c085372cfabfba, 0x372e9d75e8aab100};
  __m256i_result = (__m256i){0x0003ed8800031b38, 0x00735278007cf94c,
                             0x000315ac0000d658, 0x002e4db200000000};
  __m256i_out = __lasx_xvmaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xff01ff01ff01ff01, 0xff01ff01ff01ff01,
                             0xff01ff01ff01ff01, 0xff01ff01ff01ff01};
  __m256i_out = __lasx_xvmaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000cfefd, 0x0000000000000000,
                      0xffffffff02a0fefc, 0xffffffff0001ff04};
  v4u64_op1 = (v4u64){0x5ff00007fff9fff3, 0x7ff0000000000000,
                      0x5ee1c073b800c916, 0x6100000800060005};
  v4u64_op2 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffefffffefc, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0xff10fff9ff13fd17, 0xff10000000000000,
                             0xff1eff1902a0fea4, 0xfffffff7fffbfefa};
  __m256i_out = __lasx_xvmaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000fefefe, 0xfefefefefefefefe,
                      0x0000000000000000, 0xfafafafafafafafa};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xff01ff01fffffdff, 0xfdfffdfffdfffdff,
                             0xff01ff01ff01ff01, 0xf9fbf9fbf9fbf9fb};
  __m256i_out = __lasx_xvmaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000003fff3fff, 0x3fff3fff3fff3fff,
                      0x000000003fff3fff, 0x3fff3fff3fff3fff};
  v4u64_op1 = (v4u64){0x0000000000000627, 0x0000000000000000,
                      0x0000000000000627, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x7fff7fff05407fff,
                      0x0000000000000000, 0x7fff7fff05407fff};
  __m256i_result = (__m256i){0x000000003fff3fff, 0x3fff3fff3fff3fff,
                             0x000000003fff3fff, 0x3fff3fff3fff3fff};
  __m256i_out = __lasx_xvmaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000400,
                      0x0000000000000000, 0x0000000000000400};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x003f003f003f003f,
                      0x0000000000000000, 0x003f003f003f003f};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffee, 0xffffffffffffffee,
                      0xffffffffffffffee, 0xffffffffffffffee};
  v4u64_op1 = (v4u64){0xffffffffffffffee, 0xffffffffffffffee,
                      0xffffffffffffffee, 0xffffffffffffffee};
  v4u64_op2 = (v4u64){0xffffffffffffffee, 0xffffffffffffffee,
                      0xffffffffffffffee, 0xffffffffffffffee};
  __m256i_result = (__m256i){0xff00ff00ff00ef32, 0xff00ff00ff00ef32,
                             0xff00ff00ff00ef32, 0xff00ff00ff00ef32};
  __m256i_out = __lasx_xvmaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1010101010101010, 0x0000000000000000,
                      0x1010101010101010, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000100000001, 0x0000000100000001,
                      0x0000000100000001, 0x0000000100000001};
  v4u64_op2 = (v4u64){0xfffffffffdd97dc4, 0xffffffffffff0001,
                      0xfffffffffdd97dc4, 0xffffffffffff0001};
  __m256i_result = (__m256i){0x1010100f10100fd4, 0x0000ffff00000001,
                             0x1010100f10100fd4, 0x0000ffff00000001};
  __m256i_out = __lasx_xvmaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xebebebebebebebeb, 0xebebebebebebebeb,
                      0xebebebebebebebeb, 0xebebebebebebebeb};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xebebebebebebebeb, 0xebebebebebebebeb,
                             0xebebebebebebebeb, 0xebebebebebebebeb};
  __m256i_out = __lasx_xvmaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000ffff0000,
                      0x0000000000000000, 0x00000000ffff0000};
  v4u64_op1 = (v4u64){0xffe0ffe000000000, 0x001f001fffffffff,
                      0xffe0ffe000000000, 0x001f001fffffffff};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x00000000ffff0000,
                             0x0000000000000000, 0x00000000ffff0000};
  __m256i_out = __lasx_xvmaddwev_h_bu_b((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0e0d5fde5df99830, 0xeaa81f47dc3bdd09,
                      0x4f111e4b8e0d7291, 0x34ec5670cd4b5ec0};
  v4u64_op1 = (v4u64){0x5a2003c6a406fe53, 0xee20ad1adae2cc16,
                      0xbacda0f96d2cec01, 0x67390c19e4b17547};
  v4u64_op2 = (v4u64){0xe072db2bb9d4cd40, 0x26aa68b274dc1322,
                      0x84bd087966d4ace0, 0x80c72fcd40fb3bc0};
  __m256i_result = (__m256i){0x0d8264202b8ea3f0, 0x31730b5beb7c99f5,
                             0x5464fbfc416b9f71, 0x372e9d75e8aab100};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffffffff00ff, 0x000000ff000000ff,
                      0xff000000ffffff00, 0x00ff0000ffff00ff};
  v4u64_op1 = (v4u64){0x008102c2008a029f, 0x024c01f901950261,
                      0x030d03aa0079029b, 0x01fa022a01a401e5};
  v4u64_op2 = (v4u64){0x0003ed8800031b38, 0x00735278007cf94c,
                      0x000315ac0000d658, 0x002e4db200000000};
  __m256i_result = (__m256i){0xffce110f004658c7, 0x00a2afb7fff00ecb,
                             0xff4f6838ff937648, 0x01a72334ffff00ff};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xe032c738adcc6bbf, 0x280ac9da313763f5,
                      0x000000003a099512, 0xffffffffffff0001};
  v4u64_op1 = (v4u64){0x8000000000000000, 0x8000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000fffffffffffe, 0x0001000100020001,
                      0x0000ffff00010000, 0xfffe000000000000};
  __m256i_result = (__m256i){0xe032c738adcc6bbf, 0x280ac9da313763f5,
                             0x000000003a099512, 0xffffffffffff0001};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff000000000000, 0x0000000000000000,
                      0x7fff000000000000, 0x7f00000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x7fff000000000000, 0x0000000000000000,
                             0x7fff000000000000, 0x7f00000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000010001, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000010001, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000001, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7,
                      0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x000000000045f3fb,
                      0x0000000000000000, 0x000000000045f3fb};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7,
                             0xf7f7f7f7f7f7f7f7, 0xf7f7f7f7f7f7f7f7};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000ffff00010003, 0x0080000200000002,
                      0x0000ffff00010003, 0x0000000200000002};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x8000000000000000, 0x0000000000000000,
                      0x8000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000ffff00010003, 0x0080000200000002,
                             0x0000ffff00010003, 0x0000000200000002};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000000007fffffff, 0x0000000000000000,
                      0x000000007fffffff, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000001a00, 0x0000000000000000,
                      0x0000000000001a00, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x0000000000000000,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000001f0000ffff, 0x0000001f0000001f,
                      0x0000ffff0000ffff, 0x0000ffff0000ffff};
  v4u64_op2 = (v4u64){0x0000000000040053, 0xfffffffffffe0000,
                      0x00000000000c005b, 0x0000000000060008};
  __m256i_result = (__m256i){0x000000000053ffac, 0xffffffe100000000,
                             0xffffffff005affa4, 0xffffffff0007fff7};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000100000000, 0x0000000100000000,
                      0x0000000100000000, 0x0000000100000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff,
                      0x00ff00ff00ff00ff, 0x00ff00ff00ff00ff};
  __m256i_result = (__m256i){0x0000000100000000, 0x0000000100000000,
                             0x0000000100000000, 0x0000000100000000};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x5fff5fff607f0000, 0x0000420080000000,
                      0x5fff5fff607f0000, 0x0000420080000000};
  v4u64_op1 = (v4u64){0x5fff5fff607f0000, 0x0000420080000000,
                      0x5fff5fff607f0000, 0x0000420080000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x1000000000000000,
                      0x0000000000000000, 0x1000000000000000};
  __m256i_result = (__m256i){0x5fff5fff607f0000, 0x0000420080000000,
                             0x5fff5fff607f0000, 0x0000420080000000};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0100004300000000, 0x0100010001000100,
                      0x0100004300000000, 0x0100010001000100};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xff00010001000100, 0x0100010001000100,
                      0xff00010001000100, 0x0100010001000100};
  __m256i_result = (__m256i){0x01ffff4300ffff00, 0x0100010001000100,
                             0x01ffff4300ffff00, 0x0100010001000100};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000010001, 0x0000000000001000,
                      0x0000000000010001, 0x0000000000001000};
  v4u64_op1 = (v4u64){0xffff0607ffff0607, 0xffff0607ffff0607,
                      0xffff0607ffff0607, 0xffff0607ffff0607};
  v4u64_op2 = (v4u64){0x00000000faf3f3f2, 0x00000000f9f9f9f9,
                      0x00000000faf3f3f2, 0x00000000f9f9f9f9};
  __m256i_result = (__m256i){0x00000000ffb8579f, 0x00000000ffdbbbcf,
                             0x00000000ffb8579f, 0x00000000ffdbbbcf};
  __m256i_out = __lasx_xvmaddwev_w_hu_h((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000100000001,
                      0xffffffffffffffff, 0x0000000100000001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0x0000000100000001,
                      0xffffffffffffffff, 0x0000000100000001};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000100000001,
                             0xffffffffffffffff, 0x0000000100000001};
  __m256i_out = __lasx_xvmaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00b200b300800080, 0x00b200b300800080,
                      0x009200f200840080, 0x009200f200840080};
  v4u64_op1 = (v4u64){0x0000004000000040, 0x0000004000000040,
                      0x0000004000000040, 0x0000004000000040};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00b200b300800080, 0x00b200b300800080,
                             0x009200f200840080, 0x009200f200840080};
  __m256i_out = __lasx_xvmaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000404040, 0x0000000000202020,
                      0x0000000000404040, 0x0000000000202020};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000404040, 0x0000000000202020,
                             0x0000000000404040, 0x0000000000202020};
  __m256i_out = __lasx_xvmaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x1fa0000000080000, 0x0000000000000000,
                      0x1fa0000000080000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000202, 0x0000000000800080,
                      0x0000000000000202, 0x0000000000800080};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x1fa0000000080000, 0x0000000000000000,
                             0x1fa0000000080000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0xffffffff00000000,
                      0xffffffff00000000, 0xffffffff00000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op2 = (v4u64){0x00000000ffffffff, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xfffffffe00000001, 0xffffffff00000000,
                             0xffffffff00000000, 0xffffffff00000000};
  __m256i_out = __lasx_xvmaddwev_d_wu_w((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0202020201010000, 0x0000000000000000,
                      0x00000000eef14fe8, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0202020201010000, 0x0000000000000000,
                      0x00000000eef14fe8, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xff49fe4200000000, 0xfe02fe02fee5fe22,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x4244020201010000, 0xfffe928f1313c9cc,
                             0x00000000eef14fe8, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0005000500050005, 0x0005000500050005,
                      0x0005000500050005, 0x0005000500050005};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0005000500050005, 0x0005000500050005,
                             0x0005000500050005, 0x0005000500050005};
  __m256i_out = __lasx_xvmaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000fffffff6, 0x0000000000000000,
                      0x00000000fffffff6, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x3f3f3f3f00000000, 0x000000003f3f3f3f,
                      0x3f3f3f3f3f3f3f3f, 0x3f3f3f3f3f3f3f3f};
  __m256i_result = (__m256i){0x8787878a00000000, 0x000000003f3f3f3c,
                             0xc6c6c6c68787878a, 0x000000003f3f3f3c};
  __m256i_out = __lasx_xvmaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000fffffff6, 0x0000000000000000,
                      0x00000000fffffff6, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000080, 0x0000000000000080,
                      0x0000000000000080, 0x0000000000000080};
  v4u64_op2 = (v4u64){0x8787878a00000000, 0x000000003f3f3f3c,
                      0xc6c6c6c68787878a, 0x000000003f3f3f3c};
  __m256i_result = (__m256i){0xc3c3c500fffffff6, 0xffffffffffffffc3,
                             0x63636344c3c3c4f6, 0xffffffffffffffe3};
  __m256i_out = __lasx_xvmaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000ffff0000ffff,
                      0x0000000000000000, 0x0000ffff0000ffff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000008, 0x0000000000000000,
                      0x0000000000000008, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvmaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0xffffffffffffffff,
                             0x0000000000000000, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000009, 0x0000000000000009,
                      0x0000000000000009, 0x0000000000000009};
  v4u64_op1 = (v4u64){0x0000000900000009, 0x0000000900000009,
                      0x0000000900000009, 0x0000000900000009};
  v4u64_op2 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000009, 0x0000000000000009,
                             0x0000000000000009, 0x0000000000000009};
  __m256i_out = __lasx_xvmaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x000400030010000f, 0x0004000f00100003,
                      0x000400030010000f, 0x0004000f00100003};
  v4u64_op2 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xfffbfffcffeffff0, 0xffffffffffffffff,
                             0xfffbfffcffeffff0, 0xffffffffffffffff};
  __m256i_out = __lasx_xvmaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000f9bb562f56c80, 0x00000b0cfffff4f3,
                      0x000f9bb562f56c80, 0x00000b0cfffff4f3};
  v4u64_op1 = (v4u64){0x04f104f104f504ed, 0x0000ffff0002fffd,
                      0x04f104f104f504ed, 0x0000ffff0002fffd};
  v4u64_op2 = (v4u64){0x04f104f104f504ed, 0x0000ffff0002fffd,
                      0x04f104f104f504ed, 0x0000ffff0002fffd};
  __m256i_result = (__m256i){0xabdcdc9938afafe9, 0x0018761ed60b5d7f,
                             0xabdcdc9938afafe9, 0x0018761ed60b5d7f};
  __m256i_out = __lasx_xvmaddwev_q_du_d((__m256)v4u64_op0, (__m256)v4u64_op1, (__m256)v4u64_op2);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
