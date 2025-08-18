#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

#include "hip/hip_runtime.h"

// Tests for the functional correctness of the lowering of memset in device
// code. Various memsets are performed on device side and the result of each is
// compared to the corresponding operation on the host. Global, shared, and
// stack memory is tested.

#define VERBOSE 0

#define CHKHIP(r)                                                              \
  if (r != hipSuccess) {                                                       \
    std::cerr << hipGetErrorString(r) << std::endl;                            \
    abort();                                                                   \
  }

// Maximal number of bytes to set with a memset call, used to allocate
// buffers.
static constexpr size_t MaxBytesPerThread = 2048;

// LDS is small, so run only smaller tests there.
static constexpr size_t MaxLDSBytesPerThread = 128;

// Number of threads started in parallel.
static constexpr size_t NumMoveThreads = 2 * 32;

// Size of blocks in the grid used for threads. If the number of threads is
// smaller than this, it is used instead.
static constexpr size_t BlockSize = 256;

static constexpr size_t AllocSize = 2 * NumMoveThreads * MaxBytesPerThread;

static constexpr size_t LDSAllocSize =
    2 * NumMoveThreads * MaxLDSBytesPerThread;

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

/// Initialize \p alloc_size bytes of \p buf_device to increasing numbers
/// (modulo 256).
__global__ void init_kernel(uint8_t *buf_device, size_t alloc_size) {
  for (size_t i = 0; i < alloc_size; ++i) {
    buf_device[i] = (uint8_t)i;
  }
}

template <size_t SZ, uint8_t SetVal, bool const_size, bool use_tid,
          bool const_setval>
__global__ void memset_kernel_global(uint8_t *buf_device, size_t dst_idx,
                                     uint8_t dyn_setval, size_t dyn_sz) {
  (void)dyn_sz;
  int tid = blockDim.x * blockIdx.x + threadIdx.x;
  if (tid >= NumMoveThreads)
    return;
  uint8_t *thread_buf = buf_device + get_stride(SZ) * tid;

  if constexpr (const_size) {
    if constexpr (use_tid) {
      __builtin_memset(thread_buf + dst_idx, static_cast<uint8_t>(tid), SZ);
    } else if constexpr (const_setval) {
      __builtin_memset(thread_buf + dst_idx, SetVal, SZ);
    } else {
      __builtin_memset(thread_buf + dst_idx, dyn_setval, SZ);
    }
  } else {
    if constexpr (use_tid) {
      __builtin_memset(thread_buf + dst_idx, static_cast<uint8_t>(tid), dyn_sz);
    } else if constexpr (const_setval) {
      __builtin_memset(thread_buf + dst_idx, SetVal, dyn_sz);
    } else {
      __builtin_memset(thread_buf + dst_idx, dyn_setval, dyn_sz);
    }
  }
}

template <size_t SZ, uint8_t SetVal, bool const_size, bool use_tid,
          bool const_setval>
__global__ void memset_kernel_shared(uint8_t *buf_device, size_t dst_idx,
                                     uint8_t dyn_setval, size_t dyn_sz) {
  (void)dyn_sz;
  __shared__ uint8_t buf_shared[LDSAllocSize];
  int tid = blockDim.x * blockIdx.x + threadIdx.x;
  if (tid >= NumMoveThreads)
    return;
  constexpr size_t stride = get_stride(SZ);
  uint8_t *thread_buf = buf_device + stride * tid;
  uint8_t *thread_buf_shared = buf_shared + stride * tid;
  // Copy the original data to shared memory.
  __builtin_memcpy(thread_buf_shared, thread_buf, stride);

  // Perform the memset there.
  if constexpr (const_size) {
    if constexpr (use_tid) {
      __builtin_memset(thread_buf_shared + dst_idx, (uint8_t)tid, SZ);
    } else if constexpr (const_setval) {
      __builtin_memset(thread_buf_shared + dst_idx, SetVal, SZ);
    } else {
      __builtin_memset(thread_buf_shared + dst_idx, dyn_setval, SZ);
    }
  } else {
    if constexpr (use_tid) {
      __builtin_memset(thread_buf_shared + dst_idx, (uint8_t)tid, dyn_sz);
    } else if constexpr (const_setval) {
      __builtin_memset(thread_buf_shared + dst_idx, SetVal, dyn_sz);
    } else {
      __builtin_memset(thread_buf_shared + dst_idx, dyn_setval, dyn_sz);
    }
  }

  // Copy the modified data back to global memory.
  __builtin_memcpy(thread_buf, thread_buf_shared, stride);
}

