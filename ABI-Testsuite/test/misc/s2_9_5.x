// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: cxx_compiler -c cxx_rtti cxx_exceptions %s -o %t1.o
// RUN: c_compiler -c %s -o %t2.o
// RUN: linker -o %t%exeext %t2.o %t1.o
// RUN: runtool %t%exeext | grep PASSED

//test for section 2.9.4. Test that we generate typeinfo as per the spec

#include "../common/select2.h"
#ifdef __cplusplus
#include <typeinfo>

struct abcd { int x; };
struct efgh : abcd { int y; };
void bar(){}
enum enty { e0, e1, e2, e3};
enum enty enumv;
abcd *p, q, qa[2];
efgh efgh_var;
int abcd::*pdm;

struct str2 {
  int foo();
};
int (str2::*pmf)();

struct str3 : virtual str2 {
    int f2;
};

str3 str3_v;
void foo(int p)
{
  if (!p++) throw 3;
  if (!p++) throw p;
  if (!p++) throw bar;
  if (!p++) throw q;
  if (!p++) throw enumv;
  if (!p++) throw efgh_var;
  if (!p++) throw pdm;
  if (!p++) throw pmf;
  if (!p++) throw str3_v;
};

const std::type_info *getti(int x)
{
  if (!p++) return &typeid(bar);
  if (!p++) return &typeid(qa);
}
#else

typedef unsigned char  uchar;
typedef unsigned short ushort;
typedef unsigned int   uint;
typedef unsigned long  ulong;
typedef void *         voidp;

typedef struct { // a field spec. specifies an initialized field
  char type; // one of 'c', 's', 'i', 'l', or 'p' for integers and pointer
  long long value; // expected value, if one of ints
  uchar *ptr; // expected pointer value
  int plus; // if pointer value has an offset as well
} FSPEC;

extern uchar _ZTSA2_4abcd;
extern uchar _ZTVN10__cxxabiv117__array_type_infoE;
extern uchar _ZTI4str2;
extern uchar _ZTS4str3;
extern uchar _ZTVN10__cxxabiv121__vmi_class_type_infoE;
extern uchar _ZTS4str2;
extern uchar _ZTVN10__cxxabiv117__class_type_infoE;
extern uchar _ZTSFivE;
extern uchar _ZTVN10__cxxabiv120__function_type_infoE;
extern uchar _ZTI4str2;
extern uchar _ZTIFivE;
extern uchar _ZTSM4str2FivE;
extern uchar _ZTVN10__cxxabiv129__pointer_to_member_type_infoE;
extern uchar _ZTI4abcd;
extern uchar _ZTIi;
extern uchar _ZTSM4abcdi;
extern uchar _ZTVN10__cxxabiv129__pointer_to_member_type_infoE;
extern uchar _ZTI4abcd;
extern uchar _ZTS4efgh;
extern uchar _ZTVN10__cxxabiv120__si_class_type_infoE;
extern uchar _ZTS4enty;
extern uchar _ZTVN10__cxxabiv116__enum_type_infoE;
extern uchar _ZTS4abcd;
extern uchar _ZTVN10__cxxabiv117__class_type_infoE;
extern uchar _ZTSFvvE;
extern uchar _ZTVN10__cxxabiv120__function_type_infoE;
extern uchar _ZTIFvvE;
extern uchar _ZTSPFvvE;
extern uchar _ZTVN10__cxxabiv119__pointer_type_infoE;
extern uchar _ZTV4str3;

static int nerr;
extern int printf(const char *, ...);

FSPEC FS_ZTIPFvvE[] = {
	{'p', 0, &_ZTVN10__cxxabiv119__pointer_type_infoE, LPSELECT(16,8)},
	{'p', 0, &_ZTSPFvvE},
        {'i', 0},
	{'p', 0, &_ZTIFvvE},
};

FSPEC FS_ZTIFvvE[] = {
	{'p', 0, &_ZTVN10__cxxabiv120__function_type_infoE, LPSELECT(16,8)},
	{'p', 0, &_ZTSFvvE},
};

FSPEC FS_ZTI4abcd[] = {
	{'p', 0, &_ZTVN10__cxxabiv117__class_type_infoE, LPSELECT(16,8)},
	{'p', 0, &_ZTS4abcd},
};

FSPEC FS_ZTI4enty[] = {
	{'p', 0, &_ZTVN10__cxxabiv116__enum_type_infoE, LPSELECT(16,8)},
	{'p', 0, &_ZTS4enty},
};

FSPEC FS_ZTI4efgh[] = {
	{'p', 0, &_ZTVN10__cxxabiv120__si_class_type_infoE, LPSELECT(16,8)},
	{'p', 0, &_ZTS4efgh},
	{'p', 0, &_ZTI4abcd},
};

