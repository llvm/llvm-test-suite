//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <cassert>
#include <stdio.h>

// Test the implementation of llvm intrinsic round. In particular, when the
// source is equidistant between two integers, it rounds away from zero.
//
// In CUDA libdevice, the implementation of round separates the values into
// three regions and uses a region specific rounding method to calculate
// the result:
//    abs(x) <= 0.5
//    2 ^ 23 > abs(x) > 0.5 (float)
//    abs(x) >= 2 ^ 23 (float)
//    For double, 2 ^ 23 above is replaced with 2 ^ 52
//
// The PTX backend implements round in a similar way. We chose the test values
// based on this.

__global__ void test_round(float v) {
  assert(__builtin_roundf(-0.5f + v) == -1.0f);
  assert(__builtin_roundf(8.5f + v) == 9.0f);
  assert(__builtin_roundf(-8.38861e+06f + v) == -8.38861e+06f);
  assert(__builtin_roundf(8.38861e+06f + v) == 8.38861e+06f);

  assert(__builtin_round(0.5 + v) == 1.0f);
  assert(__builtin_round(-8.5 + v) == -9.0f);
  assert(__builtin_round(4.5035996e+15 + v) == 4.5035996e+15);
  assert(__builtin_round(-4.5035996e+15 + v) == -4.5035996e+15);
  // test values beyond +/- max(float)
  assert(__builtin_round(3.4e39 + v) == 3.4e39);
  assert(__builtin_round(-3.4e39 + v) == -3.4e39);
}

int main(int argc, char* argv[]) {
  float host_value = 0;

  // Launch the kernel.
  test_round<<<1, 1>>>(0);
  cudaError_t err = cudaDeviceSynchronize();
  if (err != cudaSuccess) {
    printf("CUDA error %d\n", (int)err);
    return 1;
  }

  printf("Success!\n");
  return 0;
}
