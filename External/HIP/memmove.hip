#include <cassert>
#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

#include "hip/hip_runtime.h"

// Tests for the functional correctness of the lowering of memmove in device
// code, including moves with overlapping source and destination ranges. Various
// memmoves are performed on device side and the result of each is compared to
// the corresponding operation on the host.
// Global, shared, and stack memory is tested.

#define VERBOSE 0

#define CHKHIP(r)                                                              \
  if (r != hipSuccess) {                                                       \
    std::cerr << hipGetErrorString(r) << std::endl;                            \
    abort();                                                                   \
  }

using item_type = uint8_t;

// Maximal number of bytes to copy with a memmove call, used to allocate
// buffers.
#define MAX_BYTES_PER_THREAD 2048

// LDS is small, so run only smaller tests there.
#define MAX_BYTES_PER_THREAD_SHARED 128

// Number of threads that move started in parallel.
#define NUM_MOVE_THREADS (2 * 32)

// Size of blocks in the grid used for move threads. If the number of threads is
// smaller than this, it is used instead.
#define BLOCK_SIZE 256

#define ALLOC_SIZE (2 * NUM_MOVE_THREADS * MAX_BYTES_PER_THREAD)

#define ALLOC_SIZE_SHARED (2 * NUM_MOVE_THREADS * MAX_BYTES_PER_THREAD_SHARED)

#define TESTED_FUNCTION __builtin_memmove

enum AddressSpace {
  GLOBAL = 0,
  SHARED = 1,
  STACK = 2,
};

static const char *as_names[] = {
    "global",
    "shared",
    "stack",
};

static constexpr size_t get_stride(size_t bytes_per_thread) {
  return 2 * bytes_per_thread;
}

__global__ void init_kernel(item_type *buf_device, size_t alloc_size) {
  for (size_t i = 0; i < alloc_size; ++i) {
    buf_device[i] = (item_type)i;
  }
}

template <size_t SZ>
__global__ void move_kernel_global_const(item_type *buf_device, size_t src_idx,
                                         size_t dst_idx, size_t dyn_sz) {
  (void)dyn_sz;
  int tid = blockDim.x * blockIdx.x + threadIdx.x;
  if (tid >= NUM_MOVE_THREADS)
    return;
  item_type *thread_buf = buf_device + get_stride(SZ) * tid;
  TESTED_FUNCTION(thread_buf + dst_idx, thread_buf + src_idx, SZ);
}

template <size_t SZ>
__global__ void move_kernel_shared_const(item_type *buf_device, size_t src_idx,
                                         size_t dst_idx, size_t dyn_sz) {
  (void)dyn_sz;
  __shared__ item_type buf_shared[ALLOC_SIZE_SHARED];
  int tid = blockDim.x * blockIdx.x + threadIdx.x;
  if (tid >= NUM_MOVE_THREADS)
    return;
  constexpr size_t stride = get_stride(SZ);
  item_type *thread_buf = buf_device + stride * tid;
  item_type *thread_buf_shared = buf_shared + stride * tid;
  // Copy the original data to shared memory.
  __builtin_memcpy(thread_buf_shared, thread_buf, stride);
  // Perform the move there.
  TESTED_FUNCTION(thread_buf_shared + dst_idx, thread_buf_shared + src_idx, SZ);
  // Copy the modified data back to global memory.
  __builtin_memcpy(thread_buf, thread_buf_shared, stride);
}

template <size_t SZ>
__global__ void move_kernel_stack_const(item_type *buf_device, size_t src_idx,
                                        size_t dst_idx, size_t dyn_sz) {
  (void)dyn_sz;
  constexpr size_t stride = get_stride(SZ);
  item_type buf_stack[stride];
  int tid = blockDim.x * blockIdx.x + threadIdx.x;
  if (tid >= NUM_MOVE_THREADS)
    return;
  item_type *thread_buf = buf_device + stride * tid;
  // Copy the original data to the stack.
  __builtin_memcpy(buf_stack, thread_buf, stride);
  // Perform the move there.
  TESTED_FUNCTION(buf_stack + dst_idx, buf_stack + src_idx, SZ);
  // Copy the modified data back to global memory.
  __builtin_memcpy(thread_buf, buf_stack, stride);
}

