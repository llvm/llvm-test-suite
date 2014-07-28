// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
#include "testsuite.h"


#if 0 // __linux__
Not yet. 
#define _GNU_SOURCE
#include <dlfcn.h>
static char *find_symname(void *addr, char *buf);
#else
#define find_symname(a,b) ""
#endif

#include <stdio.h>
#include <string.h>

// given a full pathname, return path starting from test
static char *trim_fn(const char *ifn)
{
  // basically find last /test/
  char *x, *fn = (char*) ifn;
  char *rv = fn;
  if (!strncmp(fn, "test/", 5))
    return fn; // fn starts with test/
  while ((x = strstr(rv, "/test/"))) // look for /test/
    rv = x+1;
  return rv;
}

#define TRUE 1
#define FALSE 0
int num_classes = 0, n_errors = 0, n_tests = 0;
int verbose = 0;
int test_finished = FALSE;
void f_check2(int actual, int expected, const char *name, const char *filename, int linenum)
{
  n_tests++;
  if (actual != expected) {
    printf("ERROR at %s:%d '%s' actual %d != expected %d\n", trim_fn(filename), linenum, name, actual, expected);
    n_errors++;
  } else if (verbose > 1) {
    printf("OK at %s:%d '%s' = %d\n", trim_fn(filename), linenum, name, actual);
  }
}

void f_check_field_offset(void* ps, void* pf, int ofst, const char *name, const char * filename, int linenum)
{
  n_tests++;
  if ((((char*)ps) + ofst) != ((char*)pf)) {
    //printf("ERROR at %s:%d '%s' 0x%p + %d != 0x%p\n", trim_fn(filename), linenum, name, ps, ofst, pf);
    printf("ERROR at %s:%d '%s' expected ofst %d != actual ofst %d\n", trim_fn(filename), linenum, 
               name, ofst, (int)(((char*) pf)-((char*) ps)));
    n_errors++;
  } else if (verbose > 1) {
    printf("OK at %s:%d '%s' expected ofst = %d\n", trim_fn(filename), linenum, name, ofst);
  }
}


static Class_Descriptor *cur_cd;

static void *full_object_address; // address of the full object being constructed.
        // This is used to do checks for ctors and dtors during the construction. 
        // if the object is being constructed via a placement new, we know the address before
        // the ctors starts, else this is deduced from the first call to a ctor.

static int cur_init_seq;
static int ctors_done; // set to 1 once the full object has been created.

void 
init_simple_test(const char *name)
{
  num_classes++;
  cur_cd = NULL;
  if (verbose)
    printf("Testing class %s\n", name);
}

void 
init_test(Class_Descriptor *cd, void *var_addr)
{
  cur_cd = cd;
  full_object_address = var_addr;
  cur_init_seq = 0;
  num_classes++;
  ctors_done = 0;
  if (verbose)
  printf("Testing class %s\n", cd->name);
}

#include <stdarg.h>
extern void abort();
extern void exit(int);
static void Blow_Up(const char *m, ...)
{
  va_list ap;
  va_start(ap, m);
  printf("Assertion Failed: ");
  vprintf(m, ap);
  printf("\n");
  exit(1);
}

#define Is_True(a, b) if (!(a)) Blow_Up b

static Base_Class *
find_base_from_seq_num(Class_Descriptor *cd, int seq)
{
  Base_Class *b = cur_cd->bases;
  if (b) {
    for (; b->type; b++) 
      if (b->init_seq == seq)
        return b;
  }
  return NULL;
}


