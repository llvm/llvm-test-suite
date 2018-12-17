#ifndef M512_TEST_UTIL_H_INCLUDED
#define M512_TEST_UTIL_H_INCLUDED

/*
 * Common declarations useful for writing 512-bit unit tests.
 */

#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <x86intrin.h>

#define ALIGNTO(n) __declspec(align(n))

/*
 * For purposes of unit tests it can be beneficial to suppress inlining
 * simply so that only a single instance of a test function is emitted.
 * Makes it easier to diff A/B assembly output.
 */
#define NOINLINE __declspec(noinline)

/*
 * FULL_IREG(ax) expands to either eax or rax depending on the target.
 */
#if defined(__x86_64) || defined(_M_X64)
#define FULL_IREG(reg) r##reg
#else
#define FULL_IREG(reg) e##reg
#endif

/* Number of elements in an array. */
#define ASIZE(a) (sizeof((a)) / sizeof((a)[0]))

typedef __int64 I64;
typedef unsigned __int64 U64;

typedef union ALIGNTO(64) {

  __m512 zmm;
  __m512d zmmd;
  __m512i zmmi;

  __m256 ymm[2];
  __m256d ymmd[2];
  __m256i ymmi[2];

  __m128 xmm[4];
  __m128d xmmd[4];
  __m128i xmmi[4];

  char c[64];
  signed char s8[64];
  unsigned char u8[64];
  short s16[32];
  unsigned short u16[32];
  int s32[16];
  unsigned int u32[16];
  float f32[16];
  I64 s64[8];
  U64 u64[8];
  double f64[8];

} V512;

int n_errs = 0;

/*
 * Print the low N 8-bit unsigned integers from p.
 */

void NOINLINE display_pb(const V512 *p, const char *banner, int n_elems) {
  int i = 15;

  if (banner) {
    printf("%s", banner);
  }

  for (i = n_elems; i >= 0; i--) {
    printf(" %0.2x", p->u8[i]);
    if (i > 0 && i % 16 == 0) {
      printf("\n");
      if (banner) {
        printf("%*s", (int)strlen((void *)banner), "");
      }
    }
  }
  printf("\n");
}

/*
 * Print the low N 16-bit unsigned integers from p.
 */

void NOINLINE display_pw(const V512 *p, const char *banner, int n_elems) {
  int i = 15;

  if (banner) {
    printf("%s", banner);
  }

  for (i = n_elems; i >= 0; i--) {
    printf(" %0.4x", p->u16[i]);
    if (i > 0 && i % 8 == 0) {
      printf("\n");
      if (banner) {
        printf("%*s", (int)strlen((void *)banner), "");
      }
    }
  }
  printf("\n");
}

/*
 * Print the low N 32-bit unsigned integers from p.
 */

void NOINLINE display_pd(const V512 *p, const char *banner, int n_elems) {
  int i = 15;

  if (banner) {
    printf("%s", banner);
  }

  for (i = n_elems; i >= 0; i--) {
    printf(" %0.8x", p->u32[i]);
    if (i > 0 && i % 4 == 0) {
      printf("\n");
      if (banner) {
        printf("%*s", (int)strlen((void *)banner), "");
      }
    }
  }
  printf("\n");
}

/*
 * Print the low N 64-bit unsigned integers from p.
 */
void NOINLINE display_pq(const V512 *p, const char *banner, int n_elems) {
  int i = 7;

  if (banner) {
    printf("%s", banner);
  }

  for (i = n_elems; i >= 0; i--) {
    printf(" %0.16llx", p->u64[i]);
    if (i > 0 && i % 4 == 0) {
      printf("\n");
      if (banner) {
        printf("%*s", (int)strlen((void *)banner), "");
      }
    }
  }
  printf("\n");
}

/*
 * Print the low N single precision floats from p.
 */

void NOINLINE display_psf(const V512 *p, const char *banner, int n_elems) {
  int i = 15;

  if (banner) {
    printf("%s", banner);
  }

  for (i = n_elems; i >= 0; i--) {
    printf(" %7g", p->f32[i]);
    if (i > 0 && i % 4 == 0) {
      printf("\n");
      if (banner) {
        printf("%*s", (int)strlen((void *)banner), "");
      }
    }
  }
  printf("\n");
}

/*
 * Print the low N double precision floats from p.
 */

