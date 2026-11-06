//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// The half-precision types of cuda_fp16.h and cuda_bf16.h. Their conversions
// and arithmetic are inline code in those headers, which Clang compiles. Apart
// from the conversions which must round, every value here is exactly
// representable in both types, so every result is exact. The headers only
// provide fused multiply-add from sm_53 on for __half, and from sm_80 on for
// __nv_bfloat16.

#include <stdio.h>

// Requires CUDA 12.2+, which emulates the arithmetic on older GPUs.
#if CUDA_VERSION < 12020

// An unsupported CUDA version; the test is a no-op.
int main() {
  printf("Success!\n");
  return 0;
}

#else

#include <assert.h>

#include <cuda_bf16.h>
#include <cuda_fp16.h>

// Conversions which must round, on the host and on the device. Around 0.7 the
// halves are 1/2048 apart, and 0.7 is between 1433/2048 and 1434/2048, nearer
// the second. Around 0.1 the bfloat16s are 1/2048 apart too, and 0.1 is between
// 204/2048 and 205/2048, nearer the second.
__host__ __device__ bool conversions_round() {
  return __half2float(__float2half_rn(0.7f)) == 1434.0f / 2048 &&
         __half2float(__float2half_rz(0.7f)) == 1433.0f / 2048 &&
         __bfloat162float(__float2bfloat16_rn(0.1f)) == 205.0f / 2048 &&
         __bfloat162float(__float2bfloat16_rz(0.1f)) == 204.0f / 2048;
}

__global__ void test_half() {
  __half a = __float2half(1.5f);
  __half b = __float2half(-2.25f);
  assert(__half2float(a) == 1.5f);
  assert(__half2float(__hadd(a, b)) == -0.75f);
  assert(__half2float(__hsub(a, b)) == 3.75f);
  assert(__half2float(__hmul(a, b)) == -3.375f);
#if __CUDA_ARCH__ >= 530
  assert(__half2float(__hfma(a, b, a)) == -1.875f);
#endif
  assert(__hlt(b, a) && !__hlt(a, b));
  assert(__half2int_rz(__float2half(-2.75f)) == -2);

  // The operators, which most code uses rather than the functions.
  assert(__half2float(a + b) == -0.75f);
  assert(__half2float(a * b) == -3.375f);
  assert(b < a && !(a < b));

  __half2 v = __halves2half2(a, b);
  __half2 squares = __hmul2(v, v);
  assert(__low2float(squares) == 2.25f);
  assert(__high2float(squares) == 5.0625f);
}

__global__ void test_bfloat16() {
  __nv_bfloat16 a = __float2bfloat16(1.5f);
  __nv_bfloat16 b = __float2bfloat16(-2.25f);
  assert(__bfloat162float(a) == 1.5f);
  assert(__bfloat162float(__hadd(a, b)) == -0.75f);
  assert(__bfloat162float(__hsub(a, b)) == 3.75f);
  assert(__bfloat162float(__hmul(a, b)) == -3.375f);
#if __CUDA_ARCH__ >= 800
  assert(__bfloat162float(__hfma(a, b, a)) == -1.875f);
#endif
  assert(__hlt(b, a) && !__hlt(a, b));
  assert(__bfloat162int_rz(__float2bfloat16(-2.75f)) == -2);

  // The operators, which most code uses rather than the functions.
  assert(__bfloat162float(a + b) == -0.75f);
  assert(__bfloat162float(a * b) == -3.375f);
  assert(b < a && !(a < b));

  __nv_bfloat162 v = __halves2bfloat162(a, b);
  __nv_bfloat162 squares = __hmul2(v, v);
  assert(__low2float(squares) == 2.25f);
  assert(__high2float(squares) == 5.0625f);
}

__global__ void test_conversions() { assert(conversions_round()); }

static bool check(cudaError_t err) {
  if (err != cudaSuccess)
    printf("CUDA error %d\n", (int)err);
  return err == cudaSuccess;
}

int main() {
  assert(conversions_round());
  test_half<<<1, 1>>>();
  test_bfloat16<<<1, 1>>>();
  test_conversions<<<1, 1>>>();
  // Check that the kernels launched, as one which did not would check nothing,
  // and then that they ran without failing.
  if (!check(cudaGetLastError()) || !check(cudaDeviceSynchronize()))
    return 1;
  printf("Success!\n");
  return 0;
}

#endif