__global__ void move_kernel_global_var(item_type *buf_device, size_t src_idx,
                                       size_t dst_idx, size_t dyn_sz) {
  int tid = blockDim.x * blockIdx.x + threadIdx.x;
  if (tid >= NUM_MOVE_THREADS)
    return;
  item_type *thread_buf = buf_device + get_stride(dyn_sz) * tid;
  TESTED_FUNCTION(thread_buf + dst_idx, thread_buf + src_idx, dyn_sz);
}

__global__ void move_kernel_shared_var(item_type *buf_device, size_t src_idx,
                                       size_t dst_idx, size_t dyn_sz) {
  __shared__ item_type buf_shared[ALLOC_SIZE_SHARED];
  int tid = blockDim.x * blockIdx.x + threadIdx.x;
  if (tid >= NUM_MOVE_THREADS)
    return;
  size_t stride = get_stride(dyn_sz);
  item_type *thread_buf = buf_device + stride * tid;
  item_type *thread_buf_shared = buf_shared + stride * tid;
  // Copy the original data to shared memory.
  __builtin_memcpy(thread_buf_shared, thread_buf, stride);
  // perform the move there
  TESTED_FUNCTION(thread_buf_shared + dst_idx, thread_buf_shared + src_idx,
                  dyn_sz);
  // Copy the modified data back to global memory.
  __builtin_memcpy(thread_buf, thread_buf_shared, stride);
}

template <size_t SZ>
__global__ void move_kernel_stack_var(item_type *buf_device, size_t src_idx,
                                      size_t dst_idx, size_t dyn_sz) {
  // We use the static SZ to allocate a fixed-size stack variable.
  constexpr size_t stride = get_stride(SZ);
  item_type buf_stack[stride];
  int tid = blockDim.x * blockIdx.x + threadIdx.x;
  if (tid >= NUM_MOVE_THREADS)
    return;
  item_type *thread_buf = buf_device + stride * tid;
  // Copy the original data to the stack.
  __builtin_memcpy(buf_stack, thread_buf, stride);
  // perform the move there
  TESTED_FUNCTION(buf_stack + dst_idx, buf_stack + src_idx, dyn_sz);
  // Copy the modified data back to global memory.
  __builtin_memcpy(thread_buf, buf_stack, stride);
}

template <size_t SZ>
bool run_test(item_type *buf_reference, item_type *buf_host,
              item_type *buf_device, size_t src_idx, size_t dst_idx,
              bool const_size, AddressSpace AS, size_t &differing_pos) {
  // Initialize device buffer.
  hipLaunchKernelGGL(init_kernel, dim3(1), dim3(1), 0, 0, buf_device,
                     ALLOC_SIZE);
  CHKHIP(hipDeviceSynchronize());

  // Set up the reference buffer.
  for (size_t i = 0; i < ALLOC_SIZE; ++i)
    buf_reference[i] = (item_type)i;

  // Simulate multi-threaded device-side memmove on the host.
  for (size_t tid = 0; tid < NUM_MOVE_THREADS; ++tid) {
    item_type *thread_buf = buf_reference + get_stride(SZ) * tid;
    std::memmove(thread_buf + dst_idx, thread_buf + src_idx, SZ);
  }

  // Do the device-side memmove.
  int block_size = std::min(BLOCK_SIZE, NUM_MOVE_THREADS);
  int num_blocks = (NUM_MOVE_THREADS + block_size - 1) / block_size;

  switch (AS) {
  case AddressSpace::GLOBAL:
    hipLaunchKernelGGL(const_size ? move_kernel_global_const<SZ>
                                  : move_kernel_global_var,
                       dim3(num_blocks), dim3(block_size), 0, 0, buf_device,
                       src_idx, dst_idx, SZ);
    break;
  case AddressSpace::SHARED:
    hipLaunchKernelGGL(const_size ? move_kernel_shared_const<SZ>
                                  : move_kernel_shared_var,
                       dim3(num_blocks), dim3(block_size), 0, 0, buf_device,
                       src_idx, dst_idx, SZ);
    break;
  case AddressSpace::STACK:
    hipLaunchKernelGGL(const_size ? move_kernel_stack_const<SZ>
                                  : move_kernel_stack_var<SZ>,
                       dim3(num_blocks), dim3(block_size), 0, 0, buf_device,
                       src_idx, dst_idx, SZ);
    break;
  };
  CHKHIP(hipDeviceSynchronize());

  // Fetch the result into buf_host.
  CHKHIP(hipMemcpy(buf_host, buf_device, ALLOC_SIZE, hipMemcpyDeviceToHost));

  // Compare to the reference.
  bool success = true;
  for (size_t i = 0; i < ALLOC_SIZE; ++i) {
    if (buf_host[i] != buf_reference[i]) {
      differing_pos = i;
      success = false;
      break;
    }
  }

  return success;
}

