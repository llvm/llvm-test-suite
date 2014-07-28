// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: cxx_compiler cxx_rtti -c %s -I "common" -o %t2.o
// RUN: linker -o %t2%exeext  %t1.o %t2.o
// RUN: runtool %t2%exeext | checker "TEST PASSED"
#include "testsuite.h"
#ifdef __cplusplus

struct  empty  {
};
//SIG(-1 empty) C1{}



static void Test_empty()
{
  {
    init_simple_test("empty");
    empty lv;
    check2(sizeof(lv), 1, "sizeof(empty)");
    check2(__alignof__(lv), 1, "__alignof__(empty)");
  }
}
static Arrange_To_Call_Me vempty(Test_empty, "empty", 1);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_B_Sf  {
  bool v1;
  bool v2;
  ::empty v3;
};
//SIG(1 B_B_Sf) C1{ Fc[2] FC2{}}



static void Test_B_B_Sf()
{
  {
    init_simple_test("B_B_Sf");
    B_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_B_Sf)");
    check_field_offset(lv, v1, 0, "B_B_Sf.v1");
    check_field_offset(lv, v2, 1, "B_B_Sf.v2");
    check_field_offset(lv, v3, 2, "B_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_B_Sf(Test_B_B_Sf, "B_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15i_Sf  {
  bool v1;
  unsigned int v2:15;
  ::empty v3;
};
//SIG(1 B_BFu15i_Sf) C1{ Fc Fi:15 FC2{}}



static void Test_B_BFu15i_Sf()
{
  {
    init_simple_test("B_BFu15i_Sf");
    static B_BFu15i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu15i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu15i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu15i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15i_Sf");
    check_field_offset(lv, v3, 3, "B_BFu15i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu15i_Sf(Test_B_BFu15i_Sf, "B_BFu15i_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15ll_Sf  {
  bool v1;
  __tsu64 v2:15;
  ::empty v3;
};
//SIG(1 B_BFu15ll_Sf) C1{ Fc FL:15 FC2{}}



static void Test_B_BFu15ll_Sf()
{
  {
    init_simple_test("B_BFu15ll_Sf");
    static B_BFu15ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu15ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu15ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu15ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15ll_Sf");
    check_field_offset(lv, v3, 3, "B_BFu15ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu15ll_Sf(Test_B_BFu15ll_Sf, "B_BFu15ll_Sf", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15s_Sf  {
  bool v1;
  unsigned short v2:15;
  ::empty v3;
};
//SIG(1 B_BFu15s_Sf) C1{ Fc Fs:15 FC2{}}



static void Test_B_BFu15s_Sf()
{
  {
    init_simple_test("B_BFu15s_Sf");
    static B_BFu15s_Sf lv;
    check2(sizeof(lv), 6, "sizeof(B_BFu15s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu15s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu15s_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "B_BFu15s_Sf");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "B_BFu15s_Sf");
    check_field_offset(lv, v3, 4, "B_BFu15s_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu15s_Sf(Test_B_BFu15s_Sf, "B_BFu15s_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16i_Sf  {
  bool v1;
  unsigned int v2:16;
  ::empty v3;
};
//SIG(1 B_BFu16i_Sf) C1{ Fc Fi:16 FC2{}}



static void Test_B_BFu16i_Sf()
{
  {
    init_simple_test("B_BFu16i_Sf");
    static B_BFu16i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu16i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu16i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu16i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16i_Sf");
    check_field_offset(lv, v3, 3, "B_BFu16i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu16i_Sf(Test_B_BFu16i_Sf, "B_BFu16i_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16ll_Sf  {
  bool v1;
  __tsu64 v2:16;
  ::empty v3;
};
//SIG(1 B_BFu16ll_Sf) C1{ Fc FL:16 FC2{}}



static void Test_B_BFu16ll_Sf()
{
  {
    init_simple_test("B_BFu16ll_Sf");
    static B_BFu16ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu16ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu16ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu16ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16ll_Sf");
    check_field_offset(lv, v3, 3, "B_BFu16ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu16ll_Sf(Test_B_BFu16ll_Sf, "B_BFu16ll_Sf", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16s_Sf  {
  bool v1;
  unsigned short v2:16;
  ::empty v3;
};
//SIG(1 B_BFu16s_Sf) C1{ Fc Fs:16 FC2{}}



static void Test_B_BFu16s_Sf()
{
  {
    init_simple_test("B_BFu16s_Sf");
    static B_BFu16s_Sf lv;
    check2(sizeof(lv), 6, "sizeof(B_BFu16s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu16s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu16s_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "B_BFu16s_Sf");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "B_BFu16s_Sf");
    check_field_offset(lv, v3, 4, "B_BFu16s_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu16s_Sf(Test_B_BFu16s_Sf, "B_BFu16s_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu17i_Sf  {
  bool v1;
  unsigned int v2:17;
  ::empty v3;
};
//SIG(1 B_BFu17i_Sf) C1{ Fc Fi:17 FC2{}}



static void Test_B_BFu17i_Sf()
{
  {
    init_simple_test("B_BFu17i_Sf");
    static B_BFu17i_Sf lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu17i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu17i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu17i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu17i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu17i_Sf");
    check_field_offset(lv, v3, 4, "B_BFu17i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu17i_Sf(Test_B_BFu17i_Sf, "B_BFu17i_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu17ll_Sf  {
  bool v1;
  __tsu64 v2:17;
  ::empty v3;
};
//SIG(1 B_BFu17ll_Sf) C1{ Fc FL:17 FC2{}}



static void Test_B_BFu17ll_Sf()
{
  {
    init_simple_test("B_BFu17ll_Sf");
    static B_BFu17ll_Sf lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu17ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu17ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu17ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu17ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu17ll_Sf");
    check_field_offset(lv, v3, 4, "B_BFu17ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu17ll_Sf(Test_B_BFu17ll_Sf, "B_BFu17ll_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1c_Sf  {
  bool v1;
  unsigned char v2:1;
  ::empty v3;
};
//SIG(1 B_BFu1c_Sf) C1{ Fc Fc:1 FC2{}}



static void Test_B_BFu1c_Sf()
{
  {
    init_simple_test("B_BFu1c_Sf");
    static B_BFu1c_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu1c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu1c_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu1c_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1c_Sf");
    check_field_offset(lv, v3, 2, "B_BFu1c_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu1c_Sf(Test_B_BFu1c_Sf, "B_BFu1c_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1i_Sf  {
  bool v1;
  unsigned int v2:1;
  ::empty v3;
};
//SIG(1 B_BFu1i_Sf) C1{ Fc Fi:1 FC2{}}



static void Test_B_BFu1i_Sf()
{
  {
    init_simple_test("B_BFu1i_Sf");
    static B_BFu1i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu1i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu1i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu1i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1i_Sf");
    check_field_offset(lv, v3, 2, "B_BFu1i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu1i_Sf(Test_B_BFu1i_Sf, "B_BFu1i_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1ll_Sf  {
  bool v1;
  __tsu64 v2:1;
  ::empty v3;
};
//SIG(1 B_BFu1ll_Sf) C1{ Fc FL:1 FC2{}}



static void Test_B_BFu1ll_Sf()
{
  {
    init_simple_test("B_BFu1ll_Sf");
    static B_BFu1ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu1ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu1ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu1ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1ll_Sf");
    check_field_offset(lv, v3, 2, "B_BFu1ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu1ll_Sf(Test_B_BFu1ll_Sf, "B_BFu1ll_Sf", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1s_Sf  {
  bool v1;
  unsigned short v2:1;
  ::empty v3;
};
//SIG(1 B_BFu1s_Sf) C1{ Fc Fs:1 FC2{}}



static void Test_B_BFu1s_Sf()
{
  {
    init_simple_test("B_BFu1s_Sf");
    static B_BFu1s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu1s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu1s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu1s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1s_Sf");
    check_field_offset(lv, v3, 2, "B_BFu1s_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu1s_Sf(Test_B_BFu1s_Sf, "B_BFu1s_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu31i_Sf  {
  bool v1;
  unsigned int v2:31;
  ::empty v3;
};
//SIG(1 B_BFu31i_Sf) C1{ Fc Fi:31 FC2{}}



static void Test_B_BFu31i_Sf()
{
  {
    init_simple_test("B_BFu31i_Sf");
    static B_BFu31i_Sf lv;
    check2(sizeof(lv), 12, "sizeof(B_BFu31i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu31i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu31i_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "B_BFu31i_Sf");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "B_BFu31i_Sf");
    check_field_offset(lv, v3, 8, "B_BFu31i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu31i_Sf(Test_B_BFu31i_Sf, "B_BFu31i_Sf", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu31ll_Sf  {
  bool v1;
  __tsu64 v2:31;
  ::empty v3;
};
//SIG(1 B_BFu31ll_Sf) C1{ Fc FL:31 FC2{}}



static void Test_B_BFu31ll_Sf()
{
  {
    init_simple_test("B_BFu31ll_Sf");
    static B_BFu31ll_Sf lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu31ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu31ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu31ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "B_BFu31ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "B_BFu31ll_Sf");
    check_field_offset(lv, v3, 5, "B_BFu31ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu31ll_Sf(Test_B_BFu31ll_Sf, "B_BFu31ll_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu32i_Sf  {
  bool v1;
  unsigned int v2:32;
  ::empty v3;
};
//SIG(1 B_BFu32i_Sf) C1{ Fc Fi:32 FC2{}}



static void Test_B_BFu32i_Sf()
{
  {
    init_simple_test("B_BFu32i_Sf");
    static B_BFu32i_Sf lv;
    check2(sizeof(lv), 12, "sizeof(B_BFu32i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu32i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu32i_Sf.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "B_BFu32i_Sf");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "B_BFu32i_Sf");
    check_field_offset(lv, v3, 8, "B_BFu32i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu32i_Sf(Test_B_BFu32i_Sf, "B_BFu32i_Sf", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu32ll_Sf  {
  bool v1;
  __tsu64 v2:32;
  ::empty v3;
};
//SIG(1 B_BFu32ll_Sf) C1{ Fc FL:32 FC2{}}



static void Test_B_BFu32ll_Sf()
{
  {
    init_simple_test("B_BFu32ll_Sf");
    static B_BFu32ll_Sf lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu32ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu32ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu32ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "B_BFu32ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "B_BFu32ll_Sf");
    check_field_offset(lv, v3, 5, "B_BFu32ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu32ll_Sf(Test_B_BFu32ll_Sf, "B_BFu32ll_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu33_Sf  {
  bool v1;
  __tsu64 v2:33;
  ::empty v3;
};
//SIG(1 B_BFu33_Sf) C1{ Fc FL:33 FC2{}}



static void Test_B_BFu33_Sf()
{
  {
    init_simple_test("B_BFu33_Sf");
    static B_BFu33_Sf lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu33_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu33_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu33_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "B_BFu33_Sf");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "B_BFu33_Sf");
    check_field_offset(lv, v3, 6, "B_BFu33_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu33_Sf(Test_B_BFu33_Sf, "B_BFu33_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7c_Sf  {
  bool v1;
  unsigned char v2:7;
  ::empty v3;
};
//SIG(1 B_BFu7c_Sf) C1{ Fc Fc:7 FC2{}}



static void Test_B_BFu7c_Sf()
{
  {
    init_simple_test("B_BFu7c_Sf");
    static B_BFu7c_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu7c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu7c_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu7c_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7c_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7c_Sf");
    check_field_offset(lv, v3, 2, "B_BFu7c_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu7c_Sf(Test_B_BFu7c_Sf, "B_BFu7c_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7i_Sf  {
  bool v1;
  unsigned int v2:7;
  ::empty v3;
};
//SIG(1 B_BFu7i_Sf) C1{ Fc Fi:7 FC2{}}



static void Test_B_BFu7i_Sf()
{
  {
    init_simple_test("B_BFu7i_Sf");
    static B_BFu7i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu7i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu7i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu7i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7i_Sf");
    check_field_offset(lv, v3, 2, "B_BFu7i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu7i_Sf(Test_B_BFu7i_Sf, "B_BFu7i_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7ll_Sf  {
  bool v1;
  __tsu64 v2:7;
  ::empty v3;
};
//SIG(1 B_BFu7ll_Sf) C1{ Fc FL:7 FC2{}}



static void Test_B_BFu7ll_Sf()
{
  {
    init_simple_test("B_BFu7ll_Sf");
    static B_BFu7ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu7ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu7ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu7ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7ll_Sf");
    check_field_offset(lv, v3, 2, "B_BFu7ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu7ll_Sf(Test_B_BFu7ll_Sf, "B_BFu7ll_Sf", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7s_Sf  {
  bool v1;
  unsigned short v2:7;
  ::empty v3;
};
//SIG(1 B_BFu7s_Sf) C1{ Fc Fs:7 FC2{}}



static void Test_B_BFu7s_Sf()
{
  {
    init_simple_test("B_BFu7s_Sf");
    static B_BFu7s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu7s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu7s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu7s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7s_Sf");
    check_field_offset(lv, v3, 2, "B_BFu7s_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu7s_Sf(Test_B_BFu7s_Sf, "B_BFu7s_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8c_Sf  {
  bool v1;
  unsigned char v2:8;
  ::empty v3;
};
//SIG(1 B_BFu8c_Sf) C1{ Fc Fc:8 FC2{}}



static void Test_B_BFu8c_Sf()
{
  {
    init_simple_test("B_BFu8c_Sf");
    static B_BFu8c_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_BFu8c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu8c_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu8c_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8c_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8c_Sf");
    check_field_offset(lv, v3, 2, "B_BFu8c_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu8c_Sf(Test_B_BFu8c_Sf, "B_BFu8c_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8i_Sf  {
  bool v1;
  unsigned int v2:8;
  ::empty v3;
};
//SIG(1 B_BFu8i_Sf) C1{ Fc Fi:8 FC2{}}



static void Test_B_BFu8i_Sf()
{
  {
    init_simple_test("B_BFu8i_Sf");
    static B_BFu8i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu8i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu8i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu8i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8i_Sf");
    check_field_offset(lv, v3, 2, "B_BFu8i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu8i_Sf(Test_B_BFu8i_Sf, "B_BFu8i_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8ll_Sf  {
  bool v1;
  __tsu64 v2:8;
  ::empty v3;
};
//SIG(1 B_BFu8ll_Sf) C1{ Fc FL:8 FC2{}}



static void Test_B_BFu8ll_Sf()
{
  {
    init_simple_test("B_BFu8ll_Sf");
    static B_BFu8ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu8ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu8ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu8ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8ll_Sf");
    check_field_offset(lv, v3, 2, "B_BFu8ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu8ll_Sf(Test_B_BFu8ll_Sf, "B_BFu8ll_Sf", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8s_Sf  {
  bool v1;
  unsigned short v2:8;
  ::empty v3;
};
//SIG(1 B_BFu8s_Sf) C1{ Fc Fs:8 FC2{}}



static void Test_B_BFu8s_Sf()
{
  {
    init_simple_test("B_BFu8s_Sf");
    static B_BFu8s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu8s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu8s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu8s_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8s_Sf");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8s_Sf");
    check_field_offset(lv, v3, 2, "B_BFu8s_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu8s_Sf(Test_B_BFu8s_Sf, "B_BFu8s_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9i_Sf  {
  bool v1;
  unsigned int v2:9;
  ::empty v3;
};
//SIG(1 B_BFu9i_Sf) C1{ Fc Fi:9 FC2{}}



static void Test_B_BFu9i_Sf()
{
  {
    init_simple_test("B_BFu9i_Sf");
    static B_BFu9i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu9i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu9i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu9i_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9i_Sf");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9i_Sf");
    check_field_offset(lv, v3, 3, "B_BFu9i_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu9i_Sf(Test_B_BFu9i_Sf, "B_BFu9i_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9ll_Sf  {
  bool v1;
  __tsu64 v2:9;
  ::empty v3;
};
//SIG(1 B_BFu9ll_Sf) C1{ Fc FL:9 FC2{}}



static void Test_B_BFu9ll_Sf()
{
  {
    init_simple_test("B_BFu9ll_Sf");
    static B_BFu9ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu9ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu9ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu9ll_Sf.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9ll_Sf");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9ll_Sf");
    check_field_offset(lv, v3, 3, "B_BFu9ll_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu9ll_Sf(Test_B_BFu9ll_Sf, "B_BFu9ll_Sf", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9s_Sf  {
  bool v1;
  unsigned short v2:9;
  ::empty v3;
};
//SIG(1 B_BFu9s_Sf) C1{ Fc Fs:9 FC2{}}



static void Test_B_BFu9s_Sf()
{
  {
    init_simple_test("B_BFu9s_Sf");
    static B_BFu9s_Sf lv;
    check2(sizeof(lv), 6, "sizeof(B_BFu9s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu9s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu9s_Sf.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "B_BFu9s_Sf");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "B_BFu9s_Sf");
    check_field_offset(lv, v3, 4, "B_BFu9s_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_BFu9s_Sf(Test_B_BFu9s_Sf, "B_BFu9s_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_C_Sf  {
  bool v1;
  char v2;
  ::empty v3;
};
//SIG(1 B_C_Sf) C1{ Fc[2] FC2{}}



static void Test_B_C_Sf()
{
  {
    init_simple_test("B_C_Sf");
    B_C_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_C_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_C_Sf)");
    check_field_offset(lv, v1, 0, "B_C_Sf.v1");
    check_field_offset(lv, v2, 1, "B_C_Sf.v2");
    check_field_offset(lv, v3, 2, "B_C_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_C_Sf(Test_B_C_Sf, "B_C_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_D_Sf  {
  bool v1;
  double v2;
  ::empty v3;
};
//SIG(1 B_D_Sf) C1{ Fc FL FC2{}}



static void Test_B_D_Sf()
{
  {
    init_simple_test("B_D_Sf");
    B_D_Sf lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(B_D_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_D_Sf)");
    check_field_offset(lv, v1, 0, "B_D_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_D_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "B_D_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_D_Sf(Test_B_D_Sf, "B_D_Sf", ABISELECT(24,16));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_F_Sf  {
  bool v1;
  float v2;
  ::empty v3;
};
//SIG(1 B_F_Sf) C1{ Fc Fi FC2{}}



static void Test_B_F_Sf()
{
  {
    init_simple_test("B_F_Sf");
    B_F_Sf lv;
    check2(sizeof(lv), 12, "sizeof(B_F_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(B_F_Sf)");
    check_field_offset(lv, v1, 0, "B_F_Sf.v1");
    check_field_offset(lv, v2, 4, "B_F_Sf.v2");
    check_field_offset(lv, v3, 8, "B_F_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_F_Sf(Test_B_F_Sf, "B_F_Sf", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_I_Sf  {
  bool v1;
  int v2;
  ::empty v3;
};
//SIG(1 B_I_Sf) C1{ Fc Fi FC2{}}



static void Test_B_I_Sf()
{
  {
    init_simple_test("B_I_Sf");
    B_I_Sf lv;
    check2(sizeof(lv), 12, "sizeof(B_I_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(B_I_Sf)");
    check_field_offset(lv, v1, 0, "B_I_Sf.v1");
    check_field_offset(lv, v2, 4, "B_I_Sf.v2");
    check_field_offset(lv, v3, 8, "B_I_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_I_Sf(Test_B_I_Sf, "B_I_Sf", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ip_Sf  {
  bool v1;
  int *v2;
  ::empty v3;
};
//SIG(1 B_Ip_Sf) C1{ Fc Fp FC2{}}



static void Test_B_Ip_Sf()
{
  {
    init_simple_test("B_Ip_Sf");
    B_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(B_Ip_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Ip_Sf)");
    check_field_offset(lv, v1, 0, "B_Ip_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Ip_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "B_Ip_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Ip_Sf(Test_B_Ip_Sf, "B_Ip_Sf", ABISELECT(24,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_L_Sf  {
  bool v1;
  __tsi64 v2;
  ::empty v3;
};
//SIG(1 B_L_Sf) C1{ Fc FL FC2{}}



static void Test_B_L_Sf()
{
  {
    init_simple_test("B_L_Sf");
    B_L_Sf lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(B_L_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_L_Sf)");
    check_field_offset(lv, v1, 0, "B_L_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_L_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "B_L_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_L_Sf(Test_B_L_Sf, "B_L_Sf", ABISELECT(24,16));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_S_Sf  {
  bool v1;
  short v2;
  ::empty v3;
};
//SIG(1 B_S_Sf) C1{ Fc Fs FC2{}}



static void Test_B_S_Sf()
{
  {
    init_simple_test("B_S_Sf");
    B_S_Sf lv;
    check2(sizeof(lv), 6, "sizeof(B_S_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(B_S_Sf)");
    check_field_offset(lv, v1, 0, "B_S_Sf.v1");
    check_field_offset(lv, v2, 2, "B_S_Sf.v2");
    check_field_offset(lv, v3, 4, "B_S_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_S_Sf(Test_B_S_Sf, "B_S_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf  {
  bool v1;
  ::empty v2;
};
//SIG(1 B_Sf) C1{ Fc FC2{}}



static void Test_B_Sf()
{
  {
    init_simple_test("B_Sf");
    B_Sf lv;
    check2(sizeof(lv), 2, "sizeof(B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf)");
    check_field_offset(lv, v1, 0, "B_Sf.v1");
    check_field_offset(lv, v2, 1, "B_Sf.v2");
  }
}
static Arrange_To_Call_Me vB_Sf(Test_B_Sf, "B_Sf", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_B  {
  bool v1;
  ::empty v2;
  bool v3;
};
//SIG(1 B_Sf_B) C1{ Fc FC2{} Fc}



static void Test_B_Sf_B()
{
  {
    init_simple_test("B_Sf_B");
    B_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_B)");
    check_field_offset(lv, v1, 0, "B_Sf_B.v1");
    check_field_offset(lv, v2, 1, "B_Sf_B.v2");
    check_field_offset(lv, v3, 2, "B_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_B(Test_B_Sf_B, "B_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu15i  {
  bool v1;
  ::empty v2;
  unsigned int v3:15;
};
//SIG(1 B_Sf_BFu15i) C1{ Fc FC2{} Fi:15}



static void Test_B_Sf_BFu15i()
{
  {
    init_simple_test("B_Sf_BFu15i");
    static B_Sf_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(B_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu15i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu15i.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "B_Sf_BFu15i");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "B_Sf_BFu15i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu15i(Test_B_Sf_BFu15i, "B_Sf_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu15ll  {
  bool v1;
  ::empty v2;
  __tsu64 v3:15;
};
//SIG(1 B_Sf_BFu15ll) C1{ Fc FC2{} FL:15}



static void Test_B_Sf_BFu15ll()
{
  {
    init_simple_test("B_Sf_BFu15ll");
    static B_Sf_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_Sf_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu15ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu15ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "B_Sf_BFu15ll");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "B_Sf_BFu15ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu15ll(Test_B_Sf_BFu15ll, "B_Sf_BFu15ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu15s  {
  bool v1;
  ::empty v2;
  unsigned short v3:15;
};
//SIG(1 B_Sf_BFu15s) C1{ Fc FC2{} Fs:15}



static void Test_B_Sf_BFu15s()
{
  {
    init_simple_test("B_Sf_BFu15s");
    static B_Sf_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu15s)");
    check2(__alignof__(lv), 2, "__alignof__(B_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu15s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu15s.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "B_Sf_BFu15s");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "B_Sf_BFu15s");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu15s(Test_B_Sf_BFu15s, "B_Sf_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu16i  {
  bool v1;
  ::empty v2;
  unsigned int v3:16;
};
//SIG(1 B_Sf_BFu16i) C1{ Fc FC2{} Fi:16}



static void Test_B_Sf_BFu16i()
{
  {
    init_simple_test("B_Sf_BFu16i");
    static B_Sf_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(B_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu16i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu16i.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "B_Sf_BFu16i");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "B_Sf_BFu16i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu16i(Test_B_Sf_BFu16i, "B_Sf_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu16ll  {
  bool v1;
  ::empty v2;
  __tsu64 v3:16;
};
//SIG(1 B_Sf_BFu16ll) C1{ Fc FC2{} FL:16}



static void Test_B_Sf_BFu16ll()
{
  {
    init_simple_test("B_Sf_BFu16ll");
    static B_Sf_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_Sf_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu16ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu16ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "B_Sf_BFu16ll");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "B_Sf_BFu16ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu16ll(Test_B_Sf_BFu16ll, "B_Sf_BFu16ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu16s  {
  bool v1;
  ::empty v2;
  unsigned short v3:16;
};
//SIG(1 B_Sf_BFu16s) C1{ Fc FC2{} Fs:16}



static void Test_B_Sf_BFu16s()
{
  {
    init_simple_test("B_Sf_BFu16s");
    static B_Sf_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu16s)");
    check2(__alignof__(lv), 2, "__alignof__(B_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu16s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu16s.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "B_Sf_BFu16s");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "B_Sf_BFu16s");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu16s(Test_B_Sf_BFu16s, "B_Sf_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu17i  {
  bool v1;
  ::empty v2;
  unsigned int v3:17;
};
//SIG(1 B_Sf_BFu17i) C1{ Fc FC2{} Fi:17}



static void Test_B_Sf_BFu17i()
{
  {
    init_simple_test("B_Sf_BFu17i");
    static B_Sf_BFu17i lv;
    check2(sizeof(lv), 8, "sizeof(B_Sf_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(B_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu17i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu17i.v2");
    set_bf_and_test(lv, v3, 4, 0, 17, 1, "B_Sf_BFu17i");
    set_bf_and_test(lv, v3, 4, 0, 17, hide_ull(1LL<<16), "B_Sf_BFu17i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu17i(Test_B_Sf_BFu17i, "B_Sf_BFu17i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu17ll  {
  bool v1;
  ::empty v2;
  __tsu64 v3:17;
};
//SIG(1 B_Sf_BFu17ll) C1{ Fc FC2{} FL:17}



static void Test_B_Sf_BFu17ll()
{
  {
    init_simple_test("B_Sf_BFu17ll");
    static B_Sf_BFu17ll lv;
    check2(sizeof(lv), 8, "sizeof(B_Sf_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu17ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu17ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "B_Sf_BFu17ll");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "B_Sf_BFu17ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu17ll(Test_B_Sf_BFu17ll, "B_Sf_BFu17ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu1c  {
  bool v1;
  ::empty v2;
  unsigned char v3:1;
};
//SIG(1 B_Sf_BFu1c) C1{ Fc FC2{} Fc:1}



static void Test_B_Sf_BFu1c()
{
  {
    init_simple_test("B_Sf_BFu1c");
    static B_Sf_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu1c.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu1c.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "B_Sf_BFu1c");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu1c(Test_B_Sf_BFu1c, "B_Sf_BFu1c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu1i  {
  bool v1;
  ::empty v2;
  unsigned int v3:1;
};
//SIG(1 B_Sf_BFu1i) C1{ Fc FC2{} Fi:1}



static void Test_B_Sf_BFu1i()
{
  {
    init_simple_test("B_Sf_BFu1i");
    static B_Sf_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(B_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu1i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu1i.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "B_Sf_BFu1i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu1i(Test_B_Sf_BFu1i, "B_Sf_BFu1i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu1ll  {
  bool v1;
  ::empty v2;
  __tsu64 v3:1;
};
//SIG(1 B_Sf_BFu1ll) C1{ Fc FC2{} FL:1}



static void Test_B_Sf_BFu1ll()
{
  {
    init_simple_test("B_Sf_BFu1ll");
    static B_Sf_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_Sf_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu1ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu1ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "B_Sf_BFu1ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu1ll(Test_B_Sf_BFu1ll, "B_Sf_BFu1ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu1s  {
  bool v1;
  ::empty v2;
  unsigned short v3:1;
};
//SIG(1 B_Sf_BFu1s) C1{ Fc FC2{} Fs:1}



static void Test_B_Sf_BFu1s()
{
  {
    init_simple_test("B_Sf_BFu1s");
    static B_Sf_BFu1s lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu1s)");
    check2(__alignof__(lv), 2, "__alignof__(B_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu1s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu1s.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "B_Sf_BFu1s");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu1s(Test_B_Sf_BFu1s, "B_Sf_BFu1s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu31i  {
  bool v1;
  ::empty v2;
  unsigned int v3:31;
};
//SIG(1 B_Sf_BFu31i) C1{ Fc FC2{} Fi:31}



static void Test_B_Sf_BFu31i()
{
  {
    init_simple_test("B_Sf_BFu31i");
    static B_Sf_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(B_Sf_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(B_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu31i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu31i.v2");
    set_bf_and_test(lv, v3, 4, 0, 31, 1, "B_Sf_BFu31i");
    set_bf_and_test(lv, v3, 4, 0, 31, hide_ull(1LL<<30), "B_Sf_BFu31i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu31i(Test_B_Sf_BFu31i, "B_Sf_BFu31i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu31ll  {
  bool v1;
  ::empty v2;
  __tsu64 v3:31;
};
//SIG(1 B_Sf_BFu31ll) C1{ Fc FC2{} FL:31}



static void Test_B_Sf_BFu31ll()
{
  {
    init_simple_test("B_Sf_BFu31ll");
    static B_Sf_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(B_Sf_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu31ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu31ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "B_Sf_BFu31ll");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "B_Sf_BFu31ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu31ll(Test_B_Sf_BFu31ll, "B_Sf_BFu31ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu32i  {
  bool v1;
  ::empty v2;
  unsigned int v3:32;
};
//SIG(1 B_Sf_BFu32i) C1{ Fc FC2{} Fi:32}



static void Test_B_Sf_BFu32i()
{
  {
    init_simple_test("B_Sf_BFu32i");
    static B_Sf_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(B_Sf_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(B_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu32i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu32i.v2");
    set_bf_and_test(lv, v3, 4, 0, 32, 1, "B_Sf_BFu32i");
    set_bf_and_test(lv, v3, 4, 0, 32, hide_ull(1LL<<31), "B_Sf_BFu32i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu32i(Test_B_Sf_BFu32i, "B_Sf_BFu32i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu32ll  {
  bool v1;
  ::empty v2;
  __tsu64 v3:32;
};
//SIG(1 B_Sf_BFu32ll) C1{ Fc FC2{} FL:32}



static void Test_B_Sf_BFu32ll()
{
  {
    init_simple_test("B_Sf_BFu32ll");
    static B_Sf_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(B_Sf_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu32ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu32ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "B_Sf_BFu32ll");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "B_Sf_BFu32ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu32ll(Test_B_Sf_BFu32ll, "B_Sf_BFu32ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu33  {
  bool v1;
  ::empty v2;
  __tsu64 v3:33;
};
//SIG(1 B_Sf_BFu33) C1{ Fc FC2{} FL:33}



static void Test_B_Sf_BFu33()
{
  {
    init_simple_test("B_Sf_BFu33");
    static B_Sf_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(B_Sf_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu33.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu33.v2");
    set_bf_and_test(lv, v3, 2, 0, 33, 1, "B_Sf_BFu33");
    set_bf_and_test(lv, v3, 2, 0, 33, hide_ull(1LL<<32), "B_Sf_BFu33");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu33(Test_B_Sf_BFu33, "B_Sf_BFu33", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu7c  {
  bool v1;
  ::empty v2;
  unsigned char v3:7;
};
//SIG(1 B_Sf_BFu7c) C1{ Fc FC2{} Fc:7}



static void Test_B_Sf_BFu7c()
{
  {
    init_simple_test("B_Sf_BFu7c");
    static B_Sf_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu7c.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu7c.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "B_Sf_BFu7c");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "B_Sf_BFu7c");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu7c(Test_B_Sf_BFu7c, "B_Sf_BFu7c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu7i  {
  bool v1;
  ::empty v2;
  unsigned int v3:7;
};
//SIG(1 B_Sf_BFu7i) C1{ Fc FC2{} Fi:7}



static void Test_B_Sf_BFu7i()
{
  {
    init_simple_test("B_Sf_BFu7i");
    static B_Sf_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(B_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu7i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu7i.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "B_Sf_BFu7i");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "B_Sf_BFu7i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu7i(Test_B_Sf_BFu7i, "B_Sf_BFu7i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu7ll  {
  bool v1;
  ::empty v2;
  __tsu64 v3:7;
};
//SIG(1 B_Sf_BFu7ll) C1{ Fc FC2{} FL:7}



static void Test_B_Sf_BFu7ll()
{
  {
    init_simple_test("B_Sf_BFu7ll");
    static B_Sf_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_Sf_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu7ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu7ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "B_Sf_BFu7ll");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "B_Sf_BFu7ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu7ll(Test_B_Sf_BFu7ll, "B_Sf_BFu7ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu7s  {
  bool v1;
  ::empty v2;
  unsigned short v3:7;
};
//SIG(1 B_Sf_BFu7s) C1{ Fc FC2{} Fs:7}



static void Test_B_Sf_BFu7s()
{
  {
    init_simple_test("B_Sf_BFu7s");
    static B_Sf_BFu7s lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu7s)");
    check2(__alignof__(lv), 2, "__alignof__(B_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu7s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu7s.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "B_Sf_BFu7s");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "B_Sf_BFu7s");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu7s(Test_B_Sf_BFu7s, "B_Sf_BFu7s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu8c  {
  bool v1;
  ::empty v2;
  unsigned char v3:8;
};
//SIG(1 B_Sf_BFu8c) C1{ Fc FC2{} Fc:8}



static void Test_B_Sf_BFu8c()
{
  {
    init_simple_test("B_Sf_BFu8c");
    static B_Sf_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu8c.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu8c.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "B_Sf_BFu8c");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "B_Sf_BFu8c");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu8c(Test_B_Sf_BFu8c, "B_Sf_BFu8c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu8i  {
  bool v1;
  ::empty v2;
  unsigned int v3:8;
};
//SIG(1 B_Sf_BFu8i) C1{ Fc FC2{} Fi:8}



static void Test_B_Sf_BFu8i()
{
  {
    init_simple_test("B_Sf_BFu8i");
    static B_Sf_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(B_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu8i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu8i.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "B_Sf_BFu8i");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "B_Sf_BFu8i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu8i(Test_B_Sf_BFu8i, "B_Sf_BFu8i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu8ll  {
  bool v1;
  ::empty v2;
  __tsu64 v3:8;
};
//SIG(1 B_Sf_BFu8ll) C1{ Fc FC2{} FL:8}



static void Test_B_Sf_BFu8ll()
{
  {
    init_simple_test("B_Sf_BFu8ll");
    static B_Sf_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_Sf_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu8ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu8ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "B_Sf_BFu8ll");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "B_Sf_BFu8ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu8ll(Test_B_Sf_BFu8ll, "B_Sf_BFu8ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu8s  {
  bool v1;
  ::empty v2;
  unsigned short v3:8;
};
//SIG(1 B_Sf_BFu8s) C1{ Fc FC2{} Fs:8}



static void Test_B_Sf_BFu8s()
{
  {
    init_simple_test("B_Sf_BFu8s");
    static B_Sf_BFu8s lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu8s)");
    check2(__alignof__(lv), 2, "__alignof__(B_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu8s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu8s.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "B_Sf_BFu8s");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "B_Sf_BFu8s");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu8s(Test_B_Sf_BFu8s, "B_Sf_BFu8s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu9i  {
  bool v1;
  ::empty v2;
  unsigned int v3:9;
};
//SIG(1 B_Sf_BFu9i) C1{ Fc FC2{} Fi:9}



static void Test_B_Sf_BFu9i()
{
  {
    init_simple_test("B_Sf_BFu9i");
    static B_Sf_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(B_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu9i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu9i.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "B_Sf_BFu9i");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "B_Sf_BFu9i");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu9i(Test_B_Sf_BFu9i, "B_Sf_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu9ll  {
  bool v1;
  ::empty v2;
  __tsu64 v3:9;
};
//SIG(1 B_Sf_BFu9ll) C1{ Fc FC2{} FL:9}



static void Test_B_Sf_BFu9ll()
{
  {
    init_simple_test("B_Sf_BFu9ll");
    static B_Sf_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_Sf_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu9ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu9ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "B_Sf_BFu9ll");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "B_Sf_BFu9ll");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu9ll(Test_B_Sf_BFu9ll, "B_Sf_BFu9ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu9s  {
  bool v1;
  ::empty v2;
  unsigned short v3:9;
};
//SIG(1 B_Sf_BFu9s) C1{ Fc FC2{} Fs:9}



static void Test_B_Sf_BFu9s()
{
  {
    init_simple_test("B_Sf_BFu9s");
    static B_Sf_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu9s)");
    check2(__alignof__(lv), 2, "__alignof__(B_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu9s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu9s.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "B_Sf_BFu9s");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "B_Sf_BFu9s");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu9s(Test_B_Sf_BFu9s, "B_Sf_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_C  {
  bool v1;
  ::empty v2;
  char v3;
};
//SIG(1 B_Sf_C) C1{ Fc FC2{} Fc}



static void Test_B_Sf_C()
{
  {
    init_simple_test("B_Sf_C");
    B_Sf_C lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_C)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_C)");
    check_field_offset(lv, v1, 0, "B_Sf_C.v1");
    check_field_offset(lv, v2, 1, "B_Sf_C.v2");
    check_field_offset(lv, v3, 2, "B_Sf_C.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_C(Test_B_Sf_C, "B_Sf_C", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_D  {
  bool v1;
  ::empty v2;
  double v3;
};
//SIG(1 B_Sf_D) C1{ Fc FC2{} FL}



static void Test_B_Sf_D()
{
  {
    init_simple_test("B_Sf_D");
    B_Sf_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_Sf_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_D)");
    check_field_offset(lv, v1, 0, "B_Sf_D.v1");
    check_field_offset(lv, v2, 1, "B_Sf_D.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "B_Sf_D.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_D(Test_B_Sf_D, "B_Sf_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_F  {
  bool v1;
  ::empty v2;
  float v3;
};
//SIG(1 B_Sf_F) C1{ Fc FC2{} Fi}



static void Test_B_Sf_F()
{
  {
    init_simple_test("B_Sf_F");
    B_Sf_F lv;
    check2(sizeof(lv), 8, "sizeof(B_Sf_F)");
    check2(__alignof__(lv), 4, "__alignof__(B_Sf_F)");
    check_field_offset(lv, v1, 0, "B_Sf_F.v1");
    check_field_offset(lv, v2, 1, "B_Sf_F.v2");
    check_field_offset(lv, v3, 4, "B_Sf_F.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_F(Test_B_Sf_F, "B_Sf_F", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_I  {
  bool v1;
  ::empty v2;
  int v3;
};
//SIG(1 B_Sf_I) C1{ Fc FC2{} Fi}



static void Test_B_Sf_I()
{
  {
    init_simple_test("B_Sf_I");
    B_Sf_I lv;
    check2(sizeof(lv), 8, "sizeof(B_Sf_I)");
    check2(__alignof__(lv), 4, "__alignof__(B_Sf_I)");
    check_field_offset(lv, v1, 0, "B_Sf_I.v1");
    check_field_offset(lv, v2, 1, "B_Sf_I.v2");
    check_field_offset(lv, v3, 4, "B_Sf_I.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_I(Test_B_Sf_I, "B_Sf_I", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_Ip  {
  bool v1;
  ::empty v2;
  int *v3;
};
//SIG(1 B_Sf_Ip) C1{ Fc FC2{} Fp}



static void Test_B_Sf_Ip()
{
  {
    init_simple_test("B_Sf_Ip");
    B_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_Sf_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_Ip)");
    check_field_offset(lv, v1, 0, "B_Sf_Ip.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "B_Sf_Ip.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Ip(Test_B_Sf_Ip, "B_Sf_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_L  {
  bool v1;
  ::empty v2;
  __tsi64 v3;
};
//SIG(1 B_Sf_L) C1{ Fc FC2{} FL}



static void Test_B_Sf_L()
{
  {
    init_simple_test("B_Sf_L");
    B_Sf_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_Sf_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_L)");
    check_field_offset(lv, v1, 0, "B_Sf_L.v1");
    check_field_offset(lv, v2, 1, "B_Sf_L.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "B_Sf_L.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_L(Test_B_Sf_L, "B_Sf_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_S  {
  bool v1;
  ::empty v2;
  short v3;
};
//SIG(1 B_Sf_S) C1{ Fc FC2{} Fs}



static void Test_B_Sf_S()
{
  {
    init_simple_test("B_Sf_S");
    B_Sf_S lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_S)");
    check2(__alignof__(lv), 2, "__alignof__(B_Sf_S)");
    check_field_offset(lv, v1, 0, "B_Sf_S.v1");
    check_field_offset(lv, v2, 1, "B_Sf_S.v2");
    check_field_offset(lv, v3, 2, "B_Sf_S.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_S(Test_B_Sf_S, "B_Sf_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_Sf  {
  bool v1;
  ::empty v2;
  ::empty v3;
};
//SIG(1 B_Sf_Sf) C1{ Fc FC2{} FC2}



static void Test_B_Sf_Sf()
{
  {
    init_simple_test("B_Sf_Sf");
    B_Sf_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_Sf)");
    check_field_offset(lv, v1, 0, "B_Sf_Sf.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Sf.v2");
    check_field_offset(lv, v3, 2, "B_Sf_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Sf(Test_B_Sf_Sf, "B_Sf_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_Uc  {
  bool v1;
  ::empty v2;
  unsigned char v3;
};
//SIG(1 B_Sf_Uc) C1{ Fc FC2{} Fc}



static void Test_B_Sf_Uc()
{
  {
    init_simple_test("B_Sf_Uc");
    B_Sf_Uc lv;
    check2(sizeof(lv), 3, "sizeof(B_Sf_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_Uc)");
    check_field_offset(lv, v1, 0, "B_Sf_Uc.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Uc.v2");
    check_field_offset(lv, v3, 2, "B_Sf_Uc.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Uc(Test_B_Sf_Uc, "B_Sf_Uc", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_Ui  {
  bool v1;
  ::empty v2;
  unsigned int v3;
};
//SIG(1 B_Sf_Ui) C1{ Fc FC2{} Fi}



static void Test_B_Sf_Ui()
{
  {
    init_simple_test("B_Sf_Ui");
    B_Sf_Ui lv;
    check2(sizeof(lv), 8, "sizeof(B_Sf_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(B_Sf_Ui)");
    check_field_offset(lv, v1, 0, "B_Sf_Ui.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Ui.v2");
    check_field_offset(lv, v3, 4, "B_Sf_Ui.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Ui(Test_B_Sf_Ui, "B_Sf_Ui", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_Ul  {
  bool v1;
  ::empty v2;
  __tsu64 v3;
};
//SIG(1 B_Sf_Ul) C1{ Fc FC2{} FL}



static void Test_B_Sf_Ul()
{
  {
    init_simple_test("B_Sf_Ul");
    B_Sf_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_Sf_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_Ul)");
    check_field_offset(lv, v1, 0, "B_Sf_Ul.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "B_Sf_Ul.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Ul(Test_B_Sf_Ul, "B_Sf_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_Us  {
  bool v1;
  ::empty v2;
  unsigned short v3;
};
//SIG(1 B_Sf_Us) C1{ Fc FC2{} Fs}



static void Test_B_Sf_Us()
{
  {
    init_simple_test("B_Sf_Us");
    B_Sf_Us lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_Us)");
    check2(__alignof__(lv), 2, "__alignof__(B_Sf_Us)");
    check_field_offset(lv, v1, 0, "B_Sf_Us.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Us.v2");
    check_field_offset(lv, v3, 2, "B_Sf_Us.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Us(Test_B_Sf_Us, "B_Sf_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_Vp  {
  bool v1;
  ::empty v2;
  void *v3;
};
//SIG(1 B_Sf_Vp) C1{ Fc FC2{} Fp}



static void Test_B_Sf_Vp()
{
  {
    init_simple_test("B_Sf_Vp");
    B_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_Sf_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Sf_Vp)");
    check_field_offset(lv, v1, 0, "B_Sf_Vp.v1");
    check_field_offset(lv, v2, 1, "B_Sf_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "B_Sf_Vp.v3");
  }
}
static Arrange_To_Call_Me vB_Sf_Vp(Test_B_Sf_Vp, "B_Sf_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Uc_Sf  {
  bool v1;
  unsigned char v2;
  ::empty v3;
};
//SIG(1 B_Uc_Sf) C1{ Fc[2] FC2{}}



static void Test_B_Uc_Sf()
{
  {
    init_simple_test("B_Uc_Sf");
    B_Uc_Sf lv;
    check2(sizeof(lv), 3, "sizeof(B_Uc_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_Uc_Sf)");
    check_field_offset(lv, v1, 0, "B_Uc_Sf.v1");
    check_field_offset(lv, v2, 1, "B_Uc_Sf.v2");
    check_field_offset(lv, v3, 2, "B_Uc_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Uc_Sf(Test_B_Uc_Sf, "B_Uc_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ui_Sf  {
  bool v1;
  unsigned int v2;
  ::empty v3;
};
//SIG(1 B_Ui_Sf) C1{ Fc Fi FC2{}}



static void Test_B_Ui_Sf()
{
  {
    init_simple_test("B_Ui_Sf");
    B_Ui_Sf lv;
    check2(sizeof(lv), 12, "sizeof(B_Ui_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(B_Ui_Sf)");
    check_field_offset(lv, v1, 0, "B_Ui_Sf.v1");
    check_field_offset(lv, v2, 4, "B_Ui_Sf.v2");
    check_field_offset(lv, v3, 8, "B_Ui_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Ui_Sf(Test_B_Ui_Sf, "B_Ui_Sf", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ul_Sf  {
  bool v1;
  __tsu64 v2;
  ::empty v3;
};
//SIG(1 B_Ul_Sf) C1{ Fc FL FC2{}}



static void Test_B_Ul_Sf()
{
  {
    init_simple_test("B_Ul_Sf");
    B_Ul_Sf lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(B_Ul_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Ul_Sf)");
    check_field_offset(lv, v1, 0, "B_Ul_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Ul_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "B_Ul_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Ul_Sf(Test_B_Ul_Sf, "B_Ul_Sf", ABISELECT(24,16));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Us_Sf  {
  bool v1;
  unsigned short v2;
  ::empty v3;
};
//SIG(1 B_Us_Sf) C1{ Fc Fs FC2{}}



static void Test_B_Us_Sf()
{
  {
    init_simple_test("B_Us_Sf");
    B_Us_Sf lv;
    check2(sizeof(lv), 6, "sizeof(B_Us_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(B_Us_Sf)");
    check_field_offset(lv, v1, 0, "B_Us_Sf.v1");
    check_field_offset(lv, v2, 2, "B_Us_Sf.v2");
    check_field_offset(lv, v3, 4, "B_Us_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Us_Sf(Test_B_Us_Sf, "B_Us_Sf", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Vp_Sf  {
  bool v1;
  void *v2;
  ::empty v3;
};
//SIG(1 B_Vp_Sf) C1{ Fc Fp FC2{}}



static void Test_B_Vp_Sf()
{
  {
    init_simple_test("B_Vp_Sf");
    B_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(B_Vp_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Vp_Sf)");
    check_field_offset(lv, v1, 0, "B_Vp_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Vp_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "B_Vp_Sf.v3");
  }
}
static Arrange_To_Call_Me vB_Vp_Sf(Test_B_Vp_Sf, "B_Vp_Sf", ABISELECT(24,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15i_B_Sf  {
  unsigned int v1:15;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu15i_B_Sf) C1{ Fi:15 Fc FC2{}}



static void Test_BFu15i_B_Sf()
{
  {
    init_simple_test("BFu15i_B_Sf");
    static BFu15i_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_B_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_B_Sf");
    check_field_offset(lv, v2, 2, "BFu15i_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu15i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu15i_B_Sf(Test_BFu15i_B_Sf, "BFu15i_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15i_Sf_B  {
  unsigned int v1:15;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu15i_Sf_B) C1{ Fi:15 FC2{} Fc}



static void Test_BFu15i_Sf_B()
{
  {
    init_simple_test("BFu15i_Sf_B");
    static BFu15i_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_Sf_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_Sf_B");
    check_field_offset(lv, v2, 2, "BFu15i_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu15i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu15i_Sf_B(Test_BFu15i_Sf_B, "BFu15i_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15ll_B_Sf  {
  __tsu64 v1:15;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu15ll_B_Sf) C1{ FL:15 Fc FC2{}}



static void Test_BFu15ll_B_Sf()
{
  {
    init_simple_test("BFu15ll_B_Sf");
    static BFu15ll_B_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_B_Sf");
    check_field_offset(lv, v2, 2, "BFu15ll_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu15ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu15ll_B_Sf(Test_BFu15ll_B_Sf, "BFu15ll_B_Sf", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15ll_Sf_B  {
  __tsu64 v1:15;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu15ll_Sf_B) C1{ FL:15 FC2{} Fc}



static void Test_BFu15ll_Sf_B()
{
  {
    init_simple_test("BFu15ll_Sf_B");
    static BFu15ll_Sf_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_Sf_B");
    check_field_offset(lv, v2, 2, "BFu15ll_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu15ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu15ll_Sf_B(Test_BFu15ll_Sf_B, "BFu15ll_Sf_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15s_B_Sf  {
  unsigned short v1:15;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu15s_B_Sf) C1{ Fs:15 Fc FC2{}}



static void Test_BFu15s_B_Sf()
{
  {
    init_simple_test("BFu15s_B_Sf");
    static BFu15s_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu15s_B_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu15s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_B_Sf");
    check_field_offset(lv, v2, 2, "BFu15s_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu15s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu15s_B_Sf(Test_BFu15s_B_Sf, "BFu15s_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15s_Sf_B  {
  unsigned short v1:15;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu15s_Sf_B) C1{ Fs:15 FC2{} Fc}



static void Test_BFu15s_Sf_B()
{
  {
    init_simple_test("BFu15s_Sf_B");
    static BFu15s_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu15s_Sf_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu15s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_Sf_B");
    check_field_offset(lv, v2, 2, "BFu15s_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu15s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu15s_Sf_B(Test_BFu15s_Sf_B, "BFu15s_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16i_B_Sf  {
  unsigned int v1:16;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu16i_B_Sf) C1{ Fi:16 Fc FC2{}}



static void Test_BFu16i_B_Sf()
{
  {
    init_simple_test("BFu16i_B_Sf");
    static BFu16i_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_B_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_B_Sf");
    check_field_offset(lv, v2, 2, "BFu16i_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu16i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu16i_B_Sf(Test_BFu16i_B_Sf, "BFu16i_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16i_Sf_B  {
  unsigned int v1:16;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu16i_Sf_B) C1{ Fi:16 FC2{} Fc}



static void Test_BFu16i_Sf_B()
{
  {
    init_simple_test("BFu16i_Sf_B");
    static BFu16i_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_Sf_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_Sf_B");
    check_field_offset(lv, v2, 2, "BFu16i_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu16i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu16i_Sf_B(Test_BFu16i_Sf_B, "BFu16i_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16ll_B_Sf  {
  __tsu64 v1:16;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu16ll_B_Sf) C1{ FL:16 Fc FC2{}}



static void Test_BFu16ll_B_Sf()
{
  {
    init_simple_test("BFu16ll_B_Sf");
    static BFu16ll_B_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_B_Sf");
    check_field_offset(lv, v2, 2, "BFu16ll_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu16ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu16ll_B_Sf(Test_BFu16ll_B_Sf, "BFu16ll_B_Sf", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16ll_Sf_B  {
  __tsu64 v1:16;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu16ll_Sf_B) C1{ FL:16 FC2{} Fc}



static void Test_BFu16ll_Sf_B()
{
  {
    init_simple_test("BFu16ll_Sf_B");
    static BFu16ll_Sf_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_Sf_B");
    check_field_offset(lv, v2, 2, "BFu16ll_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu16ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu16ll_Sf_B(Test_BFu16ll_Sf_B, "BFu16ll_Sf_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16s_B_Sf  {
  unsigned short v1:16;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu16s_B_Sf) C1{ Fs:16 Fc FC2{}}



static void Test_BFu16s_B_Sf()
{
  {
    init_simple_test("BFu16s_B_Sf");
    static BFu16s_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu16s_B_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu16s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_B_Sf");
    check_field_offset(lv, v2, 2, "BFu16s_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu16s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu16s_B_Sf(Test_BFu16s_B_Sf, "BFu16s_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16s_Sf_B  {
  unsigned short v1:16;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu16s_Sf_B) C1{ Fs:16 FC2{} Fc}



static void Test_BFu16s_Sf_B()
{
  {
    init_simple_test("BFu16s_Sf_B");
    static BFu16s_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu16s_Sf_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu16s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_Sf_B");
    check_field_offset(lv, v2, 2, "BFu16s_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu16s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu16s_Sf_B(Test_BFu16s_Sf_B, "BFu16s_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17i_B_Sf  {
  unsigned int v1:17;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu17i_B_Sf) C1{ Fi:17 Fc FC2{}}



static void Test_BFu17i_B_Sf()
{
  {
    init_simple_test("BFu17i_B_Sf");
    static BFu17i_B_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu17i_B_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_B_Sf");
    check_field_offset(lv, v2, 3, "BFu17i_B_Sf.v2");
    check_field_offset(lv, v3, 4, "BFu17i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu17i_B_Sf(Test_BFu17i_B_Sf, "BFu17i_B_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17i_Sf_B  {
  unsigned int v1:17;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu17i_Sf_B) C1{ Fi:17 FC2{} Fc}



static void Test_BFu17i_Sf_B()
{
  {
    init_simple_test("BFu17i_Sf_B");
    static BFu17i_Sf_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu17i_Sf_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_Sf_B");
    check_field_offset(lv, v2, 3, "BFu17i_Sf_B.v2");
    check_field_offset(lv, v3, 4, "BFu17i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu17i_Sf_B(Test_BFu17i_Sf_B, "BFu17i_Sf_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17ll_B_Sf  {
  __tsu64 v1:17;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu17ll_B_Sf) C1{ FL:17 Fc FC2{}}



static void Test_BFu17ll_B_Sf()
{
  {
    init_simple_test("BFu17ll_B_Sf");
    static BFu17ll_B_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu17ll_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_B_Sf");
    check_field_offset(lv, v2, 3, "BFu17ll_B_Sf.v2");
    check_field_offset(lv, v3, 4, "BFu17ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu17ll_B_Sf(Test_BFu17ll_B_Sf, "BFu17ll_B_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17ll_Sf_B  {
  __tsu64 v1:17;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu17ll_Sf_B) C1{ FL:17 FC2{} Fc}



static void Test_BFu17ll_Sf_B()
{
  {
    init_simple_test("BFu17ll_Sf_B");
    static BFu17ll_Sf_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu17ll_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_Sf_B");
    check_field_offset(lv, v2, 3, "BFu17ll_Sf_B.v2");
    check_field_offset(lv, v3, 4, "BFu17ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu17ll_Sf_B(Test_BFu17ll_Sf_B, "BFu17ll_Sf_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1c_B_Sf  {
  unsigned char v1:1;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu1c_B_Sf) C1{ Fc:1 Fc FC2{}}



static void Test_BFu1c_B_Sf()
{
  {
    init_simple_test("BFu1c_B_Sf");
    static BFu1c_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu1c_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1c_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_B_Sf");
    check_field_offset(lv, v2, 1, "BFu1c_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu1c_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu1c_B_Sf(Test_BFu1c_B_Sf, "BFu1c_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1c_Sf_B  {
  unsigned char v1:1;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu1c_Sf_B) C1{ Fc:1 FC2{} Fc}



static void Test_BFu1c_Sf_B()
{
  {
    init_simple_test("BFu1c_Sf_B");
    static BFu1c_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu1c_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1c_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_Sf_B");
    check_field_offset(lv, v2, 1, "BFu1c_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu1c_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu1c_Sf_B(Test_BFu1c_Sf_B, "BFu1c_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1i_B_Sf  {
  unsigned int v1:1;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu1i_B_Sf) C1{ Fi:1 Fc FC2{}}



static void Test_BFu1i_B_Sf()
{
  {
    init_simple_test("BFu1i_B_Sf");
    static BFu1i_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_B_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_B_Sf");
    check_field_offset(lv, v2, 1, "BFu1i_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu1i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu1i_B_Sf(Test_BFu1i_B_Sf, "BFu1i_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1i_Sf_B  {
  unsigned int v1:1;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu1i_Sf_B) C1{ Fi:1 FC2{} Fc}



static void Test_BFu1i_Sf_B()
{
  {
    init_simple_test("BFu1i_Sf_B");
    static BFu1i_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_Sf_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_Sf_B");
    check_field_offset(lv, v2, 1, "BFu1i_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu1i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu1i_Sf_B(Test_BFu1i_Sf_B, "BFu1i_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1ll_B_Sf  {
  __tsu64 v1:1;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu1ll_B_Sf) C1{ FL:1 Fc FC2{}}



static void Test_BFu1ll_B_Sf()
{
  {
    init_simple_test("BFu1ll_B_Sf");
    static BFu1ll_B_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_B_Sf");
    check_field_offset(lv, v2, 1, "BFu1ll_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu1ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu1ll_B_Sf(Test_BFu1ll_B_Sf, "BFu1ll_B_Sf", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1ll_Sf_B  {
  __tsu64 v1:1;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu1ll_Sf_B) C1{ FL:1 FC2{} Fc}



static void Test_BFu1ll_Sf_B()
{
  {
    init_simple_test("BFu1ll_Sf_B");
    static BFu1ll_Sf_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_Sf_B");
    check_field_offset(lv, v2, 1, "BFu1ll_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu1ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu1ll_Sf_B(Test_BFu1ll_Sf_B, "BFu1ll_Sf_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1s_B_Sf  {
  unsigned short v1:1;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu1s_B_Sf) C1{ Fs:1 Fc FC2{}}



static void Test_BFu1s_B_Sf()
{
  {
    init_simple_test("BFu1s_B_Sf");
    static BFu1s_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu1s_B_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu1s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_B_Sf");
    check_field_offset(lv, v2, 1, "BFu1s_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu1s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu1s_B_Sf(Test_BFu1s_B_Sf, "BFu1s_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1s_Sf_B  {
  unsigned short v1:1;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu1s_Sf_B) C1{ Fs:1 FC2{} Fc}



static void Test_BFu1s_Sf_B()
{
  {
    init_simple_test("BFu1s_Sf_B");
    static BFu1s_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu1s_Sf_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu1s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_Sf_B");
    check_field_offset(lv, v2, 1, "BFu1s_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu1s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu1s_Sf_B(Test_BFu1s_Sf_B, "BFu1s_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31i_B_Sf  {
  unsigned int v1:31;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu31i_B_Sf) C1{ Fi:31 Fc FC2{}}



static void Test_BFu31i_B_Sf()
{
  {
    init_simple_test("BFu31i_B_Sf");
    static BFu31i_B_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu31i_B_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_B_Sf");
    check_field_offset(lv, v2, 4, "BFu31i_B_Sf.v2");
    check_field_offset(lv, v3, 5, "BFu31i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu31i_B_Sf(Test_BFu31i_B_Sf, "BFu31i_B_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31i_Sf_B  {
  unsigned int v1:31;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu31i_Sf_B) C1{ Fi:31 FC2{} Fc}



static void Test_BFu31i_Sf_B()
{
  {
    init_simple_test("BFu31i_Sf_B");
    static BFu31i_Sf_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu31i_Sf_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_Sf_B");
    check_field_offset(lv, v2, 4, "BFu31i_Sf_B.v2");
    check_field_offset(lv, v3, 5, "BFu31i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu31i_Sf_B(Test_BFu31i_Sf_B, "BFu31i_Sf_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31ll_B_Sf  {
  __tsu64 v1:31;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu31ll_B_Sf) C1{ FL:31 Fc FC2{}}



static void Test_BFu31ll_B_Sf()
{
  {
    init_simple_test("BFu31ll_B_Sf");
    static BFu31ll_B_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu31ll_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_B_Sf");
    check_field_offset(lv, v2, 4, "BFu31ll_B_Sf.v2");
    check_field_offset(lv, v3, 5, "BFu31ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu31ll_B_Sf(Test_BFu31ll_B_Sf, "BFu31ll_B_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31ll_Sf_B  {
  __tsu64 v1:31;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu31ll_Sf_B) C1{ FL:31 FC2{} Fc}



static void Test_BFu31ll_Sf_B()
{
  {
    init_simple_test("BFu31ll_Sf_B");
    static BFu31ll_Sf_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu31ll_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_Sf_B");
    check_field_offset(lv, v2, 4, "BFu31ll_Sf_B.v2");
    check_field_offset(lv, v3, 5, "BFu31ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu31ll_Sf_B(Test_BFu31ll_Sf_B, "BFu31ll_Sf_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32i_B_Sf  {
  unsigned int v1:32;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu32i_B_Sf) C1{ Fi:32 Fc FC2{}}



static void Test_BFu32i_B_Sf()
{
  {
    init_simple_test("BFu32i_B_Sf");
    static BFu32i_B_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu32i_B_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_B_Sf");
    check_field_offset(lv, v2, 4, "BFu32i_B_Sf.v2");
    check_field_offset(lv, v3, 5, "BFu32i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu32i_B_Sf(Test_BFu32i_B_Sf, "BFu32i_B_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32i_Sf_B  {
  unsigned int v1:32;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu32i_Sf_B) C1{ Fi:32 FC2{} Fc}



static void Test_BFu32i_Sf_B()
{
  {
    init_simple_test("BFu32i_Sf_B");
    static BFu32i_Sf_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu32i_Sf_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_Sf_B");
    check_field_offset(lv, v2, 4, "BFu32i_Sf_B.v2");
    check_field_offset(lv, v3, 5, "BFu32i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu32i_Sf_B(Test_BFu32i_Sf_B, "BFu32i_Sf_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32ll_B_Sf  {
  __tsu64 v1:32;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu32ll_B_Sf) C1{ FL:32 Fc FC2{}}



static void Test_BFu32ll_B_Sf()
{
  {
    init_simple_test("BFu32ll_B_Sf");
    static BFu32ll_B_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu32ll_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_B_Sf");
    check_field_offset(lv, v2, 4, "BFu32ll_B_Sf.v2");
    check_field_offset(lv, v3, 5, "BFu32ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu32ll_B_Sf(Test_BFu32ll_B_Sf, "BFu32ll_B_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32ll_Sf_B  {
  __tsu64 v1:32;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu32ll_Sf_B) C1{ FL:32 FC2{} Fc}



static void Test_BFu32ll_Sf_B()
{
  {
    init_simple_test("BFu32ll_Sf_B");
    static BFu32ll_Sf_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu32ll_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_Sf_B");
    check_field_offset(lv, v2, 4, "BFu32ll_Sf_B.v2");
    check_field_offset(lv, v3, 5, "BFu32ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu32ll_Sf_B(Test_BFu32ll_Sf_B, "BFu32ll_Sf_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu33_B_Sf  {
  __tsu64 v1:33;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu33_B_Sf) C1{ FL:33 Fc FC2{}}



static void Test_BFu33_B_Sf()
{
  {
    init_simple_test("BFu33_B_Sf");
    static BFu33_B_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_B_Sf");
    check_field_offset(lv, v2, 5, "BFu33_B_Sf.v2");
    check_field_offset(lv, v3, 6, "BFu33_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu33_B_Sf(Test_BFu33_B_Sf, "BFu33_B_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu33_Sf_B  {
  __tsu64 v1:33;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu33_Sf_B) C1{ FL:33 FC2{} Fc}



static void Test_BFu33_Sf_B()
{
  {
    init_simple_test("BFu33_Sf_B");
    static BFu33_Sf_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_Sf_B");
    check_field_offset(lv, v2, 5, "BFu33_Sf_B.v2");
    check_field_offset(lv, v3, 6, "BFu33_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu33_Sf_B(Test_BFu33_Sf_B, "BFu33_Sf_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7c_B_Sf  {
  unsigned char v1:7;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu7c_B_Sf) C1{ Fc:7 Fc FC2{}}



static void Test_BFu7c_B_Sf()
{
  {
    init_simple_test("BFu7c_B_Sf");
    static BFu7c_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu7c_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7c_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_B_Sf");
    check_field_offset(lv, v2, 1, "BFu7c_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu7c_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu7c_B_Sf(Test_BFu7c_B_Sf, "BFu7c_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7c_Sf_B  {
  unsigned char v1:7;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu7c_Sf_B) C1{ Fc:7 FC2{} Fc}



static void Test_BFu7c_Sf_B()
{
  {
    init_simple_test("BFu7c_Sf_B");
    static BFu7c_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu7c_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7c_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_Sf_B");
    check_field_offset(lv, v2, 1, "BFu7c_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu7c_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu7c_Sf_B(Test_BFu7c_Sf_B, "BFu7c_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7i_B_Sf  {
  unsigned int v1:7;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu7i_B_Sf) C1{ Fi:7 Fc FC2{}}



static void Test_BFu7i_B_Sf()
{
  {
    init_simple_test("BFu7i_B_Sf");
    static BFu7i_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_B_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_B_Sf");
    check_field_offset(lv, v2, 1, "BFu7i_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu7i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu7i_B_Sf(Test_BFu7i_B_Sf, "BFu7i_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7i_Sf_B  {
  unsigned int v1:7;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu7i_Sf_B) C1{ Fi:7 FC2{} Fc}



static void Test_BFu7i_Sf_B()
{
  {
    init_simple_test("BFu7i_Sf_B");
    static BFu7i_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_Sf_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_Sf_B");
    check_field_offset(lv, v2, 1, "BFu7i_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu7i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu7i_Sf_B(Test_BFu7i_Sf_B, "BFu7i_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7ll_B_Sf  {
  __tsu64 v1:7;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu7ll_B_Sf) C1{ FL:7 Fc FC2{}}



static void Test_BFu7ll_B_Sf()
{
  {
    init_simple_test("BFu7ll_B_Sf");
    static BFu7ll_B_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_B_Sf");
    check_field_offset(lv, v2, 1, "BFu7ll_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu7ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu7ll_B_Sf(Test_BFu7ll_B_Sf, "BFu7ll_B_Sf", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7ll_Sf_B  {
  __tsu64 v1:7;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu7ll_Sf_B) C1{ FL:7 FC2{} Fc}



static void Test_BFu7ll_Sf_B()
{
  {
    init_simple_test("BFu7ll_Sf_B");
    static BFu7ll_Sf_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_Sf_B");
    check_field_offset(lv, v2, 1, "BFu7ll_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu7ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu7ll_Sf_B(Test_BFu7ll_Sf_B, "BFu7ll_Sf_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7s_B_Sf  {
  unsigned short v1:7;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu7s_B_Sf) C1{ Fs:7 Fc FC2{}}



static void Test_BFu7s_B_Sf()
{
  {
    init_simple_test("BFu7s_B_Sf");
    static BFu7s_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu7s_B_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu7s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_B_Sf");
    check_field_offset(lv, v2, 1, "BFu7s_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu7s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu7s_B_Sf(Test_BFu7s_B_Sf, "BFu7s_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7s_Sf_B  {
  unsigned short v1:7;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu7s_Sf_B) C1{ Fs:7 FC2{} Fc}



static void Test_BFu7s_Sf_B()
{
  {
    init_simple_test("BFu7s_Sf_B");
    static BFu7s_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu7s_Sf_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu7s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_Sf_B");
    check_field_offset(lv, v2, 1, "BFu7s_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu7s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu7s_Sf_B(Test_BFu7s_Sf_B, "BFu7s_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8c_B_Sf  {
  unsigned char v1:8;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu8c_B_Sf) C1{ Fc:8 Fc FC2{}}



static void Test_BFu8c_B_Sf()
{
  {
    init_simple_test("BFu8c_B_Sf");
    static BFu8c_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(BFu8c_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8c_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_B_Sf");
    check_field_offset(lv, v2, 1, "BFu8c_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu8c_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu8c_B_Sf(Test_BFu8c_B_Sf, "BFu8c_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8c_Sf_B  {
  unsigned char v1:8;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu8c_Sf_B) C1{ Fc:8 FC2{} Fc}



static void Test_BFu8c_Sf_B()
{
  {
    init_simple_test("BFu8c_Sf_B");
    static BFu8c_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(BFu8c_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8c_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_Sf_B");
    check_field_offset(lv, v2, 1, "BFu8c_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu8c_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu8c_Sf_B(Test_BFu8c_Sf_B, "BFu8c_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8i_B_Sf  {
  unsigned int v1:8;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu8i_B_Sf) C1{ Fi:8 Fc FC2{}}



static void Test_BFu8i_B_Sf()
{
  {
    init_simple_test("BFu8i_B_Sf");
    static BFu8i_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_B_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_B_Sf");
    check_field_offset(lv, v2, 1, "BFu8i_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu8i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu8i_B_Sf(Test_BFu8i_B_Sf, "BFu8i_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8i_Sf_B  {
  unsigned int v1:8;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu8i_Sf_B) C1{ Fi:8 FC2{} Fc}



static void Test_BFu8i_Sf_B()
{
  {
    init_simple_test("BFu8i_Sf_B");
    static BFu8i_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_Sf_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_Sf_B");
    check_field_offset(lv, v2, 1, "BFu8i_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu8i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu8i_Sf_B(Test_BFu8i_Sf_B, "BFu8i_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8ll_B_Sf  {
  __tsu64 v1:8;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu8ll_B_Sf) C1{ FL:8 Fc FC2{}}



static void Test_BFu8ll_B_Sf()
{
  {
    init_simple_test("BFu8ll_B_Sf");
    static BFu8ll_B_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_B_Sf");
    check_field_offset(lv, v2, 1, "BFu8ll_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu8ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu8ll_B_Sf(Test_BFu8ll_B_Sf, "BFu8ll_B_Sf", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8ll_Sf_B  {
  __tsu64 v1:8;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu8ll_Sf_B) C1{ FL:8 FC2{} Fc}



static void Test_BFu8ll_Sf_B()
{
  {
    init_simple_test("BFu8ll_Sf_B");
    static BFu8ll_Sf_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_Sf_B");
    check_field_offset(lv, v2, 1, "BFu8ll_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu8ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu8ll_Sf_B(Test_BFu8ll_Sf_B, "BFu8ll_Sf_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8s_B_Sf  {
  unsigned short v1:8;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu8s_B_Sf) C1{ Fs:8 Fc FC2{}}



static void Test_BFu8s_B_Sf()
{
  {
    init_simple_test("BFu8s_B_Sf");
    static BFu8s_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu8s_B_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu8s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_B_Sf");
    check_field_offset(lv, v2, 1, "BFu8s_B_Sf.v2");
    check_field_offset(lv, v3, 2, "BFu8s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu8s_B_Sf(Test_BFu8s_B_Sf, "BFu8s_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8s_Sf_B  {
  unsigned short v1:8;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu8s_Sf_B) C1{ Fs:8 FC2{} Fc}



static void Test_BFu8s_Sf_B()
{
  {
    init_simple_test("BFu8s_Sf_B");
    static BFu8s_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu8s_Sf_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu8s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_Sf_B");
    check_field_offset(lv, v2, 1, "BFu8s_Sf_B.v2");
    check_field_offset(lv, v3, 2, "BFu8s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu8s_Sf_B(Test_BFu8s_Sf_B, "BFu8s_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9i_B_Sf  {
  unsigned int v1:9;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu9i_B_Sf) C1{ Fi:9 Fc FC2{}}



static void Test_BFu9i_B_Sf()
{
  {
    init_simple_test("BFu9i_B_Sf");
    static BFu9i_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_B_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_B_Sf");
    check_field_offset(lv, v2, 2, "BFu9i_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu9i_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu9i_B_Sf(Test_BFu9i_B_Sf, "BFu9i_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9i_Sf_B  {
  unsigned int v1:9;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu9i_Sf_B) C1{ Fi:9 FC2{} Fc}



static void Test_BFu9i_Sf_B()
{
  {
    init_simple_test("BFu9i_Sf_B");
    static BFu9i_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_Sf_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_Sf_B");
    check_field_offset(lv, v2, 2, "BFu9i_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu9i_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9i_Sf_B(Test_BFu9i_Sf_B, "BFu9i_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9ll_B_Sf  {
  __tsu64 v1:9;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu9ll_B_Sf) C1{ FL:9 Fc FC2{}}



static void Test_BFu9ll_B_Sf()
{
  {
    init_simple_test("BFu9ll_B_Sf");
    static BFu9ll_B_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_B_Sf");
    check_field_offset(lv, v2, 2, "BFu9ll_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu9ll_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu9ll_B_Sf(Test_BFu9ll_B_Sf, "BFu9ll_B_Sf", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9ll_Sf_B  {
  __tsu64 v1:9;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu9ll_Sf_B) C1{ FL:9 FC2{} Fc}



static void Test_BFu9ll_Sf_B()
{
  {
    init_simple_test("BFu9ll_Sf_B");
    static BFu9ll_Sf_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_Sf_B");
    check_field_offset(lv, v2, 2, "BFu9ll_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu9ll_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9ll_Sf_B(Test_BFu9ll_Sf_B, "BFu9ll_Sf_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9s_B_Sf  {
  unsigned short v1:9;
  bool v2;
  ::empty v3;
};
//SIG(1 BFu9s_B_Sf) C1{ Fs:9 Fc FC2{}}



static void Test_BFu9s_B_Sf()
{
  {
    init_simple_test("BFu9s_B_Sf");
    static BFu9s_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_B_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu9s_B_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_B_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_B_Sf");
    check_field_offset(lv, v2, 2, "BFu9s_B_Sf.v2");
    check_field_offset(lv, v3, 3, "BFu9s_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_B_Sf(Test_BFu9s_B_Sf, "BFu9s_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9s_Sf_B  {
  unsigned short v1:9;
  ::empty v2;
  bool v3;
};
//SIG(1 BFu9s_Sf_B) C1{ Fs:9 FC2{} Fc}



static void Test_BFu9s_Sf_B()
{
  {
    init_simple_test("BFu9s_Sf_B");
    static BFu9s_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_Sf_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu9s_Sf_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_Sf_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_Sf_B");
    check_field_offset(lv, v2, 2, "BFu9s_Sf_B.v2");
    check_field_offset(lv, v3, 3, "BFu9s_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vBFu9s_Sf_B(Test_BFu9s_Sf_B, "BFu9s_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  C_B_Sf  {
  char v1;
  bool v2;
  ::empty v3;
};
//SIG(1 C_B_Sf) C1{ Fc[2] FC2{}}



static void Test_C_B_Sf()
{
  {
    init_simple_test("C_B_Sf");
    C_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(C_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_Sf)");
    check_field_offset(lv, v1, 0, "C_B_Sf.v1");
    check_field_offset(lv, v2, 1, "C_B_Sf.v2");
    check_field_offset(lv, v3, 2, "C_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vC_B_Sf(Test_C_B_Sf, "C_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  C_Sf_B  {
  char v1;
  ::empty v2;
  bool v3;
};
//SIG(1 C_Sf_B) C1{ Fc FC2{} Fc}



static void Test_C_Sf_B()
{
  {
    init_simple_test("C_Sf_B");
    C_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(C_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_Sf_B)");
    check_field_offset(lv, v1, 0, "C_Sf_B.v1");
    check_field_offset(lv, v2, 1, "C_Sf_B.v2");
    check_field_offset(lv, v3, 2, "C_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vC_Sf_B(Test_C_Sf_B, "C_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  D_B_Sf  {
  double v1;
  bool v2;
  ::empty v3;
};
//SIG(1 D_B_Sf) C1{ FL Fc FC2{}}



static void Test_D_B_Sf()
{
  {
    init_simple_test("D_B_Sf");
    D_B_Sf lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(D_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_B_Sf)");
    check_field_offset(lv, v1, 0, "D_B_Sf.v1");
    check_field_offset(lv, v2, 8, "D_B_Sf.v2");
    check_field_offset(lv, v3, 9, "D_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vD_B_Sf(Test_D_B_Sf, "D_B_Sf", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  D_Sf_B  {
  double v1;
  ::empty v2;
  bool v3;
};
//SIG(1 D_Sf_B) C1{ FL FC2{} Fc}



static void Test_D_Sf_B()
{
  {
    init_simple_test("D_Sf_B");
    D_Sf_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(D_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_Sf_B)");
    check_field_offset(lv, v1, 0, "D_Sf_B.v1");
    check_field_offset(lv, v2, 8, "D_Sf_B.v2");
    check_field_offset(lv, v3, 9, "D_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vD_Sf_B(Test_D_Sf_B, "D_Sf_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  F_B_Sf  {
  float v1;
  bool v2;
  ::empty v3;
};
//SIG(1 F_B_Sf) C1{ Fi Fc FC2{}}



static void Test_F_B_Sf()
{
  {
    init_simple_test("F_B_Sf");
    F_B_Sf lv;
    check2(sizeof(lv), 8, "sizeof(F_B_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(F_B_Sf)");
    check_field_offset(lv, v1, 0, "F_B_Sf.v1");
    check_field_offset(lv, v2, 4, "F_B_Sf.v2");
    check_field_offset(lv, v3, 5, "F_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vF_B_Sf(Test_F_B_Sf, "F_B_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  F_Sf_B  {
  float v1;
  ::empty v2;
  bool v3;
};
//SIG(1 F_Sf_B) C1{ Fi FC2{} Fc}



static void Test_F_Sf_B()
{
  {
    init_simple_test("F_Sf_B");
    F_Sf_B lv;
    check2(sizeof(lv), 8, "sizeof(F_Sf_B)");
    check2(__alignof__(lv), 4, "__alignof__(F_Sf_B)");
    check_field_offset(lv, v1, 0, "F_Sf_B.v1");
    check_field_offset(lv, v2, 4, "F_Sf_B.v2");
    check_field_offset(lv, v3, 5, "F_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vF_Sf_B(Test_F_Sf_B, "F_Sf_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  I_B_Sf  {
  int v1;
  bool v2;
  ::empty v3;
};
//SIG(1 I_B_Sf) C1{ Fi Fc FC2{}}



static void Test_I_B_Sf()
{
  {
    init_simple_test("I_B_Sf");
    I_B_Sf lv;
    check2(sizeof(lv), 8, "sizeof(I_B_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(I_B_Sf)");
    check_field_offset(lv, v1, 0, "I_B_Sf.v1");
    check_field_offset(lv, v2, 4, "I_B_Sf.v2");
    check_field_offset(lv, v3, 5, "I_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vI_B_Sf(Test_I_B_Sf, "I_B_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  I_Sf_B  {
  int v1;
  ::empty v2;
  bool v3;
};
//SIG(1 I_Sf_B) C1{ Fi FC2{} Fc}



static void Test_I_Sf_B()
{
  {
    init_simple_test("I_Sf_B");
    I_Sf_B lv;
    check2(sizeof(lv), 8, "sizeof(I_Sf_B)");
    check2(__alignof__(lv), 4, "__alignof__(I_Sf_B)");
    check_field_offset(lv, v1, 0, "I_Sf_B.v1");
    check_field_offset(lv, v2, 4, "I_Sf_B.v2");
    check_field_offset(lv, v3, 5, "I_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vI_Sf_B(Test_I_Sf_B, "I_Sf_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ip_B_Sf  {
  int *v1;
  bool v2;
  ::empty v3;
};
//SIG(1 Ip_B_Sf) C1{ Fp Fc FC2{}}



static void Test_Ip_B_Sf()
{
  {
    init_simple_test("Ip_B_Sf");
    Ip_B_Sf lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ip_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_B_Sf)");
    check_field_offset(lv, v1, 0, "Ip_B_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vIp_B_Sf(Test_Ip_B_Sf, "Ip_B_Sf", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ip_Sf_B  {
  int *v1;
  ::empty v2;
  bool v3;
};
//SIG(1 Ip_Sf_B) C1{ Fp FC2{} Fc}



static void Test_Ip_Sf_B()
{
  {
    init_simple_test("Ip_Sf_B");
    Ip_Sf_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ip_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_Sf_B)");
    check_field_offset(lv, v1, 0, "Ip_Sf_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_Sf_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Ip_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vIp_Sf_B(Test_Ip_Sf_B, "Ip_Sf_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  L_B_Sf  {
  __tsi64 v1;
  bool v2;
  ::empty v3;
};
//SIG(1 L_B_Sf) C1{ FL Fc FC2{}}



static void Test_L_B_Sf()
{
  {
    init_simple_test("L_B_Sf");
    L_B_Sf lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(L_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_B_Sf)");
    check_field_offset(lv, v1, 0, "L_B_Sf.v1");
    check_field_offset(lv, v2, 8, "L_B_Sf.v2");
    check_field_offset(lv, v3, 9, "L_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vL_B_Sf(Test_L_B_Sf, "L_B_Sf", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  L_Sf_B  {
  __tsi64 v1;
  ::empty v2;
  bool v3;
};
//SIG(1 L_Sf_B) C1{ FL FC2{} Fc}



static void Test_L_Sf_B()
{
  {
    init_simple_test("L_Sf_B");
    L_Sf_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(L_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_Sf_B)");
    check_field_offset(lv, v1, 0, "L_Sf_B.v1");
    check_field_offset(lv, v2, 8, "L_Sf_B.v2");
    check_field_offset(lv, v3, 9, "L_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vL_Sf_B(Test_L_Sf_B, "L_Sf_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  S_B_Sf  {
  short v1;
  bool v2;
  ::empty v3;
};
//SIG(1 S_B_Sf) C1{ Fs Fc FC2{}}



static void Test_S_B_Sf()
{
  {
    init_simple_test("S_B_Sf");
    S_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(S_B_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(S_B_Sf)");
    check_field_offset(lv, v1, 0, "S_B_Sf.v1");
    check_field_offset(lv, v2, 2, "S_B_Sf.v2");
    check_field_offset(lv, v3, 3, "S_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vS_B_Sf(Test_S_B_Sf, "S_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  S_Sf_B  {
  short v1;
  ::empty v2;
  bool v3;
};
//SIG(1 S_Sf_B) C1{ Fs FC2{} Fc}



static void Test_S_Sf_B()
{
  {
    init_simple_test("S_Sf_B");
    S_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(S_Sf_B)");
    check2(__alignof__(lv), 2, "__alignof__(S_Sf_B)");
    check_field_offset(lv, v1, 0, "S_Sf_B.v1");
    check_field_offset(lv, v2, 2, "S_Sf_B.v2");
    check_field_offset(lv, v3, 3, "S_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vS_Sf_B(Test_S_Sf_B, "S_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B  {
  ::empty v1;
  bool v2;
};
//SIG(1 Sf_B) C1{ FC2{} Fc}



static void Test_Sf_B()
{
  {
    init_simple_test("Sf_B");
    Sf_B lv;
    check2(sizeof(lv), 2, "sizeof(Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B)");
    check_field_offset(lv, v1, 0, "Sf_B.v1");
    check_field_offset(lv, v2, 1, "Sf_B.v2");
  }
}
static Arrange_To_Call_Me vSf_B(Test_Sf_B, "Sf_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_B  {
  ::empty v1;
  bool v2;
  bool v3;
};
//SIG(1 Sf_B_B) C1{ FC2{} Fc[2]}



static void Test_Sf_B_B()
{
  {
    init_simple_test("Sf_B_B");
    Sf_B_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_B)");
    check_field_offset(lv, v1, 0, "Sf_B_B.v1");
    check_field_offset(lv, v2, 1, "Sf_B_B.v2");
    check_field_offset(lv, v3, 2, "Sf_B_B.v3");
  }
}
static Arrange_To_Call_Me vSf_B_B(Test_Sf_B_B, "Sf_B_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu15i  {
  ::empty v1;
  bool v2;
  unsigned int v3:15;
};
//SIG(1 Sf_B_BFu15i) C1{ FC2{} Fc Fi:15}



static void Test_Sf_B_BFu15i()
{
  {
    init_simple_test("Sf_B_BFu15i");
    static Sf_B_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_B_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu15i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu15i.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Sf_B_BFu15i");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Sf_B_BFu15i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu15i(Test_Sf_B_BFu15i, "Sf_B_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu15ll  {
  ::empty v1;
  bool v2;
  __tsu64 v3:15;
};
//SIG(1 Sf_B_BFu15ll) C1{ FC2{} Fc FL:15}



static void Test_Sf_B_BFu15ll()
{
  {
    init_simple_test("Sf_B_BFu15ll");
    static Sf_B_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_B_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu15ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu15ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Sf_B_BFu15ll");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Sf_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu15ll(Test_Sf_B_BFu15ll, "Sf_B_BFu15ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu15s  {
  ::empty v1;
  bool v2;
  unsigned short v3:15;
};
//SIG(1 Sf_B_BFu15s) C1{ FC2{} Fc Fs:15}



static void Test_Sf_B_BFu15s()
{
  {
    init_simple_test("Sf_B_BFu15s");
    static Sf_B_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu15s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_B_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu15s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu15s.v2");
    set_bf_and_test(lv, v3, 2, 0, 15, 1, "Sf_B_BFu15s");
    set_bf_and_test(lv, v3, 2, 0, 15, hide_ull(1LL<<14), "Sf_B_BFu15s");
  }
}
static Arrange_To_Call_Me vSf_B_BFu15s(Test_Sf_B_BFu15s, "Sf_B_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu16i  {
  ::empty v1;
  bool v2;
  unsigned int v3:16;
};
//SIG(1 Sf_B_BFu16i) C1{ FC2{} Fc Fi:16}



static void Test_Sf_B_BFu16i()
{
  {
    init_simple_test("Sf_B_BFu16i");
    static Sf_B_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_B_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu16i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu16i.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Sf_B_BFu16i");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Sf_B_BFu16i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu16i(Test_Sf_B_BFu16i, "Sf_B_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu16ll  {
  ::empty v1;
  bool v2;
  __tsu64 v3:16;
};
//SIG(1 Sf_B_BFu16ll) C1{ FC2{} Fc FL:16}



static void Test_Sf_B_BFu16ll()
{
  {
    init_simple_test("Sf_B_BFu16ll");
    static Sf_B_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_B_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu16ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu16ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Sf_B_BFu16ll");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Sf_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu16ll(Test_Sf_B_BFu16ll, "Sf_B_BFu16ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu16s  {
  ::empty v1;
  bool v2;
  unsigned short v3:16;
};
//SIG(1 Sf_B_BFu16s) C1{ FC2{} Fc Fs:16}



static void Test_Sf_B_BFu16s()
{
  {
    init_simple_test("Sf_B_BFu16s");
    static Sf_B_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu16s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_B_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu16s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu16s.v2");
    set_bf_and_test(lv, v3, 2, 0, 16, 1, "Sf_B_BFu16s");
    set_bf_and_test(lv, v3, 2, 0, 16, hide_ull(1LL<<15), "Sf_B_BFu16s");
  }
}
static Arrange_To_Call_Me vSf_B_BFu16s(Test_Sf_B_BFu16s, "Sf_B_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu17i  {
  ::empty v1;
  bool v2;
  unsigned int v3:17;
};
//SIG(1 Sf_B_BFu17i) C1{ FC2{} Fc Fi:17}



static void Test_Sf_B_BFu17i()
{
  {
    init_simple_test("Sf_B_BFu17i");
    static Sf_B_BFu17i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_B_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_B_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu17i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu17i.v2");
    set_bf_and_test(lv, v3, 4, 0, 17, 1, "Sf_B_BFu17i");
    set_bf_and_test(lv, v3, 4, 0, 17, hide_ull(1LL<<16), "Sf_B_BFu17i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu17i(Test_Sf_B_BFu17i, "Sf_B_BFu17i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu17ll  {
  ::empty v1;
  bool v2;
  __tsu64 v3:17;
};
//SIG(1 Sf_B_BFu17ll) C1{ FC2{} Fc FL:17}



static void Test_Sf_B_BFu17ll()
{
  {
    init_simple_test("Sf_B_BFu17ll");
    static Sf_B_BFu17ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_B_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu17ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu17ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 17, 1, "Sf_B_BFu17ll");
    set_bf_and_test(lv, v3, 2, 0, 17, hide_ull(1LL<<16), "Sf_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu17ll(Test_Sf_B_BFu17ll, "Sf_B_BFu17ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu1c  {
  ::empty v1;
  bool v2;
  unsigned char v3:1;
};
//SIG(1 Sf_B_BFu1c) C1{ FC2{} Fc Fc:1}



static void Test_Sf_B_BFu1c()
{
  {
    init_simple_test("Sf_B_BFu1c");
    static Sf_B_BFu1c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu1c.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu1c.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_B_BFu1c");
  }
}
static Arrange_To_Call_Me vSf_B_BFu1c(Test_Sf_B_BFu1c, "Sf_B_BFu1c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu1i  {
  ::empty v1;
  bool v2;
  unsigned int v3:1;
};
//SIG(1 Sf_B_BFu1i) C1{ FC2{} Fc Fi:1}



static void Test_Sf_B_BFu1i()
{
  {
    init_simple_test("Sf_B_BFu1i");
    static Sf_B_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_B_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu1i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu1i.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_B_BFu1i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu1i(Test_Sf_B_BFu1i, "Sf_B_BFu1i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu1ll  {
  ::empty v1;
  bool v2;
  __tsu64 v3:1;
};
//SIG(1 Sf_B_BFu1ll) C1{ FC2{} Fc FL:1}



static void Test_Sf_B_BFu1ll()
{
  {
    init_simple_test("Sf_B_BFu1ll");
    static Sf_B_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_B_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu1ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu1ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu1ll(Test_Sf_B_BFu1ll, "Sf_B_BFu1ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu1s  {
  ::empty v1;
  bool v2;
  unsigned short v3:1;
};
//SIG(1 Sf_B_BFu1s) C1{ FC2{} Fc Fs:1}



static void Test_Sf_B_BFu1s()
{
  {
    init_simple_test("Sf_B_BFu1s");
    static Sf_B_BFu1s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu1s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_B_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu1s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu1s.v2");
    set_bf_and_test(lv, v3, 2, 0, 1, 1, "Sf_B_BFu1s");
  }
}
static Arrange_To_Call_Me vSf_B_BFu1s(Test_Sf_B_BFu1s, "Sf_B_BFu1s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu31i  {
  ::empty v1;
  bool v2;
  unsigned int v3:31;
};
//SIG(1 Sf_B_BFu31i) C1{ FC2{} Fc Fi:31}



static void Test_Sf_B_BFu31i()
{
  {
    init_simple_test("Sf_B_BFu31i");
    static Sf_B_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_B_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_B_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu31i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu31i.v2");
    set_bf_and_test(lv, v3, 4, 0, 31, 1, "Sf_B_BFu31i");
    set_bf_and_test(lv, v3, 4, 0, 31, hide_ull(1LL<<30), "Sf_B_BFu31i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu31i(Test_Sf_B_BFu31i, "Sf_B_BFu31i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu31ll  {
  ::empty v1;
  bool v2;
  __tsu64 v3:31;
};
//SIG(1 Sf_B_BFu31ll) C1{ FC2{} Fc FL:31}



static void Test_Sf_B_BFu31ll()
{
  {
    init_simple_test("Sf_B_BFu31ll");
    static Sf_B_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_B_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu31ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu31ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 31, 1, "Sf_B_BFu31ll");
    set_bf_and_test(lv, v3, 2, 0, 31, hide_ull(1LL<<30), "Sf_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu31ll(Test_Sf_B_BFu31ll, "Sf_B_BFu31ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu32i  {
  ::empty v1;
  bool v2;
  unsigned int v3:32;
};
//SIG(1 Sf_B_BFu32i) C1{ FC2{} Fc Fi:32}



static void Test_Sf_B_BFu32i()
{
  {
    init_simple_test("Sf_B_BFu32i");
    static Sf_B_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_B_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_B_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu32i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu32i.v2");
    set_bf_and_test(lv, v3, 4, 0, 32, 1, "Sf_B_BFu32i");
    set_bf_and_test(lv, v3, 4, 0, 32, hide_ull(1LL<<31), "Sf_B_BFu32i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu32i(Test_Sf_B_BFu32i, "Sf_B_BFu32i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu32ll  {
  ::empty v1;
  bool v2;
  __tsu64 v3:32;
};
//SIG(1 Sf_B_BFu32ll) C1{ FC2{} Fc FL:32}



static void Test_Sf_B_BFu32ll()
{
  {
    init_simple_test("Sf_B_BFu32ll");
    static Sf_B_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_B_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu32ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu32ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 32, 1, "Sf_B_BFu32ll");
    set_bf_and_test(lv, v3, 2, 0, 32, hide_ull(1LL<<31), "Sf_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu32ll(Test_Sf_B_BFu32ll, "Sf_B_BFu32ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu33  {
  ::empty v1;
  bool v2;
  __tsu64 v3:33;
};
//SIG(1 Sf_B_BFu33) C1{ FC2{} Fc FL:33}



static void Test_Sf_B_BFu33()
{
  {
    init_simple_test("Sf_B_BFu33");
    static Sf_B_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(Sf_B_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu33.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu33.v2");
    set_bf_and_test(lv, v3, 2, 0, 33, 1, "Sf_B_BFu33");
    set_bf_and_test(lv, v3, 2, 0, 33, hide_ull(1LL<<32), "Sf_B_BFu33");
  }
}
static Arrange_To_Call_Me vSf_B_BFu33(Test_Sf_B_BFu33, "Sf_B_BFu33", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu7c  {
  ::empty v1;
  bool v2;
  unsigned char v3:7;
};
//SIG(1 Sf_B_BFu7c) C1{ FC2{} Fc Fc:7}



static void Test_Sf_B_BFu7c()
{
  {
    init_simple_test("Sf_B_BFu7c");
    static Sf_B_BFu7c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu7c.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu7c.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_B_BFu7c");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_B_BFu7c");
  }
}
static Arrange_To_Call_Me vSf_B_BFu7c(Test_Sf_B_BFu7c, "Sf_B_BFu7c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu7i  {
  ::empty v1;
  bool v2;
  unsigned int v3:7;
};
//SIG(1 Sf_B_BFu7i) C1{ FC2{} Fc Fi:7}



static void Test_Sf_B_BFu7i()
{
  {
    init_simple_test("Sf_B_BFu7i");
    static Sf_B_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_B_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu7i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu7i.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_B_BFu7i");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_B_BFu7i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu7i(Test_Sf_B_BFu7i, "Sf_B_BFu7i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu7ll  {
  ::empty v1;
  bool v2;
  __tsu64 v3:7;
};
//SIG(1 Sf_B_BFu7ll) C1{ FC2{} Fc FL:7}



static void Test_Sf_B_BFu7ll()
{
  {
    init_simple_test("Sf_B_BFu7ll");
    static Sf_B_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_B_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu7ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu7ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_B_BFu7ll");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu7ll(Test_Sf_B_BFu7ll, "Sf_B_BFu7ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu7s  {
  ::empty v1;
  bool v2;
  unsigned short v3:7;
};
//SIG(1 Sf_B_BFu7s) C1{ FC2{} Fc Fs:7}



static void Test_Sf_B_BFu7s()
{
  {
    init_simple_test("Sf_B_BFu7s");
    static Sf_B_BFu7s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu7s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_B_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu7s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu7s.v2");
    set_bf_and_test(lv, v3, 2, 0, 7, 1, "Sf_B_BFu7s");
    set_bf_and_test(lv, v3, 2, 0, 7, hide_ull(1LL<<6), "Sf_B_BFu7s");
  }
}
static Arrange_To_Call_Me vSf_B_BFu7s(Test_Sf_B_BFu7s, "Sf_B_BFu7s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu8c  {
  ::empty v1;
  bool v2;
  unsigned char v3:8;
};
//SIG(1 Sf_B_BFu8c) C1{ FC2{} Fc Fc:8}



static void Test_Sf_B_BFu8c()
{
  {
    init_simple_test("Sf_B_BFu8c");
    static Sf_B_BFu8c lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu8c.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu8c.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_B_BFu8c");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_B_BFu8c");
  }
}
static Arrange_To_Call_Me vSf_B_BFu8c(Test_Sf_B_BFu8c, "Sf_B_BFu8c", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu8i  {
  ::empty v1;
  bool v2;
  unsigned int v3:8;
};
//SIG(1 Sf_B_BFu8i) C1{ FC2{} Fc Fi:8}



static void Test_Sf_B_BFu8i()
{
  {
    init_simple_test("Sf_B_BFu8i");
    static Sf_B_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_B_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu8i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu8i.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_B_BFu8i");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_B_BFu8i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu8i(Test_Sf_B_BFu8i, "Sf_B_BFu8i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu8ll  {
  ::empty v1;
  bool v2;
  __tsu64 v3:8;
};
//SIG(1 Sf_B_BFu8ll) C1{ FC2{} Fc FL:8}



static void Test_Sf_B_BFu8ll()
{
  {
    init_simple_test("Sf_B_BFu8ll");
    static Sf_B_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_B_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu8ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu8ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_B_BFu8ll");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu8ll(Test_Sf_B_BFu8ll, "Sf_B_BFu8ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu8s  {
  ::empty v1;
  bool v2;
  unsigned short v3:8;
};
//SIG(1 Sf_B_BFu8s) C1{ FC2{} Fc Fs:8}



static void Test_Sf_B_BFu8s()
{
  {
    init_simple_test("Sf_B_BFu8s");
    static Sf_B_BFu8s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu8s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_B_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu8s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu8s.v2");
    set_bf_and_test(lv, v3, 2, 0, 8, 1, "Sf_B_BFu8s");
    set_bf_and_test(lv, v3, 2, 0, 8, hide_ull(1LL<<7), "Sf_B_BFu8s");
  }
}
static Arrange_To_Call_Me vSf_B_BFu8s(Test_Sf_B_BFu8s, "Sf_B_BFu8s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu9i  {
  ::empty v1;
  bool v2;
  unsigned int v3:9;
};
//SIG(1 Sf_B_BFu9i) C1{ FC2{} Fc Fi:9}



static void Test_Sf_B_BFu9i()
{
  {
    init_simple_test("Sf_B_BFu9i");
    static Sf_B_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_B_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu9i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu9i.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Sf_B_BFu9i");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Sf_B_BFu9i");
  }
}
static Arrange_To_Call_Me vSf_B_BFu9i(Test_Sf_B_BFu9i, "Sf_B_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu9ll  {
  ::empty v1;
  bool v2;
  __tsu64 v3:9;
};
//SIG(1 Sf_B_BFu9ll) C1{ FC2{} Fc FL:9}



static void Test_Sf_B_BFu9ll()
{
  {
    init_simple_test("Sf_B_BFu9ll");
    static Sf_B_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_B_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu9ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu9ll.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Sf_B_BFu9ll");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Sf_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vSf_B_BFu9ll(Test_Sf_B_BFu9ll, "Sf_B_BFu9ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu9s  {
  ::empty v1;
  bool v2;
  unsigned short v3:9;
};
//SIG(1 Sf_B_BFu9s) C1{ FC2{} Fc Fs:9}



static void Test_Sf_B_BFu9s()
{
  {
    init_simple_test("Sf_B_BFu9s");
    static Sf_B_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu9s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_B_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu9s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu9s.v2");
    set_bf_and_test(lv, v3, 2, 0, 9, 1, "Sf_B_BFu9s");
    set_bf_and_test(lv, v3, 2, 0, 9, hide_ull(1LL<<8), "Sf_B_BFu9s");
  }
}
static Arrange_To_Call_Me vSf_B_BFu9s(Test_Sf_B_BFu9s, "Sf_B_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_C  {
  ::empty v1;
  bool v2;
  char v3;
};
//SIG(1 Sf_B_C) C1{ FC2{} Fc[2]}



static void Test_Sf_B_C()
{
  {
    init_simple_test("Sf_B_C");
    Sf_B_C lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_C)");
    check_field_offset(lv, v1, 0, "Sf_B_C.v1");
    check_field_offset(lv, v2, 1, "Sf_B_C.v2");
    check_field_offset(lv, v3, 2, "Sf_B_C.v3");
  }
}
static Arrange_To_Call_Me vSf_B_C(Test_Sf_B_C, "Sf_B_C", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_D  {
  ::empty v1;
  bool v2;
  double v3;
};
//SIG(1 Sf_B_D) C1{ FC2{} Fc FL}



static void Test_Sf_B_D()
{
  {
    init_simple_test("Sf_B_D");
    Sf_B_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_B_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_D)");
    check_field_offset(lv, v1, 0, "Sf_B_D.v1");
    check_field_offset(lv, v2, 1, "Sf_B_D.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_B_D.v3");
  }
}
static Arrange_To_Call_Me vSf_B_D(Test_Sf_B_D, "Sf_B_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_F  {
  ::empty v1;
  bool v2;
  float v3;
};
//SIG(1 Sf_B_F) C1{ FC2{} Fc Fi}



static void Test_Sf_B_F()
{
  {
    init_simple_test("Sf_B_F");
    Sf_B_F lv;
    check2(sizeof(lv), 8, "sizeof(Sf_B_F)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_B_F)");
    check_field_offset(lv, v1, 0, "Sf_B_F.v1");
    check_field_offset(lv, v2, 1, "Sf_B_F.v2");
    check_field_offset(lv, v3, 4, "Sf_B_F.v3");
  }
}
static Arrange_To_Call_Me vSf_B_F(Test_Sf_B_F, "Sf_B_F", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_I  {
  ::empty v1;
  bool v2;
  int v3;
};
//SIG(1 Sf_B_I) C1{ FC2{} Fc Fi}



static void Test_Sf_B_I()
{
  {
    init_simple_test("Sf_B_I");
    Sf_B_I lv;
    check2(sizeof(lv), 8, "sizeof(Sf_B_I)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_B_I)");
    check_field_offset(lv, v1, 0, "Sf_B_I.v1");
    check_field_offset(lv, v2, 1, "Sf_B_I.v2");
    check_field_offset(lv, v3, 4, "Sf_B_I.v3");
  }
}
static Arrange_To_Call_Me vSf_B_I(Test_Sf_B_I, "Sf_B_I", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_Ip  {
  ::empty v1;
  bool v2;
  int *v3;
};
//SIG(1 Sf_B_Ip) C1{ FC2{} Fc Fp}



static void Test_Sf_B_Ip()
{
  {
    init_simple_test("Sf_B_Ip");
    Sf_B_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Sf_B_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_Ip)");
    check_field_offset(lv, v1, 0, "Sf_B_Ip.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_B_Ip.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Ip(Test_Sf_B_Ip, "Sf_B_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_L  {
  ::empty v1;
  bool v2;
  __tsi64 v3;
};
//SIG(1 Sf_B_L) C1{ FC2{} Fc FL}



static void Test_Sf_B_L()
{
  {
    init_simple_test("Sf_B_L");
    Sf_B_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_B_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_L)");
    check_field_offset(lv, v1, 0, "Sf_B_L.v1");
    check_field_offset(lv, v2, 1, "Sf_B_L.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_B_L.v3");
  }
}
static Arrange_To_Call_Me vSf_B_L(Test_Sf_B_L, "Sf_B_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_S  {
  ::empty v1;
  bool v2;
  short v3;
};
//SIG(1 Sf_B_S) C1{ FC2{} Fc Fs}



static void Test_Sf_B_S()
{
  {
    init_simple_test("Sf_B_S");
    Sf_B_S lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_S)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_B_S)");
    check_field_offset(lv, v1, 0, "Sf_B_S.v1");
    check_field_offset(lv, v2, 1, "Sf_B_S.v2");
    check_field_offset(lv, v3, 2, "Sf_B_S.v3");
  }
}
static Arrange_To_Call_Me vSf_B_S(Test_Sf_B_S, "Sf_B_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_Sf  {
  ::empty v1;
  bool v2;
  ::empty v3;
};
//SIG(1 Sf_B_Sf) C1{ FC2{} Fc FC2}



static void Test_Sf_B_Sf()
{
  {
    init_simple_test("Sf_B_Sf");
    Sf_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_Sf)");
    check_field_offset(lv, v1, 0, "Sf_B_Sf.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Sf.v2");
    check_field_offset(lv, v3, 2, "Sf_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Sf(Test_Sf_B_Sf, "Sf_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_Uc  {
  ::empty v1;
  bool v2;
  unsigned char v3;
};
//SIG(1 Sf_B_Uc) C1{ FC2{} Fc[2]}



static void Test_Sf_B_Uc()
{
  {
    init_simple_test("Sf_B_Uc");
    Sf_B_Uc lv;
    check2(sizeof(lv), 3, "sizeof(Sf_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_Uc)");
    check_field_offset(lv, v1, 0, "Sf_B_Uc.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Uc.v2");
    check_field_offset(lv, v3, 2, "Sf_B_Uc.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Uc(Test_Sf_B_Uc, "Sf_B_Uc", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_Ui  {
  ::empty v1;
  bool v2;
  unsigned int v3;
};
//SIG(1 Sf_B_Ui) C1{ FC2{} Fc Fi}



static void Test_Sf_B_Ui()
{
  {
    init_simple_test("Sf_B_Ui");
    Sf_B_Ui lv;
    check2(sizeof(lv), 8, "sizeof(Sf_B_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_B_Ui)");
    check_field_offset(lv, v1, 0, "Sf_B_Ui.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Ui.v2");
    check_field_offset(lv, v3, 4, "Sf_B_Ui.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Ui(Test_Sf_B_Ui, "Sf_B_Ui", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_Ul  {
  ::empty v1;
  bool v2;
  __tsu64 v3;
};
//SIG(1 Sf_B_Ul) C1{ FC2{} Fc FL}



static void Test_Sf_B_Ul()
{
  {
    init_simple_test("Sf_B_Ul");
    Sf_B_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Sf_B_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_Ul)");
    check_field_offset(lv, v1, 0, "Sf_B_Ul.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_B_Ul.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Ul(Test_Sf_B_Ul, "Sf_B_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_Us  {
  ::empty v1;
  bool v2;
  unsigned short v3;
};
//SIG(1 Sf_B_Us) C1{ FC2{} Fc Fs}



static void Test_Sf_B_Us()
{
  {
    init_simple_test("Sf_B_Us");
    Sf_B_Us lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_Us)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_B_Us)");
    check_field_offset(lv, v1, 0, "Sf_B_Us.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Us.v2");
    check_field_offset(lv, v3, 2, "Sf_B_Us.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Us(Test_Sf_B_Us, "Sf_B_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_Vp  {
  ::empty v1;
  bool v2;
  void *v3;
};
//SIG(1 Sf_B_Vp) C1{ FC2{} Fc Fp}



static void Test_Sf_B_Vp()
{
  {
    init_simple_test("Sf_B_Vp");
    Sf_B_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Sf_B_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_B_Vp)");
    check_field_offset(lv, v1, 0, "Sf_B_Vp.v1");
    check_field_offset(lv, v2, 1, "Sf_B_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(8,4), "Sf_B_Vp.v3");
  }
}
static Arrange_To_Call_Me vSf_B_Vp(Test_Sf_B_Vp, "Sf_B_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu15i_B  {
  ::empty v1;
  unsigned int v2:15;
  bool v3;
};
//SIG(1 Sf_BFu15i_B) C1{ FC2{} Fi:15 Fc}



static void Test_Sf_BFu15i_B()
{
  {
    init_simple_test("Sf_BFu15i_B");
    static Sf_BFu15i_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu15i_B)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu15i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu15i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "Sf_BFu15i_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "Sf_BFu15i_B");
    check_field_offset(lv, v3, 3, "Sf_BFu15i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu15i_B(Test_Sf_BFu15i_B, "Sf_BFu15i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu15ll_B  {
  ::empty v1;
  __tsu64 v2:15;
  bool v3;
};
//SIG(1 Sf_BFu15ll_B) C1{ FC2{} FL:15 Fc}



static void Test_Sf_BFu15ll_B()
{
  {
    init_simple_test("Sf_BFu15ll_B");
    static Sf_BFu15ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu15ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu15ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu15ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "Sf_BFu15ll_B");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "Sf_BFu15ll_B");
    check_field_offset(lv, v3, 3, "Sf_BFu15ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu15ll_B(Test_Sf_BFu15ll_B, "Sf_BFu15ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu15s_B  {
  ::empty v1;
  unsigned short v2:15;
  bool v3;
};
//SIG(1 Sf_BFu15s_B) C1{ FC2{} Fs:15 Fc}



static void Test_Sf_BFu15s_B()
{
  {
    init_simple_test("Sf_BFu15s_B");
    static Sf_BFu15s_B lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu15s_B)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu15s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu15s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "Sf_BFu15s_B");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "Sf_BFu15s_B");
    check_field_offset(lv, v3, 4, "Sf_BFu15s_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu15s_B(Test_Sf_BFu15s_B, "Sf_BFu15s_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu16i_B  {
  ::empty v1;
  unsigned int v2:16;
  bool v3;
};
//SIG(1 Sf_BFu16i_B) C1{ FC2{} Fi:16 Fc}



static void Test_Sf_BFu16i_B()
{
  {
    init_simple_test("Sf_BFu16i_B");
    static Sf_BFu16i_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu16i_B)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu16i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu16i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "Sf_BFu16i_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "Sf_BFu16i_B");
    check_field_offset(lv, v3, 3, "Sf_BFu16i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu16i_B(Test_Sf_BFu16i_B, "Sf_BFu16i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu16ll_B  {
  ::empty v1;
  __tsu64 v2:16;
  bool v3;
};
//SIG(1 Sf_BFu16ll_B) C1{ FC2{} FL:16 Fc}



static void Test_Sf_BFu16ll_B()
{
  {
    init_simple_test("Sf_BFu16ll_B");
    static Sf_BFu16ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu16ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu16ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu16ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "Sf_BFu16ll_B");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "Sf_BFu16ll_B");
    check_field_offset(lv, v3, 3, "Sf_BFu16ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu16ll_B(Test_Sf_BFu16ll_B, "Sf_BFu16ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu16s_B  {
  ::empty v1;
  unsigned short v2:16;
  bool v3;
};
//SIG(1 Sf_BFu16s_B) C1{ FC2{} Fs:16 Fc}



static void Test_Sf_BFu16s_B()
{
  {
    init_simple_test("Sf_BFu16s_B");
    static Sf_BFu16s_B lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu16s_B)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu16s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu16s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "Sf_BFu16s_B");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "Sf_BFu16s_B");
    check_field_offset(lv, v3, 4, "Sf_BFu16s_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu16s_B(Test_Sf_BFu16s_B, "Sf_BFu16s_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu17i_B  {
  ::empty v1;
  unsigned int v2:17;
  bool v3;
};
//SIG(1 Sf_BFu17i_B) C1{ FC2{} Fi:17 Fc}



static void Test_Sf_BFu17i_B()
{
  {
    init_simple_test("Sf_BFu17i_B");
    static Sf_BFu17i_B lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu17i_B)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu17i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu17i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "Sf_BFu17i_B");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "Sf_BFu17i_B");
    check_field_offset(lv, v3, 4, "Sf_BFu17i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu17i_B(Test_Sf_BFu17i_B, "Sf_BFu17i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu17ll_B  {
  ::empty v1;
  __tsu64 v2:17;
  bool v3;
};
//SIG(1 Sf_BFu17ll_B) C1{ FC2{} FL:17 Fc}



static void Test_Sf_BFu17ll_B()
{
  {
    init_simple_test("Sf_BFu17ll_B");
    static Sf_BFu17ll_B lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu17ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu17ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu17ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "Sf_BFu17ll_B");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "Sf_BFu17ll_B");
    check_field_offset(lv, v3, 4, "Sf_BFu17ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu17ll_B(Test_Sf_BFu17ll_B, "Sf_BFu17ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu1c_B  {
  ::empty v1;
  unsigned char v2:1;
  bool v3;
};
//SIG(1 Sf_BFu1c_B) C1{ FC2{} Fc:1 Fc}



static void Test_Sf_BFu1c_B()
{
  {
    init_simple_test("Sf_BFu1c_B");
    static Sf_BFu1c_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu1c_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu1c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Sf_BFu1c_B");
    check_field_offset(lv, v3, 2, "Sf_BFu1c_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu1c_B(Test_Sf_BFu1c_B, "Sf_BFu1c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu1i_B  {
  ::empty v1;
  unsigned int v2:1;
  bool v3;
};
//SIG(1 Sf_BFu1i_B) C1{ FC2{} Fi:1 Fc}



static void Test_Sf_BFu1i_B()
{
  {
    init_simple_test("Sf_BFu1i_B");
    static Sf_BFu1i_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu1i_B)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu1i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu1i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Sf_BFu1i_B");
    check_field_offset(lv, v3, 2, "Sf_BFu1i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu1i_B(Test_Sf_BFu1i_B, "Sf_BFu1i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu1ll_B  {
  ::empty v1;
  __tsu64 v2:1;
  bool v3;
};
//SIG(1 Sf_BFu1ll_B) C1{ FC2{} FL:1 Fc}



static void Test_Sf_BFu1ll_B()
{
  {
    init_simple_test("Sf_BFu1ll_B");
    static Sf_BFu1ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu1ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu1ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu1ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Sf_BFu1ll_B");
    check_field_offset(lv, v3, 2, "Sf_BFu1ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu1ll_B(Test_Sf_BFu1ll_B, "Sf_BFu1ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu1s_B  {
  ::empty v1;
  unsigned short v2:1;
  bool v3;
};
//SIG(1 Sf_BFu1s_B) C1{ FC2{} Fs:1 Fc}



static void Test_Sf_BFu1s_B()
{
  {
    init_simple_test("Sf_BFu1s_B");
    static Sf_BFu1s_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu1s_B)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu1s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu1s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "Sf_BFu1s_B");
    check_field_offset(lv, v3, 2, "Sf_BFu1s_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu1s_B(Test_Sf_BFu1s_B, "Sf_BFu1s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu31i_B  {
  ::empty v1;
  unsigned int v2:31;
  bool v3;
};
//SIG(1 Sf_BFu31i_B) C1{ FC2{} Fi:31 Fc}



static void Test_Sf_BFu31i_B()
{
  {
    init_simple_test("Sf_BFu31i_B");
    static Sf_BFu31i_B lv;
    check2(sizeof(lv), 12, "sizeof(Sf_BFu31i_B)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu31i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu31i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "Sf_BFu31i_B");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "Sf_BFu31i_B");
    check_field_offset(lv, v3, 8, "Sf_BFu31i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu31i_B(Test_Sf_BFu31i_B, "Sf_BFu31i_B", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu31ll_B  {
  ::empty v1;
  __tsu64 v2:31;
  bool v3;
};
//SIG(1 Sf_BFu31ll_B) C1{ FC2{} FL:31 Fc}



static void Test_Sf_BFu31ll_B()
{
  {
    init_simple_test("Sf_BFu31ll_B");
    static Sf_BFu31ll_B lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu31ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu31ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu31ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "Sf_BFu31ll_B");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "Sf_BFu31ll_B");
    check_field_offset(lv, v3, 5, "Sf_BFu31ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu31ll_B(Test_Sf_BFu31ll_B, "Sf_BFu31ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu32i_B  {
  ::empty v1;
  unsigned int v2:32;
  bool v3;
};
//SIG(1 Sf_BFu32i_B) C1{ FC2{} Fi:32 Fc}



static void Test_Sf_BFu32i_B()
{
  {
    init_simple_test("Sf_BFu32i_B");
    static Sf_BFu32i_B lv;
    check2(sizeof(lv), 12, "sizeof(Sf_BFu32i_B)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu32i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu32i_B.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "Sf_BFu32i_B");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "Sf_BFu32i_B");
    check_field_offset(lv, v3, 8, "Sf_BFu32i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu32i_B(Test_Sf_BFu32i_B, "Sf_BFu32i_B", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu32ll_B  {
  ::empty v1;
  __tsu64 v2:32;
  bool v3;
};
//SIG(1 Sf_BFu32ll_B) C1{ FC2{} FL:32 Fc}



static void Test_Sf_BFu32ll_B()
{
  {
    init_simple_test("Sf_BFu32ll_B");
    static Sf_BFu32ll_B lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu32ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu32ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu32ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "Sf_BFu32ll_B");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "Sf_BFu32ll_B");
    check_field_offset(lv, v3, 5, "Sf_BFu32ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu32ll_B(Test_Sf_BFu32ll_B, "Sf_BFu32ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu33_B  {
  ::empty v1;
  __tsu64 v2:33;
  bool v3;
};
//SIG(1 Sf_BFu33_B) C1{ FC2{} FL:33 Fc}



static void Test_Sf_BFu33_B()
{
  {
    init_simple_test("Sf_BFu33_B");
    static Sf_BFu33_B lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu33_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu33_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu33_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "Sf_BFu33_B");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "Sf_BFu33_B");
    check_field_offset(lv, v3, 6, "Sf_BFu33_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu33_B(Test_Sf_BFu33_B, "Sf_BFu33_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu7c_B  {
  ::empty v1;
  unsigned char v2:7;
  bool v3;
};
//SIG(1 Sf_BFu7c_B) C1{ FC2{} Fc:7 Fc}



static void Test_Sf_BFu7c_B()
{
  {
    init_simple_test("Sf_BFu7c_B");
    static Sf_BFu7c_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu7c_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu7c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Sf_BFu7c_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Sf_BFu7c_B");
    check_field_offset(lv, v3, 2, "Sf_BFu7c_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu7c_B(Test_Sf_BFu7c_B, "Sf_BFu7c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu7i_B  {
  ::empty v1;
  unsigned int v2:7;
  bool v3;
};
//SIG(1 Sf_BFu7i_B) C1{ FC2{} Fi:7 Fc}



static void Test_Sf_BFu7i_B()
{
  {
    init_simple_test("Sf_BFu7i_B");
    static Sf_BFu7i_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu7i_B)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu7i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu7i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Sf_BFu7i_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Sf_BFu7i_B");
    check_field_offset(lv, v3, 2, "Sf_BFu7i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu7i_B(Test_Sf_BFu7i_B, "Sf_BFu7i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu7ll_B  {
  ::empty v1;
  __tsu64 v2:7;
  bool v3;
};
//SIG(1 Sf_BFu7ll_B) C1{ FC2{} FL:7 Fc}



static void Test_Sf_BFu7ll_B()
{
  {
    init_simple_test("Sf_BFu7ll_B");
    static Sf_BFu7ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu7ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu7ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu7ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Sf_BFu7ll_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Sf_BFu7ll_B");
    check_field_offset(lv, v3, 2, "Sf_BFu7ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu7ll_B(Test_Sf_BFu7ll_B, "Sf_BFu7ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu7s_B  {
  ::empty v1;
  unsigned short v2:7;
  bool v3;
};
//SIG(1 Sf_BFu7s_B) C1{ FC2{} Fs:7 Fc}



static void Test_Sf_BFu7s_B()
{
  {
    init_simple_test("Sf_BFu7s_B");
    static Sf_BFu7s_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu7s_B)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu7s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu7s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "Sf_BFu7s_B");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "Sf_BFu7s_B");
    check_field_offset(lv, v3, 2, "Sf_BFu7s_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu7s_B(Test_Sf_BFu7s_B, "Sf_BFu7s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu8c_B  {
  ::empty v1;
  unsigned char v2:8;
  bool v3;
};
//SIG(1 Sf_BFu8c_B) C1{ FC2{} Fc:8 Fc}



static void Test_Sf_BFu8c_B()
{
  {
    init_simple_test("Sf_BFu8c_B");
    static Sf_BFu8c_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu8c_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu8c_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Sf_BFu8c_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Sf_BFu8c_B");
    check_field_offset(lv, v3, 2, "Sf_BFu8c_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu8c_B(Test_Sf_BFu8c_B, "Sf_BFu8c_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu8i_B  {
  ::empty v1;
  unsigned int v2:8;
  bool v3;
};
//SIG(1 Sf_BFu8i_B) C1{ FC2{} Fi:8 Fc}



static void Test_Sf_BFu8i_B()
{
  {
    init_simple_test("Sf_BFu8i_B");
    static Sf_BFu8i_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu8i_B)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu8i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu8i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Sf_BFu8i_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Sf_BFu8i_B");
    check_field_offset(lv, v3, 2, "Sf_BFu8i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu8i_B(Test_Sf_BFu8i_B, "Sf_BFu8i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu8ll_B  {
  ::empty v1;
  __tsu64 v2:8;
  bool v3;
};
//SIG(1 Sf_BFu8ll_B) C1{ FC2{} FL:8 Fc}



static void Test_Sf_BFu8ll_B()
{
  {
    init_simple_test("Sf_BFu8ll_B");
    static Sf_BFu8ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu8ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu8ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu8ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Sf_BFu8ll_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Sf_BFu8ll_B");
    check_field_offset(lv, v3, 2, "Sf_BFu8ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu8ll_B(Test_Sf_BFu8ll_B, "Sf_BFu8ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu8s_B  {
  ::empty v1;
  unsigned short v2:8;
  bool v3;
};
//SIG(1 Sf_BFu8s_B) C1{ FC2{} Fs:8 Fc}



static void Test_Sf_BFu8s_B()
{
  {
    init_simple_test("Sf_BFu8s_B");
    static Sf_BFu8s_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu8s_B)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu8s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu8s_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "Sf_BFu8s_B");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "Sf_BFu8s_B");
    check_field_offset(lv, v3, 2, "Sf_BFu8s_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu8s_B(Test_Sf_BFu8s_B, "Sf_BFu8s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu9i_B  {
  ::empty v1;
  unsigned int v2:9;
  bool v3;
};
//SIG(1 Sf_BFu9i_B) C1{ FC2{} Fi:9 Fc}



static void Test_Sf_BFu9i_B()
{
  {
    init_simple_test("Sf_BFu9i_B");
    static Sf_BFu9i_B lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9i_B)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu9i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu9i_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "Sf_BFu9i_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "Sf_BFu9i_B");
    check_field_offset(lv, v3, 3, "Sf_BFu9i_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu9i_B(Test_Sf_BFu9i_B, "Sf_BFu9i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu9ll_B  {
  ::empty v1;
  __tsu64 v2:9;
  bool v3;
};
//SIG(1 Sf_BFu9ll_B) C1{ FC2{} FL:9 Fc}



static void Test_Sf_BFu9ll_B()
{
  {
    init_simple_test("Sf_BFu9ll_B");
    static Sf_BFu9ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu9ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu9ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_B.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "Sf_BFu9ll_B");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_B");
    check_field_offset(lv, v3, 3, "Sf_BFu9ll_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu9ll_B(Test_Sf_BFu9ll_B, "Sf_BFu9ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu9s_B  {
  ::empty v1;
  unsigned short v2:9;
  bool v3;
};
//SIG(1 Sf_BFu9s_B) C1{ FC2{} Fs:9 Fc}



static void Test_Sf_BFu9s_B()
{
  {
    init_simple_test("Sf_BFu9s_B");
    static Sf_BFu9s_B lv;
    check2(sizeof(lv), 6, "sizeof(Sf_BFu9s_B)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu9s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_B.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "Sf_BFu9s_B");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_B");
    check_field_offset(lv, v3, 4, "Sf_BFu9s_B.v3");
  }
}
static Arrange_To_Call_Me vSf_BFu9s_B(Test_Sf_BFu9s_B, "Sf_BFu9s_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_C_B  {
  ::empty v1;
  char v2;
  bool v3;
};
//SIG(1 Sf_C_B) C1{ FC2{} Fc[2]}



static void Test_Sf_C_B()
{
  {
    init_simple_test("Sf_C_B");
    Sf_C_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_B)");
    check_field_offset(lv, v1, 0, "Sf_C_B.v1");
    check_field_offset(lv, v2, 1, "Sf_C_B.v2");
    check_field_offset(lv, v3, 2, "Sf_C_B.v3");
  }
}
static Arrange_To_Call_Me vSf_C_B(Test_Sf_C_B, "Sf_C_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_D_B  {
  ::empty v1;
  double v2;
  bool v3;
};
//SIG(1 Sf_D_B) C1{ FC2{} FL Fc}



static void Test_Sf_D_B()
{
  {
    init_simple_test("Sf_D_B");
    Sf_D_B lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Sf_D_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_D_B)");
    check_field_offset(lv, v1, 0, "Sf_D_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Sf_D_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Sf_D_B.v3");
  }
}
static Arrange_To_Call_Me vSf_D_B(Test_Sf_D_B, "Sf_D_B", ABISELECT(24,16));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_F_B  {
  ::empty v1;
  float v2;
  bool v3;
};
//SIG(1 Sf_F_B) C1{ FC2{} Fi Fc}



static void Test_Sf_F_B()
{
  {
    init_simple_test("Sf_F_B");
    Sf_F_B lv;
    check2(sizeof(lv), 12, "sizeof(Sf_F_B)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_F_B)");
    check_field_offset(lv, v1, 0, "Sf_F_B.v1");
    check_field_offset(lv, v2, 4, "Sf_F_B.v2");
    check_field_offset(lv, v3, 8, "Sf_F_B.v3");
  }
}
static Arrange_To_Call_Me vSf_F_B(Test_Sf_F_B, "Sf_F_B", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_I_B  {
  ::empty v1;
  int v2;
  bool v3;
};
//SIG(1 Sf_I_B) C1{ FC2{} Fi Fc}



static void Test_Sf_I_B()
{
  {
    init_simple_test("Sf_I_B");
    Sf_I_B lv;
    check2(sizeof(lv), 12, "sizeof(Sf_I_B)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_I_B)");
    check_field_offset(lv, v1, 0, "Sf_I_B.v1");
    check_field_offset(lv, v2, 4, "Sf_I_B.v2");
    check_field_offset(lv, v3, 8, "Sf_I_B.v3");
  }
}
static Arrange_To_Call_Me vSf_I_B(Test_Sf_I_B, "Sf_I_B", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_Ip_B  {
  ::empty v1;
  int *v2;
  bool v3;
};
//SIG(1 Sf_Ip_B) C1{ FC2{} Fp Fc}



static void Test_Sf_Ip_B()
{
  {
    init_simple_test("Sf_Ip_B");
    Sf_Ip_B lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Sf_Ip_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Ip_B)");
    check_field_offset(lv, v1, 0, "Sf_Ip_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Sf_Ip_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Sf_Ip_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Ip_B(Test_Sf_Ip_B, "Sf_Ip_B", ABISELECT(24,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_L_B  {
  ::empty v1;
  __tsi64 v2;
  bool v3;
};
//SIG(1 Sf_L_B) C1{ FC2{} FL Fc}



static void Test_Sf_L_B()
{
  {
    init_simple_test("Sf_L_B");
    Sf_L_B lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Sf_L_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_L_B)");
    check_field_offset(lv, v1, 0, "Sf_L_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Sf_L_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Sf_L_B.v3");
  }
}
static Arrange_To_Call_Me vSf_L_B(Test_Sf_L_B, "Sf_L_B", ABISELECT(24,16));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_S_B  {
  ::empty v1;
  short v2;
  bool v3;
};
//SIG(1 Sf_S_B) C1{ FC2{} Fs Fc}



static void Test_Sf_S_B()
{
  {
    init_simple_test("Sf_S_B");
    Sf_S_B lv;
    check2(sizeof(lv), 6, "sizeof(Sf_S_B)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_S_B)");
    check_field_offset(lv, v1, 0, "Sf_S_B.v1");
    check_field_offset(lv, v2, 2, "Sf_S_B.v2");
    check_field_offset(lv, v3, 4, "Sf_S_B.v3");
  }
}
static Arrange_To_Call_Me vSf_S_B(Test_Sf_S_B, "Sf_S_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_Sf_B  {
  ::empty v1;
  ::empty v2;
  bool v3;
};
//SIG(1 Sf_Sf_B) C1{ FC2{} FC2 Fc}



static void Test_Sf_Sf_B()
{
  {
    init_simple_test("Sf_Sf_B");
    Sf_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_B)");
    check_field_offset(lv, v1, 0, "Sf_Sf_B.v1");
    check_field_offset(lv, v2, 1, "Sf_Sf_B.v2");
    check_field_offset(lv, v3, 2, "Sf_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Sf_B(Test_Sf_Sf_B, "Sf_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_Uc_B  {
  ::empty v1;
  unsigned char v2;
  bool v3;
};
//SIG(1 Sf_Uc_B) C1{ FC2{} Fc[2]}



static void Test_Sf_Uc_B()
{
  {
    init_simple_test("Sf_Uc_B");
    Sf_Uc_B lv;
    check2(sizeof(lv), 3, "sizeof(Sf_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_B)");
    check_field_offset(lv, v1, 0, "Sf_Uc_B.v1");
    check_field_offset(lv, v2, 1, "Sf_Uc_B.v2");
    check_field_offset(lv, v3, 2, "Sf_Uc_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Uc_B(Test_Sf_Uc_B, "Sf_Uc_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_Ui_B  {
  ::empty v1;
  unsigned int v2;
  bool v3;
};
//SIG(1 Sf_Ui_B) C1{ FC2{} Fi Fc}



static void Test_Sf_Ui_B()
{
  {
    init_simple_test("Sf_Ui_B");
    Sf_Ui_B lv;
    check2(sizeof(lv), 12, "sizeof(Sf_Ui_B)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_Ui_B)");
    check_field_offset(lv, v1, 0, "Sf_Ui_B.v1");
    check_field_offset(lv, v2, 4, "Sf_Ui_B.v2");
    check_field_offset(lv, v3, 8, "Sf_Ui_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Ui_B(Test_Sf_Ui_B, "Sf_Ui_B", 12);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_Ul_B  {
  ::empty v1;
  __tsu64 v2;
  bool v3;
};
//SIG(1 Sf_Ul_B) C1{ FC2{} FL Fc}



static void Test_Sf_Ul_B()
{
  {
    init_simple_test("Sf_Ul_B");
    Sf_Ul_B lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Sf_Ul_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Ul_B)");
    check_field_offset(lv, v1, 0, "Sf_Ul_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Sf_Ul_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Sf_Ul_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Ul_B(Test_Sf_Ul_B, "Sf_Ul_B", ABISELECT(24,16));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_Us_B  {
  ::empty v1;
  unsigned short v2;
  bool v3;
};
//SIG(1 Sf_Us_B) C1{ FC2{} Fs Fc}



static void Test_Sf_Us_B()
{
  {
    init_simple_test("Sf_Us_B");
    Sf_Us_B lv;
    check2(sizeof(lv), 6, "sizeof(Sf_Us_B)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_Us_B)");
    check_field_offset(lv, v1, 0, "Sf_Us_B.v1");
    check_field_offset(lv, v2, 2, "Sf_Us_B.v2");
    check_field_offset(lv, v3, 4, "Sf_Us_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Us_B(Test_Sf_Us_B, "Sf_Us_B", 6);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_Vp_B  {
  ::empty v1;
  void *v2;
  bool v3;
};
//SIG(1 Sf_Vp_B) C1{ FC2{} Fp Fc}



static void Test_Sf_Vp_B()
{
  {
    init_simple_test("Sf_Vp_B");
    Sf_Vp_B lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Sf_Vp_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Vp_B)");
    check_field_offset(lv, v1, 0, "Sf_Vp_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Sf_Vp_B.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Sf_Vp_B.v3");
  }
}
static Arrange_To_Call_Me vSf_Vp_B(Test_Sf_Vp_B, "Sf_Vp_B", ABISELECT(24,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Uc_B_Sf  {
  unsigned char v1;
  bool v2;
  ::empty v3;
};
//SIG(1 Uc_B_Sf) C1{ Fc[2] FC2{}}



static void Test_Uc_B_Sf()
{
  {
    init_simple_test("Uc_B_Sf");
    Uc_B_Sf lv;
    check2(sizeof(lv), 3, "sizeof(Uc_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_Sf)");
    check_field_offset(lv, v1, 0, "Uc_B_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_B_Sf.v2");
    check_field_offset(lv, v3, 2, "Uc_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vUc_B_Sf(Test_Uc_B_Sf, "Uc_B_Sf", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Uc_Sf_B  {
  unsigned char v1;
  ::empty v2;
  bool v3;
};
//SIG(1 Uc_Sf_B) C1{ Fc FC2{} Fc}



static void Test_Uc_Sf_B()
{
  {
    init_simple_test("Uc_Sf_B");
    Uc_Sf_B lv;
    check2(sizeof(lv), 3, "sizeof(Uc_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_B)");
    check_field_offset(lv, v1, 0, "Uc_Sf_B.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_B.v2");
    check_field_offset(lv, v3, 2, "Uc_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vUc_Sf_B(Test_Uc_Sf_B, "Uc_Sf_B", 3);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ui_B_Sf  {
  unsigned int v1;
  bool v2;
  ::empty v3;
};
//SIG(1 Ui_B_Sf) C1{ Fi Fc FC2{}}



static void Test_Ui_B_Sf()
{
  {
    init_simple_test("Ui_B_Sf");
    Ui_B_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ui_B_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_B_Sf)");
    check_field_offset(lv, v1, 0, "Ui_B_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_B_Sf.v2");
    check_field_offset(lv, v3, 5, "Ui_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vUi_B_Sf(Test_Ui_B_Sf, "Ui_B_Sf", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ui_Sf_B  {
  unsigned int v1;
  ::empty v2;
  bool v3;
};
//SIG(1 Ui_Sf_B) C1{ Fi FC2{} Fc}



static void Test_Ui_Sf_B()
{
  {
    init_simple_test("Ui_Sf_B");
    Ui_Sf_B lv;
    check2(sizeof(lv), 8, "sizeof(Ui_Sf_B)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_Sf_B)");
    check_field_offset(lv, v1, 0, "Ui_Sf_B.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_B.v2");
    check_field_offset(lv, v3, 5, "Ui_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vUi_Sf_B(Test_Ui_Sf_B, "Ui_Sf_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ul_B_Sf  {
  __tsu64 v1;
  bool v2;
  ::empty v3;
};
//SIG(1 Ul_B_Sf) C1{ FL Fc FC2{}}



static void Test_Ul_B_Sf()
{
  {
    init_simple_test("Ul_B_Sf");
    Ul_B_Sf lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_B_Sf)");
    check_field_offset(lv, v1, 0, "Ul_B_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_B_Sf.v2");
    check_field_offset(lv, v3, 9, "Ul_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vUl_B_Sf(Test_Ul_B_Sf, "Ul_B_Sf", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ul_Sf_B  {
  __tsu64 v1;
  ::empty v2;
  bool v3;
};
//SIG(1 Ul_Sf_B) C1{ FL FC2{} Fc}



static void Test_Ul_Sf_B()
{
  {
    init_simple_test("Ul_Sf_B");
    Ul_Sf_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_Sf_B)");
    check_field_offset(lv, v1, 0, "Ul_Sf_B.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_B.v2");
    check_field_offset(lv, v3, 9, "Ul_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vUl_Sf_B(Test_Ul_Sf_B, "Ul_Sf_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Us_B_Sf  {
  unsigned short v1;
  bool v2;
  ::empty v3;
};
//SIG(1 Us_B_Sf) C1{ Fs Fc FC2{}}



static void Test_Us_B_Sf()
{
  {
    init_simple_test("Us_B_Sf");
    Us_B_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(Us_B_Sf)");
    check_field_offset(lv, v1, 0, "Us_B_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_B_Sf.v2");
    check_field_offset(lv, v3, 3, "Us_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vUs_B_Sf(Test_Us_B_Sf, "Us_B_Sf", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Us_Sf_B  {
  unsigned short v1;
  ::empty v2;
  bool v3;
};
//SIG(1 Us_Sf_B) C1{ Fs FC2{} Fc}



static void Test_Us_Sf_B()
{
  {
    init_simple_test("Us_Sf_B");
    Us_Sf_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_B)");
    check2(__alignof__(lv), 2, "__alignof__(Us_Sf_B)");
    check_field_offset(lv, v1, 0, "Us_Sf_B.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_B.v2");
    check_field_offset(lv, v3, 3, "Us_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vUs_Sf_B(Test_Us_Sf_B, "Us_Sf_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Vp_B_Sf  {
  void *v1;
  bool v2;
  ::empty v3;
};
//SIG(1 Vp_B_Sf) C1{ Fp Fc FC2{}}



static void Test_Vp_B_Sf()
{
  {
    init_simple_test("Vp_B_Sf");
    Vp_B_Sf lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_B_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_B_Sf)");
    check_field_offset(lv, v1, 0, "Vp_B_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_Sf.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_B_Sf.v3");
  }
}
static Arrange_To_Call_Me vVp_B_Sf(Test_Vp_B_Sf, "Vp_B_Sf", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Vp_Sf_B  {
  void *v1;
  ::empty v2;
  bool v3;
};
//SIG(1 Vp_Sf_B) C1{ Fp FC2{} Fc}



static void Test_Vp_Sf_B()
{
  {
    init_simple_test("Vp_Sf_B");
    Vp_Sf_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Sf_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Sf_B)");
    check_field_offset(lv, v1, 0, "Vp_Sf_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_B.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_Sf_B.v3");
  }
}
static Arrange_To_Call_Me vVp_Sf_B(Test_Vp_Sf_B, "Vp_Sf_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