static int satisfies_alternate_matches(VTBL_ENTRY expected, VTBL_ENTRY actual, 
                                         Class_Descriptor *cd, int t)
{
  VTBL_ENTRY *alt_tbl = cd->alt_thunk_names;
  int i=0, state = 0;

  if (!alt_tbl) return 0;
  // alt_tbl is an array of items separated by a single NULL and terminated by another NULL
  // each item is a sequence of VTBL entrie such that the first one is the expected value and
  // rest of them are acceptable alternate values
  // state machine: state 0 at the start. state 1 inside the list of extected. 2 inside other list
  // state    ANTERM    expected   actual   any-non-NULL
  // 0         F         1         F          2
  // 1         F         F         T          1
  // 2         0         2         2          2
  // 
  //printf(" SAM EXP:%p ACT:%p CD=%p tbl:%p t=%d\n", expected, actual, cd, alt_tbl, t);
  while (1) {
    VTBL_ENTRY v = alt_tbl[i];
    //printf("  [%d] %d= ", i, state); 
    //printf((v==NULL)?" 0\n":(v==ALT_NAMES_TERMINATOR)?" ALNT\n":":%p\n", v);
    switch (state) {
      case 0: 
        if (v == expected) 
          state = 1;
        else if (v == actual || v == ALT_NAMES_TERMINATOR)
          return FALSE;
        else
          state = 2;
        break;
      case 1:
        if (v == actual) {
          return TRUE;
        } else if (v == ALT_NAMES_TERMINATOR || v == expected) {
          return TRUE; // this allows tests to pass if the expected sym is a virtual thunk
                       // but the actual sym is not in the alternate lists. This can happen
                       // if there are multiple virtual thunks reaching same place, and
                       // some compiler selects a different one than our. For now we are
                       // allowing that. Perhaps we can figure out a way of tightening this
                       // by 
                       //    - adding all possible thunks that reach same place, 
                       //    - somehow comparing thunks for equivalence
          //return FALSE;
        } else 
          state = 1;
        break;
      case 2:
        state = (v == ALT_NAMES_TERMINATOR) ? 0 : 2;
    }
    i++;
  }
}


// actual points to the VTT variable defined by the compiler under test.
// expected points to an array of VTT_ENTRY structures. Each VTT_ENTRY structure has a 
// field 'VTBL_ENTRY *vtbl', which must match the corresponding entry of actual. However,
// the meaning of the match is non-trivial. If expected[i].ofst==0, actual[i] and expected[i].vtbl
// both must point to same element of the primary vtbl of the class, hence the pointer values
// must match. if expected[i].ofst is non-zero, both point to copies of secondary vtables whose 
// contents must be same. In that case, we run memcmp on those vtables.
static void 
check_vtt_tbl(Class_Descriptor *cd, VTT_ENTRY *expected, VTBL_ENTRY **actual, char *name, int size)
{
  int i, j;
  n_tests++;
  if (verbose > 1) 
    printf("check_vtt_tbl %s %s EXPECTED:%p ACTUAL:%p %d\n", cd->name, name, expected, actual, size);
  for (i=0; i<size; i++) {
    if (expected[i].vtbl != actual[i]) {
      // actual pointers do not match, but the contents could still match. 
      int ofst = expected[i].ofst;
      int size = expected[i].size;
      VTBL_ENTRY *exp = expected[i].vtbl - ofst;
      VTBL_ENTRY *act = actual[i] - ofst;
      int n_mismatches = 0;
      if (memcmp(exp, act, size*sizeof(VTBL_ENTRY)) == 0) {
        // contents match. 
        continue;
      }
      for (j=0; j<size; j++) {
        if (exp[j] != act[j] && !satisfies_alternate_matches(exp[j], act[j], cd, j)) {
          if (n_mismatches==0) {
            static char erb1[10240], erb2[10240];
            if (act[j] == NULL) {
              continue; // a vtbl entry can be NULL in clang, if clang chooses to always use another vtbl
            }
            printf("ERROR: Expected contents of %s::vtbl from vtt, for class %s do not match. at index %d. "
                   "memcmp(EXPECTED:%p,ACTUAL:%p,%d)\n", 
                   name, cd->name, j, exp, act, (int)(size*sizeof(VTBL_ENTRY)));
            n_mismatches++;
            n_errors++;
            printf("   %d: EXPECTED:%p%s ACTUAL:%p%s\n", j, 
                    (void*)exp[j], find_symname((void*)exp[j], erb1),
                    (void*)act[j], find_symname((void*)act[j], erb2));
          }
        }
      }
    }
  }
}


