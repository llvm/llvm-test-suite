#include <stdio.h>
#include <stdlib.h>

int checkInt(int *I, int Align) {
  *I = 20;
  if ((((size_t)I) & (Align - 1)) != 0) {
    printf("\nUnalign address (%d): %p!\n", Align, I);
    abort();
  }
  return *I;
}

#ifndef ALIGNMENT
#define ALIGNMENT 64
#endif

typedef int aligned __attribute__((aligned(ALIGNMENT)));

void bar(char *p, int size) { __builtin_strncpy(p, "good", size); }

class Base {};

struct A : virtual public Base {
  A() {}
};

struct B {};

void foo(int size) {
  aligned Var;
  char *Ptr = (char *)__builtin_alloca(size + 1);
  aligned I;

  // clobber 32-bit base pointer.
  asm volatile("nop" ::"S"(405) :);
  // clobber 64-bit base pointer.
  asm volatile("nop" ::"b"(405) :);
  bar(Ptr, size);
  if (__builtin_strncmp(Ptr, "good", size) != 0) {
    Ptr[size] = '\0';
    printf("Failed: %s != good\n", Ptr);
    abort();
  }

  if (checkInt(&I, __alignof__(I)) != I)
    abort();

  // access argument and local variable.
  asm volatile("movl %0, %1" ::"r"(size), "m"(Var) :);
  throw A();
}

int main() {
  try {
    foo(5);
  } catch (A &a) {
  }
  return 0;
}
