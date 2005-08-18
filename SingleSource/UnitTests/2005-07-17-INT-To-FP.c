// Test the various SINT-TO-FP and UINT-TO-FP conversions.
#include <stdio.h>

int tests[] = {
  0x80000000,
  -123456789,
  -10,
  -2,
  -1,
  0,
  1,
  2,
  10,
  123456789,
  0x7FFFFFFF
};

int main() {

  unsigned i;
  // byte boundary tests
  for (i = 0; i < 64; ++i) {
    printf("%d %f, %f, %f, %f\n", i,
           (double)(signed char)(i << 2),            // i8
           (double)(signed short)(i << 10),          // i16
           (double)(signed int)(i << 26),            // i32
           (double)(signed long long)((long long)i << 58ULL));  // i64

    printf("%d %f, %f, %f, %f\n", i,
           (double)(unsigned char)(i << 2),            // i8
           (double)(unsigned short)(i << 10),          // i16
           (double)(unsigned int)(i << 26),            // i32
           (double)(unsigned long long)((unsigned long long)i << 58ULL));  // i64
  }
  // edge case tests
  for (unsigned i = 0; i < (sizeof(tests) / sizeof(int)); i++) {
    printf("%d %f %f %f %f\n", (double)(unsigned)tests[i],
                               (double)(  signed)tests[i],
                               (float) (unsigned)tests[i],
                               (float) (  signed)tests[i]);
  }
}
