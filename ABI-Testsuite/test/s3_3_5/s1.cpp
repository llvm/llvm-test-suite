// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: cxx_compiler %s -c -o %t.o
// RUN: linker %t.o -o %t%exeext
// RUN: runtool %t%exeext | tee %t.out | FileCheck %s

// section 1: testing number of functions registered with atexit()

#include <stdio.h>
#include <stdlib.h>

int global_counter = 0;

void fn01() { printf("%s()\n", __FUNCTION__); }
void fn02() { printf("%s()\n", __FUNCTION__); }
void fn03() { printf("%s()\n", __FUNCTION__); }
void fn04() { printf("%s()\n", __FUNCTION__); }
void fn05() { printf("%s()\n", __FUNCTION__); }
void fn06() { printf("%s()\n", __FUNCTION__); }
void fn07() { printf("%s()\n", __FUNCTION__); }
void fn08() { printf("%s()\n", __FUNCTION__); }
void fn09() { printf("%s()\n", __FUNCTION__); }
void fn10() { printf("%s()\n", __FUNCTION__); }

void fn11() { printf("%s()\n", __FUNCTION__); }
void fn12() { printf("%s()\n", __FUNCTION__); }
void fn13() { printf("%s()\n", __FUNCTION__); }
void fn14() { printf("%s()\n", __FUNCTION__); }
void fn15() { printf("%s()\n", __FUNCTION__); }
void fn16() { printf("%s()\n", __FUNCTION__); }
void fn17() { printf("%s()\n", __FUNCTION__); }
void fn18() { printf("%s()\n", __FUNCTION__); }
void fn19() { printf("%s()\n", __FUNCTION__); }
void fn20() { printf("%s()\n", __FUNCTION__); }

void fn21() { printf("%s()\n", __FUNCTION__); }
void fn22() { printf("%s()\n", __FUNCTION__); }
void fn23() { printf("%s()\n", __FUNCTION__); }
void fn24() { printf("%s()\n", __FUNCTION__); }
void fn25() { printf("%s()\n", __FUNCTION__); }
void fn26() { printf("%s()\n", __FUNCTION__); }
void fn27() { printf("%s()\n", __FUNCTION__); }
void fn28() { printf("%s()\n", __FUNCTION__); }
void fn29() { printf("%s()\n", __FUNCTION__); }
void fn30() { printf("%s()\n", __FUNCTION__); }

void fn31() { printf("%s()\n", __FUNCTION__); }
void fn32() { printf("%s()\n", __FUNCTION__); }
void fn33() { printf("%s()\n", __FUNCTION__); }
void fn34() { printf("%s()\n", __FUNCTION__); }
void fn35() { printf("%s()\n", __FUNCTION__); }
void fn36() { printf("%s()\n", __FUNCTION__); }
void fn37() { printf("%s()\n", __FUNCTION__); }
void fn38() { printf("%s()\n", __FUNCTION__); }
void fn39() { printf("%s()\n", __FUNCTION__); }
void fn40() { printf("%s()\n", __FUNCTION__); }

void call_me_at_exit() { printf("global_counter = %d\n", ++global_counter); }

int main(int argc, char *argv[]) {
  // CHECK: In main()
  printf("In main()\n");

  // CHECK: fn40()
  // CHECK: fn39()
  // CHECK: fn38()
  // CHECK: fn37()
  // CHECK: fn36()
  // CHECK: fn35()
  // CHECK: fn34()
  // CHECK: fn33()
  // CHECK: fn32()
  // CHECK: fn31()
  
  // CHECK: fn30()
  // CHECK: fn29()
  // CHECK: fn28()
  // CHECK: fn27()
  // CHECK: fn26()
  // CHECK: fn25()
  // CHECK: fn24()
  // CHECK: fn23()
  // CHECK: fn22()
  // CHECK: fn21()
  
  // CHECK: fn20()
  // CHECK: fn19()
  // CHECK: fn18()
  // CHECK: fn17()
  // CHECK: fn16()
  // CHECK: fn15()
  // CHECK: fn14()
  // CHECK: fn13()
  // CHECK: fn12()
  // CHECK: fn11()
  
  // CHECK: fn10()
  // CHECK: fn09()
  // CHECK: fn08()
  // CHECK: fn07()
  // CHECK: fn06()
  // CHECK: fn05()
  // CHECK: fn04()
  // CHECK: fn03()
  // CHECK: fn02()
  // CHECK: fn01()

  atexit(fn01);
  atexit(fn02);
  atexit(fn03);
  atexit(fn04);
  atexit(fn05);
  atexit(fn06);
  atexit(fn07);
  atexit(fn08);
  atexit(fn09);
  atexit(fn10);

  atexit(fn11);
  atexit(fn12);
  atexit(fn13);
  atexit(fn14);
  atexit(fn15);
  atexit(fn16);
  atexit(fn17);
  atexit(fn18);
  atexit(fn19);
  atexit(fn20);

  atexit(fn21);
  atexit(fn22);
  atexit(fn23);
  atexit(fn24);
  atexit(fn25);
  atexit(fn26);
  atexit(fn27);
  atexit(fn28);
  atexit(fn29);
  atexit(fn30);

  atexit(fn31);
  atexit(fn32);
  atexit(fn33);
  atexit(fn34);
  atexit(fn35);
  atexit(fn36);
  atexit(fn37);
  atexit(fn38);
  atexit(fn39);
  atexit(fn40);

  return 0;
}
