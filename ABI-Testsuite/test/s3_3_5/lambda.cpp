// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: cxx_compiler %s -c cxx_11 -o %t.o
// RUN: linker %t.o -o %t%exeext
// RUN: runtool %t%exeext | tee %t.out |FileCheck %s

// section 1: testing number of functions registered with atexit()

#include <stdio.h>
#include <stdlib.h>

void fn01() { printf("%s()", __FUNCTION__); }
void fn02() { printf("%s()", __FUNCTION__); }

int main(int argc, char *argv[]) {
  printf("main()");

  // CHECK: main()fn02()operator()()fn01()
  atexit(fn01);
  atexit([]() { printf("%s()", __FUNCTION__); });
  atexit(fn02);

  return 0;
}
