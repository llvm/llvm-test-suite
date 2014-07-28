// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
#ifndef __testsuite_dot_h
#define __testsuite_dot_h
#include <stddef.h>

#include "../../selector.h"

typedef long VTBL_ENTRY;


#define LPSELECT(a,b) ABISELECT(a,b)

#define vfunc_called(a,b)

#define NO_STATIC_CHECKS 1

#ifdef __cplusplus
#define STRUCT_IF_C 
#else
#define STRUCT_IF_C struct // in C mode we neet put 'struct' before typetag
#endif

#define ALT_NAMES_TERMINATOR ((VTBL_ENTRY)1)

#define __tsi64 long long
#define __tsu64 unsigned long long
#define __tsulong unsigned long
extern int verbose, num_classes , n_errors , n_tests ;
//typedef char char_al_16 __attribute__((aligned(16)));
//typedef char char_al_32 __attribute__((aligned(32)));
//typedef char char_al_64 __attribute__((aligned(64)));
//typedef char char_al_128 __attribute__((aligned(128)));
//typedef char char_al_256 __attribute__((aligned(256)));
//typedef char char_al_512 __attribute__((aligned(512)));
//typedef char char_al_1024 __attribute__((aligned(1024)));
//typedef char char_al_2048 __attribute__((aligned(2048)));
typedef struct { char __attribute__((aligned(16))) a[16]; } sal_16;
typedef struct { char __attribute__((aligned(32))) a[32]; } sal_32;
typedef struct { char __attribute__((aligned(64))) a[64]; } sal_64;
typedef struct { char __attribute__((aligned(128))) a[128]; } sal_128;
typedef struct { char __attribute__((aligned(256))) a[256]; } sal_256;
typedef struct { char __attribute__((aligned(512))) a[512]; } sal_512;
typedef struct { char __attribute__((aligned(1024))) a[1024]; } sal_1024;
typedef struct { char __attribute__((aligned(2048))) a[2048]; } sal_2048;

// A struct to map names of functions to their ptrs. A terminated array of
// these is attached to each Class_Descriptor
typedef struct {
  void (*func)();
  const char *name;
} Name_Map;
#define NSPAIR(name) { &name, #name}
#define NSPAIRA(name) { name, #name}
typedef struct Class_Descriptor Class_Descriptor;

// A structure to represent base classes 
// or destructing a derived class under test. An array of these is attached to the
// Class_Descriptor. That array specifies expected sequence of base classses that will 
// be constructed while constructing the 
typedef struct _base_class {
  Class_Descriptor *type;   // class decriptor of the base
  ptrdiff_t        ofst;    // offset in derived class
  ptrdiff_t        vtbl_ofst;  // if >=0, the index of vtable component for this base class inside
                            // the full object. This is not where the baseclass.vptr field will 
                            // point to, though. For that we need to add num_negative_vtbl_entries
  ptrdiff_t        num_negative_vtbl_entries;
                            // In the full object, the base_class.vptr points to
                            // *(vtbl_enrty**)(full_object_address+b->ofst) ==
                            // b->base->tv.typeinfo_var_ptr + b->vtbl_ofst+b->num_negative_vtbl_entries
  unsigned int index_in_vtt;         
                            // if base needs a vftbl, this is the index of that vftbl in the vtt
                            // of the derived class. Both this and next field are 1-shifted, in
                            // the sense that the value 0 indicates that this field is unused, and 
                            // value N represends index (N-1)
  unsigned int base_subarray_index_in_vtt; 
                            // if base needs a vtt itself, this is the index of that vtt set
                            // in its parent vtt.
  int init_seq;             // while initializing final derive ctor-body of this base classs is 
                            // executed at this seq, from 1. If <0, if that base class has no 
                            // ctor, so a call to note_ctor will not be made for this
  int parent_idx;           // indexof direct parent, if any. -1 if none
  unsigned char is_direct, is_virtual;
} Base_Class;

typedef struct {
  VTBL_ENTRY *var;
  char *name;
} vName_Map;
typedef struct {
  VTBL_ENTRY **var;
  char *name;
} vpName_Map;

typedef struct {
  VTBL_ENTRY *vtbl;
  unsigned short ofst, size;
} VTT_ENTRY;

struct Class_Descriptor {
  char *name; // mangled class name
  Base_Class *bases; // a NULL terminated arrray of ptrs to Class_Descriptors of direct bases
  int n_bases;
  VTBL_ENTRY *expected_vtbl_contents; 
              // ptr to an initialized array of ints having expected vtbl contents

  VTT_ENTRY *expected_vtt_contents; 
              // ptr to an initialized array of VTT_ENTRY having expected vtt contents
              // VTT entries contain a ptr to an expected point in vtbl, and a negative ofst
              // and size, if that point is not in the main vtbl variable

