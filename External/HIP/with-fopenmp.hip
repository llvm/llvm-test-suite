#include <hip/hip_runtime.h>
#include <cmath>

// Test use of std::isnan in device and host code.

namespace TestIsNan {
__device__ bool DevPass = false;

__global__ void kernel() {
  double X = 1.0;
  DevPass = !std::isnan(X);
}

bool test() {
  double X = 1.0;
  kernel<<<1, 1>>>();
  bool Pass;
  hipMemcpyFromSymbol(&Pass, DevPass, sizeof(DevPass));
  return Pass & !std::isnan(X);
}
}

int main() {
  bool Pass = TestIsNan::test();

  if (!Pass) {
    printf("FAILED!\n");
    return 1;
  }

  printf("PASSED!\n");
  return 0;
}
