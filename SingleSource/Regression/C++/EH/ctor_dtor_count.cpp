#include <stdio.h>

static int c;

struct A {
  A() { ++c; }
  A(const A&) { ++c; }
  ~A() { --c; }
};

struct B {
  A a;
  B() { A a; throw 1; }
};

int simple() {
  try {
    B b;
  } catch (...) {}
  if (!c) printf("Deriv ok!\n");
  try {
    B* b = new B();
  } catch (...) {}
  if (!c) printf("Deriv pointer ok!\n");
  try {
    throw A();
  } catch (...) {}
  if (!c) printf("Base ok!\n");
  try {
    throw new A();
  } catch (A *a) {delete a;}
  if (!c) printf("Base pointer ok!\n");
  try {
    A a;
    throw A(a);
  } catch (A &a) {}
  if (!c) printf("Copy ok!\n");
  try {
    A a;
    throw new A(a);
  } catch (A *a) {delete a;}
  if (!c) printf("Copy pointer ok!\n");
  return c;
}

static int k;

struct C : public A {
  C() : A() { ++k; }
};

struct T {
  T(int a) {
    if (a < 0)
      throw a;
  }
};

struct M {
  A a;
  T t;
  C c;
  M(int n) : t(n) {}
};

int member() {
  try {
    M(10);
  } catch (...) {
    printf("ooops\n");
    return 1;
  }
  if (!c && k == 1) printf("Member positive ok!\n");
  try {
    M(0);
  } catch (...) {
    printf("ooops\n");
    return 1;
  }
  if (!c && k == 2) printf("Member zero ok!\n");
  try {
    M(-10);
    printf("ooops\n");
    return 1;
  } catch (...) {
    printf("caught negative T\n");
  }
  if (!c && k == 2) printf("Member negative ok!\n");
  return c;
}

int main() {
  return simple() + member();
}
