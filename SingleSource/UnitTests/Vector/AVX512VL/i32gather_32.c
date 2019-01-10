/*
 * This test was created to check the correctness
 * of the following intrinsics support:
 *     _mm_mmask_i32gather_epi32()
 *     _mm256_mmask_i32gather_epi32()
 */

#include <stdio.h>
#include <x86intrin.h>

#define NUM (256 * 256)
#define SCALE 4

float dst128_f[NUM];
float dst256_f[NUM];
float dst_f[NUM];
int dst128_i[NUM];
int dst256_i[NUM];
int dst_i[NUM];
float src_f[NUM];
int src_i[NUM];
int mask128[NUM / 4];
int mask256[NUM / 8];
int g_index[NUM];

#define MIN(x, y) ((x) <= (y) ? (x) : (y))

void init_data() {
  int i;
  for (i = 0; i < NUM; i++) {
    g_index[i] = MIN(i * 17 & 0xce, NUM);
    src_f[g_index[i]] = src_i[g_index[i]] = i;

    dst_i[i] = dst_f[i] = -i;
    dst128_i[i] = dst256_i[i] = -i;
    dst128_f[i] = dst256_f[i] = -i;

    if (i % 4 == 0) {
      mask128[i / 4] = (i * 77) & 0xf;
      if (i % 8 == 0) {
        mask256[i / 8] = (i * 31) & 0xff;
      }
    }
  }
}

void do_mm_mmask_i32gather_epi32() {
  int i;
  for (i = 0; i < NUM; i += 4) {
    __m128i ind = _mm_loadu_si128((const __m128i *)(g_index + i));
    __m128i old_dst = _mm_loadu_si128((__m128i const *)(dst_i + i));
    __m128i gtr =
        _mm_mmask_i32gather_epi32(old_dst, mask128[i / 4], ind, src_i, SCALE);
    _mm_storeu_si128((__m128i *)(dst128_i + i), gtr);
  }
}

void do_mm_mmask_i32gather_ps() {
  int i;
  for (i = 0; i < NUM; i += 4) {
    __m128i ind = _mm_loadu_si128((const __m128i *)(g_index + i));
    __m128 old_dst = _mm_loadu_ps(dst_f + i);
    __m128 gtr =
        _mm_mmask_i32gather_ps(old_dst, mask128[i / 4], ind, src_f, SCALE);
    _mm_storeu_ps(dst128_f + i, gtr);
  }
}

void do_mm256_mmask_i32gather_epi32() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m256i old_dst = _mm256_loadu_si256((const __m256i *)(dst_i + i));
    __m256i gtr = _mm256_mmask_i32gather_epi32(old_dst, mask256[i / 8], ind,
                                               src_i, SCALE);
    _mm256_storeu_si256((__m256i *)(dst256_i + i), gtr);
  }
}

void do_mm256_mmask_i32gather_ps() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m256 old_dst = _mm256_loadu_ps(dst_f + i);
    __m256 gtr =
        _mm256_mmask_i32gather_ps(old_dst, mask256[i / 8], ind, src_f, SCALE);
    _mm256_storeu_ps(dst256_f + i, gtr);
  }
}

int check(int id, int *res_dst, int *pass_thru_vals, int *mask, int *src,
          int elems_in_vector) {
  int i;
  for (i = 0; i < NUM; i++) {
    int kmask = mask[i / elems_in_vector];
    int kmask_bit = kmask & (1 << (i % elems_in_vector));

    int v = kmask_bit ? src[g_index[i]] : pass_thru_vals[i];

    if (v != res_dst[i]) {
      printf("The testcase #%d FAILed at %d iteration\n", id, i);

      printf("Expected value %d, actual %d\n", v, res_dst[i]);

      return -1;
    }
  }
  return 0;
}

int main() {
  int error = 0;

  init_data();

  do_mm_mmask_i32gather_epi32();
  error |= check(1, dst128_i, dst_i, mask128, src_i, 4);

  do_mm_mmask_i32gather_ps();
  error |= check(2, (int *)dst128_f, (int *)dst_f, mask128, (int *)src_f, 4);

  do_mm256_mmask_i32gather_epi32();
  error |= check(3, dst256_i, dst_i, mask256, src_i, 8);

  do_mm256_mmask_i32gather_ps();
  error |= check(4, (int *)dst256_f, (int *)dst_f, mask256, (int *)src_f, 8);

  if (error != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
