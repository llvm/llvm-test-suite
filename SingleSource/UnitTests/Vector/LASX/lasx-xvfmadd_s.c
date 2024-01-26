#include "lasx_test_util.h"
#include <lasxintrin.h>

int
main ()
{
  __m256i __m256i_out, __m256i_result;
  __m256 __m256_out, __m256_result;
  __m256d __m256d_out, __m256d_result;
  v4u64 v4u64_op0, v4u64_op1, v4u64_op2, v4u64_result;
  v8i32 v8i32_op0, v8i32_op1, v8i32_op2, v8i32_result;

  int int_op0, int_op1, i = 1, fail;
  long int long_op0, long_op1;
  long int long_int_out, long_int_result;
  unsigned int unsigned_int_out, unsigned_int_result;
  unsigned long int unsigned_long_int_out, unsigned_long_int_result;

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x6651bfff, 0xf328dfff, 0xffffffff,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x0000dfff, 0x0000f328, 0x0000ffff, 0x0000ffff,
                      0x00007f79, 0x00004686, 0x0000ff80, 0x0000ffff};
  v8i32_result = (v8i32){0x0000dfff, 0x0000f328, 0x0000ffff, 0xffffffff,
                         0x00007f79, 0x00004686, 0x0000ff80, 0x0000ffff};
  __m256_out = __lasx_xvfmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xfff10000, 0xfff10000, 0x00000000, 0x00000000,
                      0xfff10000, 0xfff10000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xfff10000, 0xfff10000, 0x00000000, 0x00000000,
                         0xfff10000, 0xfff10000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x1f636003, 0x803f6004, 0x00000000, 0x00000000,
                      0x1f636003, 0x803f6004, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x1f636003, 0x803f6004, 0x00000000, 0x00000000,
                         0x1f636003, 0x803f6004, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0xffffffff, 0x00000000, 0x00000000, 0x00000000,
                      0xffffffff, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0x00000000, 0x00000000, 0x00000000,
                         0xffffffff, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x006ed8b8, 0xffb3430a, 0xffffffff, 0xffffffff,
                      0x006ed8b8, 0xffb3430a, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0x000003fe, 0x000001ff, 0x00000000, 0x00000000,
                      0x000003fe, 0x000001ff, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x000000ff, 0x00000000, 0x00000000, 0x00000000,
                      0x000000ff, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x000000ff, 0xfff3430a, 0xffffffff, 0xffffffff,
                         0x000000ff, 0xfff3430a, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x20010001, 0xfffe97c0, 0x9ffffd80, 0xfffeb683,
                      0x20010001, 0xfffe97c0, 0x9ffffd80, 0xfffeb683};
  v8i32_op1 = (v8i32){0x20010001, 0x0000ffff, 0x9ffffd80, 0x00009fff,
                      0x20010001, 0x0000ffff, 0x9ffffd80, 0x00009fff};
  v8i32_op2 = (v8i32){0xdf5b41cf, 0x00002080, 0x00000000, 0x00000000,
                      0xdf5b41cf, 0x00002080, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xdf5b41cf, 0xfffe97c0, 0x007ffd80, 0xfffeb683,
                         0xdf5b41cf, 0xfffe97c0, 0x007ffd80, 0xfffeb683};
  __m256_out = __lasx_xvfmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0x00000000, 0xffffffff, 0x00000000,
                      0xffffffff, 0x00000000, 0xffffffff, 0x00000000};
  v8i32_op1 = (v8i32){0xdf5b41b0, 0xfffe97a1, 0x007ffd61, 0xfffeb664,
                      0xdf5b41b0, 0xfffe97a1, 0x007ffd61, 0xfffeb664};
  v8i32_op2 = (v8i32){0x00000000, 0x94d7fb52, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0xfffe97a1, 0xffffffff, 0xfffeb664,
                         0xffffffff, 0xfffe97a1, 0xffffffff, 0xfffeb664};
  __m256_out = __lasx_xvfmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfmadd_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x199d04b5, 0xb71c413b, 0xfe02fffe, 0x000000fe,
                      0xfc1e0049, 0xb7146213, 0x12c4007e, 0xb70036db};
  v8i32_op2 = (v8i32){0x199d04b5, 0xb71c413b, 0xfe02fffe, 0x000000fe,
                      0xfc1e0049, 0xb7146213, 0x12c4007e, 0xb70036db};
  v8i32_result = (v8i32){0x999d04b5, 0x371c413b, 0x7e02fffe, 0x800000fe,
                         0x7c1e0049, 0x37146213, 0x92c4007e, 0x370036db};
  __m256_out = __lasx_xvfmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0xffffffff, 0x00000000, 0x00000000,
                      0x00000000, 0xffffffff, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0xff800000, 0x3f7f7f7e, 0x00000000, 0x00000000,
                      0xff800000, 0x3f7f7f7e, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0xff7fffff, 0x7fffffff, 0x00000000, 0x00000000,
                      0xff7fffff, 0x7fffffff, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x7fc00000, 0x7fffffff, 0x00000000, 0x00000000,
                         0x7fc00000, 0x7fffffff, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                         0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  __m256_out = __lasx_xvfmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xb3b3dc9d, 0xffffafaf, 0x00000000, 0x00000000,
                      0xb3b3dc9d, 0xffffafaf, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x004a007e, 0x00220021, 0x00020000, 0x00020000,
                      0x004a007e, 0x00220021, 0x00020000, 0x00020000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000001, 0x00007f7f, 0x00000001,
                      0x00000000, 0x00000001, 0x00007f7f, 0x00000001};
  v8i32_result = (v8i32){0x80000000, 0xffffafaf, 0x80007f7f, 0x80000001,
                         0x80000000, 0xffffafaf, 0x80007f7f, 0x80000001};
  __m256_out = __lasx_xvfmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
                      0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0xffffffe5, 0xffffffe5, 0xffffffe5, 0xffffffe5,
                      0xffffffe5, 0xffffffe5, 0xffffffe5, 0xffffffe5};
  v8i32_result = (v8i32){0xffffffe5, 0xffffffe5, 0xffffffe5, 0xffffffe5,
                         0xffffffe5, 0xffffffe5, 0xffffffe5, 0xffffffe5};
  __m256_out = __lasx_xvfmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x80000000, 0xbfff8000, 0xffff8000, 0xbfffffff,
                      0x80000000, 0xbfff8000, 0xffff8000, 0xbfffffff};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x80000000, 0x80000000, 0xffff8000, 0x80000000,
                         0x80000000, 0x80000000, 0xffff8000, 0x80000000};
  __m256_out = __lasx_xvfmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x02020102, 0x02020102, 0x02020102, 0x02020102,
                      0x02020102, 0x02020102, 0x02020102, 0x02020102};
  v8i32_op2 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                         0x00000000, 0x00000000, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000008, 0x00000000, 0x00000008, 0x00000000,
                      0x00000008, 0x00000000, 0x00000008, 0x00000000};
  v8i32_op1 = (v8i32){0x00000008, 0x00000000, 0x00000008, 0x00000000,
                      0x00000008, 0x00000000, 0x00000008, 0x00000000};
  v8i32_op2 = (v8i32){0x00000001, 0x00000001, 0x00000000, 0x00000000,
                      0x00000001, 0x00000001, 0x00000000, 0x00000000};
  v8i32_result = (v8i32){0x80000001, 0x80000001, 0x00000000, 0x00000000,
                         0x80000001, 0x80000001, 0x00000000, 0x00000000};
  __m256_out = __lasx_xvfmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  v8i32_op0 = (v8i32){0x00000040, 0x00000000, 0x00000000, 0x00000000,
                      0x00000040, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op1 = (v8i32){0x00000000, 0x00000000, 0x00000000, 0x00000000,
                      0x00000000, 0x00000000, 0x00000000, 0x00000000};
  v8i32_op2 = (v8i32){0x40404040, 0x40404040, 0x40404040, 0x40404040,
                      0x40404040, 0x40404040, 0x40404040, 0x40404040};
  v8i32_result = (v8i32){0xc0404040, 0xc0404040, 0xc0404040, 0xc0404040,
                         0xc0404040, 0xc0404040, 0xc0404040, 0xc0404040};
  __m256_out = __lasx_xvfmsub_s((__m256)v8i32_op0, (__m256)v8i32_op1, (__m256)v8i32_op2);
  check_lasx_out(&v8i32_result, &__m256_out, sizeof(__m256_out), __FILE__, __LINE__);

  return 0;
}
