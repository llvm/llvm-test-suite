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

#define NUM_BITS 23
#define SHIFT_AMOUNT (32 - NUM_BITS)

// Kernel that performs signed 23-bit division
__global__ void signed_div23_kernel(const int *__restrict__ dividends,
                                    const int *__restrict__ divisors,
                                    int *__restrict__ quotients,
                                    int *__restrict__ remainders, int n) {
  int idx = blockIdx.x * blockDim.x + threadIdx.x;

  if (idx < n) {
    // Sign-extend NUM_BITS-bit values to ensure compiler knows these fit in
    // NUM_BITS bits Shift left by SHIFT_AMOUNT to move NUM_BITS bits to top,
    // then arithmetic shift right to sign-extend

    int dividend = (dividends[idx] << SHIFT_AMOUNT) >> SHIFT_AMOUNT;
    int divisor = (divisors[idx] << SHIFT_AMOUNT) >> SHIFT_AMOUNT;

    quotients[idx] = dividend / divisor;
    remainders[idx] = dividend % divisor;
  }
}

int main(int argc, char **argv) {
  // dividends and divisors were chosen to be:
  // 1. Values from [-3,3]
  // 2. Maximum negative and positive values
  // 3. Divisors for which v_rcp_f32 generates reciprocals with poor accuracy.
  // 4. Dividends which are the maximum multiple of a divisor in #3 in the
  //    signed 23-bit range minus one.
  
  int h_dividends[] = {
      -0x400000, -0x000003, -0x000002, -0x000001, 0x000000, 0x000001, 0x000002,
      0x000003,  0x3ffb69,  0x3ffb69,  0x3fe9e4,  0x3fede6, 0x3fde62, 0x3ffec2,
      0x3ff5ed,  0x3fdb9b,  0x3ffaba,  0x3fc9ff,  0x3fcdff, 0x3fd2ff, 0x3fdcff,
      0x3f9f41,  0x3fb3ea,  0x3fbf81,  0x3fc40a,  0x3fd62e, 0x3ff5ed, 0x3ffc7a,
      0x3f857f,  0x3f977f,  0x3f9bff,  0x3fb07f,  0x3fb87f, 0x3fbaff, 0x3f20ff,
      0x3f29bf,  0x3f357f,  0x3f40ff,  0x3f457f,  0x3f577f, 0x3f703f, 0x3f733f,
      0x3f76ff,  0x3f7d7f,  0x3FFFFF,
  };

  int h_divisors[] = {
      -0x400000, -0x000003, -0x000002, -0x000001, 0x000001, 0x000002, 0x000003,
      0x000FE7,  0x001FCE,  0x001FE5,  0x001FE7,  0x003F21, 0x003F41, 0x003F77,
      0x003F9C,  0x003FBB,  0x003FCA,  0x003FCE,  0x003FD3, 0x003FDD, 0x007E42,
      0x007E6B,  0x007E82,  0x007E8B,  0x007EAF,  0x007EEE, 0x007EFB, 0x007F0B,
      0x007F2F,  0x007F38,  0x007F61,  0x007F71,  0x007F76, 0x00FC84, 0x00FCA7,
      0x00FCD6,  0x00FD04,  0x00FD16,  0x00FD5E,  0x00FDC1, 0x00FDCD, 0x00FDDC,
      0x00FDF6,  0x3FFFFF,
  };

  int num_dividends = sizeof(h_dividends) / sizeof(h_dividends[0]);
  int num_divisors = sizeof(h_divisors) / sizeof(h_divisors[0]);

  // Test all divisors
  int n = num_dividends * num_divisors;

  // Allocate host memory for all combinations
  size_t bytes = n * sizeof(int);
  int *h_all_dividends = (int *)malloc(bytes);
  int *h_all_divisors = (int *)malloc(bytes);
  int *h_quotients = (int *)malloc(bytes);
  int *h_remainders = (int *)malloc(bytes);

  // Generate all combinations
  int idx = 0;
  for (int i = 0; i < num_dividends; i++) {
    for (int j = 0; j < num_divisors; j++) {
      h_all_dividends[idx] = (h_dividends[i] << SHIFT_AMOUNT) >> SHIFT_AMOUNT;
      h_all_divisors[idx] = (h_divisors[j] << SHIFT_AMOUNT) >> SHIFT_AMOUNT;
      idx++;
    }
  }

  // Allocate device memory
  int *d_dividends, *d_divisors, *d_quotients, *d_remainders;
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

  hipLaunchKernelGGL(signed_div23_kernel, dim3(numBlocks), dim3(blockSize), 0,
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
    int dividend = (h_all_dividends[i] << SHIFT_AMOUNT) >> SHIFT_AMOUNT;
    int divisor = (h_all_divisors[i] << SHIFT_AMOUNT) >> SHIFT_AMOUNT;

    int expected_q = (divisor != 0) ? (dividend / divisor) : 0;
    int expected_r = (divisor != 0) ? (dividend % divisor) : 0;

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
