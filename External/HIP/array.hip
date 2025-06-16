#include "hip/hip_runtime.h"
// Check that we can use std::array on device code
//
// After libstdc++ 15, some internal asserts rely on function that are neither
// constexpr nor device. This can trigger errors when using std::array members
// on device code.
//
// This workaround is implemented in bits/c++config.h

#include <stdio.h>

#if __cplusplus >= 201103L

#include <array>
#include <assert.h>

#if __cplusplus >= 201402L && STDLIB_VERSION >= 2014
// call the function in a constexpr and a non-constexpr context
#define TEST(expr)                                                             \
  do {                                                                         \
    size_t M = expr;                                                           \
    (void)(M);                                                                 \
    constexpr size_t N = expr;                                                 \
    (void)(N);                                                                 \
  } while (0)
#define MAYBE_CONSTEXPR constexpr
#else
#define TEST(expr)                                                             \
  do {                                                                         \
    size_t M = expr;                                                           \
    (void)(M);                                                                 \
  } while (0)
#define MAYBE_CONSTEXPR
#endif

MAYBE_CONSTEXPR __host__ __device__ size_t test_array() {
  // Before C++17 only "operator[] const" is constexpr (thus available on
  // device).
#if __cplusplus < 201703L && STDLIB_VERSION < 2017
  const
#endif
      std::array<int, 4>
          A = {0, 1, 2, 3};

  size_t N = A.size();
  assert(N == 4);

#if __cplusplus >= 201402L && STDLIB_VERSION >= 2014
  int fst = A[0];
  assert(fst == 0);
#endif

#if __cplusplus >= 201703L && STDLIB_VERSION >= 2017
  A[0] = 4;
  int snd = A[0];
  assert(snd == 4);
#endif
  return N;
}

__host__ __device__ void do_all_tests() { TEST(test_array()); }

__global__ void kernel() { do_all_tests(); }

int main() {
  kernel<<<32, 32>>>();
  hipError_t err = hipDeviceSynchronize();
  if (err != hipSuccess) {
    printf("CUDA error %d\n", (int)err);
    return 1;
  }

  do_all_tests();

  printf("Success!\n");
  return 0;
}

#else

int main() {
  printf("Success!\n");
  return 0;
}

#endif
