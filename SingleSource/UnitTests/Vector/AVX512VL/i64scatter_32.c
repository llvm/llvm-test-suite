/*
 * This test was created to check the correctness
 * of the following intrinsics support:
 *     _mm_mmask_i32gather_epi32()
 *     _mm256_mmask_i32gather_epi32()
 */

#include <x86intrin.h>
#include <stdio.h>

#define NUM (256 * 256)
#define SCALE 4

float dst128_f[NUM], gold_dst128_f[NUM];
float dst256_f[NUM], gold_dst256_f[NUM];
int dst128_i[NUM], gold_dst128_i[NUM];
int dst256_i[NUM], gold_dst256_i[NUM];
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

void do_mm_mask_i64scatter_epi32() {
  int i;
  for (i = 0; i < NUM; i += 2) {
    __m128i ind = _mm_loadu_si128((const __m128i *)(g_index + i));

    // Only the low 2 int32 values are going to be used.
    __m128i val = _mm_set_epi32(0, 0, i + 1, i);

    _mm_mask_i64scatter_epi32(dst128_i, mask128[i / 2], ind, val, SCALE);
  }
}

void do_mm_mask_i64scatter_ps() {
  int i;
  for (i = 0; i < NUM; i += 2) {
    __m128i ind = _mm_loadu_si128((const __m128i *)(g_index + i));

    // Only the low 2 int32 values are going to be used.
    __m128 val = _mm_set_ps(0, 0, i + 1, i);

    _mm_mask_i64scatter_ps(dst128_f, mask128[i / 2], ind, val, SCALE);
  }
}

void do_mm256_mask_i64scatter_epi32() {
  int i;
  for (i = 0; i < NUM; i += 4) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m128i val = _mm_set_epi32(i + 3, i + 2, i + 1, i);
    _mm256_mask_i64scatter_epi32(dst256_i, mask256[i / 4], ind, val, SCALE);
  }
}

void do_mm256_mask_i64scatter_ps() {
  int i;
  for (i = 0; i < NUM; i += 4) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m128 val = _mm_set_ps(i + 3, i + 2, i + 1, i);
    _mm256_mask_i64scatter_ps(dst256_f, mask256[i / 4], ind, val, SCALE);
  }
}

int check(int id, int *res_dst, int *gold_dst, int *mask, int elems_in_vector) {
  int i;
  for (i = 0; i < NUM; i++) {
    int kmask = mask[i / elems_in_vector];
    int kmask_bit = kmask & (1 << (i % elems_in_vector));

    if (gold_dst[i] != res_dst[i]) {
      printf("The testcase #%d FAILed at %d iteration\n", id, i);

      printf("Expected value %d, actual %d, kmask=%d\n", gold_dst[i],
             res_dst[i], kmask_bit);
      return -1;
    }
  }
  return 0;
}

int main() {
  int error = 0;

  init_data();

  do_mm_mask_i64scatter_epi32();
  error |= check(1, dst128_i, gold_dst128_i, mask128, 2);

  do_mm_mask_i64scatter_ps();
  error |= check(2, (int *)dst128_f, (int *)gold_dst128_f, mask128, 2);

  do_mm256_mask_i64scatter_epi32();
  error |= check(3, dst256_i, gold_dst256_i, mask256, 4);

  do_mm256_mask_i64scatter_ps();
  error |= check(4, (int *)dst256_f, (int *)gold_dst256_f, mask256, 4);

  if (error != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
