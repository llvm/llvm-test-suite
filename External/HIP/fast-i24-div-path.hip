#include <hip/hip_runtime.h>

#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstdlib>

#define HIP_CHECK(call)                                                        \
  do {                                                                         \
    hipError_t err = call;                                                     \
    if (err != hipSuccess) {                                                   \
      fprintf(stderr, "HIP error %d at %s:%d\n", (int)err, __FILE__,           \
              __LINE__);                                                       \
      std::exit(EXIT_FAILURE);                                                 \
    }                                                                          \
  } while (0)

// This test is validating AMDGPUTargetLowering::LowerDIVREM24
// which exhibited a miscompilation for the unsigned case.

// Regression: The compiler was optimizing the division incorrectly assuming
// that the operand fit in 24-bit integers (unsigned case).
__global__ void div_u64_i8(int8_t divisor, uint64_t *results) {
  uint64_t si1 = 4294967295u;
  uint64_t safe_div = si1 / divisor;
  *results = safe_div;
}

// unsigned case: 24-bit integer optimization can be applied.
__global__ void div_u8_u8_to_i64(uint8_t divisor, int64_t *results) {
  uint8_t si1 = 1;
  int64_t safe_div = si1 / divisor;
  *results = safe_div;
}

// signed case: 24-bit integer optimization cannot be applied.
__global__ void div_i32_i8_to_i64(int8_t divisor, int64_t *results) {
  int32_t si1 = -1;
  int64_t safe_div = si1 / divisor;
  *results = safe_div;
}

// signed case: 24-bit integer optimization can be applied.
__global__ void div_i8_i8_to_i64(int8_t divisor, int64_t *results) {
  int8_t si1 = 1;
  int64_t safe_div = si1 / divisor;
  *results = safe_div;
}

__host__ static uint64_t host_reference_u64_i8(int8_t divisor) {
  uint64_t si1 = 4294967295u;
  return si1 / divisor;
}

__host__ static int64_t host_reference_i32_i8_to_i64(int8_t divisor) {
  int32_t si1 = -1;
  int64_t safe_div = si1 / divisor;
  return safe_div;
}

__host__ static int64_t host_reference_u8_u8_to_i64(uint8_t divisor) {
  uint8_t si1 = 1;
  int64_t safe_div = si1 / divisor;
  return safe_div;
}

__host__ static int64_t host_reference_i8_i8_to_i64(int8_t divisor) {
  int8_t si1 = 1;
  int64_t safe_div = si1 / divisor;
  return safe_div;
}

int main() {
  uint64_t *d_out_u64 = nullptr;
  HIP_CHECK(hipMalloc(reinterpret_cast<void **>(&d_out_u64), sizeof(uint64_t)));

  // Divisor is a host variable so the value is fixed at launch, not when the
  // kernel is emitted.
  int8_t divisor = 1;
  div_u64_i8<<<1, 1>>>(divisor, d_out_u64);
  HIP_CHECK(hipGetLastError());
  HIP_CHECK(hipDeviceSynchronize());

  uint64_t h_out_u64 = 0;
  HIP_CHECK(hipMemcpy(&h_out_u64, d_out_u64, sizeof(uint64_t),
                      hipMemcpyDeviceToHost));
  HIP_CHECK(hipFree(d_out_u64));

  const uint64_t expected_u64 = host_reference_u64_i8(divisor);
  if (h_out_u64 != expected_u64) {
    fprintf(stderr,
            "FAIL (u64/i8): divisor=%" PRId8 " got %" PRIu64
            " expected %" PRIu64 "\n",
            divisor, h_out_u64, expected_u64);
    return 1;
  }

  uint8_t divisor_u8 = 1;
  int64_t *d_out_u8 = nullptr;
  HIP_CHECK(hipMalloc(reinterpret_cast<void **>(&d_out_u8), sizeof(int64_t)));

  div_u8_u8_to_i64<<<1, 1>>>(divisor_u8, d_out_u8);
  HIP_CHECK(hipGetLastError());
  HIP_CHECK(hipDeviceSynchronize());

  int64_t h_out_u8 = 0;
  HIP_CHECK(
      hipMemcpy(&h_out_u8, d_out_u8, sizeof(int64_t), hipMemcpyDeviceToHost));
  HIP_CHECK(hipFree(d_out_u8));

  const int64_t expected_u8 = host_reference_u8_u8_to_i64(divisor_u8);
  if (h_out_u8 != expected_u8) {
    fprintf(stderr,
            "FAIL (u8/u8->i64): divisor=%" PRIu8 " got %" PRId64
            " expected %" PRId64 "\n",
            divisor_u8, h_out_u8, expected_u8);
    return 1;
  }

  int64_t *d_out_i8 = nullptr;
  HIP_CHECK(hipMalloc(reinterpret_cast<void **>(&d_out_i8), sizeof(int64_t)));

  div_i8_i8_to_i64<<<1, 1>>>(divisor, d_out_i8);
  HIP_CHECK(hipGetLastError());
  HIP_CHECK(hipDeviceSynchronize());

  int64_t h_out_i8 = 0;
  HIP_CHECK(
      hipMemcpy(&h_out_i8, d_out_i8, sizeof(int64_t), hipMemcpyDeviceToHost));
  HIP_CHECK(hipFree(d_out_i8));

  const int64_t expected_i8 = host_reference_i8_i8_to_i64(divisor);
  if (h_out_i8 != expected_i8) {
    fprintf(stderr,
            "FAIL (i8/i8->i64): divisor=%" PRId8 " got %" PRId64
            " expected %" PRId64 "\n",
            divisor, h_out_i8, expected_i8);
    return 1;
  }

  int64_t *d_out_i64 = nullptr;
  HIP_CHECK(hipMalloc(reinterpret_cast<void **>(&d_out_i64), sizeof(int64_t)));

  div_i32_i8_to_i64<<<1, 1>>>(divisor, d_out_i64);
  HIP_CHECK(hipGetLastError());
  HIP_CHECK(hipDeviceSynchronize());

  int64_t h_out_i64 = 0;
  HIP_CHECK(
      hipMemcpy(&h_out_i64, d_out_i64, sizeof(int64_t), hipMemcpyDeviceToHost));
  HIP_CHECK(hipFree(d_out_i64));

  const int64_t expected_i64 = host_reference_i32_i8_to_i64(divisor);
  if (h_out_i64 != expected_i64) {
    fprintf(stderr,
            "FAIL (i32/i8->i64): divisor=%" PRId8 " got %" PRId64
            " expected %" PRId64 "\n",
            divisor, h_out_i64, expected_i64);
    return 1;
  }

  printf("PASSED!\n");
  return 0;
}
