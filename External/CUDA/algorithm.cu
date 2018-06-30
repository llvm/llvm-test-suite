// Check that we can call some constexpr functions from <algorithm> and
// <functional> when compiling with C++14.  (We require C++14 because only in
// that version do these functions become constexpr and therefore implicitly
// __host__ __device__.)
//
// We assume our standard library is correct, but we still want to ensure that
// we can successfully compile and run the standard library's implementations
// of these functions.

#if __cplusplus >= 201103L

#include <assert.h>
#include <algorithm>
#include <functional>
#include <stdio.h>

__device__ void min() {
  assert(std::min(0, 1) == 0);
}
__host__ __device__ void min_hd() {
  assert(std::min(0, 1) == 0);
}

__device__ void max() {
  assert(std::max(0, 1) == 1);
}
__host__ __device__ void max_hd() {
  assert(std::max(0, 1) == 1);
}

// Clang has device-side shims implementing std::min and std::max for scalars
// starting in C++11, but doesn't implement minimax or std::min/max on
// initializer_lists until C++14, when it gets these for free from the standard
// library (because they're constexpr).
__device__ void cpp14_tests() {
#if __cplusplus >= 201402L && STDLIB_VERSION >= 2014
  assert(std::greater<int>()(1, 0));
  assert(std::min({5, 1, 10}) == 1);
  assert(std::max({5, 1, 10}, std::less<int>()) == 10);

  assert(std::minmax(1, 0).first == 0);
  assert(std::minmax(1, 0).second == 1);
  assert(std::minmax({0, 10, -10, 100}, std::less<int>()).first == -10);
  assert(std::minmax({0, 10, -10, 100}, std::less<int>()).second == 100);
  constexpr auto min = std::min(1, 2);
  constexpr auto max = std::max(1, 2);
#endif
}

// Same tests as cpp14_tests, but from a host-device context.
__host__ __device__ void cpp14_tests_hd() {
#if __cplusplus >= 201402L && STDLIB_VERSION >= 2014
  assert(std::greater<int>()(1, 0));
  assert(std::min({5, 1, 10}) == 1);
  assert(std::max({5, 1, 10}, std::less<int>()) == 10);

  assert(std::minmax(1, 0).first == 0);
  assert(std::minmax(1, 0).second == 1);
  assert(std::minmax({0, 10, -10, 100}, std::less<int>()).first == -10);
  assert(std::minmax({0, 10, -10, 100}, std::less<int>()).second == 100);
  constexpr auto min = std::min(1, 2);
  constexpr auto max = std::max(1, 2);
#endif
}

__global__ void kernel() {
  min();
  min_hd();
  max();
  max_hd();
  cpp14_tests();
  cpp14_tests_hd();
}

int main() {
  kernel<<<32, 32>>>();
  cudaError_t err = cudaDeviceSynchronize();
  if (err != cudaSuccess) {
    printf("CUDA error %d\n", (int)err);
    return 1;
  }

  min_hd();
  max_hd();
  cpp14_tests_hd();

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
