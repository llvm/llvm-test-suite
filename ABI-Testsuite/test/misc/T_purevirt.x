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
  virtual void  foo1()=0; // _ZN4abcd4foo1Ev
  virtual void  foo3()=0; // _ZN4abcd4foo3Ev
   ~abcd(); // _ZN4abcdD1Ev
   abcd(); // ABISELECT(_ZN4abcdC2Ev,_ZN4abcdC1Ev)
};
//SIG(-1 abcd) C1{ v1 v2 Fi}


 abcd ::~abcd(){ note_dtor("abcd", this);}
 abcd ::abcd(){ note_ctor("abcd", this);}

static void Test_abcd()
{
  // abstract class test skipped
}
static Arrange_To_Call_Me vabcd(Test_abcd, "abcd", ABISELECT(16,8));

#else // __cplusplus

extern void ABISELECT(_ZN4abcdC2Ev,_ZN4abcdC1Ev)();
extern void _ZN4abcdD1Ev();
Name_Map name_map_abcd[] = {
  NSPAIR(ABISELECT(_ZN4abcdC2Ev,_ZN4abcdC1Ev)),
  NSPAIR(_ZN4abcdD1Ev),
  {0,0}
};
extern VTBL_ENTRY _ZTI4abcd[];
extern void __cxa_pure_virtual();
extern void __cxa_pure_virtual();
static  VTBL_ENTRY vtc_abcd[] = {
  0,
  (VTBL_ENTRY)&(_ZTI4abcd[0]),
  (VTBL_ENTRY)&__cxa_pure_virtual,
  (VTBL_ENTRY)&__cxa_pure_virtual,
};
extern VTBL_ENTRY _ZTI4abcd[];
VTBL_ENTRY *P__ZTI4abcd = _ZTI4abcd; 
extern  VTBL_ENTRY _ZTV4abcd[];
Class_Descriptor cd_abcd = {  "abcd", // class name
  0,0,//no base classes
  &(vtc_abcd[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(16,8), // object size
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
  int q;
   efgh(); // ABISELECT(_ZN4efghC2Ev,_ZN4efghC1Ev)
  virtual void  foo2()=0; // _ZN4efgh4foo2Ev
  virtual void  foo3()=0; // _ZN4efgh4foo3Ev
   ~efgh(); // _ZN4efghD1Ev
};
//SIG(-1 efgh) C1{ BC2{ v3 v2 Fi} v1 v2 Fi}


 efgh ::efgh(){ note_ctor("efgh", this);}
 efgh ::~efgh(){ note_dtor("efgh", this);}

static void Test_efgh()
{
  // abstract class test skipped
}
static Arrange_To_Call_Me vefgh(Test_efgh, "efgh", ABISELECT(16,12));

#else // __cplusplus

extern void ABISELECT(_ZN4efghC2Ev,_ZN4efghC1Ev)();
extern void _ZN4efghD1Ev();
Name_Map name_map_efgh[] = {
  NSPAIR(ABISELECT(_ZN4efghC2Ev,_ZN4efghC1Ev)),
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
extern void __cxa_pure_virtual();
extern void __cxa_pure_virtual();
extern void __cxa_pure_virtual();
static  VTBL_ENTRY vtc_efgh[] = {
  0,
  (VTBL_ENTRY)&(_ZTI4efgh[0]),
  (VTBL_ENTRY)&__cxa_pure_virtual,
  (VTBL_ENTRY)&__cxa_pure_virtual,
  (VTBL_ENTRY)&__cxa_pure_virtual,
};
extern VTBL_ENTRY _ZTI4efgh[];
VTBL_ENTRY *P__ZTI4efgh = _ZTI4efgh; 
extern  VTBL_ENTRY _ZTV4efgh[];
Class_Descriptor cd_efgh = {  "efgh", // class name
  bases_efgh, 1,
  &(vtc_efgh[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(16,12), // object size
  NSPAIRA(_ZTI4efgh),ABISELECT(24,12), //typeinfo_var
  NSPAIRA(_ZTV4efgh),5, //virtual function table var
  2, // offset into main vftv pointed to by object[0]
  {0,0},0, // virtual table table var
  1, // n_initialized_bases
  0, // has_virtual_bases
  0, // has_class_type_fields
  0, // alt-thunk-names
};
#endif // __cplusplus

//============================================================================

#ifdef __cplusplus

struct  pqrs  : efgh {
  int r;
   pqrs(); // _ZN4pqrsC1Ev
  virtual void  foo1(); // _ZN4pqrs4foo1Ev
  virtual void  foo2(); // _ZN4pqrs4foo2Ev
  virtual void  foo3(); // _ZN4pqrs4foo3Ev
  virtual void  foo4(); // _ZN4pqrs4foo4Ev
   ~pqrs(); // _ZN4pqrsD1Ev
};
//SIG(1 pqrs) C1{ BC2{ BC3{ v1 v3 Fi} v2 v3 Fi} v1 v2 v3 v4 Fi}


 pqrs ::pqrs(){ note_ctor("pqrs", this);}
void  pqrs ::foo1(){vfunc_called(this, "_ZN4pqrs4foo1Ev");}
void  pqrs ::foo2(){vfunc_called(this, "_ZN4pqrs4foo2Ev");}
void  pqrs ::foo3(){vfunc_called(this, "_ZN4pqrs4foo3Ev");}
void  pqrs ::foo4(){vfunc_called(this, "_ZN4pqrs4foo4Ev");}
 pqrs ::~pqrs(){ note_dtor("pqrs", this);}

static void Test_pqrs()
{
  extern Class_Descriptor cd_pqrs;
  void *lvp;
  {
    ABISELECT(double,int) buf[ABISELECT(4,5)];
    init_test(&cd_pqrs, buf);
    pqrs *dp, &lv = *(dp=new (buf) pqrs());
    lvp = (void*)&lv;
    check2(sizeof(lv), ABISELECT(24,16), "sizeof(pqrs)");
    check2(__alignof__(lv), ABISELECT(8,4), "__alignof__(pqrs)");
    check_base_class_offset(lv, (abcd*)(efgh*), 0, "pqrs");
    check_base_class_offset(lv, (efgh*), 0, "pqrs");
    check_field_offset(lv, r, ABISELECT(16,12), "pqrs.r");
    test_class_info(&lv, &cd_pqrs);
    dp->~pqrs();
  }
  Check_Ctor_Dtor_Calls(lvp);
}
static Arrange_To_Call_Me vpqrs(Test_pqrs, "pqrs", ABISELECT(24,16));

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
    1, //immediately_derived
  0, 0},
  {&cd_efgh,    0, //bcp->offset
    -1, //bcp->virtual_function_table_offset
    2, //num_negative_vtable_entries(t, bcp)
    0, //bcp->index_in_construction_vtbl_array
    0, //bcp->base_subarray_index_in_construction_vtbl_array
    2, //init_seq
    -1, //immediately_derived
  1, 0},
  {0}};
extern VTBL_ENTRY _ZTI4pqrs[];
extern void _ZN4pqrs4foo1Ev();
extern void _ZN4pqrs4foo3Ev();
extern void _ZN4pqrs4foo2Ev();
extern void _ZN4pqrs4foo4Ev();
static  VTBL_ENTRY vtc_pqrs[] = {
  0,
  (VTBL_ENTRY)&(_ZTI4pqrs[0]),
  (VTBL_ENTRY)&_ZN4pqrs4foo1Ev,
  (VTBL_ENTRY)&_ZN4pqrs4foo3Ev,
  (VTBL_ENTRY)&_ZN4pqrs4foo2Ev,
  (VTBL_ENTRY)&_ZN4pqrs4foo4Ev,
};
extern VTBL_ENTRY _ZTI4pqrs[];
extern  VTBL_ENTRY _ZTV4pqrs[];
Class_Descriptor cd_pqrs = {  "pqrs", // class name
  bases_pqrs, 2,
  &(vtc_pqrs[0]), // expected_vtbl_contents
  0, //no vtt
  ABISELECT(24,16), // object size
  NSPAIRA(_ZTI4pqrs),ABISELECT(24,12), //typeinfo_var
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

