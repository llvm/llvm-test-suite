#include <hip/hip_runtime.h>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <memory>

// Execution test for the divergent lowering of s_bitreplicate (bit i -> bits
// 2i, 2i+1), which can be expanded on VALU via perm and shifts.

#define HIP_CHECK(call)                                                        \
  do {                                                                         \
    hipError_t err = (call);                                                   \
    if (err != hipSuccess) {                                                   \
      printf("HIP error: %s at %s:%d\n", hipGetErrorString(err), __FILE__,     \
             __LINE__);                                                        \
      std::exit(EXIT_FAILURE);                                                 \
    }                                                                          \
  } while (0)

__global__ void bitreplicate_kernel(uint64_t *out, int n) {
  int idx = blockIdx.x * blockDim.x + threadIdx.x;
  if (idx < n) {
    // Divergent input: differs between lanes within a wave.
    uint32_t v = idx * 2654435761u + 13u;
    out[idx] = __builtin_amdgcn_s_bitreplicate(v);
  }
}

static uint64_t reference_bitreplicate(uint32_t x) {
  uint64_t r = 0;
  for (int i = 0; i < 32; ++i)
    if (x & (1u << i))
      r |= (uint64_t)0x3 << (2 * i);
  return r;
}

int main() {
  const int N = 4096;
  const size_t bytes = N * sizeof(uint64_t);

  uint64_t *d_out = nullptr;
  HIP_CHECK(hipMalloc((void **)&d_out, bytes));

  const int threads = 256;
  bitreplicate_kernel<<<(N + threads - 1) / threads, threads>>>(d_out, N);
  HIP_CHECK(hipDeviceSynchronize());

  auto h_out = std::make_unique<uint64_t[]>(N);
  HIP_CHECK(hipMemcpy(h_out.get(), d_out, bytes, hipMemcpyDeviceToHost));

  int errors = 0;
  for (int i = 0; i < N; ++i) {
    uint32_t v = (uint32_t)i * 2654435761u + 13u;
    uint64_t expected = reference_bitreplicate(v);
    if (h_out[i] != expected) {
      if (errors < 8)
        printf("error i=%d in=0x%08x got=0x%016llx exp=0x%016llx\n", i, v,
               (unsigned long long)h_out[i], (unsigned long long)expected);
      ++errors;
    }
  }

  if (errors != 0)
    printf("%d errors\n", errors);
  else
    printf("PASSED!\n");

  HIP_CHECK(hipFree(d_out));
  return errors;
}
