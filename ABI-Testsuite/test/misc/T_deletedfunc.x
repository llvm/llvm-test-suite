// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: c_compiler -c -o %t1.o -I "common" "common/testsuite.c"
// RUN: cxx_compiler cxx_11 cxx_rtti -c %s -I "common" -o %t2.o
// RUN: c_compiler -c %s -I "common" -o %t3.o
// RUN: linker -o %t2%exeext  %t1.o %t2.o %t3.o
// RUN: runtool %t2%exeext | checker "TEST PASSED"
#include "testsuite.h"
#ifdef __cplusplus

struct  abcd  {
  virtual void  xar(); // _ZN4abcd3xarEv
  virtual void  foo()=delete; // _ZN4abcd3fooEv
  ~abcd(); // tgen
  abcd(); // tgen
};
//SIG(-1 abcd) C1{ v1 v2}


void  abcd ::xar(){vfunc_called(this, "_ZN4abcd3xarEv");}
abcd ::~abcd(){ note_dtor("abcd", this);} // tgen
abcd ::abcd(){ note_ctor("abcd", this);} // tgen

static void Test_abcd()
{
  extern Class_Descriptor cd_abcd;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_abcd, buf);
    abcd *dp, &lv = *(dp=new (buf) abcd());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(abcd)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(abcd)");
    test_class_info(&lv, &cd_abcd);
    dp->~abcd();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vabcd(Test_abcd, "abcd", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4abcdC1Ev();
extern void _ZN4abcdD1Ev();
Name_Map name_map_abcd[] = {
  NSPAIR(_ZN4abcdC1Ev),
  NSPAIR(_ZN4abcdD1Ev),
  {0,0}
};
extern VTBL_ENTRY _ZTI4abcd[];
extern void _ZN4abcd3xarEv();
extern void __cxa_deleted_virtual();
static  VTBL_ENTRY vtc_abcd[] = {
  0,
  (VTBL_ENTRY)&(_ZTI4abcd[0]),
  (VTBL_ENTRY)&_ZN4abcd3xarEv,
  (VTBL_ENTRY)&__cxa_deleted_virtual,
};
extern VTBL_ENTRY _ZTI4abcd[];
extern  VTBL_ENTRY _ZTV4abcd[];
Class_Descriptor cd_abcd = {  "abcd", // class name
  0,0,//no base classes
  &(vtc_abcd[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4abcd),ABISELECT(16,8), //typeinfo_var
  NSPAIRA(_ZTV4abcd),4, //virtual function table var
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

struct  efgh  : abcd {
  virtual void  bar(); // _ZN4efgh3barEv
  virtual void  foo()=delete; // _ZN4efgh3fooEv
  virtual void  zoo(); // _ZN4efgh3zooEv
  ~efgh(); // tgen
  efgh(); // tgen
};
//SIG(1 efgh) C1{ BC2{ v4 v2} v1 v2 v3}


void  efgh ::bar(){vfunc_called(this, "_ZN4efgh3barEv");}
void  efgh ::zoo(){vfunc_called(this, "_ZN4efgh3zooEv");}
efgh ::~efgh(){ note_dtor("efgh", this);} // tgen
efgh ::efgh(){ note_ctor("efgh", this);} // tgen

static void Test_efgh()
{
  extern Class_Descriptor cd_efgh;
  void *lvp;
  {
    ABISELECT(double,int) buf[2];
    init_test(&cd_efgh, buf);
    efgh *dp, &lv = *(dp=new (buf) efgh());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(8,4), "sizeof(efgh)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(efgh)");
    check_base_class_offset(lv, (abcd*), 0, "efgh");
    test_class_info(&lv, &cd_efgh);
    dp->~efgh();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vefgh(Test_efgh, "efgh", ABISELECT(8,4));

#else // __cplusplus

extern void _ZN4efghC1Ev();
extern void _ZN4efghD1Ev();
Name_Map name_map_efgh[] = {
  NSPAIR(_ZN4efghC1Ev),
  NSPAIR(_ZN4efghD1Ev),
  {0,0}
};
extern Class_Descriptor cd_abcd;
extern VTBL_ENTRY _ZTI4abcd[];
extern  VTBL_ENTRY _ZTV4abcd[];
static Base_Class bases_efgh[] = {
  // ofst, vfto, nneg, vtt_idx, base_vtt_idx, init_seq, direct, virtual
  {&cd_abcd,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    1, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI4efgh[];
extern void _ZN4abcd3xarEv();
extern void __cxa_deleted_virtual();
extern void _ZN4efgh3barEv();
extern void _ZN4efgh3zooEv();
static  VTBL_ENTRY vtc_efgh[] = {
  0,
  (VTBL_ENTRY)&(_ZTI4efgh[0]),
  (VTBL_ENTRY)&_ZN4abcd3xarEv,
  (VTBL_ENTRY)&__cxa_deleted_virtual,
  (VTBL_ENTRY)&_ZN4efgh3barEv,
  (VTBL_ENTRY)&_ZN4efgh3zooEv,
};
extern VTBL_ENTRY _ZTI4efgh[];
extern  VTBL_ENTRY _ZTV4efgh[];
Class_Descriptor cd_efgh = {  "efgh", // class name
  bases_efgh, 1,
  &(vtc_efgh[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(8,4), // object size
  NSPAIRA(_ZTI4efgh),ABISELECT(24,12), //typeinfo_var
  NSPAIRA(_ZTV4efgh),6, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  1, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