template <size_t SZ, uint8_t SetVal, bool const_size, bool use_tid,
          bool const_setval>
__global__ void memset_kernel_stack(uint8_t *buf_device, size_t dst_idx,
                                    uint8_t dyn_setval, size_t dyn_sz) {
  (void)dyn_sz;
  constexpr size_t stride = get_stride(SZ);
  uint8_t buf_stack[stride];
  int tid = blockDim.x * blockIdx.x + threadIdx.x;
  if (tid >= NumMoveThreads)
    return;
  uint8_t *thread_buf = buf_device + stride * tid;
  // Copy the original data to the stack.
  __builtin_memcpy(buf_stack, thread_buf, stride);

  // Perform the memset there.
  if constexpr (const_size) {
    if constexpr (use_tid) {
      __builtin_memset(buf_stack + dst_idx, (uint8_t)tid, SZ);
    } else if constexpr (const_setval) {
      __builtin_memset(buf_stack + dst_idx, SetVal, SZ);
    } else {
      __builtin_memset(buf_stack + dst_idx, dyn_setval, SZ);
    }
  } else {
    if constexpr (use_tid) {
      __builtin_memset(buf_stack + dst_idx, (uint8_t)tid, dyn_sz);
    } else if constexpr (const_setval) {
      __builtin_memset(buf_stack + dst_idx, SetVal, dyn_sz);
    } else {
      __builtin_memset(buf_stack + dst_idx, dyn_setval, dyn_sz);
    }
  }

  // Copy the modified data back to global memory.
  __builtin_memcpy(thread_buf, buf_stack, stride);
}

template <size_t SZ, uint8_t SetVal>
bool run_test(uint8_t *buf_reference, uint8_t *buf_host, uint8_t *buf_device,
              size_t dst_idx, bool const_size, bool use_tid, bool const_setval,
              AddressSpace AS, size_t &differing_pos) {
  // Initialize device buffer.
  hipLaunchKernelGGL(init_kernel, dim3(1), dim3(1), 0, 0, buf_device,
                     AllocSize);
  CHKHIP(hipDeviceSynchronize());

  // Set up the reference buffer.
  for (size_t i = 0; i < AllocSize; ++i)
    buf_reference[i] = (uint8_t)i;

  // Simulate multi-threaded device-side memset on the host.
  for (size_t tid = 0; tid < NumMoveThreads; ++tid) {
    uint8_t *thread_buf = buf_reference + get_stride(SZ) * tid;
    uint8_t v = use_tid ? tid : SetVal;
    std::memset(thread_buf + dst_idx, v, SZ);
  }

  // Do the device-side memset.
  int block_size = std::min(BlockSize, NumMoveThreads);
  int num_blocks = (NumMoveThreads + block_size - 1) / block_size;

  // Select the right kernel with the right template paramters. This is done
  // using compile-time constant template parameters so that we can control
  // which memset arguments the compiler sees as constant, as this affects code
  // generation.
  void (*chosen_kernel)(uint8_t *, size_t, uint8_t, size_t) = nullptr;

#define SELECT_KERNEL_FOR_ADDRSPACE(AS)                                        \
  if (const_size) {                                                            \
    if (use_tid)                                                               \
      chosen_kernel = memset_kernel_##AS<SZ, SetVal, true, true, false>;       \
    else if (const_setval)                                                     \
      chosen_kernel = memset_kernel_##AS<SZ, SetVal, true, false, true>;       \
    else                                                                       \
      chosen_kernel = memset_kernel_##AS<SZ, SetVal, true, false, false>;      \
  } else {                                                                     \
    if (use_tid)                                                               \
      chosen_kernel = memset_kernel_##AS<SZ, SetVal, false, true, false>;      \
    else if (const_setval)                                                     \
      chosen_kernel = memset_kernel_##AS<SZ, SetVal, false, false, true>;      \
    else                                                                       \
      chosen_kernel = memset_kernel_##AS<SZ, SetVal, false, false, false>;     \
  }

  switch (AS) {
  case AddressSpace::GLOBAL:
    SELECT_KERNEL_FOR_ADDRSPACE(global);
    break;
  case AddressSpace::SHARED:
    SELECT_KERNEL_FOR_ADDRSPACE(shared);
    break;
  case AddressSpace::STACK:
    SELECT_KERNEL_FOR_ADDRSPACE(stack);
    break;
  };
  hipLaunchKernelGGL(chosen_kernel, dim3(num_blocks), dim3(block_size), 0, 0,
                     buf_device, dst_idx, SetVal, SZ);
  CHKHIP(hipDeviceSynchronize());

  // Fetch the result into buf_host.
  CHKHIP(hipMemcpy(buf_host, buf_device, AllocSize, hipMemcpyDeviceToHost));

  // Compare to the reference.
  bool success = true;
  for (size_t i = 0; i < AllocSize; ++i) {
    if (buf_host[i] != buf_reference[i]) {
      differing_pos = i;
      success = false;
      break;
    }
  }

  return success;
}

