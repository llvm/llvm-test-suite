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

struct  B_BFu0c_Sf  {
  bool v1;
  unsigned char  :0;
  ::empty v2;
};
//SIG(1 B_BFu0c_Sf) C1{ Fc Fc:0 FC2{}}



static void Test_B_BFu0c_Sf()
{
  {
    init_simple_test("B_BFu0c_Sf");
    static B_BFu0c_Sf lv;
    check2(sizeof(lv), 2, "sizeof(B_BFu0c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(B_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu0c_Sf.v1");
    check_field_offset(lv, v2, 1, "B_BFu0c_Sf.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0c_Sf(Test_B_BFu0c_Sf, "B_BFu0c_Sf", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0i_Sf  {
  bool v1;
  unsigned int  :0;
  ::empty v2;
};
//SIG(1 B_BFu0i_Sf) C1{ Fc Fi:0 FC2{}}



static void Test_B_BFu0i_Sf()
{
  {
    init_simple_test("B_BFu0i_Sf");
    static B_BFu0i_Sf lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(B_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu0i_Sf.v1");
    check_field_offset(lv, v2, 4, "B_BFu0i_Sf.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0i_Sf(Test_B_BFu0i_Sf, "B_BFu0i_Sf", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0ll_Sf  {
  bool v1;
  __tsu64  :0;
  ::empty v2;
};
//SIG(1 B_BFu0ll_Sf) C1{ Fc FL:0 FC2{}}



static void Test_B_BFu0ll_Sf()
{
  {
    init_simple_test("B_BFu0ll_Sf");
    static B_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(B_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "B_BFu0ll_Sf.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0ll_Sf(Test_B_BFu0ll_Sf, "B_BFu0ll_Sf", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_BFu0s_Sf  {
  bool v1;
  unsigned short  :0;
  ::empty v2;
};
//SIG(1 B_BFu0s_Sf) C1{ Fc Fs:0 FC2{}}



static void Test_B_BFu0s_Sf()
{
  {
    init_simple_test("B_BFu0s_Sf");
    static B_BFu0s_Sf lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(B_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "B_BFu0s_Sf.v1");
    check_field_offset(lv, v2, 2, "B_BFu0s_Sf.v2");
  }
}
static Arrange_To_Call_Me vB_BFu0s_Sf(Test_B_BFu0s_Sf, "B_BFu0s_Sf", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu0c  {
  bool v1;
  ::empty v2;
  unsigned char  :0;
};
//SIG(1 B_Sf_BFu0c) C1{ Fc FC2{} Fc:0}



static void Test_B_Sf_BFu0c()
{
  {
    init_simple_test("B_Sf_BFu0c");
    static B_Sf_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(B_Sf_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(B_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu0c.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu0c(Test_B_Sf_BFu0c, "B_Sf_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu0i  {
  bool v1;
  ::empty v2;
  unsigned int  :0;
};
//SIG(1 B_Sf_BFu0i) C1{ Fc FC2{} Fi:0}



static void Test_B_Sf_BFu0i()
{
  {
    init_simple_test("B_Sf_BFu0i");
    static B_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(B_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu0i.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu0i(Test_B_Sf_BFu0i, "B_Sf_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu0ll  {
  bool v1;
  ::empty v2;
  __tsu64  :0;
};
//SIG(1 B_Sf_BFu0ll) C1{ Fc FC2{} FL:0}



static void Test_B_Sf_BFu0ll()
{
  {
    init_simple_test("B_Sf_BFu0ll");
    static B_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(B_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu0ll(Test_B_Sf_BFu0ll, "B_Sf_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  B_Sf_BFu0s  {
  bool v1;
  ::empty v2;
  unsigned short  :0;
};
//SIG(1 B_Sf_BFu0s) C1{ Fc FC2{} Fs:0}



static void Test_B_Sf_BFu0s()
{
  {
    init_simple_test("B_Sf_BFu0s");
    static B_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(B_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(B_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "B_Sf_BFu0s.v1");
    check_field_offset(lv, v2, 1, "B_Sf_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vB_Sf_BFu0s(Test_B_Sf_BFu0s, "B_Sf_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_B_Sf  {
  unsigned char  :0;
  bool v1;
  ::empty v2;
};
//SIG(1 BFu0c_B_Sf) C1{ Fc:0 Fc FC2{}}



static void Test_BFu0c_B_Sf()
{
  {
    init_simple_test("BFu0c_B_Sf");
    static BFu0c_B_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_B_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_B_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_B_Sf.v1");
    check_field_offset(lv, v2, 1, "BFu0c_B_Sf.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_B_Sf(Test_BFu0c_B_Sf, "BFu0c_B_Sf", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0c_Sf_B  {
  unsigned char  :0;
  ::empty v1;
  bool v2;
};
//SIG(1 BFu0c_Sf_B) C1{ Fc:0 FC2{} Fc}



static void Test_BFu0c_Sf_B()
{
  {
    init_simple_test("BFu0c_Sf_B");
    static BFu0c_Sf_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_Sf_B)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_Sf_B)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_B.v1");
    check_field_offset(lv, v2, 1, "BFu0c_Sf_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0c_Sf_B(Test_BFu0c_Sf_B, "BFu0c_Sf_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_B_Sf  {
  unsigned int  :0;
  bool v1;
  ::empty v2;
};
//SIG(1 BFu0i_B_Sf) C1{ Fi:0 Fc FC2{}}



static void Test_BFu0i_B_Sf()
{
  {
    init_simple_test("BFu0i_B_Sf");
    static BFu0i_B_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_B_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_B_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_B_Sf.v1");
    check_field_offset(lv, v2, 1, "BFu0i_B_Sf.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_B_Sf(Test_BFu0i_B_Sf, "BFu0i_B_Sf", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0i_Sf_B  {
  unsigned int  :0;
  ::empty v1;
  bool v2;
};
//SIG(1 BFu0i_Sf_B) C1{ Fi:0 FC2{} Fc}



static void Test_BFu0i_Sf_B()
{
  {
    init_simple_test("BFu0i_Sf_B");
    static BFu0i_Sf_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_Sf_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Sf_B)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_B.v1");
    check_field_offset(lv, v2, 1, "BFu0i_Sf_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0i_Sf_B(Test_BFu0i_Sf_B, "BFu0i_Sf_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_B_Sf  {
  __tsu64  :0;
  bool v1;
  ::empty v2;
};
//SIG(1 BFu0ll_B_Sf) C1{ FL:0 Fc FC2{}}



static void Test_BFu0ll_B_Sf()
{
  {
    init_simple_test("BFu0ll_B_Sf");
    static BFu0ll_B_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_B_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_B_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_B_Sf.v1");
    check_field_offset(lv, v2, 1, "BFu0ll_B_Sf.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_B_Sf(Test_BFu0ll_B_Sf, "BFu0ll_B_Sf", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0ll_Sf_B  {
  __tsu64  :0;
  ::empty v1;
  bool v2;
};
//SIG(1 BFu0ll_Sf_B) C1{ FL:0 FC2{} Fc}



static void Test_BFu0ll_Sf_B()
{
  {
    init_simple_test("BFu0ll_Sf_B");
    static BFu0ll_Sf_B lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_Sf_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Sf_B)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_B.v1");
    check_field_offset(lv, v2, 1, "BFu0ll_Sf_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0ll_Sf_B(Test_BFu0ll_Sf_B, "BFu0ll_Sf_B", ABISELECT(2,2));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_B_Sf  {
  unsigned short  :0;
  bool v1;
  ::empty v2;
};
//SIG(1 BFu0s_B_Sf) C1{ Fs:0 Fc FC2{}}



static void Test_BFu0s_B_Sf()
{
  {
    init_simple_test("BFu0s_B_Sf");
    static BFu0s_B_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_B_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_B_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_B_Sf.v1");
    check_field_offset(lv, v2, 1, "BFu0s_B_Sf.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_B_Sf(Test_BFu0s_B_Sf, "BFu0s_B_Sf", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  BFu0s_Sf_B  {
  unsigned short  :0;
  ::empty v1;
  bool v2;
};
//SIG(1 BFu0s_Sf_B) C1{ Fs:0 FC2{} Fc}



static void Test_BFu0s_Sf_B()
{
  {
    init_simple_test("BFu0s_Sf_B");
    static BFu0s_Sf_B lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_Sf_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Sf_B)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_B.v1");
    check_field_offset(lv, v2, 1, "BFu0s_Sf_B.v2");
  }
}
static Arrange_To_Call_Me vBFu0s_Sf_B(Test_BFu0s_Sf_B, "BFu0s_Sf_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu0c  {
  ::empty v1;
  bool v2;
  unsigned char  :0;
};
//SIG(1 Sf_B_BFu0c) C1{ FC2{} Fc Fc:0}



static void Test_Sf_B_BFu0c()
{
  {
    init_simple_test("Sf_B_BFu0c");
    static Sf_B_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_B_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_B_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu0c.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu0c.v2");
  }
}
static Arrange_To_Call_Me vSf_B_BFu0c(Test_Sf_B_BFu0c, "Sf_B_BFu0c", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu0i  {
  ::empty v1;
  bool v2;
  unsigned int  :0;
};
//SIG(1 Sf_B_BFu0i) C1{ FC2{} Fc Fi:0}



static void Test_Sf_B_BFu0i()
{
  {
    init_simple_test("Sf_B_BFu0i");
    static Sf_B_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_B_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_B_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu0i.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu0i.v2");
  }
}
static Arrange_To_Call_Me vSf_B_BFu0i(Test_Sf_B_BFu0i, "Sf_B_BFu0i", 4);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu0ll  {
  ::empty v1;
  bool v2;
  __tsu64  :0;
};
//SIG(1 Sf_B_BFu0ll) C1{ FC2{} Fc FL:0}



static void Test_Sf_B_BFu0ll()
{
  {
    init_simple_test("Sf_B_BFu0ll");
    static Sf_B_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_B_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_B_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu0ll.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu0ll.v2");
  }
}
static Arrange_To_Call_Me vSf_B_BFu0ll(Test_Sf_B_BFu0ll, "Sf_B_BFu0ll", ABISELECT(8,4));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_B_BFu0s  {
  ::empty v1;
  bool v2;
  unsigned short  :0;
};
//SIG(1 Sf_B_BFu0s) C1{ FC2{} Fc Fs:0}



static void Test_Sf_B_BFu0s()
{
  {
    init_simple_test("Sf_B_BFu0s");
    static Sf_B_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_B_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_B_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_B_BFu0s.v1");
    check_field_offset(lv, v2, 1, "Sf_B_BFu0s.v2");
  }
}
static Arrange_To_Call_Me vSf_B_BFu0s(Test_Sf_B_BFu0s, "Sf_B_BFu0s", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu0c_B  {
  ::empty v1;
  unsigned char  :0;
  bool v2;
};
//SIG(1 Sf_BFu0c_B) C1{ FC2{} Fc:0 Fc}



static void Test_Sf_BFu0c_B()
{
  {
    init_simple_test("Sf_BFu0c_B");
    static Sf_BFu0c_B lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0c_B)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu0c_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_B.v1");
    check_field_offset(lv, v2, 1, "Sf_BFu0c_B.v2");
  }
}
static Arrange_To_Call_Me vSf_BFu0c_B(Test_Sf_BFu0c_B, "Sf_BFu0c_B", 2);

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu0i_B  {
  ::empty v1;
  unsigned int  :0;
  bool v2;
};
//SIG(1 Sf_BFu0i_B) C1{ FC2{} Fi:0 Fc}



static void Test_Sf_BFu0i_B()
{
  {
    init_simple_test("Sf_BFu0i_B");
    static Sf_BFu0i_B lv;
    check2(sizeof(lv), ABISELECT(5,5), "sizeof(Sf_BFu0i_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0i_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_B.v1");
    check_field_offset(lv, v2, 4, "Sf_BFu0i_B.v2");
  }
}
static Arrange_To_Call_Me vSf_BFu0i_B(Test_Sf_BFu0i_B, "Sf_BFu0i_B", ABISELECT(5,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu0ll_B  {
  ::empty v1;
  __tsu64  :0;
  bool v2;
};
//SIG(1 Sf_BFu0ll_B) C1{ FC2{} FL:0 Fc}



static void Test_Sf_BFu0ll_B()
{
  {
    init_simple_test("Sf_BFu0ll_B");
    static Sf_BFu0ll_B lv;
    check2(sizeof(lv), ABISELECT(9,5), "sizeof(Sf_BFu0ll_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0ll_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_B.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Sf_BFu0ll_B.v2");
  }
}
static Arrange_To_Call_Me vSf_BFu0ll_B(Test_Sf_BFu0ll_B, "Sf_BFu0ll_B", ABISELECT(9,5));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Sf_BFu0s_B  {
  ::empty v1;
  unsigned short  :0;
  bool v2;
};
//SIG(1 Sf_BFu0s_B) C1{ FC2{} Fs:0 Fc}



static void Test_Sf_BFu0s_B()
{
  {
    init_simple_test("Sf_BFu0s_B");
    static Sf_BFu0s_B lv;
    check2(sizeof(lv), ABISELECT(3,3), "sizeof(Sf_BFu0s_B)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0s_B)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_B.v1");
    check_field_offset(lv, v2, 2, "Sf_BFu0s_B.v2");
  }
}
static Arrange_To_Call_Me vSf_BFu0s_B(Test_Sf_BFu0s_B, "Sf_BFu0s_B", ABISELECT(3,3));

#else // __cplusplus

#endif // __cplusplus

//============================================================================

