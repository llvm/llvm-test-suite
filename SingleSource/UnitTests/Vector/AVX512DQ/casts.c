/*
 * Here we check for _mm512_cast* and _mm512_xor_* intrinsics.
 */
#include "m512_test_util.h"

volatile int vol = 0; /* Inhibit optimization */

__m512 f1, f2, f3, f3_orig;
__m512d d1, d2, d3, d3_orig;
__m512i i1, i2, i3, i3_orig;

void NOINLINE set_nonzero(void *vp, int c) {
  int i;
  V512 *v = (V512 *)vp;

  for (i = 0; i < 16; i++) {
    v->u32[i] = 10 * i * i - 3 * i + c;
    if (v->u32[i] == 0) {
      v->u32[i] = 1234;
    }
  }
}

void NOINLINE check_zero(void *vp, char *banner) {
  int i;
  V512 *v = (V512 *)vp;

  for (i = 0; i < 16; i++) {
    if (v->u32[i] + vol != 0) {
      printf("ERROR: %s failed\n", banner ? banner : "");
      n_errs++;
      break;
    }
  }
}

void NOINLINE do_setzero() {
  set_nonzero(&f1, 18);
  f1 = _mm512_setzero_ps();
  check_zero(&f1, "_mm512_setzero_ps");

  set_nonzero(&f2, 19);
  f2 = _mm512_setzero();
  check_zero(&f2, "_mm512_setzero");

  set_nonzero(&d1, 20);
  d1 = _mm512_setzero_pd();
  check_zero(&d1, "_mm512_setzero_pd");

  set_nonzero(&i1, 21);
  i1 = _mm512_setzero_epi32();
  check_zero(&i1, "_mm512_setzero_epi32");
}

void NOINLINE do_cast() {
  set_nonzero(&f1, 1);
  d1 = _mm512_setzero_pd();
  f1 = _mm512_castpd_ps(d1);
  check_zero(&f1, "_mm512_castpd_ps");

  set_nonzero(&i1, 1);
  d1 = _mm512_setzero_pd();
  i1 = _mm512_castpd_si512(d1);
  check_zero(&i1, "_mm512_castpd_si512");

  set_nonzero(&d2, 1);
  f2 = _mm512_setzero_ps();
  d2 = _mm512_castps_pd(f2);
  check_zero(&d2, "_mm512_castps_pd");

  set_nonzero(&i2, 1);
  f2 = _mm512_setzero_ps();
  i2 = _mm512_castps_si512(f2);
  check_zero(&i2, "_mm512_castps_si512");

  set_nonzero(&f3, 1);
  i3 = _mm512_setzero_epi32();
  f3 = _mm512_castsi512_ps(i3);
  check_zero(&f3, "_mm512_castsi512_ps");

  set_nonzero(&d3, 1);
  i3 = _mm512_setzero_epi32();
  d3 = _mm512_castsi512_pd(i3);
  check_zero(&d3, "_mm512_castsi512_pd");
}

void NOINLINE do_size_casts() {
  __m128d xd;
  __m128 xs;
  __m128i xi;
  __m256d yd;
  __m256 ys;
  __m256i yi;
  __m512d zd;
  __m512 zs;
  __m512i zi;

  set_nonzero(&f1, 1);
  set_nonzero(&i1, 1);
  set_nonzero(&d1, 1);

  xd = _mm512_castpd512_pd128(d1);
  check_equal_nd(&xd, &d1, 4, "_mm512_castpd512_pd128", __LINE__);
  xs = _mm512_castps512_ps128(f1);
  check_equal_nd(&xs, &f1, 4, "_mm512_castps512_ps128", __LINE__);
  xi = _mm512_castsi512_si128(i1);
  check_equal_nd(&xi, &i1, 4, "_mm512_castsi512_si128", __LINE__);

  yd = _mm512_castpd512_pd256(d1);
  check_equal_nd(&yd, &d1, 8, "_mm512_castpd512_pd256", __LINE__);
  ys = _mm512_castps512_ps256(f1);
  check_equal_nd(&ys, &f1, 8, "_mm512_castps512_ps256", __LINE__);
  yi = _mm512_castsi512_si256(i1);
  check_equal_nd(&yi, &i1, 8, "_mm512_castsi512_si256", __LINE__);

  zd = _mm512_castpd128_pd512(xd);
  check_equal_nd(&zd, &d1, 4, "_mm512_castpd128_pd512", __LINE__);
  zs = _mm512_castps128_ps512(xs);
  check_equal_nd(&zs, &f1, 4, "_mm512_castps128_ps512", __LINE__);
  zi = _mm512_castsi128_si512(xi);
  check_equal_nd(&zi, &i1, 4, "_mm512_castsi128_si512", __LINE__);

  zd = _mm512_castpd256_pd512(yd);
  check_equal_nd(&zd, &d1, 8, "_mm512_castpd256_pd512", __LINE__);
  zs = _mm512_castps256_ps512(ys);
  check_equal_nd(&zs, &f1, 8, "_mm512_castps256_ps512", __LINE__);
  zi = _mm512_castsi256_si512(yi);
  check_equal_nd(&zi, &i1, 8, "_mm512_castsi256_si512", __LINE__);
}

