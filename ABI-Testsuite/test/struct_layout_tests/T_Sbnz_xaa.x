// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: cxx_compiler cxx_rtti -c %s -I "common" -o %t2.o
// RUN: linker -o %t2%exeext  %t1.o %t2.o
// RUN: runtool %t2%exeext | checker "TEST PASSED"
#include "testsuite.h"
#ifdef __cplusplus

struct  B_B_BFu0c  {
  bool v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 B_B_BFu0c) C1{ Fc[2] Fc:0}



static void Test_B_B_BFu0c()
{
  {
    init_simple_test("B_B_BFu0c");
    static B_B_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(B_B_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(B_B_BFu0c)");
    check_field_offset(lv, v1, 0, "B_B_BFu0c.v1");
    check_field_offset(lv, v2, 1, "B_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_B_BFu0c(Test_B_B_BFu0c, "B_B_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_B_BFu0i  {
  bool v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 B_B_BFu0i) C1{ Fc[2] Fi:0}



static void Test_B_B_BFu0i()
{
  {
    init_simple_test("B_B_BFu0i");
    static B_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_B_BFu0i)");
    check_field_offset(lv, v1, 0, "B_B_BFu0i.v1");
    check_field_offset(lv, v2, 1, "B_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_B_BFu0i(Test_B_B_BFu0i, "B_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_B_BFu0ll  {
  bool v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 B_B_BFu0ll) C1{ Fc[2] FL:0}



static void Test_B_B_BFu0ll()
{
  {
    init_simple_test("B_B_BFu0ll");
    static B_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_B_BFu0ll.v1");
    check_field_offset(lv, v2, 1, "B_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_B_BFu0ll(Test_B_B_BFu0ll, "B_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_B_BFu0s  {
  bool v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 B_B_BFu0s) C1{ Fc[2] Fs:0}



static void Test_B_B_BFu0s()
{
  {
    init_simple_test("B_B_BFu0s");
    static B_B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_B_BFu0s)");
    check_field_offset(lv, v1, 0, "B_B_BFu0s.v1");
    check_field_offset(lv, v2, 1, "B_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_B_BFu0s(Test_B_B_BFu0s, "B_B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c  {
  bool v1;
  unsigned char  :0;
};
//SIG(1 B_BFu0c) C1{ Fc Fc:0}



static void Test_B_BFu0c()
{
  {
    init_simple_test("B_BFu0c");
    static B_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(B_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0c(Test_B_BFu0c, "B_BFu0c", 1);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_B  {
  bool v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 B_BFu0c_B) C1{ Fc Fc:0 Fc}



static void Test_B_BFu0c_B()
{
  {
    init_simple_test("B_BFu0c_B");
    static B_BFu0c_B lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0c_B)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu0c_B)");
    check_field_offset(lv, v1, 0, "B_BFu0c_B.v1");
    check_field_offset(lv, v2, 1, "B_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_B(Test_B_BFu0c_B, "B_BFu0c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu0c  {
  bool v1;
  unsigned char  :0;
  unsigned char  :0;
};
//SIG(1 B_BFu0c_BFu0c) C1{ Fc Fc:0 Fc:0}



static void Test_B_BFu0c_BFu0c()
{
  {
    init_simple_test("B_BFu0c_BFu0c");
    static B_BFu0c_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(B_BFu0c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu0c_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu0c(Test_B_BFu0c_BFu0c, "B_BFu0c_BFu0c", 1);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu0i  {
  bool v1;
  unsigned char  :0;
  unsigned int  :0;
};
//SIG(1 B_BFu0c_BFu0i) C1{ Fc Fc:0 Fi:0}



static void Test_B_BFu0c_BFu0i()
{
  {
    init_simple_test("B_BFu0c_BFu0i");
    static B_BFu0c_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0c_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu0i(Test_B_BFu0c_BFu0i, "B_BFu0c_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu0ll  {
  bool v1;
  unsigned char  :0;
  __tsu64  :0;
};
//SIG(1 B_BFu0c_BFu0ll) C1{ Fc Fc:0 FL:0}



static void Test_B_BFu0c_BFu0ll()
{
  {
    init_simple_test("B_BFu0c_BFu0ll");
    static B_BFu0c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0c_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu0ll(Test_B_BFu0c_BFu0ll, "B_BFu0c_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu0s  {
  bool v1;
  unsigned char  :0;
  unsigned short  :0;
};
//SIG(1 B_BFu0c_BFu0s) C1{ Fc Fc:0 Fs:0}



static void Test_B_BFu0c_BFu0s()
{
  {
    init_simple_test("B_BFu0c_BFu0s");
    static B_BFu0c_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0c_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu0s(Test_B_BFu0c_BFu0s, "B_BFu0c_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu15i  {
  bool v1;
  unsigned char  :0;
  unsigned int v2:15;
};
//SIG(1 B_BFu0c_BFu15i) C1{ Fc Fc:0 Fi:15}



static void Test_B_BFu0c_BFu15i()
{
  {
    init_simple_test("B_BFu0c_BFu15i");
    static B_BFu0c_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0c_BFu15i)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu15i.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu0c_BFu15i");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu0c_BFu15i");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu15i(Test_B_BFu0c_BFu15i, "B_BFu0c_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu15ll  {
  bool v1;
  unsigned char  :0;
  __tsu64 v2:15;
};
//SIG(1 B_BFu0c_BFu15ll) C1{ Fc Fc:0 FL:15}



static void Test_B_BFu0c_BFu15ll()
{
  {
    init_simple_test("B_BFu0c_BFu15ll");
    static B_BFu0c_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0c_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_BFu15ll)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu15ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu0c_BFu15ll");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu0c_BFu15ll");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu15ll(Test_B_BFu0c_BFu15ll, "B_BFu0c_BFu15ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu15s  {
  bool v1;
  unsigned char  :0;
  unsigned short v2:15;
};
//SIG(1 B_BFu0c_BFu15s) C1{ Fc Fc:0 Fs:15}



static void Test_B_BFu0c_BFu15s()
{
  {
    init_simple_test("B_BFu0c_BFu15s");
    static B_BFu0c_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_BFu15s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0c_BFu15s)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu15s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "B_BFu0c_BFu15s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "B_BFu0c_BFu15s");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu15s(Test_B_BFu0c_BFu15s, "B_BFu0c_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu16i  {
  bool v1;
  unsigned char  :0;
  unsigned int v2:16;
};
//SIG(1 B_BFu0c_BFu16i) C1{ Fc Fc:0 Fi:16}



static void Test_B_BFu0c_BFu16i()
{
  {
    init_simple_test("B_BFu0c_BFu16i");
    static B_BFu0c_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0c_BFu16i)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu16i.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu0c_BFu16i");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu0c_BFu16i");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu16i(Test_B_BFu0c_BFu16i, "B_BFu0c_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu16ll  {
  bool v1;
  unsigned char  :0;
  __tsu64 v2:16;
};
//SIG(1 B_BFu0c_BFu16ll) C1{ Fc Fc:0 FL:16}



static void Test_B_BFu0c_BFu16ll()
{
  {
    init_simple_test("B_BFu0c_BFu16ll");
    static B_BFu0c_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0c_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_BFu16ll)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu16ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu0c_BFu16ll");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu0c_BFu16ll");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu16ll(Test_B_BFu0c_BFu16ll, "B_BFu0c_BFu16ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu16s  {
  bool v1;
  unsigned char  :0;
  unsigned short v2:16;
};
//SIG(1 B_BFu0c_BFu16s) C1{ Fc Fc:0 Fs:16}



static void Test_B_BFu0c_BFu16s()
{
  {
    init_simple_test("B_BFu0c_BFu16s");
    static B_BFu0c_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_BFu16s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0c_BFu16s)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu16s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "B_BFu0c_BFu16s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "B_BFu0c_BFu16s");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu16s(Test_B_BFu0c_BFu16s, "B_BFu0c_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu17i  {
  bool v1;
  unsigned char  :0;
  unsigned int v2:17;
};
//SIG(1 B_BFu0c_BFu17i) C1{ Fc Fc:0 Fi:17}



static void Test_B_BFu0c_BFu17i()
{
  {
    init_simple_test("B_BFu0c_BFu17i");
    static B_BFu0c_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0c_BFu17i)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu17i.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu0c_BFu17i");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu0c_BFu17i");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu17i(Test_B_BFu0c_BFu17i, "B_BFu0c_BFu17i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu17ll  {
  bool v1;
  unsigned char  :0;
  __tsu64 v2:17;
};
//SIG(1 B_BFu0c_BFu17ll) C1{ Fc Fc:0 FL:17}



static void Test_B_BFu0c_BFu17ll()
{
  {
    init_simple_test("B_BFu0c_BFu17ll");
    static B_BFu0c_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0c_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_BFu17ll)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu17ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu0c_BFu17ll");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu0c_BFu17ll");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu17ll(Test_B_BFu0c_BFu17ll, "B_BFu0c_BFu17ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu1c  {
  bool v1;
  unsigned char  :0;
  unsigned char v2:1;
};
//SIG(1 B_BFu0c_BFu1c) C1{ Fc Fc:0 Fc:1}



static void Test_B_BFu0c_BFu1c()
{
  {
    init_simple_test("B_BFu0c_BFu1c");
    static B_BFu0c_BFu1c lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0c_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu0c_BFu1c)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu1c.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu0c_BFu1c");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu1c(Test_B_BFu0c_BFu1c, "B_BFu0c_BFu1c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu1i  {
  bool v1;
  unsigned char  :0;
  unsigned int v2:1;
};
//SIG(1 B_BFu0c_BFu1i) C1{ Fc Fc:0 Fi:1}



static void Test_B_BFu0c_BFu1i()
{
  {
    init_simple_test("B_BFu0c_BFu1i");
    static B_BFu0c_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0c_BFu1i)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu1i.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu0c_BFu1i");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu1i(Test_B_BFu0c_BFu1i, "B_BFu0c_BFu1i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu1ll  {
  bool v1;
  unsigned char  :0;
  __tsu64 v2:1;
};
//SIG(1 B_BFu0c_BFu1ll) C1{ Fc Fc:0 FL:1}



static void Test_B_BFu0c_BFu1ll()
{
  {
    init_simple_test("B_BFu0c_BFu1ll");
    static B_BFu0c_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0c_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_BFu1ll)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu1ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu0c_BFu1ll");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu1ll(Test_B_BFu0c_BFu1ll, "B_BFu0c_BFu1ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu1s  {
  bool v1;
  unsigned char  :0;
  unsigned short v2:1;
};
//SIG(1 B_BFu0c_BFu1s) C1{ Fc Fc:0 Fs:1}



static void Test_B_BFu0c_BFu1s()
{
  {
    init_simple_test("B_BFu0c_BFu1s");
    static B_BFu0c_BFu1s lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0c_BFu1s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0c_BFu1s)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu1s.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu0c_BFu1s");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu1s(Test_B_BFu0c_BFu1s, "B_BFu0c_BFu1s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu31i  {
  bool v1;
  unsigned char  :0;
  unsigned int v2:31;
};
//SIG(1 B_BFu0c_BFu31i) C1{ Fc Fc:0 Fi:31}



static void Test_B_BFu0c_BFu31i()
{
  {
    init_simple_test("B_BFu0c_BFu31i");
    static B_BFu0c_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0c_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0c_BFu31i)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu31i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "B_BFu0c_BFu31i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "B_BFu0c_BFu31i");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu31i(Test_B_BFu0c_BFu31i, "B_BFu0c_BFu31i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu31ll  {
  bool v1;
  unsigned char  :0;
  __tsu64 v2:31;
};
//SIG(1 B_BFu0c_BFu31ll) C1{ Fc Fc:0 FL:31}



static void Test_B_BFu0c_BFu31ll()
{
  {
    init_simple_test("B_BFu0c_BFu31ll");
    static B_BFu0c_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0c_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_BFu31ll)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu31ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "B_BFu0c_BFu31ll");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "B_BFu0c_BFu31ll");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu31ll(Test_B_BFu0c_BFu31ll, "B_BFu0c_BFu31ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu32i  {
  bool v1;
  unsigned char  :0;
  unsigned int v2:32;
};
//SIG(1 B_BFu0c_BFu32i) C1{ Fc Fc:0 Fi:32}



static void Test_B_BFu0c_BFu32i()
{
  {
    init_simple_test("B_BFu0c_BFu32i");
    static B_BFu0c_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0c_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0c_BFu32i)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu32i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "B_BFu0c_BFu32i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "B_BFu0c_BFu32i");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu32i(Test_B_BFu0c_BFu32i, "B_BFu0c_BFu32i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu32ll  {
  bool v1;
  unsigned char  :0;
  __tsu64 v2:32;
};
//SIG(1 B_BFu0c_BFu32ll) C1{ Fc Fc:0 FL:32}



static void Test_B_BFu0c_BFu32ll()
{
  {
    init_simple_test("B_BFu0c_BFu32ll");
    static B_BFu0c_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0c_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_BFu32ll)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu32ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "B_BFu0c_BFu32ll");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "B_BFu0c_BFu32ll");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu32ll(Test_B_BFu0c_BFu32ll, "B_BFu0c_BFu32ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu33  {
  bool v1;
  unsigned char  :0;
  __tsu64 v2:33;
};
//SIG(1 B_BFu0c_BFu33) C1{ Fc Fc:0 FL:33}



static void Test_B_BFu0c_BFu33()
{
  {
    init_simple_test("B_BFu0c_BFu33");
    static B_BFu0c_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0c_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_BFu33)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu33.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "B_BFu0c_BFu33");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "B_BFu0c_BFu33");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu33(Test_B_BFu0c_BFu33, "B_BFu0c_BFu33", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu7c  {
  bool v1;
  unsigned char  :0;
  unsigned char v2:7;
};
//SIG(1 B_BFu0c_BFu7c) C1{ Fc Fc:0 Fc:7}



static void Test_B_BFu0c_BFu7c()
{
  {
    init_simple_test("B_BFu0c_BFu7c");
    static B_BFu0c_BFu7c lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0c_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu0c_BFu7c)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu7c.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu0c_BFu7c");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu0c_BFu7c");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu7c(Test_B_BFu0c_BFu7c, "B_BFu0c_BFu7c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu7i  {
  bool v1;
  unsigned char  :0;
  unsigned int v2:7;
};
//SIG(1 B_BFu0c_BFu7i) C1{ Fc Fc:0 Fi:7}



static void Test_B_BFu0c_BFu7i()
{
  {
    init_simple_test("B_BFu0c_BFu7i");
    static B_BFu0c_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0c_BFu7i)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu7i.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu0c_BFu7i");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu0c_BFu7i");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu7i(Test_B_BFu0c_BFu7i, "B_BFu0c_BFu7i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu7ll  {
  bool v1;
  unsigned char  :0;
  __tsu64 v2:7;
};
//SIG(1 B_BFu0c_BFu7ll) C1{ Fc Fc:0 FL:7}



static void Test_B_BFu0c_BFu7ll()
{
  {
    init_simple_test("B_BFu0c_BFu7ll");
    static B_BFu0c_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0c_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_BFu7ll)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu7ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu0c_BFu7ll");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu0c_BFu7ll");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu7ll(Test_B_BFu0c_BFu7ll, "B_BFu0c_BFu7ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu7s  {
  bool v1;
  unsigned char  :0;
  unsigned short v2:7;
};
//SIG(1 B_BFu0c_BFu7s) C1{ Fc Fc:0 Fs:7}



static void Test_B_BFu0c_BFu7s()
{
  {
    init_simple_test("B_BFu0c_BFu7s");
    static B_BFu0c_BFu7s lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0c_BFu7s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0c_BFu7s)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu7s.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu0c_BFu7s");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu0c_BFu7s");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu7s(Test_B_BFu0c_BFu7s, "B_BFu0c_BFu7s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu8c  {
  bool v1;
  unsigned char  :0;
  unsigned char v2:8;
};
//SIG(1 B_BFu0c_BFu8c) C1{ Fc Fc:0 Fc:8}



static void Test_B_BFu0c_BFu8c()
{
  {
    init_simple_test("B_BFu0c_BFu8c");
    static B_BFu0c_BFu8c lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0c_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu0c_BFu8c)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu8c.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu0c_BFu8c");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu0c_BFu8c");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu8c(Test_B_BFu0c_BFu8c, "B_BFu0c_BFu8c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu8i  {
  bool v1;
  unsigned char  :0;
  unsigned int v2:8;
};
//SIG(1 B_BFu0c_BFu8i) C1{ Fc Fc:0 Fi:8}



static void Test_B_BFu0c_BFu8i()
{
  {
    init_simple_test("B_BFu0c_BFu8i");
    static B_BFu0c_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0c_BFu8i)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu8i.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu0c_BFu8i");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu0c_BFu8i");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu8i(Test_B_BFu0c_BFu8i, "B_BFu0c_BFu8i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu8ll  {
  bool v1;
  unsigned char  :0;
  __tsu64 v2:8;
};
//SIG(1 B_BFu0c_BFu8ll) C1{ Fc Fc:0 FL:8}



static void Test_B_BFu0c_BFu8ll()
{
  {
    init_simple_test("B_BFu0c_BFu8ll");
    static B_BFu0c_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0c_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_BFu8ll)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu8ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu0c_BFu8ll");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu0c_BFu8ll");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu8ll(Test_B_BFu0c_BFu8ll, "B_BFu0c_BFu8ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu8s  {
  bool v1;
  unsigned char  :0;
  unsigned short v2:8;
};
//SIG(1 B_BFu0c_BFu8s) C1{ Fc Fc:0 Fs:8}



static void Test_B_BFu0c_BFu8s()
{
  {
    init_simple_test("B_BFu0c_BFu8s");
    static B_BFu0c_BFu8s lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0c_BFu8s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0c_BFu8s)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu8s.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu0c_BFu8s");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu0c_BFu8s");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu8s(Test_B_BFu0c_BFu8s, "B_BFu0c_BFu8s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu9i  {
  bool v1;
  unsigned char  :0;
  unsigned int v2:9;
};
//SIG(1 B_BFu0c_BFu9i) C1{ Fc Fc:0 Fi:9}



static void Test_B_BFu0c_BFu9i()
{
  {
    init_simple_test("B_BFu0c_BFu9i");
    static B_BFu0c_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0c_BFu9i)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu9i.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu0c_BFu9i");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu0c_BFu9i");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu9i(Test_B_BFu0c_BFu9i, "B_BFu0c_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu9ll  {
  bool v1;
  unsigned char  :0;
  __tsu64 v2:9;
};
//SIG(1 B_BFu0c_BFu9ll) C1{ Fc Fc:0 FL:9}



static void Test_B_BFu0c_BFu9ll()
{
  {
    init_simple_test("B_BFu0c_BFu9ll");
    static B_BFu0c_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0c_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_BFu9ll)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu9ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu0c_BFu9ll");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu0c_BFu9ll");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu9ll(Test_B_BFu0c_BFu9ll, "B_BFu0c_BFu9ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_BFu9s  {
  bool v1;
  unsigned char  :0;
  unsigned short v2:9;
};
//SIG(1 B_BFu0c_BFu9s) C1{ Fc Fc:0 Fs:9}



static void Test_B_BFu0c_BFu9s()
{
  {
    init_simple_test("B_BFu0c_BFu9s");
    static B_BFu0c_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_BFu9s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0c_BFu9s)");
    check_field_offset(lv, v1, 0, "B_BFu0c_BFu9s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "B_BFu0c_BFu9s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "B_BFu0c_BFu9s");
  }
}
static Arrange_To_Call_Me vB_BFu0c_BFu9s(Test_B_BFu0c_BFu9s, "B_BFu0c_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_C  {
  bool v1;
  unsigned char  :0;
  char v2;
};
//SIG(1 B_BFu0c_C) C1{ Fc Fc:0 Fc}



static void Test_B_BFu0c_C()
{
  {
    init_simple_test("B_BFu0c_C");
    static B_BFu0c_C lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0c_C)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu0c_C)");
    check_field_offset(lv, v1, 0, "B_BFu0c_C.v1");
    check_field_offset(lv, v2, 1, "B_BFu0c_C.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_C(Test_B_BFu0c_C, "B_BFu0c_C", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_D  {
  bool v1;
  unsigned char  :0;
  double v2;
};
//SIG(1 B_BFu0c_D) C1{ Fc Fc:0 FL}



static void Test_B_BFu0c_D()
{
  {
    init_simple_test("B_BFu0c_D");
    static B_BFu0c_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0c_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_D)");
    check_field_offset(lv, v1, 0, "B_BFu0c_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0c_D.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_D(Test_B_BFu0c_D, "B_BFu0c_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_F  {
  bool v1;
  unsigned char  :0;
  float v2;
};
//SIG(1 B_BFu0c_F) C1{ Fc Fc:0 Fi}



static void Test_B_BFu0c_F()
{
  {
    init_simple_test("B_BFu0c_F");
    static B_BFu0c_F lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0c_F)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0c_F)");
    check_field_offset(lv, v1, 0, "B_BFu0c_F.v1");
    check_field_offset(lv, v2, 4, "B_BFu0c_F.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_F(Test_B_BFu0c_F, "B_BFu0c_F", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_I  {
  bool v1;
  unsigned char  :0;
  int v2;
};
//SIG(1 B_BFu0c_I) C1{ Fc Fc:0 Fi}



static void Test_B_BFu0c_I()
{
  {
    init_simple_test("B_BFu0c_I");
    static B_BFu0c_I lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0c_I)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0c_I)");
    check_field_offset(lv, v1, 0, "B_BFu0c_I.v1");
    check_field_offset(lv, v2, 4, "B_BFu0c_I.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_I(Test_B_BFu0c_I, "B_BFu0c_I", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_Ip  {
  bool v1;
  unsigned char  :0;
  int *v2;
};
//SIG(1 B_BFu0c_Ip) C1{ Fc Fc:0 Fp}



static void Test_B_BFu0c_Ip()
{
  {
    init_simple_test("B_BFu0c_Ip");
    static B_BFu0c_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0c_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_Ip)");
    check_field_offset(lv, v1, 0, "B_BFu0c_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0c_Ip.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_Ip(Test_B_BFu0c_Ip, "B_BFu0c_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_L  {
  bool v1;
  unsigned char  :0;
  __tsi64 v2;
};
//SIG(1 B_BFu0c_L) C1{ Fc Fc:0 FL}



static void Test_B_BFu0c_L()
{
  {
    init_simple_test("B_BFu0c_L");
    static B_BFu0c_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0c_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_L)");
    check_field_offset(lv, v1, 0, "B_BFu0c_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0c_L.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_L(Test_B_BFu0c_L, "B_BFu0c_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_S  {
  bool v1;
  unsigned char  :0;
  short v2;
};
//SIG(1 B_BFu0c_S) C1{ Fc Fc:0 Fs}



static void Test_B_BFu0c_S()
{
  {
    init_simple_test("B_BFu0c_S");
    static B_BFu0c_S lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_S)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0c_S)");
    check_field_offset(lv, v1, 0, "B_BFu0c_S.v1");
    check_field_offset(lv, v2, 2, "B_BFu0c_S.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_S(Test_B_BFu0c_S, "B_BFu0c_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_Uc  {
  bool v1;
  unsigned char  :0;
  unsigned char v2;
};
//SIG(1 B_BFu0c_Uc) C1{ Fc Fc:0 Fc}



static void Test_B_BFu0c_Uc()
{
  {
    init_simple_test("B_BFu0c_Uc");
    static B_BFu0c_Uc lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0c_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu0c_Uc)");
    check_field_offset(lv, v1, 0, "B_BFu0c_Uc.v1");
    check_field_offset(lv, v2, 1, "B_BFu0c_Uc.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_Uc(Test_B_BFu0c_Uc, "B_BFu0c_Uc", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_Ui  {
  bool v1;
  unsigned char  :0;
  unsigned int v2;
};
//SIG(1 B_BFu0c_Ui) C1{ Fc Fc:0 Fi}



static void Test_B_BFu0c_Ui()
{
  {
    init_simple_test("B_BFu0c_Ui");
    static B_BFu0c_Ui lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0c_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0c_Ui)");
    check_field_offset(lv, v1, 0, "B_BFu0c_Ui.v1");
    check_field_offset(lv, v2, 4, "B_BFu0c_Ui.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_Ui(Test_B_BFu0c_Ui, "B_BFu0c_Ui", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_Ul  {
  bool v1;
  unsigned char  :0;
  __tsu64 v2;
};
//SIG(1 B_BFu0c_Ul) C1{ Fc Fc:0 FL}



static void Test_B_BFu0c_Ul()
{
  {
    init_simple_test("B_BFu0c_Ul");
    static B_BFu0c_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0c_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_Ul)");
    check_field_offset(lv, v1, 0, "B_BFu0c_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0c_Ul.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_Ul(Test_B_BFu0c_Ul, "B_BFu0c_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_Us  {
  bool v1;
  unsigned char  :0;
  unsigned short v2;
};
//SIG(1 B_BFu0c_Us) C1{ Fc Fc:0 Fs}



static void Test_B_BFu0c_Us()
{
  {
    init_simple_test("B_BFu0c_Us");
    static B_BFu0c_Us lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0c_Us)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0c_Us)");
    check_field_offset(lv, v1, 0, "B_BFu0c_Us.v1");
    check_field_offset(lv, v2, 2, "B_BFu0c_Us.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_Us(Test_B_BFu0c_Us, "B_BFu0c_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0c_Vp  {
  bool v1;
  unsigned char  :0;
  void *v2;
};
//SIG(1 B_BFu0c_Vp) C1{ Fc Fc:0 Fp}



static void Test_B_BFu0c_Vp()
{
  {
    init_simple_test("B_BFu0c_Vp");
    static B_BFu0c_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0c_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0c_Vp)");
    check_field_offset(lv, v1, 0, "B_BFu0c_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0c_Vp.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_Vp(Test_B_BFu0c_Vp, "B_BFu0c_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i  {
  bool v1;
  unsigned int  :0;
};
//SIG(1 B_BFu0i) C1{ Fc Fi:0}



static void Test_B_BFu0i()
{
  {
    init_simple_test("B_BFu0i");
    static B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0i(Test_B_BFu0i, "B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_B  {
  bool v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 B_BFu0i_B) C1{ Fc Fi:0 Fc}



static void Test_B_BFu0i_B()
{
  {
    init_simple_test("B_BFu0i_B");
    static B_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(B_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0i_B)");
    check_field_offset(lv, v1, 0, "B_BFu0i_B.v1");
    check_field_offset(lv, v2, 4, "B_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_B(Test_B_BFu0i_B, "B_BFu0i_B", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu0c  {
  bool v1;
  unsigned int  :0;
  unsigned char  :0;
};
//SIG(1 B_BFu0i_BFu0c) C1{ Fc Fi:0 Fc:0}



static void Test_B_BFu0i_BFu0c()
{
  {
    init_simple_test("B_BFu0i_BFu0c");
    static B_BFu0i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0i_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0i_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu0c(Test_B_BFu0i_BFu0c, "B_BFu0i_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu0i  {
  bool v1;
  unsigned int  :0;
  unsigned int  :0;
};
//SIG(1 B_BFu0i_BFu0i) C1{ Fc Fi:0 Fi:0}



static void Test_B_BFu0i_BFu0i()
{
  {
    init_simple_test("B_BFu0i_BFu0i");
    static B_BFu0i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0i_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu0i(Test_B_BFu0i_BFu0i, "B_BFu0i_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu0ll  {
  bool v1;
  unsigned int  :0;
  __tsu64  :0;
};
//SIG(1 B_BFu0i_BFu0ll) C1{ Fc Fi:0 FL:0}



static void Test_B_BFu0i_BFu0ll()
{
  {
    init_simple_test("B_BFu0i_BFu0ll");
    static B_BFu0i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0i_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu0ll(Test_B_BFu0i_BFu0ll, "B_BFu0i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu0s  {
  bool v1;
  unsigned int  :0;
  unsigned short  :0;
};
//SIG(1 B_BFu0i_BFu0s) C1{ Fc Fi:0 Fs:0}



static void Test_B_BFu0i_BFu0s()
{
  {
    init_simple_test("B_BFu0i_BFu0s");
    static B_BFu0i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0i_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu0s(Test_B_BFu0i_BFu0s, "B_BFu0i_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu15i  {
  bool v1;
  unsigned int  :0;
  unsigned int v2:15;
};
//SIG(1 B_BFu0i_BFu15i) C1{ Fc Fi:0 Fi:15}



static void Test_B_BFu0i_BFu15i()
{
  {
    init_simple_test("B_BFu0i_BFu15i");
    static B_BFu0i_BFu15i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0i_BFu15i)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu15i.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "B_BFu0i_BFu15i");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "B_BFu0i_BFu15i");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu15i(Test_B_BFu0i_BFu15i, "B_BFu0i_BFu15i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu15ll  {
  bool v1;
  unsigned int  :0;
  __tsu64 v2:15;
};
//SIG(1 B_BFu0i_BFu15ll) C1{ Fc Fi:0 FL:15}



static void Test_B_BFu0i_BFu15ll()
{
  {
    init_simple_test("B_BFu0i_BFu15ll");
    static B_BFu0i_BFu15ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_BFu15ll)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu15ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "B_BFu0i_BFu15ll");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "B_BFu0i_BFu15ll");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu15ll(Test_B_BFu0i_BFu15ll, "B_BFu0i_BFu15ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu15s  {
  bool v1;
  unsigned int  :0;
  unsigned short v2:15;
};
//SIG(1 B_BFu0i_BFu15s) C1{ Fc Fi:0 Fs:15}



static void Test_B_BFu0i_BFu15s()
{
  {
    init_simple_test("B_BFu0i_BFu15s");
    static B_BFu0i_BFu15s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(B_BFu0i_BFu15s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0i_BFu15s)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu15s.v1");
    set_bf_and_test(lv, v2, 4, 0, 15, 1, "B_BFu0i_BFu15s");
    set_bf_and_test(lv, v2, 4, 0, 15, hide_ull(1LL<<14), "B_BFu0i_BFu15s");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu15s(Test_B_BFu0i_BFu15s, "B_BFu0i_BFu15s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu16i  {
  bool v1;
  unsigned int  :0;
  unsigned int v2:16;
};
//SIG(1 B_BFu0i_BFu16i) C1{ Fc Fi:0 Fi:16}



static void Test_B_BFu0i_BFu16i()
{
  {
    init_simple_test("B_BFu0i_BFu16i");
    static B_BFu0i_BFu16i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0i_BFu16i)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu16i.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "B_BFu0i_BFu16i");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "B_BFu0i_BFu16i");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu16i(Test_B_BFu0i_BFu16i, "B_BFu0i_BFu16i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu16ll  {
  bool v1;
  unsigned int  :0;
  __tsu64 v2:16;
};
//SIG(1 B_BFu0i_BFu16ll) C1{ Fc Fi:0 FL:16}



static void Test_B_BFu0i_BFu16ll()
{
  {
    init_simple_test("B_BFu0i_BFu16ll");
    static B_BFu0i_BFu16ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_BFu16ll)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu16ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "B_BFu0i_BFu16ll");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "B_BFu0i_BFu16ll");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu16ll(Test_B_BFu0i_BFu16ll, "B_BFu0i_BFu16ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu16s  {
  bool v1;
  unsigned int  :0;
  unsigned short v2:16;
};
//SIG(1 B_BFu0i_BFu16s) C1{ Fc Fi:0 Fs:16}



static void Test_B_BFu0i_BFu16s()
{
  {
    init_simple_test("B_BFu0i_BFu16s");
    static B_BFu0i_BFu16s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(B_BFu0i_BFu16s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0i_BFu16s)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu16s.v1");
    set_bf_and_test(lv, v2, 4, 0, 16, 1, "B_BFu0i_BFu16s");
    set_bf_and_test(lv, v2, 4, 0, 16, hide_ull(1LL<<15), "B_BFu0i_BFu16s");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu16s(Test_B_BFu0i_BFu16s, "B_BFu0i_BFu16s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu17i  {
  bool v1;
  unsigned int  :0;
  unsigned int v2:17;
};
//SIG(1 B_BFu0i_BFu17i) C1{ Fc Fi:0 Fi:17}



static void Test_B_BFu0i_BFu17i()
{
  {
    init_simple_test("B_BFu0i_BFu17i");
    static B_BFu0i_BFu17i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0i_BFu17i)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu17i.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "B_BFu0i_BFu17i");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "B_BFu0i_BFu17i");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu17i(Test_B_BFu0i_BFu17i, "B_BFu0i_BFu17i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu17ll  {
  bool v1;
  unsigned int  :0;
  __tsu64 v2:17;
};
//SIG(1 B_BFu0i_BFu17ll) C1{ Fc Fi:0 FL:17}



static void Test_B_BFu0i_BFu17ll()
{
  {
    init_simple_test("B_BFu0i_BFu17ll");
    static B_BFu0i_BFu17ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_BFu17ll)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu17ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "B_BFu0i_BFu17ll");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "B_BFu0i_BFu17ll");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu17ll(Test_B_BFu0i_BFu17ll, "B_BFu0i_BFu17ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu1c  {
  bool v1;
  unsigned int  :0;
  unsigned char v2:1;
};
//SIG(1 B_BFu0i_BFu1c) C1{ Fc Fi:0 Fc:1}



static void Test_B_BFu0i_BFu1c()
{
  {
    init_simple_test("B_BFu0i_BFu1c");
    static B_BFu0i_BFu1c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(B_BFu0i_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0i_BFu1c)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu1c.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "B_BFu0i_BFu1c");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu1c(Test_B_BFu0i_BFu1c, "B_BFu0i_BFu1c", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu1i  {
  bool v1;
  unsigned int  :0;
  unsigned int v2:1;
};
//SIG(1 B_BFu0i_BFu1i) C1{ Fc Fi:0 Fi:1}



static void Test_B_BFu0i_BFu1i()
{
  {
    init_simple_test("B_BFu0i_BFu1i");
    static B_BFu0i_BFu1i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0i_BFu1i)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu1i.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "B_BFu0i_BFu1i");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu1i(Test_B_BFu0i_BFu1i, "B_BFu0i_BFu1i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu1ll  {
  bool v1;
  unsigned int  :0;
  __tsu64 v2:1;
};
//SIG(1 B_BFu0i_BFu1ll) C1{ Fc Fi:0 FL:1}



static void Test_B_BFu0i_BFu1ll()
{
  {
    init_simple_test("B_BFu0i_BFu1ll");
    static B_BFu0i_BFu1ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_BFu1ll)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu1ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "B_BFu0i_BFu1ll");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu1ll(Test_B_BFu0i_BFu1ll, "B_BFu0i_BFu1ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu1s  {
  bool v1;
  unsigned int  :0;
  unsigned short v2:1;
};
//SIG(1 B_BFu0i_BFu1s) C1{ Fc Fi:0 Fs:1}



static void Test_B_BFu0i_BFu1s()
{
  {
    init_simple_test("B_BFu0i_BFu1s");
    static B_BFu0i_BFu1s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(B_BFu0i_BFu1s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0i_BFu1s)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu1s.v1");
    set_bf_and_test(lv, v2, 4, 0, 1, 1, "B_BFu0i_BFu1s");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu1s(Test_B_BFu0i_BFu1s, "B_BFu0i_BFu1s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu31i  {
  bool v1;
  unsigned int  :0;
  unsigned int v2:31;
};
//SIG(1 B_BFu0i_BFu31i) C1{ Fc Fi:0 Fi:31}



static void Test_B_BFu0i_BFu31i()
{
  {
    init_simple_test("B_BFu0i_BFu31i");
    static B_BFu0i_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0i_BFu31i)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu31i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "B_BFu0i_BFu31i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "B_BFu0i_BFu31i");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu31i(Test_B_BFu0i_BFu31i, "B_BFu0i_BFu31i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu31ll  {
  bool v1;
  unsigned int  :0;
  __tsu64 v2:31;
};
//SIG(1 B_BFu0i_BFu31ll) C1{ Fc Fi:0 FL:31}



static void Test_B_BFu0i_BFu31ll()
{
  {
    init_simple_test("B_BFu0i_BFu31ll");
    static B_BFu0i_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_BFu31ll)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu31ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "B_BFu0i_BFu31ll");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "B_BFu0i_BFu31ll");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu31ll(Test_B_BFu0i_BFu31ll, "B_BFu0i_BFu31ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu32i  {
  bool v1;
  unsigned int  :0;
  unsigned int v2:32;
};
//SIG(1 B_BFu0i_BFu32i) C1{ Fc Fi:0 Fi:32}



static void Test_B_BFu0i_BFu32i()
{
  {
    init_simple_test("B_BFu0i_BFu32i");
    static B_BFu0i_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0i_BFu32i)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu32i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "B_BFu0i_BFu32i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "B_BFu0i_BFu32i");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu32i(Test_B_BFu0i_BFu32i, "B_BFu0i_BFu32i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu32ll  {
  bool v1;
  unsigned int  :0;
  __tsu64 v2:32;
};
//SIG(1 B_BFu0i_BFu32ll) C1{ Fc Fi:0 FL:32}



static void Test_B_BFu0i_BFu32ll()
{
  {
    init_simple_test("B_BFu0i_BFu32ll");
    static B_BFu0i_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_BFu32ll)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu32ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "B_BFu0i_BFu32ll");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "B_BFu0i_BFu32ll");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu32ll(Test_B_BFu0i_BFu32ll, "B_BFu0i_BFu32ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu33  {
  bool v1;
  unsigned int  :0;
  __tsu64 v2:33;
};
//SIG(1 B_BFu0i_BFu33) C1{ Fc Fi:0 FL:33}



static void Test_B_BFu0i_BFu33()
{
  {
    init_simple_test("B_BFu0i_BFu33");
    static B_BFu0i_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0i_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_BFu33)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "B_BFu0i_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "B_BFu0i_BFu33");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu33(Test_B_BFu0i_BFu33, "B_BFu0i_BFu33", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu7c  {
  bool v1;
  unsigned int  :0;
  unsigned char v2:7;
};
//SIG(1 B_BFu0i_BFu7c) C1{ Fc Fi:0 Fc:7}



static void Test_B_BFu0i_BFu7c()
{
  {
    init_simple_test("B_BFu0i_BFu7c");
    static B_BFu0i_BFu7c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(B_BFu0i_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0i_BFu7c)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu7c.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "B_BFu0i_BFu7c");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "B_BFu0i_BFu7c");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu7c(Test_B_BFu0i_BFu7c, "B_BFu0i_BFu7c", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu7i  {
  bool v1;
  unsigned int  :0;
  unsigned int v2:7;
};
//SIG(1 B_BFu0i_BFu7i) C1{ Fc Fi:0 Fi:7}



static void Test_B_BFu0i_BFu7i()
{
  {
    init_simple_test("B_BFu0i_BFu7i");
    static B_BFu0i_BFu7i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0i_BFu7i)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu7i.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "B_BFu0i_BFu7i");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "B_BFu0i_BFu7i");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu7i(Test_B_BFu0i_BFu7i, "B_BFu0i_BFu7i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu7ll  {
  bool v1;
  unsigned int  :0;
  __tsu64 v2:7;
};
//SIG(1 B_BFu0i_BFu7ll) C1{ Fc Fi:0 FL:7}



static void Test_B_BFu0i_BFu7ll()
{
  {
    init_simple_test("B_BFu0i_BFu7ll");
    static B_BFu0i_BFu7ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_BFu7ll)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu7ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "B_BFu0i_BFu7ll");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "B_BFu0i_BFu7ll");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu7ll(Test_B_BFu0i_BFu7ll, "B_BFu0i_BFu7ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu7s  {
  bool v1;
  unsigned int  :0;
  unsigned short v2:7;
};
//SIG(1 B_BFu0i_BFu7s) C1{ Fc Fi:0 Fs:7}



static void Test_B_BFu0i_BFu7s()
{
  {
    init_simple_test("B_BFu0i_BFu7s");
    static B_BFu0i_BFu7s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(B_BFu0i_BFu7s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0i_BFu7s)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu7s.v1");
    set_bf_and_test(lv, v2, 4, 0, 7, 1, "B_BFu0i_BFu7s");
    set_bf_and_test(lv, v2, 4, 0, 7, hide_ull(1LL<<6), "B_BFu0i_BFu7s");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu7s(Test_B_BFu0i_BFu7s, "B_BFu0i_BFu7s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu8c  {
  bool v1;
  unsigned int  :0;
  unsigned char v2:8;
};
//SIG(1 B_BFu0i_BFu8c) C1{ Fc Fi:0 Fc:8}



static void Test_B_BFu0i_BFu8c()
{
  {
    init_simple_test("B_BFu0i_BFu8c");
    static B_BFu0i_BFu8c lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(B_BFu0i_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0i_BFu8c)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu8c.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "B_BFu0i_BFu8c");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "B_BFu0i_BFu8c");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu8c(Test_B_BFu0i_BFu8c, "B_BFu0i_BFu8c", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu8i  {
  bool v1;
  unsigned int  :0;
  unsigned int v2:8;
};
//SIG(1 B_BFu0i_BFu8i) C1{ Fc Fi:0 Fi:8}



static void Test_B_BFu0i_BFu8i()
{
  {
    init_simple_test("B_BFu0i_BFu8i");
    static B_BFu0i_BFu8i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0i_BFu8i)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu8i.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "B_BFu0i_BFu8i");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "B_BFu0i_BFu8i");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu8i(Test_B_BFu0i_BFu8i, "B_BFu0i_BFu8i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu8ll  {
  bool v1;
  unsigned int  :0;
  __tsu64 v2:8;
};
//SIG(1 B_BFu0i_BFu8ll) C1{ Fc Fi:0 FL:8}



static void Test_B_BFu0i_BFu8ll()
{
  {
    init_simple_test("B_BFu0i_BFu8ll");
    static B_BFu0i_BFu8ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_BFu8ll)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu8ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "B_BFu0i_BFu8ll");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "B_BFu0i_BFu8ll");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu8ll(Test_B_BFu0i_BFu8ll, "B_BFu0i_BFu8ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu8s  {
  bool v1;
  unsigned int  :0;
  unsigned short v2:8;
};
//SIG(1 B_BFu0i_BFu8s) C1{ Fc Fi:0 Fs:8}



static void Test_B_BFu0i_BFu8s()
{
  {
    init_simple_test("B_BFu0i_BFu8s");
    static B_BFu0i_BFu8s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(B_BFu0i_BFu8s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0i_BFu8s)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu8s.v1");
    set_bf_and_test(lv, v2, 4, 0, 8, 1, "B_BFu0i_BFu8s");
    set_bf_and_test(lv, v2, 4, 0, 8, hide_ull(1LL<<7), "B_BFu0i_BFu8s");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu8s(Test_B_BFu0i_BFu8s, "B_BFu0i_BFu8s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu9i  {
  bool v1;
  unsigned int  :0;
  unsigned int v2:9;
};
//SIG(1 B_BFu0i_BFu9i) C1{ Fc Fi:0 Fi:9}



static void Test_B_BFu0i_BFu9i()
{
  {
    init_simple_test("B_BFu0i_BFu9i");
    static B_BFu0i_BFu9i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0i_BFu9i)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu9i.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "B_BFu0i_BFu9i");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "B_BFu0i_BFu9i");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu9i(Test_B_BFu0i_BFu9i, "B_BFu0i_BFu9i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu9ll  {
  bool v1;
  unsigned int  :0;
  __tsu64 v2:9;
};
//SIG(1 B_BFu0i_BFu9ll) C1{ Fc Fi:0 FL:9}



static void Test_B_BFu0i_BFu9ll()
{
  {
    init_simple_test("B_BFu0i_BFu9ll");
    static B_BFu0i_BFu9ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_BFu9ll)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu9ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "B_BFu0i_BFu9ll");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "B_BFu0i_BFu9ll");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu9ll(Test_B_BFu0i_BFu9ll, "B_BFu0i_BFu9ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_BFu9s  {
  bool v1;
  unsigned int  :0;
  unsigned short v2:9;
};
//SIG(1 B_BFu0i_BFu9s) C1{ Fc Fi:0 Fs:9}



static void Test_B_BFu0i_BFu9s()
{
  {
    init_simple_test("B_BFu0i_BFu9s");
    static B_BFu0i_BFu9s lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(B_BFu0i_BFu9s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0i_BFu9s)");
    check_field_offset(lv, v1, 0, "B_BFu0i_BFu9s.v1");
    set_bf_and_test(lv, v2, 4, 0, 9, 1, "B_BFu0i_BFu9s");
    set_bf_and_test(lv, v2, 4, 0, 9, hide_ull(1LL<<8), "B_BFu0i_BFu9s");
  }
}
static Arrange_To_Call_Me vB_BFu0i_BFu9s(Test_B_BFu0i_BFu9s, "B_BFu0i_BFu9s", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_C  {
  bool v1;
  unsigned int  :0;
  char v2;
};
//SIG(1 B_BFu0i_C) C1{ Fc Fi:0 Fc}



static void Test_B_BFu0i_C()
{
  {
    init_simple_test("B_BFu0i_C");
    static B_BFu0i_C lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(B_BFu0i_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0i_C)");
    check_field_offset(lv, v1, 0, "B_BFu0i_C.v1");
    check_field_offset(lv, v2, 4, "B_BFu0i_C.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_C(Test_B_BFu0i_C, "B_BFu0i_C", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_D  {
  bool v1;
  unsigned int  :0;
  double v2;
};
//SIG(1 B_BFu0i_D) C1{ Fc Fi:0 FL}



static void Test_B_BFu0i_D()
{
  {
    init_simple_test("B_BFu0i_D");
    static B_BFu0i_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0i_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_D)");
    check_field_offset(lv, v1, 0, "B_BFu0i_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0i_D.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_D(Test_B_BFu0i_D, "B_BFu0i_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_F  {
  bool v1;
  unsigned int  :0;
  float v2;
};
//SIG(1 B_BFu0i_F) C1{ Fc Fi:0 Fi}



static void Test_B_BFu0i_F()
{
  {
    init_simple_test("B_BFu0i_F");
    static B_BFu0i_F lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_F)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0i_F)");
    check_field_offset(lv, v1, 0, "B_BFu0i_F.v1");
    check_field_offset(lv, v2, 4, "B_BFu0i_F.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_F(Test_B_BFu0i_F, "B_BFu0i_F", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_I  {
  bool v1;
  unsigned int  :0;
  int v2;
};
//SIG(1 B_BFu0i_I) C1{ Fc Fi:0 Fi}



static void Test_B_BFu0i_I()
{
  {
    init_simple_test("B_BFu0i_I");
    static B_BFu0i_I lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_I)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0i_I)");
    check_field_offset(lv, v1, 0, "B_BFu0i_I.v1");
    check_field_offset(lv, v2, 4, "B_BFu0i_I.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_I(Test_B_BFu0i_I, "B_BFu0i_I", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_Ip  {
  bool v1;
  unsigned int  :0;
  int *v2;
};
//SIG(1 B_BFu0i_Ip) C1{ Fc Fi:0 Fp}



static void Test_B_BFu0i_Ip()
{
  {
    init_simple_test("B_BFu0i_Ip");
    static B_BFu0i_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0i_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_Ip)");
    check_field_offset(lv, v1, 0, "B_BFu0i_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0i_Ip.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_Ip(Test_B_BFu0i_Ip, "B_BFu0i_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_L  {
  bool v1;
  unsigned int  :0;
  __tsi64 v2;
};
//SIG(1 B_BFu0i_L) C1{ Fc Fi:0 FL}



static void Test_B_BFu0i_L()
{
  {
    init_simple_test("B_BFu0i_L");
    static B_BFu0i_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0i_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_L)");
    check_field_offset(lv, v1, 0, "B_BFu0i_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0i_L.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_L(Test_B_BFu0i_L, "B_BFu0i_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_S  {
  bool v1;
  unsigned int  :0;
  short v2;
};
//SIG(1 B_BFu0i_S) C1{ Fc Fi:0 Fs}



static void Test_B_BFu0i_S()
{
  {
    init_simple_test("B_BFu0i_S");
    static B_BFu0i_S lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(B_BFu0i_S)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0i_S)");
    check_field_offset(lv, v1, 0, "B_BFu0i_S.v1");
    check_field_offset(lv, v2, 4, "B_BFu0i_S.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_S(Test_B_BFu0i_S, "B_BFu0i_S", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_Uc  {
  bool v1;
  unsigned int  :0;
  unsigned char v2;
};
//SIG(1 B_BFu0i_Uc) C1{ Fc Fi:0 Fc}



static void Test_B_BFu0i_Uc()
{
  {
    init_simple_test("B_BFu0i_Uc");
    static B_BFu0i_Uc lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(B_BFu0i_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0i_Uc)");
    check_field_offset(lv, v1, 0, "B_BFu0i_Uc.v1");
    check_field_offset(lv, v2, 4, "B_BFu0i_Uc.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_Uc(Test_B_BFu0i_Uc, "B_BFu0i_Uc", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_Ui  {
  bool v1;
  unsigned int  :0;
  unsigned int v2;
};
//SIG(1 B_BFu0i_Ui) C1{ Fc Fi:0 Fi}



static void Test_B_BFu0i_Ui()
{
  {
    init_simple_test("B_BFu0i_Ui");
    static B_BFu0i_Ui lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0i_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0i_Ui)");
    check_field_offset(lv, v1, 0, "B_BFu0i_Ui.v1");
    check_field_offset(lv, v2, 4, "B_BFu0i_Ui.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_Ui(Test_B_BFu0i_Ui, "B_BFu0i_Ui", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_Ul  {
  bool v1;
  unsigned int  :0;
  __tsu64 v2;
};
//SIG(1 B_BFu0i_Ul) C1{ Fc Fi:0 FL}



static void Test_B_BFu0i_Ul()
{
  {
    init_simple_test("B_BFu0i_Ul");
    static B_BFu0i_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0i_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_Ul)");
    check_field_offset(lv, v1, 0, "B_BFu0i_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0i_Ul.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_Ul(Test_B_BFu0i_Ul, "B_BFu0i_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_Us  {
  bool v1;
  unsigned int  :0;
  unsigned short v2;
};
//SIG(1 B_BFu0i_Us) C1{ Fc Fi:0 Fs}



static void Test_B_BFu0i_Us()
{
  {
    init_simple_test("B_BFu0i_Us");
    static B_BFu0i_Us lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(B_BFu0i_Us)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0i_Us)");
    check_field_offset(lv, v1, 0, "B_BFu0i_Us.v1");
    check_field_offset(lv, v2, 4, "B_BFu0i_Us.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_Us(Test_B_BFu0i_Us, "B_BFu0i_Us", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_Vp  {
  bool v1;
  unsigned int  :0;
  void *v2;
};
//SIG(1 B_BFu0i_Vp) C1{ Fc Fi:0 Fp}



static void Test_B_BFu0i_Vp()
{
  {
    init_simple_test("B_BFu0i_Vp");
    static B_BFu0i_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0i_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0i_Vp)");
    check_field_offset(lv, v1, 0, "B_BFu0i_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0i_Vp.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_Vp(Test_B_BFu0i_Vp, "B_BFu0i_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll  {
  bool v1;
  __tsu64  :0;
};
//SIG(1 B_BFu0ll) C1{ Fc FL:0}



static void Test_B_BFu0ll()
{
  {
    init_simple_test("B_BFu0ll");
    static B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0ll(Test_B_BFu0ll, "B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_B  {
  bool v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 B_BFu0ll_B) C1{ Fc FL:0 Fc}



static void Test_B_BFu0ll_B()
{
  {
    init_simple_test("B_BFu0ll_B");
    static B_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(B_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_B(Test_B_BFu0ll_B, "B_BFu0ll_B", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu0c  {
  bool v1;
  __tsu64  :0;
  unsigned char  :0;
};
//SIG(1 B_BFu0ll_BFu0c) C1{ Fc FL:0 Fc:0}



static void Test_B_BFu0ll_BFu0c()
{
  {
    init_simple_test("B_BFu0ll_BFu0c");
    static B_BFu0ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0ll_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu0c(Test_B_BFu0ll_BFu0c, "B_BFu0ll_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu0i  {
  bool v1;
  __tsu64  :0;
  unsigned int  :0;
};
//SIG(1 B_BFu0ll_BFu0i) C1{ Fc FL:0 Fi:0}



static void Test_B_BFu0ll_BFu0i()
{
  {
    init_simple_test("B_BFu0ll_BFu0i");
    static B_BFu0ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0ll_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu0i(Test_B_BFu0ll_BFu0i, "B_BFu0ll_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu0ll  {
  bool v1;
  __tsu64  :0;
  __tsu64  :0;
};
//SIG(1 B_BFu0ll_BFu0ll) C1{ Fc FL:0 FL:0}



static void Test_B_BFu0ll_BFu0ll()
{
  {
    init_simple_test("B_BFu0ll_BFu0ll");
    static B_BFu0ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu0ll(Test_B_BFu0ll_BFu0ll, "B_BFu0ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu0s  {
  bool v1;
  __tsu64  :0;
  unsigned short  :0;
};
//SIG(1 B_BFu0ll_BFu0s) C1{ Fc FL:0 Fs:0}



static void Test_B_BFu0ll_BFu0s()
{
  {
    init_simple_test("B_BFu0ll_BFu0s");
    static B_BFu0ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0ll_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu0s(Test_B_BFu0ll_BFu0s, "B_BFu0ll_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu15i  {
  bool v1;
  __tsu64  :0;
  unsigned int v2:15;
};
//SIG(1 B_BFu0ll_BFu15i) C1{ Fc FL:0 Fi:15}



static void Test_B_BFu0ll_BFu15i()
{
  {
    init_simple_test("B_BFu0ll_BFu15i");
    static B_BFu0ll_BFu15i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(B_BFu0ll_BFu15i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu0ll_BFu15i)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "B_BFu0ll_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "B_BFu0ll_BFu15i");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu15i(Test_B_BFu0ll_BFu15i, "B_BFu0ll_BFu15i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu15ll  {
  bool v1;
  __tsu64  :0;
  __tsu64 v2:15;
};
//SIG(1 B_BFu0ll_BFu15ll) C1{ Fc FL:0 FL:15}



static void Test_B_BFu0ll_BFu15ll()
{
  {
    init_simple_test("B_BFu0ll_BFu15ll");
    static B_BFu0ll_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0ll_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_BFu15ll)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "B_BFu0ll_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "B_BFu0ll_BFu15ll");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu15ll(Test_B_BFu0ll_BFu15ll, "B_BFu0ll_BFu15ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu15s  {
  bool v1;
  __tsu64  :0;
  unsigned short v2:15;
};
//SIG(1 B_BFu0ll_BFu15s) C1{ Fc FL:0 Fs:15}



static void Test_B_BFu0ll_BFu15s()
{
  {
    init_simple_test("B_BFu0ll_BFu15s");
    static B_BFu0ll_BFu15s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(B_BFu0ll_BFu15s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0ll_BFu15s)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, 1, "B_BFu0ll_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 15, hide_ull(1LL<<14), "B_BFu0ll_BFu15s");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu15s(Test_B_BFu0ll_BFu15s, "B_BFu0ll_BFu15s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu16i  {
  bool v1;
  __tsu64  :0;
  unsigned int v2:16;
};
//SIG(1 B_BFu0ll_BFu16i) C1{ Fc FL:0 Fi:16}



static void Test_B_BFu0ll_BFu16i()
{
  {
    init_simple_test("B_BFu0ll_BFu16i");
    static B_BFu0ll_BFu16i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(B_BFu0ll_BFu16i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu0ll_BFu16i)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "B_BFu0ll_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "B_BFu0ll_BFu16i");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu16i(Test_B_BFu0ll_BFu16i, "B_BFu0ll_BFu16i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu16ll  {
  bool v1;
  __tsu64  :0;
  __tsu64 v2:16;
};
//SIG(1 B_BFu0ll_BFu16ll) C1{ Fc FL:0 FL:16}



static void Test_B_BFu0ll_BFu16ll()
{
  {
    init_simple_test("B_BFu0ll_BFu16ll");
    static B_BFu0ll_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0ll_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_BFu16ll)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "B_BFu0ll_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "B_BFu0ll_BFu16ll");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu16ll(Test_B_BFu0ll_BFu16ll, "B_BFu0ll_BFu16ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu16s  {
  bool v1;
  __tsu64  :0;
  unsigned short v2:16;
};
//SIG(1 B_BFu0ll_BFu16s) C1{ Fc FL:0 Fs:16}



static void Test_B_BFu0ll_BFu16s()
{
  {
    init_simple_test("B_BFu0ll_BFu16s");
    static B_BFu0ll_BFu16s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(B_BFu0ll_BFu16s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0ll_BFu16s)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, 1, "B_BFu0ll_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 16, hide_ull(1LL<<15), "B_BFu0ll_BFu16s");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu16s(Test_B_BFu0ll_BFu16s, "B_BFu0ll_BFu16s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu17i  {
  bool v1;
  __tsu64  :0;
  unsigned int v2:17;
};
//SIG(1 B_BFu0ll_BFu17i) C1{ Fc FL:0 Fi:17}



static void Test_B_BFu0ll_BFu17i()
{
  {
    init_simple_test("B_BFu0ll_BFu17i");
    static B_BFu0ll_BFu17i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(B_BFu0ll_BFu17i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu0ll_BFu17i)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "B_BFu0ll_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "B_BFu0ll_BFu17i");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu17i(Test_B_BFu0ll_BFu17i, "B_BFu0ll_BFu17i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu17ll  {
  bool v1;
  __tsu64  :0;
  __tsu64 v2:17;
};
//SIG(1 B_BFu0ll_BFu17ll) C1{ Fc FL:0 FL:17}



static void Test_B_BFu0ll_BFu17ll()
{
  {
    init_simple_test("B_BFu0ll_BFu17ll");
    static B_BFu0ll_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0ll_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_BFu17ll)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, 1, "B_BFu0ll_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 17, hide_ull(1LL<<16), "B_BFu0ll_BFu17ll");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu17ll(Test_B_BFu0ll_BFu17ll, "B_BFu0ll_BFu17ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu1c  {
  bool v1;
  __tsu64  :0;
  unsigned char v2:1;
};
//SIG(1 B_BFu0ll_BFu1c) C1{ Fc FL:0 Fc:1}



static void Test_B_BFu0ll_BFu1c()
{
  {
    init_simple_test("B_BFu0ll_BFu1c");
    static B_BFu0ll_BFu1c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(B_BFu0ll_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0ll_BFu1c)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "B_BFu0ll_BFu1c");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu1c(Test_B_BFu0ll_BFu1c, "B_BFu0ll_BFu1c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu1i  {
  bool v1;
  __tsu64  :0;
  unsigned int v2:1;
};
//SIG(1 B_BFu0ll_BFu1i) C1{ Fc FL:0 Fi:1}



static void Test_B_BFu0ll_BFu1i()
{
  {
    init_simple_test("B_BFu0ll_BFu1i");
    static B_BFu0ll_BFu1i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(B_BFu0ll_BFu1i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu0ll_BFu1i)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "B_BFu0ll_BFu1i");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu1i(Test_B_BFu0ll_BFu1i, "B_BFu0ll_BFu1i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu1ll  {
  bool v1;
  __tsu64  :0;
  __tsu64 v2:1;
};
//SIG(1 B_BFu0ll_BFu1ll) C1{ Fc FL:0 FL:1}



static void Test_B_BFu0ll_BFu1ll()
{
  {
    init_simple_test("B_BFu0ll_BFu1ll");
    static B_BFu0ll_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0ll_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_BFu1ll)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "B_BFu0ll_BFu1ll");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu1ll(Test_B_BFu0ll_BFu1ll, "B_BFu0ll_BFu1ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu1s  {
  bool v1;
  __tsu64  :0;
  unsigned short v2:1;
};
//SIG(1 B_BFu0ll_BFu1s) C1{ Fc FL:0 Fs:1}



static void Test_B_BFu0ll_BFu1s()
{
  {
    init_simple_test("B_BFu0ll_BFu1s");
    static B_BFu0ll_BFu1s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(B_BFu0ll_BFu1s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0ll_BFu1s)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 1, 1, "B_BFu0ll_BFu1s");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu1s(Test_B_BFu0ll_BFu1s, "B_BFu0ll_BFu1s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu31i  {
  bool v1;
  __tsu64  :0;
  unsigned int v2:31;
};
//SIG(1 B_BFu0ll_BFu31i) C1{ Fc FL:0 Fi:31}



static void Test_B_BFu0ll_BFu31i()
{
  {
    init_simple_test("B_BFu0ll_BFu31i");
    static B_BFu0ll_BFu31i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(B_BFu0ll_BFu31i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu0ll_BFu31i)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "B_BFu0ll_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "B_BFu0ll_BFu31i");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu31i(Test_B_BFu0ll_BFu31i, "B_BFu0ll_BFu31i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu31ll  {
  bool v1;
  __tsu64  :0;
  __tsu64 v2:31;
};
//SIG(1 B_BFu0ll_BFu31ll) C1{ Fc FL:0 FL:31}



static void Test_B_BFu0ll_BFu31ll()
{
  {
    init_simple_test("B_BFu0ll_BFu31ll");
    static B_BFu0ll_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0ll_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_BFu31ll)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, 1, "B_BFu0ll_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 31, hide_ull(1LL<<30), "B_BFu0ll_BFu31ll");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu31ll(Test_B_BFu0ll_BFu31ll, "B_BFu0ll_BFu31ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu32i  {
  bool v1;
  __tsu64  :0;
  unsigned int v2:32;
};
//SIG(1 B_BFu0ll_BFu32i) C1{ Fc FL:0 Fi:32}



static void Test_B_BFu0ll_BFu32i()
{
  {
    init_simple_test("B_BFu0ll_BFu32i");
    static B_BFu0ll_BFu32i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(B_BFu0ll_BFu32i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu0ll_BFu32i)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "B_BFu0ll_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "B_BFu0ll_BFu32i");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu32i(Test_B_BFu0ll_BFu32i, "B_BFu0ll_BFu32i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu32ll  {
  bool v1;
  __tsu64  :0;
  __tsu64 v2:32;
};
//SIG(1 B_BFu0ll_BFu32ll) C1{ Fc FL:0 FL:32}



static void Test_B_BFu0ll_BFu32ll()
{
  {
    init_simple_test("B_BFu0ll_BFu32ll");
    static B_BFu0ll_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0ll_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_BFu32ll)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "B_BFu0ll_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "B_BFu0ll_BFu32ll");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu32ll(Test_B_BFu0ll_BFu32ll, "B_BFu0ll_BFu32ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu33  {
  bool v1;
  __tsu64  :0;
  __tsu64 v2:33;
};
//SIG(1 B_BFu0ll_BFu33) C1{ Fc FL:0 FL:33}



static void Test_B_BFu0ll_BFu33()
{
  {
    init_simple_test("B_BFu0ll_BFu33");
    static B_BFu0ll_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0ll_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_BFu33)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "B_BFu0ll_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "B_BFu0ll_BFu33");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu33(Test_B_BFu0ll_BFu33, "B_BFu0ll_BFu33", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu7c  {
  bool v1;
  __tsu64  :0;
  unsigned char v2:7;
};
//SIG(1 B_BFu0ll_BFu7c) C1{ Fc FL:0 Fc:7}



static void Test_B_BFu0ll_BFu7c()
{
  {
    init_simple_test("B_BFu0ll_BFu7c");
    static B_BFu0ll_BFu7c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(B_BFu0ll_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0ll_BFu7c)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "B_BFu0ll_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "B_BFu0ll_BFu7c");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu7c(Test_B_BFu0ll_BFu7c, "B_BFu0ll_BFu7c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu7i  {
  bool v1;
  __tsu64  :0;
  unsigned int v2:7;
};
//SIG(1 B_BFu0ll_BFu7i) C1{ Fc FL:0 Fi:7}



static void Test_B_BFu0ll_BFu7i()
{
  {
    init_simple_test("B_BFu0ll_BFu7i");
    static B_BFu0ll_BFu7i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(B_BFu0ll_BFu7i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu0ll_BFu7i)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "B_BFu0ll_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "B_BFu0ll_BFu7i");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu7i(Test_B_BFu0ll_BFu7i, "B_BFu0ll_BFu7i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu7ll  {
  bool v1;
  __tsu64  :0;
  __tsu64 v2:7;
};
//SIG(1 B_BFu0ll_BFu7ll) C1{ Fc FL:0 FL:7}



static void Test_B_BFu0ll_BFu7ll()
{
  {
    init_simple_test("B_BFu0ll_BFu7ll");
    static B_BFu0ll_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0ll_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_BFu7ll)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "B_BFu0ll_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "B_BFu0ll_BFu7ll");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu7ll(Test_B_BFu0ll_BFu7ll, "B_BFu0ll_BFu7ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu7s  {
  bool v1;
  __tsu64  :0;
  unsigned short v2:7;
};
//SIG(1 B_BFu0ll_BFu7s) C1{ Fc FL:0 Fs:7}



static void Test_B_BFu0ll_BFu7s()
{
  {
    init_simple_test("B_BFu0ll_BFu7s");
    static B_BFu0ll_BFu7s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(B_BFu0ll_BFu7s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0ll_BFu7s)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "B_BFu0ll_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "B_BFu0ll_BFu7s");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu7s(Test_B_BFu0ll_BFu7s, "B_BFu0ll_BFu7s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu8c  {
  bool v1;
  __tsu64  :0;
  unsigned char v2:8;
};
//SIG(1 B_BFu0ll_BFu8c) C1{ Fc FL:0 Fc:8}



static void Test_B_BFu0ll_BFu8c()
{
  {
    init_simple_test("B_BFu0ll_BFu8c");
    static B_BFu0ll_BFu8c lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(B_BFu0ll_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0ll_BFu8c)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "B_BFu0ll_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "B_BFu0ll_BFu8c");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu8c(Test_B_BFu0ll_BFu8c, "B_BFu0ll_BFu8c", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu8i  {
  bool v1;
  __tsu64  :0;
  unsigned int v2:8;
};
//SIG(1 B_BFu0ll_BFu8i) C1{ Fc FL:0 Fi:8}



static void Test_B_BFu0ll_BFu8i()
{
  {
    init_simple_test("B_BFu0ll_BFu8i");
    static B_BFu0ll_BFu8i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(B_BFu0ll_BFu8i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu0ll_BFu8i)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "B_BFu0ll_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "B_BFu0ll_BFu8i");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu8i(Test_B_BFu0ll_BFu8i, "B_BFu0ll_BFu8i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu8ll  {
  bool v1;
  __tsu64  :0;
  __tsu64 v2:8;
};
//SIG(1 B_BFu0ll_BFu8ll) C1{ Fc FL:0 FL:8}



static void Test_B_BFu0ll_BFu8ll()
{
  {
    init_simple_test("B_BFu0ll_BFu8ll");
    static B_BFu0ll_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0ll_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_BFu8ll)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "B_BFu0ll_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "B_BFu0ll_BFu8ll");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu8ll(Test_B_BFu0ll_BFu8ll, "B_BFu0ll_BFu8ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu8s  {
  bool v1;
  __tsu64  :0;
  unsigned short v2:8;
};
//SIG(1 B_BFu0ll_BFu8s) C1{ Fc FL:0 Fs:8}



static void Test_B_BFu0ll_BFu8s()
{
  {
    init_simple_test("B_BFu0ll_BFu8s");
    static B_BFu0ll_BFu8s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(B_BFu0ll_BFu8s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0ll_BFu8s)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "B_BFu0ll_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "B_BFu0ll_BFu8s");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu8s(Test_B_BFu0ll_BFu8s, "B_BFu0ll_BFu8s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu9i  {
  bool v1;
  __tsu64  :0;
  unsigned int v2:9;
};
//SIG(1 B_BFu0ll_BFu9i) C1{ Fc FL:0 Fi:9}



static void Test_B_BFu0ll_BFu9i()
{
  {
    init_simple_test("B_BFu0ll_BFu9i");
    static B_BFu0ll_BFu9i lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(B_BFu0ll_BFu9i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu0ll_BFu9i)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "B_BFu0ll_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "B_BFu0ll_BFu9i");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu9i(Test_B_BFu0ll_BFu9i, "B_BFu0ll_BFu9i", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu9ll  {
  bool v1;
  __tsu64  :0;
  __tsu64 v2:9;
};
//SIG(1 B_BFu0ll_BFu9ll) C1{ Fc FL:0 FL:9}



static void Test_B_BFu0ll_BFu9ll()
{
  {
    init_simple_test("B_BFu0ll_BFu9ll");
    static B_BFu0ll_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0ll_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_BFu9ll)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "B_BFu0ll_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "B_BFu0ll_BFu9ll");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu9ll(Test_B_BFu0ll_BFu9ll, "B_BFu0ll_BFu9ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_BFu9s  {
  bool v1;
  __tsu64  :0;
  unsigned short v2:9;
};
//SIG(1 B_BFu0ll_BFu9s) C1{ Fc FL:0 Fs:9}



static void Test_B_BFu0ll_BFu9s()
{
  {
    init_simple_test("B_BFu0ll_BFu9s");
    static B_BFu0ll_BFu9s lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(B_BFu0ll_BFu9s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0ll_BFu9s)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "B_BFu0ll_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "B_BFu0ll_BFu9s");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_BFu9s(Test_B_BFu0ll_BFu9s, "B_BFu0ll_BFu9s", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_C  {
  bool v1;
  __tsu64  :0;
  char v2;
};
//SIG(1 B_BFu0ll_C) C1{ Fc FL:0 Fc}



static void Test_B_BFu0ll_C()
{
  {
    init_simple_test("B_BFu0ll_C");
    static B_BFu0ll_C lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(B_BFu0ll_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0ll_C)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_C.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_C(Test_B_BFu0ll_C, "B_BFu0ll_C", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_D  {
  bool v1;
  __tsu64  :0;
  double v2;
};
//SIG(1 B_BFu0ll_D) C1{ Fc FL:0 FL}



static void Test_B_BFu0ll_D()
{
  {
    init_simple_test("B_BFu0ll_D");
    static B_BFu0ll_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0ll_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_D)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_D.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_D(Test_B_BFu0ll_D, "B_BFu0ll_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_F  {
  bool v1;
  __tsu64  :0;
  float v2;
};
//SIG(1 B_BFu0ll_F) C1{ Fc FL:0 Fi}



static void Test_B_BFu0ll_F()
{
  {
    init_simple_test("B_BFu0ll_F");
    static B_BFu0ll_F lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(B_BFu0ll_F)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu0ll_F)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_F.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_F(Test_B_BFu0ll_F, "B_BFu0ll_F", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_I  {
  bool v1;
  __tsu64  :0;
  int v2;
};
//SIG(1 B_BFu0ll_I) C1{ Fc FL:0 Fi}



static void Test_B_BFu0ll_I()
{
  {
    init_simple_test("B_BFu0ll_I");
    static B_BFu0ll_I lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(B_BFu0ll_I)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu0ll_I)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_I.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_I(Test_B_BFu0ll_I, "B_BFu0ll_I", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_Ip  {
  bool v1;
  __tsu64  :0;
  int *v2;
};
//SIG(1 B_BFu0ll_Ip) C1{ Fc FL:0 Fp}



static void Test_B_BFu0ll_Ip()
{
  {
    init_simple_test("B_BFu0ll_Ip");
    static B_BFu0ll_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0ll_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_Ip)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_Ip.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_Ip(Test_B_BFu0ll_Ip, "B_BFu0ll_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_L  {
  bool v1;
  __tsu64  :0;
  __tsi64 v2;
};
//SIG(1 B_BFu0ll_L) C1{ Fc FL:0 FL}



static void Test_B_BFu0ll_L()
{
  {
    init_simple_test("B_BFu0ll_L");
    static B_BFu0ll_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0ll_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_L)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_L.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_L(Test_B_BFu0ll_L, "B_BFu0ll_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_S  {
  bool v1;
  __tsu64  :0;
  short v2;
};
//SIG(1 B_BFu0ll_S) C1{ Fc FL:0 Fs}



static void Test_B_BFu0ll_S()
{
  {
    init_simple_test("B_BFu0ll_S");
    static B_BFu0ll_S lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(B_BFu0ll_S)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0ll_S)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_S.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_S(Test_B_BFu0ll_S, "B_BFu0ll_S", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_Uc  {
  bool v1;
  __tsu64  :0;
  unsigned char v2;
};
//SIG(1 B_BFu0ll_Uc) C1{ Fc FL:0 Fc}



static void Test_B_BFu0ll_Uc()
{
  {
    init_simple_test("B_BFu0ll_Uc");
    static B_BFu0ll_Uc lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(B_BFu0ll_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0ll_Uc)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_Uc.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_Uc(Test_B_BFu0ll_Uc, "B_BFu0ll_Uc", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_Ui  {
  bool v1;
  __tsu64  :0;
  unsigned int v2;
};
//SIG(1 B_BFu0ll_Ui) C1{ Fc FL:0 Fi}



static void Test_B_BFu0ll_Ui()
{
  {
    init_simple_test("B_BFu0ll_Ui");
    static B_BFu0ll_Ui lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(B_BFu0ll_Ui)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu0ll_Ui)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_Ui.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_Ui(Test_B_BFu0ll_Ui, "B_BFu0ll_Ui", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_Ul  {
  bool v1;
  __tsu64  :0;
  __tsu64 v2;
};
//SIG(1 B_BFu0ll_Ul) C1{ Fc FL:0 FL}



static void Test_B_BFu0ll_Ul()
{
  {
    init_simple_test("B_BFu0ll_Ul");
    static B_BFu0ll_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0ll_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_Ul)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_Ul.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_Ul(Test_B_BFu0ll_Ul, "B_BFu0ll_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_Us  {
  bool v1;
  __tsu64  :0;
  unsigned short v2;
};
//SIG(1 B_BFu0ll_Us) C1{ Fc FL:0 Fs}



static void Test_B_BFu0ll_Us()
{
  {
    init_simple_test("B_BFu0ll_Us");
    static B_BFu0ll_Us lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(B_BFu0ll_Us)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu0ll_Us)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_Us.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_Us(Test_B_BFu0ll_Us, "B_BFu0ll_Us", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_Vp  {
  bool v1;
  __tsu64  :0;
  void *v2;
};
//SIG(1 B_BFu0ll_Vp) C1{ Fc FL:0 Fp}



static void Test_B_BFu0ll_Vp()
{
  {
    init_simple_test("B_BFu0ll_Vp");
    static B_BFu0ll_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0ll_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0ll_Vp)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_Vp.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_Vp(Test_B_BFu0ll_Vp, "B_BFu0ll_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s  {
  bool v1;
  unsigned short  :0;
};
//SIG(1 B_BFu0s) C1{ Fc Fs:0}



static void Test_B_BFu0s()
{
  {
    init_simple_test("B_BFu0s");
    static B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0s(Test_B_BFu0s, "B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_B  {
  bool v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 B_BFu0s_B) C1{ Fc Fs:0 Fc}



static void Test_B_BFu0s_B()
{
  {
    init_simple_test("B_BFu0s_B");
    static B_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(B_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0s_B)");
    check_field_offset(lv, v1, 0, "B_BFu0s_B.v1");
    check_field_offset(lv, v2, 2, "B_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_B(Test_B_BFu0s_B, "B_BFu0s_B", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu0c  {
  bool v1;
  unsigned short  :0;
  unsigned char  :0;
};
//SIG(1 B_BFu0s_BFu0c) C1{ Fc Fs:0 Fc:0}



static void Test_B_BFu0s_BFu0c()
{
  {
    init_simple_test("B_BFu0s_BFu0c");
    static B_BFu0s_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0s_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0s_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu0c(Test_B_BFu0s_BFu0c, "B_BFu0s_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu0i  {
  bool v1;
  unsigned short  :0;
  unsigned int  :0;
};
//SIG(1 B_BFu0s_BFu0i) C1{ Fc Fs:0 Fi:0}



static void Test_B_BFu0s_BFu0i()
{
  {
    init_simple_test("B_BFu0s_BFu0i");
    static B_BFu0s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0s_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu0i(Test_B_BFu0s_BFu0i, "B_BFu0s_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu0ll  {
  bool v1;
  unsigned short  :0;
  __tsu64  :0;
};
//SIG(1 B_BFu0s_BFu0ll) C1{ Fc Fs:0 FL:0}



static void Test_B_BFu0s_BFu0ll()
{
  {
    init_simple_test("B_BFu0s_BFu0ll");
    static B_BFu0s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0s_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu0ll(Test_B_BFu0s_BFu0ll, "B_BFu0s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu0s  {
  bool v1;
  unsigned short  :0;
  unsigned short  :0;
};
//SIG(1 B_BFu0s_BFu0s) C1{ Fc Fs:0 Fs:0}



static void Test_B_BFu0s_BFu0s()
{
  {
    init_simple_test("B_BFu0s_BFu0s");
    static B_BFu0s_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0s_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu0s(Test_B_BFu0s_BFu0s, "B_BFu0s_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu15i  {
  bool v1;
  unsigned short  :0;
  unsigned int v2:15;
};
//SIG(1 B_BFu0s_BFu15i) C1{ Fc Fs:0 Fi:15}



static void Test_B_BFu0s_BFu15i()
{
  {
    init_simple_test("B_BFu0s_BFu15i");
    static B_BFu0s_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0s_BFu15i)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu15i.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "B_BFu0s_BFu15i");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "B_BFu0s_BFu15i");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu15i(Test_B_BFu0s_BFu15i, "B_BFu0s_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu15ll  {
  bool v1;
  unsigned short  :0;
  __tsu64 v2:15;
};
//SIG(1 B_BFu0s_BFu15ll) C1{ Fc Fs:0 FL:15}



static void Test_B_BFu0s_BFu15ll()
{
  {
    init_simple_test("B_BFu0s_BFu15ll");
    static B_BFu0s_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_BFu15ll)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu15ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "B_BFu0s_BFu15ll");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "B_BFu0s_BFu15ll");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu15ll(Test_B_BFu0s_BFu15ll, "B_BFu0s_BFu15ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu15s  {
  bool v1;
  unsigned short  :0;
  unsigned short v2:15;
};
//SIG(1 B_BFu0s_BFu15s) C1{ Fc Fs:0 Fs:15}



static void Test_B_BFu0s_BFu15s()
{
  {
    init_simple_test("B_BFu0s_BFu15s");
    static B_BFu0s_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu15s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0s_BFu15s)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu15s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "B_BFu0s_BFu15s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "B_BFu0s_BFu15s");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu15s(Test_B_BFu0s_BFu15s, "B_BFu0s_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu16i  {
  bool v1;
  unsigned short  :0;
  unsigned int v2:16;
};
//SIG(1 B_BFu0s_BFu16i) C1{ Fc Fs:0 Fi:16}



static void Test_B_BFu0s_BFu16i()
{
  {
    init_simple_test("B_BFu0s_BFu16i");
    static B_BFu0s_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0s_BFu16i)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu16i.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "B_BFu0s_BFu16i");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "B_BFu0s_BFu16i");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu16i(Test_B_BFu0s_BFu16i, "B_BFu0s_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu16ll  {
  bool v1;
  unsigned short  :0;
  __tsu64 v2:16;
};
//SIG(1 B_BFu0s_BFu16ll) C1{ Fc Fs:0 FL:16}



static void Test_B_BFu0s_BFu16ll()
{
  {
    init_simple_test("B_BFu0s_BFu16ll");
    static B_BFu0s_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_BFu16ll)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu16ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "B_BFu0s_BFu16ll");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "B_BFu0s_BFu16ll");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu16ll(Test_B_BFu0s_BFu16ll, "B_BFu0s_BFu16ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu16s  {
  bool v1;
  unsigned short  :0;
  unsigned short v2:16;
};
//SIG(1 B_BFu0s_BFu16s) C1{ Fc Fs:0 Fs:16}



static void Test_B_BFu0s_BFu16s()
{
  {
    init_simple_test("B_BFu0s_BFu16s");
    static B_BFu0s_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu16s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0s_BFu16s)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu16s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "B_BFu0s_BFu16s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "B_BFu0s_BFu16s");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu16s(Test_B_BFu0s_BFu16s, "B_BFu0s_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu17i  {
  bool v1;
  unsigned short  :0;
  unsigned int v2:17;
};
//SIG(1 B_BFu0s_BFu17i) C1{ Fc Fs:0 Fi:17}



static void Test_B_BFu0s_BFu17i()
{
  {
    init_simple_test("B_BFu0s_BFu17i");
    static B_BFu0s_BFu17i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0s_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0s_BFu17i)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu17i.v1");
    set_bf_and_test(lv, v2, 4, 0, 17, 1, "B_BFu0s_BFu17i");
    set_bf_and_test(lv, v2, 4, 0, 17, hide_ull(1LL<<16), "B_BFu0s_BFu17i");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu17i(Test_B_BFu0s_BFu17i, "B_BFu0s_BFu17i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu17ll  {
  bool v1;
  unsigned short  :0;
  __tsu64 v2:17;
};
//SIG(1 B_BFu0s_BFu17ll) C1{ Fc Fs:0 FL:17}



static void Test_B_BFu0s_BFu17ll()
{
  {
    init_simple_test("B_BFu0s_BFu17ll");
    static B_BFu0s_BFu17ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_BFu17ll)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu17ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 17, 1, "B_BFu0s_BFu17ll");
    set_bf_and_test(lv, v2, 2, 0, 17, hide_ull(1LL<<16), "B_BFu0s_BFu17ll");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu17ll(Test_B_BFu0s_BFu17ll, "B_BFu0s_BFu17ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu1c  {
  bool v1;
  unsigned short  :0;
  unsigned char v2:1;
};
//SIG(1 B_BFu0s_BFu1c) C1{ Fc Fs:0 Fc:1}



static void Test_B_BFu0s_BFu1c()
{
  {
    init_simple_test("B_BFu0s_BFu1c");
    static B_BFu0s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(B_BFu0s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0s_BFu1c)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu1c.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "B_BFu0s_BFu1c");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu1c(Test_B_BFu0s_BFu1c, "B_BFu0s_BFu1c", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu1i  {
  bool v1;
  unsigned short  :0;
  unsigned int v2:1;
};
//SIG(1 B_BFu0s_BFu1i) C1{ Fc Fs:0 Fi:1}



static void Test_B_BFu0s_BFu1i()
{
  {
    init_simple_test("B_BFu0s_BFu1i");
    static B_BFu0s_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0s_BFu1i)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu1i.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "B_BFu0s_BFu1i");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu1i(Test_B_BFu0s_BFu1i, "B_BFu0s_BFu1i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu1ll  {
  bool v1;
  unsigned short  :0;
  __tsu64 v2:1;
};
//SIG(1 B_BFu0s_BFu1ll) C1{ Fc Fs:0 FL:1}



static void Test_B_BFu0s_BFu1ll()
{
  {
    init_simple_test("B_BFu0s_BFu1ll");
    static B_BFu0s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_BFu1ll)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu1ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "B_BFu0s_BFu1ll");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu1ll(Test_B_BFu0s_BFu1ll, "B_BFu0s_BFu1ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu1s  {
  bool v1;
  unsigned short  :0;
  unsigned short v2:1;
};
//SIG(1 B_BFu0s_BFu1s) C1{ Fc Fs:0 Fs:1}



static void Test_B_BFu0s_BFu1s()
{
  {
    init_simple_test("B_BFu0s_BFu1s");
    static B_BFu0s_BFu1s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu1s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0s_BFu1s)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu1s.v1");
    set_bf_and_test(lv, v2, 2, 0, 1, 1, "B_BFu0s_BFu1s");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu1s(Test_B_BFu0s_BFu1s, "B_BFu0s_BFu1s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu31i  {
  bool v1;
  unsigned short  :0;
  unsigned int v2:31;
};
//SIG(1 B_BFu0s_BFu31i) C1{ Fc Fs:0 Fi:31}



static void Test_B_BFu0s_BFu31i()
{
  {
    init_simple_test("B_BFu0s_BFu31i");
    static B_BFu0s_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0s_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0s_BFu31i)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu31i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "B_BFu0s_BFu31i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "B_BFu0s_BFu31i");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu31i(Test_B_BFu0s_BFu31i, "B_BFu0s_BFu31i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu31ll  {
  bool v1;
  unsigned short  :0;
  __tsu64 v2:31;
};
//SIG(1 B_BFu0s_BFu31ll) C1{ Fc Fs:0 FL:31}



static void Test_B_BFu0s_BFu31ll()
{
  {
    init_simple_test("B_BFu0s_BFu31ll");
    static B_BFu0s_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_BFu31ll)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu31ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 31, 1, "B_BFu0s_BFu31ll");
    set_bf_and_test(lv, v2, 2, 0, 31, hide_ull(1LL<<30), "B_BFu0s_BFu31ll");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu31ll(Test_B_BFu0s_BFu31ll, "B_BFu0s_BFu31ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu32i  {
  bool v1;
  unsigned short  :0;
  unsigned int v2:32;
};
//SIG(1 B_BFu0s_BFu32i) C1{ Fc Fs:0 Fi:32}



static void Test_B_BFu0s_BFu32i()
{
  {
    init_simple_test("B_BFu0s_BFu32i");
    static B_BFu0s_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0s_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0s_BFu32i)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu32i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "B_BFu0s_BFu32i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "B_BFu0s_BFu32i");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu32i(Test_B_BFu0s_BFu32i, "B_BFu0s_BFu32i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu32ll  {
  bool v1;
  unsigned short  :0;
  __tsu64 v2:32;
};
//SIG(1 B_BFu0s_BFu32ll) C1{ Fc Fs:0 FL:32}



static void Test_B_BFu0s_BFu32ll()
{
  {
    init_simple_test("B_BFu0s_BFu32ll");
    static B_BFu0s_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_BFu32ll)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu32ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 32, 1, "B_BFu0s_BFu32ll");
    set_bf_and_test(lv, v2, 2, 0, 32, hide_ull(1LL<<31), "B_BFu0s_BFu32ll");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu32ll(Test_B_BFu0s_BFu32ll, "B_BFu0s_BFu32ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu33  {
  bool v1;
  unsigned short  :0;
  __tsu64 v2:33;
};
//SIG(1 B_BFu0s_BFu33) C1{ Fc Fs:0 FL:33}



static void Test_B_BFu0s_BFu33()
{
  {
    init_simple_test("B_BFu0s_BFu33");
    static B_BFu0s_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0s_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_BFu33)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu33.v1");
    set_bf_and_test(lv, v2, 2, 0, 33, 1, "B_BFu0s_BFu33");
    set_bf_and_test(lv, v2, 2, 0, 33, hide_ull(1LL<<32), "B_BFu0s_BFu33");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu33(Test_B_BFu0s_BFu33, "B_BFu0s_BFu33", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu7c  {
  bool v1;
  unsigned short  :0;
  unsigned char v2:7;
};
//SIG(1 B_BFu0s_BFu7c) C1{ Fc Fs:0 Fc:7}



static void Test_B_BFu0s_BFu7c()
{
  {
    init_simple_test("B_BFu0s_BFu7c");
    static B_BFu0s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(B_BFu0s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0s_BFu7c)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu7c.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "B_BFu0s_BFu7c");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "B_BFu0s_BFu7c");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu7c(Test_B_BFu0s_BFu7c, "B_BFu0s_BFu7c", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu7i  {
  bool v1;
  unsigned short  :0;
  unsigned int v2:7;
};
//SIG(1 B_BFu0s_BFu7i) C1{ Fc Fs:0 Fi:7}



static void Test_B_BFu0s_BFu7i()
{
  {
    init_simple_test("B_BFu0s_BFu7i");
    static B_BFu0s_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0s_BFu7i)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu7i.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "B_BFu0s_BFu7i");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "B_BFu0s_BFu7i");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu7i(Test_B_BFu0s_BFu7i, "B_BFu0s_BFu7i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu7ll  {
  bool v1;
  unsigned short  :0;
  __tsu64 v2:7;
};
//SIG(1 B_BFu0s_BFu7ll) C1{ Fc Fs:0 FL:7}



static void Test_B_BFu0s_BFu7ll()
{
  {
    init_simple_test("B_BFu0s_BFu7ll");
    static B_BFu0s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_BFu7ll)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu7ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "B_BFu0s_BFu7ll");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "B_BFu0s_BFu7ll");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu7ll(Test_B_BFu0s_BFu7ll, "B_BFu0s_BFu7ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu7s  {
  bool v1;
  unsigned short  :0;
  unsigned short v2:7;
};
//SIG(1 B_BFu0s_BFu7s) C1{ Fc Fs:0 Fs:7}



static void Test_B_BFu0s_BFu7s()
{
  {
    init_simple_test("B_BFu0s_BFu7s");
    static B_BFu0s_BFu7s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu7s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0s_BFu7s)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu7s.v1");
    set_bf_and_test(lv, v2, 2, 0, 7, 1, "B_BFu0s_BFu7s");
    set_bf_and_test(lv, v2, 2, 0, 7, hide_ull(1LL<<6), "B_BFu0s_BFu7s");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu7s(Test_B_BFu0s_BFu7s, "B_BFu0s_BFu7s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu8c  {
  bool v1;
  unsigned short  :0;
  unsigned char v2:8;
};
//SIG(1 B_BFu0s_BFu8c) C1{ Fc Fs:0 Fc:8}



static void Test_B_BFu0s_BFu8c()
{
  {
    init_simple_test("B_BFu0s_BFu8c");
    static B_BFu0s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(B_BFu0s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0s_BFu8c)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu8c.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "B_BFu0s_BFu8c");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "B_BFu0s_BFu8c");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu8c(Test_B_BFu0s_BFu8c, "B_BFu0s_BFu8c", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu8i  {
  bool v1;
  unsigned short  :0;
  unsigned int v2:8;
};
//SIG(1 B_BFu0s_BFu8i) C1{ Fc Fs:0 Fi:8}



static void Test_B_BFu0s_BFu8i()
{
  {
    init_simple_test("B_BFu0s_BFu8i");
    static B_BFu0s_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0s_BFu8i)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu8i.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "B_BFu0s_BFu8i");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "B_BFu0s_BFu8i");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu8i(Test_B_BFu0s_BFu8i, "B_BFu0s_BFu8i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu8ll  {
  bool v1;
  unsigned short  :0;
  __tsu64 v2:8;
};
//SIG(1 B_BFu0s_BFu8ll) C1{ Fc Fs:0 FL:8}



static void Test_B_BFu0s_BFu8ll()
{
  {
    init_simple_test("B_BFu0s_BFu8ll");
    static B_BFu0s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_BFu8ll)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu8ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "B_BFu0s_BFu8ll");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "B_BFu0s_BFu8ll");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu8ll(Test_B_BFu0s_BFu8ll, "B_BFu0s_BFu8ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu8s  {
  bool v1;
  unsigned short  :0;
  unsigned short v2:8;
};
//SIG(1 B_BFu0s_BFu8s) C1{ Fc Fs:0 Fs:8}



static void Test_B_BFu0s_BFu8s()
{
  {
    init_simple_test("B_BFu0s_BFu8s");
    static B_BFu0s_BFu8s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu8s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0s_BFu8s)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu8s.v1");
    set_bf_and_test(lv, v2, 2, 0, 8, 1, "B_BFu0s_BFu8s");
    set_bf_and_test(lv, v2, 2, 0, 8, hide_ull(1LL<<7), "B_BFu0s_BFu8s");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu8s(Test_B_BFu0s_BFu8s, "B_BFu0s_BFu8s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu9i  {
  bool v1;
  unsigned short  :0;
  unsigned int v2:9;
};
//SIG(1 B_BFu0s_BFu9i) C1{ Fc Fs:0 Fi:9}



static void Test_B_BFu0s_BFu9i()
{
  {
    init_simple_test("B_BFu0s_BFu9i");
    static B_BFu0s_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0s_BFu9i)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu9i.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "B_BFu0s_BFu9i");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "B_BFu0s_BFu9i");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu9i(Test_B_BFu0s_BFu9i, "B_BFu0s_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu9ll  {
  bool v1;
  unsigned short  :0;
  __tsu64 v2:9;
};
//SIG(1 B_BFu0s_BFu9ll) C1{ Fc Fs:0 FL:9}



static void Test_B_BFu0s_BFu9ll()
{
  {
    init_simple_test("B_BFu0s_BFu9ll");
    static B_BFu0s_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu0s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_BFu9ll)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu9ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "B_BFu0s_BFu9ll");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "B_BFu0s_BFu9ll");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu9ll(Test_B_BFu0s_BFu9ll, "B_BFu0s_BFu9ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_BFu9s  {
  bool v1;
  unsigned short  :0;
  unsigned short v2:9;
};
//SIG(1 B_BFu0s_BFu9s) C1{ Fc Fs:0 Fs:9}



static void Test_B_BFu0s_BFu9s()
{
  {
    init_simple_test("B_BFu0s_BFu9s");
    static B_BFu0s_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_BFu9s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0s_BFu9s)");
    check_field_offset(lv, v1, 0, "B_BFu0s_BFu9s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "B_BFu0s_BFu9s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "B_BFu0s_BFu9s");
  }
}
static Arrange_To_Call_Me vB_BFu0s_BFu9s(Test_B_BFu0s_BFu9s, "B_BFu0s_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_C  {
  bool v1;
  unsigned short  :0;
  char v2;
};
//SIG(1 B_BFu0s_C) C1{ Fc Fs:0 Fc}



static void Test_B_BFu0s_C()
{
  {
    init_simple_test("B_BFu0s_C");
    static B_BFu0s_C lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(B_BFu0s_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0s_C)");
    check_field_offset(lv, v1, 0, "B_BFu0s_C.v1");
    check_field_offset(lv, v2, 2, "B_BFu0s_C.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_C(Test_B_BFu0s_C, "B_BFu0s_C", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_D  {
  bool v1;
  unsigned short  :0;
  double v2;
};
//SIG(1 B_BFu0s_D) C1{ Fc Fs:0 FL}



static void Test_B_BFu0s_D()
{
  {
    init_simple_test("B_BFu0s_D");
    static B_BFu0s_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0s_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_D)");
    check_field_offset(lv, v1, 0, "B_BFu0s_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0s_D.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_D(Test_B_BFu0s_D, "B_BFu0s_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_F  {
  bool v1;
  unsigned short  :0;
  float v2;
};
//SIG(1 B_BFu0s_F) C1{ Fc Fs:0 Fi}



static void Test_B_BFu0s_F()
{
  {
    init_simple_test("B_BFu0s_F");
    static B_BFu0s_F lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0s_F)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0s_F)");
    check_field_offset(lv, v1, 0, "B_BFu0s_F.v1");
    check_field_offset(lv, v2, 4, "B_BFu0s_F.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_F(Test_B_BFu0s_F, "B_BFu0s_F", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_I  {
  bool v1;
  unsigned short  :0;
  int v2;
};
//SIG(1 B_BFu0s_I) C1{ Fc Fs:0 Fi}



static void Test_B_BFu0s_I()
{
  {
    init_simple_test("B_BFu0s_I");
    static B_BFu0s_I lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0s_I)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0s_I)");
    check_field_offset(lv, v1, 0, "B_BFu0s_I.v1");
    check_field_offset(lv, v2, 4, "B_BFu0s_I.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_I(Test_B_BFu0s_I, "B_BFu0s_I", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_Ip  {
  bool v1;
  unsigned short  :0;
  int *v2;
};
//SIG(1 B_BFu0s_Ip) C1{ Fc Fs:0 Fp}



static void Test_B_BFu0s_Ip()
{
  {
    init_simple_test("B_BFu0s_Ip");
    static B_BFu0s_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0s_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_Ip)");
    check_field_offset(lv, v1, 0, "B_BFu0s_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0s_Ip.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_Ip(Test_B_BFu0s_Ip, "B_BFu0s_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_L  {
  bool v1;
  unsigned short  :0;
  __tsi64 v2;
};
//SIG(1 B_BFu0s_L) C1{ Fc Fs:0 FL}



static void Test_B_BFu0s_L()
{
  {
    init_simple_test("B_BFu0s_L");
    static B_BFu0s_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0s_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_L)");
    check_field_offset(lv, v1, 0, "B_BFu0s_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0s_L.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_L(Test_B_BFu0s_L, "B_BFu0s_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_S  {
  bool v1;
  unsigned short  :0;
  short v2;
};
//SIG(1 B_BFu0s_S) C1{ Fc Fs:0 Fs}



static void Test_B_BFu0s_S()
{
  {
    init_simple_test("B_BFu0s_S");
    static B_BFu0s_S lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_S)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0s_S)");
    check_field_offset(lv, v1, 0, "B_BFu0s_S.v1");
    check_field_offset(lv, v2, 2, "B_BFu0s_S.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_S(Test_B_BFu0s_S, "B_BFu0s_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_Uc  {
  bool v1;
  unsigned short  :0;
  unsigned char v2;
};
//SIG(1 B_BFu0s_Uc) C1{ Fc Fs:0 Fc}



static void Test_B_BFu0s_Uc()
{
  {
    init_simple_test("B_BFu0s_Uc");
    static B_BFu0s_Uc lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(B_BFu0s_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0s_Uc)");
    check_field_offset(lv, v1, 0, "B_BFu0s_Uc.v1");
    check_field_offset(lv, v2, 2, "B_BFu0s_Uc.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_Uc(Test_B_BFu0s_Uc, "B_BFu0s_Uc", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_Ui  {
  bool v1;
  unsigned short  :0;
  unsigned int v2;
};
//SIG(1 B_BFu0s_Ui) C1{ Fc Fs:0 Fi}



static void Test_B_BFu0s_Ui()
{
  {
    init_simple_test("B_BFu0s_Ui");
    static B_BFu0s_Ui lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu0s_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu0s_Ui)");
    check_field_offset(lv, v1, 0, "B_BFu0s_Ui.v1");
    check_field_offset(lv, v2, 4, "B_BFu0s_Ui.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_Ui(Test_B_BFu0s_Ui, "B_BFu0s_Ui", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_Ul  {
  bool v1;
  unsigned short  :0;
  __tsu64 v2;
};
//SIG(1 B_BFu0s_Ul) C1{ Fc Fs:0 FL}



static void Test_B_BFu0s_Ul()
{
  {
    init_simple_test("B_BFu0s_Ul");
    static B_BFu0s_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_BFu0s_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_Ul)");
    check_field_offset(lv, v1, 0, "B_BFu0s_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0s_Ul.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_Ul(Test_B_BFu0s_Ul, "B_BFu0s_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_Us  {
  bool v1;
  unsigned short  :0;
  unsigned short v2;
};
//SIG(1 B_BFu0s_Us) C1{ Fc Fs:0 Fs}



static void Test_B_BFu0s_Us()
{
  {
    init_simple_test("B_BFu0s_Us");
    static B_BFu0s_Us lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu0s_Us)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu0s_Us)");
    check_field_offset(lv, v1, 0, "B_BFu0s_Us.v1");
    check_field_offset(lv, v2, 2, "B_BFu0s_Us.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_Us(Test_B_BFu0s_Us, "B_BFu0s_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_Vp  {
  bool v1;
  unsigned short  :0;
  void *v2;
};
//SIG(1 B_BFu0s_Vp) C1{ Fc Fs:0 Fp}



static void Test_B_BFu0s_Vp()
{
  {
    init_simple_test("B_BFu0s_Vp");
    static B_BFu0s_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_BFu0s_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu0s_Vp)");
    check_field_offset(lv, v1, 0, "B_BFu0s_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0s_Vp.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_Vp(Test_B_BFu0s_Vp, "B_BFu0s_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15i_BFu0c  {
  bool v1;
  unsigned int v2:15;
  unsigned char  :0;
};
//SIG(1 B_BFu15i_BFu0c) C1{ Fc Fi:15 Fc:0}



static void Test_B_BFu15i_BFu0c()
{
  {
    init_simple_test("B_BFu15i_BFu0c");
    static B_BFu15i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu15i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu15i_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu15i_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15i_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15i_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu15i_BFu0c(Test_B_BFu15i_BFu0c, "B_BFu15i_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15i_BFu0i  {
  bool v1;
  unsigned int v2:15;
  unsigned int  :0;
};
//SIG(1 B_BFu15i_BFu0i) C1{ Fc Fi:15 Fi:0}



static void Test_B_BFu15i_BFu0i()
{
  {
    init_simple_test("B_BFu15i_BFu0i");
    static B_BFu15i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu15i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu15i_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu15i_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15i_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15i_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu15i_BFu0i(Test_B_BFu15i_BFu0i, "B_BFu15i_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15i_BFu0ll  {
  bool v1;
  unsigned int v2:15;
  __tsu64  :0;
};
//SIG(1 B_BFu15i_BFu0ll) C1{ Fc Fi:15 FL:0}



static void Test_B_BFu15i_BFu0ll()
{
  {
    init_simple_test("B_BFu15i_BFu0ll");
    static B_BFu15i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu15i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu15i_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu15i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15i_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15i_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu15i_BFu0ll(Test_B_BFu15i_BFu0ll, "B_BFu15i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15i_BFu0s  {
  bool v1;
  unsigned int v2:15;
  unsigned short  :0;
};
//SIG(1 B_BFu15i_BFu0s) C1{ Fc Fi:15 Fs:0}



static void Test_B_BFu15i_BFu0s()
{
  {
    init_simple_test("B_BFu15i_BFu0s");
    static B_BFu15i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu15i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu15i_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu15i_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15i_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15i_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu15i_BFu0s(Test_B_BFu15i_BFu0s, "B_BFu15i_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15ll_BFu0c  {
  bool v1;
  __tsu64 v2:15;
  unsigned char  :0;
};
//SIG(1 B_BFu15ll_BFu0c) C1{ Fc FL:15 Fc:0}



static void Test_B_BFu15ll_BFu0c()
{
  {
    init_simple_test("B_BFu15ll_BFu0c");
    static B_BFu15ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu15ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu15ll_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu15ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15ll_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15ll_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu15ll_BFu0c(Test_B_BFu15ll_BFu0c, "B_BFu15ll_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15ll_BFu0i  {
  bool v1;
  __tsu64 v2:15;
  unsigned int  :0;
};
//SIG(1 B_BFu15ll_BFu0i) C1{ Fc FL:15 Fi:0}



static void Test_B_BFu15ll_BFu0i()
{
  {
    init_simple_test("B_BFu15ll_BFu0i");
    static B_BFu15ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu15ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu15ll_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu15ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15ll_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15ll_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu15ll_BFu0i(Test_B_BFu15ll_BFu0i, "B_BFu15ll_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15ll_BFu0ll  {
  bool v1;
  __tsu64 v2:15;
  __tsu64  :0;
};
//SIG(1 B_BFu15ll_BFu0ll) C1{ Fc FL:15 FL:0}



static void Test_B_BFu15ll_BFu0ll()
{
  {
    init_simple_test("B_BFu15ll_BFu0ll");
    static B_BFu15ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu15ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu15ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu15ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15ll_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu15ll_BFu0ll(Test_B_BFu15ll_BFu0ll, "B_BFu15ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15ll_BFu0s  {
  bool v1;
  __tsu64 v2:15;
  unsigned short  :0;
};
//SIG(1 B_BFu15ll_BFu0s) C1{ Fc FL:15 Fs:0}



static void Test_B_BFu15ll_BFu0s()
{
  {
    init_simple_test("B_BFu15ll_BFu0s");
    static B_BFu15ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu15ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu15ll_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu15ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "B_BFu15ll_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "B_BFu15ll_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu15ll_BFu0s(Test_B_BFu15ll_BFu0s, "B_BFu15ll_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15s_BFu0c  {
  bool v1;
  unsigned short v2:15;
  unsigned char  :0;
};
//SIG(1 B_BFu15s_BFu0c) C1{ Fc Fs:15 Fc:0}



static void Test_B_BFu15s_BFu0c()
{
  {
    init_simple_test("B_BFu15s_BFu0c");
    static B_BFu15s_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu15s_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu15s_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu15s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "B_BFu15s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "B_BFu15s_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu15s_BFu0c(Test_B_BFu15s_BFu0c, "B_BFu15s_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15s_BFu0i  {
  bool v1;
  unsigned short v2:15;
  unsigned int  :0;
};
//SIG(1 B_BFu15s_BFu0i) C1{ Fc Fs:15 Fi:0}



static void Test_B_BFu15s_BFu0i()
{
  {
    init_simple_test("B_BFu15s_BFu0i");
    static B_BFu15s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu15s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu15s_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu15s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "B_BFu15s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "B_BFu15s_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu15s_BFu0i(Test_B_BFu15s_BFu0i, "B_BFu15s_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15s_BFu0ll  {
  bool v1;
  unsigned short v2:15;
  __tsu64  :0;
};
//SIG(1 B_BFu15s_BFu0ll) C1{ Fc Fs:15 FL:0}



static void Test_B_BFu15s_BFu0ll()
{
  {
    init_simple_test("B_BFu15s_BFu0ll");
    static B_BFu15s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu15s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu15s_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu15s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "B_BFu15s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "B_BFu15s_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu15s_BFu0ll(Test_B_BFu15s_BFu0ll, "B_BFu15s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu15s_BFu0s  {
  bool v1;
  unsigned short v2:15;
  unsigned short  :0;
};
//SIG(1 B_BFu15s_BFu0s) C1{ Fc Fs:15 Fs:0}



static void Test_B_BFu15s_BFu0s()
{
  {
    init_simple_test("B_BFu15s_BFu0s");
    static B_BFu15s_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu15s_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu15s_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu15s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "B_BFu15s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "B_BFu15s_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu15s_BFu0s(Test_B_BFu15s_BFu0s, "B_BFu15s_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16i_BFu0c  {
  bool v1;
  unsigned int v2:16;
  unsigned char  :0;
};
//SIG(1 B_BFu16i_BFu0c) C1{ Fc Fi:16 Fc:0}



static void Test_B_BFu16i_BFu0c()
{
  {
    init_simple_test("B_BFu16i_BFu0c");
    static B_BFu16i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu16i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu16i_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu16i_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16i_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16i_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu16i_BFu0c(Test_B_BFu16i_BFu0c, "B_BFu16i_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16i_BFu0i  {
  bool v1;
  unsigned int v2:16;
  unsigned int  :0;
};
//SIG(1 B_BFu16i_BFu0i) C1{ Fc Fi:16 Fi:0}



static void Test_B_BFu16i_BFu0i()
{
  {
    init_simple_test("B_BFu16i_BFu0i");
    static B_BFu16i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu16i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu16i_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu16i_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16i_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16i_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu16i_BFu0i(Test_B_BFu16i_BFu0i, "B_BFu16i_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16i_BFu0ll  {
  bool v1;
  unsigned int v2:16;
  __tsu64  :0;
};
//SIG(1 B_BFu16i_BFu0ll) C1{ Fc Fi:16 FL:0}



static void Test_B_BFu16i_BFu0ll()
{
  {
    init_simple_test("B_BFu16i_BFu0ll");
    static B_BFu16i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu16i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu16i_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu16i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16i_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16i_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu16i_BFu0ll(Test_B_BFu16i_BFu0ll, "B_BFu16i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16i_BFu0s  {
  bool v1;
  unsigned int v2:16;
  unsigned short  :0;
};
//SIG(1 B_BFu16i_BFu0s) C1{ Fc Fi:16 Fs:0}



static void Test_B_BFu16i_BFu0s()
{
  {
    init_simple_test("B_BFu16i_BFu0s");
    static B_BFu16i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu16i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu16i_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu16i_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16i_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16i_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu16i_BFu0s(Test_B_BFu16i_BFu0s, "B_BFu16i_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16ll_BFu0c  {
  bool v1;
  __tsu64 v2:16;
  unsigned char  :0;
};
//SIG(1 B_BFu16ll_BFu0c) C1{ Fc FL:16 Fc:0}



static void Test_B_BFu16ll_BFu0c()
{
  {
    init_simple_test("B_BFu16ll_BFu0c");
    static B_BFu16ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu16ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu16ll_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu16ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16ll_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16ll_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu16ll_BFu0c(Test_B_BFu16ll_BFu0c, "B_BFu16ll_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16ll_BFu0i  {
  bool v1;
  __tsu64 v2:16;
  unsigned int  :0;
};
//SIG(1 B_BFu16ll_BFu0i) C1{ Fc FL:16 Fi:0}



static void Test_B_BFu16ll_BFu0i()
{
  {
    init_simple_test("B_BFu16ll_BFu0i");
    static B_BFu16ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu16ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu16ll_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu16ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16ll_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16ll_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu16ll_BFu0i(Test_B_BFu16ll_BFu0i, "B_BFu16ll_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16ll_BFu0ll  {
  bool v1;
  __tsu64 v2:16;
  __tsu64  :0;
};
//SIG(1 B_BFu16ll_BFu0ll) C1{ Fc FL:16 FL:0}



static void Test_B_BFu16ll_BFu0ll()
{
  {
    init_simple_test("B_BFu16ll_BFu0ll");
    static B_BFu16ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu16ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu16ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu16ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16ll_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu16ll_BFu0ll(Test_B_BFu16ll_BFu0ll, "B_BFu16ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16ll_BFu0s  {
  bool v1;
  __tsu64 v2:16;
  unsigned short  :0;
};
//SIG(1 B_BFu16ll_BFu0s) C1{ Fc FL:16 Fs:0}



static void Test_B_BFu16ll_BFu0s()
{
  {
    init_simple_test("B_BFu16ll_BFu0s");
    static B_BFu16ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu16ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu16ll_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu16ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "B_BFu16ll_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "B_BFu16ll_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu16ll_BFu0s(Test_B_BFu16ll_BFu0s, "B_BFu16ll_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16s_BFu0c  {
  bool v1;
  unsigned short v2:16;
  unsigned char  :0;
};
//SIG(1 B_BFu16s_BFu0c) C1{ Fc Fs:16 Fc:0}



static void Test_B_BFu16s_BFu0c()
{
  {
    init_simple_test("B_BFu16s_BFu0c");
    static B_BFu16s_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu16s_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu16s_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu16s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "B_BFu16s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "B_BFu16s_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu16s_BFu0c(Test_B_BFu16s_BFu0c, "B_BFu16s_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16s_BFu0i  {
  bool v1;
  unsigned short v2:16;
  unsigned int  :0;
};
//SIG(1 B_BFu16s_BFu0i) C1{ Fc Fs:16 Fi:0}



static void Test_B_BFu16s_BFu0i()
{
  {
    init_simple_test("B_BFu16s_BFu0i");
    static B_BFu16s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu16s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu16s_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu16s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "B_BFu16s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "B_BFu16s_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu16s_BFu0i(Test_B_BFu16s_BFu0i, "B_BFu16s_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16s_BFu0ll  {
  bool v1;
  unsigned short v2:16;
  __tsu64  :0;
};
//SIG(1 B_BFu16s_BFu0ll) C1{ Fc Fs:16 FL:0}



static void Test_B_BFu16s_BFu0ll()
{
  {
    init_simple_test("B_BFu16s_BFu0ll");
    static B_BFu16s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu16s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu16s_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu16s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "B_BFu16s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "B_BFu16s_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu16s_BFu0ll(Test_B_BFu16s_BFu0ll, "B_BFu16s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu16s_BFu0s  {
  bool v1;
  unsigned short v2:16;
  unsigned short  :0;
};
//SIG(1 B_BFu16s_BFu0s) C1{ Fc Fs:16 Fs:0}



static void Test_B_BFu16s_BFu0s()
{
  {
    init_simple_test("B_BFu16s_BFu0s");
    static B_BFu16s_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu16s_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu16s_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu16s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "B_BFu16s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "B_BFu16s_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu16s_BFu0s(Test_B_BFu16s_BFu0s, "B_BFu16s_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu17i_BFu0c  {
  bool v1;
  unsigned int v2:17;
  unsigned char  :0;
};
//SIG(1 B_BFu17i_BFu0c) C1{ Fc Fi:17 Fc:0}



static void Test_B_BFu17i_BFu0c()
{
  {
    init_simple_test("B_BFu17i_BFu0c");
    static B_BFu17i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu17i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu17i_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu17i_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu17i_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu17i_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu17i_BFu0c(Test_B_BFu17i_BFu0c, "B_BFu17i_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu17i_BFu0i  {
  bool v1;
  unsigned int v2:17;
  unsigned int  :0;
};
//SIG(1 B_BFu17i_BFu0i) C1{ Fc Fi:17 Fi:0}



static void Test_B_BFu17i_BFu0i()
{
  {
    init_simple_test("B_BFu17i_BFu0i");
    static B_BFu17i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu17i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu17i_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu17i_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu17i_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu17i_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu17i_BFu0i(Test_B_BFu17i_BFu0i, "B_BFu17i_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu17i_BFu0ll  {
  bool v1;
  unsigned int v2:17;
  __tsu64  :0;
};
//SIG(1 B_BFu17i_BFu0ll) C1{ Fc Fi:17 FL:0}



static void Test_B_BFu17i_BFu0ll()
{
  {
    init_simple_test("B_BFu17i_BFu0ll");
    static B_BFu17i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu17i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu17i_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu17i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu17i_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu17i_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu17i_BFu0ll(Test_B_BFu17i_BFu0ll, "B_BFu17i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu17i_BFu0s  {
  bool v1;
  unsigned int v2:17;
  unsigned short  :0;
};
//SIG(1 B_BFu17i_BFu0s) C1{ Fc Fi:17 Fs:0}



static void Test_B_BFu17i_BFu0s()
{
  {
    init_simple_test("B_BFu17i_BFu0s");
    static B_BFu17i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu17i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu17i_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu17i_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu17i_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu17i_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu17i_BFu0s(Test_B_BFu17i_BFu0s, "B_BFu17i_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu17ll_BFu0c  {
  bool v1;
  __tsu64 v2:17;
  unsigned char  :0;
};
//SIG(1 B_BFu17ll_BFu0c) C1{ Fc FL:17 Fc:0}



static void Test_B_BFu17ll_BFu0c()
{
  {
    init_simple_test("B_BFu17ll_BFu0c");
    static B_BFu17ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu17ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu17ll_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu17ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu17ll_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu17ll_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu17ll_BFu0c(Test_B_BFu17ll_BFu0c, "B_BFu17ll_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu17ll_BFu0i  {
  bool v1;
  __tsu64 v2:17;
  unsigned int  :0;
};
//SIG(1 B_BFu17ll_BFu0i) C1{ Fc FL:17 Fi:0}



static void Test_B_BFu17ll_BFu0i()
{
  {
    init_simple_test("B_BFu17ll_BFu0i");
    static B_BFu17ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu17ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu17ll_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu17ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu17ll_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu17ll_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu17ll_BFu0i(Test_B_BFu17ll_BFu0i, "B_BFu17ll_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu17ll_BFu0ll  {
  bool v1;
  __tsu64 v2:17;
  __tsu64  :0;
};
//SIG(1 B_BFu17ll_BFu0ll) C1{ Fc FL:17 FL:0}



static void Test_B_BFu17ll_BFu0ll()
{
  {
    init_simple_test("B_BFu17ll_BFu0ll");
    static B_BFu17ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu17ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu17ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu17ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu17ll_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu17ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu17ll_BFu0ll(Test_B_BFu17ll_BFu0ll, "B_BFu17ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu17ll_BFu0s  {
  bool v1;
  __tsu64 v2:17;
  unsigned short  :0;
};
//SIG(1 B_BFu17ll_BFu0s) C1{ Fc FL:17 Fs:0}



static void Test_B_BFu17ll_BFu0s()
{
  {
    init_simple_test("B_BFu17ll_BFu0s");
    static B_BFu17ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu17ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu17ll_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu17ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "B_BFu17ll_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "B_BFu17ll_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu17ll_BFu0s(Test_B_BFu17ll_BFu0s, "B_BFu17ll_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1c_BFu0c  {
  bool v1;
  unsigned char v2:1;
  unsigned char  :0;
};
//SIG(1 B_BFu1c_BFu0c) C1{ Fc Fc:1 Fc:0}



static void Test_B_BFu1c_BFu0c()
{
  {
    init_simple_test("B_BFu1c_BFu0c");
    static B_BFu1c_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu1c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu1c_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu1c_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1c_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu1c_BFu0c(Test_B_BFu1c_BFu0c, "B_BFu1c_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1c_BFu0i  {
  bool v1;
  unsigned char v2:1;
  unsigned int  :0;
};
//SIG(1 B_BFu1c_BFu0i) C1{ Fc Fc:1 Fi:0}



static void Test_B_BFu1c_BFu0i()
{
  {
    init_simple_test("B_BFu1c_BFu0i");
    static B_BFu1c_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu1c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu1c_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu1c_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1c_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu1c_BFu0i(Test_B_BFu1c_BFu0i, "B_BFu1c_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1c_BFu0ll  {
  bool v1;
  unsigned char v2:1;
  __tsu64  :0;
};
//SIG(1 B_BFu1c_BFu0ll) C1{ Fc Fc:1 FL:0}



static void Test_B_BFu1c_BFu0ll()
{
  {
    init_simple_test("B_BFu1c_BFu0ll");
    static B_BFu1c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu1c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu1c_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu1c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1c_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu1c_BFu0ll(Test_B_BFu1c_BFu0ll, "B_BFu1c_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1c_BFu0s  {
  bool v1;
  unsigned char v2:1;
  unsigned short  :0;
};
//SIG(1 B_BFu1c_BFu0s) C1{ Fc Fc:1 Fs:0}



static void Test_B_BFu1c_BFu0s()
{
  {
    init_simple_test("B_BFu1c_BFu0s");
    static B_BFu1c_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu1c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu1c_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu1c_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1c_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu1c_BFu0s(Test_B_BFu1c_BFu0s, "B_BFu1c_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1i_BFu0c  {
  bool v1;
  unsigned int v2:1;
  unsigned char  :0;
};
//SIG(1 B_BFu1i_BFu0c) C1{ Fc Fi:1 Fc:0}



static void Test_B_BFu1i_BFu0c()
{
  {
    init_simple_test("B_BFu1i_BFu0c");
    static B_BFu1i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu1i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu1i_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu1i_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1i_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu1i_BFu0c(Test_B_BFu1i_BFu0c, "B_BFu1i_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1i_BFu0i  {
  bool v1;
  unsigned int v2:1;
  unsigned int  :0;
};
//SIG(1 B_BFu1i_BFu0i) C1{ Fc Fi:1 Fi:0}



static void Test_B_BFu1i_BFu0i()
{
  {
    init_simple_test("B_BFu1i_BFu0i");
    static B_BFu1i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu1i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu1i_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu1i_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1i_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu1i_BFu0i(Test_B_BFu1i_BFu0i, "B_BFu1i_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1i_BFu0ll  {
  bool v1;
  unsigned int v2:1;
  __tsu64  :0;
};
//SIG(1 B_BFu1i_BFu0ll) C1{ Fc Fi:1 FL:0}



static void Test_B_BFu1i_BFu0ll()
{
  {
    init_simple_test("B_BFu1i_BFu0ll");
    static B_BFu1i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu1i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu1i_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu1i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1i_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu1i_BFu0ll(Test_B_BFu1i_BFu0ll, "B_BFu1i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1i_BFu0s  {
  bool v1;
  unsigned int v2:1;
  unsigned short  :0;
};
//SIG(1 B_BFu1i_BFu0s) C1{ Fc Fi:1 Fs:0}



static void Test_B_BFu1i_BFu0s()
{
  {
    init_simple_test("B_BFu1i_BFu0s");
    static B_BFu1i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu1i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu1i_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu1i_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1i_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu1i_BFu0s(Test_B_BFu1i_BFu0s, "B_BFu1i_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1ll_BFu0c  {
  bool v1;
  __tsu64 v2:1;
  unsigned char  :0;
};
//SIG(1 B_BFu1ll_BFu0c) C1{ Fc FL:1 Fc:0}



static void Test_B_BFu1ll_BFu0c()
{
  {
    init_simple_test("B_BFu1ll_BFu0c");
    static B_BFu1ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu1ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu1ll_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu1ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1ll_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu1ll_BFu0c(Test_B_BFu1ll_BFu0c, "B_BFu1ll_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1ll_BFu0i  {
  bool v1;
  __tsu64 v2:1;
  unsigned int  :0;
};
//SIG(1 B_BFu1ll_BFu0i) C1{ Fc FL:1 Fi:0}



static void Test_B_BFu1ll_BFu0i()
{
  {
    init_simple_test("B_BFu1ll_BFu0i");
    static B_BFu1ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu1ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu1ll_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu1ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1ll_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu1ll_BFu0i(Test_B_BFu1ll_BFu0i, "B_BFu1ll_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1ll_BFu0ll  {
  bool v1;
  __tsu64 v2:1;
  __tsu64  :0;
};
//SIG(1 B_BFu1ll_BFu0ll) C1{ Fc FL:1 FL:0}



static void Test_B_BFu1ll_BFu0ll()
{
  {
    init_simple_test("B_BFu1ll_BFu0ll");
    static B_BFu1ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu1ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu1ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu1ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu1ll_BFu0ll(Test_B_BFu1ll_BFu0ll, "B_BFu1ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1ll_BFu0s  {
  bool v1;
  __tsu64 v2:1;
  unsigned short  :0;
};
//SIG(1 B_BFu1ll_BFu0s) C1{ Fc FL:1 Fs:0}



static void Test_B_BFu1ll_BFu0s()
{
  {
    init_simple_test("B_BFu1ll_BFu0s");
    static B_BFu1ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu1ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu1ll_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu1ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1ll_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu1ll_BFu0s(Test_B_BFu1ll_BFu0s, "B_BFu1ll_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1s_BFu0c  {
  bool v1;
  unsigned short v2:1;
  unsigned char  :0;
};
//SIG(1 B_BFu1s_BFu0c) C1{ Fc Fs:1 Fc:0}



static void Test_B_BFu1s_BFu0c()
{
  {
    init_simple_test("B_BFu1s_BFu0c");
    static B_BFu1s_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu1s_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu1s_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu1s_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1s_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu1s_BFu0c(Test_B_BFu1s_BFu0c, "B_BFu1s_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1s_BFu0i  {
  bool v1;
  unsigned short v2:1;
  unsigned int  :0;
};
//SIG(1 B_BFu1s_BFu0i) C1{ Fc Fs:1 Fi:0}



static void Test_B_BFu1s_BFu0i()
{
  {
    init_simple_test("B_BFu1s_BFu0i");
    static B_BFu1s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu1s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu1s_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu1s_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1s_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu1s_BFu0i(Test_B_BFu1s_BFu0i, "B_BFu1s_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1s_BFu0ll  {
  bool v1;
  unsigned short v2:1;
  __tsu64  :0;
};
//SIG(1 B_BFu1s_BFu0ll) C1{ Fc Fs:1 FL:0}



static void Test_B_BFu1s_BFu0ll()
{
  {
    init_simple_test("B_BFu1s_BFu0ll");
    static B_BFu1s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu1s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu1s_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu1s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1s_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu1s_BFu0ll(Test_B_BFu1s_BFu0ll, "B_BFu1s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu1s_BFu0s  {
  bool v1;
  unsigned short v2:1;
  unsigned short  :0;
};
//SIG(1 B_BFu1s_BFu0s) C1{ Fc Fs:1 Fs:0}



static void Test_B_BFu1s_BFu0s()
{
  {
    init_simple_test("B_BFu1s_BFu0s");
    static B_BFu1s_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu1s_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu1s_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu1s_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "B_BFu1s_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu1s_BFu0s(Test_B_BFu1s_BFu0s, "B_BFu1s_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu31i_BFu0c  {
  bool v1;
  unsigned int v2:31;
  unsigned char  :0;
};
//SIG(1 B_BFu31i_BFu0c) C1{ Fc Fi:31 Fc:0}



static void Test_B_BFu31i_BFu0c()
{
  {
    init_simple_test("B_BFu31i_BFu0c");
    static B_BFu31i_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu31i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu31i_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu31i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "B_BFu31i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "B_BFu31i_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu31i_BFu0c(Test_B_BFu31i_BFu0c, "B_BFu31i_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu31i_BFu0i  {
  bool v1;
  unsigned int v2:31;
  unsigned int  :0;
};
//SIG(1 B_BFu31i_BFu0i) C1{ Fc Fi:31 Fi:0}



static void Test_B_BFu31i_BFu0i()
{
  {
    init_simple_test("B_BFu31i_BFu0i");
    static B_BFu31i_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu31i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu31i_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu31i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "B_BFu31i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "B_BFu31i_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu31i_BFu0i(Test_B_BFu31i_BFu0i, "B_BFu31i_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu31i_BFu0ll  {
  bool v1;
  unsigned int v2:31;
  __tsu64  :0;
};
//SIG(1 B_BFu31i_BFu0ll) C1{ Fc Fi:31 FL:0}



static void Test_B_BFu31i_BFu0ll()
{
  {
    init_simple_test("B_BFu31i_BFu0ll");
    static B_BFu31i_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu31i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu31i_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu31i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "B_BFu31i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "B_BFu31i_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu31i_BFu0ll(Test_B_BFu31i_BFu0ll, "B_BFu31i_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu31i_BFu0s  {
  bool v1;
  unsigned int v2:31;
  unsigned short  :0;
};
//SIG(1 B_BFu31i_BFu0s) C1{ Fc Fi:31 Fs:0}



static void Test_B_BFu31i_BFu0s()
{
  {
    init_simple_test("B_BFu31i_BFu0s");
    static B_BFu31i_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu31i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu31i_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu31i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "B_BFu31i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "B_BFu31i_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu31i_BFu0s(Test_B_BFu31i_BFu0s, "B_BFu31i_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu31ll_BFu0c  {
  bool v1;
  __tsu64 v2:31;
  unsigned char  :0;
};
//SIG(1 B_BFu31ll_BFu0c) C1{ Fc FL:31 Fc:0}



static void Test_B_BFu31ll_BFu0c()
{
  {
    init_simple_test("B_BFu31ll_BFu0c");
    static B_BFu31ll_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu31ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu31ll_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu31ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "B_BFu31ll_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "B_BFu31ll_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu31ll_BFu0c(Test_B_BFu31ll_BFu0c, "B_BFu31ll_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu31ll_BFu0i  {
  bool v1;
  __tsu64 v2:31;
  unsigned int  :0;
};
//SIG(1 B_BFu31ll_BFu0i) C1{ Fc FL:31 Fi:0}



static void Test_B_BFu31ll_BFu0i()
{
  {
    init_simple_test("B_BFu31ll_BFu0i");
    static B_BFu31ll_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu31ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu31ll_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu31ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "B_BFu31ll_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "B_BFu31ll_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu31ll_BFu0i(Test_B_BFu31ll_BFu0i, "B_BFu31ll_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu31ll_BFu0ll  {
  bool v1;
  __tsu64 v2:31;
  __tsu64  :0;
};
//SIG(1 B_BFu31ll_BFu0ll) C1{ Fc FL:31 FL:0}



static void Test_B_BFu31ll_BFu0ll()
{
  {
    init_simple_test("B_BFu31ll_BFu0ll");
    static B_BFu31ll_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu31ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu31ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu31ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "B_BFu31ll_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "B_BFu31ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu31ll_BFu0ll(Test_B_BFu31ll_BFu0ll, "B_BFu31ll_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu31ll_BFu0s  {
  bool v1;
  __tsu64 v2:31;
  unsigned short  :0;
};
//SIG(1 B_BFu31ll_BFu0s) C1{ Fc FL:31 Fs:0}



static void Test_B_BFu31ll_BFu0s()
{
  {
    init_simple_test("B_BFu31ll_BFu0s");
    static B_BFu31ll_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu31ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu31ll_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu31ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "B_BFu31ll_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "B_BFu31ll_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu31ll_BFu0s(Test_B_BFu31ll_BFu0s, "B_BFu31ll_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu32i_BFu0c  {
  bool v1;
  unsigned int v2:32;
  unsigned char  :0;
};
//SIG(1 B_BFu32i_BFu0c) C1{ Fc Fi:32 Fc:0}



static void Test_B_BFu32i_BFu0c()
{
  {
    init_simple_test("B_BFu32i_BFu0c");
    static B_BFu32i_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu32i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu32i_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu32i_BFu0c.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "B_BFu32i_BFu0c");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "B_BFu32i_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu32i_BFu0c(Test_B_BFu32i_BFu0c, "B_BFu32i_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu32i_BFu0i  {
  bool v1;
  unsigned int v2:32;
  unsigned int  :0;
};
//SIG(1 B_BFu32i_BFu0i) C1{ Fc Fi:32 Fi:0}



static void Test_B_BFu32i_BFu0i()
{
  {
    init_simple_test("B_BFu32i_BFu0i");
    static B_BFu32i_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu32i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu32i_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu32i_BFu0i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "B_BFu32i_BFu0i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "B_BFu32i_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu32i_BFu0i(Test_B_BFu32i_BFu0i, "B_BFu32i_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu32i_BFu0ll  {
  bool v1;
  unsigned int v2:32;
  __tsu64  :0;
};
//SIG(1 B_BFu32i_BFu0ll) C1{ Fc Fi:32 FL:0}



static void Test_B_BFu32i_BFu0ll()
{
  {
    init_simple_test("B_BFu32i_BFu0ll");
    static B_BFu32i_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu32i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu32i_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu32i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "B_BFu32i_BFu0ll");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "B_BFu32i_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu32i_BFu0ll(Test_B_BFu32i_BFu0ll, "B_BFu32i_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu32i_BFu0s  {
  bool v1;
  unsigned int v2:32;
  unsigned short  :0;
};
//SIG(1 B_BFu32i_BFu0s) C1{ Fc Fi:32 Fs:0}



static void Test_B_BFu32i_BFu0s()
{
  {
    init_simple_test("B_BFu32i_BFu0s");
    static B_BFu32i_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu32i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu32i_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu32i_BFu0s.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "B_BFu32i_BFu0s");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "B_BFu32i_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu32i_BFu0s(Test_B_BFu32i_BFu0s, "B_BFu32i_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu32ll_BFu0c  {
  bool v1;
  __tsu64 v2:32;
  unsigned char  :0;
};
//SIG(1 B_BFu32ll_BFu0c) C1{ Fc FL:32 Fc:0}



static void Test_B_BFu32ll_BFu0c()
{
  {
    init_simple_test("B_BFu32ll_BFu0c");
    static B_BFu32ll_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu32ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu32ll_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu32ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "B_BFu32ll_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "B_BFu32ll_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu32ll_BFu0c(Test_B_BFu32ll_BFu0c, "B_BFu32ll_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu32ll_BFu0i  {
  bool v1;
  __tsu64 v2:32;
  unsigned int  :0;
};
//SIG(1 B_BFu32ll_BFu0i) C1{ Fc FL:32 Fi:0}



static void Test_B_BFu32ll_BFu0i()
{
  {
    init_simple_test("B_BFu32ll_BFu0i");
    static B_BFu32ll_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu32ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu32ll_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu32ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "B_BFu32ll_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "B_BFu32ll_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu32ll_BFu0i(Test_B_BFu32ll_BFu0i, "B_BFu32ll_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu32ll_BFu0ll  {
  bool v1;
  __tsu64 v2:32;
  __tsu64  :0;
};
//SIG(1 B_BFu32ll_BFu0ll) C1{ Fc FL:32 FL:0}



static void Test_B_BFu32ll_BFu0ll()
{
  {
    init_simple_test("B_BFu32ll_BFu0ll");
    static B_BFu32ll_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu32ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu32ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu32ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "B_BFu32ll_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "B_BFu32ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu32ll_BFu0ll(Test_B_BFu32ll_BFu0ll, "B_BFu32ll_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu32ll_BFu0s  {
  bool v1;
  __tsu64 v2:32;
  unsigned short  :0;
};
//SIG(1 B_BFu32ll_BFu0s) C1{ Fc FL:32 Fs:0}



static void Test_B_BFu32ll_BFu0s()
{
  {
    init_simple_test("B_BFu32ll_BFu0s");
    static B_BFu32ll_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu32ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu32ll_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu32ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "B_BFu32ll_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "B_BFu32ll_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu32ll_BFu0s(Test_B_BFu32ll_BFu0s, "B_BFu32ll_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu33_BFu0c  {
  bool v1;
  __tsu64 v2:33;
  unsigned char  :0;
};
//SIG(1 B_BFu33_BFu0c) C1{ Fc FL:33 Fc:0}



static void Test_B_BFu33_BFu0c()
{
  {
    init_simple_test("B_BFu33_BFu0c");
    static B_BFu33_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu33_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu33_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu33_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "B_BFu33_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "B_BFu33_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu33_BFu0c(Test_B_BFu33_BFu0c, "B_BFu33_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu33_BFu0i  {
  bool v1;
  __tsu64 v2:33;
  unsigned int  :0;
};
//SIG(1 B_BFu33_BFu0i) C1{ Fc FL:33 Fi:0}



static void Test_B_BFu33_BFu0i()
{
  {
    init_simple_test("B_BFu33_BFu0i");
    static B_BFu33_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu33_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu33_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu33_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "B_BFu33_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "B_BFu33_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu33_BFu0i(Test_B_BFu33_BFu0i, "B_BFu33_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu33_BFu0ll  {
  bool v1;
  __tsu64 v2:33;
  __tsu64  :0;
};
//SIG(1 B_BFu33_BFu0ll) C1{ Fc FL:33 FL:0}



static void Test_B_BFu33_BFu0ll()
{
  {
    init_simple_test("B_BFu33_BFu0ll");
    static B_BFu33_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu33_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu33_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu33_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "B_BFu33_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "B_BFu33_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu33_BFu0ll(Test_B_BFu33_BFu0ll, "B_BFu33_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu33_BFu0s  {
  bool v1;
  __tsu64 v2:33;
  unsigned short  :0;
};
//SIG(1 B_BFu33_BFu0s) C1{ Fc FL:33 Fs:0}



static void Test_B_BFu33_BFu0s()
{
  {
    init_simple_test("B_BFu33_BFu0s");
    static B_BFu33_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(B_BFu33_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu33_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu33_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "B_BFu33_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "B_BFu33_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu33_BFu0s(Test_B_BFu33_BFu0s, "B_BFu33_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7c_BFu0c  {
  bool v1;
  unsigned char v2:7;
  unsigned char  :0;
};
//SIG(1 B_BFu7c_BFu0c) C1{ Fc Fc:7 Fc:0}



static void Test_B_BFu7c_BFu0c()
{
  {
    init_simple_test("B_BFu7c_BFu0c");
    static B_BFu7c_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu7c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu7c_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu7c_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7c_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7c_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu7c_BFu0c(Test_B_BFu7c_BFu0c, "B_BFu7c_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7c_BFu0i  {
  bool v1;
  unsigned char v2:7;
  unsigned int  :0;
};
//SIG(1 B_BFu7c_BFu0i) C1{ Fc Fc:7 Fi:0}



static void Test_B_BFu7c_BFu0i()
{
  {
    init_simple_test("B_BFu7c_BFu0i");
    static B_BFu7c_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu7c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu7c_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu7c_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7c_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7c_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu7c_BFu0i(Test_B_BFu7c_BFu0i, "B_BFu7c_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7c_BFu0ll  {
  bool v1;
  unsigned char v2:7;
  __tsu64  :0;
};
//SIG(1 B_BFu7c_BFu0ll) C1{ Fc Fc:7 FL:0}



static void Test_B_BFu7c_BFu0ll()
{
  {
    init_simple_test("B_BFu7c_BFu0ll");
    static B_BFu7c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu7c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu7c_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu7c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7c_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7c_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu7c_BFu0ll(Test_B_BFu7c_BFu0ll, "B_BFu7c_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7c_BFu0s  {
  bool v1;
  unsigned char v2:7;
  unsigned short  :0;
};
//SIG(1 B_BFu7c_BFu0s) C1{ Fc Fc:7 Fs:0}



static void Test_B_BFu7c_BFu0s()
{
  {
    init_simple_test("B_BFu7c_BFu0s");
    static B_BFu7c_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu7c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu7c_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu7c_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7c_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7c_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu7c_BFu0s(Test_B_BFu7c_BFu0s, "B_BFu7c_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7i_BFu0c  {
  bool v1;
  unsigned int v2:7;
  unsigned char  :0;
};
//SIG(1 B_BFu7i_BFu0c) C1{ Fc Fi:7 Fc:0}



static void Test_B_BFu7i_BFu0c()
{
  {
    init_simple_test("B_BFu7i_BFu0c");
    static B_BFu7i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu7i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu7i_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu7i_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7i_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7i_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu7i_BFu0c(Test_B_BFu7i_BFu0c, "B_BFu7i_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7i_BFu0i  {
  bool v1;
  unsigned int v2:7;
  unsigned int  :0;
};
//SIG(1 B_BFu7i_BFu0i) C1{ Fc Fi:7 Fi:0}



static void Test_B_BFu7i_BFu0i()
{
  {
    init_simple_test("B_BFu7i_BFu0i");
    static B_BFu7i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu7i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu7i_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu7i_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7i_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7i_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu7i_BFu0i(Test_B_BFu7i_BFu0i, "B_BFu7i_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7i_BFu0ll  {
  bool v1;
  unsigned int v2:7;
  __tsu64  :0;
};
//SIG(1 B_BFu7i_BFu0ll) C1{ Fc Fi:7 FL:0}



static void Test_B_BFu7i_BFu0ll()
{
  {
    init_simple_test("B_BFu7i_BFu0ll");
    static B_BFu7i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu7i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu7i_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu7i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7i_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7i_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu7i_BFu0ll(Test_B_BFu7i_BFu0ll, "B_BFu7i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7i_BFu0s  {
  bool v1;
  unsigned int v2:7;
  unsigned short  :0;
};
//SIG(1 B_BFu7i_BFu0s) C1{ Fc Fi:7 Fs:0}



static void Test_B_BFu7i_BFu0s()
{
  {
    init_simple_test("B_BFu7i_BFu0s");
    static B_BFu7i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu7i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu7i_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu7i_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7i_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7i_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu7i_BFu0s(Test_B_BFu7i_BFu0s, "B_BFu7i_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7ll_BFu0c  {
  bool v1;
  __tsu64 v2:7;
  unsigned char  :0;
};
//SIG(1 B_BFu7ll_BFu0c) C1{ Fc FL:7 Fc:0}



static void Test_B_BFu7ll_BFu0c()
{
  {
    init_simple_test("B_BFu7ll_BFu0c");
    static B_BFu7ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu7ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu7ll_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu7ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7ll_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7ll_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu7ll_BFu0c(Test_B_BFu7ll_BFu0c, "B_BFu7ll_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7ll_BFu0i  {
  bool v1;
  __tsu64 v2:7;
  unsigned int  :0;
};
//SIG(1 B_BFu7ll_BFu0i) C1{ Fc FL:7 Fi:0}



static void Test_B_BFu7ll_BFu0i()
{
  {
    init_simple_test("B_BFu7ll_BFu0i");
    static B_BFu7ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu7ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu7ll_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu7ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7ll_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7ll_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu7ll_BFu0i(Test_B_BFu7ll_BFu0i, "B_BFu7ll_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7ll_BFu0ll  {
  bool v1;
  __tsu64 v2:7;
  __tsu64  :0;
};
//SIG(1 B_BFu7ll_BFu0ll) C1{ Fc FL:7 FL:0}



static void Test_B_BFu7ll_BFu0ll()
{
  {
    init_simple_test("B_BFu7ll_BFu0ll");
    static B_BFu7ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu7ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu7ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu7ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7ll_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu7ll_BFu0ll(Test_B_BFu7ll_BFu0ll, "B_BFu7ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7ll_BFu0s  {
  bool v1;
  __tsu64 v2:7;
  unsigned short  :0;
};
//SIG(1 B_BFu7ll_BFu0s) C1{ Fc FL:7 Fs:0}



static void Test_B_BFu7ll_BFu0s()
{
  {
    init_simple_test("B_BFu7ll_BFu0s");
    static B_BFu7ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu7ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu7ll_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu7ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7ll_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7ll_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu7ll_BFu0s(Test_B_BFu7ll_BFu0s, "B_BFu7ll_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7s_BFu0c  {
  bool v1;
  unsigned short v2:7;
  unsigned char  :0;
};
//SIG(1 B_BFu7s_BFu0c) C1{ Fc Fs:7 Fc:0}



static void Test_B_BFu7s_BFu0c()
{
  {
    init_simple_test("B_BFu7s_BFu0c");
    static B_BFu7s_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu7s_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu7s_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu7s_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7s_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7s_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu7s_BFu0c(Test_B_BFu7s_BFu0c, "B_BFu7s_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7s_BFu0i  {
  bool v1;
  unsigned short v2:7;
  unsigned int  :0;
};
//SIG(1 B_BFu7s_BFu0i) C1{ Fc Fs:7 Fi:0}



static void Test_B_BFu7s_BFu0i()
{
  {
    init_simple_test("B_BFu7s_BFu0i");
    static B_BFu7s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu7s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu7s_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu7s_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7s_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7s_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu7s_BFu0i(Test_B_BFu7s_BFu0i, "B_BFu7s_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7s_BFu0ll  {
  bool v1;
  unsigned short v2:7;
  __tsu64  :0;
};
//SIG(1 B_BFu7s_BFu0ll) C1{ Fc Fs:7 FL:0}



static void Test_B_BFu7s_BFu0ll()
{
  {
    init_simple_test("B_BFu7s_BFu0ll");
    static B_BFu7s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu7s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu7s_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu7s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7s_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7s_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu7s_BFu0ll(Test_B_BFu7s_BFu0ll, "B_BFu7s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu7s_BFu0s  {
  bool v1;
  unsigned short v2:7;
  unsigned short  :0;
};
//SIG(1 B_BFu7s_BFu0s) C1{ Fc Fs:7 Fs:0}



static void Test_B_BFu7s_BFu0s()
{
  {
    init_simple_test("B_BFu7s_BFu0s");
    static B_BFu7s_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu7s_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu7s_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu7s_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "B_BFu7s_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "B_BFu7s_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu7s_BFu0s(Test_B_BFu7s_BFu0s, "B_BFu7s_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8c_BFu0c  {
  bool v1;
  unsigned char v2:8;
  unsigned char  :0;
};
//SIG(1 B_BFu8c_BFu0c) C1{ Fc Fc:8 Fc:0}



static void Test_B_BFu8c_BFu0c()
{
  {
    init_simple_test("B_BFu8c_BFu0c");
    static B_BFu8c_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu8c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu8c_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu8c_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8c_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8c_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu8c_BFu0c(Test_B_BFu8c_BFu0c, "B_BFu8c_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8c_BFu0i  {
  bool v1;
  unsigned char v2:8;
  unsigned int  :0;
};
//SIG(1 B_BFu8c_BFu0i) C1{ Fc Fc:8 Fi:0}



static void Test_B_BFu8c_BFu0i()
{
  {
    init_simple_test("B_BFu8c_BFu0i");
    static B_BFu8c_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu8c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu8c_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu8c_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8c_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8c_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu8c_BFu0i(Test_B_BFu8c_BFu0i, "B_BFu8c_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8c_BFu0ll  {
  bool v1;
  unsigned char v2:8;
  __tsu64  :0;
};
//SIG(1 B_BFu8c_BFu0ll) C1{ Fc Fc:8 FL:0}



static void Test_B_BFu8c_BFu0ll()
{
  {
    init_simple_test("B_BFu8c_BFu0ll");
    static B_BFu8c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu8c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu8c_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu8c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8c_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8c_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu8c_BFu0ll(Test_B_BFu8c_BFu0ll, "B_BFu8c_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8c_BFu0s  {
  bool v1;
  unsigned char v2:8;
  unsigned short  :0;
};
//SIG(1 B_BFu8c_BFu0s) C1{ Fc Fc:8 Fs:0}



static void Test_B_BFu8c_BFu0s()
{
  {
    init_simple_test("B_BFu8c_BFu0s");
    static B_BFu8c_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu8c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu8c_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu8c_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8c_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8c_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu8c_BFu0s(Test_B_BFu8c_BFu0s, "B_BFu8c_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8i_BFu0c  {
  bool v1;
  unsigned int v2:8;
  unsigned char  :0;
};
//SIG(1 B_BFu8i_BFu0c) C1{ Fc Fi:8 Fc:0}



static void Test_B_BFu8i_BFu0c()
{
  {
    init_simple_test("B_BFu8i_BFu0c");
    static B_BFu8i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu8i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu8i_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu8i_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8i_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8i_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu8i_BFu0c(Test_B_BFu8i_BFu0c, "B_BFu8i_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8i_BFu0i  {
  bool v1;
  unsigned int v2:8;
  unsigned int  :0;
};
//SIG(1 B_BFu8i_BFu0i) C1{ Fc Fi:8 Fi:0}



static void Test_B_BFu8i_BFu0i()
{
  {
    init_simple_test("B_BFu8i_BFu0i");
    static B_BFu8i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu8i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu8i_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu8i_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8i_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8i_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu8i_BFu0i(Test_B_BFu8i_BFu0i, "B_BFu8i_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8i_BFu0ll  {
  bool v1;
  unsigned int v2:8;
  __tsu64  :0;
};
//SIG(1 B_BFu8i_BFu0ll) C1{ Fc Fi:8 FL:0}



static void Test_B_BFu8i_BFu0ll()
{
  {
    init_simple_test("B_BFu8i_BFu0ll");
    static B_BFu8i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu8i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu8i_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu8i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8i_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8i_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu8i_BFu0ll(Test_B_BFu8i_BFu0ll, "B_BFu8i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8i_BFu0s  {
  bool v1;
  unsigned int v2:8;
  unsigned short  :0;
};
//SIG(1 B_BFu8i_BFu0s) C1{ Fc Fi:8 Fs:0}



static void Test_B_BFu8i_BFu0s()
{
  {
    init_simple_test("B_BFu8i_BFu0s");
    static B_BFu8i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu8i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu8i_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu8i_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8i_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8i_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu8i_BFu0s(Test_B_BFu8i_BFu0s, "B_BFu8i_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8ll_BFu0c  {
  bool v1;
  __tsu64 v2:8;
  unsigned char  :0;
};
//SIG(1 B_BFu8ll_BFu0c) C1{ Fc FL:8 Fc:0}



static void Test_B_BFu8ll_BFu0c()
{
  {
    init_simple_test("B_BFu8ll_BFu0c");
    static B_BFu8ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu8ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu8ll_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu8ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8ll_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8ll_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu8ll_BFu0c(Test_B_BFu8ll_BFu0c, "B_BFu8ll_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8ll_BFu0i  {
  bool v1;
  __tsu64 v2:8;
  unsigned int  :0;
};
//SIG(1 B_BFu8ll_BFu0i) C1{ Fc FL:8 Fi:0}



static void Test_B_BFu8ll_BFu0i()
{
  {
    init_simple_test("B_BFu8ll_BFu0i");
    static B_BFu8ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu8ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu8ll_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu8ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8ll_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8ll_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu8ll_BFu0i(Test_B_BFu8ll_BFu0i, "B_BFu8ll_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8ll_BFu0ll  {
  bool v1;
  __tsu64 v2:8;
  __tsu64  :0;
};
//SIG(1 B_BFu8ll_BFu0ll) C1{ Fc FL:8 FL:0}



static void Test_B_BFu8ll_BFu0ll()
{
  {
    init_simple_test("B_BFu8ll_BFu0ll");
    static B_BFu8ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu8ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu8ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu8ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8ll_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu8ll_BFu0ll(Test_B_BFu8ll_BFu0ll, "B_BFu8ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8ll_BFu0s  {
  bool v1;
  __tsu64 v2:8;
  unsigned short  :0;
};
//SIG(1 B_BFu8ll_BFu0s) C1{ Fc FL:8 Fs:0}



static void Test_B_BFu8ll_BFu0s()
{
  {
    init_simple_test("B_BFu8ll_BFu0s");
    static B_BFu8ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu8ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu8ll_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu8ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8ll_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8ll_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu8ll_BFu0s(Test_B_BFu8ll_BFu0s, "B_BFu8ll_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8s_BFu0c  {
  bool v1;
  unsigned short v2:8;
  unsigned char  :0;
};
//SIG(1 B_BFu8s_BFu0c) C1{ Fc Fs:8 Fc:0}



static void Test_B_BFu8s_BFu0c()
{
  {
    init_simple_test("B_BFu8s_BFu0c");
    static B_BFu8s_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu8s_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu8s_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu8s_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8s_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8s_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu8s_BFu0c(Test_B_BFu8s_BFu0c, "B_BFu8s_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8s_BFu0i  {
  bool v1;
  unsigned short v2:8;
  unsigned int  :0;
};
//SIG(1 B_BFu8s_BFu0i) C1{ Fc Fs:8 Fi:0}



static void Test_B_BFu8s_BFu0i()
{
  {
    init_simple_test("B_BFu8s_BFu0i");
    static B_BFu8s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu8s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu8s_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu8s_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8s_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8s_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu8s_BFu0i(Test_B_BFu8s_BFu0i, "B_BFu8s_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8s_BFu0ll  {
  bool v1;
  unsigned short v2:8;
  __tsu64  :0;
};
//SIG(1 B_BFu8s_BFu0ll) C1{ Fc Fs:8 FL:0}



static void Test_B_BFu8s_BFu0ll()
{
  {
    init_simple_test("B_BFu8s_BFu0ll");
    static B_BFu8s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu8s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu8s_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu8s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8s_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8s_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu8s_BFu0ll(Test_B_BFu8s_BFu0ll, "B_BFu8s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu8s_BFu0s  {
  bool v1;
  unsigned short v2:8;
  unsigned short  :0;
};
//SIG(1 B_BFu8s_BFu0s) C1{ Fc Fs:8 Fs:0}



static void Test_B_BFu8s_BFu0s()
{
  {
    init_simple_test("B_BFu8s_BFu0s");
    static B_BFu8s_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu8s_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu8s_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu8s_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "B_BFu8s_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "B_BFu8s_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu8s_BFu0s(Test_B_BFu8s_BFu0s, "B_BFu8s_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9i_BFu0c  {
  bool v1;
  unsigned int v2:9;
  unsigned char  :0;
};
//SIG(1 B_BFu9i_BFu0c) C1{ Fc Fi:9 Fc:0}



static void Test_B_BFu9i_BFu0c()
{
  {
    init_simple_test("B_BFu9i_BFu0c");
    static B_BFu9i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu9i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu9i_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu9i_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9i_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9i_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu9i_BFu0c(Test_B_BFu9i_BFu0c, "B_BFu9i_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9i_BFu0i  {
  bool v1;
  unsigned int v2:9;
  unsigned int  :0;
};
//SIG(1 B_BFu9i_BFu0i) C1{ Fc Fi:9 Fi:0}



static void Test_B_BFu9i_BFu0i()
{
  {
    init_simple_test("B_BFu9i_BFu0i");
    static B_BFu9i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu9i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu9i_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu9i_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9i_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9i_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu9i_BFu0i(Test_B_BFu9i_BFu0i, "B_BFu9i_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9i_BFu0ll  {
  bool v1;
  unsigned int v2:9;
  __tsu64  :0;
};
//SIG(1 B_BFu9i_BFu0ll) C1{ Fc Fi:9 FL:0}



static void Test_B_BFu9i_BFu0ll()
{
  {
    init_simple_test("B_BFu9i_BFu0ll");
    static B_BFu9i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu9i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_BFu9i_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu9i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9i_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9i_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu9i_BFu0ll(Test_B_BFu9i_BFu0ll, "B_BFu9i_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9i_BFu0s  {
  bool v1;
  unsigned int v2:9;
  unsigned short  :0;
};
//SIG(1 B_BFu9i_BFu0s) C1{ Fc Fi:9 Fs:0}



static void Test_B_BFu9i_BFu0s()
{
  {
    init_simple_test("B_BFu9i_BFu0s");
    static B_BFu9i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu9i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(B_BFu9i_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu9i_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9i_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9i_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu9i_BFu0s(Test_B_BFu9i_BFu0s, "B_BFu9i_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9ll_BFu0c  {
  bool v1;
  __tsu64 v2:9;
  unsigned char  :0;
};
//SIG(1 B_BFu9ll_BFu0c) C1{ Fc FL:9 Fc:0}



static void Test_B_BFu9ll_BFu0c()
{
  {
    init_simple_test("B_BFu9ll_BFu0c");
    static B_BFu9ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu9ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu9ll_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu9ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9ll_BFu0c");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9ll_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu9ll_BFu0c(Test_B_BFu9ll_BFu0c, "B_BFu9ll_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9ll_BFu0i  {
  bool v1;
  __tsu64 v2:9;
  unsigned int  :0;
};
//SIG(1 B_BFu9ll_BFu0i) C1{ Fc FL:9 Fi:0}



static void Test_B_BFu9ll_BFu0i()
{
  {
    init_simple_test("B_BFu9ll_BFu0i");
    static B_BFu9ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu9ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu9ll_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu9ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9ll_BFu0i");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9ll_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu9ll_BFu0i(Test_B_BFu9ll_BFu0i, "B_BFu9ll_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9ll_BFu0ll  {
  bool v1;
  __tsu64 v2:9;
  __tsu64  :0;
};
//SIG(1 B_BFu9ll_BFu0ll) C1{ Fc FL:9 FL:0}



static void Test_B_BFu9ll_BFu0ll()
{
  {
    init_simple_test("B_BFu9ll_BFu0ll");
    static B_BFu9ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu9ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu9ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu9ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9ll_BFu0ll");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9ll_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu9ll_BFu0ll(Test_B_BFu9ll_BFu0ll, "B_BFu9ll_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9ll_BFu0s  {
  bool v1;
  __tsu64 v2:9;
  unsigned short  :0;
};
//SIG(1 B_BFu9ll_BFu0s) C1{ Fc FL:9 Fs:0}



static void Test_B_BFu9ll_BFu0s()
{
  {
    init_simple_test("B_BFu9ll_BFu0s");
    static B_BFu9ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu9ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_BFu9ll_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu9ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "B_BFu9ll_BFu0s");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "B_BFu9ll_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu9ll_BFu0s(Test_B_BFu9ll_BFu0s, "B_BFu9ll_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9s_BFu0c  {
  bool v1;
  unsigned short v2:9;
  unsigned char  :0;
};
//SIG(1 B_BFu9s_BFu0c) C1{ Fc Fs:9 Fc:0}



static void Test_B_BFu9s_BFu0c()
{
  {
    init_simple_test("B_BFu9s_BFu0c");
    static B_BFu9s_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu9s_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu9s_BFu0c)");
    check_field_offset(lv, v1, 0, "B_BFu9s_BFu0c.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "B_BFu9s_BFu0c");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "B_BFu9s_BFu0c");
  }
}
static Arrange_To_Call_Me vB_BFu9s_BFu0c(Test_B_BFu9s_BFu0c, "B_BFu9s_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9s_BFu0i  {
  bool v1;
  unsigned short v2:9;
  unsigned int  :0;
};
//SIG(1 B_BFu9s_BFu0i) C1{ Fc Fs:9 Fi:0}



static void Test_B_BFu9s_BFu0i()
{
  {
    init_simple_test("B_BFu9s_BFu0i");
    static B_BFu9s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu9s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu9s_BFu0i)");
    check_field_offset(lv, v1, 0, "B_BFu9s_BFu0i.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "B_BFu9s_BFu0i");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "B_BFu9s_BFu0i");
  }
}
static Arrange_To_Call_Me vB_BFu9s_BFu0i(Test_B_BFu9s_BFu0i, "B_BFu9s_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9s_BFu0ll  {
  bool v1;
  unsigned short v2:9;
  __tsu64  :0;
};
//SIG(1 B_BFu9s_BFu0ll) C1{ Fc Fs:9 FL:0}



static void Test_B_BFu9s_BFu0ll()
{
  {
    init_simple_test("B_BFu9s_BFu0ll");
    static B_BFu9s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_BFu9s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_BFu9s_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_BFu9s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "B_BFu9s_BFu0ll");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "B_BFu9s_BFu0ll");
  }
}
static Arrange_To_Call_Me vB_BFu9s_BFu0ll(Test_B_BFu9s_BFu0ll, "B_BFu9s_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu9s_BFu0s  {
  bool v1;
  unsigned short v2:9;
  unsigned short  :0;
};
//SIG(1 B_BFu9s_BFu0s) C1{ Fc Fs:9 Fs:0}



static void Test_B_BFu9s_BFu0s()
{
  {
    init_simple_test("B_BFu9s_BFu0s");
    static B_BFu9s_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_BFu9s_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(B_BFu9s_BFu0s)");
    check_field_offset(lv, v1, 0, "B_BFu9s_BFu0s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "B_BFu9s_BFu0s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "B_BFu9s_BFu0s");
  }
}
static Arrange_To_Call_Me vB_BFu9s_BFu0s(Test_B_BFu9s_BFu0s, "B_BFu9s_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_C_BFu0c  {
  bool v1;
  char v2;
  unsigned char  :0;
};
//SIG(1 B_C_BFu0c) C1{ Fc[2] Fc:0}



static void Test_B_C_BFu0c()
{
  {
    init_simple_test("B_C_BFu0c");
    static B_C_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(B_C_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(B_C_BFu0c)");
    check_field_offset(lv, v1, 0, "B_C_BFu0c.v1");
    check_field_offset(lv, v2, 1, "B_C_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_C_BFu0c(Test_B_C_BFu0c, "B_C_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_C_BFu0i  {
  bool v1;
  char v2;
  unsigned int  :0;
};
//SIG(1 B_C_BFu0i) C1{ Fc[2] Fi:0}



static void Test_B_C_BFu0i()
{
  {
    init_simple_test("B_C_BFu0i");
    static B_C_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_C_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_C_BFu0i)");
    check_field_offset(lv, v1, 0, "B_C_BFu0i.v1");
    check_field_offset(lv, v2, 1, "B_C_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_C_BFu0i(Test_B_C_BFu0i, "B_C_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_C_BFu0ll  {
  bool v1;
  char v2;
  __tsu64  :0;
};
//SIG(1 B_C_BFu0ll) C1{ Fc[2] FL:0}



static void Test_B_C_BFu0ll()
{
  {
    init_simple_test("B_C_BFu0ll");
    static B_C_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_C_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_C_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_C_BFu0ll.v1");
    check_field_offset(lv, v2, 1, "B_C_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_C_BFu0ll(Test_B_C_BFu0ll, "B_C_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_C_BFu0s  {
  bool v1;
  char v2;
  unsigned short  :0;
};
//SIG(1 B_C_BFu0s) C1{ Fc[2] Fs:0}



static void Test_B_C_BFu0s()
{
  {
    init_simple_test("B_C_BFu0s");
    static B_C_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_C_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_C_BFu0s)");
    check_field_offset(lv, v1, 0, "B_C_BFu0s.v1");
    check_field_offset(lv, v2, 1, "B_C_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_C_BFu0s(Test_B_C_BFu0s, "B_C_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_D_BFu0c  {
  bool v1;
  double v2;
  unsigned char  :0;
};
//SIG(1 B_D_BFu0c) C1{ Fc FL Fc:0}



static void Test_B_D_BFu0c()
{
  {
    init_simple_test("B_D_BFu0c");
    static B_D_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_D_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_D_BFu0c)");
    check_field_offset(lv, v1, 0, "B_D_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_D_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_D_BFu0c(Test_B_D_BFu0c, "B_D_BFu0c", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_D_BFu0i  {
  bool v1;
  double v2;
  unsigned int  :0;
};
//SIG(1 B_D_BFu0i) C1{ Fc FL Fi:0}



static void Test_B_D_BFu0i()
{
  {
    init_simple_test("B_D_BFu0i");
    static B_D_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_D_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_D_BFu0i)");
    check_field_offset(lv, v1, 0, "B_D_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_D_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_D_BFu0i(Test_B_D_BFu0i, "B_D_BFu0i", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_D_BFu0ll  {
  bool v1;
  double v2;
  __tsu64  :0;
};
//SIG(1 B_D_BFu0ll) C1{ Fc FL FL:0}



static void Test_B_D_BFu0ll()
{
  {
    init_simple_test("B_D_BFu0ll");
    static B_D_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_D_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_D_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_D_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_D_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_D_BFu0ll(Test_B_D_BFu0ll, "B_D_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_D_BFu0s  {
  bool v1;
  double v2;
  unsigned short  :0;
};
//SIG(1 B_D_BFu0s) C1{ Fc FL Fs:0}



static void Test_B_D_BFu0s()
{
  {
    init_simple_test("B_D_BFu0s");
    static B_D_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_D_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_D_BFu0s)");
    check_field_offset(lv, v1, 0, "B_D_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_D_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_D_BFu0s(Test_B_D_BFu0s, "B_D_BFu0s", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_F_BFu0c  {
  bool v1;
  float v2;
  unsigned char  :0;
};
//SIG(1 B_F_BFu0c) C1{ Fc Fi Fc:0}



static void Test_B_F_BFu0c()
{
  {
    init_simple_test("B_F_BFu0c");
    static B_F_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(B_F_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(B_F_BFu0c)");
    check_field_offset(lv, v1, 0, "B_F_BFu0c.v1");
    check_field_offset(lv, v2, 4, "B_F_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_F_BFu0c(Test_B_F_BFu0c, "B_F_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_F_BFu0i  {
  bool v1;
  float v2;
  unsigned int  :0;
};
//SIG(1 B_F_BFu0i) C1{ Fc Fi Fi:0}



static void Test_B_F_BFu0i()
{
  {
    init_simple_test("B_F_BFu0i");
    static B_F_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(B_F_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(B_F_BFu0i)");
    check_field_offset(lv, v1, 0, "B_F_BFu0i.v1");
    check_field_offset(lv, v2, 4, "B_F_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_F_BFu0i(Test_B_F_BFu0i, "B_F_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_F_BFu0ll  {
  bool v1;
  float v2;
  __tsu64  :0;
};
//SIG(1 B_F_BFu0ll) C1{ Fc Fi FL:0}



static void Test_B_F_BFu0ll()
{
  {
    init_simple_test("B_F_BFu0ll");
    static B_F_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(B_F_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_F_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_F_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "B_F_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_F_BFu0ll(Test_B_F_BFu0ll, "B_F_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_F_BFu0s  {
  bool v1;
  float v2;
  unsigned short  :0;
};
//SIG(1 B_F_BFu0s) C1{ Fc Fi Fs:0}



static void Test_B_F_BFu0s()
{
  {
    init_simple_test("B_F_BFu0s");
    static B_F_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(B_F_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(B_F_BFu0s)");
    check_field_offset(lv, v1, 0, "B_F_BFu0s.v1");
    check_field_offset(lv, v2, 4, "B_F_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_F_BFu0s(Test_B_F_BFu0s, "B_F_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_I_BFu0c  {
  bool v1;
  int v2;
  unsigned char  :0;
};
//SIG(1 B_I_BFu0c) C1{ Fc Fi Fc:0}



static void Test_B_I_BFu0c()
{
  {
    init_simple_test("B_I_BFu0c");
    static B_I_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(B_I_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(B_I_BFu0c)");
    check_field_offset(lv, v1, 0, "B_I_BFu0c.v1");
    check_field_offset(lv, v2, 4, "B_I_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_I_BFu0c(Test_B_I_BFu0c, "B_I_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_I_BFu0i  {
  bool v1;
  int v2;
  unsigned int  :0;
};
//SIG(1 B_I_BFu0i) C1{ Fc Fi Fi:0}



static void Test_B_I_BFu0i()
{
  {
    init_simple_test("B_I_BFu0i");
    static B_I_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(B_I_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(B_I_BFu0i)");
    check_field_offset(lv, v1, 0, "B_I_BFu0i.v1");
    check_field_offset(lv, v2, 4, "B_I_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_I_BFu0i(Test_B_I_BFu0i, "B_I_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_I_BFu0ll  {
  bool v1;
  int v2;
  __tsu64  :0;
};
//SIG(1 B_I_BFu0ll) C1{ Fc Fi FL:0}



static void Test_B_I_BFu0ll()
{
  {
    init_simple_test("B_I_BFu0ll");
    static B_I_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(B_I_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_I_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_I_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "B_I_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_I_BFu0ll(Test_B_I_BFu0ll, "B_I_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_I_BFu0s  {
  bool v1;
  int v2;
  unsigned short  :0;
};
//SIG(1 B_I_BFu0s) C1{ Fc Fi Fs:0}



static void Test_B_I_BFu0s()
{
  {
    init_simple_test("B_I_BFu0s");
    static B_I_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(B_I_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(B_I_BFu0s)");
    check_field_offset(lv, v1, 0, "B_I_BFu0s.v1");
    check_field_offset(lv, v2, 4, "B_I_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_I_BFu0s(Test_B_I_BFu0s, "B_I_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ip_BFu0c  {
  bool v1;
  int *v2;
  unsigned char  :0;
};
//SIG(1 B_Ip_BFu0c) C1{ Fc Fp Fc:0}



static void Test_B_Ip_BFu0c()
{
  {
    init_simple_test("B_Ip_BFu0c");
    static B_Ip_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_Ip_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Ip_BFu0c)");
    check_field_offset(lv, v1, 0, "B_Ip_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Ip_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_Ip_BFu0c(Test_B_Ip_BFu0c, "B_Ip_BFu0c", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ip_BFu0i  {
  bool v1;
  int *v2;
  unsigned int  :0;
};
//SIG(1 B_Ip_BFu0i) C1{ Fc Fp Fi:0}



static void Test_B_Ip_BFu0i()
{
  {
    init_simple_test("B_Ip_BFu0i");
    static B_Ip_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_Ip_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Ip_BFu0i)");
    check_field_offset(lv, v1, 0, "B_Ip_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Ip_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_Ip_BFu0i(Test_B_Ip_BFu0i, "B_Ip_BFu0i", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ip_BFu0ll  {
  bool v1;
  int *v2;
  __tsu64  :0;
};
//SIG(1 B_Ip_BFu0ll) C1{ Fc Fp FL:0}



static void Test_B_Ip_BFu0ll()
{
  {
    init_simple_test("B_Ip_BFu0ll");
    static B_Ip_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_Ip_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Ip_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_Ip_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Ip_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_Ip_BFu0ll(Test_B_Ip_BFu0ll, "B_Ip_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ip_BFu0s  {
  bool v1;
  int *v2;
  unsigned short  :0;
};
//SIG(1 B_Ip_BFu0s) C1{ Fc Fp Fs:0}



static void Test_B_Ip_BFu0s()
{
  {
    init_simple_test("B_Ip_BFu0s");
    static B_Ip_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_Ip_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Ip_BFu0s)");
    check_field_offset(lv, v1, 0, "B_Ip_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Ip_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_Ip_BFu0s(Test_B_Ip_BFu0s, "B_Ip_BFu0s", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_L_BFu0c  {
  bool v1;
  __tsi64 v2;
  unsigned char  :0;
};
//SIG(1 B_L_BFu0c) C1{ Fc FL Fc:0}



static void Test_B_L_BFu0c()
{
  {
    init_simple_test("B_L_BFu0c");
    static B_L_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_L_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_L_BFu0c)");
    check_field_offset(lv, v1, 0, "B_L_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_L_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_L_BFu0c(Test_B_L_BFu0c, "B_L_BFu0c", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_L_BFu0i  {
  bool v1;
  __tsi64 v2;
  unsigned int  :0;
};
//SIG(1 B_L_BFu0i) C1{ Fc FL Fi:0}



static void Test_B_L_BFu0i()
{
  {
    init_simple_test("B_L_BFu0i");
    static B_L_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_L_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_L_BFu0i)");
    check_field_offset(lv, v1, 0, "B_L_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_L_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_L_BFu0i(Test_B_L_BFu0i, "B_L_BFu0i", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_L_BFu0ll  {
  bool v1;
  __tsi64 v2;
  __tsu64  :0;
};
//SIG(1 B_L_BFu0ll) C1{ Fc FL FL:0}



static void Test_B_L_BFu0ll()
{
  {
    init_simple_test("B_L_BFu0ll");
    static B_L_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_L_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_L_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_L_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_L_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_L_BFu0ll(Test_B_L_BFu0ll, "B_L_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_L_BFu0s  {
  bool v1;
  __tsi64 v2;
  unsigned short  :0;
};
//SIG(1 B_L_BFu0s) C1{ Fc FL Fs:0}



static void Test_B_L_BFu0s()
{
  {
    init_simple_test("B_L_BFu0s");
    static B_L_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_L_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_L_BFu0s)");
    check_field_offset(lv, v1, 0, "B_L_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_L_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_L_BFu0s(Test_B_L_BFu0s, "B_L_BFu0s", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_S_BFu0c  {
  bool v1;
  short v2;
  unsigned char  :0;
};
//SIG(1 B_S_BFu0c) C1{ Fc Fs Fc:0}



static void Test_B_S_BFu0c()
{
  {
    init_simple_test("B_S_BFu0c");
    static B_S_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_S_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(B_S_BFu0c)");
    check_field_offset(lv, v1, 0, "B_S_BFu0c.v1");
    check_field_offset(lv, v2, 2, "B_S_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_S_BFu0c(Test_B_S_BFu0c, "B_S_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_S_BFu0i  {
  bool v1;
  short v2;
  unsigned int  :0;
};
//SIG(1 B_S_BFu0i) C1{ Fc Fs Fi:0}



static void Test_B_S_BFu0i()
{
  {
    init_simple_test("B_S_BFu0i");
    static B_S_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_S_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_S_BFu0i)");
    check_field_offset(lv, v1, 0, "B_S_BFu0i.v1");
    check_field_offset(lv, v2, 2, "B_S_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_S_BFu0i(Test_B_S_BFu0i, "B_S_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_S_BFu0ll  {
  bool v1;
  short v2;
  __tsu64  :0;
};
//SIG(1 B_S_BFu0ll) C1{ Fc Fs FL:0}



static void Test_B_S_BFu0ll()
{
  {
    init_simple_test("B_S_BFu0ll");
    static B_S_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_S_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_S_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_S_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "B_S_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_S_BFu0ll(Test_B_S_BFu0ll, "B_S_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_S_BFu0s  {
  bool v1;
  short v2;
  unsigned short  :0;
};
//SIG(1 B_S_BFu0s) C1{ Fc Fs Fs:0}



static void Test_B_S_BFu0s()
{
  {
    init_simple_test("B_S_BFu0s");
    static B_S_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_S_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(B_S_BFu0s)");
    check_field_offset(lv, v1, 0, "B_S_BFu0s.v1");
    check_field_offset(lv, v2, 2, "B_S_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_S_BFu0s(Test_B_S_BFu0s, "B_S_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Uc_BFu0c  {
  bool v1;
  unsigned char v2;
  unsigned char  :0;
};
//SIG(1 B_Uc_BFu0c) C1{ Fc[2] Fc:0}



static void Test_B_Uc_BFu0c()
{
  {
    init_simple_test("B_Uc_BFu0c");
    static B_Uc_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(B_Uc_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(B_Uc_BFu0c)");
    check_field_offset(lv, v1, 0, "B_Uc_BFu0c.v1");
    check_field_offset(lv, v2, 1, "B_Uc_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_Uc_BFu0c(Test_B_Uc_BFu0c, "B_Uc_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Uc_BFu0i  {
  bool v1;
  unsigned char v2;
  unsigned int  :0;
};
//SIG(1 B_Uc_BFu0i) C1{ Fc[2] Fi:0}



static void Test_B_Uc_BFu0i()
{
  {
    init_simple_test("B_Uc_BFu0i");
    static B_Uc_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_Uc_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_Uc_BFu0i)");
    check_field_offset(lv, v1, 0, "B_Uc_BFu0i.v1");
    check_field_offset(lv, v2, 1, "B_Uc_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_Uc_BFu0i(Test_B_Uc_BFu0i, "B_Uc_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Uc_BFu0ll  {
  bool v1;
  unsigned char v2;
  __tsu64  :0;
};
//SIG(1 B_Uc_BFu0ll) C1{ Fc[2] FL:0}



static void Test_B_Uc_BFu0ll()
{
  {
    init_simple_test("B_Uc_BFu0ll");
    static B_Uc_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_Uc_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_Uc_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_Uc_BFu0ll.v1");
    check_field_offset(lv, v2, 1, "B_Uc_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_Uc_BFu0ll(Test_B_Uc_BFu0ll, "B_Uc_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Uc_BFu0s  {
  bool v1;
  unsigned char v2;
  unsigned short  :0;
};
//SIG(1 B_Uc_BFu0s) C1{ Fc[2] Fs:0}



static void Test_B_Uc_BFu0s()
{
  {
    init_simple_test("B_Uc_BFu0s");
    static B_Uc_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_Uc_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_Uc_BFu0s)");
    check_field_offset(lv, v1, 0, "B_Uc_BFu0s.v1");
    check_field_offset(lv, v2, 1, "B_Uc_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_Uc_BFu0s(Test_B_Uc_BFu0s, "B_Uc_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ui_BFu0c  {
  bool v1;
  unsigned int v2;
  unsigned char  :0;
};
//SIG(1 B_Ui_BFu0c) C1{ Fc Fi Fc:0}



static void Test_B_Ui_BFu0c()
{
  {
    init_simple_test("B_Ui_BFu0c");
    static B_Ui_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(B_Ui_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(B_Ui_BFu0c)");
    check_field_offset(lv, v1, 0, "B_Ui_BFu0c.v1");
    check_field_offset(lv, v2, 4, "B_Ui_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_Ui_BFu0c(Test_B_Ui_BFu0c, "B_Ui_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ui_BFu0i  {
  bool v1;
  unsigned int v2;
  unsigned int  :0;
};
//SIG(1 B_Ui_BFu0i) C1{ Fc Fi Fi:0}



static void Test_B_Ui_BFu0i()
{
  {
    init_simple_test("B_Ui_BFu0i");
    static B_Ui_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(B_Ui_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(B_Ui_BFu0i)");
    check_field_offset(lv, v1, 0, "B_Ui_BFu0i.v1");
    check_field_offset(lv, v2, 4, "B_Ui_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_Ui_BFu0i(Test_B_Ui_BFu0i, "B_Ui_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ui_BFu0ll  {
  bool v1;
  unsigned int v2;
  __tsu64  :0;
};
//SIG(1 B_Ui_BFu0ll) C1{ Fc Fi FL:0}



static void Test_B_Ui_BFu0ll()
{
  {
    init_simple_test("B_Ui_BFu0ll");
    static B_Ui_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(B_Ui_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(B_Ui_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_Ui_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "B_Ui_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_Ui_BFu0ll(Test_B_Ui_BFu0ll, "B_Ui_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ui_BFu0s  {
  bool v1;
  unsigned int v2;
  unsigned short  :0;
};
//SIG(1 B_Ui_BFu0s) C1{ Fc Fi Fs:0}



static void Test_B_Ui_BFu0s()
{
  {
    init_simple_test("B_Ui_BFu0s");
    static B_Ui_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(B_Ui_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(B_Ui_BFu0s)");
    check_field_offset(lv, v1, 0, "B_Ui_BFu0s.v1");
    check_field_offset(lv, v2, 4, "B_Ui_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_Ui_BFu0s(Test_B_Ui_BFu0s, "B_Ui_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ul_BFu0c  {
  bool v1;
  __tsu64 v2;
  unsigned char  :0;
};
//SIG(1 B_Ul_BFu0c) C1{ Fc FL Fc:0}



static void Test_B_Ul_BFu0c()
{
  {
    init_simple_test("B_Ul_BFu0c");
    static B_Ul_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_Ul_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Ul_BFu0c)");
    check_field_offset(lv, v1, 0, "B_Ul_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Ul_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_Ul_BFu0c(Test_B_Ul_BFu0c, "B_Ul_BFu0c", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ul_BFu0i  {
  bool v1;
  __tsu64 v2;
  unsigned int  :0;
};
//SIG(1 B_Ul_BFu0i) C1{ Fc FL Fi:0}



static void Test_B_Ul_BFu0i()
{
  {
    init_simple_test("B_Ul_BFu0i");
    static B_Ul_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_Ul_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Ul_BFu0i)");
    check_field_offset(lv, v1, 0, "B_Ul_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Ul_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_Ul_BFu0i(Test_B_Ul_BFu0i, "B_Ul_BFu0i", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ul_BFu0ll  {
  bool v1;
  __tsu64 v2;
  __tsu64  :0;
};
//SIG(1 B_Ul_BFu0ll) C1{ Fc FL FL:0}



static void Test_B_Ul_BFu0ll()
{
  {
    init_simple_test("B_Ul_BFu0ll");
    static B_Ul_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_Ul_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Ul_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_Ul_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Ul_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_Ul_BFu0ll(Test_B_Ul_BFu0ll, "B_Ul_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Ul_BFu0s  {
  bool v1;
  __tsu64 v2;
  unsigned short  :0;
};
//SIG(1 B_Ul_BFu0s) C1{ Fc FL Fs:0}



static void Test_B_Ul_BFu0s()
{
  {
    init_simple_test("B_Ul_BFu0s");
    static B_Ul_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(B_Ul_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Ul_BFu0s)");
    check_field_offset(lv, v1, 0, "B_Ul_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Ul_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_Ul_BFu0s(Test_B_Ul_BFu0s, "B_Ul_BFu0s", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Us_BFu0c  {
  bool v1;
  unsigned short v2;
  unsigned char  :0;
};
//SIG(1 B_Us_BFu0c) C1{ Fc Fs Fc:0}



static void Test_B_Us_BFu0c()
{
  {
    init_simple_test("B_Us_BFu0c");
    static B_Us_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(B_Us_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(B_Us_BFu0c)");
    check_field_offset(lv, v1, 0, "B_Us_BFu0c.v1");
    check_field_offset(lv, v2, 2, "B_Us_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_Us_BFu0c(Test_B_Us_BFu0c, "B_Us_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Us_BFu0i  {
  bool v1;
  unsigned short v2;
  unsigned int  :0;
};
//SIG(1 B_Us_BFu0i) C1{ Fc Fs Fi:0}



static void Test_B_Us_BFu0i()
{
  {
    init_simple_test("B_Us_BFu0i");
    static B_Us_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_Us_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_Us_BFu0i)");
    check_field_offset(lv, v1, 0, "B_Us_BFu0i.v1");
    check_field_offset(lv, v2, 2, "B_Us_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_Us_BFu0i(Test_B_Us_BFu0i, "B_Us_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Us_BFu0ll  {
  bool v1;
  unsigned short v2;
  __tsu64  :0;
};
//SIG(1 B_Us_BFu0ll) C1{ Fc Fs FL:0}



static void Test_B_Us_BFu0ll()
{
  {
    init_simple_test("B_Us_BFu0ll");
    static B_Us_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_Us_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(B_Us_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_Us_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "B_Us_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_Us_BFu0ll(Test_B_Us_BFu0ll, "B_Us_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Us_BFu0s  {
  bool v1;
  unsigned short v2;
  unsigned short  :0;
};
//SIG(1 B_Us_BFu0s) C1{ Fc Fs Fs:0}



static void Test_B_Us_BFu0s()
{
  {
    init_simple_test("B_Us_BFu0s");
    static B_Us_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(B_Us_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(B_Us_BFu0s)");
    check_field_offset(lv, v1, 0, "B_Us_BFu0s.v1");
    check_field_offset(lv, v2, 2, "B_Us_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_Us_BFu0s(Test_B_Us_BFu0s, "B_Us_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Vp_BFu0c  {
  bool v1;
  void *v2;
  unsigned char  :0;
};
//SIG(1 B_Vp_BFu0c) C1{ Fc Fp Fc:0}



static void Test_B_Vp_BFu0c()
{
  {
    init_simple_test("B_Vp_BFu0c");
    static B_Vp_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_Vp_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Vp_BFu0c)");
    check_field_offset(lv, v1, 0, "B_Vp_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Vp_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_Vp_BFu0c(Test_B_Vp_BFu0c, "B_Vp_BFu0c", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Vp_BFu0i  {
  bool v1;
  void *v2;
  unsigned int  :0;
};
//SIG(1 B_Vp_BFu0i) C1{ Fc Fp Fi:0}



static void Test_B_Vp_BFu0i()
{
  {
    init_simple_test("B_Vp_BFu0i");
    static B_Vp_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_Vp_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Vp_BFu0i)");
    check_field_offset(lv, v1, 0, "B_Vp_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Vp_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_Vp_BFu0i(Test_B_Vp_BFu0i, "B_Vp_BFu0i", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Vp_BFu0ll  {
  bool v1;
  void *v2;
  __tsu64  :0;
};
//SIG(1 B_Vp_BFu0ll) C1{ Fc Fp FL:0}



static void Test_B_Vp_BFu0ll()
{
  {
    init_simple_test("B_Vp_BFu0ll");
    static B_Vp_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_Vp_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Vp_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_Vp_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Vp_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_Vp_BFu0ll(Test_B_Vp_BFu0ll, "B_Vp_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Vp_BFu0s  {
  bool v1;
  void *v2;
  unsigned short  :0;
};
//SIG(1 B_Vp_BFu0s) C1{ Fc Fp Fs:0}



static void Test_B_Vp_BFu0s()
{
  {
    init_simple_test("B_Vp_BFu0s");
    static B_Vp_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(B_Vp_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(B_Vp_BFu0s)");
    check_field_offset(lv, v1, 0, "B_Vp_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_Vp_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_Vp_BFu0s(Test_B_Vp_BFu0s, "B_Vp_BFu0s", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B  {
  unsigned char  :0;
  bool v1;
};
//SIG(1 BFu0c_B) C1{ Fc:0 Fc}



static void Test_BFu0c_B()
{
  {
    init_simple_test("BFu0c_B");
    static BFu0c_B lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_B)");
    check_field_offset(lv, v1, 0, "BFu0c_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0c_B(Test_BFu0c_B, "BFu0c_B", 1);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_B  {
  unsigned char  :0;
  bool v1;
  bool v2;
};
//SIG(1 BFu0c_B_B) C1{ Fc:0 Fc[2]}



static void Test_BFu0c_B_B()
{
  {
    init_simple_test("BFu0c_B_B");
    static BFu0c_B_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_B_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_B_B)");
    check_field_offset(lv, v1, 0, "BFu0c_B_B.v1");
    check_field_offset(lv, v2, 1, "BFu0c_B_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_B(Test_BFu0c_B_B, "BFu0c_B_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu0c  {
  unsigned char  :0;
  bool v1;
  unsigned char  :0;
};
//SIG(1 BFu0c_B_BFu0c) C1{ Fc:0 Fc Fc:0}



static void Test_BFu0c_B_BFu0c()
{
  {
    init_simple_test("BFu0c_B_BFu0c");
    static BFu0c_B_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_B_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_B_BFu0c)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu0c(Test_BFu0c_B_BFu0c, "BFu0c_B_BFu0c", 1);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu0i  {
  unsigned char  :0;
  bool v1;
  unsigned int  :0;
};
//SIG(1 BFu0c_B_BFu0i) C1{ Fc:0 Fc Fi:0}



static void Test_BFu0c_B_BFu0i()
{
  {
    init_simple_test("BFu0c_B_BFu0i");
    static BFu0c_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0c_B_BFu0i)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu0i(Test_BFu0c_B_BFu0i, "BFu0c_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu0ll  {
  unsigned char  :0;
  bool v1;
  __tsu64  :0;
};
//SIG(1 BFu0c_B_BFu0ll) C1{ Fc:0 Fc FL:0}



static void Test_BFu0c_B_BFu0ll()
{
  {
    init_simple_test("BFu0c_B_BFu0ll");
    static BFu0c_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0c_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu0ll(Test_BFu0c_B_BFu0ll, "BFu0c_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu0s  {
  unsigned char  :0;
  bool v1;
  unsigned short  :0;
};
//SIG(1 BFu0c_B_BFu0s) C1{ Fc:0 Fc Fs:0}



static void Test_BFu0c_B_BFu0s()
{
  {
    init_simple_test("BFu0c_B_BFu0s");
    static BFu0c_B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0c_B_BFu0s)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu0s(Test_BFu0c_B_BFu0s, "BFu0c_B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu15i  {
  unsigned char  :0;
  bool v1;
  unsigned int v2:15;
};
//SIG(1 BFu0c_B_BFu15i) C1{ Fc:0 Fc Fi:15}



static void Test_BFu0c_B_BFu15i()
{
  {
    init_simple_test("BFu0c_B_BFu15i");
    static BFu0c_B_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_B_BFu15i)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu15i.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "BFu0c_B_BFu15i");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "BFu0c_B_BFu15i");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu15i(Test_BFu0c_B_BFu15i, "BFu0c_B_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu15ll  {
  unsigned char  :0;
  bool v1;
  __tsu64 v2:15;
};
//SIG(1 BFu0c_B_BFu15ll) C1{ Fc:0 Fc FL:15}



static void Test_BFu0c_B_BFu15ll()
{
  {
    init_simple_test("BFu0c_B_BFu15ll");
    static BFu0c_B_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_B_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu15ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "BFu0c_B_BFu15ll");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "BFu0c_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu15ll(Test_BFu0c_B_BFu15ll, "BFu0c_B_BFu15ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu15s  {
  unsigned char  :0;
  bool v1;
  unsigned short v2:15;
};
//SIG(1 BFu0c_B_BFu15s) C1{ Fc:0 Fc Fs:15}



static void Test_BFu0c_B_BFu15s()
{
  {
    init_simple_test("BFu0c_B_BFu15s");
    static BFu0c_B_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_BFu15s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_B_BFu15s)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu15s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "BFu0c_B_BFu15s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "BFu0c_B_BFu15s");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu15s(Test_BFu0c_B_BFu15s, "BFu0c_B_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu16i  {
  unsigned char  :0;
  bool v1;
  unsigned int v2:16;
};
//SIG(1 BFu0c_B_BFu16i) C1{ Fc:0 Fc Fi:16}



static void Test_BFu0c_B_BFu16i()
{
  {
    init_simple_test("BFu0c_B_BFu16i");
    static BFu0c_B_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_B_BFu16i)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu16i.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "BFu0c_B_BFu16i");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "BFu0c_B_BFu16i");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu16i(Test_BFu0c_B_BFu16i, "BFu0c_B_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu16ll  {
  unsigned char  :0;
  bool v1;
  __tsu64 v2:16;
};
//SIG(1 BFu0c_B_BFu16ll) C1{ Fc:0 Fc FL:16}



static void Test_BFu0c_B_BFu16ll()
{
  {
    init_simple_test("BFu0c_B_BFu16ll");
    static BFu0c_B_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_B_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu16ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "BFu0c_B_BFu16ll");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "BFu0c_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu16ll(Test_BFu0c_B_BFu16ll, "BFu0c_B_BFu16ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu16s  {
  unsigned char  :0;
  bool v1;
  unsigned short v2:16;
};
//SIG(1 BFu0c_B_BFu16s) C1{ Fc:0 Fc Fs:16}



static void Test_BFu0c_B_BFu16s()
{
  {
    init_simple_test("BFu0c_B_BFu16s");
    static BFu0c_B_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_BFu16s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_B_BFu16s)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu16s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "BFu0c_B_BFu16s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "BFu0c_B_BFu16s");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu16s(Test_BFu0c_B_BFu16s, "BFu0c_B_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu17i  {
  unsigned char  :0;
  bool v1;
  unsigned int v2:17;
};
//SIG(1 BFu0c_B_BFu17i) C1{ Fc:0 Fc Fi:17}



static void Test_BFu0c_B_BFu17i()
{
  {
    init_simple_test("BFu0c_B_BFu17i");
    static BFu0c_B_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_B_BFu17i)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu17i.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "BFu0c_B_BFu17i");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "BFu0c_B_BFu17i");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu17i(Test_BFu0c_B_BFu17i, "BFu0c_B_BFu17i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu17ll  {
  unsigned char  :0;
  bool v1;
  __tsu64 v2:17;
};
//SIG(1 BFu0c_B_BFu17ll) C1{ Fc:0 Fc FL:17}



static void Test_BFu0c_B_BFu17ll()
{
  {
    init_simple_test("BFu0c_B_BFu17ll");
    static BFu0c_B_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_B_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu17ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "BFu0c_B_BFu17ll");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "BFu0c_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu17ll(Test_BFu0c_B_BFu17ll, "BFu0c_B_BFu17ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu1c  {
  unsigned char  :0;
  bool v1;
  unsigned char v2:1;
};
//SIG(1 BFu0c_B_BFu1c) C1{ Fc:0 Fc Fc:1}



static void Test_BFu0c_B_BFu1c()
{
  {
    init_simple_test("BFu0c_B_BFu1c");
    static BFu0c_B_BFu1c lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_B_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_B_BFu1c)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu1c.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0c_B_BFu1c");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu1c(Test_BFu0c_B_BFu1c, "BFu0c_B_BFu1c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu1i  {
  unsigned char  :0;
  bool v1;
  unsigned int v2:1;
};
//SIG(1 BFu0c_B_BFu1i) C1{ Fc:0 Fc Fi:1}



static void Test_BFu0c_B_BFu1i()
{
  {
    init_simple_test("BFu0c_B_BFu1i");
    static BFu0c_B_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_B_BFu1i)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu1i.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0c_B_BFu1i");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu1i(Test_BFu0c_B_BFu1i, "BFu0c_B_BFu1i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu1ll  {
  unsigned char  :0;
  bool v1;
  __tsu64 v2:1;
};
//SIG(1 BFu0c_B_BFu1ll) C1{ Fc:0 Fc FL:1}



static void Test_BFu0c_B_BFu1ll()
{
  {
    init_simple_test("BFu0c_B_BFu1ll");
    static BFu0c_B_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_B_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu1ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0c_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu1ll(Test_BFu0c_B_BFu1ll, "BFu0c_B_BFu1ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu1s  {
  unsigned char  :0;
  bool v1;
  unsigned short v2:1;
};
//SIG(1 BFu0c_B_BFu1s) C1{ Fc:0 Fc Fs:1}



static void Test_BFu0c_B_BFu1s()
{
  {
    init_simple_test("BFu0c_B_BFu1s");
    static BFu0c_B_BFu1s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_B_BFu1s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_B_BFu1s)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu1s.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0c_B_BFu1s");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu1s(Test_BFu0c_B_BFu1s, "BFu0c_B_BFu1s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu31i  {
  unsigned char  :0;
  bool v1;
  unsigned int v2:31;
};
//SIG(1 BFu0c_B_BFu31i) C1{ Fc:0 Fc Fi:31}



static void Test_BFu0c_B_BFu31i()
{
  {
    init_simple_test("BFu0c_B_BFu31i");
    static BFu0c_B_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_B_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_B_BFu31i)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu31i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "BFu0c_B_BFu31i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "BFu0c_B_BFu31i");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu31i(Test_BFu0c_B_BFu31i, "BFu0c_B_BFu31i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu31ll  {
  unsigned char  :0;
  bool v1;
  __tsu64 v2:31;
};
//SIG(1 BFu0c_B_BFu31ll) C1{ Fc:0 Fc FL:31}



static void Test_BFu0c_B_BFu31ll()
{
  {
    init_simple_test("BFu0c_B_BFu31ll");
    static BFu0c_B_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_B_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu31ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "BFu0c_B_BFu31ll");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "BFu0c_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu31ll(Test_BFu0c_B_BFu31ll, "BFu0c_B_BFu31ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu32i  {
  unsigned char  :0;
  bool v1;
  unsigned int v2:32;
};
//SIG(1 BFu0c_B_BFu32i) C1{ Fc:0 Fc Fi:32}



static void Test_BFu0c_B_BFu32i()
{
  {
    init_simple_test("BFu0c_B_BFu32i");
    static BFu0c_B_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_B_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_B_BFu32i)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu32i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "BFu0c_B_BFu32i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "BFu0c_B_BFu32i");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu32i(Test_BFu0c_B_BFu32i, "BFu0c_B_BFu32i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu32ll  {
  unsigned char  :0;
  bool v1;
  __tsu64 v2:32;
};
//SIG(1 BFu0c_B_BFu32ll) C1{ Fc:0 Fc FL:32}



static void Test_BFu0c_B_BFu32ll()
{
  {
    init_simple_test("BFu0c_B_BFu32ll");
    static BFu0c_B_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_B_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu32ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "BFu0c_B_BFu32ll");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "BFu0c_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu32ll(Test_BFu0c_B_BFu32ll, "BFu0c_B_BFu32ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu33  {
  unsigned char  :0;
  bool v1;
  __tsu64 v2:33;
};
//SIG(1 BFu0c_B_BFu33) C1{ Fc:0 Fc FL:33}



static void Test_BFu0c_B_BFu33()
{
  {
    init_simple_test("BFu0c_B_BFu33");
    static BFu0c_B_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_B_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_BFu33)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu33.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "BFu0c_B_BFu33");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "BFu0c_B_BFu33");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu33(Test_BFu0c_B_BFu33, "BFu0c_B_BFu33", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu7c  {
  unsigned char  :0;
  bool v1;
  unsigned char v2:7;
};
//SIG(1 BFu0c_B_BFu7c) C1{ Fc:0 Fc Fc:7}



static void Test_BFu0c_B_BFu7c()
{
  {
    init_simple_test("BFu0c_B_BFu7c");
    static BFu0c_B_BFu7c lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_B_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_B_BFu7c)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu7c.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0c_B_BFu7c");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0c_B_BFu7c");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu7c(Test_BFu0c_B_BFu7c, "BFu0c_B_BFu7c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu7i  {
  unsigned char  :0;
  bool v1;
  unsigned int v2:7;
};
//SIG(1 BFu0c_B_BFu7i) C1{ Fc:0 Fc Fi:7}



static void Test_BFu0c_B_BFu7i()
{
  {
    init_simple_test("BFu0c_B_BFu7i");
    static BFu0c_B_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_B_BFu7i)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu7i.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0c_B_BFu7i");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0c_B_BFu7i");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu7i(Test_BFu0c_B_BFu7i, "BFu0c_B_BFu7i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu7ll  {
  unsigned char  :0;
  bool v1;
  __tsu64 v2:7;
};
//SIG(1 BFu0c_B_BFu7ll) C1{ Fc:0 Fc FL:7}



static void Test_BFu0c_B_BFu7ll()
{
  {
    init_simple_test("BFu0c_B_BFu7ll");
    static BFu0c_B_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_B_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu7ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0c_B_BFu7ll");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0c_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu7ll(Test_BFu0c_B_BFu7ll, "BFu0c_B_BFu7ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu7s  {
  unsigned char  :0;
  bool v1;
  unsigned short v2:7;
};
//SIG(1 BFu0c_B_BFu7s) C1{ Fc:0 Fc Fs:7}



static void Test_BFu0c_B_BFu7s()
{
  {
    init_simple_test("BFu0c_B_BFu7s");
    static BFu0c_B_BFu7s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_B_BFu7s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_B_BFu7s)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu7s.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0c_B_BFu7s");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0c_B_BFu7s");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu7s(Test_BFu0c_B_BFu7s, "BFu0c_B_BFu7s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu8c  {
  unsigned char  :0;
  bool v1;
  unsigned char v2:8;
};
//SIG(1 BFu0c_B_BFu8c) C1{ Fc:0 Fc Fc:8}



static void Test_BFu0c_B_BFu8c()
{
  {
    init_simple_test("BFu0c_B_BFu8c");
    static BFu0c_B_BFu8c lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_B_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_B_BFu8c)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu8c.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0c_B_BFu8c");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0c_B_BFu8c");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu8c(Test_BFu0c_B_BFu8c, "BFu0c_B_BFu8c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu8i  {
  unsigned char  :0;
  bool v1;
  unsigned int v2:8;
};
//SIG(1 BFu0c_B_BFu8i) C1{ Fc:0 Fc Fi:8}



static void Test_BFu0c_B_BFu8i()
{
  {
    init_simple_test("BFu0c_B_BFu8i");
    static BFu0c_B_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_B_BFu8i)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu8i.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0c_B_BFu8i");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0c_B_BFu8i");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu8i(Test_BFu0c_B_BFu8i, "BFu0c_B_BFu8i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu8ll  {
  unsigned char  :0;
  bool v1;
  __tsu64 v2:8;
};
//SIG(1 BFu0c_B_BFu8ll) C1{ Fc:0 Fc FL:8}



static void Test_BFu0c_B_BFu8ll()
{
  {
    init_simple_test("BFu0c_B_BFu8ll");
    static BFu0c_B_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_B_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu8ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0c_B_BFu8ll");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0c_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu8ll(Test_BFu0c_B_BFu8ll, "BFu0c_B_BFu8ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu8s  {
  unsigned char  :0;
  bool v1;
  unsigned short v2:8;
};
//SIG(1 BFu0c_B_BFu8s) C1{ Fc:0 Fc Fs:8}



static void Test_BFu0c_B_BFu8s()
{
  {
    init_simple_test("BFu0c_B_BFu8s");
    static BFu0c_B_BFu8s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_B_BFu8s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_B_BFu8s)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu8s.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0c_B_BFu8s");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0c_B_BFu8s");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu8s(Test_BFu0c_B_BFu8s, "BFu0c_B_BFu8s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu9i  {
  unsigned char  :0;
  bool v1;
  unsigned int v2:9;
};
//SIG(1 BFu0c_B_BFu9i) C1{ Fc:0 Fc Fi:9}



static void Test_BFu0c_B_BFu9i()
{
  {
    init_simple_test("BFu0c_B_BFu9i");
    static BFu0c_B_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_B_BFu9i)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu9i.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "BFu0c_B_BFu9i");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "BFu0c_B_BFu9i");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu9i(Test_BFu0c_B_BFu9i, "BFu0c_B_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu9ll  {
  unsigned char  :0;
  bool v1;
  __tsu64 v2:9;
};
//SIG(1 BFu0c_B_BFu9ll) C1{ Fc:0 Fc FL:9}



static void Test_BFu0c_B_BFu9ll()
{
  {
    init_simple_test("BFu0c_B_BFu9ll");
    static BFu0c_B_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_B_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu9ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "BFu0c_B_BFu9ll");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "BFu0c_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu9ll(Test_BFu0c_B_BFu9ll, "BFu0c_B_BFu9ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_BFu9s  {
  unsigned char  :0;
  bool v1;
  unsigned short v2:9;
};
//SIG(1 BFu0c_B_BFu9s) C1{ Fc:0 Fc Fs:9}



static void Test_BFu0c_B_BFu9s()
{
  {
    init_simple_test("BFu0c_B_BFu9s");
    static BFu0c_B_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_BFu9s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_B_BFu9s)");
    check_field_offset(lv, v1, 0, "BFu0c_B_BFu9s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "BFu0c_B_BFu9s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "BFu0c_B_BFu9s");
  }
}
static Arrange_To_Call_Me vBFu0c_B_BFu9s(Test_BFu0c_B_BFu9s, "BFu0c_B_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_C  {
  unsigned char  :0;
  bool v1;
  char v2;
};
//SIG(1 BFu0c_B_C) C1{ Fc:0 Fc[2]}



static void Test_BFu0c_B_C()
{
  {
    init_simple_test("BFu0c_B_C");
    static BFu0c_B_C lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_B_C)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_B_C)");
    check_field_offset(lv, v1, 0, "BFu0c_B_C.v1");
    check_field_offset(lv, v2, 1, "BFu0c_B_C.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_C(Test_BFu0c_B_C, "BFu0c_B_C", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_D  {
  unsigned char  :0;
  bool v1;
  double v2;
};
//SIG(1 BFu0c_B_D) C1{ Fc:0 Fc FL}



static void Test_BFu0c_B_D()
{
  {
    init_simple_test("BFu0c_B_D");
    static BFu0c_B_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0c_B_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_D)");
    check_field_offset(lv, v1, 0, "BFu0c_B_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0c_B_D.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_D(Test_BFu0c_B_D, "BFu0c_B_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_F  {
  unsigned char  :0;
  bool v1;
  float v2;
};
//SIG(1 BFu0c_B_F) C1{ Fc:0 Fc Fi}



static void Test_BFu0c_B_F()
{
  {
    init_simple_test("BFu0c_B_F");
    static BFu0c_B_F lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_B_F)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_B_F)");
    check_field_offset(lv, v1, 0, "BFu0c_B_F.v1");
    check_field_offset(lv, v2, 4, "BFu0c_B_F.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_F(Test_BFu0c_B_F, "BFu0c_B_F", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_I  {
  unsigned char  :0;
  bool v1;
  int v2;
};
//SIG(1 BFu0c_B_I) C1{ Fc:0 Fc Fi}



static void Test_BFu0c_B_I()
{
  {
    init_simple_test("BFu0c_B_I");
    static BFu0c_B_I lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_B_I)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_B_I)");
    check_field_offset(lv, v1, 0, "BFu0c_B_I.v1");
    check_field_offset(lv, v2, 4, "BFu0c_B_I.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_I(Test_BFu0c_B_I, "BFu0c_B_I", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_Ip  {
  unsigned char  :0;
  bool v1;
  int *v2;
};
//SIG(1 BFu0c_B_Ip) C1{ Fc:0 Fc Fp}



static void Test_BFu0c_B_Ip()
{
  {
    init_simple_test("BFu0c_B_Ip");
    static BFu0c_B_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0c_B_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_Ip)");
    check_field_offset(lv, v1, 0, "BFu0c_B_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0c_B_Ip.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_Ip(Test_BFu0c_B_Ip, "BFu0c_B_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_L  {
  unsigned char  :0;
  bool v1;
  __tsi64 v2;
};
//SIG(1 BFu0c_B_L) C1{ Fc:0 Fc FL}



static void Test_BFu0c_B_L()
{
  {
    init_simple_test("BFu0c_B_L");
    static BFu0c_B_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0c_B_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_L)");
    check_field_offset(lv, v1, 0, "BFu0c_B_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0c_B_L.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_L(Test_BFu0c_B_L, "BFu0c_B_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_S  {
  unsigned char  :0;
  bool v1;
  short v2;
};
//SIG(1 BFu0c_B_S) C1{ Fc:0 Fc Fs}



static void Test_BFu0c_B_S()
{
  {
    init_simple_test("BFu0c_B_S");
    static BFu0c_B_S lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_S)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_B_S)");
    check_field_offset(lv, v1, 0, "BFu0c_B_S.v1");
    check_field_offset(lv, v2, 2, "BFu0c_B_S.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_S(Test_BFu0c_B_S, "BFu0c_B_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_Uc  {
  unsigned char  :0;
  bool v1;
  unsigned char v2;
};
//SIG(1 BFu0c_B_Uc) C1{ Fc:0 Fc[2]}



static void Test_BFu0c_B_Uc()
{
  {
    init_simple_test("BFu0c_B_Uc");
    static BFu0c_B_Uc lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_B_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_B_Uc)");
    check_field_offset(lv, v1, 0, "BFu0c_B_Uc.v1");
    check_field_offset(lv, v2, 1, "BFu0c_B_Uc.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_Uc(Test_BFu0c_B_Uc, "BFu0c_B_Uc", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_Ui  {
  unsigned char  :0;
  bool v1;
  unsigned int v2;
};
//SIG(1 BFu0c_B_Ui) C1{ Fc:0 Fc Fi}



static void Test_BFu0c_B_Ui()
{
  {
    init_simple_test("BFu0c_B_Ui");
    static BFu0c_B_Ui lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_B_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_B_Ui)");
    check_field_offset(lv, v1, 0, "BFu0c_B_Ui.v1");
    check_field_offset(lv, v2, 4, "BFu0c_B_Ui.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_Ui(Test_BFu0c_B_Ui, "BFu0c_B_Ui", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_Ul  {
  unsigned char  :0;
  bool v1;
  __tsu64 v2;
};
//SIG(1 BFu0c_B_Ul) C1{ Fc:0 Fc FL}



static void Test_BFu0c_B_Ul()
{
  {
    init_simple_test("BFu0c_B_Ul");
    static BFu0c_B_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0c_B_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_Ul)");
    check_field_offset(lv, v1, 0, "BFu0c_B_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0c_B_Ul.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_Ul(Test_BFu0c_B_Ul, "BFu0c_B_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_Us  {
  unsigned char  :0;
  bool v1;
  unsigned short v2;
};
//SIG(1 BFu0c_B_Us) C1{ Fc:0 Fc Fs}



static void Test_BFu0c_B_Us()
{
  {
    init_simple_test("BFu0c_B_Us");
    static BFu0c_B_Us lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_B_Us)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_B_Us)");
    check_field_offset(lv, v1, 0, "BFu0c_B_Us.v1");
    check_field_offset(lv, v2, 2, "BFu0c_B_Us.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_Us(Test_BFu0c_B_Us, "BFu0c_B_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_Vp  {
  unsigned char  :0;
  bool v1;
  void *v2;
};
//SIG(1 BFu0c_B_Vp) C1{ Fc:0 Fc Fp}



static void Test_BFu0c_B_Vp()
{
  {
    init_simple_test("BFu0c_B_Vp");
    static BFu0c_B_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0c_B_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_B_Vp)");
    check_field_offset(lv, v1, 0, "BFu0c_B_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0c_B_Vp.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_Vp(Test_BFu0c_B_Vp, "BFu0c_B_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu0c_B  {
  unsigned char  :0;
  unsigned char  :0;
  bool v1;
};
//SIG(1 BFu0c_BFu0c_B) C1{ Fc:0 Fc:0 Fc}



static void Test_BFu0c_BFu0c_B()
{
  {
    init_simple_test("BFu0c_BFu0c_B");
    static BFu0c_BFu0c_B lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_BFu0c_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_BFu0c_B)");
    check_field_offset(lv, v1, 0, "BFu0c_BFu0c_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu0c_B(Test_BFu0c_BFu0c_B, "BFu0c_BFu0c_B", 1);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu0i_B  {
  unsigned char  :0;
  unsigned int  :0;
  bool v1;
};
//SIG(1 BFu0c_BFu0i_B) C1{ Fc:0 Fi:0 Fc}



static void Test_BFu0c_BFu0i_B()
{
  {
    init_simple_test("BFu0c_BFu0i_B");
    static BFu0c_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0c_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0c_BFu0i_B)");
    check_field_offset(lv, v1, 0, "BFu0c_BFu0i_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu0i_B(Test_BFu0c_BFu0i_B, "BFu0c_BFu0i_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu0ll_B  {
  unsigned char  :0;
  __tsu64  :0;
  bool v1;
};
//SIG(1 BFu0c_BFu0ll_B) C1{ Fc:0 FL:0 Fc}



static void Test_BFu0c_BFu0ll_B()
{
  {
    init_simple_test("BFu0c_BFu0ll_B");
    static BFu0c_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0c_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0c_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "BFu0c_BFu0ll_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu0ll_B(Test_BFu0c_BFu0ll_B, "BFu0c_BFu0ll_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu0s_B  {
  unsigned char  :0;
  unsigned short  :0;
  bool v1;
};
//SIG(1 BFu0c_BFu0s_B) C1{ Fc:0 Fs:0 Fc}



static void Test_BFu0c_BFu0s_B()
{
  {
    init_simple_test("BFu0c_BFu0s_B");
    static BFu0c_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0c_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0c_BFu0s_B)");
    check_field_offset(lv, v1, 0, "BFu0c_BFu0s_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu0s_B(Test_BFu0c_BFu0s_B, "BFu0c_BFu0s_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu15i_B  {
  unsigned char  :0;
  unsigned int v1:15;
  bool v2;
};
//SIG(1 BFu0c_BFu15i_B) C1{ Fc:0 Fi:15 Fc}



static void Test_BFu0c_BFu15i_B()
{
  {
    init_simple_test("BFu0c_BFu15i_B");
    static BFu0c_BFu15i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu15i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu15i_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0c_BFu15i_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0c_BFu15i_B");
    check_field_offset(lv, v2, 2, "BFu0c_BFu15i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu15i_B(Test_BFu0c_BFu15i_B, "BFu0c_BFu15i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu15ll_B  {
  unsigned char  :0;
  __tsu64 v1:15;
  bool v2;
};
//SIG(1 BFu0c_BFu15ll_B) C1{ Fc:0 FL:15 Fc}



static void Test_BFu0c_BFu15ll_B()
{
  {
    init_simple_test("BFu0c_BFu15ll_B");
    static BFu0c_BFu15ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu15ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu15ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0c_BFu15ll_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0c_BFu15ll_B");
    check_field_offset(lv, v2, 2, "BFu0c_BFu15ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu15ll_B(Test_BFu0c_BFu15ll_B, "BFu0c_BFu15ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu15s_B  {
  unsigned char  :0;
  unsigned short v1:15;
  bool v2;
};
//SIG(1 BFu0c_BFu15s_B) C1{ Fc:0 Fs:15 Fc}



static void Test_BFu0c_BFu15s_B()
{
  {
    init_simple_test("BFu0c_BFu15s_B");
    static BFu0c_BFu15s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu15s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_BFu15s_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0c_BFu15s_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0c_BFu15s_B");
    check_field_offset(lv, v2, 2, "BFu0c_BFu15s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu15s_B(Test_BFu0c_BFu15s_B, "BFu0c_BFu15s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu16i_B  {
  unsigned char  :0;
  unsigned int v1:16;
  bool v2;
};
//SIG(1 BFu0c_BFu16i_B) C1{ Fc:0 Fi:16 Fc}



static void Test_BFu0c_BFu16i_B()
{
  {
    init_simple_test("BFu0c_BFu16i_B");
    static BFu0c_BFu16i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu16i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu16i_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0c_BFu16i_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0c_BFu16i_B");
    check_field_offset(lv, v2, 2, "BFu0c_BFu16i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu16i_B(Test_BFu0c_BFu16i_B, "BFu0c_BFu16i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu16ll_B  {
  unsigned char  :0;
  __tsu64 v1:16;
  bool v2;
};
//SIG(1 BFu0c_BFu16ll_B) C1{ Fc:0 FL:16 Fc}



static void Test_BFu0c_BFu16ll_B()
{
  {
    init_simple_test("BFu0c_BFu16ll_B");
    static BFu0c_BFu16ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu16ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu16ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0c_BFu16ll_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0c_BFu16ll_B");
    check_field_offset(lv, v2, 2, "BFu0c_BFu16ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu16ll_B(Test_BFu0c_BFu16ll_B, "BFu0c_BFu16ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu16s_B  {
  unsigned char  :0;
  unsigned short v1:16;
  bool v2;
};
//SIG(1 BFu0c_BFu16s_B) C1{ Fc:0 Fs:16 Fc}



static void Test_BFu0c_BFu16s_B()
{
  {
    init_simple_test("BFu0c_BFu16s_B");
    static BFu0c_BFu16s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu16s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_BFu16s_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0c_BFu16s_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0c_BFu16s_B");
    check_field_offset(lv, v2, 2, "BFu0c_BFu16s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu16s_B(Test_BFu0c_BFu16s_B, "BFu0c_BFu16s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu17i_B  {
  unsigned char  :0;
  unsigned int v1:17;
  bool v2;
};
//SIG(1 BFu0c_BFu17i_B) C1{ Fc:0 Fi:17 Fc}



static void Test_BFu0c_BFu17i_B()
{
  {
    init_simple_test("BFu0c_BFu17i_B");
    static BFu0c_BFu17i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu17i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu17i_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0c_BFu17i_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0c_BFu17i_B");
    check_field_offset(lv, v2, 3, "BFu0c_BFu17i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu17i_B(Test_BFu0c_BFu17i_B, "BFu0c_BFu17i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu17ll_B  {
  unsigned char  :0;
  __tsu64 v1:17;
  bool v2;
};
//SIG(1 BFu0c_BFu17ll_B) C1{ Fc:0 FL:17 Fc}



static void Test_BFu0c_BFu17ll_B()
{
  {
    init_simple_test("BFu0c_BFu17ll_B");
    static BFu0c_BFu17ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu17ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu17ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0c_BFu17ll_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0c_BFu17ll_B");
    check_field_offset(lv, v2, 3, "BFu0c_BFu17ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu17ll_B(Test_BFu0c_BFu17ll_B, "BFu0c_BFu17ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu1c_B  {
  unsigned char  :0;
  unsigned char v1:1;
  bool v2;
};
//SIG(1 BFu0c_BFu1c_B) C1{ Fc:0 Fc:1 Fc}



static void Test_BFu0c_BFu1c_B()
{
  {
    init_simple_test("BFu0c_BFu1c_B");
    static BFu0c_BFu1c_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_BFu1c_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_BFu1c_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0c_BFu1c_B");
    check_field_offset(lv, v2, 1, "BFu0c_BFu1c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu1c_B(Test_BFu0c_BFu1c_B, "BFu0c_BFu1c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu1i_B  {
  unsigned char  :0;
  unsigned int v1:1;
  bool v2;
};
//SIG(1 BFu0c_BFu1i_B) C1{ Fc:0 Fi:1 Fc}



static void Test_BFu0c_BFu1i_B()
{
  {
    init_simple_test("BFu0c_BFu1i_B");
    static BFu0c_BFu1i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu1i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu1i_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0c_BFu1i_B");
    check_field_offset(lv, v2, 1, "BFu0c_BFu1i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu1i_B(Test_BFu0c_BFu1i_B, "BFu0c_BFu1i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu1ll_B  {
  unsigned char  :0;
  __tsu64 v1:1;
  bool v2;
};
//SIG(1 BFu0c_BFu1ll_B) C1{ Fc:0 FL:1 Fc}



static void Test_BFu0c_BFu1ll_B()
{
  {
    init_simple_test("BFu0c_BFu1ll_B");
    static BFu0c_BFu1ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu1ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu1ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0c_BFu1ll_B");
    check_field_offset(lv, v2, 1, "BFu0c_BFu1ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu1ll_B(Test_BFu0c_BFu1ll_B, "BFu0c_BFu1ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu1s_B  {
  unsigned char  :0;
  unsigned short v1:1;
  bool v2;
};
//SIG(1 BFu0c_BFu1s_B) C1{ Fc:0 Fs:1 Fc}



static void Test_BFu0c_BFu1s_B()
{
  {
    init_simple_test("BFu0c_BFu1s_B");
    static BFu0c_BFu1s_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_BFu1s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_BFu1s_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0c_BFu1s_B");
    check_field_offset(lv, v2, 1, "BFu0c_BFu1s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu1s_B(Test_BFu0c_BFu1s_B, "BFu0c_BFu1s_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu31i_B  {
  unsigned char  :0;
  unsigned int v1:31;
  bool v2;
};
//SIG(1 BFu0c_BFu31i_B) C1{ Fc:0 Fi:31 Fc}



static void Test_BFu0c_BFu31i_B()
{
  {
    init_simple_test("BFu0c_BFu31i_B");
    static BFu0c_BFu31i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_BFu31i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu31i_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0c_BFu31i_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0c_BFu31i_B");
    check_field_offset(lv, v2, 4, "BFu0c_BFu31i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu31i_B(Test_BFu0c_BFu31i_B, "BFu0c_BFu31i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu31ll_B  {
  unsigned char  :0;
  __tsu64 v1:31;
  bool v2;
};
//SIG(1 BFu0c_BFu31ll_B) C1{ Fc:0 FL:31 Fc}



static void Test_BFu0c_BFu31ll_B()
{
  {
    init_simple_test("BFu0c_BFu31ll_B");
    static BFu0c_BFu31ll_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_BFu31ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu31ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0c_BFu31ll_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0c_BFu31ll_B");
    check_field_offset(lv, v2, 4, "BFu0c_BFu31ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu31ll_B(Test_BFu0c_BFu31ll_B, "BFu0c_BFu31ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu32i_B  {
  unsigned char  :0;
  unsigned int v1:32;
  bool v2;
};
//SIG(1 BFu0c_BFu32i_B) C1{ Fc:0 Fi:32 Fc}



static void Test_BFu0c_BFu32i_B()
{
  {
    init_simple_test("BFu0c_BFu32i_B");
    static BFu0c_BFu32i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_BFu32i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu32i_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0c_BFu32i_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0c_BFu32i_B");
    check_field_offset(lv, v2, 4, "BFu0c_BFu32i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu32i_B(Test_BFu0c_BFu32i_B, "BFu0c_BFu32i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu32ll_B  {
  unsigned char  :0;
  __tsu64 v1:32;
  bool v2;
};
//SIG(1 BFu0c_BFu32ll_B) C1{ Fc:0 FL:32 Fc}



static void Test_BFu0c_BFu32ll_B()
{
  {
    init_simple_test("BFu0c_BFu32ll_B");
    static BFu0c_BFu32ll_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_BFu32ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu32ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0c_BFu32ll_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0c_BFu32ll_B");
    check_field_offset(lv, v2, 4, "BFu0c_BFu32ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu32ll_B(Test_BFu0c_BFu32ll_B, "BFu0c_BFu32ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu33_B  {
  unsigned char  :0;
  __tsu64 v1:33;
  bool v2;
};
//SIG(1 BFu0c_BFu33_B) C1{ Fc:0 FL:33 Fc}



static void Test_BFu0c_BFu33_B()
{
  {
    init_simple_test("BFu0c_BFu33_B");
    static BFu0c_BFu33_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_BFu33_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu33_B)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu0c_BFu33_B");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu0c_BFu33_B");
    check_field_offset(lv, v2, 5, "BFu0c_BFu33_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu33_B(Test_BFu0c_BFu33_B, "BFu0c_BFu33_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu7c_B  {
  unsigned char  :0;
  unsigned char v1:7;
  bool v2;
};
//SIG(1 BFu0c_BFu7c_B) C1{ Fc:0 Fc:7 Fc}



static void Test_BFu0c_BFu7c_B()
{
  {
    init_simple_test("BFu0c_BFu7c_B");
    static BFu0c_BFu7c_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_BFu7c_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_BFu7c_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0c_BFu7c_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0c_BFu7c_B");
    check_field_offset(lv, v2, 1, "BFu0c_BFu7c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu7c_B(Test_BFu0c_BFu7c_B, "BFu0c_BFu7c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu7i_B  {
  unsigned char  :0;
  unsigned int v1:7;
  bool v2;
};
//SIG(1 BFu0c_BFu7i_B) C1{ Fc:0 Fi:7 Fc}



static void Test_BFu0c_BFu7i_B()
{
  {
    init_simple_test("BFu0c_BFu7i_B");
    static BFu0c_BFu7i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu7i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu7i_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0c_BFu7i_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0c_BFu7i_B");
    check_field_offset(lv, v2, 1, "BFu0c_BFu7i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu7i_B(Test_BFu0c_BFu7i_B, "BFu0c_BFu7i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu7ll_B  {
  unsigned char  :0;
  __tsu64 v1:7;
  bool v2;
};
//SIG(1 BFu0c_BFu7ll_B) C1{ Fc:0 FL:7 Fc}



static void Test_BFu0c_BFu7ll_B()
{
  {
    init_simple_test("BFu0c_BFu7ll_B");
    static BFu0c_BFu7ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu7ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu7ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0c_BFu7ll_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0c_BFu7ll_B");
    check_field_offset(lv, v2, 1, "BFu0c_BFu7ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu7ll_B(Test_BFu0c_BFu7ll_B, "BFu0c_BFu7ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu7s_B  {
  unsigned char  :0;
  unsigned short v1:7;
  bool v2;
};
//SIG(1 BFu0c_BFu7s_B) C1{ Fc:0 Fs:7 Fc}



static void Test_BFu0c_BFu7s_B()
{
  {
    init_simple_test("BFu0c_BFu7s_B");
    static BFu0c_BFu7s_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_BFu7s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_BFu7s_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0c_BFu7s_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0c_BFu7s_B");
    check_field_offset(lv, v2, 1, "BFu0c_BFu7s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu7s_B(Test_BFu0c_BFu7s_B, "BFu0c_BFu7s_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu8c_B  {
  unsigned char  :0;
  unsigned char v1:8;
  bool v2;
};
//SIG(1 BFu0c_BFu8c_B) C1{ Fc:0 Fc:8 Fc}



static void Test_BFu0c_BFu8c_B()
{
  {
    init_simple_test("BFu0c_BFu8c_B");
    static BFu0c_BFu8c_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_BFu8c_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_BFu8c_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0c_BFu8c_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0c_BFu8c_B");
    check_field_offset(lv, v2, 1, "BFu0c_BFu8c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu8c_B(Test_BFu0c_BFu8c_B, "BFu0c_BFu8c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu8i_B  {
  unsigned char  :0;
  unsigned int v1:8;
  bool v2;
};
//SIG(1 BFu0c_BFu8i_B) C1{ Fc:0 Fi:8 Fc}



static void Test_BFu0c_BFu8i_B()
{
  {
    init_simple_test("BFu0c_BFu8i_B");
    static BFu0c_BFu8i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu8i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu8i_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0c_BFu8i_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0c_BFu8i_B");
    check_field_offset(lv, v2, 1, "BFu0c_BFu8i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu8i_B(Test_BFu0c_BFu8i_B, "BFu0c_BFu8i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu8ll_B  {
  unsigned char  :0;
  __tsu64 v1:8;
  bool v2;
};
//SIG(1 BFu0c_BFu8ll_B) C1{ Fc:0 FL:8 Fc}



static void Test_BFu0c_BFu8ll_B()
{
  {
    init_simple_test("BFu0c_BFu8ll_B");
    static BFu0c_BFu8ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu8ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu8ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0c_BFu8ll_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0c_BFu8ll_B");
    check_field_offset(lv, v2, 1, "BFu0c_BFu8ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu8ll_B(Test_BFu0c_BFu8ll_B, "BFu0c_BFu8ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu8s_B  {
  unsigned char  :0;
  unsigned short v1:8;
  bool v2;
};
//SIG(1 BFu0c_BFu8s_B) C1{ Fc:0 Fs:8 Fc}



static void Test_BFu0c_BFu8s_B()
{
  {
    init_simple_test("BFu0c_BFu8s_B");
    static BFu0c_BFu8s_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_BFu8s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_BFu8s_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0c_BFu8s_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0c_BFu8s_B");
    check_field_offset(lv, v2, 1, "BFu0c_BFu8s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu8s_B(Test_BFu0c_BFu8s_B, "BFu0c_BFu8s_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu9i_B  {
  unsigned char  :0;
  unsigned int v1:9;
  bool v2;
};
//SIG(1 BFu0c_BFu9i_B) C1{ Fc:0 Fi:9 Fc}



static void Test_BFu0c_BFu9i_B()
{
  {
    init_simple_test("BFu0c_BFu9i_B");
    static BFu0c_BFu9i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu9i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu9i_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0c_BFu9i_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0c_BFu9i_B");
    check_field_offset(lv, v2, 2, "BFu0c_BFu9i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu9i_B(Test_BFu0c_BFu9i_B, "BFu0c_BFu9i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu9ll_B  {
  unsigned char  :0;
  __tsu64 v1:9;
  bool v2;
};
//SIG(1 BFu0c_BFu9ll_B) C1{ Fc:0 FL:9 Fc}



static void Test_BFu0c_BFu9ll_B()
{
  {
    init_simple_test("BFu0c_BFu9ll_B");
    static BFu0c_BFu9ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu9ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu9ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0c_BFu9ll_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0c_BFu9ll_B");
    check_field_offset(lv, v2, 2, "BFu0c_BFu9ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu9ll_B(Test_BFu0c_BFu9ll_B, "BFu0c_BFu9ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_BFu9s_B  {
  unsigned char  :0;
  unsigned short v1:9;
  bool v2;
};
//SIG(1 BFu0c_BFu9s_B) C1{ Fc:0 Fs:9 Fc}



static void Test_BFu0c_BFu9s_B()
{
  {
    init_simple_test("BFu0c_BFu9s_B");
    static BFu0c_BFu9s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu9s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_BFu9s_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0c_BFu9s_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0c_BFu9s_B");
    check_field_offset(lv, v2, 2, "BFu0c_BFu9s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_BFu9s_B(Test_BFu0c_BFu9s_B, "BFu0c_BFu9s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_C_B  {
  unsigned char  :0;
  char v1;
  bool v2;
};
//SIG(1 BFu0c_C_B) C1{ Fc:0 Fc[2]}



static void Test_BFu0c_C_B()
{
  {
    init_simple_test("BFu0c_C_B");
    static BFu0c_C_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_C_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_C_B)");
    check_field_offset(lv, v1, 0, "BFu0c_C_B.v1");
    check_field_offset(lv, v2, 1, "BFu0c_C_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_C_B(Test_BFu0c_C_B, "BFu0c_C_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_D_B  {
  unsigned char  :0;
  double v1;
  bool v2;
};
//SIG(1 BFu0c_D_B) C1{ Fc:0 FL Fc}



static void Test_BFu0c_D_B()
{
  {
    init_simple_test("BFu0c_D_B");
    static BFu0c_D_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0c_D_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_D_B)");
    check_field_offset(lv, v1, 0, "BFu0c_D_B.v1");
    check_field_offset(lv, v2, 8, "BFu0c_D_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_D_B(Test_BFu0c_D_B, "BFu0c_D_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_F_B  {
  unsigned char  :0;
  float v1;
  bool v2;
};
//SIG(1 BFu0c_F_B) C1{ Fc:0 Fi Fc}



static void Test_BFu0c_F_B()
{
  {
    init_simple_test("BFu0c_F_B");
    static BFu0c_F_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_F_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_F_B)");
    check_field_offset(lv, v1, 0, "BFu0c_F_B.v1");
    check_field_offset(lv, v2, 4, "BFu0c_F_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_F_B(Test_BFu0c_F_B, "BFu0c_F_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_I_B  {
  unsigned char  :0;
  int v1;
  bool v2;
};
//SIG(1 BFu0c_I_B) C1{ Fc:0 Fi Fc}



static void Test_BFu0c_I_B()
{
  {
    init_simple_test("BFu0c_I_B");
    static BFu0c_I_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_I_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_I_B)");
    check_field_offset(lv, v1, 0, "BFu0c_I_B.v1");
    check_field_offset(lv, v2, 4, "BFu0c_I_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_I_B(Test_BFu0c_I_B, "BFu0c_I_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_Ip_B  {
  unsigned char  :0;
  int *v1;
  bool v2;
};
//SIG(1 BFu0c_Ip_B) C1{ Fc:0 Fp Fc}



static void Test_BFu0c_Ip_B()
{
  {
    init_simple_test("BFu0c_Ip_B");
    static BFu0c_Ip_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0c_Ip_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Ip_B)");
    check_field_offset(lv, v1, 0, "BFu0c_Ip_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0c_Ip_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_Ip_B(Test_BFu0c_Ip_B, "BFu0c_Ip_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_L_B  {
  unsigned char  :0;
  __tsi64 v1;
  bool v2;
};
//SIG(1 BFu0c_L_B) C1{ Fc:0 FL Fc}



static void Test_BFu0c_L_B()
{
  {
    init_simple_test("BFu0c_L_B");
    static BFu0c_L_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0c_L_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_L_B)");
    check_field_offset(lv, v1, 0, "BFu0c_L_B.v1");
    check_field_offset(lv, v2, 8, "BFu0c_L_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_L_B(Test_BFu0c_L_B, "BFu0c_L_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_S_B  {
  unsigned char  :0;
  short v1;
  bool v2;
};
//SIG(1 BFu0c_S_B) C1{ Fc:0 Fs Fc}



static void Test_BFu0c_S_B()
{
  {
    init_simple_test("BFu0c_S_B");
    static BFu0c_S_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_S_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_S_B)");
    check_field_offset(lv, v1, 0, "BFu0c_S_B.v1");
    check_field_offset(lv, v2, 2, "BFu0c_S_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_S_B(Test_BFu0c_S_B, "BFu0c_S_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_Uc_B  {
  unsigned char  :0;
  unsigned char v1;
  bool v2;
};
//SIG(1 BFu0c_Uc_B) C1{ Fc:0 Fc[2]}



static void Test_BFu0c_Uc_B()
{
  {
    init_simple_test("BFu0c_Uc_B");
    static BFu0c_Uc_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_Uc_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_Uc_B)");
    check_field_offset(lv, v1, 0, "BFu0c_Uc_B.v1");
    check_field_offset(lv, v2, 1, "BFu0c_Uc_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_Uc_B(Test_BFu0c_Uc_B, "BFu0c_Uc_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_Ui_B  {
  unsigned char  :0;
  unsigned int v1;
  bool v2;
};
//SIG(1 BFu0c_Ui_B) C1{ Fc:0 Fi Fc}



static void Test_BFu0c_Ui_B()
{
  {
    init_simple_test("BFu0c_Ui_B");
    static BFu0c_Ui_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_Ui_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Ui_B)");
    check_field_offset(lv, v1, 0, "BFu0c_Ui_B.v1");
    check_field_offset(lv, v2, 4, "BFu0c_Ui_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_Ui_B(Test_BFu0c_Ui_B, "BFu0c_Ui_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_Ul_B  {
  unsigned char  :0;
  __tsu64 v1;
  bool v2;
};
//SIG(1 BFu0c_Ul_B) C1{ Fc:0 FL Fc}



static void Test_BFu0c_Ul_B()
{
  {
    init_simple_test("BFu0c_Ul_B");
    static BFu0c_Ul_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0c_Ul_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Ul_B)");
    check_field_offset(lv, v1, 0, "BFu0c_Ul_B.v1");
    check_field_offset(lv, v2, 8, "BFu0c_Ul_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_Ul_B(Test_BFu0c_Ul_B, "BFu0c_Ul_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_Us_B  {
  unsigned char  :0;
  unsigned short v1;
  bool v2;
};
//SIG(1 BFu0c_Us_B) C1{ Fc:0 Fs Fc}



static void Test_BFu0c_Us_B()
{
  {
    init_simple_test("BFu0c_Us_B");
    static BFu0c_Us_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Us_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_Us_B)");
    check_field_offset(lv, v1, 0, "BFu0c_Us_B.v1");
    check_field_offset(lv, v2, 2, "BFu0c_Us_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_Us_B(Test_BFu0c_Us_B, "BFu0c_Us_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_Vp_B  {
  unsigned char  :0;
  void *v1;
  bool v2;
};
//SIG(1 BFu0c_Vp_B) C1{ Fc:0 Fp Fc}



static void Test_BFu0c_Vp_B()
{
  {
    init_simple_test("BFu0c_Vp_B");
    static BFu0c_Vp_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0c_Vp_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Vp_B)");
    check_field_offset(lv, v1, 0, "BFu0c_Vp_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0c_Vp_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_Vp_B(Test_BFu0c_Vp_B, "BFu0c_Vp_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B  {
  unsigned int  :0;
  bool v1;
};
//SIG(1 BFu0i_B) C1{ Fi:0 Fc}



static void Test_BFu0i_B()
{
  {
    init_simple_test("BFu0i_B");
    static BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_B)");
    check_field_offset(lv, v1, 0, "BFu0i_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0i_B(Test_BFu0i_B, "BFu0i_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_B  {
  unsigned int  :0;
  bool v1;
  bool v2;
};
//SIG(1 BFu0i_B_B) C1{ Fi:0 Fc[2]}



static void Test_BFu0i_B_B()
{
  {
    init_simple_test("BFu0i_B_B");
    static BFu0i_B_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_B_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_B_B)");
    check_field_offset(lv, v1, 0, "BFu0i_B_B.v1");
    check_field_offset(lv, v2, 1, "BFu0i_B_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_B(Test_BFu0i_B_B, "BFu0i_B_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu0c  {
  unsigned int  :0;
  bool v1;
  unsigned char  :0;
};
//SIG(1 BFu0i_B_BFu0c) C1{ Fi:0 Fc Fc:0}



static void Test_BFu0i_B_BFu0c()
{
  {
    init_simple_test("BFu0i_B_BFu0c");
    static BFu0i_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_B_BFu0c)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu0c(Test_BFu0i_B_BFu0c, "BFu0i_B_BFu0c", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu0i  {
  unsigned int  :0;
  bool v1;
  unsigned int  :0;
};
//SIG(1 BFu0i_B_BFu0i) C1{ Fi:0 Fc Fi:0}



static void Test_BFu0i_B_BFu0i()
{
  {
    init_simple_test("BFu0i_B_BFu0i");
    static BFu0i_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_B_BFu0i)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu0i(Test_BFu0i_B_BFu0i, "BFu0i_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu0ll  {
  unsigned int  :0;
  bool v1;
  __tsu64  :0;
};
//SIG(1 BFu0i_B_BFu0ll) C1{ Fi:0 Fc FL:0}



static void Test_BFu0i_B_BFu0ll()
{
  {
    init_simple_test("BFu0i_B_BFu0ll");
    static BFu0i_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu0ll(Test_BFu0i_B_BFu0ll, "BFu0i_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu0s  {
  unsigned int  :0;
  bool v1;
  unsigned short  :0;
};
//SIG(1 BFu0i_B_BFu0s) C1{ Fi:0 Fc Fs:0}



static void Test_BFu0i_B_BFu0s()
{
  {
    init_simple_test("BFu0i_B_BFu0s");
    static BFu0i_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_B_BFu0s)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu0s(Test_BFu0i_B_BFu0s, "BFu0i_B_BFu0s", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu15i  {
  unsigned int  :0;
  bool v1;
  unsigned int v2:15;
};
//SIG(1 BFu0i_B_BFu15i) C1{ Fi:0 Fc Fi:15}



static void Test_BFu0i_B_BFu15i()
{
  {
    init_simple_test("BFu0i_B_BFu15i");
    static BFu0i_B_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_B_BFu15i)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu15i.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "BFu0i_B_BFu15i");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "BFu0i_B_BFu15i");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu15i(Test_BFu0i_B_BFu15i, "BFu0i_B_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu15ll  {
  unsigned int  :0;
  bool v1;
  __tsu64 v2:15;
};
//SIG(1 BFu0i_B_BFu15ll) C1{ Fi:0 Fc FL:15}



static void Test_BFu0i_B_BFu15ll()
{
  {
    init_simple_test("BFu0i_B_BFu15ll");
    static BFu0i_B_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_B_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu15ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "BFu0i_B_BFu15ll");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "BFu0i_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu15ll(Test_BFu0i_B_BFu15ll, "BFu0i_B_BFu15ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu15s  {
  unsigned int  :0;
  bool v1;
  unsigned short v2:15;
};
//SIG(1 BFu0i_B_BFu15s) C1{ Fi:0 Fc Fs:15}



static void Test_BFu0i_B_BFu15s()
{
  {
    init_simple_test("BFu0i_B_BFu15s");
    static BFu0i_B_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_BFu15s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_B_BFu15s)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu15s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "BFu0i_B_BFu15s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "BFu0i_B_BFu15s");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu15s(Test_BFu0i_B_BFu15s, "BFu0i_B_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu16i  {
  unsigned int  :0;
  bool v1;
  unsigned int v2:16;
};
//SIG(1 BFu0i_B_BFu16i) C1{ Fi:0 Fc Fi:16}



static void Test_BFu0i_B_BFu16i()
{
  {
    init_simple_test("BFu0i_B_BFu16i");
    static BFu0i_B_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_B_BFu16i)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu16i.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "BFu0i_B_BFu16i");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "BFu0i_B_BFu16i");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu16i(Test_BFu0i_B_BFu16i, "BFu0i_B_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu16ll  {
  unsigned int  :0;
  bool v1;
  __tsu64 v2:16;
};
//SIG(1 BFu0i_B_BFu16ll) C1{ Fi:0 Fc FL:16}



static void Test_BFu0i_B_BFu16ll()
{
  {
    init_simple_test("BFu0i_B_BFu16ll");
    static BFu0i_B_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_B_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu16ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "BFu0i_B_BFu16ll");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "BFu0i_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu16ll(Test_BFu0i_B_BFu16ll, "BFu0i_B_BFu16ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu16s  {
  unsigned int  :0;
  bool v1;
  unsigned short v2:16;
};
//SIG(1 BFu0i_B_BFu16s) C1{ Fi:0 Fc Fs:16}



static void Test_BFu0i_B_BFu16s()
{
  {
    init_simple_test("BFu0i_B_BFu16s");
    static BFu0i_B_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_BFu16s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_B_BFu16s)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu16s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "BFu0i_B_BFu16s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "BFu0i_B_BFu16s");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu16s(Test_BFu0i_B_BFu16s, "BFu0i_B_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu17i  {
  unsigned int  :0;
  bool v1;
  unsigned int v2:17;
};
//SIG(1 BFu0i_B_BFu17i) C1{ Fi:0 Fc Fi:17}



static void Test_BFu0i_B_BFu17i()
{
  {
    init_simple_test("BFu0i_B_BFu17i");
    static BFu0i_B_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_B_BFu17i)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu17i.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "BFu0i_B_BFu17i");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "BFu0i_B_BFu17i");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu17i(Test_BFu0i_B_BFu17i, "BFu0i_B_BFu17i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu17ll  {
  unsigned int  :0;
  bool v1;
  __tsu64 v2:17;
};
//SIG(1 BFu0i_B_BFu17ll) C1{ Fi:0 Fc FL:17}



static void Test_BFu0i_B_BFu17ll()
{
  {
    init_simple_test("BFu0i_B_BFu17ll");
    static BFu0i_B_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_B_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu17ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "BFu0i_B_BFu17ll");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "BFu0i_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu17ll(Test_BFu0i_B_BFu17ll, "BFu0i_B_BFu17ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu1c  {
  unsigned int  :0;
  bool v1;
  unsigned char v2:1;
};
//SIG(1 BFu0i_B_BFu1c) C1{ Fi:0 Fc Fc:1}



static void Test_BFu0i_B_BFu1c()
{
  {
    init_simple_test("BFu0i_B_BFu1c");
    static BFu0i_B_BFu1c lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_B_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_B_BFu1c)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu1c.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0i_B_BFu1c");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu1c(Test_BFu0i_B_BFu1c, "BFu0i_B_BFu1c", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu1i  {
  unsigned int  :0;
  bool v1;
  unsigned int v2:1;
};
//SIG(1 BFu0i_B_BFu1i) C1{ Fi:0 Fc Fi:1}



static void Test_BFu0i_B_BFu1i()
{
  {
    init_simple_test("BFu0i_B_BFu1i");
    static BFu0i_B_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_B_BFu1i)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu1i.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0i_B_BFu1i");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu1i(Test_BFu0i_B_BFu1i, "BFu0i_B_BFu1i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu1ll  {
  unsigned int  :0;
  bool v1;
  __tsu64 v2:1;
};
//SIG(1 BFu0i_B_BFu1ll) C1{ Fi:0 Fc FL:1}



static void Test_BFu0i_B_BFu1ll()
{
  {
    init_simple_test("BFu0i_B_BFu1ll");
    static BFu0i_B_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_B_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu1ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0i_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu1ll(Test_BFu0i_B_BFu1ll, "BFu0i_B_BFu1ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu1s  {
  unsigned int  :0;
  bool v1;
  unsigned short v2:1;
};
//SIG(1 BFu0i_B_BFu1s) C1{ Fi:0 Fc Fs:1}



static void Test_BFu0i_B_BFu1s()
{
  {
    init_simple_test("BFu0i_B_BFu1s");
    static BFu0i_B_BFu1s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_B_BFu1s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_B_BFu1s)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu1s.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0i_B_BFu1s");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu1s(Test_BFu0i_B_BFu1s, "BFu0i_B_BFu1s", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu31i  {
  unsigned int  :0;
  bool v1;
  unsigned int v2:31;
};
//SIG(1 BFu0i_B_BFu31i) C1{ Fi:0 Fc Fi:31}



static void Test_BFu0i_B_BFu31i()
{
  {
    init_simple_test("BFu0i_B_BFu31i");
    static BFu0i_B_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_B_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_B_BFu31i)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu31i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "BFu0i_B_BFu31i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "BFu0i_B_BFu31i");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu31i(Test_BFu0i_B_BFu31i, "BFu0i_B_BFu31i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu31ll  {
  unsigned int  :0;
  bool v1;
  __tsu64 v2:31;
};
//SIG(1 BFu0i_B_BFu31ll) C1{ Fi:0 Fc FL:31}



static void Test_BFu0i_B_BFu31ll()
{
  {
    init_simple_test("BFu0i_B_BFu31ll");
    static BFu0i_B_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_B_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu31ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "BFu0i_B_BFu31ll");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "BFu0i_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu31ll(Test_BFu0i_B_BFu31ll, "BFu0i_B_BFu31ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu32i  {
  unsigned int  :0;
  bool v1;
  unsigned int v2:32;
};
//SIG(1 BFu0i_B_BFu32i) C1{ Fi:0 Fc Fi:32}



static void Test_BFu0i_B_BFu32i()
{
  {
    init_simple_test("BFu0i_B_BFu32i");
    static BFu0i_B_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_B_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_B_BFu32i)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu32i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "BFu0i_B_BFu32i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "BFu0i_B_BFu32i");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu32i(Test_BFu0i_B_BFu32i, "BFu0i_B_BFu32i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu32ll  {
  unsigned int  :0;
  bool v1;
  __tsu64 v2:32;
};
//SIG(1 BFu0i_B_BFu32ll) C1{ Fi:0 Fc FL:32}



static void Test_BFu0i_B_BFu32ll()
{
  {
    init_simple_test("BFu0i_B_BFu32ll");
    static BFu0i_B_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_B_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu32ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "BFu0i_B_BFu32ll");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "BFu0i_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu32ll(Test_BFu0i_B_BFu32ll, "BFu0i_B_BFu32ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu33  {
  unsigned int  :0;
  bool v1;
  __tsu64 v2:33;
};
//SIG(1 BFu0i_B_BFu33) C1{ Fi:0 Fc FL:33}



static void Test_BFu0i_B_BFu33()
{
  {
    init_simple_test("BFu0i_B_BFu33");
    static BFu0i_B_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_B_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_BFu33)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu33.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "BFu0i_B_BFu33");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "BFu0i_B_BFu33");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu33(Test_BFu0i_B_BFu33, "BFu0i_B_BFu33", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu7c  {
  unsigned int  :0;
  bool v1;
  unsigned char v2:7;
};
//SIG(1 BFu0i_B_BFu7c) C1{ Fi:0 Fc Fc:7}



static void Test_BFu0i_B_BFu7c()
{
  {
    init_simple_test("BFu0i_B_BFu7c");
    static BFu0i_B_BFu7c lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_B_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_B_BFu7c)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu7c.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0i_B_BFu7c");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0i_B_BFu7c");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu7c(Test_BFu0i_B_BFu7c, "BFu0i_B_BFu7c", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu7i  {
  unsigned int  :0;
  bool v1;
  unsigned int v2:7;
};
//SIG(1 BFu0i_B_BFu7i) C1{ Fi:0 Fc Fi:7}



static void Test_BFu0i_B_BFu7i()
{
  {
    init_simple_test("BFu0i_B_BFu7i");
    static BFu0i_B_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_B_BFu7i)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu7i.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0i_B_BFu7i");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0i_B_BFu7i");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu7i(Test_BFu0i_B_BFu7i, "BFu0i_B_BFu7i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu7ll  {
  unsigned int  :0;
  bool v1;
  __tsu64 v2:7;
};
//SIG(1 BFu0i_B_BFu7ll) C1{ Fi:0 Fc FL:7}



static void Test_BFu0i_B_BFu7ll()
{
  {
    init_simple_test("BFu0i_B_BFu7ll");
    static BFu0i_B_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_B_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu7ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0i_B_BFu7ll");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0i_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu7ll(Test_BFu0i_B_BFu7ll, "BFu0i_B_BFu7ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu7s  {
  unsigned int  :0;
  bool v1;
  unsigned short v2:7;
};
//SIG(1 BFu0i_B_BFu7s) C1{ Fi:0 Fc Fs:7}



static void Test_BFu0i_B_BFu7s()
{
  {
    init_simple_test("BFu0i_B_BFu7s");
    static BFu0i_B_BFu7s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_B_BFu7s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_B_BFu7s)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu7s.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0i_B_BFu7s");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0i_B_BFu7s");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu7s(Test_BFu0i_B_BFu7s, "BFu0i_B_BFu7s", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu8c  {
  unsigned int  :0;
  bool v1;
  unsigned char v2:8;
};
//SIG(1 BFu0i_B_BFu8c) C1{ Fi:0 Fc Fc:8}



static void Test_BFu0i_B_BFu8c()
{
  {
    init_simple_test("BFu0i_B_BFu8c");
    static BFu0i_B_BFu8c lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_B_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_B_BFu8c)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu8c.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0i_B_BFu8c");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0i_B_BFu8c");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu8c(Test_BFu0i_B_BFu8c, "BFu0i_B_BFu8c", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu8i  {
  unsigned int  :0;
  bool v1;
  unsigned int v2:8;
};
//SIG(1 BFu0i_B_BFu8i) C1{ Fi:0 Fc Fi:8}



static void Test_BFu0i_B_BFu8i()
{
  {
    init_simple_test("BFu0i_B_BFu8i");
    static BFu0i_B_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_B_BFu8i)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu8i.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0i_B_BFu8i");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0i_B_BFu8i");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu8i(Test_BFu0i_B_BFu8i, "BFu0i_B_BFu8i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu8ll  {
  unsigned int  :0;
  bool v1;
  __tsu64 v2:8;
};
//SIG(1 BFu0i_B_BFu8ll) C1{ Fi:0 Fc FL:8}



static void Test_BFu0i_B_BFu8ll()
{
  {
    init_simple_test("BFu0i_B_BFu8ll");
    static BFu0i_B_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_B_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu8ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0i_B_BFu8ll");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0i_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu8ll(Test_BFu0i_B_BFu8ll, "BFu0i_B_BFu8ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu8s  {
  unsigned int  :0;
  bool v1;
  unsigned short v2:8;
};
//SIG(1 BFu0i_B_BFu8s) C1{ Fi:0 Fc Fs:8}



static void Test_BFu0i_B_BFu8s()
{
  {
    init_simple_test("BFu0i_B_BFu8s");
    static BFu0i_B_BFu8s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_B_BFu8s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_B_BFu8s)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu8s.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0i_B_BFu8s");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0i_B_BFu8s");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu8s(Test_BFu0i_B_BFu8s, "BFu0i_B_BFu8s", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu9i  {
  unsigned int  :0;
  bool v1;
  unsigned int v2:9;
};
//SIG(1 BFu0i_B_BFu9i) C1{ Fi:0 Fc Fi:9}



static void Test_BFu0i_B_BFu9i()
{
  {
    init_simple_test("BFu0i_B_BFu9i");
    static BFu0i_B_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_B_BFu9i)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu9i.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "BFu0i_B_BFu9i");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "BFu0i_B_BFu9i");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu9i(Test_BFu0i_B_BFu9i, "BFu0i_B_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu9ll  {
  unsigned int  :0;
  bool v1;
  __tsu64 v2:9;
};
//SIG(1 BFu0i_B_BFu9ll) C1{ Fi:0 Fc FL:9}



static void Test_BFu0i_B_BFu9ll()
{
  {
    init_simple_test("BFu0i_B_BFu9ll");
    static BFu0i_B_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_B_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu9ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "BFu0i_B_BFu9ll");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "BFu0i_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu9ll(Test_BFu0i_B_BFu9ll, "BFu0i_B_BFu9ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_BFu9s  {
  unsigned int  :0;
  bool v1;
  unsigned short v2:9;
};
//SIG(1 BFu0i_B_BFu9s) C1{ Fi:0 Fc Fs:9}



static void Test_BFu0i_B_BFu9s()
{
  {
    init_simple_test("BFu0i_B_BFu9s");
    static BFu0i_B_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_BFu9s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_B_BFu9s)");
    check_field_offset(lv, v1, 0, "BFu0i_B_BFu9s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "BFu0i_B_BFu9s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "BFu0i_B_BFu9s");
  }
}
static Arrange_To_Call_Me vBFu0i_B_BFu9s(Test_BFu0i_B_BFu9s, "BFu0i_B_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_C  {
  unsigned int  :0;
  bool v1;
  char v2;
};
//SIG(1 BFu0i_B_C) C1{ Fi:0 Fc[2]}



static void Test_BFu0i_B_C()
{
  {
    init_simple_test("BFu0i_B_C");
    static BFu0i_B_C lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_B_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_B_C)");
    check_field_offset(lv, v1, 0, "BFu0i_B_C.v1");
    check_field_offset(lv, v2, 1, "BFu0i_B_C.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_C(Test_BFu0i_B_C, "BFu0i_B_C", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_D  {
  unsigned int  :0;
  bool v1;
  double v2;
};
//SIG(1 BFu0i_B_D) C1{ Fi:0 Fc FL}



static void Test_BFu0i_B_D()
{
  {
    init_simple_test("BFu0i_B_D");
    static BFu0i_B_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0i_B_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_D)");
    check_field_offset(lv, v1, 0, "BFu0i_B_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0i_B_D.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_D(Test_BFu0i_B_D, "BFu0i_B_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_F  {
  unsigned int  :0;
  bool v1;
  float v2;
};
//SIG(1 BFu0i_B_F) C1{ Fi:0 Fc Fi}



static void Test_BFu0i_B_F()
{
  {
    init_simple_test("BFu0i_B_F");
    static BFu0i_B_F lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_B_F)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_B_F)");
    check_field_offset(lv, v1, 0, "BFu0i_B_F.v1");
    check_field_offset(lv, v2, 4, "BFu0i_B_F.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_F(Test_BFu0i_B_F, "BFu0i_B_F", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_I  {
  unsigned int  :0;
  bool v1;
  int v2;
};
//SIG(1 BFu0i_B_I) C1{ Fi:0 Fc Fi}



static void Test_BFu0i_B_I()
{
  {
    init_simple_test("BFu0i_B_I");
    static BFu0i_B_I lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_B_I)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_B_I)");
    check_field_offset(lv, v1, 0, "BFu0i_B_I.v1");
    check_field_offset(lv, v2, 4, "BFu0i_B_I.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_I(Test_BFu0i_B_I, "BFu0i_B_I", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_Ip  {
  unsigned int  :0;
  bool v1;
  int *v2;
};
//SIG(1 BFu0i_B_Ip) C1{ Fi:0 Fc Fp}



static void Test_BFu0i_B_Ip()
{
  {
    init_simple_test("BFu0i_B_Ip");
    static BFu0i_B_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0i_B_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_Ip)");
    check_field_offset(lv, v1, 0, "BFu0i_B_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0i_B_Ip.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_Ip(Test_BFu0i_B_Ip, "BFu0i_B_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_L  {
  unsigned int  :0;
  bool v1;
  __tsi64 v2;
};
//SIG(1 BFu0i_B_L) C1{ Fi:0 Fc FL}



static void Test_BFu0i_B_L()
{
  {
    init_simple_test("BFu0i_B_L");
    static BFu0i_B_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0i_B_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_L)");
    check_field_offset(lv, v1, 0, "BFu0i_B_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0i_B_L.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_L(Test_BFu0i_B_L, "BFu0i_B_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_S  {
  unsigned int  :0;
  bool v1;
  short v2;
};
//SIG(1 BFu0i_B_S) C1{ Fi:0 Fc Fs}



static void Test_BFu0i_B_S()
{
  {
    init_simple_test("BFu0i_B_S");
    static BFu0i_B_S lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_S)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_B_S)");
    check_field_offset(lv, v1, 0, "BFu0i_B_S.v1");
    check_field_offset(lv, v2, 2, "BFu0i_B_S.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_S(Test_BFu0i_B_S, "BFu0i_B_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_Uc  {
  unsigned int  :0;
  bool v1;
  unsigned char v2;
};
//SIG(1 BFu0i_B_Uc) C1{ Fi:0 Fc[2]}



static void Test_BFu0i_B_Uc()
{
  {
    init_simple_test("BFu0i_B_Uc");
    static BFu0i_B_Uc lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_B_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_B_Uc)");
    check_field_offset(lv, v1, 0, "BFu0i_B_Uc.v1");
    check_field_offset(lv, v2, 1, "BFu0i_B_Uc.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_Uc(Test_BFu0i_B_Uc, "BFu0i_B_Uc", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_Ui  {
  unsigned int  :0;
  bool v1;
  unsigned int v2;
};
//SIG(1 BFu0i_B_Ui) C1{ Fi:0 Fc Fi}



static void Test_BFu0i_B_Ui()
{
  {
    init_simple_test("BFu0i_B_Ui");
    static BFu0i_B_Ui lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_B_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_B_Ui)");
    check_field_offset(lv, v1, 0, "BFu0i_B_Ui.v1");
    check_field_offset(lv, v2, 4, "BFu0i_B_Ui.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_Ui(Test_BFu0i_B_Ui, "BFu0i_B_Ui", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_Ul  {
  unsigned int  :0;
  bool v1;
  __tsu64 v2;
};
//SIG(1 BFu0i_B_Ul) C1{ Fi:0 Fc FL}



static void Test_BFu0i_B_Ul()
{
  {
    init_simple_test("BFu0i_B_Ul");
    static BFu0i_B_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0i_B_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_Ul)");
    check_field_offset(lv, v1, 0, "BFu0i_B_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0i_B_Ul.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_Ul(Test_BFu0i_B_Ul, "BFu0i_B_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_Us  {
  unsigned int  :0;
  bool v1;
  unsigned short v2;
};
//SIG(1 BFu0i_B_Us) C1{ Fi:0 Fc Fs}



static void Test_BFu0i_B_Us()
{
  {
    init_simple_test("BFu0i_B_Us");
    static BFu0i_B_Us lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_B_Us)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_B_Us)");
    check_field_offset(lv, v1, 0, "BFu0i_B_Us.v1");
    check_field_offset(lv, v2, 2, "BFu0i_B_Us.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_Us(Test_BFu0i_B_Us, "BFu0i_B_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_Vp  {
  unsigned int  :0;
  bool v1;
  void *v2;
};
//SIG(1 BFu0i_B_Vp) C1{ Fi:0 Fc Fp}



static void Test_BFu0i_B_Vp()
{
  {
    init_simple_test("BFu0i_B_Vp");
    static BFu0i_B_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0i_B_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_B_Vp)");
    check_field_offset(lv, v1, 0, "BFu0i_B_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0i_B_Vp.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_Vp(Test_BFu0i_B_Vp, "BFu0i_B_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu0c_B  {
  unsigned int  :0;
  unsigned char  :0;
  bool v1;
};
//SIG(1 BFu0i_BFu0c_B) C1{ Fi:0 Fc:0 Fc}



static void Test_BFu0i_BFu0c_B()
{
  {
    init_simple_test("BFu0i_BFu0c_B");
    static BFu0i_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu0c_B)");
    check_field_offset(lv, v1, 0, "BFu0i_BFu0c_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu0c_B(Test_BFu0i_BFu0c_B, "BFu0i_BFu0c_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu0i_B  {
  unsigned int  :0;
  unsigned int  :0;
  bool v1;
};
//SIG(1 BFu0i_BFu0i_B) C1{ Fi:0 Fi:0 Fc}



static void Test_BFu0i_BFu0i_B()
{
  {
    init_simple_test("BFu0i_BFu0i_B");
    static BFu0i_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu0i_B)");
    check_field_offset(lv, v1, 0, "BFu0i_BFu0i_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu0i_B(Test_BFu0i_BFu0i_B, "BFu0i_BFu0i_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu0ll_B  {
  unsigned int  :0;
  __tsu64  :0;
  bool v1;
};
//SIG(1 BFu0i_BFu0ll_B) C1{ Fi:0 FL:0 Fc}



static void Test_BFu0i_BFu0ll_B()
{
  {
    init_simple_test("BFu0i_BFu0ll_B");
    static BFu0i_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "BFu0i_BFu0ll_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu0ll_B(Test_BFu0i_BFu0ll_B, "BFu0i_BFu0ll_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu0s_B  {
  unsigned int  :0;
  unsigned short  :0;
  bool v1;
};
//SIG(1 BFu0i_BFu0s_B) C1{ Fi:0 Fs:0 Fc}



static void Test_BFu0i_BFu0s_B()
{
  {
    init_simple_test("BFu0i_BFu0s_B");
    static BFu0i_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu0s_B)");
    check_field_offset(lv, v1, 0, "BFu0i_BFu0s_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu0s_B(Test_BFu0i_BFu0s_B, "BFu0i_BFu0s_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu15i_B  {
  unsigned int  :0;
  unsigned int v1:15;
  bool v2;
};
//SIG(1 BFu0i_BFu15i_B) C1{ Fi:0 Fi:15 Fc}



static void Test_BFu0i_BFu15i_B()
{
  {
    init_simple_test("BFu0i_BFu15i_B");
    static BFu0i_BFu15i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu15i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu15i_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0i_BFu15i_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0i_BFu15i_B");
    check_field_offset(lv, v2, 2, "BFu0i_BFu15i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu15i_B(Test_BFu0i_BFu15i_B, "BFu0i_BFu15i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu15ll_B  {
  unsigned int  :0;
  __tsu64 v1:15;
  bool v2;
};
//SIG(1 BFu0i_BFu15ll_B) C1{ Fi:0 FL:15 Fc}



static void Test_BFu0i_BFu15ll_B()
{
  {
    init_simple_test("BFu0i_BFu15ll_B");
    static BFu0i_BFu15ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu15ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu15ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0i_BFu15ll_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0i_BFu15ll_B");
    check_field_offset(lv, v2, 2, "BFu0i_BFu15ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu15ll_B(Test_BFu0i_BFu15ll_B, "BFu0i_BFu15ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu15s_B  {
  unsigned int  :0;
  unsigned short v1:15;
  bool v2;
};
//SIG(1 BFu0i_BFu15s_B) C1{ Fi:0 Fs:15 Fc}



static void Test_BFu0i_BFu15s_B()
{
  {
    init_simple_test("BFu0i_BFu15s_B");
    static BFu0i_BFu15s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu15s_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_BFu15s_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0i_BFu15s_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0i_BFu15s_B");
    check_field_offset(lv, v2, 2, "BFu0i_BFu15s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu15s_B(Test_BFu0i_BFu15s_B, "BFu0i_BFu15s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu16i_B  {
  unsigned int  :0;
  unsigned int v1:16;
  bool v2;
};
//SIG(1 BFu0i_BFu16i_B) C1{ Fi:0 Fi:16 Fc}



static void Test_BFu0i_BFu16i_B()
{
  {
    init_simple_test("BFu0i_BFu16i_B");
    static BFu0i_BFu16i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu16i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu16i_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0i_BFu16i_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0i_BFu16i_B");
    check_field_offset(lv, v2, 2, "BFu0i_BFu16i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu16i_B(Test_BFu0i_BFu16i_B, "BFu0i_BFu16i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu16ll_B  {
  unsigned int  :0;
  __tsu64 v1:16;
  bool v2;
};
//SIG(1 BFu0i_BFu16ll_B) C1{ Fi:0 FL:16 Fc}



static void Test_BFu0i_BFu16ll_B()
{
  {
    init_simple_test("BFu0i_BFu16ll_B");
    static BFu0i_BFu16ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu16ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu16ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0i_BFu16ll_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0i_BFu16ll_B");
    check_field_offset(lv, v2, 2, "BFu0i_BFu16ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu16ll_B(Test_BFu0i_BFu16ll_B, "BFu0i_BFu16ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu16s_B  {
  unsigned int  :0;
  unsigned short v1:16;
  bool v2;
};
//SIG(1 BFu0i_BFu16s_B) C1{ Fi:0 Fs:16 Fc}



static void Test_BFu0i_BFu16s_B()
{
  {
    init_simple_test("BFu0i_BFu16s_B");
    static BFu0i_BFu16s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu16s_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_BFu16s_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0i_BFu16s_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0i_BFu16s_B");
    check_field_offset(lv, v2, 2, "BFu0i_BFu16s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu16s_B(Test_BFu0i_BFu16s_B, "BFu0i_BFu16s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu17i_B  {
  unsigned int  :0;
  unsigned int v1:17;
  bool v2;
};
//SIG(1 BFu0i_BFu17i_B) C1{ Fi:0 Fi:17 Fc}



static void Test_BFu0i_BFu17i_B()
{
  {
    init_simple_test("BFu0i_BFu17i_B");
    static BFu0i_BFu17i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu17i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu17i_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0i_BFu17i_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0i_BFu17i_B");
    check_field_offset(lv, v2, 3, "BFu0i_BFu17i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu17i_B(Test_BFu0i_BFu17i_B, "BFu0i_BFu17i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu17ll_B  {
  unsigned int  :0;
  __tsu64 v1:17;
  bool v2;
};
//SIG(1 BFu0i_BFu17ll_B) C1{ Fi:0 FL:17 Fc}



static void Test_BFu0i_BFu17ll_B()
{
  {
    init_simple_test("BFu0i_BFu17ll_B");
    static BFu0i_BFu17ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu17ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu17ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0i_BFu17ll_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0i_BFu17ll_B");
    check_field_offset(lv, v2, 3, "BFu0i_BFu17ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu17ll_B(Test_BFu0i_BFu17ll_B, "BFu0i_BFu17ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu1c_B  {
  unsigned int  :0;
  unsigned char v1:1;
  bool v2;
};
//SIG(1 BFu0i_BFu1c_B) C1{ Fi:0 Fc:1 Fc}



static void Test_BFu0i_BFu1c_B()
{
  {
    init_simple_test("BFu0i_BFu1c_B");
    static BFu0i_BFu1c_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_BFu1c_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu1c_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0i_BFu1c_B");
    check_field_offset(lv, v2, 1, "BFu0i_BFu1c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu1c_B(Test_BFu0i_BFu1c_B, "BFu0i_BFu1c_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu1i_B  {
  unsigned int  :0;
  unsigned int v1:1;
  bool v2;
};
//SIG(1 BFu0i_BFu1i_B) C1{ Fi:0 Fi:1 Fc}



static void Test_BFu0i_BFu1i_B()
{
  {
    init_simple_test("BFu0i_BFu1i_B");
    static BFu0i_BFu1i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu1i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu1i_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0i_BFu1i_B");
    check_field_offset(lv, v2, 1, "BFu0i_BFu1i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu1i_B(Test_BFu0i_BFu1i_B, "BFu0i_BFu1i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu1ll_B  {
  unsigned int  :0;
  __tsu64 v1:1;
  bool v2;
};
//SIG(1 BFu0i_BFu1ll_B) C1{ Fi:0 FL:1 Fc}



static void Test_BFu0i_BFu1ll_B()
{
  {
    init_simple_test("BFu0i_BFu1ll_B");
    static BFu0i_BFu1ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu1ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu1ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0i_BFu1ll_B");
    check_field_offset(lv, v2, 1, "BFu0i_BFu1ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu1ll_B(Test_BFu0i_BFu1ll_B, "BFu0i_BFu1ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu1s_B  {
  unsigned int  :0;
  unsigned short v1:1;
  bool v2;
};
//SIG(1 BFu0i_BFu1s_B) C1{ Fi:0 Fs:1 Fc}



static void Test_BFu0i_BFu1s_B()
{
  {
    init_simple_test("BFu0i_BFu1s_B");
    static BFu0i_BFu1s_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_BFu1s_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_BFu1s_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0i_BFu1s_B");
    check_field_offset(lv, v2, 1, "BFu0i_BFu1s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu1s_B(Test_BFu0i_BFu1s_B, "BFu0i_BFu1s_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu31i_B  {
  unsigned int  :0;
  unsigned int v1:31;
  bool v2;
};
//SIG(1 BFu0i_BFu31i_B) C1{ Fi:0 Fi:31 Fc}



static void Test_BFu0i_BFu31i_B()
{
  {
    init_simple_test("BFu0i_BFu31i_B");
    static BFu0i_BFu31i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_BFu31i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu31i_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0i_BFu31i_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0i_BFu31i_B");
    check_field_offset(lv, v2, 4, "BFu0i_BFu31i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu31i_B(Test_BFu0i_BFu31i_B, "BFu0i_BFu31i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu31ll_B  {
  unsigned int  :0;
  __tsu64 v1:31;
  bool v2;
};
//SIG(1 BFu0i_BFu31ll_B) C1{ Fi:0 FL:31 Fc}



static void Test_BFu0i_BFu31ll_B()
{
  {
    init_simple_test("BFu0i_BFu31ll_B");
    static BFu0i_BFu31ll_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_BFu31ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu31ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0i_BFu31ll_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0i_BFu31ll_B");
    check_field_offset(lv, v2, 4, "BFu0i_BFu31ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu31ll_B(Test_BFu0i_BFu31ll_B, "BFu0i_BFu31ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu32i_B  {
  unsigned int  :0;
  unsigned int v1:32;
  bool v2;
};
//SIG(1 BFu0i_BFu32i_B) C1{ Fi:0 Fi:32 Fc}



static void Test_BFu0i_BFu32i_B()
{
  {
    init_simple_test("BFu0i_BFu32i_B");
    static BFu0i_BFu32i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_BFu32i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu32i_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0i_BFu32i_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0i_BFu32i_B");
    check_field_offset(lv, v2, 4, "BFu0i_BFu32i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu32i_B(Test_BFu0i_BFu32i_B, "BFu0i_BFu32i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu32ll_B  {
  unsigned int  :0;
  __tsu64 v1:32;
  bool v2;
};
//SIG(1 BFu0i_BFu32ll_B) C1{ Fi:0 FL:32 Fc}



static void Test_BFu0i_BFu32ll_B()
{
  {
    init_simple_test("BFu0i_BFu32ll_B");
    static BFu0i_BFu32ll_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_BFu32ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu32ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0i_BFu32ll_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0i_BFu32ll_B");
    check_field_offset(lv, v2, 4, "BFu0i_BFu32ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu32ll_B(Test_BFu0i_BFu32ll_B, "BFu0i_BFu32ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu33_B  {
  unsigned int  :0;
  __tsu64 v1:33;
  bool v2;
};
//SIG(1 BFu0i_BFu33_B) C1{ Fi:0 FL:33 Fc}



static void Test_BFu0i_BFu33_B()
{
  {
    init_simple_test("BFu0i_BFu33_B");
    static BFu0i_BFu33_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_BFu33_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu33_B)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu0i_BFu33_B");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu0i_BFu33_B");
    check_field_offset(lv, v2, 5, "BFu0i_BFu33_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu33_B(Test_BFu0i_BFu33_B, "BFu0i_BFu33_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu7c_B  {
  unsigned int  :0;
  unsigned char v1:7;
  bool v2;
};
//SIG(1 BFu0i_BFu7c_B) C1{ Fi:0 Fc:7 Fc}



static void Test_BFu0i_BFu7c_B()
{
  {
    init_simple_test("BFu0i_BFu7c_B");
    static BFu0i_BFu7c_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_BFu7c_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu7c_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0i_BFu7c_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0i_BFu7c_B");
    check_field_offset(lv, v2, 1, "BFu0i_BFu7c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu7c_B(Test_BFu0i_BFu7c_B, "BFu0i_BFu7c_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu7i_B  {
  unsigned int  :0;
  unsigned int v1:7;
  bool v2;
};
//SIG(1 BFu0i_BFu7i_B) C1{ Fi:0 Fi:7 Fc}



static void Test_BFu0i_BFu7i_B()
{
  {
    init_simple_test("BFu0i_BFu7i_B");
    static BFu0i_BFu7i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu7i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu7i_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0i_BFu7i_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0i_BFu7i_B");
    check_field_offset(lv, v2, 1, "BFu0i_BFu7i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu7i_B(Test_BFu0i_BFu7i_B, "BFu0i_BFu7i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu7ll_B  {
  unsigned int  :0;
  __tsu64 v1:7;
  bool v2;
};
//SIG(1 BFu0i_BFu7ll_B) C1{ Fi:0 FL:7 Fc}



static void Test_BFu0i_BFu7ll_B()
{
  {
    init_simple_test("BFu0i_BFu7ll_B");
    static BFu0i_BFu7ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu7ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu7ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0i_BFu7ll_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0i_BFu7ll_B");
    check_field_offset(lv, v2, 1, "BFu0i_BFu7ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu7ll_B(Test_BFu0i_BFu7ll_B, "BFu0i_BFu7ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu7s_B  {
  unsigned int  :0;
  unsigned short v1:7;
  bool v2;
};
//SIG(1 BFu0i_BFu7s_B) C1{ Fi:0 Fs:7 Fc}



static void Test_BFu0i_BFu7s_B()
{
  {
    init_simple_test("BFu0i_BFu7s_B");
    static BFu0i_BFu7s_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_BFu7s_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_BFu7s_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0i_BFu7s_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0i_BFu7s_B");
    check_field_offset(lv, v2, 1, "BFu0i_BFu7s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu7s_B(Test_BFu0i_BFu7s_B, "BFu0i_BFu7s_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu8c_B  {
  unsigned int  :0;
  unsigned char v1:8;
  bool v2;
};
//SIG(1 BFu0i_BFu8c_B) C1{ Fi:0 Fc:8 Fc}



static void Test_BFu0i_BFu8c_B()
{
  {
    init_simple_test("BFu0i_BFu8c_B");
    static BFu0i_BFu8c_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_BFu8c_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu8c_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0i_BFu8c_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0i_BFu8c_B");
    check_field_offset(lv, v2, 1, "BFu0i_BFu8c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu8c_B(Test_BFu0i_BFu8c_B, "BFu0i_BFu8c_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu8i_B  {
  unsigned int  :0;
  unsigned int v1:8;
  bool v2;
};
//SIG(1 BFu0i_BFu8i_B) C1{ Fi:0 Fi:8 Fc}



static void Test_BFu0i_BFu8i_B()
{
  {
    init_simple_test("BFu0i_BFu8i_B");
    static BFu0i_BFu8i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu8i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu8i_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0i_BFu8i_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0i_BFu8i_B");
    check_field_offset(lv, v2, 1, "BFu0i_BFu8i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu8i_B(Test_BFu0i_BFu8i_B, "BFu0i_BFu8i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu8ll_B  {
  unsigned int  :0;
  __tsu64 v1:8;
  bool v2;
};
//SIG(1 BFu0i_BFu8ll_B) C1{ Fi:0 FL:8 Fc}



static void Test_BFu0i_BFu8ll_B()
{
  {
    init_simple_test("BFu0i_BFu8ll_B");
    static BFu0i_BFu8ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu8ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu8ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0i_BFu8ll_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0i_BFu8ll_B");
    check_field_offset(lv, v2, 1, "BFu0i_BFu8ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu8ll_B(Test_BFu0i_BFu8ll_B, "BFu0i_BFu8ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu8s_B  {
  unsigned int  :0;
  unsigned short v1:8;
  bool v2;
};
//SIG(1 BFu0i_BFu8s_B) C1{ Fi:0 Fs:8 Fc}



static void Test_BFu0i_BFu8s_B()
{
  {
    init_simple_test("BFu0i_BFu8s_B");
    static BFu0i_BFu8s_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_BFu8s_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_BFu8s_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0i_BFu8s_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0i_BFu8s_B");
    check_field_offset(lv, v2, 1, "BFu0i_BFu8s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu8s_B(Test_BFu0i_BFu8s_B, "BFu0i_BFu8s_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu9i_B  {
  unsigned int  :0;
  unsigned int v1:9;
  bool v2;
};
//SIG(1 BFu0i_BFu9i_B) C1{ Fi:0 Fi:9 Fc}



static void Test_BFu0i_BFu9i_B()
{
  {
    init_simple_test("BFu0i_BFu9i_B");
    static BFu0i_BFu9i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu9i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu9i_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0i_BFu9i_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0i_BFu9i_B");
    check_field_offset(lv, v2, 2, "BFu0i_BFu9i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu9i_B(Test_BFu0i_BFu9i_B, "BFu0i_BFu9i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu9ll_B  {
  unsigned int  :0;
  __tsu64 v1:9;
  bool v2;
};
//SIG(1 BFu0i_BFu9ll_B) C1{ Fi:0 FL:9 Fc}



static void Test_BFu0i_BFu9ll_B()
{
  {
    init_simple_test("BFu0i_BFu9ll_B");
    static BFu0i_BFu9ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu9ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu9ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0i_BFu9ll_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0i_BFu9ll_B");
    check_field_offset(lv, v2, 2, "BFu0i_BFu9ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu9ll_B(Test_BFu0i_BFu9ll_B, "BFu0i_BFu9ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_BFu9s_B  {
  unsigned int  :0;
  unsigned short v1:9;
  bool v2;
};
//SIG(1 BFu0i_BFu9s_B) C1{ Fi:0 Fs:9 Fc}



static void Test_BFu0i_BFu9s_B()
{
  {
    init_simple_test("BFu0i_BFu9s_B");
    static BFu0i_BFu9s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu9s_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_BFu9s_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0i_BFu9s_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0i_BFu9s_B");
    check_field_offset(lv, v2, 2, "BFu0i_BFu9s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_BFu9s_B(Test_BFu0i_BFu9s_B, "BFu0i_BFu9s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_C_B  {
  unsigned int  :0;
  char v1;
  bool v2;
};
//SIG(1 BFu0i_C_B) C1{ Fi:0 Fc[2]}



static void Test_BFu0i_C_B()
{
  {
    init_simple_test("BFu0i_C_B");
    static BFu0i_C_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_C_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_C_B)");
    check_field_offset(lv, v1, 0, "BFu0i_C_B.v1");
    check_field_offset(lv, v2, 1, "BFu0i_C_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_C_B(Test_BFu0i_C_B, "BFu0i_C_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_D_B  {
  unsigned int  :0;
  double v1;
  bool v2;
};
//SIG(1 BFu0i_D_B) C1{ Fi:0 FL Fc}



static void Test_BFu0i_D_B()
{
  {
    init_simple_test("BFu0i_D_B");
    static BFu0i_D_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0i_D_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_D_B)");
    check_field_offset(lv, v1, 0, "BFu0i_D_B.v1");
    check_field_offset(lv, v2, 8, "BFu0i_D_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_D_B(Test_BFu0i_D_B, "BFu0i_D_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_F_B  {
  unsigned int  :0;
  float v1;
  bool v2;
};
//SIG(1 BFu0i_F_B) C1{ Fi:0 Fi Fc}



static void Test_BFu0i_F_B()
{
  {
    init_simple_test("BFu0i_F_B");
    static BFu0i_F_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_F_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_F_B)");
    check_field_offset(lv, v1, 0, "BFu0i_F_B.v1");
    check_field_offset(lv, v2, 4, "BFu0i_F_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_F_B(Test_BFu0i_F_B, "BFu0i_F_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_I_B  {
  unsigned int  :0;
  int v1;
  bool v2;
};
//SIG(1 BFu0i_I_B) C1{ Fi:0 Fi Fc}



static void Test_BFu0i_I_B()
{
  {
    init_simple_test("BFu0i_I_B");
    static BFu0i_I_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_I_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_I_B)");
    check_field_offset(lv, v1, 0, "BFu0i_I_B.v1");
    check_field_offset(lv, v2, 4, "BFu0i_I_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_I_B(Test_BFu0i_I_B, "BFu0i_I_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_Ip_B  {
  unsigned int  :0;
  int *v1;
  bool v2;
};
//SIG(1 BFu0i_Ip_B) C1{ Fi:0 Fp Fc}



static void Test_BFu0i_Ip_B()
{
  {
    init_simple_test("BFu0i_Ip_B");
    static BFu0i_Ip_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0i_Ip_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Ip_B)");
    check_field_offset(lv, v1, 0, "BFu0i_Ip_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0i_Ip_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_Ip_B(Test_BFu0i_Ip_B, "BFu0i_Ip_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_L_B  {
  unsigned int  :0;
  __tsi64 v1;
  bool v2;
};
//SIG(1 BFu0i_L_B) C1{ Fi:0 FL Fc}



static void Test_BFu0i_L_B()
{
  {
    init_simple_test("BFu0i_L_B");
    static BFu0i_L_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0i_L_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_L_B)");
    check_field_offset(lv, v1, 0, "BFu0i_L_B.v1");
    check_field_offset(lv, v2, 8, "BFu0i_L_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_L_B(Test_BFu0i_L_B, "BFu0i_L_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_S_B  {
  unsigned int  :0;
  short v1;
  bool v2;
};
//SIG(1 BFu0i_S_B) C1{ Fi:0 Fs Fc}



static void Test_BFu0i_S_B()
{
  {
    init_simple_test("BFu0i_S_B");
    static BFu0i_S_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_S_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_S_B)");
    check_field_offset(lv, v1, 0, "BFu0i_S_B.v1");
    check_field_offset(lv, v2, 2, "BFu0i_S_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_S_B(Test_BFu0i_S_B, "BFu0i_S_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_Uc_B  {
  unsigned int  :0;
  unsigned char v1;
  bool v2;
};
//SIG(1 BFu0i_Uc_B) C1{ Fi:0 Fc[2]}



static void Test_BFu0i_Uc_B()
{
  {
    init_simple_test("BFu0i_Uc_B");
    static BFu0i_Uc_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_Uc_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Uc_B)");
    check_field_offset(lv, v1, 0, "BFu0i_Uc_B.v1");
    check_field_offset(lv, v2, 1, "BFu0i_Uc_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_Uc_B(Test_BFu0i_Uc_B, "BFu0i_Uc_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_Ui_B  {
  unsigned int  :0;
  unsigned int v1;
  bool v2;
};
//SIG(1 BFu0i_Ui_B) C1{ Fi:0 Fi Fc}



static void Test_BFu0i_Ui_B()
{
  {
    init_simple_test("BFu0i_Ui_B");
    static BFu0i_Ui_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_Ui_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Ui_B)");
    check_field_offset(lv, v1, 0, "BFu0i_Ui_B.v1");
    check_field_offset(lv, v2, 4, "BFu0i_Ui_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_Ui_B(Test_BFu0i_Ui_B, "BFu0i_Ui_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_Ul_B  {
  unsigned int  :0;
  __tsu64 v1;
  bool v2;
};
//SIG(1 BFu0i_Ul_B) C1{ Fi:0 FL Fc}



static void Test_BFu0i_Ul_B()
{
  {
    init_simple_test("BFu0i_Ul_B");
    static BFu0i_Ul_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0i_Ul_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Ul_B)");
    check_field_offset(lv, v1, 0, "BFu0i_Ul_B.v1");
    check_field_offset(lv, v2, 8, "BFu0i_Ul_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_Ul_B(Test_BFu0i_Ul_B, "BFu0i_Ul_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_Us_B  {
  unsigned int  :0;
  unsigned short v1;
  bool v2;
};
//SIG(1 BFu0i_Us_B) C1{ Fi:0 Fs Fc}



static void Test_BFu0i_Us_B()
{
  {
    init_simple_test("BFu0i_Us_B");
    static BFu0i_Us_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Us_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_Us_B)");
    check_field_offset(lv, v1, 0, "BFu0i_Us_B.v1");
    check_field_offset(lv, v2, 2, "BFu0i_Us_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_Us_B(Test_BFu0i_Us_B, "BFu0i_Us_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_Vp_B  {
  unsigned int  :0;
  void *v1;
  bool v2;
};
//SIG(1 BFu0i_Vp_B) C1{ Fi:0 Fp Fc}



static void Test_BFu0i_Vp_B()
{
  {
    init_simple_test("BFu0i_Vp_B");
    static BFu0i_Vp_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0i_Vp_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Vp_B)");
    check_field_offset(lv, v1, 0, "BFu0i_Vp_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0i_Vp_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_Vp_B(Test_BFu0i_Vp_B, "BFu0i_Vp_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B  {
  __tsu64  :0;
  bool v1;
};
//SIG(1 BFu0ll_B) C1{ FL:0 Fc}



static void Test_BFu0ll_B()
{
  {
    init_simple_test("BFu0ll_B");
    static BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0ll_B(Test_BFu0ll_B, "BFu0ll_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_B  {
  __tsu64  :0;
  bool v1;
  bool v2;
};
//SIG(1 BFu0ll_B_B) C1{ FL:0 Fc[2]}



static void Test_BFu0ll_B_B()
{
  {
    init_simple_test("BFu0ll_B_B");
    static BFu0ll_B_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_B_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_B_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_B.v1");
    check_field_offset(lv, v2, 1, "BFu0ll_B_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_B(Test_BFu0ll_B_B, "BFu0ll_B_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu0c  {
  __tsu64  :0;
  bool v1;
  unsigned char  :0;
};
//SIG(1 BFu0ll_B_BFu0c) C1{ FL:0 Fc Fc:0}



static void Test_BFu0ll_B_BFu0c()
{
  {
    init_simple_test("BFu0ll_B_BFu0c");
    static BFu0ll_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_B_BFu0c)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu0c(Test_BFu0ll_B_BFu0c, "BFu0ll_B_BFu0c", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu0i  {
  __tsu64  :0;
  bool v1;
  unsigned int  :0;
};
//SIG(1 BFu0ll_B_BFu0i) C1{ FL:0 Fc Fi:0}



static void Test_BFu0ll_B_BFu0i()
{
  {
    init_simple_test("BFu0ll_B_BFu0i");
    static BFu0ll_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_B_BFu0i)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu0i(Test_BFu0ll_B_BFu0i, "BFu0ll_B_BFu0i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu0ll  {
  __tsu64  :0;
  bool v1;
  __tsu64  :0;
};
//SIG(1 BFu0ll_B_BFu0ll) C1{ FL:0 Fc FL:0}



static void Test_BFu0ll_B_BFu0ll()
{
  {
    init_simple_test("BFu0ll_B_BFu0ll");
    static BFu0ll_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu0ll(Test_BFu0ll_B_BFu0ll, "BFu0ll_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu0s  {
  __tsu64  :0;
  bool v1;
  unsigned short  :0;
};
//SIG(1 BFu0ll_B_BFu0s) C1{ FL:0 Fc Fs:0}



static void Test_BFu0ll_B_BFu0s()
{
  {
    init_simple_test("BFu0ll_B_BFu0s");
    static BFu0ll_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_B_BFu0s)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu0s(Test_BFu0ll_B_BFu0s, "BFu0ll_B_BFu0s", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu15i  {
  __tsu64  :0;
  bool v1;
  unsigned int v2:15;
};
//SIG(1 BFu0ll_B_BFu15i) C1{ FL:0 Fc Fi:15}



static void Test_BFu0ll_B_BFu15i()
{
  {
    init_simple_test("BFu0ll_B_BFu15i");
    static BFu0ll_B_BFu15i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_BFu15i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_B_BFu15i)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu15i.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "BFu0ll_B_BFu15i");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "BFu0ll_B_BFu15i");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu15i(Test_BFu0ll_B_BFu15i, "BFu0ll_B_BFu15i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu15ll  {
  __tsu64  :0;
  bool v1;
  __tsu64 v2:15;
};
//SIG(1 BFu0ll_B_BFu15ll) C1{ FL:0 Fc FL:15}



static void Test_BFu0ll_B_BFu15ll()
{
  {
    init_simple_test("BFu0ll_B_BFu15ll");
    static BFu0ll_B_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_B_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu15ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "BFu0ll_B_BFu15ll");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "BFu0ll_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu15ll(Test_BFu0ll_B_BFu15ll, "BFu0ll_B_BFu15ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu15s  {
  __tsu64  :0;
  bool v1;
  unsigned short v2:15;
};
//SIG(1 BFu0ll_B_BFu15s) C1{ FL:0 Fc Fs:15}



static void Test_BFu0ll_B_BFu15s()
{
  {
    init_simple_test("BFu0ll_B_BFu15s");
    static BFu0ll_B_BFu15s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_BFu15s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_B_BFu15s)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu15s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "BFu0ll_B_BFu15s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "BFu0ll_B_BFu15s");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu15s(Test_BFu0ll_B_BFu15s, "BFu0ll_B_BFu15s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu16i  {
  __tsu64  :0;
  bool v1;
  unsigned int v2:16;
};
//SIG(1 BFu0ll_B_BFu16i) C1{ FL:0 Fc Fi:16}



static void Test_BFu0ll_B_BFu16i()
{
  {
    init_simple_test("BFu0ll_B_BFu16i");
    static BFu0ll_B_BFu16i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_BFu16i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_B_BFu16i)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu16i.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "BFu0ll_B_BFu16i");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "BFu0ll_B_BFu16i");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu16i(Test_BFu0ll_B_BFu16i, "BFu0ll_B_BFu16i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu16ll  {
  __tsu64  :0;
  bool v1;
  __tsu64 v2:16;
};
//SIG(1 BFu0ll_B_BFu16ll) C1{ FL:0 Fc FL:16}



static void Test_BFu0ll_B_BFu16ll()
{
  {
    init_simple_test("BFu0ll_B_BFu16ll");
    static BFu0ll_B_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_B_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu16ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "BFu0ll_B_BFu16ll");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "BFu0ll_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu16ll(Test_BFu0ll_B_BFu16ll, "BFu0ll_B_BFu16ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu16s  {
  __tsu64  :0;
  bool v1;
  unsigned short v2:16;
};
//SIG(1 BFu0ll_B_BFu16s) C1{ FL:0 Fc Fs:16}



static void Test_BFu0ll_B_BFu16s()
{
  {
    init_simple_test("BFu0ll_B_BFu16s");
    static BFu0ll_B_BFu16s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_BFu16s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_B_BFu16s)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu16s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "BFu0ll_B_BFu16s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "BFu0ll_B_BFu16s");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu16s(Test_BFu0ll_B_BFu16s, "BFu0ll_B_BFu16s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu17i  {
  __tsu64  :0;
  bool v1;
  unsigned int v2:17;
};
//SIG(1 BFu0ll_B_BFu17i) C1{ FL:0 Fc Fi:17}



static void Test_BFu0ll_B_BFu17i()
{
  {
    init_simple_test("BFu0ll_B_BFu17i");
    static BFu0ll_B_BFu17i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_BFu17i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_B_BFu17i)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu17i.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "BFu0ll_B_BFu17i");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "BFu0ll_B_BFu17i");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu17i(Test_BFu0ll_B_BFu17i, "BFu0ll_B_BFu17i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu17ll  {
  __tsu64  :0;
  bool v1;
  __tsu64 v2:17;
};
//SIG(1 BFu0ll_B_BFu17ll) C1{ FL:0 Fc FL:17}



static void Test_BFu0ll_B_BFu17ll()
{
  {
    init_simple_test("BFu0ll_B_BFu17ll");
    static BFu0ll_B_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_B_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu17ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "BFu0ll_B_BFu17ll");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "BFu0ll_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu17ll(Test_BFu0ll_B_BFu17ll, "BFu0ll_B_BFu17ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu1c  {
  __tsu64  :0;
  bool v1;
  unsigned char v2:1;
};
//SIG(1 BFu0ll_B_BFu1c) C1{ FL:0 Fc Fc:1}



static void Test_BFu0ll_B_BFu1c()
{
  {
    init_simple_test("BFu0ll_B_BFu1c");
    static BFu0ll_B_BFu1c lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_B_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_B_BFu1c)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu1c.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0ll_B_BFu1c");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu1c(Test_BFu0ll_B_BFu1c, "BFu0ll_B_BFu1c", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu1i  {
  __tsu64  :0;
  bool v1;
  unsigned int v2:1;
};
//SIG(1 BFu0ll_B_BFu1i) C1{ FL:0 Fc Fi:1}



static void Test_BFu0ll_B_BFu1i()
{
  {
    init_simple_test("BFu0ll_B_BFu1i");
    static BFu0ll_B_BFu1i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_BFu1i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_B_BFu1i)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu1i.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0ll_B_BFu1i");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu1i(Test_BFu0ll_B_BFu1i, "BFu0ll_B_BFu1i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu1ll  {
  __tsu64  :0;
  bool v1;
  __tsu64 v2:1;
};
//SIG(1 BFu0ll_B_BFu1ll) C1{ FL:0 Fc FL:1}



static void Test_BFu0ll_B_BFu1ll()
{
  {
    init_simple_test("BFu0ll_B_BFu1ll");
    static BFu0ll_B_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_B_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu1ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0ll_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu1ll(Test_BFu0ll_B_BFu1ll, "BFu0ll_B_BFu1ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu1s  {
  __tsu64  :0;
  bool v1;
  unsigned short v2:1;
};
//SIG(1 BFu0ll_B_BFu1s) C1{ FL:0 Fc Fs:1}



static void Test_BFu0ll_B_BFu1s()
{
  {
    init_simple_test("BFu0ll_B_BFu1s");
    static BFu0ll_B_BFu1s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_B_BFu1s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_B_BFu1s)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu1s.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0ll_B_BFu1s");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu1s(Test_BFu0ll_B_BFu1s, "BFu0ll_B_BFu1s", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu31i  {
  __tsu64  :0;
  bool v1;
  unsigned int v2:31;
};
//SIG(1 BFu0ll_B_BFu31i) C1{ FL:0 Fc Fi:31}



static void Test_BFu0ll_B_BFu31i()
{
  {
    init_simple_test("BFu0ll_B_BFu31i");
    static BFu0ll_B_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_B_BFu31i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_B_BFu31i)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu31i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "BFu0ll_B_BFu31i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "BFu0ll_B_BFu31i");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu31i(Test_BFu0ll_B_BFu31i, "BFu0ll_B_BFu31i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu31ll  {
  __tsu64  :0;
  bool v1;
  __tsu64 v2:31;
};
//SIG(1 BFu0ll_B_BFu31ll) C1{ FL:0 Fc FL:31}



static void Test_BFu0ll_B_BFu31ll()
{
  {
    init_simple_test("BFu0ll_B_BFu31ll");
    static BFu0ll_B_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_B_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu31ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "BFu0ll_B_BFu31ll");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "BFu0ll_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu31ll(Test_BFu0ll_B_BFu31ll, "BFu0ll_B_BFu31ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu32i  {
  __tsu64  :0;
  bool v1;
  unsigned int v2:32;
};
//SIG(1 BFu0ll_B_BFu32i) C1{ FL:0 Fc Fi:32}



static void Test_BFu0ll_B_BFu32i()
{
  {
    init_simple_test("BFu0ll_B_BFu32i");
    static BFu0ll_B_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_B_BFu32i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_B_BFu32i)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu32i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "BFu0ll_B_BFu32i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "BFu0ll_B_BFu32i");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu32i(Test_BFu0ll_B_BFu32i, "BFu0ll_B_BFu32i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu32ll  {
  __tsu64  :0;
  bool v1;
  __tsu64 v2:32;
};
//SIG(1 BFu0ll_B_BFu32ll) C1{ FL:0 Fc FL:32}



static void Test_BFu0ll_B_BFu32ll()
{
  {
    init_simple_test("BFu0ll_B_BFu32ll");
    static BFu0ll_B_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_B_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu32ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "BFu0ll_B_BFu32ll");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "BFu0ll_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu32ll(Test_BFu0ll_B_BFu32ll, "BFu0ll_B_BFu32ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu33  {
  __tsu64  :0;
  bool v1;
  __tsu64 v2:33;
};
//SIG(1 BFu0ll_B_BFu33) C1{ FL:0 Fc FL:33}



static void Test_BFu0ll_B_BFu33()
{
  {
    init_simple_test("BFu0ll_B_BFu33");
    static BFu0ll_B_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_B_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_BFu33)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu33.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "BFu0ll_B_BFu33");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "BFu0ll_B_BFu33");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu33(Test_BFu0ll_B_BFu33, "BFu0ll_B_BFu33", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu7c  {
  __tsu64  :0;
  bool v1;
  unsigned char v2:7;
};
//SIG(1 BFu0ll_B_BFu7c) C1{ FL:0 Fc Fc:7}



static void Test_BFu0ll_B_BFu7c()
{
  {
    init_simple_test("BFu0ll_B_BFu7c");
    static BFu0ll_B_BFu7c lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_B_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_B_BFu7c)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu7c.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0ll_B_BFu7c");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0ll_B_BFu7c");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu7c(Test_BFu0ll_B_BFu7c, "BFu0ll_B_BFu7c", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu7i  {
  __tsu64  :0;
  bool v1;
  unsigned int v2:7;
};
//SIG(1 BFu0ll_B_BFu7i) C1{ FL:0 Fc Fi:7}



static void Test_BFu0ll_B_BFu7i()
{
  {
    init_simple_test("BFu0ll_B_BFu7i");
    static BFu0ll_B_BFu7i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_BFu7i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_B_BFu7i)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu7i.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0ll_B_BFu7i");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0ll_B_BFu7i");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu7i(Test_BFu0ll_B_BFu7i, "BFu0ll_B_BFu7i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu7ll  {
  __tsu64  :0;
  bool v1;
  __tsu64 v2:7;
};
//SIG(1 BFu0ll_B_BFu7ll) C1{ FL:0 Fc FL:7}



static void Test_BFu0ll_B_BFu7ll()
{
  {
    init_simple_test("BFu0ll_B_BFu7ll");
    static BFu0ll_B_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_B_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu7ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0ll_B_BFu7ll");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0ll_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu7ll(Test_BFu0ll_B_BFu7ll, "BFu0ll_B_BFu7ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu7s  {
  __tsu64  :0;
  bool v1;
  unsigned short v2:7;
};
//SIG(1 BFu0ll_B_BFu7s) C1{ FL:0 Fc Fs:7}



static void Test_BFu0ll_B_BFu7s()
{
  {
    init_simple_test("BFu0ll_B_BFu7s");
    static BFu0ll_B_BFu7s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_B_BFu7s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_B_BFu7s)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu7s.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0ll_B_BFu7s");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0ll_B_BFu7s");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu7s(Test_BFu0ll_B_BFu7s, "BFu0ll_B_BFu7s", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu8c  {
  __tsu64  :0;
  bool v1;
  unsigned char v2:8;
};
//SIG(1 BFu0ll_B_BFu8c) C1{ FL:0 Fc Fc:8}



static void Test_BFu0ll_B_BFu8c()
{
  {
    init_simple_test("BFu0ll_B_BFu8c");
    static BFu0ll_B_BFu8c lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_B_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_B_BFu8c)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu8c.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0ll_B_BFu8c");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0ll_B_BFu8c");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu8c(Test_BFu0ll_B_BFu8c, "BFu0ll_B_BFu8c", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu8i  {
  __tsu64  :0;
  bool v1;
  unsigned int v2:8;
};
//SIG(1 BFu0ll_B_BFu8i) C1{ FL:0 Fc Fi:8}



static void Test_BFu0ll_B_BFu8i()
{
  {
    init_simple_test("BFu0ll_B_BFu8i");
    static BFu0ll_B_BFu8i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_BFu8i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_B_BFu8i)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu8i.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0ll_B_BFu8i");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0ll_B_BFu8i");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu8i(Test_BFu0ll_B_BFu8i, "BFu0ll_B_BFu8i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu8ll  {
  __tsu64  :0;
  bool v1;
  __tsu64 v2:8;
};
//SIG(1 BFu0ll_B_BFu8ll) C1{ FL:0 Fc FL:8}



static void Test_BFu0ll_B_BFu8ll()
{
  {
    init_simple_test("BFu0ll_B_BFu8ll");
    static BFu0ll_B_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_B_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu8ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0ll_B_BFu8ll");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0ll_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu8ll(Test_BFu0ll_B_BFu8ll, "BFu0ll_B_BFu8ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu8s  {
  __tsu64  :0;
  bool v1;
  unsigned short v2:8;
};
//SIG(1 BFu0ll_B_BFu8s) C1{ FL:0 Fc Fs:8}



static void Test_BFu0ll_B_BFu8s()
{
  {
    init_simple_test("BFu0ll_B_BFu8s");
    static BFu0ll_B_BFu8s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_B_BFu8s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_B_BFu8s)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu8s.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0ll_B_BFu8s");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0ll_B_BFu8s");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu8s(Test_BFu0ll_B_BFu8s, "BFu0ll_B_BFu8s", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu9i  {
  __tsu64  :0;
  bool v1;
  unsigned int v2:9;
};
//SIG(1 BFu0ll_B_BFu9i) C1{ FL:0 Fc Fi:9}



static void Test_BFu0ll_B_BFu9i()
{
  {
    init_simple_test("BFu0ll_B_BFu9i");
    static BFu0ll_B_BFu9i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_BFu9i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_B_BFu9i)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu9i.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "BFu0ll_B_BFu9i");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "BFu0ll_B_BFu9i");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu9i(Test_BFu0ll_B_BFu9i, "BFu0ll_B_BFu9i", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu9ll  {
  __tsu64  :0;
  bool v1;
  __tsu64 v2:9;
};
//SIG(1 BFu0ll_B_BFu9ll) C1{ FL:0 Fc FL:9}



static void Test_BFu0ll_B_BFu9ll()
{
  {
    init_simple_test("BFu0ll_B_BFu9ll");
    static BFu0ll_B_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_B_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu9ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "BFu0ll_B_BFu9ll");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "BFu0ll_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu9ll(Test_BFu0ll_B_BFu9ll, "BFu0ll_B_BFu9ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_BFu9s  {
  __tsu64  :0;
  bool v1;
  unsigned short v2:9;
};
//SIG(1 BFu0ll_B_BFu9s) C1{ FL:0 Fc Fs:9}



static void Test_BFu0ll_B_BFu9s()
{
  {
    init_simple_test("BFu0ll_B_BFu9s");
    static BFu0ll_B_BFu9s lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_BFu9s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_B_BFu9s)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_BFu9s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "BFu0ll_B_BFu9s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "BFu0ll_B_BFu9s");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_BFu9s(Test_BFu0ll_B_BFu9s, "BFu0ll_B_BFu9s", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_C  {
  __tsu64  :0;
  bool v1;
  char v2;
};
//SIG(1 BFu0ll_B_C) C1{ FL:0 Fc[2]}



static void Test_BFu0ll_B_C()
{
  {
    init_simple_test("BFu0ll_B_C");
    static BFu0ll_B_C lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_B_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_B_C)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_C.v1");
    check_field_offset(lv, v2, 1, "BFu0ll_B_C.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_C(Test_BFu0ll_B_C, "BFu0ll_B_C", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_D  {
  __tsu64  :0;
  bool v1;
  double v2;
};
//SIG(1 BFu0ll_B_D) C1{ FL:0 Fc FL}



static void Test_BFu0ll_B_D()
{
  {
    init_simple_test("BFu0ll_B_D");
    static BFu0ll_B_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0ll_B_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_D)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0ll_B_D.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_D(Test_BFu0ll_B_D, "BFu0ll_B_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_F  {
  __tsu64  :0;
  bool v1;
  float v2;
};
//SIG(1 BFu0ll_B_F) C1{ FL:0 Fc Fi}



static void Test_BFu0ll_B_F()
{
  {
    init_simple_test("BFu0ll_B_F");
    static BFu0ll_B_F lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_B_F)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_B_F)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_F.v1");
    check_field_offset(lv, v2, 4, "BFu0ll_B_F.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_F(Test_BFu0ll_B_F, "BFu0ll_B_F", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_I  {
  __tsu64  :0;
  bool v1;
  int v2;
};
//SIG(1 BFu0ll_B_I) C1{ FL:0 Fc Fi}



static void Test_BFu0ll_B_I()
{
  {
    init_simple_test("BFu0ll_B_I");
    static BFu0ll_B_I lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_B_I)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_B_I)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_I.v1");
    check_field_offset(lv, v2, 4, "BFu0ll_B_I.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_I(Test_BFu0ll_B_I, "BFu0ll_B_I", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_Ip  {
  __tsu64  :0;
  bool v1;
  int *v2;
};
//SIG(1 BFu0ll_B_Ip) C1{ FL:0 Fc Fp}



static void Test_BFu0ll_B_Ip()
{
  {
    init_simple_test("BFu0ll_B_Ip");
    static BFu0ll_B_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0ll_B_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_Ip)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0ll_B_Ip.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_Ip(Test_BFu0ll_B_Ip, "BFu0ll_B_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_L  {
  __tsu64  :0;
  bool v1;
  __tsi64 v2;
};
//SIG(1 BFu0ll_B_L) C1{ FL:0 Fc FL}



static void Test_BFu0ll_B_L()
{
  {
    init_simple_test("BFu0ll_B_L");
    static BFu0ll_B_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0ll_B_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_L)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0ll_B_L.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_L(Test_BFu0ll_B_L, "BFu0ll_B_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_S  {
  __tsu64  :0;
  bool v1;
  short v2;
};
//SIG(1 BFu0ll_B_S) C1{ FL:0 Fc Fs}



static void Test_BFu0ll_B_S()
{
  {
    init_simple_test("BFu0ll_B_S");
    static BFu0ll_B_S lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_S)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_B_S)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_S.v1");
    check_field_offset(lv, v2, 2, "BFu0ll_B_S.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_S(Test_BFu0ll_B_S, "BFu0ll_B_S", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_Uc  {
  __tsu64  :0;
  bool v1;
  unsigned char v2;
};
//SIG(1 BFu0ll_B_Uc) C1{ FL:0 Fc[2]}



static void Test_BFu0ll_B_Uc()
{
  {
    init_simple_test("BFu0ll_B_Uc");
    static BFu0ll_B_Uc lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_B_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_B_Uc)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_Uc.v1");
    check_field_offset(lv, v2, 1, "BFu0ll_B_Uc.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_Uc(Test_BFu0ll_B_Uc, "BFu0ll_B_Uc", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_Ui  {
  __tsu64  :0;
  bool v1;
  unsigned int v2;
};
//SIG(1 BFu0ll_B_Ui) C1{ FL:0 Fc Fi}



static void Test_BFu0ll_B_Ui()
{
  {
    init_simple_test("BFu0ll_B_Ui");
    static BFu0ll_B_Ui lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_B_Ui)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_B_Ui)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_Ui.v1");
    check_field_offset(lv, v2, 4, "BFu0ll_B_Ui.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_Ui(Test_BFu0ll_B_Ui, "BFu0ll_B_Ui", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_Ul  {
  __tsu64  :0;
  bool v1;
  __tsu64 v2;
};
//SIG(1 BFu0ll_B_Ul) C1{ FL:0 Fc FL}



static void Test_BFu0ll_B_Ul()
{
  {
    init_simple_test("BFu0ll_B_Ul");
    static BFu0ll_B_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0ll_B_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_Ul)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0ll_B_Ul.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_Ul(Test_BFu0ll_B_Ul, "BFu0ll_B_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_Us  {
  __tsu64  :0;
  bool v1;
  unsigned short v2;
};
//SIG(1 BFu0ll_B_Us) C1{ FL:0 Fc Fs}



static void Test_BFu0ll_B_Us()
{
  {
    init_simple_test("BFu0ll_B_Us");
    static BFu0ll_B_Us lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_B_Us)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_B_Us)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_Us.v1");
    check_field_offset(lv, v2, 2, "BFu0ll_B_Us.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_Us(Test_BFu0ll_B_Us, "BFu0ll_B_Us", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_Vp  {
  __tsu64  :0;
  bool v1;
  void *v2;
};
//SIG(1 BFu0ll_B_Vp) C1{ FL:0 Fc Fp}



static void Test_BFu0ll_B_Vp()
{
  {
    init_simple_test("BFu0ll_B_Vp");
    static BFu0ll_B_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0ll_B_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_B_Vp)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0ll_B_Vp.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_Vp(Test_BFu0ll_B_Vp, "BFu0ll_B_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu0c_B  {
  __tsu64  :0;
  unsigned char  :0;
  bool v1;
};
//SIG(1 BFu0ll_BFu0c_B) C1{ FL:0 Fc:0 Fc}



static void Test_BFu0ll_BFu0c_B()
{
  {
    init_simple_test("BFu0ll_BFu0c_B");
    static BFu0ll_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu0c_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_BFu0c_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu0c_B(Test_BFu0ll_BFu0c_B, "BFu0ll_BFu0c_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu0i_B  {
  __tsu64  :0;
  unsigned int  :0;
  bool v1;
};
//SIG(1 BFu0ll_BFu0i_B) C1{ FL:0 Fi:0 Fc}



static void Test_BFu0ll_BFu0i_B()
{
  {
    init_simple_test("BFu0ll_BFu0i_B");
    static BFu0ll_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu0i_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_BFu0i_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu0i_B(Test_BFu0ll_BFu0i_B, "BFu0ll_BFu0i_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu0ll_B  {
  __tsu64  :0;
  __tsu64  :0;
  bool v1;
};
//SIG(1 BFu0ll_BFu0ll_B) C1{ FL:0 FL:0 Fc}



static void Test_BFu0ll_BFu0ll_B()
{
  {
    init_simple_test("BFu0ll_BFu0ll_B");
    static BFu0ll_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_BFu0ll_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu0ll_B(Test_BFu0ll_BFu0ll_B, "BFu0ll_BFu0ll_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu0s_B  {
  __tsu64  :0;
  unsigned short  :0;
  bool v1;
};
//SIG(1 BFu0ll_BFu0s_B) C1{ FL:0 Fs:0 Fc}



static void Test_BFu0ll_BFu0s_B()
{
  {
    init_simple_test("BFu0ll_BFu0s_B");
    static BFu0ll_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu0s_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_BFu0s_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu0s_B(Test_BFu0ll_BFu0s_B, "BFu0ll_BFu0s_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu15i_B  {
  __tsu64  :0;
  unsigned int v1:15;
  bool v2;
};
//SIG(1 BFu0ll_BFu15i_B) C1{ FL:0 Fi:15 Fc}



static void Test_BFu0ll_BFu15i_B()
{
  {
    init_simple_test("BFu0ll_BFu15i_B");
    static BFu0ll_BFu15i_B lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu15i_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu15i_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0ll_BFu15i_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0ll_BFu15i_B");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu15i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu15i_B(Test_BFu0ll_BFu15i_B, "BFu0ll_BFu15i_B", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu15ll_B  {
  __tsu64  :0;
  __tsu64 v1:15;
  bool v2;
};
//SIG(1 BFu0ll_BFu15ll_B) C1{ FL:0 FL:15 Fc}



static void Test_BFu0ll_BFu15ll_B()
{
  {
    init_simple_test("BFu0ll_BFu15ll_B");
    static BFu0ll_BFu15ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu15ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu15ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0ll_BFu15ll_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0ll_BFu15ll_B");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu15ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu15ll_B(Test_BFu0ll_BFu15ll_B, "BFu0ll_BFu15ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu15s_B  {
  __tsu64  :0;
  unsigned short v1:15;
  bool v2;
};
//SIG(1 BFu0ll_BFu15s_B) C1{ FL:0 Fs:15 Fc}



static void Test_BFu0ll_BFu15s_B()
{
  {
    init_simple_test("BFu0ll_BFu15s_B");
    static BFu0ll_BFu15s_B lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu15s_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_BFu15s_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0ll_BFu15s_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0ll_BFu15s_B");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu15s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu15s_B(Test_BFu0ll_BFu15s_B, "BFu0ll_BFu15s_B", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu16i_B  {
  __tsu64  :0;
  unsigned int v1:16;
  bool v2;
};
//SIG(1 BFu0ll_BFu16i_B) C1{ FL:0 Fi:16 Fc}



static void Test_BFu0ll_BFu16i_B()
{
  {
    init_simple_test("BFu0ll_BFu16i_B");
    static BFu0ll_BFu16i_B lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu16i_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu16i_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0ll_BFu16i_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0ll_BFu16i_B");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu16i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu16i_B(Test_BFu0ll_BFu16i_B, "BFu0ll_BFu16i_B", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu16ll_B  {
  __tsu64  :0;
  __tsu64 v1:16;
  bool v2;
};
//SIG(1 BFu0ll_BFu16ll_B) C1{ FL:0 FL:16 Fc}



static void Test_BFu0ll_BFu16ll_B()
{
  {
    init_simple_test("BFu0ll_BFu16ll_B");
    static BFu0ll_BFu16ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu16ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu16ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0ll_BFu16ll_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0ll_BFu16ll_B");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu16ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu16ll_B(Test_BFu0ll_BFu16ll_B, "BFu0ll_BFu16ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu16s_B  {
  __tsu64  :0;
  unsigned short v1:16;
  bool v2;
};
//SIG(1 BFu0ll_BFu16s_B) C1{ FL:0 Fs:16 Fc}



static void Test_BFu0ll_BFu16s_B()
{
  {
    init_simple_test("BFu0ll_BFu16s_B");
    static BFu0ll_BFu16s_B lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu16s_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_BFu16s_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0ll_BFu16s_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0ll_BFu16s_B");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu16s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu16s_B(Test_BFu0ll_BFu16s_B, "BFu0ll_BFu16s_B", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu17i_B  {
  __tsu64  :0;
  unsigned int v1:17;
  bool v2;
};
//SIG(1 BFu0ll_BFu17i_B) C1{ FL:0 Fi:17 Fc}



static void Test_BFu0ll_BFu17i_B()
{
  {
    init_simple_test("BFu0ll_BFu17i_B");
    static BFu0ll_BFu17i_B lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu17i_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu17i_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0ll_BFu17i_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0ll_BFu17i_B");
    check_field_offset(lv, v2, 3, "BFu0ll_BFu17i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu17i_B(Test_BFu0ll_BFu17i_B, "BFu0ll_BFu17i_B", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu17ll_B  {
  __tsu64  :0;
  __tsu64 v1:17;
  bool v2;
};
//SIG(1 BFu0ll_BFu17ll_B) C1{ FL:0 FL:17 Fc}



static void Test_BFu0ll_BFu17ll_B()
{
  {
    init_simple_test("BFu0ll_BFu17ll_B");
    static BFu0ll_BFu17ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu17ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu17ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0ll_BFu17ll_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0ll_BFu17ll_B");
    check_field_offset(lv, v2, 3, "BFu0ll_BFu17ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu17ll_B(Test_BFu0ll_BFu17ll_B, "BFu0ll_BFu17ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu1c_B  {
  __tsu64  :0;
  unsigned char v1:1;
  bool v2;
};
//SIG(1 BFu0ll_BFu1c_B) C1{ FL:0 Fc:1 Fc}



static void Test_BFu0ll_BFu1c_B()
{
  {
    init_simple_test("BFu0ll_BFu1c_B");
    static BFu0ll_BFu1c_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_BFu1c_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu1c_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0ll_BFu1c_B");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu1c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu1c_B(Test_BFu0ll_BFu1c_B, "BFu0ll_BFu1c_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu1i_B  {
  __tsu64  :0;
  unsigned int v1:1;
  bool v2;
};
//SIG(1 BFu0ll_BFu1i_B) C1{ FL:0 Fi:1 Fc}



static void Test_BFu0ll_BFu1i_B()
{
  {
    init_simple_test("BFu0ll_BFu1i_B");
    static BFu0ll_BFu1i_B lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu1i_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu1i_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0ll_BFu1i_B");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu1i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu1i_B(Test_BFu0ll_BFu1i_B, "BFu0ll_BFu1i_B", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu1ll_B  {
  __tsu64  :0;
  __tsu64 v1:1;
  bool v2;
};
//SIG(1 BFu0ll_BFu1ll_B) C1{ FL:0 FL:1 Fc}



static void Test_BFu0ll_BFu1ll_B()
{
  {
    init_simple_test("BFu0ll_BFu1ll_B");
    static BFu0ll_BFu1ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu1ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu1ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0ll_BFu1ll_B");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu1ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu1ll_B(Test_BFu0ll_BFu1ll_B, "BFu0ll_BFu1ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu1s_B  {
  __tsu64  :0;
  unsigned short v1:1;
  bool v2;
};
//SIG(1 BFu0ll_BFu1s_B) C1{ FL:0 Fs:1 Fc}



static void Test_BFu0ll_BFu1s_B()
{
  {
    init_simple_test("BFu0ll_BFu1s_B");
    static BFu0ll_BFu1s_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_BFu1s_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_BFu1s_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0ll_BFu1s_B");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu1s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu1s_B(Test_BFu0ll_BFu1s_B, "BFu0ll_BFu1s_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu31i_B  {
  __tsu64  :0;
  unsigned int v1:31;
  bool v2;
};
//SIG(1 BFu0ll_BFu31i_B) C1{ FL:0 Fi:31 Fc}



static void Test_BFu0ll_BFu31i_B()
{
  {
    init_simple_test("BFu0ll_BFu31i_B");
    static BFu0ll_BFu31i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_BFu31i_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu31i_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0ll_BFu31i_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0ll_BFu31i_B");
    check_field_offset(lv, v2, 4, "BFu0ll_BFu31i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu31i_B(Test_BFu0ll_BFu31i_B, "BFu0ll_BFu31i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu31ll_B  {
  __tsu64  :0;
  __tsu64 v1:31;
  bool v2;
};
//SIG(1 BFu0ll_BFu31ll_B) C1{ FL:0 FL:31 Fc}



static void Test_BFu0ll_BFu31ll_B()
{
  {
    init_simple_test("BFu0ll_BFu31ll_B");
    static BFu0ll_BFu31ll_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_BFu31ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu31ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0ll_BFu31ll_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0ll_BFu31ll_B");
    check_field_offset(lv, v2, 4, "BFu0ll_BFu31ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu31ll_B(Test_BFu0ll_BFu31ll_B, "BFu0ll_BFu31ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu32i_B  {
  __tsu64  :0;
  unsigned int v1:32;
  bool v2;
};
//SIG(1 BFu0ll_BFu32i_B) C1{ FL:0 Fi:32 Fc}



static void Test_BFu0ll_BFu32i_B()
{
  {
    init_simple_test("BFu0ll_BFu32i_B");
    static BFu0ll_BFu32i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_BFu32i_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu32i_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0ll_BFu32i_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0ll_BFu32i_B");
    check_field_offset(lv, v2, 4, "BFu0ll_BFu32i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu32i_B(Test_BFu0ll_BFu32i_B, "BFu0ll_BFu32i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu32ll_B  {
  __tsu64  :0;
  __tsu64 v1:32;
  bool v2;
};
//SIG(1 BFu0ll_BFu32ll_B) C1{ FL:0 FL:32 Fc}



static void Test_BFu0ll_BFu32ll_B()
{
  {
    init_simple_test("BFu0ll_BFu32ll_B");
    static BFu0ll_BFu32ll_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_BFu32ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu32ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0ll_BFu32ll_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0ll_BFu32ll_B");
    check_field_offset(lv, v2, 4, "BFu0ll_BFu32ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu32ll_B(Test_BFu0ll_BFu32ll_B, "BFu0ll_BFu32ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu33_B  {
  __tsu64  :0;
  __tsu64 v1:33;
  bool v2;
};
//SIG(1 BFu0ll_BFu33_B) C1{ FL:0 FL:33 Fc}



static void Test_BFu0ll_BFu33_B()
{
  {
    init_simple_test("BFu0ll_BFu33_B");
    static BFu0ll_BFu33_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_BFu33_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu33_B)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu0ll_BFu33_B");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu0ll_BFu33_B");
    check_field_offset(lv, v2, 5, "BFu0ll_BFu33_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu33_B(Test_BFu0ll_BFu33_B, "BFu0ll_BFu33_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu7c_B  {
  __tsu64  :0;
  unsigned char v1:7;
  bool v2;
};
//SIG(1 BFu0ll_BFu7c_B) C1{ FL:0 Fc:7 Fc}



static void Test_BFu0ll_BFu7c_B()
{
  {
    init_simple_test("BFu0ll_BFu7c_B");
    static BFu0ll_BFu7c_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_BFu7c_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu7c_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0ll_BFu7c_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0ll_BFu7c_B");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu7c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu7c_B(Test_BFu0ll_BFu7c_B, "BFu0ll_BFu7c_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu7i_B  {
  __tsu64  :0;
  unsigned int v1:7;
  bool v2;
};
//SIG(1 BFu0ll_BFu7i_B) C1{ FL:0 Fi:7 Fc}



static void Test_BFu0ll_BFu7i_B()
{
  {
    init_simple_test("BFu0ll_BFu7i_B");
    static BFu0ll_BFu7i_B lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu7i_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu7i_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0ll_BFu7i_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0ll_BFu7i_B");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu7i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu7i_B(Test_BFu0ll_BFu7i_B, "BFu0ll_BFu7i_B", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu7ll_B  {
  __tsu64  :0;
  __tsu64 v1:7;
  bool v2;
};
//SIG(1 BFu0ll_BFu7ll_B) C1{ FL:0 FL:7 Fc}



static void Test_BFu0ll_BFu7ll_B()
{
  {
    init_simple_test("BFu0ll_BFu7ll_B");
    static BFu0ll_BFu7ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu7ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu7ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0ll_BFu7ll_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0ll_BFu7ll_B");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu7ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu7ll_B(Test_BFu0ll_BFu7ll_B, "BFu0ll_BFu7ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu7s_B  {
  __tsu64  :0;
  unsigned short v1:7;
  bool v2;
};
//SIG(1 BFu0ll_BFu7s_B) C1{ FL:0 Fs:7 Fc}



static void Test_BFu0ll_BFu7s_B()
{
  {
    init_simple_test("BFu0ll_BFu7s_B");
    static BFu0ll_BFu7s_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_BFu7s_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_BFu7s_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0ll_BFu7s_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0ll_BFu7s_B");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu7s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu7s_B(Test_BFu0ll_BFu7s_B, "BFu0ll_BFu7s_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu8c_B  {
  __tsu64  :0;
  unsigned char v1:8;
  bool v2;
};
//SIG(1 BFu0ll_BFu8c_B) C1{ FL:0 Fc:8 Fc}



static void Test_BFu0ll_BFu8c_B()
{
  {
    init_simple_test("BFu0ll_BFu8c_B");
    static BFu0ll_BFu8c_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_BFu8c_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu8c_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0ll_BFu8c_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0ll_BFu8c_B");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu8c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu8c_B(Test_BFu0ll_BFu8c_B, "BFu0ll_BFu8c_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu8i_B  {
  __tsu64  :0;
  unsigned int v1:8;
  bool v2;
};
//SIG(1 BFu0ll_BFu8i_B) C1{ FL:0 Fi:8 Fc}



static void Test_BFu0ll_BFu8i_B()
{
  {
    init_simple_test("BFu0ll_BFu8i_B");
    static BFu0ll_BFu8i_B lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu8i_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu8i_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0ll_BFu8i_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0ll_BFu8i_B");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu8i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu8i_B(Test_BFu0ll_BFu8i_B, "BFu0ll_BFu8i_B", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu8ll_B  {
  __tsu64  :0;
  __tsu64 v1:8;
  bool v2;
};
//SIG(1 BFu0ll_BFu8ll_B) C1{ FL:0 FL:8 Fc}



static void Test_BFu0ll_BFu8ll_B()
{
  {
    init_simple_test("BFu0ll_BFu8ll_B");
    static BFu0ll_BFu8ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu8ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu8ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0ll_BFu8ll_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0ll_BFu8ll_B");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu8ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu8ll_B(Test_BFu0ll_BFu8ll_B, "BFu0ll_BFu8ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu8s_B  {
  __tsu64  :0;
  unsigned short v1:8;
  bool v2;
};
//SIG(1 BFu0ll_BFu8s_B) C1{ FL:0 Fs:8 Fc}



static void Test_BFu0ll_BFu8s_B()
{
  {
    init_simple_test("BFu0ll_BFu8s_B");
    static BFu0ll_BFu8s_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_BFu8s_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_BFu8s_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0ll_BFu8s_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0ll_BFu8s_B");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu8s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu8s_B(Test_BFu0ll_BFu8s_B, "BFu0ll_BFu8s_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu9i_B  {
  __tsu64  :0;
  unsigned int v1:9;
  bool v2;
};
//SIG(1 BFu0ll_BFu9i_B) C1{ FL:0 Fi:9 Fc}



static void Test_BFu0ll_BFu9i_B()
{
  {
    init_simple_test("BFu0ll_BFu9i_B");
    static BFu0ll_BFu9i_B lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu9i_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu9i_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0ll_BFu9i_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0ll_BFu9i_B");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu9i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu9i_B(Test_BFu0ll_BFu9i_B, "BFu0ll_BFu9i_B", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu9ll_B  {
  __tsu64  :0;
  __tsu64 v1:9;
  bool v2;
};
//SIG(1 BFu0ll_BFu9ll_B) C1{ FL:0 FL:9 Fc}



static void Test_BFu0ll_BFu9ll_B()
{
  {
    init_simple_test("BFu0ll_BFu9ll_B");
    static BFu0ll_BFu9ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu9ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu9ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0ll_BFu9ll_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0ll_BFu9ll_B");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu9ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu9ll_B(Test_BFu0ll_BFu9ll_B, "BFu0ll_BFu9ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_BFu9s_B  {
  __tsu64  :0;
  unsigned short v1:9;
  bool v2;
};
//SIG(1 BFu0ll_BFu9s_B) C1{ FL:0 Fs:9 Fc}



static void Test_BFu0ll_BFu9s_B()
{
  {
    init_simple_test("BFu0ll_BFu9s_B");
    static BFu0ll_BFu9s_B lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu9s_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_BFu9s_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0ll_BFu9s_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0ll_BFu9s_B");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu9s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_BFu9s_B(Test_BFu0ll_BFu9s_B, "BFu0ll_BFu9s_B", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_C_B  {
  __tsu64  :0;
  char v1;
  bool v2;
};
//SIG(1 BFu0ll_C_B) C1{ FL:0 Fc[2]}



static void Test_BFu0ll_C_B()
{
  {
    init_simple_test("BFu0ll_C_B");
    static BFu0ll_C_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_C_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_C_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_C_B.v1");
    check_field_offset(lv, v2, 1, "BFu0ll_C_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_C_B(Test_BFu0ll_C_B, "BFu0ll_C_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_D_B  {
  __tsu64  :0;
  double v1;
  bool v2;
};
//SIG(1 BFu0ll_D_B) C1{ FL:0 FL Fc}



static void Test_BFu0ll_D_B()
{
  {
    init_simple_test("BFu0ll_D_B");
    static BFu0ll_D_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0ll_D_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_D_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_D_B.v1");
    check_field_offset(lv, v2, 8, "BFu0ll_D_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_D_B(Test_BFu0ll_D_B, "BFu0ll_D_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_F_B  {
  __tsu64  :0;
  float v1;
  bool v2;
};
//SIG(1 BFu0ll_F_B) C1{ FL:0 Fi Fc}



static void Test_BFu0ll_F_B()
{
  {
    init_simple_test("BFu0ll_F_B");
    static BFu0ll_F_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_F_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_F_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_F_B.v1");
    check_field_offset(lv, v2, 4, "BFu0ll_F_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_F_B(Test_BFu0ll_F_B, "BFu0ll_F_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_I_B  {
  __tsu64  :0;
  int v1;
  bool v2;
};
//SIG(1 BFu0ll_I_B) C1{ FL:0 Fi Fc}



static void Test_BFu0ll_I_B()
{
  {
    init_simple_test("BFu0ll_I_B");
    static BFu0ll_I_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_I_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_I_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_I_B.v1");
    check_field_offset(lv, v2, 4, "BFu0ll_I_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_I_B(Test_BFu0ll_I_B, "BFu0ll_I_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_Ip_B  {
  __tsu64  :0;
  int *v1;
  bool v2;
};
//SIG(1 BFu0ll_Ip_B) C1{ FL:0 Fp Fc}



static void Test_BFu0ll_Ip_B()
{
  {
    init_simple_test("BFu0ll_Ip_B");
    static BFu0ll_Ip_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0ll_Ip_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Ip_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_Ip_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0ll_Ip_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_Ip_B(Test_BFu0ll_Ip_B, "BFu0ll_Ip_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_L_B  {
  __tsu64  :0;
  __tsi64 v1;
  bool v2;
};
//SIG(1 BFu0ll_L_B) C1{ FL:0 FL Fc}



static void Test_BFu0ll_L_B()
{
  {
    init_simple_test("BFu0ll_L_B");
    static BFu0ll_L_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0ll_L_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_L_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_L_B.v1");
    check_field_offset(lv, v2, 8, "BFu0ll_L_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_L_B(Test_BFu0ll_L_B, "BFu0ll_L_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_S_B  {
  __tsu64  :0;
  short v1;
  bool v2;
};
//SIG(1 BFu0ll_S_B) C1{ FL:0 Fs Fc}



static void Test_BFu0ll_S_B()
{
  {
    init_simple_test("BFu0ll_S_B");
    static BFu0ll_S_B lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_S_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_S_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_S_B.v1");
    check_field_offset(lv, v2, 2, "BFu0ll_S_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_S_B(Test_BFu0ll_S_B, "BFu0ll_S_B", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_Uc_B  {
  __tsu64  :0;
  unsigned char v1;
  bool v2;
};
//SIG(1 BFu0ll_Uc_B) C1{ FL:0 Fc[2]}



static void Test_BFu0ll_Uc_B()
{
  {
    init_simple_test("BFu0ll_Uc_B");
    static BFu0ll_Uc_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_Uc_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Uc_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_Uc_B.v1");
    check_field_offset(lv, v2, 1, "BFu0ll_Uc_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_Uc_B(Test_BFu0ll_Uc_B, "BFu0ll_Uc_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_Ui_B  {
  __tsu64  :0;
  unsigned int v1;
  bool v2;
};
//SIG(1 BFu0ll_Ui_B) C1{ FL:0 Fi Fc}



static void Test_BFu0ll_Ui_B()
{
  {
    init_simple_test("BFu0ll_Ui_B");
    static BFu0ll_Ui_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_Ui_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Ui_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_Ui_B.v1");
    check_field_offset(lv, v2, 4, "BFu0ll_Ui_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_Ui_B(Test_BFu0ll_Ui_B, "BFu0ll_Ui_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_Ul_B  {
  __tsu64  :0;
  __tsu64 v1;
  bool v2;
};
//SIG(1 BFu0ll_Ul_B) C1{ FL:0 FL Fc}



static void Test_BFu0ll_Ul_B()
{
  {
    init_simple_test("BFu0ll_Ul_B");
    static BFu0ll_Ul_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0ll_Ul_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Ul_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_Ul_B.v1");
    check_field_offset(lv, v2, 8, "BFu0ll_Ul_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_Ul_B(Test_BFu0ll_Ul_B, "BFu0ll_Ul_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_Us_B  {
  __tsu64  :0;
  unsigned short v1;
  bool v2;
};
//SIG(1 BFu0ll_Us_B) C1{ FL:0 Fs Fc}



static void Test_BFu0ll_Us_B()
{
  {
    init_simple_test("BFu0ll_Us_B");
    static BFu0ll_Us_B lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Us_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_Us_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_Us_B.v1");
    check_field_offset(lv, v2, 2, "BFu0ll_Us_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_Us_B(Test_BFu0ll_Us_B, "BFu0ll_Us_B", ABISELECT(4,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_Vp_B  {
  __tsu64  :0;
  void *v1;
  bool v2;
};
//SIG(1 BFu0ll_Vp_B) C1{ FL:0 Fp Fc}



static void Test_BFu0ll_Vp_B()
{
  {
    init_simple_test("BFu0ll_Vp_B");
    static BFu0ll_Vp_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0ll_Vp_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Vp_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_Vp_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0ll_Vp_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_Vp_B(Test_BFu0ll_Vp_B, "BFu0ll_Vp_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B  {
  unsigned short  :0;
  bool v1;
};
//SIG(1 BFu0s_B) C1{ Fs:0 Fc}



static void Test_BFu0s_B()
{
  {
    init_simple_test("BFu0s_B");
    static BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_B)");
    check_field_offset(lv, v1, 0, "BFu0s_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0s_B(Test_BFu0s_B, "BFu0s_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_B  {
  unsigned short  :0;
  bool v1;
  bool v2;
};
//SIG(1 BFu0s_B_B) C1{ Fs:0 Fc[2]}



static void Test_BFu0s_B_B()
{
  {
    init_simple_test("BFu0s_B_B");
    static BFu0s_B_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_B_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_B_B)");
    check_field_offset(lv, v1, 0, "BFu0s_B_B.v1");
    check_field_offset(lv, v2, 1, "BFu0s_B_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_B(Test_BFu0s_B_B, "BFu0s_B_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu0c  {
  unsigned short  :0;
  bool v1;
  unsigned char  :0;
};
//SIG(1 BFu0s_B_BFu0c) C1{ Fs:0 Fc Fc:0}



static void Test_BFu0s_B_BFu0c()
{
  {
    init_simple_test("BFu0s_B_BFu0c");
    static BFu0s_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_B_BFu0c)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu0c.v1");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu0c(Test_BFu0s_B_BFu0c, "BFu0s_B_BFu0c", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu0i  {
  unsigned short  :0;
  bool v1;
  unsigned int  :0;
};
//SIG(1 BFu0s_B_BFu0i) C1{ Fs:0 Fc Fi:0}



static void Test_BFu0s_B_BFu0i()
{
  {
    init_simple_test("BFu0s_B_BFu0i");
    static BFu0s_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_B_BFu0i)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu0i.v1");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu0i(Test_BFu0s_B_BFu0i, "BFu0s_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu0ll  {
  unsigned short  :0;
  bool v1;
  __tsu64  :0;
};
//SIG(1 BFu0s_B_BFu0ll) C1{ Fs:0 Fc FL:0}



static void Test_BFu0s_B_BFu0ll()
{
  {
    init_simple_test("BFu0s_B_BFu0ll");
    static BFu0s_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu0ll.v1");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu0ll(Test_BFu0s_B_BFu0ll, "BFu0s_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu0s  {
  unsigned short  :0;
  bool v1;
  unsigned short  :0;
};
//SIG(1 BFu0s_B_BFu0s) C1{ Fs:0 Fc Fs:0}



static void Test_BFu0s_B_BFu0s()
{
  {
    init_simple_test("BFu0s_B_BFu0s");
    static BFu0s_B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_B_BFu0s)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu0s.v1");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu0s(Test_BFu0s_B_BFu0s, "BFu0s_B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu15i  {
  unsigned short  :0;
  bool v1;
  unsigned int v2:15;
};
//SIG(1 BFu0s_B_BFu15i) C1{ Fs:0 Fc Fi:15}



static void Test_BFu0s_B_BFu15i()
{
  {
    init_simple_test("BFu0s_B_BFu15i");
    static BFu0s_B_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_B_BFu15i)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu15i.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "BFu0s_B_BFu15i");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "BFu0s_B_BFu15i");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu15i(Test_BFu0s_B_BFu15i, "BFu0s_B_BFu15i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu15ll  {
  unsigned short  :0;
  bool v1;
  __tsu64 v2:15;
};
//SIG(1 BFu0s_B_BFu15ll) C1{ Fs:0 Fc FL:15}



static void Test_BFu0s_B_BFu15ll()
{
  {
    init_simple_test("BFu0s_B_BFu15ll");
    static BFu0s_B_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_B_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_BFu15ll)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu15ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 15, 1, "BFu0s_B_BFu15ll");
    set_bf_and_test(lv, v2, 1, 0, 15, hide_ull(1LL<<14), "BFu0s_B_BFu15ll");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu15ll(Test_BFu0s_B_BFu15ll, "BFu0s_B_BFu15ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu15s  {
  unsigned short  :0;
  bool v1;
  unsigned short v2:15;
};
//SIG(1 BFu0s_B_BFu15s) C1{ Fs:0 Fc Fs:15}



static void Test_BFu0s_B_BFu15s()
{
  {
    init_simple_test("BFu0s_B_BFu15s");
    static BFu0s_B_BFu15s lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_BFu15s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_B_BFu15s)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu15s.v1");
    set_bf_and_test(lv, v2, 2, 0, 15, 1, "BFu0s_B_BFu15s");
    set_bf_and_test(lv, v2, 2, 0, 15, hide_ull(1LL<<14), "BFu0s_B_BFu15s");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu15s(Test_BFu0s_B_BFu15s, "BFu0s_B_BFu15s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu16i  {
  unsigned short  :0;
  bool v1;
  unsigned int v2:16;
};
//SIG(1 BFu0s_B_BFu16i) C1{ Fs:0 Fc Fi:16}



static void Test_BFu0s_B_BFu16i()
{
  {
    init_simple_test("BFu0s_B_BFu16i");
    static BFu0s_B_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_B_BFu16i)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu16i.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "BFu0s_B_BFu16i");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "BFu0s_B_BFu16i");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu16i(Test_BFu0s_B_BFu16i, "BFu0s_B_BFu16i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu16ll  {
  unsigned short  :0;
  bool v1;
  __tsu64 v2:16;
};
//SIG(1 BFu0s_B_BFu16ll) C1{ Fs:0 Fc FL:16}



static void Test_BFu0s_B_BFu16ll()
{
  {
    init_simple_test("BFu0s_B_BFu16ll");
    static BFu0s_B_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_B_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_BFu16ll)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu16ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 16, 1, "BFu0s_B_BFu16ll");
    set_bf_and_test(lv, v2, 1, 0, 16, hide_ull(1LL<<15), "BFu0s_B_BFu16ll");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu16ll(Test_BFu0s_B_BFu16ll, "BFu0s_B_BFu16ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu16s  {
  unsigned short  :0;
  bool v1;
  unsigned short v2:16;
};
//SIG(1 BFu0s_B_BFu16s) C1{ Fs:0 Fc Fs:16}



static void Test_BFu0s_B_BFu16s()
{
  {
    init_simple_test("BFu0s_B_BFu16s");
    static BFu0s_B_BFu16s lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_BFu16s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_B_BFu16s)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu16s.v1");
    set_bf_and_test(lv, v2, 2, 0, 16, 1, "BFu0s_B_BFu16s");
    set_bf_and_test(lv, v2, 2, 0, 16, hide_ull(1LL<<15), "BFu0s_B_BFu16s");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu16s(Test_BFu0s_B_BFu16s, "BFu0s_B_BFu16s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu17i  {
  unsigned short  :0;
  bool v1;
  unsigned int v2:17;
};
//SIG(1 BFu0s_B_BFu17i) C1{ Fs:0 Fc Fi:17}



static void Test_BFu0s_B_BFu17i()
{
  {
    init_simple_test("BFu0s_B_BFu17i");
    static BFu0s_B_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_B_BFu17i)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu17i.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "BFu0s_B_BFu17i");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "BFu0s_B_BFu17i");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu17i(Test_BFu0s_B_BFu17i, "BFu0s_B_BFu17i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu17ll  {
  unsigned short  :0;
  bool v1;
  __tsu64 v2:17;
};
//SIG(1 BFu0s_B_BFu17ll) C1{ Fs:0 Fc FL:17}



static void Test_BFu0s_B_BFu17ll()
{
  {
    init_simple_test("BFu0s_B_BFu17ll");
    static BFu0s_B_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_B_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_BFu17ll)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu17ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 17, 1, "BFu0s_B_BFu17ll");
    set_bf_and_test(lv, v2, 1, 0, 17, hide_ull(1LL<<16), "BFu0s_B_BFu17ll");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu17ll(Test_BFu0s_B_BFu17ll, "BFu0s_B_BFu17ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu1c  {
  unsigned short  :0;
  bool v1;
  unsigned char v2:1;
};
//SIG(1 BFu0s_B_BFu1c) C1{ Fs:0 Fc Fc:1}



static void Test_BFu0s_B_BFu1c()
{
  {
    init_simple_test("BFu0s_B_BFu1c");
    static BFu0s_B_BFu1c lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_B_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_B_BFu1c)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu1c.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0s_B_BFu1c");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu1c(Test_BFu0s_B_BFu1c, "BFu0s_B_BFu1c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu1i  {
  unsigned short  :0;
  bool v1;
  unsigned int v2:1;
};
//SIG(1 BFu0s_B_BFu1i) C1{ Fs:0 Fc Fi:1}



static void Test_BFu0s_B_BFu1i()
{
  {
    init_simple_test("BFu0s_B_BFu1i");
    static BFu0s_B_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_B_BFu1i)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu1i.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0s_B_BFu1i");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu1i(Test_BFu0s_B_BFu1i, "BFu0s_B_BFu1i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu1ll  {
  unsigned short  :0;
  bool v1;
  __tsu64 v2:1;
};
//SIG(1 BFu0s_B_BFu1ll) C1{ Fs:0 Fc FL:1}



static void Test_BFu0s_B_BFu1ll()
{
  {
    init_simple_test("BFu0s_B_BFu1ll");
    static BFu0s_B_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_B_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_BFu1ll)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu1ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0s_B_BFu1ll");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu1ll(Test_BFu0s_B_BFu1ll, "BFu0s_B_BFu1ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu1s  {
  unsigned short  :0;
  bool v1;
  unsigned short v2:1;
};
//SIG(1 BFu0s_B_BFu1s) C1{ Fs:0 Fc Fs:1}



static void Test_BFu0s_B_BFu1s()
{
  {
    init_simple_test("BFu0s_B_BFu1s");
    static BFu0s_B_BFu1s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_B_BFu1s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_B_BFu1s)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu1s.v1");
    set_bf_and_test(lv, v2, 1, 0, 1, 1, "BFu0s_B_BFu1s");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu1s(Test_BFu0s_B_BFu1s, "BFu0s_B_BFu1s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu31i  {
  unsigned short  :0;
  bool v1;
  unsigned int v2:31;
};
//SIG(1 BFu0s_B_BFu31i) C1{ Fs:0 Fc Fi:31}



static void Test_BFu0s_B_BFu31i()
{
  {
    init_simple_test("BFu0s_B_BFu31i");
    static BFu0s_B_BFu31i lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_B_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_B_BFu31i)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu31i.v1");
    set_bf_and_test(lv, v2, 4, 0, 31, 1, "BFu0s_B_BFu31i");
    set_bf_and_test(lv, v2, 4, 0, 31, hide_ull(1LL<<30), "BFu0s_B_BFu31i");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu31i(Test_BFu0s_B_BFu31i, "BFu0s_B_BFu31i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu31ll  {
  unsigned short  :0;
  bool v1;
  __tsu64 v2:31;
};
//SIG(1 BFu0s_B_BFu31ll) C1{ Fs:0 Fc FL:31}



static void Test_BFu0s_B_BFu31ll()
{
  {
    init_simple_test("BFu0s_B_BFu31ll");
    static BFu0s_B_BFu31ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_B_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_BFu31ll)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu31ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 31, 1, "BFu0s_B_BFu31ll");
    set_bf_and_test(lv, v2, 1, 0, 31, hide_ull(1LL<<30), "BFu0s_B_BFu31ll");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu31ll(Test_BFu0s_B_BFu31ll, "BFu0s_B_BFu31ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu32i  {
  unsigned short  :0;
  bool v1;
  unsigned int v2:32;
};
//SIG(1 BFu0s_B_BFu32i) C1{ Fs:0 Fc Fi:32}



static void Test_BFu0s_B_BFu32i()
{
  {
    init_simple_test("BFu0s_B_BFu32i");
    static BFu0s_B_BFu32i lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_B_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_B_BFu32i)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu32i.v1");
    set_bf_and_test(lv, v2, 4, 0, 32, 1, "BFu0s_B_BFu32i");
    set_bf_and_test(lv, v2, 4, 0, 32, hide_ull(1LL<<31), "BFu0s_B_BFu32i");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu32i(Test_BFu0s_B_BFu32i, "BFu0s_B_BFu32i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu32ll  {
  unsigned short  :0;
  bool v1;
  __tsu64 v2:32;
};
//SIG(1 BFu0s_B_BFu32ll) C1{ Fs:0 Fc FL:32}



static void Test_BFu0s_B_BFu32ll()
{
  {
    init_simple_test("BFu0s_B_BFu32ll");
    static BFu0s_B_BFu32ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_B_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_BFu32ll)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu32ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 32, 1, "BFu0s_B_BFu32ll");
    set_bf_and_test(lv, v2, 1, 0, 32, hide_ull(1LL<<31), "BFu0s_B_BFu32ll");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu32ll(Test_BFu0s_B_BFu32ll, "BFu0s_B_BFu32ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu33  {
  unsigned short  :0;
  bool v1;
  __tsu64 v2:33;
};
//SIG(1 BFu0s_B_BFu33) C1{ Fs:0 Fc FL:33}



static void Test_BFu0s_B_BFu33()
{
  {
    init_simple_test("BFu0s_B_BFu33");
    static BFu0s_B_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_B_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_BFu33)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu33.v1");
    set_bf_and_test(lv, v2, 1, 0, 33, 1, "BFu0s_B_BFu33");
    set_bf_and_test(lv, v2, 1, 0, 33, hide_ull(1LL<<32), "BFu0s_B_BFu33");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu33(Test_BFu0s_B_BFu33, "BFu0s_B_BFu33", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu7c  {
  unsigned short  :0;
  bool v1;
  unsigned char v2:7;
};
//SIG(1 BFu0s_B_BFu7c) C1{ Fs:0 Fc Fc:7}



static void Test_BFu0s_B_BFu7c()
{
  {
    init_simple_test("BFu0s_B_BFu7c");
    static BFu0s_B_BFu7c lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_B_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_B_BFu7c)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu7c.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0s_B_BFu7c");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0s_B_BFu7c");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu7c(Test_BFu0s_B_BFu7c, "BFu0s_B_BFu7c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu7i  {
  unsigned short  :0;
  bool v1;
  unsigned int v2:7;
};
//SIG(1 BFu0s_B_BFu7i) C1{ Fs:0 Fc Fi:7}



static void Test_BFu0s_B_BFu7i()
{
  {
    init_simple_test("BFu0s_B_BFu7i");
    static BFu0s_B_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_B_BFu7i)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu7i.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0s_B_BFu7i");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0s_B_BFu7i");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu7i(Test_BFu0s_B_BFu7i, "BFu0s_B_BFu7i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu7ll  {
  unsigned short  :0;
  bool v1;
  __tsu64 v2:7;
};
//SIG(1 BFu0s_B_BFu7ll) C1{ Fs:0 Fc FL:7}



static void Test_BFu0s_B_BFu7ll()
{
  {
    init_simple_test("BFu0s_B_BFu7ll");
    static BFu0s_B_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_B_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_BFu7ll)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu7ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0s_B_BFu7ll");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0s_B_BFu7ll");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu7ll(Test_BFu0s_B_BFu7ll, "BFu0s_B_BFu7ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu7s  {
  unsigned short  :0;
  bool v1;
  unsigned short v2:7;
};
//SIG(1 BFu0s_B_BFu7s) C1{ Fs:0 Fc Fs:7}



static void Test_BFu0s_B_BFu7s()
{
  {
    init_simple_test("BFu0s_B_BFu7s");
    static BFu0s_B_BFu7s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_B_BFu7s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_B_BFu7s)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu7s.v1");
    set_bf_and_test(lv, v2, 1, 0, 7, 1, "BFu0s_B_BFu7s");
    set_bf_and_test(lv, v2, 1, 0, 7, hide_ull(1LL<<6), "BFu0s_B_BFu7s");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu7s(Test_BFu0s_B_BFu7s, "BFu0s_B_BFu7s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu8c  {
  unsigned short  :0;
  bool v1;
  unsigned char v2:8;
};
//SIG(1 BFu0s_B_BFu8c) C1{ Fs:0 Fc Fc:8}



static void Test_BFu0s_B_BFu8c()
{
  {
    init_simple_test("BFu0s_B_BFu8c");
    static BFu0s_B_BFu8c lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_B_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_B_BFu8c)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu8c.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0s_B_BFu8c");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0s_B_BFu8c");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu8c(Test_BFu0s_B_BFu8c, "BFu0s_B_BFu8c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu8i  {
  unsigned short  :0;
  bool v1;
  unsigned int v2:8;
};
//SIG(1 BFu0s_B_BFu8i) C1{ Fs:0 Fc Fi:8}



static void Test_BFu0s_B_BFu8i()
{
  {
    init_simple_test("BFu0s_B_BFu8i");
    static BFu0s_B_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_B_BFu8i)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu8i.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0s_B_BFu8i");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0s_B_BFu8i");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu8i(Test_BFu0s_B_BFu8i, "BFu0s_B_BFu8i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu8ll  {
  unsigned short  :0;
  bool v1;
  __tsu64 v2:8;
};
//SIG(1 BFu0s_B_BFu8ll) C1{ Fs:0 Fc FL:8}



static void Test_BFu0s_B_BFu8ll()
{
  {
    init_simple_test("BFu0s_B_BFu8ll");
    static BFu0s_B_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_B_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_BFu8ll)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu8ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0s_B_BFu8ll");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0s_B_BFu8ll");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu8ll(Test_BFu0s_B_BFu8ll, "BFu0s_B_BFu8ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu8s  {
  unsigned short  :0;
  bool v1;
  unsigned short v2:8;
};
//SIG(1 BFu0s_B_BFu8s) C1{ Fs:0 Fc Fs:8}



static void Test_BFu0s_B_BFu8s()
{
  {
    init_simple_test("BFu0s_B_BFu8s");
    static BFu0s_B_BFu8s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_B_BFu8s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_B_BFu8s)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu8s.v1");
    set_bf_and_test(lv, v2, 1, 0, 8, 1, "BFu0s_B_BFu8s");
    set_bf_and_test(lv, v2, 1, 0, 8, hide_ull(1LL<<7), "BFu0s_B_BFu8s");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu8s(Test_BFu0s_B_BFu8s, "BFu0s_B_BFu8s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu9i  {
  unsigned short  :0;
  bool v1;
  unsigned int v2:9;
};
//SIG(1 BFu0s_B_BFu9i) C1{ Fs:0 Fc Fi:9}



static void Test_BFu0s_B_BFu9i()
{
  {
    init_simple_test("BFu0s_B_BFu9i");
    static BFu0s_B_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_B_BFu9i)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu9i.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "BFu0s_B_BFu9i");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "BFu0s_B_BFu9i");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu9i(Test_BFu0s_B_BFu9i, "BFu0s_B_BFu9i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu9ll  {
  unsigned short  :0;
  bool v1;
  __tsu64 v2:9;
};
//SIG(1 BFu0s_B_BFu9ll) C1{ Fs:0 Fc FL:9}



static void Test_BFu0s_B_BFu9ll()
{
  {
    init_simple_test("BFu0s_B_BFu9ll");
    static BFu0s_B_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_B_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_BFu9ll)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu9ll.v1");
    set_bf_and_test(lv, v2, 1, 0, 9, 1, "BFu0s_B_BFu9ll");
    set_bf_and_test(lv, v2, 1, 0, 9, hide_ull(1LL<<8), "BFu0s_B_BFu9ll");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu9ll(Test_BFu0s_B_BFu9ll, "BFu0s_B_BFu9ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_BFu9s  {
  unsigned short  :0;
  bool v1;
  unsigned short v2:9;
};
//SIG(1 BFu0s_B_BFu9s) C1{ Fs:0 Fc Fs:9}



static void Test_BFu0s_B_BFu9s()
{
  {
    init_simple_test("BFu0s_B_BFu9s");
    static BFu0s_B_BFu9s lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_BFu9s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_B_BFu9s)");
    check_field_offset(lv, v1, 0, "BFu0s_B_BFu9s.v1");
    set_bf_and_test(lv, v2, 2, 0, 9, 1, "BFu0s_B_BFu9s");
    set_bf_and_test(lv, v2, 2, 0, 9, hide_ull(1LL<<8), "BFu0s_B_BFu9s");
  }
}
static Arrange_To_Call_Me vBFu0s_B_BFu9s(Test_BFu0s_B_BFu9s, "BFu0s_B_BFu9s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_C  {
  unsigned short  :0;
  bool v1;
  char v2;
};
//SIG(1 BFu0s_B_C) C1{ Fs:0 Fc[2]}



static void Test_BFu0s_B_C()
{
  {
    init_simple_test("BFu0s_B_C");
    static BFu0s_B_C lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_B_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_B_C)");
    check_field_offset(lv, v1, 0, "BFu0s_B_C.v1");
    check_field_offset(lv, v2, 1, "BFu0s_B_C.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_C(Test_BFu0s_B_C, "BFu0s_B_C", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_D  {
  unsigned short  :0;
  bool v1;
  double v2;
};
//SIG(1 BFu0s_B_D) C1{ Fs:0 Fc FL}



static void Test_BFu0s_B_D()
{
  {
    init_simple_test("BFu0s_B_D");
    static BFu0s_B_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0s_B_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_D)");
    check_field_offset(lv, v1, 0, "BFu0s_B_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0s_B_D.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_D(Test_BFu0s_B_D, "BFu0s_B_D", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_F  {
  unsigned short  :0;
  bool v1;
  float v2;
};
//SIG(1 BFu0s_B_F) C1{ Fs:0 Fc Fi}



static void Test_BFu0s_B_F()
{
  {
    init_simple_test("BFu0s_B_F");
    static BFu0s_B_F lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_B_F)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_B_F)");
    check_field_offset(lv, v1, 0, "BFu0s_B_F.v1");
    check_field_offset(lv, v2, 4, "BFu0s_B_F.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_F(Test_BFu0s_B_F, "BFu0s_B_F", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_I  {
  unsigned short  :0;
  bool v1;
  int v2;
};
//SIG(1 BFu0s_B_I) C1{ Fs:0 Fc Fi}



static void Test_BFu0s_B_I()
{
  {
    init_simple_test("BFu0s_B_I");
    static BFu0s_B_I lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_B_I)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_B_I)");
    check_field_offset(lv, v1, 0, "BFu0s_B_I.v1");
    check_field_offset(lv, v2, 4, "BFu0s_B_I.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_I(Test_BFu0s_B_I, "BFu0s_B_I", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_Ip  {
  unsigned short  :0;
  bool v1;
  int *v2;
};
//SIG(1 BFu0s_B_Ip) C1{ Fs:0 Fc Fp}



static void Test_BFu0s_B_Ip()
{
  {
    init_simple_test("BFu0s_B_Ip");
    static BFu0s_B_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0s_B_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_Ip)");
    check_field_offset(lv, v1, 0, "BFu0s_B_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0s_B_Ip.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_Ip(Test_BFu0s_B_Ip, "BFu0s_B_Ip", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_L  {
  unsigned short  :0;
  bool v1;
  __tsi64 v2;
};
//SIG(1 BFu0s_B_L) C1{ Fs:0 Fc FL}



static void Test_BFu0s_B_L()
{
  {
    init_simple_test("BFu0s_B_L");
    static BFu0s_B_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0s_B_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_L)");
    check_field_offset(lv, v1, 0, "BFu0s_B_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0s_B_L.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_L(Test_BFu0s_B_L, "BFu0s_B_L", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_S  {
  unsigned short  :0;
  bool v1;
  short v2;
};
//SIG(1 BFu0s_B_S) C1{ Fs:0 Fc Fs}



static void Test_BFu0s_B_S()
{
  {
    init_simple_test("BFu0s_B_S");
    static BFu0s_B_S lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_S)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_B_S)");
    check_field_offset(lv, v1, 0, "BFu0s_B_S.v1");
    check_field_offset(lv, v2, 2, "BFu0s_B_S.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_S(Test_BFu0s_B_S, "BFu0s_B_S", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_Uc  {
  unsigned short  :0;
  bool v1;
  unsigned char v2;
};
//SIG(1 BFu0s_B_Uc) C1{ Fs:0 Fc[2]}



static void Test_BFu0s_B_Uc()
{
  {
    init_simple_test("BFu0s_B_Uc");
    static BFu0s_B_Uc lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_B_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_B_Uc)");
    check_field_offset(lv, v1, 0, "BFu0s_B_Uc.v1");
    check_field_offset(lv, v2, 1, "BFu0s_B_Uc.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_Uc(Test_BFu0s_B_Uc, "BFu0s_B_Uc", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_Ui  {
  unsigned short  :0;
  bool v1;
  unsigned int v2;
};
//SIG(1 BFu0s_B_Ui) C1{ Fs:0 Fc Fi}



static void Test_BFu0s_B_Ui()
{
  {
    init_simple_test("BFu0s_B_Ui");
    static BFu0s_B_Ui lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_B_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_B_Ui)");
    check_field_offset(lv, v1, 0, "BFu0s_B_Ui.v1");
    check_field_offset(lv, v2, 4, "BFu0s_B_Ui.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_Ui(Test_BFu0s_B_Ui, "BFu0s_B_Ui", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_Ul  {
  unsigned short  :0;
  bool v1;
  __tsu64 v2;
};
//SIG(1 BFu0s_B_Ul) C1{ Fs:0 Fc FL}



static void Test_BFu0s_B_Ul()
{
  {
    init_simple_test("BFu0s_B_Ul");
    static BFu0s_B_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0s_B_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_Ul)");
    check_field_offset(lv, v1, 0, "BFu0s_B_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0s_B_Ul.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_Ul(Test_BFu0s_B_Ul, "BFu0s_B_Ul", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_Us  {
  unsigned short  :0;
  bool v1;
  unsigned short v2;
};
//SIG(1 BFu0s_B_Us) C1{ Fs:0 Fc Fs}



static void Test_BFu0s_B_Us()
{
  {
    init_simple_test("BFu0s_B_Us");
    static BFu0s_B_Us lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_B_Us)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_B_Us)");
    check_field_offset(lv, v1, 0, "BFu0s_B_Us.v1");
    check_field_offset(lv, v2, 2, "BFu0s_B_Us.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_Us(Test_BFu0s_B_Us, "BFu0s_B_Us", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_Vp  {
  unsigned short  :0;
  bool v1;
  void *v2;
};
//SIG(1 BFu0s_B_Vp) C1{ Fs:0 Fc Fp}



static void Test_BFu0s_B_Vp()
{
  {
    init_simple_test("BFu0s_B_Vp");
    static BFu0s_B_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0s_B_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_B_Vp)");
    check_field_offset(lv, v1, 0, "BFu0s_B_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0s_B_Vp.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_Vp(Test_BFu0s_B_Vp, "BFu0s_B_Vp", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu0c_B  {
  unsigned short  :0;
  unsigned char  :0;
  bool v1;
};
//SIG(1 BFu0s_BFu0c_B) C1{ Fs:0 Fc:0 Fc}



static void Test_BFu0s_BFu0c_B()
{
  {
    init_simple_test("BFu0s_BFu0c_B");
    static BFu0s_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu0c_B)");
    check_field_offset(lv, v1, 0, "BFu0s_BFu0c_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu0c_B(Test_BFu0s_BFu0c_B, "BFu0s_BFu0c_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu0i_B  {
  unsigned short  :0;
  unsigned int  :0;
  bool v1;
};
//SIG(1 BFu0s_BFu0i_B) C1{ Fs:0 Fi:0 Fc}



static void Test_BFu0s_BFu0i_B()
{
  {
    init_simple_test("BFu0s_BFu0i_B");
    static BFu0s_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu0i_B)");
    check_field_offset(lv, v1, 0, "BFu0s_BFu0i_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu0i_B(Test_BFu0s_BFu0i_B, "BFu0s_BFu0i_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu0ll_B  {
  unsigned short  :0;
  __tsu64  :0;
  bool v1;
};
//SIG(1 BFu0s_BFu0ll_B) C1{ Fs:0 FL:0 Fc}



static void Test_BFu0s_BFu0ll_B()
{
  {
    init_simple_test("BFu0s_BFu0ll_B");
    static BFu0s_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "BFu0s_BFu0ll_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu0ll_B(Test_BFu0s_BFu0ll_B, "BFu0s_BFu0ll_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu0s_B  {
  unsigned short  :0;
  unsigned short  :0;
  bool v1;
};
//SIG(1 BFu0s_BFu0s_B) C1{ Fs:0 Fs:0 Fc}



static void Test_BFu0s_BFu0s_B()
{
  {
    init_simple_test("BFu0s_BFu0s_B");
    static BFu0s_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu0s_B)");
    check_field_offset(lv, v1, 0, "BFu0s_BFu0s_B.v1");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu0s_B(Test_BFu0s_BFu0s_B, "BFu0s_BFu0s_B", ABISELECT(1,1));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu15i_B  {
  unsigned short  :0;
  unsigned int v1:15;
  bool v2;
};
//SIG(1 BFu0s_BFu15i_B) C1{ Fs:0 Fi:15 Fc}



static void Test_BFu0s_BFu15i_B()
{
  {
    init_simple_test("BFu0s_BFu15i_B");
    static BFu0s_BFu15i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu15i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu15i_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0s_BFu15i_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0s_BFu15i_B");
    check_field_offset(lv, v2, 2, "BFu0s_BFu15i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu15i_B(Test_BFu0s_BFu15i_B, "BFu0s_BFu15i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu15ll_B  {
  unsigned short  :0;
  __tsu64 v1:15;
  bool v2;
};
//SIG(1 BFu0s_BFu15ll_B) C1{ Fs:0 FL:15 Fc}



static void Test_BFu0s_BFu15ll_B()
{
  {
    init_simple_test("BFu0s_BFu15ll_B");
    static BFu0s_BFu15ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu15ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu15ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0s_BFu15ll_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0s_BFu15ll_B");
    check_field_offset(lv, v2, 2, "BFu0s_BFu15ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu15ll_B(Test_BFu0s_BFu15ll_B, "BFu0s_BFu15ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu15s_B  {
  unsigned short  :0;
  unsigned short v1:15;
  bool v2;
};
//SIG(1 BFu0s_BFu15s_B) C1{ Fs:0 Fs:15 Fc}



static void Test_BFu0s_BFu15s_B()
{
  {
    init_simple_test("BFu0s_BFu15s_B");
    static BFu0s_BFu15s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu15s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_BFu15s_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0s_BFu15s_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0s_BFu15s_B");
    check_field_offset(lv, v2, 2, "BFu0s_BFu15s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu15s_B(Test_BFu0s_BFu15s_B, "BFu0s_BFu15s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu16i_B  {
  unsigned short  :0;
  unsigned int v1:16;
  bool v2;
};
//SIG(1 BFu0s_BFu16i_B) C1{ Fs:0 Fi:16 Fc}



static void Test_BFu0s_BFu16i_B()
{
  {
    init_simple_test("BFu0s_BFu16i_B");
    static BFu0s_BFu16i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu16i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu16i_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0s_BFu16i_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0s_BFu16i_B");
    check_field_offset(lv, v2, 2, "BFu0s_BFu16i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu16i_B(Test_BFu0s_BFu16i_B, "BFu0s_BFu16i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu16ll_B  {
  unsigned short  :0;
  __tsu64 v1:16;
  bool v2;
};
//SIG(1 BFu0s_BFu16ll_B) C1{ Fs:0 FL:16 Fc}



static void Test_BFu0s_BFu16ll_B()
{
  {
    init_simple_test("BFu0s_BFu16ll_B");
    static BFu0s_BFu16ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu16ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu16ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0s_BFu16ll_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0s_BFu16ll_B");
    check_field_offset(lv, v2, 2, "BFu0s_BFu16ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu16ll_B(Test_BFu0s_BFu16ll_B, "BFu0s_BFu16ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu16s_B  {
  unsigned short  :0;
  unsigned short v1:16;
  bool v2;
};
//SIG(1 BFu0s_BFu16s_B) C1{ Fs:0 Fs:16 Fc}



static void Test_BFu0s_BFu16s_B()
{
  {
    init_simple_test("BFu0s_BFu16s_B");
    static BFu0s_BFu16s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu16s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_BFu16s_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0s_BFu16s_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0s_BFu16s_B");
    check_field_offset(lv, v2, 2, "BFu0s_BFu16s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu16s_B(Test_BFu0s_BFu16s_B, "BFu0s_BFu16s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu17i_B  {
  unsigned short  :0;
  unsigned int v1:17;
  bool v2;
};
//SIG(1 BFu0s_BFu17i_B) C1{ Fs:0 Fi:17 Fc}



static void Test_BFu0s_BFu17i_B()
{
  {
    init_simple_test("BFu0s_BFu17i_B");
    static BFu0s_BFu17i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu17i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu17i_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0s_BFu17i_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0s_BFu17i_B");
    check_field_offset(lv, v2, 3, "BFu0s_BFu17i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu17i_B(Test_BFu0s_BFu17i_B, "BFu0s_BFu17i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu17ll_B  {
  unsigned short  :0;
  __tsu64 v1:17;
  bool v2;
};
//SIG(1 BFu0s_BFu17ll_B) C1{ Fs:0 FL:17 Fc}



static void Test_BFu0s_BFu17ll_B()
{
  {
    init_simple_test("BFu0s_BFu17ll_B");
    static BFu0s_BFu17ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu17ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu17ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0s_BFu17ll_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0s_BFu17ll_B");
    check_field_offset(lv, v2, 3, "BFu0s_BFu17ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu17ll_B(Test_BFu0s_BFu17ll_B, "BFu0s_BFu17ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu1c_B  {
  unsigned short  :0;
  unsigned char v1:1;
  bool v2;
};
//SIG(1 BFu0s_BFu1c_B) C1{ Fs:0 Fc:1 Fc}



static void Test_BFu0s_BFu1c_B()
{
  {
    init_simple_test("BFu0s_BFu1c_B");
    static BFu0s_BFu1c_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_BFu1c_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu1c_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0s_BFu1c_B");
    check_field_offset(lv, v2, 1, "BFu0s_BFu1c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu1c_B(Test_BFu0s_BFu1c_B, "BFu0s_BFu1c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu1i_B  {
  unsigned short  :0;
  unsigned int v1:1;
  bool v2;
};
//SIG(1 BFu0s_BFu1i_B) C1{ Fs:0 Fi:1 Fc}



static void Test_BFu0s_BFu1i_B()
{
  {
    init_simple_test("BFu0s_BFu1i_B");
    static BFu0s_BFu1i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu1i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu1i_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0s_BFu1i_B");
    check_field_offset(lv, v2, 1, "BFu0s_BFu1i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu1i_B(Test_BFu0s_BFu1i_B, "BFu0s_BFu1i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu1ll_B  {
  unsigned short  :0;
  __tsu64 v1:1;
  bool v2;
};
//SIG(1 BFu0s_BFu1ll_B) C1{ Fs:0 FL:1 Fc}



static void Test_BFu0s_BFu1ll_B()
{
  {
    init_simple_test("BFu0s_BFu1ll_B");
    static BFu0s_BFu1ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu1ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu1ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0s_BFu1ll_B");
    check_field_offset(lv, v2, 1, "BFu0s_BFu1ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu1ll_B(Test_BFu0s_BFu1ll_B, "BFu0s_BFu1ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu1s_B  {
  unsigned short  :0;
  unsigned short v1:1;
  bool v2;
};
//SIG(1 BFu0s_BFu1s_B) C1{ Fs:0 Fs:1 Fc}



static void Test_BFu0s_BFu1s_B()
{
  {
    init_simple_test("BFu0s_BFu1s_B");
    static BFu0s_BFu1s_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_BFu1s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_BFu1s_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0s_BFu1s_B");
    check_field_offset(lv, v2, 1, "BFu0s_BFu1s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu1s_B(Test_BFu0s_BFu1s_B, "BFu0s_BFu1s_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu31i_B  {
  unsigned short  :0;
  unsigned int v1:31;
  bool v2;
};
//SIG(1 BFu0s_BFu31i_B) C1{ Fs:0 Fi:31 Fc}



static void Test_BFu0s_BFu31i_B()
{
  {
    init_simple_test("BFu0s_BFu31i_B");
    static BFu0s_BFu31i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_BFu31i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu31i_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0s_BFu31i_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0s_BFu31i_B");
    check_field_offset(lv, v2, 4, "BFu0s_BFu31i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu31i_B(Test_BFu0s_BFu31i_B, "BFu0s_BFu31i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu31ll_B  {
  unsigned short  :0;
  __tsu64 v1:31;
  bool v2;
};
//SIG(1 BFu0s_BFu31ll_B) C1{ Fs:0 FL:31 Fc}



static void Test_BFu0s_BFu31ll_B()
{
  {
    init_simple_test("BFu0s_BFu31ll_B");
    static BFu0s_BFu31ll_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_BFu31ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu31ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0s_BFu31ll_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0s_BFu31ll_B");
    check_field_offset(lv, v2, 4, "BFu0s_BFu31ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu31ll_B(Test_BFu0s_BFu31ll_B, "BFu0s_BFu31ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu32i_B  {
  unsigned short  :0;
  unsigned int v1:32;
  bool v2;
};
//SIG(1 BFu0s_BFu32i_B) C1{ Fs:0 Fi:32 Fc}



static void Test_BFu0s_BFu32i_B()
{
  {
    init_simple_test("BFu0s_BFu32i_B");
    static BFu0s_BFu32i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_BFu32i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu32i_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0s_BFu32i_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0s_BFu32i_B");
    check_field_offset(lv, v2, 4, "BFu0s_BFu32i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu32i_B(Test_BFu0s_BFu32i_B, "BFu0s_BFu32i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu32ll_B  {
  unsigned short  :0;
  __tsu64 v1:32;
  bool v2;
};
//SIG(1 BFu0s_BFu32ll_B) C1{ Fs:0 FL:32 Fc}



static void Test_BFu0s_BFu32ll_B()
{
  {
    init_simple_test("BFu0s_BFu32ll_B");
    static BFu0s_BFu32ll_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_BFu32ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu32ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0s_BFu32ll_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0s_BFu32ll_B");
    check_field_offset(lv, v2, 4, "BFu0s_BFu32ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu32ll_B(Test_BFu0s_BFu32ll_B, "BFu0s_BFu32ll_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu33_B  {
  unsigned short  :0;
  __tsu64 v1:33;
  bool v2;
};
//SIG(1 BFu0s_BFu33_B) C1{ Fs:0 FL:33 Fc}



static void Test_BFu0s_BFu33_B()
{
  {
    init_simple_test("BFu0s_BFu33_B");
    static BFu0s_BFu33_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_BFu33_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu33_B)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu0s_BFu33_B");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu0s_BFu33_B");
    check_field_offset(lv, v2, 5, "BFu0s_BFu33_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu33_B(Test_BFu0s_BFu33_B, "BFu0s_BFu33_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu7c_B  {
  unsigned short  :0;
  unsigned char v1:7;
  bool v2;
};
//SIG(1 BFu0s_BFu7c_B) C1{ Fs:0 Fc:7 Fc}



static void Test_BFu0s_BFu7c_B()
{
  {
    init_simple_test("BFu0s_BFu7c_B");
    static BFu0s_BFu7c_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_BFu7c_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu7c_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0s_BFu7c_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0s_BFu7c_B");
    check_field_offset(lv, v2, 1, "BFu0s_BFu7c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu7c_B(Test_BFu0s_BFu7c_B, "BFu0s_BFu7c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu7i_B  {
  unsigned short  :0;
  unsigned int v1:7;
  bool v2;
};
//SIG(1 BFu0s_BFu7i_B) C1{ Fs:0 Fi:7 Fc}



static void Test_BFu0s_BFu7i_B()
{
  {
    init_simple_test("BFu0s_BFu7i_B");
    static BFu0s_BFu7i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu7i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu7i_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0s_BFu7i_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0s_BFu7i_B");
    check_field_offset(lv, v2, 1, "BFu0s_BFu7i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu7i_B(Test_BFu0s_BFu7i_B, "BFu0s_BFu7i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu7ll_B  {
  unsigned short  :0;
  __tsu64 v1:7;
  bool v2;
};
//SIG(1 BFu0s_BFu7ll_B) C1{ Fs:0 FL:7 Fc}



static void Test_BFu0s_BFu7ll_B()
{
  {
    init_simple_test("BFu0s_BFu7ll_B");
    static BFu0s_BFu7ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu7ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu7ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0s_BFu7ll_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0s_BFu7ll_B");
    check_field_offset(lv, v2, 1, "BFu0s_BFu7ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu7ll_B(Test_BFu0s_BFu7ll_B, "BFu0s_BFu7ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu7s_B  {
  unsigned short  :0;
  unsigned short v1:7;
  bool v2;
};
//SIG(1 BFu0s_BFu7s_B) C1{ Fs:0 Fs:7 Fc}



static void Test_BFu0s_BFu7s_B()
{
  {
    init_simple_test("BFu0s_BFu7s_B");
    static BFu0s_BFu7s_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_BFu7s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_BFu7s_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0s_BFu7s_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0s_BFu7s_B");
    check_field_offset(lv, v2, 1, "BFu0s_BFu7s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu7s_B(Test_BFu0s_BFu7s_B, "BFu0s_BFu7s_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu8c_B  {
  unsigned short  :0;
  unsigned char v1:8;
  bool v2;
};
//SIG(1 BFu0s_BFu8c_B) C1{ Fs:0 Fc:8 Fc}



static void Test_BFu0s_BFu8c_B()
{
  {
    init_simple_test("BFu0s_BFu8c_B");
    static BFu0s_BFu8c_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_BFu8c_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu8c_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0s_BFu8c_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0s_BFu8c_B");
    check_field_offset(lv, v2, 1, "BFu0s_BFu8c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu8c_B(Test_BFu0s_BFu8c_B, "BFu0s_BFu8c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu8i_B  {
  unsigned short  :0;
  unsigned int v1:8;
  bool v2;
};
//SIG(1 BFu0s_BFu8i_B) C1{ Fs:0 Fi:8 Fc}



static void Test_BFu0s_BFu8i_B()
{
  {
    init_simple_test("BFu0s_BFu8i_B");
    static BFu0s_BFu8i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu8i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu8i_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0s_BFu8i_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0s_BFu8i_B");
    check_field_offset(lv, v2, 1, "BFu0s_BFu8i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu8i_B(Test_BFu0s_BFu8i_B, "BFu0s_BFu8i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu8ll_B  {
  unsigned short  :0;
  __tsu64 v1:8;
  bool v2;
};
//SIG(1 BFu0s_BFu8ll_B) C1{ Fs:0 FL:8 Fc}



static void Test_BFu0s_BFu8ll_B()
{
  {
    init_simple_test("BFu0s_BFu8ll_B");
    static BFu0s_BFu8ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu8ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu8ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0s_BFu8ll_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0s_BFu8ll_B");
    check_field_offset(lv, v2, 1, "BFu0s_BFu8ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu8ll_B(Test_BFu0s_BFu8ll_B, "BFu0s_BFu8ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu8s_B  {
  unsigned short  :0;
  unsigned short v1:8;
  bool v2;
};
//SIG(1 BFu0s_BFu8s_B) C1{ Fs:0 Fs:8 Fc}



static void Test_BFu0s_BFu8s_B()
{
  {
    init_simple_test("BFu0s_BFu8s_B");
    static BFu0s_BFu8s_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_BFu8s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_BFu8s_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0s_BFu8s_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0s_BFu8s_B");
    check_field_offset(lv, v2, 1, "BFu0s_BFu8s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu8s_B(Test_BFu0s_BFu8s_B, "BFu0s_BFu8s_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu9i_B  {
  unsigned short  :0;
  unsigned int v1:9;
  bool v2;
};
//SIG(1 BFu0s_BFu9i_B) C1{ Fs:0 Fi:9 Fc}



static void Test_BFu0s_BFu9i_B()
{
  {
    init_simple_test("BFu0s_BFu9i_B");
    static BFu0s_BFu9i_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu9i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu9i_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0s_BFu9i_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0s_BFu9i_B");
    check_field_offset(lv, v2, 2, "BFu0s_BFu9i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu9i_B(Test_BFu0s_BFu9i_B, "BFu0s_BFu9i_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu9ll_B  {
  unsigned short  :0;
  __tsu64 v1:9;
  bool v2;
};
//SIG(1 BFu0s_BFu9ll_B) C1{ Fs:0 FL:9 Fc}



static void Test_BFu0s_BFu9ll_B()
{
  {
    init_simple_test("BFu0s_BFu9ll_B");
    static BFu0s_BFu9ll_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu9ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu9ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0s_BFu9ll_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0s_BFu9ll_B");
    check_field_offset(lv, v2, 2, "BFu0s_BFu9ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu9ll_B(Test_BFu0s_BFu9ll_B, "BFu0s_BFu9ll_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_BFu9s_B  {
  unsigned short  :0;
  unsigned short v1:9;
  bool v2;
};
//SIG(1 BFu0s_BFu9s_B) C1{ Fs:0 Fs:9 Fc}



static void Test_BFu0s_BFu9s_B()
{
  {
    init_simple_test("BFu0s_BFu9s_B");
    static BFu0s_BFu9s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu9s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_BFu9s_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0s_BFu9s_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0s_BFu9s_B");
    check_field_offset(lv, v2, 2, "BFu0s_BFu9s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_BFu9s_B(Test_BFu0s_BFu9s_B, "BFu0s_BFu9s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_C_B  {
  unsigned short  :0;
  char v1;
  bool v2;
};
//SIG(1 BFu0s_C_B) C1{ Fs:0 Fc[2]}



static void Test_BFu0s_C_B()
{
  {
    init_simple_test("BFu0s_C_B");
    static BFu0s_C_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_C_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_C_B)");
    check_field_offset(lv, v1, 0, "BFu0s_C_B.v1");
    check_field_offset(lv, v2, 1, "BFu0s_C_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_C_B(Test_BFu0s_C_B, "BFu0s_C_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_D_B  {
  unsigned short  :0;
  double v1;
  bool v2;
};
//SIG(1 BFu0s_D_B) C1{ Fs:0 FL Fc}



static void Test_BFu0s_D_B()
{
  {
    init_simple_test("BFu0s_D_B");
    static BFu0s_D_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0s_D_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_D_B)");
    check_field_offset(lv, v1, 0, "BFu0s_D_B.v1");
    check_field_offset(lv, v2, 8, "BFu0s_D_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_D_B(Test_BFu0s_D_B, "BFu0s_D_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_F_B  {
  unsigned short  :0;
  float v1;
  bool v2;
};
//SIG(1 BFu0s_F_B) C1{ Fs:0 Fi Fc}



static void Test_BFu0s_F_B()
{
  {
    init_simple_test("BFu0s_F_B");
    static BFu0s_F_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_F_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_F_B)");
    check_field_offset(lv, v1, 0, "BFu0s_F_B.v1");
    check_field_offset(lv, v2, 4, "BFu0s_F_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_F_B(Test_BFu0s_F_B, "BFu0s_F_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_I_B  {
  unsigned short  :0;
  int v1;
  bool v2;
};
//SIG(1 BFu0s_I_B) C1{ Fs:0 Fi Fc}



static void Test_BFu0s_I_B()
{
  {
    init_simple_test("BFu0s_I_B");
    static BFu0s_I_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_I_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_I_B)");
    check_field_offset(lv, v1, 0, "BFu0s_I_B.v1");
    check_field_offset(lv, v2, 4, "BFu0s_I_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_I_B(Test_BFu0s_I_B, "BFu0s_I_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_Ip_B  {
  unsigned short  :0;
  int *v1;
  bool v2;
};
//SIG(1 BFu0s_Ip_B) C1{ Fs:0 Fp Fc}



static void Test_BFu0s_Ip_B()
{
  {
    init_simple_test("BFu0s_Ip_B");
    static BFu0s_Ip_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0s_Ip_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Ip_B)");
    check_field_offset(lv, v1, 0, "BFu0s_Ip_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0s_Ip_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_Ip_B(Test_BFu0s_Ip_B, "BFu0s_Ip_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_L_B  {
  unsigned short  :0;
  __tsi64 v1;
  bool v2;
};
//SIG(1 BFu0s_L_B) C1{ Fs:0 FL Fc}



static void Test_BFu0s_L_B()
{
  {
    init_simple_test("BFu0s_L_B");
    static BFu0s_L_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0s_L_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_L_B)");
    check_field_offset(lv, v1, 0, "BFu0s_L_B.v1");
    check_field_offset(lv, v2, 8, "BFu0s_L_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_L_B(Test_BFu0s_L_B, "BFu0s_L_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_S_B  {
  unsigned short  :0;
  short v1;
  bool v2;
};
//SIG(1 BFu0s_S_B) C1{ Fs:0 Fs Fc}



static void Test_BFu0s_S_B()
{
  {
    init_simple_test("BFu0s_S_B");
    static BFu0s_S_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_S_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_S_B)");
    check_field_offset(lv, v1, 0, "BFu0s_S_B.v1");
    check_field_offset(lv, v2, 2, "BFu0s_S_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_S_B(Test_BFu0s_S_B, "BFu0s_S_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_Uc_B  {
  unsigned short  :0;
  unsigned char v1;
  bool v2;
};
//SIG(1 BFu0s_Uc_B) C1{ Fs:0 Fc[2]}



static void Test_BFu0s_Uc_B()
{
  {
    init_simple_test("BFu0s_Uc_B");
    static BFu0s_Uc_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_Uc_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Uc_B)");
    check_field_offset(lv, v1, 0, "BFu0s_Uc_B.v1");
    check_field_offset(lv, v2, 1, "BFu0s_Uc_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_Uc_B(Test_BFu0s_Uc_B, "BFu0s_Uc_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_Ui_B  {
  unsigned short  :0;
  unsigned int v1;
  bool v2;
};
//SIG(1 BFu0s_Ui_B) C1{ Fs:0 Fi Fc}



static void Test_BFu0s_Ui_B()
{
  {
    init_simple_test("BFu0s_Ui_B");
    static BFu0s_Ui_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_Ui_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Ui_B)");
    check_field_offset(lv, v1, 0, "BFu0s_Ui_B.v1");
    check_field_offset(lv, v2, 4, "BFu0s_Ui_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_Ui_B(Test_BFu0s_Ui_B, "BFu0s_Ui_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_Ul_B  {
  unsigned short  :0;
  __tsu64 v1;
  bool v2;
};
//SIG(1 BFu0s_Ul_B) C1{ Fs:0 FL Fc}



static void Test_BFu0s_Ul_B()
{
  {
    init_simple_test("BFu0s_Ul_B");
    static BFu0s_Ul_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu0s_Ul_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Ul_B)");
    check_field_offset(lv, v1, 0, "BFu0s_Ul_B.v1");
    check_field_offset(lv, v2, 8, "BFu0s_Ul_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_Ul_B(Test_BFu0s_Ul_B, "BFu0s_Ul_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_Us_B  {
  unsigned short  :0;
  unsigned short v1;
  bool v2;
};
//SIG(1 BFu0s_Us_B) C1{ Fs:0 Fs Fc}



static void Test_BFu0s_Us_B()
{
  {
    init_simple_test("BFu0s_Us_B");
    static BFu0s_Us_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Us_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_Us_B)");
    check_field_offset(lv, v1, 0, "BFu0s_Us_B.v1");
    check_field_offset(lv, v2, 2, "BFu0s_Us_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_Us_B(Test_BFu0s_Us_B, "BFu0s_Us_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_Vp_B  {
  unsigned short  :0;
  void *v1;
  bool v2;
};
//SIG(1 BFu0s_Vp_B) C1{ Fs:0 Fp Fc}



static void Test_BFu0s_Vp_B()
{
  {
    init_simple_test("BFu0s_Vp_B");
    static BFu0s_Vp_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu0s_Vp_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Vp_B)");
    check_field_offset(lv, v1, 0, "BFu0s_Vp_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0s_Vp_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_Vp_B(Test_BFu0s_Vp_B, "BFu0s_Vp_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15i_B_BFu0c  {
  unsigned int v1:15;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu15i_B_BFu0c) C1{ Fi:15 Fc Fc:0}



static void Test_BFu15i_B_BFu0c()
{
  {
    init_simple_test("BFu15i_B_BFu0c");
    static BFu15i_B_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_B_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_B_BFu0c");
    check_field_offset(lv, v2, 2, "BFu15i_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu15i_B_BFu0c(Test_BFu15i_B_BFu0c, "BFu15i_B_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15i_B_BFu0i  {
  unsigned int v1:15;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu15i_B_BFu0i) C1{ Fi:15 Fc Fi:0}



static void Test_BFu15i_B_BFu0i()
{
  {
    init_simple_test("BFu15i_B_BFu0i");
    static BFu15i_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_B_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_B_BFu0i");
    check_field_offset(lv, v2, 2, "BFu15i_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu15i_B_BFu0i(Test_BFu15i_B_BFu0i, "BFu15i_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15i_B_BFu0ll  {
  unsigned int v1:15;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu15i_B_BFu0ll) C1{ Fi:15 Fc FL:0}



static void Test_BFu15i_B_BFu0ll()
{
  {
    init_simple_test("BFu15i_B_BFu0ll");
    static BFu15i_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15i_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu15i_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_B_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu15i_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu15i_B_BFu0ll(Test_BFu15i_B_BFu0ll, "BFu15i_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15i_B_BFu0s  {
  unsigned int v1:15;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu15i_B_BFu0s) C1{ Fi:15 Fc Fs:0}



static void Test_BFu15i_B_BFu0s()
{
  {
    init_simple_test("BFu15i_B_BFu0s");
    static BFu15i_B_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_B_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_B_BFu0s");
    check_field_offset(lv, v2, 2, "BFu15i_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu15i_B_BFu0s(Test_BFu15i_B_BFu0s, "BFu15i_B_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15i_BFu0c_B  {
  unsigned int v1:15;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu15i_BFu0c_B) C1{ Fi:15 Fc:0 Fc}



static void Test_BFu15i_BFu0c_B()
{
  {
    init_simple_test("BFu15i_BFu0c_B");
    static BFu15i_BFu0c_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_BFu0c_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_BFu0c_B");
    check_field_offset(lv, v2, 2, "BFu15i_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu15i_BFu0c_B(Test_BFu15i_BFu0c_B, "BFu15i_BFu0c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15i_BFu0i_B  {
  unsigned int v1:15;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu15i_BFu0i_B) C1{ Fi:15 Fi:0 Fc}



static void Test_BFu15i_BFu0i_B()
{
  {
    init_simple_test("BFu15i_BFu0i_B");
    static BFu15i_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu15i_BFu0i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu15i_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu15i_BFu0i_B(Test_BFu15i_BFu0i_B, "BFu15i_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15i_BFu0ll_B  {
  unsigned int v1:15;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu15i_BFu0ll_B) C1{ Fi:15 FL:0 Fc}



static void Test_BFu15i_BFu0ll_B()
{
  {
    init_simple_test("BFu15i_BFu0ll_B");
    static BFu15i_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(BFu15i_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu15i_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu15i_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu15i_BFu0ll_B(Test_BFu15i_BFu0ll_B, "BFu15i_BFu0ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15i_BFu0s_B  {
  unsigned int v1:15;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu15i_BFu0s_B) C1{ Fi:15 Fs:0 Fc}



static void Test_BFu15i_BFu0s_B()
{
  {
    init_simple_test("BFu15i_BFu0s_B");
    static BFu15i_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_BFu0s_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu15i_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu15i_BFu0s_B(Test_BFu15i_BFu0s_B, "BFu15i_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15ll_B_BFu0c  {
  __tsu64 v1:15;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu15ll_B_BFu0c) C1{ FL:15 Fc Fc:0}



static void Test_BFu15ll_B_BFu0c()
{
  {
    init_simple_test("BFu15ll_B_BFu0c");
    static BFu15ll_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_B_BFu0c");
    check_field_offset(lv, v2, 2, "BFu15ll_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu15ll_B_BFu0c(Test_BFu15ll_B_BFu0c, "BFu15ll_B_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15ll_B_BFu0i  {
  __tsu64 v1:15;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu15ll_B_BFu0i) C1{ FL:15 Fc Fi:0}



static void Test_BFu15ll_B_BFu0i()
{
  {
    init_simple_test("BFu15ll_B_BFu0i");
    static BFu15ll_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_B_BFu0i");
    check_field_offset(lv, v2, 2, "BFu15ll_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu15ll_B_BFu0i(Test_BFu15ll_B_BFu0i, "BFu15ll_B_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15ll_B_BFu0ll  {
  __tsu64 v1:15;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu15ll_B_BFu0ll) C1{ FL:15 Fc FL:0}



static void Test_BFu15ll_B_BFu0ll()
{
  {
    init_simple_test("BFu15ll_B_BFu0ll");
    static BFu15ll_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_B_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu15ll_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu15ll_B_BFu0ll(Test_BFu15ll_B_BFu0ll, "BFu15ll_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15ll_B_BFu0s  {
  __tsu64 v1:15;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu15ll_B_BFu0s) C1{ FL:15 Fc Fs:0}



static void Test_BFu15ll_B_BFu0s()
{
  {
    init_simple_test("BFu15ll_B_BFu0s");
    static BFu15ll_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_B_BFu0s");
    check_field_offset(lv, v2, 2, "BFu15ll_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu15ll_B_BFu0s(Test_BFu15ll_B_BFu0s, "BFu15ll_B_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15ll_BFu0c_B  {
  __tsu64 v1:15;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu15ll_BFu0c_B) C1{ FL:15 Fc:0 Fc}



static void Test_BFu15ll_BFu0c_B()
{
  {
    init_simple_test("BFu15ll_BFu0c_B");
    static BFu15ll_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_BFu0c_B");
    check_field_offset(lv, v2, 2, "BFu15ll_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu15ll_BFu0c_B(Test_BFu15ll_BFu0c_B, "BFu15ll_BFu0c_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15ll_BFu0i_B  {
  __tsu64 v1:15;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu15ll_BFu0i_B) C1{ FL:15 Fi:0 Fc}



static void Test_BFu15ll_BFu0i_B()
{
  {
    init_simple_test("BFu15ll_BFu0i_B");
    static BFu15ll_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu15ll_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu15ll_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu15ll_BFu0i_B(Test_BFu15ll_BFu0i_B, "BFu15ll_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15ll_BFu0ll_B  {
  __tsu64 v1:15;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu15ll_BFu0ll_B) C1{ FL:15 FL:0 Fc}



static void Test_BFu15ll_BFu0ll_B()
{
  {
    init_simple_test("BFu15ll_BFu0ll_B");
    static BFu15ll_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu15ll_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu15ll_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu15ll_BFu0ll_B(Test_BFu15ll_BFu0ll_B, "BFu15ll_BFu0ll_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15ll_BFu0s_B  {
  __tsu64 v1:15;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu15ll_BFu0s_B) C1{ FL:15 Fs:0 Fc}



static void Test_BFu15ll_BFu0s_B()
{
  {
    init_simple_test("BFu15ll_BFu0s_B");
    static BFu15ll_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu15ll_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu15ll_BFu0s_B(Test_BFu15ll_BFu0s_B, "BFu15ll_BFu0s_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15s_B_BFu0c  {
  unsigned short v1:15;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu15s_B_BFu0c) C1{ Fs:15 Fc Fc:0}



static void Test_BFu15s_B_BFu0c()
{
  {
    init_simple_test("BFu15s_B_BFu0c");
    static BFu15s_B_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu15s_B_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(BFu15s_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_B_BFu0c");
    check_field_offset(lv, v2, 2, "BFu15s_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu15s_B_BFu0c(Test_BFu15s_B_BFu0c, "BFu15s_B_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15s_B_BFu0i  {
  unsigned short v1:15;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu15s_B_BFu0i) C1{ Fs:15 Fc Fi:0}



static void Test_BFu15s_B_BFu0i()
{
  {
    init_simple_test("BFu15s_B_BFu0i");
    static BFu15s_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu15s_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu15s_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_B_BFu0i");
    check_field_offset(lv, v2, 2, "BFu15s_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu15s_B_BFu0i(Test_BFu15s_B_BFu0i, "BFu15s_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15s_B_BFu0ll  {
  unsigned short v1:15;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu15s_B_BFu0ll) C1{ Fs:15 Fc FL:0}



static void Test_BFu15s_B_BFu0ll()
{
  {
    init_simple_test("BFu15s_B_BFu0ll");
    static BFu15s_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15s_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu15s_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_B_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu15s_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu15s_B_BFu0ll(Test_BFu15s_B_BFu0ll, "BFu15s_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15s_B_BFu0s  {
  unsigned short v1:15;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu15s_B_BFu0s) C1{ Fs:15 Fc Fs:0}



static void Test_BFu15s_B_BFu0s()
{
  {
    init_simple_test("BFu15s_B_BFu0s");
    static BFu15s_B_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu15s_B_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu15s_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_B_BFu0s");
    check_field_offset(lv, v2, 2, "BFu15s_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu15s_B_BFu0s(Test_BFu15s_B_BFu0s, "BFu15s_B_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15s_BFu0c_B  {
  unsigned short v1:15;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu15s_BFu0c_B) C1{ Fs:15 Fc:0 Fc}



static void Test_BFu15s_BFu0c_B()
{
  {
    init_simple_test("BFu15s_BFu0c_B");
    static BFu15s_BFu0c_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu15s_BFu0c_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu15s_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_BFu0c_B");
    check_field_offset(lv, v2, 2, "BFu15s_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu15s_BFu0c_B(Test_BFu15s_BFu0c_B, "BFu15s_BFu0c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15s_BFu0i_B  {
  unsigned short v1:15;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu15s_BFu0i_B) C1{ Fs:15 Fi:0 Fc}



static void Test_BFu15s_BFu0i_B()
{
  {
    init_simple_test("BFu15s_BFu0i_B");
    static BFu15s_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(BFu15s_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu15s_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu15s_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu15s_BFu0i_B(Test_BFu15s_BFu0i_B, "BFu15s_BFu0i_B", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15s_BFu0ll_B  {
  unsigned short v1:15;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu15s_BFu0ll_B) C1{ Fs:15 FL:0 Fc}



static void Test_BFu15s_BFu0ll_B()
{
  {
    init_simple_test("BFu15s_BFu0ll_B");
    static BFu15s_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(BFu15s_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu15s_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu15s_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu15s_BFu0ll_B(Test_BFu15s_BFu0ll_B, "BFu15s_BFu0ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu15s_BFu0s_B  {
  unsigned short v1:15;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu15s_BFu0s_B) C1{ Fs:15 Fs:0 Fc}



static void Test_BFu15s_BFu0s_B()
{
  {
    init_simple_test("BFu15s_BFu0s_B");
    static BFu15s_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu15s_BFu0s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu15s_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu15s_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu15s_BFu0s_B(Test_BFu15s_BFu0s_B, "BFu15s_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16i_B_BFu0c  {
  unsigned int v1:16;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu16i_B_BFu0c) C1{ Fi:16 Fc Fc:0}



static void Test_BFu16i_B_BFu0c()
{
  {
    init_simple_test("BFu16i_B_BFu0c");
    static BFu16i_B_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_B_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_B_BFu0c");
    check_field_offset(lv, v2, 2, "BFu16i_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu16i_B_BFu0c(Test_BFu16i_B_BFu0c, "BFu16i_B_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16i_B_BFu0i  {
  unsigned int v1:16;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu16i_B_BFu0i) C1{ Fi:16 Fc Fi:0}



static void Test_BFu16i_B_BFu0i()
{
  {
    init_simple_test("BFu16i_B_BFu0i");
    static BFu16i_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_B_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_B_BFu0i");
    check_field_offset(lv, v2, 2, "BFu16i_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu16i_B_BFu0i(Test_BFu16i_B_BFu0i, "BFu16i_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16i_B_BFu0ll  {
  unsigned int v1:16;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu16i_B_BFu0ll) C1{ Fi:16 Fc FL:0}



static void Test_BFu16i_B_BFu0ll()
{
  {
    init_simple_test("BFu16i_B_BFu0ll");
    static BFu16i_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16i_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu16i_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_B_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu16i_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu16i_B_BFu0ll(Test_BFu16i_B_BFu0ll, "BFu16i_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16i_B_BFu0s  {
  unsigned int v1:16;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu16i_B_BFu0s) C1{ Fi:16 Fc Fs:0}



static void Test_BFu16i_B_BFu0s()
{
  {
    init_simple_test("BFu16i_B_BFu0s");
    static BFu16i_B_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_B_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_B_BFu0s");
    check_field_offset(lv, v2, 2, "BFu16i_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu16i_B_BFu0s(Test_BFu16i_B_BFu0s, "BFu16i_B_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16i_BFu0c_B  {
  unsigned int v1:16;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu16i_BFu0c_B) C1{ Fi:16 Fc:0 Fc}



static void Test_BFu16i_BFu0c_B()
{
  {
    init_simple_test("BFu16i_BFu0c_B");
    static BFu16i_BFu0c_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_BFu0c_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_BFu0c_B");
    check_field_offset(lv, v2, 2, "BFu16i_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu16i_BFu0c_B(Test_BFu16i_BFu0c_B, "BFu16i_BFu0c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16i_BFu0i_B  {
  unsigned int v1:16;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu16i_BFu0i_B) C1{ Fi:16 Fi:0 Fc}



static void Test_BFu16i_BFu0i_B()
{
  {
    init_simple_test("BFu16i_BFu0i_B");
    static BFu16i_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu16i_BFu0i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu16i_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu16i_BFu0i_B(Test_BFu16i_BFu0i_B, "BFu16i_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16i_BFu0ll_B  {
  unsigned int v1:16;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu16i_BFu0ll_B) C1{ Fi:16 FL:0 Fc}



static void Test_BFu16i_BFu0ll_B()
{
  {
    init_simple_test("BFu16i_BFu0ll_B");
    static BFu16i_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(BFu16i_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu16i_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu16i_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu16i_BFu0ll_B(Test_BFu16i_BFu0ll_B, "BFu16i_BFu0ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16i_BFu0s_B  {
  unsigned int v1:16;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu16i_BFu0s_B) C1{ Fi:16 Fs:0 Fc}



static void Test_BFu16i_BFu0s_B()
{
  {
    init_simple_test("BFu16i_BFu0s_B");
    static BFu16i_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_BFu0s_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu16i_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu16i_BFu0s_B(Test_BFu16i_BFu0s_B, "BFu16i_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16ll_B_BFu0c  {
  __tsu64 v1:16;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu16ll_B_BFu0c) C1{ FL:16 Fc Fc:0}



static void Test_BFu16ll_B_BFu0c()
{
  {
    init_simple_test("BFu16ll_B_BFu0c");
    static BFu16ll_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_B_BFu0c");
    check_field_offset(lv, v2, 2, "BFu16ll_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu16ll_B_BFu0c(Test_BFu16ll_B_BFu0c, "BFu16ll_B_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16ll_B_BFu0i  {
  __tsu64 v1:16;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu16ll_B_BFu0i) C1{ FL:16 Fc Fi:0}



static void Test_BFu16ll_B_BFu0i()
{
  {
    init_simple_test("BFu16ll_B_BFu0i");
    static BFu16ll_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_B_BFu0i");
    check_field_offset(lv, v2, 2, "BFu16ll_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu16ll_B_BFu0i(Test_BFu16ll_B_BFu0i, "BFu16ll_B_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16ll_B_BFu0ll  {
  __tsu64 v1:16;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu16ll_B_BFu0ll) C1{ FL:16 Fc FL:0}



static void Test_BFu16ll_B_BFu0ll()
{
  {
    init_simple_test("BFu16ll_B_BFu0ll");
    static BFu16ll_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_B_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu16ll_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu16ll_B_BFu0ll(Test_BFu16ll_B_BFu0ll, "BFu16ll_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16ll_B_BFu0s  {
  __tsu64 v1:16;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu16ll_B_BFu0s) C1{ FL:16 Fc Fs:0}



static void Test_BFu16ll_B_BFu0s()
{
  {
    init_simple_test("BFu16ll_B_BFu0s");
    static BFu16ll_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_B_BFu0s");
    check_field_offset(lv, v2, 2, "BFu16ll_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu16ll_B_BFu0s(Test_BFu16ll_B_BFu0s, "BFu16ll_B_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16ll_BFu0c_B  {
  __tsu64 v1:16;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu16ll_BFu0c_B) C1{ FL:16 Fc:0 Fc}



static void Test_BFu16ll_BFu0c_B()
{
  {
    init_simple_test("BFu16ll_BFu0c_B");
    static BFu16ll_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_BFu0c_B");
    check_field_offset(lv, v2, 2, "BFu16ll_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu16ll_BFu0c_B(Test_BFu16ll_BFu0c_B, "BFu16ll_BFu0c_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16ll_BFu0i_B  {
  __tsu64 v1:16;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu16ll_BFu0i_B) C1{ FL:16 Fi:0 Fc}



static void Test_BFu16ll_BFu0i_B()
{
  {
    init_simple_test("BFu16ll_BFu0i_B");
    static BFu16ll_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu16ll_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu16ll_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu16ll_BFu0i_B(Test_BFu16ll_BFu0i_B, "BFu16ll_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16ll_BFu0ll_B  {
  __tsu64 v1:16;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu16ll_BFu0ll_B) C1{ FL:16 FL:0 Fc}



static void Test_BFu16ll_BFu0ll_B()
{
  {
    init_simple_test("BFu16ll_BFu0ll_B");
    static BFu16ll_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu16ll_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu16ll_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu16ll_BFu0ll_B(Test_BFu16ll_BFu0ll_B, "BFu16ll_BFu0ll_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16ll_BFu0s_B  {
  __tsu64 v1:16;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu16ll_BFu0s_B) C1{ FL:16 Fs:0 Fc}



static void Test_BFu16ll_BFu0s_B()
{
  {
    init_simple_test("BFu16ll_BFu0s_B");
    static BFu16ll_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu16ll_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu16ll_BFu0s_B(Test_BFu16ll_BFu0s_B, "BFu16ll_BFu0s_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16s_B_BFu0c  {
  unsigned short v1:16;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu16s_B_BFu0c) C1{ Fs:16 Fc Fc:0}



static void Test_BFu16s_B_BFu0c()
{
  {
    init_simple_test("BFu16s_B_BFu0c");
    static BFu16s_B_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu16s_B_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(BFu16s_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_B_BFu0c");
    check_field_offset(lv, v2, 2, "BFu16s_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu16s_B_BFu0c(Test_BFu16s_B_BFu0c, "BFu16s_B_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16s_B_BFu0i  {
  unsigned short v1:16;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu16s_B_BFu0i) C1{ Fs:16 Fc Fi:0}



static void Test_BFu16s_B_BFu0i()
{
  {
    init_simple_test("BFu16s_B_BFu0i");
    static BFu16s_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu16s_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu16s_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_B_BFu0i");
    check_field_offset(lv, v2, 2, "BFu16s_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu16s_B_BFu0i(Test_BFu16s_B_BFu0i, "BFu16s_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16s_B_BFu0ll  {
  unsigned short v1:16;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu16s_B_BFu0ll) C1{ Fs:16 Fc FL:0}



static void Test_BFu16s_B_BFu0ll()
{
  {
    init_simple_test("BFu16s_B_BFu0ll");
    static BFu16s_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16s_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu16s_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_B_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu16s_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu16s_B_BFu0ll(Test_BFu16s_B_BFu0ll, "BFu16s_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16s_B_BFu0s  {
  unsigned short v1:16;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu16s_B_BFu0s) C1{ Fs:16 Fc Fs:0}



static void Test_BFu16s_B_BFu0s()
{
  {
    init_simple_test("BFu16s_B_BFu0s");
    static BFu16s_B_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu16s_B_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu16s_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_B_BFu0s");
    check_field_offset(lv, v2, 2, "BFu16s_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu16s_B_BFu0s(Test_BFu16s_B_BFu0s, "BFu16s_B_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16s_BFu0c_B  {
  unsigned short v1:16;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu16s_BFu0c_B) C1{ Fs:16 Fc:0 Fc}



static void Test_BFu16s_BFu0c_B()
{
  {
    init_simple_test("BFu16s_BFu0c_B");
    static BFu16s_BFu0c_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu16s_BFu0c_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu16s_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_BFu0c_B");
    check_field_offset(lv, v2, 2, "BFu16s_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu16s_BFu0c_B(Test_BFu16s_BFu0c_B, "BFu16s_BFu0c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16s_BFu0i_B  {
  unsigned short v1:16;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu16s_BFu0i_B) C1{ Fs:16 Fi:0 Fc}



static void Test_BFu16s_BFu0i_B()
{
  {
    init_simple_test("BFu16s_BFu0i_B");
    static BFu16s_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(BFu16s_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu16s_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu16s_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu16s_BFu0i_B(Test_BFu16s_BFu0i_B, "BFu16s_BFu0i_B", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16s_BFu0ll_B  {
  unsigned short v1:16;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu16s_BFu0ll_B) C1{ Fs:16 FL:0 Fc}



static void Test_BFu16s_BFu0ll_B()
{
  {
    init_simple_test("BFu16s_BFu0ll_B");
    static BFu16s_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(BFu16s_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu16s_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu16s_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu16s_BFu0ll_B(Test_BFu16s_BFu0ll_B, "BFu16s_BFu0ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu16s_BFu0s_B  {
  unsigned short v1:16;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu16s_BFu0s_B) C1{ Fs:16 Fs:0 Fc}



static void Test_BFu16s_BFu0s_B()
{
  {
    init_simple_test("BFu16s_BFu0s_B");
    static BFu16s_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu16s_BFu0s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu16s_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu16s_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu16s_BFu0s_B(Test_BFu16s_BFu0s_B, "BFu16s_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17i_B_BFu0c  {
  unsigned int v1:17;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu17i_B_BFu0c) C1{ Fi:17 Fc Fc:0}



static void Test_BFu17i_B_BFu0c()
{
  {
    init_simple_test("BFu17i_B_BFu0c");
    static BFu17i_B_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu17i_B_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_B_BFu0c");
    check_field_offset(lv, v2, 3, "BFu17i_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu17i_B_BFu0c(Test_BFu17i_B_BFu0c, "BFu17i_B_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17i_B_BFu0i  {
  unsigned int v1:17;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu17i_B_BFu0i) C1{ Fi:17 Fc Fi:0}



static void Test_BFu17i_B_BFu0i()
{
  {
    init_simple_test("BFu17i_B_BFu0i");
    static BFu17i_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu17i_B_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_B_BFu0i");
    check_field_offset(lv, v2, 3, "BFu17i_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu17i_B_BFu0i(Test_BFu17i_B_BFu0i, "BFu17i_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17i_B_BFu0ll  {
  unsigned int v1:17;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu17i_B_BFu0ll) C1{ Fi:17 Fc FL:0}



static void Test_BFu17i_B_BFu0ll()
{
  {
    init_simple_test("BFu17i_B_BFu0ll");
    static BFu17i_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17i_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu17i_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_B_BFu0ll");
    check_field_offset(lv, v2, 3, "BFu17i_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu17i_B_BFu0ll(Test_BFu17i_B_BFu0ll, "BFu17i_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17i_B_BFu0s  {
  unsigned int v1:17;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu17i_B_BFu0s) C1{ Fi:17 Fc Fs:0}



static void Test_BFu17i_B_BFu0s()
{
  {
    init_simple_test("BFu17i_B_BFu0s");
    static BFu17i_B_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu17i_B_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_B_BFu0s");
    check_field_offset(lv, v2, 3, "BFu17i_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu17i_B_BFu0s(Test_BFu17i_B_BFu0s, "BFu17i_B_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17i_BFu0c_B  {
  unsigned int v1:17;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu17i_BFu0c_B) C1{ Fi:17 Fc:0 Fc}



static void Test_BFu17i_BFu0c_B()
{
  {
    init_simple_test("BFu17i_BFu0c_B");
    static BFu17i_BFu0c_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu17i_BFu0c_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_BFu0c_B");
    check_field_offset(lv, v2, 3, "BFu17i_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu17i_BFu0c_B(Test_BFu17i_BFu0c_B, "BFu17i_BFu0c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17i_BFu0i_B  {
  unsigned int v1:17;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu17i_BFu0i_B) C1{ Fi:17 Fi:0 Fc}



static void Test_BFu17i_BFu0i_B()
{
  {
    init_simple_test("BFu17i_BFu0i_B");
    static BFu17i_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu17i_BFu0i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu17i_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu17i_BFu0i_B(Test_BFu17i_BFu0i_B, "BFu17i_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17i_BFu0ll_B  {
  unsigned int v1:17;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu17i_BFu0ll_B) C1{ Fi:17 FL:0 Fc}



static void Test_BFu17i_BFu0ll_B()
{
  {
    init_simple_test("BFu17i_BFu0ll_B");
    static BFu17i_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(BFu17i_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu17i_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu17i_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu17i_BFu0ll_B(Test_BFu17i_BFu0ll_B, "BFu17i_BFu0ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17i_BFu0s_B  {
  unsigned int v1:17;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu17i_BFu0s_B) C1{ Fi:17 Fs:0 Fc}



static void Test_BFu17i_BFu0s_B()
{
  {
    init_simple_test("BFu17i_BFu0s_B");
    static BFu17i_BFu0s_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu17i_BFu0s_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_BFu0s_B");
    check_field_offset(lv, v2, 4, "BFu17i_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu17i_BFu0s_B(Test_BFu17i_BFu0s_B, "BFu17i_BFu0s_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17ll_B_BFu0c  {
  __tsu64 v1:17;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu17ll_B_BFu0c) C1{ FL:17 Fc Fc:0}



static void Test_BFu17ll_B_BFu0c()
{
  {
    init_simple_test("BFu17ll_B_BFu0c");
    static BFu17ll_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_B_BFu0c");
    check_field_offset(lv, v2, 3, "BFu17ll_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu17ll_B_BFu0c(Test_BFu17ll_B_BFu0c, "BFu17ll_B_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17ll_B_BFu0i  {
  __tsu64 v1:17;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu17ll_B_BFu0i) C1{ FL:17 Fc Fi:0}



static void Test_BFu17ll_B_BFu0i()
{
  {
    init_simple_test("BFu17ll_B_BFu0i");
    static BFu17ll_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_B_BFu0i");
    check_field_offset(lv, v2, 3, "BFu17ll_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu17ll_B_BFu0i(Test_BFu17ll_B_BFu0i, "BFu17ll_B_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17ll_B_BFu0ll  {
  __tsu64 v1:17;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu17ll_B_BFu0ll) C1{ FL:17 Fc FL:0}



static void Test_BFu17ll_B_BFu0ll()
{
  {
    init_simple_test("BFu17ll_B_BFu0ll");
    static BFu17ll_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_B_BFu0ll");
    check_field_offset(lv, v2, 3, "BFu17ll_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu17ll_B_BFu0ll(Test_BFu17ll_B_BFu0ll, "BFu17ll_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17ll_B_BFu0s  {
  __tsu64 v1:17;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu17ll_B_BFu0s) C1{ FL:17 Fc Fs:0}



static void Test_BFu17ll_B_BFu0s()
{
  {
    init_simple_test("BFu17ll_B_BFu0s");
    static BFu17ll_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_B_BFu0s");
    check_field_offset(lv, v2, 3, "BFu17ll_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu17ll_B_BFu0s(Test_BFu17ll_B_BFu0s, "BFu17ll_B_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17ll_BFu0c_B  {
  __tsu64 v1:17;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu17ll_BFu0c_B) C1{ FL:17 Fc:0 Fc}



static void Test_BFu17ll_BFu0c_B()
{
  {
    init_simple_test("BFu17ll_BFu0c_B");
    static BFu17ll_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_BFu0c_B");
    check_field_offset(lv, v2, 3, "BFu17ll_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu17ll_BFu0c_B(Test_BFu17ll_BFu0c_B, "BFu17ll_BFu0c_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17ll_BFu0i_B  {
  __tsu64 v1:17;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu17ll_BFu0i_B) C1{ FL:17 Fi:0 Fc}



static void Test_BFu17ll_BFu0i_B()
{
  {
    init_simple_test("BFu17ll_BFu0i_B");
    static BFu17ll_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu17ll_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu17ll_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu17ll_BFu0i_B(Test_BFu17ll_BFu0i_B, "BFu17ll_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17ll_BFu0ll_B  {
  __tsu64 v1:17;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu17ll_BFu0ll_B) C1{ FL:17 FL:0 Fc}



static void Test_BFu17ll_BFu0ll_B()
{
  {
    init_simple_test("BFu17ll_BFu0ll_B");
    static BFu17ll_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu17ll_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu17ll_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu17ll_BFu0ll_B(Test_BFu17ll_BFu0ll_B, "BFu17ll_BFu0ll_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu17ll_BFu0s_B  {
  __tsu64 v1:17;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu17ll_BFu0s_B) C1{ FL:17 Fs:0 Fc}



static void Test_BFu17ll_BFu0s_B()
{
  {
    init_simple_test("BFu17ll_BFu0s_B");
    static BFu17ll_BFu0s_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu17ll_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_BFu0s_B");
    check_field_offset(lv, v2, 4, "BFu17ll_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu17ll_BFu0s_B(Test_BFu17ll_BFu0s_B, "BFu17ll_BFu0s_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1c_B_BFu0c  {
  unsigned char v1:1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu1c_B_BFu0c) C1{ Fc:1 Fc Fc:0}



static void Test_BFu1c_B_BFu0c()
{
  {
    init_simple_test("BFu1c_B_BFu0c");
    static BFu1c_B_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(BFu1c_B_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1c_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_B_BFu0c");
    check_field_offset(lv, v2, 1, "BFu1c_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu1c_B_BFu0c(Test_BFu1c_B_BFu0c, "BFu1c_B_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1c_B_BFu0i  {
  unsigned char v1:1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu1c_B_BFu0i) C1{ Fc:1 Fc Fi:0}



static void Test_BFu1c_B_BFu0i()
{
  {
    init_simple_test("BFu1c_B_BFu0i");
    static BFu1c_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu1c_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu1c_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_B_BFu0i");
    check_field_offset(lv, v2, 1, "BFu1c_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu1c_B_BFu0i(Test_BFu1c_B_BFu0i, "BFu1c_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1c_B_BFu0ll  {
  unsigned char v1:1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu1c_B_BFu0ll) C1{ Fc:1 Fc FL:0}



static void Test_BFu1c_B_BFu0ll()
{
  {
    init_simple_test("BFu1c_B_BFu0ll");
    static BFu1c_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1c_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu1c_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_B_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu1c_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu1c_B_BFu0ll(Test_BFu1c_B_BFu0ll, "BFu1c_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1c_B_BFu0s  {
  unsigned char v1:1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu1c_B_BFu0s) C1{ Fc:1 Fc Fs:0}



static void Test_BFu1c_B_BFu0s()
{
  {
    init_simple_test("BFu1c_B_BFu0s");
    static BFu1c_B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu1c_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu1c_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_B_BFu0s");
    check_field_offset(lv, v2, 1, "BFu1c_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu1c_B_BFu0s(Test_BFu1c_B_BFu0s, "BFu1c_B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1c_BFu0c_B  {
  unsigned char v1:1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu1c_BFu0c_B) C1{ Fc:1 Fc:0 Fc}



static void Test_BFu1c_BFu0c_B()
{
  {
    init_simple_test("BFu1c_BFu0c_B");
    static BFu1c_BFu0c_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu1c_BFu0c_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1c_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_BFu0c_B");
    check_field_offset(lv, v2, 1, "BFu1c_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1c_BFu0c_B(Test_BFu1c_BFu0c_B, "BFu1c_BFu0c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1c_BFu0i_B  {
  unsigned char v1:1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu1c_BFu0i_B) C1{ Fc:1 Fi:0 Fc}



static void Test_BFu1c_BFu0i_B()
{
  {
    init_simple_test("BFu1c_BFu0i_B");
    static BFu1c_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(BFu1c_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu1c_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu1c_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1c_BFu0i_B(Test_BFu1c_BFu0i_B, "BFu1c_BFu0i_B", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1c_BFu0ll_B  {
  unsigned char v1:1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu1c_BFu0ll_B) C1{ Fc:1 FL:0 Fc}



static void Test_BFu1c_BFu0ll_B()
{
  {
    init_simple_test("BFu1c_BFu0ll_B");
    static BFu1c_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(BFu1c_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu1c_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu1c_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1c_BFu0ll_B(Test_BFu1c_BFu0ll_B, "BFu1c_BFu0ll_B", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1c_BFu0s_B  {
  unsigned char v1:1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu1c_BFu0s_B) C1{ Fc:1 Fs:0 Fc}



static void Test_BFu1c_BFu0s_B()
{
  {
    init_simple_test("BFu1c_BFu0s_B");
    static BFu1c_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(BFu1c_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu1c_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu1c_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1c_BFu0s_B(Test_BFu1c_BFu0s_B, "BFu1c_BFu0s_B", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1i_B_BFu0c  {
  unsigned int v1:1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu1i_B_BFu0c) C1{ Fi:1 Fc Fc:0}



static void Test_BFu1i_B_BFu0c()
{
  {
    init_simple_test("BFu1i_B_BFu0c");
    static BFu1i_B_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_B_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_B_BFu0c");
    check_field_offset(lv, v2, 1, "BFu1i_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu1i_B_BFu0c(Test_BFu1i_B_BFu0c, "BFu1i_B_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1i_B_BFu0i  {
  unsigned int v1:1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu1i_B_BFu0i) C1{ Fi:1 Fc Fi:0}



static void Test_BFu1i_B_BFu0i()
{
  {
    init_simple_test("BFu1i_B_BFu0i");
    static BFu1i_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_B_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_B_BFu0i");
    check_field_offset(lv, v2, 1, "BFu1i_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu1i_B_BFu0i(Test_BFu1i_B_BFu0i, "BFu1i_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1i_B_BFu0ll  {
  unsigned int v1:1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu1i_B_BFu0ll) C1{ Fi:1 Fc FL:0}



static void Test_BFu1i_B_BFu0ll()
{
  {
    init_simple_test("BFu1i_B_BFu0ll");
    static BFu1i_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1i_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu1i_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_B_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu1i_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu1i_B_BFu0ll(Test_BFu1i_B_BFu0ll, "BFu1i_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1i_B_BFu0s  {
  unsigned int v1:1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu1i_B_BFu0s) C1{ Fi:1 Fc Fs:0}



static void Test_BFu1i_B_BFu0s()
{
  {
    init_simple_test("BFu1i_B_BFu0s");
    static BFu1i_B_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_B_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_B_BFu0s");
    check_field_offset(lv, v2, 1, "BFu1i_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu1i_B_BFu0s(Test_BFu1i_B_BFu0s, "BFu1i_B_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1i_BFu0c_B  {
  unsigned int v1:1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu1i_BFu0c_B) C1{ Fi:1 Fc:0 Fc}



static void Test_BFu1i_BFu0c_B()
{
  {
    init_simple_test("BFu1i_BFu0c_B");
    static BFu1i_BFu0c_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_BFu0c_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_BFu0c_B");
    check_field_offset(lv, v2, 1, "BFu1i_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1i_BFu0c_B(Test_BFu1i_BFu0c_B, "BFu1i_BFu0c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1i_BFu0i_B  {
  unsigned int v1:1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu1i_BFu0i_B) C1{ Fi:1 Fi:0 Fc}



static void Test_BFu1i_BFu0i_B()
{
  {
    init_simple_test("BFu1i_BFu0i_B");
    static BFu1i_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu1i_BFu0i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu1i_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1i_BFu0i_B(Test_BFu1i_BFu0i_B, "BFu1i_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1i_BFu0ll_B  {
  unsigned int v1:1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu1i_BFu0ll_B) C1{ Fi:1 FL:0 Fc}



static void Test_BFu1i_BFu0ll_B()
{
  {
    init_simple_test("BFu1i_BFu0ll_B");
    static BFu1i_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(BFu1i_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu1i_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu1i_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1i_BFu0ll_B(Test_BFu1i_BFu0ll_B, "BFu1i_BFu0ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1i_BFu0s_B  {
  unsigned int v1:1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu1i_BFu0s_B) C1{ Fi:1 Fs:0 Fc}



static void Test_BFu1i_BFu0s_B()
{
  {
    init_simple_test("BFu1i_BFu0s_B");
    static BFu1i_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_BFu0s_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu1i_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1i_BFu0s_B(Test_BFu1i_BFu0s_B, "BFu1i_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1ll_B_BFu0c  {
  __tsu64 v1:1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu1ll_B_BFu0c) C1{ FL:1 Fc Fc:0}



static void Test_BFu1ll_B_BFu0c()
{
  {
    init_simple_test("BFu1ll_B_BFu0c");
    static BFu1ll_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_B_BFu0c");
    check_field_offset(lv, v2, 1, "BFu1ll_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu1ll_B_BFu0c(Test_BFu1ll_B_BFu0c, "BFu1ll_B_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1ll_B_BFu0i  {
  __tsu64 v1:1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu1ll_B_BFu0i) C1{ FL:1 Fc Fi:0}



static void Test_BFu1ll_B_BFu0i()
{
  {
    init_simple_test("BFu1ll_B_BFu0i");
    static BFu1ll_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_B_BFu0i");
    check_field_offset(lv, v2, 1, "BFu1ll_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu1ll_B_BFu0i(Test_BFu1ll_B_BFu0i, "BFu1ll_B_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1ll_B_BFu0ll  {
  __tsu64 v1:1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu1ll_B_BFu0ll) C1{ FL:1 Fc FL:0}



static void Test_BFu1ll_B_BFu0ll()
{
  {
    init_simple_test("BFu1ll_B_BFu0ll");
    static BFu1ll_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_B_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu1ll_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu1ll_B_BFu0ll(Test_BFu1ll_B_BFu0ll, "BFu1ll_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1ll_B_BFu0s  {
  __tsu64 v1:1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu1ll_B_BFu0s) C1{ FL:1 Fc Fs:0}



static void Test_BFu1ll_B_BFu0s()
{
  {
    init_simple_test("BFu1ll_B_BFu0s");
    static BFu1ll_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_B_BFu0s");
    check_field_offset(lv, v2, 1, "BFu1ll_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu1ll_B_BFu0s(Test_BFu1ll_B_BFu0s, "BFu1ll_B_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1ll_BFu0c_B  {
  __tsu64 v1:1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu1ll_BFu0c_B) C1{ FL:1 Fc:0 Fc}



static void Test_BFu1ll_BFu0c_B()
{
  {
    init_simple_test("BFu1ll_BFu0c_B");
    static BFu1ll_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_BFu0c_B");
    check_field_offset(lv, v2, 1, "BFu1ll_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1ll_BFu0c_B(Test_BFu1ll_BFu0c_B, "BFu1ll_BFu0c_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1ll_BFu0i_B  {
  __tsu64 v1:1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu1ll_BFu0i_B) C1{ FL:1 Fi:0 Fc}



static void Test_BFu1ll_BFu0i_B()
{
  {
    init_simple_test("BFu1ll_BFu0i_B");
    static BFu1ll_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu1ll_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu1ll_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1ll_BFu0i_B(Test_BFu1ll_BFu0i_B, "BFu1ll_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1ll_BFu0ll_B  {
  __tsu64 v1:1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu1ll_BFu0ll_B) C1{ FL:1 FL:0 Fc}



static void Test_BFu1ll_BFu0ll_B()
{
  {
    init_simple_test("BFu1ll_BFu0ll_B");
    static BFu1ll_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu1ll_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu1ll_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1ll_BFu0ll_B(Test_BFu1ll_BFu0ll_B, "BFu1ll_BFu0ll_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1ll_BFu0s_B  {
  __tsu64 v1:1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu1ll_BFu0s_B) C1{ FL:1 Fs:0 Fc}



static void Test_BFu1ll_BFu0s_B()
{
  {
    init_simple_test("BFu1ll_BFu0s_B");
    static BFu1ll_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu1ll_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1ll_BFu0s_B(Test_BFu1ll_BFu0s_B, "BFu1ll_BFu0s_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1s_B_BFu0c  {
  unsigned short v1:1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu1s_B_BFu0c) C1{ Fs:1 Fc Fc:0}



static void Test_BFu1s_B_BFu0c()
{
  {
    init_simple_test("BFu1s_B_BFu0c");
    static BFu1s_B_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(BFu1s_B_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(BFu1s_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_B_BFu0c");
    check_field_offset(lv, v2, 1, "BFu1s_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu1s_B_BFu0c(Test_BFu1s_B_BFu0c, "BFu1s_B_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1s_B_BFu0i  {
  unsigned short v1:1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu1s_B_BFu0i) C1{ Fs:1 Fc Fi:0}



static void Test_BFu1s_B_BFu0i()
{
  {
    init_simple_test("BFu1s_B_BFu0i");
    static BFu1s_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu1s_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu1s_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_B_BFu0i");
    check_field_offset(lv, v2, 1, "BFu1s_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu1s_B_BFu0i(Test_BFu1s_B_BFu0i, "BFu1s_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1s_B_BFu0ll  {
  unsigned short v1:1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu1s_B_BFu0ll) C1{ Fs:1 Fc FL:0}



static void Test_BFu1s_B_BFu0ll()
{
  {
    init_simple_test("BFu1s_B_BFu0ll");
    static BFu1s_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1s_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu1s_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_B_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu1s_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu1s_B_BFu0ll(Test_BFu1s_B_BFu0ll, "BFu1s_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1s_B_BFu0s  {
  unsigned short v1:1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu1s_B_BFu0s) C1{ Fs:1 Fc Fs:0}



static void Test_BFu1s_B_BFu0s()
{
  {
    init_simple_test("BFu1s_B_BFu0s");
    static BFu1s_B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu1s_B_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu1s_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_B_BFu0s");
    check_field_offset(lv, v2, 1, "BFu1s_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu1s_B_BFu0s(Test_BFu1s_B_BFu0s, "BFu1s_B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1s_BFu0c_B  {
  unsigned short v1:1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu1s_BFu0c_B) C1{ Fs:1 Fc:0 Fc}



static void Test_BFu1s_BFu0c_B()
{
  {
    init_simple_test("BFu1s_BFu0c_B");
    static BFu1s_BFu0c_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu1s_BFu0c_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu1s_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_BFu0c_B");
    check_field_offset(lv, v2, 1, "BFu1s_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1s_BFu0c_B(Test_BFu1s_BFu0c_B, "BFu1s_BFu0c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1s_BFu0i_B  {
  unsigned short v1:1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu1s_BFu0i_B) C1{ Fs:1 Fi:0 Fc}



static void Test_BFu1s_BFu0i_B()
{
  {
    init_simple_test("BFu1s_BFu0i_B");
    static BFu1s_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(BFu1s_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu1s_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu1s_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1s_BFu0i_B(Test_BFu1s_BFu0i_B, "BFu1s_BFu0i_B", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1s_BFu0ll_B  {
  unsigned short v1:1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu1s_BFu0ll_B) C1{ Fs:1 FL:0 Fc}



static void Test_BFu1s_BFu0ll_B()
{
  {
    init_simple_test("BFu1s_BFu0ll_B");
    static BFu1s_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(BFu1s_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu1s_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu1s_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1s_BFu0ll_B(Test_BFu1s_BFu0ll_B, "BFu1s_BFu0ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu1s_BFu0s_B  {
  unsigned short v1:1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu1s_BFu0s_B) C1{ Fs:1 Fs:0 Fc}



static void Test_BFu1s_BFu0s_B()
{
  {
    init_simple_test("BFu1s_BFu0s_B");
    static BFu1s_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu1s_BFu0s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu1s_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu1s_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu1s_BFu0s_B(Test_BFu1s_BFu0s_B, "BFu1s_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31i_B_BFu0c  {
  unsigned int v1:31;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu31i_B_BFu0c) C1{ Fi:31 Fc Fc:0}



static void Test_BFu31i_B_BFu0c()
{
  {
    init_simple_test("BFu31i_B_BFu0c");
    static BFu31i_B_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(BFu31i_B_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_B_BFu0c");
    check_field_offset(lv, v2, 4, "BFu31i_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu31i_B_BFu0c(Test_BFu31i_B_BFu0c, "BFu31i_B_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31i_B_BFu0i  {
  unsigned int v1:31;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu31i_B_BFu0i) C1{ Fi:31 Fc Fi:0}



static void Test_BFu31i_B_BFu0i()
{
  {
    init_simple_test("BFu31i_B_BFu0i");
    static BFu31i_B_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(BFu31i_B_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_B_BFu0i");
    check_field_offset(lv, v2, 4, "BFu31i_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu31i_B_BFu0i(Test_BFu31i_B_BFu0i, "BFu31i_B_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31i_B_BFu0ll  {
  unsigned int v1:31;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu31i_B_BFu0ll) C1{ Fi:31 Fc FL:0}



static void Test_BFu31i_B_BFu0ll()
{
  {
    init_simple_test("BFu31i_B_BFu0ll");
    static BFu31i_B_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu31i_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu31i_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_B_BFu0ll");
    check_field_offset(lv, v2, 4, "BFu31i_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu31i_B_BFu0ll(Test_BFu31i_B_BFu0ll, "BFu31i_B_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31i_B_BFu0s  {
  unsigned int v1:31;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu31i_B_BFu0s) C1{ Fi:31 Fc Fs:0}



static void Test_BFu31i_B_BFu0s()
{
  {
    init_simple_test("BFu31i_B_BFu0s");
    static BFu31i_B_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(BFu31i_B_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_B_BFu0s");
    check_field_offset(lv, v2, 4, "BFu31i_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu31i_B_BFu0s(Test_BFu31i_B_BFu0s, "BFu31i_B_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31i_BFu0c_B  {
  unsigned int v1:31;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu31i_BFu0c_B) C1{ Fi:31 Fc:0 Fc}



static void Test_BFu31i_BFu0c_B()
{
  {
    init_simple_test("BFu31i_BFu0c_B");
    static BFu31i_BFu0c_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu31i_BFu0c_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_BFu0c_B");
    check_field_offset(lv, v2, 4, "BFu31i_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu31i_BFu0c_B(Test_BFu31i_BFu0c_B, "BFu31i_BFu0c_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31i_BFu0i_B  {
  unsigned int v1:31;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu31i_BFu0i_B) C1{ Fi:31 Fi:0 Fc}



static void Test_BFu31i_BFu0i_B()
{
  {
    init_simple_test("BFu31i_BFu0i_B");
    static BFu31i_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu31i_BFu0i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu31i_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu31i_BFu0i_B(Test_BFu31i_BFu0i_B, "BFu31i_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31i_BFu0ll_B  {
  unsigned int v1:31;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu31i_BFu0ll_B) C1{ Fi:31 FL:0 Fc}



static void Test_BFu31i_BFu0ll_B()
{
  {
    init_simple_test("BFu31i_BFu0ll_B");
    static BFu31i_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(BFu31i_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu31i_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu31i_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu31i_BFu0ll_B(Test_BFu31i_BFu0ll_B, "BFu31i_BFu0ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31i_BFu0s_B  {
  unsigned int v1:31;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu31i_BFu0s_B) C1{ Fi:31 Fs:0 Fc}



static void Test_BFu31i_BFu0s_B()
{
  {
    init_simple_test("BFu31i_BFu0s_B");
    static BFu31i_BFu0s_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu31i_BFu0s_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_BFu0s_B");
    check_field_offset(lv, v2, 4, "BFu31i_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu31i_BFu0s_B(Test_BFu31i_BFu0s_B, "BFu31i_BFu0s_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31ll_B_BFu0c  {
  __tsu64 v1:31;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu31ll_B_BFu0c) C1{ FL:31 Fc Fc:0}



static void Test_BFu31ll_B_BFu0c()
{
  {
    init_simple_test("BFu31ll_B_BFu0c");
    static BFu31ll_B_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(BFu31ll_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_B_BFu0c");
    check_field_offset(lv, v2, 4, "BFu31ll_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu31ll_B_BFu0c(Test_BFu31ll_B_BFu0c, "BFu31ll_B_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31ll_B_BFu0i  {
  __tsu64 v1:31;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu31ll_B_BFu0i) C1{ FL:31 Fc Fi:0}



static void Test_BFu31ll_B_BFu0i()
{
  {
    init_simple_test("BFu31ll_B_BFu0i");
    static BFu31ll_B_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(BFu31ll_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_B_BFu0i");
    check_field_offset(lv, v2, 4, "BFu31ll_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu31ll_B_BFu0i(Test_BFu31ll_B_BFu0i, "BFu31ll_B_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31ll_B_BFu0ll  {
  __tsu64 v1:31;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu31ll_B_BFu0ll) C1{ FL:31 Fc FL:0}



static void Test_BFu31ll_B_BFu0ll()
{
  {
    init_simple_test("BFu31ll_B_BFu0ll");
    static BFu31ll_B_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu31ll_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_B_BFu0ll");
    check_field_offset(lv, v2, 4, "BFu31ll_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu31ll_B_BFu0ll(Test_BFu31ll_B_BFu0ll, "BFu31ll_B_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31ll_B_BFu0s  {
  __tsu64 v1:31;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu31ll_B_BFu0s) C1{ FL:31 Fc Fs:0}



static void Test_BFu31ll_B_BFu0s()
{
  {
    init_simple_test("BFu31ll_B_BFu0s");
    static BFu31ll_B_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(BFu31ll_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_B_BFu0s");
    check_field_offset(lv, v2, 4, "BFu31ll_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu31ll_B_BFu0s(Test_BFu31ll_B_BFu0s, "BFu31ll_B_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31ll_BFu0c_B  {
  __tsu64 v1:31;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu31ll_BFu0c_B) C1{ FL:31 Fc:0 Fc}



static void Test_BFu31ll_BFu0c_B()
{
  {
    init_simple_test("BFu31ll_BFu0c_B");
    static BFu31ll_BFu0c_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu31ll_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_BFu0c_B");
    check_field_offset(lv, v2, 4, "BFu31ll_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu31ll_BFu0c_B(Test_BFu31ll_BFu0c_B, "BFu31ll_BFu0c_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31ll_BFu0i_B  {
  __tsu64 v1:31;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu31ll_BFu0i_B) C1{ FL:31 Fi:0 Fc}



static void Test_BFu31ll_BFu0i_B()
{
  {
    init_simple_test("BFu31ll_BFu0i_B");
    static BFu31ll_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu31ll_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu31ll_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu31ll_BFu0i_B(Test_BFu31ll_BFu0i_B, "BFu31ll_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31ll_BFu0ll_B  {
  __tsu64 v1:31;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu31ll_BFu0ll_B) C1{ FL:31 FL:0 Fc}



static void Test_BFu31ll_BFu0ll_B()
{
  {
    init_simple_test("BFu31ll_BFu0ll_B");
    static BFu31ll_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu31ll_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu31ll_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu31ll_BFu0ll_B(Test_BFu31ll_BFu0ll_B, "BFu31ll_BFu0ll_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu31ll_BFu0s_B  {
  __tsu64 v1:31;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu31ll_BFu0s_B) C1{ FL:31 Fs:0 Fc}



static void Test_BFu31ll_BFu0s_B()
{
  {
    init_simple_test("BFu31ll_BFu0s_B");
    static BFu31ll_BFu0s_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu31ll_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_BFu0s_B");
    check_field_offset(lv, v2, 4, "BFu31ll_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu31ll_BFu0s_B(Test_BFu31ll_BFu0s_B, "BFu31ll_BFu0s_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32i_B_BFu0c  {
  unsigned int v1:32;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu32i_B_BFu0c) C1{ Fi:32 Fc Fc:0}



static void Test_BFu32i_B_BFu0c()
{
  {
    init_simple_test("BFu32i_B_BFu0c");
    static BFu32i_B_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(BFu32i_B_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_B_BFu0c");
    check_field_offset(lv, v2, 4, "BFu32i_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu32i_B_BFu0c(Test_BFu32i_B_BFu0c, "BFu32i_B_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32i_B_BFu0i  {
  unsigned int v1:32;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu32i_B_BFu0i) C1{ Fi:32 Fc Fi:0}



static void Test_BFu32i_B_BFu0i()
{
  {
    init_simple_test("BFu32i_B_BFu0i");
    static BFu32i_B_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(BFu32i_B_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_B_BFu0i");
    check_field_offset(lv, v2, 4, "BFu32i_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu32i_B_BFu0i(Test_BFu32i_B_BFu0i, "BFu32i_B_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32i_B_BFu0ll  {
  unsigned int v1:32;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu32i_B_BFu0ll) C1{ Fi:32 Fc FL:0}



static void Test_BFu32i_B_BFu0ll()
{
  {
    init_simple_test("BFu32i_B_BFu0ll");
    static BFu32i_B_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu32i_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu32i_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_B_BFu0ll");
    check_field_offset(lv, v2, 4, "BFu32i_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu32i_B_BFu0ll(Test_BFu32i_B_BFu0ll, "BFu32i_B_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32i_B_BFu0s  {
  unsigned int v1:32;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu32i_B_BFu0s) C1{ Fi:32 Fc Fs:0}



static void Test_BFu32i_B_BFu0s()
{
  {
    init_simple_test("BFu32i_B_BFu0s");
    static BFu32i_B_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(BFu32i_B_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_B_BFu0s");
    check_field_offset(lv, v2, 4, "BFu32i_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu32i_B_BFu0s(Test_BFu32i_B_BFu0s, "BFu32i_B_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32i_BFu0c_B  {
  unsigned int v1:32;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu32i_BFu0c_B) C1{ Fi:32 Fc:0 Fc}



static void Test_BFu32i_BFu0c_B()
{
  {
    init_simple_test("BFu32i_BFu0c_B");
    static BFu32i_BFu0c_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu32i_BFu0c_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_BFu0c_B");
    check_field_offset(lv, v2, 4, "BFu32i_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu32i_BFu0c_B(Test_BFu32i_BFu0c_B, "BFu32i_BFu0c_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32i_BFu0i_B  {
  unsigned int v1:32;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu32i_BFu0i_B) C1{ Fi:32 Fi:0 Fc}



static void Test_BFu32i_BFu0i_B()
{
  {
    init_simple_test("BFu32i_BFu0i_B");
    static BFu32i_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu32i_BFu0i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu32i_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu32i_BFu0i_B(Test_BFu32i_BFu0i_B, "BFu32i_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32i_BFu0ll_B  {
  unsigned int v1:32;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu32i_BFu0ll_B) C1{ Fi:32 FL:0 Fc}



static void Test_BFu32i_BFu0ll_B()
{
  {
    init_simple_test("BFu32i_BFu0ll_B");
    static BFu32i_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(BFu32i_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu32i_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu32i_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu32i_BFu0ll_B(Test_BFu32i_BFu0ll_B, "BFu32i_BFu0ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32i_BFu0s_B  {
  unsigned int v1:32;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu32i_BFu0s_B) C1{ Fi:32 Fs:0 Fc}



static void Test_BFu32i_BFu0s_B()
{
  {
    init_simple_test("BFu32i_BFu0s_B");
    static BFu32i_BFu0s_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu32i_BFu0s_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_BFu0s_B");
    check_field_offset(lv, v2, 4, "BFu32i_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu32i_BFu0s_B(Test_BFu32i_BFu0s_B, "BFu32i_BFu0s_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32ll_B_BFu0c  {
  __tsu64 v1:32;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu32ll_B_BFu0c) C1{ FL:32 Fc Fc:0}



static void Test_BFu32ll_B_BFu0c()
{
  {
    init_simple_test("BFu32ll_B_BFu0c");
    static BFu32ll_B_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(BFu32ll_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_B_BFu0c");
    check_field_offset(lv, v2, 4, "BFu32ll_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu32ll_B_BFu0c(Test_BFu32ll_B_BFu0c, "BFu32ll_B_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32ll_B_BFu0i  {
  __tsu64 v1:32;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu32ll_B_BFu0i) C1{ FL:32 Fc Fi:0}



static void Test_BFu32ll_B_BFu0i()
{
  {
    init_simple_test("BFu32ll_B_BFu0i");
    static BFu32ll_B_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(BFu32ll_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_B_BFu0i");
    check_field_offset(lv, v2, 4, "BFu32ll_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu32ll_B_BFu0i(Test_BFu32ll_B_BFu0i, "BFu32ll_B_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32ll_B_BFu0ll  {
  __tsu64 v1:32;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu32ll_B_BFu0ll) C1{ FL:32 Fc FL:0}



static void Test_BFu32ll_B_BFu0ll()
{
  {
    init_simple_test("BFu32ll_B_BFu0ll");
    static BFu32ll_B_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu32ll_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_B_BFu0ll");
    check_field_offset(lv, v2, 4, "BFu32ll_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu32ll_B_BFu0ll(Test_BFu32ll_B_BFu0ll, "BFu32ll_B_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32ll_B_BFu0s  {
  __tsu64 v1:32;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu32ll_B_BFu0s) C1{ FL:32 Fc Fs:0}



static void Test_BFu32ll_B_BFu0s()
{
  {
    init_simple_test("BFu32ll_B_BFu0s");
    static BFu32ll_B_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(BFu32ll_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_B_BFu0s");
    check_field_offset(lv, v2, 4, "BFu32ll_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu32ll_B_BFu0s(Test_BFu32ll_B_BFu0s, "BFu32ll_B_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32ll_BFu0c_B  {
  __tsu64 v1:32;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu32ll_BFu0c_B) C1{ FL:32 Fc:0 Fc}



static void Test_BFu32ll_BFu0c_B()
{
  {
    init_simple_test("BFu32ll_BFu0c_B");
    static BFu32ll_BFu0c_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu32ll_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_BFu0c_B");
    check_field_offset(lv, v2, 4, "BFu32ll_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu32ll_BFu0c_B(Test_BFu32ll_BFu0c_B, "BFu32ll_BFu0c_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32ll_BFu0i_B  {
  __tsu64 v1:32;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu32ll_BFu0i_B) C1{ FL:32 Fi:0 Fc}



static void Test_BFu32ll_BFu0i_B()
{
  {
    init_simple_test("BFu32ll_BFu0i_B");
    static BFu32ll_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu32ll_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu32ll_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu32ll_BFu0i_B(Test_BFu32ll_BFu0i_B, "BFu32ll_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32ll_BFu0ll_B  {
  __tsu64 v1:32;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu32ll_BFu0ll_B) C1{ FL:32 FL:0 Fc}



static void Test_BFu32ll_BFu0ll_B()
{
  {
    init_simple_test("BFu32ll_BFu0ll_B");
    static BFu32ll_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu32ll_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu32ll_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu32ll_BFu0ll_B(Test_BFu32ll_BFu0ll_B, "BFu32ll_BFu0ll_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu32ll_BFu0s_B  {
  __tsu64 v1:32;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu32ll_BFu0s_B) C1{ FL:32 Fs:0 Fc}



static void Test_BFu32ll_BFu0s_B()
{
  {
    init_simple_test("BFu32ll_BFu0s_B");
    static BFu32ll_BFu0s_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu32ll_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_BFu0s_B");
    check_field_offset(lv, v2, 4, "BFu32ll_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu32ll_BFu0s_B(Test_BFu32ll_BFu0s_B, "BFu32ll_BFu0s_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu33_B_BFu0c  {
  __tsu64 v1:33;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu33_B_BFu0c) C1{ FL:33 Fc Fc:0}



static void Test_BFu33_B_BFu0c()
{
  {
    init_simple_test("BFu33_B_BFu0c");
    static BFu33_B_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_B_BFu0c");
    check_field_offset(lv, v2, 5, "BFu33_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu33_B_BFu0c(Test_BFu33_B_BFu0c, "BFu33_B_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu33_B_BFu0i  {
  __tsu64 v1:33;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu33_B_BFu0i) C1{ FL:33 Fc Fi:0}



static void Test_BFu33_B_BFu0i()
{
  {
    init_simple_test("BFu33_B_BFu0i");
    static BFu33_B_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_B_BFu0i");
    check_field_offset(lv, v2, 5, "BFu33_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu33_B_BFu0i(Test_BFu33_B_BFu0i, "BFu33_B_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu33_B_BFu0ll  {
  __tsu64 v1:33;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu33_B_BFu0ll) C1{ FL:33 Fc FL:0}



static void Test_BFu33_B_BFu0ll()
{
  {
    init_simple_test("BFu33_B_BFu0ll");
    static BFu33_B_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_B_BFu0ll");
    check_field_offset(lv, v2, 5, "BFu33_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu33_B_BFu0ll(Test_BFu33_B_BFu0ll, "BFu33_B_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu33_B_BFu0s  {
  __tsu64 v1:33;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu33_B_BFu0s) C1{ FL:33 Fc Fs:0}



static void Test_BFu33_B_BFu0s()
{
  {
    init_simple_test("BFu33_B_BFu0s");
    static BFu33_B_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_B_BFu0s");
    check_field_offset(lv, v2, 5, "BFu33_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu33_B_BFu0s(Test_BFu33_B_BFu0s, "BFu33_B_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu33_BFu0c_B  {
  __tsu64 v1:33;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu33_BFu0c_B) C1{ FL:33 Fc:0 Fc}



static void Test_BFu33_BFu0c_B()
{
  {
    init_simple_test("BFu33_BFu0c_B");
    static BFu33_BFu0c_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_BFu0c_B");
    check_field_offset(lv, v2, 5, "BFu33_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu33_BFu0c_B(Test_BFu33_BFu0c_B, "BFu33_BFu0c_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu33_BFu0i_B  {
  __tsu64 v1:33;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu33_BFu0i_B) C1{ FL:33 Fi:0 Fc}



static void Test_BFu33_BFu0i_B()
{
  {
    init_simple_test("BFu33_BFu0i_B");
    static BFu33_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu33_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_BFu0i_B");
    check_field_offset(lv, v2, 8, "BFu33_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu33_BFu0i_B(Test_BFu33_BFu0i_B, "BFu33_BFu0i_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu33_BFu0ll_B  {
  __tsu64 v1:33;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu33_BFu0ll_B) C1{ FL:33 FL:0 Fc}



static void Test_BFu33_BFu0ll_B()
{
  {
    init_simple_test("BFu33_BFu0ll_B");
    static BFu33_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(BFu33_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_BFu0ll_B");
    check_field_offset(lv, v2, 8, "BFu33_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu33_BFu0ll_B(Test_BFu33_BFu0ll_B, "BFu33_BFu0ll_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu33_BFu0s_B  {
  __tsu64 v1:33;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu33_BFu0s_B) C1{ FL:33 Fs:0 Fc}



static void Test_BFu33_BFu0s_B()
{
  {
    init_simple_test("BFu33_BFu0s_B");
    static BFu33_BFu0s_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_BFu0s_B");
    check_field_offset(lv, v2, 6, "BFu33_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu33_BFu0s_B(Test_BFu33_BFu0s_B, "BFu33_BFu0s_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7c_B_BFu0c  {
  unsigned char v1:7;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu7c_B_BFu0c) C1{ Fc:7 Fc Fc:0}



static void Test_BFu7c_B_BFu0c()
{
  {
    init_simple_test("BFu7c_B_BFu0c");
    static BFu7c_B_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(BFu7c_B_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7c_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_B_BFu0c");
    check_field_offset(lv, v2, 1, "BFu7c_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu7c_B_BFu0c(Test_BFu7c_B_BFu0c, "BFu7c_B_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7c_B_BFu0i  {
  unsigned char v1:7;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu7c_B_BFu0i) C1{ Fc:7 Fc Fi:0}



static void Test_BFu7c_B_BFu0i()
{
  {
    init_simple_test("BFu7c_B_BFu0i");
    static BFu7c_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu7c_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu7c_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_B_BFu0i");
    check_field_offset(lv, v2, 1, "BFu7c_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu7c_B_BFu0i(Test_BFu7c_B_BFu0i, "BFu7c_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7c_B_BFu0ll  {
  unsigned char v1:7;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu7c_B_BFu0ll) C1{ Fc:7 Fc FL:0}



static void Test_BFu7c_B_BFu0ll()
{
  {
    init_simple_test("BFu7c_B_BFu0ll");
    static BFu7c_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7c_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu7c_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_B_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu7c_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu7c_B_BFu0ll(Test_BFu7c_B_BFu0ll, "BFu7c_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7c_B_BFu0s  {
  unsigned char v1:7;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu7c_B_BFu0s) C1{ Fc:7 Fc Fs:0}



static void Test_BFu7c_B_BFu0s()
{
  {
    init_simple_test("BFu7c_B_BFu0s");
    static BFu7c_B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu7c_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu7c_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_B_BFu0s");
    check_field_offset(lv, v2, 1, "BFu7c_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu7c_B_BFu0s(Test_BFu7c_B_BFu0s, "BFu7c_B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7c_BFu0c_B  {
  unsigned char v1:7;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu7c_BFu0c_B) C1{ Fc:7 Fc:0 Fc}



static void Test_BFu7c_BFu0c_B()
{
  {
    init_simple_test("BFu7c_BFu0c_B");
    static BFu7c_BFu0c_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu7c_BFu0c_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7c_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_BFu0c_B");
    check_field_offset(lv, v2, 1, "BFu7c_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7c_BFu0c_B(Test_BFu7c_BFu0c_B, "BFu7c_BFu0c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7c_BFu0i_B  {
  unsigned char v1:7;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu7c_BFu0i_B) C1{ Fc:7 Fi:0 Fc}



static void Test_BFu7c_BFu0i_B()
{
  {
    init_simple_test("BFu7c_BFu0i_B");
    static BFu7c_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(BFu7c_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu7c_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu7c_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7c_BFu0i_B(Test_BFu7c_BFu0i_B, "BFu7c_BFu0i_B", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7c_BFu0ll_B  {
  unsigned char v1:7;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu7c_BFu0ll_B) C1{ Fc:7 FL:0 Fc}



static void Test_BFu7c_BFu0ll_B()
{
  {
    init_simple_test("BFu7c_BFu0ll_B");
    static BFu7c_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(BFu7c_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu7c_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu7c_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7c_BFu0ll_B(Test_BFu7c_BFu0ll_B, "BFu7c_BFu0ll_B", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7c_BFu0s_B  {
  unsigned char v1:7;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu7c_BFu0s_B) C1{ Fc:7 Fs:0 Fc}



static void Test_BFu7c_BFu0s_B()
{
  {
    init_simple_test("BFu7c_BFu0s_B");
    static BFu7c_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(BFu7c_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu7c_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu7c_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7c_BFu0s_B(Test_BFu7c_BFu0s_B, "BFu7c_BFu0s_B", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7i_B_BFu0c  {
  unsigned int v1:7;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu7i_B_BFu0c) C1{ Fi:7 Fc Fc:0}



static void Test_BFu7i_B_BFu0c()
{
  {
    init_simple_test("BFu7i_B_BFu0c");
    static BFu7i_B_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_B_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_B_BFu0c");
    check_field_offset(lv, v2, 1, "BFu7i_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu7i_B_BFu0c(Test_BFu7i_B_BFu0c, "BFu7i_B_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7i_B_BFu0i  {
  unsigned int v1:7;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu7i_B_BFu0i) C1{ Fi:7 Fc Fi:0}



static void Test_BFu7i_B_BFu0i()
{
  {
    init_simple_test("BFu7i_B_BFu0i");
    static BFu7i_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_B_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_B_BFu0i");
    check_field_offset(lv, v2, 1, "BFu7i_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu7i_B_BFu0i(Test_BFu7i_B_BFu0i, "BFu7i_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7i_B_BFu0ll  {
  unsigned int v1:7;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu7i_B_BFu0ll) C1{ Fi:7 Fc FL:0}



static void Test_BFu7i_B_BFu0ll()
{
  {
    init_simple_test("BFu7i_B_BFu0ll");
    static BFu7i_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7i_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu7i_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_B_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu7i_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu7i_B_BFu0ll(Test_BFu7i_B_BFu0ll, "BFu7i_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7i_B_BFu0s  {
  unsigned int v1:7;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu7i_B_BFu0s) C1{ Fi:7 Fc Fs:0}



static void Test_BFu7i_B_BFu0s()
{
  {
    init_simple_test("BFu7i_B_BFu0s");
    static BFu7i_B_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_B_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_B_BFu0s");
    check_field_offset(lv, v2, 1, "BFu7i_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu7i_B_BFu0s(Test_BFu7i_B_BFu0s, "BFu7i_B_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7i_BFu0c_B  {
  unsigned int v1:7;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu7i_BFu0c_B) C1{ Fi:7 Fc:0 Fc}



static void Test_BFu7i_BFu0c_B()
{
  {
    init_simple_test("BFu7i_BFu0c_B");
    static BFu7i_BFu0c_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_BFu0c_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_BFu0c_B");
    check_field_offset(lv, v2, 1, "BFu7i_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7i_BFu0c_B(Test_BFu7i_BFu0c_B, "BFu7i_BFu0c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7i_BFu0i_B  {
  unsigned int v1:7;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu7i_BFu0i_B) C1{ Fi:7 Fi:0 Fc}



static void Test_BFu7i_BFu0i_B()
{
  {
    init_simple_test("BFu7i_BFu0i_B");
    static BFu7i_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu7i_BFu0i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu7i_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7i_BFu0i_B(Test_BFu7i_BFu0i_B, "BFu7i_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7i_BFu0ll_B  {
  unsigned int v1:7;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu7i_BFu0ll_B) C1{ Fi:7 FL:0 Fc}



static void Test_BFu7i_BFu0ll_B()
{
  {
    init_simple_test("BFu7i_BFu0ll_B");
    static BFu7i_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(BFu7i_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu7i_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu7i_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7i_BFu0ll_B(Test_BFu7i_BFu0ll_B, "BFu7i_BFu0ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7i_BFu0s_B  {
  unsigned int v1:7;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu7i_BFu0s_B) C1{ Fi:7 Fs:0 Fc}



static void Test_BFu7i_BFu0s_B()
{
  {
    init_simple_test("BFu7i_BFu0s_B");
    static BFu7i_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_BFu0s_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu7i_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7i_BFu0s_B(Test_BFu7i_BFu0s_B, "BFu7i_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7ll_B_BFu0c  {
  __tsu64 v1:7;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu7ll_B_BFu0c) C1{ FL:7 Fc Fc:0}



static void Test_BFu7ll_B_BFu0c()
{
  {
    init_simple_test("BFu7ll_B_BFu0c");
    static BFu7ll_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_B_BFu0c");
    check_field_offset(lv, v2, 1, "BFu7ll_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu7ll_B_BFu0c(Test_BFu7ll_B_BFu0c, "BFu7ll_B_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7ll_B_BFu0i  {
  __tsu64 v1:7;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu7ll_B_BFu0i) C1{ FL:7 Fc Fi:0}



static void Test_BFu7ll_B_BFu0i()
{
  {
    init_simple_test("BFu7ll_B_BFu0i");
    static BFu7ll_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_B_BFu0i");
    check_field_offset(lv, v2, 1, "BFu7ll_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu7ll_B_BFu0i(Test_BFu7ll_B_BFu0i, "BFu7ll_B_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7ll_B_BFu0ll  {
  __tsu64 v1:7;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu7ll_B_BFu0ll) C1{ FL:7 Fc FL:0}



static void Test_BFu7ll_B_BFu0ll()
{
  {
    init_simple_test("BFu7ll_B_BFu0ll");
    static BFu7ll_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_B_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu7ll_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu7ll_B_BFu0ll(Test_BFu7ll_B_BFu0ll, "BFu7ll_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7ll_B_BFu0s  {
  __tsu64 v1:7;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu7ll_B_BFu0s) C1{ FL:7 Fc Fs:0}



static void Test_BFu7ll_B_BFu0s()
{
  {
    init_simple_test("BFu7ll_B_BFu0s");
    static BFu7ll_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_B_BFu0s");
    check_field_offset(lv, v2, 1, "BFu7ll_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu7ll_B_BFu0s(Test_BFu7ll_B_BFu0s, "BFu7ll_B_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7ll_BFu0c_B  {
  __tsu64 v1:7;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu7ll_BFu0c_B) C1{ FL:7 Fc:0 Fc}



static void Test_BFu7ll_BFu0c_B()
{
  {
    init_simple_test("BFu7ll_BFu0c_B");
    static BFu7ll_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_BFu0c_B");
    check_field_offset(lv, v2, 1, "BFu7ll_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7ll_BFu0c_B(Test_BFu7ll_BFu0c_B, "BFu7ll_BFu0c_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7ll_BFu0i_B  {
  __tsu64 v1:7;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu7ll_BFu0i_B) C1{ FL:7 Fi:0 Fc}



static void Test_BFu7ll_BFu0i_B()
{
  {
    init_simple_test("BFu7ll_BFu0i_B");
    static BFu7ll_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu7ll_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu7ll_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7ll_BFu0i_B(Test_BFu7ll_BFu0i_B, "BFu7ll_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7ll_BFu0ll_B  {
  __tsu64 v1:7;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu7ll_BFu0ll_B) C1{ FL:7 FL:0 Fc}



static void Test_BFu7ll_BFu0ll_B()
{
  {
    init_simple_test("BFu7ll_BFu0ll_B");
    static BFu7ll_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu7ll_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu7ll_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7ll_BFu0ll_B(Test_BFu7ll_BFu0ll_B, "BFu7ll_BFu0ll_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7ll_BFu0s_B  {
  __tsu64 v1:7;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu7ll_BFu0s_B) C1{ FL:7 Fs:0 Fc}



static void Test_BFu7ll_BFu0s_B()
{
  {
    init_simple_test("BFu7ll_BFu0s_B");
    static BFu7ll_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu7ll_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7ll_BFu0s_B(Test_BFu7ll_BFu0s_B, "BFu7ll_BFu0s_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7s_B_BFu0c  {
  unsigned short v1:7;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu7s_B_BFu0c) C1{ Fs:7 Fc Fc:0}



static void Test_BFu7s_B_BFu0c()
{
  {
    init_simple_test("BFu7s_B_BFu0c");
    static BFu7s_B_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(BFu7s_B_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(BFu7s_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_B_BFu0c");
    check_field_offset(lv, v2, 1, "BFu7s_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu7s_B_BFu0c(Test_BFu7s_B_BFu0c, "BFu7s_B_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7s_B_BFu0i  {
  unsigned short v1:7;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu7s_B_BFu0i) C1{ Fs:7 Fc Fi:0}



static void Test_BFu7s_B_BFu0i()
{
  {
    init_simple_test("BFu7s_B_BFu0i");
    static BFu7s_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu7s_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu7s_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_B_BFu0i");
    check_field_offset(lv, v2, 1, "BFu7s_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu7s_B_BFu0i(Test_BFu7s_B_BFu0i, "BFu7s_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7s_B_BFu0ll  {
  unsigned short v1:7;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu7s_B_BFu0ll) C1{ Fs:7 Fc FL:0}



static void Test_BFu7s_B_BFu0ll()
{
  {
    init_simple_test("BFu7s_B_BFu0ll");
    static BFu7s_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7s_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu7s_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_B_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu7s_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu7s_B_BFu0ll(Test_BFu7s_B_BFu0ll, "BFu7s_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7s_B_BFu0s  {
  unsigned short v1:7;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu7s_B_BFu0s) C1{ Fs:7 Fc Fs:0}



static void Test_BFu7s_B_BFu0s()
{
  {
    init_simple_test("BFu7s_B_BFu0s");
    static BFu7s_B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu7s_B_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu7s_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_B_BFu0s");
    check_field_offset(lv, v2, 1, "BFu7s_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu7s_B_BFu0s(Test_BFu7s_B_BFu0s, "BFu7s_B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7s_BFu0c_B  {
  unsigned short v1:7;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu7s_BFu0c_B) C1{ Fs:7 Fc:0 Fc}



static void Test_BFu7s_BFu0c_B()
{
  {
    init_simple_test("BFu7s_BFu0c_B");
    static BFu7s_BFu0c_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu7s_BFu0c_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu7s_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_BFu0c_B");
    check_field_offset(lv, v2, 1, "BFu7s_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7s_BFu0c_B(Test_BFu7s_BFu0c_B, "BFu7s_BFu0c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7s_BFu0i_B  {
  unsigned short v1:7;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu7s_BFu0i_B) C1{ Fs:7 Fi:0 Fc}



static void Test_BFu7s_BFu0i_B()
{
  {
    init_simple_test("BFu7s_BFu0i_B");
    static BFu7s_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(BFu7s_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu7s_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu7s_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7s_BFu0i_B(Test_BFu7s_BFu0i_B, "BFu7s_BFu0i_B", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7s_BFu0ll_B  {
  unsigned short v1:7;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu7s_BFu0ll_B) C1{ Fs:7 FL:0 Fc}



static void Test_BFu7s_BFu0ll_B()
{
  {
    init_simple_test("BFu7s_BFu0ll_B");
    static BFu7s_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(BFu7s_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu7s_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu7s_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7s_BFu0ll_B(Test_BFu7s_BFu0ll_B, "BFu7s_BFu0ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu7s_BFu0s_B  {
  unsigned short v1:7;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu7s_BFu0s_B) C1{ Fs:7 Fs:0 Fc}



static void Test_BFu7s_BFu0s_B()
{
  {
    init_simple_test("BFu7s_BFu0s_B");
    static BFu7s_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu7s_BFu0s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu7s_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu7s_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu7s_BFu0s_B(Test_BFu7s_BFu0s_B, "BFu7s_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8c_B_BFu0c  {
  unsigned char v1:8;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu8c_B_BFu0c) C1{ Fc:8 Fc Fc:0}



static void Test_BFu8c_B_BFu0c()
{
  {
    init_simple_test("BFu8c_B_BFu0c");
    static BFu8c_B_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(BFu8c_B_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8c_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_B_BFu0c");
    check_field_offset(lv, v2, 1, "BFu8c_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu8c_B_BFu0c(Test_BFu8c_B_BFu0c, "BFu8c_B_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8c_B_BFu0i  {
  unsigned char v1:8;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu8c_B_BFu0i) C1{ Fc:8 Fc Fi:0}



static void Test_BFu8c_B_BFu0i()
{
  {
    init_simple_test("BFu8c_B_BFu0i");
    static BFu8c_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu8c_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu8c_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_B_BFu0i");
    check_field_offset(lv, v2, 1, "BFu8c_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu8c_B_BFu0i(Test_BFu8c_B_BFu0i, "BFu8c_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8c_B_BFu0ll  {
  unsigned char v1:8;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu8c_B_BFu0ll) C1{ Fc:8 Fc FL:0}



static void Test_BFu8c_B_BFu0ll()
{
  {
    init_simple_test("BFu8c_B_BFu0ll");
    static BFu8c_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8c_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu8c_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_B_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu8c_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu8c_B_BFu0ll(Test_BFu8c_B_BFu0ll, "BFu8c_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8c_B_BFu0s  {
  unsigned char v1:8;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu8c_B_BFu0s) C1{ Fc:8 Fc Fs:0}



static void Test_BFu8c_B_BFu0s()
{
  {
    init_simple_test("BFu8c_B_BFu0s");
    static BFu8c_B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu8c_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu8c_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_B_BFu0s");
    check_field_offset(lv, v2, 1, "BFu8c_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu8c_B_BFu0s(Test_BFu8c_B_BFu0s, "BFu8c_B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8c_BFu0c_B  {
  unsigned char v1:8;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu8c_BFu0c_B) C1{ Fc:8 Fc:0 Fc}



static void Test_BFu8c_BFu0c_B()
{
  {
    init_simple_test("BFu8c_BFu0c_B");
    static BFu8c_BFu0c_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu8c_BFu0c_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8c_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_BFu0c_B");
    check_field_offset(lv, v2, 1, "BFu8c_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8c_BFu0c_B(Test_BFu8c_BFu0c_B, "BFu8c_BFu0c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8c_BFu0i_B  {
  unsigned char v1:8;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu8c_BFu0i_B) C1{ Fc:8 Fi:0 Fc}



static void Test_BFu8c_BFu0i_B()
{
  {
    init_simple_test("BFu8c_BFu0i_B");
    static BFu8c_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(BFu8c_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu8c_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu8c_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8c_BFu0i_B(Test_BFu8c_BFu0i_B, "BFu8c_BFu0i_B", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8c_BFu0ll_B  {
  unsigned char v1:8;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu8c_BFu0ll_B) C1{ Fc:8 FL:0 Fc}



static void Test_BFu8c_BFu0ll_B()
{
  {
    init_simple_test("BFu8c_BFu0ll_B");
    static BFu8c_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(BFu8c_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu8c_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu8c_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8c_BFu0ll_B(Test_BFu8c_BFu0ll_B, "BFu8c_BFu0ll_B", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8c_BFu0s_B  {
  unsigned char v1:8;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu8c_BFu0s_B) C1{ Fc:8 Fs:0 Fc}



static void Test_BFu8c_BFu0s_B()
{
  {
    init_simple_test("BFu8c_BFu0s_B");
    static BFu8c_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(BFu8c_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu8c_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu8c_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8c_BFu0s_B(Test_BFu8c_BFu0s_B, "BFu8c_BFu0s_B", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8i_B_BFu0c  {
  unsigned int v1:8;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu8i_B_BFu0c) C1{ Fi:8 Fc Fc:0}



static void Test_BFu8i_B_BFu0c()
{
  {
    init_simple_test("BFu8i_B_BFu0c");
    static BFu8i_B_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_B_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_B_BFu0c");
    check_field_offset(lv, v2, 1, "BFu8i_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu8i_B_BFu0c(Test_BFu8i_B_BFu0c, "BFu8i_B_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8i_B_BFu0i  {
  unsigned int v1:8;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu8i_B_BFu0i) C1{ Fi:8 Fc Fi:0}



static void Test_BFu8i_B_BFu0i()
{
  {
    init_simple_test("BFu8i_B_BFu0i");
    static BFu8i_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_B_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_B_BFu0i");
    check_field_offset(lv, v2, 1, "BFu8i_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu8i_B_BFu0i(Test_BFu8i_B_BFu0i, "BFu8i_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8i_B_BFu0ll  {
  unsigned int v1:8;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu8i_B_BFu0ll) C1{ Fi:8 Fc FL:0}



static void Test_BFu8i_B_BFu0ll()
{
  {
    init_simple_test("BFu8i_B_BFu0ll");
    static BFu8i_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8i_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu8i_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_B_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu8i_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu8i_B_BFu0ll(Test_BFu8i_B_BFu0ll, "BFu8i_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8i_B_BFu0s  {
  unsigned int v1:8;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu8i_B_BFu0s) C1{ Fi:8 Fc Fs:0}



static void Test_BFu8i_B_BFu0s()
{
  {
    init_simple_test("BFu8i_B_BFu0s");
    static BFu8i_B_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_B_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_B_BFu0s");
    check_field_offset(lv, v2, 1, "BFu8i_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu8i_B_BFu0s(Test_BFu8i_B_BFu0s, "BFu8i_B_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8i_BFu0c_B  {
  unsigned int v1:8;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu8i_BFu0c_B) C1{ Fi:8 Fc:0 Fc}



static void Test_BFu8i_BFu0c_B()
{
  {
    init_simple_test("BFu8i_BFu0c_B");
    static BFu8i_BFu0c_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_BFu0c_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_BFu0c_B");
    check_field_offset(lv, v2, 1, "BFu8i_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8i_BFu0c_B(Test_BFu8i_BFu0c_B, "BFu8i_BFu0c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8i_BFu0i_B  {
  unsigned int v1:8;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu8i_BFu0i_B) C1{ Fi:8 Fi:0 Fc}



static void Test_BFu8i_BFu0i_B()
{
  {
    init_simple_test("BFu8i_BFu0i_B");
    static BFu8i_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu8i_BFu0i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu8i_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8i_BFu0i_B(Test_BFu8i_BFu0i_B, "BFu8i_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8i_BFu0ll_B  {
  unsigned int v1:8;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu8i_BFu0ll_B) C1{ Fi:8 FL:0 Fc}



static void Test_BFu8i_BFu0ll_B()
{
  {
    init_simple_test("BFu8i_BFu0ll_B");
    static BFu8i_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(BFu8i_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu8i_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu8i_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8i_BFu0ll_B(Test_BFu8i_BFu0ll_B, "BFu8i_BFu0ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8i_BFu0s_B  {
  unsigned int v1:8;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu8i_BFu0s_B) C1{ Fi:8 Fs:0 Fc}



static void Test_BFu8i_BFu0s_B()
{
  {
    init_simple_test("BFu8i_BFu0s_B");
    static BFu8i_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_BFu0s_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu8i_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8i_BFu0s_B(Test_BFu8i_BFu0s_B, "BFu8i_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8ll_B_BFu0c  {
  __tsu64 v1:8;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu8ll_B_BFu0c) C1{ FL:8 Fc Fc:0}



static void Test_BFu8ll_B_BFu0c()
{
  {
    init_simple_test("BFu8ll_B_BFu0c");
    static BFu8ll_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_B_BFu0c");
    check_field_offset(lv, v2, 1, "BFu8ll_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu8ll_B_BFu0c(Test_BFu8ll_B_BFu0c, "BFu8ll_B_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8ll_B_BFu0i  {
  __tsu64 v1:8;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu8ll_B_BFu0i) C1{ FL:8 Fc Fi:0}



static void Test_BFu8ll_B_BFu0i()
{
  {
    init_simple_test("BFu8ll_B_BFu0i");
    static BFu8ll_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_B_BFu0i");
    check_field_offset(lv, v2, 1, "BFu8ll_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu8ll_B_BFu0i(Test_BFu8ll_B_BFu0i, "BFu8ll_B_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8ll_B_BFu0ll  {
  __tsu64 v1:8;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu8ll_B_BFu0ll) C1{ FL:8 Fc FL:0}



static void Test_BFu8ll_B_BFu0ll()
{
  {
    init_simple_test("BFu8ll_B_BFu0ll");
    static BFu8ll_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_B_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu8ll_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu8ll_B_BFu0ll(Test_BFu8ll_B_BFu0ll, "BFu8ll_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8ll_B_BFu0s  {
  __tsu64 v1:8;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu8ll_B_BFu0s) C1{ FL:8 Fc Fs:0}



static void Test_BFu8ll_B_BFu0s()
{
  {
    init_simple_test("BFu8ll_B_BFu0s");
    static BFu8ll_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_B_BFu0s");
    check_field_offset(lv, v2, 1, "BFu8ll_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu8ll_B_BFu0s(Test_BFu8ll_B_BFu0s, "BFu8ll_B_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8ll_BFu0c_B  {
  __tsu64 v1:8;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu8ll_BFu0c_B) C1{ FL:8 Fc:0 Fc}



static void Test_BFu8ll_BFu0c_B()
{
  {
    init_simple_test("BFu8ll_BFu0c_B");
    static BFu8ll_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_BFu0c_B");
    check_field_offset(lv, v2, 1, "BFu8ll_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8ll_BFu0c_B(Test_BFu8ll_BFu0c_B, "BFu8ll_BFu0c_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8ll_BFu0i_B  {
  __tsu64 v1:8;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu8ll_BFu0i_B) C1{ FL:8 Fi:0 Fc}



static void Test_BFu8ll_BFu0i_B()
{
  {
    init_simple_test("BFu8ll_BFu0i_B");
    static BFu8ll_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu8ll_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu8ll_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8ll_BFu0i_B(Test_BFu8ll_BFu0i_B, "BFu8ll_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8ll_BFu0ll_B  {
  __tsu64 v1:8;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu8ll_BFu0ll_B) C1{ FL:8 FL:0 Fc}



static void Test_BFu8ll_BFu0ll_B()
{
  {
    init_simple_test("BFu8ll_BFu0ll_B");
    static BFu8ll_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu8ll_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu8ll_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8ll_BFu0ll_B(Test_BFu8ll_BFu0ll_B, "BFu8ll_BFu0ll_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8ll_BFu0s_B  {
  __tsu64 v1:8;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu8ll_BFu0s_B) C1{ FL:8 Fs:0 Fc}



static void Test_BFu8ll_BFu0s_B()
{
  {
    init_simple_test("BFu8ll_BFu0s_B");
    static BFu8ll_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu8ll_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8ll_BFu0s_B(Test_BFu8ll_BFu0s_B, "BFu8ll_BFu0s_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8s_B_BFu0c  {
  unsigned short v1:8;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu8s_B_BFu0c) C1{ Fs:8 Fc Fc:0}



static void Test_BFu8s_B_BFu0c()
{
  {
    init_simple_test("BFu8s_B_BFu0c");
    static BFu8s_B_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(BFu8s_B_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(BFu8s_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_B_BFu0c");
    check_field_offset(lv, v2, 1, "BFu8s_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu8s_B_BFu0c(Test_BFu8s_B_BFu0c, "BFu8s_B_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8s_B_BFu0i  {
  unsigned short v1:8;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu8s_B_BFu0i) C1{ Fs:8 Fc Fi:0}



static void Test_BFu8s_B_BFu0i()
{
  {
    init_simple_test("BFu8s_B_BFu0i");
    static BFu8s_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu8s_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu8s_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_B_BFu0i");
    check_field_offset(lv, v2, 1, "BFu8s_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu8s_B_BFu0i(Test_BFu8s_B_BFu0i, "BFu8s_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8s_B_BFu0ll  {
  unsigned short v1:8;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu8s_B_BFu0ll) C1{ Fs:8 Fc FL:0}



static void Test_BFu8s_B_BFu0ll()
{
  {
    init_simple_test("BFu8s_B_BFu0ll");
    static BFu8s_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8s_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu8s_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_B_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu8s_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu8s_B_BFu0ll(Test_BFu8s_B_BFu0ll, "BFu8s_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8s_B_BFu0s  {
  unsigned short v1:8;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu8s_B_BFu0s) C1{ Fs:8 Fc Fs:0}



static void Test_BFu8s_B_BFu0s()
{
  {
    init_simple_test("BFu8s_B_BFu0s");
    static BFu8s_B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu8s_B_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu8s_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_B_BFu0s");
    check_field_offset(lv, v2, 1, "BFu8s_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu8s_B_BFu0s(Test_BFu8s_B_BFu0s, "BFu8s_B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8s_BFu0c_B  {
  unsigned short v1:8;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu8s_BFu0c_B) C1{ Fs:8 Fc:0 Fc}



static void Test_BFu8s_BFu0c_B()
{
  {
    init_simple_test("BFu8s_BFu0c_B");
    static BFu8s_BFu0c_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu8s_BFu0c_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu8s_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_BFu0c_B");
    check_field_offset(lv, v2, 1, "BFu8s_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8s_BFu0c_B(Test_BFu8s_BFu0c_B, "BFu8s_BFu0c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8s_BFu0i_B  {
  unsigned short v1:8;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu8s_BFu0i_B) C1{ Fs:8 Fi:0 Fc}



static void Test_BFu8s_BFu0i_B()
{
  {
    init_simple_test("BFu8s_BFu0i_B");
    static BFu8s_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(BFu8s_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu8s_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu8s_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8s_BFu0i_B(Test_BFu8s_BFu0i_B, "BFu8s_BFu0i_B", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8s_BFu0ll_B  {
  unsigned short v1:8;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu8s_BFu0ll_B) C1{ Fs:8 FL:0 Fc}



static void Test_BFu8s_BFu0ll_B()
{
  {
    init_simple_test("BFu8s_BFu0ll_B");
    static BFu8s_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(BFu8s_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu8s_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu8s_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8s_BFu0ll_B(Test_BFu8s_BFu0ll_B, "BFu8s_BFu0ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu8s_BFu0s_B  {
  unsigned short v1:8;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu8s_BFu0s_B) C1{ Fs:8 Fs:0 Fc}



static void Test_BFu8s_BFu0s_B()
{
  {
    init_simple_test("BFu8s_BFu0s_B");
    static BFu8s_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu8s_BFu0s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu8s_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu8s_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu8s_BFu0s_B(Test_BFu8s_BFu0s_B, "BFu8s_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9i_B_BFu0c  {
  unsigned int v1:9;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu9i_B_BFu0c) C1{ Fi:9 Fc Fc:0}



static void Test_BFu9i_B_BFu0c()
{
  {
    init_simple_test("BFu9i_B_BFu0c");
    static BFu9i_B_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_B_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_B_BFu0c");
    check_field_offset(lv, v2, 2, "BFu9i_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu9i_B_BFu0c(Test_BFu9i_B_BFu0c, "BFu9i_B_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9i_B_BFu0i  {
  unsigned int v1:9;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu9i_B_BFu0i) C1{ Fi:9 Fc Fi:0}



static void Test_BFu9i_B_BFu0i()
{
  {
    init_simple_test("BFu9i_B_BFu0i");
    static BFu9i_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_B_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_B_BFu0i");
    check_field_offset(lv, v2, 2, "BFu9i_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu9i_B_BFu0i(Test_BFu9i_B_BFu0i, "BFu9i_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9i_B_BFu0ll  {
  unsigned int v1:9;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu9i_B_BFu0ll) C1{ Fi:9 Fc FL:0}



static void Test_BFu9i_B_BFu0ll()
{
  {
    init_simple_test("BFu9i_B_BFu0ll");
    static BFu9i_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9i_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu9i_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_B_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu9i_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu9i_B_BFu0ll(Test_BFu9i_B_BFu0ll, "BFu9i_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9i_B_BFu0s  {
  unsigned int v1:9;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu9i_B_BFu0s) C1{ Fi:9 Fc Fs:0}



static void Test_BFu9i_B_BFu0s()
{
  {
    init_simple_test("BFu9i_B_BFu0s");
    static BFu9i_B_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_B_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_B_BFu0s");
    check_field_offset(lv, v2, 2, "BFu9i_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu9i_B_BFu0s(Test_BFu9i_B_BFu0s, "BFu9i_B_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9i_BFu0c_B  {
  unsigned int v1:9;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu9i_BFu0c_B) C1{ Fi:9 Fc:0 Fc}



static void Test_BFu9i_BFu0c_B()
{
  {
    init_simple_test("BFu9i_BFu0c_B");
    static BFu9i_BFu0c_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_BFu0c_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_BFu0c_B");
    check_field_offset(lv, v2, 2, "BFu9i_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu9i_BFu0c_B(Test_BFu9i_BFu0c_B, "BFu9i_BFu0c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9i_BFu0i_B  {
  unsigned int v1:9;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu9i_BFu0i_B) C1{ Fi:9 Fi:0 Fc}



static void Test_BFu9i_BFu0i_B()
{
  {
    init_simple_test("BFu9i_BFu0i_B");
    static BFu9i_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu9i_BFu0i_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu9i_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu9i_BFu0i_B(Test_BFu9i_BFu0i_B, "BFu9i_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9i_BFu0ll_B  {
  unsigned int v1:9;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu9i_BFu0ll_B) C1{ Fi:9 FL:0 Fc}



static void Test_BFu9i_BFu0ll_B()
{
  {
    init_simple_test("BFu9i_BFu0ll_B");
    static BFu9i_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(BFu9i_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu9i_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu9i_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu9i_BFu0ll_B(Test_BFu9i_BFu0ll_B, "BFu9i_BFu0ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9i_BFu0s_B  {
  unsigned int v1:9;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu9i_BFu0s_B) C1{ Fi:9 Fs:0 Fc}



static void Test_BFu9i_BFu0s_B()
{
  {
    init_simple_test("BFu9i_BFu0s_B");
    static BFu9i_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_BFu0s_B)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu9i_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu9i_BFu0s_B(Test_BFu9i_BFu0s_B, "BFu9i_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9ll_B_BFu0c  {
  __tsu64 v1:9;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu9ll_B_BFu0c) C1{ FL:9 Fc Fc:0}



static void Test_BFu9ll_B_BFu0c()
{
  {
    init_simple_test("BFu9ll_B_BFu0c");
    static BFu9ll_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_B_BFu0c");
    check_field_offset(lv, v2, 2, "BFu9ll_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu9ll_B_BFu0c(Test_BFu9ll_B_BFu0c, "BFu9ll_B_BFu0c", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9ll_B_BFu0i  {
  __tsu64 v1:9;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu9ll_B_BFu0i) C1{ FL:9 Fc Fi:0}



static void Test_BFu9ll_B_BFu0i()
{
  {
    init_simple_test("BFu9ll_B_BFu0i");
    static BFu9ll_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_B_BFu0i");
    check_field_offset(lv, v2, 2, "BFu9ll_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu9ll_B_BFu0i(Test_BFu9ll_B_BFu0i, "BFu9ll_B_BFu0i", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9ll_B_BFu0ll  {
  __tsu64 v1:9;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu9ll_B_BFu0ll) C1{ FL:9 Fc FL:0}



static void Test_BFu9ll_B_BFu0ll()
{
  {
    init_simple_test("BFu9ll_B_BFu0ll");
    static BFu9ll_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_B_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu9ll_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu9ll_B_BFu0ll(Test_BFu9ll_B_BFu0ll, "BFu9ll_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9ll_B_BFu0s  {
  __tsu64 v1:9;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu9ll_B_BFu0s) C1{ FL:9 Fc Fs:0}



static void Test_BFu9ll_B_BFu0s()
{
  {
    init_simple_test("BFu9ll_B_BFu0s");
    static BFu9ll_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_B_BFu0s");
    check_field_offset(lv, v2, 2, "BFu9ll_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu9ll_B_BFu0s(Test_BFu9ll_B_BFu0s, "BFu9ll_B_BFu0s", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9ll_BFu0c_B  {
  __tsu64 v1:9;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu9ll_BFu0c_B) C1{ FL:9 Fc:0 Fc}



static void Test_BFu9ll_BFu0c_B()
{
  {
    init_simple_test("BFu9ll_BFu0c_B");
    static BFu9ll_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_BFu0c_B");
    check_field_offset(lv, v2, 2, "BFu9ll_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu9ll_BFu0c_B(Test_BFu9ll_BFu0c_B, "BFu9ll_BFu0c_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9ll_BFu0i_B  {
  __tsu64 v1:9;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu9ll_BFu0i_B) C1{ FL:9 Fi:0 Fc}



static void Test_BFu9ll_BFu0i_B()
{
  {
    init_simple_test("BFu9ll_BFu0i_B");
    static BFu9ll_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(BFu9ll_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu9ll_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu9ll_BFu0i_B(Test_BFu9ll_BFu0i_B, "BFu9ll_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9ll_BFu0ll_B  {
  __tsu64 v1:9;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu9ll_BFu0ll_B) C1{ FL:9 FL:0 Fc}



static void Test_BFu9ll_BFu0ll_B()
{
  {
    init_simple_test("BFu9ll_BFu0ll_B");
    static BFu9ll_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(BFu9ll_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu9ll_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu9ll_BFu0ll_B(Test_BFu9ll_BFu0ll_B, "BFu9ll_BFu0ll_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9ll_BFu0s_B  {
  __tsu64 v1:9;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu9ll_BFu0s_B) C1{ FL:9 Fs:0 Fc}



static void Test_BFu9ll_BFu0s_B()
{
  {
    init_simple_test("BFu9ll_BFu0s_B");
    static BFu9ll_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu9ll_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu9ll_BFu0s_B(Test_BFu9ll_BFu0s_B, "BFu9ll_BFu0s_B", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9s_B_BFu0c  {
  unsigned short v1:9;
  bool v2;
  unsigned char  :0;
};
//SIG(1 BFu9s_B_BFu0c) C1{ Fs:9 Fc Fc:0}



static void Test_BFu9s_B_BFu0c()
{
  {
    init_simple_test("BFu9s_B_BFu0c");
    static BFu9s_B_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_B_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(BFu9s_B_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_B_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_B_BFu0c");
    check_field_offset(lv, v2, 2, "BFu9s_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vBFu9s_B_BFu0c(Test_BFu9s_B_BFu0c, "BFu9s_B_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9s_B_BFu0i  {
  unsigned short v1:9;
  bool v2;
  unsigned int  :0;
};
//SIG(1 BFu9s_B_BFu0i) C1{ Fs:9 Fc Fi:0}



static void Test_BFu9s_B_BFu0i()
{
  {
    init_simple_test("BFu9s_B_BFu0i");
    static BFu9s_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu9s_B_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_B_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_B_BFu0i");
    check_field_offset(lv, v2, 2, "BFu9s_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vBFu9s_B_BFu0i(Test_BFu9s_B_BFu0i, "BFu9s_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9s_B_BFu0ll  {
  unsigned short v1:9;
  bool v2;
  __tsu64  :0;
};
//SIG(1 BFu9s_B_BFu0ll) C1{ Fs:9 Fc FL:0}



static void Test_BFu9s_B_BFu0ll()
{
  {
    init_simple_test("BFu9s_B_BFu0ll");
    static BFu9s_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9s_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu9s_B_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_B_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_B_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu9s_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vBFu9s_B_BFu0ll(Test_BFu9s_B_BFu0ll, "BFu9s_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9s_B_BFu0s  {
  unsigned short v1:9;
  bool v2;
  unsigned short  :0;
};
//SIG(1 BFu9s_B_BFu0s) C1{ Fs:9 Fc Fs:0}



static void Test_BFu9s_B_BFu0s()
{
  {
    init_simple_test("BFu9s_B_BFu0s");
    static BFu9s_B_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_B_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu9s_B_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_B_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_B_BFu0s");
    check_field_offset(lv, v2, 2, "BFu9s_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vBFu9s_B_BFu0s(Test_BFu9s_B_BFu0s, "BFu9s_B_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9s_BFu0c_B  {
  unsigned short v1:9;
  unsigned char  :0;
  bool v2;
};
//SIG(1 BFu9s_BFu0c_B) C1{ Fs:9 Fc:0 Fc}



static void Test_BFu9s_BFu0c_B()
{
  {
    init_simple_test("BFu9s_BFu0c_B");
    static BFu9s_BFu0c_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_BFu0c_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu9s_BFu0c_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu0c_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu0c_B");
    check_field_offset(lv, v2, 2, "BFu9s_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu0c_B(Test_BFu9s_BFu0c_B, "BFu9s_BFu0c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9s_BFu0i_B  {
  unsigned short v1:9;
  unsigned int  :0;
  bool v2;
};
//SIG(1 BFu9s_BFu0i_B) C1{ Fs:9 Fi:0 Fc}



static void Test_BFu9s_BFu0i_B()
{
  {
    init_simple_test("BFu9s_BFu0i_B");
    static BFu9s_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(BFu9s_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu9s_BFu0i_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu0i_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu0i_B");
    check_field_offset(lv, v2, 4, "BFu9s_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu0i_B(Test_BFu9s_BFu0i_B, "BFu9s_BFu0i_B", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9s_BFu0ll_B  {
  unsigned short v1:9;
  __tsu64  :0;
  bool v2;
};
//SIG(1 BFu9s_BFu0ll_B) C1{ Fs:9 FL:0 Fc}



static void Test_BFu9s_BFu0ll_B()
{
  {
    init_simple_test("BFu9s_BFu0ll_B");
    static BFu9s_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(BFu9s_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu9s_BFu0ll_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu0ll_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu0ll_B");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu9s_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu0ll_B(Test_BFu9s_BFu0ll_B, "BFu9s_BFu0ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu9s_BFu0s_B  {
  unsigned short v1:9;
  unsigned short  :0;
  bool v2;
};
//SIG(1 BFu9s_BFu0s_B) C1{ Fs:9 Fs:0 Fc}



static void Test_BFu9s_BFu0s_B()
{
  {
    init_simple_test("BFu9s_BFu0s_B");
    static BFu9s_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_BFu0s_B)");
    check2(__alignof__(lv), 2, "__alignof__(BFu9s_BFu0s_B)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu0s_B");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu0s_B");
    check_field_offset(lv, v2, 2, "BFu9s_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vBFu9s_BFu0s_B(Test_BFu9s_BFu0s_B, "BFu9s_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  C_B_BFu0c  {
  char v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 C_B_BFu0c) C1{ Fc[2] Fc:0}



static void Test_C_B_BFu0c()
{
  {
    init_simple_test("C_B_BFu0c");
    static C_B_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(C_B_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(C_B_BFu0c)");
    check_field_offset(lv, v1, 0, "C_B_BFu0c.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vC_B_BFu0c(Test_C_B_BFu0c, "C_B_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  C_B_BFu0i  {
  char v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 C_B_BFu0i) C1{ Fc[2] Fi:0}



static void Test_C_B_BFu0i()
{
  {
    init_simple_test("C_B_BFu0i");
    static C_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(C_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(C_B_BFu0i)");
    check_field_offset(lv, v1, 0, "C_B_BFu0i.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vC_B_BFu0i(Test_C_B_BFu0i, "C_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  C_B_BFu0ll  {
  char v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 C_B_BFu0ll) C1{ Fc[2] FL:0}



static void Test_C_B_BFu0ll()
{
  {
    init_simple_test("C_B_BFu0ll");
    static C_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(C_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(C_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "C_B_BFu0ll.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vC_B_BFu0ll(Test_C_B_BFu0ll, "C_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  C_B_BFu0s  {
  char v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 C_B_BFu0s) C1{ Fc[2] Fs:0}



static void Test_C_B_BFu0s()
{
  {
    init_simple_test("C_B_BFu0s");
    static C_B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(C_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(C_B_BFu0s)");
    check_field_offset(lv, v1, 0, "C_B_BFu0s.v1");
    check_field_offset(lv, v2, 1, "C_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vC_B_BFu0s(Test_C_B_BFu0s, "C_B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  C_BFu0c_B  {
  char v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 C_BFu0c_B) C1{ Fc Fc:0 Fc}



static void Test_C_BFu0c_B()
{
  {
    init_simple_test("C_BFu0c_B");
    static C_BFu0c_B lv;
    check2(sizeof(lv), 2, "sizeof(C_BFu0c_B)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu0c_B)");
    check_field_offset(lv, v1, 0, "C_BFu0c_B.v1");
    check_field_offset(lv, v2, 1, "C_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vC_BFu0c_B(Test_C_BFu0c_B, "C_BFu0c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  C_BFu0i_B  {
  char v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 C_BFu0i_B) C1{ Fc Fi:0 Fc}



static void Test_C_BFu0i_B()
{
  {
    init_simple_test("C_BFu0i_B");
    static C_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(C_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(C_BFu0i_B)");
    check_field_offset(lv, v1, 0, "C_BFu0i_B.v1");
    check_field_offset(lv, v2, 4, "C_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vC_BFu0i_B(Test_C_BFu0i_B, "C_BFu0i_B", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  C_BFu0ll_B  {
  char v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 C_BFu0ll_B) C1{ Fc FL:0 Fc}



static void Test_C_BFu0ll_B()
{
  {
    init_simple_test("C_BFu0ll_B");
    static C_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(C_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(C_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "C_BFu0ll_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "C_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vC_BFu0ll_B(Test_C_BFu0ll_B, "C_BFu0ll_B", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  C_BFu0s_B  {
  char v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 C_BFu0s_B) C1{ Fc Fs:0 Fc}



static void Test_C_BFu0s_B()
{
  {
    init_simple_test("C_BFu0s_B");
    static C_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(C_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(C_BFu0s_B)");
    check_field_offset(lv, v1, 0, "C_BFu0s_B.v1");
    check_field_offset(lv, v2, 2, "C_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vC_BFu0s_B(Test_C_BFu0s_B, "C_BFu0s_B", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  D_B_BFu0c  {
  double v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 D_B_BFu0c) C1{ FL Fc Fc:0}



static void Test_D_B_BFu0c()
{
  {
    init_simple_test("D_B_BFu0c");
    static D_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(D_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_B_BFu0c)");
    check_field_offset(lv, v1, 0, "D_B_BFu0c.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vD_B_BFu0c(Test_D_B_BFu0c, "D_B_BFu0c", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  D_B_BFu0i  {
  double v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 D_B_BFu0i) C1{ FL Fc Fi:0}



static void Test_D_B_BFu0i()
{
  {
    init_simple_test("D_B_BFu0i");
    static D_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(D_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_B_BFu0i)");
    check_field_offset(lv, v1, 0, "D_B_BFu0i.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vD_B_BFu0i(Test_D_B_BFu0i, "D_B_BFu0i", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  D_B_BFu0ll  {
  double v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 D_B_BFu0ll) C1{ FL Fc FL:0}



static void Test_D_B_BFu0ll()
{
  {
    init_simple_test("D_B_BFu0ll");
    static D_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(D_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "D_B_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vD_B_BFu0ll(Test_D_B_BFu0ll, "D_B_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  D_B_BFu0s  {
  double v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 D_B_BFu0s) C1{ FL Fc Fs:0}



static void Test_D_B_BFu0s()
{
  {
    init_simple_test("D_B_BFu0s");
    static D_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(D_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_B_BFu0s)");
    check_field_offset(lv, v1, 0, "D_B_BFu0s.v1");
    check_field_offset(lv, v2, 8, "D_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vD_B_BFu0s(Test_D_B_BFu0s, "D_B_BFu0s", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  D_BFu0c_B  {
  double v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 D_BFu0c_B) C1{ FL Fc:0 Fc}



static void Test_D_BFu0c_B()
{
  {
    init_simple_test("D_BFu0c_B");
    static D_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(D_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_BFu0c_B)");
    check_field_offset(lv, v1, 0, "D_BFu0c_B.v1");
    check_field_offset(lv, v2, 8, "D_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vD_BFu0c_B(Test_D_BFu0c_B, "D_BFu0c_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  D_BFu0i_B  {
  double v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 D_BFu0i_B) C1{ FL Fi:0 Fc}



static void Test_D_BFu0i_B()
{
  {
    init_simple_test("D_BFu0i_B");
    static D_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(D_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_BFu0i_B)");
    check_field_offset(lv, v1, 0, "D_BFu0i_B.v1");
    check_field_offset(lv, v2, 8, "D_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vD_BFu0i_B(Test_D_BFu0i_B, "D_BFu0i_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  D_BFu0ll_B  {
  double v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 D_BFu0ll_B) C1{ FL FL:0 Fc}



static void Test_D_BFu0ll_B()
{
  {
    init_simple_test("D_BFu0ll_B");
    static D_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(D_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "D_BFu0ll_B.v1");
    check_field_offset(lv, v2, 8, "D_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vD_BFu0ll_B(Test_D_BFu0ll_B, "D_BFu0ll_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  D_BFu0s_B  {
  double v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 D_BFu0s_B) C1{ FL Fs:0 Fc}



static void Test_D_BFu0s_B()
{
  {
    init_simple_test("D_BFu0s_B");
    static D_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(D_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_BFu0s_B)");
    check_field_offset(lv, v1, 0, "D_BFu0s_B.v1");
    check_field_offset(lv, v2, 8, "D_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vD_BFu0s_B(Test_D_BFu0s_B, "D_BFu0s_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  F_B_BFu0c  {
  float v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 F_B_BFu0c) C1{ Fi Fc Fc:0}



static void Test_F_B_BFu0c()
{
  {
    init_simple_test("F_B_BFu0c");
    static F_B_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(F_B_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(F_B_BFu0c)");
    check_field_offset(lv, v1, 0, "F_B_BFu0c.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vF_B_BFu0c(Test_F_B_BFu0c, "F_B_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  F_B_BFu0i  {
  float v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 F_B_BFu0i) C1{ Fi Fc Fi:0}



static void Test_F_B_BFu0i()
{
  {
    init_simple_test("F_B_BFu0i");
    static F_B_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(F_B_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(F_B_BFu0i)");
    check_field_offset(lv, v1, 0, "F_B_BFu0i.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vF_B_BFu0i(Test_F_B_BFu0i, "F_B_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  F_B_BFu0ll  {
  float v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 F_B_BFu0ll) C1{ Fi Fc FL:0}



static void Test_F_B_BFu0ll()
{
  {
    init_simple_test("F_B_BFu0ll");
    static F_B_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(F_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(F_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "F_B_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vF_B_BFu0ll(Test_F_B_BFu0ll, "F_B_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  F_B_BFu0s  {
  float v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 F_B_BFu0s) C1{ Fi Fc Fs:0}



static void Test_F_B_BFu0s()
{
  {
    init_simple_test("F_B_BFu0s");
    static F_B_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(F_B_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(F_B_BFu0s)");
    check_field_offset(lv, v1, 0, "F_B_BFu0s.v1");
    check_field_offset(lv, v2, 4, "F_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vF_B_BFu0s(Test_F_B_BFu0s, "F_B_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  F_BFu0c_B  {
  float v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 F_BFu0c_B) C1{ Fi Fc:0 Fc}



static void Test_F_BFu0c_B()
{
  {
    init_simple_test("F_BFu0c_B");
    static F_BFu0c_B lv;
    check2(sizeof(lv), 8, "sizeof(F_BFu0c_B)");
    check2(__alignof__(lv), 4, "__alignof__(F_BFu0c_B)");
    check_field_offset(lv, v1, 0, "F_BFu0c_B.v1");
    check_field_offset(lv, v2, 4, "F_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vF_BFu0c_B(Test_F_BFu0c_B, "F_BFu0c_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  F_BFu0i_B  {
  float v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 F_BFu0i_B) C1{ Fi Fi:0 Fc}



static void Test_F_BFu0i_B()
{
  {
    init_simple_test("F_BFu0i_B");
    static F_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(F_BFu0i_B)");
    check2(__alignof__(lv), 4, "__alignof__(F_BFu0i_B)");
    check_field_offset(lv, v1, 0, "F_BFu0i_B.v1");
    check_field_offset(lv, v2, 4, "F_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vF_BFu0i_B(Test_F_BFu0i_B, "F_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  F_BFu0ll_B  {
  float v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 F_BFu0ll_B) C1{ Fi FL:0 Fc}



static void Test_F_BFu0ll_B()
{
  {
    init_simple_test("F_BFu0ll_B");
    static F_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(F_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(F_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "F_BFu0ll_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "F_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vF_BFu0ll_B(Test_F_BFu0ll_B, "F_BFu0ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  F_BFu0s_B  {
  float v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 F_BFu0s_B) C1{ Fi Fs:0 Fc}



static void Test_F_BFu0s_B()
{
  {
    init_simple_test("F_BFu0s_B");
    static F_BFu0s_B lv;
    check2(sizeof(lv), 8, "sizeof(F_BFu0s_B)");
    check2(__alignof__(lv), 4, "__alignof__(F_BFu0s_B)");
    check_field_offset(lv, v1, 0, "F_BFu0s_B.v1");
    check_field_offset(lv, v2, 4, "F_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vF_BFu0s_B(Test_F_BFu0s_B, "F_BFu0s_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  I_B_BFu0c  {
  int v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 I_B_BFu0c) C1{ Fi Fc Fc:0}



static void Test_I_B_BFu0c()
{
  {
    init_simple_test("I_B_BFu0c");
    static I_B_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(I_B_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(I_B_BFu0c)");
    check_field_offset(lv, v1, 0, "I_B_BFu0c.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vI_B_BFu0c(Test_I_B_BFu0c, "I_B_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  I_B_BFu0i  {
  int v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 I_B_BFu0i) C1{ Fi Fc Fi:0}



static void Test_I_B_BFu0i()
{
  {
    init_simple_test("I_B_BFu0i");
    static I_B_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(I_B_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(I_B_BFu0i)");
    check_field_offset(lv, v1, 0, "I_B_BFu0i.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vI_B_BFu0i(Test_I_B_BFu0i, "I_B_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  I_B_BFu0ll  {
  int v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 I_B_BFu0ll) C1{ Fi Fc FL:0}



static void Test_I_B_BFu0ll()
{
  {
    init_simple_test("I_B_BFu0ll");
    static I_B_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(I_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(I_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "I_B_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vI_B_BFu0ll(Test_I_B_BFu0ll, "I_B_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  I_B_BFu0s  {
  int v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 I_B_BFu0s) C1{ Fi Fc Fs:0}



static void Test_I_B_BFu0s()
{
  {
    init_simple_test("I_B_BFu0s");
    static I_B_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(I_B_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(I_B_BFu0s)");
    check_field_offset(lv, v1, 0, "I_B_BFu0s.v1");
    check_field_offset(lv, v2, 4, "I_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vI_B_BFu0s(Test_I_B_BFu0s, "I_B_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  I_BFu0c_B  {
  int v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 I_BFu0c_B) C1{ Fi Fc:0 Fc}



static void Test_I_BFu0c_B()
{
  {
    init_simple_test("I_BFu0c_B");
    static I_BFu0c_B lv;
    check2(sizeof(lv), 8, "sizeof(I_BFu0c_B)");
    check2(__alignof__(lv), 4, "__alignof__(I_BFu0c_B)");
    check_field_offset(lv, v1, 0, "I_BFu0c_B.v1");
    check_field_offset(lv, v2, 4, "I_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vI_BFu0c_B(Test_I_BFu0c_B, "I_BFu0c_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  I_BFu0i_B  {
  int v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 I_BFu0i_B) C1{ Fi Fi:0 Fc}



static void Test_I_BFu0i_B()
{
  {
    init_simple_test("I_BFu0i_B");
    static I_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(I_BFu0i_B)");
    check2(__alignof__(lv), 4, "__alignof__(I_BFu0i_B)");
    check_field_offset(lv, v1, 0, "I_BFu0i_B.v1");
    check_field_offset(lv, v2, 4, "I_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vI_BFu0i_B(Test_I_BFu0i_B, "I_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  I_BFu0ll_B  {
  int v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 I_BFu0ll_B) C1{ Fi FL:0 Fc}



static void Test_I_BFu0ll_B()
{
  {
    init_simple_test("I_BFu0ll_B");
    static I_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(I_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(I_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "I_BFu0ll_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "I_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vI_BFu0ll_B(Test_I_BFu0ll_B, "I_BFu0ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  I_BFu0s_B  {
  int v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 I_BFu0s_B) C1{ Fi Fs:0 Fc}



static void Test_I_BFu0s_B()
{
  {
    init_simple_test("I_BFu0s_B");
    static I_BFu0s_B lv;
    check2(sizeof(lv), 8, "sizeof(I_BFu0s_B)");
    check2(__alignof__(lv), 4, "__alignof__(I_BFu0s_B)");
    check_field_offset(lv, v1, 0, "I_BFu0s_B.v1");
    check_field_offset(lv, v2, 4, "I_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vI_BFu0s_B(Test_I_BFu0s_B, "I_BFu0s_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ip_B_BFu0c  {
  int *v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 Ip_B_BFu0c) C1{ Fp Fc Fc:0}



static void Test_Ip_B_BFu0c()
{
  {
    init_simple_test("Ip_B_BFu0c");
    static Ip_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ip_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_B_BFu0c)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vIp_B_BFu0c(Test_Ip_B_BFu0c, "Ip_B_BFu0c", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ip_B_BFu0i  {
  int *v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 Ip_B_BFu0i) C1{ Fp Fc Fi:0}



static void Test_Ip_B_BFu0i()
{
  {
    init_simple_test("Ip_B_BFu0i");
    static Ip_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ip_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_B_BFu0i)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vIp_B_BFu0i(Test_Ip_B_BFu0i, "Ip_B_BFu0i", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ip_B_BFu0ll  {
  int *v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 Ip_B_BFu0ll) C1{ Fp Fc FL:0}



static void Test_Ip_B_BFu0ll()
{
  {
    init_simple_test("Ip_B_BFu0ll");
    static Ip_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ip_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vIp_B_BFu0ll(Test_Ip_B_BFu0ll, "Ip_B_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ip_B_BFu0s  {
  int *v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 Ip_B_BFu0s) C1{ Fp Fc Fs:0}



static void Test_Ip_B_BFu0s()
{
  {
    init_simple_test("Ip_B_BFu0s");
    static Ip_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ip_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_B_BFu0s)");
    check_field_offset(lv, v1, 0, "Ip_B_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vIp_B_BFu0s(Test_Ip_B_BFu0s, "Ip_B_BFu0s", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ip_BFu0c_B  {
  int *v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 Ip_BFu0c_B) C1{ Fp Fc:0 Fc}



static void Test_Ip_BFu0c_B()
{
  {
    init_simple_test("Ip_BFu0c_B");
    static Ip_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ip_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_BFu0c_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu0c_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vIp_BFu0c_B(Test_Ip_BFu0c_B, "Ip_BFu0c_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ip_BFu0i_B  {
  int *v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 Ip_BFu0i_B) C1{ Fp Fi:0 Fc}



static void Test_Ip_BFu0i_B()
{
  {
    init_simple_test("Ip_BFu0i_B");
    static Ip_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ip_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_BFu0i_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu0i_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vIp_BFu0i_B(Test_Ip_BFu0i_B, "Ip_BFu0i_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ip_BFu0ll_B  {
  int *v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 Ip_BFu0ll_B) C1{ Fp FL:0 Fc}



static void Test_Ip_BFu0ll_B()
{
  {
    init_simple_test("Ip_BFu0ll_B");
    static Ip_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ip_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu0ll_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vIp_BFu0ll_B(Test_Ip_BFu0ll_B, "Ip_BFu0ll_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ip_BFu0s_B  {
  int *v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 Ip_BFu0s_B) C1{ Fp Fs:0 Fc}



static void Test_Ip_BFu0s_B()
{
  {
    init_simple_test("Ip_BFu0s_B");
    static Ip_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Ip_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_BFu0s_B)");
    check_field_offset(lv, v1, 0, "Ip_BFu0s_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vIp_BFu0s_B(Test_Ip_BFu0s_B, "Ip_BFu0s_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  L_B_BFu0c  {
  __tsi64 v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 L_B_BFu0c) C1{ FL Fc Fc:0}



static void Test_L_B_BFu0c()
{
  {
    init_simple_test("L_B_BFu0c");
    static L_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(L_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_B_BFu0c)");
    check_field_offset(lv, v1, 0, "L_B_BFu0c.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vL_B_BFu0c(Test_L_B_BFu0c, "L_B_BFu0c", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  L_B_BFu0i  {
  __tsi64 v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 L_B_BFu0i) C1{ FL Fc Fi:0}



static void Test_L_B_BFu0i()
{
  {
    init_simple_test("L_B_BFu0i");
    static L_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(L_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_B_BFu0i)");
    check_field_offset(lv, v1, 0, "L_B_BFu0i.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vL_B_BFu0i(Test_L_B_BFu0i, "L_B_BFu0i", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  L_B_BFu0ll  {
  __tsi64 v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 L_B_BFu0ll) C1{ FL Fc FL:0}



static void Test_L_B_BFu0ll()
{
  {
    init_simple_test("L_B_BFu0ll");
    static L_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(L_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "L_B_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vL_B_BFu0ll(Test_L_B_BFu0ll, "L_B_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  L_B_BFu0s  {
  __tsi64 v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 L_B_BFu0s) C1{ FL Fc Fs:0}



static void Test_L_B_BFu0s()
{
  {
    init_simple_test("L_B_BFu0s");
    static L_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(L_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_B_BFu0s)");
    check_field_offset(lv, v1, 0, "L_B_BFu0s.v1");
    check_field_offset(lv, v2, 8, "L_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vL_B_BFu0s(Test_L_B_BFu0s, "L_B_BFu0s", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  L_BFu0c_B  {
  __tsi64 v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 L_BFu0c_B) C1{ FL Fc:0 Fc}



static void Test_L_BFu0c_B()
{
  {
    init_simple_test("L_BFu0c_B");
    static L_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(L_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_BFu0c_B)");
    check_field_offset(lv, v1, 0, "L_BFu0c_B.v1");
    check_field_offset(lv, v2, 8, "L_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vL_BFu0c_B(Test_L_BFu0c_B, "L_BFu0c_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  L_BFu0i_B  {
  __tsi64 v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 L_BFu0i_B) C1{ FL Fi:0 Fc}



static void Test_L_BFu0i_B()
{
  {
    init_simple_test("L_BFu0i_B");
    static L_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(L_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_BFu0i_B)");
    check_field_offset(lv, v1, 0, "L_BFu0i_B.v1");
    check_field_offset(lv, v2, 8, "L_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vL_BFu0i_B(Test_L_BFu0i_B, "L_BFu0i_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  L_BFu0ll_B  {
  __tsi64 v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 L_BFu0ll_B) C1{ FL FL:0 Fc}



static void Test_L_BFu0ll_B()
{
  {
    init_simple_test("L_BFu0ll_B");
    static L_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(L_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "L_BFu0ll_B.v1");
    check_field_offset(lv, v2, 8, "L_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vL_BFu0ll_B(Test_L_BFu0ll_B, "L_BFu0ll_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  L_BFu0s_B  {
  __tsi64 v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 L_BFu0s_B) C1{ FL Fs:0 Fc}



static void Test_L_BFu0s_B()
{
  {
    init_simple_test("L_BFu0s_B");
    static L_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(L_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_BFu0s_B)");
    check_field_offset(lv, v1, 0, "L_BFu0s_B.v1");
    check_field_offset(lv, v2, 8, "L_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vL_BFu0s_B(Test_L_BFu0s_B, "L_BFu0s_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  S_B_BFu0c  {
  short v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 S_B_BFu0c) C1{ Fs Fc Fc:0}



static void Test_S_B_BFu0c()
{
  {
    init_simple_test("S_B_BFu0c");
    static S_B_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(S_B_BFu0c)");
    check_field_offset(lv, v1, 0, "S_B_BFu0c.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vS_B_BFu0c(Test_S_B_BFu0c, "S_B_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  S_B_BFu0i  {
  short v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 S_B_BFu0i) C1{ Fs Fc Fi:0}



static void Test_S_B_BFu0i()
{
  {
    init_simple_test("S_B_BFu0i");
    static S_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(S_B_BFu0i)");
    check_field_offset(lv, v1, 0, "S_B_BFu0i.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vS_B_BFu0i(Test_S_B_BFu0i, "S_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  S_B_BFu0ll  {
  short v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 S_B_BFu0ll) C1{ Fs Fc FL:0}



static void Test_S_B_BFu0ll()
{
  {
    init_simple_test("S_B_BFu0ll");
    static S_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(S_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(S_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "S_B_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vS_B_BFu0ll(Test_S_B_BFu0ll, "S_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  S_B_BFu0s  {
  short v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 S_B_BFu0s) C1{ Fs Fc Fs:0}



static void Test_S_B_BFu0s()
{
  {
    init_simple_test("S_B_BFu0s");
    static S_B_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(S_B_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(S_B_BFu0s)");
    check_field_offset(lv, v1, 0, "S_B_BFu0s.v1");
    check_field_offset(lv, v2, 2, "S_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vS_B_BFu0s(Test_S_B_BFu0s, "S_B_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  S_BFu0c_B  {
  short v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 S_BFu0c_B) C1{ Fs Fc:0 Fc}



static void Test_S_BFu0c_B()
{
  {
    init_simple_test("S_BFu0c_B");
    static S_BFu0c_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu0c_B)");
    check2(__alignof__(lv), 2, "__alignof__(S_BFu0c_B)");
    check_field_offset(lv, v1, 0, "S_BFu0c_B.v1");
    check_field_offset(lv, v2, 2, "S_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vS_BFu0c_B(Test_S_BFu0c_B, "S_BFu0c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  S_BFu0i_B  {
  short v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 S_BFu0i_B) C1{ Fs Fi:0 Fc}



static void Test_S_BFu0i_B()
{
  {
    init_simple_test("S_BFu0i_B");
    static S_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(S_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(S_BFu0i_B)");
    check_field_offset(lv, v1, 0, "S_BFu0i_B.v1");
    check_field_offset(lv, v2, 4, "S_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vS_BFu0i_B(Test_S_BFu0i_B, "S_BFu0i_B", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  S_BFu0ll_B  {
  short v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 S_BFu0ll_B) C1{ Fs FL:0 Fc}



static void Test_S_BFu0ll_B()
{
  {
    init_simple_test("S_BFu0ll_B");
    static S_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(S_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(S_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "S_BFu0ll_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "S_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vS_BFu0ll_B(Test_S_BFu0ll_B, "S_BFu0ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  S_BFu0s_B  {
  short v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 S_BFu0s_B) C1{ Fs Fs:0 Fc}



static void Test_S_BFu0s_B()
{
  {
    init_simple_test("S_BFu0s_B");
    static S_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu0s_B)");
    check2(__alignof__(lv), 2, "__alignof__(S_BFu0s_B)");
    check_field_offset(lv, v1, 0, "S_BFu0s_B.v1");
    check_field_offset(lv, v2, 2, "S_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vS_BFu0s_B(Test_S_BFu0s_B, "S_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Uc_B_BFu0c  {
  unsigned char v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 Uc_B_BFu0c) C1{ Fc[2] Fc:0}



static void Test_Uc_B_BFu0c()
{
  {
    init_simple_test("Uc_B_BFu0c");
    static Uc_B_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Uc_B_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_B_BFu0c)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu0c.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUc_B_BFu0c(Test_Uc_B_BFu0c, "Uc_B_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Uc_B_BFu0i  {
  unsigned char v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 Uc_B_BFu0i) C1{ Fc[2] Fi:0}



static void Test_Uc_B_BFu0i()
{
  {
    init_simple_test("Uc_B_BFu0i");
    static Uc_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Uc_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Uc_B_BFu0i)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu0i.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUc_B_BFu0i(Test_Uc_B_BFu0i, "Uc_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Uc_B_BFu0ll  {
  unsigned char v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 Uc_B_BFu0ll) C1{ Fc[2] FL:0}



static void Test_Uc_B_BFu0ll()
{
  {
    init_simple_test("Uc_B_BFu0ll");
    static Uc_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Uc_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Uc_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu0ll.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUc_B_BFu0ll(Test_Uc_B_BFu0ll, "Uc_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Uc_B_BFu0s  {
  unsigned char v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 Uc_B_BFu0s) C1{ Fc[2] Fs:0}



static void Test_Uc_B_BFu0s()
{
  {
    init_simple_test("Uc_B_BFu0s");
    static Uc_B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Uc_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Uc_B_BFu0s)");
    check_field_offset(lv, v1, 0, "Uc_B_BFu0s.v1");
    check_field_offset(lv, v2, 1, "Uc_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUc_B_BFu0s(Test_Uc_B_BFu0s, "Uc_B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Uc_BFu0c_B  {
  unsigned char v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 Uc_BFu0c_B) C1{ Fc Fc:0 Fc}



static void Test_Uc_BFu0c_B()
{
  {
    init_simple_test("Uc_BFu0c_B");
    static Uc_BFu0c_B lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu0c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu0c_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu0c_B.v1");
    check_field_offset(lv, v2, 1, "Uc_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vUc_BFu0c_B(Test_Uc_BFu0c_B, "Uc_BFu0c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Uc_BFu0i_B  {
  unsigned char v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 Uc_BFu0i_B) C1{ Fc Fi:0 Fc}



static void Test_Uc_BFu0i_B()
{
  {
    init_simple_test("Uc_BFu0i_B");
    static Uc_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Uc_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Uc_BFu0i_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu0i_B.v1");
    check_field_offset(lv, v2, 4, "Uc_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vUc_BFu0i_B(Test_Uc_BFu0i_B, "Uc_BFu0i_B", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Uc_BFu0ll_B  {
  unsigned char v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 Uc_BFu0ll_B) C1{ Fc FL:0 Fc}



static void Test_Uc_BFu0ll_B()
{
  {
    init_simple_test("Uc_BFu0ll_B");
    static Uc_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Uc_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Uc_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu0ll_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Uc_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vUc_BFu0ll_B(Test_Uc_BFu0ll_B, "Uc_BFu0ll_B", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Uc_BFu0s_B  {
  unsigned char v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 Uc_BFu0s_B) C1{ Fc Fs:0 Fc}



static void Test_Uc_BFu0s_B()
{
  {
    init_simple_test("Uc_BFu0s_B");
    static Uc_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Uc_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Uc_BFu0s_B)");
    check_field_offset(lv, v1, 0, "Uc_BFu0s_B.v1");
    check_field_offset(lv, v2, 2, "Uc_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vUc_BFu0s_B(Test_Uc_BFu0s_B, "Uc_BFu0s_B", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ui_B_BFu0c  {
  unsigned int v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 Ui_B_BFu0c) C1{ Fi Fc Fc:0}



static void Test_Ui_B_BFu0c()
{
  {
    init_simple_test("Ui_B_BFu0c");
    static Ui_B_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ui_B_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_B_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUi_B_BFu0c(Test_Ui_B_BFu0c, "Ui_B_BFu0c", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ui_B_BFu0i  {
  unsigned int v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 Ui_B_BFu0i) C1{ Fi Fc Fi:0}



static void Test_Ui_B_BFu0i()
{
  {
    init_simple_test("Ui_B_BFu0i");
    static Ui_B_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ui_B_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_B_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUi_B_BFu0i(Test_Ui_B_BFu0i, "Ui_B_BFu0i", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ui_B_BFu0ll  {
  unsigned int v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 Ui_B_BFu0ll) C1{ Fi Fc FL:0}



static void Test_Ui_B_BFu0ll()
{
  {
    init_simple_test("Ui_B_BFu0ll");
    static Ui_B_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ui_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Ui_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUi_B_BFu0ll(Test_Ui_B_BFu0ll, "Ui_B_BFu0ll", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ui_B_BFu0s  {
  unsigned int v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 Ui_B_BFu0s) C1{ Fi Fc Fs:0}



static void Test_Ui_B_BFu0s()
{
  {
    init_simple_test("Ui_B_BFu0s");
    static Ui_B_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ui_B_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_B_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_B_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUi_B_BFu0s(Test_Ui_B_BFu0s, "Ui_B_BFu0s", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ui_BFu0c_B  {
  unsigned int v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 Ui_BFu0c_B) C1{ Fi Fc:0 Fc}



static void Test_Ui_BFu0c_B()
{
  {
    init_simple_test("Ui_BFu0c_B");
    static Ui_BFu0c_B lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0c_B)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_BFu0c_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu0c_B.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0c_B(Test_Ui_BFu0c_B, "Ui_BFu0c_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ui_BFu0i_B  {
  unsigned int v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 Ui_BFu0i_B) C1{ Fi Fi:0 Fc}



static void Test_Ui_BFu0i_B()
{
  {
    init_simple_test("Ui_BFu0i_B");
    static Ui_BFu0i_B lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0i_B)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_BFu0i_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu0i_B.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0i_B(Test_Ui_BFu0i_B, "Ui_BFu0i_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ui_BFu0ll_B  {
  unsigned int v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 Ui_BFu0ll_B) C1{ Fi FL:0 Fc}



static void Test_Ui_BFu0ll_B()
{
  {
    init_simple_test("Ui_BFu0ll_B");
    static Ui_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(12,8), "sizeof(Ui_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Ui_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0ll_B(Test_Ui_BFu0ll_B, "Ui_BFu0ll_B", ABISELECT(12,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ui_BFu0s_B  {
  unsigned int v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 Ui_BFu0s_B) C1{ Fi Fs:0 Fc}



static void Test_Ui_BFu0s_B()
{
  {
    init_simple_test("Ui_BFu0s_B");
    static Ui_BFu0s_B lv;
    check2(sizeof(lv), 8, "sizeof(Ui_BFu0s_B)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_BFu0s_B)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_B.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vUi_BFu0s_B(Test_Ui_BFu0s_B, "Ui_BFu0s_B", 8);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ul_B_BFu0c  {
  __tsu64 v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 Ul_B_BFu0c) C1{ FL Fc Fc:0}



static void Test_Ul_B_BFu0c()
{
  {
    init_simple_test("Ul_B_BFu0c");
    static Ul_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_B_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUl_B_BFu0c(Test_Ul_B_BFu0c, "Ul_B_BFu0c", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ul_B_BFu0i  {
  __tsu64 v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 Ul_B_BFu0i) C1{ FL Fc Fi:0}



static void Test_Ul_B_BFu0i()
{
  {
    init_simple_test("Ul_B_BFu0i");
    static Ul_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_B_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUl_B_BFu0i(Test_Ul_B_BFu0i, "Ul_B_BFu0i", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ul_B_BFu0ll  {
  __tsu64 v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 Ul_B_BFu0ll) C1{ FL Fc FL:0}



static void Test_Ul_B_BFu0ll()
{
  {
    init_simple_test("Ul_B_BFu0ll");
    static Ul_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUl_B_BFu0ll(Test_Ul_B_BFu0ll, "Ul_B_BFu0ll", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ul_B_BFu0s  {
  __tsu64 v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 Ul_B_BFu0s) C1{ FL Fc Fs:0}



static void Test_Ul_B_BFu0s()
{
  {
    init_simple_test("Ul_B_BFu0s");
    static Ul_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_B_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_B_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUl_B_BFu0s(Test_Ul_B_BFu0s, "Ul_B_BFu0s", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ul_BFu0c_B  {
  __tsu64 v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 Ul_BFu0c_B) C1{ FL Fc:0 Fc}



static void Test_Ul_BFu0c_B()
{
  {
    init_simple_test("Ul_BFu0c_B");
    static Ul_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_BFu0c_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_B.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0c_B(Test_Ul_BFu0c_B, "Ul_BFu0c_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ul_BFu0i_B  {
  __tsu64 v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 Ul_BFu0i_B) C1{ FL Fi:0 Fc}



static void Test_Ul_BFu0i_B()
{
  {
    init_simple_test("Ul_BFu0i_B");
    static Ul_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_BFu0i_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_B.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0i_B(Test_Ul_BFu0i_B, "Ul_BFu0i_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ul_BFu0ll_B  {
  __tsu64 v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 Ul_BFu0ll_B) C1{ FL FL:0 Fc}



static void Test_Ul_BFu0ll_B()
{
  {
    init_simple_test("Ul_BFu0ll_B");
    static Ul_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_B.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0ll_B(Test_Ul_BFu0ll_B, "Ul_BFu0ll_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Ul_BFu0s_B  {
  __tsu64 v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 Ul_BFu0s_B) C1{ FL Fs:0 Fc}



static void Test_Ul_BFu0s_B()
{
  {
    init_simple_test("Ul_BFu0s_B");
    static Ul_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Ul_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_BFu0s_B)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_B.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vUl_BFu0s_B(Test_Ul_BFu0s_B, "Ul_BFu0s_B", ABISELECT(16,12));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Us_B_BFu0c  {
  unsigned short v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 Us_B_BFu0c) C1{ Fs Fc Fc:0}



static void Test_Us_B_BFu0c()
{
  {
    init_simple_test("Us_B_BFu0c");
    static Us_B_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(Us_B_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_B_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vUs_B_BFu0c(Test_Us_B_BFu0c, "Us_B_BFu0c", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Us_B_BFu0i  {
  unsigned short v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 Us_B_BFu0i) C1{ Fs Fc Fi:0}



static void Test_Us_B_BFu0i()
{
  {
    init_simple_test("Us_B_BFu0i");
    static Us_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Us_B_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_B_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vUs_B_BFu0i(Test_Us_B_BFu0i, "Us_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Us_B_BFu0ll  {
  unsigned short v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 Us_B_BFu0ll) C1{ Fs Fc FL:0}



static void Test_Us_B_BFu0ll()
{
  {
    init_simple_test("Us_B_BFu0ll");
    static Us_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Us_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_B_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vUs_B_BFu0ll(Test_Us_B_BFu0ll, "Us_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Us_B_BFu0s  {
  unsigned short v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 Us_B_BFu0s) C1{ Fs Fc Fs:0}



static void Test_Us_B_BFu0s()
{
  {
    init_simple_test("Us_B_BFu0s");
    static Us_B_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Us_B_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(Us_B_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_B_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vUs_B_BFu0s(Test_Us_B_BFu0s, "Us_B_BFu0s", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Us_BFu0c_B  {
  unsigned short v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 Us_BFu0c_B) C1{ Fs Fc:0 Fc}



static void Test_Us_BFu0c_B()
{
  {
    init_simple_test("Us_BFu0c_B");
    static Us_BFu0c_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0c_B)");
    check2(__alignof__(lv), 2, "__alignof__(Us_BFu0c_B)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_B.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0c_B(Test_Us_BFu0c_B, "Us_BFu0c_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Us_BFu0i_B  {
  unsigned short v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 Us_BFu0i_B) C1{ Fs Fi:0 Fc}



static void Test_Us_BFu0i_B()
{
  {
    init_simple_test("Us_BFu0i_B");
    static Us_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(6,6), "sizeof(Us_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Us_BFu0i_B)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_B.v1");
    check_field_offset(lv, v2, 4, "Us_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0i_B(Test_Us_BFu0i_B, "Us_BFu0i_B", ABISELECT(6,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Us_BFu0ll_B  {
  unsigned short v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 Us_BFu0ll_B) C1{ Fs FL:0 Fc}



static void Test_Us_BFu0ll_B()
{
  {
    init_simple_test("Us_BFu0ll_B");
    static Us_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(10,6), "sizeof(Us_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Us_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0ll_B(Test_Us_BFu0ll_B, "Us_BFu0ll_B", ABISELECT(10,6));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Us_BFu0s_B  {
  unsigned short v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 Us_BFu0s_B) C1{ Fs Fs:0 Fc}



static void Test_Us_BFu0s_B()
{
  {
    init_simple_test("Us_BFu0s_B");
    static Us_BFu0s_B lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0s_B)");
    check2(__alignof__(lv), 2, "__alignof__(Us_BFu0s_B)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_B.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vUs_BFu0s_B(Test_Us_BFu0s_B, "Us_BFu0s_B", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Vp_B_BFu0c  {
  void *v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 Vp_B_BFu0c) C1{ Fp Fc Fc:0}



static void Test_Vp_B_BFu0c()
{
  {
    init_simple_test("Vp_B_BFu0c");
    static Vp_B_BFu0c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_B_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_B_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vVp_B_BFu0c(Test_Vp_B_BFu0c, "Vp_B_BFu0c", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Vp_B_BFu0i  {
  void *v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 Vp_B_BFu0i) C1{ Fp Fc Fi:0}



static void Test_Vp_B_BFu0i()
{
  {
    init_simple_test("Vp_B_BFu0i");
    static Vp_B_BFu0i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_B_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vVp_B_BFu0i(Test_Vp_B_BFu0i, "Vp_B_BFu0i", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Vp_B_BFu0ll  {
  void *v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 Vp_B_BFu0ll) C1{ Fp Fc FL:0}



static void Test_Vp_B_BFu0ll()
{
  {
    init_simple_test("Vp_B_BFu0ll");
    static Vp_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vVp_B_BFu0ll(Test_Vp_B_BFu0ll, "Vp_B_BFu0ll", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Vp_B_BFu0s  {
  void *v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 Vp_B_BFu0s) C1{ Fp Fc Fs:0}



static void Test_Vp_B_BFu0s()
{
  {
    init_simple_test("Vp_B_BFu0s");
    static Vp_B_BFu0s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_B_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_B_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vVp_B_BFu0s(Test_Vp_B_BFu0s, "Vp_B_BFu0s", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Vp_BFu0c_B  {
  void *v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 Vp_BFu0c_B) C1{ Fp Fc:0 Fc}



static void Test_Vp_BFu0c_B()
{
  {
    init_simple_test("Vp_BFu0c_B");
    static Vp_BFu0c_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0c_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu0c_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0c_B(Test_Vp_BFu0c_B, "Vp_BFu0c_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Vp_BFu0i_B  {
  void *v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 Vp_BFu0i_B) C1{ Fp Fi:0 Fc}



static void Test_Vp_BFu0i_B()
{
  {
    init_simple_test("Vp_BFu0i_B");
    static Vp_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu0i_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0i_B(Test_Vp_BFu0i_B, "Vp_BFu0i_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Vp_BFu0ll_B  {
  void *v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 Vp_BFu0ll_B) C1{ Fp FL:0 Fc}



static void Test_Vp_BFu0ll_B()
{
  {
    init_simple_test("Vp_BFu0ll_B");
    static Vp_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0ll_B(Test_Vp_BFu0ll_B, "Vp_BFu0ll_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Vp_BFu0s_B  {
  void *v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 Vp_BFu0s_B) C1{ Fp Fs:0 Fc}



static void Test_Vp_BFu0s_B()
{
  {
    init_simple_test("Vp_BFu0s_B");
    static Vp_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu0s_B)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vVp_BFu0s_B(Test_Vp_BFu0s_B, "Vp_BFu0s_B", ABISELECT(16,8));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

