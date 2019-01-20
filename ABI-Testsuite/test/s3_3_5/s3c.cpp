// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
// RUN: cxx_compiler %s -c -o %t.o
// RUN: linker %t.o -o %t%exeext
// RUN: bindump %t%exeext | tee %t.out |  FileCheck %s

#include <stdio.h>
#include <stdlib.h>

// Check that __dso_handle is present in an executable that calls atexit()

// CHECK: __dso_handle

void fn01() { printf("%s()\n", __FUNCTION__); }

int main(int argc, char *argv[]) {
  atexit(fn01);
  return 0;
}