static void 
check_vftbl(Class_Descriptor *cd, void *expected, void *actual, char *name, int size)
{
  int i, n_mismatches=0;
  n_tests++;
  if (verbose > 1) 
    printf("check_vftbl %s %s %p %p %d\n", cd->name, name, expected, actual, size);
  if (memcmp(expected, actual, sizeof(VTBL_ENTRY)*size)) {
    void **pexp = (void**) expected;
    void **pact = (void**) actual;
    for (i=0; i<size; i++) {
      if (pexp[i] != pact[i] && 
              !satisfies_alternate_matches((VTBL_ENTRY)pexp[i], (VTBL_ENTRY)pact[i], cd, -i)) {
        static char erb1[10240], erb2[10240];
        if (pact[i] == NULL) {
          continue; // a vtbl entry can be NULL in clang, if clang chooses to always use another vtbl
        }
          
        if (n_mismatches==0) {
          printf("ERROR: Expected contents of %s::vtbl, for class %s do not match.\n", name, cd->name);
          n_errors++;
          n_mismatches++;
        }
        printf("  %d: EXPECTED:%p%s ACTUAL:%p%s\n", i, pexp[i], find_symname(pexp[i], erb1),
                pact[i], find_symname(pact[i], erb2));
      }
    }
  }
}

// if derivation of b in cd has any virtual steps, return he most-derived such base, else 
// return NULL
static Base_Class *
any_virtual_steps_in_derivation(Class_Descriptor *cd, Base_Class *b)
{
  // first a simple assertion check that b is a base class of cd
  Is_True(
    cd->bases &&  // cd has bases
    (b >= cd->bases) && ((b-cd->bases) < cd->n_bases) && // b lies between first and last base of cd
    ((cd->bases + (b-cd->bases)) == b), // it is a proper Base_Class ptr
          ("Wrong base in any_virtual..."));
  while (1) {
    if (b->is_virtual)
      return b;
    if (b->parent_idx < 0)
      return 0;
    b = cd->bases + b->parent_idx;
  }
}

// check tbls of cd and all non-virtual bases, and, if check_virtual_bases is TRUE, its
// virtual bases as well. This flag will be true when the var_ptr points to a full object of 
// type cd, i.e., 
//  - when the cd is the main class under test and the full object of cd has been constructed,
//    and destruction has not yet started,
//  - or, if cd is a base class of the class under test, but cd itself does not have any 
//    virtual base classes and we are currently in ctor or dtor of cd.
static void 
check_full_object_vtbls(void *var_ptr, Class_Descriptor *cd, int check_virtual_bases)
{
  Base_Class *b;
  // check that the initialized contents of the main vtbl variable, as generated by the 
  // compiler-under-test are what we expect them to be
  if (cd->expected_vtbl_contents) {
      check_vftbl(cd, cd->expected_vtbl_contents, cd->vtbl.var, cd->vtbl.name, cd->vtbl_size);
      // check that the fully initialized object attaches to that vtbl variable at correct
      // offset. i.e., var_ptr[0] should point inside the vtbl_var+vtbl_ofst. 
      // However, if var_ptr is does not point to a full object of cd (indicated by 
      // check_virtual_bases being false), and cd has some virtual bases, its vtbl will not match
      // the cd->vtbl_var because that reflects the shape of a full object of cd.
      if (check_virtual_bases || !cd->has_virtual_bases) {
        if ((*(VTBL_ENTRY**)var_ptr) != (cd->vtbl.var + cd->vtbl_ofst)) {
          printf("ERROR: Object of class %s::%s does not point to expected spot in vtbl\n", cur_cd->name, cd->name);
          n_errors++;
        }
      }
  }
  // check that any non-primary base classes also attach to the expected offsets
  if (cd->bases)
  for (b=cd->bases; b->type; b++) {
      if (b->ofst != 0 && b->vtbl_ofst >= 0 && (check_virtual_bases || !any_virtual_steps_in_derivation(cd, b))) {
        // cd->vtbl.var is the vbl variable. It contains the main vtbl, followed by vtbls
        // for base classes at non-zero offsets. b->vtbl_ofst is the offset (in terms of vtbl 
        // entries) of the b's vtbl in the main vtbl. But the object does not attach to the top
        // of any vtbl; it attaches at least two entries down, and maybe more. That is given by 
        // b->num_negative_vtbl_entries
        if ((*(VTBL_ENTRY**)(b->ofst+(char*)var_ptr)) !=
                (cd->vtbl.var + (b->vtbl_ofst+b->num_negative_vtbl_entries))) {
          printf("ERROR: base class %s of class %s::%s does not have correct vtbl ", b->type->name,
                 cur_cd->name,  cd->name);
          printf("0x%x != (0x%x + %d + %d) = 0x%x\n",
          (int)(*(VTBL_ENTRY**)(b->ofst+(char*)var_ptr))  ,
              (int)cd->vtbl.var ,(int) b->num_negative_vtbl_entries, (int)b->vtbl_ofst,
              (int)(cd->vtbl.var + (b->vtbl_ofst+b->num_negative_vtbl_entries)));
          n_errors++;
        }
      }
  }
}



