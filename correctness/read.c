// RUN-FORMAT: %run %s

// INPUT-1: 1234
// CHECK-1: 1234

// INPUT-2: 4294967295
// CHECK-2: 4294967295

// INPUT-3: 0
// CHECK-3: 0

#include "Delendum.h"

int main() {
  unsigned x = read_unsigned();
  write_unsigned(x);
  return 0;
}


