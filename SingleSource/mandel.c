/* Sparc is not C99-compliant */
#if defined(sparc) || defined(__sparc__) || defined(__sparcv9)

int main() { return 0; }

#else /* sparc */

#define ESCAPE 2
#define IMAGE_SIZE 10
#define START_X -2.0
#define START_Y START_X
#define MAX_ITER 10
#define step (-START_X - START_X)/IMAGE_SIZE

#define I 1.0iF

#include <tgmath.h>

void emit(double __complex__ X) {
  printf("%f\n", (double)X);
}

void mandel() {
  int x, y, n;
  for (x = 0; x < IMAGE_SIZE; ++x) {
    for (y = 0; y < IMAGE_SIZE; ++y) {
      double __complex__ c = (START_X+x*step) + (START_Y-y*step) * I;
      double __complex__ z = 0.0;

      for (n = 0; n < MAX_ITER; ++n) {
        z = z * z + c;
        if (cabs(z) >= ESCAPE)
          break;
      }
      emit(z);
    }
  }
}

int main() {
  mandel();
  return 0;
}

#endif /* sparc */
