#include <hip/hip_runtime.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK_HIP(call)                                                        \
  {                                                                            \
    hipError_t err = call;                                                     \
    if (err != hipSuccess) {                                                   \
      printf("HIP error at %s:%d - %s\n", __FILE__, __LINE__,                  \
             hipGetErrorString(err));                                          \
      exit(1);                                                                 \
    }                                                                          \
  }

// Kernel that performs unsigned 24-bit division
__global__ void
unsigned_div24_kernel(const unsigned int *__restrict__ dividends,
                      const unsigned int *__restrict__ divisors,
                      unsigned int *__restrict__ quotients,
                      unsigned int *__restrict__ remainders, int n) {
  int idx = blockIdx.x * blockDim.x + threadIdx.x;

  if (idx < n) {
    // Mask to 24 bits to ensure we're in the 24-bit range.
    // This allows compiler to attempt optimized 24-bit div/rem path.
    unsigned int dividend = dividends[idx] & 0xFFFFFF;
    unsigned int divisor = divisors[idx] & 0xFFFFFF;

    quotients[idx] = dividend / divisor;
    remainders[idx] = dividend % divisor;
  }
}

int main(int argc, char **argv) {
  // dividends and denominators were chosen to hit limitations
  // of expandDivRem24Impl in compiler backend.
  unsigned int h_dividends[] = {
      0xA201C1, 0xB129DB, 0xB33EBF, 0xBA592F, 0xBB97C5, 0xBF9B5F, 0xC1E44C,
      0xC458D8, 0xC561AA, 0xC5E7F3, 0xC696FB, 0xC8E17F, 0xC9FE33, 0xD32A9D,
      0xD6E353, 0xD79F3F, 0xDA6C6F, 0xDA6CD1, 0xDBC305, 0xDEE03C, 0xDFFAAE,
      0xE1303A, 0xE32067, 0xE819A3, 0xE8D81A, 0xEBF3C9, 0xEC1CD1, 0xED674F,
      0xEE53D7, 0xF0E09D, 0xF1299A, 0xF13C71, 0xF3381E, 0xF677EB, 0xF67FA7,
      0xF866BF, 0xF905CF, 0xFC2FBD, 0xFDA151, 0xFE38EC,
  };

  unsigned int h_divisors[] = {
      0x000017, 0x00002E, 0x000075, 0x0000B0, 0x000147, 0x000159, 0x0001B9,
      0x0001D7, 0x0002BD, 0x0003AE, 0x0003C6, 0x000547, 0x0005DA, 0x000689,
      0x0009EF, 0x000B85, 0x00157E, 0x001F84, 0x003FB5, 0x0062CB, 0x00BA03,
      0x015C7B, 0x020CC0, 0x02AF2E, 0x02C514, 0x03756A, 0x05FCDB, 0x05FD50,
      0x0AF630, 0x0CB159, 0x0DE12A, 0x0F866C, 0x181FA5, 0x1ECFF5, 0x20FBFE,
      0x2BF3CE, 0x5112B5, 0x7ED0A9, 0xE1303B, 0xE8D81B,
  };

  int num_dividends = sizeof(h_dividends) / sizeof(h_dividends[0]);
  int num_divisors = sizeof(h_divisors) / sizeof(h_divisors[0]);

  // Test all combinations
  int n = num_dividends * num_divisors;

  // Allocate host memory for all combinations
  size_t bytes = n * sizeof(unsigned int);
  unsigned int *h_all_dividends = (unsigned int *)malloc(bytes);
  unsigned int *h_all_divisors = (unsigned int *)malloc(bytes);
  unsigned int *h_quotients = (unsigned int *)malloc(bytes);
  unsigned int *h_remainders = (unsigned int *)malloc(bytes);

  // Generate all combinations
  int idx = 0;
  for (int i = 0; i < num_dividends; i++) {
    for (int j = 0; j < num_divisors; j++) {
      h_all_dividends[idx] = h_dividends[i];
      h_all_divisors[idx] = h_divisors[j];
      idx++;
    }
  }

  // Allocate device memory
  unsigned int *d_dividends, *d_divisors, *d_quotients, *d_remainders;
  CHECK_HIP(hipMalloc(&d_dividends, bytes));
  CHECK_HIP(hipMalloc(&d_divisors, bytes));
  CHECK_HIP(hipMalloc(&d_quotients, bytes));
  CHECK_HIP(hipMalloc(&d_remainders, bytes));

  // Copy data to device
  CHECK_HIP(
      hipMemcpy(d_dividends, h_all_dividends, bytes, hipMemcpyHostToDevice));
  CHECK_HIP(
      hipMemcpy(d_divisors, h_all_divisors, bytes, hipMemcpyHostToDevice));

  // Launch kernel
  int blockSize = 256;
  int numBlocks = (n + blockSize - 1) / blockSize;

  hipLaunchKernelGGL(unsigned_div24_kernel, dim3(numBlocks), dim3(blockSize), 0,
                     0, d_dividends, d_divisors, d_quotients, d_remainders, n);

  CHECK_HIP(hipGetLastError());
  CHECK_HIP(hipDeviceSynchronize());

  // Copy results back
  CHECK_HIP(hipMemcpy(h_quotients, d_quotients, bytes, hipMemcpyDeviceToHost));
  CHECK_HIP(
      hipMemcpy(h_remainders, d_remainders, bytes, hipMemcpyDeviceToHost));

  // Verify all results
  int errors = 0;
  for (int i = 0; i < n; i++) {
    // Mask to 24 bits
    unsigned int dividend = h_all_dividends[i] & 0xFFFFFF;
    unsigned int divisor = h_all_divisors[i] & 0xFFFFFF;

    unsigned int expected_q = (divisor != 0) ? (dividend / divisor) : 0;
    unsigned int expected_r = (divisor != 0) ? (dividend % divisor) : 0;

    if (h_quotients[i] != expected_q || h_remainders[i] != expected_r) {
      printf("FAILURE: 0x%06X / 0x%06X\n", dividend, divisor);
      printf("  Got:      quotient = %u (0x%06X), remainder = %u (0x%06X)\n",
             h_quotients[i], h_quotients[i], h_remainders[i], h_remainders[i]);
      printf("  Expected: quotient = %u (0x%06X), remainder = %u (0x%06X)\n",
             expected_q, expected_q, expected_r, expected_r);
      errors++;
    }
  }

  if (errors == 0) {
    printf("PASSED!\n");
  }

  // Cleanup
  free(h_all_dividends);
  free(h_all_divisors);
  free(h_quotients);
  free(h_remainders);
  CHECK_HIP(hipFree(d_dividends));
  CHECK_HIP(hipFree(d_divisors));
  CHECK_HIP(hipFree(d_quotients));
  CHECK_HIP(hipFree(d_remainders));

  return errors > 0 ? 1 : 0;
}
