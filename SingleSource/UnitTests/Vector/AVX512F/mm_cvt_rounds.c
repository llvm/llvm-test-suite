/* This test was created to check the correctness
 * of the following intrinsics support:
 * _mm_cvt_roundsd_si32
 * _mm_cvt_roundsd_si64
 * _mm_cvt_roundss_si32
 * _mm_cvt_roundss_si64
 * _mm_cvtt_roundsd_si32
 * _mm_cvtt_roundsd_si64
 * _mm_cvtt_roundss_si32
 * _mm_cvtt_roundss_si64
 */
#include "m512_test_util.h"

#define DO_SS2SI32(f, r, exp)                                                  \
  src = _mm_set_ss(f);                                                         \
  res = _mm_cvt_roundss_si32(src, r | _MM_FROUND_NO_EXC);                      \
  if (res != exp) {                                                            \
    printf("cvt_roundss_si32(%f) = %d (expected %d)\n", f, res, exp);          \
    n_errs++;                                                                  \
  }

#define DO_SS2SI32T(f, r, exp)                                                 \
  src = _mm_set_ss(f);                                                         \
  res = _mm_cvtt_roundss_si32(src, r);                                         \
  if (res != exp) {                                                            \
    printf("cvtt_roundss_si32(%f) = %d (expected %d)\n", f, res, exp);         \
    n_errs++;                                                                  \
  }

#define DO_SS2SI64(f, r, exp)                                                  \
  src = _mm_set_ss(f);                                                         \
  lres = _mm_cvt_roundss_si64(src, r | _MM_FROUND_NO_EXC);                     \
  if (lres != exp) {                                                           \
    printf("cvt_roundss_si64(%f) = %lld (expected %lld)\n", f, lres, exp);     \
    n_errs++;                                                                  \
  }

#define DO_SS2SI64T(f, r, exp)                                                 \
  src = _mm_set_ss(f);                                                         \
  lres = _mm_cvtt_roundss_si64(src, r);                                        \
  if (lres != exp) {                                                           \
    printf("cvt_roundss_si64(%f) = %lld (expected %lld)\n", f, lres, exp);     \
    n_errs++;                                                                  \
  }

#define DO_SD2SI32(f, r, exp)                                                  \
  dsrc = _mm_set_sd(f);                                                        \
  res = _mm_cvt_roundsd_si32(dsrc, r | _MM_FROUND_NO_EXC);                     \
  if (res != exp) {                                                            \
    printf("cvt_roundsd_si32(%f) = %d (expected %d)\n", f, res, exp);          \
    n_errs++;                                                                  \
  }

#define DO_SD2SI32T(f, r, exp)                                                 \
  dsrc = _mm_set_sd(f);                                                        \
  res = _mm_cvtt_roundsd_si32(dsrc, r);                                        \
  if (res != exp) {                                                            \
    printf("cvtt_roundsd_si32(%f) = %d (expected %d)\n", f, res, exp);         \
    n_errs++;                                                                  \
  }

#define DO_SD2SI64(f, r, exp)                                                  \
  dsrc = _mm_set_sd(f);                                                        \
  lres = _mm_cvt_roundsd_si64(dsrc, r | _MM_FROUND_NO_EXC);                    \
  if (lres != exp) {                                                           \
    printf("cvt_roundsd_si64(%f) = %lld (expected %lld)\n", f, lres, exp);     \
    n_errs++;                                                                  \
  }

#define DO_SD2SI64T(f, r, exp)                                                 \
  dsrc = _mm_set_sd(f);                                                        \
  lres = _mm_cvtt_roundsd_si64(dsrc, r);                                       \
  if (lres != exp) {                                                           \
    printf("cvt_roundsd_si64(%f) = %lld (expected %lld)\n", f, lres, exp);     \
    n_errs++;                                                                  \
  }

void NOINLINE do_cvt_roundss() {
  __m128 src;
  int res;
  __int64 lres;

  DO_SS2SI32(1.6f, _MM_FROUND_NO_EXC, 2);
  DO_SS2SI32(-1.6f, _MM_FROUND_TO_ZERO, -1);
  DO_SS2SI32(-1.1f, _MM_FROUND_TO_NEG_INF, -2);
  DO_SS2SI32(-1.1f, _MM_FROUND_TO_POS_INF, -1);
  DO_SS2SI32(10.8f, _MM_FROUND_TO_ZERO, 10);
  DO_SS2SI32T(1.6f, _MM_FROUND_NO_EXC, 1);

#if defined(__x86_64) || defined(_M_X64)
  DO_SS2SI64(1.6f, _MM_FROUND_NO_EXC, 2ll);
  DO_SS2SI64(-1.6f, _MM_FROUND_TO_ZERO, -1ll);
  DO_SS2SI64(-1.1f, _MM_FROUND_TO_NEG_INF, -2ll);
  DO_SS2SI64(-1.1f, _MM_FROUND_TO_POS_INF, -1ll);
  DO_SS2SI64(10.8f, _MM_FROUND_TO_ZERO, 10ll);
  DO_SS2SI64T(1.6f, _MM_FROUND_NO_EXC, 1ll);
#endif
}

void NOINLINE do_cvt_roundsd() {
  __m128d dsrc;
  int res;
  __int64 lres;

  DO_SD2SI32(1.6, _MM_FROUND_NO_EXC, 2);
  DO_SD2SI32(-1.6, _MM_FROUND_TO_ZERO, -1);
  DO_SD2SI32(-1.1, _MM_FROUND_TO_NEG_INF, -2);
  DO_SD2SI32(-1.1, _MM_FROUND_TO_POS_INF, -1);
  DO_SD2SI32(10.8, _MM_FROUND_TO_ZERO, 10);
  DO_SD2SI32T(1.6, _MM_FROUND_NO_EXC, 1);

#if defined(__x86_64) || defined(_M_X64)
  DO_SD2SI64(1.6, _MM_FROUND_NO_EXC, 2ll);
  DO_SD2SI64(-1.6, _MM_FROUND_TO_ZERO, -1ll);
  DO_SD2SI64(-1.1, _MM_FROUND_TO_NEG_INF, -2ll);
  DO_SD2SI64(-1.1, _MM_FROUND_TO_POS_INF, -1ll);
  DO_SD2SI64(10.8, _MM_FROUND_TO_ZERO, 10ll);
  DO_SD2SI64T(1.6, _MM_FROUND_NO_EXC, 1ll);
#endif
}

int main() {
  do_cvt_roundss();
  do_cvt_roundsd();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