  int class_size;

  struct {
    VTBL_ENTRY *typeinfo_var_ptr; // actually it is a typeinfo ptr, but it is pointed to by a
                                   // vtbl_entry, so it is more convenient this way
    const char *typeinfo_var_name;
  } tv;
  int tv_size;


  // The virtual function table var is a combined 
  vName_Map vtbl; // extern reference to vtbl var, defined by the compiler under test
  int vtbl_size, // number of entries in vtbl var. This not the 
      vtbl_ofst; // offset from top of vtbl_var where the class attaches to it 
  // size before address point is vtbl_ofst. total size is vtbl_size

  vpName_Map vtt; // extern reference to VTT name, defined by the compiler under test
  int vtt_size;
  unsigned int n_initialized_bases;
  unsigned char has_virtual_bases;
  unsigned char has_class_type_fields;
  VTBL_ENTRY *alt_thunk_names;
};



#ifdef __cplusplus
//inline void *operator new(std::size_t, void * x) { return x;}
inline void *operator new(size_t, void * x) { return x;}
extern "C" {
#endif

  extern long long hide_sll(long long);
  extern unsigned long long hide_ull(unsigned long long);
  extern void f_note_ctor(const char *, void*, const char *, int);
  extern void f_note_dtor(const char *, void*, const char *, int);
  extern void init_test(Class_Descriptor*, void *addr);
  extern void init_simple_test(const char *name);
  extern void f_check2(int actual, int expected, const char *name, const char *filename, int linenum);
  extern void f_check_field_offset(void *var_p, void *fld_p, int expected_ofst, const char *name, const char *filename,int linenum);
  extern void Check_Ctor_Dtor_Calls(void *);
  void test_class_info(void *, Class_Descriptor*);
  void test_bitfield_value(void *obj_ptr, unsigned byte_offset, unsigned bit_offset, unsigned bit_size, long long expected_value, unsigned obj_size, const char *name, const char *filename, int linenum);
  void clear_var(void *a, unsigned sz);
#ifdef __cplusplus
}
#endif

#define note_ctor(a,b) f_note_ctor(a,b,__FILE__, __LINE__)
#define note_dtor(a,b) f_note_dtor(a,b,__FILE__, __LINE__)

#ifdef NO_STATIC_CHECKS

// This version of checking macros does all checking at runtime.
#define check2(a, b, c) f_check2(a,b,c,__FILE__, __LINE__)


#else // !NO_STATIC_CHECKS

// This version of checking macros reports test failures at compiler time. The resulting code
// is smaller with this version, but even one failure will prevent the build
#define check2(a,b,c) { extern int jj[(2*((a)==(b)))-1];n_tests++;} 

#endif // !NO_STATIC_CHECKS

#define check_field_offset(var, fld, ofst, name) \
    f_check_field_offset(&var, &(var.fld), ofst, name, __FILE__, __LINE__)

#define check_base_class_offset(var, derivation_seq, ofst, cn) \
    f_check_field_offset(&var, derivation_seq &var, ofst, #derivation_seq cn, __FILE__, __LINE__)
#define AMB_check_base_class_offset(var, derivation_seq, ofst, cn) 

#define set_bf_and_test(var, bitfield, byte_ofst, bit_ofst, bit_size, value, classname) \
    {var.bitfield = value; \
     test_bitfield_value(&var, byte_ofst, bit_ofst, bit_size, value, sizeof(var),classname "." #bitfield, __FILE__, __LINE__);}

typedef void (*voidfunc)(void);
typedef struct _atcm { // The C struct equivalent to Arrange_To_Call_Me
  voidfunc func;
  struct _atcm *next;
  const char *name;
} ATCM;

#ifdef __cplusplus
extern struct Arrange_To_Call_Me *atcm_head;
struct Arrange_To_Call_Me {
  voidfunc func;
  Arrange_To_Call_Me *next; 
  const char *name;
  Arrange_To_Call_Me(voidfunc f, const char *n, unsigned size=10) { 
    if (size <= 10240) {
      func = f;
      next = atcm_head;
      atcm_head = this;
      name = n;
    }
  }
};
#define ARRANGE_TO_CALL_ME(func,cn) Arrange_To_Call_Me v##cn(func, #cn, sizeof(cn));
#else
extern void atc_register(voidfunc func, const char *name, size_t sz);
#define ARRANGE_TO_CALL_ME(func,cn) __attribute__((constructor)) static void atc_##cn() \
              { atc_register(func,#cn, sizeof(struct cn));}


#endif

// bs is the size of a signed bitfield in bits. v is a constant being assigned to it. 
// sign extend v.
#define SEXT_BFV(bs,v) ((v)|(((v) & (1ULL<<((bs)-1))) ? (~(1ULL<<(bs))) : 0))


#endif // __testsuite_dot_h