// Given a derived class der, and it base class entry b. d_in_b is a Base_Class entry in
// b->type. Find corresponding Base_Class entry of der.
// There are three possible situations:
// 1) d_in_b is virtual by itself. In that case we need to just find a virtual base class of same
//    type in der. Since there can be only one such virtual base class in der, that is all.
// 2) d_in_b is not virtual, and there are no virtual steps from b to d_in_b. In this case
//    the relative offset of b-to-d_in_b will be same in der as it is in a b. So we just look
//    for a base class of expected type at such computed offset.
// 3) Third case is more complicated. here d_in_b is not virtual by itself, but there are virtual
//    steps in b-to-d_in_b derivation. Say a base class t is lowest such step, i.e., t is a 
//    virtual base of b, and d_in_b is a base class of t without any virtual steps from t to 
//    d_in_b. In this case we first find the virtual base t in der using rule 1, and then use 
//    rule 2 to find the final answer
//
static Base_Class *
find_corresp_base(Class_Descriptor *der, Base_Class *b, Base_Class *d_in_b)
{
  Base_Class *t, *p, *q;

  if (d_in_b->is_virtual) {
    // case 1
    for (t = der->bases; t < (der->bases + der->n_bases); t++)
      if (t->is_virtual && t->type == d_in_b->type)
        return t;
    Is_True(0, ("Count not find virtual base class %s in %s", d_in_b->type->name, der->name));
  }
  if (!(p=any_virtual_steps_in_derivation(b->type, d_in_b))) {
    // case 2
    for (t = der->bases; t < (der->bases + der->n_bases); t++)
      if ((!t->is_virtual) && t->ofst == (b->ofst + d_in_b->ofst) && t->type == d_in_b->type )
        return t;
    Is_True(0, ("Count not find non virtual base class %s in %s", d_in_b->type->name, der->name));
  }

  // case 3. First we find the highest non-virtual derived class from d_in_b
  q = find_corresp_base(der, b, p);// use rule 1. This will work because we know that p is virtual
  for (t = der->bases; t < (der->bases + der->n_bases); t++)
    if ((!t->is_virtual) && t->ofst == (q->ofst + d_in_b->ofst-p->ofst) && t->type == d_in_b->type )
      return t;
  Is_True(t<(der->bases + der->n_bases), ("Could not find_corresp_base(%s, %s, %s)", der->name, 
              b->type->name, d_in_b->type->name));
  return 0;
}

// same as strcat, but some toolkits do not have strcat
static void 
mystrcat(char *a, char *b)
{
  int i, j;
  for (j=0; a[j]; j++) ;
  for (i=0; b[i]; i++) a[j++] = b[i];
  a[j] = 0;
}

