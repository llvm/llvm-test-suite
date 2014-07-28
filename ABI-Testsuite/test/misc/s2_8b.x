// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: cxx_compiler -c %s cxx_rtti -o %t1.o
// RUN: c_compiler -c %s -o %t2.o
// RUN: linker -o %t%exeext %t1.o %t2.o 
// RUN: runtool %t%exeext | grep "PASSED"

typedef long long gvtype;
#define GVSET 1

#ifdef __cplusplus
extern "C" {
   int printf(const char *, ...);
   gvtype get_foo_gv();
   void set_foo_gv(gvtype);
   gvtype get_addx_gv();
   void set_addx_gv(gvtype);
}

inline int foo(int x, int y)
{
  static int r = y;
  return x +r;
}

int bar(int x)
{
  return foo(x, x);
}

template <class T> T addx(T x, T y) {
  static T p = y;
  return x + p;
}

int bart(int x)
{
  return addx(x, x);
}

int nerr=0, ntests=0, verbose=0;

#define check(a, b) {\
                 long long v=a; \
                 ntests++; \
                 if (v!=b) {\
                   nerr++;\
                   printf("ERROR @%d %lld != %lld\n", __LINE__, v, (long long)b); \
                 } else if (verbose) { \
                   printf("OK @%d %lld\n", __LINE__, v); \
                 }\
                }

int main()
{
    verbose = 1;
    // initial values are 0
    check(get_foo_gv(), 0);
    check(get_addx_gv(), 0);

    // first call should just return double
    check(bar(3), 6);
    check(bart(3), 6);

    // now guard vars are 1
    check(get_foo_gv(), GVSET);
    check(get_addx_gv(), GVSET);

    // this call should just add 3
    check(bar(4), 7);
    check(bart(4), 7);
 
    // now reset them
    set_foo_gv(0);
    set_addx_gv(0);

    // should double agaain
    check(bar(5), 10);
    check(bart(5), 10);

    // just add 5 again
    check(bar(6), 11);
    check(bart(6), 11);
    printf("%s. %d tests\n%c", nerr ? "FAILED":"PASSED", ntests, 0x1a);

}

#else

extern gvtype _ZGVZ3fooiiE1r, _ZGVZ4addxIiET_S0_S0_E1p;
   gvtype get_foo_gv() { return _ZGVZ3fooiiE1r ; }
   void set_foo_gv(gvtype v) { _ZGVZ3fooiiE1r = 0; }
   gvtype get_addx_gv() { return _ZGVZ4addxIiET_S0_S0_E1p;}
   void set_addx_gv(gvtype v) {_ZGVZ4addxIiET_S0_S0_E1p = v;}
#endif
