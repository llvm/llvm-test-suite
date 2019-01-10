/*
 * This test was created to check the correctness
 * of the following intrinsics support:
 *     _mm512_i32gather_epi64()
 *     _mm512_mask_i32gather_epi64()
 *     _mm512_i32gather_pd()
 *     _mm512_mask_i32gather_pd()
 */

#include <stdio.h>
#include <x86intrin.h>

#define NUM (256 * 256)
#define SCALE 8

double dst512_f[NUM];
double dst_f[NUM];
__int64 dst512_i[NUM];
__int64 dst_i[NUM];
double src_f[NUM];
__int64 src_i[NUM];
__int64 mask512[NUM / 8];
int g_index[NUM];

#define MIN(x, y) ((x) <= (y) ? (x) : (y))

void init_data() {
  int i;
  for (i = 0; i < NUM; i++) {
    g_index[i] = MIN(i * 17 & 0xce, NUM - 1);
    src_f[g_index[i]] = src_i[g_index[i]] = i;

    dst_i[i] = dst_f[i] = -i;
    dst512_i[i] = -i;
    dst512_f[i] = -i;

    if (i % 8 == 0) {
      mask512[i / 8] = (i * 31) & 0xff;
    }
  }
}

void do_mm512_mmask_i32gather_epi64() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m512i old_dst = _mm512_loadu_si512((const __m512i *)(dst_i + i));
    __m512i gtr =
        _mm512_mask_i32gather_epi64(old_dst, mask512[i / 8], ind, src_i, SCALE);
    _mm512_storeu_si512((__m512i *)(dst512_i + i), gtr);
  }
}

void do_mm512_mmask_i32gather_pd() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m512d old_dst = _mm512_loadu_pd(dst_f + i);
    __m512d gtr =
        _mm512_mask_i32gather_pd(old_dst, mask512[i / 8], ind, src_f, SCALE);
    _mm512_storeu_pd(dst512_f + i, gtr);
  }
}

void do_mm512_i32gather_epi64() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m512i gtr = _mm512_i32gather_epi64(ind, src_i, SCALE);
    _mm512_storeu_si512((__m512i *)(dst512_i + i), gtr);
  }
}

void do_mm512_i32gather_pd() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m256i ind = _mm256_loadu_si256((const __m256i *)(g_index + i));
    __m512d gtr = _mm512_i32gather_pd(ind, src_f, SCALE);
    _mm512_storeu_pd(dst512_f + i, gtr);
  }
}

int checkm(int id, __int64 *res_dst, __int64 *pass_thru_vals, __int64 *mask,
           __int64 *src, int elems_in_vector) {
  int i;
  for (i = 0; i < NUM; i++) {
    __int64 kmask = mask[i / elems_in_vector];
    __int64 kmask_bit = kmask & (1 << (i % elems_in_vector));

    __int64 v = kmask_bit ? src[g_index[i]] : pass_thru_vals[i];

    if (v != res_dst[i]) {
      printf("The testcase #%d FAILed at %d iteration\n", id, i);

      printf("Expected value %I64d, actual %I64d\n", v, res_dst[i]);

      return -1;
    }
  }
  return 0;
}

int check(int id, __int64 *res_dst, __int64 *src, int elems_in_vector) {
  int i;
  for (i = 0; i < NUM; i++) {

    __int64 v = src[g_index[i]];

    if (v != res_dst[i]) {
      printf("The testcase #%d FAILed at %d iteration\n", id, i);

      printf("Expected value %I64d, actual %I64d\n", v, res_dst[i]);

      return -1;
    }
  }
  return 0;
}

int main() {
  int error = 0;

  init_data();

  do_mm512_mmask_i32gather_epi64();
  error |= checkm(1, dst512_i, dst_i, mask512, src_i, 8);

  do_mm512_mmask_i32gather_pd();
  error |= checkm(2, (__int64 *)dst512_f, (__int64 *)dst_f, mask512,
                  (__int64 *)src_f, 8);

  init_data();

  do_mm512_i32gather_epi64();
  error |= check(3, dst512_i, src_i, 8);

  do_mm512_i32gather_pd();
  error |= check(4, (__int64 *)dst512_f, (__int64 *)src_f, 8);

  if (error != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
