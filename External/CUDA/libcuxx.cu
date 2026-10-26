//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// libcu++, the C++ standard library for device code which ships with the CUDA
// toolkit, used in device code: cuda::std::array, cuda::std::numeric_limits,
// and cuda::atomic_ref, with which every thread counts itself.

#include <stdio.h>

// libcu++ needs C++11, and C++17 from CUDA 13 on.
#if __cplusplus >= 201703L || (__cplusplus >= 201103L && CUDA_VERSION < 13000)

#include <assert.h>

#include <cuda/atomic>
#include <cuda/std/array>
#include <cuda/std/cstdint>
#include <cuda/std/limits>

const int threads = 64;

__global__ void test_libcuxx(int *count) {
  cuda::std::array<int, 3> array = {{1, 2, 3}};
  assert(array.size() == 3);
  assert(array[0] == 1 && array.back() == 3);

  assert(cuda::std::numeric_limits<cuda::std::int32_t>::max() == 2147483647);
  assert(cuda::std::numeric_limits<cuda::std::uint8_t>::max() == 255);

  cuda::atomic_ref<int, cuda::thread_scope_device> counter(*count);
  counter.fetch_add(1, cuda::std::memory_order_relaxed);
}

int main() {
  int *dcount;
  cudaMalloc(&dcount, sizeof(int));
  cudaMemset(dcount, 0, sizeof(int));
  test_libcuxx<<<1, threads>>>(dcount);
  // The copy waits for the kernel, and fails if the kernel did.
  int count = 0;
  cudaError_t err =
      cudaMemcpy(&count, dcount, sizeof(int), cudaMemcpyDeviceToHost);
  if (err != cudaSuccess) {
    printf("CUDA error %d\n", (int)err);
    return 1;
  }
  cudaFree(dcount);
  if (count != threads) {
    printf("Counted %d threads, expected %d\n", count, threads);
    return 1;
  }
  printf("Success!\n");
  return 0;
}

#else

// A C++ standard which libcu++ does not support; the test is a nop.
int main() {
  printf("Success!\n");
  return 0;
}

#endif
