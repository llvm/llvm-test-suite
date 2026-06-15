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

// Kernel that performs unsigned 23-bit division
__global__ void
unsigned_div23_kernel(const unsigned int *__restrict__ dividends,
                      const unsigned int *__restrict__ divisors,
                      unsigned int *__restrict__ quotients,
                      unsigned int *__restrict__ remainders, int n) {
  int idx = blockIdx.x * blockDim.x + threadIdx.x;

  if (idx < n) {
    // Mask to 23 bits to ensure we're in the 23-bit range.
    // This allows compiler to attempt optimized 23-bit div/rem path.
    unsigned int dividend = dividends[idx] & 0x7FFFFF;
    unsigned int divisor = divisors[idx] & 0x7FFFFF;

    quotients[idx] = dividend / divisor;
    remainders[idx] = dividend % divisor;
  }
}

int main(int argc, char **argv) {
  // divisors were chosen to hit limitations of expandDivRem23Impl in compiler
  // backend.

  unsigned int h_divisors[] = {
      0x000FE7, 0x001FCE, 0x001FE5, 0x001FE7, 0x003F21, 0x003F41,
      0x003F77, 0x003F9C, 0x003FBB, 0x003FCA, 0x003FCE, 0x003FD3,
      0x003FDD, 0x007E42, 0x007E6B, 0x007E82, 0x007E8B, 0x007EAF,
      0x007EEE, 0x007EFB, 0x007F0B, 0x007F2F, 0x007F38, 0x007F61,
      0x007F71, 0x007F76, 0x00FC84, 0x00FCA7, 0x00FCD6, 0x00FD04,
      0x00FD16, 0x00FD5E, 0x00FDC1, 0x00FDCD, 0x00FDDC, 0x00FDF6,
  };

  int num_divisors = sizeof(h_divisors) / sizeof(h_divisors[0]);

  // Test all divisors
  int n = num_divisors;

  // Allocate host memory for all combinations
  size_t bytes = n * sizeof(unsigned int);
  unsigned int *h_all_dividends = (unsigned int *)malloc(bytes);
  unsigned int *h_all_divisors = (unsigned int *)malloc(bytes);
  unsigned int *h_quotients = (unsigned int *)malloc(bytes);
  unsigned int *h_remainders = (unsigned int *)malloc(bytes);

  // Generate all combinations
  int idx = 0;
  for (int i = 0; i < num_divisors; i++) {
    unsigned int divisor = h_divisors[i];
    h_all_dividends[idx] = (0x7FFFFF / divisor) * divisor - 1;
    h_all_divisors[idx] = divisor;
    idx++;
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

  hipLaunchKernelGGL(unsigned_div23_kernel, dim3(numBlocks), dim3(blockSize), 0,
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
    // Mask to 23 bits
    unsigned int dividend = h_all_dividends[i] & 0x7FFFFF;
    unsigned int divisor = h_all_divisors[i] & 0x7FFFFF;

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
