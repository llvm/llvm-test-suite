// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: cxx_compiler -c %s -I "common" cxx_rtti -o %t1.o
// RUN: c_compiler -c %s -o %t2.o -I "common" 
// RUN: c_compiler -c -o %t3.o -I "common" "common/testsuite.c"
// RUN: linker -o %t%exeext %t1.o %t2.o %t3.o
// RUN: runtool %t%exeext | grep "TEST PASSED"
#include "testsuite.h"
#ifdef __cplusplus
extern "C" int printf(const char *, ...);


#define PTRSIZE sizeof(int*)
#define PMFSIZE (2*PTRSIZE)


struct abcd {

  int f1();
  int f3();
  int f5();
  int f7();
  virtual int g1();
  virtual int g3();
  virtual int g5();
  virtual int g7();
  int a;
};
int abcd::f1(){return __LINE__;}
int abcd::f3(){return __LINE__;}
int abcd::f5(){return __LINE__;}
int abcd::f7(){return __LINE__;}
int abcd::g1(){return __LINE__;}
int abcd::g3(){return __LINE__;}
int abcd::g5(){return __LINE__;}
int abcd::g7(){return __LINE__;}


struct efgh {
  int f2();
  int f3();
  int f6();
  int f7();
  virtual int g2();
  virtual int g3();
  virtual int g6();
  virtual int g7();
  int *e, f;
};
int efgh::f2() { return __LINE__;}
int efgh::f3() { return __LINE__;}
int efgh::f6() { return __LINE__;}
int efgh::f7() { return __LINE__;}
int efgh::g2() { return __LINE__;}
int efgh::g3() { return __LINE__;}
int efgh::g6() { return __LINE__;}
int efgh::g7() { return __LINE__;}

struct pqrs : abcd, efgh {
  int *x, p;
  int f4();
  int f5();
  int f6();
  int f7();
  virtual int g4();
  virtual int g5();
  virtual int g6();
  virtual int g7();
};
int pqrs::f4() { return __LINE__; }
int pqrs::f5() { return __LINE__; }
int pqrs::f6() { return __LINE__; }
int pqrs::f7() { return __LINE__; }
int pqrs::g4() { return __LINE__; }
int pqrs::g5() { return __LINE__; }
int pqrs::g6() { return __LINE__; }
int pqrs::g7() { return __LINE__; }

struct lmno : virtual abcd, virtual efgh {
  int f4();
  int f5();
  int f6();
  int f7();
  virtual int g4();
  virtual int g5();
  virtual int g6();
  virtual int g7();
  double d;
  int p;
  char x;
  int r;
};
int lmno::f4() { return __LINE__; }
int lmno::f5() { return __LINE__; }
int lmno::f6() { return __LINE__; }
int lmno::f7() { return __LINE__; }
int lmno::g4() { return __LINE__; }
int lmno::g5() { return __LINE__; }
int lmno::g6() { return __LINE__; }
int lmno::g7() { return __LINE__; }

struct novtbl {
  int a;
  char b;
  int *p;
  int q;
};

int abcd::*abcd_null = 0;
int abcd::*abcd_a = &abcd::a;
int *efgh::*efgh_e = &efgh::e;
int efgh::*efgh_f = &efgh::f;
int *pqrs::*pqrs_x = &pqrs::x;
int pqrs::*pqrs_p = &pqrs::p;

double lmno::*lmno_d = &lmno::d;
int    lmno::*lmno_p = &lmno::p;
char   lmno::*lmno_x = &lmno::x;
int    lmno::*lmno_r = &lmno::r;

int  novtbl::*novtbl_a = &novtbl::a;
char novtbl::*novtbl_b = &novtbl::b;
int  novtbl::*novtbl_q = &novtbl::q;
int  *novtbl::*novtbl_p = &novtbl::p;
int  *novtbl::*novtbl_null = 0;

static void reset_pdm()
{
  abcd_null = 0;
  abcd_a = &abcd::a;
  efgh_e = &efgh::e;
  efgh_f = &efgh::f;
  pqrs_x = &pqrs::x;
  pqrs_p = &pqrs::p;
  lmno_d = &lmno::d;
  lmno_p = &lmno::p;
  lmno_x = &lmno::x;
  lmno_r = &lmno::r;
  novtbl_a = &novtbl::a;
  novtbl_b = &novtbl::b;
  novtbl_q = &novtbl::q;
  novtbl_p = &novtbl::p;
  novtbl_null = 0;
}

