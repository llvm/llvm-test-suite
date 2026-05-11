#include <hip/hip_runtime.h>

#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#define HIP_CHECK(call)                                                         \
  do {                                                                        \
    hipError_t err = call;                                                    \
    if (err != hipSuccess) {                                                  \
      fprintf(stderr, "HIP error %d at %s:%d\n", (int)err, __FILE__,          \
              __LINE__);                                                      \
      std::exit(EXIT_FAILURE);                                                \
    }                                                                         \
  } while (0)

// Regression: uint64_t divided by int8_t kernel argument must be correct when
// the divisor is 1 (was miscompiled for some targets).
__global__ void hipsmit_kernel(int8_t divisor, uint64_t *results) {
  uint64_t si1 = 4294967295u;
  uint64_t safe_div = si1 / divisor;
  *results = safe_div;
}

__host__ static uint64_t host_reference(int8_t divisor) {
  uint64_t si1 = 4294967295u;
  return si1 / divisor;
}

int main() {
  uint64_t *d_out = nullptr;
  HIP_CHECK(hipMalloc(reinterpret_cast<void **>(&d_out), sizeof(uint64_t)));

  // Divisor is a host variable so the value is fixed at launch, not when the
  // kernel is emitted.
  int8_t divisor = 1;
  hipsmit_kernel<<<1, 1>>>(divisor, d_out);
  HIP_CHECK(hipGetLastError());
  HIP_CHECK(hipDeviceSynchronize());

  uint64_t h_out = 0;
  HIP_CHECK(
      hipMemcpy(&h_out, d_out, sizeof(uint64_t), hipMemcpyDeviceToHost));
  HIP_CHECK(hipFree(d_out));

  const uint64_t expected = host_reference(divisor);
  if (h_out != expected) {
    fprintf(stderr, "FAIL: divisor=%" PRId8 " got %" PRIu64 " expected %" PRIu64 "\n",
            divisor, h_out, expected);
    return 1;
  }

  printf("PASSED!\n");
  return 0;
}
