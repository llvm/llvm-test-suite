// Check that we can call some constexpr functions from <algorithm> and
// <functional> when compiling with C++14.  (We require C++14 because only in
// that version do these functions become constexpr and therefore implicitly
// __host__ __device__.)
//
// We assume our standard library is correct, but we still want to ensure that
// we can successfully compile and run the standard library's implementations
// of these functions.

#if __cplusplus >= 201402L

#include <assert.h>
#include <algorithm>
#include <functional>
#include <stdio.h>

__device__ void greater() {
  assert(std::greater<int>()(1, 0));
}

__device__ void min() {
  assert(std::min(0, 1) == 0);
  assert(std::min({5, 1, 10}) == 1);
}

__device__ void max() {
  assert(std::max(0, 1) == 1);
  assert(std::max({5, 1, 10}, std::less<int>()) == 10);
}

__device__ void minmax() {
  assert(std::minmax(1, 0).first == 0);
  assert(std::minmax(1, 0).second == 1);
  assert(std::minmax({0, 10, -10, 100}, std::less<int>()).first == -10);
  assert(std::minmax({0, 10, -10, 100}, std::less<int>()).second == 100);
}

__global__ void kernel() {
  greater();
  min();
  max();
  minmax();
}

int main() {
  kernel<<<32, 32>>>();
  cudaError_t err = cudaDeviceSynchronize();
  if (err != cudaSuccess) {
    printf("CUDA error %d\n", (int)err);
    return 1;
  }
  printf("Success!\n");
  return 0;
}

#else

#include <stdio.h>
int main() {
  printf("Success!\n");
  return 0;
}

#endif
