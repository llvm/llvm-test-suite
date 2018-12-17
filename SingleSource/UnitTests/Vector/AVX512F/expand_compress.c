/*
 * Tests for expand intrinsics family.
 * This test was created to check the correctness
 * of the following intrinsics support:
 *      _mm512_mask_compress*()
 *      _mm512_mask_compressstoreu*()
 *      _mm512_mask_expand*()
 *      _mm512_mask_expandloadu*()
 *      _mm512_maskz_compress*()
 *      _mm512_maskz_expand*()
 *      _mm512_maskz_expandloadu*()
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
__mmask16 k16;

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
  k16 = 0x25d6;
}

/*
 * Use this between tests to make compiler think src was updated.
 * Prevents PRE'ing of a load of src.
 */
#define soft_isrc1_update() isrc1.xmmi[vol0] = isrc1.xmmi[vol0]
#define soft_fsrc1_update() fsrc1.xmmi[vol0] = fsrc1.xmmi[vol0]
#define soft_dsrc1_update() dsrc1.xmmi[vol0] = dsrc1.xmmi[vol0]

/*
 * Model expand intrinsic behavior.
 */
void NOINLINE model_mask_expand_i32(void *input1, __int64 mask, void *input2,
                                    void *output, int n_elems) {
  int i, j = 0;
  int *v1i = (int *)input1;
  int *v2i = (int *)input2;
  int *v3o = (int *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[i] = v2i[j];
      j++;
    } else {
      v3o[i] = v1i[i];
    }
  }
}

void NOINLINE model_maskz_expand_i32(__int64 mask, void *input2, void *output,
                                     int n_elems) {
  int i, j = 0;
  int *v2i = (int *)input2;
  int *v3o = (int *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[i] = v2i[j];
      j++;
    } else {
      v3o[i] = 0;
    }
  }
}

void NOINLINE model_mask_expand_i64(void *input1, __int64 mask, void *input2,
                                    void *output, int n_elems) {
  int i, j = 0;
  __int64 *v1i = (__int64 *)input1;
  __int64 *v2i = (__int64 *)input2;
  __int64 *v3o = (__int64 *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[i] = v2i[j];
      j++;
    } else {
      v3o[i] = v1i[i];
    }
  }
}

void NOINLINE model_maskz_expand_i64(__int64 mask, void *input2, void *output,
                                     int n_elems) {
  int i, j = 0;
  __int64 *v2i = (__int64 *)input2;
  __int64 *v3o = (__int64 *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[i] = v2i[j];
      j++;
    } else {
      v3o[i] = 0;
    }
  }
}

void NOINLINE model_mask_expand_f32(void *input1, __int64 mask, void *input2,
                                    void *output, int n_elems) {
  int i, j = 0;
  float *v1i = (float *)input1;
  float *v2i = (float *)input2;
  float *v3o = (float *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[i] = v2i[j];
      j++;
    } else {
      v3o[i] = v1i[i];
    }
  }
}

void NOINLINE model_maskz_expand_f32(__int64 mask, void *input2, void *output,
                                     int n_elems) {
  int i, j = 0;
  float *v2i = (float *)input2;
  float *v3o = (float *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[i] = v2i[j];
      j++;
    } else {
      v3o[i] = 0.f;
    }
  }
}

void NOINLINE model_mask_expand_f64(void *input1, __int64 mask, void *input2,
                                    void *output, int n_elems) {
  int i, j = 0;
  double *v1i = (double *)input1;
  double *v2i = (double *)input2;
  double *v3o = (double *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[i] = v2i[j];
      j++;
    } else {
      v3o[i] = v1i[i];
    }
  }
}

void NOINLINE model_maskz_expand_f64(__int64 mask, void *input2, void *output,
                                     int n_elems) {
  int i, j = 0;
  double *v2i = (double *)input2;
  double *v3o = (double *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[i] = v2i[j];
      j++;
    } else {
      v3o[i] = 0.;
    }
  }
}