void NOINLINE check_xor(void *vp1, void *vp2, void *vp3, void *vp_orig,
                        int mask, char *banner) {
  int i;
  V512 *v1 = (V512 *)vp1;
  V512 *v2 = (V512 *)vp2;
  V512 *v3 = (V512 *)vp3;
  V512 *v_orig = (V512 *)vp_orig;

  for (i = 0; i < 16; i++) {
    int actual = v3->u32[i];
    int expected = v_orig->u32[i];
    if (mask & (1 << i)) {
      expected = v1->u32[i] ^ v2->u32[i];
    }
    if (actual + vol != expected - vol) {
      printf("ERROR: %s failed\n", banner ? banner : "");
      n_errs++;
      break;
    }
  }
}

void NOINLINE do_xor() {
  set_nonzero(&i1, 99);
  set_nonzero(&i2, 100);
  set_nonzero(&f1, 33);
  set_nonzero(&f2, -35);
  set_nonzero(&d1, -11);
  set_nonzero(&d2, 14);

  set_nonzero(&i3, 1000);
  i3_orig = i3;
  i3 = _mm512_xor_epi32(i1, i2);
  check_xor(&i1, &i2, &i3, &i3_orig, 0xffff, "_mm512_xor_epi32");

  set_nonzero(&i3, 1500);
  i3_orig = i3;
  i3 = _mm512_mask_xor_epi32(i3_orig, 0x5555, i1, i2);
  check_xor(&i1, &i2, &i3, &i3_orig, 0x5555, "_mm512_mask_xor_epi32");

  set_nonzero(&f3, 1000);
  f3_orig = f3;
  f3 = _mm512_xor_ps(f1, f2);
  check_xor(&f1, &f2, &f3, &f3_orig, 0xffff, "_mm512_xor_ps");

  set_nonzero(&f3, 1500);
  f3_orig = f3;
  f3 = _mm512_mask_xor_ps(f3_orig, 0x5795, f1, f2);
  check_xor(&f1, &f2, &f3, &f3_orig, 0x5795, "_mm512_mask_xor_ps");

  set_nonzero(&i3, 2000);
  i3_orig = i3;
  i3 = _mm512_xor_epi64(i1, i2);
  check_xor(&i1, &i2, &i3, &i3_orig, 0xffff, "_mm512_xor_epi64");

  set_nonzero(&i3, 2500);
  i3_orig = i3;
  i3 = _mm512_mask_xor_epi64(i3_orig, 0x55, i1, i2);
  check_xor(&i1, &i2, &i3, &i3_orig, 0x3333, "_mm512_mask_xor_epi64");

  set_nonzero(&d3, 2000);
  d3_orig = d3;
  d3 = _mm512_xor_pd(d1, d2);
  check_xor(&d1, &d2, &d3, &d3_orig, 0xffff, "_mm512_xor_pd");

  set_nonzero(&d3, 2500);
  d3_orig = d3;
  d3 = _mm512_mask_xor_pd(d3_orig, 0x55, d1, d2);
  check_xor(&d1, &d2, &d3, &d3_orig, 0x3333, "_mm512_mask_xor_pd");
}

int main() {
  do_setzero();
  do_cast();
  do_size_casts();
  do_xor();

  if (n_errs != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
