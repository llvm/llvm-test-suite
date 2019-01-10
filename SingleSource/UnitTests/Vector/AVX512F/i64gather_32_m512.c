/*
 * This test was created to check the correctness
 * of the following intrinsics support:
 *     _mm512_i64gather_epi32()
 *     _mm512_mask_i64gather_epi32()
 *     _mm512_i64gather_ps()
 *     _mm512_mask_i64gather_ps()
 */

#include "m512_test_util.h"
#include <stdio.h>

#define NUM (256 * 256)
#define SCALE 4

float dst512_f[NUM];
float dst_f[NUM];
int dst512_i[NUM];
int dst_i[NUM];
float src_f[NUM];
int src_i[NUM];
int mask512[NUM / 8];
__int64 g_index[NUM];

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

void do_mm512_mask_i64gather_epi32() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m512i ind = _mm512_loadu_si512((const __m512i *)(g_index + i));
    __m256i old_dst = _mm256_loadu_si256((const __m256i *)(dst_i + i));

    __m256i gtr =
        _mm512_mask_i64gather_epi32(old_dst, mask512[i / 8], ind, src_i, SCALE);

    _mm256_storeu_si256((__m256i *)(dst512_i + i), gtr);
  }
}

void do_mm512_mask_i64gather_ps() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m512i ind = _mm512_loadu_si512((const __m512i *)(g_index + i));
    __m256 old_dst = _mm256_loadu_ps(dst_f + i);
    __m256 gtr =
        _mm512_mask_i64gather_ps(old_dst, mask512[i / 8], ind, src_f, SCALE);
    _mm256_storeu_ps(dst512_f + i, gtr);
  }
}

void do_mm512_i64gather_epi32() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m512i ind = _mm512_loadu_si512((const __m512i *)(g_index + i));
    __m256i gtr = _mm512_i64gather_epi32(ind, src_i, SCALE);
    _mm256_storeu_si256((__m256i *)(dst512_i + i), gtr);
  }
}

void do_mm512_i64gather_ps() {
  int i;
  for (i = 0; i < NUM; i += 8) {
    __m512i ind = _mm512_loadu_si512((const __m512i *)(g_index + i));
    __m256 gtr = _mm512_i64gather_ps(ind, src_f, SCALE);
    _mm256_storeu_ps(dst512_f + i, gtr);
  }
}

int checkm(int id, int *res_dst, int *pass_thru_vals, int *mask, int *src,
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

int check(int id, int *res_dst, int *src, int elems_in_vector) {
  int i;
  for (i = 0; i < NUM; i++) {

    int v = src[g_index[i]];

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

  do_mm512_mask_i64gather_epi32();
  error |= checkm(1, dst512_i, dst_i, mask512, src_i, 8);

  do_mm512_mask_i64gather_ps();
  error |= checkm(2, (int *)dst512_f, (int *)dst_f, mask512, (int *)src_f, 8);

  init_data();

  do_mm512_i64gather_epi32();
  error |= check(3, dst512_i, src_i, 8);

  do_mm512_i64gather_ps();
  error |= check(4, (int *)dst512_f, (int *)src_f, 8);

  if (error != 0) {
    printf("FAILED\n");
    return 1;
  }

  printf("PASSED\n");
  return 0;
}