#define GEN_MASK_CHECK_CASE(intrin, prefix, suffix, mask, n_elem, modeller,    \
                            checker)                                           \
  res.suffix = intrin(prefix##src2.suffix, mask, prefix##src1.suffix);         \
  modeller((void *)&prefix##src2.suffix, mask, (void *)&prefix##src1.suffix,   \
           (void *)&mres.suffix, n_elem);                                      \
  checker((void *)&res.suffix, (void *)&mres.suffix, n_elem, #intrin, __LINE__)

#define GEN_MASK_LOAD_CHECK_CASE(intrin, prefix, suffix, mask, n_elem,         \
                                 modeller, checker)                            \
  res.suffix = intrin(prefix##src2.suffix, mask, &prefix##src1.suffix);        \
  modeller((void *)&prefix##src2.suffix, mask, (void *)&prefix##src1.suffix,   \
           (void *)&mres.suffix, n_elem);                                      \
  checker((void *)&res.suffix, (void *)&mres.suffix, n_elem, #intrin, __LINE__)

#define GEN_MASKZ_CHECK_CASE(intrin, prefix, suffix, mask, n_elem, modeller,   \
                             checker)                                          \
  res.suffix = intrin(mask, prefix##src1.suffix);                              \
  modeller(mask, (void *)&prefix##src1.suffix, (void *)&mres.suffix, n_elem);  \
  checker((void *)&res.suffix, (void *)&mres.suffix, n_elem, #intrin, __LINE__)

#define GEN_MASKZ_LOAD_CHECK_CASE(intrin, prefix, suffix, mask, n_elem,        \
                                  modeller, checker)                           \
  res.suffix = intrin(mask, &prefix##src1.suffix);                             \
  modeller(mask, (void *)&prefix##src1.suffix, (void *)&mres.suffix, n_elem);  \
  checker((void *)&res.suffix, (void *)&mres.suffix, n_elem, #intrin, __LINE__)

void NOINLINE do_m512_expand() {
  volatile V512 res;

  soft_isrc1_update();
  GEN_MASK_CHECK_CASE(_mm512_mask_expand_epi32, i, zmmi, k16, 16,
                      model_mask_expand_i32, check_equal_nd);

  soft_isrc1_update();
  GEN_MASK_LOAD_CHECK_CASE(_mm512_mask_expandloadu_epi32, i, zmmi, k16, 16,
                           model_mask_expand_i32, check_equal_nd);

  soft_isrc1_update();
  GEN_MASKZ_CHECK_CASE(_mm512_maskz_expand_epi32, i, zmmi, k16, 16,
                       model_maskz_expand_i32, check_equal_nd);

  soft_isrc1_update();
  GEN_MASKZ_LOAD_CHECK_CASE(_mm512_maskz_expandloadu_epi32, i, zmmi, k16, 16,
                            model_maskz_expand_i32, check_equal_nd);

  soft_isrc1_update();
  GEN_MASK_CHECK_CASE(_mm512_mask_expand_epi64, i, zmmi, k8, 8,
                      model_mask_expand_i64, check_equal_nq);

  soft_isrc1_update();
  GEN_MASK_LOAD_CHECK_CASE(_mm512_mask_expandloadu_epi64, i, zmmi, k8, 8,
                           model_mask_expand_i64, check_equal_nq);

  soft_isrc1_update();
  GEN_MASKZ_CHECK_CASE(_mm512_maskz_expand_epi64, i, zmmi, k8, 8,
                       model_maskz_expand_i64, check_equal_nq);

  soft_isrc1_update();
  GEN_MASKZ_LOAD_CHECK_CASE(_mm512_maskz_expandloadu_epi64, i, zmmi, k8, 8,
                            model_maskz_expand_i64, check_equal_nq);

  soft_fsrc1_update();
  GEN_MASK_CHECK_CASE(_mm512_mask_expand_ps, f, zmm, k16, 16,
                      model_mask_expand_f32, check_equal_nsf);

  soft_fsrc1_update();
  GEN_MASK_LOAD_CHECK_CASE(_mm512_mask_expandloadu_ps, f, zmm, k16, 16,
                           model_mask_expand_f32, check_equal_nsf);

  soft_fsrc1_update();
  GEN_MASKZ_CHECK_CASE(_mm512_maskz_expand_ps, f, zmm, k16, 16,
                       model_maskz_expand_f32, check_equal_nsf);

  soft_fsrc1_update();
  GEN_MASKZ_LOAD_CHECK_CASE(_mm512_maskz_expandloadu_ps, f, zmm, k16, 16,
                            model_maskz_expand_f32, check_equal_nsf);

  soft_dsrc1_update();
  GEN_MASK_CHECK_CASE(_mm512_mask_expand_pd, d, zmmd, k8, 8,
                      model_mask_expand_f64, check_equal_ndf);

  soft_dsrc1_update();
  GEN_MASK_LOAD_CHECK_CASE(_mm512_mask_expandloadu_pd, d, zmmd, k8, 8,
                           model_mask_expand_f64, check_equal_ndf);

  soft_dsrc1_update();
  GEN_MASKZ_CHECK_CASE(_mm512_maskz_expand_pd, d, zmmd, k8, 8,
                       model_maskz_expand_f64, check_equal_ndf);

  soft_dsrc1_update();
  GEN_MASKZ_LOAD_CHECK_CASE(_mm512_maskz_expandloadu_pd, d, zmmd, k8, 8,
                            model_maskz_expand_f64, check_equal_ndf);
}

/*
 * Model compress intrinsic behavior.
 */
void NOINLINE model_mask_compress_i32(void *input1, __int64 mask, void *input2,
                                      void *output, int n_elems) {
  int i, j = 0;
  int *v1i = (int *)input1;
  int *v2i = (int *)input2;
  int *v3o = (int *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[j] = v2i[i];
      j++;
    }
  }

  for (i = j; i < n_elems; i++) {
    v3o[i] = v1i[i];
  }
}

void NOINLINE model_maskz_compress_i32(__int64 mask, void *input2, void *output,
                                       int n_elems) {
  int i, j = 0;
  int *v2i = (int *)input2;
  int *v3o = (int *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[j] = v2i[i];
      j++;
    }
  }

  for (i = j; i < n_elems; i++) {
    v3o[i] = 0;
  }
}

void NOINLINE model_mask_compress_i64(void *input1, __int64 mask, void *input2,
                                      void *output, int n_elems) {
  int i, j = 0;
  __int64 *v1i = (__int64 *)input1;
  __int64 *v2i = (__int64 *)input2;
  __int64 *v3o = (__int64 *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[j] = v2i[i];
      j++;
    }
  }

  for (i = j; i < n_elems; i++) {
    v3o[i] = v1i[i];
  }
}

void NOINLINE model_maskz_compress_i64(__int64 mask, void *input2, void *output,
                                       int n_elems) {
  int i, j = 0;
  __int64 *v2i = (__int64 *)input2;
  __int64 *v3o = (__int64 *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[j] = v2i[i];
      j++;
    }
  }

  for (i = j; i < n_elems; i++) {
    v3o[i] = 0;
  }
}

void NOINLINE model_mask_compress_f32(void *input1, __int64 mask, void *input2,
                                      void *output, int n_elems) {
  int i, j = 0;
  float *v1i = (float *)input1;
  float *v2i = (float *)input2;
  float *v3o = (float *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[j] = v2i[i];
      j++;
    }
  }

  for (i = j; i < n_elems; i++) {
    v3o[i] = v1i[i];
  }
}

void NOINLINE model_maskz_compress_f32(__int64 mask, void *input2, void *output,
                                       int n_elems) {
  int i, j = 0;
  float *v2i = (float *)input2;
  float *v3o = (float *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[j] = v2i[i];
      j++;
    }
  }

  for (i = j; i < n_elems; i++) {
    v3o[i] = 0;
  }
}

void NOINLINE model_mask_compress_f64(void *input1, __int64 mask, void *input2,
                                      void *output, int n_elems) {
  int i, j = 0;
  double *v1i = (double *)input1;
  double *v2i = (double *)input2;
  double *v3o = (double *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[j] = v2i[i];
      j++;
    }
  }

  for (i = j; i < n_elems; i++) {
    v3o[i] = v1i[i];
  }
}

