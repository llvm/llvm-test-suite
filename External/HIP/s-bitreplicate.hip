#include <hip/hip_runtime.h>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <vector>

// Test __builtin_amdgcn_s_bitreplicate, which copies bit i of its operand to
// bits 2i and 2i+1 of the result.

#define HIP_CHECK(call)                                                        \
  do {                                                                         \
    hipError_t err = (call);                                                   \
    if (err != hipSuccess) {                                                   \
      printf("HIP error at %s:%d - %s\n", __FILE__, __LINE__,                  \
             hipGetErrorString(err));                                          \
      std::exit(EXIT_FAILURE);                                                 \
    }                                                                          \
  } while (0)

__global__ void bitreplicate_kernel(uint64_t *out, const uint32_t *in) {
  out[blockIdx.x] = __builtin_amdgcn_s_bitreplicate(in[blockIdx.x]);
}

static uint64_t reference(uint32_t x) {
  uint64_t r = 0;
  for (unsigned i = 0; i < 32; ++i)
    if (x & (1u << i))
      r |= (uint64_t)0x3 << (2 * i);
  return r;
}

int main() {
  // Inputs are nonzero so that a result left at its zero fill fails.
  std::vector<uint32_t> in = {0xffffffffu, 0x85fe3a92u, 0x12345678u};
  for (unsigned i = 0; i < 32; ++i)
    in.push_back(1u << i);
  const unsigned n = in.size();

  uint32_t *d_in = nullptr;
  uint64_t *d_out = nullptr;
  HIP_CHECK(hipMalloc(&d_in, n * sizeof(uint32_t)));
  HIP_CHECK(hipMalloc(&d_out, n * sizeof(uint64_t)));
  HIP_CHECK(hipMemset(d_out, 0, n * sizeof(uint64_t)));
  HIP_CHECK(
      hipMemcpy(d_in, in.data(), n * sizeof(uint32_t), hipMemcpyHostToDevice));
  bitreplicate_kernel<<<n, 1>>>(d_out, d_in);
  HIP_CHECK(hipGetLastError());
  HIP_CHECK(hipDeviceSynchronize());
  std::vector<uint64_t> out(n);
  HIP_CHECK(hipMemcpy(out.data(), d_out, n * sizeof(uint64_t),
                      hipMemcpyDeviceToHost));
  HIP_CHECK(hipFree(d_in));
  HIP_CHECK(hipFree(d_out));

  int errors = 0;
  for (unsigned i = 0; i < n; ++i) {
    uint64_t expected = reference(in[i]);
    if (out[i] != expected) {
      printf("error: in=0x%08x got=0x%016llx expected=0x%016llx\n", in[i],
             (unsigned long long)out[i], (unsigned long long)expected);
      ++errors;
    }
  }
  if (errors)
    printf("%d errors\n", errors);
  else
    printf("PASSED!\n");
  return errors != 0;
}
