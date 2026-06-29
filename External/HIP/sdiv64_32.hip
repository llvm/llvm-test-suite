#include <hip/hip_runtime.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define CHECK_HIP(call)                                                        \
  {                                                                            \
    hipError_t err = call;                                                     \
    if (err != hipSuccess) {                                                   \
      printf("HIP error at %s:%d - %s\n", __FILE__, __LINE__,                  \
             hipGetErrorString(err));                                          \
      exit(1);                                                                 \
    }                                                                          \
  }

#define SHIFT 32

// Kernel performs signed 64-bit division with operands in a 32-bit signed range
__global__ void
sdiv64_kernel(const int64_t *__restrict__ dividends,
              const int64_t *__restrict__ divisors,
              int64_t *__restrict__ quotients,
              int64_t *__restrict__ remainders,
              int n) {
  int idx = blockIdx.x * blockDim.x + threadIdx.x;

  if (idx < n) {
    // Sign-extend from (64-SHIFT) bits to 64 bits
    int64_t dividend = (dividends[idx] << SHIFT) >> SHIFT;
    int64_t divisor = (divisors[idx] << SHIFT) >> SHIFT;

    quotients[idx] = dividend / divisor;
    remainders[idx] = dividend % divisor;
  }
}

int main(int argc, char **argv) {
  // Test values to cover edge cases and various ranges (32-bit signed)
  int64_t test_values[] = {
      // Zero
      0LL,

      // Small positive values
      1LL, 2LL, 3LL, 7LL, 15LL, 31LL, 63LL, 127LL, 255LL, 511LL, 1023LL,

      // Powers of 2 and near powers of 2
      1024LL, 2048LL, 4096LL, 8192LL, 16384LL, 32768LL, 65536LL,
      (1LL << 20), (1LL << 21), (1LL << 22), (1LL << 23),
      (1LL << 30),

      // Large positive values (within 32-bit signed range)
      0x7FFFFFFFLL,       // Max 32-bit signed (2^31 - 1)
      0x7FFFFFFELL,       // Max 32-bit signed - 1
      0x7FFFFFF0LL,       // Near max 32-bit signed
      0x40000000LL,       // 2^30

      // Small negative values
      -1LL, -2LL, -3LL, -7LL, -15LL, -31LL, -63LL, -127LL, -255LL,

      // Large negative values (within 32-bit signed range)
      -0x80000000LL,      // Min 32-bit signed (-2^31)
      -0x7FFFFFFFLL,      // Min 32-bit signed + 1
      -0x7FFFFFF0LL,      // Near min 32-bit signed
      -0x40000000LL,      // -2^30

      // Random test values (within 32-bit signed range) - 150 additional values
      0x12345678LL, -0x12345678LL, 0x7BCDEF01LL, -0x7BCDEF01LL,
      0x55555555LL, -0x55555555LL, 0x2AAAAAAAAA, -0x2AAAAAAALL,
      0x11111111LL, -0x11111111LL, 0x22222222LL, -0x22222222LL,
      0x33333333LL, -0x33333333LL, 0x44444444LL, -0x44444444LL,
      0x66666666LL, -0x66666666LL, 0x77777777LL, -0x77777777LL,
      0x0FFFFFFFLL, -0x0FFFFFFFLL, 0x1FFFFFFFLL, -0x1FFFFFFFLL,
      0x3FFFFFFFLL, -0x3FFFFFFFLL, 0x5FFFFFFFLL, -0x5FFFFFFFLL,
      0x6FFFFFFFLL, -0x6FFFFFFFLL, 0x70000000LL, -0x70000000LL,
      0x60000000LL, -0x60000000LL, 0x50000000LL, -0x50000000LL,
      0x30000000LL, -0x30000000LL, 0x20000000LL, -0x20000000LL,
      0x10000000LL, -0x10000000LL, 0x08000000LL, -0x08000000LL,
      0x04000000LL, -0x04000000LL, 0x02000000LL, -0x02000000LL,
      0x01000000LL, -0x01000000LL, 0x00800000LL, -0x00800000LL,
      0x00400000LL, -0x00400000LL, 0x00200000LL, -0x00200000LL,
      0x00100000LL, -0x00100000LL, 0x00080000LL, -0x00080000LL,
      0x00040000LL, -0x00040000LL, 0x00020000LL, -0x00020000LL,
      0x00010000LL, -0x00010000LL, 0x00008000LL, -0x00008000LL,
      0x00004000LL, -0x00004000LL, 0x00002000LL, -0x00002000LL,
      0x00001000LL, -0x00001000LL, 0x00000800LL, -0x00000800LL,
      0x00000400LL, -0x00000400LL, 0x00000200LL, -0x00000200LL,
      0x00000100LL, -0x00000100LL, 0x00000080LL, -0x00000080LL,
      0x00000040LL, -0x00000040LL, 0x00000020LL, -0x00000020LL,
      0x00000010LL, -0x00000010LL, 0x00000008LL, -0x00000008LL,
      0x00000004LL, -0x00000004LL, 0x7FFFFF00LL, -0x7FFFFF00LL,
      0x7FFFFE00LL, -0x7FFFFE00LL, 0x7FFFFC00LL, -0x7FFFFC00LL,
      0x7FFFF800LL, -0x7FFFF800LL, 0x7FFFF000LL, -0x7FFFF000LL,
      0x7FFFE000LL, -0x7FFFE000LL, 0x7FFFC000LL, -0x7FFFC000LL,
      0x7FFF8000LL, -0x7FFF8000LL, 0x7FFF0000LL, -0x7FFF0000LL,
      0x7FFE0000LL, -0x7FFE0000LL, 0x7FFC0000LL, -0x7FFC0000LL,
      0x7FF80000LL, -0x7FF80000LL, 0x7FF00000LL, -0x7FF00000LL,
      0x7FE00000LL, -0x7FE00000LL, 0x7FC00000LL, -0x7FC00000LL,
      0x7F800000LL, -0x7F800000LL, 0x7F000000LL, -0x7F000000LL,
      0x7E000000LL, -0x7E000000LL, 0x7C000000LL, -0x7C000000LL,
      0x78000000LL, -0x78000000LL, 0x01234567LL, -0x01234567LL,
      0x02468ACELL, -0x02468ACELL, 0x13579BDFLL, -0x13579BDFLL,
      0x0ABCDEF0LL, -0x0ABCDEF0LL, 0x1111AAAAAA, -0x1111AAAAALL,
      0x2222BBBBLL, -0x2222BBBBLL, 0x3333CCCCLL, -0x3333CCCCLL,
      0x4444DDDDLL, -0x4444DDDDLL, 0x5555EEEELL, -0x5555EEEELL,
      0x6666FFFFLL, -0x6666FFFFLL,
  };

  int num_test_values = sizeof(test_values) / sizeof(test_values[0]);

  // Generate test cases: all pairwise combinations
  int n = num_test_values * num_test_values;
  size_t bytes = n * sizeof(int64_t);

  int64_t *h_dividends = (int64_t *)malloc(bytes);
  int64_t *h_divisors = (int64_t *)malloc(bytes);
  int64_t *h_quotients = (int64_t *)malloc(bytes);
  int64_t *h_remainders = (int64_t *)malloc(bytes);

  // Generate all pairwise combinations
  int idx = 0;
  for (int i = 0; i < num_test_values; i++) {
    for (int j = 0; j < num_test_values; j++) {
      h_dividends[idx] = test_values[i];
      h_divisors[idx] = test_values[j];
      idx++;
    }
  }

  // Allocate device memory
  int64_t *d_dividends, *d_divisors, *d_quotients, *d_remainders;
  CHECK_HIP(hipMalloc(&d_dividends, bytes));
  CHECK_HIP(hipMalloc(&d_divisors, bytes));
  CHECK_HIP(hipMalloc(&d_quotients, bytes));
  CHECK_HIP(hipMalloc(&d_remainders, bytes));

  // Copy data to device
  CHECK_HIP(hipMemcpy(d_dividends, h_dividends, bytes, hipMemcpyHostToDevice));
  CHECK_HIP(hipMemcpy(d_divisors, h_divisors, bytes, hipMemcpyHostToDevice));

  // Launch kernel
  int blockSize = 256;
  int numBlocks = (n + blockSize - 1) / blockSize;

  hipLaunchKernelGGL(sdiv64_kernel, dim3(numBlocks), dim3(blockSize), 0,
                     0, d_dividends, d_divisors, d_quotients, d_remainders, n);

  CHECK_HIP(hipGetLastError());
  CHECK_HIP(hipDeviceSynchronize());

  // Copy results back
  CHECK_HIP(hipMemcpy(h_quotients, d_quotients, bytes, hipMemcpyDeviceToHost));
  CHECK_HIP(hipMemcpy(h_remainders, d_remainders, bytes, hipMemcpyDeviceToHost));

  // Verify results
  int errors = 0;
  for (int i = 0; i < n; i++) {
    // Apply sign extension to match what the kernel does
    int64_t dividend = (h_dividends[i] << SHIFT) >> SHIFT;
    int64_t divisor = (h_divisors[i] << SHIFT) >> SHIFT;

    // Skip division by zero cases
    if (divisor == 0) continue;

    int64_t expected_q = dividend / divisor;
    int64_t expected_r = dividend % divisor;

    if (h_quotients[i] != expected_q || h_remainders[i] != expected_r) {
      printf("FAILURE [64-bit]: %lld / %lld\n",
             (long long)dividend, (long long)divisor);
      printf("  Got:      quotient = %lld (0x%llX), remainder = %lld (0x%llX)\n",
             (long long)h_quotients[i], (unsigned long long)h_quotients[i],
             (long long)h_remainders[i], (unsigned long long)h_remainders[i]);
      printf("  Expected: quotient = %lld (0x%llX), remainder = %lld (0x%llX)\n",
             (long long)expected_q, (unsigned long long)expected_q,
             (long long)expected_r, (unsigned long long)expected_r);
      errors++;
      if (errors >= 10) {
        printf("... (stopping after 10 errors)\n");
        break;
      }
    }
  }

  if (errors == 0) {
    printf("PASSED!\n");
  } else {
    printf("FAILED with %d errors\n", errors);
  }

  // Cleanup
  free(h_dividends);
  free(h_divisors);
  free(h_quotients);
  free(h_remainders);
  CHECK_HIP(hipFree(d_dividends));
  CHECK_HIP(hipFree(d_divisors));
  CHECK_HIP(hipFree(d_quotients));
  CHECK_HIP(hipFree(d_remainders));

  return errors > 0 ? 1 : 0;
}
