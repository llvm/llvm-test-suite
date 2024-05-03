#include "Delendum.h"

// INPUT-1: 5, 5
// CHECK-1: 1

// INPUT-2: 5, 4
// CHECK-2: 1

// INPUT-3: 5, 3
// CHECK-3: 1

// INPUT-4: 0, 0
// CHECK-4: 1

// INPUT-5: 4294967295, 4294967295
// CHECK-5: 1

// INPUT-6: 4294967295, 4294967294
// CHECK-6: 1

// INPUT-7: 4294967295, 4294967293
// CHECK-7: 1

int main() {
  unsigned v1 = read_unsigned();
  unsigned v2 = read_unsigned();
  unsigned result = v1 >= v2;
  write_unsigned(result);
  return 0;
}
