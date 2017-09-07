// Check that operator new and operator delete work.

#include <assert.h>
#include <new>
#include <stdio.h>

__device__ void global_new() {
  void* x = ::operator new(42);
  assert(x != NULL);
  ::operator delete(x);

  x = ::operator new(42, std::nothrow);
  assert(x != NULL);
  ::operator delete(x, std::nothrow);

  x = ::operator new[](42);
  assert(x != NULL);
  ::operator delete[](x);

  x = ::operator new[](42, std::nothrow);
  assert(x != NULL);
  ::operator delete[](x, std::nothrow);
}

__device__ void sized_delete() {
#if __cplusplus>= 201402L
  void* x = ::operator new(42);
  assert(x != NULL);
  ::operator delete(x, 42);

  x = ::operator new[](42);
  assert(x != NULL);
  ::operator delete[](x, 42);
#endif
}

__device__ void int_new() {
  int* x = new int();
  assert(*x == 0);
  delete x;
}

struct Foo {
  __device__ Foo() : x(42) {}
  int x;
};
__device__ void class_new() {
  Foo* foo = new Foo();
  assert(foo->x == 42);
  delete foo;
}

__global__ void kernel() {
  global_new();
  sized_delete();
  int_new();
  class_new();
}

int main() {
  kernel<<<32, 32>>>();
  cudaError_t err = cudaDeviceSynchronize();
  if (err != cudaSuccess) {
    printf("CUDA error %d\n", (int)err);
    return 1;
  }
  printf("Success!\n");
  return 0;
}
