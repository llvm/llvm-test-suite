/*
 * This test was created to check the correctness
 * of the following intrinsics support:
 *     _mm512_i32scatter_epi64()
 *     _mm512_mask_i32scatter_epi64()
 *     _mm512_i32scatter_pd()
 *     _mm512_mask_i32scatter_pd()
 */

#include <stdio.h>
#include <x86intrin.h>

#define NUM (256 * 256)
#define SCALE 8

double dst512_f[NUM], gold_dst512_f[NUM], full_gold_dst512_f[NUM];
__int64 dst512_i[NUM], gold_dst512_i[NUM], full_gold_dst512_i[NUM];
int mask512[NUM / 8];
int full_mask512[NUM / 8];
int g_index[NUM];

void init_data() {
  int i;
  for (i = 0; i < NUM; i++) {
    dst512_i[i] = -1;
    dst512_f[i] = -1;

    g_index[i] = i * 2;
    if (g_index[i] >= NUM) {
      g_index[i] = NUM - 1 - (i - NUM / 2) * 2;
    }

    if (i % 8 == 0) {
      mask512[i / 8] = (i * 31) & 0xff;
      full_mask512[i / 8] = 0xff;
    }

    if ((mask512[i / 8] >> (i % 8)) & 0x1) {
      gold_dst512_i[g_index[i]] = gold_dst512_f[g_index[i]] = i;
    } else {
      gold_dst512_i[g_index[i]] = gold_dst512_f[g_index[i]] = -1;
    }

    full_gold_dst512_i[g_index[i]] = full_gold_dst512_f[g_index[i]] = i;
  }
}

void do_mm512_mask_i32scatter_epi64() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m512i val =
        _mm512_set_epi64(i + 7, i + 6, i + 5, i + 4, i + 3, i + 2, i + 1, i);
    _mm512_mask_i32scatter_epi64(dst512_i, mask512[i / 8], ind, val, SCALE);
  }
}

void do_mm512_mask_i32scatter_pd() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m512d val =
        _mm512_set_pd(i + 7, i + 6, i + 5, i + 4, i + 3, i + 2, i + 1, i);
    _mm512_mask_i32scatter_pd(dst512_f, mask512[i / 8], ind, val, SCALE);
  }
}

void do_mm512_i32scatter_epi64() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m512i val =
        _mm512_set_epi64(i + 7, i + 6, i + 5, i + 4, i + 3, i + 2, i + 1, i);
    _mm512_i32scatter_epi64(dst512_i, ind, val, SCALE);
  }
}

void do_mm512_i32scatter_pd() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m512d val =
        _mm512_set_pd(i + 7, i + 6, i + 5, i + 4, i + 3, i + 2, i + 1, i);
    _mm512_i32scatter_pd(dst512_f, ind, val, SCALE);
  }
}

int check(int id, __int64 *res_dst, __int64 *gold_dst, int *mask,
          int elems_in_vector) {
  int i;
  for (i = 0; i < NUM; i++) {
    int kmask = mask[i / elems_in_vector];
    int kmask_bit = kmask & (1 << (i % elems_in_vector));

    if (gold_dst[i] != res_dst[i]) {
      printf("The testcase #%d FAILed at %d iteration\n", id, i);

      printf("Expected value %I64d, actual %I64d, kmask=%d\n", gold_dst[i],
             res_dst[i], kmask_bit);

      return -1;
    }
  }
  return 0;
}

int main() {
  int error = 0;

  init_data();

  do_mm512_mask_i32scatter_epi64();
  error |= check(1, dst512_i, gold_dst512_i, mask512, 8);

  do_mm512_mask_i32scatter_pd();
  error |= check(2, (__int64 *)dst512_f, (__int64 *)gold_dst512_f, mask512, 8);

  init_data();

  do_mm512_i32scatter_epi64();
  error |= check(3, dst512_i, full_gold_dst512_i, full_mask512, 8);

  do_mm512_i32scatter_pd();
  error |= check(4, (__int64 *)dst512_f, (__int64 *)full_gold_dst512_f,
                 full_mask512, 8);

  if (error != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