void NOINLINE model_maskz_compress_f64(__int64 mask, void *input2, void *output,
                                       int n_elems) {
  int i, j = 0;
  double *v2i = (double *)input2;
  double *v3o = (double *)output;

  for (i = 0; i < n_elems; i++) {
    if ((mask & (1LL << i)) != 0) {
      v3o[j] = v2i[i];
      j++;
    }
  }

  for (i = j; i < n_elems; i++) {
    v3o[i] = 0;
  }
}

#define GEN_MASK_STORE_CHECK_CASE(intrin, prefix, suffix, mask, n_elem,        \
                                  modeller, checker)                           \
  intrin((void *)&res.suffix, mask, prefix##src1.suffix);                      \
  modeller((void *)&prefix##src2.suffix, mask, (void *)&prefix##src1.suffix,   \
           (void *)&mres.suffix, n_elem);                                      \
  checker((void *)&res.suffix, (void *)&mres.suffix, n_elem, #intrin, __LINE__)

void NOINLINE do_m512_compress() {
  volatile V512 res;

  soft_isrc1_update();
  GEN_MASK_CHECK_CASE(_mm512_mask_compress_epi32, i, zmmi, k16, 16,
                      model_mask_compress_i32, check_equal_nd);

  soft_isrc1_update();
  GEN_MASK_STORE_CHECK_CASE(_mm512_mask_compressstoreu_epi32, i, zmmi, k16, 16,
                            model_mask_compress_i32, check_equal_nd);

  soft_isrc1_update();
  GEN_MASKZ_CHECK_CASE(_mm512_maskz_compress_epi32, i, zmmi, k16, 16,
                       model_maskz_compress_i32, check_equal_nd);

  soft_isrc1_update();
  GEN_MASK_CHECK_CASE(_mm512_mask_compress_epi64, i, zmmi, k8, 8,
                      model_mask_compress_i64, check_equal_nq);

  soft_isrc1_update();
  GEN_MASK_STORE_CHECK_CASE(_mm512_mask_compressstoreu_epi64, i, zmmi, k8, 8,
                            model_mask_compress_i64, check_equal_nq);

  soft_isrc1_update();
  GEN_MASKZ_CHECK_CASE(_mm512_maskz_compress_epi64, i, zmmi, k8, 8,
                       model_maskz_compress_i64, check_equal_nq);

  soft_fsrc1_update();
  GEN_MASK_CHECK_CASE(_mm512_mask_compress_ps, f, zmm, k16, 16,
                      model_mask_compress_f32, check_equal_nsf);

  soft_fsrc1_update();
  GEN_MASK_STORE_CHECK_CASE(_mm512_mask_compressstoreu_ps, f, zmm, k16, 16,
                            model_mask_compress_f32, check_equal_nsf);

  soft_fsrc1_update();
  GEN_MASKZ_CHECK_CASE(_mm512_maskz_compress_ps, f, zmm, k16, 16,
                       model_maskz_compress_f32, check_equal_nsf);

  soft_dsrc1_update();
  GEN_MASK_CHECK_CASE(_mm512_mask_compress_pd, d, zmmd, k8, 8,
                      model_mask_compress_f64, check_equal_ndf);

  soft_dsrc1_update();
  GEN_MASK_STORE_CHECK_CASE(_mm512_mask_compressstoreu_pd, d, zmmd, k8, 8,
                            model_mask_compress_f64, check_equal_ndf);

  soft_dsrc1_update();
  GEN_MASKZ_CHECK_CASE(_mm512_maskz_compress_pd, d, zmmd, k8, 8,
                       model_maskz_compress_f64, check_equal_ndf);
}

int main() {
  init();

  do_m512_expand();
  do_m512_compress();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
