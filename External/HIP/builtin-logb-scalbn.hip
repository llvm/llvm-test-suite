
#define __device__ __attribute__((device))

#include <hip/hip_runtime.h>
#include <cmath>
#include <cstdio>

__global__ void my_kernel(float a) {
  printf("%f\n", logbf(16.0f));
  printf("%f\n", logb(16.0));
  printf("%f\n", __builtin_logbf(16.0f));
  printf("%f\n", __builtin_logb(16.0));

  printf("%f\n", scalbnf(16.0f, 10));
  printf("%f\n", scalbn(16.0, 10));
  printf("%f\n", __builtin_scalbnf(16.0f, 10));
  printf("%f\n", __builtin_scalbn(16.0, 10));

  printf("%f\n", logbf(a));
  printf("%f\n", logb(a));
  printf("%f\n", __builtin_logbf(a));
  printf("%f\n", __builtin_logb(a));

  printf("%f\n", scalbnf(a, 10));
  printf("%f\n", scalbn(a, 10));
  printf("%f\n", __builtin_scalbnf(a, 10));
  printf("%f\n", __builtin_scalbn(a, 10));
}

void __attribute__((noinline)) test(float a) {
  printf("%f\n", logbf(a));
  printf("%f\n", logb(a));
  printf("%f\n", __builtin_logbf(a));
  printf("%f\n", __builtin_logb(a));

  printf("%f\n", scalbnf(a, 10));
  printf("%f\n", scalbn(a, 10));
  printf("%f\n", __builtin_scalbnf(a, 10));
  printf("%f\n", __builtin_scalbn(a, 10));
}

int main(int argc, char **argv) {
  my_kernel<<<1,1>>>(16.0f);

  printf("%f\n", logbf(16.0f));
  printf("%f\n", logb(16.0));
  printf("%f\n", __builtin_logbf(16.0f));
  printf("%f\n", __builtin_logb(16.0));

  printf("%f\n", scalbnf(16.0f, 10));
  printf("%f\n", scalbn(16.0, 10));
  printf("%f\n", __builtin_scalbnf(16.0f, 10));
  printf("%f\n", __builtin_scalbn(16.0, 10));

  test(16.0f);
  return 0;
}