// Called from ctor and dtors of base classes of the main class under test (which is cur_cd).
// init_seq is the sequence number of ctors, which increases from 1 till the whole class has
// been contructed, and decreases back. n is the name of the baseclass whose ctor/dtor has 
// been called. this_p is the 'this' pointer being pass the ctor/dtor. The task here is to check
// that correct vtbls are being passed to the current class being constructed, and all its
// base classes.
void 
check_base(int init_seq, const char *n, void* this_p, const char *filename, int linenum)
{
  Base_Class *b;
  if (verbose> 1) 
    printf("check_%ctor %s %p-%p from %s:%d cur_cd=%s init_seq=%d cur_init_seq=%d\n", 
            ctors_done?'d':'c',
            n, this_p, full_object_address, trim_fn(filename), linenum, cur_cd->name, init_seq, cur_init_seq);
  if (init_seq == 1 && !full_object_address) {
    // this is first call. Go through base classes of cur_cd to find the base with 
    // init_seq==1, and deduce the full object address from that. 
    b = find_base_from_seq_num(cur_cd, 1);
    Is_True(b, ("first-init base not found"));
    full_object_address = (void*) (((char*)this_p) - b->ofst);
  } else {
    // find the base with this init seq
    b = find_base_from_seq_num(cur_cd, init_seq);
    Is_True(b, ("init base %s %d not found", cur_cd->name, init_seq));
  }
  if (strcmp(b->type->name, n)) {
    printf("Wrong ctor/dtor being called \n");
    n_errors++;
    return;
  }
  if (full_object_address != (void*) (((char*)this_p) - b->ofst)) {
    printf("ERROR: %ctor of %s::%s being called with wrong offset 0x%p != 0x%p+%d = 0x%p\n", 
            ctors_done?'d':'c', cur_cd->name, b->type->name,
            this_p, full_object_address, (int)b->ofst, 
             ((char*)full_object_address)+b->ofst);
    n_errors++;
    return;
  }
  if (!cur_cd->vtbl.var)
    return; // nothing further to check.
  // While construction a full object A, during construction or destruction of a subobject, 
  // say B, the virtual function set of A::B must be same as the full object B, irrespective of
  // any virtual function overrides between B and A. However, the shape of A::B is not necessarily
  // same of the full object B.
  if (!b->type->has_virtual_bases) {
    // The shape of A::B is same as the full object B, since B does not have any virtual bases.
    // In that case, we can just run the full_object test.
    check_full_object_vtbls(this_p, b->type, TRUE);
  } else {
    // b->type has some virtual bases of its own. So the shape is not same as that of a full 
    // b->type, but the virtual function set is. In this case check the primary vtbl, and 
    // each base class separately.
    // We are running ctor of B, while constructing full object A
    // First, the primary vtbl test.
    //   a) if b->type_subarray_index_in_vtt is non-zero, the primary vtable is A.vtt[b.index_in_vtbl-1]
    //   b) else find the lowest parent, D, of B whose Base_Class entry for class B has a non-zero 
    //      index_in_vtt. (this is a_base_class.index_in_construction_vtable_array). There 
    //      must be one.
    //   c) proceed up from D to A, collecting 
    //      (base_subarray_index_in_vtt-1) whereever base_subarray_index.. is non-zero, and
    //      add that to the number of the last step.
    VTBL_ENTRY *pointed_tbl = *(VTBL_ENTRY**)this_p;
    VTT_ENTRY *vttp;
    Base_Class *d_in_b, *d_in_cur_cd;
    Class_Descriptor *bc = b->type;
    //check_full_object_vtbls(this_p, b->type, FALSE); // check non-virtual base classes, if any
    Is_True(b->base_subarray_index_in_vtt>0, ("%s::%s->type_subarray_index_in_vtt must be >0",
                                                   cur_cd->name, bc->name));
    vttp = cur_cd->expected_vtt_contents + (b->base_subarray_index_in_vtt-1);
    check_vftbl(cur_cd, vttp->vtbl - vttp->ofst, pointed_tbl-vttp->ofst, b->type->name, vttp->size);
    // and now we need to check vtbls of all subclasses of b that use vtbl.
    // scan all base classes of B, and find corresponding Base_Class entry in cur_cd->bases
    for (d_in_b = bc->bases; d_in_b < (bc->bases+bc->n_bases); d_in_b++) {
      char buf[10240];
      if (!d_in_b->type->vtbl.var)
        continue; // nothing to check for this base
      if (d_in_b->index_in_vtt == 0)
        continue; // checked via some other base
      d_in_cur_cd = find_corresp_base(cur_cd, b, d_in_b);
      if (d_in_b->ofst == 0)
        continue; // d is at offset 0, so the vtbl has already been checked above.
      // we need to take the offset from d_in_cur_cd, because that reflects the shape of cur_cd
      // but we take expected vtbl ptr by first selecting vtt group for b-in-cur_cd and then
      // using d-in-b to pick a particular vtbl
      vttp = cur_cd->expected_vtt_contents + (b->base_subarray_index_in_vtt-1) + (d_in_b->index_in_vtt-1);
      pointed_tbl = *(VTBL_ENTRY**)(((long)full_object_address) + d_in_cur_cd->ofst);

      // follwing four lines are essentially
      //     sprintf(buf, "%s-during-%s()", d_in_b->type->name, bc->name);
      buf[0] = 0;
      mystrcat(buf, d_in_b->type->name);
      mystrcat(buf, "-during-");
      mystrcat(buf, bc->name);
      mystrcat(buf, "()");
      check_vftbl(cur_cd, vttp->vtbl - vttp->ofst, pointed_tbl-vttp->ofst, buf, vttp->size);
    }
  }
}

