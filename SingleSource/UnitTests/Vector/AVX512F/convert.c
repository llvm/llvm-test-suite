/*
 * Exercise some convert instructions.
 * This test was created to check the correctness
 * of the following intrinsics support:
 * _mm512_cvt_roundph_ps()
 * _mm512_mask_cvt_roundph_ps()
 * _mm512_maskz_cvt_roundph_ps()
 * _mm512_cvtph_ps()
 * _mm512_mask_cvtph_ps()
 * _mm512_maskz_cvtph_ps()
 * _mm512_cvt_roundps_ph()
 * _mm512_mask_cvt_roundps_ph()
 * _mm512_maskz_cvt_roundps_ph()
 * _mm512_cvtps_ph()
 * _mm512_mask_cvtps_ph()
 * _mm512_maskz_cvtps_ph()
 */

#include <stdio.h>
#include <string.h>
#include <x86intrin.h>

typedef union V256 {
  __m128i m128i;
  __m128 m128;
  __m128d m128d;
  __m256 m256;
  __m256d m256d;
  __m256i m256i;
  short w[16];
  int d[8];
  long long q[4];
  float ps[8];
  double pd[4];

  int i32;
  unsigned int u32;
  __int64 i64;
  unsigned __int64 u64;
} V256;

int n_errors = 0;

void print(const char *str, int num_elts, int elt_size, V256 *p, int is_float) {
  int i;

  if (elt_size == 2 && is_float) {
    if (num_elts == 4) {
      p->m128 = _mm_cvtph_ps(p->m128i);
    } else {
      p->m256 = _mm256_cvtph_ps(p->m128i);
    }
  }

  printf("%s = {", str);
  for (i = 0; i < num_elts; i++) {
    if (!is_float) {
      int val;
      switch (elt_size) {
      case 2:
        val = p->w[i];
        break;
      case 4:
        val = p->d[i];
        break;
      case 8:
        val = p->q[i];
        break;
      }
      printf("%s %3d", i == 0 ? "" : ",", val);
    } else {
      float val;
      switch (elt_size) {
      case 2:
        val = p->ps[i];
        break;
      case 4:
        val = p->ps[i];
        break;
      case 8:
        val = p->pd[i];
        break;
      }
      printf("%s %.3f", i == 0 ? "" : ",", val);
    }
  }
  printf("}\n");
}

__declspec(noinline) void check(int is_float, int elt_size, int num_elts,
                                void *v1, void *v2, const char *str) {
  if (memcmp(v1, v2, elt_size * num_elts) != 0) {
    ++n_errors;
    printf("FAILED: %dx%d (%s)\n", elt_size, num_elts, str);

    print("exp", num_elts, elt_size, v1, is_float);
    print("got", num_elts, elt_size, v2, is_float);
  }
}

#define r _MM_FROUND_NO_EXC
int mask = 0xAAA; // b101010101010

