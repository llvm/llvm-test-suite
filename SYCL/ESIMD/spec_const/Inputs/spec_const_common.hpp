//==--------------- spec_const_common.h  - DPC++ ESIMD on-device test -----===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// The test checks that ESIMD kernels support specialization constants for all
// basic types, particularly a specialization constant can be redifined and
// correct new value is used after redefinition.

#include <iostream>
#include <vector>

using namespace sycl;

class ConstID;
class TestKernel;

int main(int argc, char **argv) {
  queue q(esimd_test::ESIMDSelector{}, esimd_test::createExceptionHandler());
  auto dev = q.get_device();
  auto ctx = q.get_context();

  const int n_times = 2;
  std::vector<container_t> output(n_times);
  std::vector<container_t> etalon = {DEF_VAL, REDEF_VAL};

  bool passed = true;
  for (int i = 0; i < n_times; i++) {
    sycl::program prg(q.get_context());

    auto spec_const = prg.set_spec_constant<ConstID>((spec_const_t)DEF_VAL);
    if (i % 2 != 0)
      spec_const = prg.set_spec_constant<ConstID>((spec_const_t)REDEF_VAL);

    prg.build_with_kernel_type<TestKernel>();

    {
      sycl::buffer<container_t, 1> buf(output.data(), output.size());

      auto e = q.submit([&](sycl::handler &cgh) {
        auto acc = buf.get_access<sycl::access::mode::write>(cgh);
        cgh.single_task<TestKernel>(
          prg.get_kernel<TestKernel>(), [=]() SYCL_ESIMD_KERNEL {
          do_the_store(acc, i, spec_const.get());
        });
      });

      e.wait();
    }

    if (output[i] != etalon[i]) {
      passed = false;
      std::cout << "comparison error -- case #" << i << " -- ";
      std::cout << "output: " << output[i] << ", ";
      std::cout << "etalon: " << etalon[i] << std::endl;
    }
  }

  if (passed) {
    std::cout << "passed" << std::endl;
    return 0;
  } else {
    std::cout << "FAILED" << std::endl;
    return 1;
  }
}