static Base_Class *find_base_class(ptrdiff_t ofst, Class_Descriptor *cd, const char *name)
{
  Base_Class *bc = cd->bases;
  if (bc) {
    for (; bc < (cd->bases+cd->n_bases); bc++)
      if (bc->ofst == ofst && !strcmp(bc->type->name, name))
        return bc;
  }
  return NULL;
}

void 
f_note_ctor(const char *n, void* this_p, const char *filename, int linenum)
{
  if (cur_cd == NULL) // cur_cd has no base classes. This must be from a field
    return;
  if (!cur_cd->has_class_type_fields) {
    if (strcmp(n, cur_cd->name))
      check_base(++cur_init_seq, n, this_p, filename, linenum);
    // else we have reached the ctor of the top class. The tests will be done by test_class_info
  } else if (cur_cd->n_bases == 0) {
    // nothing to check. ctor is for a field.
  } else {
    // cur_cd has fields that will call constructors and destructors, therefore init_sequence 
    // checks can not be done, but it also has bases that need to be checked.
    // See if a base matches the offset and type, and check that
    Base_Class *bc = find_base_class(((char*)this_p) - ((char*)full_object_address), cur_cd, n);
    if (bc)
      check_base(bc->init_seq, n, this_p, filename, linenum);
  }
}

void 
f_note_dtor(const char *n, void * this_p, const char *filename, int linenum)
{
  if (test_finished)
    return;
  if (cur_cd == NULL) // cur_cd has no base classes. This must be from a field
    return;
  if (!cur_cd->has_class_type_fields) {
    if (strcmp(n, cur_cd->name))
      check_base(cur_init_seq--, n, this_p, filename, linenum);
    // else we are destroying the top class. The tests have been done by test_class_info
  } else if (cur_cd->n_bases == 0) {
    // nothing to check. dtor is for a field.
  } else {
    // cur_cd has fields that will call constructors and destructors, therefore init_sequence 
    // checks can not be done, but it also has bases that need to be checked.
    // See if a base matches the offset and type, and check that
    Base_Class *bc = find_base_class(((char*)this_p) - ((char*)full_object_address), cur_cd, n);
    if (bc)
      check_base(bc->init_seq, n, this_p, filename, linenum);
  }
}

void Check_Ctor_Dtor_Calls(void *op)
{
  if (cur_init_seq != 0) {
    printf("ERROR: Expected number of dtors not called %s\n", cur_cd->name);
    n_errors++;
  }
}


void test_class_info(void *var_ptr, Class_Descriptor* cd)
{
  ctors_done = 1;
  if (verbose > 1) {
    printf("test_class_info %s %p cur_init_seq=%d\n", cd->name, var_ptr, cur_init_seq);
  }
  if (full_object_address && full_object_address != var_ptr) {
    printf("ERROR: full object address does not match deduced address %s\n", cur_cd->name);
    n_errors++;
  }
  if ((cur_init_seq != cd->n_initialized_bases) && !cd->has_class_type_fields) {
    printf("ERROR: Not all bases of %s were initialized \n", cur_cd->name);
    n_errors++;
  }
  if (cd->expected_vtbl_contents) {
    // check that fully constructed object points to correct vtbls.
    check_full_object_vtbls(var_ptr, cd, TRUE);
  }
  if (!cd->vtt.var) {
    // Sunil: may 1, 2014: Made vtt a weak symbol and added '&&cd->vtt.var' check. Clang, with -O
    // does not generate VTT if it is not going to be used, such as if a class X has virtual base 
    // Y but Y has no virtual base of functions. In this case the VTT for X will never be used.
    // TODO: add check for that property; that base classes do not need vtt.
  } else if (cd->expected_vtt_contents) {
    // We can not simply compare the contents of VTT tables always. 
    // VTT table has two kind of entries. Some entries point to elements of main vtbl whose
    // name is specified by the ABI spec, so we refer to them as globally visible name, and
    // we can expec the pointer values in vtt to be same.
    // In other cases though, vtt entries point to aux-vtables, whose names are not specified
    // by the ABI spec, so the generated tests have their own names which are not same as the
    // names generated by the compiler-under-test. Their contents are expected to match, but
    // not the pointer values. The contents are being tested by the ctor vtable tests.
    // TODO: check those vtt entries here that point to main vtbl
    check_vtt_tbl(cd, cd->expected_vtt_contents, cd->vtt.var, cd->vtt.name, cd->vtt_size);
  }
}

