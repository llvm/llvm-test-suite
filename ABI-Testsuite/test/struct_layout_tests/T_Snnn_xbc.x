// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: c_compiler -c %s -I "common" -o %t2.o
// RUN: linker -o %t1%exeext  %t1.o %t2.o
// RUN: runtool %t1%exeext | checker "TEST PASSED"
// RUN: cxx_compiler cxx_rtti -c %s -I "common" -o %t2.o
// RUN: linker -o %t2%exeext  %t1.o %t2.o
// RUN: runtool %t2%exeext | checker "TEST PASSED"
#include "testsuite.h"

struct  Vp_BFu32ll_BFu7i  {
  void *v1;
  __tsu64 v2:32;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu32ll_BFu7i) C1{ Fp FL:32 Fi:7}



static void Test_Vp_BFu32ll_BFu7i()
{
  {
    init_simple_test("Vp_BFu32ll_BFu7i");
    static STRUCT_IF_C Vp_BFu32ll_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_BFu32ll_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_BFu32ll_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu7i, Vp_BFu32ll_BFu7i)
//============================================================================


struct  Vp_BFu32ll_BFu7ll  {
  void *v1;
  __tsu64 v2:32;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu32ll_BFu7ll) C1{ Fp FL:32 FL:7}



static void Test_Vp_BFu32ll_BFu7ll()
{
  {
    init_simple_test("Vp_BFu32ll_BFu7ll");
    static STRUCT_IF_C Vp_BFu32ll_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_BFu32ll_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_BFu32ll_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu7ll, Vp_BFu32ll_BFu7ll)
//============================================================================


struct  Vp_BFu32ll_BFu7s  {
  void *v1;
  __tsu64 v2:32;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu32ll_BFu7s) C1{ Fp FL:32 Fs:7}



static void Test_Vp_BFu32ll_BFu7s()
{
  {
    init_simple_test("Vp_BFu32ll_BFu7s");
    static STRUCT_IF_C Vp_BFu32ll_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_BFu32ll_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_BFu32ll_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu7s, Vp_BFu32ll_BFu7s)
//============================================================================


struct  Vp_BFu32ll_BFu8c  {
  void *v1;
  __tsu64 v2:32;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu32ll_BFu8c) C1{ Fp FL:32 Fc:8}



static void Test_Vp_BFu32ll_BFu8c()
{
  {
    init_simple_test("Vp_BFu32ll_BFu8c");
    static STRUCT_IF_C Vp_BFu32ll_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_BFu32ll_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_BFu32ll_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu8c, Vp_BFu32ll_BFu8c)
//============================================================================


struct  Vp_BFu32ll_BFu8i  {
  void *v1;
  __tsu64 v2:32;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu32ll_BFu8i) C1{ Fp FL:32 Fi:8}



static void Test_Vp_BFu32ll_BFu8i()
{
  {
    init_simple_test("Vp_BFu32ll_BFu8i");
    static STRUCT_IF_C Vp_BFu32ll_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_BFu32ll_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_BFu32ll_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu8i, Vp_BFu32ll_BFu8i)
//============================================================================


struct  Vp_BFu32ll_BFu8ll  {
  void *v1;
  __tsu64 v2:32;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu32ll_BFu8ll) C1{ Fp FL:32 FL:8}



static void Test_Vp_BFu32ll_BFu8ll()
{
  {
    init_simple_test("Vp_BFu32ll_BFu8ll");
    static STRUCT_IF_C Vp_BFu32ll_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_BFu32ll_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_BFu32ll_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu8ll, Vp_BFu32ll_BFu8ll)
//============================================================================


struct  Vp_BFu32ll_BFu8s  {
  void *v1;
  __tsu64 v2:32;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu32ll_BFu8s) C1{ Fp FL:32 Fs:8}



static void Test_Vp_BFu32ll_BFu8s()
{
  {
    init_simple_test("Vp_BFu32ll_BFu8s");
    static STRUCT_IF_C Vp_BFu32ll_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_BFu32ll_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_BFu32ll_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu8s, Vp_BFu32ll_BFu8s)
//============================================================================


struct  Vp_BFu32ll_BFu9i  {
  void *v1;
  __tsu64 v2:32;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu32ll_BFu9i) C1{ Fp FL:32 Fi:9}



static void Test_Vp_BFu32ll_BFu9i()
{
  {
    init_simple_test("Vp_BFu32ll_BFu9i");
    static STRUCT_IF_C Vp_BFu32ll_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, 1, "Vp_BFu32ll_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, hide_ull(1LL<<8), "Vp_BFu32ll_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu9i, Vp_BFu32ll_BFu9i)
//============================================================================


struct  Vp_BFu32ll_BFu9ll  {
  void *v1;
  __tsu64 v2:32;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu32ll_BFu9ll) C1{ Fp FL:32 FL:9}



static void Test_Vp_BFu32ll_BFu9ll()
{
  {
    init_simple_test("Vp_BFu32ll_BFu9ll");
    static STRUCT_IF_C Vp_BFu32ll_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, 1, "Vp_BFu32ll_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, hide_ull(1LL<<8), "Vp_BFu32ll_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu9ll, Vp_BFu32ll_BFu9ll)
//============================================================================


struct  Vp_BFu32ll_BFu9s  {
  void *v1;
  __tsu64 v2:32;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu32ll_BFu9s) C1{ Fp FL:32 Fs:9}



static void Test_Vp_BFu32ll_BFu9s()
{
  {
    init_simple_test("Vp_BFu32ll_BFu9s");
    static STRUCT_IF_C Vp_BFu32ll_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, 1, "Vp_BFu32ll_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, hide_ull(1LL<<8), "Vp_BFu32ll_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_BFu9s, Vp_BFu32ll_BFu9s)
//============================================================================


struct  Vp_BFu32ll_C  {
  void *v1;
  __tsu64 v2:32;
  char v3;
};
//SIG(1 Vp_BFu32ll_C) C1{ Fp FL:32 Fc}



static void Test_Vp_BFu32ll_C()
{
  {
    init_simple_test("Vp_BFu32ll_C");
    static STRUCT_IF_C Vp_BFu32ll_C lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_C");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu32ll_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_C, Vp_BFu32ll_C)
//============================================================================


struct  Vp_BFu32ll_D  {
  void *v1;
  __tsu64 v2:32;
  double v3;
};
//SIG(1 Vp_BFu32ll_D) C1{ Fp FL:32 FL}



static void Test_Vp_BFu32ll_D()
{
  {
    init_simple_test("Vp_BFu32ll_D");
    static STRUCT_IF_C Vp_BFu32ll_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu32ll_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_D");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu32ll_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_D, Vp_BFu32ll_D)
//============================================================================


struct  Vp_BFu32ll_F  {
  void *v1;
  __tsu64 v2:32;
  float v3;
};
//SIG(1 Vp_BFu32ll_F) C1{ Fp FL:32 Fi}



static void Test_Vp_BFu32ll_F()
{
  {
    init_simple_test("Vp_BFu32ll_F");
    static STRUCT_IF_C Vp_BFu32ll_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_F");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu32ll_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_F, Vp_BFu32ll_F)
//============================================================================


struct  Vp_BFu32ll_I  {
  void *v1;
  __tsu64 v2:32;
  int v3;
};
//SIG(1 Vp_BFu32ll_I) C1{ Fp FL:32 Fi}



static void Test_Vp_BFu32ll_I()
{
  {
    init_simple_test("Vp_BFu32ll_I");
    static STRUCT_IF_C Vp_BFu32ll_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_I");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu32ll_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_I, Vp_BFu32ll_I)
//============================================================================


struct  Vp_BFu32ll_Ip  {
  void *v1;
  __tsu64 v2:32;
  int *v3;
};
//SIG(1 Vp_BFu32ll_Ip) C1{ Fp FL:32 Fp}



static void Test_Vp_BFu32ll_Ip()
{
  {
    init_simple_test("Vp_BFu32ll_Ip");
    static STRUCT_IF_C Vp_BFu32ll_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu32ll_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_Ip");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu32ll_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_Ip, Vp_BFu32ll_Ip)
//============================================================================


struct  Vp_BFu32ll_L  {
  void *v1;
  __tsu64 v2:32;
  __tsi64 v3;
};
//SIG(1 Vp_BFu32ll_L) C1{ Fp FL:32 FL}



static void Test_Vp_BFu32ll_L()
{
  {
    init_simple_test("Vp_BFu32ll_L");
    static STRUCT_IF_C Vp_BFu32ll_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu32ll_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_L");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu32ll_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_L, Vp_BFu32ll_L)
//============================================================================


struct  Vp_BFu32ll_S  {
  void *v1;
  __tsu64 v2:32;
  short v3;
};
//SIG(1 Vp_BFu32ll_S) C1{ Fp FL:32 Fs}



static void Test_Vp_BFu32ll_S()
{
  {
    init_simple_test("Vp_BFu32ll_S");
    static STRUCT_IF_C Vp_BFu32ll_S lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_S");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu32ll_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_S, Vp_BFu32ll_S)
//============================================================================


struct  Vp_BFu32ll_Uc  {
  void *v1;
  __tsu64 v2:32;
  unsigned char v3;
};
//SIG(1 Vp_BFu32ll_Uc) C1{ Fp FL:32 Fc}



static void Test_Vp_BFu32ll_Uc()
{
  {
    init_simple_test("Vp_BFu32ll_Uc");
    static STRUCT_IF_C Vp_BFu32ll_Uc lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_Uc");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu32ll_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_Uc, Vp_BFu32ll_Uc)
//============================================================================


struct  Vp_BFu32ll_Ui  {
  void *v1;
  __tsu64 v2:32;
  unsigned int v3;
};
//SIG(1 Vp_BFu32ll_Ui) C1{ Fp FL:32 Fi}



static void Test_Vp_BFu32ll_Ui()
{
  {
    init_simple_test("Vp_BFu32ll_Ui");
    static STRUCT_IF_C Vp_BFu32ll_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_Ui");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu32ll_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_Ui, Vp_BFu32ll_Ui)
//============================================================================


struct  Vp_BFu32ll_Ul  {
  void *v1;
  __tsu64 v2:32;
  __tsu64 v3;
};
//SIG(1 Vp_BFu32ll_Ul) C1{ Fp FL:32 FL}



static void Test_Vp_BFu32ll_Ul()
{
  {
    init_simple_test("Vp_BFu32ll_Ul");
    static STRUCT_IF_C Vp_BFu32ll_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu32ll_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_Ul");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu32ll_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_Ul, Vp_BFu32ll_Ul)
//============================================================================


struct  Vp_BFu32ll_Us  {
  void *v1;
  __tsu64 v2:32;
  unsigned short v3;
};
//SIG(1 Vp_BFu32ll_Us) C1{ Fp FL:32 Fs}



static void Test_Vp_BFu32ll_Us()
{
  {
    init_simple_test("Vp_BFu32ll_Us");
    static STRUCT_IF_C Vp_BFu32ll_Us lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu32ll_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_Us");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu32ll_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_Us, Vp_BFu32ll_Us)
//============================================================================


struct  Vp_BFu32ll_Vp  {
  void *v1;
  __tsu64 v2:32;
  void *v3;
};
//SIG(1 Vp_BFu32ll_Vp) C1{ Fp FL:32 Fp}



static void Test_Vp_BFu32ll_Vp()
{
  {
    init_simple_test("Vp_BFu32ll_Vp");
    static STRUCT_IF_C Vp_BFu32ll_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu32ll_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu32ll_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu32ll_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, 1, "Vp_BFu32ll_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 32, hide_ull(1LL<<31), "Vp_BFu32ll_Vp");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu32ll_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu32ll_Vp, Vp_BFu32ll_Vp)
//============================================================================


struct  Vp_BFu33  {
  void *v1;
  __tsu64 v2:33;
};
//SIG(1 Vp_BFu33) C1{ Fp FL:33}



static void Test_Vp_BFu33()
{
  {
    init_simple_test("Vp_BFu33");
    static STRUCT_IF_C Vp_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33, Vp_BFu33)
//============================================================================


struct  Vp_BFu33_BFu15i  {
  void *v1;
  __tsu64 v2:33;
  unsigned int v3:15;
};
//SIG(1 Vp_BFu33_BFu15i) C1{ Fp FL:33 Fi:15}



static void Test_Vp_BFu33_BFu15i()
{
  {
    init_simple_test("Vp_BFu33_BFu15i");
    static STRUCT_IF_C Vp_BFu33_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 15, 1, "Vp_BFu33_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 15, hide_ull(1LL<<14), "Vp_BFu33_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu15i, Vp_BFu33_BFu15i)
//============================================================================


struct  Vp_BFu33_BFu15ll  {
  void *v1;
  __tsu64 v2:33;
  __tsu64 v3:15;
};
//SIG(1 Vp_BFu33_BFu15ll) C1{ Fp FL:33 FL:15}



static void Test_Vp_BFu33_BFu15ll()
{
  {
    init_simple_test("Vp_BFu33_BFu15ll");
    static STRUCT_IF_C Vp_BFu33_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 15, 1, "Vp_BFu33_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 15, hide_ull(1LL<<14), "Vp_BFu33_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu15ll, Vp_BFu33_BFu15ll)
//============================================================================


struct  Vp_BFu33_BFu15s  {
  void *v1;
  __tsu64 v2:33;
  unsigned short v3:15;
};
//SIG(1 Vp_BFu33_BFu15s) C1{ Fp FL:33 Fs:15}



static void Test_Vp_BFu33_BFu15s()
{
  {
    init_simple_test("Vp_BFu33_BFu15s");
    static STRUCT_IF_C Vp_BFu33_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 15, 1, "Vp_BFu33_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 15, hide_ull(1LL<<14), "Vp_BFu33_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu15s, Vp_BFu33_BFu15s)
//============================================================================


struct  Vp_BFu33_BFu16i  {
  void *v1;
  __tsu64 v2:33;
  unsigned int v3:16;
};
//SIG(1 Vp_BFu33_BFu16i) C1{ Fp FL:33 Fi:16}



static void Test_Vp_BFu33_BFu16i()
{
  {
    init_simple_test("Vp_BFu33_BFu16i");
    static STRUCT_IF_C Vp_BFu33_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 16, 1, "Vp_BFu33_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 16, hide_ull(1LL<<15), "Vp_BFu33_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu16i, Vp_BFu33_BFu16i)
//============================================================================


struct  Vp_BFu33_BFu16ll  {
  void *v1;
  __tsu64 v2:33;
  __tsu64 v3:16;
};
//SIG(1 Vp_BFu33_BFu16ll) C1{ Fp FL:33 FL:16}



static void Test_Vp_BFu33_BFu16ll()
{
  {
    init_simple_test("Vp_BFu33_BFu16ll");
    static STRUCT_IF_C Vp_BFu33_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 16, 1, "Vp_BFu33_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 16, hide_ull(1LL<<15), "Vp_BFu33_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu16ll, Vp_BFu33_BFu16ll)
//============================================================================


struct  Vp_BFu33_BFu16s  {
  void *v1;
  __tsu64 v2:33;
  unsigned short v3:16;
};
//SIG(1 Vp_BFu33_BFu16s) C1{ Fp FL:33 Fs:16}



static void Test_Vp_BFu33_BFu16s()
{
  {
    init_simple_test("Vp_BFu33_BFu16s");
    static STRUCT_IF_C Vp_BFu33_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(14,10), 0, 16, 1, "Vp_BFu33_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(14,10), 0, 16, hide_ull(1LL<<15), "Vp_BFu33_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu16s, Vp_BFu33_BFu16s)
//============================================================================


struct  Vp_BFu33_BFu17i  {
  void *v1;
  __tsu64 v2:33;
  unsigned int v3:17;
};
//SIG(1 Vp_BFu33_BFu17i) C1{ Fp FL:33 Fi:17}



static void Test_Vp_BFu33_BFu17i()
{
  {
    init_simple_test("Vp_BFu33_BFu17i");
    static STRUCT_IF_C Vp_BFu33_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 17, 1, "Vp_BFu33_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 17, hide_ull(1LL<<16), "Vp_BFu33_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu17i, Vp_BFu33_BFu17i)
//============================================================================


struct  Vp_BFu33_BFu17ll  {
  void *v1;
  __tsu64 v2:33;
  __tsu64 v3:17;
};
//SIG(1 Vp_BFu33_BFu17ll) C1{ Fp FL:33 FL:17}



static void Test_Vp_BFu33_BFu17ll()
{
  {
    init_simple_test("Vp_BFu33_BFu17ll");
    static STRUCT_IF_C Vp_BFu33_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 17, 1, "Vp_BFu33_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 17, hide_ull(1LL<<16), "Vp_BFu33_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu17ll, Vp_BFu33_BFu17ll)
//============================================================================


struct  Vp_BFu33_BFu1c  {
  void *v1;
  __tsu64 v2:33;
  unsigned char v3:1;
};
//SIG(1 Vp_BFu33_BFu1c) C1{ Fp FL:33 Fc:1}



static void Test_Vp_BFu33_BFu1c()
{
  {
    init_simple_test("Vp_BFu33_BFu1c");
    static STRUCT_IF_C Vp_BFu33_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu1c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu1c");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 1, 1, "Vp_BFu33_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu1c, Vp_BFu33_BFu1c)
//============================================================================


struct  Vp_BFu33_BFu1i  {
  void *v1;
  __tsu64 v2:33;
  unsigned int v3:1;
};
//SIG(1 Vp_BFu33_BFu1i) C1{ Fp FL:33 Fi:1}



static void Test_Vp_BFu33_BFu1i()
{
  {
    init_simple_test("Vp_BFu33_BFu1i");
    static STRUCT_IF_C Vp_BFu33_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu1i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu1i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 1, 1, "Vp_BFu33_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu1i, Vp_BFu33_BFu1i)
//============================================================================


struct  Vp_BFu33_BFu1ll  {
  void *v1;
  __tsu64 v2:33;
  __tsu64 v3:1;
};
//SIG(1 Vp_BFu33_BFu1ll) C1{ Fp FL:33 FL:1}



static void Test_Vp_BFu33_BFu1ll()
{
  {
    init_simple_test("Vp_BFu33_BFu1ll");
    static STRUCT_IF_C Vp_BFu33_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu1ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu1ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 1, 1, "Vp_BFu33_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu1ll, Vp_BFu33_BFu1ll)
//============================================================================


struct  Vp_BFu33_BFu1s  {
  void *v1;
  __tsu64 v2:33;
  unsigned short v3:1;
};
//SIG(1 Vp_BFu33_BFu1s) C1{ Fp FL:33 Fs:1}



static void Test_Vp_BFu33_BFu1s()
{
  {
    init_simple_test("Vp_BFu33_BFu1s");
    static STRUCT_IF_C Vp_BFu33_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu1s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu1s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 1, 1, "Vp_BFu33_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu1s, Vp_BFu33_BFu1s)
//============================================================================


struct  Vp_BFu33_BFu31i  {
  void *v1;
  __tsu64 v2:33;
  unsigned int v3:31;
};
//SIG(1 Vp_BFu33_BFu31i) C1{ Fp FL:33 Fi:31}



static void Test_Vp_BFu33_BFu31i()
{
  {
    init_simple_test("Vp_BFu33_BFu31i");
    static STRUCT_IF_C Vp_BFu33_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 31, 1, "Vp_BFu33_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 31, hide_ull(1LL<<30), "Vp_BFu33_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu31i, Vp_BFu33_BFu31i)
//============================================================================


struct  Vp_BFu33_BFu31ll  {
  void *v1;
  __tsu64 v2:33;
  __tsu64 v3:31;
};
//SIG(1 Vp_BFu33_BFu31ll) C1{ Fp FL:33 FL:31}



static void Test_Vp_BFu33_BFu31ll()
{
  {
    init_simple_test("Vp_BFu33_BFu31ll");
    static STRUCT_IF_C Vp_BFu33_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 31, 1, "Vp_BFu33_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 31, hide_ull(1LL<<30), "Vp_BFu33_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu31ll, Vp_BFu33_BFu31ll)
//============================================================================


struct  Vp_BFu33_BFu32i  {
  void *v1;
  __tsu64 v2:33;
  unsigned int v3:32;
};
//SIG(1 Vp_BFu33_BFu32i) C1{ Fp FL:33 Fi:32}



static void Test_Vp_BFu33_BFu32i()
{
  {
    init_simple_test("Vp_BFu33_BFu32i");
    static STRUCT_IF_C Vp_BFu33_BFu32i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu33_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, 1, "Vp_BFu33_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, hide_ull(1LL<<31), "Vp_BFu33_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu32i, Vp_BFu33_BFu32i)
//============================================================================


struct  Vp_BFu33_BFu32ll  {
  void *v1;
  __tsu64 v2:33;
  __tsu64 v3:32;
};
//SIG(1 Vp_BFu33_BFu32ll) C1{ Fp FL:33 FL:32}



static void Test_Vp_BFu33_BFu32ll()
{
  {
    init_simple_test("Vp_BFu33_BFu32ll");
    static STRUCT_IF_C Vp_BFu33_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu33_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), ABISELECT(0,1), 32, 1, "Vp_BFu33_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), ABISELECT(0,1), 32, hide_ull(1LL<<31), "Vp_BFu33_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu32ll, Vp_BFu33_BFu32ll)
//============================================================================


struct  Vp_BFu33_BFu33  {
  void *v1;
  __tsu64 v2:33;
  __tsu64 v3:33;
};
//SIG(1 Vp_BFu33_BFu33) C1{ Fp FL:33 FL:33}



static void Test_Vp_BFu33_BFu33()
{
  {
    init_simple_test("Vp_BFu33_BFu33");
    static STRUCT_IF_C Vp_BFu33_BFu33 lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu33_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(16,8), ABISELECT(0,1), 33, 1, "Vp_BFu33_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(16,8), ABISELECT(0,1), 33, hide_ull(1LL<<32), "Vp_BFu33_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu33, Vp_BFu33_BFu33)
//============================================================================


struct  Vp_BFu33_BFu7c  {
  void *v1;
  __tsu64 v2:33;
  unsigned char v3:7;
};
//SIG(1 Vp_BFu33_BFu7c) C1{ Fp FL:33 Fc:7}



static void Test_Vp_BFu33_BFu7c()
{
  {
    init_simple_test("Vp_BFu33_BFu7c");
    static STRUCT_IF_C Vp_BFu33_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 7, 1, "Vp_BFu33_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 7, hide_ull(1LL<<6), "Vp_BFu33_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu7c, Vp_BFu33_BFu7c)
//============================================================================


struct  Vp_BFu33_BFu7i  {
  void *v1;
  __tsu64 v2:33;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu33_BFu7i) C1{ Fp FL:33 Fi:7}



static void Test_Vp_BFu33_BFu7i()
{
  {
    init_simple_test("Vp_BFu33_BFu7i");
    static STRUCT_IF_C Vp_BFu33_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 7, 1, "Vp_BFu33_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 7, hide_ull(1LL<<6), "Vp_BFu33_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu7i, Vp_BFu33_BFu7i)
//============================================================================


struct  Vp_BFu33_BFu7ll  {
  void *v1;
  __tsu64 v2:33;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu33_BFu7ll) C1{ Fp FL:33 FL:7}



static void Test_Vp_BFu33_BFu7ll()
{
  {
    init_simple_test("Vp_BFu33_BFu7ll");
    static STRUCT_IF_C Vp_BFu33_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 7, 1, "Vp_BFu33_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 7, hide_ull(1LL<<6), "Vp_BFu33_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu7ll, Vp_BFu33_BFu7ll)
//============================================================================


struct  Vp_BFu33_BFu7s  {
  void *v1;
  __tsu64 v2:33;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu33_BFu7s) C1{ Fp FL:33 Fs:7}



static void Test_Vp_BFu33_BFu7s()
{
  {
    init_simple_test("Vp_BFu33_BFu7s");
    static STRUCT_IF_C Vp_BFu33_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 7, 1, "Vp_BFu33_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 7, hide_ull(1LL<<6), "Vp_BFu33_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu7s, Vp_BFu33_BFu7s)
//============================================================================


struct  Vp_BFu33_BFu8c  {
  void *v1;
  __tsu64 v2:33;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu33_BFu8c) C1{ Fp FL:33 Fc:8}



static void Test_Vp_BFu33_BFu8c()
{
  {
    init_simple_test("Vp_BFu33_BFu8c");
    static STRUCT_IF_C Vp_BFu33_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(13,9), 0, 8, 1, "Vp_BFu33_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(13,9), 0, 8, hide_ull(1LL<<7), "Vp_BFu33_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu8c, Vp_BFu33_BFu8c)
//============================================================================


struct  Vp_BFu33_BFu8i  {
  void *v1;
  __tsu64 v2:33;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu33_BFu8i) C1{ Fp FL:33 Fi:8}



static void Test_Vp_BFu33_BFu8i()
{
  {
    init_simple_test("Vp_BFu33_BFu8i");
    static STRUCT_IF_C Vp_BFu33_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 8, 1, "Vp_BFu33_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 8, hide_ull(1LL<<7), "Vp_BFu33_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu8i, Vp_BFu33_BFu8i)
//============================================================================


struct  Vp_BFu33_BFu8ll  {
  void *v1;
  __tsu64 v2:33;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu33_BFu8ll) C1{ Fp FL:33 FL:8}



static void Test_Vp_BFu33_BFu8ll()
{
  {
    init_simple_test("Vp_BFu33_BFu8ll");
    static STRUCT_IF_C Vp_BFu33_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 8, 1, "Vp_BFu33_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 8, hide_ull(1LL<<7), "Vp_BFu33_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu8ll, Vp_BFu33_BFu8ll)
//============================================================================


struct  Vp_BFu33_BFu8s  {
  void *v1;
  __tsu64 v2:33;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu33_BFu8s) C1{ Fp FL:33 Fs:8}



static void Test_Vp_BFu33_BFu8s()
{
  {
    init_simple_test("Vp_BFu33_BFu8s");
    static STRUCT_IF_C Vp_BFu33_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 8, 1, "Vp_BFu33_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 8, hide_ull(1LL<<7), "Vp_BFu33_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu8s, Vp_BFu33_BFu8s)
//============================================================================


struct  Vp_BFu33_BFu9i  {
  void *v1;
  __tsu64 v2:33;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu33_BFu9i) C1{ Fp FL:33 Fi:9}



static void Test_Vp_BFu33_BFu9i()
{
  {
    init_simple_test("Vp_BFu33_BFu9i");
    static STRUCT_IF_C Vp_BFu33_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 9, 1, "Vp_BFu33_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 9, hide_ull(1LL<<8), "Vp_BFu33_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu9i, Vp_BFu33_BFu9i)
//============================================================================


struct  Vp_BFu33_BFu9ll  {
  void *v1;
  __tsu64 v2:33;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu33_BFu9ll) C1{ Fp FL:33 FL:9}



static void Test_Vp_BFu33_BFu9ll()
{
  {
    init_simple_test("Vp_BFu33_BFu9ll");
    static STRUCT_IF_C Vp_BFu33_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 9, 1, "Vp_BFu33_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 9, hide_ull(1LL<<8), "Vp_BFu33_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu9ll, Vp_BFu33_BFu9ll)
//============================================================================


struct  Vp_BFu33_BFu9s  {
  void *v1;
  __tsu64 v2:33;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu33_BFu9s) C1{ Fp FL:33 Fs:9}



static void Test_Vp_BFu33_BFu9s()
{
  {
    init_simple_test("Vp_BFu33_BFu9s");
    static STRUCT_IF_C Vp_BFu33_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 9, 1, "Vp_BFu33_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 1, 9, hide_ull(1LL<<8), "Vp_BFu33_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_BFu9s, Vp_BFu33_BFu9s)
//============================================================================


struct  Vp_BFu33_C  {
  void *v1;
  __tsu64 v2:33;
  char v3;
};
//SIG(1 Vp_BFu33_C) C1{ Fp FL:33 Fc}



static void Test_Vp_BFu33_C()
{
  {
    init_simple_test("Vp_BFu33_C");
    static STRUCT_IF_C Vp_BFu33_C lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_C");
    check_field_offset(lv, v3, ABISELECT(13,9), "Vp_BFu33_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_C, Vp_BFu33_C)
//============================================================================


struct  Vp_BFu33_D  {
  void *v1;
  __tsu64 v2:33;
  double v3;
};
//SIG(1 Vp_BFu33_D) C1{ Fp FL:33 FL}



static void Test_Vp_BFu33_D()
{
  {
    init_simple_test("Vp_BFu33_D");
    static STRUCT_IF_C Vp_BFu33_D lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_BFu33_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_D");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_BFu33_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_D, Vp_BFu33_D)
//============================================================================


struct  Vp_BFu33_F  {
  void *v1;
  __tsu64 v2:33;
  float v3;
};
//SIG(1 Vp_BFu33_F) C1{ Fp FL:33 Fi}



static void Test_Vp_BFu33_F()
{
  {
    init_simple_test("Vp_BFu33_F");
    static STRUCT_IF_C Vp_BFu33_F lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu33_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_F");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_BFu33_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_F, Vp_BFu33_F)
//============================================================================


struct  Vp_BFu33_I  {
  void *v1;
  __tsu64 v2:33;
  int v3;
};
//SIG(1 Vp_BFu33_I) C1{ Fp FL:33 Fi}



static void Test_Vp_BFu33_I()
{
  {
    init_simple_test("Vp_BFu33_I");
    static STRUCT_IF_C Vp_BFu33_I lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu33_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_I");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_BFu33_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_I, Vp_BFu33_I)
//============================================================================


struct  Vp_BFu33_Ip  {
  void *v1;
  __tsu64 v2:33;
  int *v3;
};
//SIG(1 Vp_BFu33_Ip) C1{ Fp FL:33 Fp}



static void Test_Vp_BFu33_Ip()
{
  {
    init_simple_test("Vp_BFu33_Ip");
    static STRUCT_IF_C Vp_BFu33_Ip lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu33_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_Ip");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_BFu33_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_Ip, Vp_BFu33_Ip)
//============================================================================


struct  Vp_BFu33_L  {
  void *v1;
  __tsu64 v2:33;
  __tsi64 v3;
};
//SIG(1 Vp_BFu33_L) C1{ Fp FL:33 FL}



static void Test_Vp_BFu33_L()
{
  {
    init_simple_test("Vp_BFu33_L");
    static STRUCT_IF_C Vp_BFu33_L lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_BFu33_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_L");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_BFu33_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_L, Vp_BFu33_L)
//============================================================================


struct  Vp_BFu33_S  {
  void *v1;
  __tsu64 v2:33;
  short v3;
};
//SIG(1 Vp_BFu33_S) C1{ Fp FL:33 Fs}



static void Test_Vp_BFu33_S()
{
  {
    init_simple_test("Vp_BFu33_S");
    static STRUCT_IF_C Vp_BFu33_S lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_S");
    check_field_offset(lv, v3, ABISELECT(14,10), "Vp_BFu33_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_S, Vp_BFu33_S)
//============================================================================


struct  Vp_BFu33_Uc  {
  void *v1;
  __tsu64 v2:33;
  unsigned char v3;
};
//SIG(1 Vp_BFu33_Uc) C1{ Fp FL:33 Fc}



static void Test_Vp_BFu33_Uc()
{
  {
    init_simple_test("Vp_BFu33_Uc");
    static STRUCT_IF_C Vp_BFu33_Uc lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_Uc");
    check_field_offset(lv, v3, ABISELECT(13,9), "Vp_BFu33_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_Uc, Vp_BFu33_Uc)
//============================================================================


struct  Vp_BFu33_Ui  {
  void *v1;
  __tsu64 v2:33;
  unsigned int v3;
};
//SIG(1 Vp_BFu33_Ui) C1{ Fp FL:33 Fi}



static void Test_Vp_BFu33_Ui()
{
  {
    init_simple_test("Vp_BFu33_Ui");
    static STRUCT_IF_C Vp_BFu33_Ui lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu33_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_Ui");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_BFu33_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_Ui, Vp_BFu33_Ui)
//============================================================================


struct  Vp_BFu33_Ul  {
  void *v1;
  __tsu64 v2:33;
  __tsu64 v3;
};
//SIG(1 Vp_BFu33_Ul) C1{ Fp FL:33 FL}



static void Test_Vp_BFu33_Ul()
{
  {
    init_simple_test("Vp_BFu33_Ul");
    static STRUCT_IF_C Vp_BFu33_Ul lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_BFu33_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_Ul");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_BFu33_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_Ul, Vp_BFu33_Ul)
//============================================================================


struct  Vp_BFu33_Us  {
  void *v1;
  __tsu64 v2:33;
  unsigned short v3;
};
//SIG(1 Vp_BFu33_Us) C1{ Fp FL:33 Fs}



static void Test_Vp_BFu33_Us()
{
  {
    init_simple_test("Vp_BFu33_Us");
    static STRUCT_IF_C Vp_BFu33_Us lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu33_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_Us");
    check_field_offset(lv, v3, ABISELECT(14,10), "Vp_BFu33_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_Us, Vp_BFu33_Us)
//============================================================================


struct  Vp_BFu33_Vp  {
  void *v1;
  __tsu64 v2:33;
  void *v3;
};
//SIG(1 Vp_BFu33_Vp) C1{ Fp FL:33 Fp}



static void Test_Vp_BFu33_Vp()
{
  {
    init_simple_test("Vp_BFu33_Vp");
    static STRUCT_IF_C Vp_BFu33_Vp lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu33_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu33_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu33_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, 1, "Vp_BFu33_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 33, hide_ull(1LL<<32), "Vp_BFu33_Vp");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_BFu33_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu33_Vp, Vp_BFu33_Vp)
//============================================================================


struct  Vp_BFu7c  {
  void *v1;
  unsigned char v2:7;
};
//SIG(1 Vp_BFu7c) C1{ Fp Fc:7}



static void Test_Vp_BFu7c()
{
  {
    init_simple_test("Vp_BFu7c");
    static STRUCT_IF_C Vp_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c, Vp_BFu7c)
//============================================================================


struct  Vp_BFu7c_BFu15i  {
  void *v1;
  unsigned char v2:7;
  unsigned int v3:15;
};
//SIG(1 Vp_BFu7c_BFu15i) C1{ Fp Fc:7 Fi:15}



static void Test_Vp_BFu7c_BFu15i()
{
  {
    init_simple_test("Vp_BFu7c_BFu15i");
    static STRUCT_IF_C Vp_BFu7c_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, 1, "Vp_BFu7c_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, hide_ull(1LL<<14), "Vp_BFu7c_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu15i, Vp_BFu7c_BFu15i)
//============================================================================


struct  Vp_BFu7c_BFu15ll  {
  void *v1;
  unsigned char v2:7;
  __tsu64 v3:15;
};
//SIG(1 Vp_BFu7c_BFu15ll) C1{ Fp Fc:7 FL:15}



static void Test_Vp_BFu7c_BFu15ll()
{
  {
    init_simple_test("Vp_BFu7c_BFu15ll");
    static STRUCT_IF_C Vp_BFu7c_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, 1, "Vp_BFu7c_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, hide_ull(1LL<<14), "Vp_BFu7c_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu15ll, Vp_BFu7c_BFu15ll)
//============================================================================


struct  Vp_BFu7c_BFu15s  {
  void *v1;
  unsigned char v2:7;
  unsigned short v3:15;
};
//SIG(1 Vp_BFu7c_BFu15s) C1{ Fp Fc:7 Fs:15}



static void Test_Vp_BFu7c_BFu15s()
{
  {
    init_simple_test("Vp_BFu7c_BFu15s");
    static STRUCT_IF_C Vp_BFu7c_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_BFu7c_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_BFu7c_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu15s, Vp_BFu7c_BFu15s)
//============================================================================


struct  Vp_BFu7c_BFu16i  {
  void *v1;
  unsigned char v2:7;
  unsigned int v3:16;
};
//SIG(1 Vp_BFu7c_BFu16i) C1{ Fp Fc:7 Fi:16}



static void Test_Vp_BFu7c_BFu16i()
{
  {
    init_simple_test("Vp_BFu7c_BFu16i");
    static STRUCT_IF_C Vp_BFu7c_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, 1, "Vp_BFu7c_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, hide_ull(1LL<<15), "Vp_BFu7c_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu16i, Vp_BFu7c_BFu16i)
//============================================================================


struct  Vp_BFu7c_BFu16ll  {
  void *v1;
  unsigned char v2:7;
  __tsu64 v3:16;
};
//SIG(1 Vp_BFu7c_BFu16ll) C1{ Fp Fc:7 FL:16}



static void Test_Vp_BFu7c_BFu16ll()
{
  {
    init_simple_test("Vp_BFu7c_BFu16ll");
    static STRUCT_IF_C Vp_BFu7c_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, 1, "Vp_BFu7c_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, hide_ull(1LL<<15), "Vp_BFu7c_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu16ll, Vp_BFu7c_BFu16ll)
//============================================================================


struct  Vp_BFu7c_BFu16s  {
  void *v1;
  unsigned char v2:7;
  unsigned short v3:16;
};
//SIG(1 Vp_BFu7c_BFu16s) C1{ Fp Fc:7 Fs:16}



static void Test_Vp_BFu7c_BFu16s()
{
  {
    init_simple_test("Vp_BFu7c_BFu16s");
    static STRUCT_IF_C Vp_BFu7c_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_BFu7c_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_BFu7c_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu16s, Vp_BFu7c_BFu16s)
//============================================================================


struct  Vp_BFu7c_BFu17i  {
  void *v1;
  unsigned char v2:7;
  unsigned int v3:17;
};
//SIG(1 Vp_BFu7c_BFu17i) C1{ Fp Fc:7 Fi:17}



static void Test_Vp_BFu7c_BFu17i()
{
  {
    init_simple_test("Vp_BFu7c_BFu17i");
    static STRUCT_IF_C Vp_BFu7c_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, 1, "Vp_BFu7c_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, hide_ull(1LL<<16), "Vp_BFu7c_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu17i, Vp_BFu7c_BFu17i)
//============================================================================


struct  Vp_BFu7c_BFu17ll  {
  void *v1;
  unsigned char v2:7;
  __tsu64 v3:17;
};
//SIG(1 Vp_BFu7c_BFu17ll) C1{ Fp Fc:7 FL:17}



static void Test_Vp_BFu7c_BFu17ll()
{
  {
    init_simple_test("Vp_BFu7c_BFu17ll");
    static STRUCT_IF_C Vp_BFu7c_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, 1, "Vp_BFu7c_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, hide_ull(1LL<<16), "Vp_BFu7c_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu17ll, Vp_BFu7c_BFu17ll)
//============================================================================


struct  Vp_BFu7c_BFu1c  {
  void *v1;
  unsigned char v2:7;
  unsigned char v3:1;
};
//SIG(1 Vp_BFu7c_BFu1c) C1{ Fp Fc:7 Fc:1}



static void Test_Vp_BFu7c_BFu1c()
{
  {
    init_simple_test("Vp_BFu7c_BFu1c");
    static STRUCT_IF_C Vp_BFu7c_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu1c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu1c");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7c_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu1c, Vp_BFu7c_BFu1c)
//============================================================================


struct  Vp_BFu7c_BFu1i  {
  void *v1;
  unsigned char v2:7;
  unsigned int v3:1;
};
//SIG(1 Vp_BFu7c_BFu1i) C1{ Fp Fc:7 Fi:1}



static void Test_Vp_BFu7c_BFu1i()
{
  {
    init_simple_test("Vp_BFu7c_BFu1i");
    static STRUCT_IF_C Vp_BFu7c_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu1i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu1i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7c_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu1i, Vp_BFu7c_BFu1i)
//============================================================================


struct  Vp_BFu7c_BFu1ll  {
  void *v1;
  unsigned char v2:7;
  __tsu64 v3:1;
};
//SIG(1 Vp_BFu7c_BFu1ll) C1{ Fp Fc:7 FL:1}



static void Test_Vp_BFu7c_BFu1ll()
{
  {
    init_simple_test("Vp_BFu7c_BFu1ll");
    static STRUCT_IF_C Vp_BFu7c_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu1ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu1ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7c_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu1ll, Vp_BFu7c_BFu1ll)
//============================================================================


struct  Vp_BFu7c_BFu1s  {
  void *v1;
  unsigned char v2:7;
  unsigned short v3:1;
};
//SIG(1 Vp_BFu7c_BFu1s) C1{ Fp Fc:7 Fs:1}



static void Test_Vp_BFu7c_BFu1s()
{
  {
    init_simple_test("Vp_BFu7c_BFu1s");
    static STRUCT_IF_C Vp_BFu7c_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu1s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu1s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7c_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu1s, Vp_BFu7c_BFu1s)
//============================================================================


struct  Vp_BFu7c_BFu31i  {
  void *v1;
  unsigned char v2:7;
  unsigned int v3:31;
};
//SIG(1 Vp_BFu7c_BFu31i) C1{ Fp Fc:7 Fi:31}



static void Test_Vp_BFu7c_BFu31i()
{
  {
    init_simple_test("Vp_BFu7c_BFu31i");
    static STRUCT_IF_C Vp_BFu7c_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7c_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_BFu7c_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_BFu7c_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu31i, Vp_BFu7c_BFu31i)
//============================================================================


struct  Vp_BFu7c_BFu31ll  {
  void *v1;
  unsigned char v2:7;
  __tsu64 v3:31;
};
//SIG(1 Vp_BFu7c_BFu31ll) C1{ Fp Fc:7 FL:31}



static void Test_Vp_BFu7c_BFu31ll()
{
  {
    init_simple_test("Vp_BFu7c_BFu31ll");
    static STRUCT_IF_C Vp_BFu7c_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7c_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 31, 1, "Vp_BFu7c_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 31, hide_ull(1LL<<30), "Vp_BFu7c_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu31ll, Vp_BFu7c_BFu31ll)
//============================================================================


struct  Vp_BFu7c_BFu32i  {
  void *v1;
  unsigned char v2:7;
  unsigned int v3:32;
};
//SIG(1 Vp_BFu7c_BFu32i) C1{ Fp Fc:7 Fi:32}



static void Test_Vp_BFu7c_BFu32i()
{
  {
    init_simple_test("Vp_BFu7c_BFu32i");
    static STRUCT_IF_C Vp_BFu7c_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7c_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_BFu7c_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_BFu7c_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu32i, Vp_BFu7c_BFu32i)
//============================================================================


struct  Vp_BFu7c_BFu32ll  {
  void *v1;
  unsigned char v2:7;
  __tsu64 v3:32;
};
//SIG(1 Vp_BFu7c_BFu32ll) C1{ Fp Fc:7 FL:32}



static void Test_Vp_BFu7c_BFu32ll()
{
  {
    init_simple_test("Vp_BFu7c_BFu32ll");
    static STRUCT_IF_C Vp_BFu7c_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7c_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 32, 1, "Vp_BFu7c_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 32, hide_ull(1LL<<31), "Vp_BFu7c_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu32ll, Vp_BFu7c_BFu32ll)
//============================================================================


struct  Vp_BFu7c_BFu33  {
  void *v1;
  unsigned char v2:7;
  __tsu64 v3:33;
};
//SIG(1 Vp_BFu7c_BFu33) C1{ Fp Fc:7 FL:33}



static void Test_Vp_BFu7c_BFu33()
{
  {
    init_simple_test("Vp_BFu7c_BFu33");
    static STRUCT_IF_C Vp_BFu7c_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7c_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 33, 1, "Vp_BFu7c_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 33, hide_ull(1LL<<32), "Vp_BFu7c_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu33, Vp_BFu7c_BFu33)
//============================================================================


struct  Vp_BFu7c_BFu7c  {
  void *v1;
  unsigned char v2:7;
  unsigned char v3:7;
};
//SIG(1 Vp_BFu7c_BFu7c) C1{ Fp Fc:7 Fc:7}



static void Test_Vp_BFu7c_BFu7c()
{
  {
    init_simple_test("Vp_BFu7c_BFu7c");
    static STRUCT_IF_C Vp_BFu7c_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu7c_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu7c, Vp_BFu7c_BFu7c)
//============================================================================


struct  Vp_BFu7c_BFu7i  {
  void *v1;
  unsigned char v2:7;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu7c_BFu7i) C1{ Fp Fc:7 Fi:7}



static void Test_Vp_BFu7c_BFu7i()
{
  {
    init_simple_test("Vp_BFu7c_BFu7i");
    static STRUCT_IF_C Vp_BFu7c_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, 1, "Vp_BFu7c_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu7i, Vp_BFu7c_BFu7i)
//============================================================================


struct  Vp_BFu7c_BFu7ll  {
  void *v1;
  unsigned char v2:7;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu7c_BFu7ll) C1{ Fp Fc:7 FL:7}



static void Test_Vp_BFu7c_BFu7ll()
{
  {
    init_simple_test("Vp_BFu7c_BFu7ll");
    static STRUCT_IF_C Vp_BFu7c_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, 1, "Vp_BFu7c_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu7ll, Vp_BFu7c_BFu7ll)
//============================================================================


struct  Vp_BFu7c_BFu7s  {
  void *v1;
  unsigned char v2:7;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu7c_BFu7s) C1{ Fp Fc:7 Fs:7}



static void Test_Vp_BFu7c_BFu7s()
{
  {
    init_simple_test("Vp_BFu7c_BFu7s");
    static STRUCT_IF_C Vp_BFu7c_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, 1, "Vp_BFu7c_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu7s, Vp_BFu7c_BFu7s)
//============================================================================


struct  Vp_BFu7c_BFu8c  {
  void *v1;
  unsigned char v2:7;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu7c_BFu8c) C1{ Fp Fc:7 Fc:8}



static void Test_Vp_BFu7c_BFu8c()
{
  {
    init_simple_test("Vp_BFu7c_BFu8c");
    static STRUCT_IF_C Vp_BFu7c_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu7c_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu7c_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu8c, Vp_BFu7c_BFu8c)
//============================================================================


struct  Vp_BFu7c_BFu8i  {
  void *v1;
  unsigned char v2:7;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu7c_BFu8i) C1{ Fp Fc:7 Fi:8}



static void Test_Vp_BFu7c_BFu8i()
{
  {
    init_simple_test("Vp_BFu7c_BFu8i");
    static STRUCT_IF_C Vp_BFu7c_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, 1, "Vp_BFu7c_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, hide_ull(1LL<<7), "Vp_BFu7c_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu8i, Vp_BFu7c_BFu8i)
//============================================================================


struct  Vp_BFu7c_BFu8ll  {
  void *v1;
  unsigned char v2:7;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu7c_BFu8ll) C1{ Fp Fc:7 FL:8}



static void Test_Vp_BFu7c_BFu8ll()
{
  {
    init_simple_test("Vp_BFu7c_BFu8ll");
    static STRUCT_IF_C Vp_BFu7c_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, 1, "Vp_BFu7c_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, hide_ull(1LL<<7), "Vp_BFu7c_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu8ll, Vp_BFu7c_BFu8ll)
//============================================================================


struct  Vp_BFu7c_BFu8s  {
  void *v1;
  unsigned char v2:7;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu7c_BFu8s) C1{ Fp Fc:7 Fs:8}



static void Test_Vp_BFu7c_BFu8s()
{
  {
    init_simple_test("Vp_BFu7c_BFu8s");
    static STRUCT_IF_C Vp_BFu7c_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, 1, "Vp_BFu7c_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, hide_ull(1LL<<7), "Vp_BFu7c_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu8s, Vp_BFu7c_BFu8s)
//============================================================================


struct  Vp_BFu7c_BFu9i  {
  void *v1;
  unsigned char v2:7;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu7c_BFu9i) C1{ Fp Fc:7 Fi:9}



static void Test_Vp_BFu7c_BFu9i()
{
  {
    init_simple_test("Vp_BFu7c_BFu9i");
    static STRUCT_IF_C Vp_BFu7c_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, 1, "Vp_BFu7c_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, hide_ull(1LL<<8), "Vp_BFu7c_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu9i, Vp_BFu7c_BFu9i)
//============================================================================


struct  Vp_BFu7c_BFu9ll  {
  void *v1;
  unsigned char v2:7;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu7c_BFu9ll) C1{ Fp Fc:7 FL:9}



static void Test_Vp_BFu7c_BFu9ll()
{
  {
    init_simple_test("Vp_BFu7c_BFu9ll");
    static STRUCT_IF_C Vp_BFu7c_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, 1, "Vp_BFu7c_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, hide_ull(1LL<<8), "Vp_BFu7c_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu9ll, Vp_BFu7c_BFu9ll)
//============================================================================


struct  Vp_BFu7c_BFu9s  {
  void *v1;
  unsigned char v2:7;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu7c_BFu9s) C1{ Fp Fc:7 Fs:9}



static void Test_Vp_BFu7c_BFu9s()
{
  {
    init_simple_test("Vp_BFu7c_BFu9s");
    static STRUCT_IF_C Vp_BFu7c_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, 1, "Vp_BFu7c_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, hide_ull(1LL<<8), "Vp_BFu7c_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_BFu9s, Vp_BFu7c_BFu9s)
//============================================================================


struct  Vp_BFu7c_C  {
  void *v1;
  unsigned char v2:7;
  char v3;
};
//SIG(1 Vp_BFu7c_C) C1{ Fp Fc:7 Fc}



static void Test_Vp_BFu7c_C()
{
  {
    init_simple_test("Vp_BFu7c_C");
    static STRUCT_IF_C Vp_BFu7c_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_C");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7c_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_C, Vp_BFu7c_C)
//============================================================================


struct  Vp_BFu7c_D  {
  void *v1;
  unsigned char v2:7;
  double v3;
};
//SIG(1 Vp_BFu7c_D) C1{ Fp Fc:7 FL}



static void Test_Vp_BFu7c_D()
{
  {
    init_simple_test("Vp_BFu7c_D");
    static STRUCT_IF_C Vp_BFu7c_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu7c_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_D");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7c_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_D, Vp_BFu7c_D)
//============================================================================


struct  Vp_BFu7c_F  {
  void *v1;
  unsigned char v2:7;
  float v3;
};
//SIG(1 Vp_BFu7c_F) C1{ Fp Fc:7 Fi}



static void Test_Vp_BFu7c_F()
{
  {
    init_simple_test("Vp_BFu7c_F");
    static STRUCT_IF_C Vp_BFu7c_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7c_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_F");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu7c_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_F, Vp_BFu7c_F)
//============================================================================


struct  Vp_BFu7c_I  {
  void *v1;
  unsigned char v2:7;
  int v3;
};
//SIG(1 Vp_BFu7c_I) C1{ Fp Fc:7 Fi}



static void Test_Vp_BFu7c_I()
{
  {
    init_simple_test("Vp_BFu7c_I");
    static STRUCT_IF_C Vp_BFu7c_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7c_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_I");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu7c_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_I, Vp_BFu7c_I)
//============================================================================


struct  Vp_BFu7c_Ip  {
  void *v1;
  unsigned char v2:7;
  int *v3;
};
//SIG(1 Vp_BFu7c_Ip) C1{ Fp Fc:7 Fp}



static void Test_Vp_BFu7c_Ip()
{
  {
    init_simple_test("Vp_BFu7c_Ip");
    static STRUCT_IF_C Vp_BFu7c_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu7c_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_Ip");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7c_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_Ip, Vp_BFu7c_Ip)
//============================================================================


struct  Vp_BFu7c_L  {
  void *v1;
  unsigned char v2:7;
  __tsi64 v3;
};
//SIG(1 Vp_BFu7c_L) C1{ Fp Fc:7 FL}



static void Test_Vp_BFu7c_L()
{
  {
    init_simple_test("Vp_BFu7c_L");
    static STRUCT_IF_C Vp_BFu7c_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu7c_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_L");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7c_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_L, Vp_BFu7c_L)
//============================================================================


struct  Vp_BFu7c_S  {
  void *v1;
  unsigned char v2:7;
  short v3;
};
//SIG(1 Vp_BFu7c_S) C1{ Fp Fc:7 Fs}



static void Test_Vp_BFu7c_S()
{
  {
    init_simple_test("Vp_BFu7c_S");
    static STRUCT_IF_C Vp_BFu7c_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_S");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu7c_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_S, Vp_BFu7c_S)
//============================================================================


struct  Vp_BFu7c_Uc  {
  void *v1;
  unsigned char v2:7;
  unsigned char v3;
};
//SIG(1 Vp_BFu7c_Uc) C1{ Fp Fc:7 Fc}



static void Test_Vp_BFu7c_Uc()
{
  {
    init_simple_test("Vp_BFu7c_Uc");
    static STRUCT_IF_C Vp_BFu7c_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_Uc");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7c_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_Uc, Vp_BFu7c_Uc)
//============================================================================


struct  Vp_BFu7c_Ui  {
  void *v1;
  unsigned char v2:7;
  unsigned int v3;
};
//SIG(1 Vp_BFu7c_Ui) C1{ Fp Fc:7 Fi}



static void Test_Vp_BFu7c_Ui()
{
  {
    init_simple_test("Vp_BFu7c_Ui");
    static STRUCT_IF_C Vp_BFu7c_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7c_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_Ui");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu7c_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_Ui, Vp_BFu7c_Ui)
//============================================================================


struct  Vp_BFu7c_Ul  {
  void *v1;
  unsigned char v2:7;
  __tsu64 v3;
};
//SIG(1 Vp_BFu7c_Ul) C1{ Fp Fc:7 FL}



static void Test_Vp_BFu7c_Ul()
{
  {
    init_simple_test("Vp_BFu7c_Ul");
    static STRUCT_IF_C Vp_BFu7c_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu7c_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_Ul");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7c_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_Ul, Vp_BFu7c_Ul)
//============================================================================


struct  Vp_BFu7c_Us  {
  void *v1;
  unsigned char v2:7;
  unsigned short v3;
};
//SIG(1 Vp_BFu7c_Us) C1{ Fp Fc:7 Fs}



static void Test_Vp_BFu7c_Us()
{
  {
    init_simple_test("Vp_BFu7c_Us");
    static STRUCT_IF_C Vp_BFu7c_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7c_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_Us");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu7c_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_Us, Vp_BFu7c_Us)
//============================================================================


struct  Vp_BFu7c_Vp  {
  void *v1;
  unsigned char v2:7;
  void *v3;
};
//SIG(1 Vp_BFu7c_Vp) C1{ Fp Fc:7 Fp}



static void Test_Vp_BFu7c_Vp()
{
  {
    init_simple_test("Vp_BFu7c_Vp");
    static STRUCT_IF_C Vp_BFu7c_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu7c_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7c_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu7c_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7c_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7c_Vp");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7c_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7c_Vp, Vp_BFu7c_Vp)
//============================================================================


struct  Vp_BFu7i  {
  void *v1;
  unsigned int v2:7;
};
//SIG(1 Vp_BFu7i) C1{ Fp Fi:7}



static void Test_Vp_BFu7i()
{
  {
    init_simple_test("Vp_BFu7i");
    static STRUCT_IF_C Vp_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i, Vp_BFu7i)
//============================================================================


struct  Vp_BFu7i_BFu15i  {
  void *v1;
  unsigned int v2:7;
  unsigned int v3:15;
};
//SIG(1 Vp_BFu7i_BFu15i) C1{ Fp Fi:7 Fi:15}



static void Test_Vp_BFu7i_BFu15i()
{
  {
    init_simple_test("Vp_BFu7i_BFu15i");
    static STRUCT_IF_C Vp_BFu7i_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, 1, "Vp_BFu7i_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, hide_ull(1LL<<14), "Vp_BFu7i_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu15i, Vp_BFu7i_BFu15i)
//============================================================================


struct  Vp_BFu7i_BFu15ll  {
  void *v1;
  unsigned int v2:7;
  __tsu64 v3:15;
};
//SIG(1 Vp_BFu7i_BFu15ll) C1{ Fp Fi:7 FL:15}



static void Test_Vp_BFu7i_BFu15ll()
{
  {
    init_simple_test("Vp_BFu7i_BFu15ll");
    static STRUCT_IF_C Vp_BFu7i_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, 1, "Vp_BFu7i_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, hide_ull(1LL<<14), "Vp_BFu7i_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu15ll, Vp_BFu7i_BFu15ll)
//============================================================================


struct  Vp_BFu7i_BFu15s  {
  void *v1;
  unsigned int v2:7;
  unsigned short v3:15;
};
//SIG(1 Vp_BFu7i_BFu15s) C1{ Fp Fi:7 Fs:15}



static void Test_Vp_BFu7i_BFu15s()
{
  {
    init_simple_test("Vp_BFu7i_BFu15s");
    static STRUCT_IF_C Vp_BFu7i_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_BFu7i_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_BFu7i_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu15s, Vp_BFu7i_BFu15s)
//============================================================================


struct  Vp_BFu7i_BFu16i  {
  void *v1;
  unsigned int v2:7;
  unsigned int v3:16;
};
//SIG(1 Vp_BFu7i_BFu16i) C1{ Fp Fi:7 Fi:16}



static void Test_Vp_BFu7i_BFu16i()
{
  {
    init_simple_test("Vp_BFu7i_BFu16i");
    static STRUCT_IF_C Vp_BFu7i_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, 1, "Vp_BFu7i_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, hide_ull(1LL<<15), "Vp_BFu7i_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu16i, Vp_BFu7i_BFu16i)
//============================================================================


struct  Vp_BFu7i_BFu16ll  {
  void *v1;
  unsigned int v2:7;
  __tsu64 v3:16;
};
//SIG(1 Vp_BFu7i_BFu16ll) C1{ Fp Fi:7 FL:16}



static void Test_Vp_BFu7i_BFu16ll()
{
  {
    init_simple_test("Vp_BFu7i_BFu16ll");
    static STRUCT_IF_C Vp_BFu7i_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, 1, "Vp_BFu7i_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, hide_ull(1LL<<15), "Vp_BFu7i_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu16ll, Vp_BFu7i_BFu16ll)
//============================================================================


struct  Vp_BFu7i_BFu16s  {
  void *v1;
  unsigned int v2:7;
  unsigned short v3:16;
};
//SIG(1 Vp_BFu7i_BFu16s) C1{ Fp Fi:7 Fs:16}



static void Test_Vp_BFu7i_BFu16s()
{
  {
    init_simple_test("Vp_BFu7i_BFu16s");
    static STRUCT_IF_C Vp_BFu7i_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_BFu7i_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_BFu7i_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu16s, Vp_BFu7i_BFu16s)
//============================================================================


struct  Vp_BFu7i_BFu17i  {
  void *v1;
  unsigned int v2:7;
  unsigned int v3:17;
};
//SIG(1 Vp_BFu7i_BFu17i) C1{ Fp Fi:7 Fi:17}



static void Test_Vp_BFu7i_BFu17i()
{
  {
    init_simple_test("Vp_BFu7i_BFu17i");
    static STRUCT_IF_C Vp_BFu7i_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, 1, "Vp_BFu7i_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, hide_ull(1LL<<16), "Vp_BFu7i_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu17i, Vp_BFu7i_BFu17i)
//============================================================================


struct  Vp_BFu7i_BFu17ll  {
  void *v1;
  unsigned int v2:7;
  __tsu64 v3:17;
};
//SIG(1 Vp_BFu7i_BFu17ll) C1{ Fp Fi:7 FL:17}



static void Test_Vp_BFu7i_BFu17ll()
{
  {
    init_simple_test("Vp_BFu7i_BFu17ll");
    static STRUCT_IF_C Vp_BFu7i_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, 1, "Vp_BFu7i_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, hide_ull(1LL<<16), "Vp_BFu7i_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu17ll, Vp_BFu7i_BFu17ll)
//============================================================================


struct  Vp_BFu7i_BFu1c  {
  void *v1;
  unsigned int v2:7;
  unsigned char v3:1;
};
//SIG(1 Vp_BFu7i_BFu1c) C1{ Fp Fi:7 Fc:1}



static void Test_Vp_BFu7i_BFu1c()
{
  {
    init_simple_test("Vp_BFu7i_BFu1c");
    static STRUCT_IF_C Vp_BFu7i_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu1c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu1c");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7i_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu1c, Vp_BFu7i_BFu1c)
//============================================================================


struct  Vp_BFu7i_BFu1i  {
  void *v1;
  unsigned int v2:7;
  unsigned int v3:1;
};
//SIG(1 Vp_BFu7i_BFu1i) C1{ Fp Fi:7 Fi:1}



static void Test_Vp_BFu7i_BFu1i()
{
  {
    init_simple_test("Vp_BFu7i_BFu1i");
    static STRUCT_IF_C Vp_BFu7i_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu1i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu1i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7i_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu1i, Vp_BFu7i_BFu1i)
//============================================================================


struct  Vp_BFu7i_BFu1ll  {
  void *v1;
  unsigned int v2:7;
  __tsu64 v3:1;
};
//SIG(1 Vp_BFu7i_BFu1ll) C1{ Fp Fi:7 FL:1}



static void Test_Vp_BFu7i_BFu1ll()
{
  {
    init_simple_test("Vp_BFu7i_BFu1ll");
    static STRUCT_IF_C Vp_BFu7i_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu1ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu1ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7i_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu1ll, Vp_BFu7i_BFu1ll)
//============================================================================


struct  Vp_BFu7i_BFu1s  {
  void *v1;
  unsigned int v2:7;
  unsigned short v3:1;
};
//SIG(1 Vp_BFu7i_BFu1s) C1{ Fp Fi:7 Fs:1}



static void Test_Vp_BFu7i_BFu1s()
{
  {
    init_simple_test("Vp_BFu7i_BFu1s");
    static STRUCT_IF_C Vp_BFu7i_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu1s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu1s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7i_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu1s, Vp_BFu7i_BFu1s)
//============================================================================


struct  Vp_BFu7i_BFu31i  {
  void *v1;
  unsigned int v2:7;
  unsigned int v3:31;
};
//SIG(1 Vp_BFu7i_BFu31i) C1{ Fp Fi:7 Fi:31}



static void Test_Vp_BFu7i_BFu31i()
{
  {
    init_simple_test("Vp_BFu7i_BFu31i");
    static STRUCT_IF_C Vp_BFu7i_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7i_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_BFu7i_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_BFu7i_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu31i, Vp_BFu7i_BFu31i)
//============================================================================


struct  Vp_BFu7i_BFu31ll  {
  void *v1;
  unsigned int v2:7;
  __tsu64 v3:31;
};
//SIG(1 Vp_BFu7i_BFu31ll) C1{ Fp Fi:7 FL:31}



static void Test_Vp_BFu7i_BFu31ll()
{
  {
    init_simple_test("Vp_BFu7i_BFu31ll");
    static STRUCT_IF_C Vp_BFu7i_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7i_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 31, 1, "Vp_BFu7i_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 31, hide_ull(1LL<<30), "Vp_BFu7i_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu31ll, Vp_BFu7i_BFu31ll)
//============================================================================


struct  Vp_BFu7i_BFu32i  {
  void *v1;
  unsigned int v2:7;
  unsigned int v3:32;
};
//SIG(1 Vp_BFu7i_BFu32i) C1{ Fp Fi:7 Fi:32}



static void Test_Vp_BFu7i_BFu32i()
{
  {
    init_simple_test("Vp_BFu7i_BFu32i");
    static STRUCT_IF_C Vp_BFu7i_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7i_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_BFu7i_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_BFu7i_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu32i, Vp_BFu7i_BFu32i)
//============================================================================


struct  Vp_BFu7i_BFu32ll  {
  void *v1;
  unsigned int v2:7;
  __tsu64 v3:32;
};
//SIG(1 Vp_BFu7i_BFu32ll) C1{ Fp Fi:7 FL:32}



static void Test_Vp_BFu7i_BFu32ll()
{
  {
    init_simple_test("Vp_BFu7i_BFu32ll");
    static STRUCT_IF_C Vp_BFu7i_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7i_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 32, 1, "Vp_BFu7i_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 32, hide_ull(1LL<<31), "Vp_BFu7i_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu32ll, Vp_BFu7i_BFu32ll)
//============================================================================


struct  Vp_BFu7i_BFu33  {
  void *v1;
  unsigned int v2:7;
  __tsu64 v3:33;
};
//SIG(1 Vp_BFu7i_BFu33) C1{ Fp Fi:7 FL:33}



static void Test_Vp_BFu7i_BFu33()
{
  {
    init_simple_test("Vp_BFu7i_BFu33");
    static STRUCT_IF_C Vp_BFu7i_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7i_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 33, 1, "Vp_BFu7i_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 33, hide_ull(1LL<<32), "Vp_BFu7i_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu33, Vp_BFu7i_BFu33)
//============================================================================


struct  Vp_BFu7i_BFu7c  {
  void *v1;
  unsigned int v2:7;
  unsigned char v3:7;
};
//SIG(1 Vp_BFu7i_BFu7c) C1{ Fp Fi:7 Fc:7}



static void Test_Vp_BFu7i_BFu7c()
{
  {
    init_simple_test("Vp_BFu7i_BFu7c");
    static STRUCT_IF_C Vp_BFu7i_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu7i_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu7c, Vp_BFu7i_BFu7c)
//============================================================================


struct  Vp_BFu7i_BFu7i  {
  void *v1;
  unsigned int v2:7;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu7i_BFu7i) C1{ Fp Fi:7 Fi:7}



static void Test_Vp_BFu7i_BFu7i()
{
  {
    init_simple_test("Vp_BFu7i_BFu7i");
    static STRUCT_IF_C Vp_BFu7i_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, 1, "Vp_BFu7i_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu7i, Vp_BFu7i_BFu7i)
//============================================================================


struct  Vp_BFu7i_BFu7ll  {
  void *v1;
  unsigned int v2:7;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu7i_BFu7ll) C1{ Fp Fi:7 FL:7}



static void Test_Vp_BFu7i_BFu7ll()
{
  {
    init_simple_test("Vp_BFu7i_BFu7ll");
    static STRUCT_IF_C Vp_BFu7i_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, 1, "Vp_BFu7i_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu7ll, Vp_BFu7i_BFu7ll)
//============================================================================


struct  Vp_BFu7i_BFu7s  {
  void *v1;
  unsigned int v2:7;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu7i_BFu7s) C1{ Fp Fi:7 Fs:7}



static void Test_Vp_BFu7i_BFu7s()
{
  {
    init_simple_test("Vp_BFu7i_BFu7s");
    static STRUCT_IF_C Vp_BFu7i_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, 1, "Vp_BFu7i_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu7s, Vp_BFu7i_BFu7s)
//============================================================================


struct  Vp_BFu7i_BFu8c  {
  void *v1;
  unsigned int v2:7;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu7i_BFu8c) C1{ Fp Fi:7 Fc:8}



static void Test_Vp_BFu7i_BFu8c()
{
  {
    init_simple_test("Vp_BFu7i_BFu8c");
    static STRUCT_IF_C Vp_BFu7i_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu7i_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu7i_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu8c, Vp_BFu7i_BFu8c)
//============================================================================


struct  Vp_BFu7i_BFu8i  {
  void *v1;
  unsigned int v2:7;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu7i_BFu8i) C1{ Fp Fi:7 Fi:8}



static void Test_Vp_BFu7i_BFu8i()
{
  {
    init_simple_test("Vp_BFu7i_BFu8i");
    static STRUCT_IF_C Vp_BFu7i_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, 1, "Vp_BFu7i_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, hide_ull(1LL<<7), "Vp_BFu7i_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu8i, Vp_BFu7i_BFu8i)
//============================================================================


struct  Vp_BFu7i_BFu8ll  {
  void *v1;
  unsigned int v2:7;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu7i_BFu8ll) C1{ Fp Fi:7 FL:8}



static void Test_Vp_BFu7i_BFu8ll()
{
  {
    init_simple_test("Vp_BFu7i_BFu8ll");
    static STRUCT_IF_C Vp_BFu7i_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, 1, "Vp_BFu7i_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, hide_ull(1LL<<7), "Vp_BFu7i_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu8ll, Vp_BFu7i_BFu8ll)
//============================================================================


struct  Vp_BFu7i_BFu8s  {
  void *v1;
  unsigned int v2:7;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu7i_BFu8s) C1{ Fp Fi:7 Fs:8}



static void Test_Vp_BFu7i_BFu8s()
{
  {
    init_simple_test("Vp_BFu7i_BFu8s");
    static STRUCT_IF_C Vp_BFu7i_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, 1, "Vp_BFu7i_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, hide_ull(1LL<<7), "Vp_BFu7i_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu8s, Vp_BFu7i_BFu8s)
//============================================================================


struct  Vp_BFu7i_BFu9i  {
  void *v1;
  unsigned int v2:7;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu7i_BFu9i) C1{ Fp Fi:7 Fi:9}



static void Test_Vp_BFu7i_BFu9i()
{
  {
    init_simple_test("Vp_BFu7i_BFu9i");
    static STRUCT_IF_C Vp_BFu7i_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, 1, "Vp_BFu7i_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, hide_ull(1LL<<8), "Vp_BFu7i_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu9i, Vp_BFu7i_BFu9i)
//============================================================================


struct  Vp_BFu7i_BFu9ll  {
  void *v1;
  unsigned int v2:7;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu7i_BFu9ll) C1{ Fp Fi:7 FL:9}



static void Test_Vp_BFu7i_BFu9ll()
{
  {
    init_simple_test("Vp_BFu7i_BFu9ll");
    static STRUCT_IF_C Vp_BFu7i_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, 1, "Vp_BFu7i_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, hide_ull(1LL<<8), "Vp_BFu7i_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu9ll, Vp_BFu7i_BFu9ll)
//============================================================================


struct  Vp_BFu7i_BFu9s  {
  void *v1;
  unsigned int v2:7;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu7i_BFu9s) C1{ Fp Fi:7 Fs:9}



static void Test_Vp_BFu7i_BFu9s()
{
  {
    init_simple_test("Vp_BFu7i_BFu9s");
    static STRUCT_IF_C Vp_BFu7i_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, 1, "Vp_BFu7i_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, hide_ull(1LL<<8), "Vp_BFu7i_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_BFu9s, Vp_BFu7i_BFu9s)
//============================================================================


struct  Vp_BFu7i_C  {
  void *v1;
  unsigned int v2:7;
  char v3;
};
//SIG(1 Vp_BFu7i_C) C1{ Fp Fi:7 Fc}



static void Test_Vp_BFu7i_C()
{
  {
    init_simple_test("Vp_BFu7i_C");
    static STRUCT_IF_C Vp_BFu7i_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_C");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7i_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_C, Vp_BFu7i_C)
//============================================================================


struct  Vp_BFu7i_D  {
  void *v1;
  unsigned int v2:7;
  double v3;
};
//SIG(1 Vp_BFu7i_D) C1{ Fp Fi:7 FL}



static void Test_Vp_BFu7i_D()
{
  {
    init_simple_test("Vp_BFu7i_D");
    static STRUCT_IF_C Vp_BFu7i_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu7i_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_D");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7i_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_D, Vp_BFu7i_D)
//============================================================================


struct  Vp_BFu7i_F  {
  void *v1;
  unsigned int v2:7;
  float v3;
};
//SIG(1 Vp_BFu7i_F) C1{ Fp Fi:7 Fi}



static void Test_Vp_BFu7i_F()
{
  {
    init_simple_test("Vp_BFu7i_F");
    static STRUCT_IF_C Vp_BFu7i_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7i_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_F");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu7i_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_F, Vp_BFu7i_F)
//============================================================================


struct  Vp_BFu7i_I  {
  void *v1;
  unsigned int v2:7;
  int v3;
};
//SIG(1 Vp_BFu7i_I) C1{ Fp Fi:7 Fi}



static void Test_Vp_BFu7i_I()
{
  {
    init_simple_test("Vp_BFu7i_I");
    static STRUCT_IF_C Vp_BFu7i_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7i_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_I");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu7i_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_I, Vp_BFu7i_I)
//============================================================================


struct  Vp_BFu7i_Ip  {
  void *v1;
  unsigned int v2:7;
  int *v3;
};
//SIG(1 Vp_BFu7i_Ip) C1{ Fp Fi:7 Fp}



static void Test_Vp_BFu7i_Ip()
{
  {
    init_simple_test("Vp_BFu7i_Ip");
    static STRUCT_IF_C Vp_BFu7i_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu7i_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_Ip");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7i_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_Ip, Vp_BFu7i_Ip)
//============================================================================


struct  Vp_BFu7i_L  {
  void *v1;
  unsigned int v2:7;
  __tsi64 v3;
};
//SIG(1 Vp_BFu7i_L) C1{ Fp Fi:7 FL}



static void Test_Vp_BFu7i_L()
{
  {
    init_simple_test("Vp_BFu7i_L");
    static STRUCT_IF_C Vp_BFu7i_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu7i_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_L");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7i_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_L, Vp_BFu7i_L)
//============================================================================


struct  Vp_BFu7i_S  {
  void *v1;
  unsigned int v2:7;
  short v3;
};
//SIG(1 Vp_BFu7i_S) C1{ Fp Fi:7 Fs}



static void Test_Vp_BFu7i_S()
{
  {
    init_simple_test("Vp_BFu7i_S");
    static STRUCT_IF_C Vp_BFu7i_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_S");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu7i_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_S, Vp_BFu7i_S)
//============================================================================


struct  Vp_BFu7i_Uc  {
  void *v1;
  unsigned int v2:7;
  unsigned char v3;
};
//SIG(1 Vp_BFu7i_Uc) C1{ Fp Fi:7 Fc}



static void Test_Vp_BFu7i_Uc()
{
  {
    init_simple_test("Vp_BFu7i_Uc");
    static STRUCT_IF_C Vp_BFu7i_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_Uc");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7i_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_Uc, Vp_BFu7i_Uc)
//============================================================================


struct  Vp_BFu7i_Ui  {
  void *v1;
  unsigned int v2:7;
  unsigned int v3;
};
//SIG(1 Vp_BFu7i_Ui) C1{ Fp Fi:7 Fi}



static void Test_Vp_BFu7i_Ui()
{
  {
    init_simple_test("Vp_BFu7i_Ui");
    static STRUCT_IF_C Vp_BFu7i_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7i_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_Ui");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu7i_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_Ui, Vp_BFu7i_Ui)
//============================================================================


struct  Vp_BFu7i_Ul  {
  void *v1;
  unsigned int v2:7;
  __tsu64 v3;
};
//SIG(1 Vp_BFu7i_Ul) C1{ Fp Fi:7 FL}



static void Test_Vp_BFu7i_Ul()
{
  {
    init_simple_test("Vp_BFu7i_Ul");
    static STRUCT_IF_C Vp_BFu7i_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu7i_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_Ul");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7i_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_Ul, Vp_BFu7i_Ul)
//============================================================================


struct  Vp_BFu7i_Us  {
  void *v1;
  unsigned int v2:7;
  unsigned short v3;
};
//SIG(1 Vp_BFu7i_Us) C1{ Fp Fi:7 Fs}



static void Test_Vp_BFu7i_Us()
{
  {
    init_simple_test("Vp_BFu7i_Us");
    static STRUCT_IF_C Vp_BFu7i_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7i_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_Us");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu7i_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_Us, Vp_BFu7i_Us)
//============================================================================


struct  Vp_BFu7i_Vp  {
  void *v1;
  unsigned int v2:7;
  void *v3;
};
//SIG(1 Vp_BFu7i_Vp) C1{ Fp Fi:7 Fp}



static void Test_Vp_BFu7i_Vp()
{
  {
    init_simple_test("Vp_BFu7i_Vp");
    static STRUCT_IF_C Vp_BFu7i_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu7i_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7i_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu7i_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7i_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7i_Vp");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7i_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7i_Vp, Vp_BFu7i_Vp)
//============================================================================


struct  Vp_BFu7ll  {
  void *v1;
  __tsu64 v2:7;
};
//SIG(1 Vp_BFu7ll) C1{ Fp FL:7}



static void Test_Vp_BFu7ll()
{
  {
    init_simple_test("Vp_BFu7ll");
    static STRUCT_IF_C Vp_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll, Vp_BFu7ll)
//============================================================================


struct  Vp_BFu7ll_BFu15i  {
  void *v1;
  __tsu64 v2:7;
  unsigned int v3:15;
};
//SIG(1 Vp_BFu7ll_BFu15i) C1{ Fp FL:7 Fi:15}



static void Test_Vp_BFu7ll_BFu15i()
{
  {
    init_simple_test("Vp_BFu7ll_BFu15i");
    static STRUCT_IF_C Vp_BFu7ll_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, 1, "Vp_BFu7ll_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, hide_ull(1LL<<14), "Vp_BFu7ll_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu15i, Vp_BFu7ll_BFu15i)
//============================================================================


struct  Vp_BFu7ll_BFu15ll  {
  void *v1;
  __tsu64 v2:7;
  __tsu64 v3:15;
};
//SIG(1 Vp_BFu7ll_BFu15ll) C1{ Fp FL:7 FL:15}



static void Test_Vp_BFu7ll_BFu15ll()
{
  {
    init_simple_test("Vp_BFu7ll_BFu15ll");
    static STRUCT_IF_C Vp_BFu7ll_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, 1, "Vp_BFu7ll_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, hide_ull(1LL<<14), "Vp_BFu7ll_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu15ll, Vp_BFu7ll_BFu15ll)
//============================================================================


struct  Vp_BFu7ll_BFu15s  {
  void *v1;
  __tsu64 v2:7;
  unsigned short v3:15;
};
//SIG(1 Vp_BFu7ll_BFu15s) C1{ Fp FL:7 Fs:15}



static void Test_Vp_BFu7ll_BFu15s()
{
  {
    init_simple_test("Vp_BFu7ll_BFu15s");
    static STRUCT_IF_C Vp_BFu7ll_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_BFu7ll_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_BFu7ll_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu15s, Vp_BFu7ll_BFu15s)
//============================================================================


struct  Vp_BFu7ll_BFu16i  {
  void *v1;
  __tsu64 v2:7;
  unsigned int v3:16;
};
//SIG(1 Vp_BFu7ll_BFu16i) C1{ Fp FL:7 Fi:16}



static void Test_Vp_BFu7ll_BFu16i()
{
  {
    init_simple_test("Vp_BFu7ll_BFu16i");
    static STRUCT_IF_C Vp_BFu7ll_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, 1, "Vp_BFu7ll_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, hide_ull(1LL<<15), "Vp_BFu7ll_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu16i, Vp_BFu7ll_BFu16i)
//============================================================================


struct  Vp_BFu7ll_BFu16ll  {
  void *v1;
  __tsu64 v2:7;
  __tsu64 v3:16;
};
//SIG(1 Vp_BFu7ll_BFu16ll) C1{ Fp FL:7 FL:16}



static void Test_Vp_BFu7ll_BFu16ll()
{
  {
    init_simple_test("Vp_BFu7ll_BFu16ll");
    static STRUCT_IF_C Vp_BFu7ll_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, 1, "Vp_BFu7ll_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, hide_ull(1LL<<15), "Vp_BFu7ll_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu16ll, Vp_BFu7ll_BFu16ll)
//============================================================================


struct  Vp_BFu7ll_BFu16s  {
  void *v1;
  __tsu64 v2:7;
  unsigned short v3:16;
};
//SIG(1 Vp_BFu7ll_BFu16s) C1{ Fp FL:7 Fs:16}



static void Test_Vp_BFu7ll_BFu16s()
{
  {
    init_simple_test("Vp_BFu7ll_BFu16s");
    static STRUCT_IF_C Vp_BFu7ll_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_BFu7ll_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_BFu7ll_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu16s, Vp_BFu7ll_BFu16s)
//============================================================================


struct  Vp_BFu7ll_BFu17i  {
  void *v1;
  __tsu64 v2:7;
  unsigned int v3:17;
};
//SIG(1 Vp_BFu7ll_BFu17i) C1{ Fp FL:7 Fi:17}



static void Test_Vp_BFu7ll_BFu17i()
{
  {
    init_simple_test("Vp_BFu7ll_BFu17i");
    static STRUCT_IF_C Vp_BFu7ll_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, 1, "Vp_BFu7ll_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, hide_ull(1LL<<16), "Vp_BFu7ll_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu17i, Vp_BFu7ll_BFu17i)
//============================================================================


struct  Vp_BFu7ll_BFu17ll  {
  void *v1;
  __tsu64 v2:7;
  __tsu64 v3:17;
};
//SIG(1 Vp_BFu7ll_BFu17ll) C1{ Fp FL:7 FL:17}



static void Test_Vp_BFu7ll_BFu17ll()
{
  {
    init_simple_test("Vp_BFu7ll_BFu17ll");
    static STRUCT_IF_C Vp_BFu7ll_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, 1, "Vp_BFu7ll_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, hide_ull(1LL<<16), "Vp_BFu7ll_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu17ll, Vp_BFu7ll_BFu17ll)
//============================================================================


struct  Vp_BFu7ll_BFu1c  {
  void *v1;
  __tsu64 v2:7;
  unsigned char v3:1;
};
//SIG(1 Vp_BFu7ll_BFu1c) C1{ Fp FL:7 Fc:1}



static void Test_Vp_BFu7ll_BFu1c()
{
  {
    init_simple_test("Vp_BFu7ll_BFu1c");
    static STRUCT_IF_C Vp_BFu7ll_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu1c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu1c");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7ll_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu1c, Vp_BFu7ll_BFu1c)
//============================================================================


struct  Vp_BFu7ll_BFu1i  {
  void *v1;
  __tsu64 v2:7;
  unsigned int v3:1;
};
//SIG(1 Vp_BFu7ll_BFu1i) C1{ Fp FL:7 Fi:1}



static void Test_Vp_BFu7ll_BFu1i()
{
  {
    init_simple_test("Vp_BFu7ll_BFu1i");
    static STRUCT_IF_C Vp_BFu7ll_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu1i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu1i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7ll_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu1i, Vp_BFu7ll_BFu1i)
//============================================================================


struct  Vp_BFu7ll_BFu1ll  {
  void *v1;
  __tsu64 v2:7;
  __tsu64 v3:1;
};
//SIG(1 Vp_BFu7ll_BFu1ll) C1{ Fp FL:7 FL:1}



static void Test_Vp_BFu7ll_BFu1ll()
{
  {
    init_simple_test("Vp_BFu7ll_BFu1ll");
    static STRUCT_IF_C Vp_BFu7ll_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu1ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu1ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7ll_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu1ll, Vp_BFu7ll_BFu1ll)
//============================================================================


struct  Vp_BFu7ll_BFu1s  {
  void *v1;
  __tsu64 v2:7;
  unsigned short v3:1;
};
//SIG(1 Vp_BFu7ll_BFu1s) C1{ Fp FL:7 Fs:1}



static void Test_Vp_BFu7ll_BFu1s()
{
  {
    init_simple_test("Vp_BFu7ll_BFu1s");
    static STRUCT_IF_C Vp_BFu7ll_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu1s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu1s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7ll_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu1s, Vp_BFu7ll_BFu1s)
//============================================================================


struct  Vp_BFu7ll_BFu31i  {
  void *v1;
  __tsu64 v2:7;
  unsigned int v3:31;
};
//SIG(1 Vp_BFu7ll_BFu31i) C1{ Fp FL:7 Fi:31}



static void Test_Vp_BFu7ll_BFu31i()
{
  {
    init_simple_test("Vp_BFu7ll_BFu31i");
    static STRUCT_IF_C Vp_BFu7ll_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7ll_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_BFu7ll_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_BFu7ll_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu31i, Vp_BFu7ll_BFu31i)
//============================================================================


struct  Vp_BFu7ll_BFu31ll  {
  void *v1;
  __tsu64 v2:7;
  __tsu64 v3:31;
};
//SIG(1 Vp_BFu7ll_BFu31ll) C1{ Fp FL:7 FL:31}



static void Test_Vp_BFu7ll_BFu31ll()
{
  {
    init_simple_test("Vp_BFu7ll_BFu31ll");
    static STRUCT_IF_C Vp_BFu7ll_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7ll_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 31, 1, "Vp_BFu7ll_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 31, hide_ull(1LL<<30), "Vp_BFu7ll_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu31ll, Vp_BFu7ll_BFu31ll)
//============================================================================


struct  Vp_BFu7ll_BFu32i  {
  void *v1;
  __tsu64 v2:7;
  unsigned int v3:32;
};
//SIG(1 Vp_BFu7ll_BFu32i) C1{ Fp FL:7 Fi:32}



static void Test_Vp_BFu7ll_BFu32i()
{
  {
    init_simple_test("Vp_BFu7ll_BFu32i");
    static STRUCT_IF_C Vp_BFu7ll_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7ll_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_BFu7ll_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_BFu7ll_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu32i, Vp_BFu7ll_BFu32i)
//============================================================================


struct  Vp_BFu7ll_BFu32ll  {
  void *v1;
  __tsu64 v2:7;
  __tsu64 v3:32;
};
//SIG(1 Vp_BFu7ll_BFu32ll) C1{ Fp FL:7 FL:32}



static void Test_Vp_BFu7ll_BFu32ll()
{
  {
    init_simple_test("Vp_BFu7ll_BFu32ll");
    static STRUCT_IF_C Vp_BFu7ll_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7ll_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 32, 1, "Vp_BFu7ll_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 32, hide_ull(1LL<<31), "Vp_BFu7ll_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu32ll, Vp_BFu7ll_BFu32ll)
//============================================================================


struct  Vp_BFu7ll_BFu33  {
  void *v1;
  __tsu64 v2:7;
  __tsu64 v3:33;
};
//SIG(1 Vp_BFu7ll_BFu33) C1{ Fp FL:7 FL:33}



static void Test_Vp_BFu7ll_BFu33()
{
  {
    init_simple_test("Vp_BFu7ll_BFu33");
    static STRUCT_IF_C Vp_BFu7ll_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7ll_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 33, 1, "Vp_BFu7ll_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 33, hide_ull(1LL<<32), "Vp_BFu7ll_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu33, Vp_BFu7ll_BFu33)
//============================================================================


struct  Vp_BFu7ll_BFu7c  {
  void *v1;
  __tsu64 v2:7;
  unsigned char v3:7;
};
//SIG(1 Vp_BFu7ll_BFu7c) C1{ Fp FL:7 Fc:7}



static void Test_Vp_BFu7ll_BFu7c()
{
  {
    init_simple_test("Vp_BFu7ll_BFu7c");
    static STRUCT_IF_C Vp_BFu7ll_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu7ll_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu7c, Vp_BFu7ll_BFu7c)
//============================================================================


struct  Vp_BFu7ll_BFu7i  {
  void *v1;
  __tsu64 v2:7;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu7ll_BFu7i) C1{ Fp FL:7 Fi:7}



static void Test_Vp_BFu7ll_BFu7i()
{
  {
    init_simple_test("Vp_BFu7ll_BFu7i");
    static STRUCT_IF_C Vp_BFu7ll_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, 1, "Vp_BFu7ll_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu7i, Vp_BFu7ll_BFu7i)
//============================================================================


struct  Vp_BFu7ll_BFu7ll  {
  void *v1;
  __tsu64 v2:7;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu7ll_BFu7ll) C1{ Fp FL:7 FL:7}



static void Test_Vp_BFu7ll_BFu7ll()
{
  {
    init_simple_test("Vp_BFu7ll_BFu7ll");
    static STRUCT_IF_C Vp_BFu7ll_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, 1, "Vp_BFu7ll_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu7ll, Vp_BFu7ll_BFu7ll)
//============================================================================


struct  Vp_BFu7ll_BFu7s  {
  void *v1;
  __tsu64 v2:7;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu7ll_BFu7s) C1{ Fp FL:7 Fs:7}



static void Test_Vp_BFu7ll_BFu7s()
{
  {
    init_simple_test("Vp_BFu7ll_BFu7s");
    static STRUCT_IF_C Vp_BFu7ll_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, 1, "Vp_BFu7ll_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu7s, Vp_BFu7ll_BFu7s)
//============================================================================


struct  Vp_BFu7ll_BFu8c  {
  void *v1;
  __tsu64 v2:7;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu7ll_BFu8c) C1{ Fp FL:7 Fc:8}



static void Test_Vp_BFu7ll_BFu8c()
{
  {
    init_simple_test("Vp_BFu7ll_BFu8c");
    static STRUCT_IF_C Vp_BFu7ll_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu7ll_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu7ll_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu8c, Vp_BFu7ll_BFu8c)
//============================================================================


struct  Vp_BFu7ll_BFu8i  {
  void *v1;
  __tsu64 v2:7;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu7ll_BFu8i) C1{ Fp FL:7 Fi:8}



static void Test_Vp_BFu7ll_BFu8i()
{
  {
    init_simple_test("Vp_BFu7ll_BFu8i");
    static STRUCT_IF_C Vp_BFu7ll_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, 1, "Vp_BFu7ll_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, hide_ull(1LL<<7), "Vp_BFu7ll_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu8i, Vp_BFu7ll_BFu8i)
//============================================================================


struct  Vp_BFu7ll_BFu8ll  {
  void *v1;
  __tsu64 v2:7;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu7ll_BFu8ll) C1{ Fp FL:7 FL:8}



static void Test_Vp_BFu7ll_BFu8ll()
{
  {
    init_simple_test("Vp_BFu7ll_BFu8ll");
    static STRUCT_IF_C Vp_BFu7ll_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, 1, "Vp_BFu7ll_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, hide_ull(1LL<<7), "Vp_BFu7ll_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu8ll, Vp_BFu7ll_BFu8ll)
//============================================================================


struct  Vp_BFu7ll_BFu8s  {
  void *v1;
  __tsu64 v2:7;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu7ll_BFu8s) C1{ Fp FL:7 Fs:8}



static void Test_Vp_BFu7ll_BFu8s()
{
  {
    init_simple_test("Vp_BFu7ll_BFu8s");
    static STRUCT_IF_C Vp_BFu7ll_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, 1, "Vp_BFu7ll_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, hide_ull(1LL<<7), "Vp_BFu7ll_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu8s, Vp_BFu7ll_BFu8s)
//============================================================================


struct  Vp_BFu7ll_BFu9i  {
  void *v1;
  __tsu64 v2:7;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu7ll_BFu9i) C1{ Fp FL:7 Fi:9}



static void Test_Vp_BFu7ll_BFu9i()
{
  {
    init_simple_test("Vp_BFu7ll_BFu9i");
    static STRUCT_IF_C Vp_BFu7ll_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, 1, "Vp_BFu7ll_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, hide_ull(1LL<<8), "Vp_BFu7ll_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu9i, Vp_BFu7ll_BFu9i)
//============================================================================


struct  Vp_BFu7ll_BFu9ll  {
  void *v1;
  __tsu64 v2:7;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu7ll_BFu9ll) C1{ Fp FL:7 FL:9}



static void Test_Vp_BFu7ll_BFu9ll()
{
  {
    init_simple_test("Vp_BFu7ll_BFu9ll");
    static STRUCT_IF_C Vp_BFu7ll_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, 1, "Vp_BFu7ll_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, hide_ull(1LL<<8), "Vp_BFu7ll_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu9ll, Vp_BFu7ll_BFu9ll)
//============================================================================


struct  Vp_BFu7ll_BFu9s  {
  void *v1;
  __tsu64 v2:7;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu7ll_BFu9s) C1{ Fp FL:7 Fs:9}



static void Test_Vp_BFu7ll_BFu9s()
{
  {
    init_simple_test("Vp_BFu7ll_BFu9s");
    static STRUCT_IF_C Vp_BFu7ll_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, 1, "Vp_BFu7ll_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, hide_ull(1LL<<8), "Vp_BFu7ll_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_BFu9s, Vp_BFu7ll_BFu9s)
//============================================================================


struct  Vp_BFu7ll_C  {
  void *v1;
  __tsu64 v2:7;
  char v3;
};
//SIG(1 Vp_BFu7ll_C) C1{ Fp FL:7 Fc}



static void Test_Vp_BFu7ll_C()
{
  {
    init_simple_test("Vp_BFu7ll_C");
    static STRUCT_IF_C Vp_BFu7ll_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_C");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7ll_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_C, Vp_BFu7ll_C)
//============================================================================


struct  Vp_BFu7ll_D  {
  void *v1;
  __tsu64 v2:7;
  double v3;
};
//SIG(1 Vp_BFu7ll_D) C1{ Fp FL:7 FL}



static void Test_Vp_BFu7ll_D()
{
  {
    init_simple_test("Vp_BFu7ll_D");
    static STRUCT_IF_C Vp_BFu7ll_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu7ll_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_D");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7ll_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_D, Vp_BFu7ll_D)
//============================================================================


struct  Vp_BFu7ll_F  {
  void *v1;
  __tsu64 v2:7;
  float v3;
};
//SIG(1 Vp_BFu7ll_F) C1{ Fp FL:7 Fi}



static void Test_Vp_BFu7ll_F()
{
  {
    init_simple_test("Vp_BFu7ll_F");
    static STRUCT_IF_C Vp_BFu7ll_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7ll_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_F");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu7ll_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_F, Vp_BFu7ll_F)
//============================================================================


struct  Vp_BFu7ll_I  {
  void *v1;
  __tsu64 v2:7;
  int v3;
};
//SIG(1 Vp_BFu7ll_I) C1{ Fp FL:7 Fi}



static void Test_Vp_BFu7ll_I()
{
  {
    init_simple_test("Vp_BFu7ll_I");
    static STRUCT_IF_C Vp_BFu7ll_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7ll_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_I");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu7ll_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_I, Vp_BFu7ll_I)
//============================================================================


struct  Vp_BFu7ll_Ip  {
  void *v1;
  __tsu64 v2:7;
  int *v3;
};
//SIG(1 Vp_BFu7ll_Ip) C1{ Fp FL:7 Fp}



static void Test_Vp_BFu7ll_Ip()
{
  {
    init_simple_test("Vp_BFu7ll_Ip");
    static STRUCT_IF_C Vp_BFu7ll_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu7ll_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_Ip");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7ll_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_Ip, Vp_BFu7ll_Ip)
//============================================================================


struct  Vp_BFu7ll_L  {
  void *v1;
  __tsu64 v2:7;
  __tsi64 v3;
};
//SIG(1 Vp_BFu7ll_L) C1{ Fp FL:7 FL}



static void Test_Vp_BFu7ll_L()
{
  {
    init_simple_test("Vp_BFu7ll_L");
    static STRUCT_IF_C Vp_BFu7ll_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu7ll_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_L");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7ll_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_L, Vp_BFu7ll_L)
//============================================================================


struct  Vp_BFu7ll_S  {
  void *v1;
  __tsu64 v2:7;
  short v3;
};
//SIG(1 Vp_BFu7ll_S) C1{ Fp FL:7 Fs}



static void Test_Vp_BFu7ll_S()
{
  {
    init_simple_test("Vp_BFu7ll_S");
    static STRUCT_IF_C Vp_BFu7ll_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_S");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu7ll_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_S, Vp_BFu7ll_S)
//============================================================================


struct  Vp_BFu7ll_Uc  {
  void *v1;
  __tsu64 v2:7;
  unsigned char v3;
};
//SIG(1 Vp_BFu7ll_Uc) C1{ Fp FL:7 Fc}



static void Test_Vp_BFu7ll_Uc()
{
  {
    init_simple_test("Vp_BFu7ll_Uc");
    static STRUCT_IF_C Vp_BFu7ll_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_Uc");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7ll_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_Uc, Vp_BFu7ll_Uc)
//============================================================================


struct  Vp_BFu7ll_Ui  {
  void *v1;
  __tsu64 v2:7;
  unsigned int v3;
};
//SIG(1 Vp_BFu7ll_Ui) C1{ Fp FL:7 Fi}



static void Test_Vp_BFu7ll_Ui()
{
  {
    init_simple_test("Vp_BFu7ll_Ui");
    static STRUCT_IF_C Vp_BFu7ll_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7ll_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_Ui");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu7ll_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_Ui, Vp_BFu7ll_Ui)
//============================================================================


struct  Vp_BFu7ll_Ul  {
  void *v1;
  __tsu64 v2:7;
  __tsu64 v3;
};
//SIG(1 Vp_BFu7ll_Ul) C1{ Fp FL:7 FL}



static void Test_Vp_BFu7ll_Ul()
{
  {
    init_simple_test("Vp_BFu7ll_Ul");
    static STRUCT_IF_C Vp_BFu7ll_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu7ll_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_Ul");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7ll_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_Ul, Vp_BFu7ll_Ul)
//============================================================================


struct  Vp_BFu7ll_Us  {
  void *v1;
  __tsu64 v2:7;
  unsigned short v3;
};
//SIG(1 Vp_BFu7ll_Us) C1{ Fp FL:7 Fs}



static void Test_Vp_BFu7ll_Us()
{
  {
    init_simple_test("Vp_BFu7ll_Us");
    static STRUCT_IF_C Vp_BFu7ll_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7ll_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_Us");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu7ll_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_Us, Vp_BFu7ll_Us)
//============================================================================


struct  Vp_BFu7ll_Vp  {
  void *v1;
  __tsu64 v2:7;
  void *v3;
};
//SIG(1 Vp_BFu7ll_Vp) C1{ Fp FL:7 Fp}



static void Test_Vp_BFu7ll_Vp()
{
  {
    init_simple_test("Vp_BFu7ll_Vp");
    static STRUCT_IF_C Vp_BFu7ll_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu7ll_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7ll_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu7ll_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7ll_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7ll_Vp");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7ll_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7ll_Vp, Vp_BFu7ll_Vp)
//============================================================================


struct  Vp_BFu7s  {
  void *v1;
  unsigned short v2:7;
};
//SIG(1 Vp_BFu7s) C1{ Fp Fs:7}



static void Test_Vp_BFu7s()
{
  {
    init_simple_test("Vp_BFu7s");
    static STRUCT_IF_C Vp_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s, Vp_BFu7s)
//============================================================================


struct  Vp_BFu7s_BFu15i  {
  void *v1;
  unsigned short v2:7;
  unsigned int v3:15;
};
//SIG(1 Vp_BFu7s_BFu15i) C1{ Fp Fs:7 Fi:15}



static void Test_Vp_BFu7s_BFu15i()
{
  {
    init_simple_test("Vp_BFu7s_BFu15i");
    static STRUCT_IF_C Vp_BFu7s_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, 1, "Vp_BFu7s_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, hide_ull(1LL<<14), "Vp_BFu7s_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu15i, Vp_BFu7s_BFu15i)
//============================================================================


struct  Vp_BFu7s_BFu15ll  {
  void *v1;
  unsigned short v2:7;
  __tsu64 v3:15;
};
//SIG(1 Vp_BFu7s_BFu15ll) C1{ Fp Fs:7 FL:15}



static void Test_Vp_BFu7s_BFu15ll()
{
  {
    init_simple_test("Vp_BFu7s_BFu15ll");
    static STRUCT_IF_C Vp_BFu7s_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, 1, "Vp_BFu7s_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 15, hide_ull(1LL<<14), "Vp_BFu7s_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu15ll, Vp_BFu7s_BFu15ll)
//============================================================================


struct  Vp_BFu7s_BFu15s  {
  void *v1;
  unsigned short v2:7;
  unsigned short v3:15;
};
//SIG(1 Vp_BFu7s_BFu15s) C1{ Fp Fs:7 Fs:15}



static void Test_Vp_BFu7s_BFu15s()
{
  {
    init_simple_test("Vp_BFu7s_BFu15s");
    static STRUCT_IF_C Vp_BFu7s_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_BFu7s_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_BFu7s_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu15s, Vp_BFu7s_BFu15s)
//============================================================================


struct  Vp_BFu7s_BFu16i  {
  void *v1;
  unsigned short v2:7;
  unsigned int v3:16;
};
//SIG(1 Vp_BFu7s_BFu16i) C1{ Fp Fs:7 Fi:16}



static void Test_Vp_BFu7s_BFu16i()
{
  {
    init_simple_test("Vp_BFu7s_BFu16i");
    static STRUCT_IF_C Vp_BFu7s_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, 1, "Vp_BFu7s_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, hide_ull(1LL<<15), "Vp_BFu7s_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu16i, Vp_BFu7s_BFu16i)
//============================================================================


struct  Vp_BFu7s_BFu16ll  {
  void *v1;
  unsigned short v2:7;
  __tsu64 v3:16;
};
//SIG(1 Vp_BFu7s_BFu16ll) C1{ Fp Fs:7 FL:16}



static void Test_Vp_BFu7s_BFu16ll()
{
  {
    init_simple_test("Vp_BFu7s_BFu16ll");
    static STRUCT_IF_C Vp_BFu7s_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, 1, "Vp_BFu7s_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 16, hide_ull(1LL<<15), "Vp_BFu7s_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu16ll, Vp_BFu7s_BFu16ll)
//============================================================================


struct  Vp_BFu7s_BFu16s  {
  void *v1;
  unsigned short v2:7;
  unsigned short v3:16;
};
//SIG(1 Vp_BFu7s_BFu16s) C1{ Fp Fs:7 Fs:16}



static void Test_Vp_BFu7s_BFu16s()
{
  {
    init_simple_test("Vp_BFu7s_BFu16s");
    static STRUCT_IF_C Vp_BFu7s_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_BFu7s_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_BFu7s_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu16s, Vp_BFu7s_BFu16s)
//============================================================================


struct  Vp_BFu7s_BFu17i  {
  void *v1;
  unsigned short v2:7;
  unsigned int v3:17;
};
//SIG(1 Vp_BFu7s_BFu17i) C1{ Fp Fs:7 Fi:17}



static void Test_Vp_BFu7s_BFu17i()
{
  {
    init_simple_test("Vp_BFu7s_BFu17i");
    static STRUCT_IF_C Vp_BFu7s_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, 1, "Vp_BFu7s_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, hide_ull(1LL<<16), "Vp_BFu7s_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu17i, Vp_BFu7s_BFu17i)
//============================================================================


struct  Vp_BFu7s_BFu17ll  {
  void *v1;
  unsigned short v2:7;
  __tsu64 v3:17;
};
//SIG(1 Vp_BFu7s_BFu17ll) C1{ Fp Fs:7 FL:17}



static void Test_Vp_BFu7s_BFu17ll()
{
  {
    init_simple_test("Vp_BFu7s_BFu17ll");
    static STRUCT_IF_C Vp_BFu7s_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, 1, "Vp_BFu7s_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 17, hide_ull(1LL<<16), "Vp_BFu7s_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu17ll, Vp_BFu7s_BFu17ll)
//============================================================================


struct  Vp_BFu7s_BFu1c  {
  void *v1;
  unsigned short v2:7;
  unsigned char v3:1;
};
//SIG(1 Vp_BFu7s_BFu1c) C1{ Fp Fs:7 Fc:1}



static void Test_Vp_BFu7s_BFu1c()
{
  {
    init_simple_test("Vp_BFu7s_BFu1c");
    static STRUCT_IF_C Vp_BFu7s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu1c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu1c");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7s_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu1c, Vp_BFu7s_BFu1c)
//============================================================================


struct  Vp_BFu7s_BFu1i  {
  void *v1;
  unsigned short v2:7;
  unsigned int v3:1;
};
//SIG(1 Vp_BFu7s_BFu1i) C1{ Fp Fs:7 Fi:1}



static void Test_Vp_BFu7s_BFu1i()
{
  {
    init_simple_test("Vp_BFu7s_BFu1i");
    static STRUCT_IF_C Vp_BFu7s_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu1i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu1i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7s_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu1i, Vp_BFu7s_BFu1i)
//============================================================================


struct  Vp_BFu7s_BFu1ll  {
  void *v1;
  unsigned short v2:7;
  __tsu64 v3:1;
};
//SIG(1 Vp_BFu7s_BFu1ll) C1{ Fp Fs:7 FL:1}



static void Test_Vp_BFu7s_BFu1ll()
{
  {
    init_simple_test("Vp_BFu7s_BFu1ll");
    static STRUCT_IF_C Vp_BFu7s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu1ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu1ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7s_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu1ll, Vp_BFu7s_BFu1ll)
//============================================================================


struct  Vp_BFu7s_BFu1s  {
  void *v1;
  unsigned short v2:7;
  unsigned short v3:1;
};
//SIG(1 Vp_BFu7s_BFu1s) C1{ Fp Fs:7 Fs:1}



static void Test_Vp_BFu7s_BFu1s()
{
  {
    init_simple_test("Vp_BFu7s_BFu1s");
    static STRUCT_IF_C Vp_BFu7s_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu1s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu1s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 1, 1, "Vp_BFu7s_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu1s, Vp_BFu7s_BFu1s)
//============================================================================


struct  Vp_BFu7s_BFu31i  {
  void *v1;
  unsigned short v2:7;
  unsigned int v3:31;
};
//SIG(1 Vp_BFu7s_BFu31i) C1{ Fp Fs:7 Fi:31}



static void Test_Vp_BFu7s_BFu31i()
{
  {
    init_simple_test("Vp_BFu7s_BFu31i");
    static STRUCT_IF_C Vp_BFu7s_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7s_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_BFu7s_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_BFu7s_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu31i, Vp_BFu7s_BFu31i)
//============================================================================


struct  Vp_BFu7s_BFu31ll  {
  void *v1;
  unsigned short v2:7;
  __tsu64 v3:31;
};
//SIG(1 Vp_BFu7s_BFu31ll) C1{ Fp Fs:7 FL:31}



static void Test_Vp_BFu7s_BFu31ll()
{
  {
    init_simple_test("Vp_BFu7s_BFu31ll");
    static STRUCT_IF_C Vp_BFu7s_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 31, 1, "Vp_BFu7s_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 31, hide_ull(1LL<<30), "Vp_BFu7s_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu31ll, Vp_BFu7s_BFu31ll)
//============================================================================


struct  Vp_BFu7s_BFu32i  {
  void *v1;
  unsigned short v2:7;
  unsigned int v3:32;
};
//SIG(1 Vp_BFu7s_BFu32i) C1{ Fp Fs:7 Fi:32}



static void Test_Vp_BFu7s_BFu32i()
{
  {
    init_simple_test("Vp_BFu7s_BFu32i");
    static STRUCT_IF_C Vp_BFu7s_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7s_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_BFu7s_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_BFu7s_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu32i, Vp_BFu7s_BFu32i)
//============================================================================


struct  Vp_BFu7s_BFu32ll  {
  void *v1;
  unsigned short v2:7;
  __tsu64 v3:32;
};
//SIG(1 Vp_BFu7s_BFu32ll) C1{ Fp Fs:7 FL:32}



static void Test_Vp_BFu7s_BFu32ll()
{
  {
    init_simple_test("Vp_BFu7s_BFu32ll");
    static STRUCT_IF_C Vp_BFu7s_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 32, 1, "Vp_BFu7s_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 32, hide_ull(1LL<<31), "Vp_BFu7s_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu32ll, Vp_BFu7s_BFu32ll)
//============================================================================


struct  Vp_BFu7s_BFu33  {
  void *v1;
  unsigned short v2:7;
  __tsu64 v3:33;
};
//SIG(1 Vp_BFu7s_BFu33) C1{ Fp Fs:7 FL:33}



static void Test_Vp_BFu7s_BFu33()
{
  {
    init_simple_test("Vp_BFu7s_BFu33");
    static STRUCT_IF_C Vp_BFu7s_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7s_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 33, 1, "Vp_BFu7s_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(8,4), ABISELECT(7,7), 33, hide_ull(1LL<<32), "Vp_BFu7s_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu33, Vp_BFu7s_BFu33)
//============================================================================


struct  Vp_BFu7s_BFu7c  {
  void *v1;
  unsigned short v2:7;
  unsigned char v3:7;
};
//SIG(1 Vp_BFu7s_BFu7c) C1{ Fp Fs:7 Fc:7}



static void Test_Vp_BFu7s_BFu7c()
{
  {
    init_simple_test("Vp_BFu7s_BFu7c");
    static STRUCT_IF_C Vp_BFu7s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu7s_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu7c, Vp_BFu7s_BFu7c)
//============================================================================


struct  Vp_BFu7s_BFu7i  {
  void *v1;
  unsigned short v2:7;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu7s_BFu7i) C1{ Fp Fs:7 Fi:7}



static void Test_Vp_BFu7s_BFu7i()
{
  {
    init_simple_test("Vp_BFu7s_BFu7i");
    static STRUCT_IF_C Vp_BFu7s_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, 1, "Vp_BFu7s_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu7i, Vp_BFu7s_BFu7i)
//============================================================================


struct  Vp_BFu7s_BFu7ll  {
  void *v1;
  unsigned short v2:7;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu7s_BFu7ll) C1{ Fp Fs:7 FL:7}



static void Test_Vp_BFu7s_BFu7ll()
{
  {
    init_simple_test("Vp_BFu7s_BFu7ll");
    static STRUCT_IF_C Vp_BFu7s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, 1, "Vp_BFu7s_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu7ll, Vp_BFu7s_BFu7ll)
//============================================================================


struct  Vp_BFu7s_BFu7s  {
  void *v1;
  unsigned short v2:7;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu7s_BFu7s) C1{ Fp Fs:7 Fs:7}



static void Test_Vp_BFu7s_BFu7s()
{
  {
    init_simple_test("Vp_BFu7s_BFu7s");
    static STRUCT_IF_C Vp_BFu7s_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, 1, "Vp_BFu7s_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu7s, Vp_BFu7s_BFu7s)
//============================================================================


struct  Vp_BFu7s_BFu8c  {
  void *v1;
  unsigned short v2:7;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu7s_BFu8c) C1{ Fp Fs:7 Fc:8}



static void Test_Vp_BFu7s_BFu8c()
{
  {
    init_simple_test("Vp_BFu7s_BFu8c");
    static STRUCT_IF_C Vp_BFu7s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu7s_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu7s_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu8c, Vp_BFu7s_BFu8c)
//============================================================================


struct  Vp_BFu7s_BFu8i  {
  void *v1;
  unsigned short v2:7;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu7s_BFu8i) C1{ Fp Fs:7 Fi:8}



static void Test_Vp_BFu7s_BFu8i()
{
  {
    init_simple_test("Vp_BFu7s_BFu8i");
    static STRUCT_IF_C Vp_BFu7s_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, 1, "Vp_BFu7s_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, hide_ull(1LL<<7), "Vp_BFu7s_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu8i, Vp_BFu7s_BFu8i)
//============================================================================


struct  Vp_BFu7s_BFu8ll  {
  void *v1;
  unsigned short v2:7;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu7s_BFu8ll) C1{ Fp Fs:7 FL:8}



static void Test_Vp_BFu7s_BFu8ll()
{
  {
    init_simple_test("Vp_BFu7s_BFu8ll");
    static STRUCT_IF_C Vp_BFu7s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, 1, "Vp_BFu7s_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, hide_ull(1LL<<7), "Vp_BFu7s_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu8ll, Vp_BFu7s_BFu8ll)
//============================================================================


struct  Vp_BFu7s_BFu8s  {
  void *v1;
  unsigned short v2:7;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu7s_BFu8s) C1{ Fp Fs:7 Fs:8}



static void Test_Vp_BFu7s_BFu8s()
{
  {
    init_simple_test("Vp_BFu7s_BFu8s");
    static STRUCT_IF_C Vp_BFu7s_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, 1, "Vp_BFu7s_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 8, hide_ull(1LL<<7), "Vp_BFu7s_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu8s, Vp_BFu7s_BFu8s)
//============================================================================


struct  Vp_BFu7s_BFu9i  {
  void *v1;
  unsigned short v2:7;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu7s_BFu9i) C1{ Fp Fs:7 Fi:9}



static void Test_Vp_BFu7s_BFu9i()
{
  {
    init_simple_test("Vp_BFu7s_BFu9i");
    static STRUCT_IF_C Vp_BFu7s_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, 1, "Vp_BFu7s_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, hide_ull(1LL<<8), "Vp_BFu7s_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu9i, Vp_BFu7s_BFu9i)
//============================================================================


struct  Vp_BFu7s_BFu9ll  {
  void *v1;
  unsigned short v2:7;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu7s_BFu9ll) C1{ Fp Fs:7 FL:9}



static void Test_Vp_BFu7s_BFu9ll()
{
  {
    init_simple_test("Vp_BFu7s_BFu9ll");
    static STRUCT_IF_C Vp_BFu7s_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, 1, "Vp_BFu7s_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, hide_ull(1LL<<8), "Vp_BFu7s_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu9ll, Vp_BFu7s_BFu9ll)
//============================================================================


struct  Vp_BFu7s_BFu9s  {
  void *v1;
  unsigned short v2:7;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu7s_BFu9s) C1{ Fp Fs:7 Fs:9}



static void Test_Vp_BFu7s_BFu9s()
{
  {
    init_simple_test("Vp_BFu7s_BFu9s");
    static STRUCT_IF_C Vp_BFu7s_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, 1, "Vp_BFu7s_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(8,4), 7, 9, hide_ull(1LL<<8), "Vp_BFu7s_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_BFu9s, Vp_BFu7s_BFu9s)
//============================================================================


struct  Vp_BFu7s_C  {
  void *v1;
  unsigned short v2:7;
  char v3;
};
//SIG(1 Vp_BFu7s_C) C1{ Fp Fs:7 Fc}



static void Test_Vp_BFu7s_C()
{
  {
    init_simple_test("Vp_BFu7s_C");
    static STRUCT_IF_C Vp_BFu7s_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_C");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7s_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_C, Vp_BFu7s_C)
//============================================================================


struct  Vp_BFu7s_D  {
  void *v1;
  unsigned short v2:7;
  double v3;
};
//SIG(1 Vp_BFu7s_D) C1{ Fp Fs:7 FL}



static void Test_Vp_BFu7s_D()
{
  {
    init_simple_test("Vp_BFu7s_D");
    static STRUCT_IF_C Vp_BFu7s_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu7s_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_D");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7s_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_D, Vp_BFu7s_D)
//============================================================================


struct  Vp_BFu7s_F  {
  void *v1;
  unsigned short v2:7;
  float v3;
};
//SIG(1 Vp_BFu7s_F) C1{ Fp Fs:7 Fi}



static void Test_Vp_BFu7s_F()
{
  {
    init_simple_test("Vp_BFu7s_F");
    static STRUCT_IF_C Vp_BFu7s_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7s_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_F");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu7s_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_F, Vp_BFu7s_F)
//============================================================================


struct  Vp_BFu7s_I  {
  void *v1;
  unsigned short v2:7;
  int v3;
};
//SIG(1 Vp_BFu7s_I) C1{ Fp Fs:7 Fi}



static void Test_Vp_BFu7s_I()
{
  {
    init_simple_test("Vp_BFu7s_I");
    static STRUCT_IF_C Vp_BFu7s_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7s_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_I");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu7s_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_I, Vp_BFu7s_I)
//============================================================================


struct  Vp_BFu7s_Ip  {
  void *v1;
  unsigned short v2:7;
  int *v3;
};
//SIG(1 Vp_BFu7s_Ip) C1{ Fp Fs:7 Fp}



static void Test_Vp_BFu7s_Ip()
{
  {
    init_simple_test("Vp_BFu7s_Ip");
    static STRUCT_IF_C Vp_BFu7s_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu7s_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_Ip");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7s_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_Ip, Vp_BFu7s_Ip)
//============================================================================


struct  Vp_BFu7s_L  {
  void *v1;
  unsigned short v2:7;
  __tsi64 v3;
};
//SIG(1 Vp_BFu7s_L) C1{ Fp Fs:7 FL}



static void Test_Vp_BFu7s_L()
{
  {
    init_simple_test("Vp_BFu7s_L");
    static STRUCT_IF_C Vp_BFu7s_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu7s_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_L");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7s_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_L, Vp_BFu7s_L)
//============================================================================


struct  Vp_BFu7s_S  {
  void *v1;
  unsigned short v2:7;
  short v3;
};
//SIG(1 Vp_BFu7s_S) C1{ Fp Fs:7 Fs}



static void Test_Vp_BFu7s_S()
{
  {
    init_simple_test("Vp_BFu7s_S");
    static STRUCT_IF_C Vp_BFu7s_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_S");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu7s_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_S, Vp_BFu7s_S)
//============================================================================


struct  Vp_BFu7s_Uc  {
  void *v1;
  unsigned short v2:7;
  unsigned char v3;
};
//SIG(1 Vp_BFu7s_Uc) C1{ Fp Fs:7 Fc}



static void Test_Vp_BFu7s_Uc()
{
  {
    init_simple_test("Vp_BFu7s_Uc");
    static STRUCT_IF_C Vp_BFu7s_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_Uc");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu7s_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_Uc, Vp_BFu7s_Uc)
//============================================================================


struct  Vp_BFu7s_Ui  {
  void *v1;
  unsigned short v2:7;
  unsigned int v3;
};
//SIG(1 Vp_BFu7s_Ui) C1{ Fp Fs:7 Fi}



static void Test_Vp_BFu7s_Ui()
{
  {
    init_simple_test("Vp_BFu7s_Ui");
    static STRUCT_IF_C Vp_BFu7s_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu7s_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_Ui");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu7s_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_Ui, Vp_BFu7s_Ui)
//============================================================================


struct  Vp_BFu7s_Ul  {
  void *v1;
  unsigned short v2:7;
  __tsu64 v3;
};
//SIG(1 Vp_BFu7s_Ul) C1{ Fp Fs:7 FL}



static void Test_Vp_BFu7s_Ul()
{
  {
    init_simple_test("Vp_BFu7s_Ul");
    static STRUCT_IF_C Vp_BFu7s_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu7s_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_Ul");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7s_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_Ul, Vp_BFu7s_Ul)
//============================================================================


struct  Vp_BFu7s_Us  {
  void *v1;
  unsigned short v2:7;
  unsigned short v3;
};
//SIG(1 Vp_BFu7s_Us) C1{ Fp Fs:7 Fs}



static void Test_Vp_BFu7s_Us()
{
  {
    init_simple_test("Vp_BFu7s_Us");
    static STRUCT_IF_C Vp_BFu7s_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu7s_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_Us");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu7s_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_Us, Vp_BFu7s_Us)
//============================================================================


struct  Vp_BFu7s_Vp  {
  void *v1;
  unsigned short v2:7;
  void *v3;
};
//SIG(1 Vp_BFu7s_Vp) C1{ Fp Fs:7 Fp}



static void Test_Vp_BFu7s_Vp()
{
  {
    init_simple_test("Vp_BFu7s_Vp");
    static STRUCT_IF_C Vp_BFu7s_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu7s_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu7s_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu7s_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, 1, "Vp_BFu7s_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 7, hide_ull(1LL<<6), "Vp_BFu7s_Vp");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu7s_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu7s_Vp, Vp_BFu7s_Vp)
//============================================================================


struct  Vp_BFu8c  {
  void *v1;
  unsigned char v2:8;
};
//SIG(1 Vp_BFu8c) C1{ Fp Fc:8}



static void Test_Vp_BFu8c()
{
  {
    init_simple_test("Vp_BFu8c");
    static STRUCT_IF_C Vp_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c, Vp_BFu8c)
//============================================================================


struct  Vp_BFu8c_BFu15i  {
  void *v1;
  unsigned char v2:8;
  unsigned int v3:15;
};
//SIG(1 Vp_BFu8c_BFu15i) C1{ Fp Fc:8 Fi:15}



static void Test_Vp_BFu8c_BFu15i()
{
  {
    init_simple_test("Vp_BFu8c_BFu15i");
    static STRUCT_IF_C Vp_BFu8c_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_BFu8c_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_BFu8c_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu15i, Vp_BFu8c_BFu15i)
//============================================================================


struct  Vp_BFu8c_BFu15ll  {
  void *v1;
  unsigned char v2:8;
  __tsu64 v3:15;
};
//SIG(1 Vp_BFu8c_BFu15ll) C1{ Fp Fc:8 FL:15}



static void Test_Vp_BFu8c_BFu15ll()
{
  {
    init_simple_test("Vp_BFu8c_BFu15ll");
    static STRUCT_IF_C Vp_BFu8c_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_BFu8c_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_BFu8c_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu15ll, Vp_BFu8c_BFu15ll)
//============================================================================


struct  Vp_BFu8c_BFu15s  {
  void *v1;
  unsigned char v2:8;
  unsigned short v3:15;
};
//SIG(1 Vp_BFu8c_BFu15s) C1{ Fp Fc:8 Fs:15}



static void Test_Vp_BFu8c_BFu15s()
{
  {
    init_simple_test("Vp_BFu8c_BFu15s");
    static STRUCT_IF_C Vp_BFu8c_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_BFu8c_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_BFu8c_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu15s, Vp_BFu8c_BFu15s)
//============================================================================


struct  Vp_BFu8c_BFu16i  {
  void *v1;
  unsigned char v2:8;
  unsigned int v3:16;
};
//SIG(1 Vp_BFu8c_BFu16i) C1{ Fp Fc:8 Fi:16}



static void Test_Vp_BFu8c_BFu16i()
{
  {
    init_simple_test("Vp_BFu8c_BFu16i");
    static STRUCT_IF_C Vp_BFu8c_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_BFu8c_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_BFu8c_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu16i, Vp_BFu8c_BFu16i)
//============================================================================


struct  Vp_BFu8c_BFu16ll  {
  void *v1;
  unsigned char v2:8;
  __tsu64 v3:16;
};
//SIG(1 Vp_BFu8c_BFu16ll) C1{ Fp Fc:8 FL:16}



static void Test_Vp_BFu8c_BFu16ll()
{
  {
    init_simple_test("Vp_BFu8c_BFu16ll");
    static STRUCT_IF_C Vp_BFu8c_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_BFu8c_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_BFu8c_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu16ll, Vp_BFu8c_BFu16ll)
//============================================================================


struct  Vp_BFu8c_BFu16s  {
  void *v1;
  unsigned char v2:8;
  unsigned short v3:16;
};
//SIG(1 Vp_BFu8c_BFu16s) C1{ Fp Fc:8 Fs:16}



static void Test_Vp_BFu8c_BFu16s()
{
  {
    init_simple_test("Vp_BFu8c_BFu16s");
    static STRUCT_IF_C Vp_BFu8c_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_BFu8c_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_BFu8c_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu16s, Vp_BFu8c_BFu16s)
//============================================================================


struct  Vp_BFu8c_BFu17i  {
  void *v1;
  unsigned char v2:8;
  unsigned int v3:17;
};
//SIG(1 Vp_BFu8c_BFu17i) C1{ Fp Fc:8 Fi:17}



static void Test_Vp_BFu8c_BFu17i()
{
  {
    init_simple_test("Vp_BFu8c_BFu17i");
    static STRUCT_IF_C Vp_BFu8c_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_BFu8c_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_BFu8c_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu17i, Vp_BFu8c_BFu17i)
//============================================================================


struct  Vp_BFu8c_BFu17ll  {
  void *v1;
  unsigned char v2:8;
  __tsu64 v3:17;
};
//SIG(1 Vp_BFu8c_BFu17ll) C1{ Fp Fc:8 FL:17}



static void Test_Vp_BFu8c_BFu17ll()
{
  {
    init_simple_test("Vp_BFu8c_BFu17ll");
    static STRUCT_IF_C Vp_BFu8c_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_BFu8c_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_BFu8c_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu17ll, Vp_BFu8c_BFu17ll)
//============================================================================


struct  Vp_BFu8c_BFu1c  {
  void *v1;
  unsigned char v2:8;
  unsigned char v3:1;
};
//SIG(1 Vp_BFu8c_BFu1c) C1{ Fp Fc:8 Fc:1}



static void Test_Vp_BFu8c_BFu1c()
{
  {
    init_simple_test("Vp_BFu8c_BFu1c");
    static STRUCT_IF_C Vp_BFu8c_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu1c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu1c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8c_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu1c, Vp_BFu8c_BFu1c)
//============================================================================


struct  Vp_BFu8c_BFu1i  {
  void *v1;
  unsigned char v2:8;
  unsigned int v3:1;
};
//SIG(1 Vp_BFu8c_BFu1i) C1{ Fp Fc:8 Fi:1}



static void Test_Vp_BFu8c_BFu1i()
{
  {
    init_simple_test("Vp_BFu8c_BFu1i");
    static STRUCT_IF_C Vp_BFu8c_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu1i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu1i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8c_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu1i, Vp_BFu8c_BFu1i)
//============================================================================


struct  Vp_BFu8c_BFu1ll  {
  void *v1;
  unsigned char v2:8;
  __tsu64 v3:1;
};
//SIG(1 Vp_BFu8c_BFu1ll) C1{ Fp Fc:8 FL:1}



static void Test_Vp_BFu8c_BFu1ll()
{
  {
    init_simple_test("Vp_BFu8c_BFu1ll");
    static STRUCT_IF_C Vp_BFu8c_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu1ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu1ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8c_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu1ll, Vp_BFu8c_BFu1ll)
//============================================================================


struct  Vp_BFu8c_BFu1s  {
  void *v1;
  unsigned char v2:8;
  unsigned short v3:1;
};
//SIG(1 Vp_BFu8c_BFu1s) C1{ Fp Fc:8 Fs:1}



static void Test_Vp_BFu8c_BFu1s()
{
  {
    init_simple_test("Vp_BFu8c_BFu1s");
    static STRUCT_IF_C Vp_BFu8c_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu1s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu1s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8c_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu1s, Vp_BFu8c_BFu1s)
//============================================================================


struct  Vp_BFu8c_BFu31i  {
  void *v1;
  unsigned char v2:8;
  unsigned int v3:31;
};
//SIG(1 Vp_BFu8c_BFu31i) C1{ Fp Fc:8 Fi:31}



static void Test_Vp_BFu8c_BFu31i()
{
  {
    init_simple_test("Vp_BFu8c_BFu31i");
    static STRUCT_IF_C Vp_BFu8c_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8c_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_BFu8c_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_BFu8c_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu31i, Vp_BFu8c_BFu31i)
//============================================================================


struct  Vp_BFu8c_BFu31ll  {
  void *v1;
  unsigned char v2:8;
  __tsu64 v3:31;
};
//SIG(1 Vp_BFu8c_BFu31ll) C1{ Fp Fc:8 FL:31}



static void Test_Vp_BFu8c_BFu31ll()
{
  {
    init_simple_test("Vp_BFu8c_BFu31ll");
    static STRUCT_IF_C Vp_BFu8c_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8c_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, 1, "Vp_BFu8c_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, hide_ull(1LL<<30), "Vp_BFu8c_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu31ll, Vp_BFu8c_BFu31ll)
//============================================================================


struct  Vp_BFu8c_BFu32i  {
  void *v1;
  unsigned char v2:8;
  unsigned int v3:32;
};
//SIG(1 Vp_BFu8c_BFu32i) C1{ Fp Fc:8 Fi:32}



static void Test_Vp_BFu8c_BFu32i()
{
  {
    init_simple_test("Vp_BFu8c_BFu32i");
    static STRUCT_IF_C Vp_BFu8c_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8c_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_BFu8c_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_BFu8c_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu32i, Vp_BFu8c_BFu32i)
//============================================================================


struct  Vp_BFu8c_BFu32ll  {
  void *v1;
  unsigned char v2:8;
  __tsu64 v3:32;
};
//SIG(1 Vp_BFu8c_BFu32ll) C1{ Fp Fc:8 FL:32}



static void Test_Vp_BFu8c_BFu32ll()
{
  {
    init_simple_test("Vp_BFu8c_BFu32ll");
    static STRUCT_IF_C Vp_BFu8c_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8c_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, 1, "Vp_BFu8c_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, hide_ull(1LL<<31), "Vp_BFu8c_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu32ll, Vp_BFu8c_BFu32ll)
//============================================================================


struct  Vp_BFu8c_BFu33  {
  void *v1;
  unsigned char v2:8;
  __tsu64 v3:33;
};
//SIG(1 Vp_BFu8c_BFu33) C1{ Fp Fc:8 FL:33}



static void Test_Vp_BFu8c_BFu33()
{
  {
    init_simple_test("Vp_BFu8c_BFu33");
    static STRUCT_IF_C Vp_BFu8c_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8c_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, 1, "Vp_BFu8c_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, hide_ull(1LL<<32), "Vp_BFu8c_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu33, Vp_BFu8c_BFu33)
//============================================================================


struct  Vp_BFu8c_BFu7c  {
  void *v1;
  unsigned char v2:8;
  unsigned char v3:7;
};
//SIG(1 Vp_BFu8c_BFu7c) C1{ Fp Fc:8 Fc:7}



static void Test_Vp_BFu8c_BFu7c()
{
  {
    init_simple_test("Vp_BFu8c_BFu7c");
    static STRUCT_IF_C Vp_BFu8c_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8c_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8c_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu7c, Vp_BFu8c_BFu7c)
//============================================================================


struct  Vp_BFu8c_BFu7i  {
  void *v1;
  unsigned char v2:8;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu8c_BFu7i) C1{ Fp Fc:8 Fi:7}



static void Test_Vp_BFu8c_BFu7i()
{
  {
    init_simple_test("Vp_BFu8c_BFu7i");
    static STRUCT_IF_C Vp_BFu8c_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8c_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8c_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu7i, Vp_BFu8c_BFu7i)
//============================================================================


struct  Vp_BFu8c_BFu7ll  {
  void *v1;
  unsigned char v2:8;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu8c_BFu7ll) C1{ Fp Fc:8 FL:7}



static void Test_Vp_BFu8c_BFu7ll()
{
  {
    init_simple_test("Vp_BFu8c_BFu7ll");
    static STRUCT_IF_C Vp_BFu8c_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8c_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8c_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu7ll, Vp_BFu8c_BFu7ll)
//============================================================================


struct  Vp_BFu8c_BFu7s  {
  void *v1;
  unsigned char v2:8;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu8c_BFu7s) C1{ Fp Fc:8 Fs:7}



static void Test_Vp_BFu8c_BFu7s()
{
  {
    init_simple_test("Vp_BFu8c_BFu7s");
    static STRUCT_IF_C Vp_BFu8c_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8c_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8c_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu7s, Vp_BFu8c_BFu7s)
//============================================================================


struct  Vp_BFu8c_BFu8c  {
  void *v1;
  unsigned char v2:8;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu8c_BFu8c) C1{ Fp Fc:8 Fc:8}



static void Test_Vp_BFu8c_BFu8c()
{
  {
    init_simple_test("Vp_BFu8c_BFu8c");
    static STRUCT_IF_C Vp_BFu8c_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8c_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu8c, Vp_BFu8c_BFu8c)
//============================================================================


struct  Vp_BFu8c_BFu8i  {
  void *v1;
  unsigned char v2:8;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu8c_BFu8i) C1{ Fp Fc:8 Fi:8}



static void Test_Vp_BFu8c_BFu8i()
{
  {
    init_simple_test("Vp_BFu8c_BFu8i");
    static STRUCT_IF_C Vp_BFu8c_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8c_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu8i, Vp_BFu8c_BFu8i)
//============================================================================


struct  Vp_BFu8c_BFu8ll  {
  void *v1;
  unsigned char v2:8;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu8c_BFu8ll) C1{ Fp Fc:8 FL:8}



static void Test_Vp_BFu8c_BFu8ll()
{
  {
    init_simple_test("Vp_BFu8c_BFu8ll");
    static STRUCT_IF_C Vp_BFu8c_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8c_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu8ll, Vp_BFu8c_BFu8ll)
//============================================================================


struct  Vp_BFu8c_BFu8s  {
  void *v1;
  unsigned char v2:8;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu8c_BFu8s) C1{ Fp Fc:8 Fs:8}



static void Test_Vp_BFu8c_BFu8s()
{
  {
    init_simple_test("Vp_BFu8c_BFu8s");
    static STRUCT_IF_C Vp_BFu8c_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8c_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu8s, Vp_BFu8c_BFu8s)
//============================================================================


struct  Vp_BFu8c_BFu9i  {
  void *v1;
  unsigned char v2:8;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu8c_BFu9i) C1{ Fp Fc:8 Fi:9}



static void Test_Vp_BFu8c_BFu9i()
{
  {
    init_simple_test("Vp_BFu8c_BFu9i");
    static STRUCT_IF_C Vp_BFu8c_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_BFu8c_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_BFu8c_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu9i, Vp_BFu8c_BFu9i)
//============================================================================


struct  Vp_BFu8c_BFu9ll  {
  void *v1;
  unsigned char v2:8;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu8c_BFu9ll) C1{ Fp Fc:8 FL:9}



static void Test_Vp_BFu8c_BFu9ll()
{
  {
    init_simple_test("Vp_BFu8c_BFu9ll");
    static STRUCT_IF_C Vp_BFu8c_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_BFu8c_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_BFu8c_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu9ll, Vp_BFu8c_BFu9ll)
//============================================================================


struct  Vp_BFu8c_BFu9s  {
  void *v1;
  unsigned char v2:8;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu8c_BFu9s) C1{ Fp Fc:8 Fs:9}



static void Test_Vp_BFu8c_BFu9s()
{
  {
    init_simple_test("Vp_BFu8c_BFu9s");
    static STRUCT_IF_C Vp_BFu8c_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_BFu8c_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_BFu8c_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_BFu9s, Vp_BFu8c_BFu9s)
//============================================================================


struct  Vp_BFu8c_C  {
  void *v1;
  unsigned char v2:8;
  char v3;
};
//SIG(1 Vp_BFu8c_C) C1{ Fp Fc:8 Fc}



static void Test_Vp_BFu8c_C()
{
  {
    init_simple_test("Vp_BFu8c_C");
    static STRUCT_IF_C Vp_BFu8c_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_C");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8c_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_C, Vp_BFu8c_C)
//============================================================================


struct  Vp_BFu8c_D  {
  void *v1;
  unsigned char v2:8;
  double v3;
};
//SIG(1 Vp_BFu8c_D) C1{ Fp Fc:8 FL}



static void Test_Vp_BFu8c_D()
{
  {
    init_simple_test("Vp_BFu8c_D");
    static STRUCT_IF_C Vp_BFu8c_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu8c_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_D");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8c_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_D, Vp_BFu8c_D)
//============================================================================


struct  Vp_BFu8c_F  {
  void *v1;
  unsigned char v2:8;
  float v3;
};
//SIG(1 Vp_BFu8c_F) C1{ Fp Fc:8 Fi}



static void Test_Vp_BFu8c_F()
{
  {
    init_simple_test("Vp_BFu8c_F");
    static STRUCT_IF_C Vp_BFu8c_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8c_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_F");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu8c_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_F, Vp_BFu8c_F)
//============================================================================


struct  Vp_BFu8c_I  {
  void *v1;
  unsigned char v2:8;
  int v3;
};
//SIG(1 Vp_BFu8c_I) C1{ Fp Fc:8 Fi}



static void Test_Vp_BFu8c_I()
{
  {
    init_simple_test("Vp_BFu8c_I");
    static STRUCT_IF_C Vp_BFu8c_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8c_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_I");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu8c_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_I, Vp_BFu8c_I)
//============================================================================


struct  Vp_BFu8c_Ip  {
  void *v1;
  unsigned char v2:8;
  int *v3;
};
//SIG(1 Vp_BFu8c_Ip) C1{ Fp Fc:8 Fp}



static void Test_Vp_BFu8c_Ip()
{
  {
    init_simple_test("Vp_BFu8c_Ip");
    static STRUCT_IF_C Vp_BFu8c_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu8c_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_Ip");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8c_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_Ip, Vp_BFu8c_Ip)
//============================================================================


struct  Vp_BFu8c_L  {
  void *v1;
  unsigned char v2:8;
  __tsi64 v3;
};
//SIG(1 Vp_BFu8c_L) C1{ Fp Fc:8 FL}



static void Test_Vp_BFu8c_L()
{
  {
    init_simple_test("Vp_BFu8c_L");
    static STRUCT_IF_C Vp_BFu8c_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu8c_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_L");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8c_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_L, Vp_BFu8c_L)
//============================================================================


struct  Vp_BFu8c_S  {
  void *v1;
  unsigned char v2:8;
  short v3;
};
//SIG(1 Vp_BFu8c_S) C1{ Fp Fc:8 Fs}



static void Test_Vp_BFu8c_S()
{
  {
    init_simple_test("Vp_BFu8c_S");
    static STRUCT_IF_C Vp_BFu8c_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_S");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu8c_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_S, Vp_BFu8c_S)
//============================================================================


struct  Vp_BFu8c_Uc  {
  void *v1;
  unsigned char v2:8;
  unsigned char v3;
};
//SIG(1 Vp_BFu8c_Uc) C1{ Fp Fc:8 Fc}



static void Test_Vp_BFu8c_Uc()
{
  {
    init_simple_test("Vp_BFu8c_Uc");
    static STRUCT_IF_C Vp_BFu8c_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_Uc");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8c_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_Uc, Vp_BFu8c_Uc)
//============================================================================


struct  Vp_BFu8c_Ui  {
  void *v1;
  unsigned char v2:8;
  unsigned int v3;
};
//SIG(1 Vp_BFu8c_Ui) C1{ Fp Fc:8 Fi}



static void Test_Vp_BFu8c_Ui()
{
  {
    init_simple_test("Vp_BFu8c_Ui");
    static STRUCT_IF_C Vp_BFu8c_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8c_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_Ui");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu8c_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_Ui, Vp_BFu8c_Ui)
//============================================================================


struct  Vp_BFu8c_Ul  {
  void *v1;
  unsigned char v2:8;
  __tsu64 v3;
};
//SIG(1 Vp_BFu8c_Ul) C1{ Fp Fc:8 FL}



static void Test_Vp_BFu8c_Ul()
{
  {
    init_simple_test("Vp_BFu8c_Ul");
    static STRUCT_IF_C Vp_BFu8c_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu8c_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_Ul");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8c_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_Ul, Vp_BFu8c_Ul)
//============================================================================


struct  Vp_BFu8c_Us  {
  void *v1;
  unsigned char v2:8;
  unsigned short v3;
};
//SIG(1 Vp_BFu8c_Us) C1{ Fp Fc:8 Fs}



static void Test_Vp_BFu8c_Us()
{
  {
    init_simple_test("Vp_BFu8c_Us");
    static STRUCT_IF_C Vp_BFu8c_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8c_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_Us");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu8c_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_Us, Vp_BFu8c_Us)
//============================================================================


struct  Vp_BFu8c_Vp  {
  void *v1;
  unsigned char v2:8;
  void *v3;
};
//SIG(1 Vp_BFu8c_Vp) C1{ Fp Fc:8 Fp}



static void Test_Vp_BFu8c_Vp()
{
  {
    init_simple_test("Vp_BFu8c_Vp");
    static STRUCT_IF_C Vp_BFu8c_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu8c_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8c_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu8c_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8c_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8c_Vp");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8c_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8c_Vp, Vp_BFu8c_Vp)
//============================================================================


struct  Vp_BFu8i  {
  void *v1;
  unsigned int v2:8;
};
//SIG(1 Vp_BFu8i) C1{ Fp Fi:8}



static void Test_Vp_BFu8i()
{
  {
    init_simple_test("Vp_BFu8i");
    static STRUCT_IF_C Vp_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i, Vp_BFu8i)
//============================================================================


struct  Vp_BFu8i_BFu15i  {
  void *v1;
  unsigned int v2:8;
  unsigned int v3:15;
};
//SIG(1 Vp_BFu8i_BFu15i) C1{ Fp Fi:8 Fi:15}



static void Test_Vp_BFu8i_BFu15i()
{
  {
    init_simple_test("Vp_BFu8i_BFu15i");
    static STRUCT_IF_C Vp_BFu8i_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_BFu8i_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_BFu8i_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu15i, Vp_BFu8i_BFu15i)
//============================================================================


struct  Vp_BFu8i_BFu15ll  {
  void *v1;
  unsigned int v2:8;
  __tsu64 v3:15;
};
//SIG(1 Vp_BFu8i_BFu15ll) C1{ Fp Fi:8 FL:15}



static void Test_Vp_BFu8i_BFu15ll()
{
  {
    init_simple_test("Vp_BFu8i_BFu15ll");
    static STRUCT_IF_C Vp_BFu8i_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_BFu8i_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_BFu8i_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu15ll, Vp_BFu8i_BFu15ll)
//============================================================================


struct  Vp_BFu8i_BFu15s  {
  void *v1;
  unsigned int v2:8;
  unsigned short v3:15;
};
//SIG(1 Vp_BFu8i_BFu15s) C1{ Fp Fi:8 Fs:15}



static void Test_Vp_BFu8i_BFu15s()
{
  {
    init_simple_test("Vp_BFu8i_BFu15s");
    static STRUCT_IF_C Vp_BFu8i_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_BFu8i_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_BFu8i_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu15s, Vp_BFu8i_BFu15s)
//============================================================================


struct  Vp_BFu8i_BFu16i  {
  void *v1;
  unsigned int v2:8;
  unsigned int v3:16;
};
//SIG(1 Vp_BFu8i_BFu16i) C1{ Fp Fi:8 Fi:16}



static void Test_Vp_BFu8i_BFu16i()
{
  {
    init_simple_test("Vp_BFu8i_BFu16i");
    static STRUCT_IF_C Vp_BFu8i_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_BFu8i_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_BFu8i_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu16i, Vp_BFu8i_BFu16i)
//============================================================================


struct  Vp_BFu8i_BFu16ll  {
  void *v1;
  unsigned int v2:8;
  __tsu64 v3:16;
};
//SIG(1 Vp_BFu8i_BFu16ll) C1{ Fp Fi:8 FL:16}



static void Test_Vp_BFu8i_BFu16ll()
{
  {
    init_simple_test("Vp_BFu8i_BFu16ll");
    static STRUCT_IF_C Vp_BFu8i_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_BFu8i_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_BFu8i_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu16ll, Vp_BFu8i_BFu16ll)
//============================================================================


struct  Vp_BFu8i_BFu16s  {
  void *v1;
  unsigned int v2:8;
  unsigned short v3:16;
};
//SIG(1 Vp_BFu8i_BFu16s) C1{ Fp Fi:8 Fs:16}



static void Test_Vp_BFu8i_BFu16s()
{
  {
    init_simple_test("Vp_BFu8i_BFu16s");
    static STRUCT_IF_C Vp_BFu8i_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_BFu8i_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_BFu8i_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu16s, Vp_BFu8i_BFu16s)
//============================================================================


struct  Vp_BFu8i_BFu17i  {
  void *v1;
  unsigned int v2:8;
  unsigned int v3:17;
};
//SIG(1 Vp_BFu8i_BFu17i) C1{ Fp Fi:8 Fi:17}



static void Test_Vp_BFu8i_BFu17i()
{
  {
    init_simple_test("Vp_BFu8i_BFu17i");
    static STRUCT_IF_C Vp_BFu8i_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_BFu8i_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_BFu8i_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu17i, Vp_BFu8i_BFu17i)
//============================================================================


struct  Vp_BFu8i_BFu17ll  {
  void *v1;
  unsigned int v2:8;
  __tsu64 v3:17;
};
//SIG(1 Vp_BFu8i_BFu17ll) C1{ Fp Fi:8 FL:17}



static void Test_Vp_BFu8i_BFu17ll()
{
  {
    init_simple_test("Vp_BFu8i_BFu17ll");
    static STRUCT_IF_C Vp_BFu8i_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_BFu8i_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_BFu8i_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu17ll, Vp_BFu8i_BFu17ll)
//============================================================================


struct  Vp_BFu8i_BFu1c  {
  void *v1;
  unsigned int v2:8;
  unsigned char v3:1;
};
//SIG(1 Vp_BFu8i_BFu1c) C1{ Fp Fi:8 Fc:1}



static void Test_Vp_BFu8i_BFu1c()
{
  {
    init_simple_test("Vp_BFu8i_BFu1c");
    static STRUCT_IF_C Vp_BFu8i_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu1c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu1c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8i_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu1c, Vp_BFu8i_BFu1c)
//============================================================================


struct  Vp_BFu8i_BFu1i  {
  void *v1;
  unsigned int v2:8;
  unsigned int v3:1;
};
//SIG(1 Vp_BFu8i_BFu1i) C1{ Fp Fi:8 Fi:1}



static void Test_Vp_BFu8i_BFu1i()
{
  {
    init_simple_test("Vp_BFu8i_BFu1i");
    static STRUCT_IF_C Vp_BFu8i_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu1i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu1i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8i_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu1i, Vp_BFu8i_BFu1i)
//============================================================================


struct  Vp_BFu8i_BFu1ll  {
  void *v1;
  unsigned int v2:8;
  __tsu64 v3:1;
};
//SIG(1 Vp_BFu8i_BFu1ll) C1{ Fp Fi:8 FL:1}



static void Test_Vp_BFu8i_BFu1ll()
{
  {
    init_simple_test("Vp_BFu8i_BFu1ll");
    static STRUCT_IF_C Vp_BFu8i_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu1ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu1ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8i_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu1ll, Vp_BFu8i_BFu1ll)
//============================================================================


struct  Vp_BFu8i_BFu1s  {
  void *v1;
  unsigned int v2:8;
  unsigned short v3:1;
};
//SIG(1 Vp_BFu8i_BFu1s) C1{ Fp Fi:8 Fs:1}



static void Test_Vp_BFu8i_BFu1s()
{
  {
    init_simple_test("Vp_BFu8i_BFu1s");
    static STRUCT_IF_C Vp_BFu8i_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu1s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu1s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8i_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu1s, Vp_BFu8i_BFu1s)
//============================================================================


struct  Vp_BFu8i_BFu31i  {
  void *v1;
  unsigned int v2:8;
  unsigned int v3:31;
};
//SIG(1 Vp_BFu8i_BFu31i) C1{ Fp Fi:8 Fi:31}



static void Test_Vp_BFu8i_BFu31i()
{
  {
    init_simple_test("Vp_BFu8i_BFu31i");
    static STRUCT_IF_C Vp_BFu8i_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8i_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_BFu8i_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_BFu8i_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu31i, Vp_BFu8i_BFu31i)
//============================================================================


struct  Vp_BFu8i_BFu31ll  {
  void *v1;
  unsigned int v2:8;
  __tsu64 v3:31;
};
//SIG(1 Vp_BFu8i_BFu31ll) C1{ Fp Fi:8 FL:31}



static void Test_Vp_BFu8i_BFu31ll()
{
  {
    init_simple_test("Vp_BFu8i_BFu31ll");
    static STRUCT_IF_C Vp_BFu8i_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8i_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, 1, "Vp_BFu8i_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, hide_ull(1LL<<30), "Vp_BFu8i_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu31ll, Vp_BFu8i_BFu31ll)
//============================================================================


struct  Vp_BFu8i_BFu32i  {
  void *v1;
  unsigned int v2:8;
  unsigned int v3:32;
};
//SIG(1 Vp_BFu8i_BFu32i) C1{ Fp Fi:8 Fi:32}



static void Test_Vp_BFu8i_BFu32i()
{
  {
    init_simple_test("Vp_BFu8i_BFu32i");
    static STRUCT_IF_C Vp_BFu8i_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8i_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_BFu8i_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_BFu8i_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu32i, Vp_BFu8i_BFu32i)
//============================================================================


struct  Vp_BFu8i_BFu32ll  {
  void *v1;
  unsigned int v2:8;
  __tsu64 v3:32;
};
//SIG(1 Vp_BFu8i_BFu32ll) C1{ Fp Fi:8 FL:32}



static void Test_Vp_BFu8i_BFu32ll()
{
  {
    init_simple_test("Vp_BFu8i_BFu32ll");
    static STRUCT_IF_C Vp_BFu8i_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8i_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, 1, "Vp_BFu8i_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, hide_ull(1LL<<31), "Vp_BFu8i_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu32ll, Vp_BFu8i_BFu32ll)
//============================================================================


struct  Vp_BFu8i_BFu33  {
  void *v1;
  unsigned int v2:8;
  __tsu64 v3:33;
};
//SIG(1 Vp_BFu8i_BFu33) C1{ Fp Fi:8 FL:33}



static void Test_Vp_BFu8i_BFu33()
{
  {
    init_simple_test("Vp_BFu8i_BFu33");
    static STRUCT_IF_C Vp_BFu8i_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8i_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, 1, "Vp_BFu8i_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, hide_ull(1LL<<32), "Vp_BFu8i_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu33, Vp_BFu8i_BFu33)
//============================================================================


struct  Vp_BFu8i_BFu7c  {
  void *v1;
  unsigned int v2:8;
  unsigned char v3:7;
};
//SIG(1 Vp_BFu8i_BFu7c) C1{ Fp Fi:8 Fc:7}



static void Test_Vp_BFu8i_BFu7c()
{
  {
    init_simple_test("Vp_BFu8i_BFu7c");
    static STRUCT_IF_C Vp_BFu8i_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8i_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8i_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu7c, Vp_BFu8i_BFu7c)
//============================================================================


struct  Vp_BFu8i_BFu7i  {
  void *v1;
  unsigned int v2:8;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu8i_BFu7i) C1{ Fp Fi:8 Fi:7}



static void Test_Vp_BFu8i_BFu7i()
{
  {
    init_simple_test("Vp_BFu8i_BFu7i");
    static STRUCT_IF_C Vp_BFu8i_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8i_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8i_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu7i, Vp_BFu8i_BFu7i)
//============================================================================


struct  Vp_BFu8i_BFu7ll  {
  void *v1;
  unsigned int v2:8;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu8i_BFu7ll) C1{ Fp Fi:8 FL:7}



static void Test_Vp_BFu8i_BFu7ll()
{
  {
    init_simple_test("Vp_BFu8i_BFu7ll");
    static STRUCT_IF_C Vp_BFu8i_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8i_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8i_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu7ll, Vp_BFu8i_BFu7ll)
//============================================================================


struct  Vp_BFu8i_BFu7s  {
  void *v1;
  unsigned int v2:8;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu8i_BFu7s) C1{ Fp Fi:8 Fs:7}



static void Test_Vp_BFu8i_BFu7s()
{
  {
    init_simple_test("Vp_BFu8i_BFu7s");
    static STRUCT_IF_C Vp_BFu8i_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8i_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8i_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu7s, Vp_BFu8i_BFu7s)
//============================================================================


struct  Vp_BFu8i_BFu8c  {
  void *v1;
  unsigned int v2:8;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu8i_BFu8c) C1{ Fp Fi:8 Fc:8}



static void Test_Vp_BFu8i_BFu8c()
{
  {
    init_simple_test("Vp_BFu8i_BFu8c");
    static STRUCT_IF_C Vp_BFu8i_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8i_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu8c, Vp_BFu8i_BFu8c)
//============================================================================


struct  Vp_BFu8i_BFu8i  {
  void *v1;
  unsigned int v2:8;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu8i_BFu8i) C1{ Fp Fi:8 Fi:8}



static void Test_Vp_BFu8i_BFu8i()
{
  {
    init_simple_test("Vp_BFu8i_BFu8i");
    static STRUCT_IF_C Vp_BFu8i_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8i_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu8i, Vp_BFu8i_BFu8i)
//============================================================================


struct  Vp_BFu8i_BFu8ll  {
  void *v1;
  unsigned int v2:8;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu8i_BFu8ll) C1{ Fp Fi:8 FL:8}



static void Test_Vp_BFu8i_BFu8ll()
{
  {
    init_simple_test("Vp_BFu8i_BFu8ll");
    static STRUCT_IF_C Vp_BFu8i_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8i_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu8ll, Vp_BFu8i_BFu8ll)
//============================================================================


struct  Vp_BFu8i_BFu8s  {
  void *v1;
  unsigned int v2:8;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu8i_BFu8s) C1{ Fp Fi:8 Fs:8}



static void Test_Vp_BFu8i_BFu8s()
{
  {
    init_simple_test("Vp_BFu8i_BFu8s");
    static STRUCT_IF_C Vp_BFu8i_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8i_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu8s, Vp_BFu8i_BFu8s)
//============================================================================


struct  Vp_BFu8i_BFu9i  {
  void *v1;
  unsigned int v2:8;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu8i_BFu9i) C1{ Fp Fi:8 Fi:9}



static void Test_Vp_BFu8i_BFu9i()
{
  {
    init_simple_test("Vp_BFu8i_BFu9i");
    static STRUCT_IF_C Vp_BFu8i_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_BFu8i_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_BFu8i_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu9i, Vp_BFu8i_BFu9i)
//============================================================================


struct  Vp_BFu8i_BFu9ll  {
  void *v1;
  unsigned int v2:8;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu8i_BFu9ll) C1{ Fp Fi:8 FL:9}



static void Test_Vp_BFu8i_BFu9ll()
{
  {
    init_simple_test("Vp_BFu8i_BFu9ll");
    static STRUCT_IF_C Vp_BFu8i_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_BFu8i_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_BFu8i_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu9ll, Vp_BFu8i_BFu9ll)
//============================================================================


struct  Vp_BFu8i_BFu9s  {
  void *v1;
  unsigned int v2:8;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu8i_BFu9s) C1{ Fp Fi:8 Fs:9}



static void Test_Vp_BFu8i_BFu9s()
{
  {
    init_simple_test("Vp_BFu8i_BFu9s");
    static STRUCT_IF_C Vp_BFu8i_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_BFu8i_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_BFu8i_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_BFu9s, Vp_BFu8i_BFu9s)
//============================================================================


struct  Vp_BFu8i_C  {
  void *v1;
  unsigned int v2:8;
  char v3;
};
//SIG(1 Vp_BFu8i_C) C1{ Fp Fi:8 Fc}



static void Test_Vp_BFu8i_C()
{
  {
    init_simple_test("Vp_BFu8i_C");
    static STRUCT_IF_C Vp_BFu8i_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_C");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8i_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_C, Vp_BFu8i_C)
//============================================================================


struct  Vp_BFu8i_D  {
  void *v1;
  unsigned int v2:8;
  double v3;
};
//SIG(1 Vp_BFu8i_D) C1{ Fp Fi:8 FL}



static void Test_Vp_BFu8i_D()
{
  {
    init_simple_test("Vp_BFu8i_D");
    static STRUCT_IF_C Vp_BFu8i_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu8i_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_D");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8i_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_D, Vp_BFu8i_D)
//============================================================================


struct  Vp_BFu8i_F  {
  void *v1;
  unsigned int v2:8;
  float v3;
};
//SIG(1 Vp_BFu8i_F) C1{ Fp Fi:8 Fi}



static void Test_Vp_BFu8i_F()
{
  {
    init_simple_test("Vp_BFu8i_F");
    static STRUCT_IF_C Vp_BFu8i_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8i_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_F");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu8i_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_F, Vp_BFu8i_F)
//============================================================================


struct  Vp_BFu8i_I  {
  void *v1;
  unsigned int v2:8;
  int v3;
};
//SIG(1 Vp_BFu8i_I) C1{ Fp Fi:8 Fi}



static void Test_Vp_BFu8i_I()
{
  {
    init_simple_test("Vp_BFu8i_I");
    static STRUCT_IF_C Vp_BFu8i_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8i_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_I");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu8i_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_I, Vp_BFu8i_I)
//============================================================================


struct  Vp_BFu8i_Ip  {
  void *v1;
  unsigned int v2:8;
  int *v3;
};
//SIG(1 Vp_BFu8i_Ip) C1{ Fp Fi:8 Fp}



static void Test_Vp_BFu8i_Ip()
{
  {
    init_simple_test("Vp_BFu8i_Ip");
    static STRUCT_IF_C Vp_BFu8i_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu8i_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_Ip");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8i_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_Ip, Vp_BFu8i_Ip)
//============================================================================


struct  Vp_BFu8i_L  {
  void *v1;
  unsigned int v2:8;
  __tsi64 v3;
};
//SIG(1 Vp_BFu8i_L) C1{ Fp Fi:8 FL}



static void Test_Vp_BFu8i_L()
{
  {
    init_simple_test("Vp_BFu8i_L");
    static STRUCT_IF_C Vp_BFu8i_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu8i_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_L");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8i_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_L, Vp_BFu8i_L)
//============================================================================


struct  Vp_BFu8i_S  {
  void *v1;
  unsigned int v2:8;
  short v3;
};
//SIG(1 Vp_BFu8i_S) C1{ Fp Fi:8 Fs}



static void Test_Vp_BFu8i_S()
{
  {
    init_simple_test("Vp_BFu8i_S");
    static STRUCT_IF_C Vp_BFu8i_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_S");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu8i_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_S, Vp_BFu8i_S)
//============================================================================


struct  Vp_BFu8i_Uc  {
  void *v1;
  unsigned int v2:8;
  unsigned char v3;
};
//SIG(1 Vp_BFu8i_Uc) C1{ Fp Fi:8 Fc}



static void Test_Vp_BFu8i_Uc()
{
  {
    init_simple_test("Vp_BFu8i_Uc");
    static STRUCT_IF_C Vp_BFu8i_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_Uc");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8i_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_Uc, Vp_BFu8i_Uc)
//============================================================================


struct  Vp_BFu8i_Ui  {
  void *v1;
  unsigned int v2:8;
  unsigned int v3;
};
//SIG(1 Vp_BFu8i_Ui) C1{ Fp Fi:8 Fi}



static void Test_Vp_BFu8i_Ui()
{
  {
    init_simple_test("Vp_BFu8i_Ui");
    static STRUCT_IF_C Vp_BFu8i_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8i_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_Ui");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu8i_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_Ui, Vp_BFu8i_Ui)
//============================================================================


struct  Vp_BFu8i_Ul  {
  void *v1;
  unsigned int v2:8;
  __tsu64 v3;
};
//SIG(1 Vp_BFu8i_Ul) C1{ Fp Fi:8 FL}



static void Test_Vp_BFu8i_Ul()
{
  {
    init_simple_test("Vp_BFu8i_Ul");
    static STRUCT_IF_C Vp_BFu8i_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu8i_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_Ul");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8i_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_Ul, Vp_BFu8i_Ul)
//============================================================================


struct  Vp_BFu8i_Us  {
  void *v1;
  unsigned int v2:8;
  unsigned short v3;
};
//SIG(1 Vp_BFu8i_Us) C1{ Fp Fi:8 Fs}



static void Test_Vp_BFu8i_Us()
{
  {
    init_simple_test("Vp_BFu8i_Us");
    static STRUCT_IF_C Vp_BFu8i_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8i_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_Us");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu8i_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_Us, Vp_BFu8i_Us)
//============================================================================


struct  Vp_BFu8i_Vp  {
  void *v1;
  unsigned int v2:8;
  void *v3;
};
//SIG(1 Vp_BFu8i_Vp) C1{ Fp Fi:8 Fp}



static void Test_Vp_BFu8i_Vp()
{
  {
    init_simple_test("Vp_BFu8i_Vp");
    static STRUCT_IF_C Vp_BFu8i_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu8i_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8i_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu8i_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8i_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8i_Vp");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8i_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8i_Vp, Vp_BFu8i_Vp)
//============================================================================


struct  Vp_BFu8ll  {
  void *v1;
  __tsu64 v2:8;
};
//SIG(1 Vp_BFu8ll) C1{ Fp FL:8}



static void Test_Vp_BFu8ll()
{
  {
    init_simple_test("Vp_BFu8ll");
    static STRUCT_IF_C Vp_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll, Vp_BFu8ll)
//============================================================================


struct  Vp_BFu8ll_BFu15i  {
  void *v1;
  __tsu64 v2:8;
  unsigned int v3:15;
};
//SIG(1 Vp_BFu8ll_BFu15i) C1{ Fp FL:8 Fi:15}



static void Test_Vp_BFu8ll_BFu15i()
{
  {
    init_simple_test("Vp_BFu8ll_BFu15i");
    static STRUCT_IF_C Vp_BFu8ll_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_BFu8ll_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_BFu8ll_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu15i, Vp_BFu8ll_BFu15i)
//============================================================================


struct  Vp_BFu8ll_BFu15ll  {
  void *v1;
  __tsu64 v2:8;
  __tsu64 v3:15;
};
//SIG(1 Vp_BFu8ll_BFu15ll) C1{ Fp FL:8 FL:15}



static void Test_Vp_BFu8ll_BFu15ll()
{
  {
    init_simple_test("Vp_BFu8ll_BFu15ll");
    static STRUCT_IF_C Vp_BFu8ll_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_BFu8ll_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_BFu8ll_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu15ll, Vp_BFu8ll_BFu15ll)
//============================================================================


struct  Vp_BFu8ll_BFu15s  {
  void *v1;
  __tsu64 v2:8;
  unsigned short v3:15;
};
//SIG(1 Vp_BFu8ll_BFu15s) C1{ Fp FL:8 Fs:15}



static void Test_Vp_BFu8ll_BFu15s()
{
  {
    init_simple_test("Vp_BFu8ll_BFu15s");
    static STRUCT_IF_C Vp_BFu8ll_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_BFu8ll_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_BFu8ll_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu15s, Vp_BFu8ll_BFu15s)
//============================================================================


struct  Vp_BFu8ll_BFu16i  {
  void *v1;
  __tsu64 v2:8;
  unsigned int v3:16;
};
//SIG(1 Vp_BFu8ll_BFu16i) C1{ Fp FL:8 Fi:16}



static void Test_Vp_BFu8ll_BFu16i()
{
  {
    init_simple_test("Vp_BFu8ll_BFu16i");
    static STRUCT_IF_C Vp_BFu8ll_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_BFu8ll_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_BFu8ll_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu16i, Vp_BFu8ll_BFu16i)
//============================================================================


struct  Vp_BFu8ll_BFu16ll  {
  void *v1;
  __tsu64 v2:8;
  __tsu64 v3:16;
};
//SIG(1 Vp_BFu8ll_BFu16ll) C1{ Fp FL:8 FL:16}



static void Test_Vp_BFu8ll_BFu16ll()
{
  {
    init_simple_test("Vp_BFu8ll_BFu16ll");
    static STRUCT_IF_C Vp_BFu8ll_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_BFu8ll_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_BFu8ll_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu16ll, Vp_BFu8ll_BFu16ll)
//============================================================================


struct  Vp_BFu8ll_BFu16s  {
  void *v1;
  __tsu64 v2:8;
  unsigned short v3:16;
};
//SIG(1 Vp_BFu8ll_BFu16s) C1{ Fp FL:8 Fs:16}



static void Test_Vp_BFu8ll_BFu16s()
{
  {
    init_simple_test("Vp_BFu8ll_BFu16s");
    static STRUCT_IF_C Vp_BFu8ll_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_BFu8ll_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_BFu8ll_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu16s, Vp_BFu8ll_BFu16s)
//============================================================================


struct  Vp_BFu8ll_BFu17i  {
  void *v1;
  __tsu64 v2:8;
  unsigned int v3:17;
};
//SIG(1 Vp_BFu8ll_BFu17i) C1{ Fp FL:8 Fi:17}



static void Test_Vp_BFu8ll_BFu17i()
{
  {
    init_simple_test("Vp_BFu8ll_BFu17i");
    static STRUCT_IF_C Vp_BFu8ll_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_BFu8ll_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_BFu8ll_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu17i, Vp_BFu8ll_BFu17i)
//============================================================================


struct  Vp_BFu8ll_BFu17ll  {
  void *v1;
  __tsu64 v2:8;
  __tsu64 v3:17;
};
//SIG(1 Vp_BFu8ll_BFu17ll) C1{ Fp FL:8 FL:17}



static void Test_Vp_BFu8ll_BFu17ll()
{
  {
    init_simple_test("Vp_BFu8ll_BFu17ll");
    static STRUCT_IF_C Vp_BFu8ll_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_BFu8ll_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_BFu8ll_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu17ll, Vp_BFu8ll_BFu17ll)
//============================================================================


struct  Vp_BFu8ll_BFu1c  {
  void *v1;
  __tsu64 v2:8;
  unsigned char v3:1;
};
//SIG(1 Vp_BFu8ll_BFu1c) C1{ Fp FL:8 Fc:1}



static void Test_Vp_BFu8ll_BFu1c()
{
  {
    init_simple_test("Vp_BFu8ll_BFu1c");
    static STRUCT_IF_C Vp_BFu8ll_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu1c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu1c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8ll_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu1c, Vp_BFu8ll_BFu1c)
//============================================================================


struct  Vp_BFu8ll_BFu1i  {
  void *v1;
  __tsu64 v2:8;
  unsigned int v3:1;
};
//SIG(1 Vp_BFu8ll_BFu1i) C1{ Fp FL:8 Fi:1}



static void Test_Vp_BFu8ll_BFu1i()
{
  {
    init_simple_test("Vp_BFu8ll_BFu1i");
    static STRUCT_IF_C Vp_BFu8ll_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu1i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu1i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8ll_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu1i, Vp_BFu8ll_BFu1i)
//============================================================================


struct  Vp_BFu8ll_BFu1ll  {
  void *v1;
  __tsu64 v2:8;
  __tsu64 v3:1;
};
//SIG(1 Vp_BFu8ll_BFu1ll) C1{ Fp FL:8 FL:1}



static void Test_Vp_BFu8ll_BFu1ll()
{
  {
    init_simple_test("Vp_BFu8ll_BFu1ll");
    static STRUCT_IF_C Vp_BFu8ll_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu1ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu1ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8ll_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu1ll, Vp_BFu8ll_BFu1ll)
//============================================================================


struct  Vp_BFu8ll_BFu1s  {
  void *v1;
  __tsu64 v2:8;
  unsigned short v3:1;
};
//SIG(1 Vp_BFu8ll_BFu1s) C1{ Fp FL:8 Fs:1}



static void Test_Vp_BFu8ll_BFu1s()
{
  {
    init_simple_test("Vp_BFu8ll_BFu1s");
    static STRUCT_IF_C Vp_BFu8ll_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu1s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu1s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8ll_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu1s, Vp_BFu8ll_BFu1s)
//============================================================================


struct  Vp_BFu8ll_BFu31i  {
  void *v1;
  __tsu64 v2:8;
  unsigned int v3:31;
};
//SIG(1 Vp_BFu8ll_BFu31i) C1{ Fp FL:8 Fi:31}



static void Test_Vp_BFu8ll_BFu31i()
{
  {
    init_simple_test("Vp_BFu8ll_BFu31i");
    static STRUCT_IF_C Vp_BFu8ll_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8ll_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_BFu8ll_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_BFu8ll_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu31i, Vp_BFu8ll_BFu31i)
//============================================================================


struct  Vp_BFu8ll_BFu31ll  {
  void *v1;
  __tsu64 v2:8;
  __tsu64 v3:31;
};
//SIG(1 Vp_BFu8ll_BFu31ll) C1{ Fp FL:8 FL:31}



static void Test_Vp_BFu8ll_BFu31ll()
{
  {
    init_simple_test("Vp_BFu8ll_BFu31ll");
    static STRUCT_IF_C Vp_BFu8ll_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8ll_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, 1, "Vp_BFu8ll_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, hide_ull(1LL<<30), "Vp_BFu8ll_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu31ll, Vp_BFu8ll_BFu31ll)
//============================================================================


struct  Vp_BFu8ll_BFu32i  {
  void *v1;
  __tsu64 v2:8;
  unsigned int v3:32;
};
//SIG(1 Vp_BFu8ll_BFu32i) C1{ Fp FL:8 Fi:32}



static void Test_Vp_BFu8ll_BFu32i()
{
  {
    init_simple_test("Vp_BFu8ll_BFu32i");
    static STRUCT_IF_C Vp_BFu8ll_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8ll_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_BFu8ll_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_BFu8ll_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu32i, Vp_BFu8ll_BFu32i)
//============================================================================


struct  Vp_BFu8ll_BFu32ll  {
  void *v1;
  __tsu64 v2:8;
  __tsu64 v3:32;
};
//SIG(1 Vp_BFu8ll_BFu32ll) C1{ Fp FL:8 FL:32}



static void Test_Vp_BFu8ll_BFu32ll()
{
  {
    init_simple_test("Vp_BFu8ll_BFu32ll");
    static STRUCT_IF_C Vp_BFu8ll_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8ll_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, 1, "Vp_BFu8ll_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, hide_ull(1LL<<31), "Vp_BFu8ll_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu32ll, Vp_BFu8ll_BFu32ll)
//============================================================================


struct  Vp_BFu8ll_BFu33  {
  void *v1;
  __tsu64 v2:8;
  __tsu64 v3:33;
};
//SIG(1 Vp_BFu8ll_BFu33) C1{ Fp FL:8 FL:33}



static void Test_Vp_BFu8ll_BFu33()
{
  {
    init_simple_test("Vp_BFu8ll_BFu33");
    static STRUCT_IF_C Vp_BFu8ll_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8ll_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, 1, "Vp_BFu8ll_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, hide_ull(1LL<<32), "Vp_BFu8ll_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu33, Vp_BFu8ll_BFu33)
//============================================================================


struct  Vp_BFu8ll_BFu7c  {
  void *v1;
  __tsu64 v2:8;
  unsigned char v3:7;
};
//SIG(1 Vp_BFu8ll_BFu7c) C1{ Fp FL:8 Fc:7}



static void Test_Vp_BFu8ll_BFu7c()
{
  {
    init_simple_test("Vp_BFu8ll_BFu7c");
    static STRUCT_IF_C Vp_BFu8ll_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8ll_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8ll_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu7c, Vp_BFu8ll_BFu7c)
//============================================================================


struct  Vp_BFu8ll_BFu7i  {
  void *v1;
  __tsu64 v2:8;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu8ll_BFu7i) C1{ Fp FL:8 Fi:7}



static void Test_Vp_BFu8ll_BFu7i()
{
  {
    init_simple_test("Vp_BFu8ll_BFu7i");
    static STRUCT_IF_C Vp_BFu8ll_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8ll_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8ll_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu7i, Vp_BFu8ll_BFu7i)
//============================================================================


struct  Vp_BFu8ll_BFu7ll  {
  void *v1;
  __tsu64 v2:8;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu8ll_BFu7ll) C1{ Fp FL:8 FL:7}



static void Test_Vp_BFu8ll_BFu7ll()
{
  {
    init_simple_test("Vp_BFu8ll_BFu7ll");
    static STRUCT_IF_C Vp_BFu8ll_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8ll_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8ll_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu7ll, Vp_BFu8ll_BFu7ll)
//============================================================================


struct  Vp_BFu8ll_BFu7s  {
  void *v1;
  __tsu64 v2:8;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu8ll_BFu7s) C1{ Fp FL:8 Fs:7}



static void Test_Vp_BFu8ll_BFu7s()
{
  {
    init_simple_test("Vp_BFu8ll_BFu7s");
    static STRUCT_IF_C Vp_BFu8ll_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8ll_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8ll_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu7s, Vp_BFu8ll_BFu7s)
//============================================================================


struct  Vp_BFu8ll_BFu8c  {
  void *v1;
  __tsu64 v2:8;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu8ll_BFu8c) C1{ Fp FL:8 Fc:8}



static void Test_Vp_BFu8ll_BFu8c()
{
  {
    init_simple_test("Vp_BFu8ll_BFu8c");
    static STRUCT_IF_C Vp_BFu8ll_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8ll_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu8c, Vp_BFu8ll_BFu8c)
//============================================================================


struct  Vp_BFu8ll_BFu8i  {
  void *v1;
  __tsu64 v2:8;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu8ll_BFu8i) C1{ Fp FL:8 Fi:8}



static void Test_Vp_BFu8ll_BFu8i()
{
  {
    init_simple_test("Vp_BFu8ll_BFu8i");
    static STRUCT_IF_C Vp_BFu8ll_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8ll_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu8i, Vp_BFu8ll_BFu8i)
//============================================================================


struct  Vp_BFu8ll_BFu8ll  {
  void *v1;
  __tsu64 v2:8;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu8ll_BFu8ll) C1{ Fp FL:8 FL:8}



static void Test_Vp_BFu8ll_BFu8ll()
{
  {
    init_simple_test("Vp_BFu8ll_BFu8ll");
    static STRUCT_IF_C Vp_BFu8ll_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8ll_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu8ll, Vp_BFu8ll_BFu8ll)
//============================================================================


struct  Vp_BFu8ll_BFu8s  {
  void *v1;
  __tsu64 v2:8;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu8ll_BFu8s) C1{ Fp FL:8 Fs:8}



static void Test_Vp_BFu8ll_BFu8s()
{
  {
    init_simple_test("Vp_BFu8ll_BFu8s");
    static STRUCT_IF_C Vp_BFu8ll_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8ll_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu8s, Vp_BFu8ll_BFu8s)
//============================================================================


struct  Vp_BFu8ll_BFu9i  {
  void *v1;
  __tsu64 v2:8;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu8ll_BFu9i) C1{ Fp FL:8 Fi:9}



static void Test_Vp_BFu8ll_BFu9i()
{
  {
    init_simple_test("Vp_BFu8ll_BFu9i");
    static STRUCT_IF_C Vp_BFu8ll_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_BFu8ll_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_BFu8ll_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu9i, Vp_BFu8ll_BFu9i)
//============================================================================


struct  Vp_BFu8ll_BFu9ll  {
  void *v1;
  __tsu64 v2:8;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu8ll_BFu9ll) C1{ Fp FL:8 FL:9}



static void Test_Vp_BFu8ll_BFu9ll()
{
  {
    init_simple_test("Vp_BFu8ll_BFu9ll");
    static STRUCT_IF_C Vp_BFu8ll_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_BFu8ll_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_BFu8ll_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu9ll, Vp_BFu8ll_BFu9ll)
//============================================================================


struct  Vp_BFu8ll_BFu9s  {
  void *v1;
  __tsu64 v2:8;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu8ll_BFu9s) C1{ Fp FL:8 Fs:9}



static void Test_Vp_BFu8ll_BFu9s()
{
  {
    init_simple_test("Vp_BFu8ll_BFu9s");
    static STRUCT_IF_C Vp_BFu8ll_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_BFu8ll_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_BFu8ll_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_BFu9s, Vp_BFu8ll_BFu9s)
//============================================================================


struct  Vp_BFu8ll_C  {
  void *v1;
  __tsu64 v2:8;
  char v3;
};
//SIG(1 Vp_BFu8ll_C) C1{ Fp FL:8 Fc}



static void Test_Vp_BFu8ll_C()
{
  {
    init_simple_test("Vp_BFu8ll_C");
    static STRUCT_IF_C Vp_BFu8ll_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_C");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8ll_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_C, Vp_BFu8ll_C)
//============================================================================


struct  Vp_BFu8ll_D  {
  void *v1;
  __tsu64 v2:8;
  double v3;
};
//SIG(1 Vp_BFu8ll_D) C1{ Fp FL:8 FL}



static void Test_Vp_BFu8ll_D()
{
  {
    init_simple_test("Vp_BFu8ll_D");
    static STRUCT_IF_C Vp_BFu8ll_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu8ll_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_D");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8ll_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_D, Vp_BFu8ll_D)
//============================================================================


struct  Vp_BFu8ll_F  {
  void *v1;
  __tsu64 v2:8;
  float v3;
};
//SIG(1 Vp_BFu8ll_F) C1{ Fp FL:8 Fi}



static void Test_Vp_BFu8ll_F()
{
  {
    init_simple_test("Vp_BFu8ll_F");
    static STRUCT_IF_C Vp_BFu8ll_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8ll_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_F");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu8ll_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_F, Vp_BFu8ll_F)
//============================================================================


struct  Vp_BFu8ll_I  {
  void *v1;
  __tsu64 v2:8;
  int v3;
};
//SIG(1 Vp_BFu8ll_I) C1{ Fp FL:8 Fi}



static void Test_Vp_BFu8ll_I()
{
  {
    init_simple_test("Vp_BFu8ll_I");
    static STRUCT_IF_C Vp_BFu8ll_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8ll_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_I");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu8ll_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_I, Vp_BFu8ll_I)
//============================================================================


struct  Vp_BFu8ll_Ip  {
  void *v1;
  __tsu64 v2:8;
  int *v3;
};
//SIG(1 Vp_BFu8ll_Ip) C1{ Fp FL:8 Fp}



static void Test_Vp_BFu8ll_Ip()
{
  {
    init_simple_test("Vp_BFu8ll_Ip");
    static STRUCT_IF_C Vp_BFu8ll_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu8ll_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_Ip");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8ll_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_Ip, Vp_BFu8ll_Ip)
//============================================================================


struct  Vp_BFu8ll_L  {
  void *v1;
  __tsu64 v2:8;
  __tsi64 v3;
};
//SIG(1 Vp_BFu8ll_L) C1{ Fp FL:8 FL}



static void Test_Vp_BFu8ll_L()
{
  {
    init_simple_test("Vp_BFu8ll_L");
    static STRUCT_IF_C Vp_BFu8ll_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu8ll_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_L");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8ll_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_L, Vp_BFu8ll_L)
//============================================================================


struct  Vp_BFu8ll_S  {
  void *v1;
  __tsu64 v2:8;
  short v3;
};
//SIG(1 Vp_BFu8ll_S) C1{ Fp FL:8 Fs}



static void Test_Vp_BFu8ll_S()
{
  {
    init_simple_test("Vp_BFu8ll_S");
    static STRUCT_IF_C Vp_BFu8ll_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_S");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu8ll_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_S, Vp_BFu8ll_S)
//============================================================================


struct  Vp_BFu8ll_Uc  {
  void *v1;
  __tsu64 v2:8;
  unsigned char v3;
};
//SIG(1 Vp_BFu8ll_Uc) C1{ Fp FL:8 Fc}



static void Test_Vp_BFu8ll_Uc()
{
  {
    init_simple_test("Vp_BFu8ll_Uc");
    static STRUCT_IF_C Vp_BFu8ll_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_Uc");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8ll_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_Uc, Vp_BFu8ll_Uc)
//============================================================================


struct  Vp_BFu8ll_Ui  {
  void *v1;
  __tsu64 v2:8;
  unsigned int v3;
};
//SIG(1 Vp_BFu8ll_Ui) C1{ Fp FL:8 Fi}



static void Test_Vp_BFu8ll_Ui()
{
  {
    init_simple_test("Vp_BFu8ll_Ui");
    static STRUCT_IF_C Vp_BFu8ll_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8ll_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_Ui");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu8ll_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_Ui, Vp_BFu8ll_Ui)
//============================================================================


struct  Vp_BFu8ll_Ul  {
  void *v1;
  __tsu64 v2:8;
  __tsu64 v3;
};
//SIG(1 Vp_BFu8ll_Ul) C1{ Fp FL:8 FL}



static void Test_Vp_BFu8ll_Ul()
{
  {
    init_simple_test("Vp_BFu8ll_Ul");
    static STRUCT_IF_C Vp_BFu8ll_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu8ll_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_Ul");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8ll_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_Ul, Vp_BFu8ll_Ul)
//============================================================================


struct  Vp_BFu8ll_Us  {
  void *v1;
  __tsu64 v2:8;
  unsigned short v3;
};
//SIG(1 Vp_BFu8ll_Us) C1{ Fp FL:8 Fs}



static void Test_Vp_BFu8ll_Us()
{
  {
    init_simple_test("Vp_BFu8ll_Us");
    static STRUCT_IF_C Vp_BFu8ll_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8ll_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_Us");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu8ll_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_Us, Vp_BFu8ll_Us)
//============================================================================


struct  Vp_BFu8ll_Vp  {
  void *v1;
  __tsu64 v2:8;
  void *v3;
};
//SIG(1 Vp_BFu8ll_Vp) C1{ Fp FL:8 Fp}



static void Test_Vp_BFu8ll_Vp()
{
  {
    init_simple_test("Vp_BFu8ll_Vp");
    static STRUCT_IF_C Vp_BFu8ll_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu8ll_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8ll_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu8ll_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8ll_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8ll_Vp");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8ll_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8ll_Vp, Vp_BFu8ll_Vp)
//============================================================================


struct  Vp_BFu8s  {
  void *v1;
  unsigned short v2:8;
};
//SIG(1 Vp_BFu8s) C1{ Fp Fs:8}



static void Test_Vp_BFu8s()
{
  {
    init_simple_test("Vp_BFu8s");
    static STRUCT_IF_C Vp_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s, Vp_BFu8s)
//============================================================================


struct  Vp_BFu8s_BFu15i  {
  void *v1;
  unsigned short v2:8;
  unsigned int v3:15;
};
//SIG(1 Vp_BFu8s_BFu15i) C1{ Fp Fs:8 Fi:15}



static void Test_Vp_BFu8s_BFu15i()
{
  {
    init_simple_test("Vp_BFu8s_BFu15i");
    static STRUCT_IF_C Vp_BFu8s_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_BFu8s_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_BFu8s_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu15i, Vp_BFu8s_BFu15i)
//============================================================================


struct  Vp_BFu8s_BFu15ll  {
  void *v1;
  unsigned short v2:8;
  __tsu64 v3:15;
};
//SIG(1 Vp_BFu8s_BFu15ll) C1{ Fp Fs:8 FL:15}



static void Test_Vp_BFu8s_BFu15ll()
{
  {
    init_simple_test("Vp_BFu8s_BFu15ll");
    static STRUCT_IF_C Vp_BFu8s_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_BFu8s_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_BFu8s_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu15ll, Vp_BFu8s_BFu15ll)
//============================================================================


struct  Vp_BFu8s_BFu15s  {
  void *v1;
  unsigned short v2:8;
  unsigned short v3:15;
};
//SIG(1 Vp_BFu8s_BFu15s) C1{ Fp Fs:8 Fs:15}



static void Test_Vp_BFu8s_BFu15s()
{
  {
    init_simple_test("Vp_BFu8s_BFu15s");
    static STRUCT_IF_C Vp_BFu8s_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_BFu8s_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_BFu8s_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu15s, Vp_BFu8s_BFu15s)
//============================================================================


struct  Vp_BFu8s_BFu16i  {
  void *v1;
  unsigned short v2:8;
  unsigned int v3:16;
};
//SIG(1 Vp_BFu8s_BFu16i) C1{ Fp Fs:8 Fi:16}



static void Test_Vp_BFu8s_BFu16i()
{
  {
    init_simple_test("Vp_BFu8s_BFu16i");
    static STRUCT_IF_C Vp_BFu8s_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_BFu8s_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_BFu8s_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu16i, Vp_BFu8s_BFu16i)
//============================================================================


struct  Vp_BFu8s_BFu16ll  {
  void *v1;
  unsigned short v2:8;
  __tsu64 v3:16;
};
//SIG(1 Vp_BFu8s_BFu16ll) C1{ Fp Fs:8 FL:16}



static void Test_Vp_BFu8s_BFu16ll()
{
  {
    init_simple_test("Vp_BFu8s_BFu16ll");
    static STRUCT_IF_C Vp_BFu8s_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_BFu8s_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_BFu8s_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu16ll, Vp_BFu8s_BFu16ll)
//============================================================================


struct  Vp_BFu8s_BFu16s  {
  void *v1;
  unsigned short v2:8;
  unsigned short v3:16;
};
//SIG(1 Vp_BFu8s_BFu16s) C1{ Fp Fs:8 Fs:16}



static void Test_Vp_BFu8s_BFu16s()
{
  {
    init_simple_test("Vp_BFu8s_BFu16s");
    static STRUCT_IF_C Vp_BFu8s_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_BFu8s_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_BFu8s_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu16s, Vp_BFu8s_BFu16s)
//============================================================================


struct  Vp_BFu8s_BFu17i  {
  void *v1;
  unsigned short v2:8;
  unsigned int v3:17;
};
//SIG(1 Vp_BFu8s_BFu17i) C1{ Fp Fs:8 Fi:17}



static void Test_Vp_BFu8s_BFu17i()
{
  {
    init_simple_test("Vp_BFu8s_BFu17i");
    static STRUCT_IF_C Vp_BFu8s_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_BFu8s_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_BFu8s_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu17i, Vp_BFu8s_BFu17i)
//============================================================================


struct  Vp_BFu8s_BFu17ll  {
  void *v1;
  unsigned short v2:8;
  __tsu64 v3:17;
};
//SIG(1 Vp_BFu8s_BFu17ll) C1{ Fp Fs:8 FL:17}



static void Test_Vp_BFu8s_BFu17ll()
{
  {
    init_simple_test("Vp_BFu8s_BFu17ll");
    static STRUCT_IF_C Vp_BFu8s_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_BFu8s_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_BFu8s_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu17ll, Vp_BFu8s_BFu17ll)
//============================================================================


struct  Vp_BFu8s_BFu1c  {
  void *v1;
  unsigned short v2:8;
  unsigned char v3:1;
};
//SIG(1 Vp_BFu8s_BFu1c) C1{ Fp Fs:8 Fc:1}



static void Test_Vp_BFu8s_BFu1c()
{
  {
    init_simple_test("Vp_BFu8s_BFu1c");
    static STRUCT_IF_C Vp_BFu8s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu1c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu1c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8s_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu1c, Vp_BFu8s_BFu1c)
//============================================================================


struct  Vp_BFu8s_BFu1i  {
  void *v1;
  unsigned short v2:8;
  unsigned int v3:1;
};
//SIG(1 Vp_BFu8s_BFu1i) C1{ Fp Fs:8 Fi:1}



static void Test_Vp_BFu8s_BFu1i()
{
  {
    init_simple_test("Vp_BFu8s_BFu1i");
    static STRUCT_IF_C Vp_BFu8s_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu1i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu1i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8s_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu1i, Vp_BFu8s_BFu1i)
//============================================================================


struct  Vp_BFu8s_BFu1ll  {
  void *v1;
  unsigned short v2:8;
  __tsu64 v3:1;
};
//SIG(1 Vp_BFu8s_BFu1ll) C1{ Fp Fs:8 FL:1}



static void Test_Vp_BFu8s_BFu1ll()
{
  {
    init_simple_test("Vp_BFu8s_BFu1ll");
    static STRUCT_IF_C Vp_BFu8s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu1ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu1ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8s_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu1ll, Vp_BFu8s_BFu1ll)
//============================================================================


struct  Vp_BFu8s_BFu1s  {
  void *v1;
  unsigned short v2:8;
  unsigned short v3:1;
};
//SIG(1 Vp_BFu8s_BFu1s) C1{ Fp Fs:8 Fs:1}



static void Test_Vp_BFu8s_BFu1s()
{
  {
    init_simple_test("Vp_BFu8s_BFu1s");
    static STRUCT_IF_C Vp_BFu8s_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu1s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu1s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_BFu8s_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu1s, Vp_BFu8s_BFu1s)
//============================================================================


struct  Vp_BFu8s_BFu31i  {
  void *v1;
  unsigned short v2:8;
  unsigned int v3:31;
};
//SIG(1 Vp_BFu8s_BFu31i) C1{ Fp Fs:8 Fi:31}



static void Test_Vp_BFu8s_BFu31i()
{
  {
    init_simple_test("Vp_BFu8s_BFu31i");
    static STRUCT_IF_C Vp_BFu8s_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8s_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_BFu8s_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_BFu8s_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu31i, Vp_BFu8s_BFu31i)
//============================================================================


struct  Vp_BFu8s_BFu31ll  {
  void *v1;
  unsigned short v2:8;
  __tsu64 v3:31;
};
//SIG(1 Vp_BFu8s_BFu31ll) C1{ Fp Fs:8 FL:31}



static void Test_Vp_BFu8s_BFu31ll()
{
  {
    init_simple_test("Vp_BFu8s_BFu31ll");
    static STRUCT_IF_C Vp_BFu8s_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, 1, "Vp_BFu8s_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, hide_ull(1LL<<30), "Vp_BFu8s_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu31ll, Vp_BFu8s_BFu31ll)
//============================================================================


struct  Vp_BFu8s_BFu32i  {
  void *v1;
  unsigned short v2:8;
  unsigned int v3:32;
};
//SIG(1 Vp_BFu8s_BFu32i) C1{ Fp Fs:8 Fi:32}



static void Test_Vp_BFu8s_BFu32i()
{
  {
    init_simple_test("Vp_BFu8s_BFu32i");
    static STRUCT_IF_C Vp_BFu8s_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8s_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_BFu8s_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_BFu8s_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu32i, Vp_BFu8s_BFu32i)
//============================================================================


struct  Vp_BFu8s_BFu32ll  {
  void *v1;
  unsigned short v2:8;
  __tsu64 v3:32;
};
//SIG(1 Vp_BFu8s_BFu32ll) C1{ Fp Fs:8 FL:32}



static void Test_Vp_BFu8s_BFu32ll()
{
  {
    init_simple_test("Vp_BFu8s_BFu32ll");
    static STRUCT_IF_C Vp_BFu8s_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, 1, "Vp_BFu8s_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, hide_ull(1LL<<31), "Vp_BFu8s_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu32ll, Vp_BFu8s_BFu32ll)
//============================================================================


struct  Vp_BFu8s_BFu33  {
  void *v1;
  unsigned short v2:8;
  __tsu64 v3:33;
};
//SIG(1 Vp_BFu8s_BFu33) C1{ Fp Fs:8 FL:33}



static void Test_Vp_BFu8s_BFu33()
{
  {
    init_simple_test("Vp_BFu8s_BFu33");
    static STRUCT_IF_C Vp_BFu8s_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8s_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, 1, "Vp_BFu8s_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, hide_ull(1LL<<32), "Vp_BFu8s_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu33, Vp_BFu8s_BFu33)
//============================================================================


struct  Vp_BFu8s_BFu7c  {
  void *v1;
  unsigned short v2:8;
  unsigned char v3:7;
};
//SIG(1 Vp_BFu8s_BFu7c) C1{ Fp Fs:8 Fc:7}



static void Test_Vp_BFu8s_BFu7c()
{
  {
    init_simple_test("Vp_BFu8s_BFu7c");
    static STRUCT_IF_C Vp_BFu8s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8s_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8s_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu7c, Vp_BFu8s_BFu7c)
//============================================================================


struct  Vp_BFu8s_BFu7i  {
  void *v1;
  unsigned short v2:8;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu8s_BFu7i) C1{ Fp Fs:8 Fi:7}



static void Test_Vp_BFu8s_BFu7i()
{
  {
    init_simple_test("Vp_BFu8s_BFu7i");
    static STRUCT_IF_C Vp_BFu8s_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8s_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8s_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu7i, Vp_BFu8s_BFu7i)
//============================================================================


struct  Vp_BFu8s_BFu7ll  {
  void *v1;
  unsigned short v2:8;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu8s_BFu7ll) C1{ Fp Fs:8 FL:7}



static void Test_Vp_BFu8s_BFu7ll()
{
  {
    init_simple_test("Vp_BFu8s_BFu7ll");
    static STRUCT_IF_C Vp_BFu8s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8s_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8s_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu7ll, Vp_BFu8s_BFu7ll)
//============================================================================


struct  Vp_BFu8s_BFu7s  {
  void *v1;
  unsigned short v2:8;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu8s_BFu7s) C1{ Fp Fs:8 Fs:7}



static void Test_Vp_BFu8s_BFu7s()
{
  {
    init_simple_test("Vp_BFu8s_BFu7s");
    static STRUCT_IF_C Vp_BFu8s_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_BFu8s_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_BFu8s_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu7s, Vp_BFu8s_BFu7s)
//============================================================================


struct  Vp_BFu8s_BFu8c  {
  void *v1;
  unsigned short v2:8;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu8s_BFu8c) C1{ Fp Fs:8 Fc:8}



static void Test_Vp_BFu8s_BFu8c()
{
  {
    init_simple_test("Vp_BFu8s_BFu8c");
    static STRUCT_IF_C Vp_BFu8s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8s_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu8c, Vp_BFu8s_BFu8c)
//============================================================================


struct  Vp_BFu8s_BFu8i  {
  void *v1;
  unsigned short v2:8;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu8s_BFu8i) C1{ Fp Fs:8 Fi:8}



static void Test_Vp_BFu8s_BFu8i()
{
  {
    init_simple_test("Vp_BFu8s_BFu8i");
    static STRUCT_IF_C Vp_BFu8s_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8s_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu8i, Vp_BFu8s_BFu8i)
//============================================================================


struct  Vp_BFu8s_BFu8ll  {
  void *v1;
  unsigned short v2:8;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu8s_BFu8ll) C1{ Fp Fs:8 FL:8}



static void Test_Vp_BFu8s_BFu8ll()
{
  {
    init_simple_test("Vp_BFu8s_BFu8ll");
    static STRUCT_IF_C Vp_BFu8s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8s_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu8ll, Vp_BFu8s_BFu8ll)
//============================================================================


struct  Vp_BFu8s_BFu8s  {
  void *v1;
  unsigned short v2:8;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu8s_BFu8s) C1{ Fp Fs:8 Fs:8}



static void Test_Vp_BFu8s_BFu8s()
{
  {
    init_simple_test("Vp_BFu8s_BFu8s");
    static STRUCT_IF_C Vp_BFu8s_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_BFu8s_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu8s, Vp_BFu8s_BFu8s)
//============================================================================


struct  Vp_BFu8s_BFu9i  {
  void *v1;
  unsigned short v2:8;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu8s_BFu9i) C1{ Fp Fs:8 Fi:9}



static void Test_Vp_BFu8s_BFu9i()
{
  {
    init_simple_test("Vp_BFu8s_BFu9i");
    static STRUCT_IF_C Vp_BFu8s_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_BFu8s_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_BFu8s_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu9i, Vp_BFu8s_BFu9i)
//============================================================================


struct  Vp_BFu8s_BFu9ll  {
  void *v1;
  unsigned short v2:8;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu8s_BFu9ll) C1{ Fp Fs:8 FL:9}



static void Test_Vp_BFu8s_BFu9ll()
{
  {
    init_simple_test("Vp_BFu8s_BFu9ll");
    static STRUCT_IF_C Vp_BFu8s_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_BFu8s_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_BFu8s_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu9ll, Vp_BFu8s_BFu9ll)
//============================================================================


struct  Vp_BFu8s_BFu9s  {
  void *v1;
  unsigned short v2:8;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu8s_BFu9s) C1{ Fp Fs:8 Fs:9}



static void Test_Vp_BFu8s_BFu9s()
{
  {
    init_simple_test("Vp_BFu8s_BFu9s");
    static STRUCT_IF_C Vp_BFu8s_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_BFu8s_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_BFu8s_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_BFu9s, Vp_BFu8s_BFu9s)
//============================================================================


struct  Vp_BFu8s_C  {
  void *v1;
  unsigned short v2:8;
  char v3;
};
//SIG(1 Vp_BFu8s_C) C1{ Fp Fs:8 Fc}



static void Test_Vp_BFu8s_C()
{
  {
    init_simple_test("Vp_BFu8s_C");
    static STRUCT_IF_C Vp_BFu8s_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_C");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8s_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_C, Vp_BFu8s_C)
//============================================================================


struct  Vp_BFu8s_D  {
  void *v1;
  unsigned short v2:8;
  double v3;
};
//SIG(1 Vp_BFu8s_D) C1{ Fp Fs:8 FL}



static void Test_Vp_BFu8s_D()
{
  {
    init_simple_test("Vp_BFu8s_D");
    static STRUCT_IF_C Vp_BFu8s_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu8s_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_D");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8s_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_D, Vp_BFu8s_D)
//============================================================================


struct  Vp_BFu8s_F  {
  void *v1;
  unsigned short v2:8;
  float v3;
};
//SIG(1 Vp_BFu8s_F) C1{ Fp Fs:8 Fi}



static void Test_Vp_BFu8s_F()
{
  {
    init_simple_test("Vp_BFu8s_F");
    static STRUCT_IF_C Vp_BFu8s_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8s_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_F");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu8s_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_F, Vp_BFu8s_F)
//============================================================================


struct  Vp_BFu8s_I  {
  void *v1;
  unsigned short v2:8;
  int v3;
};
//SIG(1 Vp_BFu8s_I) C1{ Fp Fs:8 Fi}



static void Test_Vp_BFu8s_I()
{
  {
    init_simple_test("Vp_BFu8s_I");
    static STRUCT_IF_C Vp_BFu8s_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8s_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_I");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu8s_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_I, Vp_BFu8s_I)
//============================================================================


struct  Vp_BFu8s_Ip  {
  void *v1;
  unsigned short v2:8;
  int *v3;
};
//SIG(1 Vp_BFu8s_Ip) C1{ Fp Fs:8 Fp}



static void Test_Vp_BFu8s_Ip()
{
  {
    init_simple_test("Vp_BFu8s_Ip");
    static STRUCT_IF_C Vp_BFu8s_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu8s_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_Ip");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8s_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_Ip, Vp_BFu8s_Ip)
//============================================================================


struct  Vp_BFu8s_L  {
  void *v1;
  unsigned short v2:8;
  __tsi64 v3;
};
//SIG(1 Vp_BFu8s_L) C1{ Fp Fs:8 FL}



static void Test_Vp_BFu8s_L()
{
  {
    init_simple_test("Vp_BFu8s_L");
    static STRUCT_IF_C Vp_BFu8s_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu8s_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_L");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8s_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_L, Vp_BFu8s_L)
//============================================================================


struct  Vp_BFu8s_S  {
  void *v1;
  unsigned short v2:8;
  short v3;
};
//SIG(1 Vp_BFu8s_S) C1{ Fp Fs:8 Fs}



static void Test_Vp_BFu8s_S()
{
  {
    init_simple_test("Vp_BFu8s_S");
    static STRUCT_IF_C Vp_BFu8s_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_S");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu8s_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_S, Vp_BFu8s_S)
//============================================================================


struct  Vp_BFu8s_Uc  {
  void *v1;
  unsigned short v2:8;
  unsigned char v3;
};
//SIG(1 Vp_BFu8s_Uc) C1{ Fp Fs:8 Fc}



static void Test_Vp_BFu8s_Uc()
{
  {
    init_simple_test("Vp_BFu8s_Uc");
    static STRUCT_IF_C Vp_BFu8s_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_Uc");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_BFu8s_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_Uc, Vp_BFu8s_Uc)
//============================================================================


struct  Vp_BFu8s_Ui  {
  void *v1;
  unsigned short v2:8;
  unsigned int v3;
};
//SIG(1 Vp_BFu8s_Ui) C1{ Fp Fs:8 Fi}



static void Test_Vp_BFu8s_Ui()
{
  {
    init_simple_test("Vp_BFu8s_Ui");
    static STRUCT_IF_C Vp_BFu8s_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu8s_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_Ui");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu8s_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_Ui, Vp_BFu8s_Ui)
//============================================================================


struct  Vp_BFu8s_Ul  {
  void *v1;
  unsigned short v2:8;
  __tsu64 v3;
};
//SIG(1 Vp_BFu8s_Ul) C1{ Fp Fs:8 FL}



static void Test_Vp_BFu8s_Ul()
{
  {
    init_simple_test("Vp_BFu8s_Ul");
    static STRUCT_IF_C Vp_BFu8s_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu8s_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_Ul");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8s_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_Ul, Vp_BFu8s_Ul)
//============================================================================


struct  Vp_BFu8s_Us  {
  void *v1;
  unsigned short v2:8;
  unsigned short v3;
};
//SIG(1 Vp_BFu8s_Us) C1{ Fp Fs:8 Fs}



static void Test_Vp_BFu8s_Us()
{
  {
    init_simple_test("Vp_BFu8s_Us");
    static STRUCT_IF_C Vp_BFu8s_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu8s_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_Us");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu8s_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_Us, Vp_BFu8s_Us)
//============================================================================


struct  Vp_BFu8s_Vp  {
  void *v1;
  unsigned short v2:8;
  void *v3;
};
//SIG(1 Vp_BFu8s_Vp) C1{ Fp Fs:8 Fp}



static void Test_Vp_BFu8s_Vp()
{
  {
    init_simple_test("Vp_BFu8s_Vp");
    static STRUCT_IF_C Vp_BFu8s_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu8s_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu8s_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu8s_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, 1, "Vp_BFu8s_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 8, hide_ull(1LL<<7), "Vp_BFu8s_Vp");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu8s_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu8s_Vp, Vp_BFu8s_Vp)
//============================================================================


struct  Vp_BFu9i  {
  void *v1;
  unsigned int v2:9;
};
//SIG(1 Vp_BFu9i) C1{ Fp Fi:9}



static void Test_Vp_BFu9i()
{
  {
    init_simple_test("Vp_BFu9i");
    static STRUCT_IF_C Vp_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i, Vp_BFu9i)
//============================================================================


struct  Vp_BFu9i_BFu15i  {
  void *v1;
  unsigned int v2:9;
  unsigned int v3:15;
};
//SIG(1 Vp_BFu9i_BFu15i) C1{ Fp Fi:9 Fi:15}



static void Test_Vp_BFu9i_BFu15i()
{
  {
    init_simple_test("Vp_BFu9i_BFu15i");
    static STRUCT_IF_C Vp_BFu9i_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 15, 1, "Vp_BFu9i_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 15, hide_ull(1LL<<14), "Vp_BFu9i_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu15i, Vp_BFu9i_BFu15i)
//============================================================================


struct  Vp_BFu9i_BFu15ll  {
  void *v1;
  unsigned int v2:9;
  __tsu64 v3:15;
};
//SIG(1 Vp_BFu9i_BFu15ll) C1{ Fp Fi:9 FL:15}



static void Test_Vp_BFu9i_BFu15ll()
{
  {
    init_simple_test("Vp_BFu9i_BFu15ll");
    static STRUCT_IF_C Vp_BFu9i_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 15, 1, "Vp_BFu9i_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 15, hide_ull(1LL<<14), "Vp_BFu9i_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu15ll, Vp_BFu9i_BFu15ll)
//============================================================================


struct  Vp_BFu9i_BFu15s  {
  void *v1;
  unsigned int v2:9;
  unsigned short v3:15;
};
//SIG(1 Vp_BFu9i_BFu15s) C1{ Fp Fi:9 Fs:15}



static void Test_Vp_BFu9i_BFu15s()
{
  {
    init_simple_test("Vp_BFu9i_BFu15s");
    static STRUCT_IF_C Vp_BFu9i_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_BFu9i_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_BFu9i_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu15s, Vp_BFu9i_BFu15s)
//============================================================================


struct  Vp_BFu9i_BFu16i  {
  void *v1;
  unsigned int v2:9;
  unsigned int v3:16;
};
//SIG(1 Vp_BFu9i_BFu16i) C1{ Fp Fi:9 Fi:16}



static void Test_Vp_BFu9i_BFu16i()
{
  {
    init_simple_test("Vp_BFu9i_BFu16i");
    static STRUCT_IF_C Vp_BFu9i_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 16, 1, "Vp_BFu9i_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 16, hide_ull(1LL<<15), "Vp_BFu9i_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu16i, Vp_BFu9i_BFu16i)
//============================================================================


struct  Vp_BFu9i_BFu16ll  {
  void *v1;
  unsigned int v2:9;
  __tsu64 v3:16;
};
//SIG(1 Vp_BFu9i_BFu16ll) C1{ Fp Fi:9 FL:16}



static void Test_Vp_BFu9i_BFu16ll()
{
  {
    init_simple_test("Vp_BFu9i_BFu16ll");
    static STRUCT_IF_C Vp_BFu9i_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 16, 1, "Vp_BFu9i_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 16, hide_ull(1LL<<15), "Vp_BFu9i_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu16ll, Vp_BFu9i_BFu16ll)
//============================================================================


struct  Vp_BFu9i_BFu16s  {
  void *v1;
  unsigned int v2:9;
  unsigned short v3:16;
};
//SIG(1 Vp_BFu9i_BFu16s) C1{ Fp Fi:9 Fs:16}



static void Test_Vp_BFu9i_BFu16s()
{
  {
    init_simple_test("Vp_BFu9i_BFu16s");
    static STRUCT_IF_C Vp_BFu9i_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_BFu9i_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_BFu9i_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu16s, Vp_BFu9i_BFu16s)
//============================================================================


struct  Vp_BFu9i_BFu17i  {
  void *v1;
  unsigned int v2:9;
  unsigned int v3:17;
};
//SIG(1 Vp_BFu9i_BFu17i) C1{ Fp Fi:9 Fi:17}



static void Test_Vp_BFu9i_BFu17i()
{
  {
    init_simple_test("Vp_BFu9i_BFu17i");
    static STRUCT_IF_C Vp_BFu9i_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 17, 1, "Vp_BFu9i_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 17, hide_ull(1LL<<16), "Vp_BFu9i_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu17i, Vp_BFu9i_BFu17i)
//============================================================================


struct  Vp_BFu9i_BFu17ll  {
  void *v1;
  unsigned int v2:9;
  __tsu64 v3:17;
};
//SIG(1 Vp_BFu9i_BFu17ll) C1{ Fp Fi:9 FL:17}



static void Test_Vp_BFu9i_BFu17ll()
{
  {
    init_simple_test("Vp_BFu9i_BFu17ll");
    static STRUCT_IF_C Vp_BFu9i_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 17, 1, "Vp_BFu9i_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 17, hide_ull(1LL<<16), "Vp_BFu9i_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu17ll, Vp_BFu9i_BFu17ll)
//============================================================================


struct  Vp_BFu9i_BFu1c  {
  void *v1;
  unsigned int v2:9;
  unsigned char v3:1;
};
//SIG(1 Vp_BFu9i_BFu1c) C1{ Fp Fi:9 Fc:1}



static void Test_Vp_BFu9i_BFu1c()
{
  {
    init_simple_test("Vp_BFu9i_BFu1c");
    static STRUCT_IF_C Vp_BFu9i_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu1c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu1c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 1, 1, "Vp_BFu9i_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu1c, Vp_BFu9i_BFu1c)
//============================================================================


struct  Vp_BFu9i_BFu1i  {
  void *v1;
  unsigned int v2:9;
  unsigned int v3:1;
};
//SIG(1 Vp_BFu9i_BFu1i) C1{ Fp Fi:9 Fi:1}



static void Test_Vp_BFu9i_BFu1i()
{
  {
    init_simple_test("Vp_BFu9i_BFu1i");
    static STRUCT_IF_C Vp_BFu9i_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu1i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu1i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 1, 1, "Vp_BFu9i_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu1i, Vp_BFu9i_BFu1i)
//============================================================================


struct  Vp_BFu9i_BFu1ll  {
  void *v1;
  unsigned int v2:9;
  __tsu64 v3:1;
};
//SIG(1 Vp_BFu9i_BFu1ll) C1{ Fp Fi:9 FL:1}



static void Test_Vp_BFu9i_BFu1ll()
{
  {
    init_simple_test("Vp_BFu9i_BFu1ll");
    static STRUCT_IF_C Vp_BFu9i_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu1ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu1ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 1, 1, "Vp_BFu9i_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu1ll, Vp_BFu9i_BFu1ll)
//============================================================================


struct  Vp_BFu9i_BFu1s  {
  void *v1;
  unsigned int v2:9;
  unsigned short v3:1;
};
//SIG(1 Vp_BFu9i_BFu1s) C1{ Fp Fi:9 Fs:1}



static void Test_Vp_BFu9i_BFu1s()
{
  {
    init_simple_test("Vp_BFu9i_BFu1s");
    static STRUCT_IF_C Vp_BFu9i_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu1s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu1s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 1, 1, "Vp_BFu9i_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu1s, Vp_BFu9i_BFu1s)
//============================================================================


struct  Vp_BFu9i_BFu31i  {
  void *v1;
  unsigned int v2:9;
  unsigned int v3:31;
};
//SIG(1 Vp_BFu9i_BFu31i) C1{ Fp Fi:9 Fi:31}



static void Test_Vp_BFu9i_BFu31i()
{
  {
    init_simple_test("Vp_BFu9i_BFu31i");
    static STRUCT_IF_C Vp_BFu9i_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9i_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_BFu9i_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_BFu9i_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu31i, Vp_BFu9i_BFu31i)
//============================================================================


struct  Vp_BFu9i_BFu31ll  {
  void *v1;
  unsigned int v2:9;
  __tsu64 v3:31;
};
//SIG(1 Vp_BFu9i_BFu31ll) C1{ Fp Fi:9 FL:31}



static void Test_Vp_BFu9i_BFu31ll()
{
  {
    init_simple_test("Vp_BFu9i_BFu31ll");
    static STRUCT_IF_C Vp_BFu9i_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9i_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 31, 1, "Vp_BFu9i_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 31, hide_ull(1LL<<30), "Vp_BFu9i_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu31ll, Vp_BFu9i_BFu31ll)
//============================================================================


struct  Vp_BFu9i_BFu32i  {
  void *v1;
  unsigned int v2:9;
  unsigned int v3:32;
};
//SIG(1 Vp_BFu9i_BFu32i) C1{ Fp Fi:9 Fi:32}



static void Test_Vp_BFu9i_BFu32i()
{
  {
    init_simple_test("Vp_BFu9i_BFu32i");
    static STRUCT_IF_C Vp_BFu9i_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9i_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_BFu9i_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_BFu9i_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu32i, Vp_BFu9i_BFu32i)
//============================================================================


struct  Vp_BFu9i_BFu32ll  {
  void *v1;
  unsigned int v2:9;
  __tsu64 v3:32;
};
//SIG(1 Vp_BFu9i_BFu32ll) C1{ Fp Fi:9 FL:32}



static void Test_Vp_BFu9i_BFu32ll()
{
  {
    init_simple_test("Vp_BFu9i_BFu32ll");
    static STRUCT_IF_C Vp_BFu9i_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9i_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 32, 1, "Vp_BFu9i_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 32, hide_ull(1LL<<31), "Vp_BFu9i_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu32ll, Vp_BFu9i_BFu32ll)
//============================================================================


struct  Vp_BFu9i_BFu33  {
  void *v1;
  unsigned int v2:9;
  __tsu64 v3:33;
};
//SIG(1 Vp_BFu9i_BFu33) C1{ Fp Fi:9 FL:33}



static void Test_Vp_BFu9i_BFu33()
{
  {
    init_simple_test("Vp_BFu9i_BFu33");
    static STRUCT_IF_C Vp_BFu9i_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9i_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 33, 1, "Vp_BFu9i_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 33, hide_ull(1LL<<32), "Vp_BFu9i_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu33, Vp_BFu9i_BFu33)
//============================================================================


struct  Vp_BFu9i_BFu7c  {
  void *v1;
  unsigned int v2:9;
  unsigned char v3:7;
};
//SIG(1 Vp_BFu9i_BFu7c) C1{ Fp Fi:9 Fc:7}



static void Test_Vp_BFu9i_BFu7c()
{
  {
    init_simple_test("Vp_BFu9i_BFu7c");
    static STRUCT_IF_C Vp_BFu9i_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, 1, "Vp_BFu9i_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, hide_ull(1LL<<6), "Vp_BFu9i_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu7c, Vp_BFu9i_BFu7c)
//============================================================================


struct  Vp_BFu9i_BFu7i  {
  void *v1;
  unsigned int v2:9;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu9i_BFu7i) C1{ Fp Fi:9 Fi:7}



static void Test_Vp_BFu9i_BFu7i()
{
  {
    init_simple_test("Vp_BFu9i_BFu7i");
    static STRUCT_IF_C Vp_BFu9i_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, 1, "Vp_BFu9i_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, hide_ull(1LL<<6), "Vp_BFu9i_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu7i, Vp_BFu9i_BFu7i)
//============================================================================


struct  Vp_BFu9i_BFu7ll  {
  void *v1;
  unsigned int v2:9;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu9i_BFu7ll) C1{ Fp Fi:9 FL:7}



static void Test_Vp_BFu9i_BFu7ll()
{
  {
    init_simple_test("Vp_BFu9i_BFu7ll");
    static STRUCT_IF_C Vp_BFu9i_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, 1, "Vp_BFu9i_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, hide_ull(1LL<<6), "Vp_BFu9i_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu7ll, Vp_BFu9i_BFu7ll)
//============================================================================


struct  Vp_BFu9i_BFu7s  {
  void *v1;
  unsigned int v2:9;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu9i_BFu7s) C1{ Fp Fi:9 Fs:7}



static void Test_Vp_BFu9i_BFu7s()
{
  {
    init_simple_test("Vp_BFu9i_BFu7s");
    static STRUCT_IF_C Vp_BFu9i_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, 1, "Vp_BFu9i_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, hide_ull(1LL<<6), "Vp_BFu9i_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu7s, Vp_BFu9i_BFu7s)
//============================================================================


struct  Vp_BFu9i_BFu8c  {
  void *v1;
  unsigned int v2:9;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu9i_BFu8c) C1{ Fp Fi:9 Fc:8}



static void Test_Vp_BFu9i_BFu8c()
{
  {
    init_simple_test("Vp_BFu9i_BFu8c");
    static STRUCT_IF_C Vp_BFu9i_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_BFu9i_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_BFu9i_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu8c, Vp_BFu9i_BFu8c)
//============================================================================


struct  Vp_BFu9i_BFu8i  {
  void *v1;
  unsigned int v2:9;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu9i_BFu8i) C1{ Fp Fi:9 Fi:8}



static void Test_Vp_BFu9i_BFu8i()
{
  {
    init_simple_test("Vp_BFu9i_BFu8i");
    static STRUCT_IF_C Vp_BFu9i_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 8, 1, "Vp_BFu9i_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 8, hide_ull(1LL<<7), "Vp_BFu9i_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu8i, Vp_BFu9i_BFu8i)
//============================================================================


struct  Vp_BFu9i_BFu8ll  {
  void *v1;
  unsigned int v2:9;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu9i_BFu8ll) C1{ Fp Fi:9 FL:8}



static void Test_Vp_BFu9i_BFu8ll()
{
  {
    init_simple_test("Vp_BFu9i_BFu8ll");
    static STRUCT_IF_C Vp_BFu9i_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 8, 1, "Vp_BFu9i_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 8, hide_ull(1LL<<7), "Vp_BFu9i_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu8ll, Vp_BFu9i_BFu8ll)
//============================================================================


struct  Vp_BFu9i_BFu8s  {
  void *v1;
  unsigned int v2:9;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu9i_BFu8s) C1{ Fp Fi:9 Fs:8}



static void Test_Vp_BFu9i_BFu8s()
{
  {
    init_simple_test("Vp_BFu9i_BFu8s");
    static STRUCT_IF_C Vp_BFu9i_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_BFu9i_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_BFu9i_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu8s, Vp_BFu9i_BFu8s)
//============================================================================


struct  Vp_BFu9i_BFu9i  {
  void *v1;
  unsigned int v2:9;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu9i_BFu9i) C1{ Fp Fi:9 Fi:9}



static void Test_Vp_BFu9i_BFu9i()
{
  {
    init_simple_test("Vp_BFu9i_BFu9i");
    static STRUCT_IF_C Vp_BFu9i_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 9, 1, "Vp_BFu9i_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu9i, Vp_BFu9i_BFu9i)
//============================================================================


struct  Vp_BFu9i_BFu9ll  {
  void *v1;
  unsigned int v2:9;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu9i_BFu9ll) C1{ Fp Fi:9 FL:9}



static void Test_Vp_BFu9i_BFu9ll()
{
  {
    init_simple_test("Vp_BFu9i_BFu9ll");
    static STRUCT_IF_C Vp_BFu9i_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 9, 1, "Vp_BFu9i_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu9ll, Vp_BFu9i_BFu9ll)
//============================================================================


struct  Vp_BFu9i_BFu9s  {
  void *v1;
  unsigned int v2:9;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu9i_BFu9s) C1{ Fp Fi:9 Fs:9}



static void Test_Vp_BFu9i_BFu9s()
{
  {
    init_simple_test("Vp_BFu9i_BFu9s");
    static STRUCT_IF_C Vp_BFu9i_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_BFu9i_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_BFu9s, Vp_BFu9i_BFu9s)
//============================================================================


struct  Vp_BFu9i_C  {
  void *v1;
  unsigned int v2:9;
  char v3;
};
//SIG(1 Vp_BFu9i_C) C1{ Fp Fi:9 Fc}



static void Test_Vp_BFu9i_C()
{
  {
    init_simple_test("Vp_BFu9i_C");
    static STRUCT_IF_C Vp_BFu9i_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_C");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9i_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_C, Vp_BFu9i_C)
//============================================================================


struct  Vp_BFu9i_D  {
  void *v1;
  unsigned int v2:9;
  double v3;
};
//SIG(1 Vp_BFu9i_D) C1{ Fp Fi:9 FL}



static void Test_Vp_BFu9i_D()
{
  {
    init_simple_test("Vp_BFu9i_D");
    static STRUCT_IF_C Vp_BFu9i_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu9i_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_D");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9i_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_D, Vp_BFu9i_D)
//============================================================================


struct  Vp_BFu9i_F  {
  void *v1;
  unsigned int v2:9;
  float v3;
};
//SIG(1 Vp_BFu9i_F) C1{ Fp Fi:9 Fi}



static void Test_Vp_BFu9i_F()
{
  {
    init_simple_test("Vp_BFu9i_F");
    static STRUCT_IF_C Vp_BFu9i_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9i_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_F");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu9i_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_F, Vp_BFu9i_F)
//============================================================================


struct  Vp_BFu9i_I  {
  void *v1;
  unsigned int v2:9;
  int v3;
};
//SIG(1 Vp_BFu9i_I) C1{ Fp Fi:9 Fi}



static void Test_Vp_BFu9i_I()
{
  {
    init_simple_test("Vp_BFu9i_I");
    static STRUCT_IF_C Vp_BFu9i_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9i_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_I");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu9i_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_I, Vp_BFu9i_I)
//============================================================================


struct  Vp_BFu9i_Ip  {
  void *v1;
  unsigned int v2:9;
  int *v3;
};
//SIG(1 Vp_BFu9i_Ip) C1{ Fp Fi:9 Fp}



static void Test_Vp_BFu9i_Ip()
{
  {
    init_simple_test("Vp_BFu9i_Ip");
    static STRUCT_IF_C Vp_BFu9i_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu9i_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_Ip");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9i_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_Ip, Vp_BFu9i_Ip)
//============================================================================


struct  Vp_BFu9i_L  {
  void *v1;
  unsigned int v2:9;
  __tsi64 v3;
};
//SIG(1 Vp_BFu9i_L) C1{ Fp Fi:9 FL}



static void Test_Vp_BFu9i_L()
{
  {
    init_simple_test("Vp_BFu9i_L");
    static STRUCT_IF_C Vp_BFu9i_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu9i_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_L");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9i_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_L, Vp_BFu9i_L)
//============================================================================


struct  Vp_BFu9i_S  {
  void *v1;
  unsigned int v2:9;
  short v3;
};
//SIG(1 Vp_BFu9i_S) C1{ Fp Fi:9 Fs}



static void Test_Vp_BFu9i_S()
{
  {
    init_simple_test("Vp_BFu9i_S");
    static STRUCT_IF_C Vp_BFu9i_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_S");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9i_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_S, Vp_BFu9i_S)
//============================================================================


struct  Vp_BFu9i_Uc  {
  void *v1;
  unsigned int v2:9;
  unsigned char v3;
};
//SIG(1 Vp_BFu9i_Uc) C1{ Fp Fi:9 Fc}



static void Test_Vp_BFu9i_Uc()
{
  {
    init_simple_test("Vp_BFu9i_Uc");
    static STRUCT_IF_C Vp_BFu9i_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_Uc");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9i_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_Uc, Vp_BFu9i_Uc)
//============================================================================


struct  Vp_BFu9i_Ui  {
  void *v1;
  unsigned int v2:9;
  unsigned int v3;
};
//SIG(1 Vp_BFu9i_Ui) C1{ Fp Fi:9 Fi}



static void Test_Vp_BFu9i_Ui()
{
  {
    init_simple_test("Vp_BFu9i_Ui");
    static STRUCT_IF_C Vp_BFu9i_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9i_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_Ui");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu9i_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_Ui, Vp_BFu9i_Ui)
//============================================================================


struct  Vp_BFu9i_Ul  {
  void *v1;
  unsigned int v2:9;
  __tsu64 v3;
};
//SIG(1 Vp_BFu9i_Ul) C1{ Fp Fi:9 FL}



static void Test_Vp_BFu9i_Ul()
{
  {
    init_simple_test("Vp_BFu9i_Ul");
    static STRUCT_IF_C Vp_BFu9i_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu9i_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_Ul");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9i_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_Ul, Vp_BFu9i_Ul)
//============================================================================


struct  Vp_BFu9i_Us  {
  void *v1;
  unsigned int v2:9;
  unsigned short v3;
};
//SIG(1 Vp_BFu9i_Us) C1{ Fp Fi:9 Fs}



static void Test_Vp_BFu9i_Us()
{
  {
    init_simple_test("Vp_BFu9i_Us");
    static STRUCT_IF_C Vp_BFu9i_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9i_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_Us");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9i_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_Us, Vp_BFu9i_Us)
//============================================================================


struct  Vp_BFu9i_Vp  {
  void *v1;
  unsigned int v2:9;
  void *v3;
};
//SIG(1 Vp_BFu9i_Vp) C1{ Fp Fi:9 Fp}



static void Test_Vp_BFu9i_Vp()
{
  {
    init_simple_test("Vp_BFu9i_Vp");
    static STRUCT_IF_C Vp_BFu9i_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu9i_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9i_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu9i_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9i_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9i_Vp");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9i_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9i_Vp, Vp_BFu9i_Vp)
//============================================================================


struct  Vp_BFu9ll  {
  void *v1;
  __tsu64 v2:9;
};
//SIG(1 Vp_BFu9ll) C1{ Fp FL:9}



static void Test_Vp_BFu9ll()
{
  {
    init_simple_test("Vp_BFu9ll");
    static STRUCT_IF_C Vp_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll, Vp_BFu9ll)
//============================================================================


struct  Vp_BFu9ll_BFu15i  {
  void *v1;
  __tsu64 v2:9;
  unsigned int v3:15;
};
//SIG(1 Vp_BFu9ll_BFu15i) C1{ Fp FL:9 Fi:15}



static void Test_Vp_BFu9ll_BFu15i()
{
  {
    init_simple_test("Vp_BFu9ll_BFu15i");
    static STRUCT_IF_C Vp_BFu9ll_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 15, 1, "Vp_BFu9ll_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 15, hide_ull(1LL<<14), "Vp_BFu9ll_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu15i, Vp_BFu9ll_BFu15i)
//============================================================================


struct  Vp_BFu9ll_BFu15ll  {
  void *v1;
  __tsu64 v2:9;
  __tsu64 v3:15;
};
//SIG(1 Vp_BFu9ll_BFu15ll) C1{ Fp FL:9 FL:15}



static void Test_Vp_BFu9ll_BFu15ll()
{
  {
    init_simple_test("Vp_BFu9ll_BFu15ll");
    static STRUCT_IF_C Vp_BFu9ll_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 15, 1, "Vp_BFu9ll_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 15, hide_ull(1LL<<14), "Vp_BFu9ll_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu15ll, Vp_BFu9ll_BFu15ll)
//============================================================================


struct  Vp_BFu9ll_BFu15s  {
  void *v1;
  __tsu64 v2:9;
  unsigned short v3:15;
};
//SIG(1 Vp_BFu9ll_BFu15s) C1{ Fp FL:9 Fs:15}



static void Test_Vp_BFu9ll_BFu15s()
{
  {
    init_simple_test("Vp_BFu9ll_BFu15s");
    static STRUCT_IF_C Vp_BFu9ll_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_BFu9ll_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_BFu9ll_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu15s, Vp_BFu9ll_BFu15s)
//============================================================================


struct  Vp_BFu9ll_BFu16i  {
  void *v1;
  __tsu64 v2:9;
  unsigned int v3:16;
};
//SIG(1 Vp_BFu9ll_BFu16i) C1{ Fp FL:9 Fi:16}



static void Test_Vp_BFu9ll_BFu16i()
{
  {
    init_simple_test("Vp_BFu9ll_BFu16i");
    static STRUCT_IF_C Vp_BFu9ll_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 16, 1, "Vp_BFu9ll_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 16, hide_ull(1LL<<15), "Vp_BFu9ll_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu16i, Vp_BFu9ll_BFu16i)
//============================================================================


struct  Vp_BFu9ll_BFu16ll  {
  void *v1;
  __tsu64 v2:9;
  __tsu64 v3:16;
};
//SIG(1 Vp_BFu9ll_BFu16ll) C1{ Fp FL:9 FL:16}



static void Test_Vp_BFu9ll_BFu16ll()
{
  {
    init_simple_test("Vp_BFu9ll_BFu16ll");
    static STRUCT_IF_C Vp_BFu9ll_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 16, 1, "Vp_BFu9ll_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 16, hide_ull(1LL<<15), "Vp_BFu9ll_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu16ll, Vp_BFu9ll_BFu16ll)
//============================================================================


struct  Vp_BFu9ll_BFu16s  {
  void *v1;
  __tsu64 v2:9;
  unsigned short v3:16;
};
//SIG(1 Vp_BFu9ll_BFu16s) C1{ Fp FL:9 Fs:16}



static void Test_Vp_BFu9ll_BFu16s()
{
  {
    init_simple_test("Vp_BFu9ll_BFu16s");
    static STRUCT_IF_C Vp_BFu9ll_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_BFu9ll_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_BFu9ll_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu16s, Vp_BFu9ll_BFu16s)
//============================================================================


struct  Vp_BFu9ll_BFu17i  {
  void *v1;
  __tsu64 v2:9;
  unsigned int v3:17;
};
//SIG(1 Vp_BFu9ll_BFu17i) C1{ Fp FL:9 Fi:17}



static void Test_Vp_BFu9ll_BFu17i()
{
  {
    init_simple_test("Vp_BFu9ll_BFu17i");
    static STRUCT_IF_C Vp_BFu9ll_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 17, 1, "Vp_BFu9ll_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 17, hide_ull(1LL<<16), "Vp_BFu9ll_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu17i, Vp_BFu9ll_BFu17i)
//============================================================================


struct  Vp_BFu9ll_BFu17ll  {
  void *v1;
  __tsu64 v2:9;
  __tsu64 v3:17;
};
//SIG(1 Vp_BFu9ll_BFu17ll) C1{ Fp FL:9 FL:17}



static void Test_Vp_BFu9ll_BFu17ll()
{
  {
    init_simple_test("Vp_BFu9ll_BFu17ll");
    static STRUCT_IF_C Vp_BFu9ll_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 17, 1, "Vp_BFu9ll_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 17, hide_ull(1LL<<16), "Vp_BFu9ll_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu17ll, Vp_BFu9ll_BFu17ll)
//============================================================================


struct  Vp_BFu9ll_BFu1c  {
  void *v1;
  __tsu64 v2:9;
  unsigned char v3:1;
};
//SIG(1 Vp_BFu9ll_BFu1c) C1{ Fp FL:9 Fc:1}



static void Test_Vp_BFu9ll_BFu1c()
{
  {
    init_simple_test("Vp_BFu9ll_BFu1c");
    static STRUCT_IF_C Vp_BFu9ll_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu1c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu1c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 1, 1, "Vp_BFu9ll_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu1c, Vp_BFu9ll_BFu1c)
//============================================================================


struct  Vp_BFu9ll_BFu1i  {
  void *v1;
  __tsu64 v2:9;
  unsigned int v3:1;
};
//SIG(1 Vp_BFu9ll_BFu1i) C1{ Fp FL:9 Fi:1}



static void Test_Vp_BFu9ll_BFu1i()
{
  {
    init_simple_test("Vp_BFu9ll_BFu1i");
    static STRUCT_IF_C Vp_BFu9ll_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu1i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu1i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 1, 1, "Vp_BFu9ll_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu1i, Vp_BFu9ll_BFu1i)
//============================================================================


struct  Vp_BFu9ll_BFu1ll  {
  void *v1;
  __tsu64 v2:9;
  __tsu64 v3:1;
};
//SIG(1 Vp_BFu9ll_BFu1ll) C1{ Fp FL:9 FL:1}



static void Test_Vp_BFu9ll_BFu1ll()
{
  {
    init_simple_test("Vp_BFu9ll_BFu1ll");
    static STRUCT_IF_C Vp_BFu9ll_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu1ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu1ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 1, 1, "Vp_BFu9ll_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu1ll, Vp_BFu9ll_BFu1ll)
//============================================================================


struct  Vp_BFu9ll_BFu1s  {
  void *v1;
  __tsu64 v2:9;
  unsigned short v3:1;
};
//SIG(1 Vp_BFu9ll_BFu1s) C1{ Fp FL:9 Fs:1}



static void Test_Vp_BFu9ll_BFu1s()
{
  {
    init_simple_test("Vp_BFu9ll_BFu1s");
    static STRUCT_IF_C Vp_BFu9ll_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu1s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu1s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 1, 1, "Vp_BFu9ll_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu1s, Vp_BFu9ll_BFu1s)
//============================================================================


struct  Vp_BFu9ll_BFu31i  {
  void *v1;
  __tsu64 v2:9;
  unsigned int v3:31;
};
//SIG(1 Vp_BFu9ll_BFu31i) C1{ Fp FL:9 Fi:31}



static void Test_Vp_BFu9ll_BFu31i()
{
  {
    init_simple_test("Vp_BFu9ll_BFu31i");
    static STRUCT_IF_C Vp_BFu9ll_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9ll_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_BFu9ll_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_BFu9ll_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu31i, Vp_BFu9ll_BFu31i)
//============================================================================


struct  Vp_BFu9ll_BFu31ll  {
  void *v1;
  __tsu64 v2:9;
  __tsu64 v3:31;
};
//SIG(1 Vp_BFu9ll_BFu31ll) C1{ Fp FL:9 FL:31}



static void Test_Vp_BFu9ll_BFu31ll()
{
  {
    init_simple_test("Vp_BFu9ll_BFu31ll");
    static STRUCT_IF_C Vp_BFu9ll_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9ll_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 31, 1, "Vp_BFu9ll_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 31, hide_ull(1LL<<30), "Vp_BFu9ll_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu31ll, Vp_BFu9ll_BFu31ll)
//============================================================================


struct  Vp_BFu9ll_BFu32i  {
  void *v1;
  __tsu64 v2:9;
  unsigned int v3:32;
};
//SIG(1 Vp_BFu9ll_BFu32i) C1{ Fp FL:9 Fi:32}



static void Test_Vp_BFu9ll_BFu32i()
{
  {
    init_simple_test("Vp_BFu9ll_BFu32i");
    static STRUCT_IF_C Vp_BFu9ll_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9ll_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_BFu9ll_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_BFu9ll_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu32i, Vp_BFu9ll_BFu32i)
//============================================================================


struct  Vp_BFu9ll_BFu32ll  {
  void *v1;
  __tsu64 v2:9;
  __tsu64 v3:32;
};
//SIG(1 Vp_BFu9ll_BFu32ll) C1{ Fp FL:9 FL:32}



static void Test_Vp_BFu9ll_BFu32ll()
{
  {
    init_simple_test("Vp_BFu9ll_BFu32ll");
    static STRUCT_IF_C Vp_BFu9ll_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9ll_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 32, 1, "Vp_BFu9ll_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 32, hide_ull(1LL<<31), "Vp_BFu9ll_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu32ll, Vp_BFu9ll_BFu32ll)
//============================================================================


struct  Vp_BFu9ll_BFu33  {
  void *v1;
  __tsu64 v2:9;
  __tsu64 v3:33;
};
//SIG(1 Vp_BFu9ll_BFu33) C1{ Fp FL:9 FL:33}



static void Test_Vp_BFu9ll_BFu33()
{
  {
    init_simple_test("Vp_BFu9ll_BFu33");
    static STRUCT_IF_C Vp_BFu9ll_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9ll_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 33, 1, "Vp_BFu9ll_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 33, hide_ull(1LL<<32), "Vp_BFu9ll_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu33, Vp_BFu9ll_BFu33)
//============================================================================


struct  Vp_BFu9ll_BFu7c  {
  void *v1;
  __tsu64 v2:9;
  unsigned char v3:7;
};
//SIG(1 Vp_BFu9ll_BFu7c) C1{ Fp FL:9 Fc:7}



static void Test_Vp_BFu9ll_BFu7c()
{
  {
    init_simple_test("Vp_BFu9ll_BFu7c");
    static STRUCT_IF_C Vp_BFu9ll_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, 1, "Vp_BFu9ll_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, hide_ull(1LL<<6), "Vp_BFu9ll_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu7c, Vp_BFu9ll_BFu7c)
//============================================================================


struct  Vp_BFu9ll_BFu7i  {
  void *v1;
  __tsu64 v2:9;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu9ll_BFu7i) C1{ Fp FL:9 Fi:7}



static void Test_Vp_BFu9ll_BFu7i()
{
  {
    init_simple_test("Vp_BFu9ll_BFu7i");
    static STRUCT_IF_C Vp_BFu9ll_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, 1, "Vp_BFu9ll_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, hide_ull(1LL<<6), "Vp_BFu9ll_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu7i, Vp_BFu9ll_BFu7i)
//============================================================================


struct  Vp_BFu9ll_BFu7ll  {
  void *v1;
  __tsu64 v2:9;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu9ll_BFu7ll) C1{ Fp FL:9 FL:7}



static void Test_Vp_BFu9ll_BFu7ll()
{
  {
    init_simple_test("Vp_BFu9ll_BFu7ll");
    static STRUCT_IF_C Vp_BFu9ll_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, 1, "Vp_BFu9ll_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, hide_ull(1LL<<6), "Vp_BFu9ll_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu7ll, Vp_BFu9ll_BFu7ll)
//============================================================================


struct  Vp_BFu9ll_BFu7s  {
  void *v1;
  __tsu64 v2:9;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu9ll_BFu7s) C1{ Fp FL:9 Fs:7}



static void Test_Vp_BFu9ll_BFu7s()
{
  {
    init_simple_test("Vp_BFu9ll_BFu7s");
    static STRUCT_IF_C Vp_BFu9ll_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, 1, "Vp_BFu9ll_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, hide_ull(1LL<<6), "Vp_BFu9ll_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu7s, Vp_BFu9ll_BFu7s)
//============================================================================


struct  Vp_BFu9ll_BFu8c  {
  void *v1;
  __tsu64 v2:9;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu9ll_BFu8c) C1{ Fp FL:9 Fc:8}



static void Test_Vp_BFu9ll_BFu8c()
{
  {
    init_simple_test("Vp_BFu9ll_BFu8c");
    static STRUCT_IF_C Vp_BFu9ll_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_BFu9ll_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_BFu9ll_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu8c, Vp_BFu9ll_BFu8c)
//============================================================================


struct  Vp_BFu9ll_BFu8i  {
  void *v1;
  __tsu64 v2:9;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu9ll_BFu8i) C1{ Fp FL:9 Fi:8}



static void Test_Vp_BFu9ll_BFu8i()
{
  {
    init_simple_test("Vp_BFu9ll_BFu8i");
    static STRUCT_IF_C Vp_BFu9ll_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 8, 1, "Vp_BFu9ll_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 8, hide_ull(1LL<<7), "Vp_BFu9ll_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu8i, Vp_BFu9ll_BFu8i)
//============================================================================


struct  Vp_BFu9ll_BFu8ll  {
  void *v1;
  __tsu64 v2:9;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu9ll_BFu8ll) C1{ Fp FL:9 FL:8}



static void Test_Vp_BFu9ll_BFu8ll()
{
  {
    init_simple_test("Vp_BFu9ll_BFu8ll");
    static STRUCT_IF_C Vp_BFu9ll_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 8, 1, "Vp_BFu9ll_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 8, hide_ull(1LL<<7), "Vp_BFu9ll_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu8ll, Vp_BFu9ll_BFu8ll)
//============================================================================


struct  Vp_BFu9ll_BFu8s  {
  void *v1;
  __tsu64 v2:9;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu9ll_BFu8s) C1{ Fp FL:9 Fs:8}



static void Test_Vp_BFu9ll_BFu8s()
{
  {
    init_simple_test("Vp_BFu9ll_BFu8s");
    static STRUCT_IF_C Vp_BFu9ll_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_BFu9ll_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_BFu9ll_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu8s, Vp_BFu9ll_BFu8s)
//============================================================================


struct  Vp_BFu9ll_BFu9i  {
  void *v1;
  __tsu64 v2:9;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu9ll_BFu9i) C1{ Fp FL:9 Fi:9}



static void Test_Vp_BFu9ll_BFu9i()
{
  {
    init_simple_test("Vp_BFu9ll_BFu9i");
    static STRUCT_IF_C Vp_BFu9ll_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 9, 1, "Vp_BFu9ll_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu9i, Vp_BFu9ll_BFu9i)
//============================================================================


struct  Vp_BFu9ll_BFu9ll  {
  void *v1;
  __tsu64 v2:9;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu9ll_BFu9ll) C1{ Fp FL:9 FL:9}



static void Test_Vp_BFu9ll_BFu9ll()
{
  {
    init_simple_test("Vp_BFu9ll_BFu9ll");
    static STRUCT_IF_C Vp_BFu9ll_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 9, 1, "Vp_BFu9ll_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu9ll, Vp_BFu9ll_BFu9ll)
//============================================================================


struct  Vp_BFu9ll_BFu9s  {
  void *v1;
  __tsu64 v2:9;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu9ll_BFu9s) C1{ Fp FL:9 Fs:9}



static void Test_Vp_BFu9ll_BFu9s()
{
  {
    init_simple_test("Vp_BFu9ll_BFu9s");
    static STRUCT_IF_C Vp_BFu9ll_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_BFu9ll_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_BFu9s, Vp_BFu9ll_BFu9s)
//============================================================================


struct  Vp_BFu9ll_C  {
  void *v1;
  __tsu64 v2:9;
  char v3;
};
//SIG(1 Vp_BFu9ll_C) C1{ Fp FL:9 Fc}



static void Test_Vp_BFu9ll_C()
{
  {
    init_simple_test("Vp_BFu9ll_C");
    static STRUCT_IF_C Vp_BFu9ll_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_C");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9ll_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_C, Vp_BFu9ll_C)
//============================================================================


struct  Vp_BFu9ll_D  {
  void *v1;
  __tsu64 v2:9;
  double v3;
};
//SIG(1 Vp_BFu9ll_D) C1{ Fp FL:9 FL}



static void Test_Vp_BFu9ll_D()
{
  {
    init_simple_test("Vp_BFu9ll_D");
    static STRUCT_IF_C Vp_BFu9ll_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu9ll_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_D");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9ll_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_D, Vp_BFu9ll_D)
//============================================================================


struct  Vp_BFu9ll_F  {
  void *v1;
  __tsu64 v2:9;
  float v3;
};
//SIG(1 Vp_BFu9ll_F) C1{ Fp FL:9 Fi}



static void Test_Vp_BFu9ll_F()
{
  {
    init_simple_test("Vp_BFu9ll_F");
    static STRUCT_IF_C Vp_BFu9ll_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9ll_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_F");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu9ll_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_F, Vp_BFu9ll_F)
//============================================================================


struct  Vp_BFu9ll_I  {
  void *v1;
  __tsu64 v2:9;
  int v3;
};
//SIG(1 Vp_BFu9ll_I) C1{ Fp FL:9 Fi}



static void Test_Vp_BFu9ll_I()
{
  {
    init_simple_test("Vp_BFu9ll_I");
    static STRUCT_IF_C Vp_BFu9ll_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9ll_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_I");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu9ll_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_I, Vp_BFu9ll_I)
//============================================================================


struct  Vp_BFu9ll_Ip  {
  void *v1;
  __tsu64 v2:9;
  int *v3;
};
//SIG(1 Vp_BFu9ll_Ip) C1{ Fp FL:9 Fp}



static void Test_Vp_BFu9ll_Ip()
{
  {
    init_simple_test("Vp_BFu9ll_Ip");
    static STRUCT_IF_C Vp_BFu9ll_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu9ll_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_Ip");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9ll_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_Ip, Vp_BFu9ll_Ip)
//============================================================================


struct  Vp_BFu9ll_L  {
  void *v1;
  __tsu64 v2:9;
  __tsi64 v3;
};
//SIG(1 Vp_BFu9ll_L) C1{ Fp FL:9 FL}



static void Test_Vp_BFu9ll_L()
{
  {
    init_simple_test("Vp_BFu9ll_L");
    static STRUCT_IF_C Vp_BFu9ll_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu9ll_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_L");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9ll_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_L, Vp_BFu9ll_L)
//============================================================================


struct  Vp_BFu9ll_S  {
  void *v1;
  __tsu64 v2:9;
  short v3;
};
//SIG(1 Vp_BFu9ll_S) C1{ Fp FL:9 Fs}



static void Test_Vp_BFu9ll_S()
{
  {
    init_simple_test("Vp_BFu9ll_S");
    static STRUCT_IF_C Vp_BFu9ll_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_S");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9ll_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_S, Vp_BFu9ll_S)
//============================================================================


struct  Vp_BFu9ll_Uc  {
  void *v1;
  __tsu64 v2:9;
  unsigned char v3;
};
//SIG(1 Vp_BFu9ll_Uc) C1{ Fp FL:9 Fc}



static void Test_Vp_BFu9ll_Uc()
{
  {
    init_simple_test("Vp_BFu9ll_Uc");
    static STRUCT_IF_C Vp_BFu9ll_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_Uc");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9ll_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_Uc, Vp_BFu9ll_Uc)
//============================================================================


struct  Vp_BFu9ll_Ui  {
  void *v1;
  __tsu64 v2:9;
  unsigned int v3;
};
//SIG(1 Vp_BFu9ll_Ui) C1{ Fp FL:9 Fi}



static void Test_Vp_BFu9ll_Ui()
{
  {
    init_simple_test("Vp_BFu9ll_Ui");
    static STRUCT_IF_C Vp_BFu9ll_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9ll_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_Ui");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu9ll_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_Ui, Vp_BFu9ll_Ui)
//============================================================================


struct  Vp_BFu9ll_Ul  {
  void *v1;
  __tsu64 v2:9;
  __tsu64 v3;
};
//SIG(1 Vp_BFu9ll_Ul) C1{ Fp FL:9 FL}



static void Test_Vp_BFu9ll_Ul()
{
  {
    init_simple_test("Vp_BFu9ll_Ul");
    static STRUCT_IF_C Vp_BFu9ll_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu9ll_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_Ul");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9ll_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_Ul, Vp_BFu9ll_Ul)
//============================================================================


struct  Vp_BFu9ll_Us  {
  void *v1;
  __tsu64 v2:9;
  unsigned short v3;
};
//SIG(1 Vp_BFu9ll_Us) C1{ Fp FL:9 Fs}



static void Test_Vp_BFu9ll_Us()
{
  {
    init_simple_test("Vp_BFu9ll_Us");
    static STRUCT_IF_C Vp_BFu9ll_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9ll_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_Us");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9ll_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_Us, Vp_BFu9ll_Us)
//============================================================================


struct  Vp_BFu9ll_Vp  {
  void *v1;
  __tsu64 v2:9;
  void *v3;
};
//SIG(1 Vp_BFu9ll_Vp) C1{ Fp FL:9 Fp}



static void Test_Vp_BFu9ll_Vp()
{
  {
    init_simple_test("Vp_BFu9ll_Vp");
    static STRUCT_IF_C Vp_BFu9ll_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu9ll_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9ll_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu9ll_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9ll_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9ll_Vp");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9ll_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9ll_Vp, Vp_BFu9ll_Vp)
//============================================================================


struct  Vp_BFu9s  {
  void *v1;
  unsigned short v2:9;
};
//SIG(1 Vp_BFu9s) C1{ Fp Fs:9}



static void Test_Vp_BFu9s()
{
  {
    init_simple_test("Vp_BFu9s");
    static STRUCT_IF_C Vp_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s, Vp_BFu9s)
//============================================================================


struct  Vp_BFu9s_BFu15i  {
  void *v1;
  unsigned short v2:9;
  unsigned int v3:15;
};
//SIG(1 Vp_BFu9s_BFu15i) C1{ Fp Fs:9 Fi:15}



static void Test_Vp_BFu9s_BFu15i()
{
  {
    init_simple_test("Vp_BFu9s_BFu15i");
    static STRUCT_IF_C Vp_BFu9s_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu15i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu15i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 15, 1, "Vp_BFu9s_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 15, hide_ull(1LL<<14), "Vp_BFu9s_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu15i, Vp_BFu9s_BFu15i)
//============================================================================


struct  Vp_BFu9s_BFu15ll  {
  void *v1;
  unsigned short v2:9;
  __tsu64 v3:15;
};
//SIG(1 Vp_BFu9s_BFu15ll) C1{ Fp Fs:9 FL:15}



static void Test_Vp_BFu9s_BFu15ll()
{
  {
    init_simple_test("Vp_BFu9s_BFu15ll");
    static STRUCT_IF_C Vp_BFu9s_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu15ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu15ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 15, 1, "Vp_BFu9s_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 15, hide_ull(1LL<<14), "Vp_BFu9s_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu15ll, Vp_BFu9s_BFu15ll)
//============================================================================


struct  Vp_BFu9s_BFu15s  {
  void *v1;
  unsigned short v2:9;
  unsigned short v3:15;
};
//SIG(1 Vp_BFu9s_BFu15s) C1{ Fp Fs:9 Fs:15}



static void Test_Vp_BFu9s_BFu15s()
{
  {
    init_simple_test("Vp_BFu9s_BFu15s");
    static STRUCT_IF_C Vp_BFu9s_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu15s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu15s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_BFu9s_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_BFu9s_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu15s, Vp_BFu9s_BFu15s)
//============================================================================


struct  Vp_BFu9s_BFu16i  {
  void *v1;
  unsigned short v2:9;
  unsigned int v3:16;
};
//SIG(1 Vp_BFu9s_BFu16i) C1{ Fp Fs:9 Fi:16}



static void Test_Vp_BFu9s_BFu16i()
{
  {
    init_simple_test("Vp_BFu9s_BFu16i");
    static STRUCT_IF_C Vp_BFu9s_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu16i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu16i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 16, 1, "Vp_BFu9s_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 16, hide_ull(1LL<<15), "Vp_BFu9s_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu16i, Vp_BFu9s_BFu16i)
//============================================================================


struct  Vp_BFu9s_BFu16ll  {
  void *v1;
  unsigned short v2:9;
  __tsu64 v3:16;
};
//SIG(1 Vp_BFu9s_BFu16ll) C1{ Fp Fs:9 FL:16}



static void Test_Vp_BFu9s_BFu16ll()
{
  {
    init_simple_test("Vp_BFu9s_BFu16ll");
    static STRUCT_IF_C Vp_BFu9s_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu16ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu16ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 16, 1, "Vp_BFu9s_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 16, hide_ull(1LL<<15), "Vp_BFu9s_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu16ll, Vp_BFu9s_BFu16ll)
//============================================================================


struct  Vp_BFu9s_BFu16s  {
  void *v1;
  unsigned short v2:9;
  unsigned short v3:16;
};
//SIG(1 Vp_BFu9s_BFu16s) C1{ Fp Fs:9 Fs:16}



static void Test_Vp_BFu9s_BFu16s()
{
  {
    init_simple_test("Vp_BFu9s_BFu16s");
    static STRUCT_IF_C Vp_BFu9s_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu16s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu16s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_BFu9s_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_BFu9s_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu16s, Vp_BFu9s_BFu16s)
//============================================================================


struct  Vp_BFu9s_BFu17i  {
  void *v1;
  unsigned short v2:9;
  unsigned int v3:17;
};
//SIG(1 Vp_BFu9s_BFu17i) C1{ Fp Fs:9 Fi:17}



static void Test_Vp_BFu9s_BFu17i()
{
  {
    init_simple_test("Vp_BFu9s_BFu17i");
    static STRUCT_IF_C Vp_BFu9s_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu17i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu17i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 17, 1, "Vp_BFu9s_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 17, hide_ull(1LL<<16), "Vp_BFu9s_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu17i, Vp_BFu9s_BFu17i)
//============================================================================


struct  Vp_BFu9s_BFu17ll  {
  void *v1;
  unsigned short v2:9;
  __tsu64 v3:17;
};
//SIG(1 Vp_BFu9s_BFu17ll) C1{ Fp Fs:9 FL:17}



static void Test_Vp_BFu9s_BFu17ll()
{
  {
    init_simple_test("Vp_BFu9s_BFu17ll");
    static STRUCT_IF_C Vp_BFu9s_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu17ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu17ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 17, 1, "Vp_BFu9s_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 17, hide_ull(1LL<<16), "Vp_BFu9s_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu17ll, Vp_BFu9s_BFu17ll)
//============================================================================


struct  Vp_BFu9s_BFu1c  {
  void *v1;
  unsigned short v2:9;
  unsigned char v3:1;
};
//SIG(1 Vp_BFu9s_BFu1c) C1{ Fp Fs:9 Fc:1}



static void Test_Vp_BFu9s_BFu1c()
{
  {
    init_simple_test("Vp_BFu9s_BFu1c");
    static STRUCT_IF_C Vp_BFu9s_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu1c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu1c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu1c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 1, 1, "Vp_BFu9s_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu1c, Vp_BFu9s_BFu1c)
//============================================================================


struct  Vp_BFu9s_BFu1i  {
  void *v1;
  unsigned short v2:9;
  unsigned int v3:1;
};
//SIG(1 Vp_BFu9s_BFu1i) C1{ Fp Fs:9 Fi:1}



static void Test_Vp_BFu9s_BFu1i()
{
  {
    init_simple_test("Vp_BFu9s_BFu1i");
    static STRUCT_IF_C Vp_BFu9s_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu1i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu1i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu1i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 1, 1, "Vp_BFu9s_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu1i, Vp_BFu9s_BFu1i)
//============================================================================


struct  Vp_BFu9s_BFu1ll  {
  void *v1;
  unsigned short v2:9;
  __tsu64 v3:1;
};
//SIG(1 Vp_BFu9s_BFu1ll) C1{ Fp Fs:9 FL:1}



static void Test_Vp_BFu9s_BFu1ll()
{
  {
    init_simple_test("Vp_BFu9s_BFu1ll");
    static STRUCT_IF_C Vp_BFu9s_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu1ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu1ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu1ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 1, 1, "Vp_BFu9s_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu1ll, Vp_BFu9s_BFu1ll)
//============================================================================


struct  Vp_BFu9s_BFu1s  {
  void *v1;
  unsigned short v2:9;
  unsigned short v3:1;
};
//SIG(1 Vp_BFu9s_BFu1s) C1{ Fp Fs:9 Fs:1}



static void Test_Vp_BFu9s_BFu1s()
{
  {
    init_simple_test("Vp_BFu9s_BFu1s");
    static STRUCT_IF_C Vp_BFu9s_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu1s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu1s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu1s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 1, 1, "Vp_BFu9s_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu1s, Vp_BFu9s_BFu1s)
//============================================================================


struct  Vp_BFu9s_BFu31i  {
  void *v1;
  unsigned short v2:9;
  unsigned int v3:31;
};
//SIG(1 Vp_BFu9s_BFu31i) C1{ Fp Fs:9 Fi:31}



static void Test_Vp_BFu9s_BFu31i()
{
  {
    init_simple_test("Vp_BFu9s_BFu31i");
    static STRUCT_IF_C Vp_BFu9s_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9s_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu31i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu31i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_BFu9s_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_BFu9s_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu31i, Vp_BFu9s_BFu31i)
//============================================================================


struct  Vp_BFu9s_BFu31ll  {
  void *v1;
  unsigned short v2:9;
  __tsu64 v3:31;
};
//SIG(1 Vp_BFu9s_BFu31ll) C1{ Fp Fs:9 FL:31}



static void Test_Vp_BFu9s_BFu31ll()
{
  {
    init_simple_test("Vp_BFu9s_BFu31ll");
    static STRUCT_IF_C Vp_BFu9s_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9s_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu31ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu31ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 31, 1, "Vp_BFu9s_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 31, hide_ull(1LL<<30), "Vp_BFu9s_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu31ll, Vp_BFu9s_BFu31ll)
//============================================================================


struct  Vp_BFu9s_BFu32i  {
  void *v1;
  unsigned short v2:9;
  unsigned int v3:32;
};
//SIG(1 Vp_BFu9s_BFu32i) C1{ Fp Fs:9 Fi:32}



static void Test_Vp_BFu9s_BFu32i()
{
  {
    init_simple_test("Vp_BFu9s_BFu32i");
    static STRUCT_IF_C Vp_BFu9s_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9s_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu32i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu32i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_BFu9s_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_BFu9s_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu32i, Vp_BFu9s_BFu32i)
//============================================================================


struct  Vp_BFu9s_BFu32ll  {
  void *v1;
  unsigned short v2:9;
  __tsu64 v3:32;
};
//SIG(1 Vp_BFu9s_BFu32ll) C1{ Fp Fs:9 FL:32}



static void Test_Vp_BFu9s_BFu32ll()
{
  {
    init_simple_test("Vp_BFu9s_BFu32ll");
    static STRUCT_IF_C Vp_BFu9s_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9s_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu32ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu32ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 32, 1, "Vp_BFu9s_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 32, hide_ull(1LL<<31), "Vp_BFu9s_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu32ll, Vp_BFu9s_BFu32ll)
//============================================================================


struct  Vp_BFu9s_BFu33  {
  void *v1;
  unsigned short v2:9;
  __tsu64 v3:33;
};
//SIG(1 Vp_BFu9s_BFu33) C1{ Fp Fs:9 FL:33}



static void Test_Vp_BFu9s_BFu33()
{
  {
    init_simple_test("Vp_BFu9s_BFu33");
    static STRUCT_IF_C Vp_BFu9s_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9s_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu33.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu33");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 33, 1, "Vp_BFu9s_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), ABISELECT(1,1), 33, hide_ull(1LL<<32), "Vp_BFu9s_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu33, Vp_BFu9s_BFu33)
//============================================================================


struct  Vp_BFu9s_BFu7c  {
  void *v1;
  unsigned short v2:9;
  unsigned char v3:7;
};
//SIG(1 Vp_BFu9s_BFu7c) C1{ Fp Fs:9 Fc:7}



static void Test_Vp_BFu9s_BFu7c()
{
  {
    init_simple_test("Vp_BFu9s_BFu7c");
    static STRUCT_IF_C Vp_BFu9s_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu7c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu7c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, 1, "Vp_BFu9s_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, hide_ull(1LL<<6), "Vp_BFu9s_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu7c, Vp_BFu9s_BFu7c)
//============================================================================


struct  Vp_BFu9s_BFu7i  {
  void *v1;
  unsigned short v2:9;
  unsigned int v3:7;
};
//SIG(1 Vp_BFu9s_BFu7i) C1{ Fp Fs:9 Fi:7}



static void Test_Vp_BFu9s_BFu7i()
{
  {
    init_simple_test("Vp_BFu9s_BFu7i");
    static STRUCT_IF_C Vp_BFu9s_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu7i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu7i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, 1, "Vp_BFu9s_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, hide_ull(1LL<<6), "Vp_BFu9s_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu7i, Vp_BFu9s_BFu7i)
//============================================================================


struct  Vp_BFu9s_BFu7ll  {
  void *v1;
  unsigned short v2:9;
  __tsu64 v3:7;
};
//SIG(1 Vp_BFu9s_BFu7ll) C1{ Fp Fs:9 FL:7}



static void Test_Vp_BFu9s_BFu7ll()
{
  {
    init_simple_test("Vp_BFu9s_BFu7ll");
    static STRUCT_IF_C Vp_BFu9s_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu7ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu7ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, 1, "Vp_BFu9s_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, hide_ull(1LL<<6), "Vp_BFu9s_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu7ll, Vp_BFu9s_BFu7ll)
//============================================================================


struct  Vp_BFu9s_BFu7s  {
  void *v1;
  unsigned short v2:9;
  unsigned short v3:7;
};
//SIG(1 Vp_BFu9s_BFu7s) C1{ Fp Fs:9 Fs:7}



static void Test_Vp_BFu9s_BFu7s()
{
  {
    init_simple_test("Vp_BFu9s_BFu7s");
    static STRUCT_IF_C Vp_BFu9s_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu7s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu7s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, 1, "Vp_BFu9s_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 7, hide_ull(1LL<<6), "Vp_BFu9s_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu7s, Vp_BFu9s_BFu7s)
//============================================================================


struct  Vp_BFu9s_BFu8c  {
  void *v1;
  unsigned short v2:9;
  unsigned char v3:8;
};
//SIG(1 Vp_BFu9s_BFu8c) C1{ Fp Fs:9 Fc:8}



static void Test_Vp_BFu9s_BFu8c()
{
  {
    init_simple_test("Vp_BFu9s_BFu8c");
    static STRUCT_IF_C Vp_BFu9s_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu8c.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu8c");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_BFu9s_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_BFu9s_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu8c, Vp_BFu9s_BFu8c)
//============================================================================


struct  Vp_BFu9s_BFu8i  {
  void *v1;
  unsigned short v2:9;
  unsigned int v3:8;
};
//SIG(1 Vp_BFu9s_BFu8i) C1{ Fp Fs:9 Fi:8}



static void Test_Vp_BFu9s_BFu8i()
{
  {
    init_simple_test("Vp_BFu9s_BFu8i");
    static STRUCT_IF_C Vp_BFu9s_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu8i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu8i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 8, 1, "Vp_BFu9s_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 8, hide_ull(1LL<<7), "Vp_BFu9s_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu8i, Vp_BFu9s_BFu8i)
//============================================================================


struct  Vp_BFu9s_BFu8ll  {
  void *v1;
  unsigned short v2:9;
  __tsu64 v3:8;
};
//SIG(1 Vp_BFu9s_BFu8ll) C1{ Fp Fs:9 FL:8}



static void Test_Vp_BFu9s_BFu8ll()
{
  {
    init_simple_test("Vp_BFu9s_BFu8ll");
    static STRUCT_IF_C Vp_BFu9s_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu8ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu8ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 8, 1, "Vp_BFu9s_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 8, hide_ull(1LL<<7), "Vp_BFu9s_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu8ll, Vp_BFu9s_BFu8ll)
//============================================================================


struct  Vp_BFu9s_BFu8s  {
  void *v1;
  unsigned short v2:9;
  unsigned short v3:8;
};
//SIG(1 Vp_BFu9s_BFu8s) C1{ Fp Fs:9 Fs:8}



static void Test_Vp_BFu9s_BFu8s()
{
  {
    init_simple_test("Vp_BFu9s_BFu8s");
    static STRUCT_IF_C Vp_BFu9s_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu8s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu8s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_BFu9s_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_BFu9s_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu8s, Vp_BFu9s_BFu8s)
//============================================================================


struct  Vp_BFu9s_BFu9i  {
  void *v1;
  unsigned short v2:9;
  unsigned int v3:9;
};
//SIG(1 Vp_BFu9s_BFu9i) C1{ Fp Fs:9 Fi:9}



static void Test_Vp_BFu9s_BFu9i()
{
  {
    init_simple_test("Vp_BFu9s_BFu9i");
    static STRUCT_IF_C Vp_BFu9s_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu9i.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu9i");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 9, 1, "Vp_BFu9s_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu9i, Vp_BFu9s_BFu9i)
//============================================================================


struct  Vp_BFu9s_BFu9ll  {
  void *v1;
  unsigned short v2:9;
  __tsu64 v3:9;
};
//SIG(1 Vp_BFu9s_BFu9ll) C1{ Fp Fs:9 FL:9}



static void Test_Vp_BFu9s_BFu9ll()
{
  {
    init_simple_test("Vp_BFu9s_BFu9ll");
    static STRUCT_IF_C Vp_BFu9s_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu9ll.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu9ll");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 9, 1, "Vp_BFu9s_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 1, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu9ll, Vp_BFu9s_BFu9ll)
//============================================================================


struct  Vp_BFu9s_BFu9s  {
  void *v1;
  unsigned short v2:9;
  unsigned short v3:9;
};
//SIG(1 Vp_BFu9s_BFu9s) C1{ Fp Fs:9 Fs:9}



static void Test_Vp_BFu9s_BFu9s()
{
  {
    init_simple_test("Vp_BFu9s_BFu9s");
    static STRUCT_IF_C Vp_BFu9s_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_BFu9s.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_BFu9s");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_BFu9s_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_BFu9s, Vp_BFu9s_BFu9s)
//============================================================================


struct  Vp_BFu9s_C  {
  void *v1;
  unsigned short v2:9;
  char v3;
};
//SIG(1 Vp_BFu9s_C) C1{ Fp Fs:9 Fc}



static void Test_Vp_BFu9s_C()
{
  {
    init_simple_test("Vp_BFu9s_C");
    static STRUCT_IF_C Vp_BFu9s_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_C)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_C.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_C");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_C");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9s_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_C, Vp_BFu9s_C)
//============================================================================


struct  Vp_BFu9s_D  {
  void *v1;
  unsigned short v2:9;
  double v3;
};
//SIG(1 Vp_BFu9s_D) C1{ Fp Fs:9 FL}



static void Test_Vp_BFu9s_D()
{
  {
    init_simple_test("Vp_BFu9s_D");
    static STRUCT_IF_C Vp_BFu9s_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu9s_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_D)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_D.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_D");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_D");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9s_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_D, Vp_BFu9s_D)
//============================================================================


struct  Vp_BFu9s_F  {
  void *v1;
  unsigned short v2:9;
  float v3;
};
//SIG(1 Vp_BFu9s_F) C1{ Fp Fs:9 Fi}



static void Test_Vp_BFu9s_F()
{
  {
    init_simple_test("Vp_BFu9s_F");
    static STRUCT_IF_C Vp_BFu9s_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9s_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_F)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_F.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_F");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_F");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu9s_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_F, Vp_BFu9s_F)
//============================================================================


struct  Vp_BFu9s_I  {
  void *v1;
  unsigned short v2:9;
  int v3;
};
//SIG(1 Vp_BFu9s_I) C1{ Fp Fs:9 Fi}



static void Test_Vp_BFu9s_I()
{
  {
    init_simple_test("Vp_BFu9s_I");
    static STRUCT_IF_C Vp_BFu9s_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9s_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_I)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_I.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_I");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_I");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu9s_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_I, Vp_BFu9s_I)
//============================================================================


struct  Vp_BFu9s_Ip  {
  void *v1;
  unsigned short v2:9;
  int *v3;
};
//SIG(1 Vp_BFu9s_Ip) C1{ Fp Fs:9 Fp}



static void Test_Vp_BFu9s_Ip()
{
  {
    init_simple_test("Vp_BFu9s_Ip");
    static STRUCT_IF_C Vp_BFu9s_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu9s_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_Ip)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_Ip.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_Ip");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_Ip");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9s_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_Ip, Vp_BFu9s_Ip)
//============================================================================


struct  Vp_BFu9s_L  {
  void *v1;
  unsigned short v2:9;
  __tsi64 v3;
};
//SIG(1 Vp_BFu9s_L) C1{ Fp Fs:9 FL}



static void Test_Vp_BFu9s_L()
{
  {
    init_simple_test("Vp_BFu9s_L");
    static STRUCT_IF_C Vp_BFu9s_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu9s_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_L)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_L.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_L");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_L");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9s_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_L, Vp_BFu9s_L)
//============================================================================


struct  Vp_BFu9s_S  {
  void *v1;
  unsigned short v2:9;
  short v3;
};
//SIG(1 Vp_BFu9s_S) C1{ Fp Fs:9 Fs}



static void Test_Vp_BFu9s_S()
{
  {
    init_simple_test("Vp_BFu9s_S");
    static STRUCT_IF_C Vp_BFu9s_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_S)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_S.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_S");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_S");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9s_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_S, Vp_BFu9s_S)
//============================================================================


struct  Vp_BFu9s_Uc  {
  void *v1;
  unsigned short v2:9;
  unsigned char v3;
};
//SIG(1 Vp_BFu9s_Uc) C1{ Fp Fs:9 Fc}



static void Test_Vp_BFu9s_Uc()
{
  {
    init_simple_test("Vp_BFu9s_Uc");
    static STRUCT_IF_C Vp_BFu9s_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_Uc)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_Uc.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_Uc");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_Uc");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9s_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_Uc, Vp_BFu9s_Uc)
//============================================================================


struct  Vp_BFu9s_Ui  {
  void *v1;
  unsigned short v2:9;
  unsigned int v3;
};
//SIG(1 Vp_BFu9s_Ui) C1{ Fp Fs:9 Fi}



static void Test_Vp_BFu9s_Ui()
{
  {
    init_simple_test("Vp_BFu9s_Ui");
    static STRUCT_IF_C Vp_BFu9s_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_BFu9s_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_Ui)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_Ui.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_Ui");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_Ui");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_BFu9s_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_Ui, Vp_BFu9s_Ui)
//============================================================================


struct  Vp_BFu9s_Ul  {
  void *v1;
  unsigned short v2:9;
  __tsu64 v3;
};
//SIG(1 Vp_BFu9s_Ul) C1{ Fp Fs:9 FL}



static void Test_Vp_BFu9s_Ul()
{
  {
    init_simple_test("Vp_BFu9s_Ul");
    static STRUCT_IF_C Vp_BFu9s_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_BFu9s_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_Ul)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_Ul.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_Ul");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_Ul");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9s_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_Ul, Vp_BFu9s_Ul)
//============================================================================


struct  Vp_BFu9s_Us  {
  void *v1;
  unsigned short v2:9;
  unsigned short v3;
};
//SIG(1 Vp_BFu9s_Us) C1{ Fp Fs:9 Fs}



static void Test_Vp_BFu9s_Us()
{
  {
    init_simple_test("Vp_BFu9s_Us");
    static STRUCT_IF_C Vp_BFu9s_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_BFu9s_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_Us)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_Us.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_Us");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_Us");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_BFu9s_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_Us, Vp_BFu9s_Us)
//============================================================================


struct  Vp_BFu9s_Vp  {
  void *v1;
  unsigned short v2:9;
  void *v3;
};
//SIG(1 Vp_BFu9s_Vp) C1{ Fp Fs:9 Fp}



static void Test_Vp_BFu9s_Vp()
{
  {
    init_simple_test("Vp_BFu9s_Vp");
    static STRUCT_IF_C Vp_BFu9s_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_BFu9s_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_BFu9s_Vp)");
    check_field_offset(lv, v1, 0, "Vp_BFu9s_Vp.v1");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, 1, "Vp_BFu9s_Vp");
    set_bf_and_test(lv, v2, ABISELECT(8,4), 0, 9, hide_ull(1LL<<8), "Vp_BFu9s_Vp");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_BFu9s_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_BFu9s_Vp, Vp_BFu9s_Vp)
//============================================================================


struct  Vp_C  {
  void *v1;
  char v2;
};
//SIG(1 Vp_C) C1{ Fp Fc}



static void Test_Vp_C()
{
  {
    init_simple_test("Vp_C");
    STRUCT_IF_C Vp_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C)");
    check_field_offset(lv, v1, 0, "Vp_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C, Vp_C)
//============================================================================


struct  Vp_C_BFu15i  {
  void *v1;
  char v2;
  unsigned int v3:15;
};
//SIG(1 Vp_C_BFu15i) C1{ Fp Fc Fi:15}



static void Test_Vp_C_BFu15i()
{
  {
    init_simple_test("Vp_C_BFu15i");
    static STRUCT_IF_C Vp_C_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_C_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_C_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu15i, Vp_C_BFu15i)
//============================================================================


struct  Vp_C_BFu15ll  {
  void *v1;
  char v2;
  __tsu64 v3:15;
};
//SIG(1 Vp_C_BFu15ll) C1{ Fp Fc FL:15}



static void Test_Vp_C_BFu15ll()
{
  {
    init_simple_test("Vp_C_BFu15ll");
    static STRUCT_IF_C Vp_C_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_C_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_C_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu15ll, Vp_C_BFu15ll)
//============================================================================


struct  Vp_C_BFu15s  {
  void *v1;
  char v2;
  unsigned short v3:15;
};
//SIG(1 Vp_C_BFu15s) C1{ Fp Fc Fs:15}



static void Test_Vp_C_BFu15s()
{
  {
    init_simple_test("Vp_C_BFu15s");
    static STRUCT_IF_C Vp_C_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_C_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_C_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu15s, Vp_C_BFu15s)
//============================================================================


struct  Vp_C_BFu16i  {
  void *v1;
  char v2;
  unsigned int v3:16;
};
//SIG(1 Vp_C_BFu16i) C1{ Fp Fc Fi:16}



static void Test_Vp_C_BFu16i()
{
  {
    init_simple_test("Vp_C_BFu16i");
    static STRUCT_IF_C Vp_C_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_C_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_C_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu16i, Vp_C_BFu16i)
//============================================================================


struct  Vp_C_BFu16ll  {
  void *v1;
  char v2;
  __tsu64 v3:16;
};
//SIG(1 Vp_C_BFu16ll) C1{ Fp Fc FL:16}



static void Test_Vp_C_BFu16ll()
{
  {
    init_simple_test("Vp_C_BFu16ll");
    static STRUCT_IF_C Vp_C_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_C_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_C_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu16ll, Vp_C_BFu16ll)
//============================================================================


struct  Vp_C_BFu16s  {
  void *v1;
  char v2;
  unsigned short v3:16;
};
//SIG(1 Vp_C_BFu16s) C1{ Fp Fc Fs:16}



static void Test_Vp_C_BFu16s()
{
  {
    init_simple_test("Vp_C_BFu16s");
    static STRUCT_IF_C Vp_C_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_C_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_C_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu16s, Vp_C_BFu16s)
//============================================================================


struct  Vp_C_BFu17i  {
  void *v1;
  char v2;
  unsigned int v3:17;
};
//SIG(1 Vp_C_BFu17i) C1{ Fp Fc Fi:17}



static void Test_Vp_C_BFu17i()
{
  {
    init_simple_test("Vp_C_BFu17i");
    static STRUCT_IF_C Vp_C_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_C_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_C_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu17i, Vp_C_BFu17i)
//============================================================================


struct  Vp_C_BFu17ll  {
  void *v1;
  char v2;
  __tsu64 v3:17;
};
//SIG(1 Vp_C_BFu17ll) C1{ Fp Fc FL:17}



static void Test_Vp_C_BFu17ll()
{
  {
    init_simple_test("Vp_C_BFu17ll");
    static STRUCT_IF_C Vp_C_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_C_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_C_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu17ll, Vp_C_BFu17ll)
//============================================================================


struct  Vp_C_BFu1c  {
  void *v1;
  char v2;
  unsigned char v3:1;
};
//SIG(1 Vp_C_BFu1c) C1{ Fp Fc Fc:1}



static void Test_Vp_C_BFu1c()
{
  {
    init_simple_test("Vp_C_BFu1c");
    static STRUCT_IF_C Vp_C_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_C_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu1c, Vp_C_BFu1c)
//============================================================================


struct  Vp_C_BFu1i  {
  void *v1;
  char v2;
  unsigned int v3:1;
};
//SIG(1 Vp_C_BFu1i) C1{ Fp Fc Fi:1}



static void Test_Vp_C_BFu1i()
{
  {
    init_simple_test("Vp_C_BFu1i");
    static STRUCT_IF_C Vp_C_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_C_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu1i, Vp_C_BFu1i)
//============================================================================


struct  Vp_C_BFu1ll  {
  void *v1;
  char v2;
  __tsu64 v3:1;
};
//SIG(1 Vp_C_BFu1ll) C1{ Fp Fc FL:1}



static void Test_Vp_C_BFu1ll()
{
  {
    init_simple_test("Vp_C_BFu1ll");
    static STRUCT_IF_C Vp_C_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_C_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu1ll, Vp_C_BFu1ll)
//============================================================================


struct  Vp_C_BFu1s  {
  void *v1;
  char v2;
  unsigned short v3:1;
};
//SIG(1 Vp_C_BFu1s) C1{ Fp Fc Fs:1}



static void Test_Vp_C_BFu1s()
{
  {
    init_simple_test("Vp_C_BFu1s");
    static STRUCT_IF_C Vp_C_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_C_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu1s, Vp_C_BFu1s)
//============================================================================


struct  Vp_C_BFu31i  {
  void *v1;
  char v2;
  unsigned int v3:31;
};
//SIG(1 Vp_C_BFu31i) C1{ Fp Fc Fi:31}



static void Test_Vp_C_BFu31i()
{
  {
    init_simple_test("Vp_C_BFu31i");
    static STRUCT_IF_C Vp_C_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_C_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_C_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_C_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu31i, Vp_C_BFu31i)
//============================================================================


struct  Vp_C_BFu31ll  {
  void *v1;
  char v2;
  __tsu64 v3:31;
};
//SIG(1 Vp_C_BFu31ll) C1{ Fp Fc FL:31}



static void Test_Vp_C_BFu31ll()
{
  {
    init_simple_test("Vp_C_BFu31ll");
    static STRUCT_IF_C Vp_C_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_C_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, 1, "Vp_C_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, hide_ull(1LL<<30), "Vp_C_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu31ll, Vp_C_BFu31ll)
//============================================================================


struct  Vp_C_BFu32i  {
  void *v1;
  char v2;
  unsigned int v3:32;
};
//SIG(1 Vp_C_BFu32i) C1{ Fp Fc Fi:32}



static void Test_Vp_C_BFu32i()
{
  {
    init_simple_test("Vp_C_BFu32i");
    static STRUCT_IF_C Vp_C_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_C_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_C_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_C_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu32i, Vp_C_BFu32i)
//============================================================================


struct  Vp_C_BFu32ll  {
  void *v1;
  char v2;
  __tsu64 v3:32;
};
//SIG(1 Vp_C_BFu32ll) C1{ Fp Fc FL:32}



static void Test_Vp_C_BFu32ll()
{
  {
    init_simple_test("Vp_C_BFu32ll");
    static STRUCT_IF_C Vp_C_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_C_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, 1, "Vp_C_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, hide_ull(1LL<<31), "Vp_C_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu32ll, Vp_C_BFu32ll)
//============================================================================


struct  Vp_C_BFu33  {
  void *v1;
  char v2;
  __tsu64 v3:33;
};
//SIG(1 Vp_C_BFu33) C1{ Fp Fc FL:33}



static void Test_Vp_C_BFu33()
{
  {
    init_simple_test("Vp_C_BFu33");
    static STRUCT_IF_C Vp_C_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_C_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, 1, "Vp_C_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, hide_ull(1LL<<32), "Vp_C_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu33, Vp_C_BFu33)
//============================================================================


struct  Vp_C_BFu7c  {
  void *v1;
  char v2;
  unsigned char v3:7;
};
//SIG(1 Vp_C_BFu7c) C1{ Fp Fc Fc:7}



static void Test_Vp_C_BFu7c()
{
  {
    init_simple_test("Vp_C_BFu7c");
    static STRUCT_IF_C Vp_C_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_C_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_C_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu7c, Vp_C_BFu7c)
//============================================================================


struct  Vp_C_BFu7i  {
  void *v1;
  char v2;
  unsigned int v3:7;
};
//SIG(1 Vp_C_BFu7i) C1{ Fp Fc Fi:7}



static void Test_Vp_C_BFu7i()
{
  {
    init_simple_test("Vp_C_BFu7i");
    static STRUCT_IF_C Vp_C_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_C_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_C_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu7i, Vp_C_BFu7i)
//============================================================================


struct  Vp_C_BFu7ll  {
  void *v1;
  char v2;
  __tsu64 v3:7;
};
//SIG(1 Vp_C_BFu7ll) C1{ Fp Fc FL:7}



static void Test_Vp_C_BFu7ll()
{
  {
    init_simple_test("Vp_C_BFu7ll");
    static STRUCT_IF_C Vp_C_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_C_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_C_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu7ll, Vp_C_BFu7ll)
//============================================================================


struct  Vp_C_BFu7s  {
  void *v1;
  char v2;
  unsigned short v3:7;
};
//SIG(1 Vp_C_BFu7s) C1{ Fp Fc Fs:7}



static void Test_Vp_C_BFu7s()
{
  {
    init_simple_test("Vp_C_BFu7s");
    static STRUCT_IF_C Vp_C_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_C_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_C_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu7s, Vp_C_BFu7s)
//============================================================================


struct  Vp_C_BFu8c  {
  void *v1;
  char v2;
  unsigned char v3:8;
};
//SIG(1 Vp_C_BFu8c) C1{ Fp Fc Fc:8}



static void Test_Vp_C_BFu8c()
{
  {
    init_simple_test("Vp_C_BFu8c");
    static STRUCT_IF_C Vp_C_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_C_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_C_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu8c, Vp_C_BFu8c)
//============================================================================


struct  Vp_C_BFu8i  {
  void *v1;
  char v2;
  unsigned int v3:8;
};
//SIG(1 Vp_C_BFu8i) C1{ Fp Fc Fi:8}



static void Test_Vp_C_BFu8i()
{
  {
    init_simple_test("Vp_C_BFu8i");
    static STRUCT_IF_C Vp_C_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_C_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_C_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu8i, Vp_C_BFu8i)
//============================================================================


struct  Vp_C_BFu8ll  {
  void *v1;
  char v2;
  __tsu64 v3:8;
};
//SIG(1 Vp_C_BFu8ll) C1{ Fp Fc FL:8}



static void Test_Vp_C_BFu8ll()
{
  {
    init_simple_test("Vp_C_BFu8ll");
    static STRUCT_IF_C Vp_C_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_C_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_C_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu8ll, Vp_C_BFu8ll)
//============================================================================


struct  Vp_C_BFu8s  {
  void *v1;
  char v2;
  unsigned short v3:8;
};
//SIG(1 Vp_C_BFu8s) C1{ Fp Fc Fs:8}



static void Test_Vp_C_BFu8s()
{
  {
    init_simple_test("Vp_C_BFu8s");
    static STRUCT_IF_C Vp_C_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_C_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_C_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu8s, Vp_C_BFu8s)
//============================================================================


struct  Vp_C_BFu9i  {
  void *v1;
  char v2;
  unsigned int v3:9;
};
//SIG(1 Vp_C_BFu9i) C1{ Fp Fc Fi:9}



static void Test_Vp_C_BFu9i()
{
  {
    init_simple_test("Vp_C_BFu9i");
    static STRUCT_IF_C Vp_C_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_C_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_C_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu9i, Vp_C_BFu9i)
//============================================================================


struct  Vp_C_BFu9ll  {
  void *v1;
  char v2;
  __tsu64 v3:9;
};
//SIG(1 Vp_C_BFu9ll) C1{ Fp Fc FL:9}



static void Test_Vp_C_BFu9ll()
{
  {
    init_simple_test("Vp_C_BFu9ll");
    static STRUCT_IF_C Vp_C_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_C_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_C_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu9ll, Vp_C_BFu9ll)
//============================================================================


struct  Vp_C_BFu9s  {
  void *v1;
  char v2;
  unsigned short v3:9;
};
//SIG(1 Vp_C_BFu9s) C1{ Fp Fc Fs:9}



static void Test_Vp_C_BFu9s()
{
  {
    init_simple_test("Vp_C_BFu9s");
    static STRUCT_IF_C Vp_C_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_C_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_C_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_C_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_BFu9s, Vp_C_BFu9s)
//============================================================================


struct  Vp_C_C  {
  void *v1;
  char v2;
  char v3;
};
//SIG(1 Vp_C_C) C1{ Fp Fc[2]}



static void Test_Vp_C_C()
{
  {
    init_simple_test("Vp_C_C");
    STRUCT_IF_C Vp_C_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_C)");
    check_field_offset(lv, v1, 0, "Vp_C_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_C.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_C_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_C, Vp_C_C)
//============================================================================


struct  Vp_C_D  {
  void *v1;
  char v2;
  double v3;
};
//SIG(1 Vp_C_D) C1{ Fp Fc FL}



static void Test_Vp_C_D()
{
  {
    init_simple_test("Vp_C_D");
    STRUCT_IF_C Vp_C_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_C_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_D)");
    check_field_offset(lv, v1, 0, "Vp_C_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_D.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_C_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_D, Vp_C_D)
//============================================================================


struct  Vp_C_F  {
  void *v1;
  char v2;
  float v3;
};
//SIG(1 Vp_C_F) C1{ Fp Fc Fi}



static void Test_Vp_C_F()
{
  {
    init_simple_test("Vp_C_F");
    STRUCT_IF_C Vp_C_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_C_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_F)");
    check_field_offset(lv, v1, 0, "Vp_C_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_F.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_C_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_F, Vp_C_F)
//============================================================================


struct  Vp_C_I  {
  void *v1;
  char v2;
  int v3;
};
//SIG(1 Vp_C_I) C1{ Fp Fc Fi}



static void Test_Vp_C_I()
{
  {
    init_simple_test("Vp_C_I");
    STRUCT_IF_C Vp_C_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_C_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_I)");
    check_field_offset(lv, v1, 0, "Vp_C_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_I.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_C_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_I, Vp_C_I)
//============================================================================


struct  Vp_C_Ip  {
  void *v1;
  char v2;
  int *v3;
};
//SIG(1 Vp_C_Ip) C1{ Fp Fc Fp}



static void Test_Vp_C_Ip()
{
  {
    init_simple_test("Vp_C_Ip");
    STRUCT_IF_C Vp_C_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_C_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_Ip)");
    check_field_offset(lv, v1, 0, "Vp_C_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_C_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_Ip, Vp_C_Ip)
//============================================================================


struct  Vp_C_L  {
  void *v1;
  char v2;
  __tsi64 v3;
};
//SIG(1 Vp_C_L) C1{ Fp Fc FL}



static void Test_Vp_C_L()
{
  {
    init_simple_test("Vp_C_L");
    STRUCT_IF_C Vp_C_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_C_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_L)");
    check_field_offset(lv, v1, 0, "Vp_C_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_L.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_C_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_L, Vp_C_L)
//============================================================================


struct  Vp_C_S  {
  void *v1;
  char v2;
  short v3;
};
//SIG(1 Vp_C_S) C1{ Fp Fc Fs}



static void Test_Vp_C_S()
{
  {
    init_simple_test("Vp_C_S");
    STRUCT_IF_C Vp_C_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_S)");
    check_field_offset(lv, v1, 0, "Vp_C_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_S.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_C_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_S, Vp_C_S)
//============================================================================


struct  Vp_C_Uc  {
  void *v1;
  char v2;
  unsigned char v3;
};
//SIG(1 Vp_C_Uc) C1{ Fp Fc[2]}



static void Test_Vp_C_Uc()
{
  {
    init_simple_test("Vp_C_Uc");
    STRUCT_IF_C Vp_C_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_Uc)");
    check_field_offset(lv, v1, 0, "Vp_C_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_C_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_Uc, Vp_C_Uc)
//============================================================================


struct  Vp_C_Ui  {
  void *v1;
  char v2;
  unsigned int v3;
};
//SIG(1 Vp_C_Ui) C1{ Fp Fc Fi}



static void Test_Vp_C_Ui()
{
  {
    init_simple_test("Vp_C_Ui");
    STRUCT_IF_C Vp_C_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_C_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_Ui)");
    check_field_offset(lv, v1, 0, "Vp_C_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_C_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_Ui, Vp_C_Ui)
//============================================================================


struct  Vp_C_Ul  {
  void *v1;
  char v2;
  __tsu64 v3;
};
//SIG(1 Vp_C_Ul) C1{ Fp Fc FL}



static void Test_Vp_C_Ul()
{
  {
    init_simple_test("Vp_C_Ul");
    STRUCT_IF_C Vp_C_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_C_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_Ul)");
    check_field_offset(lv, v1, 0, "Vp_C_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_C_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_Ul, Vp_C_Ul)
//============================================================================


struct  Vp_C_Us  {
  void *v1;
  char v2;
  unsigned short v3;
};
//SIG(1 Vp_C_Us) C1{ Fp Fc Fs}



static void Test_Vp_C_Us()
{
  {
    init_simple_test("Vp_C_Us");
    STRUCT_IF_C Vp_C_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_C_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_Us)");
    check_field_offset(lv, v1, 0, "Vp_C_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_Us.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_C_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_Us, Vp_C_Us)
//============================================================================


struct  Vp_C_Vp  {
  void *v1;
  char v2;
  void *v3;
};
//SIG(1 Vp_C_Vp) C1{ Fp Fc Fp}



static void Test_Vp_C_Vp()
{
  {
    init_simple_test("Vp_C_Vp");
    STRUCT_IF_C Vp_C_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_C_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_C_Vp)");
    check_field_offset(lv, v1, 0, "Vp_C_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_C_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_C_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_C_Vp, Vp_C_Vp)
//============================================================================


struct  Vp_D  {
  void *v1;
  double v2;
};
//SIG(1 Vp_D) C1{ Fp FL}



static void Test_Vp_D()
{
  {
    init_simple_test("Vp_D");
    STRUCT_IF_C Vp_D lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D)");
    check_field_offset(lv, v1, 0, "Vp_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D, Vp_D)
//============================================================================


struct  Vp_D_BFu15i  {
  void *v1;
  double v2;
  unsigned int v3:15;
};
//SIG(1 Vp_D_BFu15i) C1{ Fp FL Fi:15}



static void Test_Vp_D_BFu15i()
{
  {
    init_simple_test("Vp_D_BFu15i");
    static STRUCT_IF_C Vp_D_BFu15i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, 1, "Vp_D_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, hide_ull(1LL<<14), "Vp_D_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu15i, Vp_D_BFu15i)
//============================================================================


struct  Vp_D_BFu15ll  {
  void *v1;
  double v2;
  __tsu64 v3:15;
};
//SIG(1 Vp_D_BFu15ll) C1{ Fp FL FL:15}



static void Test_Vp_D_BFu15ll()
{
  {
    init_simple_test("Vp_D_BFu15ll");
    static STRUCT_IF_C Vp_D_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, 1, "Vp_D_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, hide_ull(1LL<<14), "Vp_D_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu15ll, Vp_D_BFu15ll)
//============================================================================


struct  Vp_D_BFu15s  {
  void *v1;
  double v2;
  unsigned short v3:15;
};
//SIG(1 Vp_D_BFu15s) C1{ Fp FL Fs:15}



static void Test_Vp_D_BFu15s()
{
  {
    init_simple_test("Vp_D_BFu15s");
    static STRUCT_IF_C Vp_D_BFu15s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, 1, "Vp_D_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, hide_ull(1LL<<14), "Vp_D_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu15s, Vp_D_BFu15s)
//============================================================================


struct  Vp_D_BFu16i  {
  void *v1;
  double v2;
  unsigned int v3:16;
};
//SIG(1 Vp_D_BFu16i) C1{ Fp FL Fi:16}



static void Test_Vp_D_BFu16i()
{
  {
    init_simple_test("Vp_D_BFu16i");
    static STRUCT_IF_C Vp_D_BFu16i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, 1, "Vp_D_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, hide_ull(1LL<<15), "Vp_D_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu16i, Vp_D_BFu16i)
//============================================================================


struct  Vp_D_BFu16ll  {
  void *v1;
  double v2;
  __tsu64 v3:16;
};
//SIG(1 Vp_D_BFu16ll) C1{ Fp FL FL:16}



static void Test_Vp_D_BFu16ll()
{
  {
    init_simple_test("Vp_D_BFu16ll");
    static STRUCT_IF_C Vp_D_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, 1, "Vp_D_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, hide_ull(1LL<<15), "Vp_D_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu16ll, Vp_D_BFu16ll)
//============================================================================


struct  Vp_D_BFu16s  {
  void *v1;
  double v2;
  unsigned short v3:16;
};
//SIG(1 Vp_D_BFu16s) C1{ Fp FL Fs:16}



static void Test_Vp_D_BFu16s()
{
  {
    init_simple_test("Vp_D_BFu16s");
    static STRUCT_IF_C Vp_D_BFu16s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, 1, "Vp_D_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, hide_ull(1LL<<15), "Vp_D_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu16s, Vp_D_BFu16s)
//============================================================================


struct  Vp_D_BFu17i  {
  void *v1;
  double v2;
  unsigned int v3:17;
};
//SIG(1 Vp_D_BFu17i) C1{ Fp FL Fi:17}



static void Test_Vp_D_BFu17i()
{
  {
    init_simple_test("Vp_D_BFu17i");
    static STRUCT_IF_C Vp_D_BFu17i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 17, 1, "Vp_D_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 17, hide_ull(1LL<<16), "Vp_D_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu17i, Vp_D_BFu17i)
//============================================================================


struct  Vp_D_BFu17ll  {
  void *v1;
  double v2;
  __tsu64 v3:17;
};
//SIG(1 Vp_D_BFu17ll) C1{ Fp FL FL:17}



static void Test_Vp_D_BFu17ll()
{
  {
    init_simple_test("Vp_D_BFu17ll");
    static STRUCT_IF_C Vp_D_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 17, 1, "Vp_D_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 17, hide_ull(1LL<<16), "Vp_D_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu17ll, Vp_D_BFu17ll)
//============================================================================


struct  Vp_D_BFu1c  {
  void *v1;
  double v2;
  unsigned char v3:1;
};
//SIG(1 Vp_D_BFu1c) C1{ Fp FL Fc:1}



static void Test_Vp_D_BFu1c()
{
  {
    init_simple_test("Vp_D_BFu1c");
    static STRUCT_IF_C Vp_D_BFu1c lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 1, 1, "Vp_D_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu1c, Vp_D_BFu1c)
//============================================================================


struct  Vp_D_BFu1i  {
  void *v1;
  double v2;
  unsigned int v3:1;
};
//SIG(1 Vp_D_BFu1i) C1{ Fp FL Fi:1}



static void Test_Vp_D_BFu1i()
{
  {
    init_simple_test("Vp_D_BFu1i");
    static STRUCT_IF_C Vp_D_BFu1i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 1, 1, "Vp_D_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu1i, Vp_D_BFu1i)
//============================================================================


struct  Vp_D_BFu1ll  {
  void *v1;
  double v2;
  __tsu64 v3:1;
};
//SIG(1 Vp_D_BFu1ll) C1{ Fp FL FL:1}



static void Test_Vp_D_BFu1ll()
{
  {
    init_simple_test("Vp_D_BFu1ll");
    static STRUCT_IF_C Vp_D_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 1, 1, "Vp_D_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu1ll, Vp_D_BFu1ll)
//============================================================================


struct  Vp_D_BFu1s  {
  void *v1;
  double v2;
  unsigned short v3:1;
};
//SIG(1 Vp_D_BFu1s) C1{ Fp FL Fs:1}



static void Test_Vp_D_BFu1s()
{
  {
    init_simple_test("Vp_D_BFu1s");
    static STRUCT_IF_C Vp_D_BFu1s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 1, 1, "Vp_D_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu1s, Vp_D_BFu1s)
//============================================================================


struct  Vp_D_BFu31i  {
  void *v1;
  double v2;
  unsigned int v3:31;
};
//SIG(1 Vp_D_BFu31i) C1{ Fp FL Fi:31}



static void Test_Vp_D_BFu31i()
{
  {
    init_simple_test("Vp_D_BFu31i");
    static STRUCT_IF_C Vp_D_BFu31i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 31, 1, "Vp_D_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 31, hide_ull(1LL<<30), "Vp_D_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu31i, Vp_D_BFu31i)
//============================================================================


struct  Vp_D_BFu31ll  {
  void *v1;
  double v2;
  __tsu64 v3:31;
};
//SIG(1 Vp_D_BFu31ll) C1{ Fp FL FL:31}



static void Test_Vp_D_BFu31ll()
{
  {
    init_simple_test("Vp_D_BFu31ll");
    static STRUCT_IF_C Vp_D_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 31, 1, "Vp_D_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 31, hide_ull(1LL<<30), "Vp_D_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu31ll, Vp_D_BFu31ll)
//============================================================================


struct  Vp_D_BFu32i  {
  void *v1;
  double v2;
  unsigned int v3:32;
};
//SIG(1 Vp_D_BFu32i) C1{ Fp FL Fi:32}



static void Test_Vp_D_BFu32i()
{
  {
    init_simple_test("Vp_D_BFu32i");
    static STRUCT_IF_C Vp_D_BFu32i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, 1, "Vp_D_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, hide_ull(1LL<<31), "Vp_D_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu32i, Vp_D_BFu32i)
//============================================================================


struct  Vp_D_BFu32ll  {
  void *v1;
  double v2;
  __tsu64 v3:32;
};
//SIG(1 Vp_D_BFu32ll) C1{ Fp FL FL:32}



static void Test_Vp_D_BFu32ll()
{
  {
    init_simple_test("Vp_D_BFu32ll");
    static STRUCT_IF_C Vp_D_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, 1, "Vp_D_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, hide_ull(1LL<<31), "Vp_D_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu32ll, Vp_D_BFu32ll)
//============================================================================


struct  Vp_D_BFu33  {
  void *v1;
  double v2;
  __tsu64 v3:33;
};
//SIG(1 Vp_D_BFu33) C1{ Fp FL FL:33}



static void Test_Vp_D_BFu33()
{
  {
    init_simple_test("Vp_D_BFu33");
    static STRUCT_IF_C Vp_D_BFu33 lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_D_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 33, 1, "Vp_D_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 33, hide_ull(1LL<<32), "Vp_D_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu33, Vp_D_BFu33)
//============================================================================


struct  Vp_D_BFu7c  {
  void *v1;
  double v2;
  unsigned char v3:7;
};
//SIG(1 Vp_D_BFu7c) C1{ Fp FL Fc:7}



static void Test_Vp_D_BFu7c()
{
  {
    init_simple_test("Vp_D_BFu7c");
    static STRUCT_IF_C Vp_D_BFu7c lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, 1, "Vp_D_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, hide_ull(1LL<<6), "Vp_D_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu7c, Vp_D_BFu7c)
//============================================================================


struct  Vp_D_BFu7i  {
  void *v1;
  double v2;
  unsigned int v3:7;
};
//SIG(1 Vp_D_BFu7i) C1{ Fp FL Fi:7}



static void Test_Vp_D_BFu7i()
{
  {
    init_simple_test("Vp_D_BFu7i");
    static STRUCT_IF_C Vp_D_BFu7i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, 1, "Vp_D_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, hide_ull(1LL<<6), "Vp_D_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu7i, Vp_D_BFu7i)
//============================================================================


struct  Vp_D_BFu7ll  {
  void *v1;
  double v2;
  __tsu64 v3:7;
};
//SIG(1 Vp_D_BFu7ll) C1{ Fp FL FL:7}



static void Test_Vp_D_BFu7ll()
{
  {
    init_simple_test("Vp_D_BFu7ll");
    static STRUCT_IF_C Vp_D_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, 1, "Vp_D_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, hide_ull(1LL<<6), "Vp_D_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu7ll, Vp_D_BFu7ll)
//============================================================================


struct  Vp_D_BFu7s  {
  void *v1;
  double v2;
  unsigned short v3:7;
};
//SIG(1 Vp_D_BFu7s) C1{ Fp FL Fs:7}



static void Test_Vp_D_BFu7s()
{
  {
    init_simple_test("Vp_D_BFu7s");
    static STRUCT_IF_C Vp_D_BFu7s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, 1, "Vp_D_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, hide_ull(1LL<<6), "Vp_D_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu7s, Vp_D_BFu7s)
//============================================================================


struct  Vp_D_BFu8c  {
  void *v1;
  double v2;
  unsigned char v3:8;
};
//SIG(1 Vp_D_BFu8c) C1{ Fp FL Fc:8}



static void Test_Vp_D_BFu8c()
{
  {
    init_simple_test("Vp_D_BFu8c");
    static STRUCT_IF_C Vp_D_BFu8c lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, 1, "Vp_D_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, hide_ull(1LL<<7), "Vp_D_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu8c, Vp_D_BFu8c)
//============================================================================


struct  Vp_D_BFu8i  {
  void *v1;
  double v2;
  unsigned int v3:8;
};
//SIG(1 Vp_D_BFu8i) C1{ Fp FL Fi:8}



static void Test_Vp_D_BFu8i()
{
  {
    init_simple_test("Vp_D_BFu8i");
    static STRUCT_IF_C Vp_D_BFu8i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, 1, "Vp_D_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, hide_ull(1LL<<7), "Vp_D_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu8i, Vp_D_BFu8i)
//============================================================================


struct  Vp_D_BFu8ll  {
  void *v1;
  double v2;
  __tsu64 v3:8;
};
//SIG(1 Vp_D_BFu8ll) C1{ Fp FL FL:8}



static void Test_Vp_D_BFu8ll()
{
  {
    init_simple_test("Vp_D_BFu8ll");
    static STRUCT_IF_C Vp_D_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, 1, "Vp_D_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, hide_ull(1LL<<7), "Vp_D_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu8ll, Vp_D_BFu8ll)
//============================================================================


struct  Vp_D_BFu8s  {
  void *v1;
  double v2;
  unsigned short v3:8;
};
//SIG(1 Vp_D_BFu8s) C1{ Fp FL Fs:8}



static void Test_Vp_D_BFu8s()
{
  {
    init_simple_test("Vp_D_BFu8s");
    static STRUCT_IF_C Vp_D_BFu8s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, 1, "Vp_D_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, hide_ull(1LL<<7), "Vp_D_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu8s, Vp_D_BFu8s)
//============================================================================


struct  Vp_D_BFu9i  {
  void *v1;
  double v2;
  unsigned int v3:9;
};
//SIG(1 Vp_D_BFu9i) C1{ Fp FL Fi:9}



static void Test_Vp_D_BFu9i()
{
  {
    init_simple_test("Vp_D_BFu9i");
    static STRUCT_IF_C Vp_D_BFu9i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, 1, "Vp_D_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, hide_ull(1LL<<8), "Vp_D_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu9i, Vp_D_BFu9i)
//============================================================================


struct  Vp_D_BFu9ll  {
  void *v1;
  double v2;
  __tsu64 v3:9;
};
//SIG(1 Vp_D_BFu9ll) C1{ Fp FL FL:9}



static void Test_Vp_D_BFu9ll()
{
  {
    init_simple_test("Vp_D_BFu9ll");
    static STRUCT_IF_C Vp_D_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, 1, "Vp_D_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, hide_ull(1LL<<8), "Vp_D_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu9ll, Vp_D_BFu9ll)
//============================================================================


struct  Vp_D_BFu9s  {
  void *v1;
  double v2;
  unsigned short v3:9;
};
//SIG(1 Vp_D_BFu9s) C1{ Fp FL Fs:9}



static void Test_Vp_D_BFu9s()
{
  {
    init_simple_test("Vp_D_BFu9s");
    static STRUCT_IF_C Vp_D_BFu9s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_D_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, 1, "Vp_D_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, hide_ull(1LL<<8), "Vp_D_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_BFu9s, Vp_D_BFu9s)
//============================================================================


struct  Vp_D_C  {
  void *v1;
  double v2;
  char v3;
};
//SIG(1 Vp_D_C) C1{ Fp FL Fc}



static void Test_Vp_D_C()
{
  {
    init_simple_test("Vp_D_C");
    STRUCT_IF_C Vp_D_C lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_C)");
    check_field_offset(lv, v1, 0, "Vp_D_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_C.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_C, Vp_D_C)
//============================================================================


struct  Vp_D_D  {
  void *v1;
  double v2;
  double v3;
};
//SIG(1 Vp_D_D) C1{ Fp FL[2]}



static void Test_Vp_D_D()
{
  {
    init_simple_test("Vp_D_D");
    STRUCT_IF_C Vp_D_D lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_D_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_D)");
    check_field_offset(lv, v1, 0, "Vp_D_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_D.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_D, Vp_D_D)
//============================================================================


struct  Vp_D_F  {
  void *v1;
  double v2;
  float v3;
};
//SIG(1 Vp_D_F) C1{ Fp FL Fi}



static void Test_Vp_D_F()
{
  {
    init_simple_test("Vp_D_F");
    STRUCT_IF_C Vp_D_F lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_F)");
    check_field_offset(lv, v1, 0, "Vp_D_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_F.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_F, Vp_D_F)
//============================================================================


struct  Vp_D_I  {
  void *v1;
  double v2;
  int v3;
};
//SIG(1 Vp_D_I) C1{ Fp FL Fi}



static void Test_Vp_D_I()
{
  {
    init_simple_test("Vp_D_I");
    STRUCT_IF_C Vp_D_I lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_I)");
    check_field_offset(lv, v1, 0, "Vp_D_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_I.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_I, Vp_D_I)
//============================================================================


struct  Vp_D_Ip  {
  void *v1;
  double v2;
  int *v3;
};
//SIG(1 Vp_D_Ip) C1{ Fp FL Fp}



static void Test_Vp_D_Ip()
{
  {
    init_simple_test("Vp_D_Ip");
    STRUCT_IF_C Vp_D_Ip lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_Ip)");
    check_field_offset(lv, v1, 0, "Vp_D_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_Ip, Vp_D_Ip)
//============================================================================


struct  Vp_D_L  {
  void *v1;
  double v2;
  __tsi64 v3;
};
//SIG(1 Vp_D_L) C1{ Fp FL[2]}



static void Test_Vp_D_L()
{
  {
    init_simple_test("Vp_D_L");
    STRUCT_IF_C Vp_D_L lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_D_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_L)");
    check_field_offset(lv, v1, 0, "Vp_D_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_L.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_L, Vp_D_L)
//============================================================================


struct  Vp_D_S  {
  void *v1;
  double v2;
  short v3;
};
//SIG(1 Vp_D_S) C1{ Fp FL Fs}



static void Test_Vp_D_S()
{
  {
    init_simple_test("Vp_D_S");
    STRUCT_IF_C Vp_D_S lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_S)");
    check_field_offset(lv, v1, 0, "Vp_D_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_S.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_S, Vp_D_S)
//============================================================================


struct  Vp_D_Uc  {
  void *v1;
  double v2;
  unsigned char v3;
};
//SIG(1 Vp_D_Uc) C1{ Fp FL Fc}



static void Test_Vp_D_Uc()
{
  {
    init_simple_test("Vp_D_Uc");
    STRUCT_IF_C Vp_D_Uc lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_Uc)");
    check_field_offset(lv, v1, 0, "Vp_D_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_Uc, Vp_D_Uc)
//============================================================================


struct  Vp_D_Ui  {
  void *v1;
  double v2;
  unsigned int v3;
};
//SIG(1 Vp_D_Ui) C1{ Fp FL Fi}



static void Test_Vp_D_Ui()
{
  {
    init_simple_test("Vp_D_Ui");
    STRUCT_IF_C Vp_D_Ui lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_Ui)");
    check_field_offset(lv, v1, 0, "Vp_D_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_Ui, Vp_D_Ui)
//============================================================================


struct  Vp_D_Ul  {
  void *v1;
  double v2;
  __tsu64 v3;
};
//SIG(1 Vp_D_Ul) C1{ Fp FL[2]}



static void Test_Vp_D_Ul()
{
  {
    init_simple_test("Vp_D_Ul");
    STRUCT_IF_C Vp_D_Ul lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_D_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_Ul)");
    check_field_offset(lv, v1, 0, "Vp_D_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_Ul, Vp_D_Ul)
//============================================================================


struct  Vp_D_Us  {
  void *v1;
  double v2;
  unsigned short v3;
};
//SIG(1 Vp_D_Us) C1{ Fp FL Fs}



static void Test_Vp_D_Us()
{
  {
    init_simple_test("Vp_D_Us");
    STRUCT_IF_C Vp_D_Us lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_Us)");
    check_field_offset(lv, v1, 0, "Vp_D_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_Us.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_Us, Vp_D_Us)
//============================================================================


struct  Vp_D_Vp  {
  void *v1;
  double v2;
  void *v3;
};
//SIG(1 Vp_D_Vp) C1{ Fp FL Fp}



static void Test_Vp_D_Vp()
{
  {
    init_simple_test("Vp_D_Vp");
    STRUCT_IF_C Vp_D_Vp lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_D_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_D_Vp)");
    check_field_offset(lv, v1, 0, "Vp_D_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_D_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_D_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_D_Vp, Vp_D_Vp)
//============================================================================


struct  Vp_F  {
  void *v1;
  float v2;
};
//SIG(1 Vp_F) C1{ Fp Fi}



static void Test_Vp_F()
{
  {
    init_simple_test("Vp_F");
    STRUCT_IF_C Vp_F lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F)");
    check_field_offset(lv, v1, 0, "Vp_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F, Vp_F)
//============================================================================


struct  Vp_F_BFu15i  {
  void *v1;
  float v2;
  unsigned int v3:15;
};
//SIG(1 Vp_F_BFu15i) C1{ Fp Fi Fi:15}



static void Test_Vp_F_BFu15i()
{
  {
    init_simple_test("Vp_F_BFu15i");
    static STRUCT_IF_C Vp_F_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, 1, "Vp_F_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, hide_ull(1LL<<14), "Vp_F_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu15i, Vp_F_BFu15i)
//============================================================================


struct  Vp_F_BFu15ll  {
  void *v1;
  float v2;
  __tsu64 v3:15;
};
//SIG(1 Vp_F_BFu15ll) C1{ Fp Fi FL:15}



static void Test_Vp_F_BFu15ll()
{
  {
    init_simple_test("Vp_F_BFu15ll");
    static STRUCT_IF_C Vp_F_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, 1, "Vp_F_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, hide_ull(1LL<<14), "Vp_F_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu15ll, Vp_F_BFu15ll)
//============================================================================


struct  Vp_F_BFu15s  {
  void *v1;
  float v2;
  unsigned short v3:15;
};
//SIG(1 Vp_F_BFu15s) C1{ Fp Fi Fs:15}



static void Test_Vp_F_BFu15s()
{
  {
    init_simple_test("Vp_F_BFu15s");
    static STRUCT_IF_C Vp_F_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, 1, "Vp_F_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, hide_ull(1LL<<14), "Vp_F_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu15s, Vp_F_BFu15s)
//============================================================================


struct  Vp_F_BFu16i  {
  void *v1;
  float v2;
  unsigned int v3:16;
};
//SIG(1 Vp_F_BFu16i) C1{ Fp Fi Fi:16}



static void Test_Vp_F_BFu16i()
{
  {
    init_simple_test("Vp_F_BFu16i");
    static STRUCT_IF_C Vp_F_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, 1, "Vp_F_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, hide_ull(1LL<<15), "Vp_F_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu16i, Vp_F_BFu16i)
//============================================================================


struct  Vp_F_BFu16ll  {
  void *v1;
  float v2;
  __tsu64 v3:16;
};
//SIG(1 Vp_F_BFu16ll) C1{ Fp Fi FL:16}



static void Test_Vp_F_BFu16ll()
{
  {
    init_simple_test("Vp_F_BFu16ll");
    static STRUCT_IF_C Vp_F_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, 1, "Vp_F_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, hide_ull(1LL<<15), "Vp_F_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu16ll, Vp_F_BFu16ll)
//============================================================================


struct  Vp_F_BFu16s  {
  void *v1;
  float v2;
  unsigned short v3:16;
};
//SIG(1 Vp_F_BFu16s) C1{ Fp Fi Fs:16}



static void Test_Vp_F_BFu16s()
{
  {
    init_simple_test("Vp_F_BFu16s");
    static STRUCT_IF_C Vp_F_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, 1, "Vp_F_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, hide_ull(1LL<<15), "Vp_F_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu16s, Vp_F_BFu16s)
//============================================================================


struct  Vp_F_BFu17i  {
  void *v1;
  float v2;
  unsigned int v3:17;
};
//SIG(1 Vp_F_BFu17i) C1{ Fp Fi Fi:17}



static void Test_Vp_F_BFu17i()
{
  {
    init_simple_test("Vp_F_BFu17i");
    static STRUCT_IF_C Vp_F_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, 1, "Vp_F_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, hide_ull(1LL<<16), "Vp_F_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu17i, Vp_F_BFu17i)
//============================================================================


struct  Vp_F_BFu17ll  {
  void *v1;
  float v2;
  __tsu64 v3:17;
};
//SIG(1 Vp_F_BFu17ll) C1{ Fp Fi FL:17}



static void Test_Vp_F_BFu17ll()
{
  {
    init_simple_test("Vp_F_BFu17ll");
    static STRUCT_IF_C Vp_F_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, 1, "Vp_F_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, hide_ull(1LL<<16), "Vp_F_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu17ll, Vp_F_BFu17ll)
//============================================================================


struct  Vp_F_BFu1c  {
  void *v1;
  float v2;
  unsigned char v3:1;
};
//SIG(1 Vp_F_BFu1c) C1{ Fp Fi Fc:1}



static void Test_Vp_F_BFu1c()
{
  {
    init_simple_test("Vp_F_BFu1c");
    static STRUCT_IF_C Vp_F_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 1, 1, "Vp_F_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu1c, Vp_F_BFu1c)
//============================================================================


struct  Vp_F_BFu1i  {
  void *v1;
  float v2;
  unsigned int v3:1;
};
//SIG(1 Vp_F_BFu1i) C1{ Fp Fi Fi:1}



static void Test_Vp_F_BFu1i()
{
  {
    init_simple_test("Vp_F_BFu1i");
    static STRUCT_IF_C Vp_F_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 1, 1, "Vp_F_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu1i, Vp_F_BFu1i)
//============================================================================


struct  Vp_F_BFu1ll  {
  void *v1;
  float v2;
  __tsu64 v3:1;
};
//SIG(1 Vp_F_BFu1ll) C1{ Fp Fi FL:1}



static void Test_Vp_F_BFu1ll()
{
  {
    init_simple_test("Vp_F_BFu1ll");
    static STRUCT_IF_C Vp_F_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 1, 1, "Vp_F_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu1ll, Vp_F_BFu1ll)
//============================================================================


struct  Vp_F_BFu1s  {
  void *v1;
  float v2;
  unsigned short v3:1;
};
//SIG(1 Vp_F_BFu1s) C1{ Fp Fi Fs:1}



static void Test_Vp_F_BFu1s()
{
  {
    init_simple_test("Vp_F_BFu1s");
    static STRUCT_IF_C Vp_F_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 1, 1, "Vp_F_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu1s, Vp_F_BFu1s)
//============================================================================


struct  Vp_F_BFu31i  {
  void *v1;
  float v2;
  unsigned int v3:31;
};
//SIG(1 Vp_F_BFu31i) C1{ Fp Fi Fi:31}



static void Test_Vp_F_BFu31i()
{
  {
    init_simple_test("Vp_F_BFu31i");
    static STRUCT_IF_C Vp_F_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_F_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_F_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu31i, Vp_F_BFu31i)
//============================================================================


struct  Vp_F_BFu31ll  {
  void *v1;
  float v2;
  __tsu64 v3:31;
};
//SIG(1 Vp_F_BFu31ll) C1{ Fp Fi FL:31}



static void Test_Vp_F_BFu31ll()
{
  {
    init_simple_test("Vp_F_BFu31ll");
    static STRUCT_IF_C Vp_F_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_F_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_F_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu31ll, Vp_F_BFu31ll)
//============================================================================


struct  Vp_F_BFu32i  {
  void *v1;
  float v2;
  unsigned int v3:32;
};
//SIG(1 Vp_F_BFu32i) C1{ Fp Fi Fi:32}



static void Test_Vp_F_BFu32i()
{
  {
    init_simple_test("Vp_F_BFu32i");
    static STRUCT_IF_C Vp_F_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_F_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_F_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu32i, Vp_F_BFu32i)
//============================================================================


struct  Vp_F_BFu32ll  {
  void *v1;
  float v2;
  __tsu64 v3:32;
};
//SIG(1 Vp_F_BFu32ll) C1{ Fp Fi FL:32}



static void Test_Vp_F_BFu32ll()
{
  {
    init_simple_test("Vp_F_BFu32ll");
    static STRUCT_IF_C Vp_F_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_F_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_F_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu32ll, Vp_F_BFu32ll)
//============================================================================


struct  Vp_F_BFu33  {
  void *v1;
  float v2;
  __tsu64 v3:33;
};
//SIG(1 Vp_F_BFu33) C1{ Fp Fi FL:33}



static void Test_Vp_F_BFu33()
{
  {
    init_simple_test("Vp_F_BFu33");
    static STRUCT_IF_C Vp_F_BFu33 lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_F_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 33, 1, "Vp_F_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 33, hide_ull(1LL<<32), "Vp_F_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu33, Vp_F_BFu33)
//============================================================================


struct  Vp_F_BFu7c  {
  void *v1;
  float v2;
  unsigned char v3:7;
};
//SIG(1 Vp_F_BFu7c) C1{ Fp Fi Fc:7}



static void Test_Vp_F_BFu7c()
{
  {
    init_simple_test("Vp_F_BFu7c");
    static STRUCT_IF_C Vp_F_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_F_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_F_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu7c, Vp_F_BFu7c)
//============================================================================


struct  Vp_F_BFu7i  {
  void *v1;
  float v2;
  unsigned int v3:7;
};
//SIG(1 Vp_F_BFu7i) C1{ Fp Fi Fi:7}



static void Test_Vp_F_BFu7i()
{
  {
    init_simple_test("Vp_F_BFu7i");
    static STRUCT_IF_C Vp_F_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_F_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_F_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu7i, Vp_F_BFu7i)
//============================================================================


struct  Vp_F_BFu7ll  {
  void *v1;
  float v2;
  __tsu64 v3:7;
};
//SIG(1 Vp_F_BFu7ll) C1{ Fp Fi FL:7}



static void Test_Vp_F_BFu7ll()
{
  {
    init_simple_test("Vp_F_BFu7ll");
    static STRUCT_IF_C Vp_F_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_F_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_F_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu7ll, Vp_F_BFu7ll)
//============================================================================


struct  Vp_F_BFu7s  {
  void *v1;
  float v2;
  unsigned short v3:7;
};
//SIG(1 Vp_F_BFu7s) C1{ Fp Fi Fs:7}



static void Test_Vp_F_BFu7s()
{
  {
    init_simple_test("Vp_F_BFu7s");
    static STRUCT_IF_C Vp_F_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_F_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_F_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu7s, Vp_F_BFu7s)
//============================================================================


struct  Vp_F_BFu8c  {
  void *v1;
  float v2;
  unsigned char v3:8;
};
//SIG(1 Vp_F_BFu8c) C1{ Fp Fi Fc:8}



static void Test_Vp_F_BFu8c()
{
  {
    init_simple_test("Vp_F_BFu8c");
    static STRUCT_IF_C Vp_F_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_F_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_F_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu8c, Vp_F_BFu8c)
//============================================================================


struct  Vp_F_BFu8i  {
  void *v1;
  float v2;
  unsigned int v3:8;
};
//SIG(1 Vp_F_BFu8i) C1{ Fp Fi Fi:8}



static void Test_Vp_F_BFu8i()
{
  {
    init_simple_test("Vp_F_BFu8i");
    static STRUCT_IF_C Vp_F_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_F_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_F_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu8i, Vp_F_BFu8i)
//============================================================================


struct  Vp_F_BFu8ll  {
  void *v1;
  float v2;
  __tsu64 v3:8;
};
//SIG(1 Vp_F_BFu8ll) C1{ Fp Fi FL:8}



static void Test_Vp_F_BFu8ll()
{
  {
    init_simple_test("Vp_F_BFu8ll");
    static STRUCT_IF_C Vp_F_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_F_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_F_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu8ll, Vp_F_BFu8ll)
//============================================================================


struct  Vp_F_BFu8s  {
  void *v1;
  float v2;
  unsigned short v3:8;
};
//SIG(1 Vp_F_BFu8s) C1{ Fp Fi Fs:8}



static void Test_Vp_F_BFu8s()
{
  {
    init_simple_test("Vp_F_BFu8s");
    static STRUCT_IF_C Vp_F_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_F_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_F_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu8s, Vp_F_BFu8s)
//============================================================================


struct  Vp_F_BFu9i  {
  void *v1;
  float v2;
  unsigned int v3:9;
};
//SIG(1 Vp_F_BFu9i) C1{ Fp Fi Fi:9}



static void Test_Vp_F_BFu9i()
{
  {
    init_simple_test("Vp_F_BFu9i");
    static STRUCT_IF_C Vp_F_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, 1, "Vp_F_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, hide_ull(1LL<<8), "Vp_F_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu9i, Vp_F_BFu9i)
//============================================================================


struct  Vp_F_BFu9ll  {
  void *v1;
  float v2;
  __tsu64 v3:9;
};
//SIG(1 Vp_F_BFu9ll) C1{ Fp Fi FL:9}



static void Test_Vp_F_BFu9ll()
{
  {
    init_simple_test("Vp_F_BFu9ll");
    static STRUCT_IF_C Vp_F_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, 1, "Vp_F_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, hide_ull(1LL<<8), "Vp_F_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu9ll, Vp_F_BFu9ll)
//============================================================================


struct  Vp_F_BFu9s  {
  void *v1;
  float v2;
  unsigned short v3:9;
};
//SIG(1 Vp_F_BFu9s) C1{ Fp Fi Fs:9}



static void Test_Vp_F_BFu9s()
{
  {
    init_simple_test("Vp_F_BFu9s");
    static STRUCT_IF_C Vp_F_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_F_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, 1, "Vp_F_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, hide_ull(1LL<<8), "Vp_F_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_BFu9s, Vp_F_BFu9s)
//============================================================================


struct  Vp_F_C  {
  void *v1;
  float v2;
  char v3;
};
//SIG(1 Vp_F_C) C1{ Fp Fi Fc}



static void Test_Vp_F_C()
{
  {
    init_simple_test("Vp_F_C");
    STRUCT_IF_C Vp_F_C lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_C)");
    check_field_offset(lv, v1, 0, "Vp_F_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_C.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_F_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_C, Vp_F_C)
//============================================================================


struct  Vp_F_D  {
  void *v1;
  float v2;
  double v3;
};
//SIG(1 Vp_F_D) C1{ Fp Fi FL}



static void Test_Vp_F_D()
{
  {
    init_simple_test("Vp_F_D");
    STRUCT_IF_C Vp_F_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_F_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_D)");
    check_field_offset(lv, v1, 0, "Vp_F_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_D.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_F_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_D, Vp_F_D)
//============================================================================


struct  Vp_F_F  {
  void *v1;
  float v2;
  float v3;
};
//SIG(1 Vp_F_F) C1{ Fp Fi[2]}



static void Test_Vp_F_F()
{
  {
    init_simple_test("Vp_F_F");
    STRUCT_IF_C Vp_F_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_F)");
    check_field_offset(lv, v1, 0, "Vp_F_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_F.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_F_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_F, Vp_F_F)
//============================================================================


struct  Vp_F_I  {
  void *v1;
  float v2;
  int v3;
};
//SIG(1 Vp_F_I) C1{ Fp Fi[2]}



static void Test_Vp_F_I()
{
  {
    init_simple_test("Vp_F_I");
    STRUCT_IF_C Vp_F_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_I)");
    check_field_offset(lv, v1, 0, "Vp_F_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_I.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_F_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_I, Vp_F_I)
//============================================================================


struct  Vp_F_Ip  {
  void *v1;
  float v2;
  int *v3;
};
//SIG(1 Vp_F_Ip) C1{ Fp Fi Fp}



static void Test_Vp_F_Ip()
{
  {
    init_simple_test("Vp_F_Ip");
    STRUCT_IF_C Vp_F_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_F_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_Ip)");
    check_field_offset(lv, v1, 0, "Vp_F_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_F_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_Ip, Vp_F_Ip)
//============================================================================


struct  Vp_F_L  {
  void *v1;
  float v2;
  __tsi64 v3;
};
//SIG(1 Vp_F_L) C1{ Fp Fi FL}



static void Test_Vp_F_L()
{
  {
    init_simple_test("Vp_F_L");
    STRUCT_IF_C Vp_F_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_F_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_L)");
    check_field_offset(lv, v1, 0, "Vp_F_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_L.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_F_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_L, Vp_F_L)
//============================================================================


struct  Vp_F_S  {
  void *v1;
  float v2;
  short v3;
};
//SIG(1 Vp_F_S) C1{ Fp Fi Fs}



static void Test_Vp_F_S()
{
  {
    init_simple_test("Vp_F_S");
    STRUCT_IF_C Vp_F_S lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_S)");
    check_field_offset(lv, v1, 0, "Vp_F_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_S.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_F_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_S, Vp_F_S)
//============================================================================


struct  Vp_F_Uc  {
  void *v1;
  float v2;
  unsigned char v3;
};
//SIG(1 Vp_F_Uc) C1{ Fp Fi Fc}



static void Test_Vp_F_Uc()
{
  {
    init_simple_test("Vp_F_Uc");
    STRUCT_IF_C Vp_F_Uc lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_Uc)");
    check_field_offset(lv, v1, 0, "Vp_F_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_F_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_Uc, Vp_F_Uc)
//============================================================================


struct  Vp_F_Ui  {
  void *v1;
  float v2;
  unsigned int v3;
};
//SIG(1 Vp_F_Ui) C1{ Fp Fi[2]}



static void Test_Vp_F_Ui()
{
  {
    init_simple_test("Vp_F_Ui");
    STRUCT_IF_C Vp_F_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_Ui)");
    check_field_offset(lv, v1, 0, "Vp_F_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_F_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_Ui, Vp_F_Ui)
//============================================================================


struct  Vp_F_Ul  {
  void *v1;
  float v2;
  __tsu64 v3;
};
//SIG(1 Vp_F_Ul) C1{ Fp Fi FL}



static void Test_Vp_F_Ul()
{
  {
    init_simple_test("Vp_F_Ul");
    STRUCT_IF_C Vp_F_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_F_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_Ul)");
    check_field_offset(lv, v1, 0, "Vp_F_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_F_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_Ul, Vp_F_Ul)
//============================================================================


struct  Vp_F_Us  {
  void *v1;
  float v2;
  unsigned short v3;
};
//SIG(1 Vp_F_Us) C1{ Fp Fi Fs}



static void Test_Vp_F_Us()
{
  {
    init_simple_test("Vp_F_Us");
    STRUCT_IF_C Vp_F_Us lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_F_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_Us)");
    check_field_offset(lv, v1, 0, "Vp_F_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_Us.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_F_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_Us, Vp_F_Us)
//============================================================================


struct  Vp_F_Vp  {
  void *v1;
  float v2;
  void *v3;
};
//SIG(1 Vp_F_Vp) C1{ Fp Fi Fp}



static void Test_Vp_F_Vp()
{
  {
    init_simple_test("Vp_F_Vp");
    STRUCT_IF_C Vp_F_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_F_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_F_Vp)");
    check_field_offset(lv, v1, 0, "Vp_F_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_F_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_F_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_F_Vp, Vp_F_Vp)
//============================================================================


struct  Vp_I  {
  void *v1;
  int v2;
};
//SIG(1 Vp_I) C1{ Fp Fi}



static void Test_Vp_I()
{
  {
    init_simple_test("Vp_I");
    STRUCT_IF_C Vp_I lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I)");
    check_field_offset(lv, v1, 0, "Vp_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I, Vp_I)
//============================================================================


struct  Vp_I_BFu15i  {
  void *v1;
  int v2;
  unsigned int v3:15;
};
//SIG(1 Vp_I_BFu15i) C1{ Fp Fi Fi:15}



static void Test_Vp_I_BFu15i()
{
  {
    init_simple_test("Vp_I_BFu15i");
    static STRUCT_IF_C Vp_I_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, 1, "Vp_I_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, hide_ull(1LL<<14), "Vp_I_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu15i, Vp_I_BFu15i)
//============================================================================


struct  Vp_I_BFu15ll  {
  void *v1;
  int v2;
  __tsu64 v3:15;
};
//SIG(1 Vp_I_BFu15ll) C1{ Fp Fi FL:15}



static void Test_Vp_I_BFu15ll()
{
  {
    init_simple_test("Vp_I_BFu15ll");
    static STRUCT_IF_C Vp_I_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, 1, "Vp_I_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, hide_ull(1LL<<14), "Vp_I_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu15ll, Vp_I_BFu15ll)
//============================================================================


struct  Vp_I_BFu15s  {
  void *v1;
  int v2;
  unsigned short v3:15;
};
//SIG(1 Vp_I_BFu15s) C1{ Fp Fi Fs:15}



static void Test_Vp_I_BFu15s()
{
  {
    init_simple_test("Vp_I_BFu15s");
    static STRUCT_IF_C Vp_I_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, 1, "Vp_I_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, hide_ull(1LL<<14), "Vp_I_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu15s, Vp_I_BFu15s)
//============================================================================


struct  Vp_I_BFu16i  {
  void *v1;
  int v2;
  unsigned int v3:16;
};
//SIG(1 Vp_I_BFu16i) C1{ Fp Fi Fi:16}



static void Test_Vp_I_BFu16i()
{
  {
    init_simple_test("Vp_I_BFu16i");
    static STRUCT_IF_C Vp_I_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, 1, "Vp_I_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, hide_ull(1LL<<15), "Vp_I_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu16i, Vp_I_BFu16i)
//============================================================================


struct  Vp_I_BFu16ll  {
  void *v1;
  int v2;
  __tsu64 v3:16;
};
//SIG(1 Vp_I_BFu16ll) C1{ Fp Fi FL:16}



static void Test_Vp_I_BFu16ll()
{
  {
    init_simple_test("Vp_I_BFu16ll");
    static STRUCT_IF_C Vp_I_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, 1, "Vp_I_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, hide_ull(1LL<<15), "Vp_I_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu16ll, Vp_I_BFu16ll)
//============================================================================


struct  Vp_I_BFu16s  {
  void *v1;
  int v2;
  unsigned short v3:16;
};
//SIG(1 Vp_I_BFu16s) C1{ Fp Fi Fs:16}



static void Test_Vp_I_BFu16s()
{
  {
    init_simple_test("Vp_I_BFu16s");
    static STRUCT_IF_C Vp_I_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, 1, "Vp_I_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, hide_ull(1LL<<15), "Vp_I_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu16s, Vp_I_BFu16s)
//============================================================================


struct  Vp_I_BFu17i  {
  void *v1;
  int v2;
  unsigned int v3:17;
};
//SIG(1 Vp_I_BFu17i) C1{ Fp Fi Fi:17}



static void Test_Vp_I_BFu17i()
{
  {
    init_simple_test("Vp_I_BFu17i");
    static STRUCT_IF_C Vp_I_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, 1, "Vp_I_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, hide_ull(1LL<<16), "Vp_I_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu17i, Vp_I_BFu17i)
//============================================================================


struct  Vp_I_BFu17ll  {
  void *v1;
  int v2;
  __tsu64 v3:17;
};
//SIG(1 Vp_I_BFu17ll) C1{ Fp Fi FL:17}



static void Test_Vp_I_BFu17ll()
{
  {
    init_simple_test("Vp_I_BFu17ll");
    static STRUCT_IF_C Vp_I_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, 1, "Vp_I_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, hide_ull(1LL<<16), "Vp_I_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu17ll, Vp_I_BFu17ll)
//============================================================================


struct  Vp_I_BFu1c  {
  void *v1;
  int v2;
  unsigned char v3:1;
};
//SIG(1 Vp_I_BFu1c) C1{ Fp Fi Fc:1}



static void Test_Vp_I_BFu1c()
{
  {
    init_simple_test("Vp_I_BFu1c");
    static STRUCT_IF_C Vp_I_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 1, 1, "Vp_I_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu1c, Vp_I_BFu1c)
//============================================================================


struct  Vp_I_BFu1i  {
  void *v1;
  int v2;
  unsigned int v3:1;
};
//SIG(1 Vp_I_BFu1i) C1{ Fp Fi Fi:1}



static void Test_Vp_I_BFu1i()
{
  {
    init_simple_test("Vp_I_BFu1i");
    static STRUCT_IF_C Vp_I_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 1, 1, "Vp_I_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu1i, Vp_I_BFu1i)
//============================================================================


struct  Vp_I_BFu1ll  {
  void *v1;
  int v2;
  __tsu64 v3:1;
};
//SIG(1 Vp_I_BFu1ll) C1{ Fp Fi FL:1}



static void Test_Vp_I_BFu1ll()
{
  {
    init_simple_test("Vp_I_BFu1ll");
    static STRUCT_IF_C Vp_I_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 1, 1, "Vp_I_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu1ll, Vp_I_BFu1ll)
//============================================================================


struct  Vp_I_BFu1s  {
  void *v1;
  int v2;
  unsigned short v3:1;
};
//SIG(1 Vp_I_BFu1s) C1{ Fp Fi Fs:1}



static void Test_Vp_I_BFu1s()
{
  {
    init_simple_test("Vp_I_BFu1s");
    static STRUCT_IF_C Vp_I_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 1, 1, "Vp_I_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu1s, Vp_I_BFu1s)
//============================================================================


struct  Vp_I_BFu31i  {
  void *v1;
  int v2;
  unsigned int v3:31;
};
//SIG(1 Vp_I_BFu31i) C1{ Fp Fi Fi:31}



static void Test_Vp_I_BFu31i()
{
  {
    init_simple_test("Vp_I_BFu31i");
    static STRUCT_IF_C Vp_I_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_I_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_I_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu31i, Vp_I_BFu31i)
//============================================================================


struct  Vp_I_BFu31ll  {
  void *v1;
  int v2;
  __tsu64 v3:31;
};
//SIG(1 Vp_I_BFu31ll) C1{ Fp Fi FL:31}



static void Test_Vp_I_BFu31ll()
{
  {
    init_simple_test("Vp_I_BFu31ll");
    static STRUCT_IF_C Vp_I_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_I_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_I_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu31ll, Vp_I_BFu31ll)
//============================================================================


struct  Vp_I_BFu32i  {
  void *v1;
  int v2;
  unsigned int v3:32;
};
//SIG(1 Vp_I_BFu32i) C1{ Fp Fi Fi:32}



static void Test_Vp_I_BFu32i()
{
  {
    init_simple_test("Vp_I_BFu32i");
    static STRUCT_IF_C Vp_I_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_I_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_I_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu32i, Vp_I_BFu32i)
//============================================================================


struct  Vp_I_BFu32ll  {
  void *v1;
  int v2;
  __tsu64 v3:32;
};
//SIG(1 Vp_I_BFu32ll) C1{ Fp Fi FL:32}



static void Test_Vp_I_BFu32ll()
{
  {
    init_simple_test("Vp_I_BFu32ll");
    static STRUCT_IF_C Vp_I_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_I_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_I_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu32ll, Vp_I_BFu32ll)
//============================================================================


struct  Vp_I_BFu33  {
  void *v1;
  int v2;
  __tsu64 v3:33;
};
//SIG(1 Vp_I_BFu33) C1{ Fp Fi FL:33}



static void Test_Vp_I_BFu33()
{
  {
    init_simple_test("Vp_I_BFu33");
    static STRUCT_IF_C Vp_I_BFu33 lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_I_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 33, 1, "Vp_I_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 33, hide_ull(1LL<<32), "Vp_I_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu33, Vp_I_BFu33)
//============================================================================


struct  Vp_I_BFu7c  {
  void *v1;
  int v2;
  unsigned char v3:7;
};
//SIG(1 Vp_I_BFu7c) C1{ Fp Fi Fc:7}



static void Test_Vp_I_BFu7c()
{
  {
    init_simple_test("Vp_I_BFu7c");
    static STRUCT_IF_C Vp_I_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_I_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_I_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu7c, Vp_I_BFu7c)
//============================================================================


struct  Vp_I_BFu7i  {
  void *v1;
  int v2;
  unsigned int v3:7;
};
//SIG(1 Vp_I_BFu7i) C1{ Fp Fi Fi:7}



static void Test_Vp_I_BFu7i()
{
  {
    init_simple_test("Vp_I_BFu7i");
    static STRUCT_IF_C Vp_I_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_I_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_I_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu7i, Vp_I_BFu7i)
//============================================================================


struct  Vp_I_BFu7ll  {
  void *v1;
  int v2;
  __tsu64 v3:7;
};
//SIG(1 Vp_I_BFu7ll) C1{ Fp Fi FL:7}



static void Test_Vp_I_BFu7ll()
{
  {
    init_simple_test("Vp_I_BFu7ll");
    static STRUCT_IF_C Vp_I_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_I_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_I_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu7ll, Vp_I_BFu7ll)
//============================================================================


struct  Vp_I_BFu7s  {
  void *v1;
  int v2;
  unsigned short v3:7;
};
//SIG(1 Vp_I_BFu7s) C1{ Fp Fi Fs:7}



static void Test_Vp_I_BFu7s()
{
  {
    init_simple_test("Vp_I_BFu7s");
    static STRUCT_IF_C Vp_I_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_I_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_I_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu7s, Vp_I_BFu7s)
//============================================================================


struct  Vp_I_BFu8c  {
  void *v1;
  int v2;
  unsigned char v3:8;
};
//SIG(1 Vp_I_BFu8c) C1{ Fp Fi Fc:8}



static void Test_Vp_I_BFu8c()
{
  {
    init_simple_test("Vp_I_BFu8c");
    static STRUCT_IF_C Vp_I_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_I_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_I_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu8c, Vp_I_BFu8c)
//============================================================================


struct  Vp_I_BFu8i  {
  void *v1;
  int v2;
  unsigned int v3:8;
};
//SIG(1 Vp_I_BFu8i) C1{ Fp Fi Fi:8}



static void Test_Vp_I_BFu8i()
{
  {
    init_simple_test("Vp_I_BFu8i");
    static STRUCT_IF_C Vp_I_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_I_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_I_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu8i, Vp_I_BFu8i)
//============================================================================


struct  Vp_I_BFu8ll  {
  void *v1;
  int v2;
  __tsu64 v3:8;
};
//SIG(1 Vp_I_BFu8ll) C1{ Fp Fi FL:8}



static void Test_Vp_I_BFu8ll()
{
  {
    init_simple_test("Vp_I_BFu8ll");
    static STRUCT_IF_C Vp_I_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_I_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_I_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu8ll, Vp_I_BFu8ll)
//============================================================================


struct  Vp_I_BFu8s  {
  void *v1;
  int v2;
  unsigned short v3:8;
};
//SIG(1 Vp_I_BFu8s) C1{ Fp Fi Fs:8}



static void Test_Vp_I_BFu8s()
{
  {
    init_simple_test("Vp_I_BFu8s");
    static STRUCT_IF_C Vp_I_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_I_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_I_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu8s, Vp_I_BFu8s)
//============================================================================


struct  Vp_I_BFu9i  {
  void *v1;
  int v2;
  unsigned int v3:9;
};
//SIG(1 Vp_I_BFu9i) C1{ Fp Fi Fi:9}



static void Test_Vp_I_BFu9i()
{
  {
    init_simple_test("Vp_I_BFu9i");
    static STRUCT_IF_C Vp_I_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, 1, "Vp_I_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, hide_ull(1LL<<8), "Vp_I_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu9i, Vp_I_BFu9i)
//============================================================================


struct  Vp_I_BFu9ll  {
  void *v1;
  int v2;
  __tsu64 v3:9;
};
//SIG(1 Vp_I_BFu9ll) C1{ Fp Fi FL:9}



static void Test_Vp_I_BFu9ll()
{
  {
    init_simple_test("Vp_I_BFu9ll");
    static STRUCT_IF_C Vp_I_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, 1, "Vp_I_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, hide_ull(1LL<<8), "Vp_I_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu9ll, Vp_I_BFu9ll)
//============================================================================


struct  Vp_I_BFu9s  {
  void *v1;
  int v2;
  unsigned short v3:9;
};
//SIG(1 Vp_I_BFu9s) C1{ Fp Fi Fs:9}



static void Test_Vp_I_BFu9s()
{
  {
    init_simple_test("Vp_I_BFu9s");
    static STRUCT_IF_C Vp_I_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_I_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, 1, "Vp_I_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, hide_ull(1LL<<8), "Vp_I_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_BFu9s, Vp_I_BFu9s)
//============================================================================


struct  Vp_I_C  {
  void *v1;
  int v2;
  char v3;
};
//SIG(1 Vp_I_C) C1{ Fp Fi Fc}



static void Test_Vp_I_C()
{
  {
    init_simple_test("Vp_I_C");
    STRUCT_IF_C Vp_I_C lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_C)");
    check_field_offset(lv, v1, 0, "Vp_I_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_C.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_I_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_C, Vp_I_C)
//============================================================================


struct  Vp_I_D  {
  void *v1;
  int v2;
  double v3;
};
//SIG(1 Vp_I_D) C1{ Fp Fi FL}



static void Test_Vp_I_D()
{
  {
    init_simple_test("Vp_I_D");
    STRUCT_IF_C Vp_I_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_I_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_D)");
    check_field_offset(lv, v1, 0, "Vp_I_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_D.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_I_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_D, Vp_I_D)
//============================================================================


struct  Vp_I_F  {
  void *v1;
  int v2;
  float v3;
};
//SIG(1 Vp_I_F) C1{ Fp Fi[2]}



static void Test_Vp_I_F()
{
  {
    init_simple_test("Vp_I_F");
    STRUCT_IF_C Vp_I_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_F)");
    check_field_offset(lv, v1, 0, "Vp_I_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_F.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_I_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_F, Vp_I_F)
//============================================================================


struct  Vp_I_I  {
  void *v1;
  int v2;
  int v3;
};
//SIG(1 Vp_I_I) C1{ Fp Fi[2]}



static void Test_Vp_I_I()
{
  {
    init_simple_test("Vp_I_I");
    STRUCT_IF_C Vp_I_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_I)");
    check_field_offset(lv, v1, 0, "Vp_I_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_I.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_I_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_I, Vp_I_I)
//============================================================================


struct  Vp_I_Ip  {
  void *v1;
  int v2;
  int *v3;
};
//SIG(1 Vp_I_Ip) C1{ Fp Fi Fp}



static void Test_Vp_I_Ip()
{
  {
    init_simple_test("Vp_I_Ip");
    STRUCT_IF_C Vp_I_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_I_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_Ip)");
    check_field_offset(lv, v1, 0, "Vp_I_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_I_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_Ip, Vp_I_Ip)
//============================================================================


struct  Vp_I_L  {
  void *v1;
  int v2;
  __tsi64 v3;
};
//SIG(1 Vp_I_L) C1{ Fp Fi FL}



static void Test_Vp_I_L()
{
  {
    init_simple_test("Vp_I_L");
    STRUCT_IF_C Vp_I_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_I_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_L)");
    check_field_offset(lv, v1, 0, "Vp_I_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_L.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_I_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_L, Vp_I_L)
//============================================================================


struct  Vp_I_S  {
  void *v1;
  int v2;
  short v3;
};
//SIG(1 Vp_I_S) C1{ Fp Fi Fs}



static void Test_Vp_I_S()
{
  {
    init_simple_test("Vp_I_S");
    STRUCT_IF_C Vp_I_S lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_S)");
    check_field_offset(lv, v1, 0, "Vp_I_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_S.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_I_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_S, Vp_I_S)
//============================================================================


struct  Vp_I_Uc  {
  void *v1;
  int v2;
  unsigned char v3;
};
//SIG(1 Vp_I_Uc) C1{ Fp Fi Fc}



static void Test_Vp_I_Uc()
{
  {
    init_simple_test("Vp_I_Uc");
    STRUCT_IF_C Vp_I_Uc lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_Uc)");
    check_field_offset(lv, v1, 0, "Vp_I_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_I_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_Uc, Vp_I_Uc)
//============================================================================


struct  Vp_I_Ui  {
  void *v1;
  int v2;
  unsigned int v3;
};
//SIG(1 Vp_I_Ui) C1{ Fp Fi[2]}



static void Test_Vp_I_Ui()
{
  {
    init_simple_test("Vp_I_Ui");
    STRUCT_IF_C Vp_I_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_Ui)");
    check_field_offset(lv, v1, 0, "Vp_I_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_I_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_Ui, Vp_I_Ui)
//============================================================================


struct  Vp_I_Ul  {
  void *v1;
  int v2;
  __tsu64 v3;
};
//SIG(1 Vp_I_Ul) C1{ Fp Fi FL}



static void Test_Vp_I_Ul()
{
  {
    init_simple_test("Vp_I_Ul");
    STRUCT_IF_C Vp_I_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_I_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_Ul)");
    check_field_offset(lv, v1, 0, "Vp_I_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_I_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_Ul, Vp_I_Ul)
//============================================================================


struct  Vp_I_Us  {
  void *v1;
  int v2;
  unsigned short v3;
};
//SIG(1 Vp_I_Us) C1{ Fp Fi Fs}



static void Test_Vp_I_Us()
{
  {
    init_simple_test("Vp_I_Us");
    STRUCT_IF_C Vp_I_Us lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_I_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_Us)");
    check_field_offset(lv, v1, 0, "Vp_I_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_Us.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_I_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_Us, Vp_I_Us)
//============================================================================


struct  Vp_I_Vp  {
  void *v1;
  int v2;
  void *v3;
};
//SIG(1 Vp_I_Vp) C1{ Fp Fi Fp}



static void Test_Vp_I_Vp()
{
  {
    init_simple_test("Vp_I_Vp");
    STRUCT_IF_C Vp_I_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_I_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_I_Vp)");
    check_field_offset(lv, v1, 0, "Vp_I_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_I_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_I_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_I_Vp, Vp_I_Vp)
//============================================================================


struct  Vp_Ip  {
  void *v1;
  int *v2;
};
//SIG(1 Vp_Ip) C1{ Fp[2]}



static void Test_Vp_Ip()
{
  {
    init_simple_test("Vp_Ip");
    STRUCT_IF_C Vp_Ip lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip)");
    check_field_offset(lv, v1, 0, "Vp_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip, Vp_Ip)
//============================================================================


struct  Vp_Ip_BFu15i  {
  void *v1;
  int *v2;
  unsigned int v3:15;
};
//SIG(1 Vp_Ip_BFu15i) C1{ Fp[2] Fi:15}



static void Test_Vp_Ip_BFu15i()
{
  {
    init_simple_test("Vp_Ip_BFu15i");
    static STRUCT_IF_C Vp_Ip_BFu15i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 15, 1, "Vp_Ip_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 15, hide_ull(1LL<<14), "Vp_Ip_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu15i, Vp_Ip_BFu15i)
//============================================================================


struct  Vp_Ip_BFu15ll  {
  void *v1;
  int *v2;
  __tsu64 v3:15;
};
//SIG(1 Vp_Ip_BFu15ll) C1{ Fp[2] FL:15}



static void Test_Vp_Ip_BFu15ll()
{
  {
    init_simple_test("Vp_Ip_BFu15ll");
    static STRUCT_IF_C Vp_Ip_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 15, 1, "Vp_Ip_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 15, hide_ull(1LL<<14), "Vp_Ip_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu15ll, Vp_Ip_BFu15ll)
//============================================================================


struct  Vp_Ip_BFu15s  {
  void *v1;
  int *v2;
  unsigned short v3:15;
};
//SIG(1 Vp_Ip_BFu15s) C1{ Fp[2] Fs:15}



static void Test_Vp_Ip_BFu15s()
{
  {
    init_simple_test("Vp_Ip_BFu15s");
    static STRUCT_IF_C Vp_Ip_BFu15s lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 15, 1, "Vp_Ip_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 15, hide_ull(1LL<<14), "Vp_Ip_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu15s, Vp_Ip_BFu15s)
//============================================================================


struct  Vp_Ip_BFu16i  {
  void *v1;
  int *v2;
  unsigned int v3:16;
};
//SIG(1 Vp_Ip_BFu16i) C1{ Fp[2] Fi:16}



static void Test_Vp_Ip_BFu16i()
{
  {
    init_simple_test("Vp_Ip_BFu16i");
    static STRUCT_IF_C Vp_Ip_BFu16i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 16, 1, "Vp_Ip_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 16, hide_ull(1LL<<15), "Vp_Ip_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu16i, Vp_Ip_BFu16i)
//============================================================================


struct  Vp_Ip_BFu16ll  {
  void *v1;
  int *v2;
  __tsu64 v3:16;
};
//SIG(1 Vp_Ip_BFu16ll) C1{ Fp[2] FL:16}



static void Test_Vp_Ip_BFu16ll()
{
  {
    init_simple_test("Vp_Ip_BFu16ll");
    static STRUCT_IF_C Vp_Ip_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 16, 1, "Vp_Ip_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 16, hide_ull(1LL<<15), "Vp_Ip_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu16ll, Vp_Ip_BFu16ll)
//============================================================================


struct  Vp_Ip_BFu16s  {
  void *v1;
  int *v2;
  unsigned short v3:16;
};
//SIG(1 Vp_Ip_BFu16s) C1{ Fp[2] Fs:16}



static void Test_Vp_Ip_BFu16s()
{
  {
    init_simple_test("Vp_Ip_BFu16s");
    static STRUCT_IF_C Vp_Ip_BFu16s lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 16, 1, "Vp_Ip_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 16, hide_ull(1LL<<15), "Vp_Ip_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu16s, Vp_Ip_BFu16s)
//============================================================================


struct  Vp_Ip_BFu17i  {
  void *v1;
  int *v2;
  unsigned int v3:17;
};
//SIG(1 Vp_Ip_BFu17i) C1{ Fp[2] Fi:17}



static void Test_Vp_Ip_BFu17i()
{
  {
    init_simple_test("Vp_Ip_BFu17i");
    static STRUCT_IF_C Vp_Ip_BFu17i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 17, 1, "Vp_Ip_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 17, hide_ull(1LL<<16), "Vp_Ip_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu17i, Vp_Ip_BFu17i)
//============================================================================


struct  Vp_Ip_BFu17ll  {
  void *v1;
  int *v2;
  __tsu64 v3:17;
};
//SIG(1 Vp_Ip_BFu17ll) C1{ Fp[2] FL:17}



static void Test_Vp_Ip_BFu17ll()
{
  {
    init_simple_test("Vp_Ip_BFu17ll");
    static STRUCT_IF_C Vp_Ip_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 17, 1, "Vp_Ip_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 17, hide_ull(1LL<<16), "Vp_Ip_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu17ll, Vp_Ip_BFu17ll)
//============================================================================


struct  Vp_Ip_BFu1c  {
  void *v1;
  int *v2;
  unsigned char v3:1;
};
//SIG(1 Vp_Ip_BFu1c) C1{ Fp[2] Fc:1}



static void Test_Vp_Ip_BFu1c()
{
  {
    init_simple_test("Vp_Ip_BFu1c");
    static STRUCT_IF_C Vp_Ip_BFu1c lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 1, 1, "Vp_Ip_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu1c, Vp_Ip_BFu1c)
//============================================================================


struct  Vp_Ip_BFu1i  {
  void *v1;
  int *v2;
  unsigned int v3:1;
};
//SIG(1 Vp_Ip_BFu1i) C1{ Fp[2] Fi:1}



static void Test_Vp_Ip_BFu1i()
{
  {
    init_simple_test("Vp_Ip_BFu1i");
    static STRUCT_IF_C Vp_Ip_BFu1i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 1, 1, "Vp_Ip_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu1i, Vp_Ip_BFu1i)
//============================================================================


struct  Vp_Ip_BFu1ll  {
  void *v1;
  int *v2;
  __tsu64 v3:1;
};
//SIG(1 Vp_Ip_BFu1ll) C1{ Fp[2] FL:1}



static void Test_Vp_Ip_BFu1ll()
{
  {
    init_simple_test("Vp_Ip_BFu1ll");
    static STRUCT_IF_C Vp_Ip_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 1, 1, "Vp_Ip_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu1ll, Vp_Ip_BFu1ll)
//============================================================================


struct  Vp_Ip_BFu1s  {
  void *v1;
  int *v2;
  unsigned short v3:1;
};
//SIG(1 Vp_Ip_BFu1s) C1{ Fp[2] Fs:1}



static void Test_Vp_Ip_BFu1s()
{
  {
    init_simple_test("Vp_Ip_BFu1s");
    static STRUCT_IF_C Vp_Ip_BFu1s lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 1, 1, "Vp_Ip_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu1s, Vp_Ip_BFu1s)
//============================================================================


struct  Vp_Ip_BFu31i  {
  void *v1;
  int *v2;
  unsigned int v3:31;
};
//SIG(1 Vp_Ip_BFu31i) C1{ Fp[2] Fi:31}



static void Test_Vp_Ip_BFu31i()
{
  {
    init_simple_test("Vp_Ip_BFu31i");
    static STRUCT_IF_C Vp_Ip_BFu31i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 31, 1, "Vp_Ip_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 31, hide_ull(1LL<<30), "Vp_Ip_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu31i, Vp_Ip_BFu31i)
//============================================================================


struct  Vp_Ip_BFu31ll  {
  void *v1;
  int *v2;
  __tsu64 v3:31;
};
//SIG(1 Vp_Ip_BFu31ll) C1{ Fp[2] FL:31}



static void Test_Vp_Ip_BFu31ll()
{
  {
    init_simple_test("Vp_Ip_BFu31ll");
    static STRUCT_IF_C Vp_Ip_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 31, 1, "Vp_Ip_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 31, hide_ull(1LL<<30), "Vp_Ip_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu31ll, Vp_Ip_BFu31ll)
//============================================================================


struct  Vp_Ip_BFu32i  {
  void *v1;
  int *v2;
  unsigned int v3:32;
};
//SIG(1 Vp_Ip_BFu32i) C1{ Fp[2] Fi:32}



static void Test_Vp_Ip_BFu32i()
{
  {
    init_simple_test("Vp_Ip_BFu32i");
    static STRUCT_IF_C Vp_Ip_BFu32i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 32, 1, "Vp_Ip_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 32, hide_ull(1LL<<31), "Vp_Ip_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu32i, Vp_Ip_BFu32i)
//============================================================================


struct  Vp_Ip_BFu32ll  {
  void *v1;
  int *v2;
  __tsu64 v3:32;
};
//SIG(1 Vp_Ip_BFu32ll) C1{ Fp[2] FL:32}



static void Test_Vp_Ip_BFu32ll()
{
  {
    init_simple_test("Vp_Ip_BFu32ll");
    static STRUCT_IF_C Vp_Ip_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 32, 1, "Vp_Ip_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 32, hide_ull(1LL<<31), "Vp_Ip_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu32ll, Vp_Ip_BFu32ll)
//============================================================================


struct  Vp_Ip_BFu33  {
  void *v1;
  int *v2;
  __tsu64 v3:33;
};
//SIG(1 Vp_Ip_BFu33) C1{ Fp[2] FL:33}



static void Test_Vp_Ip_BFu33()
{
  {
    init_simple_test("Vp_Ip_BFu33");
    static STRUCT_IF_C Vp_Ip_BFu33 lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ip_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 33, 1, "Vp_Ip_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 33, hide_ull(1LL<<32), "Vp_Ip_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu33, Vp_Ip_BFu33)
//============================================================================


struct  Vp_Ip_BFu7c  {
  void *v1;
  int *v2;
  unsigned char v3:7;
};
//SIG(1 Vp_Ip_BFu7c) C1{ Fp[2] Fc:7}



static void Test_Vp_Ip_BFu7c()
{
  {
    init_simple_test("Vp_Ip_BFu7c");
    static STRUCT_IF_C Vp_Ip_BFu7c lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, 1, "Vp_Ip_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, hide_ull(1LL<<6), "Vp_Ip_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu7c, Vp_Ip_BFu7c)
//============================================================================


struct  Vp_Ip_BFu7i  {
  void *v1;
  int *v2;
  unsigned int v3:7;
};
//SIG(1 Vp_Ip_BFu7i) C1{ Fp[2] Fi:7}



static void Test_Vp_Ip_BFu7i()
{
  {
    init_simple_test("Vp_Ip_BFu7i");
    static STRUCT_IF_C Vp_Ip_BFu7i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, 1, "Vp_Ip_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, hide_ull(1LL<<6), "Vp_Ip_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu7i, Vp_Ip_BFu7i)
//============================================================================


struct  Vp_Ip_BFu7ll  {
  void *v1;
  int *v2;
  __tsu64 v3:7;
};
//SIG(1 Vp_Ip_BFu7ll) C1{ Fp[2] FL:7}



static void Test_Vp_Ip_BFu7ll()
{
  {
    init_simple_test("Vp_Ip_BFu7ll");
    static STRUCT_IF_C Vp_Ip_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, 1, "Vp_Ip_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, hide_ull(1LL<<6), "Vp_Ip_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu7ll, Vp_Ip_BFu7ll)
//============================================================================


struct  Vp_Ip_BFu7s  {
  void *v1;
  int *v2;
  unsigned short v3:7;
};
//SIG(1 Vp_Ip_BFu7s) C1{ Fp[2] Fs:7}



static void Test_Vp_Ip_BFu7s()
{
  {
    init_simple_test("Vp_Ip_BFu7s");
    static STRUCT_IF_C Vp_Ip_BFu7s lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, 1, "Vp_Ip_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, hide_ull(1LL<<6), "Vp_Ip_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu7s, Vp_Ip_BFu7s)
//============================================================================


struct  Vp_Ip_BFu8c  {
  void *v1;
  int *v2;
  unsigned char v3:8;
};
//SIG(1 Vp_Ip_BFu8c) C1{ Fp[2] Fc:8}



static void Test_Vp_Ip_BFu8c()
{
  {
    init_simple_test("Vp_Ip_BFu8c");
    static STRUCT_IF_C Vp_Ip_BFu8c lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, 1, "Vp_Ip_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, hide_ull(1LL<<7), "Vp_Ip_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu8c, Vp_Ip_BFu8c)
//============================================================================


struct  Vp_Ip_BFu8i  {
  void *v1;
  int *v2;
  unsigned int v3:8;
};
//SIG(1 Vp_Ip_BFu8i) C1{ Fp[2] Fi:8}



static void Test_Vp_Ip_BFu8i()
{
  {
    init_simple_test("Vp_Ip_BFu8i");
    static STRUCT_IF_C Vp_Ip_BFu8i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, 1, "Vp_Ip_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, hide_ull(1LL<<7), "Vp_Ip_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu8i, Vp_Ip_BFu8i)
//============================================================================


struct  Vp_Ip_BFu8ll  {
  void *v1;
  int *v2;
  __tsu64 v3:8;
};
//SIG(1 Vp_Ip_BFu8ll) C1{ Fp[2] FL:8}



static void Test_Vp_Ip_BFu8ll()
{
  {
    init_simple_test("Vp_Ip_BFu8ll");
    static STRUCT_IF_C Vp_Ip_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, 1, "Vp_Ip_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, hide_ull(1LL<<7), "Vp_Ip_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu8ll, Vp_Ip_BFu8ll)
//============================================================================


struct  Vp_Ip_BFu8s  {
  void *v1;
  int *v2;
  unsigned short v3:8;
};
//SIG(1 Vp_Ip_BFu8s) C1{ Fp[2] Fs:8}



static void Test_Vp_Ip_BFu8s()
{
  {
    init_simple_test("Vp_Ip_BFu8s");
    static STRUCT_IF_C Vp_Ip_BFu8s lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, 1, "Vp_Ip_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, hide_ull(1LL<<7), "Vp_Ip_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu8s, Vp_Ip_BFu8s)
//============================================================================


struct  Vp_Ip_BFu9i  {
  void *v1;
  int *v2;
  unsigned int v3:9;
};
//SIG(1 Vp_Ip_BFu9i) C1{ Fp[2] Fi:9}



static void Test_Vp_Ip_BFu9i()
{
  {
    init_simple_test("Vp_Ip_BFu9i");
    static STRUCT_IF_C Vp_Ip_BFu9i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 9, 1, "Vp_Ip_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 9, hide_ull(1LL<<8), "Vp_Ip_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu9i, Vp_Ip_BFu9i)
//============================================================================


struct  Vp_Ip_BFu9ll  {
  void *v1;
  int *v2;
  __tsu64 v3:9;
};
//SIG(1 Vp_Ip_BFu9ll) C1{ Fp[2] FL:9}



static void Test_Vp_Ip_BFu9ll()
{
  {
    init_simple_test("Vp_Ip_BFu9ll");
    static STRUCT_IF_C Vp_Ip_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 9, 1, "Vp_Ip_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 9, hide_ull(1LL<<8), "Vp_Ip_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu9ll, Vp_Ip_BFu9ll)
//============================================================================


struct  Vp_Ip_BFu9s  {
  void *v1;
  int *v2;
  unsigned short v3:9;
};
//SIG(1 Vp_Ip_BFu9s) C1{ Fp[2] Fs:9}



static void Test_Vp_Ip_BFu9s()
{
  {
    init_simple_test("Vp_Ip_BFu9s");
    static STRUCT_IF_C Vp_Ip_BFu9s lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_Ip_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 9, 1, "Vp_Ip_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 9, hide_ull(1LL<<8), "Vp_Ip_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_BFu9s, Vp_Ip_BFu9s)
//============================================================================


struct  Vp_Ip_C  {
  void *v1;
  int *v2;
  char v3;
};
//SIG(1 Vp_Ip_C) C1{ Fp[2] Fc}



static void Test_Vp_Ip_C()
{
  {
    init_simple_test("Vp_Ip_C");
    STRUCT_IF_C Vp_Ip_C lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_C)");
    check_field_offset(lv, v1, 0, "Vp_Ip_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_C.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_C, Vp_Ip_C)
//============================================================================


struct  Vp_Ip_D  {
  void *v1;
  int *v2;
  double v3;
};
//SIG(1 Vp_Ip_D) C1{ Fp[2] FL}



static void Test_Vp_Ip_D()
{
  {
    init_simple_test("Vp_Ip_D");
    STRUCT_IF_C Vp_Ip_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ip_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_D)");
    check_field_offset(lv, v1, 0, "Vp_Ip_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_D.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_D, Vp_Ip_D)
//============================================================================


struct  Vp_Ip_F  {
  void *v1;
  int *v2;
  float v3;
};
//SIG(1 Vp_Ip_F) C1{ Fp[2] Fi}



static void Test_Vp_Ip_F()
{
  {
    init_simple_test("Vp_Ip_F");
    STRUCT_IF_C Vp_Ip_F lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_F)");
    check_field_offset(lv, v1, 0, "Vp_Ip_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_F.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_F, Vp_Ip_F)
//============================================================================


struct  Vp_Ip_I  {
  void *v1;
  int *v2;
  int v3;
};
//SIG(1 Vp_Ip_I) C1{ Fp[2] Fi}



static void Test_Vp_Ip_I()
{
  {
    init_simple_test("Vp_Ip_I");
    STRUCT_IF_C Vp_Ip_I lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_I)");
    check_field_offset(lv, v1, 0, "Vp_Ip_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_I.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_I, Vp_Ip_I)
//============================================================================


struct  Vp_Ip_Ip  {
  void *v1;
  int *v2;
  int *v3;
};
//SIG(1 Vp_Ip_Ip) C1{ Fp[3]}



static void Test_Vp_Ip_Ip()
{
  {
    init_simple_test("Vp_Ip_Ip");
    STRUCT_IF_C Vp_Ip_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_Ip)");
    check_field_offset(lv, v1, 0, "Vp_Ip_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_Ip, Vp_Ip_Ip)
//============================================================================


struct  Vp_Ip_L  {
  void *v1;
  int *v2;
  __tsi64 v3;
};
//SIG(1 Vp_Ip_L) C1{ Fp[2] FL}



static void Test_Vp_Ip_L()
{
  {
    init_simple_test("Vp_Ip_L");
    STRUCT_IF_C Vp_Ip_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ip_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_L)");
    check_field_offset(lv, v1, 0, "Vp_Ip_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_L.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_L, Vp_Ip_L)
//============================================================================


struct  Vp_Ip_S  {
  void *v1;
  int *v2;
  short v3;
};
//SIG(1 Vp_Ip_S) C1{ Fp[2] Fs}



static void Test_Vp_Ip_S()
{
  {
    init_simple_test("Vp_Ip_S");
    STRUCT_IF_C Vp_Ip_S lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_S)");
    check_field_offset(lv, v1, 0, "Vp_Ip_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_S.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_S, Vp_Ip_S)
//============================================================================


struct  Vp_Ip_Uc  {
  void *v1;
  int *v2;
  unsigned char v3;
};
//SIG(1 Vp_Ip_Uc) C1{ Fp[2] Fc}



static void Test_Vp_Ip_Uc()
{
  {
    init_simple_test("Vp_Ip_Uc");
    STRUCT_IF_C Vp_Ip_Uc lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_Uc)");
    check_field_offset(lv, v1, 0, "Vp_Ip_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_Uc, Vp_Ip_Uc)
//============================================================================


struct  Vp_Ip_Ui  {
  void *v1;
  int *v2;
  unsigned int v3;
};
//SIG(1 Vp_Ip_Ui) C1{ Fp[2] Fi}



static void Test_Vp_Ip_Ui()
{
  {
    init_simple_test("Vp_Ip_Ui");
    STRUCT_IF_C Vp_Ip_Ui lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_Ui)");
    check_field_offset(lv, v1, 0, "Vp_Ip_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_Ui, Vp_Ip_Ui)
//============================================================================


struct  Vp_Ip_Ul  {
  void *v1;
  int *v2;
  __tsu64 v3;
};
//SIG(1 Vp_Ip_Ul) C1{ Fp[2] FL}



static void Test_Vp_Ip_Ul()
{
  {
    init_simple_test("Vp_Ip_Ul");
    STRUCT_IF_C Vp_Ip_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ip_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_Ul)");
    check_field_offset(lv, v1, 0, "Vp_Ip_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_Ul, Vp_Ip_Ul)
//============================================================================


struct  Vp_Ip_Us  {
  void *v1;
  int *v2;
  unsigned short v3;
};
//SIG(1 Vp_Ip_Us) C1{ Fp[2] Fs}



static void Test_Vp_Ip_Us()
{
  {
    init_simple_test("Vp_Ip_Us");
    STRUCT_IF_C Vp_Ip_Us lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_Us)");
    check_field_offset(lv, v1, 0, "Vp_Ip_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_Us.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_Us, Vp_Ip_Us)
//============================================================================


struct  Vp_Ip_Vp  {
  void *v1;
  int *v2;
  void *v3;
};
//SIG(1 Vp_Ip_Vp) C1{ Fp[3]}



static void Test_Vp_Ip_Vp()
{
  {
    init_simple_test("Vp_Ip_Vp");
    STRUCT_IF_C Vp_Ip_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ip_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ip_Vp)");
    check_field_offset(lv, v1, 0, "Vp_Ip_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ip_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ip_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ip_Vp, Vp_Ip_Vp)
//============================================================================


struct  Vp_L  {
  void *v1;
  __tsi64 v2;
};
//SIG(1 Vp_L) C1{ Fp FL}



static void Test_Vp_L()
{
  {
    init_simple_test("Vp_L");
    STRUCT_IF_C Vp_L lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L)");
    check_field_offset(lv, v1, 0, "Vp_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L, Vp_L)
//============================================================================


struct  Vp_L_BFu15i  {
  void *v1;
  __tsi64 v2;
  unsigned int v3:15;
};
//SIG(1 Vp_L_BFu15i) C1{ Fp FL Fi:15}



static void Test_Vp_L_BFu15i()
{
  {
    init_simple_test("Vp_L_BFu15i");
    static STRUCT_IF_C Vp_L_BFu15i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, 1, "Vp_L_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, hide_ull(1LL<<14), "Vp_L_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu15i, Vp_L_BFu15i)
//============================================================================


struct  Vp_L_BFu15ll  {
  void *v1;
  __tsi64 v2;
  __tsu64 v3:15;
};
//SIG(1 Vp_L_BFu15ll) C1{ Fp FL FL:15}



static void Test_Vp_L_BFu15ll()
{
  {
    init_simple_test("Vp_L_BFu15ll");
    static STRUCT_IF_C Vp_L_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, 1, "Vp_L_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, hide_ull(1LL<<14), "Vp_L_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu15ll, Vp_L_BFu15ll)
//============================================================================


struct  Vp_L_BFu15s  {
  void *v1;
  __tsi64 v2;
  unsigned short v3:15;
};
//SIG(1 Vp_L_BFu15s) C1{ Fp FL Fs:15}



static void Test_Vp_L_BFu15s()
{
  {
    init_simple_test("Vp_L_BFu15s");
    static STRUCT_IF_C Vp_L_BFu15s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, 1, "Vp_L_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, hide_ull(1LL<<14), "Vp_L_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu15s, Vp_L_BFu15s)
//============================================================================


struct  Vp_L_BFu16i  {
  void *v1;
  __tsi64 v2;
  unsigned int v3:16;
};
//SIG(1 Vp_L_BFu16i) C1{ Fp FL Fi:16}



static void Test_Vp_L_BFu16i()
{
  {
    init_simple_test("Vp_L_BFu16i");
    static STRUCT_IF_C Vp_L_BFu16i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, 1, "Vp_L_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, hide_ull(1LL<<15), "Vp_L_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu16i, Vp_L_BFu16i)
//============================================================================


struct  Vp_L_BFu16ll  {
  void *v1;
  __tsi64 v2;
  __tsu64 v3:16;
};
//SIG(1 Vp_L_BFu16ll) C1{ Fp FL FL:16}



static void Test_Vp_L_BFu16ll()
{
  {
    init_simple_test("Vp_L_BFu16ll");
    static STRUCT_IF_C Vp_L_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, 1, "Vp_L_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, hide_ull(1LL<<15), "Vp_L_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu16ll, Vp_L_BFu16ll)
//============================================================================


struct  Vp_L_BFu16s  {
  void *v1;
  __tsi64 v2;
  unsigned short v3:16;
};
//SIG(1 Vp_L_BFu16s) C1{ Fp FL Fs:16}



static void Test_Vp_L_BFu16s()
{
  {
    init_simple_test("Vp_L_BFu16s");
    static STRUCT_IF_C Vp_L_BFu16s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, 1, "Vp_L_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, hide_ull(1LL<<15), "Vp_L_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu16s, Vp_L_BFu16s)
//============================================================================


struct  Vp_L_BFu17i  {
  void *v1;
  __tsi64 v2;
  unsigned int v3:17;
};
//SIG(1 Vp_L_BFu17i) C1{ Fp FL Fi:17}



static void Test_Vp_L_BFu17i()
{
  {
    init_simple_test("Vp_L_BFu17i");
    static STRUCT_IF_C Vp_L_BFu17i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 17, 1, "Vp_L_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 17, hide_ull(1LL<<16), "Vp_L_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu17i, Vp_L_BFu17i)
//============================================================================


struct  Vp_L_BFu17ll  {
  void *v1;
  __tsi64 v2;
  __tsu64 v3:17;
};
//SIG(1 Vp_L_BFu17ll) C1{ Fp FL FL:17}



static void Test_Vp_L_BFu17ll()
{
  {
    init_simple_test("Vp_L_BFu17ll");
    static STRUCT_IF_C Vp_L_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 17, 1, "Vp_L_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 17, hide_ull(1LL<<16), "Vp_L_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu17ll, Vp_L_BFu17ll)
//============================================================================


struct  Vp_L_BFu1c  {
  void *v1;
  __tsi64 v2;
  unsigned char v3:1;
};
//SIG(1 Vp_L_BFu1c) C1{ Fp FL Fc:1}



static void Test_Vp_L_BFu1c()
{
  {
    init_simple_test("Vp_L_BFu1c");
    static STRUCT_IF_C Vp_L_BFu1c lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 1, 1, "Vp_L_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu1c, Vp_L_BFu1c)
//============================================================================


struct  Vp_L_BFu1i  {
  void *v1;
  __tsi64 v2;
  unsigned int v3:1;
};
//SIG(1 Vp_L_BFu1i) C1{ Fp FL Fi:1}



static void Test_Vp_L_BFu1i()
{
  {
    init_simple_test("Vp_L_BFu1i");
    static STRUCT_IF_C Vp_L_BFu1i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 1, 1, "Vp_L_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu1i, Vp_L_BFu1i)
//============================================================================


struct  Vp_L_BFu1ll  {
  void *v1;
  __tsi64 v2;
  __tsu64 v3:1;
};
//SIG(1 Vp_L_BFu1ll) C1{ Fp FL FL:1}



static void Test_Vp_L_BFu1ll()
{
  {
    init_simple_test("Vp_L_BFu1ll");
    static STRUCT_IF_C Vp_L_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 1, 1, "Vp_L_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu1ll, Vp_L_BFu1ll)
//============================================================================


struct  Vp_L_BFu1s  {
  void *v1;
  __tsi64 v2;
  unsigned short v3:1;
};
//SIG(1 Vp_L_BFu1s) C1{ Fp FL Fs:1}



static void Test_Vp_L_BFu1s()
{
  {
    init_simple_test("Vp_L_BFu1s");
    static STRUCT_IF_C Vp_L_BFu1s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 1, 1, "Vp_L_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu1s, Vp_L_BFu1s)
//============================================================================


struct  Vp_L_BFu31i  {
  void *v1;
  __tsi64 v2;
  unsigned int v3:31;
};
//SIG(1 Vp_L_BFu31i) C1{ Fp FL Fi:31}



static void Test_Vp_L_BFu31i()
{
  {
    init_simple_test("Vp_L_BFu31i");
    static STRUCT_IF_C Vp_L_BFu31i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 31, 1, "Vp_L_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 31, hide_ull(1LL<<30), "Vp_L_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu31i, Vp_L_BFu31i)
//============================================================================


struct  Vp_L_BFu31ll  {
  void *v1;
  __tsi64 v2;
  __tsu64 v3:31;
};
//SIG(1 Vp_L_BFu31ll) C1{ Fp FL FL:31}



static void Test_Vp_L_BFu31ll()
{
  {
    init_simple_test("Vp_L_BFu31ll");
    static STRUCT_IF_C Vp_L_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 31, 1, "Vp_L_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 31, hide_ull(1LL<<30), "Vp_L_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu31ll, Vp_L_BFu31ll)
//============================================================================


struct  Vp_L_BFu32i  {
  void *v1;
  __tsi64 v2;
  unsigned int v3:32;
};
//SIG(1 Vp_L_BFu32i) C1{ Fp FL Fi:32}



static void Test_Vp_L_BFu32i()
{
  {
    init_simple_test("Vp_L_BFu32i");
    static STRUCT_IF_C Vp_L_BFu32i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, 1, "Vp_L_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, hide_ull(1LL<<31), "Vp_L_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu32i, Vp_L_BFu32i)
//============================================================================


struct  Vp_L_BFu32ll  {
  void *v1;
  __tsi64 v2;
  __tsu64 v3:32;
};
//SIG(1 Vp_L_BFu32ll) C1{ Fp FL FL:32}



static void Test_Vp_L_BFu32ll()
{
  {
    init_simple_test("Vp_L_BFu32ll");
    static STRUCT_IF_C Vp_L_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, 1, "Vp_L_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, hide_ull(1LL<<31), "Vp_L_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu32ll, Vp_L_BFu32ll)
//============================================================================


struct  Vp_L_BFu33  {
  void *v1;
  __tsi64 v2;
  __tsu64 v3:33;
};
//SIG(1 Vp_L_BFu33) C1{ Fp FL FL:33}



static void Test_Vp_L_BFu33()
{
  {
    init_simple_test("Vp_L_BFu33");
    static STRUCT_IF_C Vp_L_BFu33 lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_L_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 33, 1, "Vp_L_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 33, hide_ull(1LL<<32), "Vp_L_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu33, Vp_L_BFu33)
//============================================================================


struct  Vp_L_BFu7c  {
  void *v1;
  __tsi64 v2;
  unsigned char v3:7;
};
//SIG(1 Vp_L_BFu7c) C1{ Fp FL Fc:7}



static void Test_Vp_L_BFu7c()
{
  {
    init_simple_test("Vp_L_BFu7c");
    static STRUCT_IF_C Vp_L_BFu7c lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, 1, "Vp_L_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, hide_ull(1LL<<6), "Vp_L_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu7c, Vp_L_BFu7c)
//============================================================================


struct  Vp_L_BFu7i  {
  void *v1;
  __tsi64 v2;
  unsigned int v3:7;
};
//SIG(1 Vp_L_BFu7i) C1{ Fp FL Fi:7}



static void Test_Vp_L_BFu7i()
{
  {
    init_simple_test("Vp_L_BFu7i");
    static STRUCT_IF_C Vp_L_BFu7i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, 1, "Vp_L_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, hide_ull(1LL<<6), "Vp_L_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu7i, Vp_L_BFu7i)
//============================================================================


struct  Vp_L_BFu7ll  {
  void *v1;
  __tsi64 v2;
  __tsu64 v3:7;
};
//SIG(1 Vp_L_BFu7ll) C1{ Fp FL FL:7}



static void Test_Vp_L_BFu7ll()
{
  {
    init_simple_test("Vp_L_BFu7ll");
    static STRUCT_IF_C Vp_L_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, 1, "Vp_L_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, hide_ull(1LL<<6), "Vp_L_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu7ll, Vp_L_BFu7ll)
//============================================================================


struct  Vp_L_BFu7s  {
  void *v1;
  __tsi64 v2;
  unsigned short v3:7;
};
//SIG(1 Vp_L_BFu7s) C1{ Fp FL Fs:7}



static void Test_Vp_L_BFu7s()
{
  {
    init_simple_test("Vp_L_BFu7s");
    static STRUCT_IF_C Vp_L_BFu7s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, 1, "Vp_L_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, hide_ull(1LL<<6), "Vp_L_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu7s, Vp_L_BFu7s)
//============================================================================


struct  Vp_L_BFu8c  {
  void *v1;
  __tsi64 v2;
  unsigned char v3:8;
};
//SIG(1 Vp_L_BFu8c) C1{ Fp FL Fc:8}



static void Test_Vp_L_BFu8c()
{
  {
    init_simple_test("Vp_L_BFu8c");
    static STRUCT_IF_C Vp_L_BFu8c lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, 1, "Vp_L_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, hide_ull(1LL<<7), "Vp_L_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu8c, Vp_L_BFu8c)
//============================================================================


struct  Vp_L_BFu8i  {
  void *v1;
  __tsi64 v2;
  unsigned int v3:8;
};
//SIG(1 Vp_L_BFu8i) C1{ Fp FL Fi:8}



static void Test_Vp_L_BFu8i()
{
  {
    init_simple_test("Vp_L_BFu8i");
    static STRUCT_IF_C Vp_L_BFu8i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, 1, "Vp_L_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, hide_ull(1LL<<7), "Vp_L_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu8i, Vp_L_BFu8i)
//============================================================================


struct  Vp_L_BFu8ll  {
  void *v1;
  __tsi64 v2;
  __tsu64 v3:8;
};
//SIG(1 Vp_L_BFu8ll) C1{ Fp FL FL:8}



static void Test_Vp_L_BFu8ll()
{
  {
    init_simple_test("Vp_L_BFu8ll");
    static STRUCT_IF_C Vp_L_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, 1, "Vp_L_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, hide_ull(1LL<<7), "Vp_L_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu8ll, Vp_L_BFu8ll)
//============================================================================


struct  Vp_L_BFu8s  {
  void *v1;
  __tsi64 v2;
  unsigned short v3:8;
};
//SIG(1 Vp_L_BFu8s) C1{ Fp FL Fs:8}



static void Test_Vp_L_BFu8s()
{
  {
    init_simple_test("Vp_L_BFu8s");
    static STRUCT_IF_C Vp_L_BFu8s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, 1, "Vp_L_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, hide_ull(1LL<<7), "Vp_L_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu8s, Vp_L_BFu8s)
//============================================================================


struct  Vp_L_BFu9i  {
  void *v1;
  __tsi64 v2;
  unsigned int v3:9;
};
//SIG(1 Vp_L_BFu9i) C1{ Fp FL Fi:9}



static void Test_Vp_L_BFu9i()
{
  {
    init_simple_test("Vp_L_BFu9i");
    static STRUCT_IF_C Vp_L_BFu9i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, 1, "Vp_L_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, hide_ull(1LL<<8), "Vp_L_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu9i, Vp_L_BFu9i)
//============================================================================


struct  Vp_L_BFu9ll  {
  void *v1;
  __tsi64 v2;
  __tsu64 v3:9;
};
//SIG(1 Vp_L_BFu9ll) C1{ Fp FL FL:9}



static void Test_Vp_L_BFu9ll()
{
  {
    init_simple_test("Vp_L_BFu9ll");
    static STRUCT_IF_C Vp_L_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, 1, "Vp_L_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, hide_ull(1LL<<8), "Vp_L_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu9ll, Vp_L_BFu9ll)
//============================================================================


struct  Vp_L_BFu9s  {
  void *v1;
  __tsi64 v2;
  unsigned short v3:9;
};
//SIG(1 Vp_L_BFu9s) C1{ Fp FL Fs:9}



static void Test_Vp_L_BFu9s()
{
  {
    init_simple_test("Vp_L_BFu9s");
    static STRUCT_IF_C Vp_L_BFu9s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_L_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, 1, "Vp_L_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, hide_ull(1LL<<8), "Vp_L_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_BFu9s, Vp_L_BFu9s)
//============================================================================


struct  Vp_L_C  {
  void *v1;
  __tsi64 v2;
  char v3;
};
//SIG(1 Vp_L_C) C1{ Fp FL Fc}



static void Test_Vp_L_C()
{
  {
    init_simple_test("Vp_L_C");
    STRUCT_IF_C Vp_L_C lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_C)");
    check_field_offset(lv, v1, 0, "Vp_L_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_C.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_C, Vp_L_C)
//============================================================================


struct  Vp_L_D  {
  void *v1;
  __tsi64 v2;
  double v3;
};
//SIG(1 Vp_L_D) C1{ Fp FL[2]}



static void Test_Vp_L_D()
{
  {
    init_simple_test("Vp_L_D");
    STRUCT_IF_C Vp_L_D lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_L_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_D)");
    check_field_offset(lv, v1, 0, "Vp_L_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_D.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_D, Vp_L_D)
//============================================================================


struct  Vp_L_F  {
  void *v1;
  __tsi64 v2;
  float v3;
};
//SIG(1 Vp_L_F) C1{ Fp FL Fi}



static void Test_Vp_L_F()
{
  {
    init_simple_test("Vp_L_F");
    STRUCT_IF_C Vp_L_F lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_F)");
    check_field_offset(lv, v1, 0, "Vp_L_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_F.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_F, Vp_L_F)
//============================================================================


struct  Vp_L_I  {
  void *v1;
  __tsi64 v2;
  int v3;
};
//SIG(1 Vp_L_I) C1{ Fp FL Fi}



static void Test_Vp_L_I()
{
  {
    init_simple_test("Vp_L_I");
    STRUCT_IF_C Vp_L_I lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_I)");
    check_field_offset(lv, v1, 0, "Vp_L_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_I.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_I, Vp_L_I)
//============================================================================


struct  Vp_L_Ip  {
  void *v1;
  __tsi64 v2;
  int *v3;
};
//SIG(1 Vp_L_Ip) C1{ Fp FL Fp}



static void Test_Vp_L_Ip()
{
  {
    init_simple_test("Vp_L_Ip");
    STRUCT_IF_C Vp_L_Ip lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_Ip)");
    check_field_offset(lv, v1, 0, "Vp_L_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_Ip, Vp_L_Ip)
//============================================================================


struct  Vp_L_L  {
  void *v1;
  __tsi64 v2;
  __tsi64 v3;
};
//SIG(1 Vp_L_L) C1{ Fp FL[2]}



static void Test_Vp_L_L()
{
  {
    init_simple_test("Vp_L_L");
    STRUCT_IF_C Vp_L_L lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_L_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_L)");
    check_field_offset(lv, v1, 0, "Vp_L_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_L.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_L, Vp_L_L)
//============================================================================


struct  Vp_L_S  {
  void *v1;
  __tsi64 v2;
  short v3;
};
//SIG(1 Vp_L_S) C1{ Fp FL Fs}



static void Test_Vp_L_S()
{
  {
    init_simple_test("Vp_L_S");
    STRUCT_IF_C Vp_L_S lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_S)");
    check_field_offset(lv, v1, 0, "Vp_L_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_S.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_S, Vp_L_S)
//============================================================================


struct  Vp_L_Uc  {
  void *v1;
  __tsi64 v2;
  unsigned char v3;
};
//SIG(1 Vp_L_Uc) C1{ Fp FL Fc}



static void Test_Vp_L_Uc()
{
  {
    init_simple_test("Vp_L_Uc");
    STRUCT_IF_C Vp_L_Uc lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_Uc)");
    check_field_offset(lv, v1, 0, "Vp_L_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_Uc, Vp_L_Uc)
//============================================================================


struct  Vp_L_Ui  {
  void *v1;
  __tsi64 v2;
  unsigned int v3;
};
//SIG(1 Vp_L_Ui) C1{ Fp FL Fi}



static void Test_Vp_L_Ui()
{
  {
    init_simple_test("Vp_L_Ui");
    STRUCT_IF_C Vp_L_Ui lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_Ui)");
    check_field_offset(lv, v1, 0, "Vp_L_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_Ui, Vp_L_Ui)
//============================================================================


struct  Vp_L_Ul  {
  void *v1;
  __tsi64 v2;
  __tsu64 v3;
};
//SIG(1 Vp_L_Ul) C1{ Fp FL[2]}



static void Test_Vp_L_Ul()
{
  {
    init_simple_test("Vp_L_Ul");
    STRUCT_IF_C Vp_L_Ul lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_L_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_Ul)");
    check_field_offset(lv, v1, 0, "Vp_L_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_Ul, Vp_L_Ul)
//============================================================================


struct  Vp_L_Us  {
  void *v1;
  __tsi64 v2;
  unsigned short v3;
};
//SIG(1 Vp_L_Us) C1{ Fp FL Fs}



static void Test_Vp_L_Us()
{
  {
    init_simple_test("Vp_L_Us");
    STRUCT_IF_C Vp_L_Us lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_Us)");
    check_field_offset(lv, v1, 0, "Vp_L_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_Us.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_Us, Vp_L_Us)
//============================================================================


struct  Vp_L_Vp  {
  void *v1;
  __tsi64 v2;
  void *v3;
};
//SIG(1 Vp_L_Vp) C1{ Fp FL Fp}



static void Test_Vp_L_Vp()
{
  {
    init_simple_test("Vp_L_Vp");
    STRUCT_IF_C Vp_L_Vp lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_L_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_L_Vp)");
    check_field_offset(lv, v1, 0, "Vp_L_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_L_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_L_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_L_Vp, Vp_L_Vp)
//============================================================================


struct  Vp_S  {
  void *v1;
  short v2;
};
//SIG(1 Vp_S) C1{ Fp Fs}



static void Test_Vp_S()
{
  {
    init_simple_test("Vp_S");
    STRUCT_IF_C Vp_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S)");
    check_field_offset(lv, v1, 0, "Vp_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S, Vp_S)
//============================================================================


struct  Vp_S_BFu15i  {
  void *v1;
  short v2;
  unsigned int v3:15;
};
//SIG(1 Vp_S_BFu15i) C1{ Fp Fs Fi:15}



static void Test_Vp_S_BFu15i()
{
  {
    init_simple_test("Vp_S_BFu15i");
    static STRUCT_IF_C Vp_S_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_S_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_S_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu15i, Vp_S_BFu15i)
//============================================================================


struct  Vp_S_BFu15ll  {
  void *v1;
  short v2;
  __tsu64 v3:15;
};
//SIG(1 Vp_S_BFu15ll) C1{ Fp Fs FL:15}



static void Test_Vp_S_BFu15ll()
{
  {
    init_simple_test("Vp_S_BFu15ll");
    static STRUCT_IF_C Vp_S_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_S_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_S_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu15ll, Vp_S_BFu15ll)
//============================================================================


struct  Vp_S_BFu15s  {
  void *v1;
  short v2;
  unsigned short v3:15;
};
//SIG(1 Vp_S_BFu15s) C1{ Fp Fs Fs:15}



static void Test_Vp_S_BFu15s()
{
  {
    init_simple_test("Vp_S_BFu15s");
    static STRUCT_IF_C Vp_S_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_S_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_S_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu15s, Vp_S_BFu15s)
//============================================================================


struct  Vp_S_BFu16i  {
  void *v1;
  short v2;
  unsigned int v3:16;
};
//SIG(1 Vp_S_BFu16i) C1{ Fp Fs Fi:16}



static void Test_Vp_S_BFu16i()
{
  {
    init_simple_test("Vp_S_BFu16i");
    static STRUCT_IF_C Vp_S_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_S_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_S_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu16i, Vp_S_BFu16i)
//============================================================================


struct  Vp_S_BFu16ll  {
  void *v1;
  short v2;
  __tsu64 v3:16;
};
//SIG(1 Vp_S_BFu16ll) C1{ Fp Fs FL:16}



static void Test_Vp_S_BFu16ll()
{
  {
    init_simple_test("Vp_S_BFu16ll");
    static STRUCT_IF_C Vp_S_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_S_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_S_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu16ll, Vp_S_BFu16ll)
//============================================================================


struct  Vp_S_BFu16s  {
  void *v1;
  short v2;
  unsigned short v3:16;
};
//SIG(1 Vp_S_BFu16s) C1{ Fp Fs Fs:16}



static void Test_Vp_S_BFu16s()
{
  {
    init_simple_test("Vp_S_BFu16s");
    static STRUCT_IF_C Vp_S_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_S_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_S_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu16s, Vp_S_BFu16s)
//============================================================================


struct  Vp_S_BFu17i  {
  void *v1;
  short v2;
  unsigned int v3:17;
};
//SIG(1 Vp_S_BFu17i) C1{ Fp Fs Fi:17}



static void Test_Vp_S_BFu17i()
{
  {
    init_simple_test("Vp_S_BFu17i");
    static STRUCT_IF_C Vp_S_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_S_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, 1, "Vp_S_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, hide_ull(1LL<<16), "Vp_S_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu17i, Vp_S_BFu17i)
//============================================================================


struct  Vp_S_BFu17ll  {
  void *v1;
  short v2;
  __tsu64 v3:17;
};
//SIG(1 Vp_S_BFu17ll) C1{ Fp Fs FL:17}



static void Test_Vp_S_BFu17ll()
{
  {
    init_simple_test("Vp_S_BFu17ll");
    static STRUCT_IF_C Vp_S_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_S_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 17, 1, "Vp_S_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 17, hide_ull(1LL<<16), "Vp_S_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu17ll, Vp_S_BFu17ll)
//============================================================================


struct  Vp_S_BFu1c  {
  void *v1;
  short v2;
  unsigned char v3:1;
};
//SIG(1 Vp_S_BFu1c) C1{ Fp Fs Fc:1}



static void Test_Vp_S_BFu1c()
{
  {
    init_simple_test("Vp_S_BFu1c");
    static STRUCT_IF_C Vp_S_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 1, 1, "Vp_S_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu1c, Vp_S_BFu1c)
//============================================================================


struct  Vp_S_BFu1i  {
  void *v1;
  short v2;
  unsigned int v3:1;
};
//SIG(1 Vp_S_BFu1i) C1{ Fp Fs Fi:1}



static void Test_Vp_S_BFu1i()
{
  {
    init_simple_test("Vp_S_BFu1i");
    static STRUCT_IF_C Vp_S_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 1, 1, "Vp_S_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu1i, Vp_S_BFu1i)
//============================================================================


struct  Vp_S_BFu1ll  {
  void *v1;
  short v2;
  __tsu64 v3:1;
};
//SIG(1 Vp_S_BFu1ll) C1{ Fp Fs FL:1}



static void Test_Vp_S_BFu1ll()
{
  {
    init_simple_test("Vp_S_BFu1ll");
    static STRUCT_IF_C Vp_S_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 1, 1, "Vp_S_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu1ll, Vp_S_BFu1ll)
//============================================================================


struct  Vp_S_BFu1s  {
  void *v1;
  short v2;
  unsigned short v3:1;
};
//SIG(1 Vp_S_BFu1s) C1{ Fp Fs Fs:1}



static void Test_Vp_S_BFu1s()
{
  {
    init_simple_test("Vp_S_BFu1s");
    static STRUCT_IF_C Vp_S_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 1, 1, "Vp_S_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu1s, Vp_S_BFu1s)
//============================================================================


struct  Vp_S_BFu31i  {
  void *v1;
  short v2;
  unsigned int v3:31;
};
//SIG(1 Vp_S_BFu31i) C1{ Fp Fs Fi:31}



static void Test_Vp_S_BFu31i()
{
  {
    init_simple_test("Vp_S_BFu31i");
    static STRUCT_IF_C Vp_S_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_S_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_S_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_S_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu31i, Vp_S_BFu31i)
//============================================================================


struct  Vp_S_BFu31ll  {
  void *v1;
  short v2;
  __tsu64 v3:31;
};
//SIG(1 Vp_S_BFu31ll) C1{ Fp Fs FL:31}



static void Test_Vp_S_BFu31ll()
{
  {
    init_simple_test("Vp_S_BFu31ll");
    static STRUCT_IF_C Vp_S_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_S_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 31, 1, "Vp_S_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 31, hide_ull(1LL<<30), "Vp_S_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu31ll, Vp_S_BFu31ll)
//============================================================================


struct  Vp_S_BFu32i  {
  void *v1;
  short v2;
  unsigned int v3:32;
};
//SIG(1 Vp_S_BFu32i) C1{ Fp Fs Fi:32}



static void Test_Vp_S_BFu32i()
{
  {
    init_simple_test("Vp_S_BFu32i");
    static STRUCT_IF_C Vp_S_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_S_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_S_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_S_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu32i, Vp_S_BFu32i)
//============================================================================


struct  Vp_S_BFu32ll  {
  void *v1;
  short v2;
  __tsu64 v3:32;
};
//SIG(1 Vp_S_BFu32ll) C1{ Fp Fs FL:32}



static void Test_Vp_S_BFu32ll()
{
  {
    init_simple_test("Vp_S_BFu32ll");
    static STRUCT_IF_C Vp_S_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_S_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 32, 1, "Vp_S_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 32, hide_ull(1LL<<31), "Vp_S_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu32ll, Vp_S_BFu32ll)
//============================================================================


struct  Vp_S_BFu33  {
  void *v1;
  short v2;
  __tsu64 v3:33;
};
//SIG(1 Vp_S_BFu33) C1{ Fp Fs FL:33}



static void Test_Vp_S_BFu33()
{
  {
    init_simple_test("Vp_S_BFu33");
    static STRUCT_IF_C Vp_S_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_S_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 33, 1, "Vp_S_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 33, hide_ull(1LL<<32), "Vp_S_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu33, Vp_S_BFu33)
//============================================================================


struct  Vp_S_BFu7c  {
  void *v1;
  short v2;
  unsigned char v3:7;
};
//SIG(1 Vp_S_BFu7c) C1{ Fp Fs Fc:7}



static void Test_Vp_S_BFu7c()
{
  {
    init_simple_test("Vp_S_BFu7c");
    static STRUCT_IF_C Vp_S_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, 1, "Vp_S_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, hide_ull(1LL<<6), "Vp_S_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu7c, Vp_S_BFu7c)
//============================================================================


struct  Vp_S_BFu7i  {
  void *v1;
  short v2;
  unsigned int v3:7;
};
//SIG(1 Vp_S_BFu7i) C1{ Fp Fs Fi:7}



static void Test_Vp_S_BFu7i()
{
  {
    init_simple_test("Vp_S_BFu7i");
    static STRUCT_IF_C Vp_S_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, 1, "Vp_S_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, hide_ull(1LL<<6), "Vp_S_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu7i, Vp_S_BFu7i)
//============================================================================


struct  Vp_S_BFu7ll  {
  void *v1;
  short v2;
  __tsu64 v3:7;
};
//SIG(1 Vp_S_BFu7ll) C1{ Fp Fs FL:7}



static void Test_Vp_S_BFu7ll()
{
  {
    init_simple_test("Vp_S_BFu7ll");
    static STRUCT_IF_C Vp_S_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, 1, "Vp_S_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, hide_ull(1LL<<6), "Vp_S_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu7ll, Vp_S_BFu7ll)
//============================================================================


struct  Vp_S_BFu7s  {
  void *v1;
  short v2;
  unsigned short v3:7;
};
//SIG(1 Vp_S_BFu7s) C1{ Fp Fs Fs:7}



static void Test_Vp_S_BFu7s()
{
  {
    init_simple_test("Vp_S_BFu7s");
    static STRUCT_IF_C Vp_S_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, 1, "Vp_S_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, hide_ull(1LL<<6), "Vp_S_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu7s, Vp_S_BFu7s)
//============================================================================


struct  Vp_S_BFu8c  {
  void *v1;
  short v2;
  unsigned char v3:8;
};
//SIG(1 Vp_S_BFu8c) C1{ Fp Fs Fc:8}



static void Test_Vp_S_BFu8c()
{
  {
    init_simple_test("Vp_S_BFu8c");
    static STRUCT_IF_C Vp_S_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_S_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_S_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu8c, Vp_S_BFu8c)
//============================================================================


struct  Vp_S_BFu8i  {
  void *v1;
  short v2;
  unsigned int v3:8;
};
//SIG(1 Vp_S_BFu8i) C1{ Fp Fs Fi:8}



static void Test_Vp_S_BFu8i()
{
  {
    init_simple_test("Vp_S_BFu8i");
    static STRUCT_IF_C Vp_S_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_S_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_S_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu8i, Vp_S_BFu8i)
//============================================================================


struct  Vp_S_BFu8ll  {
  void *v1;
  short v2;
  __tsu64 v3:8;
};
//SIG(1 Vp_S_BFu8ll) C1{ Fp Fs FL:8}



static void Test_Vp_S_BFu8ll()
{
  {
    init_simple_test("Vp_S_BFu8ll");
    static STRUCT_IF_C Vp_S_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_S_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_S_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu8ll, Vp_S_BFu8ll)
//============================================================================


struct  Vp_S_BFu8s  {
  void *v1;
  short v2;
  unsigned short v3:8;
};
//SIG(1 Vp_S_BFu8s) C1{ Fp Fs Fs:8}



static void Test_Vp_S_BFu8s()
{
  {
    init_simple_test("Vp_S_BFu8s");
    static STRUCT_IF_C Vp_S_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_S_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_S_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu8s, Vp_S_BFu8s)
//============================================================================


struct  Vp_S_BFu9i  {
  void *v1;
  short v2;
  unsigned int v3:9;
};
//SIG(1 Vp_S_BFu9i) C1{ Fp Fs Fi:9}



static void Test_Vp_S_BFu9i()
{
  {
    init_simple_test("Vp_S_BFu9i");
    static STRUCT_IF_C Vp_S_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_S_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_S_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu9i, Vp_S_BFu9i)
//============================================================================


struct  Vp_S_BFu9ll  {
  void *v1;
  short v2;
  __tsu64 v3:9;
};
//SIG(1 Vp_S_BFu9ll) C1{ Fp Fs FL:9}



static void Test_Vp_S_BFu9ll()
{
  {
    init_simple_test("Vp_S_BFu9ll");
    static STRUCT_IF_C Vp_S_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_S_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_S_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu9ll, Vp_S_BFu9ll)
//============================================================================


struct  Vp_S_BFu9s  {
  void *v1;
  short v2;
  unsigned short v3:9;
};
//SIG(1 Vp_S_BFu9s) C1{ Fp Fs Fs:9}



static void Test_Vp_S_BFu9s()
{
  {
    init_simple_test("Vp_S_BFu9s");
    static STRUCT_IF_C Vp_S_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_S_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_S_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_S_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_BFu9s, Vp_S_BFu9s)
//============================================================================


struct  Vp_S_C  {
  void *v1;
  short v2;
  char v3;
};
//SIG(1 Vp_S_C) C1{ Fp Fs Fc}



static void Test_Vp_S_C()
{
  {
    init_simple_test("Vp_S_C");
    STRUCT_IF_C Vp_S_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_C)");
    check_field_offset(lv, v1, 0, "Vp_S_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_C.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_S_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_C, Vp_S_C)
//============================================================================


struct  Vp_S_D  {
  void *v1;
  short v2;
  double v3;
};
//SIG(1 Vp_S_D) C1{ Fp Fs FL}



static void Test_Vp_S_D()
{
  {
    init_simple_test("Vp_S_D");
    STRUCT_IF_C Vp_S_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_S_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_D)");
    check_field_offset(lv, v1, 0, "Vp_S_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_D.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_S_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_D, Vp_S_D)
//============================================================================


struct  Vp_S_F  {
  void *v1;
  short v2;
  float v3;
};
//SIG(1 Vp_S_F) C1{ Fp Fs Fi}



static void Test_Vp_S_F()
{
  {
    init_simple_test("Vp_S_F");
    STRUCT_IF_C Vp_S_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_S_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_F)");
    check_field_offset(lv, v1, 0, "Vp_S_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_F.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_S_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_F, Vp_S_F)
//============================================================================


struct  Vp_S_I  {
  void *v1;
  short v2;
  int v3;
};
//SIG(1 Vp_S_I) C1{ Fp Fs Fi}



static void Test_Vp_S_I()
{
  {
    init_simple_test("Vp_S_I");
    STRUCT_IF_C Vp_S_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_S_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_I)");
    check_field_offset(lv, v1, 0, "Vp_S_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_I.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_S_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_I, Vp_S_I)
//============================================================================


struct  Vp_S_Ip  {
  void *v1;
  short v2;
  int *v3;
};
//SIG(1 Vp_S_Ip) C1{ Fp Fs Fp}



static void Test_Vp_S_Ip()
{
  {
    init_simple_test("Vp_S_Ip");
    STRUCT_IF_C Vp_S_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_S_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_Ip)");
    check_field_offset(lv, v1, 0, "Vp_S_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_S_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_Ip, Vp_S_Ip)
//============================================================================


struct  Vp_S_L  {
  void *v1;
  short v2;
  __tsi64 v3;
};
//SIG(1 Vp_S_L) C1{ Fp Fs FL}



static void Test_Vp_S_L()
{
  {
    init_simple_test("Vp_S_L");
    STRUCT_IF_C Vp_S_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_S_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_L)");
    check_field_offset(lv, v1, 0, "Vp_S_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_L.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_S_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_L, Vp_S_L)
//============================================================================


struct  Vp_S_S  {
  void *v1;
  short v2;
  short v3;
};
//SIG(1 Vp_S_S) C1{ Fp Fs[2]}



static void Test_Vp_S_S()
{
  {
    init_simple_test("Vp_S_S");
    STRUCT_IF_C Vp_S_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_S)");
    check_field_offset(lv, v1, 0, "Vp_S_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_S.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_S_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_S, Vp_S_S)
//============================================================================


struct  Vp_S_Uc  {
  void *v1;
  short v2;
  unsigned char v3;
};
//SIG(1 Vp_S_Uc) C1{ Fp Fs Fc}



static void Test_Vp_S_Uc()
{
  {
    init_simple_test("Vp_S_Uc");
    STRUCT_IF_C Vp_S_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_Uc)");
    check_field_offset(lv, v1, 0, "Vp_S_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_S_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_Uc, Vp_S_Uc)
//============================================================================


struct  Vp_S_Ui  {
  void *v1;
  short v2;
  unsigned int v3;
};
//SIG(1 Vp_S_Ui) C1{ Fp Fs Fi}



static void Test_Vp_S_Ui()
{
  {
    init_simple_test("Vp_S_Ui");
    STRUCT_IF_C Vp_S_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_S_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_Ui)");
    check_field_offset(lv, v1, 0, "Vp_S_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_S_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_Ui, Vp_S_Ui)
//============================================================================


struct  Vp_S_Ul  {
  void *v1;
  short v2;
  __tsu64 v3;
};
//SIG(1 Vp_S_Ul) C1{ Fp Fs FL}



static void Test_Vp_S_Ul()
{
  {
    init_simple_test("Vp_S_Ul");
    STRUCT_IF_C Vp_S_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_S_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_Ul)");
    check_field_offset(lv, v1, 0, "Vp_S_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_S_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_Ul, Vp_S_Ul)
//============================================================================


struct  Vp_S_Us  {
  void *v1;
  short v2;
  unsigned short v3;
};
//SIG(1 Vp_S_Us) C1{ Fp Fs[2]}



static void Test_Vp_S_Us()
{
  {
    init_simple_test("Vp_S_Us");
    STRUCT_IF_C Vp_S_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_S_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_Us)");
    check_field_offset(lv, v1, 0, "Vp_S_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_Us.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_S_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_Us, Vp_S_Us)
//============================================================================


struct  Vp_S_Vp  {
  void *v1;
  short v2;
  void *v3;
};
//SIG(1 Vp_S_Vp) C1{ Fp Fs Fp}



static void Test_Vp_S_Vp()
{
  {
    init_simple_test("Vp_S_Vp");
    STRUCT_IF_C Vp_S_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_S_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_S_Vp)");
    check_field_offset(lv, v1, 0, "Vp_S_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_S_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_S_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_S_Vp, Vp_S_Vp)
//============================================================================


struct  Vp_Uc  {
  void *v1;
  unsigned char v2;
};
//SIG(1 Vp_Uc) C1{ Fp Fc}



static void Test_Vp_Uc()
{
  {
    init_simple_test("Vp_Uc");
    STRUCT_IF_C Vp_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc)");
    check_field_offset(lv, v1, 0, "Vp_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc, Vp_Uc)
//============================================================================


struct  Vp_Uc_BFu15i  {
  void *v1;
  unsigned char v2;
  unsigned int v3:15;
};
//SIG(1 Vp_Uc_BFu15i) C1{ Fp Fc Fi:15}



static void Test_Vp_Uc_BFu15i()
{
  {
    init_simple_test("Vp_Uc_BFu15i");
    static STRUCT_IF_C Vp_Uc_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_Uc_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_Uc_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu15i, Vp_Uc_BFu15i)
//============================================================================


struct  Vp_Uc_BFu15ll  {
  void *v1;
  unsigned char v2;
  __tsu64 v3:15;
};
//SIG(1 Vp_Uc_BFu15ll) C1{ Fp Fc FL:15}



static void Test_Vp_Uc_BFu15ll()
{
  {
    init_simple_test("Vp_Uc_BFu15ll");
    static STRUCT_IF_C Vp_Uc_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, 1, "Vp_Uc_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 15, hide_ull(1LL<<14), "Vp_Uc_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu15ll, Vp_Uc_BFu15ll)
//============================================================================


struct  Vp_Uc_BFu15s  {
  void *v1;
  unsigned char v2;
  unsigned short v3:15;
};
//SIG(1 Vp_Uc_BFu15s) C1{ Fp Fc Fs:15}



static void Test_Vp_Uc_BFu15s()
{
  {
    init_simple_test("Vp_Uc_BFu15s");
    static STRUCT_IF_C Vp_Uc_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_Uc_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_Uc_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu15s, Vp_Uc_BFu15s)
//============================================================================


struct  Vp_Uc_BFu16i  {
  void *v1;
  unsigned char v2;
  unsigned int v3:16;
};
//SIG(1 Vp_Uc_BFu16i) C1{ Fp Fc Fi:16}



static void Test_Vp_Uc_BFu16i()
{
  {
    init_simple_test("Vp_Uc_BFu16i");
    static STRUCT_IF_C Vp_Uc_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_Uc_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_Uc_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu16i, Vp_Uc_BFu16i)
//============================================================================


struct  Vp_Uc_BFu16ll  {
  void *v1;
  unsigned char v2;
  __tsu64 v3:16;
};
//SIG(1 Vp_Uc_BFu16ll) C1{ Fp Fc FL:16}



static void Test_Vp_Uc_BFu16ll()
{
  {
    init_simple_test("Vp_Uc_BFu16ll");
    static STRUCT_IF_C Vp_Uc_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, 1, "Vp_Uc_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 16, hide_ull(1LL<<15), "Vp_Uc_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu16ll, Vp_Uc_BFu16ll)
//============================================================================


struct  Vp_Uc_BFu16s  {
  void *v1;
  unsigned char v2;
  unsigned short v3:16;
};
//SIG(1 Vp_Uc_BFu16s) C1{ Fp Fc Fs:16}



static void Test_Vp_Uc_BFu16s()
{
  {
    init_simple_test("Vp_Uc_BFu16s");
    static STRUCT_IF_C Vp_Uc_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_Uc_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_Uc_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu16s, Vp_Uc_BFu16s)
//============================================================================


struct  Vp_Uc_BFu17i  {
  void *v1;
  unsigned char v2;
  unsigned int v3:17;
};
//SIG(1 Vp_Uc_BFu17i) C1{ Fp Fc Fi:17}



static void Test_Vp_Uc_BFu17i()
{
  {
    init_simple_test("Vp_Uc_BFu17i");
    static STRUCT_IF_C Vp_Uc_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_Uc_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_Uc_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu17i, Vp_Uc_BFu17i)
//============================================================================


struct  Vp_Uc_BFu17ll  {
  void *v1;
  unsigned char v2;
  __tsu64 v3:17;
};
//SIG(1 Vp_Uc_BFu17ll) C1{ Fp Fc FL:17}



static void Test_Vp_Uc_BFu17ll()
{
  {
    init_simple_test("Vp_Uc_BFu17ll");
    static STRUCT_IF_C Vp_Uc_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, 1, "Vp_Uc_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 17, hide_ull(1LL<<16), "Vp_Uc_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu17ll, Vp_Uc_BFu17ll)
//============================================================================


struct  Vp_Uc_BFu1c  {
  void *v1;
  unsigned char v2;
  unsigned char v3:1;
};
//SIG(1 Vp_Uc_BFu1c) C1{ Fp Fc Fc:1}



static void Test_Vp_Uc_BFu1c()
{
  {
    init_simple_test("Vp_Uc_BFu1c");
    static STRUCT_IF_C Vp_Uc_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_Uc_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu1c, Vp_Uc_BFu1c)
//============================================================================


struct  Vp_Uc_BFu1i  {
  void *v1;
  unsigned char v2;
  unsigned int v3:1;
};
//SIG(1 Vp_Uc_BFu1i) C1{ Fp Fc Fi:1}



static void Test_Vp_Uc_BFu1i()
{
  {
    init_simple_test("Vp_Uc_BFu1i");
    static STRUCT_IF_C Vp_Uc_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_Uc_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu1i, Vp_Uc_BFu1i)
//============================================================================


struct  Vp_Uc_BFu1ll  {
  void *v1;
  unsigned char v2;
  __tsu64 v3:1;
};
//SIG(1 Vp_Uc_BFu1ll) C1{ Fp Fc FL:1}



static void Test_Vp_Uc_BFu1ll()
{
  {
    init_simple_test("Vp_Uc_BFu1ll");
    static STRUCT_IF_C Vp_Uc_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_Uc_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu1ll, Vp_Uc_BFu1ll)
//============================================================================


struct  Vp_Uc_BFu1s  {
  void *v1;
  unsigned char v2;
  unsigned short v3:1;
};
//SIG(1 Vp_Uc_BFu1s) C1{ Fp Fc Fs:1}



static void Test_Vp_Uc_BFu1s()
{
  {
    init_simple_test("Vp_Uc_BFu1s");
    static STRUCT_IF_C Vp_Uc_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 1, 1, "Vp_Uc_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu1s, Vp_Uc_BFu1s)
//============================================================================


struct  Vp_Uc_BFu31i  {
  void *v1;
  unsigned char v2;
  unsigned int v3:31;
};
//SIG(1 Vp_Uc_BFu31i) C1{ Fp Fc Fi:31}



static void Test_Vp_Uc_BFu31i()
{
  {
    init_simple_test("Vp_Uc_BFu31i");
    static STRUCT_IF_C Vp_Uc_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Uc_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_Uc_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_Uc_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu31i, Vp_Uc_BFu31i)
//============================================================================


struct  Vp_Uc_BFu31ll  {
  void *v1;
  unsigned char v2;
  __tsu64 v3:31;
};
//SIG(1 Vp_Uc_BFu31ll) C1{ Fp Fc FL:31}



static void Test_Vp_Uc_BFu31ll()
{
  {
    init_simple_test("Vp_Uc_BFu31ll");
    static STRUCT_IF_C Vp_Uc_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Uc_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, 1, "Vp_Uc_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 31, hide_ull(1LL<<30), "Vp_Uc_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu31ll, Vp_Uc_BFu31ll)
//============================================================================


struct  Vp_Uc_BFu32i  {
  void *v1;
  unsigned char v2;
  unsigned int v3:32;
};
//SIG(1 Vp_Uc_BFu32i) C1{ Fp Fc Fi:32}



static void Test_Vp_Uc_BFu32i()
{
  {
    init_simple_test("Vp_Uc_BFu32i");
    static STRUCT_IF_C Vp_Uc_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Uc_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_Uc_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_Uc_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu32i, Vp_Uc_BFu32i)
//============================================================================


struct  Vp_Uc_BFu32ll  {
  void *v1;
  unsigned char v2;
  __tsu64 v3:32;
};
//SIG(1 Vp_Uc_BFu32ll) C1{ Fp Fc FL:32}



static void Test_Vp_Uc_BFu32ll()
{
  {
    init_simple_test("Vp_Uc_BFu32ll");
    static STRUCT_IF_C Vp_Uc_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Uc_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, 1, "Vp_Uc_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 32, hide_ull(1LL<<31), "Vp_Uc_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu32ll, Vp_Uc_BFu32ll)
//============================================================================


struct  Vp_Uc_BFu33  {
  void *v1;
  unsigned char v2;
  __tsu64 v3:33;
};
//SIG(1 Vp_Uc_BFu33) C1{ Fp Fc FL:33}



static void Test_Vp_Uc_BFu33()
{
  {
    init_simple_test("Vp_Uc_BFu33");
    static STRUCT_IF_C Vp_Uc_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Uc_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, 1, "Vp_Uc_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 33, hide_ull(1LL<<32), "Vp_Uc_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu33, Vp_Uc_BFu33)
//============================================================================


struct  Vp_Uc_BFu7c  {
  void *v1;
  unsigned char v2;
  unsigned char v3:7;
};
//SIG(1 Vp_Uc_BFu7c) C1{ Fp Fc Fc:7}



static void Test_Vp_Uc_BFu7c()
{
  {
    init_simple_test("Vp_Uc_BFu7c");
    static STRUCT_IF_C Vp_Uc_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_Uc_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_Uc_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu7c, Vp_Uc_BFu7c)
//============================================================================


struct  Vp_Uc_BFu7i  {
  void *v1;
  unsigned char v2;
  unsigned int v3:7;
};
//SIG(1 Vp_Uc_BFu7i) C1{ Fp Fc Fi:7}



static void Test_Vp_Uc_BFu7i()
{
  {
    init_simple_test("Vp_Uc_BFu7i");
    static STRUCT_IF_C Vp_Uc_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_Uc_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_Uc_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu7i, Vp_Uc_BFu7i)
//============================================================================


struct  Vp_Uc_BFu7ll  {
  void *v1;
  unsigned char v2;
  __tsu64 v3:7;
};
//SIG(1 Vp_Uc_BFu7ll) C1{ Fp Fc FL:7}



static void Test_Vp_Uc_BFu7ll()
{
  {
    init_simple_test("Vp_Uc_BFu7ll");
    static STRUCT_IF_C Vp_Uc_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_Uc_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_Uc_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu7ll, Vp_Uc_BFu7ll)
//============================================================================


struct  Vp_Uc_BFu7s  {
  void *v1;
  unsigned char v2;
  unsigned short v3:7;
};
//SIG(1 Vp_Uc_BFu7s) C1{ Fp Fc Fs:7}



static void Test_Vp_Uc_BFu7s()
{
  {
    init_simple_test("Vp_Uc_BFu7s");
    static STRUCT_IF_C Vp_Uc_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, 1, "Vp_Uc_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 7, hide_ull(1LL<<6), "Vp_Uc_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu7s, Vp_Uc_BFu7s)
//============================================================================


struct  Vp_Uc_BFu8c  {
  void *v1;
  unsigned char v2;
  unsigned char v3:8;
};
//SIG(1 Vp_Uc_BFu8c) C1{ Fp Fc Fc:8}



static void Test_Vp_Uc_BFu8c()
{
  {
    init_simple_test("Vp_Uc_BFu8c");
    static STRUCT_IF_C Vp_Uc_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_Uc_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_Uc_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu8c, Vp_Uc_BFu8c)
//============================================================================


struct  Vp_Uc_BFu8i  {
  void *v1;
  unsigned char v2;
  unsigned int v3:8;
};
//SIG(1 Vp_Uc_BFu8i) C1{ Fp Fc Fi:8}



static void Test_Vp_Uc_BFu8i()
{
  {
    init_simple_test("Vp_Uc_BFu8i");
    static STRUCT_IF_C Vp_Uc_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_Uc_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_Uc_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu8i, Vp_Uc_BFu8i)
//============================================================================


struct  Vp_Uc_BFu8ll  {
  void *v1;
  unsigned char v2;
  __tsu64 v3:8;
};
//SIG(1 Vp_Uc_BFu8ll) C1{ Fp Fc FL:8}



static void Test_Vp_Uc_BFu8ll()
{
  {
    init_simple_test("Vp_Uc_BFu8ll");
    static STRUCT_IF_C Vp_Uc_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_Uc_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_Uc_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu8ll, Vp_Uc_BFu8ll)
//============================================================================


struct  Vp_Uc_BFu8s  {
  void *v1;
  unsigned char v2;
  unsigned short v3:8;
};
//SIG(1 Vp_Uc_BFu8s) C1{ Fp Fc Fs:8}



static void Test_Vp_Uc_BFu8s()
{
  {
    init_simple_test("Vp_Uc_BFu8s");
    static STRUCT_IF_C Vp_Uc_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, 1, "Vp_Uc_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 8, hide_ull(1LL<<7), "Vp_Uc_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu8s, Vp_Uc_BFu8s)
//============================================================================


struct  Vp_Uc_BFu9i  {
  void *v1;
  unsigned char v2;
  unsigned int v3:9;
};
//SIG(1 Vp_Uc_BFu9i) C1{ Fp Fc Fi:9}



static void Test_Vp_Uc_BFu9i()
{
  {
    init_simple_test("Vp_Uc_BFu9i");
    static STRUCT_IF_C Vp_Uc_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_Uc_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_Uc_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu9i, Vp_Uc_BFu9i)
//============================================================================


struct  Vp_Uc_BFu9ll  {
  void *v1;
  unsigned char v2;
  __tsu64 v3:9;
};
//SIG(1 Vp_Uc_BFu9ll) C1{ Fp Fc FL:9}



static void Test_Vp_Uc_BFu9ll()
{
  {
    init_simple_test("Vp_Uc_BFu9ll");
    static STRUCT_IF_C Vp_Uc_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, 1, "Vp_Uc_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(9,5), 0, 9, hide_ull(1LL<<8), "Vp_Uc_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu9ll, Vp_Uc_BFu9ll)
//============================================================================


struct  Vp_Uc_BFu9s  {
  void *v1;
  unsigned char v2;
  unsigned short v3:9;
};
//SIG(1 Vp_Uc_BFu9s) C1{ Fp Fc Fs:9}



static void Test_Vp_Uc_BFu9s()
{
  {
    init_simple_test("Vp_Uc_BFu9s");
    static STRUCT_IF_C Vp_Uc_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_Uc_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_Uc_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_Uc_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_BFu9s, Vp_Uc_BFu9s)
//============================================================================


struct  Vp_Uc_C  {
  void *v1;
  unsigned char v2;
  char v3;
};
//SIG(1 Vp_Uc_C) C1{ Fp Fc[2]}



static void Test_Vp_Uc_C()
{
  {
    init_simple_test("Vp_Uc_C");
    STRUCT_IF_C Vp_Uc_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_C)");
    check_field_offset(lv, v1, 0, "Vp_Uc_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_C.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_Uc_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_C, Vp_Uc_C)
//============================================================================


struct  Vp_Uc_D  {
  void *v1;
  unsigned char v2;
  double v3;
};
//SIG(1 Vp_Uc_D) C1{ Fp Fc FL}



static void Test_Vp_Uc_D()
{
  {
    init_simple_test("Vp_Uc_D");
    STRUCT_IF_C Vp_Uc_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Uc_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_D)");
    check_field_offset(lv, v1, 0, "Vp_Uc_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_D.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Uc_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_D, Vp_Uc_D)
//============================================================================


struct  Vp_Uc_F  {
  void *v1;
  unsigned char v2;
  float v3;
};
//SIG(1 Vp_Uc_F) C1{ Fp Fc Fi}



static void Test_Vp_Uc_F()
{
  {
    init_simple_test("Vp_Uc_F");
    STRUCT_IF_C Vp_Uc_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Uc_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_F)");
    check_field_offset(lv, v1, 0, "Vp_Uc_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_F.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Uc_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_F, Vp_Uc_F)
//============================================================================


struct  Vp_Uc_I  {
  void *v1;
  unsigned char v2;
  int v3;
};
//SIG(1 Vp_Uc_I) C1{ Fp Fc Fi}



static void Test_Vp_Uc_I()
{
  {
    init_simple_test("Vp_Uc_I");
    STRUCT_IF_C Vp_Uc_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Uc_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_I)");
    check_field_offset(lv, v1, 0, "Vp_Uc_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_I.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Uc_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_I, Vp_Uc_I)
//============================================================================


struct  Vp_Uc_Ip  {
  void *v1;
  unsigned char v2;
  int *v3;
};
//SIG(1 Vp_Uc_Ip) C1{ Fp Fc Fp}



static void Test_Vp_Uc_Ip()
{
  {
    init_simple_test("Vp_Uc_Ip");
    STRUCT_IF_C Vp_Uc_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Uc_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_Ip)");
    check_field_offset(lv, v1, 0, "Vp_Uc_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Uc_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_Ip, Vp_Uc_Ip)
//============================================================================


struct  Vp_Uc_L  {
  void *v1;
  unsigned char v2;
  __tsi64 v3;
};
//SIG(1 Vp_Uc_L) C1{ Fp Fc FL}



static void Test_Vp_Uc_L()
{
  {
    init_simple_test("Vp_Uc_L");
    STRUCT_IF_C Vp_Uc_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Uc_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_L)");
    check_field_offset(lv, v1, 0, "Vp_Uc_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_L.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Uc_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_L, Vp_Uc_L)
//============================================================================


struct  Vp_Uc_S  {
  void *v1;
  unsigned char v2;
  short v3;
};
//SIG(1 Vp_Uc_S) C1{ Fp Fc Fs}



static void Test_Vp_Uc_S()
{
  {
    init_simple_test("Vp_Uc_S");
    STRUCT_IF_C Vp_Uc_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_S)");
    check_field_offset(lv, v1, 0, "Vp_Uc_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_S.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_Uc_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_S, Vp_Uc_S)
//============================================================================


struct  Vp_Uc_Uc  {
  void *v1;
  unsigned char v2;
  unsigned char v3;
};
//SIG(1 Vp_Uc_Uc) C1{ Fp Fc[2]}



static void Test_Vp_Uc_Uc()
{
  {
    init_simple_test("Vp_Uc_Uc");
    STRUCT_IF_C Vp_Uc_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_Uc)");
    check_field_offset(lv, v1, 0, "Vp_Uc_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(9,5), "Vp_Uc_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_Uc, Vp_Uc_Uc)
//============================================================================


struct  Vp_Uc_Ui  {
  void *v1;
  unsigned char v2;
  unsigned int v3;
};
//SIG(1 Vp_Uc_Ui) C1{ Fp Fc Fi}



static void Test_Vp_Uc_Ui()
{
  {
    init_simple_test("Vp_Uc_Ui");
    STRUCT_IF_C Vp_Uc_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Uc_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_Ui)");
    check_field_offset(lv, v1, 0, "Vp_Uc_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Uc_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_Ui, Vp_Uc_Ui)
//============================================================================


struct  Vp_Uc_Ul  {
  void *v1;
  unsigned char v2;
  __tsu64 v3;
};
//SIG(1 Vp_Uc_Ul) C1{ Fp Fc FL}



static void Test_Vp_Uc_Ul()
{
  {
    init_simple_test("Vp_Uc_Ul");
    STRUCT_IF_C Vp_Uc_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Uc_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_Ul)");
    check_field_offset(lv, v1, 0, "Vp_Uc_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Uc_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_Ul, Vp_Uc_Ul)
//============================================================================


struct  Vp_Uc_Us  {
  void *v1;
  unsigned char v2;
  unsigned short v3;
};
//SIG(1 Vp_Uc_Us) C1{ Fp Fc Fs}



static void Test_Vp_Uc_Us()
{
  {
    init_simple_test("Vp_Uc_Us");
    STRUCT_IF_C Vp_Uc_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Uc_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_Us)");
    check_field_offset(lv, v1, 0, "Vp_Uc_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_Us.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_Uc_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_Us, Vp_Uc_Us)
//============================================================================


struct  Vp_Uc_Vp  {
  void *v1;
  unsigned char v2;
  void *v3;
};
//SIG(1 Vp_Uc_Vp) C1{ Fp Fc Fp}



static void Test_Vp_Uc_Vp()
{
  {
    init_simple_test("Vp_Uc_Vp");
    STRUCT_IF_C Vp_Uc_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Uc_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Uc_Vp)");
    check_field_offset(lv, v1, 0, "Vp_Uc_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Uc_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Uc_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Uc_Vp, Vp_Uc_Vp)
//============================================================================


struct  Vp_Ui  {
  void *v1;
  unsigned int v2;
};
//SIG(1 Vp_Ui) C1{ Fp Fi}



static void Test_Vp_Ui()
{
  {
    init_simple_test("Vp_Ui");
    STRUCT_IF_C Vp_Ui lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui)");
    check_field_offset(lv, v1, 0, "Vp_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui, Vp_Ui)
//============================================================================


struct  Vp_Ui_BFu15i  {
  void *v1;
  unsigned int v2;
  unsigned int v3:15;
};
//SIG(1 Vp_Ui_BFu15i) C1{ Fp Fi Fi:15}



static void Test_Vp_Ui_BFu15i()
{
  {
    init_simple_test("Vp_Ui_BFu15i");
    static STRUCT_IF_C Vp_Ui_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, 1, "Vp_Ui_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, hide_ull(1LL<<14), "Vp_Ui_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu15i, Vp_Ui_BFu15i)
//============================================================================


struct  Vp_Ui_BFu15ll  {
  void *v1;
  unsigned int v2;
  __tsu64 v3:15;
};
//SIG(1 Vp_Ui_BFu15ll) C1{ Fp Fi FL:15}



static void Test_Vp_Ui_BFu15ll()
{
  {
    init_simple_test("Vp_Ui_BFu15ll");
    static STRUCT_IF_C Vp_Ui_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, 1, "Vp_Ui_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, hide_ull(1LL<<14), "Vp_Ui_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu15ll, Vp_Ui_BFu15ll)
//============================================================================


struct  Vp_Ui_BFu15s  {
  void *v1;
  unsigned int v2;
  unsigned short v3:15;
};
//SIG(1 Vp_Ui_BFu15s) C1{ Fp Fi Fs:15}



static void Test_Vp_Ui_BFu15s()
{
  {
    init_simple_test("Vp_Ui_BFu15s");
    static STRUCT_IF_C Vp_Ui_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, 1, "Vp_Ui_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 15, hide_ull(1LL<<14), "Vp_Ui_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu15s, Vp_Ui_BFu15s)
//============================================================================


struct  Vp_Ui_BFu16i  {
  void *v1;
  unsigned int v2;
  unsigned int v3:16;
};
//SIG(1 Vp_Ui_BFu16i) C1{ Fp Fi Fi:16}



static void Test_Vp_Ui_BFu16i()
{
  {
    init_simple_test("Vp_Ui_BFu16i");
    static STRUCT_IF_C Vp_Ui_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, 1, "Vp_Ui_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, hide_ull(1LL<<15), "Vp_Ui_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu16i, Vp_Ui_BFu16i)
//============================================================================


struct  Vp_Ui_BFu16ll  {
  void *v1;
  unsigned int v2;
  __tsu64 v3:16;
};
//SIG(1 Vp_Ui_BFu16ll) C1{ Fp Fi FL:16}



static void Test_Vp_Ui_BFu16ll()
{
  {
    init_simple_test("Vp_Ui_BFu16ll");
    static STRUCT_IF_C Vp_Ui_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, 1, "Vp_Ui_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, hide_ull(1LL<<15), "Vp_Ui_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu16ll, Vp_Ui_BFu16ll)
//============================================================================


struct  Vp_Ui_BFu16s  {
  void *v1;
  unsigned int v2;
  unsigned short v3:16;
};
//SIG(1 Vp_Ui_BFu16s) C1{ Fp Fi Fs:16}



static void Test_Vp_Ui_BFu16s()
{
  {
    init_simple_test("Vp_Ui_BFu16s");
    static STRUCT_IF_C Vp_Ui_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, 1, "Vp_Ui_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 16, hide_ull(1LL<<15), "Vp_Ui_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu16s, Vp_Ui_BFu16s)
//============================================================================


struct  Vp_Ui_BFu17i  {
  void *v1;
  unsigned int v2;
  unsigned int v3:17;
};
//SIG(1 Vp_Ui_BFu17i) C1{ Fp Fi Fi:17}



static void Test_Vp_Ui_BFu17i()
{
  {
    init_simple_test("Vp_Ui_BFu17i");
    static STRUCT_IF_C Vp_Ui_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, 1, "Vp_Ui_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, hide_ull(1LL<<16), "Vp_Ui_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu17i, Vp_Ui_BFu17i)
//============================================================================


struct  Vp_Ui_BFu17ll  {
  void *v1;
  unsigned int v2;
  __tsu64 v3:17;
};
//SIG(1 Vp_Ui_BFu17ll) C1{ Fp Fi FL:17}



static void Test_Vp_Ui_BFu17ll()
{
  {
    init_simple_test("Vp_Ui_BFu17ll");
    static STRUCT_IF_C Vp_Ui_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, 1, "Vp_Ui_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, hide_ull(1LL<<16), "Vp_Ui_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu17ll, Vp_Ui_BFu17ll)
//============================================================================


struct  Vp_Ui_BFu1c  {
  void *v1;
  unsigned int v2;
  unsigned char v3:1;
};
//SIG(1 Vp_Ui_BFu1c) C1{ Fp Fi Fc:1}



static void Test_Vp_Ui_BFu1c()
{
  {
    init_simple_test("Vp_Ui_BFu1c");
    static STRUCT_IF_C Vp_Ui_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 1, 1, "Vp_Ui_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu1c, Vp_Ui_BFu1c)
//============================================================================


struct  Vp_Ui_BFu1i  {
  void *v1;
  unsigned int v2;
  unsigned int v3:1;
};
//SIG(1 Vp_Ui_BFu1i) C1{ Fp Fi Fi:1}



static void Test_Vp_Ui_BFu1i()
{
  {
    init_simple_test("Vp_Ui_BFu1i");
    static STRUCT_IF_C Vp_Ui_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 1, 1, "Vp_Ui_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu1i, Vp_Ui_BFu1i)
//============================================================================


struct  Vp_Ui_BFu1ll  {
  void *v1;
  unsigned int v2;
  __tsu64 v3:1;
};
//SIG(1 Vp_Ui_BFu1ll) C1{ Fp Fi FL:1}



static void Test_Vp_Ui_BFu1ll()
{
  {
    init_simple_test("Vp_Ui_BFu1ll");
    static STRUCT_IF_C Vp_Ui_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 1, 1, "Vp_Ui_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu1ll, Vp_Ui_BFu1ll)
//============================================================================


struct  Vp_Ui_BFu1s  {
  void *v1;
  unsigned int v2;
  unsigned short v3:1;
};
//SIG(1 Vp_Ui_BFu1s) C1{ Fp Fi Fs:1}



static void Test_Vp_Ui_BFu1s()
{
  {
    init_simple_test("Vp_Ui_BFu1s");
    static STRUCT_IF_C Vp_Ui_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 1, 1, "Vp_Ui_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu1s, Vp_Ui_BFu1s)
//============================================================================


struct  Vp_Ui_BFu31i  {
  void *v1;
  unsigned int v2;
  unsigned int v3:31;
};
//SIG(1 Vp_Ui_BFu31i) C1{ Fp Fi Fi:31}



static void Test_Vp_Ui_BFu31i()
{
  {
    init_simple_test("Vp_Ui_BFu31i");
    static STRUCT_IF_C Vp_Ui_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_Ui_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_Ui_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu31i, Vp_Ui_BFu31i)
//============================================================================


struct  Vp_Ui_BFu31ll  {
  void *v1;
  unsigned int v2;
  __tsu64 v3:31;
};
//SIG(1 Vp_Ui_BFu31ll) C1{ Fp Fi FL:31}



static void Test_Vp_Ui_BFu31ll()
{
  {
    init_simple_test("Vp_Ui_BFu31ll");
    static STRUCT_IF_C Vp_Ui_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_Ui_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_Ui_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu31ll, Vp_Ui_BFu31ll)
//============================================================================


struct  Vp_Ui_BFu32i  {
  void *v1;
  unsigned int v2;
  unsigned int v3:32;
};
//SIG(1 Vp_Ui_BFu32i) C1{ Fp Fi Fi:32}



static void Test_Vp_Ui_BFu32i()
{
  {
    init_simple_test("Vp_Ui_BFu32i");
    static STRUCT_IF_C Vp_Ui_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_Ui_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_Ui_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu32i, Vp_Ui_BFu32i)
//============================================================================


struct  Vp_Ui_BFu32ll  {
  void *v1;
  unsigned int v2;
  __tsu64 v3:32;
};
//SIG(1 Vp_Ui_BFu32ll) C1{ Fp Fi FL:32}



static void Test_Vp_Ui_BFu32ll()
{
  {
    init_simple_test("Vp_Ui_BFu32ll");
    static STRUCT_IF_C Vp_Ui_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_Ui_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_Ui_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu32ll, Vp_Ui_BFu32ll)
//============================================================================


struct  Vp_Ui_BFu33  {
  void *v1;
  unsigned int v2;
  __tsu64 v3:33;
};
//SIG(1 Vp_Ui_BFu33) C1{ Fp Fi FL:33}



static void Test_Vp_Ui_BFu33()
{
  {
    init_simple_test("Vp_Ui_BFu33");
    static STRUCT_IF_C Vp_Ui_BFu33 lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ui_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 33, 1, "Vp_Ui_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 33, hide_ull(1LL<<32), "Vp_Ui_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu33, Vp_Ui_BFu33)
//============================================================================


struct  Vp_Ui_BFu7c  {
  void *v1;
  unsigned int v2;
  unsigned char v3:7;
};
//SIG(1 Vp_Ui_BFu7c) C1{ Fp Fi Fc:7}



static void Test_Vp_Ui_BFu7c()
{
  {
    init_simple_test("Vp_Ui_BFu7c");
    static STRUCT_IF_C Vp_Ui_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_Ui_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_Ui_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu7c, Vp_Ui_BFu7c)
//============================================================================


struct  Vp_Ui_BFu7i  {
  void *v1;
  unsigned int v2;
  unsigned int v3:7;
};
//SIG(1 Vp_Ui_BFu7i) C1{ Fp Fi Fi:7}



static void Test_Vp_Ui_BFu7i()
{
  {
    init_simple_test("Vp_Ui_BFu7i");
    static STRUCT_IF_C Vp_Ui_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_Ui_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_Ui_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu7i, Vp_Ui_BFu7i)
//============================================================================


struct  Vp_Ui_BFu7ll  {
  void *v1;
  unsigned int v2;
  __tsu64 v3:7;
};
//SIG(1 Vp_Ui_BFu7ll) C1{ Fp Fi FL:7}



static void Test_Vp_Ui_BFu7ll()
{
  {
    init_simple_test("Vp_Ui_BFu7ll");
    static STRUCT_IF_C Vp_Ui_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_Ui_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_Ui_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu7ll, Vp_Ui_BFu7ll)
//============================================================================


struct  Vp_Ui_BFu7s  {
  void *v1;
  unsigned int v2;
  unsigned short v3:7;
};
//SIG(1 Vp_Ui_BFu7s) C1{ Fp Fi Fs:7}



static void Test_Vp_Ui_BFu7s()
{
  {
    init_simple_test("Vp_Ui_BFu7s");
    static STRUCT_IF_C Vp_Ui_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, 1, "Vp_Ui_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 7, hide_ull(1LL<<6), "Vp_Ui_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu7s, Vp_Ui_BFu7s)
//============================================================================


struct  Vp_Ui_BFu8c  {
  void *v1;
  unsigned int v2;
  unsigned char v3:8;
};
//SIG(1 Vp_Ui_BFu8c) C1{ Fp Fi Fc:8}



static void Test_Vp_Ui_BFu8c()
{
  {
    init_simple_test("Vp_Ui_BFu8c");
    static STRUCT_IF_C Vp_Ui_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_Ui_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_Ui_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu8c, Vp_Ui_BFu8c)
//============================================================================


struct  Vp_Ui_BFu8i  {
  void *v1;
  unsigned int v2;
  unsigned int v3:8;
};
//SIG(1 Vp_Ui_BFu8i) C1{ Fp Fi Fi:8}



static void Test_Vp_Ui_BFu8i()
{
  {
    init_simple_test("Vp_Ui_BFu8i");
    static STRUCT_IF_C Vp_Ui_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_Ui_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_Ui_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu8i, Vp_Ui_BFu8i)
//============================================================================


struct  Vp_Ui_BFu8ll  {
  void *v1;
  unsigned int v2;
  __tsu64 v3:8;
};
//SIG(1 Vp_Ui_BFu8ll) C1{ Fp Fi FL:8}



static void Test_Vp_Ui_BFu8ll()
{
  {
    init_simple_test("Vp_Ui_BFu8ll");
    static STRUCT_IF_C Vp_Ui_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_Ui_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_Ui_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu8ll, Vp_Ui_BFu8ll)
//============================================================================


struct  Vp_Ui_BFu8s  {
  void *v1;
  unsigned int v2;
  unsigned short v3:8;
};
//SIG(1 Vp_Ui_BFu8s) C1{ Fp Fi Fs:8}



static void Test_Vp_Ui_BFu8s()
{
  {
    init_simple_test("Vp_Ui_BFu8s");
    static STRUCT_IF_C Vp_Ui_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, 1, "Vp_Ui_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 8, hide_ull(1LL<<7), "Vp_Ui_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu8s, Vp_Ui_BFu8s)
//============================================================================


struct  Vp_Ui_BFu9i  {
  void *v1;
  unsigned int v2;
  unsigned int v3:9;
};
//SIG(1 Vp_Ui_BFu9i) C1{ Fp Fi Fi:9}



static void Test_Vp_Ui_BFu9i()
{
  {
    init_simple_test("Vp_Ui_BFu9i");
    static STRUCT_IF_C Vp_Ui_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, 1, "Vp_Ui_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, hide_ull(1LL<<8), "Vp_Ui_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu9i, Vp_Ui_BFu9i)
//============================================================================


struct  Vp_Ui_BFu9ll  {
  void *v1;
  unsigned int v2;
  __tsu64 v3:9;
};
//SIG(1 Vp_Ui_BFu9ll) C1{ Fp Fi FL:9}



static void Test_Vp_Ui_BFu9ll()
{
  {
    init_simple_test("Vp_Ui_BFu9ll");
    static STRUCT_IF_C Vp_Ui_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, 1, "Vp_Ui_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, hide_ull(1LL<<8), "Vp_Ui_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu9ll, Vp_Ui_BFu9ll)
//============================================================================


struct  Vp_Ui_BFu9s  {
  void *v1;
  unsigned int v2;
  unsigned short v3:9;
};
//SIG(1 Vp_Ui_BFu9s) C1{ Fp Fi Fs:9}



static void Test_Vp_Ui_BFu9s()
{
  {
    init_simple_test("Vp_Ui_BFu9s");
    static STRUCT_IF_C Vp_Ui_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_Ui_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, 1, "Vp_Ui_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 9, hide_ull(1LL<<8), "Vp_Ui_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_BFu9s, Vp_Ui_BFu9s)
//============================================================================


struct  Vp_Ui_C  {
  void *v1;
  unsigned int v2;
  char v3;
};
//SIG(1 Vp_Ui_C) C1{ Fp Fi Fc}



static void Test_Vp_Ui_C()
{
  {
    init_simple_test("Vp_Ui_C");
    STRUCT_IF_C Vp_Ui_C lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_C)");
    check_field_offset(lv, v1, 0, "Vp_Ui_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_C.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Ui_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_C, Vp_Ui_C)
//============================================================================


struct  Vp_Ui_D  {
  void *v1;
  unsigned int v2;
  double v3;
};
//SIG(1 Vp_Ui_D) C1{ Fp Fi FL}



static void Test_Vp_Ui_D()
{
  {
    init_simple_test("Vp_Ui_D");
    STRUCT_IF_C Vp_Ui_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ui_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_D)");
    check_field_offset(lv, v1, 0, "Vp_Ui_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_D.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ui_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_D, Vp_Ui_D)
//============================================================================


struct  Vp_Ui_F  {
  void *v1;
  unsigned int v2;
  float v3;
};
//SIG(1 Vp_Ui_F) C1{ Fp Fi[2]}



static void Test_Vp_Ui_F()
{
  {
    init_simple_test("Vp_Ui_F");
    STRUCT_IF_C Vp_Ui_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_F)");
    check_field_offset(lv, v1, 0, "Vp_Ui_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_F.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Ui_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_F, Vp_Ui_F)
//============================================================================


struct  Vp_Ui_I  {
  void *v1;
  unsigned int v2;
  int v3;
};
//SIG(1 Vp_Ui_I) C1{ Fp Fi[2]}



static void Test_Vp_Ui_I()
{
  {
    init_simple_test("Vp_Ui_I");
    STRUCT_IF_C Vp_Ui_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_I)");
    check_field_offset(lv, v1, 0, "Vp_Ui_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_I.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Ui_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_I, Vp_Ui_I)
//============================================================================


struct  Vp_Ui_Ip  {
  void *v1;
  unsigned int v2;
  int *v3;
};
//SIG(1 Vp_Ui_Ip) C1{ Fp Fi Fp}



static void Test_Vp_Ui_Ip()
{
  {
    init_simple_test("Vp_Ui_Ip");
    STRUCT_IF_C Vp_Ui_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ui_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_Ip)");
    check_field_offset(lv, v1, 0, "Vp_Ui_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ui_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_Ip, Vp_Ui_Ip)
//============================================================================


struct  Vp_Ui_L  {
  void *v1;
  unsigned int v2;
  __tsi64 v3;
};
//SIG(1 Vp_Ui_L) C1{ Fp Fi FL}



static void Test_Vp_Ui_L()
{
  {
    init_simple_test("Vp_Ui_L");
    STRUCT_IF_C Vp_Ui_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ui_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_L)");
    check_field_offset(lv, v1, 0, "Vp_Ui_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_L.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ui_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_L, Vp_Ui_L)
//============================================================================


struct  Vp_Ui_S  {
  void *v1;
  unsigned int v2;
  short v3;
};
//SIG(1 Vp_Ui_S) C1{ Fp Fi Fs}



static void Test_Vp_Ui_S()
{
  {
    init_simple_test("Vp_Ui_S");
    STRUCT_IF_C Vp_Ui_S lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_S)");
    check_field_offset(lv, v1, 0, "Vp_Ui_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_S.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Ui_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_S, Vp_Ui_S)
//============================================================================


struct  Vp_Ui_Uc  {
  void *v1;
  unsigned int v2;
  unsigned char v3;
};
//SIG(1 Vp_Ui_Uc) C1{ Fp Fi Fc}



static void Test_Vp_Ui_Uc()
{
  {
    init_simple_test("Vp_Ui_Uc");
    STRUCT_IF_C Vp_Ui_Uc lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_Uc)");
    check_field_offset(lv, v1, 0, "Vp_Ui_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Ui_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_Uc, Vp_Ui_Uc)
//============================================================================


struct  Vp_Ui_Ui  {
  void *v1;
  unsigned int v2;
  unsigned int v3;
};
//SIG(1 Vp_Ui_Ui) C1{ Fp Fi[2]}



static void Test_Vp_Ui_Ui()
{
  {
    init_simple_test("Vp_Ui_Ui");
    STRUCT_IF_C Vp_Ui_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_Ui)");
    check_field_offset(lv, v1, 0, "Vp_Ui_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Ui_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_Ui, Vp_Ui_Ui)
//============================================================================


struct  Vp_Ui_Ul  {
  void *v1;
  unsigned int v2;
  __tsu64 v3;
};
//SIG(1 Vp_Ui_Ul) C1{ Fp Fi FL}



static void Test_Vp_Ui_Ul()
{
  {
    init_simple_test("Vp_Ui_Ul");
    STRUCT_IF_C Vp_Ui_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ui_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_Ul)");
    check_field_offset(lv, v1, 0, "Vp_Ui_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ui_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_Ul, Vp_Ui_Ul)
//============================================================================


struct  Vp_Ui_Us  {
  void *v1;
  unsigned int v2;
  unsigned short v3;
};
//SIG(1 Vp_Ui_Us) C1{ Fp Fi Fs}



static void Test_Vp_Ui_Us()
{
  {
    init_simple_test("Vp_Ui_Us");
    STRUCT_IF_C Vp_Ui_Us lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ui_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_Us)");
    check_field_offset(lv, v1, 0, "Vp_Ui_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_Us.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Ui_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_Us, Vp_Ui_Us)
//============================================================================


struct  Vp_Ui_Vp  {
  void *v1;
  unsigned int v2;
  void *v3;
};
//SIG(1 Vp_Ui_Vp) C1{ Fp Fi Fp}



static void Test_Vp_Ui_Vp()
{
  {
    init_simple_test("Vp_Ui_Vp");
    STRUCT_IF_C Vp_Ui_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Ui_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ui_Vp)");
    check_field_offset(lv, v1, 0, "Vp_Ui_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ui_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Ui_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ui_Vp, Vp_Ui_Vp)
//============================================================================


struct  Vp_Ul  {
  void *v1;
  __tsu64 v2;
};
//SIG(1 Vp_Ul) C1{ Fp FL}



static void Test_Vp_Ul()
{
  {
    init_simple_test("Vp_Ul");
    STRUCT_IF_C Vp_Ul lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul)");
    check_field_offset(lv, v1, 0, "Vp_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul, Vp_Ul)
//============================================================================


struct  Vp_Ul_BFu15i  {
  void *v1;
  __tsu64 v2;
  unsigned int v3:15;
};
//SIG(1 Vp_Ul_BFu15i) C1{ Fp FL Fi:15}



static void Test_Vp_Ul_BFu15i()
{
  {
    init_simple_test("Vp_Ul_BFu15i");
    static STRUCT_IF_C Vp_Ul_BFu15i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, 1, "Vp_Ul_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, hide_ull(1LL<<14), "Vp_Ul_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu15i, Vp_Ul_BFu15i)
//============================================================================


struct  Vp_Ul_BFu15ll  {
  void *v1;
  __tsu64 v2;
  __tsu64 v3:15;
};
//SIG(1 Vp_Ul_BFu15ll) C1{ Fp FL FL:15}



static void Test_Vp_Ul_BFu15ll()
{
  {
    init_simple_test("Vp_Ul_BFu15ll");
    static STRUCT_IF_C Vp_Ul_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, 1, "Vp_Ul_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, hide_ull(1LL<<14), "Vp_Ul_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu15ll, Vp_Ul_BFu15ll)
//============================================================================


struct  Vp_Ul_BFu15s  {
  void *v1;
  __tsu64 v2;
  unsigned short v3:15;
};
//SIG(1 Vp_Ul_BFu15s) C1{ Fp FL Fs:15}



static void Test_Vp_Ul_BFu15s()
{
  {
    init_simple_test("Vp_Ul_BFu15s");
    static STRUCT_IF_C Vp_Ul_BFu15s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, 1, "Vp_Ul_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 15, hide_ull(1LL<<14), "Vp_Ul_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu15s, Vp_Ul_BFu15s)
//============================================================================


struct  Vp_Ul_BFu16i  {
  void *v1;
  __tsu64 v2;
  unsigned int v3:16;
};
//SIG(1 Vp_Ul_BFu16i) C1{ Fp FL Fi:16}



static void Test_Vp_Ul_BFu16i()
{
  {
    init_simple_test("Vp_Ul_BFu16i");
    static STRUCT_IF_C Vp_Ul_BFu16i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, 1, "Vp_Ul_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, hide_ull(1LL<<15), "Vp_Ul_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu16i, Vp_Ul_BFu16i)
//============================================================================


struct  Vp_Ul_BFu16ll  {
  void *v1;
  __tsu64 v2;
  __tsu64 v3:16;
};
//SIG(1 Vp_Ul_BFu16ll) C1{ Fp FL FL:16}



static void Test_Vp_Ul_BFu16ll()
{
  {
    init_simple_test("Vp_Ul_BFu16ll");
    static STRUCT_IF_C Vp_Ul_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, 1, "Vp_Ul_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, hide_ull(1LL<<15), "Vp_Ul_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu16ll, Vp_Ul_BFu16ll)
//============================================================================


struct  Vp_Ul_BFu16s  {
  void *v1;
  __tsu64 v2;
  unsigned short v3:16;
};
//SIG(1 Vp_Ul_BFu16s) C1{ Fp FL Fs:16}



static void Test_Vp_Ul_BFu16s()
{
  {
    init_simple_test("Vp_Ul_BFu16s");
    static STRUCT_IF_C Vp_Ul_BFu16s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, 1, "Vp_Ul_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 16, hide_ull(1LL<<15), "Vp_Ul_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu16s, Vp_Ul_BFu16s)
//============================================================================


struct  Vp_Ul_BFu17i  {
  void *v1;
  __tsu64 v2;
  unsigned int v3:17;
};
//SIG(1 Vp_Ul_BFu17i) C1{ Fp FL Fi:17}



static void Test_Vp_Ul_BFu17i()
{
  {
    init_simple_test("Vp_Ul_BFu17i");
    static STRUCT_IF_C Vp_Ul_BFu17i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 17, 1, "Vp_Ul_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 17, hide_ull(1LL<<16), "Vp_Ul_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu17i, Vp_Ul_BFu17i)
//============================================================================


struct  Vp_Ul_BFu17ll  {
  void *v1;
  __tsu64 v2;
  __tsu64 v3:17;
};
//SIG(1 Vp_Ul_BFu17ll) C1{ Fp FL FL:17}



static void Test_Vp_Ul_BFu17ll()
{
  {
    init_simple_test("Vp_Ul_BFu17ll");
    static STRUCT_IF_C Vp_Ul_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 17, 1, "Vp_Ul_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 17, hide_ull(1LL<<16), "Vp_Ul_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu17ll, Vp_Ul_BFu17ll)
//============================================================================


struct  Vp_Ul_BFu1c  {
  void *v1;
  __tsu64 v2;
  unsigned char v3:1;
};
//SIG(1 Vp_Ul_BFu1c) C1{ Fp FL Fc:1}



static void Test_Vp_Ul_BFu1c()
{
  {
    init_simple_test("Vp_Ul_BFu1c");
    static STRUCT_IF_C Vp_Ul_BFu1c lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 1, 1, "Vp_Ul_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu1c, Vp_Ul_BFu1c)
//============================================================================


struct  Vp_Ul_BFu1i  {
  void *v1;
  __tsu64 v2;
  unsigned int v3:1;
};
//SIG(1 Vp_Ul_BFu1i) C1{ Fp FL Fi:1}



static void Test_Vp_Ul_BFu1i()
{
  {
    init_simple_test("Vp_Ul_BFu1i");
    static STRUCT_IF_C Vp_Ul_BFu1i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 1, 1, "Vp_Ul_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu1i, Vp_Ul_BFu1i)
//============================================================================


struct  Vp_Ul_BFu1ll  {
  void *v1;
  __tsu64 v2;
  __tsu64 v3:1;
};
//SIG(1 Vp_Ul_BFu1ll) C1{ Fp FL FL:1}



static void Test_Vp_Ul_BFu1ll()
{
  {
    init_simple_test("Vp_Ul_BFu1ll");
    static STRUCT_IF_C Vp_Ul_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 1, 1, "Vp_Ul_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu1ll, Vp_Ul_BFu1ll)
//============================================================================


struct  Vp_Ul_BFu1s  {
  void *v1;
  __tsu64 v2;
  unsigned short v3:1;
};
//SIG(1 Vp_Ul_BFu1s) C1{ Fp FL Fs:1}



static void Test_Vp_Ul_BFu1s()
{
  {
    init_simple_test("Vp_Ul_BFu1s");
    static STRUCT_IF_C Vp_Ul_BFu1s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 1, 1, "Vp_Ul_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu1s, Vp_Ul_BFu1s)
//============================================================================


struct  Vp_Ul_BFu31i  {
  void *v1;
  __tsu64 v2;
  unsigned int v3:31;
};
//SIG(1 Vp_Ul_BFu31i) C1{ Fp FL Fi:31}



static void Test_Vp_Ul_BFu31i()
{
  {
    init_simple_test("Vp_Ul_BFu31i");
    static STRUCT_IF_C Vp_Ul_BFu31i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 31, 1, "Vp_Ul_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 31, hide_ull(1LL<<30), "Vp_Ul_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu31i, Vp_Ul_BFu31i)
//============================================================================


struct  Vp_Ul_BFu31ll  {
  void *v1;
  __tsu64 v2;
  __tsu64 v3:31;
};
//SIG(1 Vp_Ul_BFu31ll) C1{ Fp FL FL:31}



static void Test_Vp_Ul_BFu31ll()
{
  {
    init_simple_test("Vp_Ul_BFu31ll");
    static STRUCT_IF_C Vp_Ul_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 31, 1, "Vp_Ul_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 31, hide_ull(1LL<<30), "Vp_Ul_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu31ll, Vp_Ul_BFu31ll)
//============================================================================


struct  Vp_Ul_BFu32i  {
  void *v1;
  __tsu64 v2;
  unsigned int v3:32;
};
//SIG(1 Vp_Ul_BFu32i) C1{ Fp FL Fi:32}



static void Test_Vp_Ul_BFu32i()
{
  {
    init_simple_test("Vp_Ul_BFu32i");
    static STRUCT_IF_C Vp_Ul_BFu32i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, 1, "Vp_Ul_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, hide_ull(1LL<<31), "Vp_Ul_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu32i, Vp_Ul_BFu32i)
//============================================================================


struct  Vp_Ul_BFu32ll  {
  void *v1;
  __tsu64 v2;
  __tsu64 v3:32;
};
//SIG(1 Vp_Ul_BFu32ll) C1{ Fp FL FL:32}



static void Test_Vp_Ul_BFu32ll()
{
  {
    init_simple_test("Vp_Ul_BFu32ll");
    static STRUCT_IF_C Vp_Ul_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, 1, "Vp_Ul_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 32, hide_ull(1LL<<31), "Vp_Ul_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu32ll, Vp_Ul_BFu32ll)
//============================================================================


struct  Vp_Ul_BFu33  {
  void *v1;
  __tsu64 v2;
  __tsu64 v3:33;
};
//SIG(1 Vp_Ul_BFu33) C1{ Fp FL FL:33}



static void Test_Vp_Ul_BFu33()
{
  {
    init_simple_test("Vp_Ul_BFu33");
    static STRUCT_IF_C Vp_Ul_BFu33 lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_Ul_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 33, 1, "Vp_Ul_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 33, hide_ull(1LL<<32), "Vp_Ul_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu33, Vp_Ul_BFu33)
//============================================================================


struct  Vp_Ul_BFu7c  {
  void *v1;
  __tsu64 v2;
  unsigned char v3:7;
};
//SIG(1 Vp_Ul_BFu7c) C1{ Fp FL Fc:7}



static void Test_Vp_Ul_BFu7c()
{
  {
    init_simple_test("Vp_Ul_BFu7c");
    static STRUCT_IF_C Vp_Ul_BFu7c lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, 1, "Vp_Ul_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, hide_ull(1LL<<6), "Vp_Ul_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu7c, Vp_Ul_BFu7c)
//============================================================================


struct  Vp_Ul_BFu7i  {
  void *v1;
  __tsu64 v2;
  unsigned int v3:7;
};
//SIG(1 Vp_Ul_BFu7i) C1{ Fp FL Fi:7}



static void Test_Vp_Ul_BFu7i()
{
  {
    init_simple_test("Vp_Ul_BFu7i");
    static STRUCT_IF_C Vp_Ul_BFu7i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, 1, "Vp_Ul_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, hide_ull(1LL<<6), "Vp_Ul_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu7i, Vp_Ul_BFu7i)
//============================================================================


struct  Vp_Ul_BFu7ll  {
  void *v1;
  __tsu64 v2;
  __tsu64 v3:7;
};
//SIG(1 Vp_Ul_BFu7ll) C1{ Fp FL FL:7}



static void Test_Vp_Ul_BFu7ll()
{
  {
    init_simple_test("Vp_Ul_BFu7ll");
    static STRUCT_IF_C Vp_Ul_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, 1, "Vp_Ul_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, hide_ull(1LL<<6), "Vp_Ul_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu7ll, Vp_Ul_BFu7ll)
//============================================================================


struct  Vp_Ul_BFu7s  {
  void *v1;
  __tsu64 v2;
  unsigned short v3:7;
};
//SIG(1 Vp_Ul_BFu7s) C1{ Fp FL Fs:7}



static void Test_Vp_Ul_BFu7s()
{
  {
    init_simple_test("Vp_Ul_BFu7s");
    static STRUCT_IF_C Vp_Ul_BFu7s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, 1, "Vp_Ul_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 7, hide_ull(1LL<<6), "Vp_Ul_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu7s, Vp_Ul_BFu7s)
//============================================================================


struct  Vp_Ul_BFu8c  {
  void *v1;
  __tsu64 v2;
  unsigned char v3:8;
};
//SIG(1 Vp_Ul_BFu8c) C1{ Fp FL Fc:8}



static void Test_Vp_Ul_BFu8c()
{
  {
    init_simple_test("Vp_Ul_BFu8c");
    static STRUCT_IF_C Vp_Ul_BFu8c lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, 1, "Vp_Ul_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, hide_ull(1LL<<7), "Vp_Ul_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu8c, Vp_Ul_BFu8c)
//============================================================================


struct  Vp_Ul_BFu8i  {
  void *v1;
  __tsu64 v2;
  unsigned int v3:8;
};
//SIG(1 Vp_Ul_BFu8i) C1{ Fp FL Fi:8}



static void Test_Vp_Ul_BFu8i()
{
  {
    init_simple_test("Vp_Ul_BFu8i");
    static STRUCT_IF_C Vp_Ul_BFu8i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, 1, "Vp_Ul_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, hide_ull(1LL<<7), "Vp_Ul_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu8i, Vp_Ul_BFu8i)
//============================================================================


struct  Vp_Ul_BFu8ll  {
  void *v1;
  __tsu64 v2;
  __tsu64 v3:8;
};
//SIG(1 Vp_Ul_BFu8ll) C1{ Fp FL FL:8}



static void Test_Vp_Ul_BFu8ll()
{
  {
    init_simple_test("Vp_Ul_BFu8ll");
    static STRUCT_IF_C Vp_Ul_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, 1, "Vp_Ul_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, hide_ull(1LL<<7), "Vp_Ul_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu8ll, Vp_Ul_BFu8ll)
//============================================================================


struct  Vp_Ul_BFu8s  {
  void *v1;
  __tsu64 v2;
  unsigned short v3:8;
};
//SIG(1 Vp_Ul_BFu8s) C1{ Fp FL Fs:8}



static void Test_Vp_Ul_BFu8s()
{
  {
    init_simple_test("Vp_Ul_BFu8s");
    static STRUCT_IF_C Vp_Ul_BFu8s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, 1, "Vp_Ul_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 8, hide_ull(1LL<<7), "Vp_Ul_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu8s, Vp_Ul_BFu8s)
//============================================================================


struct  Vp_Ul_BFu9i  {
  void *v1;
  __tsu64 v2;
  unsigned int v3:9;
};
//SIG(1 Vp_Ul_BFu9i) C1{ Fp FL Fi:9}



static void Test_Vp_Ul_BFu9i()
{
  {
    init_simple_test("Vp_Ul_BFu9i");
    static STRUCT_IF_C Vp_Ul_BFu9i lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, 1, "Vp_Ul_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, hide_ull(1LL<<8), "Vp_Ul_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu9i, Vp_Ul_BFu9i)
//============================================================================


struct  Vp_Ul_BFu9ll  {
  void *v1;
  __tsu64 v2;
  __tsu64 v3:9;
};
//SIG(1 Vp_Ul_BFu9ll) C1{ Fp FL FL:9}



static void Test_Vp_Ul_BFu9ll()
{
  {
    init_simple_test("Vp_Ul_BFu9ll");
    static STRUCT_IF_C Vp_Ul_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, 1, "Vp_Ul_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, hide_ull(1LL<<8), "Vp_Ul_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu9ll, Vp_Ul_BFu9ll)
//============================================================================


struct  Vp_Ul_BFu9s  {
  void *v1;
  __tsu64 v2;
  unsigned short v3:9;
};
//SIG(1 Vp_Ul_BFu9s) C1{ Fp FL Fs:9}



static void Test_Vp_Ul_BFu9s()
{
  {
    init_simple_test("Vp_Ul_BFu9s");
    static STRUCT_IF_C Vp_Ul_BFu9s lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_Ul_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, 1, "Vp_Ul_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(16,12), 0, 9, hide_ull(1LL<<8), "Vp_Ul_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_BFu9s, Vp_Ul_BFu9s)
//============================================================================


struct  Vp_Ul_C  {
  void *v1;
  __tsu64 v2;
  char v3;
};
//SIG(1 Vp_Ul_C) C1{ Fp FL Fc}



static void Test_Vp_Ul_C()
{
  {
    init_simple_test("Vp_Ul_C");
    STRUCT_IF_C Vp_Ul_C lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_C)");
    check_field_offset(lv, v1, 0, "Vp_Ul_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_C.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_C, Vp_Ul_C)
//============================================================================


struct  Vp_Ul_D  {
  void *v1;
  __tsu64 v2;
  double v3;
};
//SIG(1 Vp_Ul_D) C1{ Fp FL[2]}



static void Test_Vp_Ul_D()
{
  {
    init_simple_test("Vp_Ul_D");
    STRUCT_IF_C Vp_Ul_D lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_Ul_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_D)");
    check_field_offset(lv, v1, 0, "Vp_Ul_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_D.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_D, Vp_Ul_D)
//============================================================================


struct  Vp_Ul_F  {
  void *v1;
  __tsu64 v2;
  float v3;
};
//SIG(1 Vp_Ul_F) C1{ Fp FL Fi}



static void Test_Vp_Ul_F()
{
  {
    init_simple_test("Vp_Ul_F");
    STRUCT_IF_C Vp_Ul_F lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_F)");
    check_field_offset(lv, v1, 0, "Vp_Ul_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_F.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_F, Vp_Ul_F)
//============================================================================


struct  Vp_Ul_I  {
  void *v1;
  __tsu64 v2;
  int v3;
};
//SIG(1 Vp_Ul_I) C1{ Fp FL Fi}



static void Test_Vp_Ul_I()
{
  {
    init_simple_test("Vp_Ul_I");
    STRUCT_IF_C Vp_Ul_I lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_I)");
    check_field_offset(lv, v1, 0, "Vp_Ul_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_I.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_I, Vp_Ul_I)
//============================================================================


struct  Vp_Ul_Ip  {
  void *v1;
  __tsu64 v2;
  int *v3;
};
//SIG(1 Vp_Ul_Ip) C1{ Fp FL Fp}



static void Test_Vp_Ul_Ip()
{
  {
    init_simple_test("Vp_Ul_Ip");
    STRUCT_IF_C Vp_Ul_Ip lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_Ip)");
    check_field_offset(lv, v1, 0, "Vp_Ul_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_Ip, Vp_Ul_Ip)
//============================================================================


struct  Vp_Ul_L  {
  void *v1;
  __tsu64 v2;
  __tsi64 v3;
};
//SIG(1 Vp_Ul_L) C1{ Fp FL[2]}



static void Test_Vp_Ul_L()
{
  {
    init_simple_test("Vp_Ul_L");
    STRUCT_IF_C Vp_Ul_L lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_Ul_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_L)");
    check_field_offset(lv, v1, 0, "Vp_Ul_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_L.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_L, Vp_Ul_L)
//============================================================================


struct  Vp_Ul_S  {
  void *v1;
  __tsu64 v2;
  short v3;
};
//SIG(1 Vp_Ul_S) C1{ Fp FL Fs}



static void Test_Vp_Ul_S()
{
  {
    init_simple_test("Vp_Ul_S");
    STRUCT_IF_C Vp_Ul_S lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_S)");
    check_field_offset(lv, v1, 0, "Vp_Ul_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_S.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_S, Vp_Ul_S)
//============================================================================


struct  Vp_Ul_Uc  {
  void *v1;
  __tsu64 v2;
  unsigned char v3;
};
//SIG(1 Vp_Ul_Uc) C1{ Fp FL Fc}



static void Test_Vp_Ul_Uc()
{
  {
    init_simple_test("Vp_Ul_Uc");
    STRUCT_IF_C Vp_Ul_Uc lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_Uc)");
    check_field_offset(lv, v1, 0, "Vp_Ul_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_Uc, Vp_Ul_Uc)
//============================================================================


struct  Vp_Ul_Ui  {
  void *v1;
  __tsu64 v2;
  unsigned int v3;
};
//SIG(1 Vp_Ul_Ui) C1{ Fp FL Fi}



static void Test_Vp_Ul_Ui()
{
  {
    init_simple_test("Vp_Ul_Ui");
    STRUCT_IF_C Vp_Ul_Ui lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_Ui)");
    check_field_offset(lv, v1, 0, "Vp_Ul_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_Ui, Vp_Ul_Ui)
//============================================================================


struct  Vp_Ul_Ul  {
  void *v1;
  __tsu64 v2;
  __tsu64 v3;
};
//SIG(1 Vp_Ul_Ul) C1{ Fp FL[2]}



static void Test_Vp_Ul_Ul()
{
  {
    init_simple_test("Vp_Ul_Ul");
    STRUCT_IF_C Vp_Ul_Ul lv;
    check2(sizeof(lv), ABISELECT(24,20), "sizeof(Vp_Ul_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_Ul)");
    check_field_offset(lv, v1, 0, "Vp_Ul_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_Ul, Vp_Ul_Ul)
//============================================================================


struct  Vp_Ul_Us  {
  void *v1;
  __tsu64 v2;
  unsigned short v3;
};
//SIG(1 Vp_Ul_Us) C1{ Fp FL Fs}



static void Test_Vp_Ul_Us()
{
  {
    init_simple_test("Vp_Ul_Us");
    STRUCT_IF_C Vp_Ul_Us lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_Us)");
    check_field_offset(lv, v1, 0, "Vp_Ul_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_Us.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_Us, Vp_Ul_Us)
//============================================================================


struct  Vp_Ul_Vp  {
  void *v1;
  __tsu64 v2;
  void *v3;
};
//SIG(1 Vp_Ul_Vp) C1{ Fp FL Fp}



static void Test_Vp_Ul_Vp()
{
  {
    init_simple_test("Vp_Ul_Vp");
    STRUCT_IF_C Vp_Ul_Vp lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Ul_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Ul_Vp)");
    check_field_offset(lv, v1, 0, "Vp_Ul_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Ul_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(16,12), "Vp_Ul_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Ul_Vp, Vp_Ul_Vp)
//============================================================================


struct  Vp_Us  {
  void *v1;
  unsigned short v2;
};
//SIG(1 Vp_Us) C1{ Fp Fs}



static void Test_Vp_Us()
{
  {
    init_simple_test("Vp_Us");
    STRUCT_IF_C Vp_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us)");
    check_field_offset(lv, v1, 0, "Vp_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us, Vp_Us)
//============================================================================


struct  Vp_Us_BFu15i  {
  void *v1;
  unsigned short v2;
  unsigned int v3:15;
};
//SIG(1 Vp_Us_BFu15i) C1{ Fp Fs Fi:15}



static void Test_Vp_Us_BFu15i()
{
  {
    init_simple_test("Vp_Us_BFu15i");
    static STRUCT_IF_C Vp_Us_BFu15i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_Us_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_Us_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu15i, Vp_Us_BFu15i)
//============================================================================


struct  Vp_Us_BFu15ll  {
  void *v1;
  unsigned short v2;
  __tsu64 v3:15;
};
//SIG(1 Vp_Us_BFu15ll) C1{ Fp Fs FL:15}



static void Test_Vp_Us_BFu15ll()
{
  {
    init_simple_test("Vp_Us_BFu15ll");
    static STRUCT_IF_C Vp_Us_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_Us_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_Us_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu15ll, Vp_Us_BFu15ll)
//============================================================================


struct  Vp_Us_BFu15s  {
  void *v1;
  unsigned short v2;
  unsigned short v3:15;
};
//SIG(1 Vp_Us_BFu15s) C1{ Fp Fs Fs:15}



static void Test_Vp_Us_BFu15s()
{
  {
    init_simple_test("Vp_Us_BFu15s");
    static STRUCT_IF_C Vp_Us_BFu15s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, 1, "Vp_Us_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 15, hide_ull(1LL<<14), "Vp_Us_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu15s, Vp_Us_BFu15s)
//============================================================================


struct  Vp_Us_BFu16i  {
  void *v1;
  unsigned short v2;
  unsigned int v3:16;
};
//SIG(1 Vp_Us_BFu16i) C1{ Fp Fs Fi:16}



static void Test_Vp_Us_BFu16i()
{
  {
    init_simple_test("Vp_Us_BFu16i");
    static STRUCT_IF_C Vp_Us_BFu16i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_Us_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_Us_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu16i, Vp_Us_BFu16i)
//============================================================================


struct  Vp_Us_BFu16ll  {
  void *v1;
  unsigned short v2;
  __tsu64 v3:16;
};
//SIG(1 Vp_Us_BFu16ll) C1{ Fp Fs FL:16}



static void Test_Vp_Us_BFu16ll()
{
  {
    init_simple_test("Vp_Us_BFu16ll");
    static STRUCT_IF_C Vp_Us_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_Us_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_Us_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu16ll, Vp_Us_BFu16ll)
//============================================================================


struct  Vp_Us_BFu16s  {
  void *v1;
  unsigned short v2;
  unsigned short v3:16;
};
//SIG(1 Vp_Us_BFu16s) C1{ Fp Fs Fs:16}



static void Test_Vp_Us_BFu16s()
{
  {
    init_simple_test("Vp_Us_BFu16s");
    static STRUCT_IF_C Vp_Us_BFu16s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, 1, "Vp_Us_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 16, hide_ull(1LL<<15), "Vp_Us_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu16s, Vp_Us_BFu16s)
//============================================================================


struct  Vp_Us_BFu17i  {
  void *v1;
  unsigned short v2;
  unsigned int v3:17;
};
//SIG(1 Vp_Us_BFu17i) C1{ Fp Fs Fi:17}



static void Test_Vp_Us_BFu17i()
{
  {
    init_simple_test("Vp_Us_BFu17i");
    static STRUCT_IF_C Vp_Us_BFu17i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Us_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, 1, "Vp_Us_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 17, hide_ull(1LL<<16), "Vp_Us_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu17i, Vp_Us_BFu17i)
//============================================================================


struct  Vp_Us_BFu17ll  {
  void *v1;
  unsigned short v2;
  __tsu64 v3:17;
};
//SIG(1 Vp_Us_BFu17ll) C1{ Fp Fs FL:17}



static void Test_Vp_Us_BFu17ll()
{
  {
    init_simple_test("Vp_Us_BFu17ll");
    static STRUCT_IF_C Vp_Us_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Us_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 17, 1, "Vp_Us_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 17, hide_ull(1LL<<16), "Vp_Us_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu17ll, Vp_Us_BFu17ll)
//============================================================================


struct  Vp_Us_BFu1c  {
  void *v1;
  unsigned short v2;
  unsigned char v3:1;
};
//SIG(1 Vp_Us_BFu1c) C1{ Fp Fs Fc:1}



static void Test_Vp_Us_BFu1c()
{
  {
    init_simple_test("Vp_Us_BFu1c");
    static STRUCT_IF_C Vp_Us_BFu1c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 1, 1, "Vp_Us_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu1c, Vp_Us_BFu1c)
//============================================================================


struct  Vp_Us_BFu1i  {
  void *v1;
  unsigned short v2;
  unsigned int v3:1;
};
//SIG(1 Vp_Us_BFu1i) C1{ Fp Fs Fi:1}



static void Test_Vp_Us_BFu1i()
{
  {
    init_simple_test("Vp_Us_BFu1i");
    static STRUCT_IF_C Vp_Us_BFu1i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 1, 1, "Vp_Us_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu1i, Vp_Us_BFu1i)
//============================================================================


struct  Vp_Us_BFu1ll  {
  void *v1;
  unsigned short v2;
  __tsu64 v3:1;
};
//SIG(1 Vp_Us_BFu1ll) C1{ Fp Fs FL:1}



static void Test_Vp_Us_BFu1ll()
{
  {
    init_simple_test("Vp_Us_BFu1ll");
    static STRUCT_IF_C Vp_Us_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 1, 1, "Vp_Us_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu1ll, Vp_Us_BFu1ll)
//============================================================================


struct  Vp_Us_BFu1s  {
  void *v1;
  unsigned short v2;
  unsigned short v3:1;
};
//SIG(1 Vp_Us_BFu1s) C1{ Fp Fs Fs:1}



static void Test_Vp_Us_BFu1s()
{
  {
    init_simple_test("Vp_Us_BFu1s");
    static STRUCT_IF_C Vp_Us_BFu1s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 1, 1, "Vp_Us_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu1s, Vp_Us_BFu1s)
//============================================================================


struct  Vp_Us_BFu31i  {
  void *v1;
  unsigned short v2;
  unsigned int v3:31;
};
//SIG(1 Vp_Us_BFu31i) C1{ Fp Fs Fi:31}



static void Test_Vp_Us_BFu31i()
{
  {
    init_simple_test("Vp_Us_BFu31i");
    static STRUCT_IF_C Vp_Us_BFu31i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Us_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, 1, "Vp_Us_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 31, hide_ull(1LL<<30), "Vp_Us_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu31i, Vp_Us_BFu31i)
//============================================================================


struct  Vp_Us_BFu31ll  {
  void *v1;
  unsigned short v2;
  __tsu64 v3:31;
};
//SIG(1 Vp_Us_BFu31ll) C1{ Fp Fs FL:31}



static void Test_Vp_Us_BFu31ll()
{
  {
    init_simple_test("Vp_Us_BFu31ll");
    static STRUCT_IF_C Vp_Us_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Us_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 31, 1, "Vp_Us_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 31, hide_ull(1LL<<30), "Vp_Us_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu31ll, Vp_Us_BFu31ll)
//============================================================================


struct  Vp_Us_BFu32i  {
  void *v1;
  unsigned short v2;
  unsigned int v3:32;
};
//SIG(1 Vp_Us_BFu32i) C1{ Fp Fs Fi:32}



static void Test_Vp_Us_BFu32i()
{
  {
    init_simple_test("Vp_Us_BFu32i");
    static STRUCT_IF_C Vp_Us_BFu32i lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Us_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, 1, "Vp_Us_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(12,8), 0, 32, hide_ull(1LL<<31), "Vp_Us_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu32i, Vp_Us_BFu32i)
//============================================================================


struct  Vp_Us_BFu32ll  {
  void *v1;
  unsigned short v2;
  __tsu64 v3:32;
};
//SIG(1 Vp_Us_BFu32ll) C1{ Fp Fs FL:32}



static void Test_Vp_Us_BFu32ll()
{
  {
    init_simple_test("Vp_Us_BFu32ll");
    static STRUCT_IF_C Vp_Us_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Us_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 32, 1, "Vp_Us_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 32, hide_ull(1LL<<31), "Vp_Us_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu32ll, Vp_Us_BFu32ll)
//============================================================================


struct  Vp_Us_BFu33  {
  void *v1;
  unsigned short v2;
  __tsu64 v3:33;
};
//SIG(1 Vp_Us_BFu33) C1{ Fp Fs FL:33}



static void Test_Vp_Us_BFu33()
{
  {
    init_simple_test("Vp_Us_BFu33");
    static STRUCT_IF_C Vp_Us_BFu33 lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Us_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 33, 1, "Vp_Us_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 33, hide_ull(1LL<<32), "Vp_Us_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu33, Vp_Us_BFu33)
//============================================================================


struct  Vp_Us_BFu7c  {
  void *v1;
  unsigned short v2;
  unsigned char v3:7;
};
//SIG(1 Vp_Us_BFu7c) C1{ Fp Fs Fc:7}



static void Test_Vp_Us_BFu7c()
{
  {
    init_simple_test("Vp_Us_BFu7c");
    static STRUCT_IF_C Vp_Us_BFu7c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, 1, "Vp_Us_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, hide_ull(1LL<<6), "Vp_Us_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu7c, Vp_Us_BFu7c)
//============================================================================


struct  Vp_Us_BFu7i  {
  void *v1;
  unsigned short v2;
  unsigned int v3:7;
};
//SIG(1 Vp_Us_BFu7i) C1{ Fp Fs Fi:7}



static void Test_Vp_Us_BFu7i()
{
  {
    init_simple_test("Vp_Us_BFu7i");
    static STRUCT_IF_C Vp_Us_BFu7i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, 1, "Vp_Us_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, hide_ull(1LL<<6), "Vp_Us_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu7i, Vp_Us_BFu7i)
//============================================================================


struct  Vp_Us_BFu7ll  {
  void *v1;
  unsigned short v2;
  __tsu64 v3:7;
};
//SIG(1 Vp_Us_BFu7ll) C1{ Fp Fs FL:7}



static void Test_Vp_Us_BFu7ll()
{
  {
    init_simple_test("Vp_Us_BFu7ll");
    static STRUCT_IF_C Vp_Us_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, 1, "Vp_Us_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, hide_ull(1LL<<6), "Vp_Us_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu7ll, Vp_Us_BFu7ll)
//============================================================================


struct  Vp_Us_BFu7s  {
  void *v1;
  unsigned short v2;
  unsigned short v3:7;
};
//SIG(1 Vp_Us_BFu7s) C1{ Fp Fs Fs:7}



static void Test_Vp_Us_BFu7s()
{
  {
    init_simple_test("Vp_Us_BFu7s");
    static STRUCT_IF_C Vp_Us_BFu7s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, 1, "Vp_Us_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 7, hide_ull(1LL<<6), "Vp_Us_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu7s, Vp_Us_BFu7s)
//============================================================================


struct  Vp_Us_BFu8c  {
  void *v1;
  unsigned short v2;
  unsigned char v3:8;
};
//SIG(1 Vp_Us_BFu8c) C1{ Fp Fs Fc:8}



static void Test_Vp_Us_BFu8c()
{
  {
    init_simple_test("Vp_Us_BFu8c");
    static STRUCT_IF_C Vp_Us_BFu8c lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_Us_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_Us_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu8c, Vp_Us_BFu8c)
//============================================================================


struct  Vp_Us_BFu8i  {
  void *v1;
  unsigned short v2;
  unsigned int v3:8;
};
//SIG(1 Vp_Us_BFu8i) C1{ Fp Fs Fi:8}



static void Test_Vp_Us_BFu8i()
{
  {
    init_simple_test("Vp_Us_BFu8i");
    static STRUCT_IF_C Vp_Us_BFu8i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_Us_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_Us_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu8i, Vp_Us_BFu8i)
//============================================================================


struct  Vp_Us_BFu8ll  {
  void *v1;
  unsigned short v2;
  __tsu64 v3:8;
};
//SIG(1 Vp_Us_BFu8ll) C1{ Fp Fs FL:8}



static void Test_Vp_Us_BFu8ll()
{
  {
    init_simple_test("Vp_Us_BFu8ll");
    static STRUCT_IF_C Vp_Us_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_Us_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_Us_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu8ll, Vp_Us_BFu8ll)
//============================================================================


struct  Vp_Us_BFu8s  {
  void *v1;
  unsigned short v2;
  unsigned short v3:8;
};
//SIG(1 Vp_Us_BFu8s) C1{ Fp Fs Fs:8}



static void Test_Vp_Us_BFu8s()
{
  {
    init_simple_test("Vp_Us_BFu8s");
    static STRUCT_IF_C Vp_Us_BFu8s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, 1, "Vp_Us_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 8, hide_ull(1LL<<7), "Vp_Us_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu8s, Vp_Us_BFu8s)
//============================================================================


struct  Vp_Us_BFu9i  {
  void *v1;
  unsigned short v2;
  unsigned int v3:9;
};
//SIG(1 Vp_Us_BFu9i) C1{ Fp Fs Fi:9}



static void Test_Vp_Us_BFu9i()
{
  {
    init_simple_test("Vp_Us_BFu9i");
    static STRUCT_IF_C Vp_Us_BFu9i lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_Us_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_Us_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu9i, Vp_Us_BFu9i)
//============================================================================


struct  Vp_Us_BFu9ll  {
  void *v1;
  unsigned short v2;
  __tsu64 v3:9;
};
//SIG(1 Vp_Us_BFu9ll) C1{ Fp Fs FL:9}



static void Test_Vp_Us_BFu9ll()
{
  {
    init_simple_test("Vp_Us_BFu9ll");
    static STRUCT_IF_C Vp_Us_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_Us_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_Us_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu9ll, Vp_Us_BFu9ll)
//============================================================================


struct  Vp_Us_BFu9s  {
  void *v1;
  unsigned short v2;
  unsigned short v3:9;
};
//SIG(1 Vp_Us_BFu9s) C1{ Fp Fs Fs:9}



static void Test_Vp_Us_BFu9s()
{
  {
    init_simple_test("Vp_Us_BFu9s");
    static STRUCT_IF_C Vp_Us_BFu9s lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_Us_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, 1, "Vp_Us_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(10,6), 0, 9, hide_ull(1LL<<8), "Vp_Us_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_BFu9s, Vp_Us_BFu9s)
//============================================================================


struct  Vp_Us_C  {
  void *v1;
  unsigned short v2;
  char v3;
};
//SIG(1 Vp_Us_C) C1{ Fp Fs Fc}



static void Test_Vp_Us_C()
{
  {
    init_simple_test("Vp_Us_C");
    STRUCT_IF_C Vp_Us_C lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_C)");
    check_field_offset(lv, v1, 0, "Vp_Us_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_C.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_Us_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_C, Vp_Us_C)
//============================================================================


struct  Vp_Us_D  {
  void *v1;
  unsigned short v2;
  double v3;
};
//SIG(1 Vp_Us_D) C1{ Fp Fs FL}



static void Test_Vp_Us_D()
{
  {
    init_simple_test("Vp_Us_D");
    STRUCT_IF_C Vp_Us_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Us_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_D)");
    check_field_offset(lv, v1, 0, "Vp_Us_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_D.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Us_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_D, Vp_Us_D)
//============================================================================


struct  Vp_Us_F  {
  void *v1;
  unsigned short v2;
  float v3;
};
//SIG(1 Vp_Us_F) C1{ Fp Fs Fi}



static void Test_Vp_Us_F()
{
  {
    init_simple_test("Vp_Us_F");
    STRUCT_IF_C Vp_Us_F lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Us_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_F)");
    check_field_offset(lv, v1, 0, "Vp_Us_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_F.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Us_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_F, Vp_Us_F)
//============================================================================


struct  Vp_Us_I  {
  void *v1;
  unsigned short v2;
  int v3;
};
//SIG(1 Vp_Us_I) C1{ Fp Fs Fi}



static void Test_Vp_Us_I()
{
  {
    init_simple_test("Vp_Us_I");
    STRUCT_IF_C Vp_Us_I lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Us_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_I)");
    check_field_offset(lv, v1, 0, "Vp_Us_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_I.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Us_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_I, Vp_Us_I)
//============================================================================


struct  Vp_Us_Ip  {
  void *v1;
  unsigned short v2;
  int *v3;
};
//SIG(1 Vp_Us_Ip) C1{ Fp Fs Fp}



static void Test_Vp_Us_Ip()
{
  {
    init_simple_test("Vp_Us_Ip");
    STRUCT_IF_C Vp_Us_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Us_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_Ip)");
    check_field_offset(lv, v1, 0, "Vp_Us_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Us_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_Ip, Vp_Us_Ip)
//============================================================================


struct  Vp_Us_L  {
  void *v1;
  unsigned short v2;
  __tsi64 v3;
};
//SIG(1 Vp_Us_L) C1{ Fp Fs FL}



static void Test_Vp_Us_L()
{
  {
    init_simple_test("Vp_Us_L");
    STRUCT_IF_C Vp_Us_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Us_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_L)");
    check_field_offset(lv, v1, 0, "Vp_Us_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_L.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Us_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_L, Vp_Us_L)
//============================================================================


struct  Vp_Us_S  {
  void *v1;
  unsigned short v2;
  short v3;
};
//SIG(1 Vp_Us_S) C1{ Fp Fs[2]}



static void Test_Vp_Us_S()
{
  {
    init_simple_test("Vp_Us_S");
    STRUCT_IF_C Vp_Us_S lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_S)");
    check_field_offset(lv, v1, 0, "Vp_Us_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_S.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_Us_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_S, Vp_Us_S)
//============================================================================


struct  Vp_Us_Uc  {
  void *v1;
  unsigned short v2;
  unsigned char v3;
};
//SIG(1 Vp_Us_Uc) C1{ Fp Fs Fc}



static void Test_Vp_Us_Uc()
{
  {
    init_simple_test("Vp_Us_Uc");
    STRUCT_IF_C Vp_Us_Uc lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_Uc)");
    check_field_offset(lv, v1, 0, "Vp_Us_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_Us_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_Uc, Vp_Us_Uc)
//============================================================================


struct  Vp_Us_Ui  {
  void *v1;
  unsigned short v2;
  unsigned int v3;
};
//SIG(1 Vp_Us_Ui) C1{ Fp Fs Fi}



static void Test_Vp_Us_Ui()
{
  {
    init_simple_test("Vp_Us_Ui");
    STRUCT_IF_C Vp_Us_Ui lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(Vp_Us_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_Ui)");
    check_field_offset(lv, v1, 0, "Vp_Us_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(12,8), "Vp_Us_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_Ui, Vp_Us_Ui)
//============================================================================


struct  Vp_Us_Ul  {
  void *v1;
  unsigned short v2;
  __tsu64 v3;
};
//SIG(1 Vp_Us_Ul) C1{ Fp Fs FL}



static void Test_Vp_Us_Ul()
{
  {
    init_simple_test("Vp_Us_Ul");
    STRUCT_IF_C Vp_Us_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Us_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_Ul)");
    check_field_offset(lv, v1, 0, "Vp_Us_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Us_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_Ul, Vp_Us_Ul)
//============================================================================


struct  Vp_Us_Us  {
  void *v1;
  unsigned short v2;
  unsigned short v3;
};
//SIG(1 Vp_Us_Us) C1{ Fp Fs[2]}



static void Test_Vp_Us_Us()
{
  {
    init_simple_test("Vp_Us_Us");
    STRUCT_IF_C Vp_Us_Us lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Us_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_Us)");
    check_field_offset(lv, v1, 0, "Vp_Us_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_Us.v2");
    check_field_offset(lv, v3, ABISELECT(10,6), "Vp_Us_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_Us, Vp_Us_Us)
//============================================================================


struct  Vp_Us_Vp  {
  void *v1;
  unsigned short v2;
  void *v3;
};
//SIG(1 Vp_Us_Vp) C1{ Fp Fs Fp}



static void Test_Vp_Us_Vp()
{
  {
    init_simple_test("Vp_Us_Vp");
    STRUCT_IF_C Vp_Us_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Us_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Us_Vp)");
    check_field_offset(lv, v1, 0, "Vp_Us_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Us_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Us_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Us_Vp, Vp_Us_Vp)
//============================================================================


struct  Vp_Vp  {
  void *v1;
  void *v2;
};
//SIG(1 Vp_Vp) C1{ Fp[2]}



static void Test_Vp_Vp()
{
  {
    init_simple_test("Vp_Vp");
    STRUCT_IF_C Vp_Vp lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Vp_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp)");
    check_field_offset(lv, v1, 0, "Vp_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp.v2");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp, Vp_Vp)
//============================================================================


struct  Vp_Vp_BFu15i  {
  void *v1;
  void *v2;
  unsigned int v3:15;
};
//SIG(1 Vp_Vp_BFu15i) C1{ Fp[2] Fi:15}



static void Test_Vp_Vp_BFu15i()
{
  {
    init_simple_test("Vp_Vp_BFu15i");
    static STRUCT_IF_C Vp_Vp_BFu15i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu15i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu15i)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu15i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu15i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 15, 1, "Vp_Vp_BFu15i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 15, hide_ull(1LL<<14), "Vp_Vp_BFu15i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu15i, Vp_Vp_BFu15i)
//============================================================================


struct  Vp_Vp_BFu15ll  {
  void *v1;
  void *v2;
  __tsu64 v3:15;
};
//SIG(1 Vp_Vp_BFu15ll) C1{ Fp[2] FL:15}



static void Test_Vp_Vp_BFu15ll()
{
  {
    init_simple_test("Vp_Vp_BFu15ll");
    static STRUCT_IF_C Vp_Vp_BFu15ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu15ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu15ll)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu15ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu15ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 15, 1, "Vp_Vp_BFu15ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 15, hide_ull(1LL<<14), "Vp_Vp_BFu15ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu15ll, Vp_Vp_BFu15ll)
//============================================================================


struct  Vp_Vp_BFu15s  {
  void *v1;
  void *v2;
  unsigned short v3:15;
};
//SIG(1 Vp_Vp_BFu15s) C1{ Fp[2] Fs:15}



static void Test_Vp_Vp_BFu15s()
{
  {
    init_simple_test("Vp_Vp_BFu15s");
    static STRUCT_IF_C Vp_Vp_BFu15s lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu15s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu15s)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu15s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu15s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 15, 1, "Vp_Vp_BFu15s");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 15, hide_ull(1LL<<14), "Vp_Vp_BFu15s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu15s, Vp_Vp_BFu15s)
//============================================================================


struct  Vp_Vp_BFu16i  {
  void *v1;
  void *v2;
  unsigned int v3:16;
};
//SIG(1 Vp_Vp_BFu16i) C1{ Fp[2] Fi:16}



static void Test_Vp_Vp_BFu16i()
{
  {
    init_simple_test("Vp_Vp_BFu16i");
    static STRUCT_IF_C Vp_Vp_BFu16i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu16i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu16i)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu16i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu16i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 16, 1, "Vp_Vp_BFu16i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 16, hide_ull(1LL<<15), "Vp_Vp_BFu16i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu16i, Vp_Vp_BFu16i)
//============================================================================


struct  Vp_Vp_BFu16ll  {
  void *v1;
  void *v2;
  __tsu64 v3:16;
};
//SIG(1 Vp_Vp_BFu16ll) C1{ Fp[2] FL:16}



static void Test_Vp_Vp_BFu16ll()
{
  {
    init_simple_test("Vp_Vp_BFu16ll");
    static STRUCT_IF_C Vp_Vp_BFu16ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu16ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu16ll)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu16ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu16ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 16, 1, "Vp_Vp_BFu16ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 16, hide_ull(1LL<<15), "Vp_Vp_BFu16ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu16ll, Vp_Vp_BFu16ll)
//============================================================================


struct  Vp_Vp_BFu16s  {
  void *v1;
  void *v2;
  unsigned short v3:16;
};
//SIG(1 Vp_Vp_BFu16s) C1{ Fp[2] Fs:16}



static void Test_Vp_Vp_BFu16s()
{
  {
    init_simple_test("Vp_Vp_BFu16s");
    static STRUCT_IF_C Vp_Vp_BFu16s lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu16s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu16s)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu16s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu16s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 16, 1, "Vp_Vp_BFu16s");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 16, hide_ull(1LL<<15), "Vp_Vp_BFu16s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu16s, Vp_Vp_BFu16s)
//============================================================================


struct  Vp_Vp_BFu17i  {
  void *v1;
  void *v2;
  unsigned int v3:17;
};
//SIG(1 Vp_Vp_BFu17i) C1{ Fp[2] Fi:17}



static void Test_Vp_Vp_BFu17i()
{
  {
    init_simple_test("Vp_Vp_BFu17i");
    static STRUCT_IF_C Vp_Vp_BFu17i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu17i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu17i)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu17i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu17i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 17, 1, "Vp_Vp_BFu17i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 17, hide_ull(1LL<<16), "Vp_Vp_BFu17i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu17i, Vp_Vp_BFu17i)
//============================================================================


struct  Vp_Vp_BFu17ll  {
  void *v1;
  void *v2;
  __tsu64 v3:17;
};
//SIG(1 Vp_Vp_BFu17ll) C1{ Fp[2] FL:17}



static void Test_Vp_Vp_BFu17ll()
{
  {
    init_simple_test("Vp_Vp_BFu17ll");
    static STRUCT_IF_C Vp_Vp_BFu17ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu17ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu17ll)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu17ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu17ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 17, 1, "Vp_Vp_BFu17ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 17, hide_ull(1LL<<16), "Vp_Vp_BFu17ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu17ll, Vp_Vp_BFu17ll)
//============================================================================


struct  Vp_Vp_BFu1c  {
  void *v1;
  void *v2;
  unsigned char v3:1;
};
//SIG(1 Vp_Vp_BFu1c) C1{ Fp[2] Fc:1}



static void Test_Vp_Vp_BFu1c()
{
  {
    init_simple_test("Vp_Vp_BFu1c");
    static STRUCT_IF_C Vp_Vp_BFu1c lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu1c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu1c)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu1c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu1c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 1, 1, "Vp_Vp_BFu1c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu1c, Vp_Vp_BFu1c)
//============================================================================


struct  Vp_Vp_BFu1i  {
  void *v1;
  void *v2;
  unsigned int v3:1;
};
//SIG(1 Vp_Vp_BFu1i) C1{ Fp[2] Fi:1}



static void Test_Vp_Vp_BFu1i()
{
  {
    init_simple_test("Vp_Vp_BFu1i");
    static STRUCT_IF_C Vp_Vp_BFu1i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu1i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu1i)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu1i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu1i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 1, 1, "Vp_Vp_BFu1i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu1i, Vp_Vp_BFu1i)
//============================================================================


struct  Vp_Vp_BFu1ll  {
  void *v1;
  void *v2;
  __tsu64 v3:1;
};
//SIG(1 Vp_Vp_BFu1ll) C1{ Fp[2] FL:1}



static void Test_Vp_Vp_BFu1ll()
{
  {
    init_simple_test("Vp_Vp_BFu1ll");
    static STRUCT_IF_C Vp_Vp_BFu1ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu1ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu1ll)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu1ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu1ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 1, 1, "Vp_Vp_BFu1ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu1ll, Vp_Vp_BFu1ll)
//============================================================================


struct  Vp_Vp_BFu1s  {
  void *v1;
  void *v2;
  unsigned short v3:1;
};
//SIG(1 Vp_Vp_BFu1s) C1{ Fp[2] Fs:1}



static void Test_Vp_Vp_BFu1s()
{
  {
    init_simple_test("Vp_Vp_BFu1s");
    static STRUCT_IF_C Vp_Vp_BFu1s lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu1s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu1s)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu1s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu1s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 1, 1, "Vp_Vp_BFu1s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu1s, Vp_Vp_BFu1s)
//============================================================================


struct  Vp_Vp_BFu31i  {
  void *v1;
  void *v2;
  unsigned int v3:31;
};
//SIG(1 Vp_Vp_BFu31i) C1{ Fp[2] Fi:31}



static void Test_Vp_Vp_BFu31i()
{
  {
    init_simple_test("Vp_Vp_BFu31i");
    static STRUCT_IF_C Vp_Vp_BFu31i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu31i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu31i)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu31i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu31i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 31, 1, "Vp_Vp_BFu31i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 31, hide_ull(1LL<<30), "Vp_Vp_BFu31i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu31i, Vp_Vp_BFu31i)
//============================================================================


struct  Vp_Vp_BFu31ll  {
  void *v1;
  void *v2;
  __tsu64 v3:31;
};
//SIG(1 Vp_Vp_BFu31ll) C1{ Fp[2] FL:31}



static void Test_Vp_Vp_BFu31ll()
{
  {
    init_simple_test("Vp_Vp_BFu31ll");
    static STRUCT_IF_C Vp_Vp_BFu31ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu31ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu31ll)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu31ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu31ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 31, 1, "Vp_Vp_BFu31ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 31, hide_ull(1LL<<30), "Vp_Vp_BFu31ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu31ll, Vp_Vp_BFu31ll)
//============================================================================


struct  Vp_Vp_BFu32i  {
  void *v1;
  void *v2;
  unsigned int v3:32;
};
//SIG(1 Vp_Vp_BFu32i) C1{ Fp[2] Fi:32}



static void Test_Vp_Vp_BFu32i()
{
  {
    init_simple_test("Vp_Vp_BFu32i");
    static STRUCT_IF_C Vp_Vp_BFu32i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu32i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu32i)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu32i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu32i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 32, 1, "Vp_Vp_BFu32i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 32, hide_ull(1LL<<31), "Vp_Vp_BFu32i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu32i, Vp_Vp_BFu32i)
//============================================================================


struct  Vp_Vp_BFu32ll  {
  void *v1;
  void *v2;
  __tsu64 v3:32;
};
//SIG(1 Vp_Vp_BFu32ll) C1{ Fp[2] FL:32}



static void Test_Vp_Vp_BFu32ll()
{
  {
    init_simple_test("Vp_Vp_BFu32ll");
    static STRUCT_IF_C Vp_Vp_BFu32ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu32ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu32ll)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu32ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu32ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 32, 1, "Vp_Vp_BFu32ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 32, hide_ull(1LL<<31), "Vp_Vp_BFu32ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu32ll, Vp_Vp_BFu32ll)
//============================================================================


struct  Vp_Vp_BFu33  {
  void *v1;
  void *v2;
  __tsu64 v3:33;
};
//SIG(1 Vp_Vp_BFu33) C1{ Fp[2] FL:33}



static void Test_Vp_Vp_BFu33()
{
  {
    init_simple_test("Vp_Vp_BFu33");
    static STRUCT_IF_C Vp_Vp_BFu33 lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Vp_BFu33)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu33)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu33.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu33.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 33, 1, "Vp_Vp_BFu33");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 33, hide_ull(1LL<<32), "Vp_Vp_BFu33");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu33, Vp_Vp_BFu33)
//============================================================================


struct  Vp_Vp_BFu7c  {
  void *v1;
  void *v2;
  unsigned char v3:7;
};
//SIG(1 Vp_Vp_BFu7c) C1{ Fp[2] Fc:7}



static void Test_Vp_Vp_BFu7c()
{
  {
    init_simple_test("Vp_Vp_BFu7c");
    static STRUCT_IF_C Vp_Vp_BFu7c lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu7c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu7c)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu7c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu7c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, 1, "Vp_Vp_BFu7c");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, hide_ull(1LL<<6), "Vp_Vp_BFu7c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu7c, Vp_Vp_BFu7c)
//============================================================================


struct  Vp_Vp_BFu7i  {
  void *v1;
  void *v2;
  unsigned int v3:7;
};
//SIG(1 Vp_Vp_BFu7i) C1{ Fp[2] Fi:7}



static void Test_Vp_Vp_BFu7i()
{
  {
    init_simple_test("Vp_Vp_BFu7i");
    static STRUCT_IF_C Vp_Vp_BFu7i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu7i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu7i)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu7i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu7i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, 1, "Vp_Vp_BFu7i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, hide_ull(1LL<<6), "Vp_Vp_BFu7i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu7i, Vp_Vp_BFu7i)
//============================================================================


struct  Vp_Vp_BFu7ll  {
  void *v1;
  void *v2;
  __tsu64 v3:7;
};
//SIG(1 Vp_Vp_BFu7ll) C1{ Fp[2] FL:7}



static void Test_Vp_Vp_BFu7ll()
{
  {
    init_simple_test("Vp_Vp_BFu7ll");
    static STRUCT_IF_C Vp_Vp_BFu7ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu7ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu7ll)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu7ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu7ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, 1, "Vp_Vp_BFu7ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, hide_ull(1LL<<6), "Vp_Vp_BFu7ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu7ll, Vp_Vp_BFu7ll)
//============================================================================


struct  Vp_Vp_BFu7s  {
  void *v1;
  void *v2;
  unsigned short v3:7;
};
//SIG(1 Vp_Vp_BFu7s) C1{ Fp[2] Fs:7}



static void Test_Vp_Vp_BFu7s()
{
  {
    init_simple_test("Vp_Vp_BFu7s");
    static STRUCT_IF_C Vp_Vp_BFu7s lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu7s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu7s)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu7s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu7s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, 1, "Vp_Vp_BFu7s");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 7, hide_ull(1LL<<6), "Vp_Vp_BFu7s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu7s, Vp_Vp_BFu7s)
//============================================================================


struct  Vp_Vp_BFu8c  {
  void *v1;
  void *v2;
  unsigned char v3:8;
};
//SIG(1 Vp_Vp_BFu8c) C1{ Fp[2] Fc:8}



static void Test_Vp_Vp_BFu8c()
{
  {
    init_simple_test("Vp_Vp_BFu8c");
    static STRUCT_IF_C Vp_Vp_BFu8c lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu8c)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu8c)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu8c.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu8c.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, 1, "Vp_Vp_BFu8c");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, hide_ull(1LL<<7), "Vp_Vp_BFu8c");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu8c, Vp_Vp_BFu8c)
//============================================================================


struct  Vp_Vp_BFu8i  {
  void *v1;
  void *v2;
  unsigned int v3:8;
};
//SIG(1 Vp_Vp_BFu8i) C1{ Fp[2] Fi:8}



static void Test_Vp_Vp_BFu8i()
{
  {
    init_simple_test("Vp_Vp_BFu8i");
    static STRUCT_IF_C Vp_Vp_BFu8i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu8i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu8i)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu8i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu8i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, 1, "Vp_Vp_BFu8i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, hide_ull(1LL<<7), "Vp_Vp_BFu8i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu8i, Vp_Vp_BFu8i)
//============================================================================


struct  Vp_Vp_BFu8ll  {
  void *v1;
  void *v2;
  __tsu64 v3:8;
};
//SIG(1 Vp_Vp_BFu8ll) C1{ Fp[2] FL:8}



static void Test_Vp_Vp_BFu8ll()
{
  {
    init_simple_test("Vp_Vp_BFu8ll");
    static STRUCT_IF_C Vp_Vp_BFu8ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu8ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu8ll)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu8ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu8ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, 1, "Vp_Vp_BFu8ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, hide_ull(1LL<<7), "Vp_Vp_BFu8ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu8ll, Vp_Vp_BFu8ll)
//============================================================================


struct  Vp_Vp_BFu8s  {
  void *v1;
  void *v2;
  unsigned short v3:8;
};
//SIG(1 Vp_Vp_BFu8s) C1{ Fp[2] Fs:8}



static void Test_Vp_Vp_BFu8s()
{
  {
    init_simple_test("Vp_Vp_BFu8s");
    static STRUCT_IF_C Vp_Vp_BFu8s lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu8s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu8s)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu8s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu8s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, 1, "Vp_Vp_BFu8s");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 8, hide_ull(1LL<<7), "Vp_Vp_BFu8s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu8s, Vp_Vp_BFu8s)
//============================================================================


struct  Vp_Vp_BFu9i  {
  void *v1;
  void *v2;
  unsigned int v3:9;
};
//SIG(1 Vp_Vp_BFu9i) C1{ Fp[2] Fi:9}



static void Test_Vp_Vp_BFu9i()
{
  {
    init_simple_test("Vp_Vp_BFu9i");
    static STRUCT_IF_C Vp_Vp_BFu9i lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu9i)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu9i)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu9i.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu9i.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 9, 1, "Vp_Vp_BFu9i");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 9, hide_ull(1LL<<8), "Vp_Vp_BFu9i");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu9i, Vp_Vp_BFu9i)
//============================================================================


struct  Vp_Vp_BFu9ll  {
  void *v1;
  void *v2;
  __tsu64 v3:9;
};
//SIG(1 Vp_Vp_BFu9ll) C1{ Fp[2] FL:9}



static void Test_Vp_Vp_BFu9ll()
{
  {
    init_simple_test("Vp_Vp_BFu9ll");
    static STRUCT_IF_C Vp_Vp_BFu9ll lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu9ll)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu9ll)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu9ll.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu9ll.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 9, 1, "Vp_Vp_BFu9ll");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 9, hide_ull(1LL<<8), "Vp_Vp_BFu9ll");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu9ll, Vp_Vp_BFu9ll)
//============================================================================


struct  Vp_Vp_BFu9s  {
  void *v1;
  void *v2;
  unsigned short v3:9;
};
//SIG(1 Vp_Vp_BFu9s) C1{ Fp[2] Fs:9}



static void Test_Vp_Vp_BFu9s()
{
  {
    init_simple_test("Vp_Vp_BFu9s");
    static STRUCT_IF_C Vp_Vp_BFu9s lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_BFu9s)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_BFu9s)");
    check_field_offset(lv, v1, 0, "Vp_Vp_BFu9s.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_BFu9s.v2");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 9, 1, "Vp_Vp_BFu9s");
    set_bf_and_test(lv, v3, ABISELECT(16,8), 0, 9, hide_ull(1LL<<8), "Vp_Vp_BFu9s");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_BFu9s, Vp_Vp_BFu9s)
//============================================================================


struct  Vp_Vp_C  {
  void *v1;
  void *v2;
  char v3;
};
//SIG(1 Vp_Vp_C) C1{ Fp[2] Fc}



static void Test_Vp_Vp_C()
{
  {
    init_simple_test("Vp_Vp_C");
    STRUCT_IF_C Vp_Vp_C lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_C)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_C)");
    check_field_offset(lv, v1, 0, "Vp_Vp_C.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_C.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_C.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_C, Vp_Vp_C)
//============================================================================


struct  Vp_Vp_D  {
  void *v1;
  void *v2;
  double v3;
};
//SIG(1 Vp_Vp_D) C1{ Fp[2] FL}



static void Test_Vp_Vp_D()
{
  {
    init_simple_test("Vp_Vp_D");
    STRUCT_IF_C Vp_Vp_D lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Vp_D)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_D)");
    check_field_offset(lv, v1, 0, "Vp_Vp_D.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_D.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_D.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_D, Vp_Vp_D)
//============================================================================


struct  Vp_Vp_F  {
  void *v1;
  void *v2;
  float v3;
};
//SIG(1 Vp_Vp_F) C1{ Fp[2] Fi}



static void Test_Vp_Vp_F()
{
  {
    init_simple_test("Vp_Vp_F");
    STRUCT_IF_C Vp_Vp_F lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_F)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_F)");
    check_field_offset(lv, v1, 0, "Vp_Vp_F.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_F.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_F.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_F, Vp_Vp_F)
//============================================================================


struct  Vp_Vp_I  {
  void *v1;
  void *v2;
  int v3;
};
//SIG(1 Vp_Vp_I) C1{ Fp[2] Fi}



static void Test_Vp_Vp_I()
{
  {
    init_simple_test("Vp_Vp_I");
    STRUCT_IF_C Vp_Vp_I lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_I)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_I)");
    check_field_offset(lv, v1, 0, "Vp_Vp_I.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_I.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_I.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_I, Vp_Vp_I)
//============================================================================


struct  Vp_Vp_Ip  {
  void *v1;
  void *v2;
  int *v3;
};
//SIG(1 Vp_Vp_Ip) C1{ Fp[3]}



static void Test_Vp_Vp_Ip()
{
  {
    init_simple_test("Vp_Vp_Ip");
    STRUCT_IF_C Vp_Vp_Ip lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_Ip)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_Ip)");
    check_field_offset(lv, v1, 0, "Vp_Vp_Ip.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_Ip.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_Ip.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_Ip, Vp_Vp_Ip)
//============================================================================


struct  Vp_Vp_L  {
  void *v1;
  void *v2;
  __tsi64 v3;
};
//SIG(1 Vp_Vp_L) C1{ Fp[2] FL}



static void Test_Vp_Vp_L()
{
  {
    init_simple_test("Vp_Vp_L");
    STRUCT_IF_C Vp_Vp_L lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Vp_L)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_L)");
    check_field_offset(lv, v1, 0, "Vp_Vp_L.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_L.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_L.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_L, Vp_Vp_L)
//============================================================================


struct  Vp_Vp_S  {
  void *v1;
  void *v2;
  short v3;
};
//SIG(1 Vp_Vp_S) C1{ Fp[2] Fs}



static void Test_Vp_Vp_S()
{
  {
    init_simple_test("Vp_Vp_S");
    STRUCT_IF_C Vp_Vp_S lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_S)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_S)");
    check_field_offset(lv, v1, 0, "Vp_Vp_S.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_S.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_S.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_S, Vp_Vp_S)
//============================================================================


struct  Vp_Vp_Uc  {
  void *v1;
  void *v2;
  unsigned char v3;
};
//SIG(1 Vp_Vp_Uc) C1{ Fp[2] Fc}



static void Test_Vp_Vp_Uc()
{
  {
    init_simple_test("Vp_Vp_Uc");
    STRUCT_IF_C Vp_Vp_Uc lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_Uc)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_Uc)");
    check_field_offset(lv, v1, 0, "Vp_Vp_Uc.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_Uc.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_Uc.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_Uc, Vp_Vp_Uc)
//============================================================================


struct  Vp_Vp_Ui  {
  void *v1;
  void *v2;
  unsigned int v3;
};
//SIG(1 Vp_Vp_Ui) C1{ Fp[2] Fi}



static void Test_Vp_Vp_Ui()
{
  {
    init_simple_test("Vp_Vp_Ui");
    STRUCT_IF_C Vp_Vp_Ui lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_Ui)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_Ui)");
    check_field_offset(lv, v1, 0, "Vp_Vp_Ui.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_Ui.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_Ui.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_Ui, Vp_Vp_Ui)
//============================================================================


struct  Vp_Vp_Ul  {
  void *v1;
  void *v2;
  __tsu64 v3;
};
//SIG(1 Vp_Vp_Ul) C1{ Fp[2] FL}



static void Test_Vp_Vp_Ul()
{
  {
    init_simple_test("Vp_Vp_Ul");
    STRUCT_IF_C Vp_Vp_Ul lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(Vp_Vp_Ul)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_Ul)");
    check_field_offset(lv, v1, 0, "Vp_Vp_Ul.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_Ul.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_Ul.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_Ul, Vp_Vp_Ul)
//============================================================================


struct  Vp_Vp_Us  {
  void *v1;
  void *v2;
  unsigned short v3;
};
//SIG(1 Vp_Vp_Us) C1{ Fp[2] Fs}



static void Test_Vp_Vp_Us()
{
  {
    init_simple_test("Vp_Vp_Us");
    STRUCT_IF_C Vp_Vp_Us lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_Us)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_Us)");
    check_field_offset(lv, v1, 0, "Vp_Vp_Us.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_Us.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_Us.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_Us, Vp_Vp_Us)
//============================================================================


struct  Vp_Vp_Vp  {
  void *v1;
  void *v2;
  void *v3;
};
//SIG(1 Vp_Vp_Vp) C1{ Fp[3]}



static void Test_Vp_Vp_Vp()
{
  {
    init_simple_test("Vp_Vp_Vp");
    STRUCT_IF_C Vp_Vp_Vp lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Vp_Vp_Vp)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Vp_Vp_Vp)");
    check_field_offset(lv, v1, 0, "Vp_Vp_Vp.v1");
    check_field_offset(lv, v2, ABISELECT(8,4), "Vp_Vp_Vp.v2");
    check_field_offset(lv, v3, ABISELECT(16,8), "Vp_Vp_Vp.v3");
  }
}
ARRANGE_TO_CALL_ME(Test_Vp_Vp_Vp, Vp_Vp_Vp)
//============================================================================

