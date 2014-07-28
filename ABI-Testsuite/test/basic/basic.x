// This file is distributed under the University of Illinois Open Source License.
// See LICENSE.TXT for details.
// RUN: cxx_compiler -c %s -I "common" -o %t1.o
// RUN: c_compiler -c %s -I "common" -o %t2.o


// basic tests of sizes and zero-width-bitfield rules that need to match
// done as static checks. 
// If this file fails, there is no point in going forward

#define static_cmp(a,b)  ((((a)==(b))*2)-1)

#ifdef SHOW
#define check_sizeof(name, ty, sz) unsigned name = sizeof(ty)
#define check_alignof(name, ty, al) unsigned name = __alignof__(ty)
#else
#include "testsuite.h"
#define check_sizeof(name, ty, sz) int name[static_cmp(sizeof(ty), sz)]
#define check_alignof(name, ty, al) int name[static_cmp(__alignof__(ty), al)]
#endif

check_sizeof(chsize, char, 1);
check_alignof(chalign, char, 1);

check_sizeof(ssize, short, 2);
check_alignof(salign, short, 2);

check_sizeof(isize, int, 4);
check_alignof(ialign, int, 4);

check_sizeof(fsize, float, 4);
check_alignof(falign, float, 4);

check_sizeof(llsize, long long, 8);
check_alignof(llalign, long long, 8);

check_sizeof(dsize, double, 8);
check_alignof(dalign, double, 8);

check_sizeof(ldsize, long double, ABISELECT(16,12));
check_alignof(ldalign, long double, ABISELECT(16,4));

check_sizeof(lsize, long, ABISELECT(8,4));
check_alignof(lalign, long, ABISELECT(8,4));

check_sizeof(psize, void*, ABISELECT(8,4));
check_alignof(palign, void*, ABISELECT(8,4));

typedef struct { char a; int :0; } abcd;
typedef struct { int :0; } efgh;

check_sizeof(s1size, abcd, 4);
#ifdef __cplusplus
check_sizeof(s2size, efgh, ABISELECT(1,1));
#else
check_sizeof(s2size, efgh, 0);
#endif

int sizzzz[] = { sizeof(abcd), sizeof(efgh) };

