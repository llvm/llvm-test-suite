// RUN-FORMAT: %run %s

// INPUT-1: 1234, 1234
// CHECK-1: 2468

// INPUT-2: 34, 34
// CHECK-2: 68

// INPUT-3: 1, 1
// CHECK-3: 2

#include "Delendum.h"

int main() {
  unsigned x = read_unsigned();
  unsigned y = read_unsigned();
  write_unsigned(x+y);
  return 0;
}


