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

  v4u64_op0 = (v4u64){0x0000000000000000, 0x000000040000fff8,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x00001f41ffffbf00,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x010180068080fff9,
                             0x0101010101010101, 0x0101010101010101};
  __m256i_out = __lasx_xvbitset_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x0101010101010101,
                             0x0101010101010101, 0x0101010101010101};
  __m256i_out = __lasx_xvbitset_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x3ff0000000000000, 0x0000000000000000,
                      0x3ff0000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000ffff00010000, 0x0000000000000000,
                      0x0000ffff00010000, 0x0000000000000000};
  __m256i_result = (__m256i){0x3ff1808001020101, 0x0101010101010101,
                             0x3ff1808001020101, 0x0101010101010101};
  __m256i_out = __lasx_xvbitset_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x5ef1f90efefaf30d, 0xde91f010000006f9,
                      0x1729c073816edebe, 0xbea2e127c046721f};
  v4u64_op1 = (v4u64){0x0000000000000001, 0x000000007fef0001,
                      0x0000000001060005, 0x0000000060000108};
  __m256i_result = (__m256i){0x5ff1f90ffffbf30f, 0xdf91f111808007fb,
                             0x1729c173836edfbe, 0xbfa3e127c147721f};
  __m256i_out = __lasx_xvbitset_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xe161616161614e60, 0xe161616161614e60,
                      0xe161616161614e60, 0xe161616161614e60};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xe161616161614f61, 0xe161616161614f61,
                             0xe161616161614f61, 0xe161616161614f61};
  __m256i_out = __lasx_xvbitset_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x00000000d58f43c8,
                      0x0000000000000000, 0x0000000082f8989a};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0101010101010101, 0x01010101d58f43c9,
                             0x0101010101010101, 0x0101010183f9999b};
  __m256i_out = __lasx_xvbitset_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7ff0000000000000, 0x41cc5bb8a95fd1eb,
                      0x7ff0000000000000, 0x41cc5bb8a95fd1eb};
  v4u64_op1 = (v4u64){0xcacacb1011040500, 0x7b7b7b7b80000000,
                      0xcacacb1011040500, 0x7b7b7b7b80000000};
  __m256i_result = (__m256i){0x7ff4080102102001, 0x49cc5bb8a95fd1eb,
                             0x7ff4080102102001, 0x49cc5bb8a95fd1eb};
  __m256i_out = __lasx_xvbitset_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000200, 0x0000000000000200,
                      0x0000000000000200, 0x0000000000000200};
  __m256i_result = (__m256i){0x0101010101010401, 0x0101010101010401,
                             0x0101010101010401, 0x0101010101010401};
  __m256i_out = __lasx_xvbitset_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x5b7f00ff5b7f00ff, 0xdf00000052a00000,
                      0x5b7f00ff5b7f00ff, 0xdf00000052a00000};
  v4u64_op1 = (v4u64){0x2020202020206431, 0x2020202020202020,
                      0x2020202020206431, 0x2020202020202020};
  __m256i_result = (__m256i){0x5b7f01ff5b7f10ff, 0xdf01010153a10101,
                             0x5b7f01ff5b7f10ff, 0xdf01010153a10101};
  __m256i_out = __lasx_xvbitset_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x23222120171e151c, 0x0000000027262524,
                      0x23222120171e151c, 0x0000000027262524};
  v4u64_op1 = (v4u64){0x201fdfe0201fdfe0, 0x0000000000000000,
                      0x201fdfe0201fdfe0, 0x0000000000000000};
  __m256i_result = (__m256i){0x23a2a121179e951d, 0x0101010127272525,
                             0x23a2a121179e951d, 0x0101010127272525};
  __m256i_out = __lasx_xvbitset_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000000c9, 0x0000000000000000,
                      0x00000000000000c9, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x00000000000000f0,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x01010101010101c9, 0x0101010101010101,
                             0x01010101010101c9, 0x0101010101010101};
  __m256i_out = __lasx_xvbitset_b((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc7387fff6bbfffff, 0xc9da000063f50000,
                      0x0000000095120000, 0xffff000000010000};
  v4u64_op1 = (v4u64){0xe032c738adcb6bbb, 0x280bc9db313a63f5,
                      0x0000ffff3a0b9512, 0xfffdffffffc81aca};
  __m256i_result = (__m256i){0xc73c7fff6bbfffff, 0xc9da080067f50020,
                             0x000180009d120004, 0xffff800001010400};
  __m256i_out = __lasx_xvbitset_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffff00000000, 0xffffffffffffffff,
                      0xffffffff00000000, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x6651bfff80000000, 0xfffffffff328dfff,
                      0x8000000080000000, 0xffffff8046867f79};
  __m256i_result = (__m256i){0xffffffff00010001, 0xffffffffffffffff,
                             0xffffffff00010001, 0xffffffffffffffff};
  __m256i_out = __lasx_xvbitset_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000102};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0001000100010001, 0x0001000100010001,
                             0x0001000100010001, 0x0001000100010103};
  __m256i_out = __lasx_xvbitset_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0001000100010001, 0x0001000100010001,
                             0x0001000100010001, 0x0001000100010001};
  __m256i_out = __lasx_xvbitset_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000007fee, 0x0000000000007fee,
                      0x0000000000007fee, 0x0000000000007fee};
  v4u64_op1 = (v4u64){0x7fefffffffffffff, 0x7fefffffffffffff,
                      0x7fefffffffffffff, 0x7fefffffffffffff};
  __m256i_result = (__m256i){0x800080008000ffee, 0x800080008000ffee,
                             0x800080008000ffee, 0x800080008000ffee};
  __m256i_out = __lasx_xvbitset_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x000000000000ffff,
                      0x000000000000ffff, 0x000000000000ffff};
  v4u64_op1 = (v4u64){0x7ff0000000000000, 0x7ff0000000000000,
                      0x7ff0000000000000, 0x7ff0000000000000};
  __m256i_result = (__m256i){0x000100010001ffff, 0x000100010001ffff,
                             0x000100010001ffff, 0x000100010001ffff};
  __m256i_out = __lasx_xvbitset_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0200000202000002, 0x0000000000000000,
                      0x0200000202000002, 0x0000000000000000};
  __m256i_result = (__m256i){0x0001000400010004, 0x0001000100010001,
                             0x0001000400010004, 0x0001000100010001};
  __m256i_out = __lasx_xvbitset_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000e0000000d, 0x0000000e0000000e,
                      0x0000000e0000000d, 0x0000000e0000000e};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0001000f0001000d, 0x0001000f0001000f,
                             0x0001000f0001000d, 0x0001000f0001000f};
  __m256i_out = __lasx_xvbitset_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x4980008068400000, 0x498000804843ffe0,
                      0x4980008068400000, 0x498000804843ffe0};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x4981008168410001, 0x498100814843ffe1,
                             0x4981008168410001, 0x498100814843ffe1};
  __m256i_out = __lasx_xvbitset_h((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0x8000000080000000, 0x0000000100000001,
                             0x8000000080000000, 0x0000000100000001};
  __m256i_out = __lasx_xvbitset_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x0000000000000000,
                      0xffffffffffffffff, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000100000001,
                             0xffffffffffffffff, 0x0000000100000001};
  __m256i_out = __lasx_xvbitset_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000010, 0x0000000000000000,
                      0x0000000000000010, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffffffffffffffe, 0xfffffffffffffffe,
                      0xfffffffefffffefc, 0xfffffffffffffffe};
  __m256i_result = (__m256i){0x8000000040000010, 0x8000000040000000,
                             0x4000000010000010, 0x8000000040000000};
  __m256i_out = __lasx_xvbitset_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8080808080808080, 0x8080808080808080,
                      0x8080808080808080, 0x8080808080808080};
  v4u64_op1 = (v4u64){0x0101010101010101, 0x01010101010000ff,
                      0x0101010101010101, 0x0101010101010101};
  __m256i_result = (__m256i){0x8080808280808082, 0x8080808280808080,
                             0x8080808280808082, 0x8080808280808082};
  __m256i_out = __lasx_xvbitset_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x45baa7ef6a95a985, 0x0707feb60707b7d0,
                      0x45baa7ef6a95a985, 0x0707feb60707b7d0};
  v4u64_op1 = (v4u64){0x7ffe7ffd7ffe8001, 0x0000000000000000,
                      0x7ffe7ffd7ffe7fff, 0x0000000000000000};
  __m256i_result = (__m256i){0x65baa7ef6a95a987, 0x0707feb70707b7d1,
                             0x65baa7efea95a985, 0x0707feb70707b7d1};
  __m256i_out = __lasx_xvbitset_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xdbcbdbcb0000dbcb, 0xdbcbdbcbecececec,
                      0xdbcbdbcb0000dbcb, 0xdbcbdbcbecececec};
  __m256i_result = (__m256i){0x0000080000000800, 0x0000080000001000,
                             0x0000080000000800, 0x0000080000001000};
  __m256i_out = __lasx_xvbitset_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000100000001, 0x0000000100000001,
                             0x0000000100000001, 0x0000000100000001};
  __m256i_out = __lasx_xvbitset_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvbitset_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x007f010000000100, 0x0000000000000000,
                      0x007f010000000100, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x4000000000000000,
                      0x0000000000000000, 0x4000000000000000};
  __m256i_result = (__m256i){0x007f010100000101, 0x0000000100000001,
                             0x007f010100000101, 0x0000000100000001};
  __m256i_out = __lasx_xvbitset_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000000000d6d6d, 0x0000000000000000,
                      0x00000000090b0906, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000100002000, 0x0000000100000001,
                             0x0000000100000040, 0x0000000100000001};
  __m256i_out = __lasx_xvbitset_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x03acfc5303260e80, 0x03af03af03af03af,
                      0x03acfc5303260e80, 0x03af03af03af03af};
  v4u64_op1 = (v4u64){0x0000000000002780, 0x0000000000000000,
                      0x0000000000002780, 0x0000000000000000};
  __m256i_result = (__m256i){0x03acfc5303260e81, 0x03af03af03af03af,
                             0x03acfc5303260e81, 0x03af03af03af03af};
  __m256i_out = __lasx_xvbitset_w((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvbitset_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvbitset_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x00000000000004fb, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0800000000000000, 0x0000000000000001};
  __m256i_out = __lasx_xvbitset_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x8000000000000000, 0x8000000000000000,
                      0x8000000000000000, 0x8000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvbitset_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000000000ffff, 0x000000000000ffff,
                      0x000000000000ffff, 0x000000000000ffff};
  v4u64_op1 = (v4u64){0x00010000fffe0000, 0x00010000fffe0000,
                      0x00010000fffe0000, 0x00010000fffe0000};
  __m256i_result = (__m256i){0x000000000000ffff, 0x000000000000ffff,
                             0x000000000000ffff, 0x000000000000ffff};
  __m256i_out = __lasx_xvbitset_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvbitset_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000200000008, 0x0000000000000000,
                      0x0000000200000008, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0xffffffffffffffff,
                             0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_out = __lasx_xvbitset_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000affff800b, 0x0000000affff800b,
                      0x0000000affff800b, 0x0000000affff800b};
  __m256i_result = (__m256i){0x0000000000000800, 0x0000000000000800,
                             0x0000000000000800, 0x0000000000000800};
  __m256i_out = __lasx_xvbitset_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000001, 0x0000000000000001,
                             0x0000000000000001, 0x0000000000000001};
  __m256i_out = __lasx_xvbitset_d((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
