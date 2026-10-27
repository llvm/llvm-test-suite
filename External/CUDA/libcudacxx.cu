//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// libcu++, the C++ standard library for device code which ships with the CUDA
// toolkit, used in device code: cuda::std::array, cuda::std::numeric_limits,
// and cuda::atomic_ref, with which every thread adds an element of an array to
// a sum.

#include <stdio.h>

// Requires CUDA 12.9+, and C++11 (CUDA 12) or C++17 (CUDA 13+).
#if CUDA_VERSION < 12090 || __cplusplus < 201103L || \
    (CUDA_VERSION >= 13000 && __cplusplus < 201703L)

// An unsupported CUDA version or C++ standard; the test is a no-op.
int main() {
  printf("Success!\n");
  return 0;
}

#elif !__has_include(<cuda/std/atomic>)

// From CUDA 13 on, libcu++ is in include/cccl of the toolkit, which Clang does
// not search yet: https://github.com/llvm/llvm-project/pull/235910. Fail here
// rather than at compile time, so that the other tests still build.
int main() {
  printf("libcu++ not found\n");
  return 1;
}

#else

#include <assert.h>

#include <cuda/atomic>
#include <cuda/std/array>
#include <cuda/std/cstdint>
#include <cuda/std/limits>

using cuda::std::numeric_limits;
static_assert(numeric_limits<cuda::std::int32_t>::max() == 2147483647, "");
static_assert(numeric_limits<cuda::std::uint8_t>::max() == 255, "");

const int threads = 64;

// Each thread adds element threadIdx.x % 3 of {1, 2, 3} to the sum. Of the 64
// threads, 22 add 1, 21 add 2 and 21 add 3.
const int expected_sum = 22 * 1 + 21 * 2 + 21 * 3;

__global__ void test_libcudacxx(int *sum) {
  cuda::std::array<int, 3> array = {{1, 2, 3}};
  assert(array.size() == 3);
  assert(array.front() == 1 && array.back() == 3);

  cuda::atomic_ref<int, cuda::thread_scope_device> sum_ref(*sum);
  sum_ref.fetch_add(array[threadIdx.x % 3], cuda::std::memory_order_relaxed);
}

static bool check(cudaError_t err) {
  if (err != cudaSuccess)
    printf("CUDA error %d\n", (int)err);
  return err == cudaSuccess;
}

int main() {
  int *dsum;
  if (!check(cudaMalloc(&dsum, sizeof(int))) ||
      !check(cudaMemset(dsum, 0, sizeof(int))))
    return 1;
  test_libcudacxx<<<1, threads>>>(dsum);
  // Copy the sum back. The copy waits for the kernel, and fails if it did.
  int sum = 0;
  if (!check(cudaMemcpy(&sum, dsum, sizeof(int), cudaMemcpyDeviceToHost)))
    return 1;
  cudaFree(dsum);
  if (sum != expected_sum) {
    printf("Sum is %d, expected %d\n", sum, expected_sum);
    return 1;
  }
  printf("Success!\n");
  return 0;
}

#endif
