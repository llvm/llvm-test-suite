#include <complex.h>
#define ESCAPE 2
#define IMAGE_SIZE 10
#define START_X -2.0
#define START_Y START_X
#define MAX_ITER 10
#define step (-START_X - START_X)/IMAGE_SIZE
void emit(double complex X) {
  printf("%f\n", (double)X);
}

void mandel() {
  int x, y, n;
  for (x = 0; x < IMAGE_SIZE; ++x) {
    for (y = 0; y < IMAGE_SIZE; ++y) {
      double complex c = (START_X+x*step) + (START_Y-y*step) * I;
      double complex z = 0.0;

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