void float16_converts() {

#define M512 _mm512_set_ps

#define M512_RES M512(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)
#define M512_PASS                                                              \
  M512(11, 22, 33, 44, 55, 66, 77, 88, 99, 1010, 1111, 1212, 1313, 1414, 1515, \
       1616)
#define M512_RES_MASK                                                          \
  M512(11, 22, 33, 44, 5, 66, 7, 88, 9, 1010, 11, 1212, 13, 1414, 15, 1616)
#define M512_RES_MASKZ M512(0, 0, 0, 0, 5, 0, 7, 0, 9, 0, 11, 0, 13, 0, 15, 0)

#define M256H_SRC _mm512_cvt_roundps_ph(M512_RES, r)

  {
    __m512 got = _mm512_cvt_roundph_ps(M256H_SRC, r);
    __m512 exp = M512_RES;
    check(1, 4, 16, &exp, &got, "_mm512_cvt_roundph_ps");
  }
  {
    __m512 got = _mm512_mask_cvt_roundph_ps(M512_PASS, mask, M256H_SRC, r);
    __m512 exp = M512_RES_MASK;
    check(1, 4, 16, &exp, &got, "_mm512_mask_cvt_roundph_ps");
  }
  {
    __m512 got = _mm512_maskz_cvt_roundph_ps(mask, M256H_SRC, r);
    __m512 exp = M512_RES_MASKZ;
    check(1, 4, 16, &exp, &got, "_mm512_maskz_cvt_roundph_ps");
  }

  {
    __m512 got = _mm512_cvtph_ps(M256H_SRC);
    __m512 exp = M512_RES;
    check(1, 4, 16, &exp, &got, "_mm512_cvtph_ps");
  }
  {
    __m512 got = _mm512_mask_cvtph_ps(M512_PASS, mask, M256H_SRC);
    __m512 exp = M512_RES_MASK;
    check(1, 4, 16, &exp, &got, "_mm512_mask_cvtph_ps");
  }
  {
    __m512 got = _mm512_maskz_cvtph_ps(mask, M256H_SRC);
    __m512 exp = M512_RES_MASKZ;
    check(1, 4, 16, &exp, &got, "_mm512_maskz_cvtph_ps");
  }

#define M512_SRC M512(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)

#define M256H(m512) _mm512_cvt_roundps_ph(m512, r)

#define M256H_PASS                                                             \
  M256H(M512(11, 22, 33, 44, 55, 66, 77, 88, 99, 1010, 1111, 1212, 1313, 1414, \
             1515, 1616))
#define M256H_RES M256H(M512_SRC)
#define M256H_RES_MASK                                                         \
  M256H(M512(11, 22, 33, 44, 5, 66, 7, 88, 9, 1010, 11, 1212, 13, 1414, 15,    \
             1616))
#define M256H_RES_MASKZ                                                        \
  M256H(M512(0, 0, 0, 0, 5, 0, 7, 0, 9, 0, 11, 0, 13, 0, 15, 0))

  {
    V256 got, exp;
    got.m256i = _mm512_cvt_roundps_ph(M512_SRC, r);
    exp.m256i = M256H_RES;
    check(1, 2, 16, &exp, &got, "_mm512_cvt_roundps_ph");
  }
  {
    V256 got, exp;
    got.m256i = _mm512_mask_cvt_roundps_ph(M256H_PASS, mask, M512_SRC, r);
    exp.m256i = M256H_RES_MASK;
    check(1, 2, 16, &exp, &got, "_mm512_mask_cvt_roundps_ph");
  }
  {
    V256 got, exp;
    got.m256i = _mm512_maskz_cvt_roundps_ph(mask, M512_SRC, r);
    exp.m256i = M256H_RES_MASKZ;
    check(1, 2, 16, &exp, &got, "_mm512_maskz_cvt_roundps_ph");
  }

  {
    V256 got, exp;
    got.m256i = _mm512_cvtps_ph(M512_SRC, r);
    exp.m256i = M256H_RES;
    check(1, 2, 16, &exp, &got, "_mm512_cvtps_ph");
  }
  {
    V256 got, exp;
    got.m256i = _mm512_mask_cvtps_ph(M256H_PASS, mask, M512_SRC, r);
    exp.m256i = M256H_RES_MASK;
    check(1, 2, 16, &exp, &got, "_mm512_mask_cvtps_ph");
  }
  {
    V256 got, exp;
    got.m256i = _mm512_maskz_cvtps_ph(mask, M512_SRC, r);
    exp.m256i = M256H_RES_MASKZ;
    check(1, 2, 16, &exp, &got, "_mm512_maskz_cvtps_ph");
  }
}

