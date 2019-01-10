/*
 * Exercise intrinsics for a instructions which set mask register
 * by values in vector registers and set vector register value by
 * values in mask register.
 */

#include "m512_test_util.h"

__int64 calc_expected_mask_val(const char *valp, int el_size, int length) {
  __int64 rval = 0;
  int i;

  for (i = 0; i < length; i++) {
    if ((valp[el_size * i + (el_size - 1)] & 0x80) != 0) {
      rval |= (1LL << i);
    }
  }

  return rval;
}

char *calc_expected_vec_val(__mmask64 mask_val, int mask_size, int el_size,
                            char *buf) {
  int i, j;

  for (i = 0; i < mask_size * el_size; buf[i++] = 0)
    ;

  for (i = 0; i < mask_size; i++) {
    if ((mask_val & (1LL << i)) != 0) {
      for (j = 0; j < el_size; j++) {
        buf[i * el_size + j] = 0xff;
      }
    }
  }

  return buf;
}

NOINLINE void check_mask16(__mmask16 res_mask, __mmask16 exp_mask,
                           const char *fname, const char *input) {
  int i;

  if (res_mask != exp_mask) {
    printf("%s: 0x%x != 0x%x, input = ", fname, res_mask, exp_mask);
    for (i = 0; i < 16; i++) {
      printf("%02x ", input[i] & 0xff);
    }
    printf("\n");
    n_errs++;
  }
}

NOINLINE void check_xmm_arr(const __m128i xvar, char *buf, const char *fname,
                            __mmask64 input) {
  int i;
  char *p = (char *)&xvar;

  if (memcmp((void *)p, (void *)buf, 16) != 0) {
    printf("%s: 0x", fname);
    for (i = 0; i < 16; i++) {
      printf(" %02x", p[i] & 0xff);
    }
    printf(" != 0x");
    for (i = 0; i < 16; i++) {
      printf(" %02x", buf[i] & 0xff);
    }
    printf(", input = 0x%04x\n", (int)(input)&0xffff);
    n_errs++;
  }
}

NOINLINE void test_xmm(int shift, int mulp) {
  ALIGNTO(16) char buf[16];
  int i;
  __m128i xvar;

  for (i = 0; i < 16; i++) {
    buf[i] = (i << shift) * mulp;
  }

  memcpy(&xvar, buf, 16);

  check_mask16(_mm_movepi8_mask(xvar), calc_expected_mask_val(buf, 1, 16),
               "_mm_movepi8_mask", buf);
  check_mask16(_mm_movepi16_mask(xvar), calc_expected_mask_val(buf, 2, 8),
               "_mm_movepi16_mask", buf);

  check_xmm_arr(_mm_movm_epi8((__mmask16)shift * mulp),
                calc_expected_vec_val(shift * mulp, 16, 1, buf),
                "_mm_movm_epi8", (__mmask16)shift * mulp);
  check_xmm_arr(_mm_movm_epi16((__mmask16)shift * mulp),
                calc_expected_vec_val(shift * mulp, 8, 2, buf),
                "_mm_movm_epi16", (__mmask16)shift * mulp);
}

NOINLINE void check_mask32(__mmask32 res_mask, __mmask32 exp_mask,
                           const char *fname, const char *input) {
  int i;

  if (res_mask != exp_mask) {
    printf("%s: 0x%x != 0x%x, input = ", fname, res_mask, exp_mask);
    for (i = 0; i < 32; i++) {
      printf("%02x ", input[i] & 0xff);
    }
    printf("\n");
    n_errs++;
    exit(1);
  }
}

NOINLINE void check_ymm_arr(const __m256i yvar, char *buf, const char *fname,
                            __mmask64 input) {
  int i;
  char *p = (char *)&yvar;

  if (memcmp((void *)p, (void *)buf, 32) != 0) {
    printf("%s: 0x", fname);
    for (i = 0; i < 32; i++) {
      printf(" %02x", p[i] & 0xff);
    }
    printf(" != 0x");
    for (i = 0; i < 32; i++) {
      printf(" %02x", buf[i] & 0xff);
    }
    printf(", input = 0x%04x\n", (int)(input));
    n_errs++;
  }
}

