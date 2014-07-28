// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: cxx_compiler cxx_rtti -c %s -I "common" -o %t2.o
// RUN: linker -o %t2%exeext  %t1.o %t2.o
// RUN: runtool %t2%exeext | checker "TEST PASSED"
#include "testsuite.h"
#ifdef __cplusplus

struct  sfld  {
  char c;
  short s;
};
//SIG(1 sfld) C1{ Fc Fs}



static void Test_sfld()
{
  {
    init_simple_test("sfld");
    sfld lv;
    check2(sizeof(lv), 4, "sizeof(sfld)");
    check2(__alignof__(lv), 2, "__alignof__(sfld)");
    check_field_offset(lv, c, 0, "sfld.c");
    check_field_offset(lv, s, 2, "sfld.s");
  }
}
static Arrange_To_Call_Me vsfld(Test_sfld, "sfld", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  ifld  {
  char c;
  int s;
};
//SIG(1 ifld) C1{ Fc Fi}



static void Test_ifld()
{
  {
    init_simple_test("ifld");
    ifld lv;
    check2(sizeof(lv), 8, "sizeof(ifld)");
    check2(__alignof__(lv), 4, "__alignof__(ifld)");
    check_field_offset(lv, c, 0, "ifld.c");
    check_field_offset(lv, s, 4, "ifld.s");
  }
}
static Arrange_To_Call_Me vifld(Test_ifld, "ifld", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  lfld  {
  char c;
  long s;
};
//SIG(1 lfld) C1{ Fc Fl}



static void Test_lfld()
{
  {
    init_simple_test("lfld");
    lfld lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(lfld)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(lfld)");
    check_field_offset(lv, c, 0, "lfld.c");
    check_field_offset(lv, s, ABISELECT(8,4), "lfld.s");
  }
}
static Arrange_To_Call_Me vlfld(Test_lfld, "lfld", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  llfld  {
  char c;
  __tsi64 s;
};
//SIG(1 llfld) C1{ Fc FL}



static void Test_llfld()
{
  {
    init_simple_test("llfld");
    llfld lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(llfld)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(llfld)");
    check_field_offset(lv, c, 0, "llfld.c");
    check_field_offset(lv, s, ABISELECT(8,4), "llfld.s");
  }
}
static Arrange_To_Call_Me vllfld(Test_llfld, "llfld", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  ffld  {
  char c;
  float s;
};
//SIG(1 ffld) C1{ Fc Fi}



static void Test_ffld()
{
  {
    init_simple_test("ffld");
    ffld lv;
    check2(sizeof(lv), 8, "sizeof(ffld)");
    check2(__alignof__(lv), 4, "__alignof__(ffld)");
    check_field_offset(lv, c, 0, "ffld.c");
    check_field_offset(lv, s, 4, "ffld.s");
  }
}
static Arrange_To_Call_Me vffld(Test_ffld, "ffld", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  dfld  {
  char c;
  double s;
};
//SIG(1 dfld) C1{ Fc FL}



static void Test_dfld()
{
  {
    init_simple_test("dfld");
    dfld lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(dfld)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(dfld)");
    check_field_offset(lv, c, 0, "dfld.c");
    check_field_offset(lv, s, ABISELECT(8,4), "dfld.s");
  }
}
static Arrange_To_Call_Me vdfld(Test_dfld, "dfld", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  ldfld  {
  char c;
  long double s;
};
//SIG(1 ldfld) C1{ Fc FD}



static void Test_ldfld()
{
  {
    init_simple_test("ldfld");
    ldfld lv;
    check2(sizeof(lv), ABISELECT(32,16), "sizeof(ldfld)");
    check2(__alignof__(lv), ABISELECT(16,4), "__alignof__(ldfld)");
    check_field_offset(lv, c, 0, "ldfld.c");
    check_field_offset(lv, s, ABISELECT(16,4), "ldfld.s");
  }
}
static Arrange_To_Call_Me vldfld(Test_ldfld, "ldfld", ABISELECT(32,16));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  zb  {
  int  :0;
};
//SIG(1 zb) C1{ Fi:0}



static void Test_zb()
{
  {
    init_simple_test("zb");
    static zb lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(zb)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(zb)");
  }
}
static Arrange_To_Call_Me vzb(Test_zb, "zb", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

