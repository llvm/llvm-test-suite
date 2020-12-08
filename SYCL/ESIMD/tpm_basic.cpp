//==---------------- basic_tpm.cpp  - DPC++ ESIMD on-device test
//------------==//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// TODO enable on Windows and Level Zero
// REQUIRES: linux && gpu && opencl
// RUN: %clangxx-esimd -fsycl %s -o %t.out
// RUN: %HOST_RUN_PLACEHOLDER %t.out
// RUN: %ESIMD_RUN_PLACEHOLDER %t.out

#include "esimd_test_utils.hpp"

#include <CL/sycl.hpp>
#include <CL/sycl/INTEL/esimd.hpp>
#include <iostream>

using namespace cl::sycl;

int main(void) {
  constexpr unsigned VL = 8;
  constexpr unsigned SZ = 800; // big enough to use TPM

  queue q(esimd_test::ESIMDSelector{}, esimd_test::createExceptionHandler());

  auto dev = q.get_device();
  std::cout << "Running on " << dev.get_info<info::device::name>() << "\n";
  auto ctx = q.get_context();

  int *output = static_cast<int *>(malloc_shared(VL * sizeof(int), dev, ctx));
  memset(output, 0, VL * sizeof(int));

  int off1 = 16;
  int off2 = 128;
  int base1 = 500;
  int base2 = 100;
  int divisor = 4;

  {
    auto e = q.submit([&](handler &cgh) {
      cgh.parallel_for<class Test>(
          sycl::range<1>{1}, [=](id<1> i) SYCL_ESIMD_KERNEL {
            using namespace sycl::INTEL::gpu;

            int x1[SZ];
            for (int j = 0; j < SZ; ++j) {
              int idx = (j + off1) % SZ;
              x1[idx] = (idx % 2) == 0 ? j : base1;
            }

            int x2[SZ];
            for (int j = 0; j < SZ; ++j) {
              int idx = (j + off2) % SZ;
              x2[idx] = base2 << (j % 32);
            }

            // some work with X1
            for (int j = 1; j < SZ; ++j) {
              if ((x1[j] + j) > base1)
                x1[j] = (j * (x1[j] + x1[j - 1]) / divisor) - base2;
            }

            // some work with X2
            for (int j = 1; j < SZ; ++j) {
              if ((x2[j] + j) > base2)
                x2[j] = (divisor * (x2[j] - x2[j - 1]) / j) + base1;
            }

            simd<int, VL> val(0);
            for (int j = 0; j < SZ; ++j)
              val.select<1, 1>(j % VL) += x1[j] - x2[j];
            block_store<int, VL>(output, val);
          });
    });
    e.wait();
  }

  int x1[SZ];
  for (int j = 0; j < SZ; ++j) {
    int idx = (j + off1) % SZ;
    x1[idx] = (idx % 2) == 0 ? j : base1;
  }

  // same work with X1
  for (int j = 1; j < SZ; ++j) {
    if ((x1[j] + j) > base1)
      x1[j] = (j * (x1[j] + x1[j - 1]) / divisor) - base2;
  }

  int x2[SZ];
  for (int j = 0; j < SZ; ++j) {
    int idx = (j + off2) % SZ;
    x2[idx] = base2 << (j % 32);
  }

  // same work with X2
  for (int j = 1; j < SZ; ++j) {
    if ((x2[j] + j) > base2)
      x2[j] = (divisor * (x2[j] - x2[j - 1]) / j) + base1;
  }

  int o[VL] = {0};
  for (int j = 0; j < SZ; ++j)
    o[j % VL] += x1[j] - x2[j];

  int err_cnt = 0;
  for (int j = 0; j < VL; ++j)
    if (output[j] != o[j])
      err_cnt += 1;

  if (err_cnt > 0) {
    std::cout << "FAILED.\n";
    return 1;
  }

  std::cout << "Passed\n";
  return 0;
}
