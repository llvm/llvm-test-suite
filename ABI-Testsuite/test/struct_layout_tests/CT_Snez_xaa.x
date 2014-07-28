// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: c_compiler -c %s -I "common" -o %t2.o
// RUN: linker -o %t1%exeext  %t1.o %t2.o
// RUN: runtool %t1%exeext | checker "TEST PASSED"
#include "testsuite.h"

struct  empty  {
};
//SIG(-1 empty) C1{}



static void Test_empty()
{
  {
    init_simple_test("empty");
    STRUCT_IF_C empty lv;
    check2(sizeof(lv), 0, "sizeof(empty)");
    check2(__alignof__(lv), 1, "__alignof__(empty)");
  }
}
ARRANGE_TO_CALL_ME(Test_empty, empty)
//============================================================================


struct  BFu0c_BFu0c_Sf  {
  unsigned char  :0;
  unsigned char  :0;
  struct empty v1;
};
//SIG(1 BFu0c_BFu0c_Sf) C1{ Fc:0 Fc:0 FC2{}}



static void Test_BFu0c_BFu0c_Sf()
{
  {
    init_simple_test("BFu0c_BFu0c_Sf");
    static STRUCT_IF_C BFu0c_BFu0c_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0c_BFu0c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_BFu0c_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu0c_Sf, BFu0c_BFu0c_Sf)
//============================================================================


struct  BFu0c_BFu0i_Sf  {
  unsigned char  :0;
  unsigned int  :0;
  struct empty v1;
};
//SIG(1 BFu0c_BFu0i_Sf) C1{ Fc:0 Fi:0 FC2{}}



static void Test_BFu0c_BFu0i_Sf()
{
  {
    init_simple_test("BFu0c_BFu0i_Sf");
    static STRUCT_IF_C BFu0c_BFu0i_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0c_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0c_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_BFu0i_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu0i_Sf, BFu0c_BFu0i_Sf)
//============================================================================


struct  BFu0c_BFu0ll_Sf  {
  unsigned char  :0;
  __tsu64  :0;
  struct empty v1;
};
//SIG(1 BFu0c_BFu0ll_Sf) C1{ Fc:0 FL:0 FC2{}}



static void Test_BFu0c_BFu0ll_Sf()
{
  {
    init_simple_test("BFu0c_BFu0ll_Sf");
    static STRUCT_IF_C BFu0c_BFu0ll_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0c_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0c_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_BFu0ll_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu0ll_Sf, BFu0c_BFu0ll_Sf)
//============================================================================


struct  BFu0c_BFu0s_Sf  {
  unsigned char  :0;
  unsigned short  :0;
  struct empty v1;
};
//SIG(1 BFu0c_BFu0s_Sf) C1{ Fc:0 Fs:0 FC2{}}



static void Test_BFu0c_BFu0s_Sf()
{
  {
    init_simple_test("BFu0c_BFu0s_Sf");
    static STRUCT_IF_C BFu0c_BFu0s_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0c_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0c_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_BFu0s_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu0s_Sf, BFu0c_BFu0s_Sf)
//============================================================================


struct  BFu0c_BFu15i_Sf  {
  unsigned char  :0;
  unsigned int v1:15;
  struct empty v2;
};
//SIG(1 BFu0c_BFu15i_Sf) C1{ Fc:0 Fi:15 FC2{}}



static void Test_BFu0c_BFu15i_Sf()
{
  {
    init_simple_test("BFu0c_BFu15i_Sf");
    static STRUCT_IF_C BFu0c_BFu15i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu15i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu15i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0c_BFu15i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0c_BFu15i_Sf");
    check_field_offset(lv, v2, 2, "BFu0c_BFu15i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu15i_Sf, BFu0c_BFu15i_Sf)
//============================================================================


struct  BFu0c_BFu15ll_Sf  {
  unsigned char  :0;
  __tsu64 v1:15;
  struct empty v2;
};
//SIG(1 BFu0c_BFu15ll_Sf) C1{ Fc:0 FL:15 FC2{}}



static void Test_BFu0c_BFu15ll_Sf()
{
  {
    init_simple_test("BFu0c_BFu15ll_Sf");
    static STRUCT_IF_C BFu0c_BFu15ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu15ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu15ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0c_BFu15ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0c_BFu15ll_Sf");
    check_field_offset(lv, v2, 2, "BFu0c_BFu15ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu15ll_Sf, BFu0c_BFu15ll_Sf)
//============================================================================


struct  BFu0c_BFu15s_Sf  {
  unsigned char  :0;
  unsigned short v1:15;
  struct empty v2;
};
//SIG(1 BFu0c_BFu15s_Sf) C1{ Fc:0 Fs:15 FC2{}}



static void Test_BFu0c_BFu15s_Sf()
{
  {
    init_simple_test("BFu0c_BFu15s_Sf");
    static STRUCT_IF_C BFu0c_BFu15s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_BFu15s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_BFu15s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0c_BFu15s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0c_BFu15s_Sf");
    check_field_offset(lv, v2, 2, "BFu0c_BFu15s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu15s_Sf, BFu0c_BFu15s_Sf)
//============================================================================


struct  BFu0c_BFu16i_Sf  {
  unsigned char  :0;
  unsigned int v1:16;
  struct empty v2;
};
//SIG(1 BFu0c_BFu16i_Sf) C1{ Fc:0 Fi:16 FC2{}}



static void Test_BFu0c_BFu16i_Sf()
{
  {
    init_simple_test("BFu0c_BFu16i_Sf");
    static STRUCT_IF_C BFu0c_BFu16i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu16i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu16i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0c_BFu16i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0c_BFu16i_Sf");
    check_field_offset(lv, v2, 2, "BFu0c_BFu16i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu16i_Sf, BFu0c_BFu16i_Sf)
//============================================================================


struct  BFu0c_BFu16ll_Sf  {
  unsigned char  :0;
  __tsu64 v1:16;
  struct empty v2;
};
//SIG(1 BFu0c_BFu16ll_Sf) C1{ Fc:0 FL:16 FC2{}}



static void Test_BFu0c_BFu16ll_Sf()
{
  {
    init_simple_test("BFu0c_BFu16ll_Sf");
    static STRUCT_IF_C BFu0c_BFu16ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu16ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu16ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0c_BFu16ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0c_BFu16ll_Sf");
    check_field_offset(lv, v2, 2, "BFu0c_BFu16ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu16ll_Sf, BFu0c_BFu16ll_Sf)
//============================================================================


struct  BFu0c_BFu16s_Sf  {
  unsigned char  :0;
  unsigned short v1:16;
  struct empty v2;
};
//SIG(1 BFu0c_BFu16s_Sf) C1{ Fc:0 Fs:16 FC2{}}



static void Test_BFu0c_BFu16s_Sf()
{
  {
    init_simple_test("BFu0c_BFu16s_Sf");
    static STRUCT_IF_C BFu0c_BFu16s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_BFu16s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_BFu16s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0c_BFu16s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0c_BFu16s_Sf");
    check_field_offset(lv, v2, 2, "BFu0c_BFu16s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu16s_Sf, BFu0c_BFu16s_Sf)
//============================================================================


struct  BFu0c_BFu17i_Sf  {
  unsigned char  :0;
  unsigned int v1:17;
  struct empty v2;
};
//SIG(1 BFu0c_BFu17i_Sf) C1{ Fc:0 Fi:17 FC2{}}



static void Test_BFu0c_BFu17i_Sf()
{
  {
    init_simple_test("BFu0c_BFu17i_Sf");
    static STRUCT_IF_C BFu0c_BFu17i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu17i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu17i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0c_BFu17i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0c_BFu17i_Sf");
    check_field_offset(lv, v2, 3, "BFu0c_BFu17i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu17i_Sf, BFu0c_BFu17i_Sf)
//============================================================================


struct  BFu0c_BFu17ll_Sf  {
  unsigned char  :0;
  __tsu64 v1:17;
  struct empty v2;
};
//SIG(1 BFu0c_BFu17ll_Sf) C1{ Fc:0 FL:17 FC2{}}



static void Test_BFu0c_BFu17ll_Sf()
{
  {
    init_simple_test("BFu0c_BFu17ll_Sf");
    static STRUCT_IF_C BFu0c_BFu17ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu17ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu17ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0c_BFu17ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0c_BFu17ll_Sf");
    check_field_offset(lv, v2, 3, "BFu0c_BFu17ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu17ll_Sf, BFu0c_BFu17ll_Sf)
//============================================================================


struct  BFu0c_BFu1c_Sf  {
  unsigned char  :0;
  unsigned char v1:1;
  struct empty v2;
};
//SIG(1 BFu0c_BFu1c_Sf) C1{ Fc:0 Fc:1 FC2{}}



static void Test_BFu0c_BFu1c_Sf()
{
  {
    init_simple_test("BFu0c_BFu1c_Sf");
    static STRUCT_IF_C BFu0c_BFu1c_Sf lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_BFu1c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_BFu1c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0c_BFu1c_Sf");
    check_field_offset(lv, v2, 1, "BFu0c_BFu1c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu1c_Sf, BFu0c_BFu1c_Sf)
//============================================================================


struct  BFu0c_BFu1i_Sf  {
  unsigned char  :0;
  unsigned int v1:1;
  struct empty v2;
};
//SIG(1 BFu0c_BFu1i_Sf) C1{ Fc:0 Fi:1 FC2{}}



static void Test_BFu0c_BFu1i_Sf()
{
  {
    init_simple_test("BFu0c_BFu1i_Sf");
    static STRUCT_IF_C BFu0c_BFu1i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu1i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu1i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0c_BFu1i_Sf");
    check_field_offset(lv, v2, 1, "BFu0c_BFu1i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu1i_Sf, BFu0c_BFu1i_Sf)
//============================================================================


struct  BFu0c_BFu1ll_Sf  {
  unsigned char  :0;
  __tsu64 v1:1;
  struct empty v2;
};
//SIG(1 BFu0c_BFu1ll_Sf) C1{ Fc:0 FL:1 FC2{}}



static void Test_BFu0c_BFu1ll_Sf()
{
  {
    init_simple_test("BFu0c_BFu1ll_Sf");
    static STRUCT_IF_C BFu0c_BFu1ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu1ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu1ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0c_BFu1ll_Sf");
    check_field_offset(lv, v2, 1, "BFu0c_BFu1ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu1ll_Sf, BFu0c_BFu1ll_Sf)
//============================================================================


struct  BFu0c_BFu1s_Sf  {
  unsigned char  :0;
  unsigned short v1:1;
  struct empty v2;
};
//SIG(1 BFu0c_BFu1s_Sf) C1{ Fc:0 Fs:1 FC2{}}



static void Test_BFu0c_BFu1s_Sf()
{
  {
    init_simple_test("BFu0c_BFu1s_Sf");
    static STRUCT_IF_C BFu0c_BFu1s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_BFu1s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_BFu1s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0c_BFu1s_Sf");
    check_field_offset(lv, v2, 1, "BFu0c_BFu1s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu1s_Sf, BFu0c_BFu1s_Sf)
//============================================================================


struct  BFu0c_BFu31i_Sf  {
  unsigned char  :0;
  unsigned int v1:31;
  struct empty v2;
};
//SIG(1 BFu0c_BFu31i_Sf) C1{ Fc:0 Fi:31 FC2{}}



static void Test_BFu0c_BFu31i_Sf()
{
  {
    init_simple_test("BFu0c_BFu31i_Sf");
    static STRUCT_IF_C BFu0c_BFu31i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu31i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu31i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0c_BFu31i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0c_BFu31i_Sf");
    check_field_offset(lv, v2, 4, "BFu0c_BFu31i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu31i_Sf, BFu0c_BFu31i_Sf)
//============================================================================


struct  BFu0c_BFu31ll_Sf  {
  unsigned char  :0;
  __tsu64 v1:31;
  struct empty v2;
};
//SIG(1 BFu0c_BFu31ll_Sf) C1{ Fc:0 FL:31 FC2{}}



static void Test_BFu0c_BFu31ll_Sf()
{
  {
    init_simple_test("BFu0c_BFu31ll_Sf");
    static STRUCT_IF_C BFu0c_BFu31ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu31ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu31ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0c_BFu31ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0c_BFu31ll_Sf");
    check_field_offset(lv, v2, 4, "BFu0c_BFu31ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu31ll_Sf, BFu0c_BFu31ll_Sf)
//============================================================================


struct  BFu0c_BFu32i_Sf  {
  unsigned char  :0;
  unsigned int v1:32;
  struct empty v2;
};
//SIG(1 BFu0c_BFu32i_Sf) C1{ Fc:0 Fi:32 FC2{}}



static void Test_BFu0c_BFu32i_Sf()
{
  {
    init_simple_test("BFu0c_BFu32i_Sf");
    static STRUCT_IF_C BFu0c_BFu32i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu32i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu32i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0c_BFu32i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0c_BFu32i_Sf");
    check_field_offset(lv, v2, 4, "BFu0c_BFu32i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu32i_Sf, BFu0c_BFu32i_Sf)
//============================================================================


struct  BFu0c_BFu32ll_Sf  {
  unsigned char  :0;
  __tsu64 v1:32;
  struct empty v2;
};
//SIG(1 BFu0c_BFu32ll_Sf) C1{ Fc:0 FL:32 FC2{}}



static void Test_BFu0c_BFu32ll_Sf()
{
  {
    init_simple_test("BFu0c_BFu32ll_Sf");
    static STRUCT_IF_C BFu0c_BFu32ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu32ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu32ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0c_BFu32ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0c_BFu32ll_Sf");
    check_field_offset(lv, v2, 4, "BFu0c_BFu32ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu32ll_Sf, BFu0c_BFu32ll_Sf)
//============================================================================


struct  BFu0c_BFu33_Sf  {
  unsigned char  :0;
  __tsu64 v1:33;
  struct empty v2;
};
//SIG(1 BFu0c_BFu33_Sf) C1{ Fc:0 FL:33 FC2{}}



static void Test_BFu0c_BFu33_Sf()
{
  {
    init_simple_test("BFu0c_BFu33_Sf");
    static STRUCT_IF_C BFu0c_BFu33_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_BFu33_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu33_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu0c_BFu33_Sf");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu0c_BFu33_Sf");
    check_field_offset(lv, v2, 5, "BFu0c_BFu33_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu33_Sf, BFu0c_BFu33_Sf)
//============================================================================


struct  BFu0c_BFu7c_Sf  {
  unsigned char  :0;
  unsigned char v1:7;
  struct empty v2;
};
//SIG(1 BFu0c_BFu7c_Sf) C1{ Fc:0 Fc:7 FC2{}}



static void Test_BFu0c_BFu7c_Sf()
{
  {
    init_simple_test("BFu0c_BFu7c_Sf");
    static STRUCT_IF_C BFu0c_BFu7c_Sf lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_BFu7c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_BFu7c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0c_BFu7c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0c_BFu7c_Sf");
    check_field_offset(lv, v2, 1, "BFu0c_BFu7c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu7c_Sf, BFu0c_BFu7c_Sf)
//============================================================================


struct  BFu0c_BFu7i_Sf  {
  unsigned char  :0;
  unsigned int v1:7;
  struct empty v2;
};
//SIG(1 BFu0c_BFu7i_Sf) C1{ Fc:0 Fi:7 FC2{}}



static void Test_BFu0c_BFu7i_Sf()
{
  {
    init_simple_test("BFu0c_BFu7i_Sf");
    static STRUCT_IF_C BFu0c_BFu7i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu7i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu7i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0c_BFu7i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0c_BFu7i_Sf");
    check_field_offset(lv, v2, 1, "BFu0c_BFu7i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu7i_Sf, BFu0c_BFu7i_Sf)
//============================================================================


struct  BFu0c_BFu7ll_Sf  {
  unsigned char  :0;
  __tsu64 v1:7;
  struct empty v2;
};
//SIG(1 BFu0c_BFu7ll_Sf) C1{ Fc:0 FL:7 FC2{}}



static void Test_BFu0c_BFu7ll_Sf()
{
  {
    init_simple_test("BFu0c_BFu7ll_Sf");
    static STRUCT_IF_C BFu0c_BFu7ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu7ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu7ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0c_BFu7ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0c_BFu7ll_Sf");
    check_field_offset(lv, v2, 1, "BFu0c_BFu7ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu7ll_Sf, BFu0c_BFu7ll_Sf)
//============================================================================


struct  BFu0c_BFu7s_Sf  {
  unsigned char  :0;
  unsigned short v1:7;
  struct empty v2;
};
//SIG(1 BFu0c_BFu7s_Sf) C1{ Fc:0 Fs:7 FC2{}}



static void Test_BFu0c_BFu7s_Sf()
{
  {
    init_simple_test("BFu0c_BFu7s_Sf");
    static STRUCT_IF_C BFu0c_BFu7s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_BFu7s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_BFu7s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0c_BFu7s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0c_BFu7s_Sf");
    check_field_offset(lv, v2, 1, "BFu0c_BFu7s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu7s_Sf, BFu0c_BFu7s_Sf)
//============================================================================


struct  BFu0c_BFu8c_Sf  {
  unsigned char  :0;
  unsigned char v1:8;
  struct empty v2;
};
//SIG(1 BFu0c_BFu8c_Sf) C1{ Fc:0 Fc:8 FC2{}}



static void Test_BFu0c_BFu8c_Sf()
{
  {
    init_simple_test("BFu0c_BFu8c_Sf");
    static STRUCT_IF_C BFu0c_BFu8c_Sf lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_BFu8c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_BFu8c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0c_BFu8c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0c_BFu8c_Sf");
    check_field_offset(lv, v2, 1, "BFu0c_BFu8c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu8c_Sf, BFu0c_BFu8c_Sf)
//============================================================================


struct  BFu0c_BFu8i_Sf  {
  unsigned char  :0;
  unsigned int v1:8;
  struct empty v2;
};
//SIG(1 BFu0c_BFu8i_Sf) C1{ Fc:0 Fi:8 FC2{}}



static void Test_BFu0c_BFu8i_Sf()
{
  {
    init_simple_test("BFu0c_BFu8i_Sf");
    static STRUCT_IF_C BFu0c_BFu8i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu8i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu8i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0c_BFu8i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0c_BFu8i_Sf");
    check_field_offset(lv, v2, 1, "BFu0c_BFu8i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu8i_Sf, BFu0c_BFu8i_Sf)
//============================================================================


struct  BFu0c_BFu8ll_Sf  {
  unsigned char  :0;
  __tsu64 v1:8;
  struct empty v2;
};
//SIG(1 BFu0c_BFu8ll_Sf) C1{ Fc:0 FL:8 FC2{}}



static void Test_BFu0c_BFu8ll_Sf()
{
  {
    init_simple_test("BFu0c_BFu8ll_Sf");
    static STRUCT_IF_C BFu0c_BFu8ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu8ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu8ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0c_BFu8ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0c_BFu8ll_Sf");
    check_field_offset(lv, v2, 1, "BFu0c_BFu8ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu8ll_Sf, BFu0c_BFu8ll_Sf)
//============================================================================


struct  BFu0c_BFu8s_Sf  {
  unsigned char  :0;
  unsigned short v1:8;
  struct empty v2;
};
//SIG(1 BFu0c_BFu8s_Sf) C1{ Fc:0 Fs:8 FC2{}}



static void Test_BFu0c_BFu8s_Sf()
{
  {
    init_simple_test("BFu0c_BFu8s_Sf");
    static STRUCT_IF_C BFu0c_BFu8s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_BFu8s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_BFu8s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0c_BFu8s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0c_BFu8s_Sf");
    check_field_offset(lv, v2, 1, "BFu0c_BFu8s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu8s_Sf, BFu0c_BFu8s_Sf)
//============================================================================


struct  BFu0c_BFu9i_Sf  {
  unsigned char  :0;
  unsigned int v1:9;
  struct empty v2;
};
//SIG(1 BFu0c_BFu9i_Sf) C1{ Fc:0 Fi:9 FC2{}}



static void Test_BFu0c_BFu9i_Sf()
{
  {
    init_simple_test("BFu0c_BFu9i_Sf");
    static STRUCT_IF_C BFu0c_BFu9i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_BFu9i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_BFu9i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0c_BFu9i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0c_BFu9i_Sf");
    check_field_offset(lv, v2, 2, "BFu0c_BFu9i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu9i_Sf, BFu0c_BFu9i_Sf)
//============================================================================


struct  BFu0c_BFu9ll_Sf  {
  unsigned char  :0;
  __tsu64 v1:9;
  struct empty v2;
};
//SIG(1 BFu0c_BFu9ll_Sf) C1{ Fc:0 FL:9 FC2{}}



static void Test_BFu0c_BFu9ll_Sf()
{
  {
    init_simple_test("BFu0c_BFu9ll_Sf");
    static STRUCT_IF_C BFu0c_BFu9ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_BFu9ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_BFu9ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0c_BFu9ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0c_BFu9ll_Sf");
    check_field_offset(lv, v2, 2, "BFu0c_BFu9ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu9ll_Sf, BFu0c_BFu9ll_Sf)
//============================================================================


struct  BFu0c_BFu9s_Sf  {
  unsigned char  :0;
  unsigned short v1:9;
  struct empty v2;
};
//SIG(1 BFu0c_BFu9s_Sf) C1{ Fc:0 Fs:9 FC2{}}



static void Test_BFu0c_BFu9s_Sf()
{
  {
    init_simple_test("BFu0c_BFu9s_Sf");
    static STRUCT_IF_C BFu0c_BFu9s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_BFu9s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_BFu9s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0c_BFu9s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0c_BFu9s_Sf");
    check_field_offset(lv, v2, 2, "BFu0c_BFu9s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_BFu9s_Sf, BFu0c_BFu9s_Sf)
//============================================================================


struct  BFu0c_C_Sf  {
  unsigned char  :0;
  char v1;
  struct empty v2;
};
//SIG(1 BFu0c_C_Sf) C1{ Fc:0 Fc FC2{}}



static void Test_BFu0c_C_Sf()
{
  {
    init_simple_test("BFu0c_C_Sf");
    static STRUCT_IF_C BFu0c_C_Sf lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_C_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_C_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_C_Sf.v1");
    check_field_offset(lv, v2, 1, "BFu0c_C_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_C_Sf, BFu0c_C_Sf)
//============================================================================


struct  BFu0c_D_Sf  {
  unsigned char  :0;
  double v1;
  struct empty v2;
};
//SIG(1 BFu0c_D_Sf) C1{ Fc:0 FL FC2{}}



static void Test_BFu0c_D_Sf()
{
  {
    init_simple_test("BFu0c_D_Sf");
    static STRUCT_IF_C BFu0c_D_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_D_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_D_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_D_Sf.v1");
    check_field_offset(lv, v2, 8, "BFu0c_D_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_D_Sf, BFu0c_D_Sf)
//============================================================================


struct  BFu0c_F_Sf  {
  unsigned char  :0;
  float v1;
  struct empty v2;
};
//SIG(1 BFu0c_F_Sf) C1{ Fc:0 Fi FC2{}}



static void Test_BFu0c_F_Sf()
{
  {
    init_simple_test("BFu0c_F_Sf");
    static STRUCT_IF_C BFu0c_F_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_F_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_F_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_F_Sf.v1");
    check_field_offset(lv, v2, 4, "BFu0c_F_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_F_Sf, BFu0c_F_Sf)
//============================================================================


struct  BFu0c_I_Sf  {
  unsigned char  :0;
  int v1;
  struct empty v2;
};
//SIG(1 BFu0c_I_Sf) C1{ Fc:0 Fi FC2{}}



static void Test_BFu0c_I_Sf()
{
  {
    init_simple_test("BFu0c_I_Sf");
    static STRUCT_IF_C BFu0c_I_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_I_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_I_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_I_Sf.v1");
    check_field_offset(lv, v2, 4, "BFu0c_I_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_I_Sf, BFu0c_I_Sf)
//============================================================================


struct  BFu0c_Ip_Sf  {
  unsigned char  :0;
  int *v1;
  struct empty v2;
};
//SIG(1 BFu0c_Ip_Sf) C1{ Fc:0 Fp FC2{}}



static void Test_BFu0c_Ip_Sf()
{
  {
    init_simple_test("BFu0c_Ip_Sf");
    static STRUCT_IF_C BFu0c_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Ip_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Ip_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_Ip_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0c_Ip_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Ip_Sf, BFu0c_Ip_Sf)
//============================================================================


struct  BFu0c_L_Sf  {
  unsigned char  :0;
  __tsi64 v1;
  struct empty v2;
};
//SIG(1 BFu0c_L_Sf) C1{ Fc:0 FL FC2{}}



static void Test_BFu0c_L_Sf()
{
  {
    init_simple_test("BFu0c_L_Sf");
    static STRUCT_IF_C BFu0c_L_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_L_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_L_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_L_Sf.v1");
    check_field_offset(lv, v2, 8, "BFu0c_L_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_L_Sf, BFu0c_L_Sf)
//============================================================================


struct  BFu0c_S_Sf  {
  unsigned char  :0;
  short v1;
  struct empty v2;
};
//SIG(1 BFu0c_S_Sf) C1{ Fc:0 Fs FC2{}}



static void Test_BFu0c_S_Sf()
{
  {
    init_simple_test("BFu0c_S_Sf");
    static STRUCT_IF_C BFu0c_S_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_S_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_S_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_S_Sf.v1");
    check_field_offset(lv, v2, 2, "BFu0c_S_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_S_Sf, BFu0c_S_Sf)
//============================================================================


struct  BFu0c_Sf  {
  unsigned char  :0;
  struct empty v1;
};
//SIG(1 BFu0c_Sf) C1{ Fc:0 FC2{}}



static void Test_BFu0c_Sf()
{
  {
    init_simple_test("BFu0c_Sf");
    static STRUCT_IF_C BFu0c_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf, BFu0c_Sf)
//============================================================================


struct  BFu0c_Sf_BFu0c  {
  unsigned char  :0;
  struct empty v1;
  unsigned char  :0;
};
//SIG(1 BFu0c_Sf_BFu0c) C1{ Fc:0 FC2{} Fc:0}



static void Test_BFu0c_Sf_BFu0c()
{
  {
    init_simple_test("BFu0c_Sf_BFu0c");
    static STRUCT_IF_C BFu0c_Sf_BFu0c lv;
    check2(sizeof(lv), 0, "sizeof(BFu0c_Sf_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu0c, BFu0c_Sf_BFu0c)
//============================================================================


struct  BFu0c_Sf_BFu0i  {
  unsigned char  :0;
  struct empty v1;
  unsigned int  :0;
};
//SIG(1 BFu0c_Sf_BFu0i) C1{ Fc:0 FC2{} Fi:0}



static void Test_BFu0c_Sf_BFu0i()
{
  {
    init_simple_test("BFu0c_Sf_BFu0i");
    static STRUCT_IF_C BFu0c_Sf_BFu0i lv;
    check2(sizeof(lv), 0, "sizeof(BFu0c_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0c_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu0i, BFu0c_Sf_BFu0i)
//============================================================================


struct  BFu0c_Sf_BFu0ll  {
  unsigned char  :0;
  struct empty v1;
  __tsu64  :0;
};
//SIG(1 BFu0c_Sf_BFu0ll) C1{ Fc:0 FC2{} FL:0}



static void Test_BFu0c_Sf_BFu0ll()
{
  {
    init_simple_test("BFu0c_Sf_BFu0ll");
    static STRUCT_IF_C BFu0c_Sf_BFu0ll lv;
    check2(sizeof(lv), 0, "sizeof(BFu0c_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0c_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu0ll, BFu0c_Sf_BFu0ll)
//============================================================================


struct  BFu0c_Sf_BFu0s  {
  unsigned char  :0;
  struct empty v1;
  unsigned short  :0;
};
//SIG(1 BFu0c_Sf_BFu0s) C1{ Fc:0 FC2{} Fs:0}



static void Test_BFu0c_Sf_BFu0s()
{
  {
    init_simple_test("BFu0c_Sf_BFu0s");
    static STRUCT_IF_C BFu0c_Sf_BFu0s lv;
    check2(sizeof(lv), 0, "sizeof(BFu0c_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0c_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu0s, BFu0c_Sf_BFu0s)
//============================================================================


struct  BFu0c_Sf_BFu15i  {
  unsigned char  :0;
  struct empty v1;
  unsigned int v2:15;
};
//SIG(1 BFu0c_Sf_BFu15i) C1{ Fc:0 FC2{} Fi:15}



static void Test_BFu0c_Sf_BFu15i()
{
  {
    init_simple_test("BFu0c_Sf_BFu15i");
    static STRUCT_IF_C BFu0c_Sf_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Sf_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu15i.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "BFu0c_Sf_BFu15i");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "BFu0c_Sf_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu15i, BFu0c_Sf_BFu15i)
//============================================================================


struct  BFu0c_Sf_BFu15ll  {
  unsigned char  :0;
  struct empty v1;
  __tsu64 v2:15;
};
//SIG(1 BFu0c_Sf_BFu15ll) C1{ Fc:0 FC2{} FL:15}



static void Test_BFu0c_Sf_BFu15ll()
{
  {
    init_simple_test("BFu0c_Sf_BFu15ll");
    static STRUCT_IF_C BFu0c_Sf_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Sf_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu15ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "BFu0c_Sf_BFu15ll");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "BFu0c_Sf_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu15ll, BFu0c_Sf_BFu15ll)
//============================================================================


struct  BFu0c_Sf_BFu15s  {
  unsigned char  :0;
  struct empty v1;
  unsigned short v2:15;
};
//SIG(1 BFu0c_Sf_BFu15s) C1{ Fc:0 FC2{} Fs:15}



static void Test_BFu0c_Sf_BFu15s()
{
  {
    init_simple_test("BFu0c_Sf_BFu15s");
    static STRUCT_IF_C BFu0c_Sf_BFu15s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_Sf_BFu15s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu15s.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "BFu0c_Sf_BFu15s");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "BFu0c_Sf_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu15s, BFu0c_Sf_BFu15s)
//============================================================================


struct  BFu0c_Sf_BFu16i  {
  unsigned char  :0;
  struct empty v1;
  unsigned int v2:16;
};
//SIG(1 BFu0c_Sf_BFu16i) C1{ Fc:0 FC2{} Fi:16}



static void Test_BFu0c_Sf_BFu16i()
{
  {
    init_simple_test("BFu0c_Sf_BFu16i");
    static STRUCT_IF_C BFu0c_Sf_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Sf_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu16i.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "BFu0c_Sf_BFu16i");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "BFu0c_Sf_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu16i, BFu0c_Sf_BFu16i)
//============================================================================


struct  BFu0c_Sf_BFu16ll  {
  unsigned char  :0;
  struct empty v1;
  __tsu64 v2:16;
};
//SIG(1 BFu0c_Sf_BFu16ll) C1{ Fc:0 FC2{} FL:16}



static void Test_BFu0c_Sf_BFu16ll()
{
  {
    init_simple_test("BFu0c_Sf_BFu16ll");
    static STRUCT_IF_C BFu0c_Sf_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Sf_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu16ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "BFu0c_Sf_BFu16ll");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "BFu0c_Sf_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu16ll, BFu0c_Sf_BFu16ll)
//============================================================================


struct  BFu0c_Sf_BFu16s  {
  unsigned char  :0;
  struct empty v1;
  unsigned short v2:16;
};
//SIG(1 BFu0c_Sf_BFu16s) C1{ Fc:0 FC2{} Fs:16}



static void Test_BFu0c_Sf_BFu16s()
{
  {
    init_simple_test("BFu0c_Sf_BFu16s");
    static STRUCT_IF_C BFu0c_Sf_BFu16s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_Sf_BFu16s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu16s.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "BFu0c_Sf_BFu16s");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "BFu0c_Sf_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu16s, BFu0c_Sf_BFu16s)
//============================================================================


struct  BFu0c_Sf_BFu17i  {
  unsigned char  :0;
  struct empty v1;
  unsigned int v2:17;
};
//SIG(1 BFu0c_Sf_BFu17i) C1{ Fc:0 FC2{} Fi:17}



static void Test_BFu0c_Sf_BFu17i()
{
  {
    init_simple_test("BFu0c_Sf_BFu17i");
    static STRUCT_IF_C BFu0c_Sf_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Sf_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu17i.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "BFu0c_Sf_BFu17i");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "BFu0c_Sf_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu17i, BFu0c_Sf_BFu17i)
//============================================================================


struct  BFu0c_Sf_BFu17ll  {
  unsigned char  :0;
  struct empty v1;
  __tsu64 v2:17;
};
//SIG(1 BFu0c_Sf_BFu17ll) C1{ Fc:0 FC2{} FL:17}



static void Test_BFu0c_Sf_BFu17ll()
{
  {
    init_simple_test("BFu0c_Sf_BFu17ll");
    static STRUCT_IF_C BFu0c_Sf_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Sf_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu17ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "BFu0c_Sf_BFu17ll");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "BFu0c_Sf_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu17ll, BFu0c_Sf_BFu17ll)
//============================================================================


struct  BFu0c_Sf_BFu1c  {
  unsigned char  :0;
  struct empty v1;
  unsigned char v2:1;
};
//SIG(1 BFu0c_Sf_BFu1c) C1{ Fc:0 FC2{} Fc:1}



static void Test_BFu0c_Sf_BFu1c()
{
  {
    init_simple_test("BFu0c_Sf_BFu1c");
    static STRUCT_IF_C BFu0c_Sf_BFu1c lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_Sf_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu1c.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0c_Sf_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu1c, BFu0c_Sf_BFu1c)
//============================================================================


struct  BFu0c_Sf_BFu1i  {
  unsigned char  :0;
  struct empty v1;
  unsigned int v2:1;
};
//SIG(1 BFu0c_Sf_BFu1i) C1{ Fc:0 FC2{} Fi:1}



static void Test_BFu0c_Sf_BFu1i()
{
  {
    init_simple_test("BFu0c_Sf_BFu1i");
    static STRUCT_IF_C BFu0c_Sf_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Sf_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu1i.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0c_Sf_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu1i, BFu0c_Sf_BFu1i)
//============================================================================


struct  BFu0c_Sf_BFu1ll  {
  unsigned char  :0;
  struct empty v1;
  __tsu64 v2:1;
};
//SIG(1 BFu0c_Sf_BFu1ll) C1{ Fc:0 FC2{} FL:1}



static void Test_BFu0c_Sf_BFu1ll()
{
  {
    init_simple_test("BFu0c_Sf_BFu1ll");
    static STRUCT_IF_C BFu0c_Sf_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Sf_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu1ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0c_Sf_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu1ll, BFu0c_Sf_BFu1ll)
//============================================================================


struct  BFu0c_Sf_BFu1s  {
  unsigned char  :0;
  struct empty v1;
  unsigned short v2:1;
};
//SIG(1 BFu0c_Sf_BFu1s) C1{ Fc:0 FC2{} Fs:1}



static void Test_BFu0c_Sf_BFu1s()
{
  {
    init_simple_test("BFu0c_Sf_BFu1s");
    static STRUCT_IF_C BFu0c_Sf_BFu1s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_Sf_BFu1s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu1s.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0c_Sf_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu1s, BFu0c_Sf_BFu1s)
//============================================================================


struct  BFu0c_Sf_BFu31i  {
  unsigned char  :0;
  struct empty v1;
  unsigned int v2:31;
};
//SIG(1 BFu0c_Sf_BFu31i) C1{ Fc:0 FC2{} Fi:31}



static void Test_BFu0c_Sf_BFu31i()
{
  {
    init_simple_test("BFu0c_Sf_BFu31i");
    static STRUCT_IF_C BFu0c_Sf_BFu31i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Sf_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu31i.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "BFu0c_Sf_BFu31i");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "BFu0c_Sf_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu31i, BFu0c_Sf_BFu31i)
//============================================================================


struct  BFu0c_Sf_BFu31ll  {
  unsigned char  :0;
  struct empty v1;
  __tsu64 v2:31;
};
//SIG(1 BFu0c_Sf_BFu31ll) C1{ Fc:0 FC2{} FL:31}



static void Test_BFu0c_Sf_BFu31ll()
{
  {
    init_simple_test("BFu0c_Sf_BFu31ll");
    static STRUCT_IF_C BFu0c_Sf_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Sf_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu31ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "BFu0c_Sf_BFu31ll");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "BFu0c_Sf_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu31ll, BFu0c_Sf_BFu31ll)
//============================================================================


struct  BFu0c_Sf_BFu32i  {
  unsigned char  :0;
  struct empty v1;
  unsigned int v2:32;
};
//SIG(1 BFu0c_Sf_BFu32i) C1{ Fc:0 FC2{} Fi:32}



static void Test_BFu0c_Sf_BFu32i()
{
  {
    init_simple_test("BFu0c_Sf_BFu32i");
    static STRUCT_IF_C BFu0c_Sf_BFu32i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Sf_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu32i.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "BFu0c_Sf_BFu32i");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "BFu0c_Sf_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu32i, BFu0c_Sf_BFu32i)
//============================================================================


struct  BFu0c_Sf_BFu32ll  {
  unsigned char  :0;
  struct empty v1;
  __tsu64 v2:32;
};
//SIG(1 BFu0c_Sf_BFu32ll) C1{ Fc:0 FC2{} FL:32}



static void Test_BFu0c_Sf_BFu32ll()
{
  {
    init_simple_test("BFu0c_Sf_BFu32ll");
    static STRUCT_IF_C BFu0c_Sf_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Sf_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu32ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "BFu0c_Sf_BFu32ll");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "BFu0c_Sf_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu32ll, BFu0c_Sf_BFu32ll)
//============================================================================


struct  BFu0c_Sf_BFu33  {
  unsigned char  :0;
  struct empty v1;
  __tsu64 v2:33;
};
//SIG(1 BFu0c_Sf_BFu33) C1{ Fc:0 FC2{} FL:33}



static void Test_BFu0c_Sf_BFu33()
{
  {
    init_simple_test("BFu0c_Sf_BFu33");
    static STRUCT_IF_C BFu0c_Sf_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_Sf_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu33.v1");
    set_bf_and_test(lv, v2, 0, 0, 33, 1, "BFu0c_Sf_BFu33");
    set_bf_and_test(lv, v2, 0, 0, 33, hide_ull(1LL<<32), "BFu0c_Sf_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu33, BFu0c_Sf_BFu33)
//============================================================================


struct  BFu0c_Sf_BFu7c  {
  unsigned char  :0;
  struct empty v1;
  unsigned char v2:7;
};
//SIG(1 BFu0c_Sf_BFu7c) C1{ Fc:0 FC2{} Fc:7}



static void Test_BFu0c_Sf_BFu7c()
{
  {
    init_simple_test("BFu0c_Sf_BFu7c");
    static STRUCT_IF_C BFu0c_Sf_BFu7c lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_Sf_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu7c.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0c_Sf_BFu7c");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0c_Sf_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu7c, BFu0c_Sf_BFu7c)
//============================================================================


struct  BFu0c_Sf_BFu7i  {
  unsigned char  :0;
  struct empty v1;
  unsigned int v2:7;
};
//SIG(1 BFu0c_Sf_BFu7i) C1{ Fc:0 FC2{} Fi:7}



static void Test_BFu0c_Sf_BFu7i()
{
  {
    init_simple_test("BFu0c_Sf_BFu7i");
    static STRUCT_IF_C BFu0c_Sf_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Sf_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu7i.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0c_Sf_BFu7i");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0c_Sf_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu7i, BFu0c_Sf_BFu7i)
//============================================================================


struct  BFu0c_Sf_BFu7ll  {
  unsigned char  :0;
  struct empty v1;
  __tsu64 v2:7;
};
//SIG(1 BFu0c_Sf_BFu7ll) C1{ Fc:0 FC2{} FL:7}



static void Test_BFu0c_Sf_BFu7ll()
{
  {
    init_simple_test("BFu0c_Sf_BFu7ll");
    static STRUCT_IF_C BFu0c_Sf_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Sf_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu7ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0c_Sf_BFu7ll");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0c_Sf_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu7ll, BFu0c_Sf_BFu7ll)
//============================================================================


struct  BFu0c_Sf_BFu7s  {
  unsigned char  :0;
  struct empty v1;
  unsigned short v2:7;
};
//SIG(1 BFu0c_Sf_BFu7s) C1{ Fc:0 FC2{} Fs:7}



static void Test_BFu0c_Sf_BFu7s()
{
  {
    init_simple_test("BFu0c_Sf_BFu7s");
    static STRUCT_IF_C BFu0c_Sf_BFu7s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_Sf_BFu7s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu7s.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0c_Sf_BFu7s");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0c_Sf_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu7s, BFu0c_Sf_BFu7s)
//============================================================================


struct  BFu0c_Sf_BFu8c  {
  unsigned char  :0;
  struct empty v1;
  unsigned char v2:8;
};
//SIG(1 BFu0c_Sf_BFu8c) C1{ Fc:0 FC2{} Fc:8}



static void Test_BFu0c_Sf_BFu8c()
{
  {
    init_simple_test("BFu0c_Sf_BFu8c");
    static STRUCT_IF_C BFu0c_Sf_BFu8c lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_Sf_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu8c.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0c_Sf_BFu8c");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0c_Sf_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu8c, BFu0c_Sf_BFu8c)
//============================================================================


struct  BFu0c_Sf_BFu8i  {
  unsigned char  :0;
  struct empty v1;
  unsigned int v2:8;
};
//SIG(1 BFu0c_Sf_BFu8i) C1{ Fc:0 FC2{} Fi:8}



static void Test_BFu0c_Sf_BFu8i()
{
  {
    init_simple_test("BFu0c_Sf_BFu8i");
    static STRUCT_IF_C BFu0c_Sf_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Sf_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu8i.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0c_Sf_BFu8i");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0c_Sf_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu8i, BFu0c_Sf_BFu8i)
//============================================================================


struct  BFu0c_Sf_BFu8ll  {
  unsigned char  :0;
  struct empty v1;
  __tsu64 v2:8;
};
//SIG(1 BFu0c_Sf_BFu8ll) C1{ Fc:0 FC2{} FL:8}



static void Test_BFu0c_Sf_BFu8ll()
{
  {
    init_simple_test("BFu0c_Sf_BFu8ll");
    static STRUCT_IF_C BFu0c_Sf_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Sf_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu8ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0c_Sf_BFu8ll");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0c_Sf_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu8ll, BFu0c_Sf_BFu8ll)
//============================================================================


struct  BFu0c_Sf_BFu8s  {
  unsigned char  :0;
  struct empty v1;
  unsigned short v2:8;
};
//SIG(1 BFu0c_Sf_BFu8s) C1{ Fc:0 FC2{} Fs:8}



static void Test_BFu0c_Sf_BFu8s()
{
  {
    init_simple_test("BFu0c_Sf_BFu8s");
    static STRUCT_IF_C BFu0c_Sf_BFu8s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_Sf_BFu8s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu8s.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0c_Sf_BFu8s");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0c_Sf_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu8s, BFu0c_Sf_BFu8s)
//============================================================================


struct  BFu0c_Sf_BFu9i  {
  unsigned char  :0;
  struct empty v1;
  unsigned int v2:9;
};
//SIG(1 BFu0c_Sf_BFu9i) C1{ Fc:0 FC2{} Fi:9}



static void Test_BFu0c_Sf_BFu9i()
{
  {
    init_simple_test("BFu0c_Sf_BFu9i");
    static STRUCT_IF_C BFu0c_Sf_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Sf_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu9i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "BFu0c_Sf_BFu9i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "BFu0c_Sf_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu9i, BFu0c_Sf_BFu9i)
//============================================================================


struct  BFu0c_Sf_BFu9ll  {
  unsigned char  :0;
  struct empty v1;
  __tsu64 v2:9;
};
//SIG(1 BFu0c_Sf_BFu9ll) C1{ Fc:0 FC2{} FL:9}



static void Test_BFu0c_Sf_BFu9ll()
{
  {
    init_simple_test("BFu0c_Sf_BFu9ll");
    static STRUCT_IF_C BFu0c_Sf_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Sf_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu9ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "BFu0c_Sf_BFu9ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "BFu0c_Sf_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu9ll, BFu0c_Sf_BFu9ll)
//============================================================================


struct  BFu0c_Sf_BFu9s  {
  unsigned char  :0;
  struct empty v1;
  unsigned short v2:9;
};
//SIG(1 BFu0c_Sf_BFu9s) C1{ Fc:0 FC2{} Fs:9}



static void Test_BFu0c_Sf_BFu9s()
{
  {
    init_simple_test("BFu0c_Sf_BFu9s");
    static STRUCT_IF_C BFu0c_Sf_BFu9s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_Sf_BFu9s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_BFu9s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "BFu0c_Sf_BFu9s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "BFu0c_Sf_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_BFu9s, BFu0c_Sf_BFu9s)
//============================================================================


struct  BFu0c_Sf_C  {
  unsigned char  :0;
  struct empty v1;
  char v2;
};
//SIG(1 BFu0c_Sf_C) C1{ Fc:0 FC2{} Fc}



static void Test_BFu0c_Sf_C()
{
  {
    init_simple_test("BFu0c_Sf_C");
    static STRUCT_IF_C BFu0c_Sf_C lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_Sf_C)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_Sf_C)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_C.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_C, BFu0c_Sf_C)
//============================================================================


struct  BFu0c_Sf_D  {
  unsigned char  :0;
  struct empty v1;
  double v2;
};
//SIG(1 BFu0c_Sf_D) C1{ Fc:0 FC2{} FL}



static void Test_BFu0c_Sf_D()
{
  {
    init_simple_test("BFu0c_Sf_D");
    static STRUCT_IF_C BFu0c_Sf_D lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_Sf_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_D)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_D.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_D, BFu0c_Sf_D)
//============================================================================


struct  BFu0c_Sf_F  {
  unsigned char  :0;
  struct empty v1;
  float v2;
};
//SIG(1 BFu0c_Sf_F) C1{ Fc:0 FC2{} Fi}



static void Test_BFu0c_Sf_F()
{
  {
    init_simple_test("BFu0c_Sf_F");
    static STRUCT_IF_C BFu0c_Sf_F lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Sf_F)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Sf_F)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_F.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_F, BFu0c_Sf_F)
//============================================================================


struct  BFu0c_Sf_I  {
  unsigned char  :0;
  struct empty v1;
  int v2;
};
//SIG(1 BFu0c_Sf_I) C1{ Fc:0 FC2{} Fi}



static void Test_BFu0c_Sf_I()
{
  {
    init_simple_test("BFu0c_Sf_I");
    static STRUCT_IF_C BFu0c_Sf_I lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Sf_I)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Sf_I)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_I.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_I, BFu0c_Sf_I)
//============================================================================


struct  BFu0c_Sf_Ip  {
  unsigned char  :0;
  struct empty v1;
  int *v2;
};
//SIG(1 BFu0c_Sf_Ip) C1{ Fc:0 FC2{} Fp}



static void Test_BFu0c_Sf_Ip()
{
  {
    init_simple_test("BFu0c_Sf_Ip");
    static STRUCT_IF_C BFu0c_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Sf_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_Ip)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_Ip.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_Ip, BFu0c_Sf_Ip)
//============================================================================


struct  BFu0c_Sf_L  {
  unsigned char  :0;
  struct empty v1;
  __tsi64 v2;
};
//SIG(1 BFu0c_Sf_L) C1{ Fc:0 FC2{} FL}



static void Test_BFu0c_Sf_L()
{
  {
    init_simple_test("BFu0c_Sf_L");
    static STRUCT_IF_C BFu0c_Sf_L lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_Sf_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_L)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_L.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_L, BFu0c_Sf_L)
//============================================================================


struct  BFu0c_Sf_S  {
  unsigned char  :0;
  struct empty v1;
  short v2;
};
//SIG(1 BFu0c_Sf_S) C1{ Fc:0 FC2{} Fs}



static void Test_BFu0c_Sf_S()
{
  {
    init_simple_test("BFu0c_Sf_S");
    static STRUCT_IF_C BFu0c_Sf_S lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_Sf_S)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_Sf_S)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_S.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_S, BFu0c_Sf_S)
//============================================================================


struct  BFu0c_Sf_Sf  {
  unsigned char  :0;
  struct empty v1;
  struct empty v2;
};
//SIG(1 BFu0c_Sf_Sf) C1{ Fc:0 FC2{} FC2}



static void Test_BFu0c_Sf_Sf()
{
  {
    init_simple_test("BFu0c_Sf_Sf");
    static STRUCT_IF_C BFu0c_Sf_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0c_Sf_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_Sf_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_Sf.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_Sf, BFu0c_Sf_Sf)
//============================================================================


struct  BFu0c_Sf_Uc  {
  unsigned char  :0;
  struct empty v1;
  unsigned char v2;
};
//SIG(1 BFu0c_Sf_Uc) C1{ Fc:0 FC2{} Fc}



static void Test_BFu0c_Sf_Uc()
{
  {
    init_simple_test("BFu0c_Sf_Uc");
    static STRUCT_IF_C BFu0c_Sf_Uc lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_Sf_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_Sf_Uc)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_Uc.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_Uc, BFu0c_Sf_Uc)
//============================================================================


struct  BFu0c_Sf_Ui  {
  unsigned char  :0;
  struct empty v1;
  unsigned int v2;
};
//SIG(1 BFu0c_Sf_Ui) C1{ Fc:0 FC2{} Fi}



static void Test_BFu0c_Sf_Ui()
{
  {
    init_simple_test("BFu0c_Sf_Ui");
    static STRUCT_IF_C BFu0c_Sf_Ui lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Sf_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Sf_Ui)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_Ui.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_Ui, BFu0c_Sf_Ui)
//============================================================================


struct  BFu0c_Sf_Ul  {
  unsigned char  :0;
  struct empty v1;
  __tsu64 v2;
};
//SIG(1 BFu0c_Sf_Ul) C1{ Fc:0 FC2{} FL}



static void Test_BFu0c_Sf_Ul()
{
  {
    init_simple_test("BFu0c_Sf_Ul");
    static STRUCT_IF_C BFu0c_Sf_Ul lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_Sf_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_Ul)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_Ul.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_Ul, BFu0c_Sf_Ul)
//============================================================================


struct  BFu0c_Sf_Us  {
  unsigned char  :0;
  struct empty v1;
  unsigned short v2;
};
//SIG(1 BFu0c_Sf_Us) C1{ Fc:0 FC2{} Fs}



static void Test_BFu0c_Sf_Us()
{
  {
    init_simple_test("BFu0c_Sf_Us");
    static STRUCT_IF_C BFu0c_Sf_Us lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_Sf_Us)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_Sf_Us)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_Us.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_Us, BFu0c_Sf_Us)
//============================================================================


struct  BFu0c_Sf_Vp  {
  unsigned char  :0;
  struct empty v1;
  void *v2;
};
//SIG(1 BFu0c_Sf_Vp) C1{ Fc:0 FC2{} Fp}



static void Test_BFu0c_Sf_Vp()
{
  {
    init_simple_test("BFu0c_Sf_Vp");
    static STRUCT_IF_C BFu0c_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Sf_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Sf_Vp)");
    check_field_offset(lv, v1, 0, "BFu0c_Sf_Vp.v1");
    check_field_offset(lv, v2, 0, "BFu0c_Sf_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Sf_Vp, BFu0c_Sf_Vp)
//============================================================================


struct  BFu0c_Uc_Sf  {
  unsigned char  :0;
  unsigned char v1;
  struct empty v2;
};
//SIG(1 BFu0c_Uc_Sf) C1{ Fc:0 Fc FC2{}}



static void Test_BFu0c_Uc_Sf()
{
  {
    init_simple_test("BFu0c_Uc_Sf");
    static STRUCT_IF_C BFu0c_Uc_Sf lv;
    check2(sizeof(lv), 1, "sizeof(BFu0c_Uc_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu0c_Uc_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_Uc_Sf.v1");
    check_field_offset(lv, v2, 1, "BFu0c_Uc_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Uc_Sf, BFu0c_Uc_Sf)
//============================================================================


struct  BFu0c_Ui_Sf  {
  unsigned char  :0;
  unsigned int v1;
  struct empty v2;
};
//SIG(1 BFu0c_Ui_Sf) C1{ Fc:0 Fi FC2{}}



static void Test_BFu0c_Ui_Sf()
{
  {
    init_simple_test("BFu0c_Ui_Sf");
    static STRUCT_IF_C BFu0c_Ui_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0c_Ui_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0c_Ui_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_Ui_Sf.v1");
    check_field_offset(lv, v2, 4, "BFu0c_Ui_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Ui_Sf, BFu0c_Ui_Sf)
//============================================================================


struct  BFu0c_Ul_Sf  {
  unsigned char  :0;
  __tsu64 v1;
  struct empty v2;
};
//SIG(1 BFu0c_Ul_Sf) C1{ Fc:0 FL FC2{}}



static void Test_BFu0c_Ul_Sf()
{
  {
    init_simple_test("BFu0c_Ul_Sf");
    static STRUCT_IF_C BFu0c_Ul_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0c_Ul_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Ul_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_Ul_Sf.v1");
    check_field_offset(lv, v2, 8, "BFu0c_Ul_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Ul_Sf, BFu0c_Ul_Sf)
//============================================================================


struct  BFu0c_Us_Sf  {
  unsigned char  :0;
  unsigned short v1;
  struct empty v2;
};
//SIG(1 BFu0c_Us_Sf) C1{ Fc:0 Fs FC2{}}



static void Test_BFu0c_Us_Sf()
{
  {
    init_simple_test("BFu0c_Us_Sf");
    static STRUCT_IF_C BFu0c_Us_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0c_Us_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0c_Us_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_Us_Sf.v1");
    check_field_offset(lv, v2, 2, "BFu0c_Us_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Us_Sf, BFu0c_Us_Sf)
//============================================================================


struct  BFu0c_Vp_Sf  {
  unsigned char  :0;
  void *v1;
  struct empty v2;
};
//SIG(1 BFu0c_Vp_Sf) C1{ Fc:0 Fp FC2{}}



static void Test_BFu0c_Vp_Sf()
{
  {
    init_simple_test("BFu0c_Vp_Sf");
    static STRUCT_IF_C BFu0c_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0c_Vp_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0c_Vp_Sf)");
    check_field_offset(lv, v1, 0, "BFu0c_Vp_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0c_Vp_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0c_Vp_Sf, BFu0c_Vp_Sf)
//============================================================================


struct  BFu0i_BFu0c_Sf  {
  unsigned int  :0;
  unsigned char  :0;
  struct empty v1;
};
//SIG(1 BFu0i_BFu0c_Sf) C1{ Fi:0 Fc:0 FC2{}}



static void Test_BFu0i_BFu0c_Sf()
{
  {
    init_simple_test("BFu0i_BFu0c_Sf");
    static STRUCT_IF_C BFu0i_BFu0c_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0i_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_BFu0c_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu0c_Sf, BFu0i_BFu0c_Sf)
//============================================================================


struct  BFu0i_BFu0i_Sf  {
  unsigned int  :0;
  unsigned int  :0;
  struct empty v1;
};
//SIG(1 BFu0i_BFu0i_Sf) C1{ Fi:0 Fi:0 FC2{}}



static void Test_BFu0i_BFu0i_Sf()
{
  {
    init_simple_test("BFu0i_BFu0i_Sf");
    static STRUCT_IF_C BFu0i_BFu0i_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0i_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_BFu0i_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu0i_Sf, BFu0i_BFu0i_Sf)
//============================================================================


struct  BFu0i_BFu0ll_Sf  {
  unsigned int  :0;
  __tsu64  :0;
  struct empty v1;
};
//SIG(1 BFu0i_BFu0ll_Sf) C1{ Fi:0 FL:0 FC2{}}



static void Test_BFu0i_BFu0ll_Sf()
{
  {
    init_simple_test("BFu0i_BFu0ll_Sf");
    static STRUCT_IF_C BFu0i_BFu0ll_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0i_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_BFu0ll_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu0ll_Sf, BFu0i_BFu0ll_Sf)
//============================================================================


struct  BFu0i_BFu0s_Sf  {
  unsigned int  :0;
  unsigned short  :0;
  struct empty v1;
};
//SIG(1 BFu0i_BFu0s_Sf) C1{ Fi:0 Fs:0 FC2{}}



static void Test_BFu0i_BFu0s_Sf()
{
  {
    init_simple_test("BFu0i_BFu0s_Sf");
    static STRUCT_IF_C BFu0i_BFu0s_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0i_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_BFu0s_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu0s_Sf, BFu0i_BFu0s_Sf)
//============================================================================


struct  BFu0i_BFu15i_Sf  {
  unsigned int  :0;
  unsigned int v1:15;
  struct empty v2;
};
//SIG(1 BFu0i_BFu15i_Sf) C1{ Fi:0 Fi:15 FC2{}}



static void Test_BFu0i_BFu15i_Sf()
{
  {
    init_simple_test("BFu0i_BFu15i_Sf");
    static STRUCT_IF_C BFu0i_BFu15i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu15i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu15i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0i_BFu15i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0i_BFu15i_Sf");
    check_field_offset(lv, v2, 2, "BFu0i_BFu15i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu15i_Sf, BFu0i_BFu15i_Sf)
//============================================================================


struct  BFu0i_BFu15ll_Sf  {
  unsigned int  :0;
  __tsu64 v1:15;
  struct empty v2;
};
//SIG(1 BFu0i_BFu15ll_Sf) C1{ Fi:0 FL:15 FC2{}}



static void Test_BFu0i_BFu15ll_Sf()
{
  {
    init_simple_test("BFu0i_BFu15ll_Sf");
    static STRUCT_IF_C BFu0i_BFu15ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu15ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu15ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0i_BFu15ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0i_BFu15ll_Sf");
    check_field_offset(lv, v2, 2, "BFu0i_BFu15ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu15ll_Sf, BFu0i_BFu15ll_Sf)
//============================================================================


struct  BFu0i_BFu15s_Sf  {
  unsigned int  :0;
  unsigned short v1:15;
  struct empty v2;
};
//SIG(1 BFu0i_BFu15s_Sf) C1{ Fi:0 Fs:15 FC2{}}



static void Test_BFu0i_BFu15s_Sf()
{
  {
    init_simple_test("BFu0i_BFu15s_Sf");
    static STRUCT_IF_C BFu0i_BFu15s_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_BFu15s_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_BFu15s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0i_BFu15s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0i_BFu15s_Sf");
    check_field_offset(lv, v2, 2, "BFu0i_BFu15s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu15s_Sf, BFu0i_BFu15s_Sf)
//============================================================================


struct  BFu0i_BFu16i_Sf  {
  unsigned int  :0;
  unsigned int v1:16;
  struct empty v2;
};
//SIG(1 BFu0i_BFu16i_Sf) C1{ Fi:0 Fi:16 FC2{}}



static void Test_BFu0i_BFu16i_Sf()
{
  {
    init_simple_test("BFu0i_BFu16i_Sf");
    static STRUCT_IF_C BFu0i_BFu16i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu16i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu16i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0i_BFu16i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0i_BFu16i_Sf");
    check_field_offset(lv, v2, 2, "BFu0i_BFu16i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu16i_Sf, BFu0i_BFu16i_Sf)
//============================================================================


struct  BFu0i_BFu16ll_Sf  {
  unsigned int  :0;
  __tsu64 v1:16;
  struct empty v2;
};
//SIG(1 BFu0i_BFu16ll_Sf) C1{ Fi:0 FL:16 FC2{}}



static void Test_BFu0i_BFu16ll_Sf()
{
  {
    init_simple_test("BFu0i_BFu16ll_Sf");
    static STRUCT_IF_C BFu0i_BFu16ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu16ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu16ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0i_BFu16ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0i_BFu16ll_Sf");
    check_field_offset(lv, v2, 2, "BFu0i_BFu16ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu16ll_Sf, BFu0i_BFu16ll_Sf)
//============================================================================


struct  BFu0i_BFu16s_Sf  {
  unsigned int  :0;
  unsigned short v1:16;
  struct empty v2;
};
//SIG(1 BFu0i_BFu16s_Sf) C1{ Fi:0 Fs:16 FC2{}}



static void Test_BFu0i_BFu16s_Sf()
{
  {
    init_simple_test("BFu0i_BFu16s_Sf");
    static STRUCT_IF_C BFu0i_BFu16s_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_BFu16s_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_BFu16s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0i_BFu16s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0i_BFu16s_Sf");
    check_field_offset(lv, v2, 2, "BFu0i_BFu16s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu16s_Sf, BFu0i_BFu16s_Sf)
//============================================================================


struct  BFu0i_BFu17i_Sf  {
  unsigned int  :0;
  unsigned int v1:17;
  struct empty v2;
};
//SIG(1 BFu0i_BFu17i_Sf) C1{ Fi:0 Fi:17 FC2{}}



static void Test_BFu0i_BFu17i_Sf()
{
  {
    init_simple_test("BFu0i_BFu17i_Sf");
    static STRUCT_IF_C BFu0i_BFu17i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu17i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu17i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0i_BFu17i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0i_BFu17i_Sf");
    check_field_offset(lv, v2, 3, "BFu0i_BFu17i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu17i_Sf, BFu0i_BFu17i_Sf)
//============================================================================


struct  BFu0i_BFu17ll_Sf  {
  unsigned int  :0;
  __tsu64 v1:17;
  struct empty v2;
};
//SIG(1 BFu0i_BFu17ll_Sf) C1{ Fi:0 FL:17 FC2{}}



static void Test_BFu0i_BFu17ll_Sf()
{
  {
    init_simple_test("BFu0i_BFu17ll_Sf");
    static STRUCT_IF_C BFu0i_BFu17ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu17ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu17ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0i_BFu17ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0i_BFu17ll_Sf");
    check_field_offset(lv, v2, 3, "BFu0i_BFu17ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu17ll_Sf, BFu0i_BFu17ll_Sf)
//============================================================================


struct  BFu0i_BFu1c_Sf  {
  unsigned int  :0;
  unsigned char v1:1;
  struct empty v2;
};
//SIG(1 BFu0i_BFu1c_Sf) C1{ Fi:0 Fc:1 FC2{}}



static void Test_BFu0i_BFu1c_Sf()
{
  {
    init_simple_test("BFu0i_BFu1c_Sf");
    static STRUCT_IF_C BFu0i_BFu1c_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_BFu1c_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu1c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0i_BFu1c_Sf");
    check_field_offset(lv, v2, 1, "BFu0i_BFu1c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu1c_Sf, BFu0i_BFu1c_Sf)
//============================================================================


struct  BFu0i_BFu1i_Sf  {
  unsigned int  :0;
  unsigned int v1:1;
  struct empty v2;
};
//SIG(1 BFu0i_BFu1i_Sf) C1{ Fi:0 Fi:1 FC2{}}



static void Test_BFu0i_BFu1i_Sf()
{
  {
    init_simple_test("BFu0i_BFu1i_Sf");
    static STRUCT_IF_C BFu0i_BFu1i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu1i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu1i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0i_BFu1i_Sf");
    check_field_offset(lv, v2, 1, "BFu0i_BFu1i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu1i_Sf, BFu0i_BFu1i_Sf)
//============================================================================


struct  BFu0i_BFu1ll_Sf  {
  unsigned int  :0;
  __tsu64 v1:1;
  struct empty v2;
};
//SIG(1 BFu0i_BFu1ll_Sf) C1{ Fi:0 FL:1 FC2{}}



static void Test_BFu0i_BFu1ll_Sf()
{
  {
    init_simple_test("BFu0i_BFu1ll_Sf");
    static STRUCT_IF_C BFu0i_BFu1ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu1ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu1ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0i_BFu1ll_Sf");
    check_field_offset(lv, v2, 1, "BFu0i_BFu1ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu1ll_Sf, BFu0i_BFu1ll_Sf)
//============================================================================


struct  BFu0i_BFu1s_Sf  {
  unsigned int  :0;
  unsigned short v1:1;
  struct empty v2;
};
//SIG(1 BFu0i_BFu1s_Sf) C1{ Fi:0 Fs:1 FC2{}}



static void Test_BFu0i_BFu1s_Sf()
{
  {
    init_simple_test("BFu0i_BFu1s_Sf");
    static STRUCT_IF_C BFu0i_BFu1s_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_BFu1s_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_BFu1s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0i_BFu1s_Sf");
    check_field_offset(lv, v2, 1, "BFu0i_BFu1s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu1s_Sf, BFu0i_BFu1s_Sf)
//============================================================================


struct  BFu0i_BFu31i_Sf  {
  unsigned int  :0;
  unsigned int v1:31;
  struct empty v2;
};
//SIG(1 BFu0i_BFu31i_Sf) C1{ Fi:0 Fi:31 FC2{}}



static void Test_BFu0i_BFu31i_Sf()
{
  {
    init_simple_test("BFu0i_BFu31i_Sf");
    static STRUCT_IF_C BFu0i_BFu31i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu31i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu31i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0i_BFu31i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0i_BFu31i_Sf");
    check_field_offset(lv, v2, 4, "BFu0i_BFu31i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu31i_Sf, BFu0i_BFu31i_Sf)
//============================================================================


struct  BFu0i_BFu31ll_Sf  {
  unsigned int  :0;
  __tsu64 v1:31;
  struct empty v2;
};
//SIG(1 BFu0i_BFu31ll_Sf) C1{ Fi:0 FL:31 FC2{}}



static void Test_BFu0i_BFu31ll_Sf()
{
  {
    init_simple_test("BFu0i_BFu31ll_Sf");
    static STRUCT_IF_C BFu0i_BFu31ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu31ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu31ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0i_BFu31ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0i_BFu31ll_Sf");
    check_field_offset(lv, v2, 4, "BFu0i_BFu31ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu31ll_Sf, BFu0i_BFu31ll_Sf)
//============================================================================


struct  BFu0i_BFu32i_Sf  {
  unsigned int  :0;
  unsigned int v1:32;
  struct empty v2;
};
//SIG(1 BFu0i_BFu32i_Sf) C1{ Fi:0 Fi:32 FC2{}}



static void Test_BFu0i_BFu32i_Sf()
{
  {
    init_simple_test("BFu0i_BFu32i_Sf");
    static STRUCT_IF_C BFu0i_BFu32i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu32i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu32i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0i_BFu32i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0i_BFu32i_Sf");
    check_field_offset(lv, v2, 4, "BFu0i_BFu32i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu32i_Sf, BFu0i_BFu32i_Sf)
//============================================================================


struct  BFu0i_BFu32ll_Sf  {
  unsigned int  :0;
  __tsu64 v1:32;
  struct empty v2;
};
//SIG(1 BFu0i_BFu32ll_Sf) C1{ Fi:0 FL:32 FC2{}}



static void Test_BFu0i_BFu32ll_Sf()
{
  {
    init_simple_test("BFu0i_BFu32ll_Sf");
    static STRUCT_IF_C BFu0i_BFu32ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu32ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu32ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0i_BFu32ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0i_BFu32ll_Sf");
    check_field_offset(lv, v2, 4, "BFu0i_BFu32ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu32ll_Sf, BFu0i_BFu32ll_Sf)
//============================================================================


struct  BFu0i_BFu33_Sf  {
  unsigned int  :0;
  __tsu64 v1:33;
  struct empty v2;
};
//SIG(1 BFu0i_BFu33_Sf) C1{ Fi:0 FL:33 FC2{}}



static void Test_BFu0i_BFu33_Sf()
{
  {
    init_simple_test("BFu0i_BFu33_Sf");
    static STRUCT_IF_C BFu0i_BFu33_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_BFu33_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu33_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu0i_BFu33_Sf");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu0i_BFu33_Sf");
    check_field_offset(lv, v2, 5, "BFu0i_BFu33_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu33_Sf, BFu0i_BFu33_Sf)
//============================================================================


struct  BFu0i_BFu7c_Sf  {
  unsigned int  :0;
  unsigned char v1:7;
  struct empty v2;
};
//SIG(1 BFu0i_BFu7c_Sf) C1{ Fi:0 Fc:7 FC2{}}



static void Test_BFu0i_BFu7c_Sf()
{
  {
    init_simple_test("BFu0i_BFu7c_Sf");
    static STRUCT_IF_C BFu0i_BFu7c_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_BFu7c_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu7c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0i_BFu7c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0i_BFu7c_Sf");
    check_field_offset(lv, v2, 1, "BFu0i_BFu7c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu7c_Sf, BFu0i_BFu7c_Sf)
//============================================================================


struct  BFu0i_BFu7i_Sf  {
  unsigned int  :0;
  unsigned int v1:7;
  struct empty v2;
};
//SIG(1 BFu0i_BFu7i_Sf) C1{ Fi:0 Fi:7 FC2{}}



static void Test_BFu0i_BFu7i_Sf()
{
  {
    init_simple_test("BFu0i_BFu7i_Sf");
    static STRUCT_IF_C BFu0i_BFu7i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu7i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu7i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0i_BFu7i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0i_BFu7i_Sf");
    check_field_offset(lv, v2, 1, "BFu0i_BFu7i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu7i_Sf, BFu0i_BFu7i_Sf)
//============================================================================


struct  BFu0i_BFu7ll_Sf  {
  unsigned int  :0;
  __tsu64 v1:7;
  struct empty v2;
};
//SIG(1 BFu0i_BFu7ll_Sf) C1{ Fi:0 FL:7 FC2{}}



static void Test_BFu0i_BFu7ll_Sf()
{
  {
    init_simple_test("BFu0i_BFu7ll_Sf");
    static STRUCT_IF_C BFu0i_BFu7ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu7ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu7ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0i_BFu7ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0i_BFu7ll_Sf");
    check_field_offset(lv, v2, 1, "BFu0i_BFu7ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu7ll_Sf, BFu0i_BFu7ll_Sf)
//============================================================================


struct  BFu0i_BFu7s_Sf  {
  unsigned int  :0;
  unsigned short v1:7;
  struct empty v2;
};
//SIG(1 BFu0i_BFu7s_Sf) C1{ Fi:0 Fs:7 FC2{}}



static void Test_BFu0i_BFu7s_Sf()
{
  {
    init_simple_test("BFu0i_BFu7s_Sf");
    static STRUCT_IF_C BFu0i_BFu7s_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_BFu7s_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_BFu7s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0i_BFu7s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0i_BFu7s_Sf");
    check_field_offset(lv, v2, 1, "BFu0i_BFu7s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu7s_Sf, BFu0i_BFu7s_Sf)
//============================================================================


struct  BFu0i_BFu8c_Sf  {
  unsigned int  :0;
  unsigned char v1:8;
  struct empty v2;
};
//SIG(1 BFu0i_BFu8c_Sf) C1{ Fi:0 Fc:8 FC2{}}



static void Test_BFu0i_BFu8c_Sf()
{
  {
    init_simple_test("BFu0i_BFu8c_Sf");
    static STRUCT_IF_C BFu0i_BFu8c_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_BFu8c_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_BFu8c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0i_BFu8c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0i_BFu8c_Sf");
    check_field_offset(lv, v2, 1, "BFu0i_BFu8c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu8c_Sf, BFu0i_BFu8c_Sf)
//============================================================================


struct  BFu0i_BFu8i_Sf  {
  unsigned int  :0;
  unsigned int v1:8;
  struct empty v2;
};
//SIG(1 BFu0i_BFu8i_Sf) C1{ Fi:0 Fi:8 FC2{}}



static void Test_BFu0i_BFu8i_Sf()
{
  {
    init_simple_test("BFu0i_BFu8i_Sf");
    static STRUCT_IF_C BFu0i_BFu8i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu8i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu8i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0i_BFu8i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0i_BFu8i_Sf");
    check_field_offset(lv, v2, 1, "BFu0i_BFu8i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu8i_Sf, BFu0i_BFu8i_Sf)
//============================================================================


struct  BFu0i_BFu8ll_Sf  {
  unsigned int  :0;
  __tsu64 v1:8;
  struct empty v2;
};
//SIG(1 BFu0i_BFu8ll_Sf) C1{ Fi:0 FL:8 FC2{}}



static void Test_BFu0i_BFu8ll_Sf()
{
  {
    init_simple_test("BFu0i_BFu8ll_Sf");
    static STRUCT_IF_C BFu0i_BFu8ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu8ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu8ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0i_BFu8ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0i_BFu8ll_Sf");
    check_field_offset(lv, v2, 1, "BFu0i_BFu8ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu8ll_Sf, BFu0i_BFu8ll_Sf)
//============================================================================


struct  BFu0i_BFu8s_Sf  {
  unsigned int  :0;
  unsigned short v1:8;
  struct empty v2;
};
//SIG(1 BFu0i_BFu8s_Sf) C1{ Fi:0 Fs:8 FC2{}}



static void Test_BFu0i_BFu8s_Sf()
{
  {
    init_simple_test("BFu0i_BFu8s_Sf");
    static STRUCT_IF_C BFu0i_BFu8s_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_BFu8s_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_BFu8s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0i_BFu8s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0i_BFu8s_Sf");
    check_field_offset(lv, v2, 1, "BFu0i_BFu8s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu8s_Sf, BFu0i_BFu8s_Sf)
//============================================================================


struct  BFu0i_BFu9i_Sf  {
  unsigned int  :0;
  unsigned int v1:9;
  struct empty v2;
};
//SIG(1 BFu0i_BFu9i_Sf) C1{ Fi:0 Fi:9 FC2{}}



static void Test_BFu0i_BFu9i_Sf()
{
  {
    init_simple_test("BFu0i_BFu9i_Sf");
    static STRUCT_IF_C BFu0i_BFu9i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_BFu9i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_BFu9i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0i_BFu9i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0i_BFu9i_Sf");
    check_field_offset(lv, v2, 2, "BFu0i_BFu9i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu9i_Sf, BFu0i_BFu9i_Sf)
//============================================================================


struct  BFu0i_BFu9ll_Sf  {
  unsigned int  :0;
  __tsu64 v1:9;
  struct empty v2;
};
//SIG(1 BFu0i_BFu9ll_Sf) C1{ Fi:0 FL:9 FC2{}}



static void Test_BFu0i_BFu9ll_Sf()
{
  {
    init_simple_test("BFu0i_BFu9ll_Sf");
    static STRUCT_IF_C BFu0i_BFu9ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_BFu9ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_BFu9ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0i_BFu9ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0i_BFu9ll_Sf");
    check_field_offset(lv, v2, 2, "BFu0i_BFu9ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu9ll_Sf, BFu0i_BFu9ll_Sf)
//============================================================================


struct  BFu0i_BFu9s_Sf  {
  unsigned int  :0;
  unsigned short v1:9;
  struct empty v2;
};
//SIG(1 BFu0i_BFu9s_Sf) C1{ Fi:0 Fs:9 FC2{}}



static void Test_BFu0i_BFu9s_Sf()
{
  {
    init_simple_test("BFu0i_BFu9s_Sf");
    static STRUCT_IF_C BFu0i_BFu9s_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_BFu9s_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_BFu9s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0i_BFu9s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0i_BFu9s_Sf");
    check_field_offset(lv, v2, 2, "BFu0i_BFu9s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_BFu9s_Sf, BFu0i_BFu9s_Sf)
//============================================================================


struct  BFu0i_C_Sf  {
  unsigned int  :0;
  char v1;
  struct empty v2;
};
//SIG(1 BFu0i_C_Sf) C1{ Fi:0 Fc FC2{}}



static void Test_BFu0i_C_Sf()
{
  {
    init_simple_test("BFu0i_C_Sf");
    static STRUCT_IF_C BFu0i_C_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_C_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_C_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_C_Sf.v1");
    check_field_offset(lv, v2, 1, "BFu0i_C_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_C_Sf, BFu0i_C_Sf)
//============================================================================


struct  BFu0i_D_Sf  {
  unsigned int  :0;
  double v1;
  struct empty v2;
};
//SIG(1 BFu0i_D_Sf) C1{ Fi:0 FL FC2{}}



static void Test_BFu0i_D_Sf()
{
  {
    init_simple_test("BFu0i_D_Sf");
    static STRUCT_IF_C BFu0i_D_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_D_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_D_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_D_Sf.v1");
    check_field_offset(lv, v2, 8, "BFu0i_D_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_D_Sf, BFu0i_D_Sf)
//============================================================================


struct  BFu0i_F_Sf  {
  unsigned int  :0;
  float v1;
  struct empty v2;
};
//SIG(1 BFu0i_F_Sf) C1{ Fi:0 Fi FC2{}}



static void Test_BFu0i_F_Sf()
{
  {
    init_simple_test("BFu0i_F_Sf");
    static STRUCT_IF_C BFu0i_F_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_F_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_F_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_F_Sf.v1");
    check_field_offset(lv, v2, 4, "BFu0i_F_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_F_Sf, BFu0i_F_Sf)
//============================================================================


struct  BFu0i_I_Sf  {
  unsigned int  :0;
  int v1;
  struct empty v2;
};
//SIG(1 BFu0i_I_Sf) C1{ Fi:0 Fi FC2{}}



static void Test_BFu0i_I_Sf()
{
  {
    init_simple_test("BFu0i_I_Sf");
    static STRUCT_IF_C BFu0i_I_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_I_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_I_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_I_Sf.v1");
    check_field_offset(lv, v2, 4, "BFu0i_I_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_I_Sf, BFu0i_I_Sf)
//============================================================================


struct  BFu0i_Ip_Sf  {
  unsigned int  :0;
  int *v1;
  struct empty v2;
};
//SIG(1 BFu0i_Ip_Sf) C1{ Fi:0 Fp FC2{}}



static void Test_BFu0i_Ip_Sf()
{
  {
    init_simple_test("BFu0i_Ip_Sf");
    static STRUCT_IF_C BFu0i_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Ip_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Ip_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_Ip_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0i_Ip_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Ip_Sf, BFu0i_Ip_Sf)
//============================================================================


struct  BFu0i_L_Sf  {
  unsigned int  :0;
  __tsi64 v1;
  struct empty v2;
};
//SIG(1 BFu0i_L_Sf) C1{ Fi:0 FL FC2{}}



static void Test_BFu0i_L_Sf()
{
  {
    init_simple_test("BFu0i_L_Sf");
    static STRUCT_IF_C BFu0i_L_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_L_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_L_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_L_Sf.v1");
    check_field_offset(lv, v2, 8, "BFu0i_L_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_L_Sf, BFu0i_L_Sf)
//============================================================================


struct  BFu0i_S_Sf  {
  unsigned int  :0;
  short v1;
  struct empty v2;
};
//SIG(1 BFu0i_S_Sf) C1{ Fi:0 Fs FC2{}}



static void Test_BFu0i_S_Sf()
{
  {
    init_simple_test("BFu0i_S_Sf");
    static STRUCT_IF_C BFu0i_S_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_S_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_S_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_S_Sf.v1");
    check_field_offset(lv, v2, 2, "BFu0i_S_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_S_Sf, BFu0i_S_Sf)
//============================================================================


struct  BFu0i_Sf  {
  unsigned int  :0;
  struct empty v1;
};
//SIG(1 BFu0i_Sf) C1{ Fi:0 FC2{}}



static void Test_BFu0i_Sf()
{
  {
    init_simple_test("BFu0i_Sf");
    static STRUCT_IF_C BFu0i_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf, BFu0i_Sf)
//============================================================================


struct  BFu0i_Sf_BFu0c  {
  unsigned int  :0;
  struct empty v1;
  unsigned char  :0;
};
//SIG(1 BFu0i_Sf_BFu0c) C1{ Fi:0 FC2{} Fc:0}



static void Test_BFu0i_Sf_BFu0c()
{
  {
    init_simple_test("BFu0i_Sf_BFu0c");
    static STRUCT_IF_C BFu0i_Sf_BFu0c lv;
    check2(sizeof(lv), 0, "sizeof(BFu0i_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu0c, BFu0i_Sf_BFu0c)
//============================================================================


struct  BFu0i_Sf_BFu0i  {
  unsigned int  :0;
  struct empty v1;
  unsigned int  :0;
};
//SIG(1 BFu0i_Sf_BFu0i) C1{ Fi:0 FC2{} Fi:0}



static void Test_BFu0i_Sf_BFu0i()
{
  {
    init_simple_test("BFu0i_Sf_BFu0i");
    static STRUCT_IF_C BFu0i_Sf_BFu0i lv;
    check2(sizeof(lv), 0, "sizeof(BFu0i_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu0i, BFu0i_Sf_BFu0i)
//============================================================================


struct  BFu0i_Sf_BFu0ll  {
  unsigned int  :0;
  struct empty v1;
  __tsu64  :0;
};
//SIG(1 BFu0i_Sf_BFu0ll) C1{ Fi:0 FC2{} FL:0}



static void Test_BFu0i_Sf_BFu0ll()
{
  {
    init_simple_test("BFu0i_Sf_BFu0ll");
    static STRUCT_IF_C BFu0i_Sf_BFu0ll lv;
    check2(sizeof(lv), 0, "sizeof(BFu0i_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu0ll, BFu0i_Sf_BFu0ll)
//============================================================================


struct  BFu0i_Sf_BFu0s  {
  unsigned int  :0;
  struct empty v1;
  unsigned short  :0;
};
//SIG(1 BFu0i_Sf_BFu0s) C1{ Fi:0 FC2{} Fs:0}



static void Test_BFu0i_Sf_BFu0s()
{
  {
    init_simple_test("BFu0i_Sf_BFu0s");
    static STRUCT_IF_C BFu0i_Sf_BFu0s lv;
    check2(sizeof(lv), 0, "sizeof(BFu0i_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu0s, BFu0i_Sf_BFu0s)
//============================================================================


struct  BFu0i_Sf_BFu15i  {
  unsigned int  :0;
  struct empty v1;
  unsigned int v2:15;
};
//SIG(1 BFu0i_Sf_BFu15i) C1{ Fi:0 FC2{} Fi:15}



static void Test_BFu0i_Sf_BFu15i()
{
  {
    init_simple_test("BFu0i_Sf_BFu15i");
    static STRUCT_IF_C BFu0i_Sf_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Sf_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu15i.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "BFu0i_Sf_BFu15i");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "BFu0i_Sf_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu15i, BFu0i_Sf_BFu15i)
//============================================================================


struct  BFu0i_Sf_BFu15ll  {
  unsigned int  :0;
  struct empty v1;
  __tsu64 v2:15;
};
//SIG(1 BFu0i_Sf_BFu15ll) C1{ Fi:0 FC2{} FL:15}



static void Test_BFu0i_Sf_BFu15ll()
{
  {
    init_simple_test("BFu0i_Sf_BFu15ll");
    static STRUCT_IF_C BFu0i_Sf_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Sf_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu15ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "BFu0i_Sf_BFu15ll");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "BFu0i_Sf_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu15ll, BFu0i_Sf_BFu15ll)
//============================================================================


struct  BFu0i_Sf_BFu15s  {
  unsigned int  :0;
  struct empty v1;
  unsigned short v2:15;
};
//SIG(1 BFu0i_Sf_BFu15s) C1{ Fi:0 FC2{} Fs:15}



static void Test_BFu0i_Sf_BFu15s()
{
  {
    init_simple_test("BFu0i_Sf_BFu15s");
    static STRUCT_IF_C BFu0i_Sf_BFu15s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_Sf_BFu15s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu15s.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "BFu0i_Sf_BFu15s");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "BFu0i_Sf_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu15s, BFu0i_Sf_BFu15s)
//============================================================================


struct  BFu0i_Sf_BFu16i  {
  unsigned int  :0;
  struct empty v1;
  unsigned int v2:16;
};
//SIG(1 BFu0i_Sf_BFu16i) C1{ Fi:0 FC2{} Fi:16}



static void Test_BFu0i_Sf_BFu16i()
{
  {
    init_simple_test("BFu0i_Sf_BFu16i");
    static STRUCT_IF_C BFu0i_Sf_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Sf_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu16i.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "BFu0i_Sf_BFu16i");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "BFu0i_Sf_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu16i, BFu0i_Sf_BFu16i)
//============================================================================


struct  BFu0i_Sf_BFu16ll  {
  unsigned int  :0;
  struct empty v1;
  __tsu64 v2:16;
};
//SIG(1 BFu0i_Sf_BFu16ll) C1{ Fi:0 FC2{} FL:16}



static void Test_BFu0i_Sf_BFu16ll()
{
  {
    init_simple_test("BFu0i_Sf_BFu16ll");
    static STRUCT_IF_C BFu0i_Sf_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Sf_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu16ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "BFu0i_Sf_BFu16ll");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "BFu0i_Sf_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu16ll, BFu0i_Sf_BFu16ll)
//============================================================================


struct  BFu0i_Sf_BFu16s  {
  unsigned int  :0;
  struct empty v1;
  unsigned short v2:16;
};
//SIG(1 BFu0i_Sf_BFu16s) C1{ Fi:0 FC2{} Fs:16}



static void Test_BFu0i_Sf_BFu16s()
{
  {
    init_simple_test("BFu0i_Sf_BFu16s");
    static STRUCT_IF_C BFu0i_Sf_BFu16s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_Sf_BFu16s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu16s.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "BFu0i_Sf_BFu16s");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "BFu0i_Sf_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu16s, BFu0i_Sf_BFu16s)
//============================================================================


struct  BFu0i_Sf_BFu17i  {
  unsigned int  :0;
  struct empty v1;
  unsigned int v2:17;
};
//SIG(1 BFu0i_Sf_BFu17i) C1{ Fi:0 FC2{} Fi:17}



static void Test_BFu0i_Sf_BFu17i()
{
  {
    init_simple_test("BFu0i_Sf_BFu17i");
    static STRUCT_IF_C BFu0i_Sf_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Sf_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu17i.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "BFu0i_Sf_BFu17i");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "BFu0i_Sf_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu17i, BFu0i_Sf_BFu17i)
//============================================================================


struct  BFu0i_Sf_BFu17ll  {
  unsigned int  :0;
  struct empty v1;
  __tsu64 v2:17;
};
//SIG(1 BFu0i_Sf_BFu17ll) C1{ Fi:0 FC2{} FL:17}



static void Test_BFu0i_Sf_BFu17ll()
{
  {
    init_simple_test("BFu0i_Sf_BFu17ll");
    static STRUCT_IF_C BFu0i_Sf_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Sf_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu17ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "BFu0i_Sf_BFu17ll");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "BFu0i_Sf_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu17ll, BFu0i_Sf_BFu17ll)
//============================================================================


struct  BFu0i_Sf_BFu1c  {
  unsigned int  :0;
  struct empty v1;
  unsigned char v2:1;
};
//SIG(1 BFu0i_Sf_BFu1c) C1{ Fi:0 FC2{} Fc:1}



static void Test_BFu0i_Sf_BFu1c()
{
  {
    init_simple_test("BFu0i_Sf_BFu1c");
    static STRUCT_IF_C BFu0i_Sf_BFu1c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_Sf_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu1c.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0i_Sf_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu1c, BFu0i_Sf_BFu1c)
//============================================================================


struct  BFu0i_Sf_BFu1i  {
  unsigned int  :0;
  struct empty v1;
  unsigned int v2:1;
};
//SIG(1 BFu0i_Sf_BFu1i) C1{ Fi:0 FC2{} Fi:1}



static void Test_BFu0i_Sf_BFu1i()
{
  {
    init_simple_test("BFu0i_Sf_BFu1i");
    static STRUCT_IF_C BFu0i_Sf_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Sf_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu1i.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0i_Sf_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu1i, BFu0i_Sf_BFu1i)
//============================================================================


struct  BFu0i_Sf_BFu1ll  {
  unsigned int  :0;
  struct empty v1;
  __tsu64 v2:1;
};
//SIG(1 BFu0i_Sf_BFu1ll) C1{ Fi:0 FC2{} FL:1}



static void Test_BFu0i_Sf_BFu1ll()
{
  {
    init_simple_test("BFu0i_Sf_BFu1ll");
    static STRUCT_IF_C BFu0i_Sf_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Sf_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu1ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0i_Sf_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu1ll, BFu0i_Sf_BFu1ll)
//============================================================================


struct  BFu0i_Sf_BFu1s  {
  unsigned int  :0;
  struct empty v1;
  unsigned short v2:1;
};
//SIG(1 BFu0i_Sf_BFu1s) C1{ Fi:0 FC2{} Fs:1}



static void Test_BFu0i_Sf_BFu1s()
{
  {
    init_simple_test("BFu0i_Sf_BFu1s");
    static STRUCT_IF_C BFu0i_Sf_BFu1s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_Sf_BFu1s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu1s.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0i_Sf_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu1s, BFu0i_Sf_BFu1s)
//============================================================================


struct  BFu0i_Sf_BFu31i  {
  unsigned int  :0;
  struct empty v1;
  unsigned int v2:31;
};
//SIG(1 BFu0i_Sf_BFu31i) C1{ Fi:0 FC2{} Fi:31}



static void Test_BFu0i_Sf_BFu31i()
{
  {
    init_simple_test("BFu0i_Sf_BFu31i");
    static STRUCT_IF_C BFu0i_Sf_BFu31i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Sf_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu31i.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "BFu0i_Sf_BFu31i");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "BFu0i_Sf_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu31i, BFu0i_Sf_BFu31i)
//============================================================================


struct  BFu0i_Sf_BFu31ll  {
  unsigned int  :0;
  struct empty v1;
  __tsu64 v2:31;
};
//SIG(1 BFu0i_Sf_BFu31ll) C1{ Fi:0 FC2{} FL:31}



static void Test_BFu0i_Sf_BFu31ll()
{
  {
    init_simple_test("BFu0i_Sf_BFu31ll");
    static STRUCT_IF_C BFu0i_Sf_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Sf_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu31ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "BFu0i_Sf_BFu31ll");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "BFu0i_Sf_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu31ll, BFu0i_Sf_BFu31ll)
//============================================================================


struct  BFu0i_Sf_BFu32i  {
  unsigned int  :0;
  struct empty v1;
  unsigned int v2:32;
};
//SIG(1 BFu0i_Sf_BFu32i) C1{ Fi:0 FC2{} Fi:32}



static void Test_BFu0i_Sf_BFu32i()
{
  {
    init_simple_test("BFu0i_Sf_BFu32i");
    static STRUCT_IF_C BFu0i_Sf_BFu32i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Sf_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu32i.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "BFu0i_Sf_BFu32i");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "BFu0i_Sf_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu32i, BFu0i_Sf_BFu32i)
//============================================================================


struct  BFu0i_Sf_BFu32ll  {
  unsigned int  :0;
  struct empty v1;
  __tsu64 v2:32;
};
//SIG(1 BFu0i_Sf_BFu32ll) C1{ Fi:0 FC2{} FL:32}



static void Test_BFu0i_Sf_BFu32ll()
{
  {
    init_simple_test("BFu0i_Sf_BFu32ll");
    static STRUCT_IF_C BFu0i_Sf_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Sf_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu32ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "BFu0i_Sf_BFu32ll");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "BFu0i_Sf_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu32ll, BFu0i_Sf_BFu32ll)
//============================================================================


struct  BFu0i_Sf_BFu33  {
  unsigned int  :0;
  struct empty v1;
  __tsu64 v2:33;
};
//SIG(1 BFu0i_Sf_BFu33) C1{ Fi:0 FC2{} FL:33}



static void Test_BFu0i_Sf_BFu33()
{
  {
    init_simple_test("BFu0i_Sf_BFu33");
    static STRUCT_IF_C BFu0i_Sf_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_Sf_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu33.v1");
    set_bf_and_test(lv, v2, 0, 0, 33, 1, "BFu0i_Sf_BFu33");
    set_bf_and_test(lv, v2, 0, 0, 33, hide_ull(1LL<<32), "BFu0i_Sf_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu33, BFu0i_Sf_BFu33)
//============================================================================


struct  BFu0i_Sf_BFu7c  {
  unsigned int  :0;
  struct empty v1;
  unsigned char v2:7;
};
//SIG(1 BFu0i_Sf_BFu7c) C1{ Fi:0 FC2{} Fc:7}



static void Test_BFu0i_Sf_BFu7c()
{
  {
    init_simple_test("BFu0i_Sf_BFu7c");
    static STRUCT_IF_C BFu0i_Sf_BFu7c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_Sf_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu7c.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0i_Sf_BFu7c");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0i_Sf_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu7c, BFu0i_Sf_BFu7c)
//============================================================================


struct  BFu0i_Sf_BFu7i  {
  unsigned int  :0;
  struct empty v1;
  unsigned int v2:7;
};
//SIG(1 BFu0i_Sf_BFu7i) C1{ Fi:0 FC2{} Fi:7}



static void Test_BFu0i_Sf_BFu7i()
{
  {
    init_simple_test("BFu0i_Sf_BFu7i");
    static STRUCT_IF_C BFu0i_Sf_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Sf_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu7i.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0i_Sf_BFu7i");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0i_Sf_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu7i, BFu0i_Sf_BFu7i)
//============================================================================


struct  BFu0i_Sf_BFu7ll  {
  unsigned int  :0;
  struct empty v1;
  __tsu64 v2:7;
};
//SIG(1 BFu0i_Sf_BFu7ll) C1{ Fi:0 FC2{} FL:7}



static void Test_BFu0i_Sf_BFu7ll()
{
  {
    init_simple_test("BFu0i_Sf_BFu7ll");
    static STRUCT_IF_C BFu0i_Sf_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Sf_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu7ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0i_Sf_BFu7ll");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0i_Sf_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu7ll, BFu0i_Sf_BFu7ll)
//============================================================================


struct  BFu0i_Sf_BFu7s  {
  unsigned int  :0;
  struct empty v1;
  unsigned short v2:7;
};
//SIG(1 BFu0i_Sf_BFu7s) C1{ Fi:0 FC2{} Fs:7}



static void Test_BFu0i_Sf_BFu7s()
{
  {
    init_simple_test("BFu0i_Sf_BFu7s");
    static STRUCT_IF_C BFu0i_Sf_BFu7s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_Sf_BFu7s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu7s.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0i_Sf_BFu7s");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0i_Sf_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu7s, BFu0i_Sf_BFu7s)
//============================================================================


struct  BFu0i_Sf_BFu8c  {
  unsigned int  :0;
  struct empty v1;
  unsigned char v2:8;
};
//SIG(1 BFu0i_Sf_BFu8c) C1{ Fi:0 FC2{} Fc:8}



static void Test_BFu0i_Sf_BFu8c()
{
  {
    init_simple_test("BFu0i_Sf_BFu8c");
    static STRUCT_IF_C BFu0i_Sf_BFu8c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_Sf_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu8c.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0i_Sf_BFu8c");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0i_Sf_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu8c, BFu0i_Sf_BFu8c)
//============================================================================


struct  BFu0i_Sf_BFu8i  {
  unsigned int  :0;
  struct empty v1;
  unsigned int v2:8;
};
//SIG(1 BFu0i_Sf_BFu8i) C1{ Fi:0 FC2{} Fi:8}



static void Test_BFu0i_Sf_BFu8i()
{
  {
    init_simple_test("BFu0i_Sf_BFu8i");
    static STRUCT_IF_C BFu0i_Sf_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Sf_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu8i.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0i_Sf_BFu8i");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0i_Sf_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu8i, BFu0i_Sf_BFu8i)
//============================================================================


struct  BFu0i_Sf_BFu8ll  {
  unsigned int  :0;
  struct empty v1;
  __tsu64 v2:8;
};
//SIG(1 BFu0i_Sf_BFu8ll) C1{ Fi:0 FC2{} FL:8}



static void Test_BFu0i_Sf_BFu8ll()
{
  {
    init_simple_test("BFu0i_Sf_BFu8ll");
    static STRUCT_IF_C BFu0i_Sf_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Sf_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu8ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0i_Sf_BFu8ll");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0i_Sf_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu8ll, BFu0i_Sf_BFu8ll)
//============================================================================


struct  BFu0i_Sf_BFu8s  {
  unsigned int  :0;
  struct empty v1;
  unsigned short v2:8;
};
//SIG(1 BFu0i_Sf_BFu8s) C1{ Fi:0 FC2{} Fs:8}



static void Test_BFu0i_Sf_BFu8s()
{
  {
    init_simple_test("BFu0i_Sf_BFu8s");
    static STRUCT_IF_C BFu0i_Sf_BFu8s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_Sf_BFu8s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu8s.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0i_Sf_BFu8s");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0i_Sf_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu8s, BFu0i_Sf_BFu8s)
//============================================================================


struct  BFu0i_Sf_BFu9i  {
  unsigned int  :0;
  struct empty v1;
  unsigned int v2:9;
};
//SIG(1 BFu0i_Sf_BFu9i) C1{ Fi:0 FC2{} Fi:9}



static void Test_BFu0i_Sf_BFu9i()
{
  {
    init_simple_test("BFu0i_Sf_BFu9i");
    static STRUCT_IF_C BFu0i_Sf_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Sf_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu9i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "BFu0i_Sf_BFu9i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "BFu0i_Sf_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu9i, BFu0i_Sf_BFu9i)
//============================================================================


struct  BFu0i_Sf_BFu9ll  {
  unsigned int  :0;
  struct empty v1;
  __tsu64 v2:9;
};
//SIG(1 BFu0i_Sf_BFu9ll) C1{ Fi:0 FC2{} FL:9}



static void Test_BFu0i_Sf_BFu9ll()
{
  {
    init_simple_test("BFu0i_Sf_BFu9ll");
    static STRUCT_IF_C BFu0i_Sf_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Sf_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu9ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "BFu0i_Sf_BFu9ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "BFu0i_Sf_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu9ll, BFu0i_Sf_BFu9ll)
//============================================================================


struct  BFu0i_Sf_BFu9s  {
  unsigned int  :0;
  struct empty v1;
  unsigned short v2:9;
};
//SIG(1 BFu0i_Sf_BFu9s) C1{ Fi:0 FC2{} Fs:9}



static void Test_BFu0i_Sf_BFu9s()
{
  {
    init_simple_test("BFu0i_Sf_BFu9s");
    static STRUCT_IF_C BFu0i_Sf_BFu9s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_Sf_BFu9s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_BFu9s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "BFu0i_Sf_BFu9s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "BFu0i_Sf_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_BFu9s, BFu0i_Sf_BFu9s)
//============================================================================


struct  BFu0i_Sf_C  {
  unsigned int  :0;
  struct empty v1;
  char v2;
};
//SIG(1 BFu0i_Sf_C) C1{ Fi:0 FC2{} Fc}



static void Test_BFu0i_Sf_C()
{
  {
    init_simple_test("BFu0i_Sf_C");
    static STRUCT_IF_C BFu0i_Sf_C lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_Sf_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Sf_C)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_C.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_C, BFu0i_Sf_C)
//============================================================================


struct  BFu0i_Sf_D  {
  unsigned int  :0;
  struct empty v1;
  double v2;
};
//SIG(1 BFu0i_Sf_D) C1{ Fi:0 FC2{} FL}



static void Test_BFu0i_Sf_D()
{
  {
    init_simple_test("BFu0i_Sf_D");
    static STRUCT_IF_C BFu0i_Sf_D lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_Sf_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_D)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_D.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_D, BFu0i_Sf_D)
//============================================================================


struct  BFu0i_Sf_F  {
  unsigned int  :0;
  struct empty v1;
  float v2;
};
//SIG(1 BFu0i_Sf_F) C1{ Fi:0 FC2{} Fi}



static void Test_BFu0i_Sf_F()
{
  {
    init_simple_test("BFu0i_Sf_F");
    static STRUCT_IF_C BFu0i_Sf_F lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Sf_F)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Sf_F)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_F.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_F, BFu0i_Sf_F)
//============================================================================


struct  BFu0i_Sf_I  {
  unsigned int  :0;
  struct empty v1;
  int v2;
};
//SIG(1 BFu0i_Sf_I) C1{ Fi:0 FC2{} Fi}



static void Test_BFu0i_Sf_I()
{
  {
    init_simple_test("BFu0i_Sf_I");
    static STRUCT_IF_C BFu0i_Sf_I lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Sf_I)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Sf_I)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_I.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_I, BFu0i_Sf_I)
//============================================================================


struct  BFu0i_Sf_Ip  {
  unsigned int  :0;
  struct empty v1;
  int *v2;
};
//SIG(1 BFu0i_Sf_Ip) C1{ Fi:0 FC2{} Fp}



static void Test_BFu0i_Sf_Ip()
{
  {
    init_simple_test("BFu0i_Sf_Ip");
    static STRUCT_IF_C BFu0i_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Sf_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_Ip)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_Ip.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_Ip, BFu0i_Sf_Ip)
//============================================================================


struct  BFu0i_Sf_L  {
  unsigned int  :0;
  struct empty v1;
  __tsi64 v2;
};
//SIG(1 BFu0i_Sf_L) C1{ Fi:0 FC2{} FL}



static void Test_BFu0i_Sf_L()
{
  {
    init_simple_test("BFu0i_Sf_L");
    static STRUCT_IF_C BFu0i_Sf_L lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_Sf_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_L)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_L.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_L, BFu0i_Sf_L)
//============================================================================


struct  BFu0i_Sf_S  {
  unsigned int  :0;
  struct empty v1;
  short v2;
};
//SIG(1 BFu0i_Sf_S) C1{ Fi:0 FC2{} Fs}



static void Test_BFu0i_Sf_S()
{
  {
    init_simple_test("BFu0i_Sf_S");
    static STRUCT_IF_C BFu0i_Sf_S lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_Sf_S)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_Sf_S)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_S.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_S, BFu0i_Sf_S)
//============================================================================


struct  BFu0i_Sf_Sf  {
  unsigned int  :0;
  struct empty v1;
  struct empty v2;
};
//SIG(1 BFu0i_Sf_Sf) C1{ Fi:0 FC2{} FC2}



static void Test_BFu0i_Sf_Sf()
{
  {
    init_simple_test("BFu0i_Sf_Sf");
    static STRUCT_IF_C BFu0i_Sf_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0i_Sf_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Sf_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_Sf.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_Sf, BFu0i_Sf_Sf)
//============================================================================


struct  BFu0i_Sf_Uc  {
  unsigned int  :0;
  struct empty v1;
  unsigned char v2;
};
//SIG(1 BFu0i_Sf_Uc) C1{ Fi:0 FC2{} Fc}



static void Test_BFu0i_Sf_Uc()
{
  {
    init_simple_test("BFu0i_Sf_Uc");
    static STRUCT_IF_C BFu0i_Sf_Uc lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_Sf_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Sf_Uc)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_Uc.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_Uc, BFu0i_Sf_Uc)
//============================================================================


struct  BFu0i_Sf_Ui  {
  unsigned int  :0;
  struct empty v1;
  unsigned int v2;
};
//SIG(1 BFu0i_Sf_Ui) C1{ Fi:0 FC2{} Fi}



static void Test_BFu0i_Sf_Ui()
{
  {
    init_simple_test("BFu0i_Sf_Ui");
    static STRUCT_IF_C BFu0i_Sf_Ui lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Sf_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Sf_Ui)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_Ui.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_Ui, BFu0i_Sf_Ui)
//============================================================================


struct  BFu0i_Sf_Ul  {
  unsigned int  :0;
  struct empty v1;
  __tsu64 v2;
};
//SIG(1 BFu0i_Sf_Ul) C1{ Fi:0 FC2{} FL}



static void Test_BFu0i_Sf_Ul()
{
  {
    init_simple_test("BFu0i_Sf_Ul");
    static STRUCT_IF_C BFu0i_Sf_Ul lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_Sf_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_Ul)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_Ul.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_Ul, BFu0i_Sf_Ul)
//============================================================================


struct  BFu0i_Sf_Us  {
  unsigned int  :0;
  struct empty v1;
  unsigned short v2;
};
//SIG(1 BFu0i_Sf_Us) C1{ Fi:0 FC2{} Fs}



static void Test_BFu0i_Sf_Us()
{
  {
    init_simple_test("BFu0i_Sf_Us");
    static STRUCT_IF_C BFu0i_Sf_Us lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_Sf_Us)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_Sf_Us)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_Us.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_Us, BFu0i_Sf_Us)
//============================================================================


struct  BFu0i_Sf_Vp  {
  unsigned int  :0;
  struct empty v1;
  void *v2;
};
//SIG(1 BFu0i_Sf_Vp) C1{ Fi:0 FC2{} Fp}



static void Test_BFu0i_Sf_Vp()
{
  {
    init_simple_test("BFu0i_Sf_Vp");
    static STRUCT_IF_C BFu0i_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Sf_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Sf_Vp)");
    check_field_offset(lv, v1, 0, "BFu0i_Sf_Vp.v1");
    check_field_offset(lv, v2, 0, "BFu0i_Sf_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Sf_Vp, BFu0i_Sf_Vp)
//============================================================================


struct  BFu0i_Uc_Sf  {
  unsigned int  :0;
  unsigned char v1;
  struct empty v2;
};
//SIG(1 BFu0i_Uc_Sf) C1{ Fi:0 Fc FC2{}}



static void Test_BFu0i_Uc_Sf()
{
  {
    init_simple_test("BFu0i_Uc_Sf");
    static STRUCT_IF_C BFu0i_Uc_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0i_Uc_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0i_Uc_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_Uc_Sf.v1");
    check_field_offset(lv, v2, 1, "BFu0i_Uc_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Uc_Sf, BFu0i_Uc_Sf)
//============================================================================


struct  BFu0i_Ui_Sf  {
  unsigned int  :0;
  unsigned int v1;
  struct empty v2;
};
//SIG(1 BFu0i_Ui_Sf) C1{ Fi:0 Fi FC2{}}



static void Test_BFu0i_Ui_Sf()
{
  {
    init_simple_test("BFu0i_Ui_Sf");
    static STRUCT_IF_C BFu0i_Ui_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0i_Ui_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0i_Ui_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_Ui_Sf.v1");
    check_field_offset(lv, v2, 4, "BFu0i_Ui_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Ui_Sf, BFu0i_Ui_Sf)
//============================================================================


struct  BFu0i_Ul_Sf  {
  unsigned int  :0;
  __tsu64 v1;
  struct empty v2;
};
//SIG(1 BFu0i_Ul_Sf) C1{ Fi:0 FL FC2{}}



static void Test_BFu0i_Ul_Sf()
{
  {
    init_simple_test("BFu0i_Ul_Sf");
    static STRUCT_IF_C BFu0i_Ul_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0i_Ul_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Ul_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_Ul_Sf.v1");
    check_field_offset(lv, v2, 8, "BFu0i_Ul_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Ul_Sf, BFu0i_Ul_Sf)
//============================================================================


struct  BFu0i_Us_Sf  {
  unsigned int  :0;
  unsigned short v1;
  struct empty v2;
};
//SIG(1 BFu0i_Us_Sf) C1{ Fi:0 Fs FC2{}}



static void Test_BFu0i_Us_Sf()
{
  {
    init_simple_test("BFu0i_Us_Sf");
    static STRUCT_IF_C BFu0i_Us_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0i_Us_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0i_Us_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_Us_Sf.v1");
    check_field_offset(lv, v2, 2, "BFu0i_Us_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Us_Sf, BFu0i_Us_Sf)
//============================================================================


struct  BFu0i_Vp_Sf  {
  unsigned int  :0;
  void *v1;
  struct empty v2;
};
//SIG(1 BFu0i_Vp_Sf) C1{ Fi:0 Fp FC2{}}



static void Test_BFu0i_Vp_Sf()
{
  {
    init_simple_test("BFu0i_Vp_Sf");
    static STRUCT_IF_C BFu0i_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0i_Vp_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0i_Vp_Sf)");
    check_field_offset(lv, v1, 0, "BFu0i_Vp_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0i_Vp_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0i_Vp_Sf, BFu0i_Vp_Sf)
//============================================================================


struct  BFu0ll_BFu0c_Sf  {
  __tsu64  :0;
  unsigned char  :0;
  struct empty v1;
};
//SIG(1 BFu0ll_BFu0c_Sf) C1{ FL:0 Fc:0 FC2{}}



static void Test_BFu0ll_BFu0c_Sf()
{
  {
    init_simple_test("BFu0ll_BFu0c_Sf");
    static STRUCT_IF_C BFu0ll_BFu0c_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0ll_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_BFu0c_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu0c_Sf, BFu0ll_BFu0c_Sf)
//============================================================================


struct  BFu0ll_BFu0i_Sf  {
  __tsu64  :0;
  unsigned int  :0;
  struct empty v1;
};
//SIG(1 BFu0ll_BFu0i_Sf) C1{ FL:0 Fi:0 FC2{}}



static void Test_BFu0ll_BFu0i_Sf()
{
  {
    init_simple_test("BFu0ll_BFu0i_Sf");
    static STRUCT_IF_C BFu0ll_BFu0i_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0ll_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_BFu0i_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu0i_Sf, BFu0ll_BFu0i_Sf)
//============================================================================


struct  BFu0ll_BFu0ll_Sf  {
  __tsu64  :0;
  __tsu64  :0;
  struct empty v1;
};
//SIG(1 BFu0ll_BFu0ll_Sf) C1{ FL:0 FL:0 FC2{}}



static void Test_BFu0ll_BFu0ll_Sf()
{
  {
    init_simple_test("BFu0ll_BFu0ll_Sf");
    static STRUCT_IF_C BFu0ll_BFu0ll_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0ll_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_BFu0ll_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu0ll_Sf, BFu0ll_BFu0ll_Sf)
//============================================================================


struct  BFu0ll_BFu0s_Sf  {
  __tsu64  :0;
  unsigned short  :0;
  struct empty v1;
};
//SIG(1 BFu0ll_BFu0s_Sf) C1{ FL:0 Fs:0 FC2{}}



static void Test_BFu0ll_BFu0s_Sf()
{
  {
    init_simple_test("BFu0ll_BFu0s_Sf");
    static STRUCT_IF_C BFu0ll_BFu0s_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0ll_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_BFu0s_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu0s_Sf, BFu0ll_BFu0s_Sf)
//============================================================================


struct  BFu0ll_BFu15i_Sf  {
  __tsu64  :0;
  unsigned int v1:15;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu15i_Sf) C1{ FL:0 Fi:15 FC2{}}



static void Test_BFu0ll_BFu15i_Sf()
{
  {
    init_simple_test("BFu0ll_BFu15i_Sf");
    static STRUCT_IF_C BFu0ll_BFu15i_Sf lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu15i_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu15i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0ll_BFu15i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0ll_BFu15i_Sf");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu15i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu15i_Sf, BFu0ll_BFu15i_Sf)
//============================================================================


struct  BFu0ll_BFu15ll_Sf  {
  __tsu64  :0;
  __tsu64 v1:15;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu15ll_Sf) C1{ FL:0 FL:15 FC2{}}



static void Test_BFu0ll_BFu15ll_Sf()
{
  {
    init_simple_test("BFu0ll_BFu15ll_Sf");
    static STRUCT_IF_C BFu0ll_BFu15ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu15ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu15ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0ll_BFu15ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0ll_BFu15ll_Sf");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu15ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu15ll_Sf, BFu0ll_BFu15ll_Sf)
//============================================================================


struct  BFu0ll_BFu15s_Sf  {
  __tsu64  :0;
  unsigned short v1:15;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu15s_Sf) C1{ FL:0 Fs:15 FC2{}}



static void Test_BFu0ll_BFu15s_Sf()
{
  {
    init_simple_test("BFu0ll_BFu15s_Sf");
    static STRUCT_IF_C BFu0ll_BFu15s_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_BFu15s_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_BFu15s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0ll_BFu15s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0ll_BFu15s_Sf");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu15s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu15s_Sf, BFu0ll_BFu15s_Sf)
//============================================================================


struct  BFu0ll_BFu16i_Sf  {
  __tsu64  :0;
  unsigned int v1:16;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu16i_Sf) C1{ FL:0 Fi:16 FC2{}}



static void Test_BFu0ll_BFu16i_Sf()
{
  {
    init_simple_test("BFu0ll_BFu16i_Sf");
    static STRUCT_IF_C BFu0ll_BFu16i_Sf lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu16i_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu16i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0ll_BFu16i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0ll_BFu16i_Sf");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu16i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu16i_Sf, BFu0ll_BFu16i_Sf)
//============================================================================


struct  BFu0ll_BFu16ll_Sf  {
  __tsu64  :0;
  __tsu64 v1:16;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu16ll_Sf) C1{ FL:0 FL:16 FC2{}}



static void Test_BFu0ll_BFu16ll_Sf()
{
  {
    init_simple_test("BFu0ll_BFu16ll_Sf");
    static STRUCT_IF_C BFu0ll_BFu16ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu16ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu16ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0ll_BFu16ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0ll_BFu16ll_Sf");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu16ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu16ll_Sf, BFu0ll_BFu16ll_Sf)
//============================================================================


struct  BFu0ll_BFu16s_Sf  {
  __tsu64  :0;
  unsigned short v1:16;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu16s_Sf) C1{ FL:0 Fs:16 FC2{}}



static void Test_BFu0ll_BFu16s_Sf()
{
  {
    init_simple_test("BFu0ll_BFu16s_Sf");
    static STRUCT_IF_C BFu0ll_BFu16s_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_BFu16s_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_BFu16s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0ll_BFu16s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0ll_BFu16s_Sf");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu16s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu16s_Sf, BFu0ll_BFu16s_Sf)
//============================================================================


struct  BFu0ll_BFu17i_Sf  {
  __tsu64  :0;
  unsigned int v1:17;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu17i_Sf) C1{ FL:0 Fi:17 FC2{}}



static void Test_BFu0ll_BFu17i_Sf()
{
  {
    init_simple_test("BFu0ll_BFu17i_Sf");
    static STRUCT_IF_C BFu0ll_BFu17i_Sf lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu17i_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu17i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0ll_BFu17i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0ll_BFu17i_Sf");
    check_field_offset(lv, v2, 3, "BFu0ll_BFu17i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu17i_Sf, BFu0ll_BFu17i_Sf)
//============================================================================


struct  BFu0ll_BFu17ll_Sf  {
  __tsu64  :0;
  __tsu64 v1:17;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu17ll_Sf) C1{ FL:0 FL:17 FC2{}}



static void Test_BFu0ll_BFu17ll_Sf()
{
  {
    init_simple_test("BFu0ll_BFu17ll_Sf");
    static STRUCT_IF_C BFu0ll_BFu17ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu17ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu17ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0ll_BFu17ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0ll_BFu17ll_Sf");
    check_field_offset(lv, v2, 3, "BFu0ll_BFu17ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu17ll_Sf, BFu0ll_BFu17ll_Sf)
//============================================================================


struct  BFu0ll_BFu1c_Sf  {
  __tsu64  :0;
  unsigned char v1:1;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu1c_Sf) C1{ FL:0 Fc:1 FC2{}}



static void Test_BFu0ll_BFu1c_Sf()
{
  {
    init_simple_test("BFu0ll_BFu1c_Sf");
    static STRUCT_IF_C BFu0ll_BFu1c_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_BFu1c_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu1c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0ll_BFu1c_Sf");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu1c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu1c_Sf, BFu0ll_BFu1c_Sf)
//============================================================================


struct  BFu0ll_BFu1i_Sf  {
  __tsu64  :0;
  unsigned int v1:1;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu1i_Sf) C1{ FL:0 Fi:1 FC2{}}



static void Test_BFu0ll_BFu1i_Sf()
{
  {
    init_simple_test("BFu0ll_BFu1i_Sf");
    static STRUCT_IF_C BFu0ll_BFu1i_Sf lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu1i_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu1i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0ll_BFu1i_Sf");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu1i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu1i_Sf, BFu0ll_BFu1i_Sf)
//============================================================================


struct  BFu0ll_BFu1ll_Sf  {
  __tsu64  :0;
  __tsu64 v1:1;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu1ll_Sf) C1{ FL:0 FL:1 FC2{}}



static void Test_BFu0ll_BFu1ll_Sf()
{
  {
    init_simple_test("BFu0ll_BFu1ll_Sf");
    static STRUCT_IF_C BFu0ll_BFu1ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu1ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu1ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0ll_BFu1ll_Sf");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu1ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu1ll_Sf, BFu0ll_BFu1ll_Sf)
//============================================================================


struct  BFu0ll_BFu1s_Sf  {
  __tsu64  :0;
  unsigned short v1:1;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu1s_Sf) C1{ FL:0 Fs:1 FC2{}}



static void Test_BFu0ll_BFu1s_Sf()
{
  {
    init_simple_test("BFu0ll_BFu1s_Sf");
    static STRUCT_IF_C BFu0ll_BFu1s_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_BFu1s_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_BFu1s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0ll_BFu1s_Sf");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu1s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu1s_Sf, BFu0ll_BFu1s_Sf)
//============================================================================


struct  BFu0ll_BFu31i_Sf  {
  __tsu64  :0;
  unsigned int v1:31;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu31i_Sf) C1{ FL:0 Fi:31 FC2{}}



static void Test_BFu0ll_BFu31i_Sf()
{
  {
    init_simple_test("BFu0ll_BFu31i_Sf");
    static STRUCT_IF_C BFu0ll_BFu31i_Sf lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu31i_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu31i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0ll_BFu31i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0ll_BFu31i_Sf");
    check_field_offset(lv, v2, 4, "BFu0ll_BFu31i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu31i_Sf, BFu0ll_BFu31i_Sf)
//============================================================================


struct  BFu0ll_BFu31ll_Sf  {
  __tsu64  :0;
  __tsu64 v1:31;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu31ll_Sf) C1{ FL:0 FL:31 FC2{}}



static void Test_BFu0ll_BFu31ll_Sf()
{
  {
    init_simple_test("BFu0ll_BFu31ll_Sf");
    static STRUCT_IF_C BFu0ll_BFu31ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu31ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu31ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0ll_BFu31ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0ll_BFu31ll_Sf");
    check_field_offset(lv, v2, 4, "BFu0ll_BFu31ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu31ll_Sf, BFu0ll_BFu31ll_Sf)
//============================================================================


struct  BFu0ll_BFu32i_Sf  {
  __tsu64  :0;
  unsigned int v1:32;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu32i_Sf) C1{ FL:0 Fi:32 FC2{}}



static void Test_BFu0ll_BFu32i_Sf()
{
  {
    init_simple_test("BFu0ll_BFu32i_Sf");
    static STRUCT_IF_C BFu0ll_BFu32i_Sf lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu32i_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu32i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0ll_BFu32i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0ll_BFu32i_Sf");
    check_field_offset(lv, v2, 4, "BFu0ll_BFu32i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu32i_Sf, BFu0ll_BFu32i_Sf)
//============================================================================


struct  BFu0ll_BFu32ll_Sf  {
  __tsu64  :0;
  __tsu64 v1:32;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu32ll_Sf) C1{ FL:0 FL:32 FC2{}}



static void Test_BFu0ll_BFu32ll_Sf()
{
  {
    init_simple_test("BFu0ll_BFu32ll_Sf");
    static STRUCT_IF_C BFu0ll_BFu32ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu32ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu32ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0ll_BFu32ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0ll_BFu32ll_Sf");
    check_field_offset(lv, v2, 4, "BFu0ll_BFu32ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu32ll_Sf, BFu0ll_BFu32ll_Sf)
//============================================================================


struct  BFu0ll_BFu33_Sf  {
  __tsu64  :0;
  __tsu64 v1:33;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu33_Sf) C1{ FL:0 FL:33 FC2{}}



static void Test_BFu0ll_BFu33_Sf()
{
  {
    init_simple_test("BFu0ll_BFu33_Sf");
    static STRUCT_IF_C BFu0ll_BFu33_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_BFu33_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu33_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu0ll_BFu33_Sf");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu0ll_BFu33_Sf");
    check_field_offset(lv, v2, 5, "BFu0ll_BFu33_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu33_Sf, BFu0ll_BFu33_Sf)
//============================================================================


struct  BFu0ll_BFu7c_Sf  {
  __tsu64  :0;
  unsigned char v1:7;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu7c_Sf) C1{ FL:0 Fc:7 FC2{}}



static void Test_BFu0ll_BFu7c_Sf()
{
  {
    init_simple_test("BFu0ll_BFu7c_Sf");
    static STRUCT_IF_C BFu0ll_BFu7c_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_BFu7c_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu7c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0ll_BFu7c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0ll_BFu7c_Sf");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu7c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu7c_Sf, BFu0ll_BFu7c_Sf)
//============================================================================


struct  BFu0ll_BFu7i_Sf  {
  __tsu64  :0;
  unsigned int v1:7;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu7i_Sf) C1{ FL:0 Fi:7 FC2{}}



static void Test_BFu0ll_BFu7i_Sf()
{
  {
    init_simple_test("BFu0ll_BFu7i_Sf");
    static STRUCT_IF_C BFu0ll_BFu7i_Sf lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu7i_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu7i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0ll_BFu7i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0ll_BFu7i_Sf");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu7i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu7i_Sf, BFu0ll_BFu7i_Sf)
//============================================================================


struct  BFu0ll_BFu7ll_Sf  {
  __tsu64  :0;
  __tsu64 v1:7;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu7ll_Sf) C1{ FL:0 FL:7 FC2{}}



static void Test_BFu0ll_BFu7ll_Sf()
{
  {
    init_simple_test("BFu0ll_BFu7ll_Sf");
    static STRUCT_IF_C BFu0ll_BFu7ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu7ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu7ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0ll_BFu7ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0ll_BFu7ll_Sf");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu7ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu7ll_Sf, BFu0ll_BFu7ll_Sf)
//============================================================================


struct  BFu0ll_BFu7s_Sf  {
  __tsu64  :0;
  unsigned short v1:7;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu7s_Sf) C1{ FL:0 Fs:7 FC2{}}



static void Test_BFu0ll_BFu7s_Sf()
{
  {
    init_simple_test("BFu0ll_BFu7s_Sf");
    static STRUCT_IF_C BFu0ll_BFu7s_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_BFu7s_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_BFu7s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0ll_BFu7s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0ll_BFu7s_Sf");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu7s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu7s_Sf, BFu0ll_BFu7s_Sf)
//============================================================================


struct  BFu0ll_BFu8c_Sf  {
  __tsu64  :0;
  unsigned char v1:8;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu8c_Sf) C1{ FL:0 Fc:8 FC2{}}



static void Test_BFu0ll_BFu8c_Sf()
{
  {
    init_simple_test("BFu0ll_BFu8c_Sf");
    static STRUCT_IF_C BFu0ll_BFu8c_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_BFu8c_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_BFu8c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0ll_BFu8c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0ll_BFu8c_Sf");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu8c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu8c_Sf, BFu0ll_BFu8c_Sf)
//============================================================================


struct  BFu0ll_BFu8i_Sf  {
  __tsu64  :0;
  unsigned int v1:8;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu8i_Sf) C1{ FL:0 Fi:8 FC2{}}



static void Test_BFu0ll_BFu8i_Sf()
{
  {
    init_simple_test("BFu0ll_BFu8i_Sf");
    static STRUCT_IF_C BFu0ll_BFu8i_Sf lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu8i_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu8i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0ll_BFu8i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0ll_BFu8i_Sf");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu8i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu8i_Sf, BFu0ll_BFu8i_Sf)
//============================================================================


struct  BFu0ll_BFu8ll_Sf  {
  __tsu64  :0;
  __tsu64 v1:8;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu8ll_Sf) C1{ FL:0 FL:8 FC2{}}



static void Test_BFu0ll_BFu8ll_Sf()
{
  {
    init_simple_test("BFu0ll_BFu8ll_Sf");
    static STRUCT_IF_C BFu0ll_BFu8ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu8ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu8ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0ll_BFu8ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0ll_BFu8ll_Sf");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu8ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu8ll_Sf, BFu0ll_BFu8ll_Sf)
//============================================================================


struct  BFu0ll_BFu8s_Sf  {
  __tsu64  :0;
  unsigned short v1:8;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu8s_Sf) C1{ FL:0 Fs:8 FC2{}}



static void Test_BFu0ll_BFu8s_Sf()
{
  {
    init_simple_test("BFu0ll_BFu8s_Sf");
    static STRUCT_IF_C BFu0ll_BFu8s_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_BFu8s_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_BFu8s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0ll_BFu8s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0ll_BFu8s_Sf");
    check_field_offset(lv, v2, 1, "BFu0ll_BFu8s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu8s_Sf, BFu0ll_BFu8s_Sf)
//============================================================================


struct  BFu0ll_BFu9i_Sf  {
  __tsu64  :0;
  unsigned int v1:9;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu9i_Sf) C1{ FL:0 Fi:9 FC2{}}



static void Test_BFu0ll_BFu9i_Sf()
{
  {
    init_simple_test("BFu0ll_BFu9i_Sf");
    static STRUCT_IF_C BFu0ll_BFu9i_Sf lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_BFu9i_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_BFu9i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0ll_BFu9i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0ll_BFu9i_Sf");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu9i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu9i_Sf, BFu0ll_BFu9i_Sf)
//============================================================================


struct  BFu0ll_BFu9ll_Sf  {
  __tsu64  :0;
  __tsu64 v1:9;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu9ll_Sf) C1{ FL:0 FL:9 FC2{}}



static void Test_BFu0ll_BFu9ll_Sf()
{
  {
    init_simple_test("BFu0ll_BFu9ll_Sf");
    static STRUCT_IF_C BFu0ll_BFu9ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_BFu9ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_BFu9ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0ll_BFu9ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0ll_BFu9ll_Sf");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu9ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu9ll_Sf, BFu0ll_BFu9ll_Sf)
//============================================================================


struct  BFu0ll_BFu9s_Sf  {
  __tsu64  :0;
  unsigned short v1:9;
  struct empty v2;
};
//SIG(1 BFu0ll_BFu9s_Sf) C1{ FL:0 Fs:9 FC2{}}



static void Test_BFu0ll_BFu9s_Sf()
{
  {
    init_simple_test("BFu0ll_BFu9s_Sf");
    static STRUCT_IF_C BFu0ll_BFu9s_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_BFu9s_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_BFu9s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0ll_BFu9s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0ll_BFu9s_Sf");
    check_field_offset(lv, v2, 2, "BFu0ll_BFu9s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_BFu9s_Sf, BFu0ll_BFu9s_Sf)
//============================================================================


struct  BFu0ll_C_Sf  {
  __tsu64  :0;
  char v1;
  struct empty v2;
};
//SIG(1 BFu0ll_C_Sf) C1{ FL:0 Fc FC2{}}



static void Test_BFu0ll_C_Sf()
{
  {
    init_simple_test("BFu0ll_C_Sf");
    static STRUCT_IF_C BFu0ll_C_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_C_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_C_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_C_Sf.v1");
    check_field_offset(lv, v2, 1, "BFu0ll_C_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_C_Sf, BFu0ll_C_Sf)
//============================================================================


struct  BFu0ll_D_Sf  {
  __tsu64  :0;
  double v1;
  struct empty v2;
};
//SIG(1 BFu0ll_D_Sf) C1{ FL:0 FL FC2{}}



static void Test_BFu0ll_D_Sf()
{
  {
    init_simple_test("BFu0ll_D_Sf");
    static STRUCT_IF_C BFu0ll_D_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_D_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_D_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_D_Sf.v1");
    check_field_offset(lv, v2, 8, "BFu0ll_D_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_D_Sf, BFu0ll_D_Sf)
//============================================================================


struct  BFu0ll_F_Sf  {
  __tsu64  :0;
  float v1;
  struct empty v2;
};
//SIG(1 BFu0ll_F_Sf) C1{ FL:0 Fi FC2{}}



static void Test_BFu0ll_F_Sf()
{
  {
    init_simple_test("BFu0ll_F_Sf");
    static STRUCT_IF_C BFu0ll_F_Sf lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_F_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_F_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_F_Sf.v1");
    check_field_offset(lv, v2, 4, "BFu0ll_F_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_F_Sf, BFu0ll_F_Sf)
//============================================================================


struct  BFu0ll_I_Sf  {
  __tsu64  :0;
  int v1;
  struct empty v2;
};
//SIG(1 BFu0ll_I_Sf) C1{ FL:0 Fi FC2{}}



static void Test_BFu0ll_I_Sf()
{
  {
    init_simple_test("BFu0ll_I_Sf");
    static STRUCT_IF_C BFu0ll_I_Sf lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_I_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_I_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_I_Sf.v1");
    check_field_offset(lv, v2, 4, "BFu0ll_I_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_I_Sf, BFu0ll_I_Sf)
//============================================================================


struct  BFu0ll_Ip_Sf  {
  __tsu64  :0;
  int *v1;
  struct empty v2;
};
//SIG(1 BFu0ll_Ip_Sf) C1{ FL:0 Fp FC2{}}



static void Test_BFu0ll_Ip_Sf()
{
  {
    init_simple_test("BFu0ll_Ip_Sf");
    static STRUCT_IF_C BFu0ll_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Ip_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Ip_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_Ip_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0ll_Ip_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Ip_Sf, BFu0ll_Ip_Sf)
//============================================================================


struct  BFu0ll_L_Sf  {
  __tsu64  :0;
  __tsi64 v1;
  struct empty v2;
};
//SIG(1 BFu0ll_L_Sf) C1{ FL:0 FL FC2{}}



static void Test_BFu0ll_L_Sf()
{
  {
    init_simple_test("BFu0ll_L_Sf");
    static STRUCT_IF_C BFu0ll_L_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_L_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_L_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_L_Sf.v1");
    check_field_offset(lv, v2, 8, "BFu0ll_L_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_L_Sf, BFu0ll_L_Sf)
//============================================================================


struct  BFu0ll_S_Sf  {
  __tsu64  :0;
  short v1;
  struct empty v2;
};
//SIG(1 BFu0ll_S_Sf) C1{ FL:0 Fs FC2{}}



static void Test_BFu0ll_S_Sf()
{
  {
    init_simple_test("BFu0ll_S_Sf");
    static STRUCT_IF_C BFu0ll_S_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_S_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_S_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_S_Sf.v1");
    check_field_offset(lv, v2, 2, "BFu0ll_S_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_S_Sf, BFu0ll_S_Sf)
//============================================================================


struct  BFu0ll_Sf  {
  __tsu64  :0;
  struct empty v1;
};
//SIG(1 BFu0ll_Sf) C1{ FL:0 FC2{}}



static void Test_BFu0ll_Sf()
{
  {
    init_simple_test("BFu0ll_Sf");
    static STRUCT_IF_C BFu0ll_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf, BFu0ll_Sf)
//============================================================================


struct  BFu0ll_Sf_BFu0c  {
  __tsu64  :0;
  struct empty v1;
  unsigned char  :0;
};
//SIG(1 BFu0ll_Sf_BFu0c) C1{ FL:0 FC2{} Fc:0}



static void Test_BFu0ll_Sf_BFu0c()
{
  {
    init_simple_test("BFu0ll_Sf_BFu0c");
    static STRUCT_IF_C BFu0ll_Sf_BFu0c lv;
    check2(sizeof(lv), 0, "sizeof(BFu0ll_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu0c, BFu0ll_Sf_BFu0c)
//============================================================================


struct  BFu0ll_Sf_BFu0i  {
  __tsu64  :0;
  struct empty v1;
  unsigned int  :0;
};
//SIG(1 BFu0ll_Sf_BFu0i) C1{ FL:0 FC2{} Fi:0}



static void Test_BFu0ll_Sf_BFu0i()
{
  {
    init_simple_test("BFu0ll_Sf_BFu0i");
    static STRUCT_IF_C BFu0ll_Sf_BFu0i lv;
    check2(sizeof(lv), 0, "sizeof(BFu0ll_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu0i, BFu0ll_Sf_BFu0i)
//============================================================================


struct  BFu0ll_Sf_BFu0ll  {
  __tsu64  :0;
  struct empty v1;
  __tsu64  :0;
};
//SIG(1 BFu0ll_Sf_BFu0ll) C1{ FL:0 FC2{} FL:0}



static void Test_BFu0ll_Sf_BFu0ll()
{
  {
    init_simple_test("BFu0ll_Sf_BFu0ll");
    static STRUCT_IF_C BFu0ll_Sf_BFu0ll lv;
    check2(sizeof(lv), 0, "sizeof(BFu0ll_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu0ll, BFu0ll_Sf_BFu0ll)
//============================================================================


struct  BFu0ll_Sf_BFu0s  {
  __tsu64  :0;
  struct empty v1;
  unsigned short  :0;
};
//SIG(1 BFu0ll_Sf_BFu0s) C1{ FL:0 FC2{} Fs:0}



static void Test_BFu0ll_Sf_BFu0s()
{
  {
    init_simple_test("BFu0ll_Sf_BFu0s");
    static STRUCT_IF_C BFu0ll_Sf_BFu0s lv;
    check2(sizeof(lv), 0, "sizeof(BFu0ll_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu0s, BFu0ll_Sf_BFu0s)
//============================================================================


struct  BFu0ll_Sf_BFu15i  {
  __tsu64  :0;
  struct empty v1;
  unsigned int v2:15;
};
//SIG(1 BFu0ll_Sf_BFu15i) C1{ FL:0 FC2{} Fi:15}



static void Test_BFu0ll_Sf_BFu15i()
{
  {
    init_simple_test("BFu0ll_Sf_BFu15i");
    static STRUCT_IF_C BFu0ll_Sf_BFu15i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Sf_BFu15i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu15i.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "BFu0ll_Sf_BFu15i");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "BFu0ll_Sf_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu15i, BFu0ll_Sf_BFu15i)
//============================================================================


struct  BFu0ll_Sf_BFu15ll  {
  __tsu64  :0;
  struct empty v1;
  __tsu64 v2:15;
};
//SIG(1 BFu0ll_Sf_BFu15ll) C1{ FL:0 FC2{} FL:15}



static void Test_BFu0ll_Sf_BFu15ll()
{
  {
    init_simple_test("BFu0ll_Sf_BFu15ll");
    static STRUCT_IF_C BFu0ll_Sf_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Sf_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu15ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "BFu0ll_Sf_BFu15ll");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "BFu0ll_Sf_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu15ll, BFu0ll_Sf_BFu15ll)
//============================================================================


struct  BFu0ll_Sf_BFu15s  {
  __tsu64  :0;
  struct empty v1;
  unsigned short v2:15;
};
//SIG(1 BFu0ll_Sf_BFu15s) C1{ FL:0 FC2{} Fs:15}



static void Test_BFu0ll_Sf_BFu15s()
{
  {
    init_simple_test("BFu0ll_Sf_BFu15s");
    static STRUCT_IF_C BFu0ll_Sf_BFu15s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_Sf_BFu15s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu15s.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "BFu0ll_Sf_BFu15s");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "BFu0ll_Sf_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu15s, BFu0ll_Sf_BFu15s)
//============================================================================


struct  BFu0ll_Sf_BFu16i  {
  __tsu64  :0;
  struct empty v1;
  unsigned int v2:16;
};
//SIG(1 BFu0ll_Sf_BFu16i) C1{ FL:0 FC2{} Fi:16}



static void Test_BFu0ll_Sf_BFu16i()
{
  {
    init_simple_test("BFu0ll_Sf_BFu16i");
    static STRUCT_IF_C BFu0ll_Sf_BFu16i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Sf_BFu16i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu16i.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "BFu0ll_Sf_BFu16i");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "BFu0ll_Sf_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu16i, BFu0ll_Sf_BFu16i)
//============================================================================


struct  BFu0ll_Sf_BFu16ll  {
  __tsu64  :0;
  struct empty v1;
  __tsu64 v2:16;
};
//SIG(1 BFu0ll_Sf_BFu16ll) C1{ FL:0 FC2{} FL:16}



static void Test_BFu0ll_Sf_BFu16ll()
{
  {
    init_simple_test("BFu0ll_Sf_BFu16ll");
    static STRUCT_IF_C BFu0ll_Sf_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Sf_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu16ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "BFu0ll_Sf_BFu16ll");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "BFu0ll_Sf_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu16ll, BFu0ll_Sf_BFu16ll)
//============================================================================


struct  BFu0ll_Sf_BFu16s  {
  __tsu64  :0;
  struct empty v1;
  unsigned short v2:16;
};
//SIG(1 BFu0ll_Sf_BFu16s) C1{ FL:0 FC2{} Fs:16}



static void Test_BFu0ll_Sf_BFu16s()
{
  {
    init_simple_test("BFu0ll_Sf_BFu16s");
    static STRUCT_IF_C BFu0ll_Sf_BFu16s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_Sf_BFu16s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu16s.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "BFu0ll_Sf_BFu16s");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "BFu0ll_Sf_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu16s, BFu0ll_Sf_BFu16s)
//============================================================================


struct  BFu0ll_Sf_BFu17i  {
  __tsu64  :0;
  struct empty v1;
  unsigned int v2:17;
};
//SIG(1 BFu0ll_Sf_BFu17i) C1{ FL:0 FC2{} Fi:17}



static void Test_BFu0ll_Sf_BFu17i()
{
  {
    init_simple_test("BFu0ll_Sf_BFu17i");
    static STRUCT_IF_C BFu0ll_Sf_BFu17i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Sf_BFu17i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu17i.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "BFu0ll_Sf_BFu17i");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "BFu0ll_Sf_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu17i, BFu0ll_Sf_BFu17i)
//============================================================================


struct  BFu0ll_Sf_BFu17ll  {
  __tsu64  :0;
  struct empty v1;
  __tsu64 v2:17;
};
//SIG(1 BFu0ll_Sf_BFu17ll) C1{ FL:0 FC2{} FL:17}



static void Test_BFu0ll_Sf_BFu17ll()
{
  {
    init_simple_test("BFu0ll_Sf_BFu17ll");
    static STRUCT_IF_C BFu0ll_Sf_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Sf_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu17ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "BFu0ll_Sf_BFu17ll");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "BFu0ll_Sf_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu17ll, BFu0ll_Sf_BFu17ll)
//============================================================================


struct  BFu0ll_Sf_BFu1c  {
  __tsu64  :0;
  struct empty v1;
  unsigned char v2:1;
};
//SIG(1 BFu0ll_Sf_BFu1c) C1{ FL:0 FC2{} Fc:1}



static void Test_BFu0ll_Sf_BFu1c()
{
  {
    init_simple_test("BFu0ll_Sf_BFu1c");
    static STRUCT_IF_C BFu0ll_Sf_BFu1c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_Sf_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu1c.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0ll_Sf_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu1c, BFu0ll_Sf_BFu1c)
//============================================================================


struct  BFu0ll_Sf_BFu1i  {
  __tsu64  :0;
  struct empty v1;
  unsigned int v2:1;
};
//SIG(1 BFu0ll_Sf_BFu1i) C1{ FL:0 FC2{} Fi:1}



static void Test_BFu0ll_Sf_BFu1i()
{
  {
    init_simple_test("BFu0ll_Sf_BFu1i");
    static STRUCT_IF_C BFu0ll_Sf_BFu1i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Sf_BFu1i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu1i.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0ll_Sf_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu1i, BFu0ll_Sf_BFu1i)
//============================================================================


struct  BFu0ll_Sf_BFu1ll  {
  __tsu64  :0;
  struct empty v1;
  __tsu64 v2:1;
};
//SIG(1 BFu0ll_Sf_BFu1ll) C1{ FL:0 FC2{} FL:1}



static void Test_BFu0ll_Sf_BFu1ll()
{
  {
    init_simple_test("BFu0ll_Sf_BFu1ll");
    static STRUCT_IF_C BFu0ll_Sf_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Sf_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu1ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0ll_Sf_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu1ll, BFu0ll_Sf_BFu1ll)
//============================================================================


struct  BFu0ll_Sf_BFu1s  {
  __tsu64  :0;
  struct empty v1;
  unsigned short v2:1;
};
//SIG(1 BFu0ll_Sf_BFu1s) C1{ FL:0 FC2{} Fs:1}



static void Test_BFu0ll_Sf_BFu1s()
{
  {
    init_simple_test("BFu0ll_Sf_BFu1s");
    static STRUCT_IF_C BFu0ll_Sf_BFu1s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_Sf_BFu1s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu1s.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0ll_Sf_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu1s, BFu0ll_Sf_BFu1s)
//============================================================================


struct  BFu0ll_Sf_BFu31i  {
  __tsu64  :0;
  struct empty v1;
  unsigned int v2:31;
};
//SIG(1 BFu0ll_Sf_BFu31i) C1{ FL:0 FC2{} Fi:31}



static void Test_BFu0ll_Sf_BFu31i()
{
  {
    init_simple_test("BFu0ll_Sf_BFu31i");
    static STRUCT_IF_C BFu0ll_Sf_BFu31i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Sf_BFu31i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu31i.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "BFu0ll_Sf_BFu31i");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "BFu0ll_Sf_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu31i, BFu0ll_Sf_BFu31i)
//============================================================================


struct  BFu0ll_Sf_BFu31ll  {
  __tsu64  :0;
  struct empty v1;
  __tsu64 v2:31;
};
//SIG(1 BFu0ll_Sf_BFu31ll) C1{ FL:0 FC2{} FL:31}



static void Test_BFu0ll_Sf_BFu31ll()
{
  {
    init_simple_test("BFu0ll_Sf_BFu31ll");
    static STRUCT_IF_C BFu0ll_Sf_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Sf_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu31ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "BFu0ll_Sf_BFu31ll");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "BFu0ll_Sf_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu31ll, BFu0ll_Sf_BFu31ll)
//============================================================================


struct  BFu0ll_Sf_BFu32i  {
  __tsu64  :0;
  struct empty v1;
  unsigned int v2:32;
};
//SIG(1 BFu0ll_Sf_BFu32i) C1{ FL:0 FC2{} Fi:32}



static void Test_BFu0ll_Sf_BFu32i()
{
  {
    init_simple_test("BFu0ll_Sf_BFu32i");
    static STRUCT_IF_C BFu0ll_Sf_BFu32i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Sf_BFu32i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu32i.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "BFu0ll_Sf_BFu32i");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "BFu0ll_Sf_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu32i, BFu0ll_Sf_BFu32i)
//============================================================================


struct  BFu0ll_Sf_BFu32ll  {
  __tsu64  :0;
  struct empty v1;
  __tsu64 v2:32;
};
//SIG(1 BFu0ll_Sf_BFu32ll) C1{ FL:0 FC2{} FL:32}



static void Test_BFu0ll_Sf_BFu32ll()
{
  {
    init_simple_test("BFu0ll_Sf_BFu32ll");
    static STRUCT_IF_C BFu0ll_Sf_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Sf_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu32ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "BFu0ll_Sf_BFu32ll");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "BFu0ll_Sf_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu32ll, BFu0ll_Sf_BFu32ll)
//============================================================================


struct  BFu0ll_Sf_BFu33  {
  __tsu64  :0;
  struct empty v1;
  __tsu64 v2:33;
};
//SIG(1 BFu0ll_Sf_BFu33) C1{ FL:0 FC2{} FL:33}



static void Test_BFu0ll_Sf_BFu33()
{
  {
    init_simple_test("BFu0ll_Sf_BFu33");
    static STRUCT_IF_C BFu0ll_Sf_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_Sf_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu33.v1");
    set_bf_and_test(lv, v2, 0, 0, 33, 1, "BFu0ll_Sf_BFu33");
    set_bf_and_test(lv, v2, 0, 0, 33, hide_ull(1LL<<32), "BFu0ll_Sf_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu33, BFu0ll_Sf_BFu33)
//============================================================================


struct  BFu0ll_Sf_BFu7c  {
  __tsu64  :0;
  struct empty v1;
  unsigned char v2:7;
};
//SIG(1 BFu0ll_Sf_BFu7c) C1{ FL:0 FC2{} Fc:7}



static void Test_BFu0ll_Sf_BFu7c()
{
  {
    init_simple_test("BFu0ll_Sf_BFu7c");
    static STRUCT_IF_C BFu0ll_Sf_BFu7c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_Sf_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu7c.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0ll_Sf_BFu7c");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0ll_Sf_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu7c, BFu0ll_Sf_BFu7c)
//============================================================================


struct  BFu0ll_Sf_BFu7i  {
  __tsu64  :0;
  struct empty v1;
  unsigned int v2:7;
};
//SIG(1 BFu0ll_Sf_BFu7i) C1{ FL:0 FC2{} Fi:7}



static void Test_BFu0ll_Sf_BFu7i()
{
  {
    init_simple_test("BFu0ll_Sf_BFu7i");
    static STRUCT_IF_C BFu0ll_Sf_BFu7i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Sf_BFu7i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu7i.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0ll_Sf_BFu7i");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0ll_Sf_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu7i, BFu0ll_Sf_BFu7i)
//============================================================================


struct  BFu0ll_Sf_BFu7ll  {
  __tsu64  :0;
  struct empty v1;
  __tsu64 v2:7;
};
//SIG(1 BFu0ll_Sf_BFu7ll) C1{ FL:0 FC2{} FL:7}



static void Test_BFu0ll_Sf_BFu7ll()
{
  {
    init_simple_test("BFu0ll_Sf_BFu7ll");
    static STRUCT_IF_C BFu0ll_Sf_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Sf_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu7ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0ll_Sf_BFu7ll");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0ll_Sf_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu7ll, BFu0ll_Sf_BFu7ll)
//============================================================================


struct  BFu0ll_Sf_BFu7s  {
  __tsu64  :0;
  struct empty v1;
  unsigned short v2:7;
};
//SIG(1 BFu0ll_Sf_BFu7s) C1{ FL:0 FC2{} Fs:7}



static void Test_BFu0ll_Sf_BFu7s()
{
  {
    init_simple_test("BFu0ll_Sf_BFu7s");
    static STRUCT_IF_C BFu0ll_Sf_BFu7s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_Sf_BFu7s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu7s.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0ll_Sf_BFu7s");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0ll_Sf_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu7s, BFu0ll_Sf_BFu7s)
//============================================================================


struct  BFu0ll_Sf_BFu8c  {
  __tsu64  :0;
  struct empty v1;
  unsigned char v2:8;
};
//SIG(1 BFu0ll_Sf_BFu8c) C1{ FL:0 FC2{} Fc:8}



static void Test_BFu0ll_Sf_BFu8c()
{
  {
    init_simple_test("BFu0ll_Sf_BFu8c");
    static STRUCT_IF_C BFu0ll_Sf_BFu8c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_Sf_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu8c.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0ll_Sf_BFu8c");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0ll_Sf_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu8c, BFu0ll_Sf_BFu8c)
//============================================================================


struct  BFu0ll_Sf_BFu8i  {
  __tsu64  :0;
  struct empty v1;
  unsigned int v2:8;
};
//SIG(1 BFu0ll_Sf_BFu8i) C1{ FL:0 FC2{} Fi:8}



static void Test_BFu0ll_Sf_BFu8i()
{
  {
    init_simple_test("BFu0ll_Sf_BFu8i");
    static STRUCT_IF_C BFu0ll_Sf_BFu8i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Sf_BFu8i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu8i.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0ll_Sf_BFu8i");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0ll_Sf_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu8i, BFu0ll_Sf_BFu8i)
//============================================================================


struct  BFu0ll_Sf_BFu8ll  {
  __tsu64  :0;
  struct empty v1;
  __tsu64 v2:8;
};
//SIG(1 BFu0ll_Sf_BFu8ll) C1{ FL:0 FC2{} FL:8}



static void Test_BFu0ll_Sf_BFu8ll()
{
  {
    init_simple_test("BFu0ll_Sf_BFu8ll");
    static STRUCT_IF_C BFu0ll_Sf_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Sf_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu8ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0ll_Sf_BFu8ll");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0ll_Sf_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu8ll, BFu0ll_Sf_BFu8ll)
//============================================================================


struct  BFu0ll_Sf_BFu8s  {
  __tsu64  :0;
  struct empty v1;
  unsigned short v2:8;
};
//SIG(1 BFu0ll_Sf_BFu8s) C1{ FL:0 FC2{} Fs:8}



static void Test_BFu0ll_Sf_BFu8s()
{
  {
    init_simple_test("BFu0ll_Sf_BFu8s");
    static STRUCT_IF_C BFu0ll_Sf_BFu8s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_Sf_BFu8s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu8s.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0ll_Sf_BFu8s");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0ll_Sf_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu8s, BFu0ll_Sf_BFu8s)
//============================================================================


struct  BFu0ll_Sf_BFu9i  {
  __tsu64  :0;
  struct empty v1;
  unsigned int v2:9;
};
//SIG(1 BFu0ll_Sf_BFu9i) C1{ FL:0 FC2{} Fi:9}



static void Test_BFu0ll_Sf_BFu9i()
{
  {
    init_simple_test("BFu0ll_Sf_BFu9i");
    static STRUCT_IF_C BFu0ll_Sf_BFu9i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Sf_BFu9i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu9i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "BFu0ll_Sf_BFu9i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "BFu0ll_Sf_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu9i, BFu0ll_Sf_BFu9i)
//============================================================================


struct  BFu0ll_Sf_BFu9ll  {
  __tsu64  :0;
  struct empty v1;
  __tsu64 v2:9;
};
//SIG(1 BFu0ll_Sf_BFu9ll) C1{ FL:0 FC2{} FL:9}



static void Test_BFu0ll_Sf_BFu9ll()
{
  {
    init_simple_test("BFu0ll_Sf_BFu9ll");
    static STRUCT_IF_C BFu0ll_Sf_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Sf_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu9ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "BFu0ll_Sf_BFu9ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "BFu0ll_Sf_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu9ll, BFu0ll_Sf_BFu9ll)
//============================================================================


struct  BFu0ll_Sf_BFu9s  {
  __tsu64  :0;
  struct empty v1;
  unsigned short v2:9;
};
//SIG(1 BFu0ll_Sf_BFu9s) C1{ FL:0 FC2{} Fs:9}



static void Test_BFu0ll_Sf_BFu9s()
{
  {
    init_simple_test("BFu0ll_Sf_BFu9s");
    static STRUCT_IF_C BFu0ll_Sf_BFu9s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_Sf_BFu9s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_BFu9s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "BFu0ll_Sf_BFu9s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "BFu0ll_Sf_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_BFu9s, BFu0ll_Sf_BFu9s)
//============================================================================


struct  BFu0ll_Sf_C  {
  __tsu64  :0;
  struct empty v1;
  char v2;
};
//SIG(1 BFu0ll_Sf_C) C1{ FL:0 FC2{} Fc}



static void Test_BFu0ll_Sf_C()
{
  {
    init_simple_test("BFu0ll_Sf_C");
    static STRUCT_IF_C BFu0ll_Sf_C lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_Sf_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Sf_C)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_C.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_C, BFu0ll_Sf_C)
//============================================================================


struct  BFu0ll_Sf_D  {
  __tsu64  :0;
  struct empty v1;
  double v2;
};
//SIG(1 BFu0ll_Sf_D) C1{ FL:0 FC2{} FL}



static void Test_BFu0ll_Sf_D()
{
  {
    init_simple_test("BFu0ll_Sf_D");
    static STRUCT_IF_C BFu0ll_Sf_D lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_Sf_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_D)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_D.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_D, BFu0ll_Sf_D)
//============================================================================


struct  BFu0ll_Sf_F  {
  __tsu64  :0;
  struct empty v1;
  float v2;
};
//SIG(1 BFu0ll_Sf_F) C1{ FL:0 FC2{} Fi}



static void Test_BFu0ll_Sf_F()
{
  {
    init_simple_test("BFu0ll_Sf_F");
    static STRUCT_IF_C BFu0ll_Sf_F lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Sf_F)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Sf_F)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_F.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_F, BFu0ll_Sf_F)
//============================================================================


struct  BFu0ll_Sf_I  {
  __tsu64  :0;
  struct empty v1;
  int v2;
};
//SIG(1 BFu0ll_Sf_I) C1{ FL:0 FC2{} Fi}



static void Test_BFu0ll_Sf_I()
{
  {
    init_simple_test("BFu0ll_Sf_I");
    static STRUCT_IF_C BFu0ll_Sf_I lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Sf_I)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Sf_I)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_I.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_I, BFu0ll_Sf_I)
//============================================================================


struct  BFu0ll_Sf_Ip  {
  __tsu64  :0;
  struct empty v1;
  int *v2;
};
//SIG(1 BFu0ll_Sf_Ip) C1{ FL:0 FC2{} Fp}



static void Test_BFu0ll_Sf_Ip()
{
  {
    init_simple_test("BFu0ll_Sf_Ip");
    static STRUCT_IF_C BFu0ll_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Sf_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_Ip)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_Ip.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_Ip, BFu0ll_Sf_Ip)
//============================================================================


struct  BFu0ll_Sf_L  {
  __tsu64  :0;
  struct empty v1;
  __tsi64 v2;
};
//SIG(1 BFu0ll_Sf_L) C1{ FL:0 FC2{} FL}



static void Test_BFu0ll_Sf_L()
{
  {
    init_simple_test("BFu0ll_Sf_L");
    static STRUCT_IF_C BFu0ll_Sf_L lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_Sf_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_L)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_L.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_L, BFu0ll_Sf_L)
//============================================================================


struct  BFu0ll_Sf_S  {
  __tsu64  :0;
  struct empty v1;
  short v2;
};
//SIG(1 BFu0ll_Sf_S) C1{ FL:0 FC2{} Fs}



static void Test_BFu0ll_Sf_S()
{
  {
    init_simple_test("BFu0ll_Sf_S");
    static STRUCT_IF_C BFu0ll_Sf_S lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_Sf_S)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_Sf_S)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_S.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_S, BFu0ll_Sf_S)
//============================================================================


struct  BFu0ll_Sf_Sf  {
  __tsu64  :0;
  struct empty v1;
  struct empty v2;
};
//SIG(1 BFu0ll_Sf_Sf) C1{ FL:0 FC2{} FC2}



static void Test_BFu0ll_Sf_Sf()
{
  {
    init_simple_test("BFu0ll_Sf_Sf");
    static STRUCT_IF_C BFu0ll_Sf_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0ll_Sf_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Sf_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_Sf.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_Sf, BFu0ll_Sf_Sf)
//============================================================================


struct  BFu0ll_Sf_Uc  {
  __tsu64  :0;
  struct empty v1;
  unsigned char v2;
};
//SIG(1 BFu0ll_Sf_Uc) C1{ FL:0 FC2{} Fc}



static void Test_BFu0ll_Sf_Uc()
{
  {
    init_simple_test("BFu0ll_Sf_Uc");
    static STRUCT_IF_C BFu0ll_Sf_Uc lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_Sf_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Sf_Uc)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_Uc.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_Uc, BFu0ll_Sf_Uc)
//============================================================================


struct  BFu0ll_Sf_Ui  {
  __tsu64  :0;
  struct empty v1;
  unsigned int v2;
};
//SIG(1 BFu0ll_Sf_Ui) C1{ FL:0 FC2{} Fi}



static void Test_BFu0ll_Sf_Ui()
{
  {
    init_simple_test("BFu0ll_Sf_Ui");
    static STRUCT_IF_C BFu0ll_Sf_Ui lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Sf_Ui)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Sf_Ui)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_Ui.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_Ui, BFu0ll_Sf_Ui)
//============================================================================


struct  BFu0ll_Sf_Ul  {
  __tsu64  :0;
  struct empty v1;
  __tsu64 v2;
};
//SIG(1 BFu0ll_Sf_Ul) C1{ FL:0 FC2{} FL}



static void Test_BFu0ll_Sf_Ul()
{
  {
    init_simple_test("BFu0ll_Sf_Ul");
    static STRUCT_IF_C BFu0ll_Sf_Ul lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_Sf_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_Ul)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_Ul.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_Ul, BFu0ll_Sf_Ul)
//============================================================================


struct  BFu0ll_Sf_Us  {
  __tsu64  :0;
  struct empty v1;
  unsigned short v2;
};
//SIG(1 BFu0ll_Sf_Us) C1{ FL:0 FC2{} Fs}



static void Test_BFu0ll_Sf_Us()
{
  {
    init_simple_test("BFu0ll_Sf_Us");
    static STRUCT_IF_C BFu0ll_Sf_Us lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_Sf_Us)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_Sf_Us)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_Us.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_Us, BFu0ll_Sf_Us)
//============================================================================


struct  BFu0ll_Sf_Vp  {
  __tsu64  :0;
  struct empty v1;
  void *v2;
};
//SIG(1 BFu0ll_Sf_Vp) C1{ FL:0 FC2{} Fp}



static void Test_BFu0ll_Sf_Vp()
{
  {
    init_simple_test("BFu0ll_Sf_Vp");
    static STRUCT_IF_C BFu0ll_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Sf_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Sf_Vp)");
    check_field_offset(lv, v1, 0, "BFu0ll_Sf_Vp.v1");
    check_field_offset(lv, v2, 0, "BFu0ll_Sf_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Sf_Vp, BFu0ll_Sf_Vp)
//============================================================================


struct  BFu0ll_Uc_Sf  {
  __tsu64  :0;
  unsigned char v1;
  struct empty v2;
};
//SIG(1 BFu0ll_Uc_Sf) C1{ FL:0 Fc FC2{}}



static void Test_BFu0ll_Uc_Sf()
{
  {
    init_simple_test("BFu0ll_Uc_Sf");
    static STRUCT_IF_C BFu0ll_Uc_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0ll_Uc_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0ll_Uc_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_Uc_Sf.v1");
    check_field_offset(lv, v2, 1, "BFu0ll_Uc_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Uc_Sf, BFu0ll_Uc_Sf)
//============================================================================


struct  BFu0ll_Ui_Sf  {
  __tsu64  :0;
  unsigned int v1;
  struct empty v2;
};
//SIG(1 BFu0ll_Ui_Sf) C1{ FL:0 Fi FC2{}}



static void Test_BFu0ll_Ui_Sf()
{
  {
    init_simple_test("BFu0ll_Ui_Sf");
    static STRUCT_IF_C BFu0ll_Ui_Sf lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(BFu0ll_Ui_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu0ll_Ui_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_Ui_Sf.v1");
    check_field_offset(lv, v2, 4, "BFu0ll_Ui_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Ui_Sf, BFu0ll_Ui_Sf)
//============================================================================


struct  BFu0ll_Ul_Sf  {
  __tsu64  :0;
  __tsu64 v1;
  struct empty v2;
};
//SIG(1 BFu0ll_Ul_Sf) C1{ FL:0 FL FC2{}}



static void Test_BFu0ll_Ul_Sf()
{
  {
    init_simple_test("BFu0ll_Ul_Sf");
    static STRUCT_IF_C BFu0ll_Ul_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0ll_Ul_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Ul_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_Ul_Sf.v1");
    check_field_offset(lv, v2, 8, "BFu0ll_Ul_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Ul_Sf, BFu0ll_Ul_Sf)
//============================================================================


struct  BFu0ll_Us_Sf  {
  __tsu64  :0;
  unsigned short v1;
  struct empty v2;
};
//SIG(1 BFu0ll_Us_Sf) C1{ FL:0 Fs FC2{}}



static void Test_BFu0ll_Us_Sf()
{
  {
    init_simple_test("BFu0ll_Us_Sf");
    static STRUCT_IF_C BFu0ll_Us_Sf lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(BFu0ll_Us_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu0ll_Us_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_Us_Sf.v1");
    check_field_offset(lv, v2, 2, "BFu0ll_Us_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Us_Sf, BFu0ll_Us_Sf)
//============================================================================


struct  BFu0ll_Vp_Sf  {
  __tsu64  :0;
  void *v1;
  struct empty v2;
};
//SIG(1 BFu0ll_Vp_Sf) C1{ FL:0 Fp FC2{}}



static void Test_BFu0ll_Vp_Sf()
{
  {
    init_simple_test("BFu0ll_Vp_Sf");
    static STRUCT_IF_C BFu0ll_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0ll_Vp_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0ll_Vp_Sf)");
    check_field_offset(lv, v1, 0, "BFu0ll_Vp_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0ll_Vp_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0ll_Vp_Sf, BFu0ll_Vp_Sf)
//============================================================================


struct  BFu0s_BFu0c_Sf  {
  unsigned short  :0;
  unsigned char  :0;
  struct empty v1;
};
//SIG(1 BFu0s_BFu0c_Sf) C1{ Fs:0 Fc:0 FC2{}}



static void Test_BFu0s_BFu0c_Sf()
{
  {
    init_simple_test("BFu0s_BFu0c_Sf");
    static STRUCT_IF_C BFu0s_BFu0c_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0s_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_BFu0c_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu0c_Sf, BFu0s_BFu0c_Sf)
//============================================================================


struct  BFu0s_BFu0i_Sf  {
  unsigned short  :0;
  unsigned int  :0;
  struct empty v1;
};
//SIG(1 BFu0s_BFu0i_Sf) C1{ Fs:0 Fi:0 FC2{}}



static void Test_BFu0s_BFu0i_Sf()
{
  {
    init_simple_test("BFu0s_BFu0i_Sf");
    static STRUCT_IF_C BFu0s_BFu0i_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0s_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_BFu0i_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu0i_Sf, BFu0s_BFu0i_Sf)
//============================================================================


struct  BFu0s_BFu0ll_Sf  {
  unsigned short  :0;
  __tsu64  :0;
  struct empty v1;
};
//SIG(1 BFu0s_BFu0ll_Sf) C1{ Fs:0 FL:0 FC2{}}



static void Test_BFu0s_BFu0ll_Sf()
{
  {
    init_simple_test("BFu0s_BFu0ll_Sf");
    static STRUCT_IF_C BFu0s_BFu0ll_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0s_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_BFu0ll_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu0ll_Sf, BFu0s_BFu0ll_Sf)
//============================================================================


struct  BFu0s_BFu0s_Sf  {
  unsigned short  :0;
  unsigned short  :0;
  struct empty v1;
};
//SIG(1 BFu0s_BFu0s_Sf) C1{ Fs:0 Fs:0 FC2{}}



static void Test_BFu0s_BFu0s_Sf()
{
  {
    init_simple_test("BFu0s_BFu0s_Sf");
    static STRUCT_IF_C BFu0s_BFu0s_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0s_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_BFu0s_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu0s_Sf, BFu0s_BFu0s_Sf)
//============================================================================


struct  BFu0s_BFu15i_Sf  {
  unsigned short  :0;
  unsigned int v1:15;
  struct empty v2;
};
//SIG(1 BFu0s_BFu15i_Sf) C1{ Fs:0 Fi:15 FC2{}}



static void Test_BFu0s_BFu15i_Sf()
{
  {
    init_simple_test("BFu0s_BFu15i_Sf");
    static STRUCT_IF_C BFu0s_BFu15i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu15i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu15i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0s_BFu15i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0s_BFu15i_Sf");
    check_field_offset(lv, v2, 2, "BFu0s_BFu15i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu15i_Sf, BFu0s_BFu15i_Sf)
//============================================================================


struct  BFu0s_BFu15ll_Sf  {
  unsigned short  :0;
  __tsu64 v1:15;
  struct empty v2;
};
//SIG(1 BFu0s_BFu15ll_Sf) C1{ Fs:0 FL:15 FC2{}}



static void Test_BFu0s_BFu15ll_Sf()
{
  {
    init_simple_test("BFu0s_BFu15ll_Sf");
    static STRUCT_IF_C BFu0s_BFu15ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu15ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu15ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0s_BFu15ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0s_BFu15ll_Sf");
    check_field_offset(lv, v2, 2, "BFu0s_BFu15ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu15ll_Sf, BFu0s_BFu15ll_Sf)
//============================================================================


struct  BFu0s_BFu15s_Sf  {
  unsigned short  :0;
  unsigned short v1:15;
  struct empty v2;
};
//SIG(1 BFu0s_BFu15s_Sf) C1{ Fs:0 Fs:15 FC2{}}



static void Test_BFu0s_BFu15s_Sf()
{
  {
    init_simple_test("BFu0s_BFu15s_Sf");
    static STRUCT_IF_C BFu0s_BFu15s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_BFu15s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_BFu15s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu0s_BFu15s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu0s_BFu15s_Sf");
    check_field_offset(lv, v2, 2, "BFu0s_BFu15s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu15s_Sf, BFu0s_BFu15s_Sf)
//============================================================================


struct  BFu0s_BFu16i_Sf  {
  unsigned short  :0;
  unsigned int v1:16;
  struct empty v2;
};
//SIG(1 BFu0s_BFu16i_Sf) C1{ Fs:0 Fi:16 FC2{}}



static void Test_BFu0s_BFu16i_Sf()
{
  {
    init_simple_test("BFu0s_BFu16i_Sf");
    static STRUCT_IF_C BFu0s_BFu16i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu16i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu16i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0s_BFu16i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0s_BFu16i_Sf");
    check_field_offset(lv, v2, 2, "BFu0s_BFu16i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu16i_Sf, BFu0s_BFu16i_Sf)
//============================================================================


struct  BFu0s_BFu16ll_Sf  {
  unsigned short  :0;
  __tsu64 v1:16;
  struct empty v2;
};
//SIG(1 BFu0s_BFu16ll_Sf) C1{ Fs:0 FL:16 FC2{}}



static void Test_BFu0s_BFu16ll_Sf()
{
  {
    init_simple_test("BFu0s_BFu16ll_Sf");
    static STRUCT_IF_C BFu0s_BFu16ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu16ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu16ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0s_BFu16ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0s_BFu16ll_Sf");
    check_field_offset(lv, v2, 2, "BFu0s_BFu16ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu16ll_Sf, BFu0s_BFu16ll_Sf)
//============================================================================


struct  BFu0s_BFu16s_Sf  {
  unsigned short  :0;
  unsigned short v1:16;
  struct empty v2;
};
//SIG(1 BFu0s_BFu16s_Sf) C1{ Fs:0 Fs:16 FC2{}}



static void Test_BFu0s_BFu16s_Sf()
{
  {
    init_simple_test("BFu0s_BFu16s_Sf");
    static STRUCT_IF_C BFu0s_BFu16s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_BFu16s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_BFu16s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu0s_BFu16s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu0s_BFu16s_Sf");
    check_field_offset(lv, v2, 2, "BFu0s_BFu16s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu16s_Sf, BFu0s_BFu16s_Sf)
//============================================================================


struct  BFu0s_BFu17i_Sf  {
  unsigned short  :0;
  unsigned int v1:17;
  struct empty v2;
};
//SIG(1 BFu0s_BFu17i_Sf) C1{ Fs:0 Fi:17 FC2{}}



static void Test_BFu0s_BFu17i_Sf()
{
  {
    init_simple_test("BFu0s_BFu17i_Sf");
    static STRUCT_IF_C BFu0s_BFu17i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu17i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu17i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0s_BFu17i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0s_BFu17i_Sf");
    check_field_offset(lv, v2, 3, "BFu0s_BFu17i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu17i_Sf, BFu0s_BFu17i_Sf)
//============================================================================


struct  BFu0s_BFu17ll_Sf  {
  unsigned short  :0;
  __tsu64 v1:17;
  struct empty v2;
};
//SIG(1 BFu0s_BFu17ll_Sf) C1{ Fs:0 FL:17 FC2{}}



static void Test_BFu0s_BFu17ll_Sf()
{
  {
    init_simple_test("BFu0s_BFu17ll_Sf");
    static STRUCT_IF_C BFu0s_BFu17ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu17ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu17ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu0s_BFu17ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu0s_BFu17ll_Sf");
    check_field_offset(lv, v2, 3, "BFu0s_BFu17ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu17ll_Sf, BFu0s_BFu17ll_Sf)
//============================================================================


struct  BFu0s_BFu1c_Sf  {
  unsigned short  :0;
  unsigned char v1:1;
  struct empty v2;
};
//SIG(1 BFu0s_BFu1c_Sf) C1{ Fs:0 Fc:1 FC2{}}



static void Test_BFu0s_BFu1c_Sf()
{
  {
    init_simple_test("BFu0s_BFu1c_Sf");
    static STRUCT_IF_C BFu0s_BFu1c_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_BFu1c_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu1c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0s_BFu1c_Sf");
    check_field_offset(lv, v2, 1, "BFu0s_BFu1c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu1c_Sf, BFu0s_BFu1c_Sf)
//============================================================================


struct  BFu0s_BFu1i_Sf  {
  unsigned short  :0;
  unsigned int v1:1;
  struct empty v2;
};
//SIG(1 BFu0s_BFu1i_Sf) C1{ Fs:0 Fi:1 FC2{}}



static void Test_BFu0s_BFu1i_Sf()
{
  {
    init_simple_test("BFu0s_BFu1i_Sf");
    static STRUCT_IF_C BFu0s_BFu1i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu1i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu1i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0s_BFu1i_Sf");
    check_field_offset(lv, v2, 1, "BFu0s_BFu1i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu1i_Sf, BFu0s_BFu1i_Sf)
//============================================================================


struct  BFu0s_BFu1ll_Sf  {
  unsigned short  :0;
  __tsu64 v1:1;
  struct empty v2;
};
//SIG(1 BFu0s_BFu1ll_Sf) C1{ Fs:0 FL:1 FC2{}}



static void Test_BFu0s_BFu1ll_Sf()
{
  {
    init_simple_test("BFu0s_BFu1ll_Sf");
    static STRUCT_IF_C BFu0s_BFu1ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu1ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu1ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0s_BFu1ll_Sf");
    check_field_offset(lv, v2, 1, "BFu0s_BFu1ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu1ll_Sf, BFu0s_BFu1ll_Sf)
//============================================================================


struct  BFu0s_BFu1s_Sf  {
  unsigned short  :0;
  unsigned short v1:1;
  struct empty v2;
};
//SIG(1 BFu0s_BFu1s_Sf) C1{ Fs:0 Fs:1 FC2{}}



static void Test_BFu0s_BFu1s_Sf()
{
  {
    init_simple_test("BFu0s_BFu1s_Sf");
    static STRUCT_IF_C BFu0s_BFu1s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_BFu1s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_BFu1s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu0s_BFu1s_Sf");
    check_field_offset(lv, v2, 1, "BFu0s_BFu1s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu1s_Sf, BFu0s_BFu1s_Sf)
//============================================================================


struct  BFu0s_BFu31i_Sf  {
  unsigned short  :0;
  unsigned int v1:31;
  struct empty v2;
};
//SIG(1 BFu0s_BFu31i_Sf) C1{ Fs:0 Fi:31 FC2{}}



static void Test_BFu0s_BFu31i_Sf()
{
  {
    init_simple_test("BFu0s_BFu31i_Sf");
    static STRUCT_IF_C BFu0s_BFu31i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu31i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu31i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0s_BFu31i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0s_BFu31i_Sf");
    check_field_offset(lv, v2, 4, "BFu0s_BFu31i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu31i_Sf, BFu0s_BFu31i_Sf)
//============================================================================


struct  BFu0s_BFu31ll_Sf  {
  unsigned short  :0;
  __tsu64 v1:31;
  struct empty v2;
};
//SIG(1 BFu0s_BFu31ll_Sf) C1{ Fs:0 FL:31 FC2{}}



static void Test_BFu0s_BFu31ll_Sf()
{
  {
    init_simple_test("BFu0s_BFu31ll_Sf");
    static STRUCT_IF_C BFu0s_BFu31ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu31ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu31ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu0s_BFu31ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu0s_BFu31ll_Sf");
    check_field_offset(lv, v2, 4, "BFu0s_BFu31ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu31ll_Sf, BFu0s_BFu31ll_Sf)
//============================================================================


struct  BFu0s_BFu32i_Sf  {
  unsigned short  :0;
  unsigned int v1:32;
  struct empty v2;
};
//SIG(1 BFu0s_BFu32i_Sf) C1{ Fs:0 Fi:32 FC2{}}



static void Test_BFu0s_BFu32i_Sf()
{
  {
    init_simple_test("BFu0s_BFu32i_Sf");
    static STRUCT_IF_C BFu0s_BFu32i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu32i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu32i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0s_BFu32i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0s_BFu32i_Sf");
    check_field_offset(lv, v2, 4, "BFu0s_BFu32i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu32i_Sf, BFu0s_BFu32i_Sf)
//============================================================================


struct  BFu0s_BFu32ll_Sf  {
  unsigned short  :0;
  __tsu64 v1:32;
  struct empty v2;
};
//SIG(1 BFu0s_BFu32ll_Sf) C1{ Fs:0 FL:32 FC2{}}



static void Test_BFu0s_BFu32ll_Sf()
{
  {
    init_simple_test("BFu0s_BFu32ll_Sf");
    static STRUCT_IF_C BFu0s_BFu32ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu32ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu32ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu0s_BFu32ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu0s_BFu32ll_Sf");
    check_field_offset(lv, v2, 4, "BFu0s_BFu32ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu32ll_Sf, BFu0s_BFu32ll_Sf)
//============================================================================


struct  BFu0s_BFu33_Sf  {
  unsigned short  :0;
  __tsu64 v1:33;
  struct empty v2;
};
//SIG(1 BFu0s_BFu33_Sf) C1{ Fs:0 FL:33 FC2{}}



static void Test_BFu0s_BFu33_Sf()
{
  {
    init_simple_test("BFu0s_BFu33_Sf");
    static STRUCT_IF_C BFu0s_BFu33_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_BFu33_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu33_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu0s_BFu33_Sf");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu0s_BFu33_Sf");
    check_field_offset(lv, v2, 5, "BFu0s_BFu33_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu33_Sf, BFu0s_BFu33_Sf)
//============================================================================


struct  BFu0s_BFu7c_Sf  {
  unsigned short  :0;
  unsigned char v1:7;
  struct empty v2;
};
//SIG(1 BFu0s_BFu7c_Sf) C1{ Fs:0 Fc:7 FC2{}}



static void Test_BFu0s_BFu7c_Sf()
{
  {
    init_simple_test("BFu0s_BFu7c_Sf");
    static STRUCT_IF_C BFu0s_BFu7c_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_BFu7c_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu7c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0s_BFu7c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0s_BFu7c_Sf");
    check_field_offset(lv, v2, 1, "BFu0s_BFu7c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu7c_Sf, BFu0s_BFu7c_Sf)
//============================================================================


struct  BFu0s_BFu7i_Sf  {
  unsigned short  :0;
  unsigned int v1:7;
  struct empty v2;
};
//SIG(1 BFu0s_BFu7i_Sf) C1{ Fs:0 Fi:7 FC2{}}



static void Test_BFu0s_BFu7i_Sf()
{
  {
    init_simple_test("BFu0s_BFu7i_Sf");
    static STRUCT_IF_C BFu0s_BFu7i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu7i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu7i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0s_BFu7i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0s_BFu7i_Sf");
    check_field_offset(lv, v2, 1, "BFu0s_BFu7i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu7i_Sf, BFu0s_BFu7i_Sf)
//============================================================================


struct  BFu0s_BFu7ll_Sf  {
  unsigned short  :0;
  __tsu64 v1:7;
  struct empty v2;
};
//SIG(1 BFu0s_BFu7ll_Sf) C1{ Fs:0 FL:7 FC2{}}



static void Test_BFu0s_BFu7ll_Sf()
{
  {
    init_simple_test("BFu0s_BFu7ll_Sf");
    static STRUCT_IF_C BFu0s_BFu7ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu7ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu7ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0s_BFu7ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0s_BFu7ll_Sf");
    check_field_offset(lv, v2, 1, "BFu0s_BFu7ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu7ll_Sf, BFu0s_BFu7ll_Sf)
//============================================================================


struct  BFu0s_BFu7s_Sf  {
  unsigned short  :0;
  unsigned short v1:7;
  struct empty v2;
};
//SIG(1 BFu0s_BFu7s_Sf) C1{ Fs:0 Fs:7 FC2{}}



static void Test_BFu0s_BFu7s_Sf()
{
  {
    init_simple_test("BFu0s_BFu7s_Sf");
    static STRUCT_IF_C BFu0s_BFu7s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_BFu7s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_BFu7s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu0s_BFu7s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu0s_BFu7s_Sf");
    check_field_offset(lv, v2, 1, "BFu0s_BFu7s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu7s_Sf, BFu0s_BFu7s_Sf)
//============================================================================


struct  BFu0s_BFu8c_Sf  {
  unsigned short  :0;
  unsigned char v1:8;
  struct empty v2;
};
//SIG(1 BFu0s_BFu8c_Sf) C1{ Fs:0 Fc:8 FC2{}}



static void Test_BFu0s_BFu8c_Sf()
{
  {
    init_simple_test("BFu0s_BFu8c_Sf");
    static STRUCT_IF_C BFu0s_BFu8c_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_BFu8c_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_BFu8c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0s_BFu8c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0s_BFu8c_Sf");
    check_field_offset(lv, v2, 1, "BFu0s_BFu8c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu8c_Sf, BFu0s_BFu8c_Sf)
//============================================================================


struct  BFu0s_BFu8i_Sf  {
  unsigned short  :0;
  unsigned int v1:8;
  struct empty v2;
};
//SIG(1 BFu0s_BFu8i_Sf) C1{ Fs:0 Fi:8 FC2{}}



static void Test_BFu0s_BFu8i_Sf()
{
  {
    init_simple_test("BFu0s_BFu8i_Sf");
    static STRUCT_IF_C BFu0s_BFu8i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu8i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu8i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0s_BFu8i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0s_BFu8i_Sf");
    check_field_offset(lv, v2, 1, "BFu0s_BFu8i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu8i_Sf, BFu0s_BFu8i_Sf)
//============================================================================


struct  BFu0s_BFu8ll_Sf  {
  unsigned short  :0;
  __tsu64 v1:8;
  struct empty v2;
};
//SIG(1 BFu0s_BFu8ll_Sf) C1{ Fs:0 FL:8 FC2{}}



static void Test_BFu0s_BFu8ll_Sf()
{
  {
    init_simple_test("BFu0s_BFu8ll_Sf");
    static STRUCT_IF_C BFu0s_BFu8ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu8ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu8ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0s_BFu8ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0s_BFu8ll_Sf");
    check_field_offset(lv, v2, 1, "BFu0s_BFu8ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu8ll_Sf, BFu0s_BFu8ll_Sf)
//============================================================================


struct  BFu0s_BFu8s_Sf  {
  unsigned short  :0;
  unsigned short v1:8;
  struct empty v2;
};
//SIG(1 BFu0s_BFu8s_Sf) C1{ Fs:0 Fs:8 FC2{}}



static void Test_BFu0s_BFu8s_Sf()
{
  {
    init_simple_test("BFu0s_BFu8s_Sf");
    static STRUCT_IF_C BFu0s_BFu8s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_BFu8s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_BFu8s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu0s_BFu8s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu0s_BFu8s_Sf");
    check_field_offset(lv, v2, 1, "BFu0s_BFu8s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu8s_Sf, BFu0s_BFu8s_Sf)
//============================================================================


struct  BFu0s_BFu9i_Sf  {
  unsigned short  :0;
  unsigned int v1:9;
  struct empty v2;
};
//SIG(1 BFu0s_BFu9i_Sf) C1{ Fs:0 Fi:9 FC2{}}



static void Test_BFu0s_BFu9i_Sf()
{
  {
    init_simple_test("BFu0s_BFu9i_Sf");
    static STRUCT_IF_C BFu0s_BFu9i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_BFu9i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_BFu9i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0s_BFu9i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0s_BFu9i_Sf");
    check_field_offset(lv, v2, 2, "BFu0s_BFu9i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu9i_Sf, BFu0s_BFu9i_Sf)
//============================================================================


struct  BFu0s_BFu9ll_Sf  {
  unsigned short  :0;
  __tsu64 v1:9;
  struct empty v2;
};
//SIG(1 BFu0s_BFu9ll_Sf) C1{ Fs:0 FL:9 FC2{}}



static void Test_BFu0s_BFu9ll_Sf()
{
  {
    init_simple_test("BFu0s_BFu9ll_Sf");
    static STRUCT_IF_C BFu0s_BFu9ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_BFu9ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_BFu9ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0s_BFu9ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0s_BFu9ll_Sf");
    check_field_offset(lv, v2, 2, "BFu0s_BFu9ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu9ll_Sf, BFu0s_BFu9ll_Sf)
//============================================================================


struct  BFu0s_BFu9s_Sf  {
  unsigned short  :0;
  unsigned short v1:9;
  struct empty v2;
};
//SIG(1 BFu0s_BFu9s_Sf) C1{ Fs:0 Fs:9 FC2{}}



static void Test_BFu0s_BFu9s_Sf()
{
  {
    init_simple_test("BFu0s_BFu9s_Sf");
    static STRUCT_IF_C BFu0s_BFu9s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_BFu9s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_BFu9s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu0s_BFu9s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu0s_BFu9s_Sf");
    check_field_offset(lv, v2, 2, "BFu0s_BFu9s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_BFu9s_Sf, BFu0s_BFu9s_Sf)
//============================================================================


struct  BFu0s_C_Sf  {
  unsigned short  :0;
  char v1;
  struct empty v2;
};
//SIG(1 BFu0s_C_Sf) C1{ Fs:0 Fc FC2{}}



static void Test_BFu0s_C_Sf()
{
  {
    init_simple_test("BFu0s_C_Sf");
    static STRUCT_IF_C BFu0s_C_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_C_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_C_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_C_Sf.v1");
    check_field_offset(lv, v2, 1, "BFu0s_C_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_C_Sf, BFu0s_C_Sf)
//============================================================================


struct  BFu0s_D_Sf  {
  unsigned short  :0;
  double v1;
  struct empty v2;
};
//SIG(1 BFu0s_D_Sf) C1{ Fs:0 FL FC2{}}



static void Test_BFu0s_D_Sf()
{
  {
    init_simple_test("BFu0s_D_Sf");
    static STRUCT_IF_C BFu0s_D_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_D_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_D_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_D_Sf.v1");
    check_field_offset(lv, v2, 8, "BFu0s_D_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_D_Sf, BFu0s_D_Sf)
//============================================================================


struct  BFu0s_F_Sf  {
  unsigned short  :0;
  float v1;
  struct empty v2;
};
//SIG(1 BFu0s_F_Sf) C1{ Fs:0 Fi FC2{}}



static void Test_BFu0s_F_Sf()
{
  {
    init_simple_test("BFu0s_F_Sf");
    static STRUCT_IF_C BFu0s_F_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_F_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_F_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_F_Sf.v1");
    check_field_offset(lv, v2, 4, "BFu0s_F_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_F_Sf, BFu0s_F_Sf)
//============================================================================


struct  BFu0s_I_Sf  {
  unsigned short  :0;
  int v1;
  struct empty v2;
};
//SIG(1 BFu0s_I_Sf) C1{ Fs:0 Fi FC2{}}



static void Test_BFu0s_I_Sf()
{
  {
    init_simple_test("BFu0s_I_Sf");
    static STRUCT_IF_C BFu0s_I_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_I_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_I_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_I_Sf.v1");
    check_field_offset(lv, v2, 4, "BFu0s_I_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_I_Sf, BFu0s_I_Sf)
//============================================================================


struct  BFu0s_Ip_Sf  {
  unsigned short  :0;
  int *v1;
  struct empty v2;
};
//SIG(1 BFu0s_Ip_Sf) C1{ Fs:0 Fp FC2{}}



static void Test_BFu0s_Ip_Sf()
{
  {
    init_simple_test("BFu0s_Ip_Sf");
    static STRUCT_IF_C BFu0s_Ip_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Ip_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Ip_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_Ip_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0s_Ip_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Ip_Sf, BFu0s_Ip_Sf)
//============================================================================


struct  BFu0s_L_Sf  {
  unsigned short  :0;
  __tsi64 v1;
  struct empty v2;
};
//SIG(1 BFu0s_L_Sf) C1{ Fs:0 FL FC2{}}



static void Test_BFu0s_L_Sf()
{
  {
    init_simple_test("BFu0s_L_Sf");
    static STRUCT_IF_C BFu0s_L_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_L_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_L_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_L_Sf.v1");
    check_field_offset(lv, v2, 8, "BFu0s_L_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_L_Sf, BFu0s_L_Sf)
//============================================================================


struct  BFu0s_S_Sf  {
  unsigned short  :0;
  short v1;
  struct empty v2;
};
//SIG(1 BFu0s_S_Sf) C1{ Fs:0 Fs FC2{}}



static void Test_BFu0s_S_Sf()
{
  {
    init_simple_test("BFu0s_S_Sf");
    static STRUCT_IF_C BFu0s_S_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_S_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_S_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_S_Sf.v1");
    check_field_offset(lv, v2, 2, "BFu0s_S_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_S_Sf, BFu0s_S_Sf)
//============================================================================


struct  BFu0s_Sf  {
  unsigned short  :0;
  struct empty v1;
};
//SIG(1 BFu0s_Sf) C1{ Fs:0 FC2{}}



static void Test_BFu0s_Sf()
{
  {
    init_simple_test("BFu0s_Sf");
    static STRUCT_IF_C BFu0s_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf, BFu0s_Sf)
//============================================================================


struct  BFu0s_Sf_BFu0c  {
  unsigned short  :0;
  struct empty v1;
  unsigned char  :0;
};
//SIG(1 BFu0s_Sf_BFu0c) C1{ Fs:0 FC2{} Fc:0}



static void Test_BFu0s_Sf_BFu0c()
{
  {
    init_simple_test("BFu0s_Sf_BFu0c");
    static STRUCT_IF_C BFu0s_Sf_BFu0c lv;
    check2(sizeof(lv), 0, "sizeof(BFu0s_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu0c, BFu0s_Sf_BFu0c)
//============================================================================


struct  BFu0s_Sf_BFu0i  {
  unsigned short  :0;
  struct empty v1;
  unsigned int  :0;
};
//SIG(1 BFu0s_Sf_BFu0i) C1{ Fs:0 FC2{} Fi:0}



static void Test_BFu0s_Sf_BFu0i()
{
  {
    init_simple_test("BFu0s_Sf_BFu0i");
    static STRUCT_IF_C BFu0s_Sf_BFu0i lv;
    check2(sizeof(lv), 0, "sizeof(BFu0s_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu0i, BFu0s_Sf_BFu0i)
//============================================================================


struct  BFu0s_Sf_BFu0ll  {
  unsigned short  :0;
  struct empty v1;
  __tsu64  :0;
};
//SIG(1 BFu0s_Sf_BFu0ll) C1{ Fs:0 FC2{} FL:0}



static void Test_BFu0s_Sf_BFu0ll()
{
  {
    init_simple_test("BFu0s_Sf_BFu0ll");
    static STRUCT_IF_C BFu0s_Sf_BFu0ll lv;
    check2(sizeof(lv), 0, "sizeof(BFu0s_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu0ll, BFu0s_Sf_BFu0ll)
//============================================================================


struct  BFu0s_Sf_BFu0s  {
  unsigned short  :0;
  struct empty v1;
  unsigned short  :0;
};
//SIG(1 BFu0s_Sf_BFu0s) C1{ Fs:0 FC2{} Fs:0}



static void Test_BFu0s_Sf_BFu0s()
{
  {
    init_simple_test("BFu0s_Sf_BFu0s");
    static STRUCT_IF_C BFu0s_Sf_BFu0s lv;
    check2(sizeof(lv), 0, "sizeof(BFu0s_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu0s, BFu0s_Sf_BFu0s)
//============================================================================


struct  BFu0s_Sf_BFu15i  {
  unsigned short  :0;
  struct empty v1;
  unsigned int v2:15;
};
//SIG(1 BFu0s_Sf_BFu15i) C1{ Fs:0 FC2{} Fi:15}



static void Test_BFu0s_Sf_BFu15i()
{
  {
    init_simple_test("BFu0s_Sf_BFu15i");
    static STRUCT_IF_C BFu0s_Sf_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Sf_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Sf_BFu15i)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu15i.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "BFu0s_Sf_BFu15i");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "BFu0s_Sf_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu15i, BFu0s_Sf_BFu15i)
//============================================================================


struct  BFu0s_Sf_BFu15ll  {
  unsigned short  :0;
  struct empty v1;
  __tsu64 v2:15;
};
//SIG(1 BFu0s_Sf_BFu15ll) C1{ Fs:0 FC2{} FL:15}



static void Test_BFu0s_Sf_BFu15ll()
{
  {
    init_simple_test("BFu0s_Sf_BFu15ll");
    static STRUCT_IF_C BFu0s_Sf_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Sf_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_BFu15ll)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu15ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "BFu0s_Sf_BFu15ll");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "BFu0s_Sf_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu15ll, BFu0s_Sf_BFu15ll)
//============================================================================


struct  BFu0s_Sf_BFu15s  {
  unsigned short  :0;
  struct empty v1;
  unsigned short v2:15;
};
//SIG(1 BFu0s_Sf_BFu15s) C1{ Fs:0 FC2{} Fs:15}



static void Test_BFu0s_Sf_BFu15s()
{
  {
    init_simple_test("BFu0s_Sf_BFu15s");
    static STRUCT_IF_C BFu0s_Sf_BFu15s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_Sf_BFu15s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_Sf_BFu15s)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu15s.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "BFu0s_Sf_BFu15s");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "BFu0s_Sf_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu15s, BFu0s_Sf_BFu15s)
//============================================================================


struct  BFu0s_Sf_BFu16i  {
  unsigned short  :0;
  struct empty v1;
  unsigned int v2:16;
};
//SIG(1 BFu0s_Sf_BFu16i) C1{ Fs:0 FC2{} Fi:16}



static void Test_BFu0s_Sf_BFu16i()
{
  {
    init_simple_test("BFu0s_Sf_BFu16i");
    static STRUCT_IF_C BFu0s_Sf_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Sf_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Sf_BFu16i)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu16i.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "BFu0s_Sf_BFu16i");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "BFu0s_Sf_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu16i, BFu0s_Sf_BFu16i)
//============================================================================


struct  BFu0s_Sf_BFu16ll  {
  unsigned short  :0;
  struct empty v1;
  __tsu64 v2:16;
};
//SIG(1 BFu0s_Sf_BFu16ll) C1{ Fs:0 FC2{} FL:16}



static void Test_BFu0s_Sf_BFu16ll()
{
  {
    init_simple_test("BFu0s_Sf_BFu16ll");
    static STRUCT_IF_C BFu0s_Sf_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Sf_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_BFu16ll)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu16ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "BFu0s_Sf_BFu16ll");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "BFu0s_Sf_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu16ll, BFu0s_Sf_BFu16ll)
//============================================================================


struct  BFu0s_Sf_BFu16s  {
  unsigned short  :0;
  struct empty v1;
  unsigned short v2:16;
};
//SIG(1 BFu0s_Sf_BFu16s) C1{ Fs:0 FC2{} Fs:16}



static void Test_BFu0s_Sf_BFu16s()
{
  {
    init_simple_test("BFu0s_Sf_BFu16s");
    static STRUCT_IF_C BFu0s_Sf_BFu16s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_Sf_BFu16s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_Sf_BFu16s)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu16s.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "BFu0s_Sf_BFu16s");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "BFu0s_Sf_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu16s, BFu0s_Sf_BFu16s)
//============================================================================


struct  BFu0s_Sf_BFu17i  {
  unsigned short  :0;
  struct empty v1;
  unsigned int v2:17;
};
//SIG(1 BFu0s_Sf_BFu17i) C1{ Fs:0 FC2{} Fi:17}



static void Test_BFu0s_Sf_BFu17i()
{
  {
    init_simple_test("BFu0s_Sf_BFu17i");
    static STRUCT_IF_C BFu0s_Sf_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Sf_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Sf_BFu17i)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu17i.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "BFu0s_Sf_BFu17i");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "BFu0s_Sf_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu17i, BFu0s_Sf_BFu17i)
//============================================================================


struct  BFu0s_Sf_BFu17ll  {
  unsigned short  :0;
  struct empty v1;
  __tsu64 v2:17;
};
//SIG(1 BFu0s_Sf_BFu17ll) C1{ Fs:0 FC2{} FL:17}



static void Test_BFu0s_Sf_BFu17ll()
{
  {
    init_simple_test("BFu0s_Sf_BFu17ll");
    static STRUCT_IF_C BFu0s_Sf_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Sf_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_BFu17ll)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu17ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "BFu0s_Sf_BFu17ll");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "BFu0s_Sf_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu17ll, BFu0s_Sf_BFu17ll)
//============================================================================


struct  BFu0s_Sf_BFu1c  {
  unsigned short  :0;
  struct empty v1;
  unsigned char v2:1;
};
//SIG(1 BFu0s_Sf_BFu1c) C1{ Fs:0 FC2{} Fc:1}



static void Test_BFu0s_Sf_BFu1c()
{
  {
    init_simple_test("BFu0s_Sf_BFu1c");
    static STRUCT_IF_C BFu0s_Sf_BFu1c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_Sf_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Sf_BFu1c)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu1c.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0s_Sf_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu1c, BFu0s_Sf_BFu1c)
//============================================================================


struct  BFu0s_Sf_BFu1i  {
  unsigned short  :0;
  struct empty v1;
  unsigned int v2:1;
};
//SIG(1 BFu0s_Sf_BFu1i) C1{ Fs:0 FC2{} Fi:1}



static void Test_BFu0s_Sf_BFu1i()
{
  {
    init_simple_test("BFu0s_Sf_BFu1i");
    static STRUCT_IF_C BFu0s_Sf_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Sf_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Sf_BFu1i)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu1i.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0s_Sf_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu1i, BFu0s_Sf_BFu1i)
//============================================================================


struct  BFu0s_Sf_BFu1ll  {
  unsigned short  :0;
  struct empty v1;
  __tsu64 v2:1;
};
//SIG(1 BFu0s_Sf_BFu1ll) C1{ Fs:0 FC2{} FL:1}



static void Test_BFu0s_Sf_BFu1ll()
{
  {
    init_simple_test("BFu0s_Sf_BFu1ll");
    static STRUCT_IF_C BFu0s_Sf_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Sf_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_BFu1ll)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu1ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0s_Sf_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu1ll, BFu0s_Sf_BFu1ll)
//============================================================================


struct  BFu0s_Sf_BFu1s  {
  unsigned short  :0;
  struct empty v1;
  unsigned short v2:1;
};
//SIG(1 BFu0s_Sf_BFu1s) C1{ Fs:0 FC2{} Fs:1}



static void Test_BFu0s_Sf_BFu1s()
{
  {
    init_simple_test("BFu0s_Sf_BFu1s");
    static STRUCT_IF_C BFu0s_Sf_BFu1s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_Sf_BFu1s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_Sf_BFu1s)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu1s.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "BFu0s_Sf_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu1s, BFu0s_Sf_BFu1s)
//============================================================================


struct  BFu0s_Sf_BFu31i  {
  unsigned short  :0;
  struct empty v1;
  unsigned int v2:31;
};
//SIG(1 BFu0s_Sf_BFu31i) C1{ Fs:0 FC2{} Fi:31}



static void Test_BFu0s_Sf_BFu31i()
{
  {
    init_simple_test("BFu0s_Sf_BFu31i");
    static STRUCT_IF_C BFu0s_Sf_BFu31i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Sf_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Sf_BFu31i)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu31i.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "BFu0s_Sf_BFu31i");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "BFu0s_Sf_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu31i, BFu0s_Sf_BFu31i)
//============================================================================


struct  BFu0s_Sf_BFu31ll  {
  unsigned short  :0;
  struct empty v1;
  __tsu64 v2:31;
};
//SIG(1 BFu0s_Sf_BFu31ll) C1{ Fs:0 FC2{} FL:31}



static void Test_BFu0s_Sf_BFu31ll()
{
  {
    init_simple_test("BFu0s_Sf_BFu31ll");
    static STRUCT_IF_C BFu0s_Sf_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Sf_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_BFu31ll)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu31ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "BFu0s_Sf_BFu31ll");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "BFu0s_Sf_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu31ll, BFu0s_Sf_BFu31ll)
//============================================================================


struct  BFu0s_Sf_BFu32i  {
  unsigned short  :0;
  struct empty v1;
  unsigned int v2:32;
};
//SIG(1 BFu0s_Sf_BFu32i) C1{ Fs:0 FC2{} Fi:32}



static void Test_BFu0s_Sf_BFu32i()
{
  {
    init_simple_test("BFu0s_Sf_BFu32i");
    static STRUCT_IF_C BFu0s_Sf_BFu32i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Sf_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Sf_BFu32i)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu32i.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "BFu0s_Sf_BFu32i");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "BFu0s_Sf_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu32i, BFu0s_Sf_BFu32i)
//============================================================================


struct  BFu0s_Sf_BFu32ll  {
  unsigned short  :0;
  struct empty v1;
  __tsu64 v2:32;
};
//SIG(1 BFu0s_Sf_BFu32ll) C1{ Fs:0 FC2{} FL:32}



static void Test_BFu0s_Sf_BFu32ll()
{
  {
    init_simple_test("BFu0s_Sf_BFu32ll");
    static STRUCT_IF_C BFu0s_Sf_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Sf_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_BFu32ll)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu32ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "BFu0s_Sf_BFu32ll");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "BFu0s_Sf_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu32ll, BFu0s_Sf_BFu32ll)
//============================================================================


struct  BFu0s_Sf_BFu33  {
  unsigned short  :0;
  struct empty v1;
  __tsu64 v2:33;
};
//SIG(1 BFu0s_Sf_BFu33) C1{ Fs:0 FC2{} FL:33}



static void Test_BFu0s_Sf_BFu33()
{
  {
    init_simple_test("BFu0s_Sf_BFu33");
    static STRUCT_IF_C BFu0s_Sf_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_Sf_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_BFu33)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu33.v1");
    set_bf_and_test(lv, v2, 0, 0, 33, 1, "BFu0s_Sf_BFu33");
    set_bf_and_test(lv, v2, 0, 0, 33, hide_ull(1LL<<32), "BFu0s_Sf_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu33, BFu0s_Sf_BFu33)
//============================================================================


struct  BFu0s_Sf_BFu7c  {
  unsigned short  :0;
  struct empty v1;
  unsigned char v2:7;
};
//SIG(1 BFu0s_Sf_BFu7c) C1{ Fs:0 FC2{} Fc:7}



static void Test_BFu0s_Sf_BFu7c()
{
  {
    init_simple_test("BFu0s_Sf_BFu7c");
    static STRUCT_IF_C BFu0s_Sf_BFu7c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_Sf_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Sf_BFu7c)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu7c.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0s_Sf_BFu7c");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0s_Sf_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu7c, BFu0s_Sf_BFu7c)
//============================================================================


struct  BFu0s_Sf_BFu7i  {
  unsigned short  :0;
  struct empty v1;
  unsigned int v2:7;
};
//SIG(1 BFu0s_Sf_BFu7i) C1{ Fs:0 FC2{} Fi:7}



static void Test_BFu0s_Sf_BFu7i()
{
  {
    init_simple_test("BFu0s_Sf_BFu7i");
    static STRUCT_IF_C BFu0s_Sf_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Sf_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Sf_BFu7i)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu7i.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0s_Sf_BFu7i");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0s_Sf_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu7i, BFu0s_Sf_BFu7i)
//============================================================================


struct  BFu0s_Sf_BFu7ll  {
  unsigned short  :0;
  struct empty v1;
  __tsu64 v2:7;
};
//SIG(1 BFu0s_Sf_BFu7ll) C1{ Fs:0 FC2{} FL:7}



static void Test_BFu0s_Sf_BFu7ll()
{
  {
    init_simple_test("BFu0s_Sf_BFu7ll");
    static STRUCT_IF_C BFu0s_Sf_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Sf_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_BFu7ll)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu7ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0s_Sf_BFu7ll");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0s_Sf_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu7ll, BFu0s_Sf_BFu7ll)
//============================================================================


struct  BFu0s_Sf_BFu7s  {
  unsigned short  :0;
  struct empty v1;
  unsigned short v2:7;
};
//SIG(1 BFu0s_Sf_BFu7s) C1{ Fs:0 FC2{} Fs:7}



static void Test_BFu0s_Sf_BFu7s()
{
  {
    init_simple_test("BFu0s_Sf_BFu7s");
    static STRUCT_IF_C BFu0s_Sf_BFu7s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_Sf_BFu7s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_Sf_BFu7s)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu7s.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "BFu0s_Sf_BFu7s");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "BFu0s_Sf_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu7s, BFu0s_Sf_BFu7s)
//============================================================================


struct  BFu0s_Sf_BFu8c  {
  unsigned short  :0;
  struct empty v1;
  unsigned char v2:8;
};
//SIG(1 BFu0s_Sf_BFu8c) C1{ Fs:0 FC2{} Fc:8}



static void Test_BFu0s_Sf_BFu8c()
{
  {
    init_simple_test("BFu0s_Sf_BFu8c");
    static STRUCT_IF_C BFu0s_Sf_BFu8c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_Sf_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Sf_BFu8c)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu8c.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0s_Sf_BFu8c");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0s_Sf_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu8c, BFu0s_Sf_BFu8c)
//============================================================================


struct  BFu0s_Sf_BFu8i  {
  unsigned short  :0;
  struct empty v1;
  unsigned int v2:8;
};
//SIG(1 BFu0s_Sf_BFu8i) C1{ Fs:0 FC2{} Fi:8}



static void Test_BFu0s_Sf_BFu8i()
{
  {
    init_simple_test("BFu0s_Sf_BFu8i");
    static STRUCT_IF_C BFu0s_Sf_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Sf_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Sf_BFu8i)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu8i.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0s_Sf_BFu8i");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0s_Sf_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu8i, BFu0s_Sf_BFu8i)
//============================================================================


struct  BFu0s_Sf_BFu8ll  {
  unsigned short  :0;
  struct empty v1;
  __tsu64 v2:8;
};
//SIG(1 BFu0s_Sf_BFu8ll) C1{ Fs:0 FC2{} FL:8}



static void Test_BFu0s_Sf_BFu8ll()
{
  {
    init_simple_test("BFu0s_Sf_BFu8ll");
    static STRUCT_IF_C BFu0s_Sf_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Sf_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_BFu8ll)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu8ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0s_Sf_BFu8ll");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0s_Sf_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu8ll, BFu0s_Sf_BFu8ll)
//============================================================================


struct  BFu0s_Sf_BFu8s  {
  unsigned short  :0;
  struct empty v1;
  unsigned short v2:8;
};
//SIG(1 BFu0s_Sf_BFu8s) C1{ Fs:0 FC2{} Fs:8}



static void Test_BFu0s_Sf_BFu8s()
{
  {
    init_simple_test("BFu0s_Sf_BFu8s");
    static STRUCT_IF_C BFu0s_Sf_BFu8s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_Sf_BFu8s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_Sf_BFu8s)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu8s.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "BFu0s_Sf_BFu8s");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "BFu0s_Sf_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu8s, BFu0s_Sf_BFu8s)
//============================================================================


struct  BFu0s_Sf_BFu9i  {
  unsigned short  :0;
  struct empty v1;
  unsigned int v2:9;
};
//SIG(1 BFu0s_Sf_BFu9i) C1{ Fs:0 FC2{} Fi:9}



static void Test_BFu0s_Sf_BFu9i()
{
  {
    init_simple_test("BFu0s_Sf_BFu9i");
    static STRUCT_IF_C BFu0s_Sf_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Sf_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Sf_BFu9i)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu9i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "BFu0s_Sf_BFu9i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "BFu0s_Sf_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu9i, BFu0s_Sf_BFu9i)
//============================================================================


struct  BFu0s_Sf_BFu9ll  {
  unsigned short  :0;
  struct empty v1;
  __tsu64 v2:9;
};
//SIG(1 BFu0s_Sf_BFu9ll) C1{ Fs:0 FC2{} FL:9}



static void Test_BFu0s_Sf_BFu9ll()
{
  {
    init_simple_test("BFu0s_Sf_BFu9ll");
    static STRUCT_IF_C BFu0s_Sf_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Sf_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_BFu9ll)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu9ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "BFu0s_Sf_BFu9ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "BFu0s_Sf_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu9ll, BFu0s_Sf_BFu9ll)
//============================================================================


struct  BFu0s_Sf_BFu9s  {
  unsigned short  :0;
  struct empty v1;
  unsigned short v2:9;
};
//SIG(1 BFu0s_Sf_BFu9s) C1{ Fs:0 FC2{} Fs:9}



static void Test_BFu0s_Sf_BFu9s()
{
  {
    init_simple_test("BFu0s_Sf_BFu9s");
    static STRUCT_IF_C BFu0s_Sf_BFu9s lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_Sf_BFu9s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_Sf_BFu9s)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_BFu9s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "BFu0s_Sf_BFu9s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "BFu0s_Sf_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_BFu9s, BFu0s_Sf_BFu9s)
//============================================================================


struct  BFu0s_Sf_C  {
  unsigned short  :0;
  struct empty v1;
  char v2;
};
//SIG(1 BFu0s_Sf_C) C1{ Fs:0 FC2{} Fc}



static void Test_BFu0s_Sf_C()
{
  {
    init_simple_test("BFu0s_Sf_C");
    static STRUCT_IF_C BFu0s_Sf_C lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_Sf_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Sf_C)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_C.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_C, BFu0s_Sf_C)
//============================================================================


struct  BFu0s_Sf_D  {
  unsigned short  :0;
  struct empty v1;
  double v2;
};
//SIG(1 BFu0s_Sf_D) C1{ Fs:0 FC2{} FL}



static void Test_BFu0s_Sf_D()
{
  {
    init_simple_test("BFu0s_Sf_D");
    static STRUCT_IF_C BFu0s_Sf_D lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_Sf_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_D)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_D.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_D, BFu0s_Sf_D)
//============================================================================


struct  BFu0s_Sf_F  {
  unsigned short  :0;
  struct empty v1;
  float v2;
};
//SIG(1 BFu0s_Sf_F) C1{ Fs:0 FC2{} Fi}



static void Test_BFu0s_Sf_F()
{
  {
    init_simple_test("BFu0s_Sf_F");
    static STRUCT_IF_C BFu0s_Sf_F lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Sf_F)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Sf_F)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_F.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_F, BFu0s_Sf_F)
//============================================================================


struct  BFu0s_Sf_I  {
  unsigned short  :0;
  struct empty v1;
  int v2;
};
//SIG(1 BFu0s_Sf_I) C1{ Fs:0 FC2{} Fi}



static void Test_BFu0s_Sf_I()
{
  {
    init_simple_test("BFu0s_Sf_I");
    static STRUCT_IF_C BFu0s_Sf_I lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Sf_I)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Sf_I)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_I.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_I, BFu0s_Sf_I)
//============================================================================


struct  BFu0s_Sf_Ip  {
  unsigned short  :0;
  struct empty v1;
  int *v2;
};
//SIG(1 BFu0s_Sf_Ip) C1{ Fs:0 FC2{} Fp}



static void Test_BFu0s_Sf_Ip()
{
  {
    init_simple_test("BFu0s_Sf_Ip");
    static STRUCT_IF_C BFu0s_Sf_Ip lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Sf_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_Ip)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_Ip.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_Ip, BFu0s_Sf_Ip)
//============================================================================


struct  BFu0s_Sf_L  {
  unsigned short  :0;
  struct empty v1;
  __tsi64 v2;
};
//SIG(1 BFu0s_Sf_L) C1{ Fs:0 FC2{} FL}



static void Test_BFu0s_Sf_L()
{
  {
    init_simple_test("BFu0s_Sf_L");
    static STRUCT_IF_C BFu0s_Sf_L lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_Sf_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_L)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_L.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_L, BFu0s_Sf_L)
//============================================================================


struct  BFu0s_Sf_S  {
  unsigned short  :0;
  struct empty v1;
  short v2;
};
//SIG(1 BFu0s_Sf_S) C1{ Fs:0 FC2{} Fs}



static void Test_BFu0s_Sf_S()
{
  {
    init_simple_test("BFu0s_Sf_S");
    static STRUCT_IF_C BFu0s_Sf_S lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_Sf_S)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_Sf_S)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_S.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_S, BFu0s_Sf_S)
//============================================================================


struct  BFu0s_Sf_Sf  {
  unsigned short  :0;
  struct empty v1;
  struct empty v2;
};
//SIG(1 BFu0s_Sf_Sf) C1{ Fs:0 FC2{} FC2}



static void Test_BFu0s_Sf_Sf()
{
  {
    init_simple_test("BFu0s_Sf_Sf");
    static STRUCT_IF_C BFu0s_Sf_Sf lv;
    check2(sizeof(lv), 0, "sizeof(BFu0s_Sf_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Sf_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_Sf.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_Sf, BFu0s_Sf_Sf)
//============================================================================


struct  BFu0s_Sf_Uc  {
  unsigned short  :0;
  struct empty v1;
  unsigned char v2;
};
//SIG(1 BFu0s_Sf_Uc) C1{ Fs:0 FC2{} Fc}



static void Test_BFu0s_Sf_Uc()
{
  {
    init_simple_test("BFu0s_Sf_Uc");
    static STRUCT_IF_C BFu0s_Sf_Uc lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_Sf_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Sf_Uc)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_Uc.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_Uc, BFu0s_Sf_Uc)
//============================================================================


struct  BFu0s_Sf_Ui  {
  unsigned short  :0;
  struct empty v1;
  unsigned int v2;
};
//SIG(1 BFu0s_Sf_Ui) C1{ Fs:0 FC2{} Fi}



static void Test_BFu0s_Sf_Ui()
{
  {
    init_simple_test("BFu0s_Sf_Ui");
    static STRUCT_IF_C BFu0s_Sf_Ui lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Sf_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Sf_Ui)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_Ui.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_Ui, BFu0s_Sf_Ui)
//============================================================================


struct  BFu0s_Sf_Ul  {
  unsigned short  :0;
  struct empty v1;
  __tsu64 v2;
};
//SIG(1 BFu0s_Sf_Ul) C1{ Fs:0 FC2{} FL}



static void Test_BFu0s_Sf_Ul()
{
  {
    init_simple_test("BFu0s_Sf_Ul");
    static STRUCT_IF_C BFu0s_Sf_Ul lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_Sf_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_Ul)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_Ul.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_Ul, BFu0s_Sf_Ul)
//============================================================================


struct  BFu0s_Sf_Us  {
  unsigned short  :0;
  struct empty v1;
  unsigned short v2;
};
//SIG(1 BFu0s_Sf_Us) C1{ Fs:0 FC2{} Fs}



static void Test_BFu0s_Sf_Us()
{
  {
    init_simple_test("BFu0s_Sf_Us");
    static STRUCT_IF_C BFu0s_Sf_Us lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_Sf_Us)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_Sf_Us)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_Us.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_Us, BFu0s_Sf_Us)
//============================================================================


struct  BFu0s_Sf_Vp  {
  unsigned short  :0;
  struct empty v1;
  void *v2;
};
//SIG(1 BFu0s_Sf_Vp) C1{ Fs:0 FC2{} Fp}



static void Test_BFu0s_Sf_Vp()
{
  {
    init_simple_test("BFu0s_Sf_Vp");
    static STRUCT_IF_C BFu0s_Sf_Vp lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Sf_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Sf_Vp)");
    check_field_offset(lv, v1, 0, "BFu0s_Sf_Vp.v1");
    check_field_offset(lv, v2, 0, "BFu0s_Sf_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Sf_Vp, BFu0s_Sf_Vp)
//============================================================================


struct  BFu0s_Uc_Sf  {
  unsigned short  :0;
  unsigned char v1;
  struct empty v2;
};
//SIG(1 BFu0s_Uc_Sf) C1{ Fs:0 Fc FC2{}}



static void Test_BFu0s_Uc_Sf()
{
  {
    init_simple_test("BFu0s_Uc_Sf");
    static STRUCT_IF_C BFu0s_Uc_Sf lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(BFu0s_Uc_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu0s_Uc_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_Uc_Sf.v1");
    check_field_offset(lv, v2, 1, "BFu0s_Uc_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Uc_Sf, BFu0s_Uc_Sf)
//============================================================================


struct  BFu0s_Ui_Sf  {
  unsigned short  :0;
  unsigned int v1;
  struct empty v2;
};
//SIG(1 BFu0s_Ui_Sf) C1{ Fs:0 Fi FC2{}}



static void Test_BFu0s_Ui_Sf()
{
  {
    init_simple_test("BFu0s_Ui_Sf");
    static STRUCT_IF_C BFu0s_Ui_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu0s_Ui_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu0s_Ui_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_Ui_Sf.v1");
    check_field_offset(lv, v2, 4, "BFu0s_Ui_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Ui_Sf, BFu0s_Ui_Sf)
//============================================================================


struct  BFu0s_Ul_Sf  {
  unsigned short  :0;
  __tsu64 v1;
  struct empty v2;
};
//SIG(1 BFu0s_Ul_Sf) C1{ Fs:0 FL FC2{}}



static void Test_BFu0s_Ul_Sf()
{
  {
    init_simple_test("BFu0s_Ul_Sf");
    static STRUCT_IF_C BFu0s_Ul_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu0s_Ul_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Ul_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_Ul_Sf.v1");
    check_field_offset(lv, v2, 8, "BFu0s_Ul_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Ul_Sf, BFu0s_Ul_Sf)
//============================================================================


struct  BFu0s_Us_Sf  {
  unsigned short  :0;
  unsigned short v1;
  struct empty v2;
};
//SIG(1 BFu0s_Us_Sf) C1{ Fs:0 Fs FC2{}}



static void Test_BFu0s_Us_Sf()
{
  {
    init_simple_test("BFu0s_Us_Sf");
    static STRUCT_IF_C BFu0s_Us_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu0s_Us_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu0s_Us_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_Us_Sf.v1");
    check_field_offset(lv, v2, 2, "BFu0s_Us_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Us_Sf, BFu0s_Us_Sf)
//============================================================================


struct  BFu0s_Vp_Sf  {
  unsigned short  :0;
  void *v1;
  struct empty v2;
};
//SIG(1 BFu0s_Vp_Sf) C1{ Fs:0 Fp FC2{}}



static void Test_BFu0s_Vp_Sf()
{
  {
    init_simple_test("BFu0s_Vp_Sf");
    static STRUCT_IF_C BFu0s_Vp_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu0s_Vp_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu0s_Vp_Sf)");
    check_field_offset(lv, v1, 0, "BFu0s_Vp_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu0s_Vp_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu0s_Vp_Sf, BFu0s_Vp_Sf)
//============================================================================


struct  BFu15i_BFu0c_Sf  {
  unsigned int v1:15;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu15i_BFu0c_Sf) C1{ Fi:15 Fc:0 FC2{}}



static void Test_BFu15i_BFu0c_Sf()
{
  {
    init_simple_test("BFu15i_BFu0c_Sf");
    static STRUCT_IF_C BFu15i_BFu0c_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_BFu0c_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_BFu0c_Sf");
    check_field_offset(lv, v2, 2, "BFu15i_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15i_BFu0c_Sf, BFu15i_BFu0c_Sf)
//============================================================================


struct  BFu15i_BFu0i_Sf  {
  unsigned int v1:15;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu15i_BFu0i_Sf) C1{ Fi:15 Fi:0 FC2{}}



static void Test_BFu15i_BFu0i_Sf()
{
  {
    init_simple_test("BFu15i_BFu0i_Sf");
    static STRUCT_IF_C BFu15i_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_BFu0i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu15i_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15i_BFu0i_Sf, BFu15i_BFu0i_Sf)
//============================================================================


struct  BFu15i_BFu0ll_Sf  {
  unsigned int v1:15;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu15i_BFu0ll_Sf) C1{ Fi:15 FL:0 FC2{}}



static void Test_BFu15i_BFu0ll_Sf()
{
  {
    init_simple_test("BFu15i_BFu0ll_Sf");
    static STRUCT_IF_C BFu15i_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15i_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu15i_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu15i_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15i_BFu0ll_Sf, BFu15i_BFu0ll_Sf)
//============================================================================


struct  BFu15i_BFu0s_Sf  {
  unsigned int v1:15;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu15i_BFu0s_Sf) C1{ Fi:15 Fs:0 FC2{}}



static void Test_BFu15i_BFu0s_Sf()
{
  {
    init_simple_test("BFu15i_BFu0s_Sf");
    static STRUCT_IF_C BFu15i_BFu0s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_BFu0s_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu15i_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15i_BFu0s_Sf, BFu15i_BFu0s_Sf)
//============================================================================


struct  BFu15i_Sf_BFu0c  {
  unsigned int v1:15;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu15i_Sf_BFu0c) C1{ Fi:15 FC2{} Fc:0}



static void Test_BFu15i_Sf_BFu0c()
{
  {
    init_simple_test("BFu15i_Sf_BFu0c");
    static STRUCT_IF_C BFu15i_Sf_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_Sf_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_Sf_BFu0c");
    check_field_offset(lv, v2, 2, "BFu15i_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15i_Sf_BFu0c, BFu15i_Sf_BFu0c)
//============================================================================


struct  BFu15i_Sf_BFu0i  {
  unsigned int v1:15;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu15i_Sf_BFu0i) C1{ Fi:15 FC2{} Fi:0}



static void Test_BFu15i_Sf_BFu0i()
{
  {
    init_simple_test("BFu15i_Sf_BFu0i");
    static STRUCT_IF_C BFu15i_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_Sf_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_Sf_BFu0i");
    check_field_offset(lv, v2, 2, "BFu15i_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15i_Sf_BFu0i, BFu15i_Sf_BFu0i)
//============================================================================


struct  BFu15i_Sf_BFu0ll  {
  unsigned int v1:15;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu15i_Sf_BFu0ll) C1{ Fi:15 FC2{} FL:0}



static void Test_BFu15i_Sf_BFu0ll()
{
  {
    init_simple_test("BFu15i_Sf_BFu0ll");
    static STRUCT_IF_C BFu15i_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15i_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu15i_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_Sf_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu15i_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15i_Sf_BFu0ll, BFu15i_Sf_BFu0ll)
//============================================================================


struct  BFu15i_Sf_BFu0s  {
  unsigned int v1:15;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu15i_Sf_BFu0s) C1{ Fi:15 FC2{} Fs:0}



static void Test_BFu15i_Sf_BFu0s()
{
  {
    init_simple_test("BFu15i_Sf_BFu0s");
    static STRUCT_IF_C BFu15i_Sf_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu15i_Sf_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu15i_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15i_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15i_Sf_BFu0s");
    check_field_offset(lv, v2, 2, "BFu15i_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15i_Sf_BFu0s, BFu15i_Sf_BFu0s)
//============================================================================


struct  BFu15ll_BFu0c_Sf  {
  __tsu64 v1:15;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu15ll_BFu0c_Sf) C1{ FL:15 Fc:0 FC2{}}



static void Test_BFu15ll_BFu0c_Sf()
{
  {
    init_simple_test("BFu15ll_BFu0c_Sf");
    static STRUCT_IF_C BFu15ll_BFu0c_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_BFu0c_Sf");
    check_field_offset(lv, v2, 2, "BFu15ll_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15ll_BFu0c_Sf, BFu15ll_BFu0c_Sf)
//============================================================================


struct  BFu15ll_BFu0i_Sf  {
  __tsu64 v1:15;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu15ll_BFu0i_Sf) C1{ FL:15 Fi:0 FC2{}}



static void Test_BFu15ll_BFu0i_Sf()
{
  {
    init_simple_test("BFu15ll_BFu0i_Sf");
    static STRUCT_IF_C BFu15ll_BFu0i_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu15ll_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15ll_BFu0i_Sf, BFu15ll_BFu0i_Sf)
//============================================================================


struct  BFu15ll_BFu0ll_Sf  {
  __tsu64 v1:15;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu15ll_BFu0ll_Sf) C1{ FL:15 FL:0 FC2{}}



static void Test_BFu15ll_BFu0ll_Sf()
{
  {
    init_simple_test("BFu15ll_BFu0ll_Sf");
    static STRUCT_IF_C BFu15ll_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu15ll_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15ll_BFu0ll_Sf, BFu15ll_BFu0ll_Sf)
//============================================================================


struct  BFu15ll_BFu0s_Sf  {
  __tsu64 v1:15;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu15ll_BFu0s_Sf) C1{ FL:15 Fs:0 FC2{}}



static void Test_BFu15ll_BFu0s_Sf()
{
  {
    init_simple_test("BFu15ll_BFu0s_Sf");
    static STRUCT_IF_C BFu15ll_BFu0s_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu15ll_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15ll_BFu0s_Sf, BFu15ll_BFu0s_Sf)
//============================================================================


struct  BFu15ll_Sf_BFu0c  {
  __tsu64 v1:15;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu15ll_Sf_BFu0c) C1{ FL:15 FC2{} Fc:0}



static void Test_BFu15ll_Sf_BFu0c()
{
  {
    init_simple_test("BFu15ll_Sf_BFu0c");
    static STRUCT_IF_C BFu15ll_Sf_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_Sf_BFu0c");
    check_field_offset(lv, v2, 2, "BFu15ll_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15ll_Sf_BFu0c, BFu15ll_Sf_BFu0c)
//============================================================================


struct  BFu15ll_Sf_BFu0i  {
  __tsu64 v1:15;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu15ll_Sf_BFu0i) C1{ FL:15 FC2{} Fi:0}



static void Test_BFu15ll_Sf_BFu0i()
{
  {
    init_simple_test("BFu15ll_Sf_BFu0i");
    static STRUCT_IF_C BFu15ll_Sf_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_Sf_BFu0i");
    check_field_offset(lv, v2, 2, "BFu15ll_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15ll_Sf_BFu0i, BFu15ll_Sf_BFu0i)
//============================================================================


struct  BFu15ll_Sf_BFu0ll  {
  __tsu64 v1:15;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu15ll_Sf_BFu0ll) C1{ FL:15 FC2{} FL:0}



static void Test_BFu15ll_Sf_BFu0ll()
{
  {
    init_simple_test("BFu15ll_Sf_BFu0ll");
    static STRUCT_IF_C BFu15ll_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_Sf_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu15ll_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15ll_Sf_BFu0ll, BFu15ll_Sf_BFu0ll)
//============================================================================


struct  BFu15ll_Sf_BFu0s  {
  __tsu64 v1:15;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu15ll_Sf_BFu0s) C1{ FL:15 FC2{} Fs:0}



static void Test_BFu15ll_Sf_BFu0s()
{
  {
    init_simple_test("BFu15ll_Sf_BFu0s");
    static STRUCT_IF_C BFu15ll_Sf_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15ll_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu15ll_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15ll_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15ll_Sf_BFu0s");
    check_field_offset(lv, v2, 2, "BFu15ll_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15ll_Sf_BFu0s, BFu15ll_Sf_BFu0s)
//============================================================================


struct  BFu15s_BFu0c_Sf  {
  unsigned short v1:15;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu15s_BFu0c_Sf) C1{ Fs:15 Fc:0 FC2{}}



static void Test_BFu15s_BFu0c_Sf()
{
  {
    init_simple_test("BFu15s_BFu0c_Sf");
    static STRUCT_IF_C BFu15s_BFu0c_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu15s_BFu0c_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu15s_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_BFu0c_Sf");
    check_field_offset(lv, v2, 2, "BFu15s_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15s_BFu0c_Sf, BFu15s_BFu0c_Sf)
//============================================================================


struct  BFu15s_BFu0i_Sf  {
  unsigned short v1:15;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu15s_BFu0i_Sf) C1{ Fs:15 Fi:0 FC2{}}



static void Test_BFu15s_BFu0i_Sf()
{
  {
    init_simple_test("BFu15s_BFu0i_Sf");
    static STRUCT_IF_C BFu15s_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu15s_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu15s_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu15s_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15s_BFu0i_Sf, BFu15s_BFu0i_Sf)
//============================================================================


struct  BFu15s_BFu0ll_Sf  {
  unsigned short v1:15;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu15s_BFu0ll_Sf) C1{ Fs:15 FL:0 FC2{}}



static void Test_BFu15s_BFu0ll_Sf()
{
  {
    init_simple_test("BFu15s_BFu0ll_Sf");
    static STRUCT_IF_C BFu15s_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15s_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu15s_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu15s_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15s_BFu0ll_Sf, BFu15s_BFu0ll_Sf)
//============================================================================


struct  BFu15s_BFu0s_Sf  {
  unsigned short v1:15;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu15s_BFu0s_Sf) C1{ Fs:15 Fs:0 FC2{}}



static void Test_BFu15s_BFu0s_Sf()
{
  {
    init_simple_test("BFu15s_BFu0s_Sf");
    static STRUCT_IF_C BFu15s_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu15s_BFu0s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu15s_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu15s_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15s_BFu0s_Sf, BFu15s_BFu0s_Sf)
//============================================================================


struct  BFu15s_Sf_BFu0c  {
  unsigned short v1:15;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu15s_Sf_BFu0c) C1{ Fs:15 FC2{} Fc:0}



static void Test_BFu15s_Sf_BFu0c()
{
  {
    init_simple_test("BFu15s_Sf_BFu0c");
    static STRUCT_IF_C BFu15s_Sf_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(BFu15s_Sf_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(BFu15s_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_Sf_BFu0c");
    check_field_offset(lv, v2, 2, "BFu15s_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15s_Sf_BFu0c, BFu15s_Sf_BFu0c)
//============================================================================


struct  BFu15s_Sf_BFu0i  {
  unsigned short v1:15;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu15s_Sf_BFu0i) C1{ Fs:15 FC2{} Fi:0}



static void Test_BFu15s_Sf_BFu0i()
{
  {
    init_simple_test("BFu15s_Sf_BFu0i");
    static STRUCT_IF_C BFu15s_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu15s_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu15s_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_Sf_BFu0i");
    check_field_offset(lv, v2, 2, "BFu15s_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15s_Sf_BFu0i, BFu15s_Sf_BFu0i)
//============================================================================


struct  BFu15s_Sf_BFu0ll  {
  unsigned short v1:15;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu15s_Sf_BFu0ll) C1{ Fs:15 FC2{} FL:0}



static void Test_BFu15s_Sf_BFu0ll()
{
  {
    init_simple_test("BFu15s_Sf_BFu0ll");
    static STRUCT_IF_C BFu15s_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu15s_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu15s_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_Sf_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu15s_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15s_Sf_BFu0ll, BFu15s_Sf_BFu0ll)
//============================================================================


struct  BFu15s_Sf_BFu0s  {
  unsigned short v1:15;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu15s_Sf_BFu0s) C1{ Fs:15 FC2{} Fs:0}



static void Test_BFu15s_Sf_BFu0s()
{
  {
    init_simple_test("BFu15s_Sf_BFu0s");
    static STRUCT_IF_C BFu15s_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu15s_Sf_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu15s_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 15, 1, "BFu15s_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 15, hide_ull(1LL<<14), "BFu15s_Sf_BFu0s");
    check_field_offset(lv, v2, 2, "BFu15s_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu15s_Sf_BFu0s, BFu15s_Sf_BFu0s)
//============================================================================


struct  BFu16i_BFu0c_Sf  {
  unsigned int v1:16;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu16i_BFu0c_Sf) C1{ Fi:16 Fc:0 FC2{}}



static void Test_BFu16i_BFu0c_Sf()
{
  {
    init_simple_test("BFu16i_BFu0c_Sf");
    static STRUCT_IF_C BFu16i_BFu0c_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_BFu0c_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_BFu0c_Sf");
    check_field_offset(lv, v2, 2, "BFu16i_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16i_BFu0c_Sf, BFu16i_BFu0c_Sf)
//============================================================================


struct  BFu16i_BFu0i_Sf  {
  unsigned int v1:16;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu16i_BFu0i_Sf) C1{ Fi:16 Fi:0 FC2{}}



static void Test_BFu16i_BFu0i_Sf()
{
  {
    init_simple_test("BFu16i_BFu0i_Sf");
    static STRUCT_IF_C BFu16i_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_BFu0i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu16i_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16i_BFu0i_Sf, BFu16i_BFu0i_Sf)
//============================================================================


struct  BFu16i_BFu0ll_Sf  {
  unsigned int v1:16;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu16i_BFu0ll_Sf) C1{ Fi:16 FL:0 FC2{}}



static void Test_BFu16i_BFu0ll_Sf()
{
  {
    init_simple_test("BFu16i_BFu0ll_Sf");
    static STRUCT_IF_C BFu16i_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16i_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu16i_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu16i_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16i_BFu0ll_Sf, BFu16i_BFu0ll_Sf)
//============================================================================


struct  BFu16i_BFu0s_Sf  {
  unsigned int v1:16;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu16i_BFu0s_Sf) C1{ Fi:16 Fs:0 FC2{}}



static void Test_BFu16i_BFu0s_Sf()
{
  {
    init_simple_test("BFu16i_BFu0s_Sf");
    static STRUCT_IF_C BFu16i_BFu0s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_BFu0s_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu16i_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16i_BFu0s_Sf, BFu16i_BFu0s_Sf)
//============================================================================


struct  BFu16i_Sf_BFu0c  {
  unsigned int v1:16;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu16i_Sf_BFu0c) C1{ Fi:16 FC2{} Fc:0}



static void Test_BFu16i_Sf_BFu0c()
{
  {
    init_simple_test("BFu16i_Sf_BFu0c");
    static STRUCT_IF_C BFu16i_Sf_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_Sf_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_Sf_BFu0c");
    check_field_offset(lv, v2, 2, "BFu16i_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16i_Sf_BFu0c, BFu16i_Sf_BFu0c)
//============================================================================


struct  BFu16i_Sf_BFu0i  {
  unsigned int v1:16;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu16i_Sf_BFu0i) C1{ Fi:16 FC2{} Fi:0}



static void Test_BFu16i_Sf_BFu0i()
{
  {
    init_simple_test("BFu16i_Sf_BFu0i");
    static STRUCT_IF_C BFu16i_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_Sf_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_Sf_BFu0i");
    check_field_offset(lv, v2, 2, "BFu16i_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16i_Sf_BFu0i, BFu16i_Sf_BFu0i)
//============================================================================


struct  BFu16i_Sf_BFu0ll  {
  unsigned int v1:16;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu16i_Sf_BFu0ll) C1{ Fi:16 FC2{} FL:0}



static void Test_BFu16i_Sf_BFu0ll()
{
  {
    init_simple_test("BFu16i_Sf_BFu0ll");
    static STRUCT_IF_C BFu16i_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16i_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu16i_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_Sf_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu16i_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16i_Sf_BFu0ll, BFu16i_Sf_BFu0ll)
//============================================================================


struct  BFu16i_Sf_BFu0s  {
  unsigned int v1:16;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu16i_Sf_BFu0s) C1{ Fi:16 FC2{} Fs:0}



static void Test_BFu16i_Sf_BFu0s()
{
  {
    init_simple_test("BFu16i_Sf_BFu0s");
    static STRUCT_IF_C BFu16i_Sf_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu16i_Sf_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu16i_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16i_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16i_Sf_BFu0s");
    check_field_offset(lv, v2, 2, "BFu16i_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16i_Sf_BFu0s, BFu16i_Sf_BFu0s)
//============================================================================


struct  BFu16ll_BFu0c_Sf  {
  __tsu64 v1:16;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu16ll_BFu0c_Sf) C1{ FL:16 Fc:0 FC2{}}



static void Test_BFu16ll_BFu0c_Sf()
{
  {
    init_simple_test("BFu16ll_BFu0c_Sf");
    static STRUCT_IF_C BFu16ll_BFu0c_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_BFu0c_Sf");
    check_field_offset(lv, v2, 2, "BFu16ll_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16ll_BFu0c_Sf, BFu16ll_BFu0c_Sf)
//============================================================================


struct  BFu16ll_BFu0i_Sf  {
  __tsu64 v1:16;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu16ll_BFu0i_Sf) C1{ FL:16 Fi:0 FC2{}}



static void Test_BFu16ll_BFu0i_Sf()
{
  {
    init_simple_test("BFu16ll_BFu0i_Sf");
    static STRUCT_IF_C BFu16ll_BFu0i_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu16ll_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16ll_BFu0i_Sf, BFu16ll_BFu0i_Sf)
//============================================================================


struct  BFu16ll_BFu0ll_Sf  {
  __tsu64 v1:16;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu16ll_BFu0ll_Sf) C1{ FL:16 FL:0 FC2{}}



static void Test_BFu16ll_BFu0ll_Sf()
{
  {
    init_simple_test("BFu16ll_BFu0ll_Sf");
    static STRUCT_IF_C BFu16ll_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu16ll_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16ll_BFu0ll_Sf, BFu16ll_BFu0ll_Sf)
//============================================================================


struct  BFu16ll_BFu0s_Sf  {
  __tsu64 v1:16;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu16ll_BFu0s_Sf) C1{ FL:16 Fs:0 FC2{}}



static void Test_BFu16ll_BFu0s_Sf()
{
  {
    init_simple_test("BFu16ll_BFu0s_Sf");
    static STRUCT_IF_C BFu16ll_BFu0s_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu16ll_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16ll_BFu0s_Sf, BFu16ll_BFu0s_Sf)
//============================================================================


struct  BFu16ll_Sf_BFu0c  {
  __tsu64 v1:16;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu16ll_Sf_BFu0c) C1{ FL:16 FC2{} Fc:0}



static void Test_BFu16ll_Sf_BFu0c()
{
  {
    init_simple_test("BFu16ll_Sf_BFu0c");
    static STRUCT_IF_C BFu16ll_Sf_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_Sf_BFu0c");
    check_field_offset(lv, v2, 2, "BFu16ll_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16ll_Sf_BFu0c, BFu16ll_Sf_BFu0c)
//============================================================================


struct  BFu16ll_Sf_BFu0i  {
  __tsu64 v1:16;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu16ll_Sf_BFu0i) C1{ FL:16 FC2{} Fi:0}



static void Test_BFu16ll_Sf_BFu0i()
{
  {
    init_simple_test("BFu16ll_Sf_BFu0i");
    static STRUCT_IF_C BFu16ll_Sf_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_Sf_BFu0i");
    check_field_offset(lv, v2, 2, "BFu16ll_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16ll_Sf_BFu0i, BFu16ll_Sf_BFu0i)
//============================================================================


struct  BFu16ll_Sf_BFu0ll  {
  __tsu64 v1:16;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu16ll_Sf_BFu0ll) C1{ FL:16 FC2{} FL:0}



static void Test_BFu16ll_Sf_BFu0ll()
{
  {
    init_simple_test("BFu16ll_Sf_BFu0ll");
    static STRUCT_IF_C BFu16ll_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_Sf_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu16ll_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16ll_Sf_BFu0ll, BFu16ll_Sf_BFu0ll)
//============================================================================


struct  BFu16ll_Sf_BFu0s  {
  __tsu64 v1:16;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu16ll_Sf_BFu0s) C1{ FL:16 FC2{} Fs:0}



static void Test_BFu16ll_Sf_BFu0s()
{
  {
    init_simple_test("BFu16ll_Sf_BFu0s");
    static STRUCT_IF_C BFu16ll_Sf_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16ll_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu16ll_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16ll_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16ll_Sf_BFu0s");
    check_field_offset(lv, v2, 2, "BFu16ll_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16ll_Sf_BFu0s, BFu16ll_Sf_BFu0s)
//============================================================================


struct  BFu16s_BFu0c_Sf  {
  unsigned short v1:16;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu16s_BFu0c_Sf) C1{ Fs:16 Fc:0 FC2{}}



static void Test_BFu16s_BFu0c_Sf()
{
  {
    init_simple_test("BFu16s_BFu0c_Sf");
    static STRUCT_IF_C BFu16s_BFu0c_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu16s_BFu0c_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu16s_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_BFu0c_Sf");
    check_field_offset(lv, v2, 2, "BFu16s_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16s_BFu0c_Sf, BFu16s_BFu0c_Sf)
//============================================================================


struct  BFu16s_BFu0i_Sf  {
  unsigned short v1:16;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu16s_BFu0i_Sf) C1{ Fs:16 Fi:0 FC2{}}



static void Test_BFu16s_BFu0i_Sf()
{
  {
    init_simple_test("BFu16s_BFu0i_Sf");
    static STRUCT_IF_C BFu16s_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu16s_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu16s_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu16s_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16s_BFu0i_Sf, BFu16s_BFu0i_Sf)
//============================================================================


struct  BFu16s_BFu0ll_Sf  {
  unsigned short v1:16;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu16s_BFu0ll_Sf) C1{ Fs:16 FL:0 FC2{}}



static void Test_BFu16s_BFu0ll_Sf()
{
  {
    init_simple_test("BFu16s_BFu0ll_Sf");
    static STRUCT_IF_C BFu16s_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16s_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu16s_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu16s_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16s_BFu0ll_Sf, BFu16s_BFu0ll_Sf)
//============================================================================


struct  BFu16s_BFu0s_Sf  {
  unsigned short v1:16;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu16s_BFu0s_Sf) C1{ Fs:16 Fs:0 FC2{}}



static void Test_BFu16s_BFu0s_Sf()
{
  {
    init_simple_test("BFu16s_BFu0s_Sf");
    static STRUCT_IF_C BFu16s_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu16s_BFu0s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu16s_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu16s_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16s_BFu0s_Sf, BFu16s_BFu0s_Sf)
//============================================================================


struct  BFu16s_Sf_BFu0c  {
  unsigned short v1:16;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu16s_Sf_BFu0c) C1{ Fs:16 FC2{} Fc:0}



static void Test_BFu16s_Sf_BFu0c()
{
  {
    init_simple_test("BFu16s_Sf_BFu0c");
    static STRUCT_IF_C BFu16s_Sf_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(BFu16s_Sf_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(BFu16s_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_Sf_BFu0c");
    check_field_offset(lv, v2, 2, "BFu16s_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16s_Sf_BFu0c, BFu16s_Sf_BFu0c)
//============================================================================


struct  BFu16s_Sf_BFu0i  {
  unsigned short v1:16;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu16s_Sf_BFu0i) C1{ Fs:16 FC2{} Fi:0}



static void Test_BFu16s_Sf_BFu0i()
{
  {
    init_simple_test("BFu16s_Sf_BFu0i");
    static STRUCT_IF_C BFu16s_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu16s_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu16s_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_Sf_BFu0i");
    check_field_offset(lv, v2, 2, "BFu16s_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16s_Sf_BFu0i, BFu16s_Sf_BFu0i)
//============================================================================


struct  BFu16s_Sf_BFu0ll  {
  unsigned short v1:16;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu16s_Sf_BFu0ll) C1{ Fs:16 FC2{} FL:0}



static void Test_BFu16s_Sf_BFu0ll()
{
  {
    init_simple_test("BFu16s_Sf_BFu0ll");
    static STRUCT_IF_C BFu16s_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu16s_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu16s_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_Sf_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu16s_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16s_Sf_BFu0ll, BFu16s_Sf_BFu0ll)
//============================================================================


struct  BFu16s_Sf_BFu0s  {
  unsigned short v1:16;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu16s_Sf_BFu0s) C1{ Fs:16 FC2{} Fs:0}



static void Test_BFu16s_Sf_BFu0s()
{
  {
    init_simple_test("BFu16s_Sf_BFu0s");
    static STRUCT_IF_C BFu16s_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu16s_Sf_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu16s_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 16, 1, "BFu16s_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 16, hide_ull(1LL<<15), "BFu16s_Sf_BFu0s");
    check_field_offset(lv, v2, 2, "BFu16s_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu16s_Sf_BFu0s, BFu16s_Sf_BFu0s)
//============================================================================


struct  BFu17i_BFu0c_Sf  {
  unsigned int v1:17;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu17i_BFu0c_Sf) C1{ Fi:17 Fc:0 FC2{}}



static void Test_BFu17i_BFu0c_Sf()
{
  {
    init_simple_test("BFu17i_BFu0c_Sf");
    static STRUCT_IF_C BFu17i_BFu0c_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu17i_BFu0c_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_BFu0c_Sf");
    check_field_offset(lv, v2, 3, "BFu17i_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17i_BFu0c_Sf, BFu17i_BFu0c_Sf)
//============================================================================


struct  BFu17i_BFu0i_Sf  {
  unsigned int v1:17;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu17i_BFu0i_Sf) C1{ Fi:17 Fi:0 FC2{}}



static void Test_BFu17i_BFu0i_Sf()
{
  {
    init_simple_test("BFu17i_BFu0i_Sf");
    static STRUCT_IF_C BFu17i_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu17i_BFu0i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu17i_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17i_BFu0i_Sf, BFu17i_BFu0i_Sf)
//============================================================================


struct  BFu17i_BFu0ll_Sf  {
  unsigned int v1:17;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu17i_BFu0ll_Sf) C1{ Fi:17 FL:0 FC2{}}



static void Test_BFu17i_BFu0ll_Sf()
{
  {
    init_simple_test("BFu17i_BFu0ll_Sf");
    static STRUCT_IF_C BFu17i_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17i_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu17i_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu17i_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17i_BFu0ll_Sf, BFu17i_BFu0ll_Sf)
//============================================================================


struct  BFu17i_BFu0s_Sf  {
  unsigned int v1:17;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu17i_BFu0s_Sf) C1{ Fi:17 Fs:0 FC2{}}



static void Test_BFu17i_BFu0s_Sf()
{
  {
    init_simple_test("BFu17i_BFu0s_Sf");
    static STRUCT_IF_C BFu17i_BFu0s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu17i_BFu0s_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_BFu0s_Sf");
    check_field_offset(lv, v2, 4, "BFu17i_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17i_BFu0s_Sf, BFu17i_BFu0s_Sf)
//============================================================================


struct  BFu17i_Sf_BFu0c  {
  unsigned int v1:17;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu17i_Sf_BFu0c) C1{ Fi:17 FC2{} Fc:0}



static void Test_BFu17i_Sf_BFu0c()
{
  {
    init_simple_test("BFu17i_Sf_BFu0c");
    static STRUCT_IF_C BFu17i_Sf_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu17i_Sf_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_Sf_BFu0c");
    check_field_offset(lv, v2, 3, "BFu17i_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17i_Sf_BFu0c, BFu17i_Sf_BFu0c)
//============================================================================


struct  BFu17i_Sf_BFu0i  {
  unsigned int v1:17;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu17i_Sf_BFu0i) C1{ Fi:17 FC2{} Fi:0}



static void Test_BFu17i_Sf_BFu0i()
{
  {
    init_simple_test("BFu17i_Sf_BFu0i");
    static STRUCT_IF_C BFu17i_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu17i_Sf_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_Sf_BFu0i");
    check_field_offset(lv, v2, 3, "BFu17i_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17i_Sf_BFu0i, BFu17i_Sf_BFu0i)
//============================================================================


struct  BFu17i_Sf_BFu0ll  {
  unsigned int v1:17;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu17i_Sf_BFu0ll) C1{ Fi:17 FC2{} FL:0}



static void Test_BFu17i_Sf_BFu0ll()
{
  {
    init_simple_test("BFu17i_Sf_BFu0ll");
    static STRUCT_IF_C BFu17i_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17i_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu17i_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_Sf_BFu0ll");
    check_field_offset(lv, v2, 3, "BFu17i_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17i_Sf_BFu0ll, BFu17i_Sf_BFu0ll)
//============================================================================


struct  BFu17i_Sf_BFu0s  {
  unsigned int v1:17;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu17i_Sf_BFu0s) C1{ Fi:17 FC2{} Fs:0}



static void Test_BFu17i_Sf_BFu0s()
{
  {
    init_simple_test("BFu17i_Sf_BFu0s");
    static STRUCT_IF_C BFu17i_Sf_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu17i_Sf_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu17i_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17i_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17i_Sf_BFu0s");
    check_field_offset(lv, v2, 3, "BFu17i_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17i_Sf_BFu0s, BFu17i_Sf_BFu0s)
//============================================================================


struct  BFu17ll_BFu0c_Sf  {
  __tsu64 v1:17;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu17ll_BFu0c_Sf) C1{ FL:17 Fc:0 FC2{}}



static void Test_BFu17ll_BFu0c_Sf()
{
  {
    init_simple_test("BFu17ll_BFu0c_Sf");
    static STRUCT_IF_C BFu17ll_BFu0c_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_BFu0c_Sf");
    check_field_offset(lv, v2, 3, "BFu17ll_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17ll_BFu0c_Sf, BFu17ll_BFu0c_Sf)
//============================================================================


struct  BFu17ll_BFu0i_Sf  {
  __tsu64 v1:17;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu17ll_BFu0i_Sf) C1{ FL:17 Fi:0 FC2{}}



static void Test_BFu17ll_BFu0i_Sf()
{
  {
    init_simple_test("BFu17ll_BFu0i_Sf");
    static STRUCT_IF_C BFu17ll_BFu0i_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu17ll_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17ll_BFu0i_Sf, BFu17ll_BFu0i_Sf)
//============================================================================


struct  BFu17ll_BFu0ll_Sf  {
  __tsu64 v1:17;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu17ll_BFu0ll_Sf) C1{ FL:17 FL:0 FC2{}}



static void Test_BFu17ll_BFu0ll_Sf()
{
  {
    init_simple_test("BFu17ll_BFu0ll_Sf");
    static STRUCT_IF_C BFu17ll_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu17ll_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17ll_BFu0ll_Sf, BFu17ll_BFu0ll_Sf)
//============================================================================


struct  BFu17ll_BFu0s_Sf  {
  __tsu64 v1:17;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu17ll_BFu0s_Sf) C1{ FL:17 Fs:0 FC2{}}



static void Test_BFu17ll_BFu0s_Sf()
{
  {
    init_simple_test("BFu17ll_BFu0s_Sf");
    static STRUCT_IF_C BFu17ll_BFu0s_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_BFu0s_Sf");
    check_field_offset(lv, v2, 4, "BFu17ll_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17ll_BFu0s_Sf, BFu17ll_BFu0s_Sf)
//============================================================================


struct  BFu17ll_Sf_BFu0c  {
  __tsu64 v1:17;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu17ll_Sf_BFu0c) C1{ FL:17 FC2{} Fc:0}



static void Test_BFu17ll_Sf_BFu0c()
{
  {
    init_simple_test("BFu17ll_Sf_BFu0c");
    static STRUCT_IF_C BFu17ll_Sf_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_Sf_BFu0c");
    check_field_offset(lv, v2, 3, "BFu17ll_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17ll_Sf_BFu0c, BFu17ll_Sf_BFu0c)
//============================================================================


struct  BFu17ll_Sf_BFu0i  {
  __tsu64 v1:17;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu17ll_Sf_BFu0i) C1{ FL:17 FC2{} Fi:0}



static void Test_BFu17ll_Sf_BFu0i()
{
  {
    init_simple_test("BFu17ll_Sf_BFu0i");
    static STRUCT_IF_C BFu17ll_Sf_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_Sf_BFu0i");
    check_field_offset(lv, v2, 3, "BFu17ll_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17ll_Sf_BFu0i, BFu17ll_Sf_BFu0i)
//============================================================================


struct  BFu17ll_Sf_BFu0ll  {
  __tsu64 v1:17;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu17ll_Sf_BFu0ll) C1{ FL:17 FC2{} FL:0}



static void Test_BFu17ll_Sf_BFu0ll()
{
  {
    init_simple_test("BFu17ll_Sf_BFu0ll");
    static STRUCT_IF_C BFu17ll_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_Sf_BFu0ll");
    check_field_offset(lv, v2, 3, "BFu17ll_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17ll_Sf_BFu0ll, BFu17ll_Sf_BFu0ll)
//============================================================================


struct  BFu17ll_Sf_BFu0s  {
  __tsu64 v1:17;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu17ll_Sf_BFu0s) C1{ FL:17 FC2{} Fs:0}



static void Test_BFu17ll_Sf_BFu0s()
{
  {
    init_simple_test("BFu17ll_Sf_BFu0s");
    static STRUCT_IF_C BFu17ll_Sf_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu17ll_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu17ll_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 17, 1, "BFu17ll_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 17, hide_ull(1LL<<16), "BFu17ll_Sf_BFu0s");
    check_field_offset(lv, v2, 3, "BFu17ll_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu17ll_Sf_BFu0s, BFu17ll_Sf_BFu0s)
//============================================================================


struct  BFu1c_BFu0c_Sf  {
  unsigned char v1:1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu1c_BFu0c_Sf) C1{ Fc:1 Fc:0 FC2{}}



static void Test_BFu1c_BFu0c_Sf()
{
  {
    init_simple_test("BFu1c_BFu0c_Sf");
    static STRUCT_IF_C BFu1c_BFu0c_Sf lv;
    check2(sizeof(lv), 1, "sizeof(BFu1c_BFu0c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1c_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_BFu0c_Sf");
    check_field_offset(lv, v2, 1, "BFu1c_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1c_BFu0c_Sf, BFu1c_BFu0c_Sf)
//============================================================================


struct  BFu1c_BFu0i_Sf  {
  unsigned char v1:1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu1c_BFu0i_Sf) C1{ Fc:1 Fi:0 FC2{}}



static void Test_BFu1c_BFu0i_Sf()
{
  {
    init_simple_test("BFu1c_BFu0i_Sf");
    static STRUCT_IF_C BFu1c_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu1c_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu1c_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu1c_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1c_BFu0i_Sf, BFu1c_BFu0i_Sf)
//============================================================================


struct  BFu1c_BFu0ll_Sf  {
  unsigned char v1:1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu1c_BFu0ll_Sf) C1{ Fc:1 FL:0 FC2{}}



static void Test_BFu1c_BFu0ll_Sf()
{
  {
    init_simple_test("BFu1c_BFu0ll_Sf");
    static STRUCT_IF_C BFu1c_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1c_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu1c_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu1c_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1c_BFu0ll_Sf, BFu1c_BFu0ll_Sf)
//============================================================================


struct  BFu1c_BFu0s_Sf  {
  unsigned char v1:1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu1c_BFu0s_Sf) C1{ Fc:1 Fs:0 FC2{}}



static void Test_BFu1c_BFu0s_Sf()
{
  {
    init_simple_test("BFu1c_BFu0s_Sf");
    static STRUCT_IF_C BFu1c_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu1c_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu1c_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu1c_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1c_BFu0s_Sf, BFu1c_BFu0s_Sf)
//============================================================================


struct  BFu1c_Sf_BFu0c  {
  unsigned char v1:1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu1c_Sf_BFu0c) C1{ Fc:1 FC2{} Fc:0}



static void Test_BFu1c_Sf_BFu0c()
{
  {
    init_simple_test("BFu1c_Sf_BFu0c");
    static STRUCT_IF_C BFu1c_Sf_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(BFu1c_Sf_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu1c_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_Sf_BFu0c");
    check_field_offset(lv, v2, 1, "BFu1c_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1c_Sf_BFu0c, BFu1c_Sf_BFu0c)
//============================================================================


struct  BFu1c_Sf_BFu0i  {
  unsigned char v1:1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu1c_Sf_BFu0i) C1{ Fc:1 FC2{} Fi:0}



static void Test_BFu1c_Sf_BFu0i()
{
  {
    init_simple_test("BFu1c_Sf_BFu0i");
    static STRUCT_IF_C BFu1c_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu1c_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu1c_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_Sf_BFu0i");
    check_field_offset(lv, v2, 1, "BFu1c_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1c_Sf_BFu0i, BFu1c_Sf_BFu0i)
//============================================================================


struct  BFu1c_Sf_BFu0ll  {
  unsigned char v1:1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu1c_Sf_BFu0ll) C1{ Fc:1 FC2{} FL:0}



static void Test_BFu1c_Sf_BFu0ll()
{
  {
    init_simple_test("BFu1c_Sf_BFu0ll");
    static STRUCT_IF_C BFu1c_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1c_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu1c_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_Sf_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu1c_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1c_Sf_BFu0ll, BFu1c_Sf_BFu0ll)
//============================================================================


struct  BFu1c_Sf_BFu0s  {
  unsigned char v1:1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu1c_Sf_BFu0s) C1{ Fc:1 FC2{} Fs:0}



static void Test_BFu1c_Sf_BFu0s()
{
  {
    init_simple_test("BFu1c_Sf_BFu0s");
    static STRUCT_IF_C BFu1c_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu1c_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu1c_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1c_Sf_BFu0s");
    check_field_offset(lv, v2, 1, "BFu1c_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1c_Sf_BFu0s, BFu1c_Sf_BFu0s)
//============================================================================


struct  BFu1i_BFu0c_Sf  {
  unsigned int v1:1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu1i_BFu0c_Sf) C1{ Fi:1 Fc:0 FC2{}}



static void Test_BFu1i_BFu0c_Sf()
{
  {
    init_simple_test("BFu1i_BFu0c_Sf");
    static STRUCT_IF_C BFu1i_BFu0c_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_BFu0c_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_BFu0c_Sf");
    check_field_offset(lv, v2, 1, "BFu1i_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1i_BFu0c_Sf, BFu1i_BFu0c_Sf)
//============================================================================


struct  BFu1i_BFu0i_Sf  {
  unsigned int v1:1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu1i_BFu0i_Sf) C1{ Fi:1 Fi:0 FC2{}}



static void Test_BFu1i_BFu0i_Sf()
{
  {
    init_simple_test("BFu1i_BFu0i_Sf");
    static STRUCT_IF_C BFu1i_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_BFu0i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu1i_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1i_BFu0i_Sf, BFu1i_BFu0i_Sf)
//============================================================================


struct  BFu1i_BFu0ll_Sf  {
  unsigned int v1:1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu1i_BFu0ll_Sf) C1{ Fi:1 FL:0 FC2{}}



static void Test_BFu1i_BFu0ll_Sf()
{
  {
    init_simple_test("BFu1i_BFu0ll_Sf");
    static STRUCT_IF_C BFu1i_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1i_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu1i_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu1i_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1i_BFu0ll_Sf, BFu1i_BFu0ll_Sf)
//============================================================================


struct  BFu1i_BFu0s_Sf  {
  unsigned int v1:1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu1i_BFu0s_Sf) C1{ Fi:1 Fs:0 FC2{}}



static void Test_BFu1i_BFu0s_Sf()
{
  {
    init_simple_test("BFu1i_BFu0s_Sf");
    static STRUCT_IF_C BFu1i_BFu0s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_BFu0s_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu1i_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1i_BFu0s_Sf, BFu1i_BFu0s_Sf)
//============================================================================


struct  BFu1i_Sf_BFu0c  {
  unsigned int v1:1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu1i_Sf_BFu0c) C1{ Fi:1 FC2{} Fc:0}



static void Test_BFu1i_Sf_BFu0c()
{
  {
    init_simple_test("BFu1i_Sf_BFu0c");
    static STRUCT_IF_C BFu1i_Sf_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_Sf_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_Sf_BFu0c");
    check_field_offset(lv, v2, 1, "BFu1i_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1i_Sf_BFu0c, BFu1i_Sf_BFu0c)
//============================================================================


struct  BFu1i_Sf_BFu0i  {
  unsigned int v1:1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu1i_Sf_BFu0i) C1{ Fi:1 FC2{} Fi:0}



static void Test_BFu1i_Sf_BFu0i()
{
  {
    init_simple_test("BFu1i_Sf_BFu0i");
    static STRUCT_IF_C BFu1i_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_Sf_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_Sf_BFu0i");
    check_field_offset(lv, v2, 1, "BFu1i_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1i_Sf_BFu0i, BFu1i_Sf_BFu0i)
//============================================================================


struct  BFu1i_Sf_BFu0ll  {
  unsigned int v1:1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu1i_Sf_BFu0ll) C1{ Fi:1 FC2{} FL:0}



static void Test_BFu1i_Sf_BFu0ll()
{
  {
    init_simple_test("BFu1i_Sf_BFu0ll");
    static STRUCT_IF_C BFu1i_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1i_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu1i_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_Sf_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu1i_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1i_Sf_BFu0ll, BFu1i_Sf_BFu0ll)
//============================================================================


struct  BFu1i_Sf_BFu0s  {
  unsigned int v1:1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu1i_Sf_BFu0s) C1{ Fi:1 FC2{} Fs:0}



static void Test_BFu1i_Sf_BFu0s()
{
  {
    init_simple_test("BFu1i_Sf_BFu0s");
    static STRUCT_IF_C BFu1i_Sf_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu1i_Sf_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu1i_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1i_Sf_BFu0s");
    check_field_offset(lv, v2, 1, "BFu1i_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1i_Sf_BFu0s, BFu1i_Sf_BFu0s)
//============================================================================


struct  BFu1ll_BFu0c_Sf  {
  __tsu64 v1:1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu1ll_BFu0c_Sf) C1{ FL:1 Fc:0 FC2{}}



static void Test_BFu1ll_BFu0c_Sf()
{
  {
    init_simple_test("BFu1ll_BFu0c_Sf");
    static STRUCT_IF_C BFu1ll_BFu0c_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_BFu0c_Sf");
    check_field_offset(lv, v2, 1, "BFu1ll_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1ll_BFu0c_Sf, BFu1ll_BFu0c_Sf)
//============================================================================


struct  BFu1ll_BFu0i_Sf  {
  __tsu64 v1:1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu1ll_BFu0i_Sf) C1{ FL:1 Fi:0 FC2{}}



static void Test_BFu1ll_BFu0i_Sf()
{
  {
    init_simple_test("BFu1ll_BFu0i_Sf");
    static STRUCT_IF_C BFu1ll_BFu0i_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu1ll_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1ll_BFu0i_Sf, BFu1ll_BFu0i_Sf)
//============================================================================


struct  BFu1ll_BFu0ll_Sf  {
  __tsu64 v1:1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu1ll_BFu0ll_Sf) C1{ FL:1 FL:0 FC2{}}



static void Test_BFu1ll_BFu0ll_Sf()
{
  {
    init_simple_test("BFu1ll_BFu0ll_Sf");
    static STRUCT_IF_C BFu1ll_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu1ll_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1ll_BFu0ll_Sf, BFu1ll_BFu0ll_Sf)
//============================================================================


struct  BFu1ll_BFu0s_Sf  {
  __tsu64 v1:1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu1ll_BFu0s_Sf) C1{ FL:1 Fs:0 FC2{}}



static void Test_BFu1ll_BFu0s_Sf()
{
  {
    init_simple_test("BFu1ll_BFu0s_Sf");
    static STRUCT_IF_C BFu1ll_BFu0s_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu1ll_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1ll_BFu0s_Sf, BFu1ll_BFu0s_Sf)
//============================================================================


struct  BFu1ll_Sf_BFu0c  {
  __tsu64 v1:1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu1ll_Sf_BFu0c) C1{ FL:1 FC2{} Fc:0}



static void Test_BFu1ll_Sf_BFu0c()
{
  {
    init_simple_test("BFu1ll_Sf_BFu0c");
    static STRUCT_IF_C BFu1ll_Sf_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_Sf_BFu0c");
    check_field_offset(lv, v2, 1, "BFu1ll_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1ll_Sf_BFu0c, BFu1ll_Sf_BFu0c)
//============================================================================


struct  BFu1ll_Sf_BFu0i  {
  __tsu64 v1:1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu1ll_Sf_BFu0i) C1{ FL:1 FC2{} Fi:0}



static void Test_BFu1ll_Sf_BFu0i()
{
  {
    init_simple_test("BFu1ll_Sf_BFu0i");
    static STRUCT_IF_C BFu1ll_Sf_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_Sf_BFu0i");
    check_field_offset(lv, v2, 1, "BFu1ll_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1ll_Sf_BFu0i, BFu1ll_Sf_BFu0i)
//============================================================================


struct  BFu1ll_Sf_BFu0ll  {
  __tsu64 v1:1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu1ll_Sf_BFu0ll) C1{ FL:1 FC2{} FL:0}



static void Test_BFu1ll_Sf_BFu0ll()
{
  {
    init_simple_test("BFu1ll_Sf_BFu0ll");
    static STRUCT_IF_C BFu1ll_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_Sf_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu1ll_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1ll_Sf_BFu0ll, BFu1ll_Sf_BFu0ll)
//============================================================================


struct  BFu1ll_Sf_BFu0s  {
  __tsu64 v1:1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu1ll_Sf_BFu0s) C1{ FL:1 FC2{} Fs:0}



static void Test_BFu1ll_Sf_BFu0s()
{
  {
    init_simple_test("BFu1ll_Sf_BFu0s");
    static STRUCT_IF_C BFu1ll_Sf_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1ll_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu1ll_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1ll_Sf_BFu0s");
    check_field_offset(lv, v2, 1, "BFu1ll_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1ll_Sf_BFu0s, BFu1ll_Sf_BFu0s)
//============================================================================


struct  BFu1s_BFu0c_Sf  {
  unsigned short v1:1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu1s_BFu0c_Sf) C1{ Fs:1 Fc:0 FC2{}}



static void Test_BFu1s_BFu0c_Sf()
{
  {
    init_simple_test("BFu1s_BFu0c_Sf");
    static STRUCT_IF_C BFu1s_BFu0c_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu1s_BFu0c_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu1s_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_BFu0c_Sf");
    check_field_offset(lv, v2, 1, "BFu1s_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1s_BFu0c_Sf, BFu1s_BFu0c_Sf)
//============================================================================


struct  BFu1s_BFu0i_Sf  {
  unsigned short v1:1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu1s_BFu0i_Sf) C1{ Fs:1 Fi:0 FC2{}}



static void Test_BFu1s_BFu0i_Sf()
{
  {
    init_simple_test("BFu1s_BFu0i_Sf");
    static STRUCT_IF_C BFu1s_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu1s_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu1s_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu1s_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1s_BFu0i_Sf, BFu1s_BFu0i_Sf)
//============================================================================


struct  BFu1s_BFu0ll_Sf  {
  unsigned short v1:1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu1s_BFu0ll_Sf) C1{ Fs:1 FL:0 FC2{}}



static void Test_BFu1s_BFu0ll_Sf()
{
  {
    init_simple_test("BFu1s_BFu0ll_Sf");
    static STRUCT_IF_C BFu1s_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1s_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu1s_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu1s_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1s_BFu0ll_Sf, BFu1s_BFu0ll_Sf)
//============================================================================


struct  BFu1s_BFu0s_Sf  {
  unsigned short v1:1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu1s_BFu0s_Sf) C1{ Fs:1 Fs:0 FC2{}}



static void Test_BFu1s_BFu0s_Sf()
{
  {
    init_simple_test("BFu1s_BFu0s_Sf");
    static STRUCT_IF_C BFu1s_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu1s_BFu0s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu1s_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu1s_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1s_BFu0s_Sf, BFu1s_BFu0s_Sf)
//============================================================================


struct  BFu1s_Sf_BFu0c  {
  unsigned short v1:1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu1s_Sf_BFu0c) C1{ Fs:1 FC2{} Fc:0}



static void Test_BFu1s_Sf_BFu0c()
{
  {
    init_simple_test("BFu1s_Sf_BFu0c");
    static STRUCT_IF_C BFu1s_Sf_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(BFu1s_Sf_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(BFu1s_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_Sf_BFu0c");
    check_field_offset(lv, v2, 1, "BFu1s_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1s_Sf_BFu0c, BFu1s_Sf_BFu0c)
//============================================================================


struct  BFu1s_Sf_BFu0i  {
  unsigned short v1:1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu1s_Sf_BFu0i) C1{ Fs:1 FC2{} Fi:0}



static void Test_BFu1s_Sf_BFu0i()
{
  {
    init_simple_test("BFu1s_Sf_BFu0i");
    static STRUCT_IF_C BFu1s_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu1s_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu1s_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_Sf_BFu0i");
    check_field_offset(lv, v2, 1, "BFu1s_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1s_Sf_BFu0i, BFu1s_Sf_BFu0i)
//============================================================================


struct  BFu1s_Sf_BFu0ll  {
  unsigned short v1:1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu1s_Sf_BFu0ll) C1{ Fs:1 FC2{} FL:0}



static void Test_BFu1s_Sf_BFu0ll()
{
  {
    init_simple_test("BFu1s_Sf_BFu0ll");
    static STRUCT_IF_C BFu1s_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu1s_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu1s_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_Sf_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu1s_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1s_Sf_BFu0ll, BFu1s_Sf_BFu0ll)
//============================================================================


struct  BFu1s_Sf_BFu0s  {
  unsigned short v1:1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu1s_Sf_BFu0s) C1{ Fs:1 FC2{} Fs:0}



static void Test_BFu1s_Sf_BFu0s()
{
  {
    init_simple_test("BFu1s_Sf_BFu0s");
    static STRUCT_IF_C BFu1s_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu1s_Sf_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu1s_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 1, 1, "BFu1s_Sf_BFu0s");
    check_field_offset(lv, v2, 1, "BFu1s_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu1s_Sf_BFu0s, BFu1s_Sf_BFu0s)
//============================================================================


struct  BFu31i_BFu0c_Sf  {
  unsigned int v1:31;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu31i_BFu0c_Sf) C1{ Fi:31 Fc:0 FC2{}}



static void Test_BFu31i_BFu0c_Sf()
{
  {
    init_simple_test("BFu31i_BFu0c_Sf");
    static STRUCT_IF_C BFu31i_BFu0c_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu31i_BFu0c_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_BFu0c_Sf");
    check_field_offset(lv, v2, 4, "BFu31i_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31i_BFu0c_Sf, BFu31i_BFu0c_Sf)
//============================================================================


struct  BFu31i_BFu0i_Sf  {
  unsigned int v1:31;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu31i_BFu0i_Sf) C1{ Fi:31 Fi:0 FC2{}}



static void Test_BFu31i_BFu0i_Sf()
{
  {
    init_simple_test("BFu31i_BFu0i_Sf");
    static STRUCT_IF_C BFu31i_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu31i_BFu0i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu31i_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31i_BFu0i_Sf, BFu31i_BFu0i_Sf)
//============================================================================


struct  BFu31i_BFu0ll_Sf  {
  unsigned int v1:31;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu31i_BFu0ll_Sf) C1{ Fi:31 FL:0 FC2{}}



static void Test_BFu31i_BFu0ll_Sf()
{
  {
    init_simple_test("BFu31i_BFu0ll_Sf");
    static STRUCT_IF_C BFu31i_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu31i_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu31i_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu31i_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31i_BFu0ll_Sf, BFu31i_BFu0ll_Sf)
//============================================================================


struct  BFu31i_BFu0s_Sf  {
  unsigned int v1:31;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu31i_BFu0s_Sf) C1{ Fi:31 Fs:0 FC2{}}



static void Test_BFu31i_BFu0s_Sf()
{
  {
    init_simple_test("BFu31i_BFu0s_Sf");
    static STRUCT_IF_C BFu31i_BFu0s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu31i_BFu0s_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_BFu0s_Sf");
    check_field_offset(lv, v2, 4, "BFu31i_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31i_BFu0s_Sf, BFu31i_BFu0s_Sf)
//============================================================================


struct  BFu31i_Sf_BFu0c  {
  unsigned int v1:31;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu31i_Sf_BFu0c) C1{ Fi:31 FC2{} Fc:0}



static void Test_BFu31i_Sf_BFu0c()
{
  {
    init_simple_test("BFu31i_Sf_BFu0c");
    static STRUCT_IF_C BFu31i_Sf_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu31i_Sf_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_Sf_BFu0c");
    check_field_offset(lv, v2, 4, "BFu31i_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31i_Sf_BFu0c, BFu31i_Sf_BFu0c)
//============================================================================


struct  BFu31i_Sf_BFu0i  {
  unsigned int v1:31;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu31i_Sf_BFu0i) C1{ Fi:31 FC2{} Fi:0}



static void Test_BFu31i_Sf_BFu0i()
{
  {
    init_simple_test("BFu31i_Sf_BFu0i");
    static STRUCT_IF_C BFu31i_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu31i_Sf_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_Sf_BFu0i");
    check_field_offset(lv, v2, 4, "BFu31i_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31i_Sf_BFu0i, BFu31i_Sf_BFu0i)
//============================================================================


struct  BFu31i_Sf_BFu0ll  {
  unsigned int v1:31;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu31i_Sf_BFu0ll) C1{ Fi:31 FC2{} FL:0}



static void Test_BFu31i_Sf_BFu0ll()
{
  {
    init_simple_test("BFu31i_Sf_BFu0ll");
    static STRUCT_IF_C BFu31i_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu31i_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu31i_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_Sf_BFu0ll");
    check_field_offset(lv, v2, 4, "BFu31i_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31i_Sf_BFu0ll, BFu31i_Sf_BFu0ll)
//============================================================================


struct  BFu31i_Sf_BFu0s  {
  unsigned int v1:31;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu31i_Sf_BFu0s) C1{ Fi:31 FC2{} Fs:0}



static void Test_BFu31i_Sf_BFu0s()
{
  {
    init_simple_test("BFu31i_Sf_BFu0s");
    static STRUCT_IF_C BFu31i_Sf_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu31i_Sf_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu31i_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31i_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31i_Sf_BFu0s");
    check_field_offset(lv, v2, 4, "BFu31i_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31i_Sf_BFu0s, BFu31i_Sf_BFu0s)
//============================================================================


struct  BFu31ll_BFu0c_Sf  {
  __tsu64 v1:31;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu31ll_BFu0c_Sf) C1{ FL:31 Fc:0 FC2{}}



static void Test_BFu31ll_BFu0c_Sf()
{
  {
    init_simple_test("BFu31ll_BFu0c_Sf");
    static STRUCT_IF_C BFu31ll_BFu0c_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu31ll_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_BFu0c_Sf");
    check_field_offset(lv, v2, 4, "BFu31ll_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31ll_BFu0c_Sf, BFu31ll_BFu0c_Sf)
//============================================================================


struct  BFu31ll_BFu0i_Sf  {
  __tsu64 v1:31;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu31ll_BFu0i_Sf) C1{ FL:31 Fi:0 FC2{}}



static void Test_BFu31ll_BFu0i_Sf()
{
  {
    init_simple_test("BFu31ll_BFu0i_Sf");
    static STRUCT_IF_C BFu31ll_BFu0i_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu31ll_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu31ll_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31ll_BFu0i_Sf, BFu31ll_BFu0i_Sf)
//============================================================================


struct  BFu31ll_BFu0ll_Sf  {
  __tsu64 v1:31;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu31ll_BFu0ll_Sf) C1{ FL:31 FL:0 FC2{}}



static void Test_BFu31ll_BFu0ll_Sf()
{
  {
    init_simple_test("BFu31ll_BFu0ll_Sf");
    static STRUCT_IF_C BFu31ll_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu31ll_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu31ll_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31ll_BFu0ll_Sf, BFu31ll_BFu0ll_Sf)
//============================================================================


struct  BFu31ll_BFu0s_Sf  {
  __tsu64 v1:31;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu31ll_BFu0s_Sf) C1{ FL:31 Fs:0 FC2{}}



static void Test_BFu31ll_BFu0s_Sf()
{
  {
    init_simple_test("BFu31ll_BFu0s_Sf");
    static STRUCT_IF_C BFu31ll_BFu0s_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu31ll_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_BFu0s_Sf");
    check_field_offset(lv, v2, 4, "BFu31ll_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31ll_BFu0s_Sf, BFu31ll_BFu0s_Sf)
//============================================================================


struct  BFu31ll_Sf_BFu0c  {
  __tsu64 v1:31;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu31ll_Sf_BFu0c) C1{ FL:31 FC2{} Fc:0}



static void Test_BFu31ll_Sf_BFu0c()
{
  {
    init_simple_test("BFu31ll_Sf_BFu0c");
    static STRUCT_IF_C BFu31ll_Sf_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu31ll_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_Sf_BFu0c");
    check_field_offset(lv, v2, 4, "BFu31ll_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31ll_Sf_BFu0c, BFu31ll_Sf_BFu0c)
//============================================================================


struct  BFu31ll_Sf_BFu0i  {
  __tsu64 v1:31;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu31ll_Sf_BFu0i) C1{ FL:31 FC2{} Fi:0}



static void Test_BFu31ll_Sf_BFu0i()
{
  {
    init_simple_test("BFu31ll_Sf_BFu0i");
    static STRUCT_IF_C BFu31ll_Sf_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu31ll_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_Sf_BFu0i");
    check_field_offset(lv, v2, 4, "BFu31ll_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31ll_Sf_BFu0i, BFu31ll_Sf_BFu0i)
//============================================================================


struct  BFu31ll_Sf_BFu0ll  {
  __tsu64 v1:31;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu31ll_Sf_BFu0ll) C1{ FL:31 FC2{} FL:0}



static void Test_BFu31ll_Sf_BFu0ll()
{
  {
    init_simple_test("BFu31ll_Sf_BFu0ll");
    static STRUCT_IF_C BFu31ll_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu31ll_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_Sf_BFu0ll");
    check_field_offset(lv, v2, 4, "BFu31ll_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31ll_Sf_BFu0ll, BFu31ll_Sf_BFu0ll)
//============================================================================


struct  BFu31ll_Sf_BFu0s  {
  __tsu64 v1:31;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu31ll_Sf_BFu0s) C1{ FL:31 FC2{} Fs:0}



static void Test_BFu31ll_Sf_BFu0s()
{
  {
    init_simple_test("BFu31ll_Sf_BFu0s");
    static STRUCT_IF_C BFu31ll_Sf_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu31ll_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu31ll_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 31, 1, "BFu31ll_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 31, hide_ull(1LL<<30), "BFu31ll_Sf_BFu0s");
    check_field_offset(lv, v2, 4, "BFu31ll_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu31ll_Sf_BFu0s, BFu31ll_Sf_BFu0s)
//============================================================================


struct  BFu32i_BFu0c_Sf  {
  unsigned int v1:32;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu32i_BFu0c_Sf) C1{ Fi:32 Fc:0 FC2{}}



static void Test_BFu32i_BFu0c_Sf()
{
  {
    init_simple_test("BFu32i_BFu0c_Sf");
    static STRUCT_IF_C BFu32i_BFu0c_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu32i_BFu0c_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_BFu0c_Sf");
    check_field_offset(lv, v2, 4, "BFu32i_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32i_BFu0c_Sf, BFu32i_BFu0c_Sf)
//============================================================================


struct  BFu32i_BFu0i_Sf  {
  unsigned int v1:32;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu32i_BFu0i_Sf) C1{ Fi:32 Fi:0 FC2{}}



static void Test_BFu32i_BFu0i_Sf()
{
  {
    init_simple_test("BFu32i_BFu0i_Sf");
    static STRUCT_IF_C BFu32i_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu32i_BFu0i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu32i_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32i_BFu0i_Sf, BFu32i_BFu0i_Sf)
//============================================================================


struct  BFu32i_BFu0ll_Sf  {
  unsigned int v1:32;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu32i_BFu0ll_Sf) C1{ Fi:32 FL:0 FC2{}}



static void Test_BFu32i_BFu0ll_Sf()
{
  {
    init_simple_test("BFu32i_BFu0ll_Sf");
    static STRUCT_IF_C BFu32i_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu32i_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu32i_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu32i_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32i_BFu0ll_Sf, BFu32i_BFu0ll_Sf)
//============================================================================


struct  BFu32i_BFu0s_Sf  {
  unsigned int v1:32;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu32i_BFu0s_Sf) C1{ Fi:32 Fs:0 FC2{}}



static void Test_BFu32i_BFu0s_Sf()
{
  {
    init_simple_test("BFu32i_BFu0s_Sf");
    static STRUCT_IF_C BFu32i_BFu0s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu32i_BFu0s_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_BFu0s_Sf");
    check_field_offset(lv, v2, 4, "BFu32i_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32i_BFu0s_Sf, BFu32i_BFu0s_Sf)
//============================================================================


struct  BFu32i_Sf_BFu0c  {
  unsigned int v1:32;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu32i_Sf_BFu0c) C1{ Fi:32 FC2{} Fc:0}



static void Test_BFu32i_Sf_BFu0c()
{
  {
    init_simple_test("BFu32i_Sf_BFu0c");
    static STRUCT_IF_C BFu32i_Sf_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu32i_Sf_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_Sf_BFu0c");
    check_field_offset(lv, v2, 4, "BFu32i_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32i_Sf_BFu0c, BFu32i_Sf_BFu0c)
//============================================================================


struct  BFu32i_Sf_BFu0i  {
  unsigned int v1:32;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu32i_Sf_BFu0i) C1{ Fi:32 FC2{} Fi:0}



static void Test_BFu32i_Sf_BFu0i()
{
  {
    init_simple_test("BFu32i_Sf_BFu0i");
    static STRUCT_IF_C BFu32i_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu32i_Sf_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_Sf_BFu0i");
    check_field_offset(lv, v2, 4, "BFu32i_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32i_Sf_BFu0i, BFu32i_Sf_BFu0i)
//============================================================================


struct  BFu32i_Sf_BFu0ll  {
  unsigned int v1:32;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu32i_Sf_BFu0ll) C1{ Fi:32 FC2{} FL:0}



static void Test_BFu32i_Sf_BFu0ll()
{
  {
    init_simple_test("BFu32i_Sf_BFu0ll");
    static STRUCT_IF_C BFu32i_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu32i_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu32i_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_Sf_BFu0ll");
    check_field_offset(lv, v2, 4, "BFu32i_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32i_Sf_BFu0ll, BFu32i_Sf_BFu0ll)
//============================================================================


struct  BFu32i_Sf_BFu0s  {
  unsigned int v1:32;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu32i_Sf_BFu0s) C1{ Fi:32 FC2{} Fs:0}



static void Test_BFu32i_Sf_BFu0s()
{
  {
    init_simple_test("BFu32i_Sf_BFu0s");
    static STRUCT_IF_C BFu32i_Sf_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu32i_Sf_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu32i_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32i_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32i_Sf_BFu0s");
    check_field_offset(lv, v2, 4, "BFu32i_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32i_Sf_BFu0s, BFu32i_Sf_BFu0s)
//============================================================================


struct  BFu32ll_BFu0c_Sf  {
  __tsu64 v1:32;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu32ll_BFu0c_Sf) C1{ FL:32 Fc:0 FC2{}}



static void Test_BFu32ll_BFu0c_Sf()
{
  {
    init_simple_test("BFu32ll_BFu0c_Sf");
    static STRUCT_IF_C BFu32ll_BFu0c_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu32ll_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_BFu0c_Sf");
    check_field_offset(lv, v2, 4, "BFu32ll_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32ll_BFu0c_Sf, BFu32ll_BFu0c_Sf)
//============================================================================


struct  BFu32ll_BFu0i_Sf  {
  __tsu64 v1:32;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu32ll_BFu0i_Sf) C1{ FL:32 Fi:0 FC2{}}



static void Test_BFu32ll_BFu0i_Sf()
{
  {
    init_simple_test("BFu32ll_BFu0i_Sf");
    static STRUCT_IF_C BFu32ll_BFu0i_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu32ll_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu32ll_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32ll_BFu0i_Sf, BFu32ll_BFu0i_Sf)
//============================================================================


struct  BFu32ll_BFu0ll_Sf  {
  __tsu64 v1:32;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu32ll_BFu0ll_Sf) C1{ FL:32 FL:0 FC2{}}



static void Test_BFu32ll_BFu0ll_Sf()
{
  {
    init_simple_test("BFu32ll_BFu0ll_Sf");
    static STRUCT_IF_C BFu32ll_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu32ll_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu32ll_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32ll_BFu0ll_Sf, BFu32ll_BFu0ll_Sf)
//============================================================================


struct  BFu32ll_BFu0s_Sf  {
  __tsu64 v1:32;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu32ll_BFu0s_Sf) C1{ FL:32 Fs:0 FC2{}}



static void Test_BFu32ll_BFu0s_Sf()
{
  {
    init_simple_test("BFu32ll_BFu0s_Sf");
    static STRUCT_IF_C BFu32ll_BFu0s_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu32ll_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_BFu0s_Sf");
    check_field_offset(lv, v2, 4, "BFu32ll_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32ll_BFu0s_Sf, BFu32ll_BFu0s_Sf)
//============================================================================


struct  BFu32ll_Sf_BFu0c  {
  __tsu64 v1:32;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu32ll_Sf_BFu0c) C1{ FL:32 FC2{} Fc:0}



static void Test_BFu32ll_Sf_BFu0c()
{
  {
    init_simple_test("BFu32ll_Sf_BFu0c");
    static STRUCT_IF_C BFu32ll_Sf_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu32ll_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_Sf_BFu0c");
    check_field_offset(lv, v2, 4, "BFu32ll_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32ll_Sf_BFu0c, BFu32ll_Sf_BFu0c)
//============================================================================


struct  BFu32ll_Sf_BFu0i  {
  __tsu64 v1:32;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu32ll_Sf_BFu0i) C1{ FL:32 FC2{} Fi:0}



static void Test_BFu32ll_Sf_BFu0i()
{
  {
    init_simple_test("BFu32ll_Sf_BFu0i");
    static STRUCT_IF_C BFu32ll_Sf_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu32ll_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_Sf_BFu0i");
    check_field_offset(lv, v2, 4, "BFu32ll_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32ll_Sf_BFu0i, BFu32ll_Sf_BFu0i)
//============================================================================


struct  BFu32ll_Sf_BFu0ll  {
  __tsu64 v1:32;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu32ll_Sf_BFu0ll) C1{ FL:32 FC2{} FL:0}



static void Test_BFu32ll_Sf_BFu0ll()
{
  {
    init_simple_test("BFu32ll_Sf_BFu0ll");
    static STRUCT_IF_C BFu32ll_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu32ll_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_Sf_BFu0ll");
    check_field_offset(lv, v2, 4, "BFu32ll_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32ll_Sf_BFu0ll, BFu32ll_Sf_BFu0ll)
//============================================================================


struct  BFu32ll_Sf_BFu0s  {
  __tsu64 v1:32;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu32ll_Sf_BFu0s) C1{ FL:32 FC2{} Fs:0}



static void Test_BFu32ll_Sf_BFu0s()
{
  {
    init_simple_test("BFu32ll_Sf_BFu0s");
    static STRUCT_IF_C BFu32ll_Sf_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu32ll_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu32ll_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 32, 1, "BFu32ll_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 32, hide_ull(1LL<<31), "BFu32ll_Sf_BFu0s");
    check_field_offset(lv, v2, 4, "BFu32ll_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu32ll_Sf_BFu0s, BFu32ll_Sf_BFu0s)
//============================================================================


struct  BFu33_BFu0c_Sf  {
  __tsu64 v1:33;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu33_BFu0c_Sf) C1{ FL:33 Fc:0 FC2{}}



static void Test_BFu33_BFu0c_Sf()
{
  {
    init_simple_test("BFu33_BFu0c_Sf");
    static STRUCT_IF_C BFu33_BFu0c_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_BFu0c_Sf");
    check_field_offset(lv, v2, 5, "BFu33_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu33_BFu0c_Sf, BFu33_BFu0c_Sf)
//============================================================================


struct  BFu33_BFu0i_Sf  {
  __tsu64 v1:33;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu33_BFu0i_Sf) C1{ FL:33 Fi:0 FC2{}}



static void Test_BFu33_BFu0i_Sf()
{
  {
    init_simple_test("BFu33_BFu0i_Sf");
    static STRUCT_IF_C BFu33_BFu0i_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_BFu0i_Sf");
    check_field_offset(lv, v2, 8, "BFu33_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu33_BFu0i_Sf, BFu33_BFu0i_Sf)
//============================================================================


struct  BFu33_BFu0ll_Sf  {
  __tsu64 v1:33;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu33_BFu0ll_Sf) C1{ FL:33 FL:0 FC2{}}



static void Test_BFu33_BFu0ll_Sf()
{
  {
    init_simple_test("BFu33_BFu0ll_Sf");
    static STRUCT_IF_C BFu33_BFu0ll_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_BFu0ll_Sf");
    check_field_offset(lv, v2, 8, "BFu33_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu33_BFu0ll_Sf, BFu33_BFu0ll_Sf)
//============================================================================


struct  BFu33_BFu0s_Sf  {
  __tsu64 v1:33;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu33_BFu0s_Sf) C1{ FL:33 Fs:0 FC2{}}



static void Test_BFu33_BFu0s_Sf()
{
  {
    init_simple_test("BFu33_BFu0s_Sf");
    static STRUCT_IF_C BFu33_BFu0s_Sf lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_BFu0s_Sf");
    check_field_offset(lv, v2, 6, "BFu33_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu33_BFu0s_Sf, BFu33_BFu0s_Sf)
//============================================================================


struct  BFu33_Sf_BFu0c  {
  __tsu64 v1:33;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu33_Sf_BFu0c) C1{ FL:33 FC2{} Fc:0}



static void Test_BFu33_Sf_BFu0c()
{
  {
    init_simple_test("BFu33_Sf_BFu0c");
    static STRUCT_IF_C BFu33_Sf_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_Sf_BFu0c");
    check_field_offset(lv, v2, 5, "BFu33_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu33_Sf_BFu0c, BFu33_Sf_BFu0c)
//============================================================================


struct  BFu33_Sf_BFu0i  {
  __tsu64 v1:33;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu33_Sf_BFu0i) C1{ FL:33 FC2{} Fi:0}



static void Test_BFu33_Sf_BFu0i()
{
  {
    init_simple_test("BFu33_Sf_BFu0i");
    static STRUCT_IF_C BFu33_Sf_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_Sf_BFu0i");
    check_field_offset(lv, v2, 5, "BFu33_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu33_Sf_BFu0i, BFu33_Sf_BFu0i)
//============================================================================


struct  BFu33_Sf_BFu0ll  {
  __tsu64 v1:33;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu33_Sf_BFu0ll) C1{ FL:33 FC2{} FL:0}



static void Test_BFu33_Sf_BFu0ll()
{
  {
    init_simple_test("BFu33_Sf_BFu0ll");
    static STRUCT_IF_C BFu33_Sf_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_Sf_BFu0ll");
    check_field_offset(lv, v2, 5, "BFu33_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu33_Sf_BFu0ll, BFu33_Sf_BFu0ll)
//============================================================================


struct  BFu33_Sf_BFu0s  {
  __tsu64 v1:33;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu33_Sf_BFu0s) C1{ FL:33 FC2{} Fs:0}



static void Test_BFu33_Sf_BFu0s()
{
  {
    init_simple_test("BFu33_Sf_BFu0s");
    static STRUCT_IF_C BFu33_Sf_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(BFu33_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu33_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 33, 1, "BFu33_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 33, hide_ull(1LL<<32), "BFu33_Sf_BFu0s");
    check_field_offset(lv, v2, 5, "BFu33_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu33_Sf_BFu0s, BFu33_Sf_BFu0s)
//============================================================================


struct  BFu7c_BFu0c_Sf  {
  unsigned char v1:7;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu7c_BFu0c_Sf) C1{ Fc:7 Fc:0 FC2{}}



static void Test_BFu7c_BFu0c_Sf()
{
  {
    init_simple_test("BFu7c_BFu0c_Sf");
    static STRUCT_IF_C BFu7c_BFu0c_Sf lv;
    check2(sizeof(lv), 1, "sizeof(BFu7c_BFu0c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7c_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_BFu0c_Sf");
    check_field_offset(lv, v2, 1, "BFu7c_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7c_BFu0c_Sf, BFu7c_BFu0c_Sf)
//============================================================================


struct  BFu7c_BFu0i_Sf  {
  unsigned char v1:7;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu7c_BFu0i_Sf) C1{ Fc:7 Fi:0 FC2{}}



static void Test_BFu7c_BFu0i_Sf()
{
  {
    init_simple_test("BFu7c_BFu0i_Sf");
    static STRUCT_IF_C BFu7c_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu7c_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu7c_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu7c_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7c_BFu0i_Sf, BFu7c_BFu0i_Sf)
//============================================================================


struct  BFu7c_BFu0ll_Sf  {
  unsigned char v1:7;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu7c_BFu0ll_Sf) C1{ Fc:7 FL:0 FC2{}}



static void Test_BFu7c_BFu0ll_Sf()
{
  {
    init_simple_test("BFu7c_BFu0ll_Sf");
    static STRUCT_IF_C BFu7c_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7c_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu7c_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu7c_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7c_BFu0ll_Sf, BFu7c_BFu0ll_Sf)
//============================================================================


struct  BFu7c_BFu0s_Sf  {
  unsigned char v1:7;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu7c_BFu0s_Sf) C1{ Fc:7 Fs:0 FC2{}}



static void Test_BFu7c_BFu0s_Sf()
{
  {
    init_simple_test("BFu7c_BFu0s_Sf");
    static STRUCT_IF_C BFu7c_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu7c_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu7c_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu7c_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7c_BFu0s_Sf, BFu7c_BFu0s_Sf)
//============================================================================


struct  BFu7c_Sf_BFu0c  {
  unsigned char v1:7;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu7c_Sf_BFu0c) C1{ Fc:7 FC2{} Fc:0}



static void Test_BFu7c_Sf_BFu0c()
{
  {
    init_simple_test("BFu7c_Sf_BFu0c");
    static STRUCT_IF_C BFu7c_Sf_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(BFu7c_Sf_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu7c_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_Sf_BFu0c");
    check_field_offset(lv, v2, 1, "BFu7c_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7c_Sf_BFu0c, BFu7c_Sf_BFu0c)
//============================================================================


struct  BFu7c_Sf_BFu0i  {
  unsigned char v1:7;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu7c_Sf_BFu0i) C1{ Fc:7 FC2{} Fi:0}



static void Test_BFu7c_Sf_BFu0i()
{
  {
    init_simple_test("BFu7c_Sf_BFu0i");
    static STRUCT_IF_C BFu7c_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu7c_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu7c_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_Sf_BFu0i");
    check_field_offset(lv, v2, 1, "BFu7c_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7c_Sf_BFu0i, BFu7c_Sf_BFu0i)
//============================================================================


struct  BFu7c_Sf_BFu0ll  {
  unsigned char v1:7;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu7c_Sf_BFu0ll) C1{ Fc:7 FC2{} FL:0}



static void Test_BFu7c_Sf_BFu0ll()
{
  {
    init_simple_test("BFu7c_Sf_BFu0ll");
    static STRUCT_IF_C BFu7c_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7c_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu7c_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_Sf_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu7c_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7c_Sf_BFu0ll, BFu7c_Sf_BFu0ll)
//============================================================================


struct  BFu7c_Sf_BFu0s  {
  unsigned char v1:7;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu7c_Sf_BFu0s) C1{ Fc:7 FC2{} Fs:0}



static void Test_BFu7c_Sf_BFu0s()
{
  {
    init_simple_test("BFu7c_Sf_BFu0s");
    static STRUCT_IF_C BFu7c_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu7c_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu7c_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7c_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7c_Sf_BFu0s");
    check_field_offset(lv, v2, 1, "BFu7c_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7c_Sf_BFu0s, BFu7c_Sf_BFu0s)
//============================================================================


struct  BFu7i_BFu0c_Sf  {
  unsigned int v1:7;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu7i_BFu0c_Sf) C1{ Fi:7 Fc:0 FC2{}}



static void Test_BFu7i_BFu0c_Sf()
{
  {
    init_simple_test("BFu7i_BFu0c_Sf");
    static STRUCT_IF_C BFu7i_BFu0c_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_BFu0c_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_BFu0c_Sf");
    check_field_offset(lv, v2, 1, "BFu7i_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7i_BFu0c_Sf, BFu7i_BFu0c_Sf)
//============================================================================


struct  BFu7i_BFu0i_Sf  {
  unsigned int v1:7;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu7i_BFu0i_Sf) C1{ Fi:7 Fi:0 FC2{}}



static void Test_BFu7i_BFu0i_Sf()
{
  {
    init_simple_test("BFu7i_BFu0i_Sf");
    static STRUCT_IF_C BFu7i_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_BFu0i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu7i_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7i_BFu0i_Sf, BFu7i_BFu0i_Sf)
//============================================================================


struct  BFu7i_BFu0ll_Sf  {
  unsigned int v1:7;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu7i_BFu0ll_Sf) C1{ Fi:7 FL:0 FC2{}}



static void Test_BFu7i_BFu0ll_Sf()
{
  {
    init_simple_test("BFu7i_BFu0ll_Sf");
    static STRUCT_IF_C BFu7i_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7i_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu7i_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu7i_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7i_BFu0ll_Sf, BFu7i_BFu0ll_Sf)
//============================================================================


struct  BFu7i_BFu0s_Sf  {
  unsigned int v1:7;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu7i_BFu0s_Sf) C1{ Fi:7 Fs:0 FC2{}}



static void Test_BFu7i_BFu0s_Sf()
{
  {
    init_simple_test("BFu7i_BFu0s_Sf");
    static STRUCT_IF_C BFu7i_BFu0s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_BFu0s_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu7i_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7i_BFu0s_Sf, BFu7i_BFu0s_Sf)
//============================================================================


struct  BFu7i_Sf_BFu0c  {
  unsigned int v1:7;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu7i_Sf_BFu0c) C1{ Fi:7 FC2{} Fc:0}



static void Test_BFu7i_Sf_BFu0c()
{
  {
    init_simple_test("BFu7i_Sf_BFu0c");
    static STRUCT_IF_C BFu7i_Sf_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_Sf_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_Sf_BFu0c");
    check_field_offset(lv, v2, 1, "BFu7i_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7i_Sf_BFu0c, BFu7i_Sf_BFu0c)
//============================================================================


struct  BFu7i_Sf_BFu0i  {
  unsigned int v1:7;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu7i_Sf_BFu0i) C1{ Fi:7 FC2{} Fi:0}



static void Test_BFu7i_Sf_BFu0i()
{
  {
    init_simple_test("BFu7i_Sf_BFu0i");
    static STRUCT_IF_C BFu7i_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_Sf_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_Sf_BFu0i");
    check_field_offset(lv, v2, 1, "BFu7i_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7i_Sf_BFu0i, BFu7i_Sf_BFu0i)
//============================================================================


struct  BFu7i_Sf_BFu0ll  {
  unsigned int v1:7;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu7i_Sf_BFu0ll) C1{ Fi:7 FC2{} FL:0}



static void Test_BFu7i_Sf_BFu0ll()
{
  {
    init_simple_test("BFu7i_Sf_BFu0ll");
    static STRUCT_IF_C BFu7i_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7i_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu7i_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_Sf_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu7i_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7i_Sf_BFu0ll, BFu7i_Sf_BFu0ll)
//============================================================================


struct  BFu7i_Sf_BFu0s  {
  unsigned int v1:7;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu7i_Sf_BFu0s) C1{ Fi:7 FC2{} Fs:0}



static void Test_BFu7i_Sf_BFu0s()
{
  {
    init_simple_test("BFu7i_Sf_BFu0s");
    static STRUCT_IF_C BFu7i_Sf_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu7i_Sf_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu7i_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7i_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7i_Sf_BFu0s");
    check_field_offset(lv, v2, 1, "BFu7i_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7i_Sf_BFu0s, BFu7i_Sf_BFu0s)
//============================================================================


struct  BFu7ll_BFu0c_Sf  {
  __tsu64 v1:7;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu7ll_BFu0c_Sf) C1{ FL:7 Fc:0 FC2{}}



static void Test_BFu7ll_BFu0c_Sf()
{
  {
    init_simple_test("BFu7ll_BFu0c_Sf");
    static STRUCT_IF_C BFu7ll_BFu0c_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_BFu0c_Sf");
    check_field_offset(lv, v2, 1, "BFu7ll_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7ll_BFu0c_Sf, BFu7ll_BFu0c_Sf)
//============================================================================


struct  BFu7ll_BFu0i_Sf  {
  __tsu64 v1:7;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu7ll_BFu0i_Sf) C1{ FL:7 Fi:0 FC2{}}



static void Test_BFu7ll_BFu0i_Sf()
{
  {
    init_simple_test("BFu7ll_BFu0i_Sf");
    static STRUCT_IF_C BFu7ll_BFu0i_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu7ll_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7ll_BFu0i_Sf, BFu7ll_BFu0i_Sf)
//============================================================================


struct  BFu7ll_BFu0ll_Sf  {
  __tsu64 v1:7;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu7ll_BFu0ll_Sf) C1{ FL:7 FL:0 FC2{}}



static void Test_BFu7ll_BFu0ll_Sf()
{
  {
    init_simple_test("BFu7ll_BFu0ll_Sf");
    static STRUCT_IF_C BFu7ll_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu7ll_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7ll_BFu0ll_Sf, BFu7ll_BFu0ll_Sf)
//============================================================================


struct  BFu7ll_BFu0s_Sf  {
  __tsu64 v1:7;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu7ll_BFu0s_Sf) C1{ FL:7 Fs:0 FC2{}}



static void Test_BFu7ll_BFu0s_Sf()
{
  {
    init_simple_test("BFu7ll_BFu0s_Sf");
    static STRUCT_IF_C BFu7ll_BFu0s_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu7ll_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7ll_BFu0s_Sf, BFu7ll_BFu0s_Sf)
//============================================================================


struct  BFu7ll_Sf_BFu0c  {
  __tsu64 v1:7;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu7ll_Sf_BFu0c) C1{ FL:7 FC2{} Fc:0}



static void Test_BFu7ll_Sf_BFu0c()
{
  {
    init_simple_test("BFu7ll_Sf_BFu0c");
    static STRUCT_IF_C BFu7ll_Sf_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_Sf_BFu0c");
    check_field_offset(lv, v2, 1, "BFu7ll_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7ll_Sf_BFu0c, BFu7ll_Sf_BFu0c)
//============================================================================


struct  BFu7ll_Sf_BFu0i  {
  __tsu64 v1:7;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu7ll_Sf_BFu0i) C1{ FL:7 FC2{} Fi:0}



static void Test_BFu7ll_Sf_BFu0i()
{
  {
    init_simple_test("BFu7ll_Sf_BFu0i");
    static STRUCT_IF_C BFu7ll_Sf_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_Sf_BFu0i");
    check_field_offset(lv, v2, 1, "BFu7ll_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7ll_Sf_BFu0i, BFu7ll_Sf_BFu0i)
//============================================================================


struct  BFu7ll_Sf_BFu0ll  {
  __tsu64 v1:7;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu7ll_Sf_BFu0ll) C1{ FL:7 FC2{} FL:0}



static void Test_BFu7ll_Sf_BFu0ll()
{
  {
    init_simple_test("BFu7ll_Sf_BFu0ll");
    static STRUCT_IF_C BFu7ll_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_Sf_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu7ll_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7ll_Sf_BFu0ll, BFu7ll_Sf_BFu0ll)
//============================================================================


struct  BFu7ll_Sf_BFu0s  {
  __tsu64 v1:7;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu7ll_Sf_BFu0s) C1{ FL:7 FC2{} Fs:0}



static void Test_BFu7ll_Sf_BFu0s()
{
  {
    init_simple_test("BFu7ll_Sf_BFu0s");
    static STRUCT_IF_C BFu7ll_Sf_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7ll_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu7ll_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7ll_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7ll_Sf_BFu0s");
    check_field_offset(lv, v2, 1, "BFu7ll_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7ll_Sf_BFu0s, BFu7ll_Sf_BFu0s)
//============================================================================


struct  BFu7s_BFu0c_Sf  {
  unsigned short v1:7;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu7s_BFu0c_Sf) C1{ Fs:7 Fc:0 FC2{}}



static void Test_BFu7s_BFu0c_Sf()
{
  {
    init_simple_test("BFu7s_BFu0c_Sf");
    static STRUCT_IF_C BFu7s_BFu0c_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu7s_BFu0c_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu7s_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_BFu0c_Sf");
    check_field_offset(lv, v2, 1, "BFu7s_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7s_BFu0c_Sf, BFu7s_BFu0c_Sf)
//============================================================================


struct  BFu7s_BFu0i_Sf  {
  unsigned short v1:7;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu7s_BFu0i_Sf) C1{ Fs:7 Fi:0 FC2{}}



static void Test_BFu7s_BFu0i_Sf()
{
  {
    init_simple_test("BFu7s_BFu0i_Sf");
    static STRUCT_IF_C BFu7s_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu7s_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu7s_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu7s_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7s_BFu0i_Sf, BFu7s_BFu0i_Sf)
//============================================================================


struct  BFu7s_BFu0ll_Sf  {
  unsigned short v1:7;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu7s_BFu0ll_Sf) C1{ Fs:7 FL:0 FC2{}}



static void Test_BFu7s_BFu0ll_Sf()
{
  {
    init_simple_test("BFu7s_BFu0ll_Sf");
    static STRUCT_IF_C BFu7s_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7s_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu7s_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu7s_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7s_BFu0ll_Sf, BFu7s_BFu0ll_Sf)
//============================================================================


struct  BFu7s_BFu0s_Sf  {
  unsigned short v1:7;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu7s_BFu0s_Sf) C1{ Fs:7 Fs:0 FC2{}}



static void Test_BFu7s_BFu0s_Sf()
{
  {
    init_simple_test("BFu7s_BFu0s_Sf");
    static STRUCT_IF_C BFu7s_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu7s_BFu0s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu7s_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu7s_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7s_BFu0s_Sf, BFu7s_BFu0s_Sf)
//============================================================================


struct  BFu7s_Sf_BFu0c  {
  unsigned short v1:7;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu7s_Sf_BFu0c) C1{ Fs:7 FC2{} Fc:0}



static void Test_BFu7s_Sf_BFu0c()
{
  {
    init_simple_test("BFu7s_Sf_BFu0c");
    static STRUCT_IF_C BFu7s_Sf_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(BFu7s_Sf_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(BFu7s_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_Sf_BFu0c");
    check_field_offset(lv, v2, 1, "BFu7s_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7s_Sf_BFu0c, BFu7s_Sf_BFu0c)
//============================================================================


struct  BFu7s_Sf_BFu0i  {
  unsigned short v1:7;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu7s_Sf_BFu0i) C1{ Fs:7 FC2{} Fi:0}



static void Test_BFu7s_Sf_BFu0i()
{
  {
    init_simple_test("BFu7s_Sf_BFu0i");
    static STRUCT_IF_C BFu7s_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu7s_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu7s_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_Sf_BFu0i");
    check_field_offset(lv, v2, 1, "BFu7s_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7s_Sf_BFu0i, BFu7s_Sf_BFu0i)
//============================================================================


struct  BFu7s_Sf_BFu0ll  {
  unsigned short v1:7;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu7s_Sf_BFu0ll) C1{ Fs:7 FC2{} FL:0}



static void Test_BFu7s_Sf_BFu0ll()
{
  {
    init_simple_test("BFu7s_Sf_BFu0ll");
    static STRUCT_IF_C BFu7s_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu7s_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu7s_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_Sf_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu7s_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7s_Sf_BFu0ll, BFu7s_Sf_BFu0ll)
//============================================================================


struct  BFu7s_Sf_BFu0s  {
  unsigned short v1:7;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu7s_Sf_BFu0s) C1{ Fs:7 FC2{} Fs:0}



static void Test_BFu7s_Sf_BFu0s()
{
  {
    init_simple_test("BFu7s_Sf_BFu0s");
    static STRUCT_IF_C BFu7s_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu7s_Sf_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu7s_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 7, 1, "BFu7s_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 7, hide_ull(1LL<<6), "BFu7s_Sf_BFu0s");
    check_field_offset(lv, v2, 1, "BFu7s_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu7s_Sf_BFu0s, BFu7s_Sf_BFu0s)
//============================================================================


struct  BFu8c_BFu0c_Sf  {
  unsigned char v1:8;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu8c_BFu0c_Sf) C1{ Fc:8 Fc:0 FC2{}}



static void Test_BFu8c_BFu0c_Sf()
{
  {
    init_simple_test("BFu8c_BFu0c_Sf");
    static STRUCT_IF_C BFu8c_BFu0c_Sf lv;
    check2(sizeof(lv), 1, "sizeof(BFu8c_BFu0c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8c_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_BFu0c_Sf");
    check_field_offset(lv, v2, 1, "BFu8c_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8c_BFu0c_Sf, BFu8c_BFu0c_Sf)
//============================================================================


struct  BFu8c_BFu0i_Sf  {
  unsigned char v1:8;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu8c_BFu0i_Sf) C1{ Fc:8 Fi:0 FC2{}}



static void Test_BFu8c_BFu0i_Sf()
{
  {
    init_simple_test("BFu8c_BFu0i_Sf");
    static STRUCT_IF_C BFu8c_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu8c_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu8c_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu8c_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8c_BFu0i_Sf, BFu8c_BFu0i_Sf)
//============================================================================


struct  BFu8c_BFu0ll_Sf  {
  unsigned char v1:8;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu8c_BFu0ll_Sf) C1{ Fc:8 FL:0 FC2{}}



static void Test_BFu8c_BFu0ll_Sf()
{
  {
    init_simple_test("BFu8c_BFu0ll_Sf");
    static STRUCT_IF_C BFu8c_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8c_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu8c_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu8c_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8c_BFu0ll_Sf, BFu8c_BFu0ll_Sf)
//============================================================================


struct  BFu8c_BFu0s_Sf  {
  unsigned char v1:8;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu8c_BFu0s_Sf) C1{ Fc:8 Fs:0 FC2{}}



static void Test_BFu8c_BFu0s_Sf()
{
  {
    init_simple_test("BFu8c_BFu0s_Sf");
    static STRUCT_IF_C BFu8c_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu8c_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu8c_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu8c_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8c_BFu0s_Sf, BFu8c_BFu0s_Sf)
//============================================================================


struct  BFu8c_Sf_BFu0c  {
  unsigned char v1:8;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu8c_Sf_BFu0c) C1{ Fc:8 FC2{} Fc:0}



static void Test_BFu8c_Sf_BFu0c()
{
  {
    init_simple_test("BFu8c_Sf_BFu0c");
    static STRUCT_IF_C BFu8c_Sf_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(BFu8c_Sf_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(BFu8c_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_Sf_BFu0c");
    check_field_offset(lv, v2, 1, "BFu8c_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8c_Sf_BFu0c, BFu8c_Sf_BFu0c)
//============================================================================


struct  BFu8c_Sf_BFu0i  {
  unsigned char v1:8;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu8c_Sf_BFu0i) C1{ Fc:8 FC2{} Fi:0}



static void Test_BFu8c_Sf_BFu0i()
{
  {
    init_simple_test("BFu8c_Sf_BFu0i");
    static STRUCT_IF_C BFu8c_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu8c_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu8c_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_Sf_BFu0i");
    check_field_offset(lv, v2, 1, "BFu8c_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8c_Sf_BFu0i, BFu8c_Sf_BFu0i)
//============================================================================


struct  BFu8c_Sf_BFu0ll  {
  unsigned char v1:8;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu8c_Sf_BFu0ll) C1{ Fc:8 FC2{} FL:0}



static void Test_BFu8c_Sf_BFu0ll()
{
  {
    init_simple_test("BFu8c_Sf_BFu0ll");
    static STRUCT_IF_C BFu8c_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8c_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu8c_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_Sf_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu8c_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8c_Sf_BFu0ll, BFu8c_Sf_BFu0ll)
//============================================================================


struct  BFu8c_Sf_BFu0s  {
  unsigned char v1:8;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu8c_Sf_BFu0s) C1{ Fc:8 FC2{} Fs:0}



static void Test_BFu8c_Sf_BFu0s()
{
  {
    init_simple_test("BFu8c_Sf_BFu0s");
    static STRUCT_IF_C BFu8c_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu8c_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(BFu8c_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8c_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8c_Sf_BFu0s");
    check_field_offset(lv, v2, 1, "BFu8c_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8c_Sf_BFu0s, BFu8c_Sf_BFu0s)
//============================================================================


struct  BFu8i_BFu0c_Sf  {
  unsigned int v1:8;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu8i_BFu0c_Sf) C1{ Fi:8 Fc:0 FC2{}}



static void Test_BFu8i_BFu0c_Sf()
{
  {
    init_simple_test("BFu8i_BFu0c_Sf");
    static STRUCT_IF_C BFu8i_BFu0c_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_BFu0c_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_BFu0c_Sf");
    check_field_offset(lv, v2, 1, "BFu8i_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8i_BFu0c_Sf, BFu8i_BFu0c_Sf)
//============================================================================


struct  BFu8i_BFu0i_Sf  {
  unsigned int v1:8;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu8i_BFu0i_Sf) C1{ Fi:8 Fi:0 FC2{}}



static void Test_BFu8i_BFu0i_Sf()
{
  {
    init_simple_test("BFu8i_BFu0i_Sf");
    static STRUCT_IF_C BFu8i_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_BFu0i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu8i_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8i_BFu0i_Sf, BFu8i_BFu0i_Sf)
//============================================================================


struct  BFu8i_BFu0ll_Sf  {
  unsigned int v1:8;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu8i_BFu0ll_Sf) C1{ Fi:8 FL:0 FC2{}}



static void Test_BFu8i_BFu0ll_Sf()
{
  {
    init_simple_test("BFu8i_BFu0ll_Sf");
    static STRUCT_IF_C BFu8i_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8i_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu8i_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu8i_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8i_BFu0ll_Sf, BFu8i_BFu0ll_Sf)
//============================================================================


struct  BFu8i_BFu0s_Sf  {
  unsigned int v1:8;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu8i_BFu0s_Sf) C1{ Fi:8 Fs:0 FC2{}}



static void Test_BFu8i_BFu0s_Sf()
{
  {
    init_simple_test("BFu8i_BFu0s_Sf");
    static STRUCT_IF_C BFu8i_BFu0s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_BFu0s_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu8i_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8i_BFu0s_Sf, BFu8i_BFu0s_Sf)
//============================================================================


struct  BFu8i_Sf_BFu0c  {
  unsigned int v1:8;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu8i_Sf_BFu0c) C1{ Fi:8 FC2{} Fc:0}



static void Test_BFu8i_Sf_BFu0c()
{
  {
    init_simple_test("BFu8i_Sf_BFu0c");
    static STRUCT_IF_C BFu8i_Sf_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_Sf_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_Sf_BFu0c");
    check_field_offset(lv, v2, 1, "BFu8i_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8i_Sf_BFu0c, BFu8i_Sf_BFu0c)
//============================================================================


struct  BFu8i_Sf_BFu0i  {
  unsigned int v1:8;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu8i_Sf_BFu0i) C1{ Fi:8 FC2{} Fi:0}



static void Test_BFu8i_Sf_BFu0i()
{
  {
    init_simple_test("BFu8i_Sf_BFu0i");
    static STRUCT_IF_C BFu8i_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_Sf_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_Sf_BFu0i");
    check_field_offset(lv, v2, 1, "BFu8i_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8i_Sf_BFu0i, BFu8i_Sf_BFu0i)
//============================================================================


struct  BFu8i_Sf_BFu0ll  {
  unsigned int v1:8;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu8i_Sf_BFu0ll) C1{ Fi:8 FC2{} FL:0}



static void Test_BFu8i_Sf_BFu0ll()
{
  {
    init_simple_test("BFu8i_Sf_BFu0ll");
    static STRUCT_IF_C BFu8i_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8i_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu8i_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_Sf_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu8i_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8i_Sf_BFu0ll, BFu8i_Sf_BFu0ll)
//============================================================================


struct  BFu8i_Sf_BFu0s  {
  unsigned int v1:8;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu8i_Sf_BFu0s) C1{ Fi:8 FC2{} Fs:0}



static void Test_BFu8i_Sf_BFu0s()
{
  {
    init_simple_test("BFu8i_Sf_BFu0s");
    static STRUCT_IF_C BFu8i_Sf_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu8i_Sf_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu8i_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8i_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8i_Sf_BFu0s");
    check_field_offset(lv, v2, 1, "BFu8i_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8i_Sf_BFu0s, BFu8i_Sf_BFu0s)
//============================================================================


struct  BFu8ll_BFu0c_Sf  {
  __tsu64 v1:8;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu8ll_BFu0c_Sf) C1{ FL:8 Fc:0 FC2{}}



static void Test_BFu8ll_BFu0c_Sf()
{
  {
    init_simple_test("BFu8ll_BFu0c_Sf");
    static STRUCT_IF_C BFu8ll_BFu0c_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_BFu0c_Sf");
    check_field_offset(lv, v2, 1, "BFu8ll_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8ll_BFu0c_Sf, BFu8ll_BFu0c_Sf)
//============================================================================


struct  BFu8ll_BFu0i_Sf  {
  __tsu64 v1:8;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu8ll_BFu0i_Sf) C1{ FL:8 Fi:0 FC2{}}



static void Test_BFu8ll_BFu0i_Sf()
{
  {
    init_simple_test("BFu8ll_BFu0i_Sf");
    static STRUCT_IF_C BFu8ll_BFu0i_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu8ll_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8ll_BFu0i_Sf, BFu8ll_BFu0i_Sf)
//============================================================================


struct  BFu8ll_BFu0ll_Sf  {
  __tsu64 v1:8;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu8ll_BFu0ll_Sf) C1{ FL:8 FL:0 FC2{}}



static void Test_BFu8ll_BFu0ll_Sf()
{
  {
    init_simple_test("BFu8ll_BFu0ll_Sf");
    static STRUCT_IF_C BFu8ll_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu8ll_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8ll_BFu0ll_Sf, BFu8ll_BFu0ll_Sf)
//============================================================================


struct  BFu8ll_BFu0s_Sf  {
  __tsu64 v1:8;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu8ll_BFu0s_Sf) C1{ FL:8 Fs:0 FC2{}}



static void Test_BFu8ll_BFu0s_Sf()
{
  {
    init_simple_test("BFu8ll_BFu0s_Sf");
    static STRUCT_IF_C BFu8ll_BFu0s_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu8ll_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8ll_BFu0s_Sf, BFu8ll_BFu0s_Sf)
//============================================================================


struct  BFu8ll_Sf_BFu0c  {
  __tsu64 v1:8;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu8ll_Sf_BFu0c) C1{ FL:8 FC2{} Fc:0}



static void Test_BFu8ll_Sf_BFu0c()
{
  {
    init_simple_test("BFu8ll_Sf_BFu0c");
    static STRUCT_IF_C BFu8ll_Sf_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_Sf_BFu0c");
    check_field_offset(lv, v2, 1, "BFu8ll_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8ll_Sf_BFu0c, BFu8ll_Sf_BFu0c)
//============================================================================


struct  BFu8ll_Sf_BFu0i  {
  __tsu64 v1:8;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu8ll_Sf_BFu0i) C1{ FL:8 FC2{} Fi:0}



static void Test_BFu8ll_Sf_BFu0i()
{
  {
    init_simple_test("BFu8ll_Sf_BFu0i");
    static STRUCT_IF_C BFu8ll_Sf_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_Sf_BFu0i");
    check_field_offset(lv, v2, 1, "BFu8ll_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8ll_Sf_BFu0i, BFu8ll_Sf_BFu0i)
//============================================================================


struct  BFu8ll_Sf_BFu0ll  {
  __tsu64 v1:8;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu8ll_Sf_BFu0ll) C1{ FL:8 FC2{} FL:0}



static void Test_BFu8ll_Sf_BFu0ll()
{
  {
    init_simple_test("BFu8ll_Sf_BFu0ll");
    static STRUCT_IF_C BFu8ll_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_Sf_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu8ll_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8ll_Sf_BFu0ll, BFu8ll_Sf_BFu0ll)
//============================================================================


struct  BFu8ll_Sf_BFu0s  {
  __tsu64 v1:8;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu8ll_Sf_BFu0s) C1{ FL:8 FC2{} Fs:0}



static void Test_BFu8ll_Sf_BFu0s()
{
  {
    init_simple_test("BFu8ll_Sf_BFu0s");
    static STRUCT_IF_C BFu8ll_Sf_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8ll_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu8ll_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8ll_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8ll_Sf_BFu0s");
    check_field_offset(lv, v2, 1, "BFu8ll_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8ll_Sf_BFu0s, BFu8ll_Sf_BFu0s)
//============================================================================


struct  BFu8s_BFu0c_Sf  {
  unsigned short v1:8;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu8s_BFu0c_Sf) C1{ Fs:8 Fc:0 FC2{}}



static void Test_BFu8s_BFu0c_Sf()
{
  {
    init_simple_test("BFu8s_BFu0c_Sf");
    static STRUCT_IF_C BFu8s_BFu0c_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu8s_BFu0c_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu8s_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_BFu0c_Sf");
    check_field_offset(lv, v2, 1, "BFu8s_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8s_BFu0c_Sf, BFu8s_BFu0c_Sf)
//============================================================================


struct  BFu8s_BFu0i_Sf  {
  unsigned short v1:8;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu8s_BFu0i_Sf) C1{ Fs:8 Fi:0 FC2{}}



static void Test_BFu8s_BFu0i_Sf()
{
  {
    init_simple_test("BFu8s_BFu0i_Sf");
    static STRUCT_IF_C BFu8s_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu8s_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu8s_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu8s_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8s_BFu0i_Sf, BFu8s_BFu0i_Sf)
//============================================================================


struct  BFu8s_BFu0ll_Sf  {
  unsigned short v1:8;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu8s_BFu0ll_Sf) C1{ Fs:8 FL:0 FC2{}}



static void Test_BFu8s_BFu0ll_Sf()
{
  {
    init_simple_test("BFu8s_BFu0ll_Sf");
    static STRUCT_IF_C BFu8s_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8s_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu8s_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu8s_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8s_BFu0ll_Sf, BFu8s_BFu0ll_Sf)
//============================================================================


struct  BFu8s_BFu0s_Sf  {
  unsigned short v1:8;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu8s_BFu0s_Sf) C1{ Fs:8 Fs:0 FC2{}}



static void Test_BFu8s_BFu0s_Sf()
{
  {
    init_simple_test("BFu8s_BFu0s_Sf");
    static STRUCT_IF_C BFu8s_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu8s_BFu0s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu8s_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu8s_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8s_BFu0s_Sf, BFu8s_BFu0s_Sf)
//============================================================================


struct  BFu8s_Sf_BFu0c  {
  unsigned short v1:8;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu8s_Sf_BFu0c) C1{ Fs:8 FC2{} Fc:0}



static void Test_BFu8s_Sf_BFu0c()
{
  {
    init_simple_test("BFu8s_Sf_BFu0c");
    static STRUCT_IF_C BFu8s_Sf_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(BFu8s_Sf_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(BFu8s_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_Sf_BFu0c");
    check_field_offset(lv, v2, 1, "BFu8s_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8s_Sf_BFu0c, BFu8s_Sf_BFu0c)
//============================================================================


struct  BFu8s_Sf_BFu0i  {
  unsigned short v1:8;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu8s_Sf_BFu0i) C1{ Fs:8 FC2{} Fi:0}



static void Test_BFu8s_Sf_BFu0i()
{
  {
    init_simple_test("BFu8s_Sf_BFu0i");
    static STRUCT_IF_C BFu8s_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu8s_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu8s_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_Sf_BFu0i");
    check_field_offset(lv, v2, 1, "BFu8s_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8s_Sf_BFu0i, BFu8s_Sf_BFu0i)
//============================================================================


struct  BFu8s_Sf_BFu0ll  {
  unsigned short v1:8;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu8s_Sf_BFu0ll) C1{ Fs:8 FC2{} FL:0}



static void Test_BFu8s_Sf_BFu0ll()
{
  {
    init_simple_test("BFu8s_Sf_BFu0ll");
    static STRUCT_IF_C BFu8s_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu8s_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu8s_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_Sf_BFu0ll");
    check_field_offset(lv, v2, 1, "BFu8s_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8s_Sf_BFu0ll, BFu8s_Sf_BFu0ll)
//============================================================================


struct  BFu8s_Sf_BFu0s  {
  unsigned short v1:8;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu8s_Sf_BFu0s) C1{ Fs:8 FC2{} Fs:0}



static void Test_BFu8s_Sf_BFu0s()
{
  {
    init_simple_test("BFu8s_Sf_BFu0s");
    static STRUCT_IF_C BFu8s_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu8s_Sf_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu8s_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 8, 1, "BFu8s_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 8, hide_ull(1LL<<7), "BFu8s_Sf_BFu0s");
    check_field_offset(lv, v2, 1, "BFu8s_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu8s_Sf_BFu0s, BFu8s_Sf_BFu0s)
//============================================================================


struct  BFu9i_BFu0c_Sf  {
  unsigned int v1:9;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu9i_BFu0c_Sf) C1{ Fi:9 Fc:0 FC2{}}



static void Test_BFu9i_BFu0c_Sf()
{
  {
    init_simple_test("BFu9i_BFu0c_Sf");
    static STRUCT_IF_C BFu9i_BFu0c_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_BFu0c_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_BFu0c_Sf");
    check_field_offset(lv, v2, 2, "BFu9i_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9i_BFu0c_Sf, BFu9i_BFu0c_Sf)
//============================================================================


struct  BFu9i_BFu0i_Sf  {
  unsigned int v1:9;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu9i_BFu0i_Sf) C1{ Fi:9 Fi:0 FC2{}}



static void Test_BFu9i_BFu0i_Sf()
{
  {
    init_simple_test("BFu9i_BFu0i_Sf");
    static STRUCT_IF_C BFu9i_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_BFu0i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu9i_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9i_BFu0i_Sf, BFu9i_BFu0i_Sf)
//============================================================================


struct  BFu9i_BFu0ll_Sf  {
  unsigned int v1:9;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu9i_BFu0ll_Sf) C1{ Fi:9 FL:0 FC2{}}



static void Test_BFu9i_BFu0ll_Sf()
{
  {
    init_simple_test("BFu9i_BFu0ll_Sf");
    static STRUCT_IF_C BFu9i_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9i_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu9i_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu9i_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9i_BFu0ll_Sf, BFu9i_BFu0ll_Sf)
//============================================================================


struct  BFu9i_BFu0s_Sf  {
  unsigned int v1:9;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu9i_BFu0s_Sf) C1{ Fi:9 Fs:0 FC2{}}



static void Test_BFu9i_BFu0s_Sf()
{
  {
    init_simple_test("BFu9i_BFu0s_Sf");
    static STRUCT_IF_C BFu9i_BFu0s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_BFu0s_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu9i_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9i_BFu0s_Sf, BFu9i_BFu0s_Sf)
//============================================================================


struct  BFu9i_Sf_BFu0c  {
  unsigned int v1:9;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu9i_Sf_BFu0c) C1{ Fi:9 FC2{} Fc:0}



static void Test_BFu9i_Sf_BFu0c()
{
  {
    init_simple_test("BFu9i_Sf_BFu0c");
    static STRUCT_IF_C BFu9i_Sf_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_Sf_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_Sf_BFu0c");
    check_field_offset(lv, v2, 2, "BFu9i_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9i_Sf_BFu0c, BFu9i_Sf_BFu0c)
//============================================================================


struct  BFu9i_Sf_BFu0i  {
  unsigned int v1:9;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu9i_Sf_BFu0i) C1{ Fi:9 FC2{} Fi:0}



static void Test_BFu9i_Sf_BFu0i()
{
  {
    init_simple_test("BFu9i_Sf_BFu0i");
    static STRUCT_IF_C BFu9i_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_Sf_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_Sf_BFu0i");
    check_field_offset(lv, v2, 2, "BFu9i_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9i_Sf_BFu0i, BFu9i_Sf_BFu0i)
//============================================================================


struct  BFu9i_Sf_BFu0ll  {
  unsigned int v1:9;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu9i_Sf_BFu0ll) C1{ Fi:9 FC2{} FL:0}



static void Test_BFu9i_Sf_BFu0ll()
{
  {
    init_simple_test("BFu9i_Sf_BFu0ll");
    static STRUCT_IF_C BFu9i_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9i_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(BFu9i_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_Sf_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu9i_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9i_Sf_BFu0ll, BFu9i_Sf_BFu0ll)
//============================================================================


struct  BFu9i_Sf_BFu0s  {
  unsigned int v1:9;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu9i_Sf_BFu0s) C1{ Fi:9 FC2{} Fs:0}



static void Test_BFu9i_Sf_BFu0s()
{
  {
    init_simple_test("BFu9i_Sf_BFu0s");
    static STRUCT_IF_C BFu9i_Sf_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(BFu9i_Sf_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(BFu9i_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9i_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9i_Sf_BFu0s");
    check_field_offset(lv, v2, 2, "BFu9i_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9i_Sf_BFu0s, BFu9i_Sf_BFu0s)
//============================================================================


struct  BFu9ll_BFu0c_Sf  {
  __tsu64 v1:9;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu9ll_BFu0c_Sf) C1{ FL:9 Fc:0 FC2{}}



static void Test_BFu9ll_BFu0c_Sf()
{
  {
    init_simple_test("BFu9ll_BFu0c_Sf");
    static STRUCT_IF_C BFu9ll_BFu0c_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_BFu0c_Sf");
    check_field_offset(lv, v2, 2, "BFu9ll_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9ll_BFu0c_Sf, BFu9ll_BFu0c_Sf)
//============================================================================


struct  BFu9ll_BFu0i_Sf  {
  __tsu64 v1:9;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu9ll_BFu0i_Sf) C1{ FL:9 Fi:0 FC2{}}



static void Test_BFu9ll_BFu0i_Sf()
{
  {
    init_simple_test("BFu9ll_BFu0i_Sf");
    static STRUCT_IF_C BFu9ll_BFu0i_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu9ll_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9ll_BFu0i_Sf, BFu9ll_BFu0i_Sf)
//============================================================================


struct  BFu9ll_BFu0ll_Sf  {
  __tsu64 v1:9;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu9ll_BFu0ll_Sf) C1{ FL:9 FL:0 FC2{}}



static void Test_BFu9ll_BFu0ll_Sf()
{
  {
    init_simple_test("BFu9ll_BFu0ll_Sf");
    static STRUCT_IF_C BFu9ll_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu9ll_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9ll_BFu0ll_Sf, BFu9ll_BFu0ll_Sf)
//============================================================================


struct  BFu9ll_BFu0s_Sf  {
  __tsu64 v1:9;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu9ll_BFu0s_Sf) C1{ FL:9 Fs:0 FC2{}}



static void Test_BFu9ll_BFu0s_Sf()
{
  {
    init_simple_test("BFu9ll_BFu0s_Sf");
    static STRUCT_IF_C BFu9ll_BFu0s_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu9ll_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9ll_BFu0s_Sf, BFu9ll_BFu0s_Sf)
//============================================================================


struct  BFu9ll_Sf_BFu0c  {
  __tsu64 v1:9;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu9ll_Sf_BFu0c) C1{ FL:9 FC2{} Fc:0}



static void Test_BFu9ll_Sf_BFu0c()
{
  {
    init_simple_test("BFu9ll_Sf_BFu0c");
    static STRUCT_IF_C BFu9ll_Sf_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_Sf_BFu0c");
    check_field_offset(lv, v2, 2, "BFu9ll_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9ll_Sf_BFu0c, BFu9ll_Sf_BFu0c)
//============================================================================


struct  BFu9ll_Sf_BFu0i  {
  __tsu64 v1:9;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu9ll_Sf_BFu0i) C1{ FL:9 FC2{} Fi:0}



static void Test_BFu9ll_Sf_BFu0i()
{
  {
    init_simple_test("BFu9ll_Sf_BFu0i");
    static STRUCT_IF_C BFu9ll_Sf_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_Sf_BFu0i");
    check_field_offset(lv, v2, 2, "BFu9ll_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9ll_Sf_BFu0i, BFu9ll_Sf_BFu0i)
//============================================================================


struct  BFu9ll_Sf_BFu0ll  {
  __tsu64 v1:9;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu9ll_Sf_BFu0ll) C1{ FL:9 FC2{} FL:0}



static void Test_BFu9ll_Sf_BFu0ll()
{
  {
    init_simple_test("BFu9ll_Sf_BFu0ll");
    static STRUCT_IF_C BFu9ll_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_Sf_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu9ll_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9ll_Sf_BFu0ll, BFu9ll_Sf_BFu0ll)
//============================================================================


struct  BFu9ll_Sf_BFu0s  {
  __tsu64 v1:9;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu9ll_Sf_BFu0s) C1{ FL:9 FC2{} Fs:0}



static void Test_BFu9ll_Sf_BFu0s()
{
  {
    init_simple_test("BFu9ll_Sf_BFu0s");
    static STRUCT_IF_C BFu9ll_Sf_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9ll_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(BFu9ll_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9ll_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9ll_Sf_BFu0s");
    check_field_offset(lv, v2, 2, "BFu9ll_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9ll_Sf_BFu0s, BFu9ll_Sf_BFu0s)
//============================================================================


struct  BFu9s_BFu0c_Sf  {
  unsigned short v1:9;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 BFu9s_BFu0c_Sf) C1{ Fs:9 Fc:0 FC2{}}



static void Test_BFu9s_BFu0c_Sf()
{
  {
    init_simple_test("BFu9s_BFu0c_Sf");
    static STRUCT_IF_C BFu9s_BFu0c_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu9s_BFu0c_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu9s_BFu0c_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu0c_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu0c_Sf");
    check_field_offset(lv, v2, 2, "BFu9s_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9s_BFu0c_Sf, BFu9s_BFu0c_Sf)
//============================================================================


struct  BFu9s_BFu0i_Sf  {
  unsigned short v1:9;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 BFu9s_BFu0i_Sf) C1{ Fs:9 Fi:0 FC2{}}



static void Test_BFu9s_BFu0i_Sf()
{
  {
    init_simple_test("BFu9s_BFu0i_Sf");
    static STRUCT_IF_C BFu9s_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu9s_BFu0i_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu0i_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu0i_Sf");
    check_field_offset(lv, v2, 4, "BFu9s_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9s_BFu0i_Sf, BFu9s_BFu0i_Sf)
//============================================================================


struct  BFu9s_BFu0ll_Sf  {
  unsigned short v1:9;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 BFu9s_BFu0ll_Sf) C1{ Fs:9 FL:0 FC2{}}



static void Test_BFu9s_BFu0ll_Sf()
{
  {
    init_simple_test("BFu9s_BFu0ll_Sf");
    static STRUCT_IF_C BFu9s_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9s_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu9s_BFu0ll_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu0ll_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu0ll_Sf");
    check_field_offset(lv, v2, ABISELECT(8,4), "BFu9s_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9s_BFu0ll_Sf, BFu9s_BFu0ll_Sf)
//============================================================================


struct  BFu9s_BFu0s_Sf  {
  unsigned short v1:9;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 BFu9s_BFu0s_Sf) C1{ Fs:9 Fs:0 FC2{}}



static void Test_BFu9s_BFu0s_Sf()
{
  {
    init_simple_test("BFu9s_BFu0s_Sf");
    static STRUCT_IF_C BFu9s_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(BFu9s_BFu0s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(BFu9s_BFu0s_Sf)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_BFu0s_Sf");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_BFu0s_Sf");
    check_field_offset(lv, v2, 2, "BFu9s_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9s_BFu0s_Sf, BFu9s_BFu0s_Sf)
//============================================================================


struct  BFu9s_Sf_BFu0c  {
  unsigned short v1:9;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 BFu9s_Sf_BFu0c) C1{ Fs:9 FC2{} Fc:0}



static void Test_BFu9s_Sf_BFu0c()
{
  {
    init_simple_test("BFu9s_Sf_BFu0c");
    static STRUCT_IF_C BFu9s_Sf_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(BFu9s_Sf_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(BFu9s_Sf_BFu0c)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_Sf_BFu0c");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_Sf_BFu0c");
    check_field_offset(lv, v2, 2, "BFu9s_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9s_Sf_BFu0c, BFu9s_Sf_BFu0c)
//============================================================================


struct  BFu9s_Sf_BFu0i  {
  unsigned short v1:9;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 BFu9s_Sf_BFu0i) C1{ Fs:9 FC2{} Fi:0}



static void Test_BFu9s_Sf_BFu0i()
{
  {
    init_simple_test("BFu9s_Sf_BFu0i");
    static STRUCT_IF_C BFu9s_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(BFu9s_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu9s_Sf_BFu0i)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_Sf_BFu0i");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_Sf_BFu0i");
    check_field_offset(lv, v2, 2, "BFu9s_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9s_Sf_BFu0i, BFu9s_Sf_BFu0i)
//============================================================================


struct  BFu9s_Sf_BFu0ll  {
  unsigned short v1:9;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 BFu9s_Sf_BFu0ll) C1{ Fs:9 FC2{} FL:0}



static void Test_BFu9s_Sf_BFu0ll()
{
  {
    init_simple_test("BFu9s_Sf_BFu0ll");
    static STRUCT_IF_C BFu9s_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(BFu9s_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(BFu9s_Sf_BFu0ll)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_Sf_BFu0ll");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_Sf_BFu0ll");
    check_field_offset(lv, v2, 2, "BFu9s_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9s_Sf_BFu0ll, BFu9s_Sf_BFu0ll)
//============================================================================


struct  BFu9s_Sf_BFu0s  {
  unsigned short v1:9;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 BFu9s_Sf_BFu0s) C1{ Fs:9 FC2{} Fs:0}



static void Test_BFu9s_Sf_BFu0s()
{
  {
    init_simple_test("BFu9s_Sf_BFu0s");
    static STRUCT_IF_C BFu9s_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(BFu9s_Sf_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(BFu9s_Sf_BFu0s)");
    set_bf_and_test(lv, v1, 0, 0, 9, 1, "BFu9s_Sf_BFu0s");
    set_bf_and_test(lv, v1, 0, 0, 9, hide_ull(1LL<<8), "BFu9s_Sf_BFu0s");
    check_field_offset(lv, v2, 2, "BFu9s_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_BFu9s_Sf_BFu0s, BFu9s_Sf_BFu0s)
//============================================================================


struct  C_BFu0c_Sf  {
  char v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 C_BFu0c_Sf) C1{ Fc Fc:0 FC2{}}



static void Test_C_BFu0c_Sf()
{
  {
    init_simple_test("C_BFu0c_Sf");
    static STRUCT_IF_C C_BFu0c_Sf lv;
    check2(sizeof(lv), 1, "sizeof(C_BFu0c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(C_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "C_BFu0c_Sf.v1");
    check_field_offset(lv, v2, 1, "C_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_C_BFu0c_Sf, C_BFu0c_Sf)
//============================================================================


struct  C_BFu0i_Sf  {
  char v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 C_BFu0i_Sf) C1{ Fc Fi:0 FC2{}}



static void Test_C_BFu0i_Sf()
{
  {
    init_simple_test("C_BFu0i_Sf");
    static STRUCT_IF_C C_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(C_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(C_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "C_BFu0i_Sf.v1");
    check_field_offset(lv, v2, 4, "C_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_C_BFu0i_Sf, C_BFu0i_Sf)
//============================================================================


struct  C_BFu0ll_Sf  {
  char v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 C_BFu0ll_Sf) C1{ Fc FL:0 FC2{}}



static void Test_C_BFu0ll_Sf()
{
  {
    init_simple_test("C_BFu0ll_Sf");
    static STRUCT_IF_C C_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(C_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(C_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "C_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "C_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_C_BFu0ll_Sf, C_BFu0ll_Sf)
//============================================================================


struct  C_BFu0s_Sf  {
  char v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 C_BFu0s_Sf) C1{ Fc Fs:0 FC2{}}



static void Test_C_BFu0s_Sf()
{
  {
    init_simple_test("C_BFu0s_Sf");
    static STRUCT_IF_C C_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(C_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(C_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "C_BFu0s_Sf.v1");
    check_field_offset(lv, v2, 2, "C_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_C_BFu0s_Sf, C_BFu0s_Sf)
//============================================================================


struct  C_Sf_BFu0c  {
  char v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 C_Sf_BFu0c) C1{ Fc FC2{} Fc:0}



static void Test_C_Sf_BFu0c()
{
  {
    init_simple_test("C_Sf_BFu0c");
    static STRUCT_IF_C C_Sf_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(C_Sf_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(C_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "C_Sf_BFu0c.v1");
    check_field_offset(lv, v2, 1, "C_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_C_Sf_BFu0c, C_Sf_BFu0c)
//============================================================================


struct  C_Sf_BFu0i  {
  char v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 C_Sf_BFu0i) C1{ Fc FC2{} Fi:0}



static void Test_C_Sf_BFu0i()
{
  {
    init_simple_test("C_Sf_BFu0i");
    static STRUCT_IF_C C_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(C_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(C_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "C_Sf_BFu0i.v1");
    check_field_offset(lv, v2, 1, "C_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_C_Sf_BFu0i, C_Sf_BFu0i)
//============================================================================


struct  C_Sf_BFu0ll  {
  char v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 C_Sf_BFu0ll) C1{ Fc FC2{} FL:0}



static void Test_C_Sf_BFu0ll()
{
  {
    init_simple_test("C_Sf_BFu0ll");
    static STRUCT_IF_C C_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(C_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(C_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "C_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, 1, "C_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_C_Sf_BFu0ll, C_Sf_BFu0ll)
//============================================================================


struct  C_Sf_BFu0s  {
  char v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 C_Sf_BFu0s) C1{ Fc FC2{} Fs:0}



static void Test_C_Sf_BFu0s()
{
  {
    init_simple_test("C_Sf_BFu0s");
    static STRUCT_IF_C C_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(C_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(C_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "C_Sf_BFu0s.v1");
    check_field_offset(lv, v2, 1, "C_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_C_Sf_BFu0s, C_Sf_BFu0s)
//============================================================================


struct  D_BFu0c_Sf  {
  double v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 D_BFu0c_Sf) C1{ FL Fc:0 FC2{}}



static void Test_D_BFu0c_Sf()
{
  {
    init_simple_test("D_BFu0c_Sf");
    static STRUCT_IF_C D_BFu0c_Sf lv;
    check2(sizeof(lv), 8, "sizeof(D_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "D_BFu0c_Sf.v1");
    check_field_offset(lv, v2, 8, "D_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_D_BFu0c_Sf, D_BFu0c_Sf)
//============================================================================


struct  D_BFu0i_Sf  {
  double v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 D_BFu0i_Sf) C1{ FL Fi:0 FC2{}}



static void Test_D_BFu0i_Sf()
{
  {
    init_simple_test("D_BFu0i_Sf");
    static STRUCT_IF_C D_BFu0i_Sf lv;
    check2(sizeof(lv), 8, "sizeof(D_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "D_BFu0i_Sf.v1");
    check_field_offset(lv, v2, 8, "D_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_D_BFu0i_Sf, D_BFu0i_Sf)
//============================================================================


struct  D_BFu0ll_Sf  {
  double v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 D_BFu0ll_Sf) C1{ FL FL:0 FC2{}}



static void Test_D_BFu0ll_Sf()
{
  {
    init_simple_test("D_BFu0ll_Sf");
    static STRUCT_IF_C D_BFu0ll_Sf lv;
    check2(sizeof(lv), 8, "sizeof(D_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "D_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, 8, "D_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_D_BFu0ll_Sf, D_BFu0ll_Sf)
//============================================================================


struct  D_BFu0s_Sf  {
  double v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 D_BFu0s_Sf) C1{ FL Fs:0 FC2{}}



static void Test_D_BFu0s_Sf()
{
  {
    init_simple_test("D_BFu0s_Sf");
    static STRUCT_IF_C D_BFu0s_Sf lv;
    check2(sizeof(lv), 8, "sizeof(D_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "D_BFu0s_Sf.v1");
    check_field_offset(lv, v2, 8, "D_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_D_BFu0s_Sf, D_BFu0s_Sf)
//============================================================================


struct  D_Sf_BFu0c  {
  double v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 D_Sf_BFu0c) C1{ FL FC2{} Fc:0}



static void Test_D_Sf_BFu0c()
{
  {
    init_simple_test("D_Sf_BFu0c");
    static STRUCT_IF_C D_Sf_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(D_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "D_Sf_BFu0c.v1");
    check_field_offset(lv, v2, 8, "D_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_D_Sf_BFu0c, D_Sf_BFu0c)
//============================================================================


struct  D_Sf_BFu0i  {
  double v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 D_Sf_BFu0i) C1{ FL FC2{} Fi:0}



static void Test_D_Sf_BFu0i()
{
  {
    init_simple_test("D_Sf_BFu0i");
    static STRUCT_IF_C D_Sf_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(D_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "D_Sf_BFu0i.v1");
    check_field_offset(lv, v2, 8, "D_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_D_Sf_BFu0i, D_Sf_BFu0i)
//============================================================================


struct  D_Sf_BFu0ll  {
  double v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 D_Sf_BFu0ll) C1{ FL FC2{} FL:0}



static void Test_D_Sf_BFu0ll()
{
  {
    init_simple_test("D_Sf_BFu0ll");
    static STRUCT_IF_C D_Sf_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(D_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "D_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "D_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_D_Sf_BFu0ll, D_Sf_BFu0ll)
//============================================================================


struct  D_Sf_BFu0s  {
  double v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 D_Sf_BFu0s) C1{ FL FC2{} Fs:0}



static void Test_D_Sf_BFu0s()
{
  {
    init_simple_test("D_Sf_BFu0s");
    static STRUCT_IF_C D_Sf_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(D_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(D_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "D_Sf_BFu0s.v1");
    check_field_offset(lv, v2, 8, "D_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_D_Sf_BFu0s, D_Sf_BFu0s)
//============================================================================


struct  F_BFu0c_Sf  {
  float v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 F_BFu0c_Sf) C1{ Fi Fc:0 FC2{}}



static void Test_F_BFu0c_Sf()
{
  {
    init_simple_test("F_BFu0c_Sf");
    static STRUCT_IF_C F_BFu0c_Sf lv;
    check2(sizeof(lv), 4, "sizeof(F_BFu0c_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(F_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "F_BFu0c_Sf.v1");
    check_field_offset(lv, v2, 4, "F_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_F_BFu0c_Sf, F_BFu0c_Sf)
//============================================================================


struct  F_BFu0i_Sf  {
  float v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 F_BFu0i_Sf) C1{ Fi Fi:0 FC2{}}



static void Test_F_BFu0i_Sf()
{
  {
    init_simple_test("F_BFu0i_Sf");
    static STRUCT_IF_C F_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(F_BFu0i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(F_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "F_BFu0i_Sf.v1");
    check_field_offset(lv, v2, 4, "F_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_F_BFu0i_Sf, F_BFu0i_Sf)
//============================================================================


struct  F_BFu0ll_Sf  {
  float v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 F_BFu0ll_Sf) C1{ Fi FL:0 FC2{}}



static void Test_F_BFu0ll_Sf()
{
  {
    init_simple_test("F_BFu0ll_Sf");
    static STRUCT_IF_C F_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(F_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(F_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "F_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "F_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_F_BFu0ll_Sf, F_BFu0ll_Sf)
//============================================================================


struct  F_BFu0s_Sf  {
  float v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 F_BFu0s_Sf) C1{ Fi Fs:0 FC2{}}



static void Test_F_BFu0s_Sf()
{
  {
    init_simple_test("F_BFu0s_Sf");
    static STRUCT_IF_C F_BFu0s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(F_BFu0s_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(F_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "F_BFu0s_Sf.v1");
    check_field_offset(lv, v2, 4, "F_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_F_BFu0s_Sf, F_BFu0s_Sf)
//============================================================================


struct  F_Sf_BFu0c  {
  float v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 F_Sf_BFu0c) C1{ Fi FC2{} Fc:0}



static void Test_F_Sf_BFu0c()
{
  {
    init_simple_test("F_Sf_BFu0c");
    static STRUCT_IF_C F_Sf_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(F_Sf_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(F_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "F_Sf_BFu0c.v1");
    check_field_offset(lv, v2, 4, "F_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_F_Sf_BFu0c, F_Sf_BFu0c)
//============================================================================


struct  F_Sf_BFu0i  {
  float v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 F_Sf_BFu0i) C1{ Fi FC2{} Fi:0}



static void Test_F_Sf_BFu0i()
{
  {
    init_simple_test("F_Sf_BFu0i");
    static STRUCT_IF_C F_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(F_Sf_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(F_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "F_Sf_BFu0i.v1");
    check_field_offset(lv, v2, 4, "F_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_F_Sf_BFu0i, F_Sf_BFu0i)
//============================================================================


struct  F_Sf_BFu0ll  {
  float v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 F_Sf_BFu0ll) C1{ Fi FC2{} FL:0}



static void Test_F_Sf_BFu0ll()
{
  {
    init_simple_test("F_Sf_BFu0ll");
    static STRUCT_IF_C F_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(F_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(F_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "F_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "F_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_F_Sf_BFu0ll, F_Sf_BFu0ll)
//============================================================================


struct  F_Sf_BFu0s  {
  float v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 F_Sf_BFu0s) C1{ Fi FC2{} Fs:0}



static void Test_F_Sf_BFu0s()
{
  {
    init_simple_test("F_Sf_BFu0s");
    static STRUCT_IF_C F_Sf_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(F_Sf_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(F_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "F_Sf_BFu0s.v1");
    check_field_offset(lv, v2, 4, "F_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_F_Sf_BFu0s, F_Sf_BFu0s)
//============================================================================


struct  I_BFu0c_Sf  {
  int v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 I_BFu0c_Sf) C1{ Fi Fc:0 FC2{}}



static void Test_I_BFu0c_Sf()
{
  {
    init_simple_test("I_BFu0c_Sf");
    static STRUCT_IF_C I_BFu0c_Sf lv;
    check2(sizeof(lv), 4, "sizeof(I_BFu0c_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(I_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "I_BFu0c_Sf.v1");
    check_field_offset(lv, v2, 4, "I_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_I_BFu0c_Sf, I_BFu0c_Sf)
//============================================================================


struct  I_BFu0i_Sf  {
  int v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 I_BFu0i_Sf) C1{ Fi Fi:0 FC2{}}



static void Test_I_BFu0i_Sf()
{
  {
    init_simple_test("I_BFu0i_Sf");
    static STRUCT_IF_C I_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(I_BFu0i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(I_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "I_BFu0i_Sf.v1");
    check_field_offset(lv, v2, 4, "I_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_I_BFu0i_Sf, I_BFu0i_Sf)
//============================================================================


struct  I_BFu0ll_Sf  {
  int v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 I_BFu0ll_Sf) C1{ Fi FL:0 FC2{}}



static void Test_I_BFu0ll_Sf()
{
  {
    init_simple_test("I_BFu0ll_Sf");
    static STRUCT_IF_C I_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(I_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(I_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "I_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "I_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_I_BFu0ll_Sf, I_BFu0ll_Sf)
//============================================================================


struct  I_BFu0s_Sf  {
  int v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 I_BFu0s_Sf) C1{ Fi Fs:0 FC2{}}



static void Test_I_BFu0s_Sf()
{
  {
    init_simple_test("I_BFu0s_Sf");
    static STRUCT_IF_C I_BFu0s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(I_BFu0s_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(I_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "I_BFu0s_Sf.v1");
    check_field_offset(lv, v2, 4, "I_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_I_BFu0s_Sf, I_BFu0s_Sf)
//============================================================================


struct  I_Sf_BFu0c  {
  int v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 I_Sf_BFu0c) C1{ Fi FC2{} Fc:0}



static void Test_I_Sf_BFu0c()
{
  {
    init_simple_test("I_Sf_BFu0c");
    static STRUCT_IF_C I_Sf_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(I_Sf_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(I_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "I_Sf_BFu0c.v1");
    check_field_offset(lv, v2, 4, "I_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_I_Sf_BFu0c, I_Sf_BFu0c)
//============================================================================


struct  I_Sf_BFu0i  {
  int v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 I_Sf_BFu0i) C1{ Fi FC2{} Fi:0}



static void Test_I_Sf_BFu0i()
{
  {
    init_simple_test("I_Sf_BFu0i");
    static STRUCT_IF_C I_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(I_Sf_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(I_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "I_Sf_BFu0i.v1");
    check_field_offset(lv, v2, 4, "I_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_I_Sf_BFu0i, I_Sf_BFu0i)
//============================================================================


struct  I_Sf_BFu0ll  {
  int v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 I_Sf_BFu0ll) C1{ Fi FC2{} FL:0}



static void Test_I_Sf_BFu0ll()
{
  {
    init_simple_test("I_Sf_BFu0ll");
    static STRUCT_IF_C I_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(I_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(I_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "I_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "I_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_I_Sf_BFu0ll, I_Sf_BFu0ll)
//============================================================================


struct  I_Sf_BFu0s  {
  int v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 I_Sf_BFu0s) C1{ Fi FC2{} Fs:0}



static void Test_I_Sf_BFu0s()
{
  {
    init_simple_test("I_Sf_BFu0s");
    static STRUCT_IF_C I_Sf_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(I_Sf_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(I_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "I_Sf_BFu0s.v1");
    check_field_offset(lv, v2, 4, "I_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_I_Sf_BFu0s, I_Sf_BFu0s)
//============================================================================


struct  Ip_BFu0c_Sf  {
  int *v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 Ip_BFu0c_Sf) C1{ Fp Fc:0 FC2{}}



static void Test_Ip_BFu0c_Sf()
{
  {
    init_simple_test("Ip_BFu0c_Sf");
    static STRUCT_IF_C Ip_BFu0c_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Ip_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "Ip_BFu0c_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ip_BFu0c_Sf, Ip_BFu0c_Sf)
//============================================================================


struct  Ip_BFu0i_Sf  {
  int *v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 Ip_BFu0i_Sf) C1{ Fp Fi:0 FC2{}}



static void Test_Ip_BFu0i_Sf()
{
  {
    init_simple_test("Ip_BFu0i_Sf");
    static STRUCT_IF_C Ip_BFu0i_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Ip_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "Ip_BFu0i_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ip_BFu0i_Sf, Ip_BFu0i_Sf)
//============================================================================


struct  Ip_BFu0ll_Sf  {
  int *v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 Ip_BFu0ll_Sf) C1{ Fp FL:0 FC2{}}



static void Test_Ip_BFu0ll_Sf()
{
  {
    init_simple_test("Ip_BFu0ll_Sf");
    static STRUCT_IF_C Ip_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Ip_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "Ip_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ip_BFu0ll_Sf, Ip_BFu0ll_Sf)
//============================================================================


struct  Ip_BFu0s_Sf  {
  int *v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 Ip_BFu0s_Sf) C1{ Fp Fs:0 FC2{}}



static void Test_Ip_BFu0s_Sf()
{
  {
    init_simple_test("Ip_BFu0s_Sf");
    static STRUCT_IF_C Ip_BFu0s_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Ip_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "Ip_BFu0s_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ip_BFu0s_Sf, Ip_BFu0s_Sf)
//============================================================================


struct  Ip_Sf_BFu0c  {
  int *v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 Ip_Sf_BFu0c) C1{ Fp FC2{} Fc:0}



static void Test_Ip_Sf_BFu0c()
{
  {
    init_simple_test("Ip_Sf_BFu0c");
    static STRUCT_IF_C Ip_Sf_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Ip_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "Ip_Sf_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ip_Sf_BFu0c, Ip_Sf_BFu0c)
//============================================================================


struct  Ip_Sf_BFu0i  {
  int *v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 Ip_Sf_BFu0i) C1{ Fp FC2{} Fi:0}



static void Test_Ip_Sf_BFu0i()
{
  {
    init_simple_test("Ip_Sf_BFu0i");
    static STRUCT_IF_C Ip_Sf_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Ip_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "Ip_Sf_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ip_Sf_BFu0i, Ip_Sf_BFu0i)
//============================================================================


struct  Ip_Sf_BFu0ll  {
  int *v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 Ip_Sf_BFu0ll) C1{ Fp FC2{} FL:0}



static void Test_Ip_Sf_BFu0ll()
{
  {
    init_simple_test("Ip_Sf_BFu0ll");
    static STRUCT_IF_C Ip_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Ip_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ip_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ip_Sf_BFu0ll, Ip_Sf_BFu0ll)
//============================================================================


struct  Ip_Sf_BFu0s  {
  int *v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 Ip_Sf_BFu0s) C1{ Fp FC2{} Fs:0}



static void Test_Ip_Sf_BFu0s()
{
  {
    init_simple_test("Ip_Sf_BFu0s");
    static STRUCT_IF_C Ip_Sf_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Ip_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ip_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "Ip_Sf_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ip_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ip_Sf_BFu0s, Ip_Sf_BFu0s)
//============================================================================


struct  L_BFu0c_Sf  {
  __tsi64 v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 L_BFu0c_Sf) C1{ FL Fc:0 FC2{}}



static void Test_L_BFu0c_Sf()
{
  {
    init_simple_test("L_BFu0c_Sf");
    static STRUCT_IF_C L_BFu0c_Sf lv;
    check2(sizeof(lv), 8, "sizeof(L_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "L_BFu0c_Sf.v1");
    check_field_offset(lv, v2, 8, "L_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_L_BFu0c_Sf, L_BFu0c_Sf)
//============================================================================


struct  L_BFu0i_Sf  {
  __tsi64 v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 L_BFu0i_Sf) C1{ FL Fi:0 FC2{}}



static void Test_L_BFu0i_Sf()
{
  {
    init_simple_test("L_BFu0i_Sf");
    static STRUCT_IF_C L_BFu0i_Sf lv;
    check2(sizeof(lv), 8, "sizeof(L_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "L_BFu0i_Sf.v1");
    check_field_offset(lv, v2, 8, "L_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_L_BFu0i_Sf, L_BFu0i_Sf)
//============================================================================


struct  L_BFu0ll_Sf  {
  __tsi64 v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 L_BFu0ll_Sf) C1{ FL FL:0 FC2{}}



static void Test_L_BFu0ll_Sf()
{
  {
    init_simple_test("L_BFu0ll_Sf");
    static STRUCT_IF_C L_BFu0ll_Sf lv;
    check2(sizeof(lv), 8, "sizeof(L_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "L_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, 8, "L_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_L_BFu0ll_Sf, L_BFu0ll_Sf)
//============================================================================


struct  L_BFu0s_Sf  {
  __tsi64 v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 L_BFu0s_Sf) C1{ FL Fs:0 FC2{}}



static void Test_L_BFu0s_Sf()
{
  {
    init_simple_test("L_BFu0s_Sf");
    static STRUCT_IF_C L_BFu0s_Sf lv;
    check2(sizeof(lv), 8, "sizeof(L_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "L_BFu0s_Sf.v1");
    check_field_offset(lv, v2, 8, "L_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_L_BFu0s_Sf, L_BFu0s_Sf)
//============================================================================


struct  L_Sf_BFu0c  {
  __tsi64 v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 L_Sf_BFu0c) C1{ FL FC2{} Fc:0}



static void Test_L_Sf_BFu0c()
{
  {
    init_simple_test("L_Sf_BFu0c");
    static STRUCT_IF_C L_Sf_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(L_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "L_Sf_BFu0c.v1");
    check_field_offset(lv, v2, 8, "L_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_L_Sf_BFu0c, L_Sf_BFu0c)
//============================================================================


struct  L_Sf_BFu0i  {
  __tsi64 v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 L_Sf_BFu0i) C1{ FL FC2{} Fi:0}



static void Test_L_Sf_BFu0i()
{
  {
    init_simple_test("L_Sf_BFu0i");
    static STRUCT_IF_C L_Sf_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(L_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "L_Sf_BFu0i.v1");
    check_field_offset(lv, v2, 8, "L_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_L_Sf_BFu0i, L_Sf_BFu0i)
//============================================================================


struct  L_Sf_BFu0ll  {
  __tsi64 v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 L_Sf_BFu0ll) C1{ FL FC2{} FL:0}



static void Test_L_Sf_BFu0ll()
{
  {
    init_simple_test("L_Sf_BFu0ll");
    static STRUCT_IF_C L_Sf_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(L_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "L_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "L_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_L_Sf_BFu0ll, L_Sf_BFu0ll)
//============================================================================


struct  L_Sf_BFu0s  {
  __tsi64 v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 L_Sf_BFu0s) C1{ FL FC2{} Fs:0}



static void Test_L_Sf_BFu0s()
{
  {
    init_simple_test("L_Sf_BFu0s");
    static STRUCT_IF_C L_Sf_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(L_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(L_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "L_Sf_BFu0s.v1");
    check_field_offset(lv, v2, 8, "L_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_L_Sf_BFu0s, L_Sf_BFu0s)
//============================================================================


struct  S_BFu0c_Sf  {
  short v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 S_BFu0c_Sf) C1{ Fs Fc:0 FC2{}}



static void Test_S_BFu0c_Sf()
{
  {
    init_simple_test("S_BFu0c_Sf");
    static STRUCT_IF_C S_BFu0c_Sf lv;
    check2(sizeof(lv), 2, "sizeof(S_BFu0c_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(S_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "S_BFu0c_Sf.v1");
    check_field_offset(lv, v2, 2, "S_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_S_BFu0c_Sf, S_BFu0c_Sf)
//============================================================================


struct  S_BFu0i_Sf  {
  short v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 S_BFu0i_Sf) C1{ Fs Fi:0 FC2{}}



static void Test_S_BFu0i_Sf()
{
  {
    init_simple_test("S_BFu0i_Sf");
    static STRUCT_IF_C S_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(S_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(S_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "S_BFu0i_Sf.v1");
    check_field_offset(lv, v2, 4, "S_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_S_BFu0i_Sf, S_BFu0i_Sf)
//============================================================================


struct  S_BFu0ll_Sf  {
  short v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 S_BFu0ll_Sf) C1{ Fs FL:0 FC2{}}



static void Test_S_BFu0ll_Sf()
{
  {
    init_simple_test("S_BFu0ll_Sf");
    static STRUCT_IF_C S_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(S_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(S_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "S_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "S_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_S_BFu0ll_Sf, S_BFu0ll_Sf)
//============================================================================


struct  S_BFu0s_Sf  {
  short v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 S_BFu0s_Sf) C1{ Fs Fs:0 FC2{}}



static void Test_S_BFu0s_Sf()
{
  {
    init_simple_test("S_BFu0s_Sf");
    static STRUCT_IF_C S_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(S_BFu0s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(S_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "S_BFu0s_Sf.v1");
    check_field_offset(lv, v2, 2, "S_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_S_BFu0s_Sf, S_BFu0s_Sf)
//============================================================================


struct  S_Sf_BFu0c  {
  short v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 S_Sf_BFu0c) C1{ Fs FC2{} Fc:0}



static void Test_S_Sf_BFu0c()
{
  {
    init_simple_test("S_Sf_BFu0c");
    static STRUCT_IF_C S_Sf_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(S_Sf_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(S_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "S_Sf_BFu0c.v1");
    check_field_offset(lv, v2, 2, "S_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_S_Sf_BFu0c, S_Sf_BFu0c)
//============================================================================


struct  S_Sf_BFu0i  {
  short v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 S_Sf_BFu0i) C1{ Fs FC2{} Fi:0}



static void Test_S_Sf_BFu0i()
{
  {
    init_simple_test("S_Sf_BFu0i");
    static STRUCT_IF_C S_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(S_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(S_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "S_Sf_BFu0i.v1");
    check_field_offset(lv, v2, 2, "S_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_S_Sf_BFu0i, S_Sf_BFu0i)
//============================================================================


struct  S_Sf_BFu0ll  {
  short v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 S_Sf_BFu0ll) C1{ Fs FC2{} FL:0}



static void Test_S_Sf_BFu0ll()
{
  {
    init_simple_test("S_Sf_BFu0ll");
    static STRUCT_IF_C S_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(S_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(S_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "S_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "S_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_S_Sf_BFu0ll, S_Sf_BFu0ll)
//============================================================================


struct  S_Sf_BFu0s  {
  short v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 S_Sf_BFu0s) C1{ Fs FC2{} Fs:0}



static void Test_S_Sf_BFu0s()
{
  {
    init_simple_test("S_Sf_BFu0s");
    static STRUCT_IF_C S_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(S_Sf_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(S_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "S_Sf_BFu0s.v1");
    check_field_offset(lv, v2, 2, "S_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_S_Sf_BFu0s, S_Sf_BFu0s)
//============================================================================


struct  Sf_BFu0c  {
  struct empty v1;
  unsigned char  :0;
};
//SIG(1 Sf_BFu0c) C1{ FC2{} Fc:0}



static void Test_Sf_BFu0c()
{
  {
    init_simple_test("Sf_BFu0c");
    static STRUCT_IF_C Sf_BFu0c lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c, Sf_BFu0c)
//============================================================================


struct  Sf_BFu0c_BFu0c  {
  struct empty v1;
  unsigned char  :0;
  unsigned char  :0;
};
//SIG(1 Sf_BFu0c_BFu0c) C1{ FC2{} Fc:0 Fc:0}



static void Test_Sf_BFu0c_BFu0c()
{
  {
    init_simple_test("Sf_BFu0c_BFu0c");
    static STRUCT_IF_C Sf_BFu0c_BFu0c lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu0c_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu0c, Sf_BFu0c_BFu0c)
//============================================================================


struct  Sf_BFu0c_BFu0i  {
  struct empty v1;
  unsigned char  :0;
  unsigned int  :0;
};
//SIG(1 Sf_BFu0c_BFu0i) C1{ FC2{} Fc:0 Fi:0}



static void Test_Sf_BFu0c_BFu0i()
{
  {
    init_simple_test("Sf_BFu0c_BFu0i");
    static STRUCT_IF_C Sf_BFu0c_BFu0i lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0c_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu0i, Sf_BFu0c_BFu0i)
//============================================================================


struct  Sf_BFu0c_BFu0ll  {
  struct empty v1;
  unsigned char  :0;
  __tsu64  :0;
};
//SIG(1 Sf_BFu0c_BFu0ll) C1{ FC2{} Fc:0 FL:0}



static void Test_Sf_BFu0c_BFu0ll()
{
  {
    init_simple_test("Sf_BFu0c_BFu0ll");
    static STRUCT_IF_C Sf_BFu0c_BFu0ll lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu0ll, Sf_BFu0c_BFu0ll)
//============================================================================


struct  Sf_BFu0c_BFu0s  {
  struct empty v1;
  unsigned char  :0;
  unsigned short  :0;
};
//SIG(1 Sf_BFu0c_BFu0s) C1{ FC2{} Fc:0 Fs:0}



static void Test_Sf_BFu0c_BFu0s()
{
  {
    init_simple_test("Sf_BFu0c_BFu0s");
    static STRUCT_IF_C Sf_BFu0c_BFu0s lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0c_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu0s, Sf_BFu0c_BFu0s)
//============================================================================


struct  Sf_BFu0c_BFu15i  {
  struct empty v1;
  unsigned char  :0;
  unsigned int v2:15;
};
//SIG(1 Sf_BFu0c_BFu15i) C1{ FC2{} Fc:0 Fi:15}



static void Test_Sf_BFu0c_BFu15i()
{
  {
    init_simple_test("Sf_BFu0c_BFu15i");
    static STRUCT_IF_C Sf_BFu0c_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0c_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0c_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu15i.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu0c_BFu15i");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu0c_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu15i, Sf_BFu0c_BFu15i)
//============================================================================


struct  Sf_BFu0c_BFu15ll  {
  struct empty v1;
  unsigned char  :0;
  __tsu64 v2:15;
};
//SIG(1 Sf_BFu0c_BFu15ll) C1{ FC2{} Fc:0 FL:15}



static void Test_Sf_BFu0c_BFu15ll()
{
  {
    init_simple_test("Sf_BFu0c_BFu15ll");
    static STRUCT_IF_C Sf_BFu0c_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0c_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu15ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu0c_BFu15ll");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu0c_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu15ll, Sf_BFu0c_BFu15ll)
//============================================================================


struct  Sf_BFu0c_BFu15s  {
  struct empty v1;
  unsigned char  :0;
  unsigned short v2:15;
};
//SIG(1 Sf_BFu0c_BFu15s) C1{ FC2{} Fc:0 Fs:15}



static void Test_Sf_BFu0c_BFu15s()
{
  {
    init_simple_test("Sf_BFu0c_BFu15s");
    static STRUCT_IF_C Sf_BFu0c_BFu15s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0c_BFu15s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0c_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu15s.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu0c_BFu15s");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu0c_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu15s, Sf_BFu0c_BFu15s)
//============================================================================


struct  Sf_BFu0c_BFu16i  {
  struct empty v1;
  unsigned char  :0;
  unsigned int v2:16;
};
//SIG(1 Sf_BFu0c_BFu16i) C1{ FC2{} Fc:0 Fi:16}



static void Test_Sf_BFu0c_BFu16i()
{
  {
    init_simple_test("Sf_BFu0c_BFu16i");
    static STRUCT_IF_C Sf_BFu0c_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0c_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0c_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu16i.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu0c_BFu16i");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu0c_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu16i, Sf_BFu0c_BFu16i)
//============================================================================


struct  Sf_BFu0c_BFu16ll  {
  struct empty v1;
  unsigned char  :0;
  __tsu64 v2:16;
};
//SIG(1 Sf_BFu0c_BFu16ll) C1{ FC2{} Fc:0 FL:16}



static void Test_Sf_BFu0c_BFu16ll()
{
  {
    init_simple_test("Sf_BFu0c_BFu16ll");
    static STRUCT_IF_C Sf_BFu0c_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0c_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu16ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu0c_BFu16ll");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu0c_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu16ll, Sf_BFu0c_BFu16ll)
//============================================================================


struct  Sf_BFu0c_BFu16s  {
  struct empty v1;
  unsigned char  :0;
  unsigned short v2:16;
};
//SIG(1 Sf_BFu0c_BFu16s) C1{ FC2{} Fc:0 Fs:16}



static void Test_Sf_BFu0c_BFu16s()
{
  {
    init_simple_test("Sf_BFu0c_BFu16s");
    static STRUCT_IF_C Sf_BFu0c_BFu16s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0c_BFu16s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0c_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu16s.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu0c_BFu16s");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu0c_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu16s, Sf_BFu0c_BFu16s)
//============================================================================


struct  Sf_BFu0c_BFu17i  {
  struct empty v1;
  unsigned char  :0;
  unsigned int v2:17;
};
//SIG(1 Sf_BFu0c_BFu17i) C1{ FC2{} Fc:0 Fi:17}



static void Test_Sf_BFu0c_BFu17i()
{
  {
    init_simple_test("Sf_BFu0c_BFu17i");
    static STRUCT_IF_C Sf_BFu0c_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0c_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0c_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu17i.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu0c_BFu17i");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu0c_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu17i, Sf_BFu0c_BFu17i)
//============================================================================


struct  Sf_BFu0c_BFu17ll  {
  struct empty v1;
  unsigned char  :0;
  __tsu64 v2:17;
};
//SIG(1 Sf_BFu0c_BFu17ll) C1{ FC2{} Fc:0 FL:17}



static void Test_Sf_BFu0c_BFu17ll()
{
  {
    init_simple_test("Sf_BFu0c_BFu17ll");
    static STRUCT_IF_C Sf_BFu0c_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0c_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu17ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu0c_BFu17ll");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu0c_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu17ll, Sf_BFu0c_BFu17ll)
//============================================================================


struct  Sf_BFu0c_BFu1c  {
  struct empty v1;
  unsigned char  :0;
  unsigned char v2:1;
};
//SIG(1 Sf_BFu0c_BFu1c) C1{ FC2{} Fc:0 Fc:1}



static void Test_Sf_BFu0c_BFu1c()
{
  {
    init_simple_test("Sf_BFu0c_BFu1c");
    static STRUCT_IF_C Sf_BFu0c_BFu1c lv;
    check2(sizeof(lv), 1, "sizeof(Sf_BFu0c_BFu1c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu0c_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu1c.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0c_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu1c, Sf_BFu0c_BFu1c)
//============================================================================


struct  Sf_BFu0c_BFu1i  {
  struct empty v1;
  unsigned char  :0;
  unsigned int v2:1;
};
//SIG(1 Sf_BFu0c_BFu1i) C1{ FC2{} Fc:0 Fi:1}



static void Test_Sf_BFu0c_BFu1i()
{
  {
    init_simple_test("Sf_BFu0c_BFu1i");
    static STRUCT_IF_C Sf_BFu0c_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0c_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0c_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu1i.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0c_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu1i, Sf_BFu0c_BFu1i)
//============================================================================


struct  Sf_BFu0c_BFu1ll  {
  struct empty v1;
  unsigned char  :0;
  __tsu64 v2:1;
};
//SIG(1 Sf_BFu0c_BFu1ll) C1{ FC2{} Fc:0 FL:1}



static void Test_Sf_BFu0c_BFu1ll()
{
  {
    init_simple_test("Sf_BFu0c_BFu1ll");
    static STRUCT_IF_C Sf_BFu0c_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0c_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu1ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0c_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu1ll, Sf_BFu0c_BFu1ll)
//============================================================================


struct  Sf_BFu0c_BFu1s  {
  struct empty v1;
  unsigned char  :0;
  unsigned short v2:1;
};
//SIG(1 Sf_BFu0c_BFu1s) C1{ FC2{} Fc:0 Fs:1}



static void Test_Sf_BFu0c_BFu1s()
{
  {
    init_simple_test("Sf_BFu0c_BFu1s");
    static STRUCT_IF_C Sf_BFu0c_BFu1s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0c_BFu1s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0c_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu1s.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0c_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu1s, Sf_BFu0c_BFu1s)
//============================================================================


struct  Sf_BFu0c_BFu31i  {
  struct empty v1;
  unsigned char  :0;
  unsigned int v2:31;
};
//SIG(1 Sf_BFu0c_BFu31i) C1{ FC2{} Fc:0 Fi:31}



static void Test_Sf_BFu0c_BFu31i()
{
  {
    init_simple_test("Sf_BFu0c_BFu31i");
    static STRUCT_IF_C Sf_BFu0c_BFu31i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0c_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0c_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu31i.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu0c_BFu31i");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu0c_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu31i, Sf_BFu0c_BFu31i)
//============================================================================


struct  Sf_BFu0c_BFu31ll  {
  struct empty v1;
  unsigned char  :0;
  __tsu64 v2:31;
};
//SIG(1 Sf_BFu0c_BFu31ll) C1{ FC2{} Fc:0 FL:31}



static void Test_Sf_BFu0c_BFu31ll()
{
  {
    init_simple_test("Sf_BFu0c_BFu31ll");
    static STRUCT_IF_C Sf_BFu0c_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0c_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu31ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu0c_BFu31ll");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu0c_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu31ll, Sf_BFu0c_BFu31ll)
//============================================================================


struct  Sf_BFu0c_BFu32i  {
  struct empty v1;
  unsigned char  :0;
  unsigned int v2:32;
};
//SIG(1 Sf_BFu0c_BFu32i) C1{ FC2{} Fc:0 Fi:32}



static void Test_Sf_BFu0c_BFu32i()
{
  {
    init_simple_test("Sf_BFu0c_BFu32i");
    static STRUCT_IF_C Sf_BFu0c_BFu32i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0c_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0c_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu32i.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu0c_BFu32i");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu0c_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu32i, Sf_BFu0c_BFu32i)
//============================================================================


struct  Sf_BFu0c_BFu32ll  {
  struct empty v1;
  unsigned char  :0;
  __tsu64 v2:32;
};
//SIG(1 Sf_BFu0c_BFu32ll) C1{ FC2{} Fc:0 FL:32}



static void Test_Sf_BFu0c_BFu32ll()
{
  {
    init_simple_test("Sf_BFu0c_BFu32ll");
    static STRUCT_IF_C Sf_BFu0c_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0c_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu32ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu0c_BFu32ll");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu0c_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu32ll, Sf_BFu0c_BFu32ll)
//============================================================================


struct  Sf_BFu0c_BFu33  {
  struct empty v1;
  unsigned char  :0;
  __tsu64 v2:33;
};
//SIG(1 Sf_BFu0c_BFu33) C1{ FC2{} Fc:0 FL:33}



static void Test_Sf_BFu0c_BFu33()
{
  {
    init_simple_test("Sf_BFu0c_BFu33");
    static STRUCT_IF_C Sf_BFu0c_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0c_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu33.v1");
    set_bf_and_test(lv, v2, 0, 0, 33, 1, "Sf_BFu0c_BFu33");
    set_bf_and_test(lv, v2, 0, 0, 33, hide_ull(1LL<<32), "Sf_BFu0c_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu33, Sf_BFu0c_BFu33)
//============================================================================


struct  Sf_BFu0c_BFu7c  {
  struct empty v1;
  unsigned char  :0;
  unsigned char v2:7;
};
//SIG(1 Sf_BFu0c_BFu7c) C1{ FC2{} Fc:0 Fc:7}



static void Test_Sf_BFu0c_BFu7c()
{
  {
    init_simple_test("Sf_BFu0c_BFu7c");
    static STRUCT_IF_C Sf_BFu0c_BFu7c lv;
    check2(sizeof(lv), 1, "sizeof(Sf_BFu0c_BFu7c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu0c_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu7c.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0c_BFu7c");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0c_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu7c, Sf_BFu0c_BFu7c)
//============================================================================


struct  Sf_BFu0c_BFu7i  {
  struct empty v1;
  unsigned char  :0;
  unsigned int v2:7;
};
//SIG(1 Sf_BFu0c_BFu7i) C1{ FC2{} Fc:0 Fi:7}



static void Test_Sf_BFu0c_BFu7i()
{
  {
    init_simple_test("Sf_BFu0c_BFu7i");
    static STRUCT_IF_C Sf_BFu0c_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0c_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0c_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu7i.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0c_BFu7i");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0c_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu7i, Sf_BFu0c_BFu7i)
//============================================================================


struct  Sf_BFu0c_BFu7ll  {
  struct empty v1;
  unsigned char  :0;
  __tsu64 v2:7;
};
//SIG(1 Sf_BFu0c_BFu7ll) C1{ FC2{} Fc:0 FL:7}



static void Test_Sf_BFu0c_BFu7ll()
{
  {
    init_simple_test("Sf_BFu0c_BFu7ll");
    static STRUCT_IF_C Sf_BFu0c_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0c_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu7ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0c_BFu7ll");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0c_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu7ll, Sf_BFu0c_BFu7ll)
//============================================================================


struct  Sf_BFu0c_BFu7s  {
  struct empty v1;
  unsigned char  :0;
  unsigned short v2:7;
};
//SIG(1 Sf_BFu0c_BFu7s) C1{ FC2{} Fc:0 Fs:7}



static void Test_Sf_BFu0c_BFu7s()
{
  {
    init_simple_test("Sf_BFu0c_BFu7s");
    static STRUCT_IF_C Sf_BFu0c_BFu7s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0c_BFu7s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0c_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu7s.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0c_BFu7s");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0c_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu7s, Sf_BFu0c_BFu7s)
//============================================================================


struct  Sf_BFu0c_BFu8c  {
  struct empty v1;
  unsigned char  :0;
  unsigned char v2:8;
};
//SIG(1 Sf_BFu0c_BFu8c) C1{ FC2{} Fc:0 Fc:8}



static void Test_Sf_BFu0c_BFu8c()
{
  {
    init_simple_test("Sf_BFu0c_BFu8c");
    static STRUCT_IF_C Sf_BFu0c_BFu8c lv;
    check2(sizeof(lv), 1, "sizeof(Sf_BFu0c_BFu8c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu0c_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu8c.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0c_BFu8c");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0c_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu8c, Sf_BFu0c_BFu8c)
//============================================================================


struct  Sf_BFu0c_BFu8i  {
  struct empty v1;
  unsigned char  :0;
  unsigned int v2:8;
};
//SIG(1 Sf_BFu0c_BFu8i) C1{ FC2{} Fc:0 Fi:8}



static void Test_Sf_BFu0c_BFu8i()
{
  {
    init_simple_test("Sf_BFu0c_BFu8i");
    static STRUCT_IF_C Sf_BFu0c_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0c_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0c_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu8i.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0c_BFu8i");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0c_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu8i, Sf_BFu0c_BFu8i)
//============================================================================


struct  Sf_BFu0c_BFu8ll  {
  struct empty v1;
  unsigned char  :0;
  __tsu64 v2:8;
};
//SIG(1 Sf_BFu0c_BFu8ll) C1{ FC2{} Fc:0 FL:8}



static void Test_Sf_BFu0c_BFu8ll()
{
  {
    init_simple_test("Sf_BFu0c_BFu8ll");
    static STRUCT_IF_C Sf_BFu0c_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0c_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu8ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0c_BFu8ll");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0c_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu8ll, Sf_BFu0c_BFu8ll)
//============================================================================


struct  Sf_BFu0c_BFu8s  {
  struct empty v1;
  unsigned char  :0;
  unsigned short v2:8;
};
//SIG(1 Sf_BFu0c_BFu8s) C1{ FC2{} Fc:0 Fs:8}



static void Test_Sf_BFu0c_BFu8s()
{
  {
    init_simple_test("Sf_BFu0c_BFu8s");
    static STRUCT_IF_C Sf_BFu0c_BFu8s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0c_BFu8s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0c_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu8s.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0c_BFu8s");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0c_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu8s, Sf_BFu0c_BFu8s)
//============================================================================


struct  Sf_BFu0c_BFu9i  {
  struct empty v1;
  unsigned char  :0;
  unsigned int v2:9;
};
//SIG(1 Sf_BFu0c_BFu9i) C1{ FC2{} Fc:0 Fi:9}



static void Test_Sf_BFu0c_BFu9i()
{
  {
    init_simple_test("Sf_BFu0c_BFu9i");
    static STRUCT_IF_C Sf_BFu0c_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0c_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0c_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu9i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu0c_BFu9i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu0c_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu9i, Sf_BFu0c_BFu9i)
//============================================================================


struct  Sf_BFu0c_BFu9ll  {
  struct empty v1;
  unsigned char  :0;
  __tsu64 v2:9;
};
//SIG(1 Sf_BFu0c_BFu9ll) C1{ FC2{} Fc:0 FL:9}



static void Test_Sf_BFu0c_BFu9ll()
{
  {
    init_simple_test("Sf_BFu0c_BFu9ll");
    static STRUCT_IF_C Sf_BFu0c_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0c_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu9ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu0c_BFu9ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu0c_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu9ll, Sf_BFu0c_BFu9ll)
//============================================================================


struct  Sf_BFu0c_BFu9s  {
  struct empty v1;
  unsigned char  :0;
  unsigned short v2:9;
};
//SIG(1 Sf_BFu0c_BFu9s) C1{ FC2{} Fc:0 Fs:9}



static void Test_Sf_BFu0c_BFu9s()
{
  {
    init_simple_test("Sf_BFu0c_BFu9s");
    static STRUCT_IF_C Sf_BFu0c_BFu9s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0c_BFu9s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0c_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_BFu9s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu0c_BFu9s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu0c_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_BFu9s, Sf_BFu0c_BFu9s)
//============================================================================


struct  Sf_BFu0c_C  {
  struct empty v1;
  unsigned char  :0;
  char v2;
};
//SIG(1 Sf_BFu0c_C) C1{ FC2{} Fc:0 Fc}



static void Test_Sf_BFu0c_C()
{
  {
    init_simple_test("Sf_BFu0c_C");
    static STRUCT_IF_C Sf_BFu0c_C lv;
    check2(sizeof(lv), 1, "sizeof(Sf_BFu0c_C)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu0c_C)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_C.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_C, Sf_BFu0c_C)
//============================================================================


struct  Sf_BFu0c_D  {
  struct empty v1;
  unsigned char  :0;
  double v2;
};
//SIG(1 Sf_BFu0c_D) C1{ FC2{} Fc:0 FL}



static void Test_Sf_BFu0c_D()
{
  {
    init_simple_test("Sf_BFu0c_D");
    static STRUCT_IF_C Sf_BFu0c_D lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0c_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_D)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_D.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_D, Sf_BFu0c_D)
//============================================================================


struct  Sf_BFu0c_F  {
  struct empty v1;
  unsigned char  :0;
  float v2;
};
//SIG(1 Sf_BFu0c_F) C1{ FC2{} Fc:0 Fi}



static void Test_Sf_BFu0c_F()
{
  {
    init_simple_test("Sf_BFu0c_F");
    static STRUCT_IF_C Sf_BFu0c_F lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0c_F)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0c_F)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_F.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_F, Sf_BFu0c_F)
//============================================================================


struct  Sf_BFu0c_I  {
  struct empty v1;
  unsigned char  :0;
  int v2;
};
//SIG(1 Sf_BFu0c_I) C1{ FC2{} Fc:0 Fi}



static void Test_Sf_BFu0c_I()
{
  {
    init_simple_test("Sf_BFu0c_I");
    static STRUCT_IF_C Sf_BFu0c_I lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0c_I)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0c_I)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_I.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_I, Sf_BFu0c_I)
//============================================================================


struct  Sf_BFu0c_Ip  {
  struct empty v1;
  unsigned char  :0;
  int *v2;
};
//SIG(1 Sf_BFu0c_Ip) C1{ FC2{} Fc:0 Fp}



static void Test_Sf_BFu0c_Ip()
{
  {
    init_simple_test("Sf_BFu0c_Ip");
    static STRUCT_IF_C Sf_BFu0c_Ip lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0c_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_Ip)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_Ip, Sf_BFu0c_Ip)
//============================================================================


struct  Sf_BFu0c_L  {
  struct empty v1;
  unsigned char  :0;
  __tsi64 v2;
};
//SIG(1 Sf_BFu0c_L) C1{ FC2{} Fc:0 FL}



static void Test_Sf_BFu0c_L()
{
  {
    init_simple_test("Sf_BFu0c_L");
    static STRUCT_IF_C Sf_BFu0c_L lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0c_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_L)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_L.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_L, Sf_BFu0c_L)
//============================================================================


struct  Sf_BFu0c_S  {
  struct empty v1;
  unsigned char  :0;
  short v2;
};
//SIG(1 Sf_BFu0c_S) C1{ FC2{} Fc:0 Fs}



static void Test_Sf_BFu0c_S()
{
  {
    init_simple_test("Sf_BFu0c_S");
    static STRUCT_IF_C Sf_BFu0c_S lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0c_S)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0c_S)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_S.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_S, Sf_BFu0c_S)
//============================================================================


struct  Sf_BFu0c_Sf  {
  struct empty v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 Sf_BFu0c_Sf) C1{ FC2{} Fc:0 FC2}



static void Test_Sf_BFu0c_Sf()
{
  {
    init_simple_test("Sf_BFu0c_Sf");
    static STRUCT_IF_C Sf_BFu0c_Sf lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_Sf, Sf_BFu0c_Sf)
//============================================================================


struct  Sf_BFu0c_Uc  {
  struct empty v1;
  unsigned char  :0;
  unsigned char v2;
};
//SIG(1 Sf_BFu0c_Uc) C1{ FC2{} Fc:0 Fc}



static void Test_Sf_BFu0c_Uc()
{
  {
    init_simple_test("Sf_BFu0c_Uc");
    static STRUCT_IF_C Sf_BFu0c_Uc lv;
    check2(sizeof(lv), 1, "sizeof(Sf_BFu0c_Uc)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu0c_Uc)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_Uc, Sf_BFu0c_Uc)
//============================================================================


struct  Sf_BFu0c_Ui  {
  struct empty v1;
  unsigned char  :0;
  unsigned int v2;
};
//SIG(1 Sf_BFu0c_Ui) C1{ FC2{} Fc:0 Fi}



static void Test_Sf_BFu0c_Ui()
{
  {
    init_simple_test("Sf_BFu0c_Ui");
    static STRUCT_IF_C Sf_BFu0c_Ui lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0c_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0c_Ui)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_Ui, Sf_BFu0c_Ui)
//============================================================================


struct  Sf_BFu0c_Ul  {
  struct empty v1;
  unsigned char  :0;
  __tsu64 v2;
};
//SIG(1 Sf_BFu0c_Ul) C1{ FC2{} Fc:0 FL}



static void Test_Sf_BFu0c_Ul()
{
  {
    init_simple_test("Sf_BFu0c_Ul");
    static STRUCT_IF_C Sf_BFu0c_Ul lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0c_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_Ul)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_Ul, Sf_BFu0c_Ul)
//============================================================================


struct  Sf_BFu0c_Us  {
  struct empty v1;
  unsigned char  :0;
  unsigned short v2;
};
//SIG(1 Sf_BFu0c_Us) C1{ FC2{} Fc:0 Fs}



static void Test_Sf_BFu0c_Us()
{
  {
    init_simple_test("Sf_BFu0c_Us");
    static STRUCT_IF_C Sf_BFu0c_Us lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0c_Us)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0c_Us)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_Us, Sf_BFu0c_Us)
//============================================================================


struct  Sf_BFu0c_Vp  {
  struct empty v1;
  unsigned char  :0;
  void *v2;
};
//SIG(1 Sf_BFu0c_Vp) C1{ FC2{} Fc:0 Fp}



static void Test_Sf_BFu0c_Vp()
{
  {
    init_simple_test("Sf_BFu0c_Vp");
    static STRUCT_IF_C Sf_BFu0c_Vp lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0c_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0c_Vp)");
    check_field_offset(lv, v1, 0, "Sf_BFu0c_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0c_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0c_Vp, Sf_BFu0c_Vp)
//============================================================================


struct  Sf_BFu0i  {
  struct empty v1;
  unsigned int  :0;
};
//SIG(1 Sf_BFu0i) C1{ FC2{} Fi:0}



static void Test_Sf_BFu0i()
{
  {
    init_simple_test("Sf_BFu0i");
    static STRUCT_IF_C Sf_BFu0i lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i, Sf_BFu0i)
//============================================================================


struct  Sf_BFu0i_BFu0c  {
  struct empty v1;
  unsigned int  :0;
  unsigned char  :0;
};
//SIG(1 Sf_BFu0i_BFu0c) C1{ FC2{} Fi:0 Fc:0}



static void Test_Sf_BFu0i_BFu0c()
{
  {
    init_simple_test("Sf_BFu0i_BFu0c");
    static STRUCT_IF_C Sf_BFu0i_BFu0c lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0i_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0i_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu0c, Sf_BFu0i_BFu0c)
//============================================================================


struct  Sf_BFu0i_BFu0i  {
  struct empty v1;
  unsigned int  :0;
  unsigned int  :0;
};
//SIG(1 Sf_BFu0i_BFu0i) C1{ FC2{} Fi:0 Fi:0}



static void Test_Sf_BFu0i_BFu0i()
{
  {
    init_simple_test("Sf_BFu0i_BFu0i");
    static STRUCT_IF_C Sf_BFu0i_BFu0i lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0i_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0i_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu0i, Sf_BFu0i_BFu0i)
//============================================================================


struct  Sf_BFu0i_BFu0ll  {
  struct empty v1;
  unsigned int  :0;
  __tsu64  :0;
};
//SIG(1 Sf_BFu0i_BFu0ll) C1{ FC2{} Fi:0 FL:0}



static void Test_Sf_BFu0i_BFu0ll()
{
  {
    init_simple_test("Sf_BFu0i_BFu0ll");
    static STRUCT_IF_C Sf_BFu0i_BFu0ll lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu0ll, Sf_BFu0i_BFu0ll)
//============================================================================


struct  Sf_BFu0i_BFu0s  {
  struct empty v1;
  unsigned int  :0;
  unsigned short  :0;
};
//SIG(1 Sf_BFu0i_BFu0s) C1{ FC2{} Fi:0 Fs:0}



static void Test_Sf_BFu0i_BFu0s()
{
  {
    init_simple_test("Sf_BFu0i_BFu0s");
    static STRUCT_IF_C Sf_BFu0i_BFu0s lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0i_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0i_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu0s, Sf_BFu0i_BFu0s)
//============================================================================


struct  Sf_BFu0i_BFu15i  {
  struct empty v1;
  unsigned int  :0;
  unsigned int v2:15;
};
//SIG(1 Sf_BFu0i_BFu15i) C1{ FC2{} Fi:0 Fi:15}



static void Test_Sf_BFu0i_BFu15i()
{
  {
    init_simple_test("Sf_BFu0i_BFu15i");
    static STRUCT_IF_C Sf_BFu0i_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0i_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0i_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu15i.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu0i_BFu15i");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu0i_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu15i, Sf_BFu0i_BFu15i)
//============================================================================


struct  Sf_BFu0i_BFu15ll  {
  struct empty v1;
  unsigned int  :0;
  __tsu64 v2:15;
};
//SIG(1 Sf_BFu0i_BFu15ll) C1{ FC2{} Fi:0 FL:15}



static void Test_Sf_BFu0i_BFu15ll()
{
  {
    init_simple_test("Sf_BFu0i_BFu15ll");
    static STRUCT_IF_C Sf_BFu0i_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0i_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu15ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu0i_BFu15ll");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu0i_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu15ll, Sf_BFu0i_BFu15ll)
//============================================================================


struct  Sf_BFu0i_BFu15s  {
  struct empty v1;
  unsigned int  :0;
  unsigned short v2:15;
};
//SIG(1 Sf_BFu0i_BFu15s) C1{ FC2{} Fi:0 Fs:15}



static void Test_Sf_BFu0i_BFu15s()
{
  {
    init_simple_test("Sf_BFu0i_BFu15s");
    static STRUCT_IF_C Sf_BFu0i_BFu15s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0i_BFu15s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0i_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu15s.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu0i_BFu15s");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu0i_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu15s, Sf_BFu0i_BFu15s)
//============================================================================


struct  Sf_BFu0i_BFu16i  {
  struct empty v1;
  unsigned int  :0;
  unsigned int v2:16;
};
//SIG(1 Sf_BFu0i_BFu16i) C1{ FC2{} Fi:0 Fi:16}



static void Test_Sf_BFu0i_BFu16i()
{
  {
    init_simple_test("Sf_BFu0i_BFu16i");
    static STRUCT_IF_C Sf_BFu0i_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0i_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0i_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu16i.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu0i_BFu16i");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu0i_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu16i, Sf_BFu0i_BFu16i)
//============================================================================


struct  Sf_BFu0i_BFu16ll  {
  struct empty v1;
  unsigned int  :0;
  __tsu64 v2:16;
};
//SIG(1 Sf_BFu0i_BFu16ll) C1{ FC2{} Fi:0 FL:16}



static void Test_Sf_BFu0i_BFu16ll()
{
  {
    init_simple_test("Sf_BFu0i_BFu16ll");
    static STRUCT_IF_C Sf_BFu0i_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0i_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu16ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu0i_BFu16ll");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu0i_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu16ll, Sf_BFu0i_BFu16ll)
//============================================================================


struct  Sf_BFu0i_BFu16s  {
  struct empty v1;
  unsigned int  :0;
  unsigned short v2:16;
};
//SIG(1 Sf_BFu0i_BFu16s) C1{ FC2{} Fi:0 Fs:16}



static void Test_Sf_BFu0i_BFu16s()
{
  {
    init_simple_test("Sf_BFu0i_BFu16s");
    static STRUCT_IF_C Sf_BFu0i_BFu16s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0i_BFu16s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0i_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu16s.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu0i_BFu16s");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu0i_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu16s, Sf_BFu0i_BFu16s)
//============================================================================


struct  Sf_BFu0i_BFu17i  {
  struct empty v1;
  unsigned int  :0;
  unsigned int v2:17;
};
//SIG(1 Sf_BFu0i_BFu17i) C1{ FC2{} Fi:0 Fi:17}



static void Test_Sf_BFu0i_BFu17i()
{
  {
    init_simple_test("Sf_BFu0i_BFu17i");
    static STRUCT_IF_C Sf_BFu0i_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0i_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0i_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu17i.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu0i_BFu17i");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu0i_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu17i, Sf_BFu0i_BFu17i)
//============================================================================


struct  Sf_BFu0i_BFu17ll  {
  struct empty v1;
  unsigned int  :0;
  __tsu64 v2:17;
};
//SIG(1 Sf_BFu0i_BFu17ll) C1{ FC2{} Fi:0 FL:17}



static void Test_Sf_BFu0i_BFu17ll()
{
  {
    init_simple_test("Sf_BFu0i_BFu17ll");
    static STRUCT_IF_C Sf_BFu0i_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0i_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu17ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu0i_BFu17ll");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu0i_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu17ll, Sf_BFu0i_BFu17ll)
//============================================================================


struct  Sf_BFu0i_BFu1c  {
  struct empty v1;
  unsigned int  :0;
  unsigned char v2:1;
};
//SIG(1 Sf_BFu0i_BFu1c) C1{ FC2{} Fi:0 Fc:1}



static void Test_Sf_BFu0i_BFu1c()
{
  {
    init_simple_test("Sf_BFu0i_BFu1c");
    static STRUCT_IF_C Sf_BFu0i_BFu1c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0i_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0i_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu1c.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0i_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu1c, Sf_BFu0i_BFu1c)
//============================================================================


struct  Sf_BFu0i_BFu1i  {
  struct empty v1;
  unsigned int  :0;
  unsigned int v2:1;
};
//SIG(1 Sf_BFu0i_BFu1i) C1{ FC2{} Fi:0 Fi:1}



static void Test_Sf_BFu0i_BFu1i()
{
  {
    init_simple_test("Sf_BFu0i_BFu1i");
    static STRUCT_IF_C Sf_BFu0i_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0i_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0i_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu1i.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0i_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu1i, Sf_BFu0i_BFu1i)
//============================================================================


struct  Sf_BFu0i_BFu1ll  {
  struct empty v1;
  unsigned int  :0;
  __tsu64 v2:1;
};
//SIG(1 Sf_BFu0i_BFu1ll) C1{ FC2{} Fi:0 FL:1}



static void Test_Sf_BFu0i_BFu1ll()
{
  {
    init_simple_test("Sf_BFu0i_BFu1ll");
    static STRUCT_IF_C Sf_BFu0i_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0i_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu1ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0i_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu1ll, Sf_BFu0i_BFu1ll)
//============================================================================


struct  Sf_BFu0i_BFu1s  {
  struct empty v1;
  unsigned int  :0;
  unsigned short v2:1;
};
//SIG(1 Sf_BFu0i_BFu1s) C1{ FC2{} Fi:0 Fs:1}



static void Test_Sf_BFu0i_BFu1s()
{
  {
    init_simple_test("Sf_BFu0i_BFu1s");
    static STRUCT_IF_C Sf_BFu0i_BFu1s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0i_BFu1s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0i_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu1s.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0i_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu1s, Sf_BFu0i_BFu1s)
//============================================================================


struct  Sf_BFu0i_BFu31i  {
  struct empty v1;
  unsigned int  :0;
  unsigned int v2:31;
};
//SIG(1 Sf_BFu0i_BFu31i) C1{ FC2{} Fi:0 Fi:31}



static void Test_Sf_BFu0i_BFu31i()
{
  {
    init_simple_test("Sf_BFu0i_BFu31i");
    static STRUCT_IF_C Sf_BFu0i_BFu31i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0i_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0i_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu31i.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu0i_BFu31i");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu0i_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu31i, Sf_BFu0i_BFu31i)
//============================================================================


struct  Sf_BFu0i_BFu31ll  {
  struct empty v1;
  unsigned int  :0;
  __tsu64 v2:31;
};
//SIG(1 Sf_BFu0i_BFu31ll) C1{ FC2{} Fi:0 FL:31}



static void Test_Sf_BFu0i_BFu31ll()
{
  {
    init_simple_test("Sf_BFu0i_BFu31ll");
    static STRUCT_IF_C Sf_BFu0i_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0i_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu31ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu0i_BFu31ll");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu0i_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu31ll, Sf_BFu0i_BFu31ll)
//============================================================================


struct  Sf_BFu0i_BFu32i  {
  struct empty v1;
  unsigned int  :0;
  unsigned int v2:32;
};
//SIG(1 Sf_BFu0i_BFu32i) C1{ FC2{} Fi:0 Fi:32}



static void Test_Sf_BFu0i_BFu32i()
{
  {
    init_simple_test("Sf_BFu0i_BFu32i");
    static STRUCT_IF_C Sf_BFu0i_BFu32i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0i_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0i_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu32i.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu0i_BFu32i");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu0i_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu32i, Sf_BFu0i_BFu32i)
//============================================================================


struct  Sf_BFu0i_BFu32ll  {
  struct empty v1;
  unsigned int  :0;
  __tsu64 v2:32;
};
//SIG(1 Sf_BFu0i_BFu32ll) C1{ FC2{} Fi:0 FL:32}



static void Test_Sf_BFu0i_BFu32ll()
{
  {
    init_simple_test("Sf_BFu0i_BFu32ll");
    static STRUCT_IF_C Sf_BFu0i_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0i_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu32ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu0i_BFu32ll");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu0i_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu32ll, Sf_BFu0i_BFu32ll)
//============================================================================


struct  Sf_BFu0i_BFu33  {
  struct empty v1;
  unsigned int  :0;
  __tsu64 v2:33;
};
//SIG(1 Sf_BFu0i_BFu33) C1{ FC2{} Fi:0 FL:33}



static void Test_Sf_BFu0i_BFu33()
{
  {
    init_simple_test("Sf_BFu0i_BFu33");
    static STRUCT_IF_C Sf_BFu0i_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0i_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu33.v1");
    set_bf_and_test(lv, v2, 0, 0, 33, 1, "Sf_BFu0i_BFu33");
    set_bf_and_test(lv, v2, 0, 0, 33, hide_ull(1LL<<32), "Sf_BFu0i_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu33, Sf_BFu0i_BFu33)
//============================================================================


struct  Sf_BFu0i_BFu7c  {
  struct empty v1;
  unsigned int  :0;
  unsigned char v2:7;
};
//SIG(1 Sf_BFu0i_BFu7c) C1{ FC2{} Fi:0 Fc:7}



static void Test_Sf_BFu0i_BFu7c()
{
  {
    init_simple_test("Sf_BFu0i_BFu7c");
    static STRUCT_IF_C Sf_BFu0i_BFu7c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0i_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0i_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu7c.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0i_BFu7c");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0i_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu7c, Sf_BFu0i_BFu7c)
//============================================================================


struct  Sf_BFu0i_BFu7i  {
  struct empty v1;
  unsigned int  :0;
  unsigned int v2:7;
};
//SIG(1 Sf_BFu0i_BFu7i) C1{ FC2{} Fi:0 Fi:7}



static void Test_Sf_BFu0i_BFu7i()
{
  {
    init_simple_test("Sf_BFu0i_BFu7i");
    static STRUCT_IF_C Sf_BFu0i_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0i_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0i_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu7i.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0i_BFu7i");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0i_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu7i, Sf_BFu0i_BFu7i)
//============================================================================


struct  Sf_BFu0i_BFu7ll  {
  struct empty v1;
  unsigned int  :0;
  __tsu64 v2:7;
};
//SIG(1 Sf_BFu0i_BFu7ll) C1{ FC2{} Fi:0 FL:7}



static void Test_Sf_BFu0i_BFu7ll()
{
  {
    init_simple_test("Sf_BFu0i_BFu7ll");
    static STRUCT_IF_C Sf_BFu0i_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0i_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu7ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0i_BFu7ll");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0i_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu7ll, Sf_BFu0i_BFu7ll)
//============================================================================


struct  Sf_BFu0i_BFu7s  {
  struct empty v1;
  unsigned int  :0;
  unsigned short v2:7;
};
//SIG(1 Sf_BFu0i_BFu7s) C1{ FC2{} Fi:0 Fs:7}



static void Test_Sf_BFu0i_BFu7s()
{
  {
    init_simple_test("Sf_BFu0i_BFu7s");
    static STRUCT_IF_C Sf_BFu0i_BFu7s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0i_BFu7s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0i_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu7s.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0i_BFu7s");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0i_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu7s, Sf_BFu0i_BFu7s)
//============================================================================


struct  Sf_BFu0i_BFu8c  {
  struct empty v1;
  unsigned int  :0;
  unsigned char v2:8;
};
//SIG(1 Sf_BFu0i_BFu8c) C1{ FC2{} Fi:0 Fc:8}



static void Test_Sf_BFu0i_BFu8c()
{
  {
    init_simple_test("Sf_BFu0i_BFu8c");
    static STRUCT_IF_C Sf_BFu0i_BFu8c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0i_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0i_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu8c.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0i_BFu8c");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0i_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu8c, Sf_BFu0i_BFu8c)
//============================================================================


struct  Sf_BFu0i_BFu8i  {
  struct empty v1;
  unsigned int  :0;
  unsigned int v2:8;
};
//SIG(1 Sf_BFu0i_BFu8i) C1{ FC2{} Fi:0 Fi:8}



static void Test_Sf_BFu0i_BFu8i()
{
  {
    init_simple_test("Sf_BFu0i_BFu8i");
    static STRUCT_IF_C Sf_BFu0i_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0i_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0i_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu8i.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0i_BFu8i");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0i_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu8i, Sf_BFu0i_BFu8i)
//============================================================================


struct  Sf_BFu0i_BFu8ll  {
  struct empty v1;
  unsigned int  :0;
  __tsu64 v2:8;
};
//SIG(1 Sf_BFu0i_BFu8ll) C1{ FC2{} Fi:0 FL:8}



static void Test_Sf_BFu0i_BFu8ll()
{
  {
    init_simple_test("Sf_BFu0i_BFu8ll");
    static STRUCT_IF_C Sf_BFu0i_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0i_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu8ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0i_BFu8ll");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0i_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu8ll, Sf_BFu0i_BFu8ll)
//============================================================================


struct  Sf_BFu0i_BFu8s  {
  struct empty v1;
  unsigned int  :0;
  unsigned short v2:8;
};
//SIG(1 Sf_BFu0i_BFu8s) C1{ FC2{} Fi:0 Fs:8}



static void Test_Sf_BFu0i_BFu8s()
{
  {
    init_simple_test("Sf_BFu0i_BFu8s");
    static STRUCT_IF_C Sf_BFu0i_BFu8s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0i_BFu8s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0i_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu8s.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0i_BFu8s");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0i_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu8s, Sf_BFu0i_BFu8s)
//============================================================================


struct  Sf_BFu0i_BFu9i  {
  struct empty v1;
  unsigned int  :0;
  unsigned int v2:9;
};
//SIG(1 Sf_BFu0i_BFu9i) C1{ FC2{} Fi:0 Fi:9}



static void Test_Sf_BFu0i_BFu9i()
{
  {
    init_simple_test("Sf_BFu0i_BFu9i");
    static STRUCT_IF_C Sf_BFu0i_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0i_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0i_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu9i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu0i_BFu9i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu0i_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu9i, Sf_BFu0i_BFu9i)
//============================================================================


struct  Sf_BFu0i_BFu9ll  {
  struct empty v1;
  unsigned int  :0;
  __tsu64 v2:9;
};
//SIG(1 Sf_BFu0i_BFu9ll) C1{ FC2{} Fi:0 FL:9}



static void Test_Sf_BFu0i_BFu9ll()
{
  {
    init_simple_test("Sf_BFu0i_BFu9ll");
    static STRUCT_IF_C Sf_BFu0i_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0i_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu9ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu0i_BFu9ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu0i_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu9ll, Sf_BFu0i_BFu9ll)
//============================================================================


struct  Sf_BFu0i_BFu9s  {
  struct empty v1;
  unsigned int  :0;
  unsigned short v2:9;
};
//SIG(1 Sf_BFu0i_BFu9s) C1{ FC2{} Fi:0 Fs:9}



static void Test_Sf_BFu0i_BFu9s()
{
  {
    init_simple_test("Sf_BFu0i_BFu9s");
    static STRUCT_IF_C Sf_BFu0i_BFu9s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0i_BFu9s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0i_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_BFu9s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu0i_BFu9s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu0i_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_BFu9s, Sf_BFu0i_BFu9s)
//============================================================================


struct  Sf_BFu0i_C  {
  struct empty v1;
  unsigned int  :0;
  char v2;
};
//SIG(1 Sf_BFu0i_C) C1{ FC2{} Fi:0 Fc}



static void Test_Sf_BFu0i_C()
{
  {
    init_simple_test("Sf_BFu0i_C");
    static STRUCT_IF_C Sf_BFu0i_C lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0i_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0i_C)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_C.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_C, Sf_BFu0i_C)
//============================================================================


struct  Sf_BFu0i_D  {
  struct empty v1;
  unsigned int  :0;
  double v2;
};
//SIG(1 Sf_BFu0i_D) C1{ FC2{} Fi:0 FL}



static void Test_Sf_BFu0i_D()
{
  {
    init_simple_test("Sf_BFu0i_D");
    static STRUCT_IF_C Sf_BFu0i_D lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0i_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_D)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_D.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_D, Sf_BFu0i_D)
//============================================================================


struct  Sf_BFu0i_F  {
  struct empty v1;
  unsigned int  :0;
  float v2;
};
//SIG(1 Sf_BFu0i_F) C1{ FC2{} Fi:0 Fi}



static void Test_Sf_BFu0i_F()
{
  {
    init_simple_test("Sf_BFu0i_F");
    static STRUCT_IF_C Sf_BFu0i_F lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0i_F)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0i_F)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_F.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_F, Sf_BFu0i_F)
//============================================================================


struct  Sf_BFu0i_I  {
  struct empty v1;
  unsigned int  :0;
  int v2;
};
//SIG(1 Sf_BFu0i_I) C1{ FC2{} Fi:0 Fi}



static void Test_Sf_BFu0i_I()
{
  {
    init_simple_test("Sf_BFu0i_I");
    static STRUCT_IF_C Sf_BFu0i_I lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0i_I)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0i_I)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_I.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_I, Sf_BFu0i_I)
//============================================================================


struct  Sf_BFu0i_Ip  {
  struct empty v1;
  unsigned int  :0;
  int *v2;
};
//SIG(1 Sf_BFu0i_Ip) C1{ FC2{} Fi:0 Fp}



static void Test_Sf_BFu0i_Ip()
{
  {
    init_simple_test("Sf_BFu0i_Ip");
    static STRUCT_IF_C Sf_BFu0i_Ip lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0i_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_Ip)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_Ip, Sf_BFu0i_Ip)
//============================================================================


struct  Sf_BFu0i_L  {
  struct empty v1;
  unsigned int  :0;
  __tsi64 v2;
};
//SIG(1 Sf_BFu0i_L) C1{ FC2{} Fi:0 FL}



static void Test_Sf_BFu0i_L()
{
  {
    init_simple_test("Sf_BFu0i_L");
    static STRUCT_IF_C Sf_BFu0i_L lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0i_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_L)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_L.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_L, Sf_BFu0i_L)
//============================================================================


struct  Sf_BFu0i_S  {
  struct empty v1;
  unsigned int  :0;
  short v2;
};
//SIG(1 Sf_BFu0i_S) C1{ FC2{} Fi:0 Fs}



static void Test_Sf_BFu0i_S()
{
  {
    init_simple_test("Sf_BFu0i_S");
    static STRUCT_IF_C Sf_BFu0i_S lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0i_S)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0i_S)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_S.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_S, Sf_BFu0i_S)
//============================================================================


struct  Sf_BFu0i_Sf  {
  struct empty v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 Sf_BFu0i_Sf) C1{ FC2{} Fi:0 FC2}



static void Test_Sf_BFu0i_Sf()
{
  {
    init_simple_test("Sf_BFu0i_Sf");
    static STRUCT_IF_C Sf_BFu0i_Sf lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_Sf, Sf_BFu0i_Sf)
//============================================================================


struct  Sf_BFu0i_Uc  {
  struct empty v1;
  unsigned int  :0;
  unsigned char v2;
};
//SIG(1 Sf_BFu0i_Uc) C1{ FC2{} Fi:0 Fc}



static void Test_Sf_BFu0i_Uc()
{
  {
    init_simple_test("Sf_BFu0i_Uc");
    static STRUCT_IF_C Sf_BFu0i_Uc lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0i_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0i_Uc)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_Uc, Sf_BFu0i_Uc)
//============================================================================


struct  Sf_BFu0i_Ui  {
  struct empty v1;
  unsigned int  :0;
  unsigned int v2;
};
//SIG(1 Sf_BFu0i_Ui) C1{ FC2{} Fi:0 Fi}



static void Test_Sf_BFu0i_Ui()
{
  {
    init_simple_test("Sf_BFu0i_Ui");
    static STRUCT_IF_C Sf_BFu0i_Ui lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0i_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0i_Ui)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_Ui, Sf_BFu0i_Ui)
//============================================================================


struct  Sf_BFu0i_Ul  {
  struct empty v1;
  unsigned int  :0;
  __tsu64 v2;
};
//SIG(1 Sf_BFu0i_Ul) C1{ FC2{} Fi:0 FL}



static void Test_Sf_BFu0i_Ul()
{
  {
    init_simple_test("Sf_BFu0i_Ul");
    static STRUCT_IF_C Sf_BFu0i_Ul lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0i_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_Ul)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_Ul, Sf_BFu0i_Ul)
//============================================================================


struct  Sf_BFu0i_Us  {
  struct empty v1;
  unsigned int  :0;
  unsigned short v2;
};
//SIG(1 Sf_BFu0i_Us) C1{ FC2{} Fi:0 Fs}



static void Test_Sf_BFu0i_Us()
{
  {
    init_simple_test("Sf_BFu0i_Us");
    static STRUCT_IF_C Sf_BFu0i_Us lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0i_Us)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0i_Us)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_Us, Sf_BFu0i_Us)
//============================================================================


struct  Sf_BFu0i_Vp  {
  struct empty v1;
  unsigned int  :0;
  void *v2;
};
//SIG(1 Sf_BFu0i_Vp) C1{ FC2{} Fi:0 Fp}



static void Test_Sf_BFu0i_Vp()
{
  {
    init_simple_test("Sf_BFu0i_Vp");
    static STRUCT_IF_C Sf_BFu0i_Vp lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0i_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0i_Vp)");
    check_field_offset(lv, v1, 0, "Sf_BFu0i_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0i_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0i_Vp, Sf_BFu0i_Vp)
//============================================================================


struct  Sf_BFu0ll  {
  struct empty v1;
  __tsu64  :0;
};
//SIG(1 Sf_BFu0ll) C1{ FC2{} FL:0}



static void Test_Sf_BFu0ll()
{
  {
    init_simple_test("Sf_BFu0ll");
    static STRUCT_IF_C Sf_BFu0ll lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll, Sf_BFu0ll)
//============================================================================


struct  Sf_BFu0ll_BFu0c  {
  struct empty v1;
  __tsu64  :0;
  unsigned char  :0;
};
//SIG(1 Sf_BFu0ll_BFu0c) C1{ FC2{} FL:0 Fc:0}



static void Test_Sf_BFu0ll_BFu0c()
{
  {
    init_simple_test("Sf_BFu0ll_BFu0c");
    static STRUCT_IF_C Sf_BFu0ll_BFu0c lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu0c, Sf_BFu0ll_BFu0c)
//============================================================================


struct  Sf_BFu0ll_BFu0i  {
  struct empty v1;
  __tsu64  :0;
  unsigned int  :0;
};
//SIG(1 Sf_BFu0ll_BFu0i) C1{ FC2{} FL:0 Fi:0}



static void Test_Sf_BFu0ll_BFu0i()
{
  {
    init_simple_test("Sf_BFu0ll_BFu0i");
    static STRUCT_IF_C Sf_BFu0ll_BFu0i lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu0i, Sf_BFu0ll_BFu0i)
//============================================================================


struct  Sf_BFu0ll_BFu0ll  {
  struct empty v1;
  __tsu64  :0;
  __tsu64  :0;
};
//SIG(1 Sf_BFu0ll_BFu0ll) C1{ FC2{} FL:0 FL:0}



static void Test_Sf_BFu0ll_BFu0ll()
{
  {
    init_simple_test("Sf_BFu0ll_BFu0ll");
    static STRUCT_IF_C Sf_BFu0ll_BFu0ll lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu0ll, Sf_BFu0ll_BFu0ll)
//============================================================================


struct  Sf_BFu0ll_BFu0s  {
  struct empty v1;
  __tsu64  :0;
  unsigned short  :0;
};
//SIG(1 Sf_BFu0ll_BFu0s) C1{ FC2{} FL:0 Fs:0}



static void Test_Sf_BFu0ll_BFu0s()
{
  {
    init_simple_test("Sf_BFu0ll_BFu0s");
    static STRUCT_IF_C Sf_BFu0ll_BFu0s lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu0s, Sf_BFu0ll_BFu0s)
//============================================================================


struct  Sf_BFu0ll_BFu15i  {
  struct empty v1;
  __tsu64  :0;
  unsigned int v2:15;
};
//SIG(1 Sf_BFu0ll_BFu15i) C1{ FC2{} FL:0 Fi:15}



static void Test_Sf_BFu0ll_BFu15i()
{
  {
    init_simple_test("Sf_BFu0ll_BFu15i");
    static STRUCT_IF_C Sf_BFu0ll_BFu15i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Sf_BFu0ll_BFu15i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu0ll_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu15i.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu0ll_BFu15i");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu0ll_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu15i, Sf_BFu0ll_BFu15i)
//============================================================================


struct  Sf_BFu0ll_BFu15ll  {
  struct empty v1;
  __tsu64  :0;
  __tsu64 v2:15;
};
//SIG(1 Sf_BFu0ll_BFu15ll) C1{ FC2{} FL:0 FL:15}



static void Test_Sf_BFu0ll_BFu15ll()
{
  {
    init_simple_test("Sf_BFu0ll_BFu15ll");
    static STRUCT_IF_C Sf_BFu0ll_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0ll_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu15ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu0ll_BFu15ll");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu0ll_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu15ll, Sf_BFu0ll_BFu15ll)
//============================================================================


struct  Sf_BFu0ll_BFu15s  {
  struct empty v1;
  __tsu64  :0;
  unsigned short v2:15;
};
//SIG(1 Sf_BFu0ll_BFu15s) C1{ FC2{} FL:0 Fs:15}



static void Test_Sf_BFu0ll_BFu15s()
{
  {
    init_simple_test("Sf_BFu0ll_BFu15s");
    static STRUCT_IF_C Sf_BFu0ll_BFu15s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0ll_BFu15s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0ll_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu15s.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu0ll_BFu15s");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu0ll_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu15s, Sf_BFu0ll_BFu15s)
//============================================================================


struct  Sf_BFu0ll_BFu16i  {
  struct empty v1;
  __tsu64  :0;
  unsigned int v2:16;
};
//SIG(1 Sf_BFu0ll_BFu16i) C1{ FC2{} FL:0 Fi:16}



static void Test_Sf_BFu0ll_BFu16i()
{
  {
    init_simple_test("Sf_BFu0ll_BFu16i");
    static STRUCT_IF_C Sf_BFu0ll_BFu16i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Sf_BFu0ll_BFu16i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu0ll_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu16i.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu0ll_BFu16i");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu0ll_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu16i, Sf_BFu0ll_BFu16i)
//============================================================================


struct  Sf_BFu0ll_BFu16ll  {
  struct empty v1;
  __tsu64  :0;
  __tsu64 v2:16;
};
//SIG(1 Sf_BFu0ll_BFu16ll) C1{ FC2{} FL:0 FL:16}



static void Test_Sf_BFu0ll_BFu16ll()
{
  {
    init_simple_test("Sf_BFu0ll_BFu16ll");
    static STRUCT_IF_C Sf_BFu0ll_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0ll_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu16ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu0ll_BFu16ll");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu0ll_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu16ll, Sf_BFu0ll_BFu16ll)
//============================================================================


struct  Sf_BFu0ll_BFu16s  {
  struct empty v1;
  __tsu64  :0;
  unsigned short v2:16;
};
//SIG(1 Sf_BFu0ll_BFu16s) C1{ FC2{} FL:0 Fs:16}



static void Test_Sf_BFu0ll_BFu16s()
{
  {
    init_simple_test("Sf_BFu0ll_BFu16s");
    static STRUCT_IF_C Sf_BFu0ll_BFu16s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0ll_BFu16s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0ll_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu16s.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu0ll_BFu16s");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu0ll_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu16s, Sf_BFu0ll_BFu16s)
//============================================================================


struct  Sf_BFu0ll_BFu17i  {
  struct empty v1;
  __tsu64  :0;
  unsigned int v2:17;
};
//SIG(1 Sf_BFu0ll_BFu17i) C1{ FC2{} FL:0 Fi:17}



static void Test_Sf_BFu0ll_BFu17i()
{
  {
    init_simple_test("Sf_BFu0ll_BFu17i");
    static STRUCT_IF_C Sf_BFu0ll_BFu17i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Sf_BFu0ll_BFu17i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu0ll_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu17i.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu0ll_BFu17i");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu0ll_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu17i, Sf_BFu0ll_BFu17i)
//============================================================================


struct  Sf_BFu0ll_BFu17ll  {
  struct empty v1;
  __tsu64  :0;
  __tsu64 v2:17;
};
//SIG(1 Sf_BFu0ll_BFu17ll) C1{ FC2{} FL:0 FL:17}



static void Test_Sf_BFu0ll_BFu17ll()
{
  {
    init_simple_test("Sf_BFu0ll_BFu17ll");
    static STRUCT_IF_C Sf_BFu0ll_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0ll_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu17ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu0ll_BFu17ll");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu0ll_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu17ll, Sf_BFu0ll_BFu17ll)
//============================================================================


struct  Sf_BFu0ll_BFu1c  {
  struct empty v1;
  __tsu64  :0;
  unsigned char v2:1;
};
//SIG(1 Sf_BFu0ll_BFu1c) C1{ FC2{} FL:0 Fc:1}



static void Test_Sf_BFu0ll_BFu1c()
{
  {
    init_simple_test("Sf_BFu0ll_BFu1c");
    static STRUCT_IF_C Sf_BFu0ll_BFu1c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0ll_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0ll_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu1c.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0ll_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu1c, Sf_BFu0ll_BFu1c)
//============================================================================


struct  Sf_BFu0ll_BFu1i  {
  struct empty v1;
  __tsu64  :0;
  unsigned int v2:1;
};
//SIG(1 Sf_BFu0ll_BFu1i) C1{ FC2{} FL:0 Fi:1}



static void Test_Sf_BFu0ll_BFu1i()
{
  {
    init_simple_test("Sf_BFu0ll_BFu1i");
    static STRUCT_IF_C Sf_BFu0ll_BFu1i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Sf_BFu0ll_BFu1i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu0ll_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu1i.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0ll_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu1i, Sf_BFu0ll_BFu1i)
//============================================================================


struct  Sf_BFu0ll_BFu1ll  {
  struct empty v1;
  __tsu64  :0;
  __tsu64 v2:1;
};
//SIG(1 Sf_BFu0ll_BFu1ll) C1{ FC2{} FL:0 FL:1}



static void Test_Sf_BFu0ll_BFu1ll()
{
  {
    init_simple_test("Sf_BFu0ll_BFu1ll");
    static STRUCT_IF_C Sf_BFu0ll_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0ll_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu1ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0ll_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu1ll, Sf_BFu0ll_BFu1ll)
//============================================================================


struct  Sf_BFu0ll_BFu1s  {
  struct empty v1;
  __tsu64  :0;
  unsigned short v2:1;
};
//SIG(1 Sf_BFu0ll_BFu1s) C1{ FC2{} FL:0 Fs:1}



static void Test_Sf_BFu0ll_BFu1s()
{
  {
    init_simple_test("Sf_BFu0ll_BFu1s");
    static STRUCT_IF_C Sf_BFu0ll_BFu1s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0ll_BFu1s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0ll_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu1s.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0ll_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu1s, Sf_BFu0ll_BFu1s)
//============================================================================


struct  Sf_BFu0ll_BFu31i  {
  struct empty v1;
  __tsu64  :0;
  unsigned int v2:31;
};
//SIG(1 Sf_BFu0ll_BFu31i) C1{ FC2{} FL:0 Fi:31}



static void Test_Sf_BFu0ll_BFu31i()
{
  {
    init_simple_test("Sf_BFu0ll_BFu31i");
    static STRUCT_IF_C Sf_BFu0ll_BFu31i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Sf_BFu0ll_BFu31i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu0ll_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu31i.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu0ll_BFu31i");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu0ll_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu31i, Sf_BFu0ll_BFu31i)
//============================================================================


struct  Sf_BFu0ll_BFu31ll  {
  struct empty v1;
  __tsu64  :0;
  __tsu64 v2:31;
};
//SIG(1 Sf_BFu0ll_BFu31ll) C1{ FC2{} FL:0 FL:31}



static void Test_Sf_BFu0ll_BFu31ll()
{
  {
    init_simple_test("Sf_BFu0ll_BFu31ll");
    static STRUCT_IF_C Sf_BFu0ll_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0ll_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu31ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu0ll_BFu31ll");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu0ll_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu31ll, Sf_BFu0ll_BFu31ll)
//============================================================================


struct  Sf_BFu0ll_BFu32i  {
  struct empty v1;
  __tsu64  :0;
  unsigned int v2:32;
};
//SIG(1 Sf_BFu0ll_BFu32i) C1{ FC2{} FL:0 Fi:32}



static void Test_Sf_BFu0ll_BFu32i()
{
  {
    init_simple_test("Sf_BFu0ll_BFu32i");
    static STRUCT_IF_C Sf_BFu0ll_BFu32i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Sf_BFu0ll_BFu32i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu0ll_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu32i.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu0ll_BFu32i");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu0ll_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu32i, Sf_BFu0ll_BFu32i)
//============================================================================


struct  Sf_BFu0ll_BFu32ll  {
  struct empty v1;
  __tsu64  :0;
  __tsu64 v2:32;
};
//SIG(1 Sf_BFu0ll_BFu32ll) C1{ FC2{} FL:0 FL:32}



static void Test_Sf_BFu0ll_BFu32ll()
{
  {
    init_simple_test("Sf_BFu0ll_BFu32ll");
    static STRUCT_IF_C Sf_BFu0ll_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0ll_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu32ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu0ll_BFu32ll");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu0ll_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu32ll, Sf_BFu0ll_BFu32ll)
//============================================================================


struct  Sf_BFu0ll_BFu33  {
  struct empty v1;
  __tsu64  :0;
  __tsu64 v2:33;
};
//SIG(1 Sf_BFu0ll_BFu33) C1{ FC2{} FL:0 FL:33}



static void Test_Sf_BFu0ll_BFu33()
{
  {
    init_simple_test("Sf_BFu0ll_BFu33");
    static STRUCT_IF_C Sf_BFu0ll_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0ll_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu33.v1");
    set_bf_and_test(lv, v2, 0, 0, 33, 1, "Sf_BFu0ll_BFu33");
    set_bf_and_test(lv, v2, 0, 0, 33, hide_ull(1LL<<32), "Sf_BFu0ll_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu33, Sf_BFu0ll_BFu33)
//============================================================================


struct  Sf_BFu0ll_BFu7c  {
  struct empty v1;
  __tsu64  :0;
  unsigned char v2:7;
};
//SIG(1 Sf_BFu0ll_BFu7c) C1{ FC2{} FL:0 Fc:7}



static void Test_Sf_BFu0ll_BFu7c()
{
  {
    init_simple_test("Sf_BFu0ll_BFu7c");
    static STRUCT_IF_C Sf_BFu0ll_BFu7c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0ll_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0ll_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu7c.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0ll_BFu7c");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0ll_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu7c, Sf_BFu0ll_BFu7c)
//============================================================================


struct  Sf_BFu0ll_BFu7i  {
  struct empty v1;
  __tsu64  :0;
  unsigned int v2:7;
};
//SIG(1 Sf_BFu0ll_BFu7i) C1{ FC2{} FL:0 Fi:7}



static void Test_Sf_BFu0ll_BFu7i()
{
  {
    init_simple_test("Sf_BFu0ll_BFu7i");
    static STRUCT_IF_C Sf_BFu0ll_BFu7i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Sf_BFu0ll_BFu7i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu0ll_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu7i.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0ll_BFu7i");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0ll_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu7i, Sf_BFu0ll_BFu7i)
//============================================================================


struct  Sf_BFu0ll_BFu7ll  {
  struct empty v1;
  __tsu64  :0;
  __tsu64 v2:7;
};
//SIG(1 Sf_BFu0ll_BFu7ll) C1{ FC2{} FL:0 FL:7}



static void Test_Sf_BFu0ll_BFu7ll()
{
  {
    init_simple_test("Sf_BFu0ll_BFu7ll");
    static STRUCT_IF_C Sf_BFu0ll_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0ll_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu7ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0ll_BFu7ll");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0ll_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu7ll, Sf_BFu0ll_BFu7ll)
//============================================================================


struct  Sf_BFu0ll_BFu7s  {
  struct empty v1;
  __tsu64  :0;
  unsigned short v2:7;
};
//SIG(1 Sf_BFu0ll_BFu7s) C1{ FC2{} FL:0 Fs:7}



static void Test_Sf_BFu0ll_BFu7s()
{
  {
    init_simple_test("Sf_BFu0ll_BFu7s");
    static STRUCT_IF_C Sf_BFu0ll_BFu7s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0ll_BFu7s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0ll_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu7s.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0ll_BFu7s");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0ll_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu7s, Sf_BFu0ll_BFu7s)
//============================================================================


struct  Sf_BFu0ll_BFu8c  {
  struct empty v1;
  __tsu64  :0;
  unsigned char v2:8;
};
//SIG(1 Sf_BFu0ll_BFu8c) C1{ FC2{} FL:0 Fc:8}



static void Test_Sf_BFu0ll_BFu8c()
{
  {
    init_simple_test("Sf_BFu0ll_BFu8c");
    static STRUCT_IF_C Sf_BFu0ll_BFu8c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0ll_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0ll_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu8c.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0ll_BFu8c");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0ll_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu8c, Sf_BFu0ll_BFu8c)
//============================================================================


struct  Sf_BFu0ll_BFu8i  {
  struct empty v1;
  __tsu64  :0;
  unsigned int v2:8;
};
//SIG(1 Sf_BFu0ll_BFu8i) C1{ FC2{} FL:0 Fi:8}



static void Test_Sf_BFu0ll_BFu8i()
{
  {
    init_simple_test("Sf_BFu0ll_BFu8i");
    static STRUCT_IF_C Sf_BFu0ll_BFu8i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Sf_BFu0ll_BFu8i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu0ll_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu8i.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0ll_BFu8i");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0ll_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu8i, Sf_BFu0ll_BFu8i)
//============================================================================


struct  Sf_BFu0ll_BFu8ll  {
  struct empty v1;
  __tsu64  :0;
  __tsu64 v2:8;
};
//SIG(1 Sf_BFu0ll_BFu8ll) C1{ FC2{} FL:0 FL:8}



static void Test_Sf_BFu0ll_BFu8ll()
{
  {
    init_simple_test("Sf_BFu0ll_BFu8ll");
    static STRUCT_IF_C Sf_BFu0ll_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0ll_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu8ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0ll_BFu8ll");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0ll_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu8ll, Sf_BFu0ll_BFu8ll)
//============================================================================


struct  Sf_BFu0ll_BFu8s  {
  struct empty v1;
  __tsu64  :0;
  unsigned short v2:8;
};
//SIG(1 Sf_BFu0ll_BFu8s) C1{ FC2{} FL:0 Fs:8}



static void Test_Sf_BFu0ll_BFu8s()
{
  {
    init_simple_test("Sf_BFu0ll_BFu8s");
    static STRUCT_IF_C Sf_BFu0ll_BFu8s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0ll_BFu8s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0ll_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu8s.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0ll_BFu8s");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0ll_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu8s, Sf_BFu0ll_BFu8s)
//============================================================================


struct  Sf_BFu0ll_BFu9i  {
  struct empty v1;
  __tsu64  :0;
  unsigned int v2:9;
};
//SIG(1 Sf_BFu0ll_BFu9i) C1{ FC2{} FL:0 Fi:9}



static void Test_Sf_BFu0ll_BFu9i()
{
  {
    init_simple_test("Sf_BFu0ll_BFu9i");
    static STRUCT_IF_C Sf_BFu0ll_BFu9i lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Sf_BFu0ll_BFu9i)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu0ll_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu9i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu0ll_BFu9i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu0ll_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu9i, Sf_BFu0ll_BFu9i)
//============================================================================


struct  Sf_BFu0ll_BFu9ll  {
  struct empty v1;
  __tsu64  :0;
  __tsu64 v2:9;
};
//SIG(1 Sf_BFu0ll_BFu9ll) C1{ FC2{} FL:0 FL:9}



static void Test_Sf_BFu0ll_BFu9ll()
{
  {
    init_simple_test("Sf_BFu0ll_BFu9ll");
    static STRUCT_IF_C Sf_BFu0ll_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0ll_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu9ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu0ll_BFu9ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu0ll_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu9ll, Sf_BFu0ll_BFu9ll)
//============================================================================


struct  Sf_BFu0ll_BFu9s  {
  struct empty v1;
  __tsu64  :0;
  unsigned short v2:9;
};
//SIG(1 Sf_BFu0ll_BFu9s) C1{ FC2{} FL:0 Fs:9}



static void Test_Sf_BFu0ll_BFu9s()
{
  {
    init_simple_test("Sf_BFu0ll_BFu9s");
    static STRUCT_IF_C Sf_BFu0ll_BFu9s lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0ll_BFu9s)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0ll_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_BFu9s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu0ll_BFu9s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu0ll_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_BFu9s, Sf_BFu0ll_BFu9s)
//============================================================================


struct  Sf_BFu0ll_C  {
  struct empty v1;
  __tsu64  :0;
  char v2;
};
//SIG(1 Sf_BFu0ll_C) C1{ FC2{} FL:0 Fc}



static void Test_Sf_BFu0ll_C()
{
  {
    init_simple_test("Sf_BFu0ll_C");
    static STRUCT_IF_C Sf_BFu0ll_C lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0ll_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0ll_C)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_C.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_C, Sf_BFu0ll_C)
//============================================================================


struct  Sf_BFu0ll_D  {
  struct empty v1;
  __tsu64  :0;
  double v2;
};
//SIG(1 Sf_BFu0ll_D) C1{ FC2{} FL:0 FL}



static void Test_Sf_BFu0ll_D()
{
  {
    init_simple_test("Sf_BFu0ll_D");
    static STRUCT_IF_C Sf_BFu0ll_D lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0ll_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_D)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_D.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_D, Sf_BFu0ll_D)
//============================================================================


struct  Sf_BFu0ll_F  {
  struct empty v1;
  __tsu64  :0;
  float v2;
};
//SIG(1 Sf_BFu0ll_F) C1{ FC2{} FL:0 Fi}



static void Test_Sf_BFu0ll_F()
{
  {
    init_simple_test("Sf_BFu0ll_F");
    static STRUCT_IF_C Sf_BFu0ll_F lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Sf_BFu0ll_F)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu0ll_F)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_F.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_F, Sf_BFu0ll_F)
//============================================================================


struct  Sf_BFu0ll_I  {
  struct empty v1;
  __tsu64  :0;
  int v2;
};
//SIG(1 Sf_BFu0ll_I) C1{ FC2{} FL:0 Fi}



static void Test_Sf_BFu0ll_I()
{
  {
    init_simple_test("Sf_BFu0ll_I");
    static STRUCT_IF_C Sf_BFu0ll_I lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Sf_BFu0ll_I)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu0ll_I)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_I.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_I, Sf_BFu0ll_I)
//============================================================================


struct  Sf_BFu0ll_Ip  {
  struct empty v1;
  __tsu64  :0;
  int *v2;
};
//SIG(1 Sf_BFu0ll_Ip) C1{ FC2{} FL:0 Fp}



static void Test_Sf_BFu0ll_Ip()
{
  {
    init_simple_test("Sf_BFu0ll_Ip");
    static STRUCT_IF_C Sf_BFu0ll_Ip lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0ll_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_Ip)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_Ip, Sf_BFu0ll_Ip)
//============================================================================


struct  Sf_BFu0ll_L  {
  struct empty v1;
  __tsu64  :0;
  __tsi64 v2;
};
//SIG(1 Sf_BFu0ll_L) C1{ FC2{} FL:0 FL}



static void Test_Sf_BFu0ll_L()
{
  {
    init_simple_test("Sf_BFu0ll_L");
    static STRUCT_IF_C Sf_BFu0ll_L lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0ll_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_L)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_L.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_L, Sf_BFu0ll_L)
//============================================================================


struct  Sf_BFu0ll_S  {
  struct empty v1;
  __tsu64  :0;
  short v2;
};
//SIG(1 Sf_BFu0ll_S) C1{ FC2{} FL:0 Fs}



static void Test_Sf_BFu0ll_S()
{
  {
    init_simple_test("Sf_BFu0ll_S");
    static STRUCT_IF_C Sf_BFu0ll_S lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0ll_S)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0ll_S)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_S.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_S, Sf_BFu0ll_S)
//============================================================================


struct  Sf_BFu0ll_Sf  {
  struct empty v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 Sf_BFu0ll_Sf) C1{ FC2{} FL:0 FC2}



static void Test_Sf_BFu0ll_Sf()
{
  {
    init_simple_test("Sf_BFu0ll_Sf");
    static STRUCT_IF_C Sf_BFu0ll_Sf lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_Sf, Sf_BFu0ll_Sf)
//============================================================================


struct  Sf_BFu0ll_Uc  {
  struct empty v1;
  __tsu64  :0;
  unsigned char v2;
};
//SIG(1 Sf_BFu0ll_Uc) C1{ FC2{} FL:0 Fc}



static void Test_Sf_BFu0ll_Uc()
{
  {
    init_simple_test("Sf_BFu0ll_Uc");
    static STRUCT_IF_C Sf_BFu0ll_Uc lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0ll_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0ll_Uc)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_Uc, Sf_BFu0ll_Uc)
//============================================================================


struct  Sf_BFu0ll_Ui  {
  struct empty v1;
  __tsu64  :0;
  unsigned int v2;
};
//SIG(1 Sf_BFu0ll_Ui) C1{ FC2{} FL:0 Fi}



static void Test_Sf_BFu0ll_Ui()
{
  {
    init_simple_test("Sf_BFu0ll_Ui");
    static STRUCT_IF_C Sf_BFu0ll_Ui lv;
    check2(sizeof(lv), ABISELECT(4,4), "sizeof(Sf_BFu0ll_Ui)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu0ll_Ui)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_Ui, Sf_BFu0ll_Ui)
//============================================================================


struct  Sf_BFu0ll_Ul  {
  struct empty v1;
  __tsu64  :0;
  __tsu64 v2;
};
//SIG(1 Sf_BFu0ll_Ul) C1{ FC2{} FL:0 FL}



static void Test_Sf_BFu0ll_Ul()
{
  {
    init_simple_test("Sf_BFu0ll_Ul");
    static STRUCT_IF_C Sf_BFu0ll_Ul lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0ll_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_Ul)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_Ul, Sf_BFu0ll_Ul)
//============================================================================


struct  Sf_BFu0ll_Us  {
  struct empty v1;
  __tsu64  :0;
  unsigned short v2;
};
//SIG(1 Sf_BFu0ll_Us) C1{ FC2{} FL:0 Fs}



static void Test_Sf_BFu0ll_Us()
{
  {
    init_simple_test("Sf_BFu0ll_Us");
    static STRUCT_IF_C Sf_BFu0ll_Us lv;
    check2(sizeof(lv), ABISELECT(2,2), "sizeof(Sf_BFu0ll_Us)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu0ll_Us)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_Us, Sf_BFu0ll_Us)
//============================================================================


struct  Sf_BFu0ll_Vp  {
  struct empty v1;
  __tsu64  :0;
  void *v2;
};
//SIG(1 Sf_BFu0ll_Vp) C1{ FC2{} FL:0 Fp}



static void Test_Sf_BFu0ll_Vp()
{
  {
    init_simple_test("Sf_BFu0ll_Vp");
    static STRUCT_IF_C Sf_BFu0ll_Vp lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0ll_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0ll_Vp)");
    check_field_offset(lv, v1, 0, "Sf_BFu0ll_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0ll_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0ll_Vp, Sf_BFu0ll_Vp)
//============================================================================


struct  Sf_BFu0s  {
  struct empty v1;
  unsigned short  :0;
};
//SIG(1 Sf_BFu0s) C1{ FC2{} Fs:0}



static void Test_Sf_BFu0s()
{
  {
    init_simple_test("Sf_BFu0s");
    static STRUCT_IF_C Sf_BFu0s lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s, Sf_BFu0s)
//============================================================================


struct  Sf_BFu0s_BFu0c  {
  struct empty v1;
  unsigned short  :0;
  unsigned char  :0;
};
//SIG(1 Sf_BFu0s_BFu0c) C1{ FC2{} Fs:0 Fc:0}



static void Test_Sf_BFu0s_BFu0c()
{
  {
    init_simple_test("Sf_BFu0s_BFu0c");
    static STRUCT_IF_C Sf_BFu0s_BFu0c lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0s_BFu0c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0s_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu0c.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu0c, Sf_BFu0s_BFu0c)
//============================================================================


struct  Sf_BFu0s_BFu0i  {
  struct empty v1;
  unsigned short  :0;
  unsigned int  :0;
};
//SIG(1 Sf_BFu0s_BFu0i) C1{ FC2{} Fs:0 Fi:0}



static void Test_Sf_BFu0s_BFu0i()
{
  {
    init_simple_test("Sf_BFu0s_BFu0i");
    static STRUCT_IF_C Sf_BFu0s_BFu0i lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0s_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu0i.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu0i, Sf_BFu0s_BFu0i)
//============================================================================


struct  Sf_BFu0s_BFu0ll  {
  struct empty v1;
  unsigned short  :0;
  __tsu64  :0;
};
//SIG(1 Sf_BFu0s_BFu0ll) C1{ FC2{} Fs:0 FL:0}



static void Test_Sf_BFu0s_BFu0ll()
{
  {
    init_simple_test("Sf_BFu0s_BFu0ll");
    static STRUCT_IF_C Sf_BFu0s_BFu0ll lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu0ll.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu0ll, Sf_BFu0s_BFu0ll)
//============================================================================


struct  Sf_BFu0s_BFu0s  {
  struct empty v1;
  unsigned short  :0;
  unsigned short  :0;
};
//SIG(1 Sf_BFu0s_BFu0s) C1{ FC2{} Fs:0 Fs:0}



static void Test_Sf_BFu0s_BFu0s()
{
  {
    init_simple_test("Sf_BFu0s_BFu0s");
    static STRUCT_IF_C Sf_BFu0s_BFu0s lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0s_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0s_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu0s.v1");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu0s, Sf_BFu0s_BFu0s)
//============================================================================


struct  Sf_BFu0s_BFu15i  {
  struct empty v1;
  unsigned short  :0;
  unsigned int v2:15;
};
//SIG(1 Sf_BFu0s_BFu15i) C1{ FC2{} Fs:0 Fi:15}



static void Test_Sf_BFu0s_BFu15i()
{
  {
    init_simple_test("Sf_BFu0s_BFu15i");
    static STRUCT_IF_C Sf_BFu0s_BFu15i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0s_BFu15i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0s_BFu15i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu15i.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu0s_BFu15i");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu0s_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu15i, Sf_BFu0s_BFu15i)
//============================================================================


struct  Sf_BFu0s_BFu15ll  {
  struct empty v1;
  unsigned short  :0;
  __tsu64 v2:15;
};
//SIG(1 Sf_BFu0s_BFu15ll) C1{ FC2{} Fs:0 FL:15}



static void Test_Sf_BFu0s_BFu15ll()
{
  {
    init_simple_test("Sf_BFu0s_BFu15ll");
    static STRUCT_IF_C Sf_BFu0s_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu15ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu0s_BFu15ll");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu0s_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu15ll, Sf_BFu0s_BFu15ll)
//============================================================================


struct  Sf_BFu0s_BFu15s  {
  struct empty v1;
  unsigned short  :0;
  unsigned short v2:15;
};
//SIG(1 Sf_BFu0s_BFu15s) C1{ FC2{} Fs:0 Fs:15}



static void Test_Sf_BFu0s_BFu15s()
{
  {
    init_simple_test("Sf_BFu0s_BFu15s");
    static STRUCT_IF_C Sf_BFu0s_BFu15s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0s_BFu15s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0s_BFu15s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu15s.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu0s_BFu15s");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu0s_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu15s, Sf_BFu0s_BFu15s)
//============================================================================


struct  Sf_BFu0s_BFu16i  {
  struct empty v1;
  unsigned short  :0;
  unsigned int v2:16;
};
//SIG(1 Sf_BFu0s_BFu16i) C1{ FC2{} Fs:0 Fi:16}



static void Test_Sf_BFu0s_BFu16i()
{
  {
    init_simple_test("Sf_BFu0s_BFu16i");
    static STRUCT_IF_C Sf_BFu0s_BFu16i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0s_BFu16i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0s_BFu16i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu16i.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu0s_BFu16i");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu0s_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu16i, Sf_BFu0s_BFu16i)
//============================================================================


struct  Sf_BFu0s_BFu16ll  {
  struct empty v1;
  unsigned short  :0;
  __tsu64 v2:16;
};
//SIG(1 Sf_BFu0s_BFu16ll) C1{ FC2{} Fs:0 FL:16}



static void Test_Sf_BFu0s_BFu16ll()
{
  {
    init_simple_test("Sf_BFu0s_BFu16ll");
    static STRUCT_IF_C Sf_BFu0s_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu16ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu0s_BFu16ll");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu0s_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu16ll, Sf_BFu0s_BFu16ll)
//============================================================================


struct  Sf_BFu0s_BFu16s  {
  struct empty v1;
  unsigned short  :0;
  unsigned short v2:16;
};
//SIG(1 Sf_BFu0s_BFu16s) C1{ FC2{} Fs:0 Fs:16}



static void Test_Sf_BFu0s_BFu16s()
{
  {
    init_simple_test("Sf_BFu0s_BFu16s");
    static STRUCT_IF_C Sf_BFu0s_BFu16s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0s_BFu16s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0s_BFu16s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu16s.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu0s_BFu16s");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu0s_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu16s, Sf_BFu0s_BFu16s)
//============================================================================


struct  Sf_BFu0s_BFu17i  {
  struct empty v1;
  unsigned short  :0;
  unsigned int v2:17;
};
//SIG(1 Sf_BFu0s_BFu17i) C1{ FC2{} Fs:0 Fi:17}



static void Test_Sf_BFu0s_BFu17i()
{
  {
    init_simple_test("Sf_BFu0s_BFu17i");
    static STRUCT_IF_C Sf_BFu0s_BFu17i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0s_BFu17i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0s_BFu17i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu17i.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu0s_BFu17i");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu0s_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu17i, Sf_BFu0s_BFu17i)
//============================================================================


struct  Sf_BFu0s_BFu17ll  {
  struct empty v1;
  unsigned short  :0;
  __tsu64 v2:17;
};
//SIG(1 Sf_BFu0s_BFu17ll) C1{ FC2{} Fs:0 FL:17}



static void Test_Sf_BFu0s_BFu17ll()
{
  {
    init_simple_test("Sf_BFu0s_BFu17ll");
    static STRUCT_IF_C Sf_BFu0s_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu17ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu0s_BFu17ll");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu0s_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu17ll, Sf_BFu0s_BFu17ll)
//============================================================================


struct  Sf_BFu0s_BFu1c  {
  struct empty v1;
  unsigned short  :0;
  unsigned char v2:1;
};
//SIG(1 Sf_BFu0s_BFu1c) C1{ FC2{} Fs:0 Fc:1}



static void Test_Sf_BFu0s_BFu1c()
{
  {
    init_simple_test("Sf_BFu0s_BFu1c");
    static STRUCT_IF_C Sf_BFu0s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0s_BFu1c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu1c.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0s_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu1c, Sf_BFu0s_BFu1c)
//============================================================================


struct  Sf_BFu0s_BFu1i  {
  struct empty v1;
  unsigned short  :0;
  unsigned int v2:1;
};
//SIG(1 Sf_BFu0s_BFu1i) C1{ FC2{} Fs:0 Fi:1}



static void Test_Sf_BFu0s_BFu1i()
{
  {
    init_simple_test("Sf_BFu0s_BFu1i");
    static STRUCT_IF_C Sf_BFu0s_BFu1i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0s_BFu1i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0s_BFu1i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu1i.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0s_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu1i, Sf_BFu0s_BFu1i)
//============================================================================


struct  Sf_BFu0s_BFu1ll  {
  struct empty v1;
  unsigned short  :0;
  __tsu64 v2:1;
};
//SIG(1 Sf_BFu0s_BFu1ll) C1{ FC2{} Fs:0 FL:1}



static void Test_Sf_BFu0s_BFu1ll()
{
  {
    init_simple_test("Sf_BFu0s_BFu1ll");
    static STRUCT_IF_C Sf_BFu0s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu1ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0s_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu1ll, Sf_BFu0s_BFu1ll)
//============================================================================


struct  Sf_BFu0s_BFu1s  {
  struct empty v1;
  unsigned short  :0;
  unsigned short v2:1;
};
//SIG(1 Sf_BFu0s_BFu1s) C1{ FC2{} Fs:0 Fs:1}



static void Test_Sf_BFu0s_BFu1s()
{
  {
    init_simple_test("Sf_BFu0s_BFu1s");
    static STRUCT_IF_C Sf_BFu0s_BFu1s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0s_BFu1s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0s_BFu1s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu1s.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu0s_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu1s, Sf_BFu0s_BFu1s)
//============================================================================


struct  Sf_BFu0s_BFu31i  {
  struct empty v1;
  unsigned short  :0;
  unsigned int v2:31;
};
//SIG(1 Sf_BFu0s_BFu31i) C1{ FC2{} Fs:0 Fi:31}



static void Test_Sf_BFu0s_BFu31i()
{
  {
    init_simple_test("Sf_BFu0s_BFu31i");
    static STRUCT_IF_C Sf_BFu0s_BFu31i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0s_BFu31i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0s_BFu31i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu31i.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu0s_BFu31i");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu0s_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu31i, Sf_BFu0s_BFu31i)
//============================================================================


struct  Sf_BFu0s_BFu31ll  {
  struct empty v1;
  unsigned short  :0;
  __tsu64 v2:31;
};
//SIG(1 Sf_BFu0s_BFu31ll) C1{ FC2{} Fs:0 FL:31}



static void Test_Sf_BFu0s_BFu31ll()
{
  {
    init_simple_test("Sf_BFu0s_BFu31ll");
    static STRUCT_IF_C Sf_BFu0s_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu31ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu0s_BFu31ll");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu0s_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu31ll, Sf_BFu0s_BFu31ll)
//============================================================================


struct  Sf_BFu0s_BFu32i  {
  struct empty v1;
  unsigned short  :0;
  unsigned int v2:32;
};
//SIG(1 Sf_BFu0s_BFu32i) C1{ FC2{} Fs:0 Fi:32}



static void Test_Sf_BFu0s_BFu32i()
{
  {
    init_simple_test("Sf_BFu0s_BFu32i");
    static STRUCT_IF_C Sf_BFu0s_BFu32i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0s_BFu32i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0s_BFu32i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu32i.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu0s_BFu32i");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu0s_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu32i, Sf_BFu0s_BFu32i)
//============================================================================


struct  Sf_BFu0s_BFu32ll  {
  struct empty v1;
  unsigned short  :0;
  __tsu64 v2:32;
};
//SIG(1 Sf_BFu0s_BFu32ll) C1{ FC2{} Fs:0 FL:32}



static void Test_Sf_BFu0s_BFu32ll()
{
  {
    init_simple_test("Sf_BFu0s_BFu32ll");
    static STRUCT_IF_C Sf_BFu0s_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu32ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu0s_BFu32ll");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu0s_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu32ll, Sf_BFu0s_BFu32ll)
//============================================================================


struct  Sf_BFu0s_BFu33  {
  struct empty v1;
  unsigned short  :0;
  __tsu64 v2:33;
};
//SIG(1 Sf_BFu0s_BFu33) C1{ FC2{} Fs:0 FL:33}



static void Test_Sf_BFu0s_BFu33()
{
  {
    init_simple_test("Sf_BFu0s_BFu33");
    static STRUCT_IF_C Sf_BFu0s_BFu33 lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0s_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_BFu33)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu33.v1");
    set_bf_and_test(lv, v2, 0, 0, 33, 1, "Sf_BFu0s_BFu33");
    set_bf_and_test(lv, v2, 0, 0, 33, hide_ull(1LL<<32), "Sf_BFu0s_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu33, Sf_BFu0s_BFu33)
//============================================================================


struct  Sf_BFu0s_BFu7c  {
  struct empty v1;
  unsigned short  :0;
  unsigned char v2:7;
};
//SIG(1 Sf_BFu0s_BFu7c) C1{ FC2{} Fs:0 Fc:7}



static void Test_Sf_BFu0s_BFu7c()
{
  {
    init_simple_test("Sf_BFu0s_BFu7c");
    static STRUCT_IF_C Sf_BFu0s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0s_BFu7c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu7c.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0s_BFu7c");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0s_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu7c, Sf_BFu0s_BFu7c)
//============================================================================


struct  Sf_BFu0s_BFu7i  {
  struct empty v1;
  unsigned short  :0;
  unsigned int v2:7;
};
//SIG(1 Sf_BFu0s_BFu7i) C1{ FC2{} Fs:0 Fi:7}



static void Test_Sf_BFu0s_BFu7i()
{
  {
    init_simple_test("Sf_BFu0s_BFu7i");
    static STRUCT_IF_C Sf_BFu0s_BFu7i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0s_BFu7i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0s_BFu7i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu7i.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0s_BFu7i");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0s_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu7i, Sf_BFu0s_BFu7i)
//============================================================================


struct  Sf_BFu0s_BFu7ll  {
  struct empty v1;
  unsigned short  :0;
  __tsu64 v2:7;
};
//SIG(1 Sf_BFu0s_BFu7ll) C1{ FC2{} Fs:0 FL:7}



static void Test_Sf_BFu0s_BFu7ll()
{
  {
    init_simple_test("Sf_BFu0s_BFu7ll");
    static STRUCT_IF_C Sf_BFu0s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu7ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0s_BFu7ll");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0s_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu7ll, Sf_BFu0s_BFu7ll)
//============================================================================


struct  Sf_BFu0s_BFu7s  {
  struct empty v1;
  unsigned short  :0;
  unsigned short v2:7;
};
//SIG(1 Sf_BFu0s_BFu7s) C1{ FC2{} Fs:0 Fs:7}



static void Test_Sf_BFu0s_BFu7s()
{
  {
    init_simple_test("Sf_BFu0s_BFu7s");
    static STRUCT_IF_C Sf_BFu0s_BFu7s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0s_BFu7s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0s_BFu7s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu7s.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu0s_BFu7s");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu0s_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu7s, Sf_BFu0s_BFu7s)
//============================================================================


struct  Sf_BFu0s_BFu8c  {
  struct empty v1;
  unsigned short  :0;
  unsigned char v2:8;
};
//SIG(1 Sf_BFu0s_BFu8c) C1{ FC2{} Fs:0 Fc:8}



static void Test_Sf_BFu0s_BFu8c()
{
  {
    init_simple_test("Sf_BFu0s_BFu8c");
    static STRUCT_IF_C Sf_BFu0s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0s_BFu8c)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu8c.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0s_BFu8c");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0s_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu8c, Sf_BFu0s_BFu8c)
//============================================================================


struct  Sf_BFu0s_BFu8i  {
  struct empty v1;
  unsigned short  :0;
  unsigned int v2:8;
};
//SIG(1 Sf_BFu0s_BFu8i) C1{ FC2{} Fs:0 Fi:8}



static void Test_Sf_BFu0s_BFu8i()
{
  {
    init_simple_test("Sf_BFu0s_BFu8i");
    static STRUCT_IF_C Sf_BFu0s_BFu8i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0s_BFu8i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0s_BFu8i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu8i.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0s_BFu8i");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0s_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu8i, Sf_BFu0s_BFu8i)
//============================================================================


struct  Sf_BFu0s_BFu8ll  {
  struct empty v1;
  unsigned short  :0;
  __tsu64 v2:8;
};
//SIG(1 Sf_BFu0s_BFu8ll) C1{ FC2{} Fs:0 FL:8}



static void Test_Sf_BFu0s_BFu8ll()
{
  {
    init_simple_test("Sf_BFu0s_BFu8ll");
    static STRUCT_IF_C Sf_BFu0s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu8ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0s_BFu8ll");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0s_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu8ll, Sf_BFu0s_BFu8ll)
//============================================================================


struct  Sf_BFu0s_BFu8s  {
  struct empty v1;
  unsigned short  :0;
  unsigned short v2:8;
};
//SIG(1 Sf_BFu0s_BFu8s) C1{ FC2{} Fs:0 Fs:8}



static void Test_Sf_BFu0s_BFu8s()
{
  {
    init_simple_test("Sf_BFu0s_BFu8s");
    static STRUCT_IF_C Sf_BFu0s_BFu8s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0s_BFu8s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0s_BFu8s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu8s.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu0s_BFu8s");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu0s_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu8s, Sf_BFu0s_BFu8s)
//============================================================================


struct  Sf_BFu0s_BFu9i  {
  struct empty v1;
  unsigned short  :0;
  unsigned int v2:9;
};
//SIG(1 Sf_BFu0s_BFu9i) C1{ FC2{} Fs:0 Fi:9}



static void Test_Sf_BFu0s_BFu9i()
{
  {
    init_simple_test("Sf_BFu0s_BFu9i");
    static STRUCT_IF_C Sf_BFu0s_BFu9i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0s_BFu9i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0s_BFu9i)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu9i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu0s_BFu9i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu0s_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu9i, Sf_BFu0s_BFu9i)
//============================================================================


struct  Sf_BFu0s_BFu9ll  {
  struct empty v1;
  unsigned short  :0;
  __tsu64 v2:9;
};
//SIG(1 Sf_BFu0s_BFu9ll) C1{ FC2{} Fs:0 FL:9}



static void Test_Sf_BFu0s_BFu9ll()
{
  {
    init_simple_test("Sf_BFu0s_BFu9ll");
    static STRUCT_IF_C Sf_BFu0s_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu9ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu0s_BFu9ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu0s_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu9ll, Sf_BFu0s_BFu9ll)
//============================================================================


struct  Sf_BFu0s_BFu9s  {
  struct empty v1;
  unsigned short  :0;
  unsigned short v2:9;
};
//SIG(1 Sf_BFu0s_BFu9s) C1{ FC2{} Fs:0 Fs:9}



static void Test_Sf_BFu0s_BFu9s()
{
  {
    init_simple_test("Sf_BFu0s_BFu9s");
    static STRUCT_IF_C Sf_BFu0s_BFu9s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0s_BFu9s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0s_BFu9s)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_BFu9s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu0s_BFu9s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu0s_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_BFu9s, Sf_BFu0s_BFu9s)
//============================================================================


struct  Sf_BFu0s_C  {
  struct empty v1;
  unsigned short  :0;
  char v2;
};
//SIG(1 Sf_BFu0s_C) C1{ FC2{} Fs:0 Fc}



static void Test_Sf_BFu0s_C()
{
  {
    init_simple_test("Sf_BFu0s_C");
    static STRUCT_IF_C Sf_BFu0s_C lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0s_C)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0s_C)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_C.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_C, Sf_BFu0s_C)
//============================================================================


struct  Sf_BFu0s_D  {
  struct empty v1;
  unsigned short  :0;
  double v2;
};
//SIG(1 Sf_BFu0s_D) C1{ FC2{} Fs:0 FL}



static void Test_Sf_BFu0s_D()
{
  {
    init_simple_test("Sf_BFu0s_D");
    static STRUCT_IF_C Sf_BFu0s_D lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0s_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_D)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_D.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_D, Sf_BFu0s_D)
//============================================================================


struct  Sf_BFu0s_F  {
  struct empty v1;
  unsigned short  :0;
  float v2;
};
//SIG(1 Sf_BFu0s_F) C1{ FC2{} Fs:0 Fi}



static void Test_Sf_BFu0s_F()
{
  {
    init_simple_test("Sf_BFu0s_F");
    static STRUCT_IF_C Sf_BFu0s_F lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0s_F)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0s_F)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_F.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_F, Sf_BFu0s_F)
//============================================================================


struct  Sf_BFu0s_I  {
  struct empty v1;
  unsigned short  :0;
  int v2;
};
//SIG(1 Sf_BFu0s_I) C1{ FC2{} Fs:0 Fi}



static void Test_Sf_BFu0s_I()
{
  {
    init_simple_test("Sf_BFu0s_I");
    static STRUCT_IF_C Sf_BFu0s_I lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0s_I)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0s_I)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_I.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_I, Sf_BFu0s_I)
//============================================================================


struct  Sf_BFu0s_Ip  {
  struct empty v1;
  unsigned short  :0;
  int *v2;
};
//SIG(1 Sf_BFu0s_Ip) C1{ FC2{} Fs:0 Fp}



static void Test_Sf_BFu0s_Ip()
{
  {
    init_simple_test("Sf_BFu0s_Ip");
    static STRUCT_IF_C Sf_BFu0s_Ip lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0s_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_Ip)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_Ip.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_Ip, Sf_BFu0s_Ip)
//============================================================================


struct  Sf_BFu0s_L  {
  struct empty v1;
  unsigned short  :0;
  __tsi64 v2;
};
//SIG(1 Sf_BFu0s_L) C1{ FC2{} Fs:0 FL}



static void Test_Sf_BFu0s_L()
{
  {
    init_simple_test("Sf_BFu0s_L");
    static STRUCT_IF_C Sf_BFu0s_L lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0s_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_L)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_L.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_L, Sf_BFu0s_L)
//============================================================================


struct  Sf_BFu0s_S  {
  struct empty v1;
  unsigned short  :0;
  short v2;
};
//SIG(1 Sf_BFu0s_S) C1{ FC2{} Fs:0 Fs}



static void Test_Sf_BFu0s_S()
{
  {
    init_simple_test("Sf_BFu0s_S");
    static STRUCT_IF_C Sf_BFu0s_S lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0s_S)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0s_S)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_S.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_S, Sf_BFu0s_S)
//============================================================================


struct  Sf_BFu0s_Sf  {
  struct empty v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 Sf_BFu0s_Sf) C1{ FC2{} Fs:0 FC2}



static void Test_Sf_BFu0s_Sf()
{
  {
    init_simple_test("Sf_BFu0s_Sf");
    static STRUCT_IF_C Sf_BFu0s_Sf lv;
    check2(sizeof(lv), 0, "sizeof(Sf_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_Sf.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_Sf, Sf_BFu0s_Sf)
//============================================================================


struct  Sf_BFu0s_Uc  {
  struct empty v1;
  unsigned short  :0;
  unsigned char v2;
};
//SIG(1 Sf_BFu0s_Uc) C1{ FC2{} Fs:0 Fc}



static void Test_Sf_BFu0s_Uc()
{
  {
    init_simple_test("Sf_BFu0s_Uc");
    static STRUCT_IF_C Sf_BFu0s_Uc lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(Sf_BFu0s_Uc)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu0s_Uc)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_Uc.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_Uc, Sf_BFu0s_Uc)
//============================================================================


struct  Sf_BFu0s_Ui  {
  struct empty v1;
  unsigned short  :0;
  unsigned int v2;
};
//SIG(1 Sf_BFu0s_Ui) C1{ FC2{} Fs:0 Fi}



static void Test_Sf_BFu0s_Ui()
{
  {
    init_simple_test("Sf_BFu0s_Ui");
    static STRUCT_IF_C Sf_BFu0s_Ui lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu0s_Ui)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu0s_Ui)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_Ui.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_Ui, Sf_BFu0s_Ui)
//============================================================================


struct  Sf_BFu0s_Ul  {
  struct empty v1;
  unsigned short  :0;
  __tsu64 v2;
};
//SIG(1 Sf_BFu0s_Ul) C1{ FC2{} Fs:0 FL}



static void Test_Sf_BFu0s_Ul()
{
  {
    init_simple_test("Sf_BFu0s_Ul");
    static STRUCT_IF_C Sf_BFu0s_Ul lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu0s_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_Ul)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_Ul.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_Ul, Sf_BFu0s_Ul)
//============================================================================


struct  Sf_BFu0s_Us  {
  struct empty v1;
  unsigned short  :0;
  unsigned short v2;
};
//SIG(1 Sf_BFu0s_Us) C1{ FC2{} Fs:0 Fs}



static void Test_Sf_BFu0s_Us()
{
  {
    init_simple_test("Sf_BFu0s_Us");
    static STRUCT_IF_C Sf_BFu0s_Us lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu0s_Us)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu0s_Us)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_Us.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_Us, Sf_BFu0s_Us)
//============================================================================


struct  Sf_BFu0s_Vp  {
  struct empty v1;
  unsigned short  :0;
  void *v2;
};
//SIG(1 Sf_BFu0s_Vp) C1{ FC2{} Fs:0 Fp}



static void Test_Sf_BFu0s_Vp()
{
  {
    init_simple_test("Sf_BFu0s_Vp");
    static STRUCT_IF_C Sf_BFu0s_Vp lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu0s_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu0s_Vp)");
    check_field_offset(lv, v1, 0, "Sf_BFu0s_Vp.v1");
    check_field_offset(lv, v2, 0, "Sf_BFu0s_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu0s_Vp, Sf_BFu0s_Vp)
//============================================================================


struct  Sf_BFu15i_BFu0c  {
  struct empty v1;
  unsigned int v2:15;
  unsigned char  :0;
};
//SIG(1 Sf_BFu15i_BFu0c) C1{ FC2{} Fi:15 Fc:0}



static void Test_Sf_BFu15i_BFu0c()
{
  {
    init_simple_test("Sf_BFu15i_BFu0c");
    static STRUCT_IF_C Sf_BFu15i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu15i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu15i_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu15i_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu15i_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu15i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu15i_BFu0c, Sf_BFu15i_BFu0c)
//============================================================================


struct  Sf_BFu15i_BFu0i  {
  struct empty v1;
  unsigned int v2:15;
  unsigned int  :0;
};
//SIG(1 Sf_BFu15i_BFu0i) C1{ FC2{} Fi:15 Fi:0}



static void Test_Sf_BFu15i_BFu0i()
{
  {
    init_simple_test("Sf_BFu15i_BFu0i");
    static STRUCT_IF_C Sf_BFu15i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu15i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu15i_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu15i_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu15i_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu15i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu15i_BFu0i, Sf_BFu15i_BFu0i)
//============================================================================


struct  Sf_BFu15i_BFu0ll  {
  struct empty v1;
  unsigned int v2:15;
  __tsu64  :0;
};
//SIG(1 Sf_BFu15i_BFu0ll) C1{ FC2{} Fi:15 FL:0}



static void Test_Sf_BFu15i_BFu0ll()
{
  {
    init_simple_test("Sf_BFu15i_BFu0ll");
    static STRUCT_IF_C Sf_BFu15i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu15i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu15i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu15i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu15i_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu15i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu15i_BFu0ll, Sf_BFu15i_BFu0ll)
//============================================================================


struct  Sf_BFu15i_BFu0s  {
  struct empty v1;
  unsigned int v2:15;
  unsigned short  :0;
};
//SIG(1 Sf_BFu15i_BFu0s) C1{ FC2{} Fi:15 Fs:0}



static void Test_Sf_BFu15i_BFu0s()
{
  {
    init_simple_test("Sf_BFu15i_BFu0s");
    static STRUCT_IF_C Sf_BFu15i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu15i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu15i_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu15i_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu15i_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu15i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu15i_BFu0s, Sf_BFu15i_BFu0s)
//============================================================================


struct  Sf_BFu15ll_BFu0c  {
  struct empty v1;
  __tsu64 v2:15;
  unsigned char  :0;
};
//SIG(1 Sf_BFu15ll_BFu0c) C1{ FC2{} FL:15 Fc:0}



static void Test_Sf_BFu15ll_BFu0c()
{
  {
    init_simple_test("Sf_BFu15ll_BFu0c");
    static STRUCT_IF_C Sf_BFu15ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu15ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu15ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu15ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu15ll_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu15ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu15ll_BFu0c, Sf_BFu15ll_BFu0c)
//============================================================================


struct  Sf_BFu15ll_BFu0i  {
  struct empty v1;
  __tsu64 v2:15;
  unsigned int  :0;
};
//SIG(1 Sf_BFu15ll_BFu0i) C1{ FC2{} FL:15 Fi:0}



static void Test_Sf_BFu15ll_BFu0i()
{
  {
    init_simple_test("Sf_BFu15ll_BFu0i");
    static STRUCT_IF_C Sf_BFu15ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu15ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu15ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu15ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu15ll_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu15ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu15ll_BFu0i, Sf_BFu15ll_BFu0i)
//============================================================================


struct  Sf_BFu15ll_BFu0ll  {
  struct empty v1;
  __tsu64 v2:15;
  __tsu64  :0;
};
//SIG(1 Sf_BFu15ll_BFu0ll) C1{ FC2{} FL:15 FL:0}



static void Test_Sf_BFu15ll_BFu0ll()
{
  {
    init_simple_test("Sf_BFu15ll_BFu0ll");
    static STRUCT_IF_C Sf_BFu15ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu15ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu15ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu15ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu15ll_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu15ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu15ll_BFu0ll, Sf_BFu15ll_BFu0ll)
//============================================================================


struct  Sf_BFu15ll_BFu0s  {
  struct empty v1;
  __tsu64 v2:15;
  unsigned short  :0;
};
//SIG(1 Sf_BFu15ll_BFu0s) C1{ FC2{} FL:15 Fs:0}



static void Test_Sf_BFu15ll_BFu0s()
{
  {
    init_simple_test("Sf_BFu15ll_BFu0s");
    static STRUCT_IF_C Sf_BFu15ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu15ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu15ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu15ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu15ll_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu15ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu15ll_BFu0s, Sf_BFu15ll_BFu0s)
//============================================================================


struct  Sf_BFu15s_BFu0c  {
  struct empty v1;
  unsigned short v2:15;
  unsigned char  :0;
};
//SIG(1 Sf_BFu15s_BFu0c) C1{ FC2{} Fs:15 Fc:0}



static void Test_Sf_BFu15s_BFu0c()
{
  {
    init_simple_test("Sf_BFu15s_BFu0c");
    static STRUCT_IF_C Sf_BFu15s_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu15s_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu15s_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu15s_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu15s_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu15s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu15s_BFu0c, Sf_BFu15s_BFu0c)
//============================================================================


struct  Sf_BFu15s_BFu0i  {
  struct empty v1;
  unsigned short v2:15;
  unsigned int  :0;
};
//SIG(1 Sf_BFu15s_BFu0i) C1{ FC2{} Fs:15 Fi:0}



static void Test_Sf_BFu15s_BFu0i()
{
  {
    init_simple_test("Sf_BFu15s_BFu0i");
    static STRUCT_IF_C Sf_BFu15s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu15s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu15s_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu15s_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu15s_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu15s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu15s_BFu0i, Sf_BFu15s_BFu0i)
//============================================================================


struct  Sf_BFu15s_BFu0ll  {
  struct empty v1;
  unsigned short v2:15;
  __tsu64  :0;
};
//SIG(1 Sf_BFu15s_BFu0ll) C1{ FC2{} Fs:15 FL:0}



static void Test_Sf_BFu15s_BFu0ll()
{
  {
    init_simple_test("Sf_BFu15s_BFu0ll");
    static STRUCT_IF_C Sf_BFu15s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu15s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu15s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu15s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu15s_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu15s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu15s_BFu0ll, Sf_BFu15s_BFu0ll)
//============================================================================


struct  Sf_BFu15s_BFu0s  {
  struct empty v1;
  unsigned short v2:15;
  unsigned short  :0;
};
//SIG(1 Sf_BFu15s_BFu0s) C1{ FC2{} Fs:15 Fs:0}



static void Test_Sf_BFu15s_BFu0s()
{
  {
    init_simple_test("Sf_BFu15s_BFu0s");
    static STRUCT_IF_C Sf_BFu15s_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu15s_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu15s_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu15s_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 15, 1, "Sf_BFu15s_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 15, hide_ull(1LL<<14), "Sf_BFu15s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu15s_BFu0s, Sf_BFu15s_BFu0s)
//============================================================================


struct  Sf_BFu16i_BFu0c  {
  struct empty v1;
  unsigned int v2:16;
  unsigned char  :0;
};
//SIG(1 Sf_BFu16i_BFu0c) C1{ FC2{} Fi:16 Fc:0}



static void Test_Sf_BFu16i_BFu0c()
{
  {
    init_simple_test("Sf_BFu16i_BFu0c");
    static STRUCT_IF_C Sf_BFu16i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu16i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu16i_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu16i_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu16i_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu16i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu16i_BFu0c, Sf_BFu16i_BFu0c)
//============================================================================


struct  Sf_BFu16i_BFu0i  {
  struct empty v1;
  unsigned int v2:16;
  unsigned int  :0;
};
//SIG(1 Sf_BFu16i_BFu0i) C1{ FC2{} Fi:16 Fi:0}



static void Test_Sf_BFu16i_BFu0i()
{
  {
    init_simple_test("Sf_BFu16i_BFu0i");
    static STRUCT_IF_C Sf_BFu16i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu16i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu16i_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu16i_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu16i_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu16i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu16i_BFu0i, Sf_BFu16i_BFu0i)
//============================================================================


struct  Sf_BFu16i_BFu0ll  {
  struct empty v1;
  unsigned int v2:16;
  __tsu64  :0;
};
//SIG(1 Sf_BFu16i_BFu0ll) C1{ FC2{} Fi:16 FL:0}



static void Test_Sf_BFu16i_BFu0ll()
{
  {
    init_simple_test("Sf_BFu16i_BFu0ll");
    static STRUCT_IF_C Sf_BFu16i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu16i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu16i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu16i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu16i_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu16i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu16i_BFu0ll, Sf_BFu16i_BFu0ll)
//============================================================================


struct  Sf_BFu16i_BFu0s  {
  struct empty v1;
  unsigned int v2:16;
  unsigned short  :0;
};
//SIG(1 Sf_BFu16i_BFu0s) C1{ FC2{} Fi:16 Fs:0}



static void Test_Sf_BFu16i_BFu0s()
{
  {
    init_simple_test("Sf_BFu16i_BFu0s");
    static STRUCT_IF_C Sf_BFu16i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu16i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu16i_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu16i_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu16i_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu16i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu16i_BFu0s, Sf_BFu16i_BFu0s)
//============================================================================


struct  Sf_BFu16ll_BFu0c  {
  struct empty v1;
  __tsu64 v2:16;
  unsigned char  :0;
};
//SIG(1 Sf_BFu16ll_BFu0c) C1{ FC2{} FL:16 Fc:0}



static void Test_Sf_BFu16ll_BFu0c()
{
  {
    init_simple_test("Sf_BFu16ll_BFu0c");
    static STRUCT_IF_C Sf_BFu16ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu16ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu16ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu16ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu16ll_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu16ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu16ll_BFu0c, Sf_BFu16ll_BFu0c)
//============================================================================


struct  Sf_BFu16ll_BFu0i  {
  struct empty v1;
  __tsu64 v2:16;
  unsigned int  :0;
};
//SIG(1 Sf_BFu16ll_BFu0i) C1{ FC2{} FL:16 Fi:0}



static void Test_Sf_BFu16ll_BFu0i()
{
  {
    init_simple_test("Sf_BFu16ll_BFu0i");
    static STRUCT_IF_C Sf_BFu16ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu16ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu16ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu16ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu16ll_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu16ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu16ll_BFu0i, Sf_BFu16ll_BFu0i)
//============================================================================


struct  Sf_BFu16ll_BFu0ll  {
  struct empty v1;
  __tsu64 v2:16;
  __tsu64  :0;
};
//SIG(1 Sf_BFu16ll_BFu0ll) C1{ FC2{} FL:16 FL:0}



static void Test_Sf_BFu16ll_BFu0ll()
{
  {
    init_simple_test("Sf_BFu16ll_BFu0ll");
    static STRUCT_IF_C Sf_BFu16ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu16ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu16ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu16ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu16ll_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu16ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu16ll_BFu0ll, Sf_BFu16ll_BFu0ll)
//============================================================================


struct  Sf_BFu16ll_BFu0s  {
  struct empty v1;
  __tsu64 v2:16;
  unsigned short  :0;
};
//SIG(1 Sf_BFu16ll_BFu0s) C1{ FC2{} FL:16 Fs:0}



static void Test_Sf_BFu16ll_BFu0s()
{
  {
    init_simple_test("Sf_BFu16ll_BFu0s");
    static STRUCT_IF_C Sf_BFu16ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu16ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu16ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu16ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu16ll_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu16ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu16ll_BFu0s, Sf_BFu16ll_BFu0s)
//============================================================================


struct  Sf_BFu16s_BFu0c  {
  struct empty v1;
  unsigned short v2:16;
  unsigned char  :0;
};
//SIG(1 Sf_BFu16s_BFu0c) C1{ FC2{} Fs:16 Fc:0}



static void Test_Sf_BFu16s_BFu0c()
{
  {
    init_simple_test("Sf_BFu16s_BFu0c");
    static STRUCT_IF_C Sf_BFu16s_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu16s_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu16s_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu16s_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu16s_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu16s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu16s_BFu0c, Sf_BFu16s_BFu0c)
//============================================================================


struct  Sf_BFu16s_BFu0i  {
  struct empty v1;
  unsigned short v2:16;
  unsigned int  :0;
};
//SIG(1 Sf_BFu16s_BFu0i) C1{ FC2{} Fs:16 Fi:0}



static void Test_Sf_BFu16s_BFu0i()
{
  {
    init_simple_test("Sf_BFu16s_BFu0i");
    static STRUCT_IF_C Sf_BFu16s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu16s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu16s_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu16s_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu16s_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu16s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu16s_BFu0i, Sf_BFu16s_BFu0i)
//============================================================================


struct  Sf_BFu16s_BFu0ll  {
  struct empty v1;
  unsigned short v2:16;
  __tsu64  :0;
};
//SIG(1 Sf_BFu16s_BFu0ll) C1{ FC2{} Fs:16 FL:0}



static void Test_Sf_BFu16s_BFu0ll()
{
  {
    init_simple_test("Sf_BFu16s_BFu0ll");
    static STRUCT_IF_C Sf_BFu16s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu16s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu16s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu16s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu16s_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu16s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu16s_BFu0ll, Sf_BFu16s_BFu0ll)
//============================================================================


struct  Sf_BFu16s_BFu0s  {
  struct empty v1;
  unsigned short v2:16;
  unsigned short  :0;
};
//SIG(1 Sf_BFu16s_BFu0s) C1{ FC2{} Fs:16 Fs:0}



static void Test_Sf_BFu16s_BFu0s()
{
  {
    init_simple_test("Sf_BFu16s_BFu0s");
    static STRUCT_IF_C Sf_BFu16s_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu16s_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu16s_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu16s_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 16, 1, "Sf_BFu16s_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 16, hide_ull(1LL<<15), "Sf_BFu16s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu16s_BFu0s, Sf_BFu16s_BFu0s)
//============================================================================


struct  Sf_BFu17i_BFu0c  {
  struct empty v1;
  unsigned int v2:17;
  unsigned char  :0;
};
//SIG(1 Sf_BFu17i_BFu0c) C1{ FC2{} Fi:17 Fc:0}



static void Test_Sf_BFu17i_BFu0c()
{
  {
    init_simple_test("Sf_BFu17i_BFu0c");
    static STRUCT_IF_C Sf_BFu17i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu17i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu17i_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu17i_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu17i_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu17i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu17i_BFu0c, Sf_BFu17i_BFu0c)
//============================================================================


struct  Sf_BFu17i_BFu0i  {
  struct empty v1;
  unsigned int v2:17;
  unsigned int  :0;
};
//SIG(1 Sf_BFu17i_BFu0i) C1{ FC2{} Fi:17 Fi:0}



static void Test_Sf_BFu17i_BFu0i()
{
  {
    init_simple_test("Sf_BFu17i_BFu0i");
    static STRUCT_IF_C Sf_BFu17i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu17i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu17i_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu17i_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu17i_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu17i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu17i_BFu0i, Sf_BFu17i_BFu0i)
//============================================================================


struct  Sf_BFu17i_BFu0ll  {
  struct empty v1;
  unsigned int v2:17;
  __tsu64  :0;
};
//SIG(1 Sf_BFu17i_BFu0ll) C1{ FC2{} Fi:17 FL:0}



static void Test_Sf_BFu17i_BFu0ll()
{
  {
    init_simple_test("Sf_BFu17i_BFu0ll");
    static STRUCT_IF_C Sf_BFu17i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu17i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu17i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu17i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu17i_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu17i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu17i_BFu0ll, Sf_BFu17i_BFu0ll)
//============================================================================


struct  Sf_BFu17i_BFu0s  {
  struct empty v1;
  unsigned int v2:17;
  unsigned short  :0;
};
//SIG(1 Sf_BFu17i_BFu0s) C1{ FC2{} Fi:17 Fs:0}



static void Test_Sf_BFu17i_BFu0s()
{
  {
    init_simple_test("Sf_BFu17i_BFu0s");
    static STRUCT_IF_C Sf_BFu17i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu17i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu17i_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu17i_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu17i_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu17i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu17i_BFu0s, Sf_BFu17i_BFu0s)
//============================================================================


struct  Sf_BFu17ll_BFu0c  {
  struct empty v1;
  __tsu64 v2:17;
  unsigned char  :0;
};
//SIG(1 Sf_BFu17ll_BFu0c) C1{ FC2{} FL:17 Fc:0}



static void Test_Sf_BFu17ll_BFu0c()
{
  {
    init_simple_test("Sf_BFu17ll_BFu0c");
    static STRUCT_IF_C Sf_BFu17ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu17ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu17ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu17ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu17ll_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu17ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu17ll_BFu0c, Sf_BFu17ll_BFu0c)
//============================================================================


struct  Sf_BFu17ll_BFu0i  {
  struct empty v1;
  __tsu64 v2:17;
  unsigned int  :0;
};
//SIG(1 Sf_BFu17ll_BFu0i) C1{ FC2{} FL:17 Fi:0}



static void Test_Sf_BFu17ll_BFu0i()
{
  {
    init_simple_test("Sf_BFu17ll_BFu0i");
    static STRUCT_IF_C Sf_BFu17ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu17ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu17ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu17ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu17ll_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu17ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu17ll_BFu0i, Sf_BFu17ll_BFu0i)
//============================================================================


struct  Sf_BFu17ll_BFu0ll  {
  struct empty v1;
  __tsu64 v2:17;
  __tsu64  :0;
};
//SIG(1 Sf_BFu17ll_BFu0ll) C1{ FC2{} FL:17 FL:0}



static void Test_Sf_BFu17ll_BFu0ll()
{
  {
    init_simple_test("Sf_BFu17ll_BFu0ll");
    static STRUCT_IF_C Sf_BFu17ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu17ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu17ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu17ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu17ll_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu17ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu17ll_BFu0ll, Sf_BFu17ll_BFu0ll)
//============================================================================


struct  Sf_BFu17ll_BFu0s  {
  struct empty v1;
  __tsu64 v2:17;
  unsigned short  :0;
};
//SIG(1 Sf_BFu17ll_BFu0s) C1{ FC2{} FL:17 Fs:0}



static void Test_Sf_BFu17ll_BFu0s()
{
  {
    init_simple_test("Sf_BFu17ll_BFu0s");
    static STRUCT_IF_C Sf_BFu17ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu17ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu17ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu17ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 17, 1, "Sf_BFu17ll_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 17, hide_ull(1LL<<16), "Sf_BFu17ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu17ll_BFu0s, Sf_BFu17ll_BFu0s)
//============================================================================


struct  Sf_BFu1c_BFu0c  {
  struct empty v1;
  unsigned char v2:1;
  unsigned char  :0;
};
//SIG(1 Sf_BFu1c_BFu0c) C1{ FC2{} Fc:1 Fc:0}



static void Test_Sf_BFu1c_BFu0c()
{
  {
    init_simple_test("Sf_BFu1c_BFu0c");
    static STRUCT_IF_C Sf_BFu1c_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(Sf_BFu1c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu1c_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu1c_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1c_BFu0c, Sf_BFu1c_BFu0c)
//============================================================================


struct  Sf_BFu1c_BFu0i  {
  struct empty v1;
  unsigned char v2:1;
  unsigned int  :0;
};
//SIG(1 Sf_BFu1c_BFu0i) C1{ FC2{} Fc:1 Fi:0}



static void Test_Sf_BFu1c_BFu0i()
{
  {
    init_simple_test("Sf_BFu1c_BFu0i");
    static STRUCT_IF_C Sf_BFu1c_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu1c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu1c_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu1c_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1c_BFu0i, Sf_BFu1c_BFu0i)
//============================================================================


struct  Sf_BFu1c_BFu0ll  {
  struct empty v1;
  unsigned char v2:1;
  __tsu64  :0;
};
//SIG(1 Sf_BFu1c_BFu0ll) C1{ FC2{} Fc:1 FL:0}



static void Test_Sf_BFu1c_BFu0ll()
{
  {
    init_simple_test("Sf_BFu1c_BFu0ll");
    static STRUCT_IF_C Sf_BFu1c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu1c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu1c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu1c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1c_BFu0ll, Sf_BFu1c_BFu0ll)
//============================================================================


struct  Sf_BFu1c_BFu0s  {
  struct empty v1;
  unsigned char v2:1;
  unsigned short  :0;
};
//SIG(1 Sf_BFu1c_BFu0s) C1{ FC2{} Fc:1 Fs:0}



static void Test_Sf_BFu1c_BFu0s()
{
  {
    init_simple_test("Sf_BFu1c_BFu0s");
    static STRUCT_IF_C Sf_BFu1c_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu1c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu1c_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu1c_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1c_BFu0s, Sf_BFu1c_BFu0s)
//============================================================================


struct  Sf_BFu1i_BFu0c  {
  struct empty v1;
  unsigned int v2:1;
  unsigned char  :0;
};
//SIG(1 Sf_BFu1i_BFu0c) C1{ FC2{} Fi:1 Fc:0}



static void Test_Sf_BFu1i_BFu0c()
{
  {
    init_simple_test("Sf_BFu1i_BFu0c");
    static STRUCT_IF_C Sf_BFu1i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu1i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu1i_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu1i_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1i_BFu0c, Sf_BFu1i_BFu0c)
//============================================================================


struct  Sf_BFu1i_BFu0i  {
  struct empty v1;
  unsigned int v2:1;
  unsigned int  :0;
};
//SIG(1 Sf_BFu1i_BFu0i) C1{ FC2{} Fi:1 Fi:0}



static void Test_Sf_BFu1i_BFu0i()
{
  {
    init_simple_test("Sf_BFu1i_BFu0i");
    static STRUCT_IF_C Sf_BFu1i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu1i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu1i_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu1i_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1i_BFu0i, Sf_BFu1i_BFu0i)
//============================================================================


struct  Sf_BFu1i_BFu0ll  {
  struct empty v1;
  unsigned int v2:1;
  __tsu64  :0;
};
//SIG(1 Sf_BFu1i_BFu0ll) C1{ FC2{} Fi:1 FL:0}



static void Test_Sf_BFu1i_BFu0ll()
{
  {
    init_simple_test("Sf_BFu1i_BFu0ll");
    static STRUCT_IF_C Sf_BFu1i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu1i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu1i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu1i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1i_BFu0ll, Sf_BFu1i_BFu0ll)
//============================================================================


struct  Sf_BFu1i_BFu0s  {
  struct empty v1;
  unsigned int v2:1;
  unsigned short  :0;
};
//SIG(1 Sf_BFu1i_BFu0s) C1{ FC2{} Fi:1 Fs:0}



static void Test_Sf_BFu1i_BFu0s()
{
  {
    init_simple_test("Sf_BFu1i_BFu0s");
    static STRUCT_IF_C Sf_BFu1i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu1i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu1i_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu1i_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1i_BFu0s, Sf_BFu1i_BFu0s)
//============================================================================


struct  Sf_BFu1ll_BFu0c  {
  struct empty v1;
  __tsu64 v2:1;
  unsigned char  :0;
};
//SIG(1 Sf_BFu1ll_BFu0c) C1{ FC2{} FL:1 Fc:0}



static void Test_Sf_BFu1ll_BFu0c()
{
  {
    init_simple_test("Sf_BFu1ll_BFu0c");
    static STRUCT_IF_C Sf_BFu1ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu1ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu1ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu1ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1ll_BFu0c, Sf_BFu1ll_BFu0c)
//============================================================================


struct  Sf_BFu1ll_BFu0i  {
  struct empty v1;
  __tsu64 v2:1;
  unsigned int  :0;
};
//SIG(1 Sf_BFu1ll_BFu0i) C1{ FC2{} FL:1 Fi:0}



static void Test_Sf_BFu1ll_BFu0i()
{
  {
    init_simple_test("Sf_BFu1ll_BFu0i");
    static STRUCT_IF_C Sf_BFu1ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu1ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu1ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu1ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1ll_BFu0i, Sf_BFu1ll_BFu0i)
//============================================================================


struct  Sf_BFu1ll_BFu0ll  {
  struct empty v1;
  __tsu64 v2:1;
  __tsu64  :0;
};
//SIG(1 Sf_BFu1ll_BFu0ll) C1{ FC2{} FL:1 FL:0}



static void Test_Sf_BFu1ll_BFu0ll()
{
  {
    init_simple_test("Sf_BFu1ll_BFu0ll");
    static STRUCT_IF_C Sf_BFu1ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu1ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu1ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu1ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1ll_BFu0ll, Sf_BFu1ll_BFu0ll)
//============================================================================


struct  Sf_BFu1ll_BFu0s  {
  struct empty v1;
  __tsu64 v2:1;
  unsigned short  :0;
};
//SIG(1 Sf_BFu1ll_BFu0s) C1{ FC2{} FL:1 Fs:0}



static void Test_Sf_BFu1ll_BFu0s()
{
  {
    init_simple_test("Sf_BFu1ll_BFu0s");
    static STRUCT_IF_C Sf_BFu1ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu1ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu1ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu1ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1ll_BFu0s, Sf_BFu1ll_BFu0s)
//============================================================================


struct  Sf_BFu1s_BFu0c  {
  struct empty v1;
  unsigned short v2:1;
  unsigned char  :0;
};
//SIG(1 Sf_BFu1s_BFu0c) C1{ FC2{} Fs:1 Fc:0}



static void Test_Sf_BFu1s_BFu0c()
{
  {
    init_simple_test("Sf_BFu1s_BFu0c");
    static STRUCT_IF_C Sf_BFu1s_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu1s_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu1s_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu1s_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1s_BFu0c, Sf_BFu1s_BFu0c)
//============================================================================


struct  Sf_BFu1s_BFu0i  {
  struct empty v1;
  unsigned short v2:1;
  unsigned int  :0;
};
//SIG(1 Sf_BFu1s_BFu0i) C1{ FC2{} Fs:1 Fi:0}



static void Test_Sf_BFu1s_BFu0i()
{
  {
    init_simple_test("Sf_BFu1s_BFu0i");
    static STRUCT_IF_C Sf_BFu1s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu1s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu1s_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu1s_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1s_BFu0i, Sf_BFu1s_BFu0i)
//============================================================================


struct  Sf_BFu1s_BFu0ll  {
  struct empty v1;
  unsigned short v2:1;
  __tsu64  :0;
};
//SIG(1 Sf_BFu1s_BFu0ll) C1{ FC2{} Fs:1 FL:0}



static void Test_Sf_BFu1s_BFu0ll()
{
  {
    init_simple_test("Sf_BFu1s_BFu0ll");
    static STRUCT_IF_C Sf_BFu1s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu1s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu1s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu1s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1s_BFu0ll, Sf_BFu1s_BFu0ll)
//============================================================================


struct  Sf_BFu1s_BFu0s  {
  struct empty v1;
  unsigned short v2:1;
  unsigned short  :0;
};
//SIG(1 Sf_BFu1s_BFu0s) C1{ FC2{} Fs:1 Fs:0}



static void Test_Sf_BFu1s_BFu0s()
{
  {
    init_simple_test("Sf_BFu1s_BFu0s");
    static STRUCT_IF_C Sf_BFu1s_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu1s_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu1s_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu1s_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 1, 1, "Sf_BFu1s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu1s_BFu0s, Sf_BFu1s_BFu0s)
//============================================================================


struct  Sf_BFu31i_BFu0c  {
  struct empty v1;
  unsigned int v2:31;
  unsigned char  :0;
};
//SIG(1 Sf_BFu31i_BFu0c) C1{ FC2{} Fi:31 Fc:0}



static void Test_Sf_BFu31i_BFu0c()
{
  {
    init_simple_test("Sf_BFu31i_BFu0c");
    static STRUCT_IF_C Sf_BFu31i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu31i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu31i_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu31i_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu31i_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu31i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu31i_BFu0c, Sf_BFu31i_BFu0c)
//============================================================================


struct  Sf_BFu31i_BFu0i  {
  struct empty v1;
  unsigned int v2:31;
  unsigned int  :0;
};
//SIG(1 Sf_BFu31i_BFu0i) C1{ FC2{} Fi:31 Fi:0}



static void Test_Sf_BFu31i_BFu0i()
{
  {
    init_simple_test("Sf_BFu31i_BFu0i");
    static STRUCT_IF_C Sf_BFu31i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu31i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu31i_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu31i_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu31i_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu31i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu31i_BFu0i, Sf_BFu31i_BFu0i)
//============================================================================


struct  Sf_BFu31i_BFu0ll  {
  struct empty v1;
  unsigned int v2:31;
  __tsu64  :0;
};
//SIG(1 Sf_BFu31i_BFu0ll) C1{ FC2{} Fi:31 FL:0}



static void Test_Sf_BFu31i_BFu0ll()
{
  {
    init_simple_test("Sf_BFu31i_BFu0ll");
    static STRUCT_IF_C Sf_BFu31i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu31i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu31i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu31i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu31i_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu31i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu31i_BFu0ll, Sf_BFu31i_BFu0ll)
//============================================================================


struct  Sf_BFu31i_BFu0s  {
  struct empty v1;
  unsigned int v2:31;
  unsigned short  :0;
};
//SIG(1 Sf_BFu31i_BFu0s) C1{ FC2{} Fi:31 Fs:0}



static void Test_Sf_BFu31i_BFu0s()
{
  {
    init_simple_test("Sf_BFu31i_BFu0s");
    static STRUCT_IF_C Sf_BFu31i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu31i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu31i_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu31i_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu31i_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu31i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu31i_BFu0s, Sf_BFu31i_BFu0s)
//============================================================================


struct  Sf_BFu31ll_BFu0c  {
  struct empty v1;
  __tsu64 v2:31;
  unsigned char  :0;
};
//SIG(1 Sf_BFu31ll_BFu0c) C1{ FC2{} FL:31 Fc:0}



static void Test_Sf_BFu31ll_BFu0c()
{
  {
    init_simple_test("Sf_BFu31ll_BFu0c");
    static STRUCT_IF_C Sf_BFu31ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu31ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu31ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu31ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu31ll_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu31ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu31ll_BFu0c, Sf_BFu31ll_BFu0c)
//============================================================================


struct  Sf_BFu31ll_BFu0i  {
  struct empty v1;
  __tsu64 v2:31;
  unsigned int  :0;
};
//SIG(1 Sf_BFu31ll_BFu0i) C1{ FC2{} FL:31 Fi:0}



static void Test_Sf_BFu31ll_BFu0i()
{
  {
    init_simple_test("Sf_BFu31ll_BFu0i");
    static STRUCT_IF_C Sf_BFu31ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu31ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu31ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu31ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu31ll_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu31ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu31ll_BFu0i, Sf_BFu31ll_BFu0i)
//============================================================================


struct  Sf_BFu31ll_BFu0ll  {
  struct empty v1;
  __tsu64 v2:31;
  __tsu64  :0;
};
//SIG(1 Sf_BFu31ll_BFu0ll) C1{ FC2{} FL:31 FL:0}



static void Test_Sf_BFu31ll_BFu0ll()
{
  {
    init_simple_test("Sf_BFu31ll_BFu0ll");
    static STRUCT_IF_C Sf_BFu31ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu31ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu31ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu31ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu31ll_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu31ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu31ll_BFu0ll, Sf_BFu31ll_BFu0ll)
//============================================================================


struct  Sf_BFu31ll_BFu0s  {
  struct empty v1;
  __tsu64 v2:31;
  unsigned short  :0;
};
//SIG(1 Sf_BFu31ll_BFu0s) C1{ FC2{} FL:31 Fs:0}



static void Test_Sf_BFu31ll_BFu0s()
{
  {
    init_simple_test("Sf_BFu31ll_BFu0s");
    static STRUCT_IF_C Sf_BFu31ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu31ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu31ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu31ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 31, 1, "Sf_BFu31ll_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 31, hide_ull(1LL<<30), "Sf_BFu31ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu31ll_BFu0s, Sf_BFu31ll_BFu0s)
//============================================================================


struct  Sf_BFu32i_BFu0c  {
  struct empty v1;
  unsigned int v2:32;
  unsigned char  :0;
};
//SIG(1 Sf_BFu32i_BFu0c) C1{ FC2{} Fi:32 Fc:0}



static void Test_Sf_BFu32i_BFu0c()
{
  {
    init_simple_test("Sf_BFu32i_BFu0c");
    static STRUCT_IF_C Sf_BFu32i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu32i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu32i_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu32i_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu32i_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu32i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu32i_BFu0c, Sf_BFu32i_BFu0c)
//============================================================================


struct  Sf_BFu32i_BFu0i  {
  struct empty v1;
  unsigned int v2:32;
  unsigned int  :0;
};
//SIG(1 Sf_BFu32i_BFu0i) C1{ FC2{} Fi:32 Fi:0}



static void Test_Sf_BFu32i_BFu0i()
{
  {
    init_simple_test("Sf_BFu32i_BFu0i");
    static STRUCT_IF_C Sf_BFu32i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu32i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu32i_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu32i_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu32i_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu32i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu32i_BFu0i, Sf_BFu32i_BFu0i)
//============================================================================


struct  Sf_BFu32i_BFu0ll  {
  struct empty v1;
  unsigned int v2:32;
  __tsu64  :0;
};
//SIG(1 Sf_BFu32i_BFu0ll) C1{ FC2{} Fi:32 FL:0}



static void Test_Sf_BFu32i_BFu0ll()
{
  {
    init_simple_test("Sf_BFu32i_BFu0ll");
    static STRUCT_IF_C Sf_BFu32i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu32i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu32i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu32i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu32i_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu32i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu32i_BFu0ll, Sf_BFu32i_BFu0ll)
//============================================================================


struct  Sf_BFu32i_BFu0s  {
  struct empty v1;
  unsigned int v2:32;
  unsigned short  :0;
};
//SIG(1 Sf_BFu32i_BFu0s) C1{ FC2{} Fi:32 Fs:0}



static void Test_Sf_BFu32i_BFu0s()
{
  {
    init_simple_test("Sf_BFu32i_BFu0s");
    static STRUCT_IF_C Sf_BFu32i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu32i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu32i_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu32i_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu32i_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu32i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu32i_BFu0s, Sf_BFu32i_BFu0s)
//============================================================================


struct  Sf_BFu32ll_BFu0c  {
  struct empty v1;
  __tsu64 v2:32;
  unsigned char  :0;
};
//SIG(1 Sf_BFu32ll_BFu0c) C1{ FC2{} FL:32 Fc:0}



static void Test_Sf_BFu32ll_BFu0c()
{
  {
    init_simple_test("Sf_BFu32ll_BFu0c");
    static STRUCT_IF_C Sf_BFu32ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu32ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu32ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu32ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu32ll_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu32ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu32ll_BFu0c, Sf_BFu32ll_BFu0c)
//============================================================================


struct  Sf_BFu32ll_BFu0i  {
  struct empty v1;
  __tsu64 v2:32;
  unsigned int  :0;
};
//SIG(1 Sf_BFu32ll_BFu0i) C1{ FC2{} FL:32 Fi:0}



static void Test_Sf_BFu32ll_BFu0i()
{
  {
    init_simple_test("Sf_BFu32ll_BFu0i");
    static STRUCT_IF_C Sf_BFu32ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu32ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu32ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu32ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu32ll_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu32ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu32ll_BFu0i, Sf_BFu32ll_BFu0i)
//============================================================================


struct  Sf_BFu32ll_BFu0ll  {
  struct empty v1;
  __tsu64 v2:32;
  __tsu64  :0;
};
//SIG(1 Sf_BFu32ll_BFu0ll) C1{ FC2{} FL:32 FL:0}



static void Test_Sf_BFu32ll_BFu0ll()
{
  {
    init_simple_test("Sf_BFu32ll_BFu0ll");
    static STRUCT_IF_C Sf_BFu32ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu32ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu32ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu32ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu32ll_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu32ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu32ll_BFu0ll, Sf_BFu32ll_BFu0ll)
//============================================================================


struct  Sf_BFu32ll_BFu0s  {
  struct empty v1;
  __tsu64 v2:32;
  unsigned short  :0;
};
//SIG(1 Sf_BFu32ll_BFu0s) C1{ FC2{} FL:32 Fs:0}



static void Test_Sf_BFu32ll_BFu0s()
{
  {
    init_simple_test("Sf_BFu32ll_BFu0s");
    static STRUCT_IF_C Sf_BFu32ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu32ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu32ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu32ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 32, 1, "Sf_BFu32ll_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 32, hide_ull(1LL<<31), "Sf_BFu32ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu32ll_BFu0s, Sf_BFu32ll_BFu0s)
//============================================================================


struct  Sf_BFu33_BFu0c  {
  struct empty v1;
  __tsu64 v2:33;
  unsigned char  :0;
};
//SIG(1 Sf_BFu33_BFu0c) C1{ FC2{} FL:33 Fc:0}



static void Test_Sf_BFu33_BFu0c()
{
  {
    init_simple_test("Sf_BFu33_BFu0c");
    static STRUCT_IF_C Sf_BFu33_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu33_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu33_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu33_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 33, 1, "Sf_BFu33_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 33, hide_ull(1LL<<32), "Sf_BFu33_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu33_BFu0c, Sf_BFu33_BFu0c)
//============================================================================


struct  Sf_BFu33_BFu0i  {
  struct empty v1;
  __tsu64 v2:33;
  unsigned int  :0;
};
//SIG(1 Sf_BFu33_BFu0i) C1{ FC2{} FL:33 Fi:0}



static void Test_Sf_BFu33_BFu0i()
{
  {
    init_simple_test("Sf_BFu33_BFu0i");
    static STRUCT_IF_C Sf_BFu33_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu33_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu33_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu33_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 33, 1, "Sf_BFu33_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 33, hide_ull(1LL<<32), "Sf_BFu33_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu33_BFu0i, Sf_BFu33_BFu0i)
//============================================================================


struct  Sf_BFu33_BFu0ll  {
  struct empty v1;
  __tsu64 v2:33;
  __tsu64  :0;
};
//SIG(1 Sf_BFu33_BFu0ll) C1{ FC2{} FL:33 FL:0}



static void Test_Sf_BFu33_BFu0ll()
{
  {
    init_simple_test("Sf_BFu33_BFu0ll");
    static STRUCT_IF_C Sf_BFu33_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu33_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu33_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu33_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 33, 1, "Sf_BFu33_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 33, hide_ull(1LL<<32), "Sf_BFu33_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu33_BFu0ll, Sf_BFu33_BFu0ll)
//============================================================================


struct  Sf_BFu33_BFu0s  {
  struct empty v1;
  __tsu64 v2:33;
  unsigned short  :0;
};
//SIG(1 Sf_BFu33_BFu0s) C1{ FC2{} FL:33 Fs:0}



static void Test_Sf_BFu33_BFu0s()
{
  {
    init_simple_test("Sf_BFu33_BFu0s");
    static STRUCT_IF_C Sf_BFu33_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Sf_BFu33_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu33_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu33_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 33, 1, "Sf_BFu33_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 33, hide_ull(1LL<<32), "Sf_BFu33_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu33_BFu0s, Sf_BFu33_BFu0s)
//============================================================================


struct  Sf_BFu7c_BFu0c  {
  struct empty v1;
  unsigned char v2:7;
  unsigned char  :0;
};
//SIG(1 Sf_BFu7c_BFu0c) C1{ FC2{} Fc:7 Fc:0}



static void Test_Sf_BFu7c_BFu0c()
{
  {
    init_simple_test("Sf_BFu7c_BFu0c");
    static STRUCT_IF_C Sf_BFu7c_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(Sf_BFu7c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu7c_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu7c_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7c_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7c_BFu0c, Sf_BFu7c_BFu0c)
//============================================================================


struct  Sf_BFu7c_BFu0i  {
  struct empty v1;
  unsigned char v2:7;
  unsigned int  :0;
};
//SIG(1 Sf_BFu7c_BFu0i) C1{ FC2{} Fc:7 Fi:0}



static void Test_Sf_BFu7c_BFu0i()
{
  {
    init_simple_test("Sf_BFu7c_BFu0i");
    static STRUCT_IF_C Sf_BFu7c_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu7c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu7c_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu7c_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7c_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7c_BFu0i, Sf_BFu7c_BFu0i)
//============================================================================


struct  Sf_BFu7c_BFu0ll  {
  struct empty v1;
  unsigned char v2:7;
  __tsu64  :0;
};
//SIG(1 Sf_BFu7c_BFu0ll) C1{ FC2{} Fc:7 FL:0}



static void Test_Sf_BFu7c_BFu0ll()
{
  {
    init_simple_test("Sf_BFu7c_BFu0ll");
    static STRUCT_IF_C Sf_BFu7c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu7c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu7c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu7c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7c_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7c_BFu0ll, Sf_BFu7c_BFu0ll)
//============================================================================


struct  Sf_BFu7c_BFu0s  {
  struct empty v1;
  unsigned char v2:7;
  unsigned short  :0;
};
//SIG(1 Sf_BFu7c_BFu0s) C1{ FC2{} Fc:7 Fs:0}



static void Test_Sf_BFu7c_BFu0s()
{
  {
    init_simple_test("Sf_BFu7c_BFu0s");
    static STRUCT_IF_C Sf_BFu7c_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu7c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu7c_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu7c_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7c_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7c_BFu0s, Sf_BFu7c_BFu0s)
//============================================================================


struct  Sf_BFu7i_BFu0c  {
  struct empty v1;
  unsigned int v2:7;
  unsigned char  :0;
};
//SIG(1 Sf_BFu7i_BFu0c) C1{ FC2{} Fi:7 Fc:0}



static void Test_Sf_BFu7i_BFu0c()
{
  {
    init_simple_test("Sf_BFu7i_BFu0c");
    static STRUCT_IF_C Sf_BFu7i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu7i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu7i_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu7i_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7i_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7i_BFu0c, Sf_BFu7i_BFu0c)
//============================================================================


struct  Sf_BFu7i_BFu0i  {
  struct empty v1;
  unsigned int v2:7;
  unsigned int  :0;
};
//SIG(1 Sf_BFu7i_BFu0i) C1{ FC2{} Fi:7 Fi:0}



static void Test_Sf_BFu7i_BFu0i()
{
  {
    init_simple_test("Sf_BFu7i_BFu0i");
    static STRUCT_IF_C Sf_BFu7i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu7i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu7i_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu7i_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7i_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7i_BFu0i, Sf_BFu7i_BFu0i)
//============================================================================


struct  Sf_BFu7i_BFu0ll  {
  struct empty v1;
  unsigned int v2:7;
  __tsu64  :0;
};
//SIG(1 Sf_BFu7i_BFu0ll) C1{ FC2{} Fi:7 FL:0}



static void Test_Sf_BFu7i_BFu0ll()
{
  {
    init_simple_test("Sf_BFu7i_BFu0ll");
    static STRUCT_IF_C Sf_BFu7i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu7i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu7i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu7i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7i_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7i_BFu0ll, Sf_BFu7i_BFu0ll)
//============================================================================


struct  Sf_BFu7i_BFu0s  {
  struct empty v1;
  unsigned int v2:7;
  unsigned short  :0;
};
//SIG(1 Sf_BFu7i_BFu0s) C1{ FC2{} Fi:7 Fs:0}



static void Test_Sf_BFu7i_BFu0s()
{
  {
    init_simple_test("Sf_BFu7i_BFu0s");
    static STRUCT_IF_C Sf_BFu7i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu7i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu7i_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu7i_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7i_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7i_BFu0s, Sf_BFu7i_BFu0s)
//============================================================================


struct  Sf_BFu7ll_BFu0c  {
  struct empty v1;
  __tsu64 v2:7;
  unsigned char  :0;
};
//SIG(1 Sf_BFu7ll_BFu0c) C1{ FC2{} FL:7 Fc:0}



static void Test_Sf_BFu7ll_BFu0c()
{
  {
    init_simple_test("Sf_BFu7ll_BFu0c");
    static STRUCT_IF_C Sf_BFu7ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu7ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu7ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu7ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7ll_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7ll_BFu0c, Sf_BFu7ll_BFu0c)
//============================================================================


struct  Sf_BFu7ll_BFu0i  {
  struct empty v1;
  __tsu64 v2:7;
  unsigned int  :0;
};
//SIG(1 Sf_BFu7ll_BFu0i) C1{ FC2{} FL:7 Fi:0}



static void Test_Sf_BFu7ll_BFu0i()
{
  {
    init_simple_test("Sf_BFu7ll_BFu0i");
    static STRUCT_IF_C Sf_BFu7ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu7ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu7ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu7ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7ll_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7ll_BFu0i, Sf_BFu7ll_BFu0i)
//============================================================================


struct  Sf_BFu7ll_BFu0ll  {
  struct empty v1;
  __tsu64 v2:7;
  __tsu64  :0;
};
//SIG(1 Sf_BFu7ll_BFu0ll) C1{ FC2{} FL:7 FL:0}



static void Test_Sf_BFu7ll_BFu0ll()
{
  {
    init_simple_test("Sf_BFu7ll_BFu0ll");
    static STRUCT_IF_C Sf_BFu7ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu7ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu7ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu7ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7ll_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7ll_BFu0ll, Sf_BFu7ll_BFu0ll)
//============================================================================


struct  Sf_BFu7ll_BFu0s  {
  struct empty v1;
  __tsu64 v2:7;
  unsigned short  :0;
};
//SIG(1 Sf_BFu7ll_BFu0s) C1{ FC2{} FL:7 Fs:0}



static void Test_Sf_BFu7ll_BFu0s()
{
  {
    init_simple_test("Sf_BFu7ll_BFu0s");
    static STRUCT_IF_C Sf_BFu7ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu7ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu7ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu7ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7ll_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7ll_BFu0s, Sf_BFu7ll_BFu0s)
//============================================================================


struct  Sf_BFu7s_BFu0c  {
  struct empty v1;
  unsigned short v2:7;
  unsigned char  :0;
};
//SIG(1 Sf_BFu7s_BFu0c) C1{ FC2{} Fs:7 Fc:0}



static void Test_Sf_BFu7s_BFu0c()
{
  {
    init_simple_test("Sf_BFu7s_BFu0c");
    static STRUCT_IF_C Sf_BFu7s_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu7s_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu7s_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu7s_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7s_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7s_BFu0c, Sf_BFu7s_BFu0c)
//============================================================================


struct  Sf_BFu7s_BFu0i  {
  struct empty v1;
  unsigned short v2:7;
  unsigned int  :0;
};
//SIG(1 Sf_BFu7s_BFu0i) C1{ FC2{} Fs:7 Fi:0}



static void Test_Sf_BFu7s_BFu0i()
{
  {
    init_simple_test("Sf_BFu7s_BFu0i");
    static STRUCT_IF_C Sf_BFu7s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu7s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu7s_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu7s_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7s_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7s_BFu0i, Sf_BFu7s_BFu0i)
//============================================================================


struct  Sf_BFu7s_BFu0ll  {
  struct empty v1;
  unsigned short v2:7;
  __tsu64  :0;
};
//SIG(1 Sf_BFu7s_BFu0ll) C1{ FC2{} Fs:7 FL:0}



static void Test_Sf_BFu7s_BFu0ll()
{
  {
    init_simple_test("Sf_BFu7s_BFu0ll");
    static STRUCT_IF_C Sf_BFu7s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu7s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu7s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu7s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7s_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7s_BFu0ll, Sf_BFu7s_BFu0ll)
//============================================================================


struct  Sf_BFu7s_BFu0s  {
  struct empty v1;
  unsigned short v2:7;
  unsigned short  :0;
};
//SIG(1 Sf_BFu7s_BFu0s) C1{ FC2{} Fs:7 Fs:0}



static void Test_Sf_BFu7s_BFu0s()
{
  {
    init_simple_test("Sf_BFu7s_BFu0s");
    static STRUCT_IF_C Sf_BFu7s_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu7s_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu7s_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu7s_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 7, 1, "Sf_BFu7s_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 7, hide_ull(1LL<<6), "Sf_BFu7s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu7s_BFu0s, Sf_BFu7s_BFu0s)
//============================================================================


struct  Sf_BFu8c_BFu0c  {
  struct empty v1;
  unsigned char v2:8;
  unsigned char  :0;
};
//SIG(1 Sf_BFu8c_BFu0c) C1{ FC2{} Fc:8 Fc:0}



static void Test_Sf_BFu8c_BFu0c()
{
  {
    init_simple_test("Sf_BFu8c_BFu0c");
    static STRUCT_IF_C Sf_BFu8c_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(Sf_BFu8c_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_BFu8c_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu8c_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8c_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8c_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8c_BFu0c, Sf_BFu8c_BFu0c)
//============================================================================


struct  Sf_BFu8c_BFu0i  {
  struct empty v1;
  unsigned char v2:8;
  unsigned int  :0;
};
//SIG(1 Sf_BFu8c_BFu0i) C1{ FC2{} Fc:8 Fi:0}



static void Test_Sf_BFu8c_BFu0i()
{
  {
    init_simple_test("Sf_BFu8c_BFu0i");
    static STRUCT_IF_C Sf_BFu8c_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu8c_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu8c_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu8c_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8c_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8c_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8c_BFu0i, Sf_BFu8c_BFu0i)
//============================================================================


struct  Sf_BFu8c_BFu0ll  {
  struct empty v1;
  unsigned char v2:8;
  __tsu64  :0;
};
//SIG(1 Sf_BFu8c_BFu0ll) C1{ FC2{} Fc:8 FL:0}



static void Test_Sf_BFu8c_BFu0ll()
{
  {
    init_simple_test("Sf_BFu8c_BFu0ll");
    static STRUCT_IF_C Sf_BFu8c_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu8c_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu8c_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu8c_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8c_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8c_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8c_BFu0ll, Sf_BFu8c_BFu0ll)
//============================================================================


struct  Sf_BFu8c_BFu0s  {
  struct empty v1;
  unsigned char v2:8;
  unsigned short  :0;
};
//SIG(1 Sf_BFu8c_BFu0s) C1{ FC2{} Fc:8 Fs:0}



static void Test_Sf_BFu8c_BFu0s()
{
  {
    init_simple_test("Sf_BFu8c_BFu0s");
    static STRUCT_IF_C Sf_BFu8c_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu8c_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_BFu8c_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu8c_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8c_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8c_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8c_BFu0s, Sf_BFu8c_BFu0s)
//============================================================================


struct  Sf_BFu8i_BFu0c  {
  struct empty v1;
  unsigned int v2:8;
  unsigned char  :0;
};
//SIG(1 Sf_BFu8i_BFu0c) C1{ FC2{} Fi:8 Fc:0}



static void Test_Sf_BFu8i_BFu0c()
{
  {
    init_simple_test("Sf_BFu8i_BFu0c");
    static STRUCT_IF_C Sf_BFu8i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu8i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu8i_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu8i_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8i_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8i_BFu0c, Sf_BFu8i_BFu0c)
//============================================================================


struct  Sf_BFu8i_BFu0i  {
  struct empty v1;
  unsigned int v2:8;
  unsigned int  :0;
};
//SIG(1 Sf_BFu8i_BFu0i) C1{ FC2{} Fi:8 Fi:0}



static void Test_Sf_BFu8i_BFu0i()
{
  {
    init_simple_test("Sf_BFu8i_BFu0i");
    static STRUCT_IF_C Sf_BFu8i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu8i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu8i_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu8i_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8i_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8i_BFu0i, Sf_BFu8i_BFu0i)
//============================================================================


struct  Sf_BFu8i_BFu0ll  {
  struct empty v1;
  unsigned int v2:8;
  __tsu64  :0;
};
//SIG(1 Sf_BFu8i_BFu0ll) C1{ FC2{} Fi:8 FL:0}



static void Test_Sf_BFu8i_BFu0ll()
{
  {
    init_simple_test("Sf_BFu8i_BFu0ll");
    static STRUCT_IF_C Sf_BFu8i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu8i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu8i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu8i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8i_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8i_BFu0ll, Sf_BFu8i_BFu0ll)
//============================================================================


struct  Sf_BFu8i_BFu0s  {
  struct empty v1;
  unsigned int v2:8;
  unsigned short  :0;
};
//SIG(1 Sf_BFu8i_BFu0s) C1{ FC2{} Fi:8 Fs:0}



static void Test_Sf_BFu8i_BFu0s()
{
  {
    init_simple_test("Sf_BFu8i_BFu0s");
    static STRUCT_IF_C Sf_BFu8i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu8i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu8i_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu8i_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8i_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8i_BFu0s, Sf_BFu8i_BFu0s)
//============================================================================


struct  Sf_BFu8ll_BFu0c  {
  struct empty v1;
  __tsu64 v2:8;
  unsigned char  :0;
};
//SIG(1 Sf_BFu8ll_BFu0c) C1{ FC2{} FL:8 Fc:0}



static void Test_Sf_BFu8ll_BFu0c()
{
  {
    init_simple_test("Sf_BFu8ll_BFu0c");
    static STRUCT_IF_C Sf_BFu8ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu8ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu8ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu8ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8ll_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8ll_BFu0c, Sf_BFu8ll_BFu0c)
//============================================================================


struct  Sf_BFu8ll_BFu0i  {
  struct empty v1;
  __tsu64 v2:8;
  unsigned int  :0;
};
//SIG(1 Sf_BFu8ll_BFu0i) C1{ FC2{} FL:8 Fi:0}



static void Test_Sf_BFu8ll_BFu0i()
{
  {
    init_simple_test("Sf_BFu8ll_BFu0i");
    static STRUCT_IF_C Sf_BFu8ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu8ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu8ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu8ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8ll_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8ll_BFu0i, Sf_BFu8ll_BFu0i)
//============================================================================


struct  Sf_BFu8ll_BFu0ll  {
  struct empty v1;
  __tsu64 v2:8;
  __tsu64  :0;
};
//SIG(1 Sf_BFu8ll_BFu0ll) C1{ FC2{} FL:8 FL:0}



static void Test_Sf_BFu8ll_BFu0ll()
{
  {
    init_simple_test("Sf_BFu8ll_BFu0ll");
    static STRUCT_IF_C Sf_BFu8ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu8ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu8ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu8ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8ll_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8ll_BFu0ll, Sf_BFu8ll_BFu0ll)
//============================================================================


struct  Sf_BFu8ll_BFu0s  {
  struct empty v1;
  __tsu64 v2:8;
  unsigned short  :0;
};
//SIG(1 Sf_BFu8ll_BFu0s) C1{ FC2{} FL:8 Fs:0}



static void Test_Sf_BFu8ll_BFu0s()
{
  {
    init_simple_test("Sf_BFu8ll_BFu0s");
    static STRUCT_IF_C Sf_BFu8ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu8ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu8ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu8ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8ll_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8ll_BFu0s, Sf_BFu8ll_BFu0s)
//============================================================================


struct  Sf_BFu8s_BFu0c  {
  struct empty v1;
  unsigned short v2:8;
  unsigned char  :0;
};
//SIG(1 Sf_BFu8s_BFu0c) C1{ FC2{} Fs:8 Fc:0}



static void Test_Sf_BFu8s_BFu0c()
{
  {
    init_simple_test("Sf_BFu8s_BFu0c");
    static STRUCT_IF_C Sf_BFu8s_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu8s_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu8s_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu8s_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8s_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8s_BFu0c, Sf_BFu8s_BFu0c)
//============================================================================


struct  Sf_BFu8s_BFu0i  {
  struct empty v1;
  unsigned short v2:8;
  unsigned int  :0;
};
//SIG(1 Sf_BFu8s_BFu0i) C1{ FC2{} Fs:8 Fi:0}



static void Test_Sf_BFu8s_BFu0i()
{
  {
    init_simple_test("Sf_BFu8s_BFu0i");
    static STRUCT_IF_C Sf_BFu8s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu8s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu8s_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu8s_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8s_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8s_BFu0i, Sf_BFu8s_BFu0i)
//============================================================================


struct  Sf_BFu8s_BFu0ll  {
  struct empty v1;
  unsigned short v2:8;
  __tsu64  :0;
};
//SIG(1 Sf_BFu8s_BFu0ll) C1{ FC2{} Fs:8 FL:0}



static void Test_Sf_BFu8s_BFu0ll()
{
  {
    init_simple_test("Sf_BFu8s_BFu0ll");
    static STRUCT_IF_C Sf_BFu8s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu8s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu8s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu8s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8s_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8s_BFu0ll, Sf_BFu8s_BFu0ll)
//============================================================================


struct  Sf_BFu8s_BFu0s  {
  struct empty v1;
  unsigned short v2:8;
  unsigned short  :0;
};
//SIG(1 Sf_BFu8s_BFu0s) C1{ FC2{} Fs:8 Fs:0}



static void Test_Sf_BFu8s_BFu0s()
{
  {
    init_simple_test("Sf_BFu8s_BFu0s");
    static STRUCT_IF_C Sf_BFu8s_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu8s_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu8s_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu8s_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 8, 1, "Sf_BFu8s_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 8, hide_ull(1LL<<7), "Sf_BFu8s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu8s_BFu0s, Sf_BFu8s_BFu0s)
//============================================================================


struct  Sf_BFu9i_BFu0c  {
  struct empty v1;
  unsigned int v2:9;
  unsigned char  :0;
};
//SIG(1 Sf_BFu9i_BFu0c) C1{ FC2{} Fi:9 Fc:0}



static void Test_Sf_BFu9i_BFu0c()
{
  {
    init_simple_test("Sf_BFu9i_BFu0c");
    static STRUCT_IF_C Sf_BFu9i_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9i_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu9i_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu9i_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9i_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9i_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9i_BFu0c, Sf_BFu9i_BFu0c)
//============================================================================


struct  Sf_BFu9i_BFu0i  {
  struct empty v1;
  unsigned int v2:9;
  unsigned int  :0;
};
//SIG(1 Sf_BFu9i_BFu0i) C1{ FC2{} Fi:9 Fi:0}



static void Test_Sf_BFu9i_BFu0i()
{
  {
    init_simple_test("Sf_BFu9i_BFu0i");
    static STRUCT_IF_C Sf_BFu9i_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9i_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu9i_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu9i_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9i_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9i_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9i_BFu0i, Sf_BFu9i_BFu0i)
//============================================================================


struct  Sf_BFu9i_BFu0ll  {
  struct empty v1;
  unsigned int v2:9;
  __tsu64  :0;
};
//SIG(1 Sf_BFu9i_BFu0ll) C1{ FC2{} Fi:9 FL:0}



static void Test_Sf_BFu9i_BFu0ll()
{
  {
    init_simple_test("Sf_BFu9i_BFu0ll");
    static STRUCT_IF_C Sf_BFu9i_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu9i_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_BFu9i_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu9i_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9i_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9i_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9i_BFu0ll, Sf_BFu9i_BFu0ll)
//============================================================================


struct  Sf_BFu9i_BFu0s  {
  struct empty v1;
  unsigned int v2:9;
  unsigned short  :0;
};
//SIG(1 Sf_BFu9i_BFu0s) C1{ FC2{} Fi:9 Fs:0}



static void Test_Sf_BFu9i_BFu0s()
{
  {
    init_simple_test("Sf_BFu9i_BFu0s");
    static STRUCT_IF_C Sf_BFu9i_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9i_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_BFu9i_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu9i_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9i_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9i_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9i_BFu0s, Sf_BFu9i_BFu0s)
//============================================================================


struct  Sf_BFu9ll_BFu0c  {
  struct empty v1;
  __tsu64 v2:9;
  unsigned char  :0;
};
//SIG(1 Sf_BFu9ll_BFu0c) C1{ FC2{} FL:9 Fc:0}



static void Test_Sf_BFu9ll_BFu0c()
{
  {
    init_simple_test("Sf_BFu9ll_BFu0c");
    static STRUCT_IF_C Sf_BFu9ll_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu9ll_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu9ll_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9ll_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9ll_BFu0c, Sf_BFu9ll_BFu0c)
//============================================================================


struct  Sf_BFu9ll_BFu0i  {
  struct empty v1;
  __tsu64 v2:9;
  unsigned int  :0;
};
//SIG(1 Sf_BFu9ll_BFu0i) C1{ FC2{} FL:9 Fi:0}



static void Test_Sf_BFu9ll_BFu0i()
{
  {
    init_simple_test("Sf_BFu9ll_BFu0i");
    static STRUCT_IF_C Sf_BFu9ll_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu9ll_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu9ll_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9ll_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9ll_BFu0i, Sf_BFu9ll_BFu0i)
//============================================================================


struct  Sf_BFu9ll_BFu0ll  {
  struct empty v1;
  __tsu64 v2:9;
  __tsu64  :0;
};
//SIG(1 Sf_BFu9ll_BFu0ll) C1{ FC2{} FL:9 FL:0}



static void Test_Sf_BFu9ll_BFu0ll()
{
  {
    init_simple_test("Sf_BFu9ll_BFu0ll");
    static STRUCT_IF_C Sf_BFu9ll_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu9ll_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu9ll_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9ll_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9ll_BFu0ll, Sf_BFu9ll_BFu0ll)
//============================================================================


struct  Sf_BFu9ll_BFu0s  {
  struct empty v1;
  __tsu64 v2:9;
  unsigned short  :0;
};
//SIG(1 Sf_BFu9ll_BFu0s) C1{ FC2{} FL:9 Fs:0}



static void Test_Sf_BFu9ll_BFu0s()
{
  {
    init_simple_test("Sf_BFu9ll_BFu0s");
    static STRUCT_IF_C Sf_BFu9ll_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu9ll_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_BFu9ll_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu9ll_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9ll_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9ll_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9ll_BFu0s, Sf_BFu9ll_BFu0s)
//============================================================================


struct  Sf_BFu9s_BFu0c  {
  struct empty v1;
  unsigned short v2:9;
  unsigned char  :0;
};
//SIG(1 Sf_BFu9s_BFu0c) C1{ FC2{} Fs:9 Fc:0}



static void Test_Sf_BFu9s_BFu0c()
{
  {
    init_simple_test("Sf_BFu9s_BFu0c");
    static STRUCT_IF_C Sf_BFu9s_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9s_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu9s_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu0c.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu0c");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu0c");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu0c, Sf_BFu9s_BFu0c)
//============================================================================


struct  Sf_BFu9s_BFu0i  {
  struct empty v1;
  unsigned short v2:9;
  unsigned int  :0;
};
//SIG(1 Sf_BFu9s_BFu0i) C1{ FC2{} Fs:9 Fi:0}



static void Test_Sf_BFu9s_BFu0i()
{
  {
    init_simple_test("Sf_BFu9s_BFu0i");
    static STRUCT_IF_C Sf_BFu9s_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_BFu9s_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu9s_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu0i.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu0i");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu0i");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu0i, Sf_BFu9s_BFu0i)
//============================================================================


struct  Sf_BFu9s_BFu0ll  {
  struct empty v1;
  unsigned short v2:9;
  __tsu64  :0;
};
//SIG(1 Sf_BFu9s_BFu0ll) C1{ FC2{} Fs:9 FL:0}



static void Test_Sf_BFu9s_BFu0ll()
{
  {
    init_simple_test("Sf_BFu9s_BFu0ll");
    static STRUCT_IF_C Sf_BFu9s_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_BFu9s_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_BFu9s_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu0ll.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu0ll");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu0ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu0ll, Sf_BFu9s_BFu0ll)
//============================================================================


struct  Sf_BFu9s_BFu0s  {
  struct empty v1;
  unsigned short v2:9;
  unsigned short  :0;
};
//SIG(1 Sf_BFu9s_BFu0s) C1{ FC2{} Fs:9 Fs:0}



static void Test_Sf_BFu9s_BFu0s()
{
  {
    init_simple_test("Sf_BFu9s_BFu0s");
    static STRUCT_IF_C Sf_BFu9s_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_BFu9s_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_BFu9s_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_BFu9s_BFu0s.v1");
    set_bf_and_test(lv, v2, 0, 0, 9, 1, "Sf_BFu9s_BFu0s");
    set_bf_and_test(lv, v2, 0, 0, 9, hide_ull(1LL<<8), "Sf_BFu9s_BFu0s");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_BFu9s_BFu0s, Sf_BFu9s_BFu0s)
//============================================================================


struct  Sf_C_BFu0c  {
  struct empty v1;
  char v2;
  unsigned char  :0;
};
//SIG(1 Sf_C_BFu0c) C1{ FC2{} Fc Fc:0}



static void Test_Sf_C_BFu0c()
{
  {
    init_simple_test("Sf_C_BFu0c");
    static STRUCT_IF_C Sf_C_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(Sf_C_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_C_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu0c, Sf_C_BFu0c)
//============================================================================


struct  Sf_C_BFu0i  {
  struct empty v1;
  char v2;
  unsigned int  :0;
};
//SIG(1 Sf_C_BFu0i) C1{ FC2{} Fc Fi:0}



static void Test_Sf_C_BFu0i()
{
  {
    init_simple_test("Sf_C_BFu0i");
    static STRUCT_IF_C Sf_C_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_C_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_C_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu0i, Sf_C_BFu0i)
//============================================================================


struct  Sf_C_BFu0ll  {
  struct empty v1;
  char v2;
  __tsu64  :0;
};
//SIG(1 Sf_C_BFu0ll) C1{ FC2{} Fc FL:0}



static void Test_Sf_C_BFu0ll()
{
  {
    init_simple_test("Sf_C_BFu0ll");
    static STRUCT_IF_C Sf_C_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_C_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_C_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu0ll, Sf_C_BFu0ll)
//============================================================================


struct  Sf_C_BFu0s  {
  struct empty v1;
  char v2;
  unsigned short  :0;
};
//SIG(1 Sf_C_BFu0s) C1{ FC2{} Fc Fs:0}



static void Test_Sf_C_BFu0s()
{
  {
    init_simple_test("Sf_C_BFu0s");
    static STRUCT_IF_C Sf_C_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_C_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_C_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_C_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_C_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_C_BFu0s, Sf_C_BFu0s)
//============================================================================


struct  Sf_D_BFu0c  {
  struct empty v1;
  double v2;
  unsigned char  :0;
};
//SIG(1 Sf_D_BFu0c) C1{ FC2{} FL Fc:0}



static void Test_Sf_D_BFu0c()
{
  {
    init_simple_test("Sf_D_BFu0c");
    static STRUCT_IF_C Sf_D_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Sf_D_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_D_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu0c, Sf_D_BFu0c)
//============================================================================


struct  Sf_D_BFu0i  {
  struct empty v1;
  double v2;
  unsigned int  :0;
};
//SIG(1 Sf_D_BFu0i) C1{ FC2{} FL Fi:0}



static void Test_Sf_D_BFu0i()
{
  {
    init_simple_test("Sf_D_BFu0i");
    static STRUCT_IF_C Sf_D_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_D_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_D_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu0i, Sf_D_BFu0i)
//============================================================================


struct  Sf_D_BFu0ll  {
  struct empty v1;
  double v2;
  __tsu64  :0;
};
//SIG(1 Sf_D_BFu0ll) C1{ FC2{} FL FL:0}



static void Test_Sf_D_BFu0ll()
{
  {
    init_simple_test("Sf_D_BFu0ll");
    static STRUCT_IF_C Sf_D_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_D_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_D_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu0ll, Sf_D_BFu0ll)
//============================================================================


struct  Sf_D_BFu0s  {
  struct empty v1;
  double v2;
  unsigned short  :0;
};
//SIG(1 Sf_D_BFu0s) C1{ FC2{} FL Fs:0}



static void Test_Sf_D_BFu0s()
{
  {
    init_simple_test("Sf_D_BFu0s");
    static STRUCT_IF_C Sf_D_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Sf_D_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_D_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_D_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_D_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_D_BFu0s, Sf_D_BFu0s)
//============================================================================


struct  Sf_F_BFu0c  {
  struct empty v1;
  float v2;
  unsigned char  :0;
};
//SIG(1 Sf_F_BFu0c) C1{ FC2{} Fi Fc:0}



static void Test_Sf_F_BFu0c()
{
  {
    init_simple_test("Sf_F_BFu0c");
    static STRUCT_IF_C Sf_F_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Sf_F_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_F_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu0c, Sf_F_BFu0c)
//============================================================================


struct  Sf_F_BFu0i  {
  struct empty v1;
  float v2;
  unsigned int  :0;
};
//SIG(1 Sf_F_BFu0i) C1{ FC2{} Fi Fi:0}



static void Test_Sf_F_BFu0i()
{
  {
    init_simple_test("Sf_F_BFu0i");
    static STRUCT_IF_C Sf_F_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_F_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_F_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu0i, Sf_F_BFu0i)
//============================================================================


struct  Sf_F_BFu0ll  {
  struct empty v1;
  float v2;
  __tsu64  :0;
};
//SIG(1 Sf_F_BFu0ll) C1{ FC2{} Fi FL:0}



static void Test_Sf_F_BFu0ll()
{
  {
    init_simple_test("Sf_F_BFu0ll");
    static STRUCT_IF_C Sf_F_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_F_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_F_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu0ll, Sf_F_BFu0ll)
//============================================================================


struct  Sf_F_BFu0s  {
  struct empty v1;
  float v2;
  unsigned short  :0;
};
//SIG(1 Sf_F_BFu0s) C1{ FC2{} Fi Fs:0}



static void Test_Sf_F_BFu0s()
{
  {
    init_simple_test("Sf_F_BFu0s");
    static STRUCT_IF_C Sf_F_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_F_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_F_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_F_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_F_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_F_BFu0s, Sf_F_BFu0s)
//============================================================================


struct  Sf_I_BFu0c  {
  struct empty v1;
  int v2;
  unsigned char  :0;
};
//SIG(1 Sf_I_BFu0c) C1{ FC2{} Fi Fc:0}



static void Test_Sf_I_BFu0c()
{
  {
    init_simple_test("Sf_I_BFu0c");
    static STRUCT_IF_C Sf_I_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Sf_I_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_I_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu0c, Sf_I_BFu0c)
//============================================================================


struct  Sf_I_BFu0i  {
  struct empty v1;
  int v2;
  unsigned int  :0;
};
//SIG(1 Sf_I_BFu0i) C1{ FC2{} Fi Fi:0}



static void Test_Sf_I_BFu0i()
{
  {
    init_simple_test("Sf_I_BFu0i");
    static STRUCT_IF_C Sf_I_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_I_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_I_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu0i, Sf_I_BFu0i)
//============================================================================


struct  Sf_I_BFu0ll  {
  struct empty v1;
  int v2;
  __tsu64  :0;
};
//SIG(1 Sf_I_BFu0ll) C1{ FC2{} Fi FL:0}



static void Test_Sf_I_BFu0ll()
{
  {
    init_simple_test("Sf_I_BFu0ll");
    static STRUCT_IF_C Sf_I_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_I_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_I_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu0ll, Sf_I_BFu0ll)
//============================================================================


struct  Sf_I_BFu0s  {
  struct empty v1;
  int v2;
  unsigned short  :0;
};
//SIG(1 Sf_I_BFu0s) C1{ FC2{} Fi Fs:0}



static void Test_Sf_I_BFu0s()
{
  {
    init_simple_test("Sf_I_BFu0s");
    static STRUCT_IF_C Sf_I_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_I_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_I_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_I_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_I_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_I_BFu0s, Sf_I_BFu0s)
//============================================================================


struct  Sf_Ip_BFu0c  {
  struct empty v1;
  int *v2;
  unsigned char  :0;
};
//SIG(1 Sf_Ip_BFu0c) C1{ FC2{} Fp Fc:0}



static void Test_Sf_Ip_BFu0c()
{
  {
    init_simple_test("Sf_Ip_BFu0c");
    static STRUCT_IF_C Sf_Ip_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Ip_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Ip_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu0c, Sf_Ip_BFu0c)
//============================================================================


struct  Sf_Ip_BFu0i  {
  struct empty v1;
  int *v2;
  unsigned int  :0;
};
//SIG(1 Sf_Ip_BFu0i) C1{ FC2{} Fp Fi:0}



static void Test_Sf_Ip_BFu0i()
{
  {
    init_simple_test("Sf_Ip_BFu0i");
    static STRUCT_IF_C Sf_Ip_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Ip_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Ip_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu0i, Sf_Ip_BFu0i)
//============================================================================


struct  Sf_Ip_BFu0ll  {
  struct empty v1;
  int *v2;
  __tsu64  :0;
};
//SIG(1 Sf_Ip_BFu0ll) C1{ FC2{} Fp FL:0}



static void Test_Sf_Ip_BFu0ll()
{
  {
    init_simple_test("Sf_Ip_BFu0ll");
    static STRUCT_IF_C Sf_Ip_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Ip_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Ip_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu0ll, Sf_Ip_BFu0ll)
//============================================================================


struct  Sf_Ip_BFu0s  {
  struct empty v1;
  int *v2;
  unsigned short  :0;
};
//SIG(1 Sf_Ip_BFu0s) C1{ FC2{} Fp Fs:0}



static void Test_Sf_Ip_BFu0s()
{
  {
    init_simple_test("Sf_Ip_BFu0s");
    static STRUCT_IF_C Sf_Ip_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Ip_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Ip_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_Ip_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ip_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ip_BFu0s, Sf_Ip_BFu0s)
//============================================================================


struct  Sf_L_BFu0c  {
  struct empty v1;
  __tsi64 v2;
  unsigned char  :0;
};
//SIG(1 Sf_L_BFu0c) C1{ FC2{} FL Fc:0}



static void Test_Sf_L_BFu0c()
{
  {
    init_simple_test("Sf_L_BFu0c");
    static STRUCT_IF_C Sf_L_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Sf_L_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_L_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu0c, Sf_L_BFu0c)
//============================================================================


struct  Sf_L_BFu0i  {
  struct empty v1;
  __tsi64 v2;
  unsigned int  :0;
};
//SIG(1 Sf_L_BFu0i) C1{ FC2{} FL Fi:0}



static void Test_Sf_L_BFu0i()
{
  {
    init_simple_test("Sf_L_BFu0i");
    static STRUCT_IF_C Sf_L_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_L_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_L_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu0i, Sf_L_BFu0i)
//============================================================================


struct  Sf_L_BFu0ll  {
  struct empty v1;
  __tsi64 v2;
  __tsu64  :0;
};
//SIG(1 Sf_L_BFu0ll) C1{ FC2{} FL FL:0}



static void Test_Sf_L_BFu0ll()
{
  {
    init_simple_test("Sf_L_BFu0ll");
    static STRUCT_IF_C Sf_L_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_L_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_L_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu0ll, Sf_L_BFu0ll)
//============================================================================


struct  Sf_L_BFu0s  {
  struct empty v1;
  __tsi64 v2;
  unsigned short  :0;
};
//SIG(1 Sf_L_BFu0s) C1{ FC2{} FL Fs:0}



static void Test_Sf_L_BFu0s()
{
  {
    init_simple_test("Sf_L_BFu0s");
    static STRUCT_IF_C Sf_L_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Sf_L_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_L_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_L_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_L_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_L_BFu0s, Sf_L_BFu0s)
//============================================================================


struct  Sf_S_BFu0c  {
  struct empty v1;
  short v2;
  unsigned char  :0;
};
//SIG(1 Sf_S_BFu0c) C1{ FC2{} Fs Fc:0}



static void Test_Sf_S_BFu0c()
{
  {
    init_simple_test("Sf_S_BFu0c");
    static STRUCT_IF_C Sf_S_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_S_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_S_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu0c, Sf_S_BFu0c)
//============================================================================


struct  Sf_S_BFu0i  {
  struct empty v1;
  short v2;
  unsigned int  :0;
};
//SIG(1 Sf_S_BFu0i) C1{ FC2{} Fs Fi:0}



static void Test_Sf_S_BFu0i()
{
  {
    init_simple_test("Sf_S_BFu0i");
    static STRUCT_IF_C Sf_S_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_S_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_S_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu0i, Sf_S_BFu0i)
//============================================================================


struct  Sf_S_BFu0ll  {
  struct empty v1;
  short v2;
  __tsu64  :0;
};
//SIG(1 Sf_S_BFu0ll) C1{ FC2{} Fs FL:0}



static void Test_Sf_S_BFu0ll()
{
  {
    init_simple_test("Sf_S_BFu0ll");
    static STRUCT_IF_C Sf_S_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_S_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_S_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu0ll, Sf_S_BFu0ll)
//============================================================================


struct  Sf_S_BFu0s  {
  struct empty v1;
  short v2;
  unsigned short  :0;
};
//SIG(1 Sf_S_BFu0s) C1{ FC2{} Fs Fs:0}



static void Test_Sf_S_BFu0s()
{
  {
    init_simple_test("Sf_S_BFu0s");
    static STRUCT_IF_C Sf_S_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_S_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_S_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_S_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_S_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_S_BFu0s, Sf_S_BFu0s)
//============================================================================


struct  Sf_Sf_BFu0c  {
  struct empty v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 Sf_Sf_BFu0c) C1{ FC2{} FC2 Fc:0}



static void Test_Sf_Sf_BFu0c()
{
  {
    init_simple_test("Sf_Sf_BFu0c");
    static STRUCT_IF_C Sf_Sf_BFu0c lv;
    check2(sizeof(lv), 0, "sizeof(Sf_Sf_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu0c, Sf_Sf_BFu0c)
//============================================================================


struct  Sf_Sf_BFu0i  {
  struct empty v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 Sf_Sf_BFu0i) C1{ FC2{} FC2 Fi:0}



static void Test_Sf_Sf_BFu0i()
{
  {
    init_simple_test("Sf_Sf_BFu0i");
    static STRUCT_IF_C Sf_Sf_BFu0i lv;
    check2(sizeof(lv), 0, "sizeof(Sf_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu0i, Sf_Sf_BFu0i)
//============================================================================


struct  Sf_Sf_BFu0ll  {
  struct empty v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 Sf_Sf_BFu0ll) C1{ FC2{} FC2 FL:0}



static void Test_Sf_Sf_BFu0ll()
{
  {
    init_simple_test("Sf_Sf_BFu0ll");
    static STRUCT_IF_C Sf_Sf_BFu0ll lv;
    check2(sizeof(lv), 0, "sizeof(Sf_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu0ll, Sf_Sf_BFu0ll)
//============================================================================


struct  Sf_Sf_BFu0s  {
  struct empty v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 Sf_Sf_BFu0s) C1{ FC2{} FC2 Fs:0}



static void Test_Sf_Sf_BFu0s()
{
  {
    init_simple_test("Sf_Sf_BFu0s");
    static STRUCT_IF_C Sf_Sf_BFu0s lv;
    check2(sizeof(lv), 0, "sizeof(Sf_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_Sf_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Sf_BFu0s, Sf_Sf_BFu0s)
//============================================================================


struct  Sf_Uc_BFu0c  {
  struct empty v1;
  unsigned char v2;
  unsigned char  :0;
};
//SIG(1 Sf_Uc_BFu0c) C1{ FC2{} Fc Fc:0}



static void Test_Sf_Uc_BFu0c()
{
  {
    init_simple_test("Sf_Uc_BFu0c");
    static STRUCT_IF_C Sf_Uc_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(Sf_Uc_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Sf_Uc_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu0c, Sf_Uc_BFu0c)
//============================================================================


struct  Sf_Uc_BFu0i  {
  struct empty v1;
  unsigned char v2;
  unsigned int  :0;
};
//SIG(1 Sf_Uc_BFu0i) C1{ FC2{} Fc Fi:0}



static void Test_Sf_Uc_BFu0i()
{
  {
    init_simple_test("Sf_Uc_BFu0i");
    static STRUCT_IF_C Sf_Uc_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Uc_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_Uc_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu0i, Sf_Uc_BFu0i)
//============================================================================


struct  Sf_Uc_BFu0ll  {
  struct empty v1;
  unsigned char v2;
  __tsu64  :0;
};
//SIG(1 Sf_Uc_BFu0ll) C1{ FC2{} Fc FL:0}



static void Test_Sf_Uc_BFu0ll()
{
  {
    init_simple_test("Sf_Uc_BFu0ll");
    static STRUCT_IF_C Sf_Uc_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Uc_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_Uc_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu0ll, Sf_Uc_BFu0ll)
//============================================================================


struct  Sf_Uc_BFu0s  {
  struct empty v1;
  unsigned char v2;
  unsigned short  :0;
};
//SIG(1 Sf_Uc_BFu0s) C1{ FC2{} Fc Fs:0}



static void Test_Sf_Uc_BFu0s()
{
  {
    init_simple_test("Sf_Uc_BFu0s");
    static STRUCT_IF_C Sf_Uc_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Uc_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Sf_Uc_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_Uc_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_Uc_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Uc_BFu0s, Sf_Uc_BFu0s)
//============================================================================


struct  Sf_Ui_BFu0c  {
  struct empty v1;
  unsigned int v2;
  unsigned char  :0;
};
//SIG(1 Sf_Ui_BFu0c) C1{ FC2{} Fi Fc:0}



static void Test_Sf_Ui_BFu0c()
{
  {
    init_simple_test("Sf_Ui_BFu0c");
    static STRUCT_IF_C Sf_Ui_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Ui_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_Ui_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu0c, Sf_Ui_BFu0c)
//============================================================================


struct  Sf_Ui_BFu0i  {
  struct empty v1;
  unsigned int v2;
  unsigned int  :0;
};
//SIG(1 Sf_Ui_BFu0i) C1{ FC2{} Fi Fi:0}



static void Test_Sf_Ui_BFu0i()
{
  {
    init_simple_test("Sf_Ui_BFu0i");
    static STRUCT_IF_C Sf_Ui_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Ui_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_Ui_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu0i, Sf_Ui_BFu0i)
//============================================================================


struct  Sf_Ui_BFu0ll  {
  struct empty v1;
  unsigned int v2;
  __tsu64  :0;
};
//SIG(1 Sf_Ui_BFu0ll) C1{ FC2{} Fi FL:0}



static void Test_Sf_Ui_BFu0ll()
{
  {
    init_simple_test("Sf_Ui_BFu0ll");
    static STRUCT_IF_C Sf_Ui_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Ui_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Sf_Ui_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu0ll, Sf_Ui_BFu0ll)
//============================================================================


struct  Sf_Ui_BFu0s  {
  struct empty v1;
  unsigned int v2;
  unsigned short  :0;
};
//SIG(1 Sf_Ui_BFu0s) C1{ FC2{} Fi Fs:0}



static void Test_Sf_Ui_BFu0s()
{
  {
    init_simple_test("Sf_Ui_BFu0s");
    static STRUCT_IF_C Sf_Ui_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Ui_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Sf_Ui_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_Ui_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ui_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ui_BFu0s, Sf_Ui_BFu0s)
//============================================================================


struct  Sf_Ul_BFu0c  {
  struct empty v1;
  __tsu64 v2;
  unsigned char  :0;
};
//SIG(1 Sf_Ul_BFu0c) C1{ FC2{} FL Fc:0}



static void Test_Sf_Ul_BFu0c()
{
  {
    init_simple_test("Sf_Ul_BFu0c");
    static STRUCT_IF_C Sf_Ul_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ul_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Ul_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu0c, Sf_Ul_BFu0c)
//============================================================================


struct  Sf_Ul_BFu0i  {
  struct empty v1;
  __tsu64 v2;
  unsigned int  :0;
};
//SIG(1 Sf_Ul_BFu0i) C1{ FC2{} FL Fi:0}



static void Test_Sf_Ul_BFu0i()
{
  {
    init_simple_test("Sf_Ul_BFu0i");
    static STRUCT_IF_C Sf_Ul_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ul_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Ul_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu0i, Sf_Ul_BFu0i)
//============================================================================


struct  Sf_Ul_BFu0ll  {
  struct empty v1;
  __tsu64 v2;
  __tsu64  :0;
};
//SIG(1 Sf_Ul_BFu0ll) C1{ FC2{} FL FL:0}



static void Test_Sf_Ul_BFu0ll()
{
  {
    init_simple_test("Sf_Ul_BFu0ll");
    static STRUCT_IF_C Sf_Ul_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ul_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Ul_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu0ll, Sf_Ul_BFu0ll)
//============================================================================


struct  Sf_Ul_BFu0s  {
  struct empty v1;
  __tsu64 v2;
  unsigned short  :0;
};
//SIG(1 Sf_Ul_BFu0s) C1{ FC2{} FL Fs:0}



static void Test_Sf_Ul_BFu0s()
{
  {
    init_simple_test("Sf_Ul_BFu0s");
    static STRUCT_IF_C Sf_Ul_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Sf_Ul_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Ul_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_Ul_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_Ul_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Ul_BFu0s, Sf_Ul_BFu0s)
//============================================================================


struct  Sf_Us_BFu0c  {
  struct empty v1;
  unsigned short v2;
  unsigned char  :0;
};
//SIG(1 Sf_Us_BFu0c) C1{ FC2{} Fs Fc:0}



static void Test_Sf_Us_BFu0c()
{
  {
    init_simple_test("Sf_Us_BFu0c");
    static STRUCT_IF_C Sf_Us_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Us_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_Us_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu0c, Sf_Us_BFu0c)
//============================================================================


struct  Sf_Us_BFu0i  {
  struct empty v1;
  unsigned short v2;
  unsigned int  :0;
};
//SIG(1 Sf_Us_BFu0i) C1{ FC2{} Fs Fi:0}



static void Test_Sf_Us_BFu0i()
{
  {
    init_simple_test("Sf_Us_BFu0i");
    static STRUCT_IF_C Sf_Us_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Sf_Us_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_Us_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu0i, Sf_Us_BFu0i)
//============================================================================


struct  Sf_Us_BFu0ll  {
  struct empty v1;
  unsigned short v2;
  __tsu64  :0;
};
//SIG(1 Sf_Us_BFu0ll) C1{ FC2{} Fs FL:0}



static void Test_Sf_Us_BFu0ll()
{
  {
    init_simple_test("Sf_Us_BFu0ll");
    static STRUCT_IF_C Sf_Us_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Us_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Sf_Us_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu0ll, Sf_Us_BFu0ll)
//============================================================================


struct  Sf_Us_BFu0s  {
  struct empty v1;
  unsigned short v2;
  unsigned short  :0;
};
//SIG(1 Sf_Us_BFu0s) C1{ FC2{} Fs Fs:0}



static void Test_Sf_Us_BFu0s()
{
  {
    init_simple_test("Sf_Us_BFu0s");
    static STRUCT_IF_C Sf_Us_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Sf_Us_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(Sf_Us_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_Us_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_Us_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Us_BFu0s, Sf_Us_BFu0s)
//============================================================================


struct  Sf_Vp_BFu0c  {
  struct empty v1;
  void *v2;
  unsigned char  :0;
};
//SIG(1 Sf_Vp_BFu0c) C1{ FC2{} Fp Fc:0}



static void Test_Sf_Vp_BFu0c()
{
  {
    init_simple_test("Sf_Vp_BFu0c");
    static STRUCT_IF_C Sf_Vp_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Vp_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Vp_BFu0c)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu0c.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu0c, Sf_Vp_BFu0c)
//============================================================================


struct  Sf_Vp_BFu0i  {
  struct empty v1;
  void *v2;
  unsigned int  :0;
};
//SIG(1 Sf_Vp_BFu0i) C1{ FC2{} Fp Fi:0}



static void Test_Sf_Vp_BFu0i()
{
  {
    init_simple_test("Sf_Vp_BFu0i");
    static STRUCT_IF_C Sf_Vp_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Vp_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Vp_BFu0i)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu0i.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu0i, Sf_Vp_BFu0i)
//============================================================================


struct  Sf_Vp_BFu0ll  {
  struct empty v1;
  void *v2;
  __tsu64  :0;
};
//SIG(1 Sf_Vp_BFu0ll) C1{ FC2{} Fp FL:0}



static void Test_Sf_Vp_BFu0ll()
{
  {
    init_simple_test("Sf_Vp_BFu0ll");
    static STRUCT_IF_C Sf_Vp_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Vp_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Vp_BFu0ll)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu0ll.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu0ll, Sf_Vp_BFu0ll)
//============================================================================


struct  Sf_Vp_BFu0s  {
  struct empty v1;
  void *v2;
  unsigned short  :0;
};
//SIG(1 Sf_Vp_BFu0s) C1{ FC2{} Fp Fs:0}



static void Test_Sf_Vp_BFu0s()
{
  {
    init_simple_test("Sf_Vp_BFu0s");
    static STRUCT_IF_C Sf_Vp_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Sf_Vp_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Sf_Vp_BFu0s)");
    check_field_offset(lv, v1, 0, "Sf_Vp_BFu0s.v1");
    check_field_offset(lv, v2, 0, "Sf_Vp_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Sf_Vp_BFu0s, Sf_Vp_BFu0s)
//============================================================================


struct  Uc_BFu0c_Sf  {
  unsigned char v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 Uc_BFu0c_Sf) C1{ Fc Fc:0 FC2{}}



static void Test_Uc_BFu0c_Sf()
{
  {
    init_simple_test("Uc_BFu0c_Sf");
    static STRUCT_IF_C Uc_BFu0c_Sf lv;
    check2(sizeof(lv), 1, "sizeof(Uc_BFu0c_Sf)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu0c_Sf.v1");
    check_field_offset(lv, v2, 1, "Uc_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu0c_Sf, Uc_BFu0c_Sf)
//============================================================================


struct  Uc_BFu0i_Sf  {
  unsigned char v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 Uc_BFu0i_Sf) C1{ Fc Fi:0 FC2{}}



static void Test_Uc_BFu0i_Sf()
{
  {
    init_simple_test("Uc_BFu0i_Sf");
    static STRUCT_IF_C Uc_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Uc_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Uc_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu0i_Sf.v1");
    check_field_offset(lv, v2, 4, "Uc_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu0i_Sf, Uc_BFu0i_Sf)
//============================================================================


struct  Uc_BFu0ll_Sf  {
  unsigned char v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 Uc_BFu0ll_Sf) C1{ Fc FL:0 FC2{}}



static void Test_Uc_BFu0ll_Sf()
{
  {
    init_simple_test("Uc_BFu0ll_Sf");
    static STRUCT_IF_C Uc_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Uc_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Uc_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Uc_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu0ll_Sf, Uc_BFu0ll_Sf)
//============================================================================


struct  Uc_BFu0s_Sf  {
  unsigned char v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 Uc_BFu0s_Sf) C1{ Fc Fs:0 FC2{}}



static void Test_Uc_BFu0s_Sf()
{
  {
    init_simple_test("Uc_BFu0s_Sf");
    static STRUCT_IF_C Uc_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Uc_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Uc_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "Uc_BFu0s_Sf.v1");
    check_field_offset(lv, v2, 2, "Uc_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_BFu0s_Sf, Uc_BFu0s_Sf)
//============================================================================


struct  Uc_Sf_BFu0c  {
  unsigned char v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 Uc_Sf_BFu0c) C1{ Fc FC2{} Fc:0}



static void Test_Uc_Sf_BFu0c()
{
  {
    init_simple_test("Uc_Sf_BFu0c");
    static STRUCT_IF_C Uc_Sf_BFu0c lv;
    check2(sizeof(lv), 1, "sizeof(Uc_Sf_BFu0c)");
    check2(__alignof__(lv), 1, "__alignof__(Uc_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu0c.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu0c, Uc_Sf_BFu0c)
//============================================================================


struct  Uc_Sf_BFu0i  {
  unsigned char v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 Uc_Sf_BFu0i) C1{ Fc FC2{} Fi:0}



static void Test_Uc_Sf_BFu0i()
{
  {
    init_simple_test("Uc_Sf_BFu0i");
    static STRUCT_IF_C Uc_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Uc_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Uc_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu0i.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu0i, Uc_Sf_BFu0i)
//============================================================================


struct  Uc_Sf_BFu0ll  {
  unsigned char v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 Uc_Sf_BFu0ll) C1{ Fc FC2{} FL:0}



static void Test_Uc_Sf_BFu0ll()
{
  {
    init_simple_test("Uc_Sf_BFu0ll");
    static STRUCT_IF_C Uc_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Uc_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Uc_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu0ll, Uc_Sf_BFu0ll)
//============================================================================


struct  Uc_Sf_BFu0s  {
  unsigned char v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 Uc_Sf_BFu0s) C1{ Fc FC2{} Fs:0}



static void Test_Uc_Sf_BFu0s()
{
  {
    init_simple_test("Uc_Sf_BFu0s");
    static STRUCT_IF_C Uc_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Uc_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(Uc_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "Uc_Sf_BFu0s.v1");
    check_field_offset(lv, v2, 1, "Uc_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Uc_Sf_BFu0s, Uc_Sf_BFu0s)
//============================================================================


struct  Ui_BFu0c_Sf  {
  unsigned int v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 Ui_BFu0c_Sf) C1{ Fi Fc:0 FC2{}}



static void Test_Ui_BFu0c_Sf()
{
  {
    init_simple_test("Ui_BFu0c_Sf");
    static STRUCT_IF_C Ui_BFu0c_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Ui_BFu0c_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu0c_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0c_Sf, Ui_BFu0c_Sf)
//============================================================================


struct  Ui_BFu0i_Sf  {
  unsigned int v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 Ui_BFu0i_Sf) C1{ Fi Fi:0 FC2{}}



static void Test_Ui_BFu0i_Sf()
{
  {
    init_simple_test("Ui_BFu0i_Sf");
    static STRUCT_IF_C Ui_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Ui_BFu0i_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu0i_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0i_Sf, Ui_BFu0i_Sf)
//============================================================================


struct  Ui_BFu0ll_Sf  {
  unsigned int v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 Ui_BFu0ll_Sf) C1{ Fi FL:0 FC2{}}



static void Test_Ui_BFu0ll_Sf()
{
  {
    init_simple_test("Ui_BFu0ll_Sf");
    static STRUCT_IF_C Ui_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Ui_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Ui_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Ui_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0ll_Sf, Ui_BFu0ll_Sf)
//============================================================================


struct  Ui_BFu0s_Sf  {
  unsigned int v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 Ui_BFu0s_Sf) C1{ Fi Fs:0 FC2{}}



static void Test_Ui_BFu0s_Sf()
{
  {
    init_simple_test("Ui_BFu0s_Sf");
    static STRUCT_IF_C Ui_BFu0s_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Ui_BFu0s_Sf)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "Ui_BFu0s_Sf.v1");
    check_field_offset(lv, v2, 4, "Ui_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_BFu0s_Sf, Ui_BFu0s_Sf)
//============================================================================


struct  Ui_Sf_BFu0c  {
  unsigned int v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 Ui_Sf_BFu0c) C1{ Fi FC2{} Fc:0}



static void Test_Ui_Sf_BFu0c()
{
  {
    init_simple_test("Ui_Sf_BFu0c");
    static STRUCT_IF_C Ui_Sf_BFu0c lv;
    check2(sizeof(lv), 4, "sizeof(Ui_Sf_BFu0c)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu0c.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu0c, Ui_Sf_BFu0c)
//============================================================================


struct  Ui_Sf_BFu0i  {
  unsigned int v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 Ui_Sf_BFu0i) C1{ Fi FC2{} Fi:0}



static void Test_Ui_Sf_BFu0i()
{
  {
    init_simple_test("Ui_Sf_BFu0i");
    static STRUCT_IF_C Ui_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Ui_Sf_BFu0i)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu0i.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu0i, Ui_Sf_BFu0i)
//============================================================================


struct  Ui_Sf_BFu0ll  {
  unsigned int v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 Ui_Sf_BFu0ll) C1{ Fi FC2{} FL:0}



static void Test_Ui_Sf_BFu0ll()
{
  {
    init_simple_test("Ui_Sf_BFu0ll");
    static STRUCT_IF_C Ui_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Ui_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(4,4), "__alignof__(Ui_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu0ll, Ui_Sf_BFu0ll)
//============================================================================


struct  Ui_Sf_BFu0s  {
  unsigned int v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 Ui_Sf_BFu0s) C1{ Fi FC2{} Fs:0}



static void Test_Ui_Sf_BFu0s()
{
  {
    init_simple_test("Ui_Sf_BFu0s");
    static STRUCT_IF_C Ui_Sf_BFu0s lv;
    check2(sizeof(lv), 4, "sizeof(Ui_Sf_BFu0s)");
    check2(__alignof__(lv), 4, "__alignof__(Ui_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "Ui_Sf_BFu0s.v1");
    check_field_offset(lv, v2, 4, "Ui_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ui_Sf_BFu0s, Ui_Sf_BFu0s)
//============================================================================


struct  Ul_BFu0c_Sf  {
  __tsu64 v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 Ul_BFu0c_Sf) C1{ FL Fc:0 FC2{}}



static void Test_Ul_BFu0c_Sf()
{
  {
    init_simple_test("Ul_BFu0c_Sf");
    static STRUCT_IF_C Ul_BFu0c_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu0c_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0c_Sf, Ul_BFu0c_Sf)
//============================================================================


struct  Ul_BFu0i_Sf  {
  __tsu64 v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 Ul_BFu0i_Sf) C1{ FL Fi:0 FC2{}}



static void Test_Ul_BFu0i_Sf()
{
  {
    init_simple_test("Ul_BFu0i_Sf");
    static STRUCT_IF_C Ul_BFu0i_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu0i_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0i_Sf, Ul_BFu0i_Sf)
//============================================================================


struct  Ul_BFu0ll_Sf  {
  __tsu64 v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 Ul_BFu0ll_Sf) C1{ FL FL:0 FC2{}}



static void Test_Ul_BFu0ll_Sf()
{
  {
    init_simple_test("Ul_BFu0ll_Sf");
    static STRUCT_IF_C Ul_BFu0ll_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0ll_Sf, Ul_BFu0ll_Sf)
//============================================================================


struct  Ul_BFu0s_Sf  {
  __tsu64 v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 Ul_BFu0s_Sf) C1{ FL Fs:0 FC2{}}



static void Test_Ul_BFu0s_Sf()
{
  {
    init_simple_test("Ul_BFu0s_Sf");
    static STRUCT_IF_C Ul_BFu0s_Sf lv;
    check2(sizeof(lv), 8, "sizeof(Ul_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "Ul_BFu0s_Sf.v1");
    check_field_offset(lv, v2, 8, "Ul_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_BFu0s_Sf, Ul_BFu0s_Sf)
//============================================================================


struct  Ul_Sf_BFu0c  {
  __tsu64 v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 Ul_Sf_BFu0c) C1{ FL FC2{} Fc:0}



static void Test_Ul_Sf_BFu0c()
{
  {
    init_simple_test("Ul_Sf_BFu0c");
    static STRUCT_IF_C Ul_Sf_BFu0c lv;
    check2(sizeof(lv), 8, "sizeof(Ul_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu0c.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu0c, Ul_Sf_BFu0c)
//============================================================================


struct  Ul_Sf_BFu0i  {
  __tsu64 v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 Ul_Sf_BFu0i) C1{ FL FC2{} Fi:0}



static void Test_Ul_Sf_BFu0i()
{
  {
    init_simple_test("Ul_Sf_BFu0i");
    static STRUCT_IF_C Ul_Sf_BFu0i lv;
    check2(sizeof(lv), 8, "sizeof(Ul_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu0i.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu0i, Ul_Sf_BFu0i)
//============================================================================


struct  Ul_Sf_BFu0ll  {
  __tsu64 v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 Ul_Sf_BFu0ll) C1{ FL FC2{} FL:0}



static void Test_Ul_Sf_BFu0ll()
{
  {
    init_simple_test("Ul_Sf_BFu0ll");
    static STRUCT_IF_C Ul_Sf_BFu0ll lv;
    check2(sizeof(lv), 8, "sizeof(Ul_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu0ll, Ul_Sf_BFu0ll)
//============================================================================


struct  Ul_Sf_BFu0s  {
  __tsu64 v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 Ul_Sf_BFu0s) C1{ FL FC2{} Fs:0}



static void Test_Ul_Sf_BFu0s()
{
  {
    init_simple_test("Ul_Sf_BFu0s");
    static STRUCT_IF_C Ul_Sf_BFu0s lv;
    check2(sizeof(lv), 8, "sizeof(Ul_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Ul_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "Ul_Sf_BFu0s.v1");
    check_field_offset(lv, v2, 8, "Ul_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Ul_Sf_BFu0s, Ul_Sf_BFu0s)
//============================================================================


struct  Us_BFu0c_Sf  {
  unsigned short v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 Us_BFu0c_Sf) C1{ Fs Fc:0 FC2{}}



static void Test_Us_BFu0c_Sf()
{
  {
    init_simple_test("Us_BFu0c_Sf");
    static STRUCT_IF_C Us_BFu0c_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0c_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(Us_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu0c_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0c_Sf, Us_BFu0c_Sf)
//============================================================================


struct  Us_BFu0i_Sf  {
  unsigned short v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 Us_BFu0i_Sf) C1{ Fs Fi:0 FC2{}}



static void Test_Us_BFu0i_Sf()
{
  {
    init_simple_test("Us_BFu0i_Sf");
    static STRUCT_IF_C Us_BFu0i_Sf lv;
    check2(sizeof(lv), 4, "sizeof(Us_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Us_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu0i_Sf.v1");
    check_field_offset(lv, v2, 4, "Us_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0i_Sf, Us_BFu0i_Sf)
//============================================================================


struct  Us_BFu0ll_Sf  {
  unsigned short v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 Us_BFu0ll_Sf) C1{ Fs FL:0 FC2{}}



static void Test_Us_BFu0ll_Sf()
{
  {
    init_simple_test("Us_BFu0ll_Sf");
    static STRUCT_IF_C Us_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Us_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Us_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0ll_Sf, Us_BFu0ll_Sf)
//============================================================================


struct  Us_BFu0s_Sf  {
  unsigned short v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 Us_BFu0s_Sf) C1{ Fs Fs:0 FC2{}}



static void Test_Us_BFu0s_Sf()
{
  {
    init_simple_test("Us_BFu0s_Sf");
    static STRUCT_IF_C Us_BFu0s_Sf lv;
    check2(sizeof(lv), 2, "sizeof(Us_BFu0s_Sf)");
    check2(__alignof__(lv), 2, "__alignof__(Us_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "Us_BFu0s_Sf.v1");
    check_field_offset(lv, v2, 2, "Us_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_BFu0s_Sf, Us_BFu0s_Sf)
//============================================================================


struct  Us_Sf_BFu0c  {
  unsigned short v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 Us_Sf_BFu0c) C1{ Fs FC2{} Fc:0}



static void Test_Us_Sf_BFu0c()
{
  {
    init_simple_test("Us_Sf_BFu0c");
    static STRUCT_IF_C Us_Sf_BFu0c lv;
    check2(sizeof(lv), 2, "sizeof(Us_Sf_BFu0c)");
    check2(__alignof__(lv), 2, "__alignof__(Us_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu0c.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu0c, Us_Sf_BFu0c)
//============================================================================


struct  Us_Sf_BFu0i  {
  unsigned short v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 Us_Sf_BFu0i) C1{ Fs FC2{} Fi:0}



static void Test_Us_Sf_BFu0i()
{
  {
    init_simple_test("Us_Sf_BFu0i");
    static STRUCT_IF_C Us_Sf_BFu0i lv;
    check2(sizeof(lv), 4, "sizeof(Us_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Us_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu0i.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu0i, Us_Sf_BFu0i)
//============================================================================


struct  Us_Sf_BFu0ll  {
  unsigned short v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 Us_Sf_BFu0ll) C1{ Fs FC2{} FL:0}



static void Test_Us_Sf_BFu0ll()
{
  {
    init_simple_test("Us_Sf_BFu0ll");
    static STRUCT_IF_C Us_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Us_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(2,2), "__alignof__(Us_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu0ll, Us_Sf_BFu0ll)
//============================================================================


struct  Us_Sf_BFu0s  {
  unsigned short v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 Us_Sf_BFu0s) C1{ Fs FC2{} Fs:0}



static void Test_Us_Sf_BFu0s()
{
  {
    init_simple_test("Us_Sf_BFu0s");
    static STRUCT_IF_C Us_Sf_BFu0s lv;
    check2(sizeof(lv), 2, "sizeof(Us_Sf_BFu0s)");
    check2(__alignof__(lv), 2, "__alignof__(Us_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "Us_Sf_BFu0s.v1");
    check_field_offset(lv, v2, 2, "Us_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Us_Sf_BFu0s, Us_Sf_BFu0s)
//============================================================================


struct  Vp_BFu0c_Sf  {
  void *v1;
  unsigned char  :0;
  struct empty v2;
};
//SIG(1 Vp_BFu0c_Sf) C1{ Fp Fc:0 FC2{}}



static void Test_Vp_BFu0c_Sf()
{
  {
    init_simple_test("Vp_BFu0c_Sf");
    static STRUCT_IF_C Vp_BFu0c_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0c_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu0c_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu0c_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0c_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0c_Sf, Vp_BFu0c_Sf)
//============================================================================


struct  Vp_BFu0i_Sf  {
  void *v1;
  unsigned int  :0;
  struct empty v2;
};
//SIG(1 Vp_BFu0i_Sf) C1{ Fp Fi:0 FC2{}}



static void Test_Vp_BFu0i_Sf()
{
  {
    init_simple_test("Vp_BFu0i_Sf");
    static STRUCT_IF_C Vp_BFu0i_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0i_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu0i_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu0i_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0i_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0i_Sf, Vp_BFu0i_Sf)
//============================================================================


struct  Vp_BFu0ll_Sf  {
  void *v1;
  __tsu64  :0;
  struct empty v2;
};
//SIG(1 Vp_BFu0ll_Sf) C1{ Fp FL:0 FC2{}}



static void Test_Vp_BFu0ll_Sf()
{
  {
    init_simple_test("Vp_BFu0ll_Sf");
    static STRUCT_IF_C Vp_BFu0ll_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0ll_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu0ll_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu0ll_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0ll_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0ll_Sf, Vp_BFu0ll_Sf)
//============================================================================


struct  Vp_BFu0s_Sf  {
  void *v1;
  unsigned short  :0;
  struct empty v2;
};
//SIG(1 Vp_BFu0s_Sf) C1{ Fp Fs:0 FC2{}}



static void Test_Vp_BFu0s_Sf()
{
  {
    init_simple_test("Vp_BFu0s_Sf");
    static STRUCT_IF_C Vp_BFu0s_Sf lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_BFu0s_Sf)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu0s_Sf)");
    check_field_offset(lv, v1, 0, "Vp_BFu0s_Sf.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_BFu0s_Sf.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu0s_Sf, Vp_BFu0s_Sf)
//============================================================================


struct  Vp_Sf_BFu0c  {
  void *v1;
  struct empty v2;
  unsigned char  :0;
};
//SIG(1 Vp_Sf_BFu0c) C1{ Fp FC2{} Fc:0}



static void Test_Vp_Sf_BFu0c()
{
  {
    init_simple_test("Vp_Sf_BFu0c");
    static STRUCT_IF_C Vp_Sf_BFu0c lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_Sf_BFu0c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Sf_BFu0c)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu0c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu0c.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu0c, Vp_Sf_BFu0c)
//============================================================================


struct  Vp_Sf_BFu0i  {
  void *v1;
  struct empty v2;
  unsigned int  :0;
};
//SIG(1 Vp_Sf_BFu0i) C1{ Fp FC2{} Fi:0}



static void Test_Vp_Sf_BFu0i()
{
  {
    init_simple_test("Vp_Sf_BFu0i");
    static STRUCT_IF_C Vp_Sf_BFu0i lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_Sf_BFu0i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Sf_BFu0i)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu0i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu0i.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu0i, Vp_Sf_BFu0i)
//============================================================================


struct  Vp_Sf_BFu0ll  {
  void *v1;
  struct empty v2;
  __tsu64  :0;
};
//SIG(1 Vp_Sf_BFu0ll) C1{ Fp FC2{} FL:0}



static void Test_Vp_Sf_BFu0ll()
{
  {
    init_simple_test("Vp_Sf_BFu0ll");
    static STRUCT_IF_C Vp_Sf_BFu0ll lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_Sf_BFu0ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Sf_BFu0ll)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu0ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu0ll.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu0ll, Vp_Sf_BFu0ll)
//============================================================================


struct  Vp_Sf_BFu0s  {
  void *v1;
  struct empty v2;
  unsigned short  :0;
};
//SIG(1 Vp_Sf_BFu0s) C1{ Fp FC2{} Fs:0}



static void Test_Vp_Sf_BFu0s()
{
  {
    init_simple_test("Vp_Sf_BFu0s");
    static STRUCT_IF_C Vp_Sf_BFu0s lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Vp_Sf_BFu0s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Sf_BFu0s)");
    check_field_offset(lv, v1, 0, "Vp_Sf_BFu0s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Sf_BFu0s.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Sf_BFu0s, Vp_Sf_BFu0s)
//============================================================================