__declspec(noinline) void scalar_converts() {

#define M128SD(scalar) _mm_set_pd(123, scalar)

#define CHECK__(core, src, res_type, res)                                      \
  {                                                                            \
    V256 got, exp;                                                             \
    ((got).res_type) = _mm_##core src;                                         \
    ((exp).res_type) = res;                                                    \
    check(0, sizeof((exp).res_type), 1, &exp, &got, "_mm_" #core);             \
  }

#if defined(__x86_64) || defined(_M_X64)
#define CHECK64 CHECK__
#else
#define CHECK64(core, src, res_type, res)
#endif

#undef R
#define R _MM_FROUND_FLOOR | _MM_FROUND_NO_EXC

  CHECK__(cvt_roundsd_i32, (M128SD(100.7), R), i32, 100)
  CHECK__(cvtsd_i32, (M128SD(100.7)), i32, 101)
  CHECK__(cvtsd_si32, (M128SD(100.7)), i32, 101)
  CHECK__(cvt_roundsd_u32, (M128SD(100.7), R), u32, 100)
  CHECK__(cvtsd_u32, (M128SD(100.7)), u32, 101)

  CHECK64(cvt_roundsd_i64, (M128SD(100.7), R), i64, 100)
  CHECK64(cvtsd_i64, (M128SD(100.7)), i64, 101)
  CHECK64(cvtsd_si64, (M128SD(100.7)), i64, 101)
  CHECK64(cvt_roundsd_u64, (M128SD(100.7), R), u64, 100)
  CHECK64(cvtsd_u64, (M128SD(100.7)), u64, 101)

#undef R
#define R _MM_FROUND_NO_EXC

  CHECK__(cvtt_roundsd_i32, (M128SD(100.7), R), i32, 100)
  CHECK__(cvttsd_i32, (M128SD(100.7)), i32, 100)
  CHECK__(cvttsd_si32, (M128SD(100.7)), i32, 100)
  CHECK__(cvtt_roundsd_u32, (M128SD(100.7), R), u32, 100)
  CHECK__(cvttsd_u32, (M128SD(100.7)), u32, 100)

  CHECK64(cvtt_roundsd_i64, (M128SD(100.7), R), i64, 100)
  CHECK64(cvttsd_i64, (M128SD(100.7)), i64, 100)
  CHECK64(cvttsd_si64, (M128SD(100.7)), i64, 100)
  CHECK64(cvtt_roundsd_u64, (M128SD(100.7), R), u64, 100)
  CHECK64(cvttsd_u64, (M128SD(100.7)), u64, 100)

  CHECK64(cvt_roundi64_sd, (M128SD(100.7), 35, R), m128d, M128SD(35))
  CHECK64(cvt_roundsi64_sd, (M128SD(100.7), 35, R), m128d, M128SD(35))
  CHECK64(cvt_roundu64_sd, (M128SD(100.7), 35, R), m128d, M128SD(35))
  CHECK64(cvti64_sd, (M128SD(100.7), 35), m128d, M128SD(35))
  CHECK64(cvtsi64_sd, (M128SD(100.7), 35), m128d, M128SD(35))
  CHECK64(cvtu64_sd, (M128SD(100.7), 35), m128d, M128SD(35))

  // Rounding not supported for [ui]32->sd
  CHECK__(cvti32_sd, (M128SD(100.7), 35), m128d, M128SD(35))
  CHECK__(cvtsi32_sd, (M128SD(100.7), 35), m128d, M128SD(35))
  CHECK__(cvtu32_sd, (M128SD(100.7), 35), m128d, M128SD(35))

#define M128SS(scalar) _mm_set_ps(1, 2, 3, scalar)
#undef R
#define R _MM_FROUND_FLOOR | _MM_FROUND_NO_EXC

  CHECK__(cvt_roundss_i32, (M128SS(100.7), R), i32, 100)
  CHECK__(cvt_roundss_u32, (M128SS(100.7), R), u32, 100)
  CHECK__(cvtss_i32, (M128SS(100.7)), i32, 101)
  CHECK__(cvtss_si32, (M128SS(100.7)), i32, 101)
  CHECK__(cvtss_u32, (M128SS(100.7)), u32, 101)

  CHECK64(cvt_roundss_i64, (M128SS(100.7), R), i64, 100)
  CHECK64(cvt_roundss_u64, (M128SS(100.7), R), u64, 100)
  CHECK64(cvtss_i64, (M128SS(100.7)), i64, 101)
  CHECK64(cvtss_si64, (M128SS(100.7)), i64, 101)
  CHECK64(cvtss_u64, (M128SS(100.7)), u64, 101)

#undef R
#define R _MM_FROUND_NO_EXC

  CHECK__(cvtt_roundss_i32, (M128SS(100.7), R), i32, 100)
  CHECK__(cvtt_roundss_u32, (M128SS(100.7), R), u32, 100)
  CHECK__(cvttss_i32, (M128SS(100.7)), i32, 100)
  CHECK__(cvttss_si32, (M128SS(100.7)), i32, 100)
  CHECK__(cvttss_u32, (M128SS(100.7)), u32, 100)

  CHECK64(cvtt_roundss_i64, (M128SS(100.7), R), i64, 100)
  CHECK64(cvtt_roundss_u64, (M128SS(100.7), R), u64, 100)
  CHECK64(cvttss_i64, (M128SS(100.7)), i64, 100)
  CHECK64(cvttss_si64, (M128SS(100.7)), i64, 100)
  CHECK64(cvttss_u64, (M128SS(100.7)), u64, 100)

  CHECK__(cvt_roundi32_ss, (M128SS(100.7), 47, R), m128, M128SS(47))
  CHECK__(cvt_roundsi32_ss, (M128SS(100.7), 47, R), m128, M128SS(47))
  CHECK__(cvt_roundu32_ss, (M128SS(100.7), 47, R), m128, M128SS(47))
  CHECK__(cvti32_ss, (M128SS(100.7), 47), m128, M128SS(47))
  CHECK__(cvtsi32_ss, (M128SS(100.7), 47), m128, M128SS(47))
  CHECK__(cvtu32_ss, (M128SS(100.7), 47), m128, M128SS(47))

  CHECK64(cvt_roundi64_ss, (M128SS(100.7), 47, R), m128, M128SS(47))
  CHECK64(cvt_roundsi64_ss, (M128SS(100.7), 47, R), m128, M128SS(47))
  CHECK64(cvt_roundu64_ss, (M128SS(100.7), 47, R), m128, M128SS(47))
  CHECK64(cvti64_ss, (M128SS(100.7), 47), m128, M128SS(47))
  CHECK64(cvtsi64_ss, (M128SS(100.7), 47), m128, M128SS(47))
  CHECK64(cvtu64_ss, (M128SS(100.7), 47), m128, M128SS(47))

#undef R
#define R _MM_FROUND_NO_EXC

#define CHECK_M128D(core, src, res_type, res)                                  \
  {                                                                            \
    V256 got, exp;                                                             \
    ((got).res_type) = _mm_##core src;                                         \
    ((exp).res_type) = res;                                                    \
    check(1, 8, 2, &exp, &got, "_mm_" #core);                                  \
  }

#define M128D(a, b) _mm_set_pd(a, b)

  CHECK_M128D(cvt_roundss_sd, (M128D(1, 11) /*src1*/, M128SS(51) /*src2*/, R),
              m128d, M128D(1, 51))
  CHECK_M128D(cvtss_sd, (M128D(1, 11), M128SS(51)), m128d, M128D(1, 51))

  // For masked operations we check both 0 and 1 masks
  //
  CHECK_M128D(
      mask_cvt_roundss_sd,
      (M128D(1, 11) /*dest*/, 1, M128D(2, 22) /*src1*/, M128SS(51) /*src2*/, R),
      m128d, M128D(2, 51))
  CHECK_M128D(mask_cvt_roundss_sd,
              (M128D(1, 11), 0, M128D(2, 22), M128SS(51), R), m128d,
              M128D(2, 11))

  CHECK_M128D(
      mask_cvtss_sd,
      (M128D(1, 11) /*dest*/, 1, M128D(2, 22) /*src1*/, M128SS(51) /*src2*/),
      m128d, M128D(2, 51))
  CHECK_M128D(mask_cvtss_sd, (M128D(1, 11), 0, M128D(2, 22), M128SS(51)), m128d,
              M128D(2, 11))

  CHECK_M128D(maskz_cvt_roundss_sd,
              (1, M128D(2, 22) /*src1*/, M128SS(51) /*src2*/, R), m128d,
              M128D(2, 51))
  CHECK_M128D(maskz_cvt_roundss_sd, (0, M128D(2, 22), M128SS(51), R), m128d,
              M128D(2, 0))

  CHECK_M128D(maskz_cvtss_sd, (1, M128D(2, 22) /*src1*/, M128SS(51) /*src2*/),
              m128d, M128D(2, 51))
  CHECK_M128D(maskz_cvtss_sd, (0, M128D(2, 22), M128SS(51)), m128d, M128D(2, 0))

#define M128(a, b, c, d) _mm_set_ps(a, b, c, d)
#define CHECK_M128(core, src, res_type, res)                                   \
  {                                                                            \
    V256 got, exp;                                                             \
    ((got).res_type) = _mm_##core src;                                         \
    ((exp).res_type) = res;                                                    \
    check(1, 4, 4, &exp, &got, "_mm_" #core);                                  \
  }

  CHECK_M128(cvt_roundsd_ss,
             (M128(1, 11, 111, 1111) /*src1*/, M128D(2, 22) /*src2*/, R), m128,
             M128(1, 11, 111, 22))
  CHECK_M128(cvtsd_ss, (M128(1, 11, 111, 1111), M128D(2, 22)), m128,
             M128(1, 11, 111, 22))

  // For masked operations we check both 0 and 1 masks
  //
  CHECK_M128(mask_cvt_roundsd_ss,
             (M128(1, 11, 111, 1111) /*dest*/, 1,
              M128(2, 22, 222, 2222) /*src1*/, M128D(3, 33) /*src2*/, R),
             m128, M128(2, 22, 222, 33))
  CHECK_M128(mask_cvt_roundsd_ss,
             (M128(1, 11, 111, 1111) /*dest*/, 0,
              M128(2, 22, 222, 2222) /*src1*/, M128D(3, 33) /*src2*/, R),
             m128, M128(2, 22, 222, 1111))

  CHECK_M128(mask_cvtsd_ss,
             (M128(1, 11, 111, 1111) /*dest*/, 1,
              M128(2, 22, 222, 2222) /*src1*/, M128D(3, 33) /*src2*/),
             m128, M128(2, 22, 222, 33))
  CHECK_M128(mask_cvtsd_ss,
             (M128(1, 11, 111, 1111) /*dest*/, 0,
              M128(2, 22, 222, 2222) /*src1*/, M128D(3, 33) /*src2*/),
             m128, M128(2, 22, 222, 1111))

  CHECK_M128(maskz_cvt_roundsd_ss,
             (1, M128(2, 22, 222, 2222) /*src1*/, M128D(3, 33) /*src2*/, R),
             m128, M128(2, 22, 222, 33))
  CHECK_M128(maskz_cvt_roundsd_ss,
             (0, M128(2, 22, 222, 2222) /*src1*/, M128D(3, 33) /*src2*/, R),
             m128, M128(2, 22, 222, 0))

  CHECK_M128(maskz_cvtsd_ss,
             (1, M128(2, 22, 222, 2222) /*src1*/, M128D(3, 33) /*src2*/), m128,
             M128(2, 22, 222, 33))
  CHECK_M128(maskz_cvtsd_ss,
             (0, M128(2, 22, 222, 2222) /*src1*/, M128D(3, 33) /*src2*/), m128,
             M128(2, 22, 222, 0))
}

int main(void) {
  float16_converts();
  scalar_converts();

  if (n_errors) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
