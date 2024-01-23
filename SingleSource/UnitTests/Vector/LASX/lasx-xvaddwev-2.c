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
  v4u64_op1 = (v4u64){0x0010100000000000, 0x0000000000000000,
                      0x0010100000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0010000000000000, 0x0000000000000000,
                             0x0010000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fff7fff7fff7fff, 0x0000000000000000,
                      0x7fff7fff7fff7fff, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xfffc0003fffa0000, 0xffffffffffffffff,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x01fb010201f900ff, 0x00ff00ff00ff00ff,
                             0x00ff00ff00ff00ff, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0xaaaa0000aaacfffe, 0x0000000000005554,
                      0xaaaa0000aaacfffe, 0x0000000000005554};
  __m256i_result = (__m256i){0x00aa000000ac00fe, 0x0000000000000054,
                             0x00aa000000ac00fe, 0x0000000000000054};
  __m256i_out = __lasx_xvaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x05960616020e0005, 0x017f01fe01ff0000,
                      0x05960616020e0203, 0x017f01fe01ff01fe};
  v4u64_op1 = (v4u64){0x05960616020e0005, 0x017f01fe01ff0000,
                      0x05960616020e0203, 0x017f01fe01ff01fe};
  __m256i_result = (__m256i){0x012c002c001c000a, 0x00fe01fc01fe0000,
                             0x012c002c001c0006, 0x00fe01fc01fe01fc};
  __m256i_out = __lasx_xvaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xc8eab25698f97e90, 0xd207e90001fb16ef,
                      0xc8eab25698f97e90, 0xd207e90001fb16ef};
  v4u64_op1 = (v4u64){0x7c007c007c007c00, 0x7c007c007c007c00,
                      0x7c007c007c007c00, 0x7c007c007c007c00};
  __m256i_result = (__m256i){0x00ea005600f90090, 0x0007000000fb00ef,
                             0x00ea005600f90090, 0x0007000000fb00ef};
  __m256i_out = __lasx_xvaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x6a9e3fa2603a2000, 0xffffc03b1fc5e050,
                      0x6a9e3fa2603a2000, 0xffffc03b1fc5e050};
  v4u64_op1 = (v4u64){0xffffc00000000000, 0xffffc03fffffffc0,
                      0xffffc00000000000, 0xffffc03fffffffc0};
  __m256i_result = (__m256i){0x019d00a2003a0000, 0x01fe007a01c40110,
                             0x019d00a2003a0000, 0x01fe007a01c40110};
  __m256i_out = __lasx_xvaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x7fe363637fe36363, 0x7fe36364661af18f,
                      0x7fe363637fe36363, 0x7fe36364661af18f};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00e3006300e30063, 0x00e30064001a008f,
                             0x00e3006300e30063, 0x00e30064001a008f};
  __m256i_out = __lasx_xvaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000013, 0x0000000000000013,
                      0x0000000000000013, 0x0000000000000013};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000013, 0x0000000000000013,
                             0x0000000000000013, 0x0000000000000013};
  __m256i_out = __lasx_xvaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x000020a4ffffbe4f, 0x000000010000685e,
                      0x000020a4ffffbe4f, 0x000000010000685e};
  __m256i_result = (__m256i){0x000000a400ff004f, 0x000000010000005e,
                             0x000000a400ff004f, 0x000000010000005e};
  __m256i_out = __lasx_xvaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x04f504f104f504f5, 0x0002ffff00020002,
                      0x04f504f104f504f5, 0x0002ffff00020002};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00f500f100f500f5, 0x000200ff00020002,
                             0x00f500f100f500f5, 0x000200ff00020002};
  __m256i_out = __lasx_xvaddwev_h_bu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x6d3c2d3aa1c82947, 0x0000883a00000f20,
                      0xf259905a0c126604, 0x000019410000e69a};
  v4u64_op1 = (v4u64){0x0658f2dc0eb21e3c, 0x31730b5beb7c99f5,
                      0xc5c085372cfabfba, 0x372e9d75e8aab100};
  __m256i_result = (__m256i){0x0001201600004783, 0x000093950000a915,
                             0x00011591000125be, 0x0000b6b60001979a};
  __m256i_out = __lasx_xvaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0xfffff6ff00000000,
                      0x0000000000000000, 0xfffff6ff00000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000f6ff00000000,
                             0x0000000000000000, 0x0000f6ff00000000};
  __m256i_out = __lasx_xvaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0057ffa800ceff31, 0x80f900f980780078,
                      0x00faff0500c3ff3c, 0x8011ffee804c004c};
  v4u64_op1 = (v4u64){0xff000000ff000000, 0x0000ff000000ff00,
                      0xff000000ff000000, 0x000000000000ff00};
  __m256i_result = (__m256i){0x0000ffa80000ff31, 0x0000fff90000ff78,
                             0x0000ff050000ff3c, 0x0000ffee0000ff4c};
  __m256i_out = __lasx_xvaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffc000, 0x00000000fffc7f7f,
                      0xffffffffffffc000, 0x00000000fffc7f7f};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0x8001b0b1b4b5dd9f,
                      0xffffffffffffffff, 0x8001b0b1b4b5dd9f};
  __m256i_result = (__m256i){0x0001fffe0001bfff, 0x0000b0b100015d1e,
                             0x0001fffe0001bfff, 0x0000b0b100015d1e};
  __m256i_out = __lasx_xvaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xfffffe20001dfe1f,
                      0x0000000000000000, 0xfffffe20001dfe1f};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000fe200000fe1f,
                             0x0000000000000000, 0x0000fe200000fe1f};
  __m256i_out = __lasx_xvaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x003f00000000003f, 0xffffffffffc0ffc1,
                      0x003f00000000003f, 0xffffffffffc0ffc1};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x0000ffff0001003e, 0x0001fffe0001ffc0,
                             0x0000ffff0001003e, 0x0001fffe0001ffc0};
  __m256i_out = __lasx_xvaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0061200000610000, 0x0020010101610000,
                      0x0061200000610000, 0x0020010101610000};
  v4u64_op1 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x00011fff0000ffff, 0x000101000000ffff,
                             0x00011fff0000ffff, 0x000101000000ffff};
  __m256i_out = __lasx_xvaddwev_w_hu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0x0000000000000001,
                      0xffffffffffffffff, 0x0000000000000001};
  v4u64_op1 = (v4u64){0x0000000000000000, 0xffffffffffffffff,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x00000000ffffffff, 0x0000000100000000,
                             0x00000000ffffffff, 0x0000000000000001};
  __m256i_out = __lasx_xvaddwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x00000013ffffebd8, 0x00000013ffffffec,
                      0x00000013ffffebd8, 0x00000013ffffffec};
  __m256i_result = (__m256i){0x00000000ffffebd8, 0x00000000ffffffec,
                             0x00000000ffffebd8, 0x00000000ffffffec};
  __m256i_out = __lasx_xvaddwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x00000000000c0007, 0x0000000000000000,
                      0x00000000000c0007, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0080000000800080, 0x3abb3abbbabababa,
                      0x0080000000800080, 0x3abb3abbbabababa};
  __m256i_result = (__m256i){0x00000000008c0087, 0x00000000babababa,
                             0x00000000008c0087, 0x00000000babababa};
  __m256i_out = __lasx_xvaddwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000080, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000080, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000040, 0x0000000000000040,
                      0x0000000000000040, 0x0000000000000040};
  __m256i_result = (__m256i){0x0000000000000040, 0x0000000000000040,
                             0x0000000000000040, 0x0000000000000040};
  __m256i_out = __lasx_xvaddwev_d_wu((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xffffffffffffffff, 0xffffffffffffffff,
                      0xffffffffffffffff, 0xffffffffffffffff};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xffffffffffffffff, 0x0000000000000000,
                             0xffffffffffffffff, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x000003ff000003ff,
                      0x0000000000000000, 0x000003ff000003ff};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x0000000000000000, 0x0000000000000000,
                             0x0000000000000000, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000010000000a, 0x0000000a00000000,
                      0x000000010000000a, 0x0000000a00000000};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0x000000010000000a, 0x0000000000000000,
                             0x000000010000000a, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x8060000000000000, 0x7ff0000000000000,
                      0x8060000000000000, 0x7ff0000000000000};
  v4u64_op1 = (v4u64){0xffff0000ffffffff, 0xffffffffffffffff,
                      0xffff0000ffffffff, 0xffffffffffffffff};
  __m256i_result = (__m256i){0x805f0000ffffffff, 0x0000000000000001,
                             0x805f0000ffffffff, 0x0000000000000001};
  __m256i_out = __lasx_xvaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0x000000003fc03fc0, 0xfe01fe010000fd02,
                      0x000000003fc03fc0, 0xfe01fe010000fd02};
  v4u64_op1 = (v4u64){0x000000003fc03fc0, 0xfe01fe010000fd02,
                      0x000000003fc03fc0, 0xfe01fe010000fd02};
  __m256i_result = (__m256i){0x000000007f807f80, 0x0000000000000000,
                             0x000000007f807f80, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  v4u64_op0 = (v4u64){0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c,
                      0xff1cff1cff1cff1c, 0xff1cff1cff1cff1c};
  v4u64_op1 = (v4u64){0x0000000000000000, 0x0000000000000000,
                      0x0000000000000000, 0x0000000000000000};
  __m256i_result = (__m256i){0xff1cff1cff1cff1c, 0x0000000000000000,
                             0xff1cff1cff1cff1c, 0x0000000000000000};
  __m256i_out = __lasx_xvaddwev_q_du((__m256)v4u64_op0, (__m256)v4u64_op1);
  check_lasx_out(&__m256i_result, &__m256i_out, sizeof(__m256i_out), __FILE__, __LINE__);

  return 0;
}