static void 
check_sz(size_t a, size_t b, const char *varname, const char *filename, int linenum)
{
  if (a != b) {
    printf("sizeof(%s) is %d. Should be %d. @%s:%d\n", varname, (int)a, (int)b, filename, linenum);
    n_errors++;
  } else if (verbose) {
    printf("sizeof(%s) is %d. @%s:%d\n", varname, (int)a, filename, linenum);
  }
}

static void 
check_pdm_val(ptrdiff_t a, ptrdiff_t b, const char *varname, const char *filename, int linenum)
{
  if (a != b) {
    printf("%s is %d. Should be %d. @%s:%d\n", varname, (int)a, (int)b, filename, linenum);
    n_errors++;
  } else if (verbose) {
    printf("%s is %d. @%s:%d\n", varname, (int)a,  filename, linenum);
  }
  n_tests++;
}


#define TEST_PDM(var,val) \
    check_sz(sizeof(var),PTRSIZE, #var, __FILE__, __LINE__);\
    check_pdm_val(*(ptrdiff_t*)&var, val, #var, __FILE__, __LINE__);

struct pmfty { // a struct representing ptr-to-member function1
  union {
    int (*ptr)();
    ptrdiff_t ofst;
  } ;
  ptrdiff_t adj;
};

extern "C" ptrdiff_t find_func_addr(const char *);
extern "C" char* find_func_name(ptrdiff_t);
static const char *lfn;
static void 
check_pmf_val(pmfty *a, ptrdiff_t v1, ptrdiff_t v2, const char *varname, const char *filename, int linenum)
{
  if (a->ofst != v1 || a->adj != v2) {
    printf("%s is (%s/%d/0x%x,%d). Should be (%s/%d/0x%x,%d). @%s:%d\n", varname, 
                  lfn[0]?find_func_name(a->ofst):lfn,
                  (int)(a->ofst),(int)(a->ofst), (int)(a->adj),
                  lfn,(int)v1, (int)v1, (int)v2, 
                  filename, linenum);
    n_errors++;
  } else if (verbose) {
    printf("%s is (%d,%d). @%s:%d\n", varname, (int)v1, (int)v2, filename, linenum);
  }
  n_tests++;
}


void test_pdm_x()
{
  TEST_PDM(abcd_a, LPSELECT(8,4));
  TEST_PDM(abcd_null , -1);
  TEST_PDM(efgh_e , LPSELECT(8,4));
  TEST_PDM(efgh_f , LPSELECT(16,8));
  TEST_PDM(pqrs_x , LPSELECT(40,20));
  TEST_PDM(pqrs_p , LPSELECT(48,24));

  TEST_PDM(lmno_d , LPSELECT(8,4));
  TEST_PDM(lmno_p , LPSELECT(16,12));
  TEST_PDM(lmno_x , LPSELECT(20,16));
  TEST_PDM(lmno_r , LPSELECT(24,20));

  TEST_PDM(novtbl_a , 0);
  TEST_PDM(novtbl_b , 4);
  TEST_PDM(novtbl_q , LPSELECT(16,12));
  TEST_PDM(novtbl_p , 8);
  TEST_PDM(novtbl_null , -1);
}

#if 0
#define N0 abcd
#define N1 efgh
#define N2 pqrs
#define N3 lmno
#define M0 f1
#define M1 f2
#define M2 f3
#define M3 f4
#define M4 g1
#define M5 g2
#define M6 g3
#define M7 g4
<for i in 0..3>
<for j in 0..3>
<for k in 0..7>
int (N<id i>::*N<id i> _ N<id j> _ M<id k>)() = &N<id i>::M<id k>;
</for>
</for>
</for>
#endif


int (abcd::*abcd_abcd_f1)() = &abcd::f1;
int (abcd::*abcd_abcd_f3)() = &abcd::f3;
int (abcd::*abcd_abcd_g1)() = &abcd::g1;
int (abcd::*abcd_abcd_g3)() = &abcd::g3;
int (abcd::*abcd_efgh_f1)() = &abcd::f1;
int (abcd::*abcd_efgh_f3)() = &abcd::f3;
int (abcd::*abcd_efgh_g1)() = &abcd::g1;
int (abcd::*abcd_efgh_g3)() = &abcd::g3;
int (abcd::*abcd_pqrs_f1)() = &abcd::f1;
int (abcd::*abcd_pqrs_f3)() = &abcd::f3;
int (abcd::*abcd_pqrs_g1)() = &abcd::g1;
int (abcd::*abcd_pqrs_g3)() = &abcd::g3;
int (abcd::*abcd_lmno_f1)() = &abcd::f1;
int (abcd::*abcd_lmno_f3)() = &abcd::f3;
int (abcd::*abcd_lmno_g1)() = &abcd::g1;
int (abcd::*abcd_lmno_g3)() = &abcd::g3;
int (efgh::*efgh_abcd_f2)() = &efgh::f2;
int (efgh::*efgh_abcd_f3)() = &efgh::f3;
int (efgh::*efgh_abcd_g2)() = &efgh::g2;
int (efgh::*efgh_abcd_g3)() = &efgh::g3;
int (efgh::*efgh_efgh_f2)() = &efgh::f2;
int (efgh::*efgh_efgh_f3)() = &efgh::f3;
int (efgh::*efgh_efgh_g2)() = &efgh::g2;
int (efgh::*efgh_efgh_g3)() = &efgh::g3;
int (efgh::*efgh_pqrs_f2)() = &efgh::f2;
int (efgh::*efgh_pqrs_f3)() = &efgh::f3;
int (efgh::*efgh_pqrs_g2)() = &efgh::g2;
int (efgh::*efgh_pqrs_g3)() = &efgh::g3;
int (efgh::*efgh_lmno_f2)() = &efgh::f2;
int (efgh::*efgh_lmno_f3)() = &efgh::f3;
int (efgh::*efgh_lmno_g2)() = &efgh::g2;
int (efgh::*efgh_lmno_g3)() = &efgh::g3;
int (pqrs::*pqrs_abcd_f1)() = &pqrs::f1;
int (pqrs::*pqrs_abcd_f2)() = &pqrs::f2;
int (pqrs::*pqrs_abcd_f4)() = &pqrs::f4;
int (pqrs::*pqrs_abcd_g1)() = &pqrs::g1;
int (pqrs::*pqrs_abcd_g2)() = &pqrs::g2;
int (pqrs::*pqrs_abcd_g4)() = &pqrs::g4;
int (pqrs::*pqrs_efgh_f1)() = &pqrs::f1;
int (pqrs::*pqrs_efgh_f2)() = &pqrs::f2;
int (pqrs::*pqrs_efgh_f4)() = &pqrs::f4;
int (pqrs::*pqrs_efgh_g1)() = &pqrs::g1;
int (pqrs::*pqrs_efgh_g2)() = &pqrs::g2;
int (pqrs::*pqrs_efgh_g4)() = &pqrs::g4;
int (pqrs::*pqrs_pqrs_f1)() = &pqrs::f1;
int (pqrs::*pqrs_pqrs_f2)() = &pqrs::f2;
int (pqrs::*pqrs_pqrs_f4)() = &pqrs::f4;
int (pqrs::*pqrs_pqrs_g1)() = &pqrs::g1;
int (pqrs::*pqrs_pqrs_g2)() = &pqrs::g2;
int (pqrs::*pqrs_pqrs_g4)() = &pqrs::g4;
int (pqrs::*pqrs_lmno_f1)() = &pqrs::f1;
int (pqrs::*pqrs_lmno_f2)() = &pqrs::f2;
int (pqrs::*pqrs_lmno_f4)() = &pqrs::f4;
int (pqrs::*pqrs_lmno_g1)() = &pqrs::g1;
int (pqrs::*pqrs_lmno_g2)() = &pqrs::g2;
int (pqrs::*pqrs_lmno_g4)() = &pqrs::g4;
int (lmno::*lmno_abcd_f4)() = &lmno::f4;
int (lmno::*lmno_abcd_g4)() = &lmno::g4;
int (lmno::*lmno_efgh_f4)() = &lmno::f4;
int (lmno::*lmno_efgh_g4)() = &lmno::g4;
int (lmno::*lmno_pqrs_f4)() = &lmno::f4;
int (lmno::*lmno_pqrs_g4)() = &lmno::g4;
int (lmno::*lmno_lmno_f4)() = &lmno::f4;
int (lmno::*lmno_lmno_g4)() = &lmno::g4;
int (lmno::*lmno_lmno_null)() = 0;

static void reset_pmf()
{
  abcd_abcd_f1 = &abcd::f1;
  abcd_abcd_f3 = &abcd::f3;
  abcd_abcd_g1 = &abcd::g1;
  abcd_abcd_g3 = &abcd::g3;
  abcd_efgh_f1 = &abcd::f1;
  abcd_efgh_f3 = &abcd::f3;
  abcd_efgh_g1 = &abcd::g1;
  abcd_efgh_g3 = &abcd::g3;
  abcd_pqrs_f1 = &abcd::f1;
  abcd_pqrs_f3 = &abcd::f3;
  abcd_pqrs_g1 = &abcd::g1;
  abcd_pqrs_g3 = &abcd::g3;
  abcd_lmno_f1 = &abcd::f1;
  abcd_lmno_f3 = &abcd::f3;
  abcd_lmno_g1 = &abcd::g1;
  abcd_lmno_g3 = &abcd::g3;
  efgh_abcd_f2 = &efgh::f2;
  efgh_abcd_f3 = &efgh::f3;
  efgh_abcd_g2 = &efgh::g2;
  efgh_abcd_g3 = &efgh::g3;
  efgh_efgh_f2 = &efgh::f2;
  efgh_efgh_f3 = &efgh::f3;
  efgh_efgh_g2 = &efgh::g2;
  efgh_efgh_g3 = &efgh::g3;
  efgh_pqrs_f2 = &efgh::f2;
  efgh_pqrs_f3 = &efgh::f3;
  efgh_pqrs_g2 = &efgh::g2;
  efgh_pqrs_g3 = &efgh::g3;
  efgh_lmno_f2 = &efgh::f2;
  efgh_lmno_f3 = &efgh::f3;
  efgh_lmno_g2 = &efgh::g2;
  efgh_lmno_g3 = &efgh::g3;
  pqrs_abcd_f1 = &pqrs::f1;
  pqrs_abcd_f2 = &pqrs::f2;
  pqrs_abcd_f4 = &pqrs::f4;
  pqrs_abcd_g1 = &pqrs::g1;
  pqrs_abcd_g2 = &pqrs::g2;
  pqrs_abcd_g4 = &pqrs::g4;
  pqrs_efgh_f1 = &pqrs::f1;
  pqrs_efgh_f2 = &pqrs::f2;
  pqrs_efgh_f4 = &pqrs::f4;
  pqrs_efgh_g1 = &pqrs::g1;
  pqrs_efgh_g2 = &pqrs::g2;
  pqrs_efgh_g4 = &pqrs::g4;
  pqrs_pqrs_f1 = &pqrs::f1;
  pqrs_pqrs_f2 = &pqrs::f2;
  pqrs_pqrs_f4 = &pqrs::f4;
  pqrs_pqrs_g1 = &pqrs::g1;
  pqrs_pqrs_g2 = &pqrs::g2;
  pqrs_pqrs_g4 = &pqrs::g4;
  pqrs_lmno_f1 = &pqrs::f1;
  pqrs_lmno_f2 = &pqrs::f2;
  pqrs_lmno_f4 = &pqrs::f4;
  pqrs_lmno_g1 = &pqrs::g1;
  pqrs_lmno_g2 = &pqrs::g2;
  pqrs_lmno_g4 = &pqrs::g4;
  lmno_abcd_f4 = &lmno::f4;
  lmno_abcd_g4 = &lmno::g4;
  lmno_efgh_f4 = &lmno::f4;
  lmno_efgh_g4 = &lmno::g4;
  lmno_pqrs_f4 = &lmno::f4;
  lmno_pqrs_g4 = &lmno::g4;
  lmno_lmno_f4 = &lmno::f4;
  lmno_lmno_g4 = &lmno::g4;
  lmno_lmno_null = 0;
}
#define TEST_PMF(var,v1, v2) \
    lfn="";check_sz(sizeof(var),PMFSIZE, #var, __FILE__, __LINE__);\
    check_pmf_val((pmfty*)&var, v1, v2, #var, __FILE__, __LINE__);

// PMF (ptr to member function) layout: Plain G++ abi 
//   ptr: func_ptr for non-virtual, or 1+vtbl_ofst for virtual. bit 1 indicates virtual
//   adj: adjustment to base class, when the declared class of function is at an offset
//        from the declared class of the PMF.

#define TEST_VPMF(a,b,c) TEST_PMF(a,b,c)
#define TEST_NVPMF(a,b,c) TEST_PMF(a,b,c)

void test_pmf_x()
{ 
  TEST_NVPMF(abcd_abcd_f1, find_func_addr(lfn="_ZN4abcd2f1Ev"), 0);
  TEST_NVPMF(abcd_abcd_f3, find_func_addr(lfn="_ZN4abcd2f3Ev"), 0);
  TEST_VPMF (abcd_abcd_g1, 1, 0);
  TEST_VPMF (abcd_abcd_g3, LPSELECT(9,5), 0);
  TEST_NVPMF(abcd_efgh_f1, find_func_addr(lfn="_ZN4abcd2f1Ev"), 0);
  TEST_NVPMF(abcd_efgh_f3, find_func_addr(lfn="_ZN4abcd2f3Ev"), 0);
  TEST_VPMF (abcd_efgh_g1, 1, 0);
  TEST_VPMF (abcd_efgh_g3, LPSELECT(9,5), 0);
  TEST_NVPMF(abcd_pqrs_f1, find_func_addr(lfn="_ZN4abcd2f1Ev"), 0);
  TEST_NVPMF(abcd_pqrs_f3, find_func_addr(lfn="_ZN4abcd2f3Ev"), 0);
  TEST_VPMF (abcd_pqrs_g1, 1, 0);
  TEST_VPMF (abcd_pqrs_g3, LPSELECT(9,5), 0);
  TEST_NVPMF(abcd_lmno_f1, find_func_addr(lfn="_ZN4abcd2f1Ev"), 0);
  TEST_NVPMF(abcd_lmno_f3, find_func_addr(lfn="_ZN4abcd2f3Ev"), 0);
  TEST_VPMF (abcd_lmno_g1, 1, 0);
  TEST_VPMF (abcd_lmno_g3, LPSELECT(9,5), 0);
  TEST_NVPMF(efgh_abcd_f2, find_func_addr(lfn="_ZN4efgh2f2Ev"), 0);
  TEST_NVPMF(efgh_abcd_f3, find_func_addr(lfn="_ZN4efgh2f3Ev"), 0);
  TEST_VPMF (efgh_abcd_g2, 1, 0);
  TEST_VPMF (efgh_abcd_g3, LPSELECT(9,5), 0);
  TEST_NVPMF(efgh_efgh_f2, find_func_addr(lfn="_ZN4efgh2f2Ev"), 0);
  TEST_NVPMF(efgh_efgh_f3, find_func_addr(lfn="_ZN4efgh2f3Ev"), 0);
  TEST_VPMF (efgh_efgh_g2, 1, 0);
  TEST_VPMF (efgh_efgh_g3, LPSELECT(9,5), 0);
  TEST_NVPMF(efgh_pqrs_f2, find_func_addr(lfn="_ZN4efgh2f2Ev"), 0);
  TEST_NVPMF(efgh_pqrs_f3, find_func_addr(lfn="_ZN4efgh2f3Ev"), 0);
  TEST_VPMF (efgh_pqrs_g2, 1, 0);
  TEST_VPMF (efgh_pqrs_g3, LPSELECT(9,5), 0);
  TEST_NVPMF(efgh_lmno_f2, find_func_addr(lfn="_ZN4efgh2f2Ev"), 0);
  TEST_NVPMF(efgh_lmno_f3, find_func_addr(lfn="_ZN4efgh2f3Ev"), 0);
  TEST_VPMF (efgh_lmno_g2, 1, 0);
  TEST_VPMF (efgh_lmno_g3, LPSELECT(9,5), 0);
  TEST_NVPMF(pqrs_abcd_f1, find_func_addr(lfn="_ZN4abcd2f1Ev"), 0);
  TEST_NVPMF(pqrs_abcd_f2, find_func_addr(lfn="_ZN4efgh2f2Ev"), LPSELECT(16,8));
  TEST_NVPMF(pqrs_abcd_f4, find_func_addr(lfn="_ZN4pqrs2f4Ev"), 0);
  TEST_VPMF (pqrs_abcd_g1, 1, 0);
  TEST_VPMF (pqrs_abcd_g2, 1, LPSELECT(16,8));
  TEST_VPMF (pqrs_abcd_g4, LPSELECT(33,17), 0);
  TEST_NVPMF(pqrs_efgh_f1, find_func_addr(lfn="_ZN4abcd2f1Ev"), 0);
  TEST_NVPMF(pqrs_efgh_f2, find_func_addr(lfn="_ZN4efgh2f2Ev"), LPSELECT(16,8));
  TEST_NVPMF(pqrs_efgh_f4, find_func_addr(lfn="_ZN4pqrs2f4Ev"), 0);
  TEST_VPMF (pqrs_efgh_g1, 1, 0);
  TEST_VPMF (pqrs_efgh_g2, 1, LPSELECT(16,8));
  TEST_VPMF (pqrs_efgh_g4, LPSELECT(33,17), 0);
  TEST_NVPMF(pqrs_pqrs_f1, find_func_addr(lfn="_ZN4abcd2f1Ev"), 0);
  TEST_NVPMF(pqrs_pqrs_f2, find_func_addr(lfn="_ZN4efgh2f2Ev"), LPSELECT(16,8));
  TEST_NVPMF(pqrs_pqrs_f4, find_func_addr(lfn="_ZN4pqrs2f4Ev"), 0);
  TEST_VPMF (pqrs_pqrs_g1, 1, 0);
  TEST_VPMF (pqrs_pqrs_g2, 1, LPSELECT(16,8));
  TEST_VPMF (pqrs_pqrs_g4, LPSELECT(33,17), 0);
  TEST_NVPMF(pqrs_lmno_f1, find_func_addr(lfn="_ZN4abcd2f1Ev"), 0);
  TEST_NVPMF(pqrs_lmno_f2, find_func_addr(lfn="_ZN4efgh2f2Ev"), LPSELECT(16,8));
  TEST_NVPMF(pqrs_lmno_f4, find_func_addr(lfn="_ZN4pqrs2f4Ev"), 0);
  TEST_VPMF (pqrs_lmno_g1, 1, 0);
  TEST_VPMF (pqrs_lmno_g2, 1, LPSELECT(16,8));
  TEST_VPMF (pqrs_lmno_g4, LPSELECT(33,17), 0);
  TEST_NVPMF(lmno_abcd_f4, find_func_addr(lfn="_ZN4lmno2f4Ev"), 0);
  TEST_VPMF (lmno_abcd_g4, 1, 0);
  TEST_NVPMF(lmno_efgh_f4, find_func_addr(lfn="_ZN4lmno2f4Ev"), 0);
  TEST_VPMF (lmno_efgh_g4, 1, 0);
  TEST_NVPMF(lmno_pqrs_f4, find_func_addr(lfn="_ZN4lmno2f4Ev"), 0);
  TEST_VPMF (lmno_pqrs_g4, 1, 0);
  TEST_NVPMF(lmno_lmno_f4, find_func_addr(lfn="_ZN4lmno2f4Ev"), 0);
  TEST_VPMF (lmno_lmno_g4, 1, 0);
  TEST_VPMF (lmno_lmno_null, 0, 0);
  TEST_NVPMF(lmno_lmno_null, 0, 0);
}
void test_pdm()
{
  // test static assignments
  test_pdm_x();
  // now test dynamic assignments
  reset_pdm();
  test_pdm_x();
}
void test_pmf()
{
  // test static assignments
  test_pmf_x();
  // now test dynamic assignments
  reset_pmf();
  test_pmf_x();
}

static Arrange_To_Call_Me Tpmf(test_pmf, "pmf");
static Arrange_To_Call_Me Tpdm(test_pdm, "pdm");
#else

typedef struct {
  const char *name;
  void (*pf)();
} NAME_MAP;

extern void _ZN4abcd2f1Ev();
extern void _ZN4abcd2f3Ev();
extern void _ZN4abcd2f1Ev();
extern void _ZN4abcd2f3Ev();
extern void _ZN4abcd2f1Ev();
extern void _ZN4abcd2f3Ev();
extern void _ZN4abcd2f1Ev();
extern void _ZN4abcd2f3Ev();
extern void _ZN4efgh2f2Ev();
extern void _ZN4efgh2f3Ev();
extern void _ZN4efgh2f2Ev();
extern void _ZN4efgh2f3Ev();
extern void _ZN4efgh2f2Ev();
extern void _ZN4efgh2f3Ev();
extern void _ZN4efgh2f2Ev();
extern void _ZN4efgh2f3Ev();
extern void _ZN4abcd2f1Ev();
extern void _ZN4efgh2f2Ev();
extern void _ZN4pqrs2f4Ev();
extern void _ZN4abcd2f1Ev();
extern void _ZN4efgh2f2Ev();
extern void _ZN4pqrs2f4Ev();
extern void _ZN4abcd2f1Ev();
extern void _ZN4efgh2f2Ev();
extern void _ZN4pqrs2f4Ev();
extern void _ZN4abcd2f1Ev();
extern void _ZN4efgh2f2Ev();
extern void _ZN4pqrs2f4Ev();
extern void _ZN4lmno2f4Ev();
extern void _ZN4lmno2f4Ev();
extern void _ZN4lmno2f4Ev();
extern void _ZN4lmno2f4Ev();

#define PAIR(a) {#a, a}
static NAME_MAP map[] = {
  PAIR(_ZN4abcd2f1Ev),
  PAIR(_ZN4abcd2f3Ev),
  PAIR(_ZN4abcd2f1Ev),
  PAIR(_ZN4abcd2f3Ev),
  PAIR(_ZN4abcd2f1Ev),
  PAIR(_ZN4abcd2f3Ev),
  PAIR(_ZN4abcd2f1Ev),
  PAIR(_ZN4abcd2f3Ev),
  PAIR(_ZN4efgh2f2Ev),
  PAIR(_ZN4efgh2f3Ev),
  PAIR(_ZN4efgh2f2Ev),
  PAIR(_ZN4efgh2f3Ev),
  PAIR(_ZN4efgh2f2Ev),
  PAIR(_ZN4efgh2f3Ev),
  PAIR(_ZN4efgh2f2Ev),
  PAIR(_ZN4efgh2f3Ev),
  PAIR(_ZN4abcd2f1Ev),
  PAIR(_ZN4efgh2f2Ev),
  PAIR(_ZN4pqrs2f4Ev),
  PAIR(_ZN4abcd2f1Ev),
  PAIR(_ZN4efgh2f2Ev),
  PAIR(_ZN4pqrs2f4Ev),
  PAIR(_ZN4abcd2f1Ev),
  PAIR(_ZN4efgh2f2Ev),
  PAIR(_ZN4pqrs2f4Ev),
  PAIR(_ZN4abcd2f1Ev),
  PAIR(_ZN4efgh2f2Ev),
  PAIR(_ZN4pqrs2f4Ev),
  PAIR(_ZN4lmno2f4Ev),
  PAIR(_ZN4lmno2f4Ev),
  PAIR(_ZN4lmno2f4Ev),
  PAIR(_ZN4lmno2f4Ev),
  {0,0}
};

#include <string.h>
ptrdiff_t 
find_func_addr(const char *name)
{
  NAME_MAP *m;
  for (m = map; m->name; m++)
    if (!strcmp(m->name, name))
      return (ptrdiff_t) m->pf;
  return (ptrdiff_t) 0x33333333;
}

const char *
find_func_name(void (*f)())
{
  NAME_MAP *m;
  if (!f) return "";
  for (m = map; m->name; m++)
    if (m->pf == f)
      return m->name;
  return "???";
}

#endif
    





//these combinations break C++ rules
//int (abcd::*abcd_abcd_f2)() = &abcd::f2;
//int (abcd::*abcd_abcd_f4)() = &abcd::f4;
//int (abcd::*abcd_abcd_g2)() = &abcd::g2;
//int (abcd::*abcd_abcd_g4)() = &abcd::g4;
//int (abcd::*abcd_efgh_f2)() = &abcd::f2;
//int (abcd::*abcd_efgh_f4)() = &abcd::f4;
//int (abcd::*abcd_efgh_g2)() = &abcd::g2;
//int (abcd::*abcd_efgh_g4)() = &abcd::g4;
//int (abcd::*abcd_pqrs_f2)() = &abcd::f2;
//int (abcd::*abcd_pqrs_f4)() = &abcd::f4;
//int (abcd::*abcd_pqrs_g2)() = &abcd::g2;
//int (abcd::*abcd_pqrs_g4)() = &abcd::g4;
//int (abcd::*abcd_lmno_f2)() = &abcd::f2;
//int (abcd::*abcd_lmno_f4)() = &abcd::f4;
//int (abcd::*abcd_lmno_g2)() = &abcd::g2;
//int (abcd::*abcd_lmno_g4)() = &abcd::g4;
//int (efgh::*efgh_abcd_f1)() = &efgh::f1;
//int (efgh::*efgh_abcd_f4)() = &efgh::f4;
//int (efgh::*efgh_abcd_g1)() = &efgh::g1;
//int (efgh::*efgh_abcd_g4)() = &efgh::g4;
//int (efgh::*efgh_efgh_f1)() = &efgh::f1;
//int (efgh::*efgh_efgh_f4)() = &efgh::f4;
//int (efgh::*efgh_efgh_g1)() = &efgh::g1;
//int (efgh::*efgh_efgh_g4)() = &efgh::g4;
//int (efgh::*efgh_pqrs_f1)() = &efgh::f1;
//int (efgh::*efgh_pqrs_f4)() = &efgh::f4;
//int (efgh::*efgh_pqrs_g1)() = &efgh::g1;
//int (efgh::*efgh_pqrs_g4)() = &efgh::g4;
//int (efgh::*efgh_lmno_f1)() = &efgh::f1;
//int (efgh::*efgh_lmno_f4)() = &efgh::f4;
//int (efgh::*efgh_lmno_g1)() = &efgh::g1;
//int (efgh::*efgh_lmno_g4)() = &efgh::g4;
//int (pqrs::*pqrs_abcd_f3)() = &pqrs::f3;
//int (pqrs::*pqrs_abcd_g3)() = &pqrs::g3;
//int (pqrs::*pqrs_efgh_f3)() = &pqrs::f3;
//int (pqrs::*pqrs_efgh_g3)() = &pqrs::g3;
//int (pqrs::*pqrs_pqrs_f3)() = &pqrs::f3;
//int (pqrs::*pqrs_pqrs_g3)() = &pqrs::g3;
//int (pqrs::*pqrs_lmno_f3)() = &pqrs::f3;
//int (pqrs::*pqrs_lmno_g3)() = &pqrs::g3;
//int (lmno::*lmno_abcd_f1)() = &lmno::f1;
//int (lmno::*lmno_abcd_f2)() = &lmno::f2;
//int (lmno::*lmno_abcd_f3)() = &lmno::f3;
//int (lmno::*lmno_abcd_g1)() = &lmno::g1;
//int (lmno::*lmno_abcd_g2)() = &lmno::g2;
//int (lmno::*lmno_abcd_g3)() = &lmno::g3;
//int (lmno::*lmno_efgh_f1)() = &lmno::f1;
//int (lmno::*lmno_efgh_f2)() = &lmno::f2;
//int (lmno::*lmno_efgh_f3)() = &lmno::f3;
//int (lmno::*lmno_efgh_g1)() = &lmno::g1;
//int (lmno::*lmno_efgh_g2)() = &lmno::g2;
//int (lmno::*lmno_efgh_g3)() = &lmno::g3;
//int (lmno::*lmno_pqrs_f1)() = &lmno::f1;
//int (lmno::*lmno_pqrs_f2)() = &lmno::f2;
//int (lmno::*lmno_pqrs_f3)() = &lmno::f3;
//int (lmno::*lmno_pqrs_g1)() = &lmno::g1;
//int (lmno::*lmno_pqrs_g2)() = &lmno::g2;
//int (lmno::*lmno_pqrs_g3)() = &lmno::g3;
//int (lmno::*lmno_lmno_f1)() = &lmno::f1;
//int (lmno::*lmno_lmno_f2)() = &lmno::f2;
//int (lmno::*lmno_lmno_f3)() = &lmno::f3;
//int (lmno::*lmno_lmno_g1)() = &lmno::g1;
//int (lmno::*lmno_lmno_g2)() = &lmno::g2;
//int (lmno::*lmno_lmno_g3)() = &lmno::g3;
