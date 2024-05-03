#include "Delendum.h"

// INPUT-1: 5, 3
// CHECK-1: 8

__attribute__((noinline))
unsigned add(unsigned a, unsigned b) {
    return a + b;
}

int main() {
    // Declare a function pointer and initialize it to point to the add function
    unsigned (*funcPtr)(unsigned, unsigned) = add;
    // Now, call the add function indirectly using the function pointer
    unsigned a = read_unsigned();
    unsigned b = read_unsigned();
    unsigned result = funcPtr(a, b);
    write_unsigned(result);
    return 0;
}
