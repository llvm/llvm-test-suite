/*
 * This test was created to check the correctness
 * of the following intrinsics support:
 *     _mm_mmask_i32gather_epi32()
 *     _mm256_mmask_i32gather_epi32()
 */

#include <x86intrin.h>
#include <stdio.h>

#define NUM (256 * 256)
#define SCALE 8

double dst128_f[NUM], gold_dst128_f[NUM];
double dst256_f[NUM], gold_dst256_f[NUM];
__int64 dst128_i[NUM], gold_dst128_i[NUM];
__int64 dst256_i[NUM], gold_dst256_i[NUM];
int mask128[NUM / 2];
int mask256[NUM / 4];
__int64 g_index[NUM];

#define MIN(x, y) ((x) <= (y) ? (x) : (y))

void init_data() {
  int i;
  for (i = 0; i < NUM; i++) {
    dst128_i[i] = dst256_i[i] = -1;
    dst128_f[i] = dst256_f[i] = -1;

    g_index[i] = i * 2;
    if (g_index[i] >= NUM) {
      g_index[i] = NUM - 1 - (i - NUM / 2) * 2;
    }

    if (i % 2 == 0) {
      mask128[i / 2] = (i * 77) & 0xf;
      if (i % 4 == 0) {
        mask256[i / 4] = (i * 31) & 0xff;
      }
    }

    if ((mask128[i / 2] >> (i % 2)) & 0x1) {
      gold_dst128_i[g_index[i]] = gold_dst128_f[g_index[i]] = i;
    } else {
      gold_dst128_i[g_index[i]] = gold_dst128_f[g_index[i]] = -1;
    }

    if ((mask256[i / 4] >> (i % 4)) & 0x1) {
      gold_dst256_i[g_index[i]] = gold_dst256_f[g_index[i]] = i;
    } else {
      gold_dst256_i[g_index[i]] = gold_dst256_f[g_index[i]] = -1;
    }
  }
}

void do_mm_mask_i64scatter_epi64() {
  int i;
  for (i = 0; i < NUM; i += 2) {
    __m128i ind = _mm_loadu_si128((const __m128i *)(g_index + i));
    __m128i val = _mm_set_epi64x(i + 1, i);
    _mm_mask_i64scatter_epi64(dst128_i, mask128[i / 2], ind, val, SCALE);
  }
}

void do_mm_mask_i64scatter_pd() {
  int i;
  for (i = 0; i < NUM; i += 2) {
    __m128i ind = _mm_loadu_si128((const __m128i *)(g_index + i));
    __m128d val = _mm_set_pd(i + 1, i);
    _mm_mask_i64scatter_pd(dst128_f, mask128[i / 2], ind, val, SCALE);
  }
}

void do_mm256_mask_i64scatter_epi64() {
  int i;
  for (i = 0; i < NUM; i += 4) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m256i val = _mm256_set_epi64x(i + 3, i + 2, i + 1, i);
    _mm256_mask_i64scatter_epi64(dst256_i, mask256[i / 4], ind, val, SCALE);
  }
}

void do_mm256_mask_i64scatter_pd() {
  int i;
  for (i = 0; i < NUM; i += 4) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m256d val = _mm256_set_pd(i + 3, i + 2, i + 1, i);
    _mm256_mask_i64scatter_pd(dst256_f, mask256[i / 4], ind, val, SCALE);
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

      printf("Expected value %lld, actual %lld, kmask=%d\n", gold_dst[i],
             res_dst[i], kmask_bit);

      return -1;
    }
  }
  return 0;
}

int main() {
  int error = 0;

  init_data();

  do_mm_mask_i64scatter_epi64();
  error |= check(1, dst128_i, gold_dst128_i, mask128, 2);

  do_mm_mask_i64scatter_pd();
  error |= check(2, (__int64 *)dst128_f, (__int64 *)gold_dst128_f, mask128, 2);

  do_mm256_mask_i64scatter_epi64();
  error |= check(3, dst256_i, gold_dst256_i, mask256, 4);

  do_mm256_mask_i64scatter_pd();
  error |= check(4, (__int64 *)dst256_f, (__int64 *)gold_dst256_f, mask256, 4);

  if (error != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