NOINLINE void test_ymm(int shift, int mulp) {
  ALIGNTO(32) char buf[32];
  int i;
  __m256i yvar;

  for (i = 0; i < 32; i++) {
    buf[i] = (i << shift) * mulp;
  }

  memcpy(&yvar, buf, 32);

  check_mask32(_mm256_movepi8_mask(yvar), calc_expected_mask_val(buf, 1, 32),
               "_mm256_movepi8_mask", buf);
  check_mask32(_mm256_movepi16_mask(yvar), calc_expected_mask_val(buf, 2, 16),
               "_mm256_movepi16_mask", buf);

  check_ymm_arr(_mm256_movm_epi8((__mmask32)shift * mulp),
                calc_expected_vec_val(shift * mulp, 32, 1, buf),
                "_mm256_movm_epi8", (__mmask32)shift * mulp);
  check_ymm_arr(_mm256_movm_epi16((__mmask32)shift * mulp),
                calc_expected_vec_val(shift * mulp, 16, 2, buf),
                "_mm256_movm_epi16", (__mmask32)shift * mulp);
}

NOINLINE void check_mask64(__mmask64 res_mask, __mmask64 exp_mask,
                           const char *fname, const char *input) {
  int i;

  if (res_mask != exp_mask) {
    printf("%s: 0x%llx != 0x%llx, input = ", fname, res_mask, exp_mask);
    for (i = 0; i < 64; i++) {
      printf("%02x ", input[i] & 0xff);
    }
    printf("\n");
    n_errs++;
  }
}

NOINLINE void check_zmm_arr(const __m512i zvar, char *buf, const char *fname,
                            __mmask64 input) {
  int i;
  char *p = (char *)&zvar;

  if (memcmp((void *)p, (void *)buf, 64) != 0) {
    printf("%s: 0x", fname);
    for (i = 0; i < 64; i++) {
      printf(" %02x", p[i] & 0xff);
    }
    printf(" != 0x");
    for (i = 0; i < 64; i++) {
      printf(" %02x", buf[i] & 0xff);
    }
    printf(", input = 0x%08llx\n", input);
    n_errs++;
  }
}

NOINLINE void test_zmm(int shift, int mulp) {
  ALIGNTO(64) char buf[64];
  int i;
  __m512i zvar;

  for (i = 0; i < 64; i++) {
    buf[i] = (i << shift) * mulp;
  }

  memcpy(&zvar, buf, 64);

  check_mask64(_mm512_movepi8_mask(zvar), calc_expected_mask_val(buf, 1, 64),
               "_mm512_movepi8_mask", buf);
  check_mask64(_mm512_movepi16_mask(zvar), calc_expected_mask_val(buf, 2, 32),
               "_mm512_movepi16_mask", buf);

  check_zmm_arr(_mm512_movm_epi8((__mmask64)shift * mulp),
                calc_expected_vec_val(shift * mulp, 64, 1, buf),
                "_mm512_movm_epi8", (__mmask64)shift * mulp);
  check_zmm_arr(_mm512_movm_epi16((__mmask64)shift * mulp),
                calc_expected_vec_val(shift * mulp, 32, 2, buf),
                "_mm512_movm_epi16", (__mmask64)shift * mulp);
}

NOINLINE void test_all() {
  int shift, mulp;

  for (mulp = -1000; mulp < 1000; mulp += 10) {
    for (shift = 0; shift < 64; shift++) {
      test_xmm(shift, mulp);
      test_ymm(shift, mulp);
      test_zmm(shift, mulp);
    }
  }
}

int main(void) {
  test_all();

  if (n_errs != 0) {
    printf("FAILED, n_errs = %d\n", n_errs);
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
