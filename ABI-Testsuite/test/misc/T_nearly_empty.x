// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: cxx_compiler cxx_rtti -c %s -I "common" -o %t2.o
// RUN: c_compiler -c %s -I "common" -o %t3.o
// RUN: linker -o %t2%exeext  %t1.o %t2.o %t3.o
// RUN: runtool %t2%exeext | checker "TEST PASSED"
#include "testsuite.h"
#ifdef __cplusplus

struct  em_0  {
};
//SIG(-1 em_0) C1{}



static void Test_em_0()
{
  {
    init_simple_test("em_0");
    em_0 lv;
    check2(sizeof(lv), 1, "sizeof(em_0)");
    check2(__alignof__(lv), 1, "__alignof__(em_0)");
  }
}
static Arrange_To_Call_Me vem_0(Test_em_0, "em_0", 1);

#else // __cplusplus

extern VTBL_ENTRY _ZTI4em_0[];
VTBL_ENTRY *P__ZTI4em_0 = _ZTI4em_0; 
Class_Descriptor cd_em_0 = {  "em_0", // class name
  0,0,//no base classes
  0, // no vftv
  0, //no vtt
  1, // object size
  NSPAIRA(_ZTI4em_0),ABISELECT(16,8), //typeinfo_var
  {0,0},0, // virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  em_1  {
};
//SIG(-1 em_1) C1{}



static void Test_em_1()
{
  {
    init_simple_test("em_1");
    em_1 lv;
    check2(sizeof(lv), 1, "sizeof(em_1)");
    check2(__alignof__(lv), 1, "__alignof__(em_1)");
  }
}
static Arrange_To_Call_Me vem_1(Test_em_1, "em_1", 1);

#else // __cplusplus

extern VTBL_ENTRY _ZTI4em_1[];
VTBL_ENTRY *P__ZTI4em_1 = _ZTI4em_1; 
Class_Descriptor cd_em_1 = {  "em_1", // class name
  0,0,//no base classes
  0, // no vftv
  0, //no vtt
  1, // object size
  NSPAIRA(_ZTI4em_1),ABISELECT(16,8), //typeinfo_var
  {0,0},0, // virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  ne_0  {
  void  foo(); // _ZN4ne_03fooEv
};
//SIG(-1 ne_0) C1{ m}


void  ne_0 ::foo(){}

static void Test_ne_0()
{
  {
    init_simple_test("ne_0");
    ne_0 lv;
    check2(sizeof(lv), 1, "sizeof(ne_0)");
    check2(__alignof__(lv), 1, "__alignof__(ne_0)");
  }
}
static Arrange_To_Call_Me vne_0(Test_ne_0, "ne_0", 1);

#else // __cplusplus

extern VTBL_ENTRY _ZTI4ne_0[];
VTBL_ENTRY *P__ZTI4ne_0 = _ZTI4ne_0; 
Class_Descriptor cd_ne_0 = {  "ne_0", // class name
  0,0,//no base classes
  0, // no vftv
  0, //no vtt
  1, // object size
  NSPAIRA(_ZTI4ne_0),ABISELECT(16,8), //typeinfo_var
  {0,0},0, // virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  ne_1  {
  int  :0;
  void  foo(); // _ZN4ne_13fooEv
};
//SIG(-1 ne_1) C1{ m Fi:0}


void  ne_1 ::foo(){}

static void Test_ne_1()
{
  {
    init_simple_test("ne_1");
    static ne_1 lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(ne_1)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(ne_1)");
  }
}
static Arrange_To_Call_Me vne_1(Test_ne_1, "ne_1", ABISELECT(1,1));

#else // __cplusplus

extern VTBL_ENTRY _ZTI4ne_1[];
VTBL_ENTRY *P__ZTI4ne_1 = _ZTI4ne_1; 
Class_Descriptor cd_ne_1 = {  "ne_1", // class name
  0,0,//no base classes
  0, // no vftv
  0, //no vtt
  ABISELECT(1,1), // object size
  NSPAIRA(_ZTI4ne_1),ABISELECT(16,8), //typeinfo_var
  {0,0},0, // virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  ne_2  {
  short  :0;
  int  :0;
  void  foo(); // _ZN4ne_23fooEv
};
//SIG(-1 ne_2) C1{ m Fs:0 Fi:0}


void  ne_2 ::foo(){}

static void Test_ne_2()
{
  {
    init_simple_test("ne_2");
    static ne_2 lv;
    check2(sizeof(lv), ABISELECT(1,1), "sizeof(ne_2)");
    check2(__alignof__(lv), ABISELECT(1,1), "__alignof__(ne_2)");
  }
}
static Arrange_To_Call_Me vne_2(Test_ne_2, "ne_2", ABISELECT(1,1));

#else // __cplusplus

extern VTBL_ENTRY _ZTI4ne_2[];
VTBL_ENTRY *P__ZTI4ne_2 = _ZTI4ne_2; 
Class_Descriptor cd_ne_2 = {  "ne_2", // class name
  0,0,//no base classes
  0, // no vftv
  0, //no vtt
  ABISELECT(1,1), // object size
  NSPAIRA(_ZTI4ne_2),ABISELECT(16,8), //typeinfo_var
  {0,0},0, // virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  xx  {
  int p;
};
//SIG(-1 xx) C1{ Fi}



static void Test_xx()
{
  {
    init_simple_test("xx");
    xx lv;
    check2(sizeof(lv), 4, "sizeof(xx)");
    check2(__alignof__(lv), 4, "__alignof__(xx)");
    check_field_offset(lv, p, 0, "xx.p");
  }
}
static Arrange_To_Call_Me vxx(Test_xx, "xx", 4);

#else // __cplusplus

extern VTBL_ENTRY _ZTI2xx[];
VTBL_ENTRY *P__ZTI2xx = _ZTI2xx; 
Class_Descriptor cd_xx = {  "xx", // class name
  0,0,//no base classes
  0, // no vftv
  0, //no vtt
  4, // object size
  NSPAIRA(_ZTI2xx),ABISELECT(16,8), //typeinfo_var
  {0,0},0, // virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t01  : em_0 {
  virtual void  bar(); // _ZN3t013barEv
  ~t01(); // tgen
  t01(); // tgen
};
//SIG(-1 t01) C1{ BC2{} v1}


void  t01 ::bar(){vfunc_called(this, "_ZN3t013barEv");}
t01 ::~t01(){ note_dtor("t01", this);} // tgen
t01 ::t01(){ note_ctor("t01", this);} // tgen

