/*
 * Tests for extract intrinsics family.
 * Here we check for _mm512_[mask|maskz]_extract[f|i] intrinsics.
 */

#include "m512_test_util.h"
#include <stdio.h>
#include <string.h>

volatile __int64 vol0;

V512 isrc1;
V512 isrc2;

V512 fsrc1;
V512 fsrc2;

V512 dsrc1;
V512 dsrc2;

V512 res;
V512 mres;

__mmask8 k8;

void NOINLINE init() {
  volatile int i;

  for (i = 0; i < 16; i++) {
    isrc1.s32[i] = i;
    isrc2.s32[i] = i + 1;

    fsrc1.f32[i] = i * 1.0f;
    fsrc2.f32[i] = i * 2.0f;
  }

  for (i = 0; i < 8; i++) {
    dsrc1.f64[i] = i * 4.0;
    dsrc2.f64[i] = i * 5.0;
  }

  k8 = 0x5a;
}

/*
 * Use this between tests to make compiler think src was updated.
 * Prevents PRE'ing of a load of src.
 */
#define soft_isrc1_update() isrc1.xmmi[vol0] = isrc1.xmmi[vol0]
#define soft_fsrc1_update() fsrc1.xmmi[vol0] = fsrc1.xmmi[vol0]
#define soft_dsrc1_update() dsrc1.xmmi[vol0] = dsrc1.xmmi[vol0]

/*
 * Model extract intrinsic behavior.
 */
V512 NOINLINE model_mask_extract_32x4(V512 input1, __mmask8 mask, V512 input2,
                                      int selector) {
  V512 tmp, lres;
  int i;

  tmp.xmm[0] = input2.xmm[selector];

  for (i = 0; i < 4; i++) {
    if ((mask & (1LL << i)) != 0) {
      lres.s32[i] = tmp.s32[i];
    } else {
      lres.s32[i] = input1.s32[i];
    }
  }

  return lres;
}

V512 NOINLINE model_maskz_extract_32x4(__mmask8 mask, V512 input2,
                                       int selector) {
  V512 tmp, lres;
  int i;

  tmp.xmm[0] = input2.xmm[selector];

  for (i = 0; i < 4; i++) {
    if ((mask & (1LL << i)) != 0) {
      lres.s32[i] = tmp.s32[i];
    } else {
      lres.s32[i] = 0;
    }
  }

  return lres;
}

V512 NOINLINE model_mask_extract_64x4(V512 input1, __mmask8 mask, V512 input2,
                                      int selector) {
  V512 tmp, lres;
  int i;

  tmp.ymm[0] = input2.ymm[selector];

  for (i = 0; i < 4; i++) {
    if ((mask & (1LL << i)) != 0) {
      lres.s64[i] = tmp.s64[i];
    } else {
      lres.s64[i] = input1.s64[i];
    }
  }

  return lres;
}

V512 NOINLINE model_maskz_extract_64x4(__mmask8 mask, V512 input2,
                                       int selector) {
  V512 tmp, lres;
  int i;

  tmp.ymm[0] = input2.ymm[selector];

  for (i = 0; i < 4; i++) {
    if ((mask & (1LL << i)) != 0) {
      lres.s64[i] = tmp.s64[i];
    } else {
      lres.s64[i] = 0;
    }
  }

  return lres;
}

#define GEN_CHECK_CASE_SEL(intrin, prefix, suffix, ress, n_elem, modeller,     \
                           checker, selector)                                  \
  res.ress[0] = intrin(prefix##src1.suffix, selector);                         \
  mres = modeller(0xff, prefix##src1, selector);                               \
  checker((void *)&res.suffix, (void *)&mres.suffix, n_elem, #intrin, __LINE__)

#define GEN_MASK_CHECK_CASE_SEL(intrin, prefix, suffix, ress, n_elem,          \
                                modeller, checker, selector)                   \
  res.ress[0] =                                                                \
      intrin(prefix##src2.ress[0], k8, prefix##src1.suffix, selector);         \
  mres = modeller(prefix##src2, k8, prefix##src1, selector);                   \
  checker((void *)&res.suffix, (void *)&mres.suffix, n_elem, #intrin, __LINE__)

#define GEN_MASKZ_CHECK_CASE_SEL(intrin, prefix, suffix, ress, n_elem,         \
                                 modeller, checker, selector)                  \
  res.ress[0] = intrin(k8, prefix##src1.suffix, selector);                     \
  mres = modeller(k8, prefix##src1, selector);                                 \
  checker((void *)&res.suffix, (void *)&mres.suffix, n_elem, #intrin, __LINE__)

#define GEN_CHECK_CASE_3_SEL(intrin_end, prefix, suffix, ress, n_elem,         \
                             modeller_end, checker_end, selector)              \
  GEN_CHECK_CASE_SEL(_mm512_##intrin_end, prefix, suffix, ress, n_elem,        \
                     model_maskz_##modeller_end, check_##checker_end,          \
                     selector);                                                \
  GEN_MASK_CHECK_CASE_SEL(_mm512_mask_##intrin_end, prefix, suffix, ress,      \
                          n_elem, model_mask_##modeller_end,                   \
                          check_##checker_end, selector);                      \
  GEN_MASKZ_CHECK_CASE_SEL(_mm512_maskz_##intrin_end, prefix, suffix, ress,    \
                           n_elem, model_maskz_##modeller_end,                 \
                           check_##checker_end, selector)

#define GEN_CHECK_CASE_3_2(intrin_end, prefix, suffix, ress, n_elem,           \
                           modeller_end, checker_end)                          \
  GEN_CHECK_CASE_3_SEL(intrin_end, prefix, suffix, ress, n_elem, modeller_end, \
                       checker_end, 0);                                        \
  GEN_CHECK_CASE_3_SEL(intrin_end, prefix, suffix, ress, n_elem, modeller_end, \
                       checker_end, 1)

#define GEN_CHECK_CASE_3_4(intrin_end, prefix, suffix, ress, n_elem,           \
                           modeller_end, checker_end)                          \
  GEN_CHECK_CASE_3_SEL(intrin_end, prefix, suffix, ress, n_elem, modeller_end, \
                       checker_end, 0);                                        \
  GEN_CHECK_CASE_3_SEL(intrin_end, prefix, suffix, ress, n_elem, modeller_end, \
                       checker_end, 1);                                        \
  GEN_CHECK_CASE_3_SEL(intrin_end, prefix, suffix, ress, n_elem, modeller_end, \
                       checker_end, 2);                                        \
  GEN_CHECK_CASE_3_SEL(intrin_end, prefix, suffix, ress, n_elem, modeller_end, \
                       checker_end, 3)

void NOINLINE do_m512_extract() {
  soft_fsrc1_update();
  GEN_CHECK_CASE_3_4(extractf32x4_ps, f, zmm, xmm, 4, extract_32x4, equal_nsf);
  soft_isrc1_update();
  GEN_CHECK_CASE_3_4(extracti32x4_epi32, i, zmmi, xmmi, 4, extract_32x4,
                     equal_nd);

  soft_fsrc1_update();
  GEN_CHECK_CASE_3_2(extractf64x4_pd, d, zmmd, ymmd, 2, extract_64x4,
                     equal_ndf);
  soft_isrc1_update();
  GEN_CHECK_CASE_3_2(extracti64x4_epi64, i, zmmi, ymmi, 2, extract_64x4,
                     equal_nq);
}

int main() {
  init();

  do_m512_extract();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
