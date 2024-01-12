#pragma once
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include <cstdlib> // for std::abort()
#include <hip/hip_runtime.h>
#include <iostream>

void checkHIP(hipError_t resultCode, const char *errorMsg = "") {
  if (resultCode != hipSuccess) {
    std::cerr << "Error: " << errorMsg << " - " << hipGetErrorString(resultCode)
              << std::endl;
    std::abort();
  }
}
