/*
 * Test 512-bit intrinsics related to valignd and valignq.
 * Here we check for _mm512_[mask|maskz]_alignr_epi*
 * intrinsics.
 */

#include "m512_test_util.h"
#include <memory.h>

volatile int vol0 = 0;

#define soft_update(v512) (v512).xmmi[vol0] = (v512).xmmi[vol0]

#define TEST_MASK(instr, elembits, mask, imm, num_elems, dtype)                \
  { /* Blend masking */                                                        \
    memcpy(&res, &dtype##res_orig, sizeof(res));                               \
    soft_update(dtype##op2);                                                   \
    res.zmmi = _mm512_mask_alignr_epi##elembits(                               \
        res.zmmi, mask, dtype##op1.zmmi, dtype##op2.zmmi, imm);                \
                                                                               \
    /* Compute the expected result. */                                         \
    expect.zmmi =                                                              \
        compute_##instr(mask, 0, &dtype##op1, &dtype##op2, imm, num_elems);    \
                                                                               \
    /* Compare the obtained and expected results. */                           \
    check_equal_n##dtype(&res, &expect, num_elems,                             \
                         "_mm512_mask_alignr_epi" #elembits ", " #imm,         \
                         __LINE__);                                            \
    /* Verify combination with masked load. */                                 \
    {                                                                          \
      __m512i src2_copy, src2 = dtype##op1.zmmi;                               \
      memcpy(&res, &dtype##res_orig, sizeof(res));                             \
      soft_update(dtype##op2);                                                 \
      src2 = _mm512_mask_load_epi##elembits(src2, mask, &dtype##op2.zmmi);     \
      res.zmmi = _mm512_mask_alignr_epi##elembits(res.zmmi, mask,              \
                                                  dtype##op1.zmmi, src2, imm); \
      soft_update(dtype##op2);                                                 \
      src2_copy = _mm512_mask_load_epi##elembits(dtype##op1.zmmi, mask,        \
                                                 &dtype##op2.zmmi);            \
      expect.zmmi =                                                            \
          compute_##instr(mask, 0, &dtype##op1, &src2_copy, imm, num_elems);   \
      check_equal_n##dtype(&res, &expect, num_elems,                           \
                           "mix with load _mm512_mask_alignr_epi" #elembits ", \
                           " #imm, __LINE__);                                  \
    }                                                                          \
  }

#define TEST_MASKZ(instr, elembits, mask, imm, num_elems, dtype)               \
  {                                                                            \
    /* Zero masking */                                                         \
    memset(&res, 0xFF, sizeof(res));                                           \
    soft_update(dtype##op2);                                                   \
    res.zmmi = _mm512_maskz_alignr_epi##elembits(mask, dtype##op1.zmmi,        \
                                                 dtype##op2.zmmi, imm);        \
                                                                               \
    /* Compute the expected result. */                                         \
    expect.zmmi =                                                              \
        compute_##instr(mask, 1, &dtype##op1, &dtype##op2, imm, num_elems);    \
                                                                               \
    /* Compare the obtained and expected results. */                           \
    check_equal_n##dtype(&res, &expect, num_elems,                             \
                         "_mm512_maskz_alignr_epi" #elembits ", " #imm,        \
                         __LINE__);                                            \
  }

#define TEST(instr, elembits, imm, num_elems, dtype)                           \
  {                                                                            \
    /* No masking */                                                           \
    memset(&res, 0xFF, sizeof(res));                                           \
    soft_update(dtype##op2);                                                   \
    res.zmmi =                                                                 \
        _mm512_alignr_epi##elembits(dtype##op1.zmmi, dtype##op2.zmmi, imm);    \
                                                                               \
    /* Compute the expected result. */                                         \
    expect.zmmi = compute_##instr((1 << (num_elems)) - 1, 0, &dtype##op1,      \
                                  &dtype##op2, imm, num_elems);                \
                                                                               \
    /* Compare the obtained and expected results. */                           \
    check_equal_n##dtype(&res, &expect, num_elems,                             \
                         "_mm512_alignr_epi" #elembits ", " #imm, __LINE__);   \
  }

#define TEST_ALIGN(instr, elembits, mask, imm, num_elems, dtype)               \
  TEST_MASK(instr, elembits, mask, imm, num_elems, dtype)                      \
  TEST_MASKZ(instr, elembits, mask, imm, num_elems, dtype)                     \
  TEST(instr, elembits, imm, num_elems, dtype)

#define TEST_ALIGND(mask, imm) TEST_ALIGN(zalignd, 32, mask, imm, 16, d)

#define TEST_ALIGNQ(mask, imm) TEST_ALIGN(zalignq, 64, mask, imm, 8, q)

V512 dop1, dop2, dres_orig;
V512 qop1, qop2, qres_orig;
V512 res, expect;

volatile unsigned int dres_orig_arr[16] = {
    0x12345678, 0x11111111, 0x22222222, 0x33333333, 0x44444444, 0x55555555,
    0x66666666, 0x77777777, 0x88888888, 0x99999999, 0xaaaaaaaa, 0xbbbbbbbb,
    0xcccccccc, 0xdddddddd, 0xeeeeeeee, 0xffffffff};

volatile U64 qres_orig_arr[8] = {0x123456789abcdef0, 0x1111111111111111,
                                 0x2222222222222222, 0x3333333333333333,
                                 0x4444444444444444, 0x5555555555555555,
                                 0x7777777777777777, 0x6666666666666666};

static void NOINLINE init() {
  int i;

  for (i = 0; i < 16; i++) {
    dop1.u32[i] = 0x11000000 + i;
  }
  for (i = 0; i < 16; i++) {
    dop2.u32[i] = 0x22000000 + i;
  }

  for (i = 0; i < 8; i++) {
    qop1.u64[i] = 0x1111000000000000 + i;
  }
  for (i = 0; i < 8; i++) {
    qop2.u64[i] = 0x2222000000000000 + i;
  }

  memcpy((void *)&dres_orig, (void *)dres_orig_arr, 64);
  memcpy((void *)&qres_orig, (void *)qres_orig_arr, 64);
}

__m512i NOINLINE compute_zalignd(__mmask16 mask, int zero_mask, const void *op1,
                                 const void *op2, int imm, int num_elems) {
  V512 res;
  int i, res_idx;

  res_idx = 0;
  for (i = 0; i < 2; i++) {
    int lower, upper, op_idx;
    unsigned int *vop;

    if (i == 0) {
      lower = imm;
      upper = num_elems;
      vop = (unsigned int *)op2;
    } else {
      lower = 0;
      upper = imm;
      vop = (unsigned int *)op1;
    }

    for (op_idx = lower; op_idx < upper; op_idx++) {

      int elem_mask = mask & (1 << res_idx);

      if (elem_mask) {
        res.u32[res_idx] = vop[op_idx];
      } else if (zero_mask) {
        res.u32[res_idx] = 0;
      } else {
        res.u32[res_idx] = dres_orig.u32[res_idx];
      }

      res_idx++;
    }
  }

  return res.zmmi;
}

void NOINLINE do_zalignd() {
  TEST_ALIGND(0x0000, 0);
  TEST_ALIGND(0xabcd, 0);
  TEST_ALIGND(0xffff, 0);

  TEST_ALIGND(0x0000, 1);
  TEST_ALIGND(0xabcd, 1);
  TEST_ALIGND(0xfef7, 1);
  TEST_ALIGND(0xffff, 1);

  TEST_ALIGND(0xabcd, 3);
  TEST_ALIGND(0xfefe, 5);

  TEST_ALIGND(0x0000, 7);
  TEST_ALIGND(0xabcd, 7);
  TEST_ALIGND(0xffff, 7);

  TEST_ALIGND(0x0000, 8);
  TEST_ALIGND(0xabcd, 8);
  TEST_ALIGND(0xffff, 8);

  TEST_ALIGND(0x0000, 9);
  TEST_ALIGND(0xabcd, 9);
  TEST_ALIGND(0xffff, 9);

  TEST_ALIGND(0x0000, 14);
  TEST_ALIGND(0xabcd, 14);
  TEST_ALIGND(0xfef7, 14);
  TEST_ALIGND(0xffff, 14);

  TEST_ALIGND(0x0000, 15);
  TEST_ALIGND(0xabcd, 15);
  TEST_ALIGND(0xffff, 15);
}

__m512i NOINLINE compute_zalignq(int mask, int zero_mask, const void *op1,
                                 const void *op2, int imm, int num_elems) {
  V512 res;
  int i, res_idx;

  res_idx = 0;
  for (i = 0; i < 2; i++) {
    int lower, upper, op_idx;
    U64 *vop;

    if (i == 0) {
      lower = imm;
      upper = num_elems;
      vop = (U64 *)op2;
    } else {
      lower = 0;
      upper = imm;
      vop = (U64 *)op1;
    }

    for (op_idx = lower; op_idx < upper; op_idx++) {

      int elem_mask = mask & (1 << res_idx);

      if (elem_mask) {
        res.u64[res_idx] = vop[op_idx];
      } else if (zero_mask) {
        res.u64[res_idx] = 0;
      } else {
        res.u64[res_idx] = qres_orig.u64[res_idx];
      }

      res_idx++;
    }
  }

  return res.zmmi;
}

void NOINLINE do_zalignq() {
  TEST_ALIGNQ(0x00, 0);
  TEST_ALIGNQ(0xbe, 0);
  TEST_ALIGNQ(0xff, 0);

  TEST_ALIGNQ(0x00, 1);
  TEST_ALIGNQ(0xbe, 1);
  TEST_ALIGNQ(0xff, 1);

  TEST_ALIGNQ(0x00, 3);
  TEST_ALIGNQ(0xbe, 3);
  TEST_ALIGNQ(0xff, 3);

  TEST_ALIGNQ(0x00, 4);
  TEST_ALIGNQ(0xbe, 4);
  TEST_ALIGNQ(0xff, 4);

  TEST_ALIGNQ(0x00, 5);
  TEST_ALIGNQ(0xbe, 5);
  TEST_ALIGNQ(0xff, 5);

  TEST_ALIGNQ(0x00, 6);
  TEST_ALIGNQ(0xbe, 6);
  TEST_ALIGNQ(0xff, 6);

  TEST_ALIGNQ(0x00, 7);
  TEST_ALIGNQ(0xbe, 7);
  TEST_ALIGNQ(0xe7, 7);
  TEST_ALIGNQ(0xff, 7);
}

int main() {
  init();

  do_zalignd();

  do_zalignq();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