void NOINLINE display_pdf(const V512 *p, const char *banner, int n_elems) {
  int i = 15;

  if (banner) {
    printf("%s", banner);
  }

  for (i = n_elems; i >= 0; i--) {
    printf(" %7g", p->f64[i]);
    if (i > 0 && i % 4 == 0) {
      printf("\n");
      if (banner) {
        printf("%*s", (int)strlen((void *)banner), "");
      }
    }
  }
  printf("\n");
}

/*
 * Check that the low N 16-bit elements of "got" and "expected" are the same.
 */
int NOINLINE check_equal_nw(void *got, void *expected, int n_elems,
                            char *banner, int line) {
  int i, fail = 0;
  V512 *v1 = (V512 *)got;
  V512 *v2 = (V512 *)expected;

  for (i = 0; i < n_elems; i++) {
    if (v1->u16[i] != v2->u16[i]) {
      printf("ERROR(%d): %s failed at %d'th element:  0x%0.4x != 0x%0.4x\n",
             line, banner ? banner : "", i, v1->u16[i], v2->u16[i]);
      display_pw(got, "got:", n_elems);
      display_pw(expected, "exp:", n_elems);
      n_errs++;
      fail = 1;
      break;
    }
  }
  return fail;
}

/*
 * Check that the low N 32-bit elements of "got" and "expected" are the same.
 */
int NOINLINE check_equal_nd(void *got, void *expected, int n_elems,
                            char *banner, int line) {
  int i, fail = 0;
  V512 *v1 = (V512 *)got;
  V512 *v2 = (V512 *)expected;

  for (i = 0; i < n_elems; i++) {
    if (v1->u32[i] != v2->u32[i]) {
      printf("ERROR(%d): %s failed at %d'th element:  0x%0.8x != 0x%0.8x\n",
             line, banner ? banner : "", i, v1->u32[i], v2->u32[i]);
      display_pd(got, "got:", n_elems);
      display_pd(expected, "exp:", n_elems);
      n_errs++;
      fail = 1;
      break;
    }
  }
  return fail;
}

/*
 * Check that the low N 64-bit elements of "got" and "expected" are the same.
 */
int NOINLINE check_equal_nq(void *got, void *expected, int n_elems,
                            char *banner, int line) {
  int i, fail = 0;
  V512 *v1 = (V512 *)got;
  V512 *v2 = (V512 *)expected;

  for (i = 0; i < n_elems; i++) {
    if (v1->u64[i] != v2->u64[i]) {
      printf(
          "ERROR(%d): %s failed at %d'th element:  0x%0.16llx != 0x%0.16llx\n",
          line, banner ? banner : "", i, v1->u64[i], v2->u64[i]);
      display_pq(got, "got:", n_elems);
      display_pq(expected, "exp:", n_elems);
      n_errs++;
      fail = 1;
      break;
    }
  }
  return fail;
}

double delta = 1e-4;

#define EQUAL_FP(v1, v2)                                                       \
  ((v1) < (v2) ? ((v2) - (v1) < delta) : ((v1) - (v2) < delta))

/*
 * Check that the low N single precision float elements of "got" and "expected"
 * are the same.
 */
int NOINLINE check_equal_nsf(void *got, void *expected, int n_elems,
                             char *banner, int line) {
  int i, fail = 0;
  V512 *v1 = (V512 *)got;
  V512 *v2 = (V512 *)expected;

  for (i = 0; i < n_elems; i++) {
    if (!EQUAL_FP(v1->f32[i], v2->f32[i])) {
      printf("ERROR(%d): %s failed at %d'th element:  %7g != %7g \n", line,
             banner ? banner : "", i, v1->f32[i], v2->f32[i]);
      display_psf(got, "got:", n_elems);
      display_psf(expected, "exp:", n_elems);
      n_errs++;
      fail = 1;
      break;
    }
  }
  return fail;
}

/*
 * Check that the low N double precision float elements of "got" and "expected"
 * are the same.
 */
int NOINLINE check_equal_ndf(void *got, void *expected, int n_elems,
                             char *banner, int line) {
  int i, fail = 0;
  V512 *v1 = (V512 *)got;
  V512 *v2 = (V512 *)expected;

  for (i = 0; i < n_elems; i++) {
    if (!EQUAL_FP(v1->f64[i], v2->f64[i])) {
      printf("ERROR(%d): %s failed at %d'th element:  %7g != %7g \n", line,
             banner ? banner : "", i, v1->f64[i], v2->f64[i]);
      display_pdf(got, "got:", n_elems);
      display_pdf(expected, "exp:", n_elems);
      n_errs++;
      fail = 1;
      break;
    }
  }
  return fail;
}

#endif /* M512_TEST_UTIL_H_INCLUDED */
