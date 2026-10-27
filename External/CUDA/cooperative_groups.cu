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

// cooperative_groups/reduce.h needs C++11, and from CUDA 13 on the headers
// include libcu++, which needs C++17.
#if __cplusplus >= 201703L || (__cplusplus >= 201103L && CUDA_VERSION < 13000)

#include <assert.h>

#include <cooperative_groups.h>
#include <cooperative_groups/reduce.h>

namespace cg = cooperative_groups;

const int threads = 128;
const int tile_size = 32;

__global__ void test_groups() {
  cg::thread_block block = cg::this_thread_block();
  int rank = block.thread_rank();
  assert(block.size() == threads);
  assert(rank == (int)threadIdx.x);

  // After the block synchronizes, each thread sees what another one wrote.
  __shared__ int ranks[threads];
  ranks[rank] = rank;
  block.sync();
  assert(ranks[threads - 1 - rank] == threads - 1 - rank);

  cg::thread_block_tile<tile_size> tile = cg::tiled_partition<tile_size>(block);
  int first = tile.meta_group_rank() * tile_size;
  assert(tile.size() == tile_size);
  assert(tile.thread_rank() == rank % tile_size);
  assert(first == rank - rank % tile_size);
  assert(tile.shfl(rank, 0) == first);

  // first + (first + 1) + ... + (first + tile_size - 1).
  int sum = cg::reduce(tile, rank, cg::plus<int>());
  assert(sum == first * tile_size + tile_size * (tile_size - 1) / 2);
}

int main() {
  test_groups<<<1, threads>>>();
  cudaError_t err = cudaDeviceSynchronize();
  if (err != cudaSuccess) {
    printf("CUDA error %d\n", (int)err);
    return 1;
  }
  printf("Success!\n");
  return 0;
}

#else

// A C++ standard which the headers do not support; the test is a no-op.
int main() {
  printf("Success!\n");
  return 0;
}

#endif
