// Make sure that we can compile CUDA files that include <future> and use
// std::shared_future.
//
// At one point in time this didn't work because clang defined different values
// for __GCC_ATOMIC_INT_LOCK_FREE on host and device.  This caused libstdc++
// not to define std::shared_future when compiling for device, resulting in
// compile errors (even though we only use std::shared_future in host code).

#if __cplusplus >= 201103L
#include <future>

void foo() {
  std::shared_future<int> x;
}
#else
#warning Skipping test because not compiled in C++11 mode.
#endif

int main() {
  return 0;
}
