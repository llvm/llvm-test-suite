// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: cxx_compiler cxx_rtti -c %s -I "common" -o %t2.o
// RUN: c_compiler -c %s -I "common" -o %t3.o
// RUN: linker -o %t2%exeext  %t1.o %t2.o %t3.o
// RUN: runtool %t2%exeext | checker "TEST PASSED"
#include "testsuite.h"
#ifdef __cplusplus

struct  abcd  {
  int p;
  virtual ::abcd * foo(int ); // _ZN4abcd3fooEi
  ~abcd(); // tgen
  abcd(); // tgen
};
//SIG(-1 abcd) C1{ v1 Fi}


abcd * abcd ::foo(int ){vfunc_called(this, "_ZN4abcd3fooEi");}
abcd ::~abcd(){ note_dtor("abcd", this);} // tgen
abcd ::abcd(){ note_ctor("abcd", this);} // tgen

static void Test_abcd()
{
  extern Class_Descriptor cd_abcd;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_abcd, buf);
    abcd *dp, &lv = *(dp=new (buf) abcd());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(abcd)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(abcd)");
    check_field_offset(lv, p, ABISELECT(8,4), "abcd.p");
    test_class_info(&lv, &cd_abcd);
    dp->~abcd();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vabcd(Test_abcd, "abcd", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN4abcdC1Ev();
extern void _ZN4abcdD1Ev();
Name_Map name_map_abcd[] = {
  NSPAIR(_ZN4abcdC1Ev),
  NSPAIR(_ZN4abcdD1Ev),
  {0,0}
};
extern VTBL_ENTRY _ZTI4abcd[];
extern void _ZN4abcd3fooEi();
static  VTBL_ENTRY vtc_abcd[] = {
  0,
  (VTBL_ENTRY)&(_ZTI4abcd[0]),
  (VTBL_ENTRY)&_ZN4abcd3fooEi,
};
extern VTBL_ENTRY _ZTI4abcd[];
extern  VTBL_ENTRY _ZTV4abcd[];
Class_Descriptor cd_abcd = {  "abcd", // class name
  0,0,//no base classes
  &(vtc_abcd[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI4abcd),ABISELECT(16,8), //typeinfo_var
  NSPAIRA(_ZTV4abcd),3, //virtual function table var
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

struct  efgh  {
  int q;
  virtual ::efgh * foo(int ); // _ZN4efgh3fooEi
  ~efgh(); // tgen
  efgh(); // tgen
};
//SIG(-1 efgh) C1{ v1 Fi}


efgh * efgh ::foo(int ){vfunc_called(this, "_ZN4efgh3fooEi");}
efgh ::~efgh(){ note_dtor("efgh", this);} // tgen
efgh ::efgh(){ note_ctor("efgh", this);} // tgen

static void Test_efgh()
{
  extern Class_Descriptor cd_efgh;
  void *lvp;
  {
    ABISELECT(double,int) buf[3];
    init_test(&cd_efgh, buf);
    efgh *dp, &lv = *(dp=new (buf) efgh());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,8), "sizeof(efgh)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(efgh)");
    check_field_offset(lv, q, ABISELECT(8,4), "efgh.q");
    test_class_info(&lv, &cd_efgh);
    dp->~efgh();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vefgh(Test_efgh, "efgh", ABISELECT(16,8));

#else // __cplusplus

extern void _ZN4efghC1Ev();
extern void _ZN4efghD1Ev();
Name_Map name_map_efgh[] = {
  NSPAIR(_ZN4efghC1Ev),
  NSPAIR(_ZN4efghD1Ev),
  {0,0}
};
extern VTBL_ENTRY _ZTI4efgh[];
extern void _ZN4efgh3fooEi();
static  VTBL_ENTRY vtc_efgh[] = {
  0,
  (VTBL_ENTRY)&(_ZTI4efgh[0]),
  (VTBL_ENTRY)&_ZN4efgh3fooEi,
};
extern VTBL_ENTRY _ZTI4efgh[];
extern  VTBL_ENTRY _ZTV4efgh[];
Class_Descriptor cd_efgh = {  "efgh", // class name
  0,0,//no base classes
  &(vtc_efgh[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(16,8), // object size
  NSPAIRA(_ZTI4efgh),ABISELECT(16,8), //typeinfo_var
  NSPAIRA(_ZTV4efgh),3, //virtual function table var
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

struct  pqrs  : abcd , efgh {
  int r;
  virtual ::pqrs * foo(int ); // _ZN4pqrs3fooEi
  ~pqrs(); // tgen
  pqrs(); // tgen
};
//SIG(1 pqrs) C1{ BC2{ v1 Fi} BC3{ v1 Fi} v1 Fi}


pqrs * pqrs ::foo(int ){vfunc_called(this, "_ZN4pqrs3fooEi");}
pqrs ::~pqrs(){ note_dtor("pqrs", this);} // tgen
pqrs ::pqrs(){ note_ctor("pqrs", this);} // tgen

static void Test_pqrs()
{
  extern Class_Descriptor cd_pqrs;
  void *lvp;
  {
    ABISELECT(double,int) buf[ABISELECT(5,6)];
    init_test(&cd_pqrs, buf);
    pqrs *dp, &lv = *(dp=new (buf) pqrs());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(32,20), "sizeof(pqrs)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(pqrs)");
    check_base_class_offset(lv, (abcd*), 0, "pqrs");
    check_base_class_offset(lv, (efgh*), ABISELECT(16,8), "pqrs");
    check_field_offset(lv, r, ABISELECT(28,16), "pqrs.r");
    test_class_info(&lv, &cd_pqrs);
    dp->~pqrs();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vpqrs(Test_pqrs, "pqrs", ABISELECT(32,20));

#else // __cplusplus

extern void _ZN4pqrsC1Ev();
extern void _ZN4pqrsD1Ev();
Name_Map name_map_pqrs[] = {
  NSPAIR(_ZN4pqrsC1Ev),
  NSPAIR(_ZN4pqrsD1Ev),
  {0,0}
};
extern Class_Descriptor cd_abcd;
extern VTBL_ENTRY _ZTI4abcd[];
extern  VTBL_ENTRY _ZTV4abcd[];
extern Class_Descriptor cd_efgh;
extern VTBL_ENTRY _ZTI4efgh[];
extern  VTBL_ENTRY _ZTV4efgh[];
static Base_Class bases_pqrs[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_abcd,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_efgh,    ABISELECT(16,8), //bcp->offset
    3, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    2, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI4pqrs[];
extern void _ZN4pqrs3fooEi();
extern void ABISELECT(_ZTchn16_h16_N4pqrs3fooEi,_ZTchn8_h8_N4pqrs3fooEi)();
static  VTBL_ENTRY vtc_pqrs[] = {
  0,
  (VTBL_ENTRY)&(_ZTI4pqrs[0]),
  (VTBL_ENTRY)&_ZN4pqrs3fooEi,
  ABISELECT(-16,-8),
  (VTBL_ENTRY)&(_ZTI4pqrs[0]),
  (VTBL_ENTRY)&ABISELECT(_ZTchn16_h16_N4pqrs3fooEi,_ZTchn8_h8_N4pqrs3fooEi),
};
extern VTBL_ENTRY _ZTI4pqrs[];
extern  VTBL_ENTRY _ZTV4pqrs[];
Class_Descriptor cd_pqrs = {  "pqrs", // class name
  bases_pqrs, 2,
  &(vtc_pqrs[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(32,20), // object size
  NSPAIRA(_ZTI4pqrs),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV4pqrs),6, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  2, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  aaa1  {
  int x;
  int y;
  virtual ::abcd * fff(int ); // _ZN4aaa13fffEi
  virtual ::efgh * kkk(int ); // _ZN4aaa13kkkEi
  ~aaa1(); // tgen
  aaa1(); // tgen
};
//SIG(-1 aaa1) C1{ v1 v2 Fi[2]}


abcd * aaa1 ::fff(int ){vfunc_called(this, "_ZN4aaa13fffEi");}
efgh * aaa1 ::kkk(int ){vfunc_called(this, "_ZN4aaa13kkkEi");}
aaa1 ::~aaa1(){ note_dtor("aaa1", this);} // tgen
aaa1 ::aaa1(){ note_ctor("aaa1", this);} // tgen

static void Test_aaa1()
{
  extern Class_Descriptor cd_aaa1;
  void *lvp;
  {
    ABISELECT(double,int) buf[ABISELECT(3,4)];
    init_test(&cd_aaa1, buf);
    aaa1 *dp, &lv = *(dp=new (buf) aaa1());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(aaa1)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(aaa1)");
    check_field_offset(lv, x, ABISELECT(8,4), "aaa1.x");
    check_field_offset(lv, y, ABISELECT(12,8), "aaa1.y");
    test_class_info(&lv, &cd_aaa1);
    dp->~aaa1();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vaaa1(Test_aaa1, "aaa1", ABISELECT(16,12));

#else // __cplusplus

extern void _ZN4aaa1C1Ev();
extern void _ZN4aaa1D1Ev();
Name_Map name_map_aaa1[] = {
  NSPAIR(_ZN4aaa1C1Ev),
  NSPAIR(_ZN4aaa1D1Ev),
  {0,0}
};
extern VTBL_ENTRY _ZTI4aaa1[];
extern void _ZN4aaa13fffEi();
extern void _ZN4aaa13kkkEi();
static  VTBL_ENTRY vtc_aaa1[] = {
  0,
  (VTBL_ENTRY)&(_ZTI4aaa1[0]),
  (VTBL_ENTRY)&_ZN4aaa13fffEi,
  (VTBL_ENTRY)&_ZN4aaa13kkkEi,
};
extern VTBL_ENTRY _ZTI4aaa1[];
extern  VTBL_ENTRY _ZTV4aaa1[];
Class_Descriptor cd_aaa1 = {  "aaa1", // class name
  0,0,//no base classes
  &(vtc_aaa1[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(16,12), // object size
  NSPAIRA(_ZTI4aaa1),ABISELECT(16,8), //typeinfo_var
  NSPAIRA(_ZTV4aaa1),4, //virtual function table var
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

struct  bbb1  {
  int p;
  int q;
  virtual ::abcd * fff(int ); // _ZN4bbb13fffEi
  virtual ::efgh * kkk(int ); // _ZN4bbb13kkkEi
  ~bbb1(); // tgen
  bbb1(); // tgen
};
//SIG(-1 bbb1) C1{ v1 v2 Fi[2]}


abcd * bbb1 ::fff(int ){vfunc_called(this, "_ZN4bbb13fffEi");}
efgh * bbb1 ::kkk(int ){vfunc_called(this, "_ZN4bbb13kkkEi");}
bbb1 ::~bbb1(){ note_dtor("bbb1", this);} // tgen
bbb1 ::bbb1(){ note_ctor("bbb1", this);} // tgen

static void Test_bbb1()
{
  extern Class_Descriptor cd_bbb1;
  void *lvp;
  {
    ABISELECT(double,int) buf[ABISELECT(3,4)];
    init_test(&cd_bbb1, buf);
    bbb1 *dp, &lv = *(dp=new (buf) bbb1());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(16,12), "sizeof(bbb1)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(bbb1)");
    check_field_offset(lv, p, ABISELECT(8,4), "bbb1.p");
    check_field_offset(lv, q, ABISELECT(12,8), "bbb1.q");
    test_class_info(&lv, &cd_bbb1);
    dp->~bbb1();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vbbb1(Test_bbb1, "bbb1", ABISELECT(16,12));

#else // __cplusplus

extern void _ZN4bbb1C1Ev();
extern void _ZN4bbb1D1Ev();
Name_Map name_map_bbb1[] = {
  NSPAIR(_ZN4bbb1C1Ev),
  NSPAIR(_ZN4bbb1D1Ev),
  {0,0}
};
extern VTBL_ENTRY _ZTI4bbb1[];
extern void _ZN4bbb13fffEi();
extern void _ZN4bbb13kkkEi();
static  VTBL_ENTRY vtc_bbb1[] = {
  0,
  (VTBL_ENTRY)&(_ZTI4bbb1[0]),
  (VTBL_ENTRY)&_ZN4bbb13fffEi,
  (VTBL_ENTRY)&_ZN4bbb13kkkEi,
};
extern VTBL_ENTRY _ZTI4bbb1[];
extern  VTBL_ENTRY _ZTV4bbb1[];
Class_Descriptor cd_bbb1 = {  "bbb1", // class name
  0,0,//no base classes
  &(vtc_bbb1[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(16,12), // object size
  NSPAIRA(_ZTI4bbb1),ABISELECT(16,8), //typeinfo_var
  NSPAIRA(_ZTV4bbb1),4, //virtual function table var
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

struct  ccc1  : virtual aaa1 , virtual bbb1 {
  int d;
  int f;
  virtual ::pqrs * fff(int ); // _ZN4ccc13fffEi
  virtual ::pqrs * kkk(int ); // _ZN4ccc13kkkEi
  ~ccc1(); // tgen
  ccc1(); // tgen
};
//SIG(1 ccc1) C1{ VBC2{ v1 v2 Fi[2]} VBC3{ v1 v2 Fi[2]} v1 v2 Fi[2]}


pqrs * ccc1 ::fff(int ){vfunc_called(this, "_ZN4ccc13fffEi");}
pqrs * ccc1 ::kkk(int ){vfunc_called(this, "_ZN4ccc13kkkEi");}
ccc1 ::~ccc1(){ note_dtor("ccc1", this);} // tgen
ccc1 ::ccc1(){ note_ctor("ccc1", this);} // tgen

static void Test_ccc1()
{
  extern Class_Descriptor cd_ccc1;
  void *lvp;
  {
    ABISELECT(double,int) buf[ABISELECT(7,10)];
    init_test(&cd_ccc1, buf);
    ccc1 *dp, &lv = *(dp=new (buf) ccc1());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(48,36), "sizeof(ccc1)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(ccc1)");
    check_base_class_offset(lv, (aaa1*), ABISELECT(16,12), "ccc1");
    check_base_class_offset(lv, (bbb1*), ABISELECT(32,24), "ccc1");
    check_field_offset(lv, d, ABISELECT(8,4), "ccc1.d");
    check_field_offset(lv, f, ABISELECT(12,8), "ccc1.f");
    test_class_info(&lv, &cd_ccc1);
    dp->~ccc1();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vccc1(Test_ccc1, "ccc1", ABISELECT(48,36));

#else // __cplusplus

extern void _ZN4ccc1C1Ev();
extern void _ZN4ccc1D1Ev();
Name_Map name_map_ccc1[] = {
  NSPAIR(_ZN4ccc1C1Ev),
  NSPAIR(_ZN4ccc1D1Ev),
  {0,0}
};
extern Class_Descriptor cd_aaa1;
extern VTBL_ENTRY _ZTI4aaa1[];
extern  VTBL_ENTRY _ZTV4aaa1[];
extern Class_Descriptor cd_bbb1;
extern VTBL_ENTRY _ZTI4bbb1[];
extern  VTBL_ENTRY _ZTV4bbb1[];
static Base_Class bases_ccc1[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_aaa1,    ABISELECT(16,12), //bcp->offset
    6, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    2, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 1},
  {&cd_bbb1,    ABISELECT(32,24), //bcp->offset
    12, //bcp->virtual_function_table_offset
    4, //num_negative_vtable_entries(t, bcp)
    3, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    2, //init_seq
    -1, //immediately_derived
  1, 1},
  {0}};
extern VTBL_ENTRY _ZTI4ccc1[];
extern void _ZN4ccc13fffEi();
extern void _ZN4ccc13kkkEi();
extern void ABISELECT(_ZTv0_n24_N4ccc13fffEi,_ZTv0_n12_N4ccc13fffEi)();
extern void ABISELECT(_ZThn16_N4ccc13fffEi,_ZThn12_N4ccc13fffEi)() __attribute__((weak));
extern void ABISELECT(_ZTcv0_n32_h16_N4ccc13kkkEi,_ZTcv0_n16_h8_N4ccc13kkkEi)();
extern void ABISELECT(_ZTv0_n24_N4ccc13fffEi,_ZTv0_n12_N4ccc13fffEi)();
extern void ABISELECT(_ZThn32_N4ccc13fffEi,_ZThn24_N4ccc13fffEi)() __attribute__((weak));
extern void ABISELECT(_ZTcv0_n32_h16_N4ccc13kkkEi,_ZTcv0_n16_h8_N4ccc13kkkEi)();
static  VTBL_ENTRY vtc_ccc1[] = {
  ABISELECT(32,24),
  ABISELECT(16,12),
  0,
  (VTBL_ENTRY)&(_ZTI4ccc1[0]),
  (VTBL_ENTRY)&_ZN4ccc13fffEi,
  (VTBL_ENTRY)&_ZN4ccc13kkkEi,
  ABISELECT(-16,-12),
  ABISELECT(-16,-12),
  ABISELECT(-16,-12),
  (VTBL_ENTRY)&(_ZTI4ccc1[0]),
  (VTBL_ENTRY)&ABISELECT(_ZTv0_n24_N4ccc13fffEi,_ZTv0_n12_N4ccc13fffEi),
  (VTBL_ENTRY)&ABISELECT(_ZTcv0_n32_h16_N4ccc13kkkEi,_ZTcv0_n16_h8_N4ccc13kkkEi),
  ABISELECT(-32,-24),
  ABISELECT(-32,-24),
  ABISELECT(-32,-24),
  (VTBL_ENTRY)&(_ZTI4ccc1[0]),
  (VTBL_ENTRY)&ABISELECT(_ZTv0_n24_N4ccc13fffEi,_ZTv0_n12_N4ccc13fffEi),
  (VTBL_ENTRY)&ABISELECT(_ZTcv0_n32_h16_N4ccc13kkkEi,_ZTcv0_n16_h8_N4ccc13kkkEi),
};
extern VTBL_ENTRY _ZTV4ccc1[];
static  VTT_ENTRY vtt_ccc1[] = {
  {&(_ZTV4ccc1[4]),  4,18},
  {&(_ZTV4ccc1[10]),  10,18},
  {&(_ZTV4ccc1[16]),  16,18},
};
extern VTBL_ENTRY _ZTI4ccc1[];
extern  VTBL_ENTRY _ZTV4ccc1[];
extern  VTBL_ENTRY * __attribute__((weak))_ZTT4ccc1[];
static VTBL_ENTRY alt_thunk_names1[] = {
  (VTBL_ENTRY)ABISELECT(_ZTv0_n24_N4ccc13fffEi,_ZTv0_n12_N4ccc13fffEi), // 
  (VTBL_ENTRY)ABISELECT(_ZThn32_N4ccc13fffEi,_ZThn24_N4ccc13fffEi),
  (VTBL_ENTRY)ABISELECT(_ZThn16_N4ccc13fffEi,_ZThn12_N4ccc13fffEi),
  ALT_NAMES_TERMINATOR,
ALT_NAMES_TERMINATOR};
Class_Descriptor cd_ccc1 = {  "ccc1", // class name
  bases_ccc1, 2,
  &(vtc_ccc1[0]), // expected_vtbl_contents
  &(vtt_ccc1[0]), // expected_vtt_contents
  ABISELECT(48,36), // object size
  NSPAIRA(_ZTI4ccc1),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV4ccc1),18, //virtual function table var
  4, // offset into main vftv pointed to by object[0]
  NSPAIRA(_ZTT4ccc1),3, //virtual table table var
  2, // n_initialized_bases
  1, // has_virtual_bases
  0, // has_class_type_fields
  alt_thunk_names1,
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  ddd1  : aaa1 , bbb1 {
  int d;
  int f;
  virtual ::pqrs * fff(int ); // _ZN4ddd13fffEi
  virtual ::pqrs * kkk(int ); // _ZN4ddd13kkkEi
  ~ddd1(); // tgen
  ddd1(); // tgen
};
//SIG(1 ddd1) C1{ BC2{ v1 v2 Fi[2]} BC3{ v1 v2 Fi[2]} v1 v2 Fi[2]}


pqrs * ddd1 ::fff(int ){vfunc_called(this, "_ZN4ddd13fffEi");}
pqrs * ddd1 ::kkk(int ){vfunc_called(this, "_ZN4ddd13kkkEi");}
ddd1 ::~ddd1(){ note_dtor("ddd1", this);} // tgen
ddd1 ::ddd1(){ note_ctor("ddd1", this);} // tgen

static void Test_ddd1()
{
  extern Class_Descriptor cd_ddd1;
  void *lvp;
  {
    ABISELECT(double,int) buf[ABISELECT(6,9)];
    init_test(&cd_ddd1, buf);
    ddd1 *dp, &lv = *(dp=new (buf) ddd1());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(40,32), "sizeof(ddd1)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(ddd1)");
    check_base_class_offset(lv, (aaa1*), 0, "ddd1");
    check_base_class_offset(lv, (bbb1*), ABISELECT(16,12), "ddd1");
    check_field_offset(lv, d, ABISELECT(32,24), "ddd1.d");
    check_field_offset(lv, f, ABISELECT(36,28), "ddd1.f");
    test_class_info(&lv, &cd_ddd1);
    dp->~ddd1();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vddd1(Test_ddd1, "ddd1", ABISELECT(40,32));

#else // __cplusplus

extern void _ZN4ddd1C1Ev();
extern void _ZN4ddd1D1Ev();
Name_Map name_map_ddd1[] = {
  NSPAIR(_ZN4ddd1C1Ev),
  NSPAIR(_ZN4ddd1D1Ev),
  {0,0}
};
extern Class_Descriptor cd_aaa1;
extern VTBL_ENTRY _ZTI4aaa1[];
extern  VTBL_ENTRY _ZTV4aaa1[];
extern Class_Descriptor cd_bbb1;
extern VTBL_ENTRY _ZTI4bbb1[];
extern  VTBL_ENTRY _ZTV4bbb1[];
static Base_Class bases_ddd1[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_aaa1,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 0},
  {&cd_bbb1,    ABISELECT(16,12), //bcp->offset
    5, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    2, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI4ddd1[];
extern void _ZN4ddd13fffEi();
extern void ABISELECT(_ZTch0_h16_N4ddd13kkkEi,_ZTch0_h8_N4ddd13kkkEi)();
extern void _ZN4ddd13kkkEi();
extern void ABISELECT(_ZThn16_N4ddd13fffEi,_ZThn12_N4ddd13fffEi)();
extern void ABISELECT(_ZTchn16_h16_N4ddd13kkkEi,_ZTchn12_h8_N4ddd13kkkEi)();
static  VTBL_ENTRY vtc_ddd1[] = {
  0,
  (VTBL_ENTRY)&(_ZTI4ddd1[0]),
  (VTBL_ENTRY)&_ZN4ddd13fffEi,
  (VTBL_ENTRY)&ABISELECT(_ZTch0_h16_N4ddd13kkkEi,_ZTch0_h8_N4ddd13kkkEi),
  (VTBL_ENTRY)&_ZN4ddd13kkkEi,
  ABISELECT(-16,-12),
  (VTBL_ENTRY)&(_ZTI4ddd1[0]),
  (VTBL_ENTRY)&ABISELECT(_ZThn16_N4ddd13fffEi,_ZThn12_N4ddd13fffEi),
  (VTBL_ENTRY)&ABISELECT(_ZTchn16_h16_N4ddd13kkkEi,_ZTchn12_h8_N4ddd13kkkEi),
};
extern VTBL_ENTRY _ZTI4ddd1[];
extern  VTBL_ENTRY _ZTV4ddd1[];
Class_Descriptor cd_ddd1 = {  "ddd1", // class name
  bases_ddd1, 2,
  &(vtc_ddd1[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(40,32), // object size
  NSPAIRA(_ZTI4ddd1),ABISELECT(56,32), //typeinfo_var
  NSPAIRA(_ZTV4ddd1),9, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  2, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