FSPEC FS_ZTIM4abcdi[] = {
	{'p', 0, &_ZTVN10__cxxabiv129__pointer_to_member_type_infoE, LPSELECT(16,8)},
	{'p', 0, &_ZTSM4abcdi},
        {'i', 0},
	{'p', 0, &_ZTIi},
	{'p', 0, &_ZTI4abcd},
};

FSPEC FS_ZTIM4str2FivE[] = {
	{'p', 0, &_ZTVN10__cxxabiv129__pointer_to_member_type_infoE, LPSELECT(16,8)},
	{'p', 0, &_ZTSM4str2FivE},
        {'i', 0},
	{'p', 0, &_ZTIFivE},
	{'p', 0, &_ZTI4str2},
};

FSPEC FS_ZTIFivE[] = {
	{'p', 0, &_ZTVN10__cxxabiv120__function_type_infoE, LPSELECT(16,8)},
	{'p', 0, &_ZTSFivE},
};

FSPEC FS_ZTI4str2[] = {
	{'p', 0, &_ZTVN10__cxxabiv117__class_type_infoE, LPSELECT(16,8)},
	{'p', 0, &_ZTS4str2},
};

FSPEC FS_ZTI4str3[] = {
	{'p', 0, &_ZTVN10__cxxabiv121__vmi_class_type_infoE, LPSELECT(16,8)},
	{'p', 0, &_ZTS4str3},
        {'i', 0},
        {'i', 1},
	{'p', 0, &_ZTI4str2},
        {'i', LPSELECT( -6141,-3069)},
};

FSPEC FS_ZTIA2_4abcd[] = {
	{'p', 0, &_ZTVN10__cxxabiv117__array_type_infoE, LPSELECT(16,8)},
	{'p', 0, &_ZTSA2_4abcd},
};

static int align_tbl[128];
static void err_f(uchar *addr, int ofst, char *name, int idx, FSPEC *f)
{
  printf("ERROR at idx %d of %s ", idx, name);
  switch (f->type) {
    case 'c': printf("%x != %x\n", *(uchar*)(addr+ofst), (uchar)f->value); break;
    case 's': printf("%x != %x\n", *(ushort*)(addr+ofst), (ushort)f->value); break;
    case 'i': printf("%x != %x\n", *(uint*)(addr+ofst), (uint)f->value); break;
    case 'l': printf("%lx != %lx\n", *(ulong*)(addr+ofst), (ulong)f->value); break;
    case 'p': printf("%p != %p\n", *(voidp*)(addr+ofst), (voidp)(f->ptr + f->plus)); break;
  }
  nerr ++;
}
// check that values at addr are as specified by fspec
static void 
test_fs(FSPEC *spec, int spec_size, uchar *addr, char *name)
{
  int ofst = 0, i;
  for (i=0; i<spec_size; i++) {
    FSPEC *f = spec + i;
    int al = align_tbl[f->type];
    if (!al) {
      printf("ERROR: Bad spec %s %d '%c' \n", name, i, f->type);
      nerr++;
      continue;
    }
    while (ofst % al) ofst++; // align the offset
    switch (f->type) {
#define check(type, addr, ofst, name, idx, f) \
        if ((*(type*)(addr+ofst)) != ((type)(f->value))) err_f(addr, ofst, name, i, f);
      case 'c': check(uchar,  addr, ofst, name, i, f); break;
      case 's': check(ushort, addr, ofst, name, i, f); break;
      case 'i': check(uint,   addr, ofst, name, i, f); break;
      case 'l': check(ulong,  addr, ofst, name, i, f); break;
      case 'p': if ((*(voidp*)(addr+ofst)) != (voidp)(f->ptr+f->plus))
                                                err_f(addr, ofst, name, i, f);

    }
    ofst += al; // al and size are always same
  }
}

#define TESTIT(n) extern uchar n; test_fs(FS##n, sizeof(FS##n)/sizeof(FSPEC), &n, #n)

int main() {
  align_tbl['c'] = 1;
  align_tbl['s'] = 2;
  align_tbl['i'] = 4;
  align_tbl['l'] = LPSELECT(8,4);
  align_tbl['p'] = LPSELECT(8,4);
  TESTIT(_ZTIPFvvE);
  TESTIT(_ZTIFvvE);
  TESTIT(_ZTI4abcd);
  TESTIT(_ZTI4enty);
  TESTIT(_ZTI4efgh);
  TESTIT(_ZTIM4abcdi);
  TESTIT(_ZTIM4str2FivE);
  TESTIT(_ZTIFivE);
  TESTIT(_ZTI4str2);
  TESTIT(_ZTI4str3);
  TESTIT(_ZTIA2_4abcd);
  printf("%s\n", nerr ? "FAILED": "PASSED");
  return nerr ? 1 : 0;
}
#endif