template <size_t SZ, uint8_t SetVal>
int run_tests(uint8_t *buf_reference, uint8_t *buf_host, uint8_t *buf_device,
              AddressSpace AS) {
  if (AS == AddressSpace::SHARED && SZ > MaxLDSBytesPerThread) {
    // LDS is too small for these tests.
    return 0;
  }
  assert(SZ <= MaxBytesPerThread &&
         "Increase MaxBytesPerThread for larger sizes");

  std::vector<size_t> indexes_to_test = {0, 1, SZ - 1, SZ};
  if (SZ > 8) {
    indexes_to_test.emplace_back(7);
    indexes_to_test.emplace_back(8);
  }
  if (SZ > 16) {
    indexes_to_test.emplace_back(15);
    indexes_to_test.emplace_back(16);
  }

  int nerrs = 0;

  size_t differing_pos = 0;
  auto test_indexes = [&](bool const_size, bool use_tid, bool const_setval) {
    for (const auto &dst_idx : indexes_to_test) {
      bool success = run_test<SZ, SetVal>(buf_reference, buf_host, buf_device,
                                          dst_idx, const_size, use_tid,
                                          const_setval, AS, differing_pos);
      nerrs += !success;
      if (VERBOSE || !success) {
        std::cout << "- memsetting [" << dst_idx << ", " << (dst_idx + SZ - 1)
                  << "] to ";
        if (use_tid) {
          std::cout << "the thread id";
        } else {
          std::cout << static_cast<int>(SetVal) << " ("
                    << (const_setval ? "const" : "dynamic") << ")";
        }
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
  test_indexes(false, false, false);
  test_indexes(false, false, true);
  test_indexes(false, true, false);

  // Different paths in codegen are taken if the move length is statically
  // known.
  if (VERBOSE)
    std::cout << "running tests for static move length " << SZ << " in "
              << as_names[AS] << " memory\n";
  test_indexes(true, false, false);
  test_indexes(true, false, true);
  test_indexes(true, true, false);

  return nerrs;
}

int main(void) {
  uint8_t *buf_device;
  CHKHIP(hipMalloc(&buf_device, AllocSize));

  std::unique_ptr<uint8_t> buf_host(new uint8_t[AllocSize]);
  std::unique_ptr<uint8_t> buf_reference(new uint8_t[AllocSize]);

  int nerrs = 0;
  for (AddressSpace AS :
       {AddressSpace::GLOBAL, AddressSpace::SHARED, AddressSpace::STACK}) {
    nerrs += run_tests<64, 0xbb>(buf_reference.get(), buf_host.get(),
                                 buf_device, AS);
    nerrs += run_tests<66, 0xbb>(buf_reference.get(), buf_host.get(),
                                 buf_device, AS);
    nerrs += run_tests<73, 0xbb>(buf_reference.get(), buf_host.get(),
                                 buf_device, AS);
    nerrs +=
        run_tests<3, 0xbb>(buf_reference.get(), buf_host.get(), buf_device, AS);
    nerrs +=
        run_tests<1, 0xbb>(buf_reference.get(), buf_host.get(), buf_device, AS);

    // Lengths that are large enough for the IR lowering in the constant
    // case, with simple residual, no residual, and maximal residual:
    nerrs += run_tests<1025, 0xbb>(buf_reference.get(), buf_host.get(),
                                   buf_device, AS);
    nerrs += run_tests<1040, 0xbb>(buf_reference.get(), buf_host.get(),
                                   buf_device, AS);
    nerrs += run_tests<1039, 0xbb>(buf_reference.get(), buf_host.get(),
                                   buf_device, AS);
  }

  CHKHIP(hipFree(buf_device));

  if (nerrs != 0) {
    std::cout << nerrs << " errors\n";
    return 1;
  }
  std::cout << "PASSED!\n";
  return 0;
}