template <size_t SZ>
int run_tests(item_type *buf_reference, item_type *buf_host,
              item_type *buf_device, AddressSpace AS) {
  if (AS == AddressSpace::SHARED && SZ > MAX_BYTES_PER_THREAD_SHARED) {
    // LDS is too small for these tests.
    return 0;
  }
  assert(SZ <= MAX_BYTES_PER_THREAD &&
         "Increase MAX_BYTES_PER_THREAD for larger sizes");

  std::vector<std::pair<size_t, size_t>> index_combinations = {
      {0, 1}, {0, SZ}, {0, SZ - 1}, {1, 0}, {SZ, 0}, {SZ - 1, 0},
  };
  if (SZ > 16) {
    index_combinations.emplace_back(0, 16);
    index_combinations.emplace_back(16, 0);
  }

  int nerrs = 0;

  size_t differing_pos = 0;
  auto test_index_combinations = [&](bool const_size) {
    for (const auto &[src_idx, dst_idx] : index_combinations) {
      bool success = run_test<SZ>(buf_reference, buf_host, buf_device, src_idx,
                                  dst_idx, const_size, AS, differing_pos);
      nerrs += !success;
      if (VERBOSE || !success) {
        std::cout << "- moving [" << src_idx << ", " << (src_idx + SZ - 1)
                  << "] -> [" << dst_idx << ", " << (dst_idx + SZ - 1) << "]";
        if (!VERBOSE) {
          std::cout << " with " << (const_size ? "static" : "dynamic")
                    << " size in " << as_names[AS] << " memory";
        }
        std::cout << ":";
        if (success) {
          std::cout << " successful\n";
        } else {
          std::cout << " failed\n    -> first difference at index "
                    << differing_pos << '\n';
        }
      }
    }
  };

  if (VERBOSE)
    std::cout << "running tests for dynamic move length " << SZ << " in "
              << as_names[AS] << " memory\n";
  test_index_combinations(false);

  // Different paths in codegen are taken if the move length is statically
  // known.
  if (VERBOSE)
    std::cout << "running tests for static move length " << SZ << " in "
              << as_names[AS] << " memory\n";
  test_index_combinations(true);

  return nerrs;
}

int main(void) {
  item_type *buf_device;
  CHKHIP(hipMalloc(&buf_device, ALLOC_SIZE));

  std::unique_ptr<item_type> buf_host(new item_type[ALLOC_SIZE]);
  std::unique_ptr<item_type> buf_reference(new item_type[ALLOC_SIZE]);

  int nerrs = 0;
  for (AddressSpace AS :
       {AddressSpace::GLOBAL, AddressSpace::SHARED, AddressSpace::STACK}) {
    nerrs += run_tests<64>(buf_reference.get(), buf_host.get(), buf_device, AS);
    nerrs += run_tests<66>(buf_reference.get(), buf_host.get(), buf_device, AS);
    nerrs += run_tests<73>(buf_reference.get(), buf_host.get(), buf_device, AS);
    nerrs += run_tests<3>(buf_reference.get(), buf_host.get(), buf_device, AS);
    nerrs += run_tests<1>(buf_reference.get(), buf_host.get(), buf_device, AS);

    // Move lengths that are large enough for the IR lowering in the constant
    // case, with simple residual, no residual, and maximal residual:
    nerrs +=
        run_tests<1025>(buf_reference.get(), buf_host.get(), buf_device, AS);
    nerrs +=
        run_tests<1040>(buf_reference.get(), buf_host.get(), buf_device, AS);
    nerrs +=
        run_tests<1039>(buf_reference.get(), buf_host.get(), buf_device, AS);
  }

  CHKHIP(hipFree(buf_device));

  if (nerrs != 0) {
    std::cout << nerrs << " errors\n";
    return 1;
  }
  std::cout << "PASSED!\n";
  return 0;
}