static int f_isLittleEndian() {
  unsigned short i = 0xff00;
  unsigned char *i_ptr = (unsigned char *) &i;
  return !(*i_ptr);
}
static int isLittleEndian;

static unsigned char LITTLE_ENDIAN_MASKS[] = { 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff };
static unsigned char BIG_ENDIAN_MASKS[] = { 0x00, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff };

// Function to read the value of a bitfield
// NOTE: This function implicitly depends on a byte having 8 bits. If a byte is of a different size, several of the calculations would be incorrect.
static long long readValue(unsigned char *iter, unsigned int bit_offset, int size) {
  int is_little_endian = isLittleEndian;
  long long retval = 0;
  unsigned char mask = 0;
  unsigned char adjustment_offset = 0;

  if(!iter) return retval;

  // read the first partial piece (if any)
  if(bit_offset) {
    unsigned char bits_to_read = 8 - bit_offset;
    // Check to see if the object is fully contained within the remaining bits, and if so
    // restrict the read to only those bits.
    if(size < bits_to_read)
      bits_to_read = size;

    if(is_little_endian) {
      mask = LITTLE_ENDIAN_MASKS[bits_to_read] << bit_offset;
      retval = ((*iter) & mask) >> bit_offset;
      adjustment_offset += bits_to_read;
    } else {
      mask = BIG_ENDIAN_MASKS[bits_to_read] >> bit_offset;
      retval = (*iter) & mask;
      // If we read in the entire value, we need to potentially right shift it, and clear 
      // out the upper bits to be safe
      if(size == bits_to_read) {
        retval >>= (8 - (bits_to_read + bit_offset));
        retval &= ~(BIG_ENDIAN_MASKS[8 - bits_to_read]);
      }
    }

    // Decrement the size by the number of bits read, and move to the next byte
    size -= bits_to_read;
    iter++;
  }
  
  // read in a full byte at a time
  while(size >= 8) {
    if(is_little_endian) {
      retval |= ((long long)((*iter) & 0xff)) << adjustment_offset;
      adjustment_offset += 8;
    } else {
      retval <<= 8;
      retval |= (*iter) & 0xff;
    }
    // Decrement the size by a byte and move to the next byte
    size -= 8;
    iter++;
  }

  // read any remaining bits
  if(size) {
    if(is_little_endian) {
      mask = LITTLE_ENDIAN_MASKS[size];
      retval |= ((long long)((*iter) & mask)) << adjustment_offset;
      adjustment_offset += size;
    } else {
      mask = BIG_ENDIAN_MASKS[size];
      retval <<= size;
      retval |= ((*iter) & mask) >> (8 - size);
    }
    size = 0;
    iter = 0;
  }

  return retval;
}


int  is_bitfield_value_correct(void *obj_ptr, unsigned int byte_offset, unsigned int bit_offset, unsigned int size, long long expected_value) {
  long long read_value = readValue(((unsigned char *)obj_ptr) + byte_offset, bit_offset, size);
  unsigned long long expected_mask = 0, i;

  //n_tests++;

  // Calculate the mask to be used for the incoming value which was probably sign extended
  expected_mask = 0;
  for(i = 0; i < size; i += 8) {
    expected_mask <<= 8;
    expected_mask |= 0xff;
  }
  if(size % 8) {
    expected_mask <<= (size % 8);
    expected_mask |= LITTLE_ENDIAN_MASKS[(size % 8)];
  }
  expected_value &= expected_mask;
  read_value &= expected_mask;

  if(read_value != expected_value) 
    return 0;

  return 1;
}
void clear_var(void *a, unsigned b)
{
  // do not rely on memzero
  char *ca = a;
  unsigned i;
  for (i=0; i<b; i++)
    ca[i] = 0;
}