static void Test_t01()
{
  extern Class_Descriptor cd_t01;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t01, buf);
    t01 *dp, &lv = *(dp=new (buf) t01());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t01)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t01)");
    check_base_class_offset(lv, (em_0*), 0, "t01");
    test_class_info(&lv, &cd_t01);
    dp->~t01();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt01(Test_t01, "t01", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t01C1Ev();
extern void _ZN3t01D1Ev();
Name_Map name_map_t01[] = {
  NSPAIR(_ZN3t01C1Ev),
  NSPAIR(_ZN3t01D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
static Base_Class bases_t01[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t01[];
extern void _ZN3t013barEv();
static  VTBL_ENTRY vtc_t01[] = {
  0,
  (VTBL_ENTRY)&(_ZTI3t01[0]),
  (VTBL_ENTRY)&_ZN3t013barEv,
};
extern VTBL_ENTRY _ZTI3t01[];
extern  VTBL_ENTRY _ZTV3t01[];
Class_Descriptor cd_t01 = {  "t01", // class name
  bases_t01, 1,
  &(vtc_t01[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t01),ABISELECT(24,12), //typeinfo_var
  NSPAIRA(_ZTV3t01),3, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t02  : virtual em_0 {
  virtual void  bar(); // _ZN3t023barEv
  ~t02(); // tgen
  t02(); // tgen
};
//SIG(-1 t02) C1{ VBC2{} v1}


void  t02 ::bar(){vfunc_called(this, "_ZN3t023barEv");}
t02 ::~t02(){ note_dtor("t02", this);} // tgen
t02 ::t02(){ note_ctor("t02", this);} // tgen

static void Test_t02()
{
  extern Class_Descriptor cd_t02;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t02, buf);
    t02 *dp, &lv = *(dp=new (buf) t02());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t02)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t02)");
    check_base_class_offset(lv, (em_0*), 0, "t02");
    test_class_info(&lv, &cd_t02);
    dp->~t02();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt02(Test_t02, "t02", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t02C1Ev();
extern void _ZN3t02D1Ev();
Name_Map name_map_t02[] = {
  NSPAIR(_ZN3t02C1Ev),
  NSPAIR(_ZN3t02D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
static Base_Class bases_t02[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t02[];
extern void _ZN3t023barEv();
static  VTBL_ENTRY vtc_t02[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t02[0]),
  (VTBL_ENTRY)&_ZN3t023barEv,
};
extern VTBL_ENTRY _ZTV3t02[];
static  VTT_ENTRY vtt_t02[] = {
  {&(_ZTV3t02[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t02[];
extern  VTBL_ENTRY _ZTV3t02[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t02[];
Class_Descriptor cd_t02 = {  "t02", // class name
  bases_t02, 1,
  &(vtc_t02[0]), // expected_vtbl_contents
  &(vtt_t02[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t02),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV3t02),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t02),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t03  : em_0 , em_1 {
  virtual void  bar(); // _ZN3t033barEv
  ~t03(); // tgen
  t03(); // tgen
};
//SIG(-1 t03) C1{ BC2{} BC3{} v1}


void  t03 ::bar(){vfunc_called(this, "_ZN3t033barEv");}
t03 ::~t03(){ note_dtor("t03", this);} // tgen
t03 ::t03(){ note_ctor("t03", this);} // tgen

static void Test_t03()
{
  extern Class_Descriptor cd_t03;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t03, buf);
    t03 *dp, &lv = *(dp=new (buf) t03());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t03)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t03)");
    check_base_class_offset(lv, (em_0*), 0, "t03");
    check_base_class_offset(lv, (em_1*), 0, "t03");
    test_class_info(&lv, &cd_t03);
    dp->~t03();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt03(Test_t03, "t03", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t03C1Ev();
extern void _ZN3t03D1Ev();
Name_Map name_map_t03[] = {
  NSPAIR(_ZN3t03C1Ev),
  NSPAIR(_ZN3t03D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
static Base_Class bases_t03[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t03[];
extern void _ZN3t033barEv();
static  VTBL_ENTRY vtc_t03[] = {
  0,
  (VTBL_ENTRY)&(_ZTI3t03[0]),
  (VTBL_ENTRY)&_ZN3t033barEv,
};
extern VTBL_ENTRY _ZTI3t03[];
extern  VTBL_ENTRY _ZTV3t03[];
Class_Descriptor cd_t03 = {  "t03", // class name
  bases_t03, 2,
  &(vtc_t03[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t03),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t03),3, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t04  : virtual em_0 , em_1 {
  virtual void  bar(); // _ZN3t043barEv
  ~t04(); // tgen
  t04(); // tgen
};
//SIG(-1 t04) C1{ VBC2{} BC3{} v1}


void  t04 ::bar(){vfunc_called(this, "_ZN3t043barEv");}
t04 ::~t04(){ note_dtor("t04", this);} // tgen
t04 ::t04(){ note_ctor("t04", this);} // tgen

static void Test_t04()
{
  extern Class_Descriptor cd_t04;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t04, buf);
    t04 *dp, &lv = *(dp=new (buf) t04());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t04)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t04)");
    check_base_class_offset(lv, (em_0*), 0, "t04");
    check_base_class_offset(lv, (em_1*), 0, "t04");
    test_class_info(&lv, &cd_t04);
    dp->~t04();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt04(Test_t04, "t04", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t04C1Ev();
extern void _ZN3t04D1Ev();
Name_Map name_map_t04[] = {
  NSPAIR(_ZN3t04C1Ev),
  NSPAIR(_ZN3t04D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
static Base_Class bases_t04[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t04[];
extern void _ZN3t043barEv();
static  VTBL_ENTRY vtc_t04[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t04[0]),
  (VTBL_ENTRY)&_ZN3t043barEv,
};
extern VTBL_ENTRY _ZTV3t04[];
static  VTT_ENTRY vtt_t04[] = {
  {&(_ZTV3t04[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t04[];
extern  VTBL_ENTRY _ZTV3t04[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t04[];
Class_Descriptor cd_t04 = {  "t04", // class name
  bases_t04, 2,
  &(vtc_t04[0]), // expected_vtbl_contents
  &(vtt_t04[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t04),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t04),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t04),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t05  : em_0 , virtual em_1 {
  virtual void  bar(); // _ZN3t053barEv
  ~t05(); // tgen
  t05(); // tgen
};
//SIG(-1 t05) C1{ BC2{} VBC3{} v1}


void  t05 ::bar(){vfunc_called(this, "_ZN3t053barEv");}
t05 ::~t05(){ note_dtor("t05", this);} // tgen
t05 ::t05(){ note_ctor("t05", this);} // tgen

static void Test_t05()
{
  extern Class_Descriptor cd_t05;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t05, buf);
    t05 *dp, &lv = *(dp=new (buf) t05());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t05)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t05)");
    check_base_class_offset(lv, (em_0*), 0, "t05");
    check_base_class_offset(lv, (em_1*), 0, "t05");
    test_class_info(&lv, &cd_t05);
    dp->~t05();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt05(Test_t05, "t05", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t05C1Ev();
extern void _ZN3t05D1Ev();
Name_Map name_map_t05[] = {
  NSPAIR(_ZN3t05C1Ev),
  NSPAIR(_ZN3t05D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
static Base_Class bases_t05[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t05[];
extern void _ZN3t053barEv();
static  VTBL_ENTRY vtc_t05[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t05[0]),
  (VTBL_ENTRY)&_ZN3t053barEv,
};
extern VTBL_ENTRY _ZTV3t05[];
static  VTT_ENTRY vtt_t05[] = {
  {&(_ZTV3t05[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t05[];
extern  VTBL_ENTRY _ZTV3t05[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t05[];
Class_Descriptor cd_t05 = {  "t05", // class name
  bases_t05, 2,
  &(vtc_t05[0]), // expected_vtbl_contents
  &(vtt_t05[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t05),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t05),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t05),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t06  : virtual em_0 , virtual em_1 {
  virtual void  bar(); // _ZN3t063barEv
  ~t06(); // tgen
  t06(); // tgen
};
//SIG(-1 t06) C1{ VBC2{} VBC3{} v1}


void  t06 ::bar(){vfunc_called(this, "_ZN3t063barEv");}
t06 ::~t06(){ note_dtor("t06", this);} // tgen
t06 ::t06(){ note_ctor("t06", this);} // tgen

static void Test_t06()
{
  extern Class_Descriptor cd_t06;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t06, buf);
    t06 *dp, &lv = *(dp=new (buf) t06());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t06)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t06)");
    check_base_class_offset(lv, (em_0*), 0, "t06");
    check_base_class_offset(lv, (em_1*), 0, "t06");
    test_class_info(&lv, &cd_t06);
    dp->~t06();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt06(Test_t06, "t06", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t06C1Ev();
extern void _ZN3t06D1Ev();
Name_Map name_map_t06[] = {
  NSPAIR(_ZN3t06C1Ev),
  NSPAIR(_ZN3t06D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
static Base_Class bases_t06[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t06[];
extern void _ZN3t063barEv();
static  VTBL_ENTRY vtc_t06[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t06[0]),
  (VTBL_ENTRY)&_ZN3t063barEv,
};
extern VTBL_ENTRY _ZTV3t06[];
static  VTT_ENTRY vtt_t06[] = {
  {&(_ZTV3t06[4]),  4,5},
};
extern VTBL_ENTRY _ZTI3t06[];
extern  VTBL_ENTRY _ZTV3t06[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t06[];
Class_Descriptor cd_t06 = {  "t06", // class name
  bases_t06, 2,
  &(vtc_t06[0]), // expected_vtbl_contents
  &(vtt_t06[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t06),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t06),5, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t06),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t07  : em_0 , ne_1 {
  virtual void  bar(); // _ZN3t073barEv
  ~t07(); // tgen
  t07(); // tgen
};
//SIG(-1 t07) C1{ BC2{} BC3{ m Fi:0} v1}


void  t07 ::bar(){vfunc_called(this, "_ZN3t073barEv");}
t07 ::~t07(){ note_dtor("t07", this);} // tgen
t07 ::t07(){ note_ctor("t07", this);} // tgen

static void Test_t07()
{
  extern Class_Descriptor cd_t07;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t07, buf);
    t07 *dp, &lv = *(dp=new (buf) t07());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t07)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t07)");
    check_base_class_offset(lv, (em_0*), 0, "t07");
    check_base_class_offset(lv, (ne_1*), 0, "t07");
    test_class_info(&lv, &cd_t07);
    dp->~t07();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt07(Test_t07, "t07", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t07C1Ev();
extern void _ZN3t07D1Ev();
Name_Map name_map_t07[] = {
  NSPAIR(_ZN3t07C1Ev),
  NSPAIR(_ZN3t07D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_t07[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t07[];
extern void _ZN3t073barEv();
static  VTBL_ENTRY vtc_t07[] = {
  0,
  (VTBL_ENTRY)&(_ZTI3t07[0]),
  (VTBL_ENTRY)&_ZN3t073barEv,
};
extern VTBL_ENTRY _ZTI3t07[];
extern  VTBL_ENTRY _ZTV3t07[];
Class_Descriptor cd_t07 = {  "t07", // class name
  bases_t07, 2,
  &(vtc_t07[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t07),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t07),3, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t08  : virtual em_0 , ne_1 {
  virtual void  bar(); // _ZN3t083barEv
  ~t08(); // tgen
  t08(); // tgen
};
//SIG(-1 t08) C1{ VBC2{} BC3{ m Fi:0} v1}


void  t08 ::bar(){vfunc_called(this, "_ZN3t083barEv");}
t08 ::~t08(){ note_dtor("t08", this);} // tgen
t08 ::t08(){ note_ctor("t08", this);} // tgen

static void Test_t08()
{
  extern Class_Descriptor cd_t08;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t08, buf);
    t08 *dp, &lv = *(dp=new (buf) t08());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t08)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t08)");
    check_base_class_offset(lv, (em_0*), 0, "t08");
    check_base_class_offset(lv, (ne_1*), 0, "t08");
    test_class_info(&lv, &cd_t08);
    dp->~t08();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt08(Test_t08, "t08", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t08C1Ev();
extern void _ZN3t08D1Ev();
Name_Map name_map_t08[] = {
  NSPAIR(_ZN3t08C1Ev),
  NSPAIR(_ZN3t08D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_t08[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t08[];
extern void _ZN3t083barEv();
static  VTBL_ENTRY vtc_t08[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t08[0]),
  (VTBL_ENTRY)&_ZN3t083barEv,
};
extern VTBL_ENTRY _ZTV3t08[];
static  VTT_ENTRY vtt_t08[] = {
  {&(_ZTV3t08[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t08[];
extern  VTBL_ENTRY _ZTV3t08[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t08[];
Class_Descriptor cd_t08 = {  "t08", // class name
  bases_t08, 2,
  &(vtc_t08[0]), // expected_vtbl_contents
  &(vtt_t08[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t08),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t08),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t08),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t09  : em_0 , virtual ne_1 {
  virtual void  bar(); // _ZN3t093barEv
  ~t09(); // tgen
  t09(); // tgen
};
//SIG(-1 t09) C1{ BC2{} VBC3{ m Fi:0} v1}


void  t09 ::bar(){vfunc_called(this, "_ZN3t093barEv");}
t09 ::~t09(){ note_dtor("t09", this);} // tgen
t09 ::t09(){ note_ctor("t09", this);} // tgen

static void Test_t09()
{
  extern Class_Descriptor cd_t09;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t09, buf);
    t09 *dp, &lv = *(dp=new (buf) t09());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t09)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t09)");
    check_base_class_offset(lv, (em_0*), 0, "t09");
    check_base_class_offset(lv, (ne_1*), 0, "t09");
    test_class_info(&lv, &cd_t09);
    dp->~t09();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt09(Test_t09, "t09", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t09C1Ev();
extern void _ZN3t09D1Ev();
Name_Map name_map_t09[] = {
  NSPAIR(_ZN3t09C1Ev),
  NSPAIR(_ZN3t09D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_t09[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t09[];
extern void _ZN3t093barEv();
static  VTBL_ENTRY vtc_t09[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t09[0]),
  (VTBL_ENTRY)&_ZN3t093barEv,
};
extern VTBL_ENTRY _ZTV3t09[];
static  VTT_ENTRY vtt_t09[] = {
  {&(_ZTV3t09[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t09[];
extern  VTBL_ENTRY _ZTV3t09[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t09[];
Class_Descriptor cd_t09 = {  "t09", // class name
  bases_t09, 2,
  &(vtc_t09[0]), // expected_vtbl_contents
  &(vtt_t09[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t09),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t09),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t09),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t00  : virtual em_0 , virtual ne_1 {
  virtual void  bar(); // _ZN3t003barEv
  ~t00(); // tgen
  t00(); // tgen
};
//SIG(-1 t00) C1{ VBC2{} VBC3{ m Fi:0} v1}


void  t00 ::bar(){vfunc_called(this, "_ZN3t003barEv");}
t00 ::~t00(){ note_dtor("t00", this);} // tgen
t00 ::t00(){ note_ctor("t00", this);} // tgen

static void Test_t00()
{
  extern Class_Descriptor cd_t00;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t00, buf);
    t00 *dp, &lv = *(dp=new (buf) t00());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t00)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t00)");
    check_base_class_offset(lv, (em_0*), 0, "t00");
    check_base_class_offset(lv, (ne_1*), 0, "t00");
    test_class_info(&lv, &cd_t00);
    dp->~t00();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt00(Test_t00, "t00", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t00C1Ev();
extern void _ZN3t00D1Ev();
Name_Map name_map_t00[] = {
  NSPAIR(_ZN3t00C1Ev),
  NSPAIR(_ZN3t00D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_t00[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t00[];
extern void _ZN3t003barEv();
static  VTBL_ENTRY vtc_t00[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t00[0]),
  (VTBL_ENTRY)&_ZN3t003barEv,
};
extern VTBL_ENTRY _ZTV3t00[];
static  VTT_ENTRY vtt_t00[] = {
  {&(_ZTV3t00[4]),  4,5},
};
extern VTBL_ENTRY _ZTI3t00[];
extern  VTBL_ENTRY _ZTV3t00[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t00[];
Class_Descriptor cd_t00 = {  "t00", // class name
  bases_t00, 2,
  &(vtc_t00[0]), // expected_vtbl_contents
  &(vtt_t00[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t00),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t00),5, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t00),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t11  : ne_0 {
  virtual void  bar(); // _ZN3t113barEv
  ~t11(); // tgen
  t11(); // tgen
};
//SIG(-1 t11) C1{ BC2{ m} v1}


void  t11 ::bar(){vfunc_called(this, "_ZN3t113barEv");}
t11 ::~t11(){ note_dtor("t11", this);} // tgen
t11 ::t11(){ note_ctor("t11", this);} // tgen

static void Test_t11()
{
  extern Class_Descriptor cd_t11;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t11, buf);
    t11 *dp, &lv = *(dp=new (buf) t11());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t11)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t11)");
    check_base_class_offset(lv, (ne_0*), 0, "t11");
    test_class_info(&lv, &cd_t11);
    dp->~t11();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt11(Test_t11, "t11", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t11C1Ev();
extern void _ZN3t11D1Ev();
Name_Map name_map_t11[] = {
  NSPAIR(_ZN3t11C1Ev),
  NSPAIR(_ZN3t11D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
static Base_Class bases_t11[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t11[];
extern void _ZN3t113barEv();
static  VTBL_ENTRY vtc_t11[] = {
  0,
  (VTBL_ENTRY)&(_ZTI3t11[0]),
  (VTBL_ENTRY)&_ZN3t113barEv,
};
extern VTBL_ENTRY _ZTI3t11[];
extern  VTBL_ENTRY _ZTV3t11[];
Class_Descriptor cd_t11 = {  "t11", // class name
  bases_t11, 1,
  &(vtc_t11[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t11),ABISELECT(24,12), //typeinfo_var
  NSPAIRA(_ZTV3t11),3, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t12  : virtual ne_0 {
  virtual void  bar(); // _ZN3t123barEv
  ~t12(); // tgen
  t12(); // tgen
};
//SIG(-1 t12) C1{ VBC2{ m} v1}


void  t12 ::bar(){vfunc_called(this, "_ZN3t123barEv");}
t12 ::~t12(){ note_dtor("t12", this);} // tgen
t12 ::t12(){ note_ctor("t12", this);} // tgen

static void Test_t12()
{
  extern Class_Descriptor cd_t12;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t12, buf);
    t12 *dp, &lv = *(dp=new (buf) t12());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t12)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t12)");
    check_base_class_offset(lv, (ne_0*), 0, "t12");
    test_class_info(&lv, &cd_t12);
    dp->~t12();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt12(Test_t12, "t12", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t12C1Ev();
extern void _ZN3t12D1Ev();
Name_Map name_map_t12[] = {
  NSPAIR(_ZN3t12C1Ev),
  NSPAIR(_ZN3t12D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
static Base_Class bases_t12[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t12[];
extern void _ZN3t123barEv();
static  VTBL_ENTRY vtc_t12[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t12[0]),
  (VTBL_ENTRY)&_ZN3t123barEv,
};
extern VTBL_ENTRY _ZTV3t12[];
static  VTT_ENTRY vtt_t12[] = {
  {&(_ZTV3t12[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t12[];
extern  VTBL_ENTRY _ZTV3t12[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t12[];
Class_Descriptor cd_t12 = {  "t12", // class name
  bases_t12, 1,
  &(vtc_t12[0]), // expected_vtbl_contents
  &(vtt_t12[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t12),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV3t12),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t12),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t13  : ne_0 , em_1 {
  virtual void  bar(); // _ZN3t133barEv
  ~t13(); // tgen
  t13(); // tgen
};
//SIG(-1 t13) C1{ BC2{ m} BC3{} v1}


void  t13 ::bar(){vfunc_called(this, "_ZN3t133barEv");}
t13 ::~t13(){ note_dtor("t13", this);} // tgen
t13 ::t13(){ note_ctor("t13", this);} // tgen

static void Test_t13()
{
  extern Class_Descriptor cd_t13;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t13, buf);
    t13 *dp, &lv = *(dp=new (buf) t13());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t13)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t13)");
    check_base_class_offset(lv, (ne_0*), 0, "t13");
    check_base_class_offset(lv, (em_1*), 0, "t13");
    test_class_info(&lv, &cd_t13);
    dp->~t13();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt13(Test_t13, "t13", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t13C1Ev();
extern void _ZN3t13D1Ev();
Name_Map name_map_t13[] = {
  NSPAIR(_ZN3t13C1Ev),
  NSPAIR(_ZN3t13D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
static Base_Class bases_t13[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t13[];
extern void _ZN3t133barEv();
static  VTBL_ENTRY vtc_t13[] = {
  0,
  (VTBL_ENTRY)&(_ZTI3t13[0]),
  (VTBL_ENTRY)&_ZN3t133barEv,
};
extern VTBL_ENTRY _ZTI3t13[];
extern  VTBL_ENTRY _ZTV3t13[];
Class_Descriptor cd_t13 = {  "t13", // class name
  bases_t13, 2,
  &(vtc_t13[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t13),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t13),3, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t14  : virtual ne_0 , em_1 {
  virtual void  bar(); // _ZN3t143barEv
  ~t14(); // tgen
  t14(); // tgen
};
//SIG(-1 t14) C1{ VBC2{ m} BC3{} v1}


void  t14 ::bar(){vfunc_called(this, "_ZN3t143barEv");}
t14 ::~t14(){ note_dtor("t14", this);} // tgen
t14 ::t14(){ note_ctor("t14", this);} // tgen

static void Test_t14()
{
  extern Class_Descriptor cd_t14;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t14, buf);
    t14 *dp, &lv = *(dp=new (buf) t14());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t14)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t14)");
    check_base_class_offset(lv, (ne_0*), 0, "t14");
    check_base_class_offset(lv, (em_1*), 0, "t14");
    test_class_info(&lv, &cd_t14);
    dp->~t14();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt14(Test_t14, "t14", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t14C1Ev();
extern void _ZN3t14D1Ev();
Name_Map name_map_t14[] = {
  NSPAIR(_ZN3t14C1Ev),
  NSPAIR(_ZN3t14D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
static Base_Class bases_t14[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t14[];
extern void _ZN3t143barEv();
static  VTBL_ENTRY vtc_t14[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t14[0]),
  (VTBL_ENTRY)&_ZN3t143barEv,
};
extern VTBL_ENTRY _ZTV3t14[];
static  VTT_ENTRY vtt_t14[] = {
  {&(_ZTV3t14[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t14[];
extern  VTBL_ENTRY _ZTV3t14[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t14[];
Class_Descriptor cd_t14 = {  "t14", // class name
  bases_t14, 2,
  &(vtc_t14[0]), // expected_vtbl_contents
  &(vtt_t14[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t14),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t14),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t14),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t15  : ne_0 , virtual em_1 {
  virtual void  bar(); // _ZN3t153barEv
  ~t15(); // tgen
  t15(); // tgen
};
//SIG(-1 t15) C1{ BC2{ m} VBC3{} v1}


void  t15 ::bar(){vfunc_called(this, "_ZN3t153barEv");}
t15 ::~t15(){ note_dtor("t15", this);} // tgen
t15 ::t15(){ note_ctor("t15", this);} // tgen

static void Test_t15()
{
  extern Class_Descriptor cd_t15;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t15, buf);
    t15 *dp, &lv = *(dp=new (buf) t15());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t15)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t15)");
    check_base_class_offset(lv, (ne_0*), 0, "t15");
    check_base_class_offset(lv, (em_1*), 0, "t15");
    test_class_info(&lv, &cd_t15);
    dp->~t15();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt15(Test_t15, "t15", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t15C1Ev();
extern void _ZN3t15D1Ev();
Name_Map name_map_t15[] = {
  NSPAIR(_ZN3t15C1Ev),
  NSPAIR(_ZN3t15D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
static Base_Class bases_t15[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t15[];
extern void _ZN3t153barEv();
static  VTBL_ENTRY vtc_t15[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t15[0]),
  (VTBL_ENTRY)&_ZN3t153barEv,
};
extern VTBL_ENTRY _ZTV3t15[];
static  VTT_ENTRY vtt_t15[] = {
  {&(_ZTV3t15[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t15[];
extern  VTBL_ENTRY _ZTV3t15[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t15[];
Class_Descriptor cd_t15 = {  "t15", // class name
  bases_t15, 2,
  &(vtc_t15[0]), // expected_vtbl_contents
  &(vtt_t15[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t15),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t15),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t15),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t16  : virtual ne_0 , virtual em_1 {
  virtual void  bar(); // _ZN3t163barEv
  ~t16(); // tgen
  t16(); // tgen
};
//SIG(-1 t16) C1{ VBC2{ m} VBC3{} v1}


void  t16 ::bar(){vfunc_called(this, "_ZN3t163barEv");}
t16 ::~t16(){ note_dtor("t16", this);} // tgen
t16 ::t16(){ note_ctor("t16", this);} // tgen

static void Test_t16()
{
  extern Class_Descriptor cd_t16;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t16, buf);
    t16 *dp, &lv = *(dp=new (buf) t16());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t16)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t16)");
    check_base_class_offset(lv, (ne_0*), 0, "t16");
    check_base_class_offset(lv, (em_1*), 0, "t16");
    test_class_info(&lv, &cd_t16);
    dp->~t16();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt16(Test_t16, "t16", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t16C1Ev();
extern void _ZN3t16D1Ev();
Name_Map name_map_t16[] = {
  NSPAIR(_ZN3t16C1Ev),
  NSPAIR(_ZN3t16D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
static Base_Class bases_t16[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t16[];
extern void _ZN3t163barEv();
static  VTBL_ENTRY vtc_t16[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t16[0]),
  (VTBL_ENTRY)&_ZN3t163barEv,
};
extern VTBL_ENTRY _ZTV3t16[];
static  VTT_ENTRY vtt_t16[] = {
  {&(_ZTV3t16[4]),  4,5},
};
extern VTBL_ENTRY _ZTI3t16[];
extern  VTBL_ENTRY _ZTV3t16[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t16[];
Class_Descriptor cd_t16 = {  "t16", // class name
  bases_t16, 2,
  &(vtc_t16[0]), // expected_vtbl_contents
  &(vtt_t16[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t16),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t16),5, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t16),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t17  : ne_0 , ne_1 {
  virtual void  bar(); // _ZN3t173barEv
  ~t17(); // tgen
  t17(); // tgen
};
//SIG(-1 t17) C1{ BC2{ m} BC3{ m Fi:0} v1}


void  t17 ::bar(){vfunc_called(this, "_ZN3t173barEv");}
t17 ::~t17(){ note_dtor("t17", this);} // tgen
t17 ::t17(){ note_ctor("t17", this);} // tgen

static void Test_t17()
{
  extern Class_Descriptor cd_t17;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t17, buf);
    t17 *dp, &lv = *(dp=new (buf) t17());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t17)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t17)");
    check_base_class_offset(lv, (ne_0*), 0, "t17");
    check_base_class_offset(lv, (ne_1*), 0, "t17");
    test_class_info(&lv, &cd_t17);
    dp->~t17();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt17(Test_t17, "t17", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t17C1Ev();
extern void _ZN3t17D1Ev();
Name_Map name_map_t17[] = {
  NSPAIR(_ZN3t17C1Ev),
  NSPAIR(_ZN3t17D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_t17[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t17[];
extern void _ZN3t173barEv();
static  VTBL_ENTRY vtc_t17[] = {
  0,
  (VTBL_ENTRY)&(_ZTI3t17[0]),
  (VTBL_ENTRY)&_ZN3t173barEv,
};
extern VTBL_ENTRY _ZTI3t17[];
extern  VTBL_ENTRY _ZTV3t17[];
Class_Descriptor cd_t17 = {  "t17", // class name
  bases_t17, 2,
  &(vtc_t17[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t17),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t17),3, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t18  : virtual ne_0 , ne_1 {
  virtual void  bar(); // _ZN3t183barEv
  ~t18(); // tgen
  t18(); // tgen
};
//SIG(-1 t18) C1{ VBC2{ m} BC3{ m Fi:0} v1}


void  t18 ::bar(){vfunc_called(this, "_ZN3t183barEv");}
t18 ::~t18(){ note_dtor("t18", this);} // tgen
t18 ::t18(){ note_ctor("t18", this);} // tgen

static void Test_t18()
{
  extern Class_Descriptor cd_t18;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t18, buf);
    t18 *dp, &lv = *(dp=new (buf) t18());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t18)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t18)");
    check_base_class_offset(lv, (ne_0*), 0, "t18");
    check_base_class_offset(lv, (ne_1*), 0, "t18");
    test_class_info(&lv, &cd_t18);
    dp->~t18();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt18(Test_t18, "t18", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t18C1Ev();
extern void _ZN3t18D1Ev();
Name_Map name_map_t18[] = {
  NSPAIR(_ZN3t18C1Ev),
  NSPAIR(_ZN3t18D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_t18[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t18[];
extern void _ZN3t183barEv();
static  VTBL_ENTRY vtc_t18[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t18[0]),
  (VTBL_ENTRY)&_ZN3t183barEv,
};
extern VTBL_ENTRY _ZTV3t18[];
static  VTT_ENTRY vtt_t18[] = {
  {&(_ZTV3t18[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t18[];
extern  VTBL_ENTRY _ZTV3t18[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t18[];
Class_Descriptor cd_t18 = {  "t18", // class name
  bases_t18, 2,
  &(vtc_t18[0]), // expected_vtbl_contents
  &(vtt_t18[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t18),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t18),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t18),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t19  : ne_0 , virtual ne_1 {
  virtual void  bar(); // _ZN3t193barEv
  ~t19(); // tgen
  t19(); // tgen
};
//SIG(-1 t19) C1{ BC2{ m} VBC3{ m Fi:0} v1}


void  t19 ::bar(){vfunc_called(this, "_ZN3t193barEv");}
t19 ::~t19(){ note_dtor("t19", this);} // tgen
t19 ::t19(){ note_ctor("t19", this);} // tgen

static void Test_t19()
{
  extern Class_Descriptor cd_t19;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t19, buf);
    t19 *dp, &lv = *(dp=new (buf) t19());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t19)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t19)");
    check_base_class_offset(lv, (ne_0*), 0, "t19");
    check_base_class_offset(lv, (ne_1*), 0, "t19");
    test_class_info(&lv, &cd_t19);
    dp->~t19();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt19(Test_t19, "t19", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t19C1Ev();
extern void _ZN3t19D1Ev();
Name_Map name_map_t19[] = {
  NSPAIR(_ZN3t19C1Ev),
  NSPAIR(_ZN3t19D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_t19[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t19[];
extern void _ZN3t193barEv();
static  VTBL_ENTRY vtc_t19[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t19[0]),
  (VTBL_ENTRY)&_ZN3t193barEv,
};
extern VTBL_ENTRY _ZTV3t19[];
static  VTT_ENTRY vtt_t19[] = {
  {&(_ZTV3t19[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t19[];
extern  VTBL_ENTRY _ZTV3t19[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t19[];
Class_Descriptor cd_t19 = {  "t19", // class name
  bases_t19, 2,
  &(vtc_t19[0]), // expected_vtbl_contents
  &(vtt_t19[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t19),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t19),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t19),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t20  : virtual ne_0 , virtual ne_1 {
  virtual void  bar(); // _ZN3t203barEv
  ~t20(); // tgen
  t20(); // tgen
};
//SIG(-1 t20) C1{ VBC2{ m} VBC3{ m Fi:0} v1}


void  t20 ::bar(){vfunc_called(this, "_ZN3t203barEv");}
t20 ::~t20(){ note_dtor("t20", this);} // tgen
t20 ::t20(){ note_ctor("t20", this);} // tgen

static void Test_t20()
{
  extern Class_Descriptor cd_t20;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_t20, buf);
    t20 *dp, &lv = *(dp=new (buf) t20());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(t20)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t20)");
    check_base_class_offset(lv, (ne_0*), 0, "t20");
    check_base_class_offset(lv, (ne_1*), 0, "t20");
    test_class_info(&lv, &cd_t20);
    dp->~t20();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt20(Test_t20, "t20", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN3t20C1Ev();
extern void _ZN3t20D1Ev();
Name_Map name_map_t20[] = {
  NSPAIR(_ZN3t20C1Ev),
  NSPAIR(_ZN3t20D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_t20[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t20[];
extern void _ZN3t203barEv();
static  VTBL_ENTRY vtc_t20[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t20[0]),
  (VTBL_ENTRY)&_ZN3t203barEv,
};
extern VTBL_ENTRY _ZTV3t20[];
static  VTT_ENTRY vtt_t20[] = {
  {&(_ZTV3t20[4]),  4,5},
};
extern VTBL_ENTRY _ZTI3t20[];
extern  VTBL_ENTRY _ZTV3t20[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t20[];
Class_Descriptor cd_t20 = {  "t20", // class name
  bases_t20, 2,
  &(vtc_t20[0]), // expected_vtbl_contents
  &(vtt_t20[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI3t20),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t20),5, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t20),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t21  : xx {
  virtual void  bar(); // _ZN3t213barEv
  ~t21(); // tgen
  t21(); // tgen
};
//SIG(-1 t21) C1{ BC2{ Fi} v1}


void  t21 ::bar(){vfunc_called(this, "_ZN3t213barEv");}
t21 ::~t21(){ note_dtor("t21", this);} // tgen
t21 ::t21(){ note_ctor("t21", this);} // tgen

static void Test_t21()
{
  extern Class_Descriptor cd_t21;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_t21, buf);
    t21 *dp, &lv = *(dp=new (buf) t21());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(t21)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t21)");
    check_base_class_offset(lv, (xx*), ABISELECT(8,4), "t21");
    test_class_info(&lv, &cd_t21);
    dp->~t21();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt21(Test_t21, "t21", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN3t21C1Ev();
extern void _ZN3t21D1Ev();
Name_Map name_map_t21[] = {
  NSPAIR(_ZN3t21C1Ev),
  NSPAIR(_ZN3t21D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
static Base_Class bases_t21[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t21[];
extern void _ZN3t213barEv();
static  VTBL_ENTRY vtc_t21[] = {
  0,
  (VTBL_ENTRY)&(_ZTI3t21[0]),
  (VTBL_ENTRY)&_ZN3t213barEv,
};
extern VTBL_ENTRY _ZTI3t21[];
extern  VTBL_ENTRY _ZTV3t21[];
Class_Descriptor cd_t21 = {  "t21", // class name
  bases_t21, 1,
  &(vtc_t21[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI3t21),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV3t21),3, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t22  : virtual xx {
  virtual void  bar(); // _ZN3t223barEv
  ~t22(); // tgen
  t22(); // tgen
};
//SIG(-1 t22) C1{ VBC2{ Fi} v1}


void  t22 ::bar(){vfunc_called(this, "_ZN3t223barEv");}
t22 ::~t22(){ note_dtor("t22", this);} // tgen
t22 ::t22(){ note_ctor("t22", this);} // tgen

static void Test_t22()
{
  extern Class_Descriptor cd_t22;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_t22, buf);
    t22 *dp, &lv = *(dp=new (buf) t22());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(t22)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t22)");
    check_base_class_offset(lv, (xx*), ABISELECT(8,4), "t22");
    test_class_info(&lv, &cd_t22);
    dp->~t22();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt22(Test_t22, "t22", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN3t22C1Ev();
extern void _ZN3t22D1Ev();
Name_Map name_map_t22[] = {
  NSPAIR(_ZN3t22C1Ev),
  NSPAIR(_ZN3t22D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
static Base_Class bases_t22[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t22[];
extern void _ZN3t223barEv();
static  VTBL_ENTRY vtc_t22[] = {
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI3t22[0]),
  (VTBL_ENTRY)&_ZN3t223barEv,
};
extern VTBL_ENTRY _ZTV3t22[];
static  VTT_ENTRY vtt_t22[] = {
  {&(_ZTV3t22[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t22[];
extern  VTBL_ENTRY _ZTV3t22[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t22[];
Class_Descriptor cd_t22 = {  "t22", // class name
  bases_t22, 1,
  &(vtc_t22[0]), // expected_vtbl_contents
  &(vtt_t22[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI3t22),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV3t22),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t22),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t23  : xx , em_1 {
  virtual void  bar(); // _ZN3t233barEv
  ~t23(); // tgen
  t23(); // tgen
};
//SIG(-1 t23) C1{ BC2{ Fi} BC3{} v1}


void  t23 ::bar(){vfunc_called(this, "_ZN3t233barEv");}
t23 ::~t23(){ note_dtor("t23", this);} // tgen
t23 ::t23(){ note_ctor("t23", this);} // tgen

static void Test_t23()
{
  extern Class_Descriptor cd_t23;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_t23, buf);
    t23 *dp, &lv = *(dp=new (buf) t23());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(t23)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t23)");
    check_base_class_offset(lv, (xx*), ABISELECT(8,4), "t23");
    check_base_class_offset(lv, (em_1*), 0, "t23");
    test_class_info(&lv, &cd_t23);
    dp->~t23();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt23(Test_t23, "t23", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN3t23C1Ev();
extern void _ZN3t23D1Ev();
Name_Map name_map_t23[] = {
  NSPAIR(_ZN3t23C1Ev),
  NSPAIR(_ZN3t23D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
static Base_Class bases_t23[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t23[];
extern void _ZN3t233barEv();
static  VTBL_ENTRY vtc_t23[] = {
  0,
  (VTBL_ENTRY)&(_ZTI3t23[0]),
  (VTBL_ENTRY)&_ZN3t233barEv,
};
extern VTBL_ENTRY _ZTI3t23[];
extern  VTBL_ENTRY _ZTV3t23[];
Class_Descriptor cd_t23 = {  "t23", // class name
  bases_t23, 2,
  &(vtc_t23[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI3t23),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t23),3, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t24  : virtual xx , em_1 {
  virtual void  bar(); // _ZN3t243barEv
  ~t24(); // tgen
  t24(); // tgen
};
//SIG(-1 t24) C1{ VBC2{ Fi} BC3{} v1}


void  t24 ::bar(){vfunc_called(this, "_ZN3t243barEv");}
t24 ::~t24(){ note_dtor("t24", this);} // tgen
t24 ::t24(){ note_ctor("t24", this);} // tgen

static void Test_t24()
{
  extern Class_Descriptor cd_t24;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_t24, buf);
    t24 *dp, &lv = *(dp=new (buf) t24());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(t24)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t24)");
    check_base_class_offset(lv, (xx*), ABISELECT(8,4), "t24");
    check_base_class_offset(lv, (em_1*), 0, "t24");
    test_class_info(&lv, &cd_t24);
    dp->~t24();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt24(Test_t24, "t24", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN3t24C1Ev();
extern void _ZN3t24D1Ev();
Name_Map name_map_t24[] = {
  NSPAIR(_ZN3t24C1Ev),
  NSPAIR(_ZN3t24D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
static Base_Class bases_t24[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t24[];
extern void _ZN3t243barEv();
static  VTBL_ENTRY vtc_t24[] = {
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI3t24[0]),
  (VTBL_ENTRY)&_ZN3t243barEv,
};
extern VTBL_ENTRY _ZTV3t24[];
static  VTT_ENTRY vtt_t24[] = {
  {&(_ZTV3t24[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t24[];
extern  VTBL_ENTRY _ZTV3t24[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t24[];
Class_Descriptor cd_t24 = {  "t24", // class name
  bases_t24, 2,
  &(vtc_t24[0]), // expected_vtbl_contents
  &(vtt_t24[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI3t24),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t24),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t24),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t25  : xx , virtual em_1 {
  virtual void  bar(); // _ZN3t253barEv
  ~t25(); // tgen
  t25(); // tgen
};
//SIG(-1 t25) C1{ BC2{ Fi} VBC3{} v1}


void  t25 ::bar(){vfunc_called(this, "_ZN3t253barEv");}
t25 ::~t25(){ note_dtor("t25", this);} // tgen
t25 ::t25(){ note_ctor("t25", this);} // tgen

static void Test_t25()
{
  extern Class_Descriptor cd_t25;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_t25, buf);
    t25 *dp, &lv = *(dp=new (buf) t25());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(t25)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t25)");
    check_base_class_offset(lv, (xx*), ABISELECT(8,4), "t25");
    check_base_class_offset(lv, (em_1*), 0, "t25");
    test_class_info(&lv, &cd_t25);
    dp->~t25();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt25(Test_t25, "t25", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN3t25C1Ev();
extern void _ZN3t25D1Ev();
Name_Map name_map_t25[] = {
  NSPAIR(_ZN3t25C1Ev),
  NSPAIR(_ZN3t25D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
static Base_Class bases_t25[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t25[];
extern void _ZN3t253barEv();
static  VTBL_ENTRY vtc_t25[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t25[0]),
  (VTBL_ENTRY)&_ZN3t253barEv,
};
extern VTBL_ENTRY _ZTV3t25[];
static  VTT_ENTRY vtt_t25[] = {
  {&(_ZTV3t25[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t25[];
extern  VTBL_ENTRY _ZTV3t25[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t25[];
Class_Descriptor cd_t25 = {  "t25", // class name
  bases_t25, 2,
  &(vtc_t25[0]), // expected_vtbl_contents
  &(vtt_t25[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI3t25),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t25),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t25),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t26  : virtual xx , virtual em_1 {
  virtual void  bar(); // _ZN3t263barEv
  ~t26(); // tgen
  t26(); // tgen
};
//SIG(-1 t26) C1{ VBC2{ Fi} VBC3{} v1}


void  t26 ::bar(){vfunc_called(this, "_ZN3t263barEv");}
t26 ::~t26(){ note_dtor("t26", this);} // tgen
t26 ::t26(){ note_ctor("t26", this);} // tgen

static void Test_t26()
{
  extern Class_Descriptor cd_t26;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_t26, buf);
    t26 *dp, &lv = *(dp=new (buf) t26());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(t26)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t26)");
    check_base_class_offset(lv, (xx*), ABISELECT(8,4), "t26");
    check_base_class_offset(lv, (em_1*), 0, "t26");
    test_class_info(&lv, &cd_t26);
    dp->~t26();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt26(Test_t26, "t26", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN3t26C1Ev();
extern void _ZN3t26D1Ev();
Name_Map name_map_t26[] = {
  NSPAIR(_ZN3t26C1Ev),
  NSPAIR(_ZN3t26D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
static Base_Class bases_t26[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t26[];
extern void _ZN3t263barEv();
static  VTBL_ENTRY vtc_t26[] = {
  0,
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI3t26[0]),
  (VTBL_ENTRY)&_ZN3t263barEv,
};
extern VTBL_ENTRY _ZTV3t26[];
static  VTT_ENTRY vtt_t26[] = {
  {&(_ZTV3t26[4]),  4,5},
};
extern VTBL_ENTRY _ZTI3t26[];
extern  VTBL_ENTRY _ZTV3t26[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t26[];
Class_Descriptor cd_t26 = {  "t26", // class name
  bases_t26, 2,
  &(vtc_t26[0]), // expected_vtbl_contents
  &(vtt_t26[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI3t26),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t26),5, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t26),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t27  : xx , ne_1 {
  virtual void  bar(); // _ZN3t273barEv
  ~t27(); // tgen
  t27(); // tgen
};
//SIG(-1 t27) C1{ BC2{ Fi} BC3{ m Fi:0} v1}


void  t27 ::bar(){vfunc_called(this, "_ZN3t273barEv");}
t27 ::~t27(){ note_dtor("t27", this);} // tgen
t27 ::t27(){ note_ctor("t27", this);} // tgen

static void Test_t27()
{
  extern Class_Descriptor cd_t27;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_t27, buf);
    t27 *dp, &lv = *(dp=new (buf) t27());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(t27)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t27)");
    check_base_class_offset(lv, (xx*), ABISELECT(8,4), "t27");
    check_base_class_offset(lv, (ne_1*), 0, "t27");
    test_class_info(&lv, &cd_t27);
    dp->~t27();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt27(Test_t27, "t27", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN3t27C1Ev();
extern void _ZN3t27D1Ev();
Name_Map name_map_t27[] = {
  NSPAIR(_ZN3t27C1Ev),
  NSPAIR(_ZN3t27D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_t27[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t27[];
extern void _ZN3t273barEv();
static  VTBL_ENTRY vtc_t27[] = {
  0,
  (VTBL_ENTRY)&(_ZTI3t27[0]),
  (VTBL_ENTRY)&_ZN3t273barEv,
};
extern VTBL_ENTRY _ZTI3t27[];
extern  VTBL_ENTRY _ZTV3t27[];
Class_Descriptor cd_t27 = {  "t27", // class name
  bases_t27, 2,
  &(vtc_t27[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI3t27),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t27),3, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  0, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t28  : virtual xx , ne_1 {
  virtual void  bar(); // _ZN3t283barEv
  ~t28(); // tgen
  t28(); // tgen
};
//SIG(-1 t28) C1{ VBC2{ Fi} BC3{ m Fi:0} v1}


void  t28 ::bar(){vfunc_called(this, "_ZN3t283barEv");}
t28 ::~t28(){ note_dtor("t28", this);} // tgen
t28 ::t28(){ note_ctor("t28", this);} // tgen

static void Test_t28()
{
  extern Class_Descriptor cd_t28;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_t28, buf);
    t28 *dp, &lv = *(dp=new (buf) t28());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(t28)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t28)");
    check_base_class_offset(lv, (xx*), ABISELECT(8,4), "t28");
    check_base_class_offset(lv, (ne_1*), 0, "t28");
    test_class_info(&lv, &cd_t28);
    dp->~t28();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt28(Test_t28, "t28", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN3t28C1Ev();
extern void _ZN3t28D1Ev();
Name_Map name_map_t28[] = {
  NSPAIR(_ZN3t28C1Ev),
  NSPAIR(_ZN3t28D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_t28[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI3t28[];
extern void _ZN3t283barEv();
static  VTBL_ENTRY vtc_t28[] = {
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI3t28[0]),
  (VTBL_ENTRY)&_ZN3t283barEv,
};
extern VTBL_ENTRY _ZTV3t28[];
static  VTT_ENTRY vtt_t28[] = {
  {&(_ZTV3t28[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t28[];
extern  VTBL_ENTRY _ZTV3t28[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t28[];
Class_Descriptor cd_t28 = {  "t28", // class name
  bases_t28, 2,
  &(vtc_t28[0]), // expected_vtbl_contents
  &(vtt_t28[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI3t28),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t28),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t28),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t29  : xx , virtual ne_1 {
  virtual void  bar(); // _ZN3t293barEv
  ~t29(); // tgen
  t29(); // tgen
};
//SIG(-1 t29) C1{ BC2{ Fi} VBC3{ m Fi:0} v1}


void  t29 ::bar(){vfunc_called(this, "_ZN3t293barEv");}
t29 ::~t29(){ note_dtor("t29", this);} // tgen
t29 ::t29(){ note_ctor("t29", this);} // tgen

static void Test_t29()
{
  extern Class_Descriptor cd_t29;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_t29, buf);
    t29 *dp, &lv = *(dp=new (buf) t29());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(t29)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t29)");
    check_base_class_offset(lv, (xx*), ABISELECT(8,4), "t29");
    check_base_class_offset(lv, (ne_1*), 0, "t29");
    test_class_info(&lv, &cd_t29);
    dp->~t29();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt29(Test_t29, "t29", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN3t29C1Ev();
extern void _ZN3t29D1Ev();
Name_Map name_map_t29[] = {
  NSPAIR(_ZN3t29C1Ev),
  NSPAIR(_ZN3t29D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_t29[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t29[];
extern void _ZN3t293barEv();
static  VTBL_ENTRY vtc_t29[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t29[0]),
  (VTBL_ENTRY)&_ZN3t293barEv,
};
extern VTBL_ENTRY _ZTV3t29[];
static  VTT_ENTRY vtt_t29[] = {
  {&(_ZTV3t29[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3t29[];
extern  VTBL_ENTRY _ZTV3t29[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t29[];
Class_Descriptor cd_t29 = {  "t29", // class name
  bases_t29, 2,
  &(vtc_t29[0]), // expected_vtbl_contents
  &(vtt_t29[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI3t29),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t29),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t29),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  t30  : virtual xx , virtual ne_1 {
  virtual void  bar(); // _ZN3t303barEv
  ~t30(); // tgen
  t30(); // tgen
};
//SIG(-1 t30) C1{ VBC2{ Fi} VBC3{ m Fi:0} v1}


void  t30 ::bar(){vfunc_called(this, "_ZN3t303barEv");}
t30 ::~t30(){ note_dtor("t30", this);} // tgen
t30 ::t30(){ note_ctor("t30", this);} // tgen

static void Test_t30()
{
  extern Class_Descriptor cd_t30;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_t30, buf);
    t30 *dp, &lv = *(dp=new (buf) t30());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(t30)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(t30)");
    check_base_class_offset(lv, (xx*), ABISELECT(8,4), "t30");
    check_base_class_offset(lv, (ne_1*), 0, "t30");
    test_class_info(&lv, &cd_t30);
    dp->~t30();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vt30(Test_t30, "t30", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN3t30C1Ev();
extern void _ZN3t30D1Ev();
Name_Map name_map_t30[] = {
  NSPAIR(_ZN3t30C1Ev),
  NSPAIR(_ZN3t30D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_t30[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3t30[];
extern void _ZN3t303barEv();
static  VTBL_ENTRY vtc_t30[] = {
  0,
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI3t30[0]),
  (VTBL_ENTRY)&_ZN3t303barEv,
};
extern VTBL_ENTRY _ZTV3t30[];
static  VTT_ENTRY vtt_t30[] = {
  {&(_ZTV3t30[4]),  4,5},
};
extern VTBL_ENTRY _ZTI3t30[];
extern  VTBL_ENTRY _ZTV3t30[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t30[];
Class_Descriptor cd_t30 = {  "t30", // class name
  bases_t30, 2,
  &(vtc_t30[0]), // expected_vtbl_contents
  &(vtt_t30[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI3t30),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV3t30),5, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3t30),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xem_0  : virtual em_0 {
  virtual void  abc(); // _ZN5Xem_03abcEv
  ~Xem_0(); // tgen
  Xem_0(); // tgen
};
//SIG(1 Xem_0) C1{ VBC2{} v1}


void  Xem_0 ::abc(){vfunc_called(this, "_ZN5Xem_03abcEv");}
Xem_0 ::~Xem_0(){ note_dtor("Xem_0", this);} // tgen
Xem_0 ::Xem_0(){ note_ctor("Xem_0", this);} // tgen

static void Test_Xem_0()
{
  extern Class_Descriptor cd_Xem_0;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xem_0, buf);
    Xem_0 *dp, &lv = *(dp=new (buf) Xem_0());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xem_0)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xem_0)");
    check_base_class_offset(lv, (em_0*), 0, "Xem_0");
    test_class_info(&lv, &cd_Xem_0);
    dp->~Xem_0();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXem_0(Test_Xem_0, "Xem_0", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN5Xem_0C1Ev();
extern void _ZN5Xem_0D1Ev();
Name_Map name_map_Xem_0[] = {
  NSPAIR(_ZN5Xem_0C1Ev),
  NSPAIR(_ZN5Xem_0D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
static Base_Class bases_Xem_0[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI5Xem_0[];
extern void _ZN5Xem_03abcEv();
static  VTBL_ENTRY vtc_Xem_0[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI5Xem_0[0]),
  (VTBL_ENTRY)&_ZN5Xem_03abcEv,
};
extern VTBL_ENTRY _ZTV5Xem_0[];
static  VTT_ENTRY vtt_Xem_0[] = {
  {&(_ZTV5Xem_0[3]),  3,4},
};
extern VTBL_ENTRY _ZTI5Xem_0[];
extern  VTBL_ENTRY _ZTV5Xem_0[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT5Xem_0[];
Class_Descriptor cd_Xem_0 = {  "Xem_0", // class name
  bases_Xem_0, 1,
  &(vtc_Xem_0[0]), // expected_vtbl_contents
  &(vtt_Xem_0[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI5Xem_0),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV5Xem_0),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT5Xem_0),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xne_0  : virtual ne_0 {
  virtual void  abc(); // _ZN5Xne_03abcEv
  ~Xne_0(); // tgen
  Xne_0(); // tgen
};
//SIG(1 Xne_0) C1{ VBC2{ m} v1}


void  Xne_0 ::abc(){vfunc_called(this, "_ZN5Xne_03abcEv");}
Xne_0 ::~Xne_0(){ note_dtor("Xne_0", this);} // tgen
Xne_0 ::Xne_0(){ note_ctor("Xne_0", this);} // tgen

static void Test_Xne_0()
{
  extern Class_Descriptor cd_Xne_0;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xne_0, buf);
    Xne_0 *dp, &lv = *(dp=new (buf) Xne_0());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xne_0)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xne_0)");
    check_base_class_offset(lv, (ne_0*), 0, "Xne_0");
    test_class_info(&lv, &cd_Xne_0);
    dp->~Xne_0();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXne_0(Test_Xne_0, "Xne_0", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN5Xne_0C1Ev();
extern void _ZN5Xne_0D1Ev();
Name_Map name_map_Xne_0[] = {
  NSPAIR(_ZN5Xne_0C1Ev),
  NSPAIR(_ZN5Xne_0D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
static Base_Class bases_Xne_0[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI5Xne_0[];
extern void _ZN5Xne_03abcEv();
static  VTBL_ENTRY vtc_Xne_0[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI5Xne_0[0]),
  (VTBL_ENTRY)&_ZN5Xne_03abcEv,
};
extern VTBL_ENTRY _ZTV5Xne_0[];
static  VTT_ENTRY vtt_Xne_0[] = {
  {&(_ZTV5Xne_0[3]),  3,4},
};
extern VTBL_ENTRY _ZTI5Xne_0[];
extern  VTBL_ENTRY _ZTV5Xne_0[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT5Xne_0[];
Class_Descriptor cd_Xne_0 = {  "Xne_0", // class name
  bases_Xne_0, 1,
  &(vtc_Xne_0[0]), // expected_vtbl_contents
  &(vtt_Xne_0[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI5Xne_0),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV5Xne_0),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT5Xne_0),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xne_1  : virtual ne_1 {
  virtual void  abc(); // _ZN5Xne_13abcEv
  ~Xne_1(); // tgen
  Xne_1(); // tgen
};
//SIG(1 Xne_1) C1{ VBC2{ m Fi:0} v1}


void  Xne_1 ::abc(){vfunc_called(this, "_ZN5Xne_13abcEv");}
Xne_1 ::~Xne_1(){ note_dtor("Xne_1", this);} // tgen
Xne_1 ::Xne_1(){ note_ctor("Xne_1", this);} // tgen

static void Test_Xne_1()
{
  extern Class_Descriptor cd_Xne_1;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xne_1, buf);
    Xne_1 *dp, &lv = *(dp=new (buf) Xne_1());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xne_1)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xne_1)");
    check_base_class_offset(lv, (ne_1*), 0, "Xne_1");
    test_class_info(&lv, &cd_Xne_1);
    dp->~Xne_1();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXne_1(Test_Xne_1, "Xne_1", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN5Xne_1C1Ev();
extern void _ZN5Xne_1D1Ev();
Name_Map name_map_Xne_1[] = {
  NSPAIR(_ZN5Xne_1C1Ev),
  NSPAIR(_ZN5Xne_1D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
static Base_Class bases_Xne_1[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI5Xne_1[];
extern void _ZN5Xne_13abcEv();
static  VTBL_ENTRY vtc_Xne_1[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI5Xne_1[0]),
  (VTBL_ENTRY)&_ZN5Xne_13abcEv,
};
extern VTBL_ENTRY _ZTV5Xne_1[];
static  VTT_ENTRY vtt_Xne_1[] = {
  {&(_ZTV5Xne_1[3]),  3,4},
};
extern VTBL_ENTRY _ZTI5Xne_1[];
extern  VTBL_ENTRY _ZTV5Xne_1[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT5Xne_1[];
Class_Descriptor cd_Xne_1 = {  "Xne_1", // class name
  bases_Xne_1, 1,
  &(vtc_Xne_1[0]), // expected_vtbl_contents
  &(vtt_Xne_1[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI5Xne_1),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV5Xne_1),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT5Xne_1),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xne_2  : virtual ne_2 {
  virtual void  abc(); // _ZN5Xne_23abcEv
  ~Xne_2(); // tgen
  Xne_2(); // tgen
};
//SIG(1 Xne_2) C1{ VBC2{ m Fs:0 Fi:0} v1}


void  Xne_2 ::abc(){vfunc_called(this, "_ZN5Xne_23abcEv");}
Xne_2 ::~Xne_2(){ note_dtor("Xne_2", this);} // tgen
Xne_2 ::Xne_2(){ note_ctor("Xne_2", this);} // tgen

static void Test_Xne_2()
{
  extern Class_Descriptor cd_Xne_2;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xne_2, buf);
    Xne_2 *dp, &lv = *(dp=new (buf) Xne_2());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xne_2)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xne_2)");
    check_base_class_offset(lv, (ne_2*), 0, "Xne_2");
    test_class_info(&lv, &cd_Xne_2);
    dp->~Xne_2();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXne_2(Test_Xne_2, "Xne_2", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN5Xne_2C1Ev();
extern void _ZN5Xne_2D1Ev();
Name_Map name_map_Xne_2[] = {
  NSPAIR(_ZN5Xne_2C1Ev),
  NSPAIR(_ZN5Xne_2D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_2;
extern VTBL_ENTRY _ZTI4ne_2[];
static Base_Class bases_Xne_2[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_2,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI5Xne_2[];
extern void _ZN5Xne_23abcEv();
static  VTBL_ENTRY vtc_Xne_2[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI5Xne_2[0]),
  (VTBL_ENTRY)&_ZN5Xne_23abcEv,
};
extern VTBL_ENTRY _ZTV5Xne_2[];
static  VTT_ENTRY vtt_Xne_2[] = {
  {&(_ZTV5Xne_2[3]),  3,4},
};
extern VTBL_ENTRY _ZTI5Xne_2[];
extern  VTBL_ENTRY _ZTV5Xne_2[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT5Xne_2[];
Class_Descriptor cd_Xne_2 = {  "Xne_2", // class name
  bases_Xne_2, 1,
  &(vtc_Xne_2[0]), // expected_vtbl_contents
  &(vtt_Xne_2[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI5Xne_2),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV5Xne_2),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT5Xne_2),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xxx  : virtual xx {
  virtual void  abc(); // _ZN3Xxx3abcEv
  ~Xxx(); // tgen
  Xxx(); // tgen
};
//SIG(1 Xxx) C1{ VBC2{ Fi} v1}


void  Xxx ::abc(){vfunc_called(this, "_ZN3Xxx3abcEv");}
Xxx ::~Xxx(){ note_dtor("Xxx", this);} // tgen
Xxx ::Xxx(){ note_ctor("Xxx", this);} // tgen

static void Test_Xxx()
{
  extern Class_Descriptor cd_Xxx;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_Xxx, buf);
    Xxx *dp, &lv = *(dp=new (buf) Xxx());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Xxx)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xxx)");
    check_base_class_offset(lv, (xx*), ABISELECT(8,4), "Xxx");
    test_class_info(&lv, &cd_Xxx);
    dp->~Xxx();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXxx(Test_Xxx, "Xxx", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN3XxxC1Ev();
extern void _ZN3XxxD1Ev();
Name_Map name_map_Xxx[] = {
  NSPAIR(_ZN3XxxC1Ev),
  NSPAIR(_ZN3XxxD1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
static Base_Class bases_Xxx[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI3Xxx[];
extern void _ZN3Xxx3abcEv();
static  VTBL_ENTRY vtc_Xxx[] = {
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI3Xxx[0]),
  (VTBL_ENTRY)&_ZN3Xxx3abcEv,
};
extern VTBL_ENTRY _ZTV3Xxx[];
static  VTT_ENTRY vtt_Xxx[] = {
  {&(_ZTV3Xxx[3]),  3,4},
};
extern VTBL_ENTRY _ZTI3Xxx[];
extern  VTBL_ENTRY _ZTV3Xxx[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3Xxx[];
Class_Descriptor cd_Xxx = {  "Xxx", // class name
  bases_Xxx, 1,
  &(vtc_Xxx[0]), // expected_vtbl_contents
  &(vtt_Xxx[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI3Xxx),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV3Xxx),4, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT3Xxx),1, //virtual table table var
  0, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt01  : virtual t01 {
  virtual void  abc(); // _ZN4Xt013abcEv
  ~Xt01(); // tgen
  Xt01(); // tgen
};
//SIG(1 Xt01) C1{ VBC2{ BC3{} v2} v1}


void  Xt01 ::abc(){vfunc_called(this, "_ZN4Xt013abcEv");}
Xt01 ::~Xt01(){ note_dtor("Xt01", this);} // tgen
Xt01 ::Xt01(){ note_ctor("Xt01", this);} // tgen

static void Test_Xt01()
{
  extern Class_Descriptor cd_Xt01;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt01, buf);
    Xt01 *dp, &lv = *(dp=new (buf) Xt01());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt01)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt01)");
    check_base_class_offset(lv, (em_0*)(t01*), 0, "Xt01");
    check_base_class_offset(lv, (t01*), 0, "Xt01");
    test_class_info(&lv, &cd_Xt01);
    dp->~Xt01();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt01(Test_Xt01, "Xt01", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt01C1Ev();
extern void _ZN4Xt01D1Ev();
Name_Map name_map_Xt01[] = {
  NSPAIR(_ZN4Xt01C1Ev),
  NSPAIR(_ZN4Xt01D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_t01;
extern VTBL_ENTRY _ZTI3t01[];
extern  VTBL_ENTRY _ZTV3t01[];
static Base_Class bases_Xt01[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    1, //immediately_derived
  0, 0},
  {&cd_t01,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    3, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt01[];
extern void _ZN3t013barEv();
extern void _ZN4Xt013abcEv();
static  VTBL_ENTRY vtc_Xt01[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt01[0]),
  (VTBL_ENTRY)&_ZN3t013barEv,
  (VTBL_ENTRY)&_ZN4Xt013abcEv,
};
extern VTBL_ENTRY _ZTV4Xt01[];
static  VTT_ENTRY vtt_Xt01[] = {
  {&(_ZTV4Xt01[4]),  4,6},
  {&(_ZTV4Xt01[4]),  4,6},
};
extern VTBL_ENTRY _ZTI4Xt01[];
extern  VTBL_ENTRY _ZTV4Xt01[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt01[];
Class_Descriptor cd_Xt01 = {  "Xt01", // class name
  bases_Xt01, 2,
  &(vtc_Xt01[0]), // expected_vtbl_contents
  &(vtt_Xt01[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt01),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt01),6, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt01),2, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt02  : virtual t02 {
  virtual void  abc(); // _ZN4Xt023abcEv
  ~Xt02(); // tgen
  Xt02(); // tgen
};
//SIG(1 Xt02) C1{ VBC2{ VBC3{} v2} v1}


void  Xt02 ::abc(){vfunc_called(this, "_ZN4Xt023abcEv");}
Xt02 ::~Xt02(){ note_dtor("Xt02", this);} // tgen
Xt02 ::Xt02(){ note_ctor("Xt02", this);} // tgen

static void Test_Xt02()
{
  extern Class_Descriptor cd_Xt02;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt02, buf);
    Xt02 *dp, &lv = *(dp=new (buf) Xt02());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt02)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt02)");
    check_base_class_offset(lv, (em_0*)(t02*), 0, "Xt02");
    check_base_class_offset(lv, (t02*), 0, "Xt02");
    test_class_info(&lv, &cd_Xt02);
    dp->~Xt02();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt02(Test_Xt02, "Xt02", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt02C1Ev();
extern void _ZN4Xt02D1Ev();
Name_Map name_map_Xt02[] = {
  NSPAIR(_ZN4Xt02C1Ev),
  NSPAIR(_ZN4Xt02D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_t02;
extern VTBL_ENTRY _ZTI3t02[];
extern  VTBL_ENTRY _ZTV3t02[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t02[];
static Base_Class bases_Xt02[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    1, //immediately_derived
  0, 1},
  {&cd_t02,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt02[];
extern void _ZN3t023barEv();
extern void _ZN4Xt023abcEv();
static  VTBL_ENTRY vtc_Xt02[] = {
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt02[0]),
  (VTBL_ENTRY)&_ZN3t023barEv,
  (VTBL_ENTRY)&_ZN4Xt023abcEv,
};
extern VTBL_ENTRY _ZTV4Xt02[];
extern void _ZN3t023barEv();
static  VTBL_ENTRY _tg__ZTV3t02__4Xt02[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t02[0]),
  (VTBL_ENTRY)&_ZN3t023barEv,
};
static  VTT_ENTRY vtt_Xt02[] = {
  {&(_ZTV4Xt02[5]),  5,7},
  {&(_ZTV4Xt02[5]),  5,7},
  {&(_tg__ZTV3t02__4Xt02[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt02[];
extern  VTBL_ENTRY _ZTV4Xt02[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt02[];
Class_Descriptor cd_Xt02 = {  "Xt02", // class name
  bases_Xt02, 2,
  &(vtc_Xt02[0]), // expected_vtbl_contents
  &(vtt_Xt02[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt02),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt02),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt02),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt03  : virtual t03 {
  virtual void  abc(); // _ZN4Xt033abcEv
  ~Xt03(); // tgen
  Xt03(); // tgen
};
//SIG(1 Xt03) C1{ VBC2{ BC3{} BC4{} v2} v1}


void  Xt03 ::abc(){vfunc_called(this, "_ZN4Xt033abcEv");}
Xt03 ::~Xt03(){ note_dtor("Xt03", this);} // tgen
Xt03 ::Xt03(){ note_ctor("Xt03", this);} // tgen

static void Test_Xt03()
{
  extern Class_Descriptor cd_Xt03;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt03, buf);
    Xt03 *dp, &lv = *(dp=new (buf) Xt03());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt03)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt03)");
    check_base_class_offset(lv, (em_0*)(t03*), 0, "Xt03");
    check_base_class_offset(lv, (em_1*)(t03*), 0, "Xt03");
    check_base_class_offset(lv, (t03*), 0, "Xt03");
    test_class_info(&lv, &cd_Xt03);
    dp->~Xt03();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt03(Test_Xt03, "Xt03", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt03C1Ev();
extern void _ZN4Xt03D1Ev();
Name_Map name_map_Xt03[] = {
  NSPAIR(_ZN4Xt03C1Ev),
  NSPAIR(_ZN4Xt03D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
extern Class_Descriptor cd_t03;
extern VTBL_ENTRY _ZTI3t03[];
extern  VTBL_ENTRY _ZTV3t03[];
static Base_Class bases_Xt03[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_t03,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    3, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt03[];
extern void _ZN3t033barEv();
extern void _ZN4Xt033abcEv();
static  VTBL_ENTRY vtc_Xt03[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt03[0]),
  (VTBL_ENTRY)&_ZN3t033barEv,
  (VTBL_ENTRY)&_ZN4Xt033abcEv,
};
extern VTBL_ENTRY _ZTV4Xt03[];
static  VTT_ENTRY vtt_Xt03[] = {
  {&(_ZTV4Xt03[4]),  4,6},
  {&(_ZTV4Xt03[4]),  4,6},
};
extern VTBL_ENTRY _ZTI4Xt03[];
extern  VTBL_ENTRY _ZTV4Xt03[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt03[];
Class_Descriptor cd_Xt03 = {  "Xt03", // class name
  bases_Xt03, 3,
  &(vtc_Xt03[0]), // expected_vtbl_contents
  &(vtt_Xt03[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt03),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt03),6, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt03),2, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt04  : virtual t04 {
  virtual void  abc(); // _ZN4Xt043abcEv
  ~Xt04(); // tgen
  Xt04(); // tgen
};
//SIG(1 Xt04) C1{ VBC2{ VBC3{} BC4{} v2} v1}


void  Xt04 ::abc(){vfunc_called(this, "_ZN4Xt043abcEv");}
Xt04 ::~Xt04(){ note_dtor("Xt04", this);} // tgen
Xt04 ::Xt04(){ note_ctor("Xt04", this);} // tgen

static void Test_Xt04()
{
  extern Class_Descriptor cd_Xt04;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt04, buf);
    Xt04 *dp, &lv = *(dp=new (buf) Xt04());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt04)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt04)");
    check_base_class_offset(lv, (em_0*)(t04*), 0, "Xt04");
    check_base_class_offset(lv, (em_1*)(t04*), 0, "Xt04");
    check_base_class_offset(lv, (t04*), 0, "Xt04");
    test_class_info(&lv, &cd_Xt04);
    dp->~Xt04();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt04(Test_Xt04, "Xt04", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt04C1Ev();
extern void _ZN4Xt04D1Ev();
Name_Map name_map_Xt04[] = {
  NSPAIR(_ZN4Xt04C1Ev),
  NSPAIR(_ZN4Xt04D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
extern Class_Descriptor cd_t04;
extern VTBL_ENTRY _ZTI3t04[];
extern  VTBL_ENTRY _ZTV3t04[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t04[];
static Base_Class bases_Xt04[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_t04,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt04[];
extern void _ZN3t043barEv();
extern void _ZN4Xt043abcEv();
static  VTBL_ENTRY vtc_Xt04[] = {
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt04[0]),
  (VTBL_ENTRY)&_ZN3t043barEv,
  (VTBL_ENTRY)&_ZN4Xt043abcEv,
};
extern VTBL_ENTRY _ZTV4Xt04[];
extern void _ZN3t043barEv();
static  VTBL_ENTRY _tg__ZTV3t04__4Xt04[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t04[0]),
  (VTBL_ENTRY)&_ZN3t043barEv,
};
static  VTT_ENTRY vtt_Xt04[] = {
  {&(_ZTV4Xt04[5]),  5,7},
  {&(_ZTV4Xt04[5]),  5,7},
  {&(_tg__ZTV3t04__4Xt04[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt04[];
extern  VTBL_ENTRY _ZTV4Xt04[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt04[];
Class_Descriptor cd_Xt04 = {  "Xt04", // class name
  bases_Xt04, 3,
  &(vtc_Xt04[0]), // expected_vtbl_contents
  &(vtt_Xt04[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt04),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt04),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt04),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt05  : virtual t05 {
  virtual void  abc(); // _ZN4Xt053abcEv
  ~Xt05(); // tgen
  Xt05(); // tgen
};
//SIG(1 Xt05) C1{ VBC2{ BC3{} VBC4{} v2} v1}


void  Xt05 ::abc(){vfunc_called(this, "_ZN4Xt053abcEv");}
Xt05 ::~Xt05(){ note_dtor("Xt05", this);} // tgen
Xt05 ::Xt05(){ note_ctor("Xt05", this);} // tgen

static void Test_Xt05()
{
  extern Class_Descriptor cd_Xt05;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt05, buf);
    Xt05 *dp, &lv = *(dp=new (buf) Xt05());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt05)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt05)");
    check_base_class_offset(lv, (em_0*)(t05*), 0, "Xt05");
    check_base_class_offset(lv, (em_1*)(t05*), 0, "Xt05");
    check_base_class_offset(lv, (t05*), 0, "Xt05");
    test_class_info(&lv, &cd_Xt05);
    dp->~Xt05();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt05(Test_Xt05, "Xt05", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt05C1Ev();
extern void _ZN4Xt05D1Ev();
Name_Map name_map_Xt05[] = {
  NSPAIR(_ZN4Xt05C1Ev),
  NSPAIR(_ZN4Xt05D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
extern Class_Descriptor cd_t05;
extern VTBL_ENTRY _ZTI3t05[];
extern  VTBL_ENTRY _ZTV3t05[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t05[];
static Base_Class bases_Xt05[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_t05,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt05[];
extern void _ZN3t053barEv();
extern void _ZN4Xt053abcEv();
static  VTBL_ENTRY vtc_Xt05[] = {
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt05[0]),
  (VTBL_ENTRY)&_ZN3t053barEv,
  (VTBL_ENTRY)&_ZN4Xt053abcEv,
};
extern VTBL_ENTRY _ZTV4Xt05[];
extern void _ZN3t053barEv();
static  VTBL_ENTRY _tg__ZTV3t05__4Xt05[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t05[0]),
  (VTBL_ENTRY)&_ZN3t053barEv,
};
static  VTT_ENTRY vtt_Xt05[] = {
  {&(_ZTV4Xt05[5]),  5,7},
  {&(_ZTV4Xt05[5]),  5,7},
  {&(_tg__ZTV3t05__4Xt05[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt05[];
extern  VTBL_ENTRY _ZTV4Xt05[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt05[];
Class_Descriptor cd_Xt05 = {  "Xt05", // class name
  bases_Xt05, 3,
  &(vtc_Xt05[0]), // expected_vtbl_contents
  &(vtt_Xt05[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt05),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt05),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt05),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt06  : virtual t06 {
  virtual void  abc(); // _ZN4Xt063abcEv
  ~Xt06(); // tgen
  Xt06(); // tgen
};
//SIG(1 Xt06) C1{ VBC2{ VBC3{} VBC4{} v2} v1}


void  Xt06 ::abc(){vfunc_called(this, "_ZN4Xt063abcEv");}
Xt06 ::~Xt06(){ note_dtor("Xt06", this);} // tgen
Xt06 ::Xt06(){ note_ctor("Xt06", this);} // tgen

static void Test_Xt06()
{
  extern Class_Descriptor cd_Xt06;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt06, buf);
    Xt06 *dp, &lv = *(dp=new (buf) Xt06());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt06)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt06)");
    check_base_class_offset(lv, (em_0*)(t06*), 0, "Xt06");
    check_base_class_offset(lv, (em_1*)(t06*), 0, "Xt06");
    check_base_class_offset(lv, (t06*), 0, "Xt06");
    test_class_info(&lv, &cd_Xt06);
    dp->~Xt06();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt06(Test_Xt06, "Xt06", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt06C1Ev();
extern void _ZN4Xt06D1Ev();
Name_Map name_map_Xt06[] = {
  NSPAIR(_ZN4Xt06C1Ev),
  NSPAIR(_ZN4Xt06D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
extern Class_Descriptor cd_t06;
extern VTBL_ENTRY _ZTI3t06[];
extern  VTBL_ENTRY _ZTV3t06[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t06[];
static Base_Class bases_Xt06[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_t06,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    5, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt06[];
extern void _ZN3t063barEv();
extern void _ZN4Xt063abcEv();
static  VTBL_ENTRY vtc_Xt06[] = {
  0,
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt06[0]),
  (VTBL_ENTRY)&_ZN3t063barEv,
  (VTBL_ENTRY)&_ZN4Xt063abcEv,
};
extern VTBL_ENTRY _ZTV4Xt06[];
extern void _ZN3t063barEv();
static  VTBL_ENTRY _tg__ZTV3t06__4Xt06[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t06[0]),
  (VTBL_ENTRY)&_ZN3t063barEv,
};
static  VTT_ENTRY vtt_Xt06[] = {
  {&(_ZTV4Xt06[6]),  6,8},
  {&(_ZTV4Xt06[6]),  6,8},
  {&(_tg__ZTV3t06__4Xt06[4]),  4,5},
};
extern VTBL_ENTRY _ZTI4Xt06[];
extern  VTBL_ENTRY _ZTV4Xt06[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt06[];
Class_Descriptor cd_Xt06 = {  "Xt06", // class name
  bases_Xt06, 3,
  &(vtc_Xt06[0]), // expected_vtbl_contents
  &(vtt_Xt06[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt06),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt06),8, //virtual function table var
  6, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt06),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt07  : virtual t07 {
  virtual void  abc(); // _ZN4Xt073abcEv
  ~Xt07(); // tgen
  Xt07(); // tgen
};
//SIG(1 Xt07) C1{ VBC2{ BC3{} BC4{ m Fi:0} v2} v1}


void  Xt07 ::abc(){vfunc_called(this, "_ZN4Xt073abcEv");}
Xt07 ::~Xt07(){ note_dtor("Xt07", this);} // tgen
Xt07 ::Xt07(){ note_ctor("Xt07", this);} // tgen

static void Test_Xt07()
{
  extern Class_Descriptor cd_Xt07;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt07, buf);
    Xt07 *dp, &lv = *(dp=new (buf) Xt07());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt07)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt07)");
    check_base_class_offset(lv, (em_0*)(t07*), 0, "Xt07");
    check_base_class_offset(lv, (ne_1*)(t07*), 0, "Xt07");
    check_base_class_offset(lv, (t07*), 0, "Xt07");
    test_class_info(&lv, &cd_Xt07);
    dp->~Xt07();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt07(Test_Xt07, "Xt07", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt07C1Ev();
extern void _ZN4Xt07D1Ev();
Name_Map name_map_Xt07[] = {
  NSPAIR(_ZN4Xt07C1Ev),
  NSPAIR(_ZN4Xt07D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
extern Class_Descriptor cd_t07;
extern VTBL_ENTRY _ZTI3t07[];
extern  VTBL_ENTRY _ZTV3t07[];
static Base_Class bases_Xt07[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_t07,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    3, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt07[];
extern void _ZN3t073barEv();
extern void _ZN4Xt073abcEv();
static  VTBL_ENTRY vtc_Xt07[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt07[0]),
  (VTBL_ENTRY)&_ZN3t073barEv,
  (VTBL_ENTRY)&_ZN4Xt073abcEv,
};
extern VTBL_ENTRY _ZTV4Xt07[];
static  VTT_ENTRY vtt_Xt07[] = {
  {&(_ZTV4Xt07[4]),  4,6},
  {&(_ZTV4Xt07[4]),  4,6},
};
extern VTBL_ENTRY _ZTI4Xt07[];
extern  VTBL_ENTRY _ZTV4Xt07[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt07[];
Class_Descriptor cd_Xt07 = {  "Xt07", // class name
  bases_Xt07, 3,
  &(vtc_Xt07[0]), // expected_vtbl_contents
  &(vtt_Xt07[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt07),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt07),6, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt07),2, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt08  : virtual t08 {
  virtual void  abc(); // _ZN4Xt083abcEv
  ~Xt08(); // tgen
  Xt08(); // tgen
};
//SIG(1 Xt08) C1{ VBC2{ VBC3{} BC4{ m Fi:0} v2} v1}


void  Xt08 ::abc(){vfunc_called(this, "_ZN4Xt083abcEv");}
Xt08 ::~Xt08(){ note_dtor("Xt08", this);} // tgen
Xt08 ::Xt08(){ note_ctor("Xt08", this);} // tgen

static void Test_Xt08()
{
  extern Class_Descriptor cd_Xt08;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt08, buf);
    Xt08 *dp, &lv = *(dp=new (buf) Xt08());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt08)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt08)");
    check_base_class_offset(lv, (em_0*)(t08*), 0, "Xt08");
    check_base_class_offset(lv, (ne_1*)(t08*), 0, "Xt08");
    check_base_class_offset(lv, (t08*), 0, "Xt08");
    test_class_info(&lv, &cd_Xt08);
    dp->~Xt08();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt08(Test_Xt08, "Xt08", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt08C1Ev();
extern void _ZN4Xt08D1Ev();
Name_Map name_map_Xt08[] = {
  NSPAIR(_ZN4Xt08C1Ev),
  NSPAIR(_ZN4Xt08D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
extern Class_Descriptor cd_t08;
extern VTBL_ENTRY _ZTI3t08[];
extern  VTBL_ENTRY _ZTV3t08[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t08[];
static Base_Class bases_Xt08[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_t08,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt08[];
extern void _ZN3t083barEv();
extern void _ZN4Xt083abcEv();
static  VTBL_ENTRY vtc_Xt08[] = {
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt08[0]),
  (VTBL_ENTRY)&_ZN3t083barEv,
  (VTBL_ENTRY)&_ZN4Xt083abcEv,
};
extern VTBL_ENTRY _ZTV4Xt08[];
extern void _ZN3t083barEv();
static  VTBL_ENTRY _tg__ZTV3t08__4Xt08[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t08[0]),
  (VTBL_ENTRY)&_ZN3t083barEv,
};
static  VTT_ENTRY vtt_Xt08[] = {
  {&(_ZTV4Xt08[5]),  5,7},
  {&(_ZTV4Xt08[5]),  5,7},
  {&(_tg__ZTV3t08__4Xt08[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt08[];
extern  VTBL_ENTRY _ZTV4Xt08[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt08[];
Class_Descriptor cd_Xt08 = {  "Xt08", // class name
  bases_Xt08, 3,
  &(vtc_Xt08[0]), // expected_vtbl_contents
  &(vtt_Xt08[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt08),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt08),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt08),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt09  : virtual t09 {
  virtual void  abc(); // _ZN4Xt093abcEv
  ~Xt09(); // tgen
  Xt09(); // tgen
};
//SIG(1 Xt09) C1{ VBC2{ BC3{} VBC4{ m Fi:0} v2} v1}


void  Xt09 ::abc(){vfunc_called(this, "_ZN4Xt093abcEv");}
Xt09 ::~Xt09(){ note_dtor("Xt09", this);} // tgen
Xt09 ::Xt09(){ note_ctor("Xt09", this);} // tgen

static void Test_Xt09()
{
  extern Class_Descriptor cd_Xt09;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt09, buf);
    Xt09 *dp, &lv = *(dp=new (buf) Xt09());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt09)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt09)");
    check_base_class_offset(lv, (em_0*)(t09*), 0, "Xt09");
    check_base_class_offset(lv, (ne_1*)(t09*), 0, "Xt09");
    check_base_class_offset(lv, (t09*), 0, "Xt09");
    test_class_info(&lv, &cd_Xt09);
    dp->~Xt09();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt09(Test_Xt09, "Xt09", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt09C1Ev();
extern void _ZN4Xt09D1Ev();
Name_Map name_map_Xt09[] = {
  NSPAIR(_ZN4Xt09C1Ev),
  NSPAIR(_ZN4Xt09D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
extern Class_Descriptor cd_t09;
extern VTBL_ENTRY _ZTI3t09[];
extern  VTBL_ENTRY _ZTV3t09[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t09[];
static Base_Class bases_Xt09[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_t09,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt09[];
extern void _ZN3t093barEv();
extern void _ZN4Xt093abcEv();
static  VTBL_ENTRY vtc_Xt09[] = {
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt09[0]),
  (VTBL_ENTRY)&_ZN3t093barEv,
  (VTBL_ENTRY)&_ZN4Xt093abcEv,
};
extern VTBL_ENTRY _ZTV4Xt09[];
extern void _ZN3t093barEv();
static  VTBL_ENTRY _tg__ZTV3t09__4Xt09[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t09[0]),
  (VTBL_ENTRY)&_ZN3t093barEv,
};
static  VTT_ENTRY vtt_Xt09[] = {
  {&(_ZTV4Xt09[5]),  5,7},
  {&(_ZTV4Xt09[5]),  5,7},
  {&(_tg__ZTV3t09__4Xt09[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt09[];
extern  VTBL_ENTRY _ZTV4Xt09[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt09[];
Class_Descriptor cd_Xt09 = {  "Xt09", // class name
  bases_Xt09, 3,
  &(vtc_Xt09[0]), // expected_vtbl_contents
  &(vtt_Xt09[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt09),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt09),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt09),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt00  : virtual t00 {
  virtual void  abc(); // _ZN4Xt003abcEv
  ~Xt00(); // tgen
  Xt00(); // tgen
};
//SIG(1 Xt00) C1{ VBC2{ VBC3{} VBC4{ m Fi:0} v2} v1}


void  Xt00 ::abc(){vfunc_called(this, "_ZN4Xt003abcEv");}
Xt00 ::~Xt00(){ note_dtor("Xt00", this);} // tgen
Xt00 ::Xt00(){ note_ctor("Xt00", this);} // tgen

static void Test_Xt00()
{
  extern Class_Descriptor cd_Xt00;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt00, buf);
    Xt00 *dp, &lv = *(dp=new (buf) Xt00());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt00)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt00)");
    check_base_class_offset(lv, (em_0*)(t00*), 0, "Xt00");
    check_base_class_offset(lv, (ne_1*)(t00*), 0, "Xt00");
    check_base_class_offset(lv, (t00*), 0, "Xt00");
    test_class_info(&lv, &cd_Xt00);
    dp->~Xt00();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt00(Test_Xt00, "Xt00", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt00C1Ev();
extern void _ZN4Xt00D1Ev();
Name_Map name_map_Xt00[] = {
  NSPAIR(_ZN4Xt00C1Ev),
  NSPAIR(_ZN4Xt00D1Ev),
  {0,0}
};
extern Class_Descriptor cd_em_0;
extern VTBL_ENTRY _ZTI4em_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
extern Class_Descriptor cd_t00;
extern VTBL_ENTRY _ZTI3t00[];
extern  VTBL_ENTRY _ZTV3t00[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t00[];
static Base_Class bases_Xt00[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_em_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_t00,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    5, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt00[];
extern void _ZN3t003barEv();
extern void _ZN4Xt003abcEv();
static  VTBL_ENTRY vtc_Xt00[] = {
  0,
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt00[0]),
  (VTBL_ENTRY)&_ZN3t003barEv,
  (VTBL_ENTRY)&_ZN4Xt003abcEv,
};
extern VTBL_ENTRY _ZTV4Xt00[];
extern void _ZN3t003barEv();
static  VTBL_ENTRY _tg__ZTV3t00__4Xt00[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t00[0]),
  (VTBL_ENTRY)&_ZN3t003barEv,
};
static  VTT_ENTRY vtt_Xt00[] = {
  {&(_ZTV4Xt00[6]),  6,8},
  {&(_ZTV4Xt00[6]),  6,8},
  {&(_tg__ZTV3t00__4Xt00[4]),  4,5},
};
extern VTBL_ENTRY _ZTI4Xt00[];
extern  VTBL_ENTRY _ZTV4Xt00[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt00[];
Class_Descriptor cd_Xt00 = {  "Xt00", // class name
  bases_Xt00, 3,
  &(vtc_Xt00[0]), // expected_vtbl_contents
  &(vtt_Xt00[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt00),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt00),8, //virtual function table var
  6, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt00),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt11  : virtual t11 {
  virtual void  abc(); // _ZN4Xt113abcEv
  ~Xt11(); // tgen
  Xt11(); // tgen
};
//SIG(1 Xt11) C1{ VBC2{ BC3{ m} v2} v1}


void  Xt11 ::abc(){vfunc_called(this, "_ZN4Xt113abcEv");}
Xt11 ::~Xt11(){ note_dtor("Xt11", this);} // tgen
Xt11 ::Xt11(){ note_ctor("Xt11", this);} // tgen

static void Test_Xt11()
{
  extern Class_Descriptor cd_Xt11;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt11, buf);
    Xt11 *dp, &lv = *(dp=new (buf) Xt11());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt11)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt11)");
    check_base_class_offset(lv, (ne_0*)(t11*), 0, "Xt11");
    check_base_class_offset(lv, (t11*), 0, "Xt11");
    test_class_info(&lv, &cd_Xt11);
    dp->~Xt11();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt11(Test_Xt11, "Xt11", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt11C1Ev();
extern void _ZN4Xt11D1Ev();
Name_Map name_map_Xt11[] = {
  NSPAIR(_ZN4Xt11C1Ev),
  NSPAIR(_ZN4Xt11D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_t11;
extern VTBL_ENTRY _ZTI3t11[];
extern  VTBL_ENTRY _ZTV3t11[];
static Base_Class bases_Xt11[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    1, //immediately_derived
  0, 0},
  {&cd_t11,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    3, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt11[];
extern void _ZN3t113barEv();
extern void _ZN4Xt113abcEv();
static  VTBL_ENTRY vtc_Xt11[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt11[0]),
  (VTBL_ENTRY)&_ZN3t113barEv,
  (VTBL_ENTRY)&_ZN4Xt113abcEv,
};
extern VTBL_ENTRY _ZTV4Xt11[];
static  VTT_ENTRY vtt_Xt11[] = {
  {&(_ZTV4Xt11[4]),  4,6},
  {&(_ZTV4Xt11[4]),  4,6},
};
extern VTBL_ENTRY _ZTI4Xt11[];
extern  VTBL_ENTRY _ZTV4Xt11[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt11[];
Class_Descriptor cd_Xt11 = {  "Xt11", // class name
  bases_Xt11, 2,
  &(vtc_Xt11[0]), // expected_vtbl_contents
  &(vtt_Xt11[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt11),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt11),6, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt11),2, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt12  : virtual t12 {
  virtual void  abc(); // _ZN4Xt123abcEv
  ~Xt12(); // tgen
  Xt12(); // tgen
};
//SIG(1 Xt12) C1{ VBC2{ VBC3{ m} v2} v1}


void  Xt12 ::abc(){vfunc_called(this, "_ZN4Xt123abcEv");}
Xt12 ::~Xt12(){ note_dtor("Xt12", this);} // tgen
Xt12 ::Xt12(){ note_ctor("Xt12", this);} // tgen

static void Test_Xt12()
{
  extern Class_Descriptor cd_Xt12;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt12, buf);
    Xt12 *dp, &lv = *(dp=new (buf) Xt12());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt12)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt12)");
    check_base_class_offset(lv, (ne_0*)(t12*), 0, "Xt12");
    check_base_class_offset(lv, (t12*), 0, "Xt12");
    test_class_info(&lv, &cd_Xt12);
    dp->~Xt12();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt12(Test_Xt12, "Xt12", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt12C1Ev();
extern void _ZN4Xt12D1Ev();
Name_Map name_map_Xt12[] = {
  NSPAIR(_ZN4Xt12C1Ev),
  NSPAIR(_ZN4Xt12D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_t12;
extern VTBL_ENTRY _ZTI3t12[];
extern  VTBL_ENTRY _ZTV3t12[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t12[];
static Base_Class bases_Xt12[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    1, //immediately_derived
  0, 1},
  {&cd_t12,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt12[];
extern void _ZN3t123barEv();
extern void _ZN4Xt123abcEv();
static  VTBL_ENTRY vtc_Xt12[] = {
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt12[0]),
  (VTBL_ENTRY)&_ZN3t123barEv,
  (VTBL_ENTRY)&_ZN4Xt123abcEv,
};
extern VTBL_ENTRY _ZTV4Xt12[];
extern void _ZN3t123barEv();
static  VTBL_ENTRY _tg__ZTV3t12__4Xt12[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t12[0]),
  (VTBL_ENTRY)&_ZN3t123barEv,
};
static  VTT_ENTRY vtt_Xt12[] = {
  {&(_ZTV4Xt12[5]),  5,7},
  {&(_ZTV4Xt12[5]),  5,7},
  {&(_tg__ZTV3t12__4Xt12[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt12[];
extern  VTBL_ENTRY _ZTV4Xt12[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt12[];
Class_Descriptor cd_Xt12 = {  "Xt12", // class name
  bases_Xt12, 2,
  &(vtc_Xt12[0]), // expected_vtbl_contents
  &(vtt_Xt12[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt12),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt12),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt12),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt13  : virtual t13 {
  virtual void  abc(); // _ZN4Xt133abcEv
  ~Xt13(); // tgen
  Xt13(); // tgen
};
//SIG(1 Xt13) C1{ VBC2{ BC3{ m} BC4{} v2} v1}


void  Xt13 ::abc(){vfunc_called(this, "_ZN4Xt133abcEv");}
Xt13 ::~Xt13(){ note_dtor("Xt13", this);} // tgen
Xt13 ::Xt13(){ note_ctor("Xt13", this);} // tgen

static void Test_Xt13()
{
  extern Class_Descriptor cd_Xt13;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt13, buf);
    Xt13 *dp, &lv = *(dp=new (buf) Xt13());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt13)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt13)");
    check_base_class_offset(lv, (ne_0*)(t13*), 0, "Xt13");
    check_base_class_offset(lv, (em_1*)(t13*), 0, "Xt13");
    check_base_class_offset(lv, (t13*), 0, "Xt13");
    test_class_info(&lv, &cd_Xt13);
    dp->~Xt13();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt13(Test_Xt13, "Xt13", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt13C1Ev();
extern void _ZN4Xt13D1Ev();
Name_Map name_map_Xt13[] = {
  NSPAIR(_ZN4Xt13C1Ev),
  NSPAIR(_ZN4Xt13D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
extern Class_Descriptor cd_t13;
extern VTBL_ENTRY _ZTI3t13[];
extern  VTBL_ENTRY _ZTV3t13[];
static Base_Class bases_Xt13[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_t13,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    3, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt13[];
extern void _ZN3t133barEv();
extern void _ZN4Xt133abcEv();
static  VTBL_ENTRY vtc_Xt13[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt13[0]),
  (VTBL_ENTRY)&_ZN3t133barEv,
  (VTBL_ENTRY)&_ZN4Xt133abcEv,
};
extern VTBL_ENTRY _ZTV4Xt13[];
static  VTT_ENTRY vtt_Xt13[] = {
  {&(_ZTV4Xt13[4]),  4,6},
  {&(_ZTV4Xt13[4]),  4,6},
};
extern VTBL_ENTRY _ZTI4Xt13[];
extern  VTBL_ENTRY _ZTV4Xt13[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt13[];
Class_Descriptor cd_Xt13 = {  "Xt13", // class name
  bases_Xt13, 3,
  &(vtc_Xt13[0]), // expected_vtbl_contents
  &(vtt_Xt13[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt13),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt13),6, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt13),2, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt14  : virtual t14 {
  virtual void  abc(); // _ZN4Xt143abcEv
  ~Xt14(); // tgen
  Xt14(); // tgen
};
//SIG(1 Xt14) C1{ VBC2{ VBC3{ m} BC4{} v2} v1}


void  Xt14 ::abc(){vfunc_called(this, "_ZN4Xt143abcEv");}
Xt14 ::~Xt14(){ note_dtor("Xt14", this);} // tgen
Xt14 ::Xt14(){ note_ctor("Xt14", this);} // tgen

static void Test_Xt14()
{
  extern Class_Descriptor cd_Xt14;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt14, buf);
    Xt14 *dp, &lv = *(dp=new (buf) Xt14());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt14)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt14)");
    check_base_class_offset(lv, (ne_0*)(t14*), 0, "Xt14");
    check_base_class_offset(lv, (em_1*)(t14*), 0, "Xt14");
    check_base_class_offset(lv, (t14*), 0, "Xt14");
    test_class_info(&lv, &cd_Xt14);
    dp->~Xt14();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt14(Test_Xt14, "Xt14", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt14C1Ev();
extern void _ZN4Xt14D1Ev();
Name_Map name_map_Xt14[] = {
  NSPAIR(_ZN4Xt14C1Ev),
  NSPAIR(_ZN4Xt14D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
extern Class_Descriptor cd_t14;
extern VTBL_ENTRY _ZTI3t14[];
extern  VTBL_ENTRY _ZTV3t14[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t14[];
static Base_Class bases_Xt14[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_t14,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt14[];
extern void _ZN3t143barEv();
extern void _ZN4Xt143abcEv();
static  VTBL_ENTRY vtc_Xt14[] = {
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt14[0]),
  (VTBL_ENTRY)&_ZN3t143barEv,
  (VTBL_ENTRY)&_ZN4Xt143abcEv,
};
extern VTBL_ENTRY _ZTV4Xt14[];
extern void _ZN3t143barEv();
static  VTBL_ENTRY _tg__ZTV3t14__4Xt14[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t14[0]),
  (VTBL_ENTRY)&_ZN3t143barEv,
};
static  VTT_ENTRY vtt_Xt14[] = {
  {&(_ZTV4Xt14[5]),  5,7},
  {&(_ZTV4Xt14[5]),  5,7},
  {&(_tg__ZTV3t14__4Xt14[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt14[];
extern  VTBL_ENTRY _ZTV4Xt14[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt14[];
Class_Descriptor cd_Xt14 = {  "Xt14", // class name
  bases_Xt14, 3,
  &(vtc_Xt14[0]), // expected_vtbl_contents
  &(vtt_Xt14[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt14),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt14),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt14),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt15  : virtual t15 {
  virtual void  abc(); // _ZN4Xt153abcEv
  ~Xt15(); // tgen
  Xt15(); // tgen
};
//SIG(1 Xt15) C1{ VBC2{ BC3{ m} VBC4{} v2} v1}


void  Xt15 ::abc(){vfunc_called(this, "_ZN4Xt153abcEv");}
Xt15 ::~Xt15(){ note_dtor("Xt15", this);} // tgen
Xt15 ::Xt15(){ note_ctor("Xt15", this);} // tgen

static void Test_Xt15()
{
  extern Class_Descriptor cd_Xt15;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt15, buf);
    Xt15 *dp, &lv = *(dp=new (buf) Xt15());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt15)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt15)");
    check_base_class_offset(lv, (ne_0*)(t15*), 0, "Xt15");
    check_base_class_offset(lv, (em_1*)(t15*), 0, "Xt15");
    check_base_class_offset(lv, (t15*), 0, "Xt15");
    test_class_info(&lv, &cd_Xt15);
    dp->~Xt15();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt15(Test_Xt15, "Xt15", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt15C1Ev();
extern void _ZN4Xt15D1Ev();
Name_Map name_map_Xt15[] = {
  NSPAIR(_ZN4Xt15C1Ev),
  NSPAIR(_ZN4Xt15D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
extern Class_Descriptor cd_t15;
extern VTBL_ENTRY _ZTI3t15[];
extern  VTBL_ENTRY _ZTV3t15[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t15[];
static Base_Class bases_Xt15[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_t15,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt15[];
extern void _ZN3t153barEv();
extern void _ZN4Xt153abcEv();
static  VTBL_ENTRY vtc_Xt15[] = {
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt15[0]),
  (VTBL_ENTRY)&_ZN3t153barEv,
  (VTBL_ENTRY)&_ZN4Xt153abcEv,
};
extern VTBL_ENTRY _ZTV4Xt15[];
extern void _ZN3t153barEv();
static  VTBL_ENTRY _tg__ZTV3t15__4Xt15[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t15[0]),
  (VTBL_ENTRY)&_ZN3t153barEv,
};
static  VTT_ENTRY vtt_Xt15[] = {
  {&(_ZTV4Xt15[5]),  5,7},
  {&(_ZTV4Xt15[5]),  5,7},
  {&(_tg__ZTV3t15__4Xt15[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt15[];
extern  VTBL_ENTRY _ZTV4Xt15[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt15[];
Class_Descriptor cd_Xt15 = {  "Xt15", // class name
  bases_Xt15, 3,
  &(vtc_Xt15[0]), // expected_vtbl_contents
  &(vtt_Xt15[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt15),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt15),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt15),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt16  : virtual t16 {
  virtual void  abc(); // _ZN4Xt163abcEv
  ~Xt16(); // tgen
  Xt16(); // tgen
};
//SIG(1 Xt16) C1{ VBC2{ VBC3{ m} VBC4{} v2} v1}


void  Xt16 ::abc(){vfunc_called(this, "_ZN4Xt163abcEv");}
Xt16 ::~Xt16(){ note_dtor("Xt16", this);} // tgen
Xt16 ::Xt16(){ note_ctor("Xt16", this);} // tgen

static void Test_Xt16()
{
  extern Class_Descriptor cd_Xt16;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt16, buf);
    Xt16 *dp, &lv = *(dp=new (buf) Xt16());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt16)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt16)");
    check_base_class_offset(lv, (ne_0*)(t16*), 0, "Xt16");
    check_base_class_offset(lv, (em_1*)(t16*), 0, "Xt16");
    check_base_class_offset(lv, (t16*), 0, "Xt16");
    test_class_info(&lv, &cd_Xt16);
    dp->~Xt16();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt16(Test_Xt16, "Xt16", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt16C1Ev();
extern void _ZN4Xt16D1Ev();
Name_Map name_map_Xt16[] = {
  NSPAIR(_ZN4Xt16C1Ev),
  NSPAIR(_ZN4Xt16D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
extern Class_Descriptor cd_t16;
extern VTBL_ENTRY _ZTI3t16[];
extern  VTBL_ENTRY _ZTV3t16[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t16[];
static Base_Class bases_Xt16[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_t16,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    5, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt16[];
extern void _ZN3t163barEv();
extern void _ZN4Xt163abcEv();
static  VTBL_ENTRY vtc_Xt16[] = {
  0,
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt16[0]),
  (VTBL_ENTRY)&_ZN3t163barEv,
  (VTBL_ENTRY)&_ZN4Xt163abcEv,
};
extern VTBL_ENTRY _ZTV4Xt16[];
extern void _ZN3t163barEv();
static  VTBL_ENTRY _tg__ZTV3t16__4Xt16[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t16[0]),
  (VTBL_ENTRY)&_ZN3t163barEv,
};
static  VTT_ENTRY vtt_Xt16[] = {
  {&(_ZTV4Xt16[6]),  6,8},
  {&(_ZTV4Xt16[6]),  6,8},
  {&(_tg__ZTV3t16__4Xt16[4]),  4,5},
};
extern VTBL_ENTRY _ZTI4Xt16[];
extern  VTBL_ENTRY _ZTV4Xt16[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt16[];
Class_Descriptor cd_Xt16 = {  "Xt16", // class name
  bases_Xt16, 3,
  &(vtc_Xt16[0]), // expected_vtbl_contents
  &(vtt_Xt16[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt16),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt16),8, //virtual function table var
  6, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt16),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt17  : virtual t17 {
  virtual void  abc(); // _ZN4Xt173abcEv
  ~Xt17(); // tgen
  Xt17(); // tgen
};
//SIG(1 Xt17) C1{ VBC2{ BC3{ m} BC4{ m Fi:0} v2} v1}


void  Xt17 ::abc(){vfunc_called(this, "_ZN4Xt173abcEv");}
Xt17 ::~Xt17(){ note_dtor("Xt17", this);} // tgen
Xt17 ::Xt17(){ note_ctor("Xt17", this);} // tgen

static void Test_Xt17()
{
  extern Class_Descriptor cd_Xt17;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt17, buf);
    Xt17 *dp, &lv = *(dp=new (buf) Xt17());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt17)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt17)");
    check_base_class_offset(lv, (ne_0*)(t17*), 0, "Xt17");
    check_base_class_offset(lv, (ne_1*)(t17*), 0, "Xt17");
    check_base_class_offset(lv, (t17*), 0, "Xt17");
    test_class_info(&lv, &cd_Xt17);
    dp->~Xt17();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt17(Test_Xt17, "Xt17", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt17C1Ev();
extern void _ZN4Xt17D1Ev();
Name_Map name_map_Xt17[] = {
  NSPAIR(_ZN4Xt17C1Ev),
  NSPAIR(_ZN4Xt17D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
extern Class_Descriptor cd_t17;
extern VTBL_ENTRY _ZTI3t17[];
extern  VTBL_ENTRY _ZTV3t17[];
static Base_Class bases_Xt17[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_t17,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    3, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt17[];
extern void _ZN3t173barEv();
extern void _ZN4Xt173abcEv();
static  VTBL_ENTRY vtc_Xt17[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt17[0]),
  (VTBL_ENTRY)&_ZN3t173barEv,
  (VTBL_ENTRY)&_ZN4Xt173abcEv,
};
extern VTBL_ENTRY _ZTV4Xt17[];
static  VTT_ENTRY vtt_Xt17[] = {
  {&(_ZTV4Xt17[4]),  4,6},
  {&(_ZTV4Xt17[4]),  4,6},
};
extern VTBL_ENTRY _ZTI4Xt17[];
extern  VTBL_ENTRY _ZTV4Xt17[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt17[];
Class_Descriptor cd_Xt17 = {  "Xt17", // class name
  bases_Xt17, 3,
  &(vtc_Xt17[0]), // expected_vtbl_contents
  &(vtt_Xt17[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt17),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt17),6, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt17),2, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt18  : virtual t18 {
  virtual void  abc(); // _ZN4Xt183abcEv
  ~Xt18(); // tgen
  Xt18(); // tgen
};
//SIG(1 Xt18) C1{ VBC2{ VBC3{ m} BC4{ m Fi:0} v2} v1}


void  Xt18 ::abc(){vfunc_called(this, "_ZN4Xt183abcEv");}
Xt18 ::~Xt18(){ note_dtor("Xt18", this);} // tgen
Xt18 ::Xt18(){ note_ctor("Xt18", this);} // tgen

static void Test_Xt18()
{
  extern Class_Descriptor cd_Xt18;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt18, buf);
    Xt18 *dp, &lv = *(dp=new (buf) Xt18());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt18)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt18)");
    check_base_class_offset(lv, (ne_0*)(t18*), 0, "Xt18");
    check_base_class_offset(lv, (ne_1*)(t18*), 0, "Xt18");
    check_base_class_offset(lv, (t18*), 0, "Xt18");
    test_class_info(&lv, &cd_Xt18);
    dp->~Xt18();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt18(Test_Xt18, "Xt18", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt18C1Ev();
extern void _ZN4Xt18D1Ev();
Name_Map name_map_Xt18[] = {
  NSPAIR(_ZN4Xt18C1Ev),
  NSPAIR(_ZN4Xt18D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
extern Class_Descriptor cd_t18;
extern VTBL_ENTRY _ZTI3t18[];
extern  VTBL_ENTRY _ZTV3t18[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t18[];
static Base_Class bases_Xt18[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_t18,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt18[];
extern void _ZN3t183barEv();
extern void _ZN4Xt183abcEv();
static  VTBL_ENTRY vtc_Xt18[] = {
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt18[0]),
  (VTBL_ENTRY)&_ZN3t183barEv,
  (VTBL_ENTRY)&_ZN4Xt183abcEv,
};
extern VTBL_ENTRY _ZTV4Xt18[];
extern void _ZN3t183barEv();
static  VTBL_ENTRY _tg__ZTV3t18__4Xt18[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t18[0]),
  (VTBL_ENTRY)&_ZN3t183barEv,
};
static  VTT_ENTRY vtt_Xt18[] = {
  {&(_ZTV4Xt18[5]),  5,7},
  {&(_ZTV4Xt18[5]),  5,7},
  {&(_tg__ZTV3t18__4Xt18[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt18[];
extern  VTBL_ENTRY _ZTV4Xt18[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt18[];
Class_Descriptor cd_Xt18 = {  "Xt18", // class name
  bases_Xt18, 3,
  &(vtc_Xt18[0]), // expected_vtbl_contents
  &(vtt_Xt18[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt18),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt18),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt18),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt19  : virtual t19 {
  virtual void  abc(); // _ZN4Xt193abcEv
  ~Xt19(); // tgen
  Xt19(); // tgen
};
//SIG(1 Xt19) C1{ VBC2{ BC3{ m} VBC4{ m Fi:0} v2} v1}


void  Xt19 ::abc(){vfunc_called(this, "_ZN4Xt193abcEv");}
Xt19 ::~Xt19(){ note_dtor("Xt19", this);} // tgen
Xt19 ::Xt19(){ note_ctor("Xt19", this);} // tgen

static void Test_Xt19()
{
  extern Class_Descriptor cd_Xt19;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt19, buf);
    Xt19 *dp, &lv = *(dp=new (buf) Xt19());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt19)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt19)");
    check_base_class_offset(lv, (ne_0*)(t19*), 0, "Xt19");
    check_base_class_offset(lv, (ne_1*)(t19*), 0, "Xt19");
    check_base_class_offset(lv, (t19*), 0, "Xt19");
    test_class_info(&lv, &cd_Xt19);
    dp->~Xt19();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt19(Test_Xt19, "Xt19", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt19C1Ev();
extern void _ZN4Xt19D1Ev();
Name_Map name_map_Xt19[] = {
  NSPAIR(_ZN4Xt19C1Ev),
  NSPAIR(_ZN4Xt19D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
extern Class_Descriptor cd_t19;
extern VTBL_ENTRY _ZTI3t19[];
extern  VTBL_ENTRY _ZTV3t19[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t19[];
static Base_Class bases_Xt19[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_t19,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt19[];
extern void _ZN3t193barEv();
extern void _ZN4Xt193abcEv();
static  VTBL_ENTRY vtc_Xt19[] = {
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt19[0]),
  (VTBL_ENTRY)&_ZN3t193barEv,
  (VTBL_ENTRY)&_ZN4Xt193abcEv,
};
extern VTBL_ENTRY _ZTV4Xt19[];
extern void _ZN3t193barEv();
static  VTBL_ENTRY _tg__ZTV3t19__4Xt19[] = {
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t19[0]),
  (VTBL_ENTRY)&_ZN3t193barEv,
};
static  VTT_ENTRY vtt_Xt19[] = {
  {&(_ZTV4Xt19[5]),  5,7},
  {&(_ZTV4Xt19[5]),  5,7},
  {&(_tg__ZTV3t19__4Xt19[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt19[];
extern  VTBL_ENTRY _ZTV4Xt19[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt19[];
Class_Descriptor cd_Xt19 = {  "Xt19", // class name
  bases_Xt19, 3,
  &(vtc_Xt19[0]), // expected_vtbl_contents
  &(vtt_Xt19[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt19),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt19),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt19),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt20  : virtual t20 {
  virtual void  abc(); // _ZN4Xt203abcEv
  ~Xt20(); // tgen
  Xt20(); // tgen
};
//SIG(1 Xt20) C1{ VBC2{ VBC3{ m} VBC4{ m Fi:0} v2} v1}


void  Xt20 ::abc(){vfunc_called(this, "_ZN4Xt203abcEv");}
Xt20 ::~Xt20(){ note_dtor("Xt20", this);} // tgen
Xt20 ::Xt20(){ note_ctor("Xt20", this);} // tgen

static void Test_Xt20()
{
  extern Class_Descriptor cd_Xt20;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_Xt20, buf);
    Xt20 *dp, &lv = *(dp=new (buf) Xt20());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(Xt20)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt20)");
    check_base_class_offset(lv, (ne_0*)(t20*), 0, "Xt20");
    check_base_class_offset(lv, (ne_1*)(t20*), 0, "Xt20");
    check_base_class_offset(lv, (t20*), 0, "Xt20");
    test_class_info(&lv, &cd_Xt20);
    dp->~Xt20();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt20(Test_Xt20, "Xt20", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4Xt20C1Ev();
extern void _ZN4Xt20D1Ev();
Name_Map name_map_Xt20[] = {
  NSPAIR(_ZN4Xt20C1Ev),
  NSPAIR(_ZN4Xt20D1Ev),
  {0,0}
};
extern Class_Descriptor cd_ne_0;
extern VTBL_ENTRY _ZTI4ne_0[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
extern Class_Descriptor cd_t20;
extern VTBL_ENTRY _ZTI3t20[];
extern  VTBL_ENTRY _ZTV3t20[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t20[];
static Base_Class bases_Xt20[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_ne_0,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_t20,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    5, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt20[];
extern void _ZN3t203barEv();
extern void _ZN4Xt203abcEv();
static  VTBL_ENTRY vtc_Xt20[] = {
  0,
  0,
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI4Xt20[0]),
  (VTBL_ENTRY)&_ZN3t203barEv,
  (VTBL_ENTRY)&_ZN4Xt203abcEv,
};
extern VTBL_ENTRY _ZTV4Xt20[];
extern void _ZN3t203barEv();
static  VTBL_ENTRY _tg__ZTV3t20__4Xt20[] = {
  0,
  0,
  0,
  (VTBL_ENTRY)&(_ZTI3t20[0]),
  (VTBL_ENTRY)&_ZN3t203barEv,
};
static  VTT_ENTRY vtt_Xt20[] = {
  {&(_ZTV4Xt20[6]),  6,8},
  {&(_ZTV4Xt20[6]),  6,8},
  {&(_tg__ZTV3t20__4Xt20[4]),  4,5},
};
extern VTBL_ENTRY _ZTI4Xt20[];
extern  VTBL_ENTRY _ZTV4Xt20[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt20[];
Class_Descriptor cd_Xt20 = {  "Xt20", // class name
  bases_Xt20, 3,
  &(vtc_Xt20[0]), // expected_vtbl_contents
  &(vtt_Xt20[0]), // expected_vtt_contents
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4Xt20),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt20),8, //virtual function table var
  6, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt20),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt21  : virtual t21 {
  virtual void  abc(); // _ZN4Xt213abcEv
  ~Xt21(); // tgen
  Xt21(); // tgen
};
//SIG(1 Xt21) C1{ VBC2{ BC3{ Fi} v2} v1}


void  Xt21 ::abc(){vfunc_called(this, "_ZN4Xt213abcEv");}
Xt21 ::~Xt21(){ note_dtor("Xt21", this);} // tgen
Xt21 ::Xt21(){ note_ctor("Xt21", this);} // tgen

static void Test_Xt21()
{
  extern Class_Descriptor cd_Xt21;
  void *lvp;
  {
    ABISELECT(double,int) buf[4];
    init_test(&cd_Xt21, buf);
    Xt21 *dp, &lv = *(dp=new (buf) Xt21());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Xt21)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt21)");
    check_base_class_offset(lv, (xx*)(t21*), ABISELECT(16,8), "Xt21");
    check_base_class_offset(lv, (t21*), ABISELECT(8,4), "Xt21");
    test_class_info(&lv, &cd_Xt21);
    dp->~Xt21();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt21(Test_Xt21, "Xt21", ABISELECT(24,12));

#else // __cplusplus

extern void _ZN4Xt21C1Ev();
extern void _ZN4Xt21D1Ev();
Name_Map name_map_Xt21[] = {
  NSPAIR(_ZN4Xt21C1Ev),
  NSPAIR(_ZN4Xt21D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_t21;
extern VTBL_ENTRY _ZTI3t21[];
extern  VTBL_ENTRY _ZTV3t21[];
static Base_Class bases_Xt21[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(16,8), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    1, //immediately_derived
  0, 0},
  {&cd_t21,    ABISELECT(8,4), //bcp->offset
    4, //bcp->virtual_function_table_offset
    3, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt21[];
extern void _ZN4Xt213abcEv();
extern void _ZN3t213barEv();
static  VTBL_ENTRY vtc_Xt21[] = {
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI4Xt21[0]),
  (VTBL_ENTRY)&_ZN4Xt213abcEv,
  0,
  ABISELECT(-8,-4),
  (VTBL_ENTRY)&(_ZTI4Xt21[0]),
  (VTBL_ENTRY)&_ZN3t213barEv,
};
extern VTBL_ENTRY _ZTV4Xt21[];
static  VTT_ENTRY vtt_Xt21[] = {
  {&(_ZTV4Xt21[3]),  3,8},
  {&(_ZTV4Xt21[7]),  7,8},
};
extern VTBL_ENTRY _ZTI4Xt21[];
extern  VTBL_ENTRY _ZTV4Xt21[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt21[];
Class_Descriptor cd_Xt21 = {  "Xt21", // class name
  bases_Xt21, 2,
  &(vtc_Xt21[0]), // expected_vtbl_contents
  &(vtt_Xt21[0]), // expected_vtt_contents
  ABISELECT(24,12), // object size
  NSPAIRA(_ZTI4Xt21),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt21),8, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt21),2, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt22  : virtual t22 {
  virtual void  abc(); // _ZN4Xt223abcEv
  ~Xt22(); // tgen
  Xt22(); // tgen
};
//SIG(1 Xt22) C1{ VBC2{ VBC3{ Fi} v2} v1}


void  Xt22 ::abc(){vfunc_called(this, "_ZN4Xt223abcEv");}
Xt22 ::~Xt22(){ note_dtor("Xt22", this);} // tgen
Xt22 ::Xt22(){ note_ctor("Xt22", this);} // tgen

static void Test_Xt22()
{
  extern Class_Descriptor cd_Xt22;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_Xt22, buf);
    Xt22 *dp, &lv = *(dp=new (buf) Xt22());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Xt22)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt22)");
    check_base_class_offset(lv, (xx*)(t22*), ABISELECT(8,4), "Xt22");
    check_base_class_offset(lv, (t22*), 0, "Xt22");
    test_class_info(&lv, &cd_Xt22);
    dp->~Xt22();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt22(Test_Xt22, "Xt22", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN4Xt22C1Ev();
extern void _ZN4Xt22D1Ev();
Name_Map name_map_Xt22[] = {
  NSPAIR(_ZN4Xt22C1Ev),
  NSPAIR(_ZN4Xt22D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_t22;
extern VTBL_ENTRY _ZTI3t22[];
extern  VTBL_ENTRY _ZTV3t22[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t22[];
static Base_Class bases_Xt22[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    1, //immediately_derived
  0, 1},
  {&cd_t22,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt22[];
extern void _ZN3t223barEv();
extern void _ZN4Xt223abcEv();
static  VTBL_ENTRY vtc_Xt22[] = {
  0,
  0,
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI4Xt22[0]),
  (VTBL_ENTRY)&_ZN3t223barEv,
  (VTBL_ENTRY)&_ZN4Xt223abcEv,
};
extern VTBL_ENTRY _ZTV4Xt22[];
extern void _ZN3t223barEv();
static  VTBL_ENTRY _tg__ZTV3t22__4Xt22[] = {
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI3t22[0]),
  (VTBL_ENTRY)&_ZN3t223barEv,
};
static  VTT_ENTRY vtt_Xt22[] = {
  {&(_ZTV4Xt22[5]),  5,7},
  {&(_ZTV4Xt22[5]),  5,7},
  {&(_tg__ZTV3t22__4Xt22[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt22[];
extern  VTBL_ENTRY _ZTV4Xt22[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt22[];
Class_Descriptor cd_Xt22 = {  "Xt22", // class name
  bases_Xt22, 2,
  &(vtc_Xt22[0]), // expected_vtbl_contents
  &(vtt_Xt22[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI4Xt22),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt22),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt22),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt23  : virtual t23 {
  virtual void  abc(); // _ZN4Xt233abcEv
  ~Xt23(); // tgen
  Xt23(); // tgen
};
//SIG(1 Xt23) C1{ VBC2{ BC3{ Fi} BC4{} v2} v1}


void  Xt23 ::abc(){vfunc_called(this, "_ZN4Xt233abcEv");}
Xt23 ::~Xt23(){ note_dtor("Xt23", this);} // tgen
Xt23 ::Xt23(){ note_ctor("Xt23", this);} // tgen

static void Test_Xt23()
{
  extern Class_Descriptor cd_Xt23;
  void *lvp;
  {
    ABISELECT(double,int) buf[4];
    init_test(&cd_Xt23, buf);
    Xt23 *dp, &lv = *(dp=new (buf) Xt23());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Xt23)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt23)");
    check_base_class_offset(lv, (xx*)(t23*), ABISELECT(16,8), "Xt23");
    check_base_class_offset(lv, (em_1*)(t23*), ABISELECT(8,4), "Xt23");
    check_base_class_offset(lv, (t23*), ABISELECT(8,4), "Xt23");
    test_class_info(&lv, &cd_Xt23);
    dp->~Xt23();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt23(Test_Xt23, "Xt23", ABISELECT(24,12));

#else // __cplusplus

extern void _ZN4Xt23C1Ev();
extern void _ZN4Xt23D1Ev();
Name_Map name_map_Xt23[] = {
  NSPAIR(_ZN4Xt23C1Ev),
  NSPAIR(_ZN4Xt23D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
extern Class_Descriptor cd_t23;
extern VTBL_ENTRY _ZTI3t23[];
extern  VTBL_ENTRY _ZTV3t23[];
static Base_Class bases_Xt23[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(16,8), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_em_1,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_t23,    ABISELECT(8,4), //bcp->offset
    4, //bcp->virtual_function_table_offset
    3, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt23[];
extern void _ZN4Xt233abcEv();
extern void _ZN3t233barEv();
static  VTBL_ENTRY vtc_Xt23[] = {
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI4Xt23[0]),
  (VTBL_ENTRY)&_ZN4Xt233abcEv,
  0,
  ABISELECT(-8,-4),
  (VTBL_ENTRY)&(_ZTI4Xt23[0]),
  (VTBL_ENTRY)&_ZN3t233barEv,
};
extern VTBL_ENTRY _ZTV4Xt23[];
static  VTT_ENTRY vtt_Xt23[] = {
  {&(_ZTV4Xt23[3]),  3,8},
  {&(_ZTV4Xt23[7]),  7,8},
};
extern VTBL_ENTRY _ZTI4Xt23[];
extern  VTBL_ENTRY _ZTV4Xt23[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt23[];
Class_Descriptor cd_Xt23 = {  "Xt23", // class name
  bases_Xt23, 3,
  &(vtc_Xt23[0]), // expected_vtbl_contents
  &(vtt_Xt23[0]), // expected_vtt_contents
  ABISELECT(24,12), // object size
  NSPAIRA(_ZTI4Xt23),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt23),8, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt23),2, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt24  : virtual t24 {
  virtual void  abc(); // _ZN4Xt243abcEv
  ~Xt24(); // tgen
  Xt24(); // tgen
};
//SIG(1 Xt24) C1{ VBC2{ VBC3{ Fi} BC4{} v2} v1}


void  Xt24 ::abc(){vfunc_called(this, "_ZN4Xt243abcEv");}
Xt24 ::~Xt24(){ note_dtor("Xt24", this);} // tgen
Xt24 ::Xt24(){ note_ctor("Xt24", this);} // tgen

static void Test_Xt24()
{
  extern Class_Descriptor cd_Xt24;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_Xt24, buf);
    Xt24 *dp, &lv = *(dp=new (buf) Xt24());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Xt24)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt24)");
    check_base_class_offset(lv, (xx*)(t24*), ABISELECT(8,4), "Xt24");
    check_base_class_offset(lv, (em_1*)(t24*), 0, "Xt24");
    check_base_class_offset(lv, (t24*), 0, "Xt24");
    test_class_info(&lv, &cd_Xt24);
    dp->~Xt24();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt24(Test_Xt24, "Xt24", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN4Xt24C1Ev();
extern void _ZN4Xt24D1Ev();
Name_Map name_map_Xt24[] = {
  NSPAIR(_ZN4Xt24C1Ev),
  NSPAIR(_ZN4Xt24D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
extern Class_Descriptor cd_t24;
extern VTBL_ENTRY _ZTI3t24[];
extern  VTBL_ENTRY _ZTV3t24[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t24[];
static Base_Class bases_Xt24[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_t24,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt24[];
extern void _ZN3t243barEv();
extern void _ZN4Xt243abcEv();
static  VTBL_ENTRY vtc_Xt24[] = {
  0,
  0,
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI4Xt24[0]),
  (VTBL_ENTRY)&_ZN3t243barEv,
  (VTBL_ENTRY)&_ZN4Xt243abcEv,
};
extern VTBL_ENTRY _ZTV4Xt24[];
extern void _ZN3t243barEv();
static  VTBL_ENTRY _tg__ZTV3t24__4Xt24[] = {
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI3t24[0]),
  (VTBL_ENTRY)&_ZN3t243barEv,
};
static  VTT_ENTRY vtt_Xt24[] = {
  {&(_ZTV4Xt24[5]),  5,7},
  {&(_ZTV4Xt24[5]),  5,7},
  {&(_tg__ZTV3t24__4Xt24[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt24[];
extern  VTBL_ENTRY _ZTV4Xt24[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt24[];
Class_Descriptor cd_Xt24 = {  "Xt24", // class name
  bases_Xt24, 3,
  &(vtc_Xt24[0]), // expected_vtbl_contents
  &(vtt_Xt24[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI4Xt24),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt24),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt24),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt25  : virtual t25 {
  virtual void  abc(); // _ZN4Xt253abcEv
  ~Xt25(); // tgen
  Xt25(); // tgen
};
//SIG(1 Xt25) C1{ VBC2{ BC3{ Fi} VBC4{} v2} v1}


void  Xt25 ::abc(){vfunc_called(this, "_ZN4Xt253abcEv");}
Xt25 ::~Xt25(){ note_dtor("Xt25", this);} // tgen
Xt25 ::Xt25(){ note_ctor("Xt25", this);} // tgen

static void Test_Xt25()
{
  extern Class_Descriptor cd_Xt25;
  void *lvp;
  {
    ABISELECT(double,int) buf[4];
    init_test(&cd_Xt25, buf);
    Xt25 *dp, &lv = *(dp=new (buf) Xt25());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Xt25)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt25)");
    check_base_class_offset(lv, (xx*)(t25*), ABISELECT(16,8), "Xt25");
    check_base_class_offset(lv, (em_1*)(t25*), 0, "Xt25");
    check_base_class_offset(lv, (t25*), ABISELECT(8,4), "Xt25");
    test_class_info(&lv, &cd_Xt25);
    dp->~Xt25();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt25(Test_Xt25, "Xt25", ABISELECT(24,12));

#else // __cplusplus

extern void _ZN4Xt25C1Ev();
extern void _ZN4Xt25D1Ev();
Name_Map name_map_Xt25[] = {
  NSPAIR(_ZN4Xt25C1Ev),
  NSPAIR(_ZN4Xt25D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
extern Class_Descriptor cd_t25;
extern VTBL_ENTRY _ZTI3t25[];
extern  VTBL_ENTRY _ZTV3t25[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t25[];
static Base_Class bases_Xt25[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(16,8), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_t25,    ABISELECT(8,4), //bcp->offset
    5, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt25[];
extern void _ZN4Xt253abcEv();
extern void _ZN3t253barEv();
static  VTBL_ENTRY vtc_Xt25[] = {
  0,
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI4Xt25[0]),
  (VTBL_ENTRY)&_ZN4Xt253abcEv,
  0,
  ABISELECT(-8,-4),
  ABISELECT(-8,-4),
  (VTBL_ENTRY)&(_ZTI4Xt25[0]),
  (VTBL_ENTRY)&_ZN3t253barEv,
};
extern VTBL_ENTRY _ZTV4Xt25[];
extern void _ZN3t253barEv();
static  VTBL_ENTRY _tg__ZTV3t25__4Xt25[] = {
  ABISELECT(-8,-4),
  0,
  (VTBL_ENTRY)&(_ZTI3t25[0]),
  (VTBL_ENTRY)&_ZN3t253barEv,
};
static  VTT_ENTRY vtt_Xt25[] = {
  {&(_ZTV4Xt25[4]),  4,10},
  {&(_ZTV4Xt25[9]),  9,10},
  {&(_tg__ZTV3t25__4Xt25[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt25[];
extern  VTBL_ENTRY _ZTV4Xt25[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt25[];
Class_Descriptor cd_Xt25 = {  "Xt25", // class name
  bases_Xt25, 3,
  &(vtc_Xt25[0]), // expected_vtbl_contents
  &(vtt_Xt25[0]), // expected_vtt_contents
  ABISELECT(24,12), // object size
  NSPAIRA(_ZTI4Xt25),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt25),10, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt25),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt26  : virtual t26 {
  virtual void  abc(); // _ZN4Xt263abcEv
  ~Xt26(); // tgen
  Xt26(); // tgen
};
//SIG(1 Xt26) C1{ VBC2{ VBC3{ Fi} VBC4{} v2} v1}


void  Xt26 ::abc(){vfunc_called(this, "_ZN4Xt263abcEv");}
Xt26 ::~Xt26(){ note_dtor("Xt26", this);} // tgen
Xt26 ::Xt26(){ note_ctor("Xt26", this);} // tgen

static void Test_Xt26()
{
  extern Class_Descriptor cd_Xt26;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_Xt26, buf);
    Xt26 *dp, &lv = *(dp=new (buf) Xt26());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Xt26)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt26)");
    check_base_class_offset(lv, (xx*)(t26*), ABISELECT(8,4), "Xt26");
    check_base_class_offset(lv, (em_1*)(t26*), 0, "Xt26");
    check_base_class_offset(lv, (t26*), 0, "Xt26");
    test_class_info(&lv, &cd_Xt26);
    dp->~Xt26();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt26(Test_Xt26, "Xt26", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN4Xt26C1Ev();
extern void _ZN4Xt26D1Ev();
Name_Map name_map_Xt26[] = {
  NSPAIR(_ZN4Xt26C1Ev),
  NSPAIR(_ZN4Xt26D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_em_1;
extern VTBL_ENTRY _ZTI4em_1[];
extern Class_Descriptor cd_t26;
extern VTBL_ENTRY _ZTI3t26[];
extern  VTBL_ENTRY _ZTV3t26[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t26[];
static Base_Class bases_Xt26[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_em_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_t26,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    5, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt26[];
extern void _ZN3t263barEv();
extern void _ZN4Xt263abcEv();
static  VTBL_ENTRY vtc_Xt26[] = {
  0,
  0,
  0,
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI4Xt26[0]),
  (VTBL_ENTRY)&_ZN3t263barEv,
  (VTBL_ENTRY)&_ZN4Xt263abcEv,
};
extern VTBL_ENTRY _ZTV4Xt26[];
extern void _ZN3t263barEv();
static  VTBL_ENTRY _tg__ZTV3t26__4Xt26[] = {
  0,
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI3t26[0]),
  (VTBL_ENTRY)&_ZN3t263barEv,
};
static  VTT_ENTRY vtt_Xt26[] = {
  {&(_ZTV4Xt26[6]),  6,8},
  {&(_ZTV4Xt26[6]),  6,8},
  {&(_tg__ZTV3t26__4Xt26[4]),  4,5},
};
extern VTBL_ENTRY _ZTI4Xt26[];
extern  VTBL_ENTRY _ZTV4Xt26[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt26[];
Class_Descriptor cd_Xt26 = {  "Xt26", // class name
  bases_Xt26, 3,
  &(vtc_Xt26[0]), // expected_vtbl_contents
  &(vtt_Xt26[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI4Xt26),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt26),8, //virtual function table var
  6, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt26),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt27  : virtual t27 {
  virtual void  abc(); // _ZN4Xt273abcEv
  ~Xt27(); // tgen
  Xt27(); // tgen
};
//SIG(1 Xt27) C1{ VBC2{ BC3{ Fi} BC4{ m Fi:0} v2} v1}


void  Xt27 ::abc(){vfunc_called(this, "_ZN4Xt273abcEv");}
Xt27 ::~Xt27(){ note_dtor("Xt27", this);} // tgen
Xt27 ::Xt27(){ note_ctor("Xt27", this);} // tgen

static void Test_Xt27()
{
  extern Class_Descriptor cd_Xt27;
  void *lvp;
  {
    ABISELECT(double,int) buf[4];
    init_test(&cd_Xt27, buf);
    Xt27 *dp, &lv = *(dp=new (buf) Xt27());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Xt27)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt27)");
    check_base_class_offset(lv, (xx*)(t27*), ABISELECT(16,8), "Xt27");
    check_base_class_offset(lv, (ne_1*)(t27*), ABISELECT(8,4), "Xt27");
    check_base_class_offset(lv, (t27*), ABISELECT(8,4), "Xt27");
    test_class_info(&lv, &cd_Xt27);
    dp->~Xt27();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt27(Test_Xt27, "Xt27", ABISELECT(24,12));

#else // __cplusplus

extern void _ZN4Xt27C1Ev();
extern void _ZN4Xt27D1Ev();
Name_Map name_map_Xt27[] = {
  NSPAIR(_ZN4Xt27C1Ev),
  NSPAIR(_ZN4Xt27D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
extern Class_Descriptor cd_t27;
extern VTBL_ENTRY _ZTI3t27[];
extern  VTBL_ENTRY _ZTV3t27[];
static Base_Class bases_Xt27[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(16,8), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_ne_1,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_t27,    ABISELECT(8,4), //bcp->offset
    4, //bcp->virtual_function_table_offset
    3, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt27[];
extern void _ZN4Xt273abcEv();
extern void _ZN3t273barEv();
static  VTBL_ENTRY vtc_Xt27[] = {
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI4Xt27[0]),
  (VTBL_ENTRY)&_ZN4Xt273abcEv,
  0,
  ABISELECT(-8,-4),
  (VTBL_ENTRY)&(_ZTI4Xt27[0]),
  (VTBL_ENTRY)&_ZN3t273barEv,
};
extern VTBL_ENTRY _ZTV4Xt27[];
static  VTT_ENTRY vtt_Xt27[] = {
  {&(_ZTV4Xt27[3]),  3,8},
  {&(_ZTV4Xt27[7]),  7,8},
};
extern VTBL_ENTRY _ZTI4Xt27[];
extern  VTBL_ENTRY _ZTV4Xt27[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt27[];
Class_Descriptor cd_Xt27 = {  "Xt27", // class name
  bases_Xt27, 3,
  &(vtc_Xt27[0]), // expected_vtbl_contents
  &(vtt_Xt27[0]), // expected_vtt_contents
  ABISELECT(24,12), // object size
  NSPAIRA(_ZTI4Xt27),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt27),8, //virtual function table var
  3, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt27),2, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt28  : virtual t28 {
  virtual void  abc(); // _ZN4Xt283abcEv
  ~Xt28(); // tgen
  Xt28(); // tgen
};
//SIG(1 Xt28) C1{ VBC2{ VBC3{ Fi} BC4{ m Fi:0} v2} v1}


void  Xt28 ::abc(){vfunc_called(this, "_ZN4Xt283abcEv");}
Xt28 ::~Xt28(){ note_dtor("Xt28", this);} // tgen
Xt28 ::Xt28(){ note_ctor("Xt28", this);} // tgen

static void Test_Xt28()
{
  extern Class_Descriptor cd_Xt28;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_Xt28, buf);
    Xt28 *dp, &lv = *(dp=new (buf) Xt28());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Xt28)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt28)");
    check_base_class_offset(lv, (xx*)(t28*), ABISELECT(8,4), "Xt28");
    check_base_class_offset(lv, (ne_1*)(t28*), 0, "Xt28");
    check_base_class_offset(lv, (t28*), 0, "Xt28");
    test_class_info(&lv, &cd_Xt28);
    dp->~Xt28();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt28(Test_Xt28, "Xt28", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN4Xt28C1Ev();
extern void _ZN4Xt28D1Ev();
Name_Map name_map_Xt28[] = {
  NSPAIR(_ZN4Xt28C1Ev),
  NSPAIR(_ZN4Xt28D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
extern Class_Descriptor cd_t28;
extern VTBL_ENTRY _ZTI3t28[];
extern  VTBL_ENTRY _ZTV3t28[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t28[];
static Base_Class bases_Xt28[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_t28,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt28[];
extern void _ZN3t283barEv();
extern void _ZN4Xt283abcEv();
static  VTBL_ENTRY vtc_Xt28[] = {
  0,
  0,
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI4Xt28[0]),
  (VTBL_ENTRY)&_ZN3t283barEv,
  (VTBL_ENTRY)&_ZN4Xt283abcEv,
};
extern VTBL_ENTRY _ZTV4Xt28[];
extern void _ZN3t283barEv();
static  VTBL_ENTRY _tg__ZTV3t28__4Xt28[] = {
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI3t28[0]),
  (VTBL_ENTRY)&_ZN3t283barEv,
};
static  VTT_ENTRY vtt_Xt28[] = {
  {&(_ZTV4Xt28[5]),  5,7},
  {&(_ZTV4Xt28[5]),  5,7},
  {&(_tg__ZTV3t28__4Xt28[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt28[];
extern  VTBL_ENTRY _ZTV4Xt28[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt28[];
Class_Descriptor cd_Xt28 = {  "Xt28", // class name
  bases_Xt28, 3,
  &(vtc_Xt28[0]), // expected_vtbl_contents
  &(vtt_Xt28[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI4Xt28),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt28),7, //virtual function table var
  5, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt28),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt29  : virtual t29 {
  virtual void  abc(); // _ZN4Xt293abcEv
  ~Xt29(); // tgen
  Xt29(); // tgen
};
//SIG(1 Xt29) C1{ VBC2{ BC3{ Fi} VBC4{ m Fi:0} v2} v1}


void  Xt29 ::abc(){vfunc_called(this, "_ZN4Xt293abcEv");}
Xt29 ::~Xt29(){ note_dtor("Xt29", this);} // tgen
Xt29 ::Xt29(){ note_ctor("Xt29", this);} // tgen

static void Test_Xt29()
{
  extern Class_Descriptor cd_Xt29;
  void *lvp;
  {
    ABISELECT(double,int) buf[4];
    init_test(&cd_Xt29, buf);
    Xt29 *dp, &lv = *(dp=new (buf) Xt29());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(24,12), "sizeof(Xt29)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt29)");
    check_base_class_offset(lv, (xx*)(t29*), ABISELECT(16,8), "Xt29");
    check_base_class_offset(lv, (ne_1*)(t29*), 0, "Xt29");
    check_base_class_offset(lv, (t29*), ABISELECT(8,4), "Xt29");
    test_class_info(&lv, &cd_Xt29);
    dp->~Xt29();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt29(Test_Xt29, "Xt29", ABISELECT(24,12));

#else // __cplusplus

extern void _ZN4Xt29C1Ev();
extern void _ZN4Xt29D1Ev();
Name_Map name_map_Xt29[] = {
  NSPAIR(_ZN4Xt29C1Ev),
  NSPAIR(_ZN4Xt29D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
extern Class_Descriptor cd_t29;
extern VTBL_ENTRY _ZTI3t29[];
extern  VTBL_ENTRY _ZTV3t29[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t29[];
static Base_Class bases_Xt29[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(16,8), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 0},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_t29,    ABISELECT(8,4), //bcp->offset
    5, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt29[];
extern void _ZN4Xt293abcEv();
extern void _ZN3t293barEv();
static  VTBL_ENTRY vtc_Xt29[] = {
  0,
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI4Xt29[0]),
  (VTBL_ENTRY)&_ZN4Xt293abcEv,
  0,
  ABISELECT(-8,-4),
  ABISELECT(-8,-4),
  (VTBL_ENTRY)&(_ZTI4Xt29[0]),
  (VTBL_ENTRY)&_ZN3t293barEv,
};
extern VTBL_ENTRY _ZTV4Xt29[];
extern void _ZN3t293barEv();
static  VTBL_ENTRY _tg__ZTV3t29__4Xt29[] = {
  ABISELECT(-8,-4),
  0,
  (VTBL_ENTRY)&(_ZTI3t29[0]),
  (VTBL_ENTRY)&_ZN3t293barEv,
};
static  VTT_ENTRY vtt_Xt29[] = {
  {&(_ZTV4Xt29[4]),  4,10},
  {&(_ZTV4Xt29[9]),  9,10},
  {&(_tg__ZTV3t29__4Xt29[3]),  3,4},
};
extern VTBL_ENTRY _ZTI4Xt29[];
extern  VTBL_ENTRY _ZTV4Xt29[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt29[];
Class_Descriptor cd_Xt29 = {  "Xt29", // class name
  bases_Xt29, 3,
  &(vtc_Xt29[0]), // expected_vtbl_contents
  &(vtt_Xt29[0]), // expected_vtt_contents
  ABISELECT(24,12), // object size
  NSPAIRA(_ZTI4Xt29),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt29),10, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt29),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  Xt30  : virtual t30 {
  virtual void  abc(); // _ZN4Xt303abcEv
  ~Xt30(); // tgen
  Xt30(); // tgen
};
//SIG(1 Xt30) C1{ VBC2{ VBC3{ Fi} VBC4{ m Fi:0} v2} v1}


void  Xt30 ::abc(){vfunc_called(this, "_ZN4Xt303abcEv");}
Xt30 ::~Xt30(){ note_dtor("Xt30", this);} // tgen
Xt30 ::Xt30(){ note_ctor("Xt30", this);} // tgen

static void Test_Xt30()
{
  extern Class_Descriptor cd_Xt30;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_Xt30, buf);
    Xt30 *dp, &lv = *(dp=new (buf) Xt30());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(Xt30)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(Xt30)");
    check_base_class_offset(lv, (xx*)(t30*), ABISELECT(8,4), "Xt30");
    check_base_class_offset(lv, (ne_1*)(t30*), 0, "Xt30");
    check_base_class_offset(lv, (t30*), 0, "Xt30");
    test_class_info(&lv, &cd_Xt30);
    dp->~Xt30();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vXt30(Test_Xt30, "Xt30", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN4Xt30C1Ev();
extern void _ZN4Xt30D1Ev();
Name_Map name_map_Xt30[] = {
  NSPAIR(_ZN4Xt30C1Ev),
  NSPAIR(_ZN4Xt30D1Ev),
  {0,0}
};
extern Class_Descriptor cd_xx;
extern VTBL_ENTRY _ZTI2xx[];
extern Class_Descriptor cd_ne_1;
extern VTBL_ENTRY _ZTI4ne_1[];
extern Class_Descriptor cd_t30;
extern VTBL_ENTRY _ZTI3t30[];
extern  VTBL_ENTRY _ZTV3t30[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT3t30[];
static Base_Class bases_Xt30[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_xx,    ABISELECT(8,4), //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_ne_1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    -1, //init_seq
    2, //immediately_derived
  0, 1},
  {&cd_t30,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    5, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    3, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4Xt30[];
extern void _ZN3t303barEv();
extern void _ZN4Xt303abcEv();
static  VTBL_ENTRY vtc_Xt30[] = {
  0,
  0,
  0,
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI4Xt30[0]),
  (VTBL_ENTRY)&_ZN3t303barEv,
  (VTBL_ENTRY)&_ZN4Xt303abcEv,
};
extern VTBL_ENTRY _ZTV4Xt30[];
extern void _ZN3t303barEv();
static  VTBL_ENTRY _tg__ZTV3t30__4Xt30[] = {
  0,
  ABISELECT(8,4),
  0,
  (VTBL_ENTRY)&(_ZTI3t30[0]),
  (VTBL_ENTRY)&_ZN3t303barEv,
};
static  VTT_ENTRY vtt_Xt30[] = {
  {&(_ZTV4Xt30[6]),  6,8},
  {&(_ZTV4Xt30[6]),  6,8},
  {&(_tg__ZTV3t30__4Xt30[4]),  4,5},
};
extern VTBL_ENTRY _ZTI4Xt30[];
extern  VTBL_ENTRY _ZTV4Xt30[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4Xt30[];
Class_Descriptor cd_Xt30 = {  "Xt30", // class name
  bases_Xt30, 3,
  &(vtc_Xt30[0]), // expected_vtbl_contents
  &(vtt_Xt30[0]), // expected_vtt_contents
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI4Xt30),ABISELECT(40,24), //typeinfo_var
  NSPAIRA(_ZTV4Xt30),8, //virtual function table var
  6, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4Xt30),3, //virtual table table var
  1, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

