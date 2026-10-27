//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// Cooperative groups, which cooperative_groups.h implements in inline device
// code that Clang compiles: synchronizing a thread block, partitioning it into
// tiles, shuffling within a tile, and reducing over a tile with
// cooperative_groups/reduce.h.

#include <stdio.h>

// Requires CUDA 12.9+, and C++11 (CUDA 12) or C++17 (CUDA 13+, whose headers
// use libcu++).
#if CUDA_VERSION < 12090 || __cplusplus < 201103L || \
    (CUDA_VERSION >= 13000 && __cplusplus < 201703L)

// An unsupported CUDA version or C++ standard; the test is a no-op.
int main() {
  printf("Success!\n");
  return 0;
}

#elif !__has_include(<cuda/std/type_traits>)

// From CUDA 13 on, the headers include libcu++, which is in include/cccl of the
// toolkit, which Clang does not search yet:
// https://github.com/llvm/llvm-project/pull/235910. Fail here rather than at
// compile time, so that the other tests still build.
int main() {
  printf("libcu++ not found\n");
  return 1;
}

#else

#include <assert.h>

#include <cooperative_groups.h>
#include <cooperative_groups/reduce.h>

namespace cg = cooperative_groups;

const int threads = 128;
const int tile_size = 32;

__global__ void test_groups() {
  cg::thread_block block = cg::this_thread_block();
  int rank = block.thread_rank();
  assert(block.num_threads() == threads);
  assert(rank == (int)threadIdx.x);

  // After the block synchronizes, each thread sees what another one wrote.
  __shared__ int ranks[threads];
  ranks[rank] = rank;
  block.sync();
  assert(ranks[threads - 1 - rank] == threads - 1 - rank);

  cg::thread_block_tile<tile_size> tile = cg::tiled_partition<tile_size>(block);
  int first = tile.meta_group_rank() * tile_size;
  assert(tile.num_threads() == tile_size);
  assert(tile.thread_rank() == rank % tile_size);
  assert(first == rank - rank % tile_size);
  assert(tile.shfl(rank, 0) == first);

  // first + (first + 1) + ... + (first + tile_size - 1).
  int sum = cg::reduce(tile, rank, cg::plus<int>());
  assert(sum == first * tile_size + tile_size * (tile_size - 1) / 2);
}

static bool check(cudaError_t err) {
  if (err != cudaSuccess)
    printf("CUDA error %d\n", (int)err);
  return err == cudaSuccess;
}

int main() {
  test_groups<<<1, threads>>>();
  // Check that the kernel launched, as one which did not would check nothing,
  // and then that it ran without failing.
  if (!check(cudaGetLastError()) || !check(cudaDeviceSynchronize()))
    return 1;
  printf("Success!\n");
  return 0;
}

#endif