void test_bitfield_value(void *obj_ptr, unsigned int byte_offset, unsigned int bit_offset, 
                         unsigned int size, long long expected_value, unsigned var_size, 
                         const char *name, const char *filename, int linenum) {
  long long read_value = readValue(((unsigned char *)obj_ptr) + byte_offset, bit_offset, size);
  unsigned long long expected_mask = 0, i;

  n_tests++;

  // Calculate the mask to be used for the incoming value which was probably sign extended
  expected_mask = 0;
  if (size > 7)
  for(i = 0; i < size; i += 8) {
    expected_mask <<= 8;
    expected_mask |= 0xff;
  }
  if(size % 8) {
    expected_mask <<= (size % 8);
    expected_mask |= LITTLE_ENDIAN_MASKS[(size % 8)];
  }
  expected_value &= expected_mask;
  read_value &= expected_mask;

  if(read_value != expected_value) {
    int i, found = -1;
    for (i=1; i<20; i++) {
      if ((byte_offset+i) < var_size && is_bitfield_value_correct(obj_ptr, byte_offset+i, bit_offset, size, expected_value)) {
        found = byte_offset+i;
        break;
      }
      if (byte_offset >= i && is_bitfield_value_correct(obj_ptr, byte_offset-i, bit_offset, size, expected_value)) {
        found = byte_offset-i;
        break;
      }
    }
    printf("ERROR at %s:%d Bitfield errors found (expected=0X%llX, got=0X%llX) in %s", 
            trim_fn(filename), linenum, expected_value, read_value, name);
    if (found >= 0) printf(" expected byte ofst %d != actual byte ofst %d", byte_offset, found);
    printf("\n");
    n_errors++;
  }

  return;
}


ATCM *atcm_head;

#ifndef __cplusplus
extern void *malloc(size_t);
void atc_register(voidfunc func, const char *name, size_t sz)
{
  ATCM *sa = (ATCM*) malloc(sizeof(ATCM));
  sa->next = atcm_head;
  atcm_head = sa;
  sa->func = func;
  sa->name = name;
}

#endif


int main(int argc, char **argv)
{
  int i, run_full_test = 1;
  ATCM *p;
  isLittleEndian = f_isLittleEndian();
  for (i=1; i<argc; i++) {
    char *a = argv[i];
    if (a[0] == '-' && a[1] == 'v') {
      verbose++;
      continue;
    }
    for (p=atcm_head; p; p = p->next)
      if (strcmp(a, p->name)==0)
        break;
    if (!p) {
      printf("Unknown arg '%s'\n", a);
      exit(1);
    }
    p->func();
    run_full_test = 0;
  }
  if (run_full_test) {
    ATCM *t, *h = NULL;
    // first reverse the chain
    while (atcm_head) {
      t = atcm_head;
      atcm_head = t->next;
      t->next = h;
      h = t;
    }

    while (h) {
      h->func();
      h = h->next;
    }
  }
  printf("TEST %s. %d classes. %d tests. %d failures.\n", 
           n_errors||!n_tests?"FAILED":"PASSED",num_classes, n_tests, n_errors);
  
  test_finished = TRUE;
  cur_cd = NULL;
  return n_errors != 0;
}

long long hide_sll(long long p) { return p; }
unsigned long long hide_ull(unsigned long long p) { return p; }
#if 0 //def __linux__
static char *find_symname(void *addr, char *buf)
{
  Dl_info dli;
  int rv;
  if (!addr) return "";
  rv = dladdr(addr, &dli);
  if (rv) return "";
  long ofst = ((long)dli.dli_saddr) - ((long)addr);
  if (ofst > 0)
    sprintf(buf, " (%s+%ld)", dli.dli_sname, ofst);
  else if (ofst < 0)
    sprintf(buf, " (%s-%ld)", dli.dli_sname, -ofst);
  else
    sprintf(buf, " (%s)", dli.dli_sname);
  return buf;
}
#endif
