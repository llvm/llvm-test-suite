//===--- template3.cpp --- Test Cases for Bit Accurate Types -------------------------------===//
//
// This is a test for partial specialization.
//
//===------------------------------------------------------------------------===//

#include <iostream>
using namespace std;

typedef int __attribute__ ((bitwidth(17))) int17;
typedef int __attribute__ ((bitwidth(15))) int15;

template<class T, class U, int I> struct X
  { void f() { cout << "Primary template" << endl; } };

template<class T, int I> struct X<T, T*, I>
  { void f() { cout << "Partial specialization 1" << endl;
  } };

template<class T, class U, int I> struct X<T*, U, I>
  { void f() { cout << "Partial specialization 2" << endl;
  } };

template<class T> struct X<int, T*, 10>
  { void f() { cout << "Partial specialization 3" << endl;
  } };

template<class T, class U, int I> struct X<T, U*, I>
  { void f() { cout << "Partial specialization 4" << endl;
  } };

int main() {
   X<int17, int17, 10> a;
   X<int15, int15*, 5> b;
   X<int17, int15*, 5> bb;

   X<int17*, float, 10> c;
   X<int15, char*, 10> d;
   X<float, int15*, 10> e;
//   X<int, int*, 10> f;
   a.f(); b.f(); bb.f(); c.f(); d.f(); e.f();

   return 0;
}
