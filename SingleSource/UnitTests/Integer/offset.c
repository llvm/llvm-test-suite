//===--- offset.c --- Test Cases for Bit Accurate Types -----------------===//
//
// This file was developed by Guoling han and donated to the LLVM research
// group and is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//===-------------------------------------------------------------------===//
//
// This is a test for data size calculation with non-regular integral type.
//
//===--------------------------------------------------------------------===//

#include <stdio.h>

typedef int __attribute__ ((bitwidth(33))) int33;

struct s {
  int33 field[0];
};

#define OFFS \
        (((char *) &((struct s *) 0)->field[1]) - (char *) 0)

int foo[OFFS];

int main()
{
    printf("%d\n", OFFS);
    return 0;
}
