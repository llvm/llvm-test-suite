/*
 * This test was created to check the correctness
 * of the following intrinsics support:
 *     _mm_mmask_i32gather_epi64()
 *     _mm256_mmask_i32gather_epi64()
 */

#include <x86intrin.h>
#include <stdio.h>

#define NUM (256 * 256)
#define SCALE 8

double dst128_f[NUM];
double dst256_f[NUM];
double dst_f[NUM];
__int64 dst128_i[NUM];
__int64 dst256_i[NUM];
__int64 dst_i[NUM];
double src_f[NUM];
__int64 src_i[NUM];
__int64 mask128[NUM / 2];
__int64 mask256[NUM / 4];
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

    if (i % 2 == 0) {
      mask128[i / 2] = (i * 77) & 0xf;
      if (i % 4 == 0) {
        mask256[i / 4] = (i * 31) & 0xff;
      }
    }
  }
}

void do_mm_mmask_i32gather_epi64() {
  int i;
  for (i = 0; i < NUM; i += 2) {

    // Only the low 2 int32 elements should be used.
    __m128i ind = _mm_loadu_si128((const __m128i *)(g_index + i));

    __m128i old_dst = _mm_loadu_si128((__m128i const *)(dst_i + i));
    __m128i gtr =
        _mm_mmask_i32gather_epi64(old_dst, mask128[i / 2], ind, src_i, SCALE);
    _mm_storeu_si128((__m128i *)(dst128_i + i), gtr);
  }
}

void do_mm_mmask_i32gather_pd() {
  int i;
  for (i = 0; i < NUM; i += 2) {

    // Only the low 2 int32 elements should be used.
    __m128i ind = _mm_loadu_si128((const __m128i *)(g_index + i));

    __m128d old_dst = _mm_loadu_pd(dst_f + i);
    __m128d gtr =
        _mm_mmask_i32gather_pd(old_dst, mask128[i / 2], ind, src_f, SCALE);
    _mm_storeu_pd(dst128_f + i, gtr);
  }
}

void do_mm256_mmask_i32gather_epi64() {
  int i;
  for (i = 0; i < NUM; i += 4) {
    __m128i ind = _mm_loadu_si128((const __m128i *)(g_index + i));
    __m256i old_dst = _mm256_loadu_si256((const __m256i *)(dst_i + i));
    __m256i gtr = _mm256_mmask_i32gather_epi64(old_dst, mask256[i / 4], ind,
                                               src_i, SCALE);
    _mm256_storeu_si256((__m256i *)(dst256_i + i), gtr);
  }
}

void do_mm256_mmask_i32gather_pd() {
  int i;
  for (i = 0; i < NUM; i += 4) {
    __m128i ind = _mm_loadu_si128((const __m128i *)(g_index + i));
    __m256d old_dst = _mm256_loadu_pd(dst_f + i);
    __m256d gtr =
        _mm256_mmask_i32gather_pd(old_dst, mask256[i / 4], ind, src_f, SCALE);
    _mm256_storeu_pd(dst256_f + i, gtr);
  }
}

int check(int id, __int64 *res_dst, __int64 *pass_thru_vals, __int64 *mask,
          __int64 *src, int elems_in_vector) {
  int i;
  for (i = 0; i < NUM; i++) {
    __int64 kmask = mask[i / elems_in_vector];
    __int64 kmask_bit = kmask & (1 << (i % elems_in_vector));

    __int64 v = kmask_bit ? src[g_index[i]] : pass_thru_vals[i];

    if (v != res_dst[i]) {
      printf("The testcase #%d FAILed at %d iteration\n", id, i);

      printf("Expected value %lld, actual %lld\n", v, res_dst[i]);

      return -1;
    }
  }
  return 0;
}

int main() {
  int error = 0;

  init_data();

  do_mm_mmask_i32gather_epi64();
  error |= check(1, dst128_i, dst_i, mask128, src_i, 2);

  do_mm_mmask_i32gather_pd();
  error |= check(2, (__int64 *)dst128_f, (__int64 *)dst_f, mask128,
                 (__int64 *)src_f, 2);

  do_mm256_mmask_i32gather_epi64();
  error |= check(3, dst256_i, dst_i, mask256, src_i, 4);

  do_mm256_mmask_i32gather_pd();
  error |= check(4, (__int64 *)dst256_f, (__int64 *)dst_f, mask256,
                 (__int64 *)src_f, 4);

  if (error != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
